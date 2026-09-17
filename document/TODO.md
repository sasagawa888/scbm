# TODO

The preparations for testing the new approach are now complete. The remaining task is to implement failure continuations according to the original plan.

No failure continuation is generated at the beginning of a predicate body. Instead, the information required to construct a failure continuation, such as the stack pointer, is obtained from the success continuation.
2026/9/18

A failure continuation is generated only when the `B` argument is not an empty list. This indicates that a nondeterministic predicate has already occurred earlier in the body.

At the beginning of the body, `B` is an empty list, so no failure continuation is generated there.

Whether a failure continuation should be generated depends on the preceding predicate, not on the type of the predicate currently being executed.
For now, disjunctions are ignored. The immediate goal is to ensure that ordinary conjunctions and cut (`!`) work correctly.

Specifically, the initial test cases are `queens` and `qsort`.

