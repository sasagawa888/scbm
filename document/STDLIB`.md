# SCBM-Prolog Standard Library (`stdlib`)

## Overview

The `stdlib` module provides a small collection of commonly used predicates written in Prolog rather than implemented as built-ins. This keeps the SCBM-Prolog core lightweight and makes the library's behavior easy to inspect, modify, and compile together with user programs.

The documentation below describes **the supplied implementation**, including its operational limitations. It does not imply full ISO Prolog compatibility.

## Importing the Library

```prolog
?- use_module(stdlib).
yes
```

The module exports the following predicates:

```prolog
:- module(stdlib, [append/3, between/3, member/2,
                  select/3, repeat/0, length/2]).
```

### Predicate summary

| Predicate | Purpose | Backtracking |
| --- | --- | --- |
| `append/3` | Concatenate lists or relate a list to its prefix and suffix | Enumerates possible splits |
| `between/3` | Enumerate integers in an inclusive range | Enumerates integers in ascending order |
| `member/2` | Relate an element to a list | Enumerates matching elements |
| `select/3` | Remove one occurrence of an element from a list | Enumerates possible removals |
| `repeat/0` | Succeed indefinitely on backtracking | Unbounded |
| `length/2` | Compute the length of a finite, proper list | Deterministic for an instantiated finite list |

## Predicate Reference

### `append(?Prefix, ?Suffix, ?List)`

**Description:** `List` is the concatenation of `Prefix` and `Suffix`. It can also enumerate all prefix/suffix splits of a given proper list.

**Examples:**

```prolog
?- append([a,b], [c], X).
X = [a,b,c].

?- append(X, Y, [a,b]).
X = [],    Y = [a,b] ;
X = [a],   Y = [b] ;
X = [a,b], Y = [].
```

**Definition:**

```prolog
append([], Ys, Ys).
append([X|Xs], Ys, [X|Zs]) :-
    append(Xs, Ys, Zs).
```

### `between(+Low, +High, ?Value)`

**Description:** Relates `Value` to an integer between `Low` and `High`, inclusive. With an unbound `Value`, solutions are produced in ascending order. If `Low > High`, the predicate fails.

**Arguments:** `Low` and `High` must be instantiated to suitable integers before the call. `Value` may be instantiated or unbound.

**Examples:**

```prolog
?- between(1, 3, X).
X = 1 ;
X = 2 ;
X = 3.

?- between(3, 1, X).
no

?- between(1, 5, 4).
yes
```

**Definition:**

```prolog
between(L, H, L) :-
    L =< H.
between(L, H, X) :-
    L < H,
    L1 is L + 1,
    between(L1, H, X).
```

**Note:** This implementation advances one integer at a time. A bound `Value` does not enable a direct jump to that integer.

### `member(?Element, ?List)`

**Description:** Succeeds if `Element` is a member of `List`. On backtracking, it visits list positions from left to right. Duplicate elements may therefore produce duplicate solutions.

**Examples:**

```prolog
?- member(X, [red, green, blue]).
X = red ;
X = green ;
X = blue.

?- member(a, [a, b, a]).
yes ;
yes.
```

**Definition:**

```prolog
member(X, [X|_]).
member(X, [_|Xs]) :-
    member(X, Xs).
```

### `select(?Element, ?List, ?Rest)`

**Description:** `Rest` is obtained by removing exactly one occurrence of `Element` from `List`. On backtracking, each possible removal is considered from left to right.

**Examples:**

```prolog
?- select(X, [a,b,c], Rest).
X = a, Rest = [b,c] ;
X = b, Rest = [a,c] ;
X = c, Rest = [a,b].

?- select(b, [a,b,c], Rest).
Rest = [a,c].
```

**Definition:**

```prolog
select(X, [X|Xs], Xs).
select(X, [Y|Ys], [Y|Zs]) :-
    select(X, Ys, Zs).
```

**Note:** When a list contains repeated elements, different removal positions can yield identical results.

### `repeat`

**Description:** Succeeds once immediately and provides another success whenever execution backtracks into it. The sequence of successes has no natural end.

**Example:**

```prolog
?- repeat.
yes ;
yes ;
yes ;
...
```

**Definition:**

```prolog
repeat.
repeat :- repeat.
```

**Caution:** A query that keeps requesting more answers from `repeat/0` does not terminate on its own. Use it only when the surrounding program supplies an appropriate stopping condition or control mechanism.

### `length(+List, ?Length)`

**Description:** Computes the number of elements in a finite, proper list. `Length` is unified with that number.

**Examples:**

```prolog
?- length([a,b,c], N).
N = 3.

?- length([], N).
N = 0.

?- length([a,b], 2).
yes

?- length([a,b], 3).
no
```

**Definition:**

```prolog
length([], 0).
length([_|Xs], N) :-
    length(Xs, M),
    N is M + 1.
```

**Important limitation:** Unlike the relational `length/2` provided by some Prolog systems, this definition is intended for **length calculation**, not list generation. For example, `length(List, 3)` with `List` unbound does not construct a three-element list: recursive descent can continue indefinitely because the arithmetic step is performed only *after* the recursive call returns. Similarly, `length(List, N)` with both arguments unbound does not provide practical finite enumeration of lists.

## Operational Notes

- These predicates are ordinary Prolog definitions, not special instructions in the SCBM-Prolog runtime.
- Backtracking behavior follows the order of the clauses and goals shown above.
- The examples show logical answers in a conventional Prolog style. Exact prompts, continuation characters, and variable formatting may differ in the SCBM-Prolog REPL.
- List-processing predicates are primarily intended for proper lists; calls with free or partially instantiated lists can create unbounded search spaces.
- The library intentionally favors small, readable definitions over specialized optimizations or full compatibility with every ISO Prolog library predicate.

## Complete Source

```prolog
% standard library
:- module(stdlib,[append/3,between/3,member/2,select/3,repeat/0,length/2]).

append([], Ys, Ys).
append([X|Xs], Ys, [X|Zs]) :-
    append(Xs, Ys, Zs).

between(L, H, L) :-
    L =< H.
between(L, H, X) :-
    L < H,
    L1 is L + 1,
    between(L1, H, X).

member(X,[X|_]).
member(X,[_|Xs]) :-
    member(X,Xs).

select(X,[X|Xs],Xs).
select(X,[Y|Ys],[Y|Zs]) :-
    select(X,Ys,Zs).

repeat.
repeat :- repeat.

length([], 0).
length([_|Xs], N) :-
    length(Xs, M),
    N is M + 1.