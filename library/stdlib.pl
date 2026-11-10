% standard library 
:- module(stdlib,[append/3,between/3]).


append([], Ys, Ys).
append([X|Xs], Ys, [X|Zs]) :-
    append(Xs, Ys, Zs).


between(L, H, L) :-
    L =< H.
between(L, H, X) :-
    L < H,
    L1 is L + 1,
    between(L1, H, X).
