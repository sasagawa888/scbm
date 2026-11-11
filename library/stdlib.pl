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