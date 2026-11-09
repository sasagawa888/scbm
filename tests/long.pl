% SCBM-Prolog unify_long regression tests

% Same long integer
long1(123456789012345).

% Different long integers
long2(123456789012345).
long2(123456789012346).

% Dereference
long3(X) :-
    X = Y,
    Y = 123456789012345.

% Repeated variable
long4(X) :-
    X = 123456789012345,
    X = 123456789012345.

% Different values - must fail
long5 :-
    123456789012345 = 123456789012346.

% Backtracking
long6(123456789012345).
long6(987654321098765).
long6(111111111111111).

% Nested structure
long7(f(123456789012345)).

% Anonymous variable
long8(123456789012345).