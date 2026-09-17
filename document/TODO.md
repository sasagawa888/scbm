# TODO

The preparations for testing the new approach are now complete. The remaining task is to implement failure continuations according to the original plan.

No failure continuation is generated at the beginning of a predicate body. Instead, the information required to construct a failure continuation, such as the stack pointer, is obtained from the success continuation.
2026/9/18