# SCBM-Prolog v1.11 — Internal API Reference

**Status:** Experimental implementation documentation  
**Scope:** SCBM proof-sequence representation and operations in the supplied C source  
**Version:** 1.11

## 1. Overview

SCBM represents execution state as a **proof sequence** built from a bidirectional linked list. Each list node references a proof object, which holds execution metadata such as determinism, clause selection, saved runtime pointers, the original sequence position, and arguments. A separate table stores the continuation label for each proof object.

The API supports list construction and reconnection, proof-object creation, success-driven backtracking, reconstruction after complete failure (`allfail`), restoration of runtime state, clause-choice management, and debugging.

This reference describes the **behavior visible in the supplied implementation**, not a stable public API. Callers must preserve the invariants discussed below.

## 2. Data Structures and Constants

```c
typedef struct bidirectional {
    int back;
    int front;
    int entity;
} bidirectional;

#define LISTSIZE 10000
#define OBJSIZE 10000
#define NONDET  1
#define DET     2

static bidirectional blist[LISTSIZE][THREADSIZE];
static int proof_obj[OBJSIZE][SCBM_ELT_SIZE][THREADSIZE];
static void *proof_goto[OBJSIZE][THREADSIZE];
int lp[THREADSIZE];  /* list allocator cursor */
int op[THREADSIZE];  /* proof-object allocator cursor */
int pc[THREADSIZE];  /* current proof-sequence node */
```

| Name | Purpose |
|---|---|
| `blist[node][th]` | Doubly linked proof-sequence node. `entity` indexes a proof object. |
| `back` | Link followed by `Sback()` and `Sdump()` when traversing the sequence. |
| `front` | Opposite link, followed by `Sfront()` when searching toward the sequence head. |
| `proof_obj[obj][field][th]` | Metadata for a proof object. |
| `proof_goto[obj][th]` | Saved computed-goto label/address for a proof object. |
| `lp[th]` | Last allocated list-node index. |
| `op[th]` | Last allocated proof-object index. |
| `pc[th]` | Current list-node index, **not** a proof-object index. |
| `NIL` | Sentinel for an absent node/link or absent saved `FIRST` value; defined elsewhere. |
| `th` | Thread index selecting a separate runtime state. |

The metadata fields referenced here are `CHOICE_SCBM`, `PROP_SCBM`, `SP_SCBM`, `AC_SCBM`, `WP_SCBM`, `FIRST_SCBM`, and `ARGLIST_SCBM`. Their numeric indices and `SCBM_ELT_SIZE` are defined elsewhere.

## 3. API Conventions

- `x` and `y` denote list-node indices for link/traversal operations, except that the `x` passed to `Scons()`, `Smake_nondet()`, and `Smake_det()` has a different meaning, as described below.
- `th` selects the thread-specific arrays and VM state.
- `pc[th]` must identify a valid current list node before functions that dereference it are called.
- `Sentity(node, th)` converts a list-node index to its proof-object index.
- `Scons(entity, next, th)` allocates a list node; `Smake_*()` allocates a proof object. The caller is responsible for combining them correctly.
- All objects and nodes are stored in fixed-capacity arrays. These functions do not implement garbage collection or reclamation.

## 4. Bidirectional List API

### `Sconc(int x, int y, int th) -> int`

Connects list node `x` to list node `y` by setting `x.back = y` and `y.front = x` when both are non-`NIL`. If one endpoint is `NIL`, the corresponding outer link of the other node is set to `NIL`. Returns `y` (or `NIL` if both arguments are `NIL`).

**Important:** This routine changes links in place. It does not allocate nodes, verify node indices, or repair other existing links. Callers must ensure reconnection preserves the intended sequence.

### `Scons(int x, int y, int th) -> int`

Allocates a new list node, stores proof-object index `x` in its `entity` field, sets `back = y` and `front = NIL`, and, if `y != NIL`, sets `y.front` to the new node. Returns the new list-node index. Checks for list-capacity overflow and raises `Jerrorcomp(RESOURCE_ERR, ...)` if the limit is reached.

### `Sback(int x, int th) -> int`
Returns `blist[x][th].back`.

### `Sfront(int x, int th) -> int`
Returns `blist[x][th].front`.

### `Sentity(int x, int th) -> int`
Returns the proof-object index stored in `blist[x][th].entity`.

## 5. Proof-Object Inspection

### `Sfirst(int x, int th) -> int`
Returns `1` when the object referenced by list node `x` has `FIRST_SCBM != NIL`, otherwise `0`.

### `Sget_first(int x, int th) -> int`
Returns the referenced object's `FIRST_SCBM` field. In this implementation it is either a saved `pc[th]` value or `NIL`.

### `Snondet(int x, int th) -> int`
Returns `1` if the referenced object's `PROP_SCBM` field equals `NONDET`, otherwise `0`.

## 6. Backtracking API

### `Sbacktrack1(int x, int th) -> int` — Backtracking after success

Walks from list node `x` along `front` links until it finds a node whose proof object is `NONDET`. Returns that node index, or `NIL` when none is found. It **does not** update `pc[th]`, restore variable state, or advance the clause choice. The caller performs the subsequent control flow.

### `Sbacktrack2(int x, int th) -> int` — Reconstruction on `allfail`

If `Sfirst(x, th)` is false, returns `NIL`. Otherwise:

1. Reads `front = Sfront(x, th)`.
2. Reads `first = Sget_first(x, th)`.
3. Calls `Sconc(front, first, th)` to reconnect the saved proof sequence.
4. Returns `first` as the node from which execution can resume.

This function **does not** modify `pc[th]` itself. Under the intended control flow, a `NIL` result is handled by the caller as `NO` (search exhausted). The supplied design uses a `NIL` initial `FIRST` value for the initial nondeterministic object, while nested/restorable objects record a previous `pc`.

**Precondition:** `allfail` dispatch must pass the appropriate nondeterministic object/node, and the saved `FIRST` node must still be valid. The function does not independently search for such an object or validate the detached segment.

## 7. Proof-Object Creation

### `Smake_nondet(void *x, int n, int th) -> int`

Allocates a proof object and stores `x` as its continuation label in `proof_goto`. Initializes:

- `CHOICE_SCBM = 0`
- `PROP_SCBM = NONDET`
- `SP_SCBM = Jget_sp(th)`
- `AC_SCBM = Jget_ac(th)`
- `WP_SCBM = Jget_wp(th)`
- `FIRST_SCBM = pc[th]` if `n == 0`, otherwise `NIL`

Returns the new **proof-object index**. Raises a resource error if object storage is exhausted. The meaning of `n == 0` is defined by the caller/compiler protocol; here its immediate effect is to preserve the current proof-sequence node in `FIRST`.

### `Smake_det(void *x, int n, int th) -> int`

Allocates a proof object, saves continuation label `x`, sets `PROP_SCBM = DET`, and initializes `FIRST_SCBM` using the same `n == 0` rule. Returns the new proof-object index. It does **not** initialize `CHOICE`, `SP`, `AC`, or `WP` in the shown code.

**Note:** Newly allocated objects are not automatically inserted into the proof sequence. A caller normally uses the returned index with `Scons()`.

## 8. Runtime State and Clause Choice

### `Srelease(int th) -> void`

Restores runtime state from the proof object referenced by `pc[th]`:

```c
Junbind(saved_SP, th);
Jset_ac(saved_AC, th);
Jset_wp(saved_WP, th);
```

This releases bindings using the saved `SP` and restores `AC` and `WP`. It assumes those fields have been initialized for the current object (as in `Smake_nondet()`). It does not restore arguments or clause choice by itself.

### `Sget_choice(int th) -> int`
Returns the current object's `CHOICE_SCBM` value.

### `Sinc_choice(int th) -> void`
Increments the current object's `CHOICE_SCBM` value.

### `Sreset_choice(int th) -> void`
Sets the current object's `CHOICE_SCBM` value to zero.

### `Ssave_arg(int x, int th) -> void`
Stores argument-list representation `x` in `ARGLIST_SCBM` of the **most recently allocated proof object**, `op[th]`. It does not use `pc[th]`.

### `Sget_arg(int th) -> int`
Returns the `ARGLIST_SCBM` value of the object referenced by the **current list node**, `pc[th]`.

## 9. Diagnostics

### `Sdump(int th) -> void`

Prints the current `pc`, traverses `front` links to the head of the current proof sequence, then walks the sequence along `back` links and prints each node's:

- continuation-label address;
- clause choice;
- saved `SP`, `AC`, and `WP`;
- saved `FIRST` and argument list;
- list-node index and proof-object index;
- `back`/`front` links and whether the node is the current `pc`.

**Implementation note:** The supplied source prints `proof_goto[entity]` without a thread subscript, whereas the array is declared `proof_goto[OBJSIZE][THREADSIZE]`. To print the stored address for thread `th`, the expression should be `proof_goto[entity][th]`. The existing expression is a pointer to the row rather than the stored continuation address.

`Sdump()` assumes `pc[th]` is a valid list node; calling it with `pc[th] == NIL` would be unsafe as written.

## 10. Operational Outline

A typical compiled execution path follows this conceptual sequence:

1. Create a proof object with `Smake_nondet()` or `Smake_det()`.
2. Save its argument list with `Ssave_arg()` while it is still the most recently allocated object.
3. Insert the object into the bidirectional proof sequence with `Scons()` and update `pc[th]` as required by the caller.
4. On a successful solution when more answers are requested, locate a nondeterministic object with `Sbacktrack1()`; the caller restores the required state and resumes its next choice.
5. On `allfail`, call `Sbacktrack2()` on the appropriate node. A non-`NIL` return identifies the reconstructed restart node; `NIL` indicates termination under the caller's `NO` convention.

This is an explanatory outline, **not a complete standalone driver**; scheduling, computed-goto dispatch, and compiler-generated code are outside the supplied excerpt.

## 11. Constraints and Implementation Caveats

- **Experimental API:** Correct execution of PAIP's `likes/2` demonstrates useful behavior, but does not establish correctness for arbitrary programs.
- **Fixed capacity:** List and object storage each have a nominal capacity of 10,000 entries per thread. Actual usable indices depend on initial cursor values and reserved sentinels.
- **Array initialization:** The excerpt does not show initialization of `lp`, `op`, `pc`, object metadata, or the `NIL` sentinel; those are required elsewhere.
- **No bounds checks in accessors:** `Sback`, `Sfront`, `Sentity`, and most metadata operations require valid indices.
- **Field initialization differs by object type:** `Smake_det()` does not fill the runtime state fields used by `Srelease()`; calling `Srelease()` on such an object requires a separate guarantee.
- **List consistency:** `Sconc()` and `Scons()` mutate links directly. Unexpected shared nodes, stale links, or cycles can corrupt traversal or cause infinite loops in `Sdump()`.
- **Thread state:** Arrays are indexed by `th`, but the excerpt alone does not establish thread-safety for the external `J*` routines or coordinated access to shared resources.
- **Continuation labels:** `proof_goto` holds compiler-specific code addresses; validity depends on the generated-code and dispatch environment.

## 12. API Summary

| Function | Return | Primary responsibility |
|---|---|---|
| `Sconc(x,y,th)` | node index | Reconnect adjacent nodes |
| `Scons(x,y,th)` | node index | Allocate and link list node referencing object `x` |
| `Sback(x,th)` | node index | Read `back` link |
| `Sfront(x,th)` | node index | Read `front` link |
| `Sentity(x,th)` | object index | Resolve object from list node |
| `Sfirst(x,th)` | boolean `int` | Test saved first position |
| `Sget_first(x,th)` | node index / `NIL` | Retrieve saved first position |
| `Snondet(x,th)` | boolean `int` | Test nondeterminism flag |
| `Sbacktrack1(x,th)` | node index / `NIL` | Search nondeterministic node after success |
| `Sbacktrack2(x,th)` | node index / `NIL` | Reconnect sequence after `allfail` |
| `Smake_nondet(x,n,th)` | object index | Allocate nondeterministic proof object |
| `Smake_det(x,n,th)` | object index | Allocate deterministic proof object |
| `Srelease(th)` | `void` | Unbind/restore saved runtime pointers |
| `Sget_choice(th)` | integer | Read current clause choice |
| `Sinc_choice(th)` | `void` | Advance current clause choice |
| `Sreset_choice(th)` | `void` | Reset current clause choice |
| `Ssave_arg(x,th)` | `void` | Save arguments on latest allocated object |
| `Sget_arg(th)` | integer | Load current object's arguments |
| `Sdump(th)` | `void` | Print proof-sequence state |

---

*Based on the SCBM-Prolog v1.11 source excerpt supplied by the project author. This document describes the code as written and explicitly marks assumptions and potential implementation issues.*

