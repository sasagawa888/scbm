


color(red).
color(green).
color(blue).

foo(X) :- write(X).


likes(kim,robin).
likes(sandy,lee).
likes(sandy,kim).
likes(robin,cats).
likes(sandy,X) :- likes(X,cats).
likes(kim,X) :- likes(X,lee),likes(X,kim).
likes(X,X).

fact(0,1).
fact(N,X) :-
        N1 is N-1,
        fact(N1,X1),
        X is N*X1.


select1(X,[X|Xs],Xs).
select1(X,[Y|Ys],[Y|Zs]) :-
    select1(X,Ys,Zs).


perm1([],[]).
perm1(Xs,[X|Ys]) :-
    select1(X,Xs,Zs),
    perm1(Zs,Ys).

