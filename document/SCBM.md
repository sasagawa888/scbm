# The SCBM-Prolog Execution Model

## Understanding Proof Sequences and Continuations Through `append/3`

**SCBM — Sasagawa Continuation Backtracking Model**  
**Technical Note — First Draft**  
**November 23, 2026**

## 1. Introduction

SCBM is a Prolog execution model in which computation is represented as transformations of a **proof sequence**.

Conventional Prolog implementations commonly use stacks, choice points, and dedicated control mechanisms to manage predicate calls, success continuations, failure continuations, and backtracking. SCBM instead places executable predicate objects in a **doubly linked list** and advances computation by manipulating this list.

This doubly linked list is called the *proof sequence*.

The basic execution process is:

1. Place a predicate in the proof sequence.
2. Evaluate the predicate.
3. If the selected clause has a body, expand that body into predicate objects and splice them into the proof sequence.
4. On success, advance to the next predicate.
5. On failure, traverse the proof sequence backward to locate a point that can be retried.
6. When necessary, restore the original predicate and its execution state.

The central idea is that **success and failure continuations are managed within a common data structure**.

The following sections explain this model using the generated C code for the familiar Prolog predicate `append/3`.

## 2. The Prolog Definition of `append/3`

The source predicate is:

```prolog
append([], Ys, Ys).
append([X|Xs], Ys, [X|Zs]) :-
    append(Xs, Ys, Zs).
```

The first clause is the base case: if the first argument is empty, the second and third arguments must unify.

The second clause is recursive: it takes the head of the first list, matches that head in the result list, and recursively appends the remaining elements.

For example:

```prolog
?- append([a,b], [c], Z).
Z = [a,b,c].
```

In SCBM, this recursive computation is performed by expanding and transforming the proof sequence rather than by directly recursing through C function calls.

## 3. The Proof Sequence

### 3.1 Doubly linked elements

The core data structure is `blist`:

```c
blist[x][th].front
blist[x][th].back
blist[x][th].entity
```

| Field | Purpose |
| --- | --- |
| `front` | Link to the preceding element in the proof sequence |
| `back` | Link to the following element in the proof sequence |
| `entity` | Identifier of an object holding execution information |

Here, `th` is the thread index.

A simple proof sequence can be pictured as:

```text
[A] <-> [B] <-> [C]
```

When `B` succeeds, execution can proceed to `C`. When evaluation fails, the control mechanism can traverse in the opposite direction to look for an earlier predicate that can be retried.

The proof sequence is therefore more than a list of goals: its elements also hold the information needed to resume or backtrack computation.

### 3.2 The program counter

```c
pc[th]
```

`pc` identifies the current element of the proof sequence. Unlike a conventional machine program counter, it points to an element in the dynamically changing proof sequence.

### 3.3 Predicate categories

SCBM uses predicate properties to distinguish execution behavior.

| Property | Meaning |
| --- | --- |
| `NONDET` | A predicate for which alternative clauses or solutions may remain |
| `DET` | A predicate executed deterministically |
| `TAIL` | A predicate handled using a specialized tail-call strategy |
| `FIRST` | A marker relevant to restoring the proof sequence |

In this generated example, `append/3` is represented as a nondeterministic predicate object:

```c
Smake_nondet(&&append_3, -1, th)
```

The expression `&&append_3` uses the GNU C labels-as-values extension. It supplies the address of the C label at which execution can resume.

## 4. Predicate Registration and Initialization

### 4.1 Registration

The generated code registers `append/3` as follows:

```c
void init_tpredicate(void) {
    (deftpred)("append", c_append, 3, 1);
}
```

Its entry wrapper is:

```c
static int c_append(int arglist, int rest, int th) {
    int n;
    n = Jlength(arglist);
    return user_scbm(0, n, 0, arglist, rest, th);
}
```

The parameters have these roles:

- `arglist`: arguments to the predicate;
- `rest`: remaining goals supplied by the calling context;
- `th`: thread index.

The shared function `user_scbm` performs the actual execution.

### 4.2 Initial state

The generated code begins by initializing its control and allocation pointers:

```c
pc[th] = 0;
lp[th] = 0;
op[th] = 0;
if (!call_flag[th]) proof[th] = 0;
```

It then dispatches according to the predicate number:

```c
switch (pred) {
case 0: goto append;
}
```

## 5. Creating the Initial Proof Sequence

The entry point creates a `NONDET` object:

```c
append_3entry:
if (!call_flag[th]) {
    pc[th] = Scons(
        Smake_nondet(&&append_3, -1, th), NIL, th);
    Ssave_arg(arglist, th);
} else {
    i = pc[th] = Sreplace(
        pc[th], Smake_nondet(&&append_3, -1, th), th);
    Ssave_arg(arglist, th);
    return i;
}
```

In the ordinary entry path, `Smake_nondet` allocates a predicate object, `Scons` places it in a proof sequence, and `Ssave_arg` preserves the arguments needed for execution and later retrying.

Conceptually, the initial proof sequence consists of one goal:

```text
[append/3]
```

The `call_flag` path is different: `Sreplace` replaces an existing proof-sequence element with the newly created predicate object. This supports execution in a context where a goal is already present in the proof sequence.

**A predicate invocation can therefore be expressed as a replacement of a proof-sequence element.**

## 6. The Execution Loop

The main execution loop is compact:

```c
loop:
if (pc[th] == NIL) goto success;

next = proof_goto[blist[pc[th]][th].entity][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto *next;
```

The loop:

1. Checks whether the current proof sequence has reached `NIL`.
2. Retrieves the executable code address for the current element.
3. Restores the current clause-selection information.
4. Retrieves the saved arguments.
5. Jumps directly to the relevant C label.

`goto *next` is a GNU C *computed goto*. The executable continuation address is stored with the proof-sequence object, so execution can resume without a fresh predicate-name lookup.

## 7. Clause Selection

`append/3` contains two Prolog clauses. The generated C code uses an additional state to mark exhaustion of the available choices:

```c
append_3:
Sinc_proof(th);
switch (clause) {
case 0: Sset_state(th); goto append_3_0;
case 1: goto append_3_1;
case 2: goto append_3_2;
default: goto allfail;
}
```

| Choice value | Action |
| --- | --- |
| `0` | Try the base clause |
| `1` | Try the recursive clause |
| `2` | Handle exhaustion of alternatives |

`Sinc_choice` advances the selection state between clause attempts.

## 8. Evaluating the Base Clause

The first clause is:

```prolog
append([], Ys, Ys).
```

Its generated code is:

```c
append_3_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist, 2);
arg3 = Jnth(arglist, 3);
Srelease(th);
varYs = Jmakevariant(th);
Sinc_choice(th);

if (Junify_nil(arg1, th) == YES &&
    Junify_var(arg2, varYs, th) == YES &&
    Junify_var(arg3, varYs, th) == YES) {
    goto success;
}
```

`Srelease` restores the working state associated with trying the clause. A fresh variable representing `Ys` is created, and the three arguments are unified with the clause head.

For the query:

```prolog
?- append([a,b], [c], Z).
```

unification with `[]` fails, so control falls through to the second clause.

## 9. Evaluating the Recursive Clause

The second clause is:

```prolog
append([X|Xs], Ys, [X|Zs]) :-
    append(Xs, Ys, Zs).
```

### 9.1 Unifying the head

The generated code creates fresh variables:

```c
Srelease(th);
varXs = Jmakevariant(th);
varYs = Jmakevariant(th);
varX  = Jmakevariant(th);
varZs = Jmakevariant(th);
Sinc_choice(th);
```

It then unifies the arguments with the head of the recursive clause:

```c
if (Junify_pair(arg1, Jwlistcons(varX, varXs, th), th) == YES &&
    Junify_var(arg2, varYs, th) == YES &&
    Junify_pair(arg3, Jwlistcons(varX, varZs, th), th) == YES) {
    /* Construct and insert the clause body. */
}
```

For the query `append([a,b], [c], Z)`, the relationships are conceptually:

```text
X  = a
Xs = [b]
Ys = [c]
Z  = [a|Zs]
```

### 9.2 Building the body

After successful head unification, the generated code constructs the argument list for `append(Xs, Ys, Zs)`:

```c
arglist = Jwlistcons(
    varXs,
    Jwlistcons(
        varYs,
        Jwlistcons(varZs, NIL, th),
        th),
    th);
```

Next it creates an executable object for the body goal:

```c
body[0][th] = Smake_nondet(&&append_3_1_0, 0, th);
Ssave_arg(arglist, th);
```

The relevant local variables are saved in `proof_obj`:

```c
proof_obj[op[th]][0][th] = varXs;
proof_obj[op[th]][1][th] = varYs;
proof_obj[op[th]][2][th] = varX;
proof_obj[op[th]][3][th] = varZs;
```

These values allow the computation to recover the appropriate state when execution resumes at the saved continuation.

## 10. The Core Operation: Expanding the Proof Sequence

The generated code inserts the clause body into the proof sequence:

```c
front = Sfront(pc[th], th);
back  = Sback(pc[th], th);

for (i = 0; i >= 0; i--)
    back = Scons(body[i][th], back, th);

Sconc(front, back, th);
pc[th] = back;
goto loop;
```

For this example the body contains only one goal, so the loop runs once. In the general case, a clause body can contain several goals, and these can be assembled into a linked sequence.

At the logical level, the transformation is:

```text
Before expansion:

    append([a,b], [c], Z)

After expansion:

    append([b], [c], Zs)
```

This diagram shows the **active logical goal**, not every control object retained by the implementation. Information required to retry the original predicate is preserved in the relevant proof-sequence structures.

For a clause with multiple goals:

```prolog
p(X) :- q(X), r(X), s(X).
```

its body can be represented conceptually as:

```text
[q(X)] <-> [r(X)] <-> [s(X)]
```

This is the key property of SCBM: **a predicate call with a clause body becomes a transformation of the proof sequence, rather than a nest of C calls representing each Prolog goal.**

## 11. Recursive Execution Without Recursive C Calls

Consider again:

```prolog
?- append([a,b], [c], Z).
```

The logical progression is:

```text
append([a,b], [c], Z)
          |
          v
append([b], [c], Zs1)
          |
          v
append([], [c], Zs2)
          |
          v
        success
```

At the final step, the base clause succeeds. The accumulated unifications give:

```text
Zs2 = [c]
Zs1 = [b|Zs2]
Z   = [a|Zs1]
```

Therefore:

```prolog
Z = [a,b,c].
```

Each recursive Prolog goal is expressed as a proof-sequence expansion. The generated C program transfers control with labels and its execution loop rather than calling `c_append` recursively for each logical step.

## 12. Success Continuation

Successful evaluation enters the `success` label:

```c
success:
if (Sback(pc[th], th) == NIL) {
    if (Jprove_all(rest, Jget_sp(th), th) == YES) {
        Jset_proof(proof[th], th);
        return YES;
    }
    pc[th] = Sbacktrack1(pc[th], th);
    if (pc[th] == NIL) return NO;
    else goto loop;
} else {
    pc[th] = Sback(pc[th], th);
    goto loop;
}
```

There are two cases:

**A subsequent proof-sequence element exists.** SCBM follows the `back` link and continues at that element:

```c
pc[th] = Sback(pc[th], th);
goto loop;
```

**The current sequence has reached its end.** SCBM evaluates the remaining goals provided by the calling context:

```c
Jprove_all(rest, Jget_sp(th), th)
```

If this succeeds, the predicate returns `YES`. If it fails, `Sbacktrack1` searches for an alternative.

Thus the generated code combines a continuation **within the proof sequence** with an **outer continuation** represented by `rest`.

## 13. Failure Continuation and Backtracking

A Prolog computation must return to earlier choice points when a later goal fails. SCBM supports this by examining and restoring the proof sequence.

The example uses two distinct backtracking operations.

### 13.1 `Sbacktrack1`: retry after success

```c
pc[th] = Sbacktrack1(pc[th], th);
```

This operation is used when a successful local computation must seek another alternative—for example, because the remaining goals failed or the caller requests another solution.

The query:

```prolog
?- append(X, Y, [a,b]).
```

can have multiple answers, so execution must be able to resume from retained choice information.

### 13.2 `Sbacktrack2`: handling complete failure

```c
allfail:
Sreset_choice(th);
pc[th] = Sbacktrack2(pc[th], th);
if (pc[th] == NIL) {
    Jset_proof(proof[th], th);
    return NO;
} else {
    goto loop;
}
```

The current selection state is reset, and SCBM searches for a proof-sequence element from which execution can continue. If no such element exists, the computation returns `NO`.

| Function | Main role in this generated code |
| --- | --- |
| `Sbacktrack1` | Find an alternative after local success when continuation requires retrying |
| `Sbacktrack2` | Find a recovery point after clause exhaustion or complete failure |

The precise search and restoration behavior is defined by these functions and the attributes carried by the proof-sequence elements, particularly markers such as `FIRST`.

## 14. Restoring a Predicate

Expanding a clause body changes the active proof sequence. If execution of that body ultimately fails, SCBM must be able to return to the appropriate earlier predicate and try another available alternative.

For example:

```prolog
append([X|Xs], Ys, [X|Zs]) :-
    append(Xs, Ys, Zs).
```

When the recursive body can no longer produce a solution, control must return to the appropriate saved selection state of the enclosing `append/3` invocation.

The proof sequence and its associated objects retain the state required for this restoration. In this way, the same linked representation supports both forward evaluation and backward recovery.

## 15. Saving and Restoring Local Variables

The generated code saves the variables used by the recursive clause:

```c
proof_obj[op[th]][0][th] = varXs;
proof_obj[op[th]][1][th] = varYs;
proof_obj[op[th]][2][th] = varX;
proof_obj[op[th]][3][th] = varZs;
```

The continuation label retrieves them using the current element's `entity`:

```c
append_3_1_0:
varXs = proof_obj[Sentity(pc[th], th)][0][th];
varYs = proof_obj[Sentity(pc[th], th)][1][th];
varX  = proof_obj[Sentity(pc[th], th)][2][th];
varZs = proof_obj[Sentity(pc[th], th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto append_3;
```

Explicitly stored state makes it possible to resume the generated Prolog execution logic without relying on the C call stack as a Prolog backtracking stack.

SCBM still uses separate mechanisms for variable binding, unification, and working-memory management. The proof sequence does not replace every runtime data structure.

## 16. Proof-Sequence Garbage Collection

Expanding and restoring a proof sequence can make some generated elements unreachable or otherwise unnecessary. SCBM can reclaim such elements as part of its proof-sequence management.

In the current implementation, the proof-sequence collection function is named **`Scollect_proof`**.

Collection must respect the lifetime of the objects needed for restoration. A failure alone does not imply that all recently created objects can be reclaimed: objects still referenced by the restored proof sequence must survive.

The exact collection boundary, the role of `FIRST`, and the saved `lp`/`op` values belong to the detailed specification of SCBM memory management. They are not established by the `append/3` code fragment alone.

## 17. Architectural Comparison with the WAM

The Warren Abstract Machine (WAM) is a widely used reference architecture for Prolog implementation. The two approaches emphasize different ways of representing control.

| Aspect | WAM | SCBM |
| --- | --- | --- |
| Execution control | Abstract-machine instructions and registers | Proof-sequence elements and executable addresses |
| Success continuation | Continuation registers / environment mechanisms | Links within the proof sequence plus an outer continuation |
| Failure continuation | Choice points and backtracking machinery | Searching and restoring proof-sequence state |
| Clause body | Compiled instruction sequence | Expansion into proof-sequence elements |
| Recursive goals | WAM environments and control state | Proof-sequence transformations |
| Local state | Environments and stacks | Objects such as `proof_obj`, together with other runtime storage |
| Memory management | Stacks, heap, trails, etc. | Working-memory management plus proof-sequence management |

This is a comparison of architectures, **not** a performance claim. Quantitative evaluation must use controlled benchmarks and comparable measurement definitions.

## 18. Summary

The generated C implementation of `append/3` illustrates the main elements of SCBM:

1. Generate an executable predicate object and place it in the proof sequence.
2. Select a clause and unify its head.
3. On successful unification, generate predicate objects for its body.
4. Splice those objects into the proof sequence and continue execution.
5. On success, follow the next link or return to the outer continuation.
6. On failure, search backward for a point from which the computation can resume.
7. Restore the appropriate execution state as alternatives are explored.

**The defining idea of SCBM is to model Prolog execution as the transformation and restoration of a proof sequence, with success and failure continuations managed through that common representation.**

This provides a distinct perspective on the operational structure of Prolog execution.

---

## Appendix A. SCBM Runtime Data Structures and API Reference

This appendix documents the SCBM runtime interface as implemented in the supplied C definitions. It describes observable behavior of the code, including the distinctions between success-driven backtracking and complete-failure backtracking. Unless stated otherwise, `x` and `y` are **proof-sequence list indices**, `th` is the thread index, and an *entity* is an index into the predicate-object tables. `NIL` denotes the runtime's null-list sentinel.

### A.1. Storage model and object layout

SCBM separates **list nodes** (their position in a proof sequence) from **predicate objects** (their executable label and saved state):

```c
typedef struct bidirectional {
    int back;
    int front;
    int entity;
} bidirectional;

#define LISTSIZE 50000
#define OBJSIZE  50000

static bidirectional blist[LISTSIZE][THREADSIZE];
static int   proof_obj[OBJSIZE][SCBM_ELT_SIZE][THREADSIZE];
static void *proof_goto[OBJSIZE][THREADSIZE];

int lp[THREADSIZE];       /* last allocated list index */
int op[THREADSIZE];       /* last allocated object index */
int pc[THREADSIZE];       /* current proof-sequence node */
int proof[THREADSIZE];    /* proof counter */
int call_flag[THREADSIZE];
```

- `blist[node][th]` records the links and entity of a proof-sequence node.
- `proof_obj[entity][field][th]` records the state belonging to that entity.
- `proof_goto[entity][th]` is its executable C label address (used with computed `goto`).
- `lp` and `op` are allocation high-water indices for the two tables. Rewinding them makes subsequently allocated indices reusable; it does **not** clear their old contents.
- `pc` identifies the current node, not a machine-code instruction address.
- All these arrays are statically allocated and indexed by `th`; thread correctness additionally depends on the surrounding runtime.

The object layout begins with 64 general-purpose integer slots (`DATA_SIZE = 64`), followed by named SCBM fields:

| Field | Meaning in the supplied implementation |
| --- | --- |
| `SP_SCBM` | Saved variable-binding state; passed to `Junbind` on release. |
| `CHOICE_SCBM` | Current clause/alternative counter. |
| `WP_SCBM` | Saved working-area pointer. |
| `AC_SCBM` | Saved allocation/argument counter (`Jget_ac` / `Jset_ac`). |
| `ARGLIST_SCBM` | Saved predicate argument list. |
| `LABEL_SCBM` | Reserved named slot; not accessed by these API functions. Executable addresses are held in `proof_goto`. |
| `PROP_SCBM` | Predicate category (`BUILTIN`, `NONDET`, `DET`, `TAIL`, `DYN`). |
| `FIRST_SCBM` | Restoration target (a list-node index), or `NIL`. |
| `LP_SCBM` | Saved list allocation boundary for restoration. |
| `OP_SCBM` | Saved object allocation boundary for restoration. |

The category constants are `BUILTIN = 0`, `NONDET = 1`, `DET = 2`, `TAIL = 3`, and `DYN = 4`. The constructors below directly create only `NONDET` and `DET` objects; the other categories are declared here but their constructors and execution rules are not specified by this code.

**Direction convention.** Following `back` advances through the proof sequence in its normal execution order; following `front` walks toward earlier nodes, which is the direction used in backtracking searches. Thus `front` and `back` are not interchangeable generic pointer names.

### A.2. List construction and navigation

| API | Signature | Contract |
| --- | --- | --- |
| `Scons` | `int Scons(int entity, int y, int th)` | Allocate a new list node with the given entity, set its `front` to `NIL` and `back` to `y`, and, if `y != NIL`, set `y.front` to the new node. Return the new node index. |
| `Sconc` | `int Sconc(int x, int y, int th)` | Join the tail node `x` to the head node `y`: set `x.back = y` and `y.front = x` where applicable. If either is `NIL`, update the non-null node's corresponding link. Return `y` (including `NIL` if `y == NIL`). |
| `Sback` | `int Sback(int x, int th)` | Return `blist[x][th].back`. |
| `Sfront` | `int Sfront(int x, int th)` | Return `blist[x][th].front`. |
| `Sentity` | `int Sentity(int x, int th)` | Return `blist[x][th].entity`. |
| `Sreplace` | `int Sreplace(int x, int entity, int th)` | Allocate a new node bearing `entity` at the same position as `x`, reconnect its two neighbors to the new node, and return the new node index. Primarily used for `call/1`. |

`Scons` and `Sreplace` increment `lp[th]` and report a resource error if the list capacity would be exceeded. Neither function is a general-purpose heap allocator. In particular, `Sreplace` **does not modify** the old node; it reconnects its neighbors to a newly allocated node, so callers must update references such as `pc` to the return value. The implementation writes through both neighboring indices in `Sreplace` without explicit `NIL` checks; correct use therefore depends on the runtime's sentinel representation or on caller-established boundary conditions.

For a one-element clause body, the generated `append/3` code uses:

```c
front = Sfront(pc[th], th);
back  = Sback(pc[th], th);
back  = Scons(body[0][th], back, th);
Sconc(front, back, th);
pc[th] = back;
```

This illustrates **body expansion by splicing**. It is distinct from `Sreplace`, which substitutes a single node and is used in the `call/1` path.

### A.3. Object construction and FIRST markers

**`Smake_nondet(void *label, int n, int th) -> int`** allocates a new object and returns its entity index. It sets `proof_goto` to `label`, initializes `CHOICE_SCBM` to zero, and sets `PROP_SCBM` to `NONDET`. It records allocation boundaries as follows:

```c
saved_LP = (n == -1) ? lp[th] : lp[th] + n;
saved_OP = op[th];   /* after incrementing op */
```

Its `FIRST_SCBM` initialization is conditional:

| Condition | Stored `FIRST_SCBM` |
| --- | --- |
| `n == 0` | Current `pc[th]` (the node to restore). |
| `n != 0` and `call_flag[th] != 0` | Inherit the current node's `FIRST_SCBM`. |
| Otherwise | `NIL`. |

These tests are evaluated in that order. Thus `n` is not merely a Boolean flag: it changes the saved list boundary and, for zero, marks a restoration point. In the generated `append/3`, `n = -1` is used for the initial predicate object, while `n = 0` is used for the expanded recursive body.

**`Smake_det(void *label, int n, int th) -> int`** allocates an entity, stores its executable label, and sets `PROP_SCBM = DET`. It sets `FIRST_SCBM` to the current `pc` only when `n == 0`; otherwise it sets `FIRST_SCBM = NIL`. Unlike `Smake_nondet`, this constructor does **not** initialize `CHOICE_SCBM`, `LP_SCBM`, or `OP_SCBM` in the supplied code. Consequently, any execution path that restores boundaries from a DET object must ensure those values have been correctly established elsewhere before they are read; their correctness cannot be inferred from this constructor alone.

Both object constructors increment `op[th]` and signal a resource error on object-table overflow. Neither clears the entire allocated object record.

### A.4. Property and restoration-target inspection

| API | Signature | Contract |
| --- | --- | --- |
| `Snondet` | `int Snondet(int x, int th)` | Return `1` iff the current node's object's `PROP_SCBM` equals `NONDET`; otherwise return `0`. |
| `Sfirst` | `int Sfirst(int x, int th)` | Return `1` iff its `FIRST_SCBM` field is not `NIL`; otherwise return `0`. |
| `Sget_first` | `int Sget_first(int x, int th)` | Return the raw list index saved in `FIRST_SCBM`. |

A non-`NIL` `FIRST_SCBM` does **not** mean that the current node is itself the first node in the list. It means that this node carries a **target for restoration**: the earlier node that must be reconnected after discarding an expanded body. The distinction is essential to understanding the backtracking functions.

### A.5. Choice and argument state

| API | Signature | Contract |
| --- | --- | --- |
| `Sget_choice` | `int Sget_choice(int th)` | Return the current object's `CHOICE_SCBM`. |
| `Sinc_choice` | `void Sinc_choice(int th)` | Increment the current object's `CHOICE_SCBM`. |
| `Sreset_choice` | `void Sreset_choice(int th)` | Set the current object's `CHOICE_SCBM` to zero. |
| `Ssave_arg` | `void Ssave_arg(int arglist, int th)` | Save `arglist` in `ARGLIST_SCBM` of the entity indexed by the **current `op[th]`**. |
| `Sget_arg` | `int Sget_arg(int th)` | Return the argument list of the entity referenced by **current `pc[th]`**. |

The `Ssave_arg` / `Sget_arg` asymmetry is deliberate in this implementation: the first operates on the most recently allocated object, while the second operates on the object selected by `pc`. Generated code must call `Ssave_arg` at the correct point in object construction so that the intended entity receives the arguments.

### A.6. State checkpoints and release

**`Sset_state(int th)`** saves three values into the current object's fields:

```c
SP_SCBM = Jget_sp(th);
AC_SCBM = Jget_ac(th);
WP_SCBM = Jget_wp(th);
```

**`Srelease(int th)`** restores the corresponding execution state:

```c
Junbind(saved_SP, th);
Jset_ac(saved_AC, th);
Jset_wp(saved_WP, th);
```

The binding undo, allocation/argument counter, and working-area restoration here are **separate from** proof-sequence allocation-pointer restoration. Specifically, `Srelease` does not modify `lp[th]` or `op[th]`. Those pointers are reset by the `FIRST` restoration branches of the backtracking functions in this code. `Srelease` assumes the current object's saved checkpoint is valid.

### A.7. Backtracking and proof-sequence restoration

There are two backtracking entry points, and **they are not equivalent**.

**`Sbacktrack1(int x, int th) -> int`: backtracking after success.**

1. If `x` carries a `FIRST` target **and is not NONDET**, restore immediately.
2. Otherwise, walk toward earlier nodes by repeatedly following `front`.
3. If a `NONDET` node is encountered, return it **without restoring** the sequence; its alternative(s) can still be attempted.
4. If a node carrying `FIRST` is encountered before such a NONDET node, restore the earlier node designated by `FIRST` and return that node.
5. If the search reaches `NIL`, return `NIL`.

**`Sbacktrack2(int x, int th) -> int`: backtracking after complete failure.**

1. If the starting node carries `FIRST`, restore its designated target **immediately**, even when the starting node is NONDET.
2. Otherwise, start at `Sfront(x, th)` (skipping the completely failed current node), and walk toward earlier nodes.
3. Return the first encountered `NONDET` node without restoring, or restore and return the first encountered `FIRST` target.
4. Return `NIL` if no such node exists.

The common restoration operation performed in these functions is:

```c
lp[th] = proof_obj[blist[x][th].entity][LP_SCBM][th];
op[th] = proof_obj[blist[x][th].entity][OP_SCBM][th];
front   = Sfront(x, th);
first   = Sget_first(x, th);
Sconc(front, first, th);
return first;
```

Here `x` denotes the node carrying the `FIRST` marker at the point of restoration. Reconnecting `front` directly to `first` removes the expanded segment from the active proof sequence. Restoring `lp` and `op` makes the allocated list/object space beyond the recorded boundaries available for reuse. **It does not zero or independently free every object**; the validity of this pointer rewind rests on the saved boundaries and the absence of surviving references to reclaimed entries.

The practical distinction is that `Sbacktrack1` preserves a retryable current NONDET node, whereas `Sbacktrack2` treats its initial node as already exhausted. The special `FIRST` cases encode the additional need to collapse a body expansion back to its original predicate before resuming execution.

### A.8. Cut operation

**`Scut(int x, int th) -> int`** performs the following steps:

1. Save `back = Sback(x, th)`, the node after the current cut position.
2. Walk toward earlier nodes using `front` until a node carrying a non-`NIL` `FIRST_SCBM` is found.
3. Take `front = Sfront(found_node, th)`.
4. Connect `front` directly to the previously saved `back` using `Sconc(front, back, th)`.
5. Return `back` as the continuation node.

Thus `Scut` **splices a segment out of the active proof sequence**, pruning the portion between the surrounding links. This particular function does not itself rewind `lp` or `op`, and it does not test `NONDET` while searching. It assumes that a suitable `FIRST` marker is reachable; otherwise `front` would not be initialized before `Sconc`. The exact logical scope of cut also depends on where the compiler places `FIRST` markers and how generated code invokes `Scut`.

### A.9. Counters and debugging

- **`Sinc_proof(int th) -> int`** increments `proof[th]` and returns `YES`. This is a proof-step accounting operation, not a proof-sequence edit.
- **`Sdump(int th) -> void`** walks from `pc` toward the beginning of the active proof sequence via `front`, then prints each node while following `back`. It reports the executable label, choice, predicate property, saved checkpoints, `FIRST`, argument list, node/entity indices, links, and whether the node is current. It is a diagnostic routine, not part of normal execution semantics. Its simple property display treats every non-`NONDET` object as `det`, so it does not fully distinguish `BUILTIN`, `TAIL`, and `DYN`.

### A.10. Operational invariants and limitations

The API depends on several conditions that should be stated explicitly in a formal specification:

1. **Valid indices and sentinel behavior.** Callers must supply valid nodes/entities and respect the runtime's `NIL` convention, especially where a function accesses neighboring nodes directly.
2. **Correct splice boundaries.** `Sconc(x, y)` expects appropriate boundary nodes; it does not search for the tail of a sublist or the head of another.
3. **Valid saved state.** `Srelease` and the restoration branches require checkpoints and allocation boundaries to have been established for the relevant entity.
4. **FIRST is a restoration link.** It denotes the original predicate node to reconnect, not merely a Boolean “first clause” flag.
5. **Lifetime safety for `lp`/`op`.** Rewinding allocation pointers is safe only when no surviving active continuation needs entries beyond the saved boundary.
6. **No automatic initialization of every slot.** Constructors initialize only the fields shown in their bodies. Reused table entries can contain older values in other fields.
7. **Implementation-specific control transfer.** `proof_goto` contains C label addresses, requiring compiler support for labels as values and computed `goto`.

This appendix specifies the API **visible in the supplied source**. It does not claim to define the internals of `Junbind`, `Jget_sp`, the object allocation conventions outside these functions, or any additional standalone garbage collector such as `Scollect_proof` unless their definitions are supplied. The explicit list/object reclamation behavior demonstrated here is the `lp`/`op` rewind performed during `FIRST` restoration.