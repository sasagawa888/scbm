% standard library 
:- module(stdlib,[append/3]).


append([], Ys, Ys).
append([X|Xs], Ys, [X|Zs]) :-
    append(Xs, Ys, Zs).

