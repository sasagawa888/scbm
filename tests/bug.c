#include "jump.h"
static int c_color(int arglist, int rest, int th);
static int c_foo(int arglist, int rest, int th);
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th);
static int c_color(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(0,n,0,arglist,rest,th));
}

static int c_foo(int arglist, int rest, int th){
int arg1,varX,n,body,save1,save2,save3,goal,cont,clause,res;
Jinc_proof(th);
n = Jarity_count(arglist);
save1 = Jget_wp(th);
save2 = Jget_sp(th);
save3 = Jget_ac(th);
if(n == 1){
arg1 = Jcar(arglist);
varX = Jmakevariant(th);
arg1 = Jcar(arglist);
if(Junify_var(arg1,varX,th) == YES)
if (Jcall_det(Jmakesys("write"),Jwcons(varX,NIL,th),th) == YES)

return(Jprove_all(rest,Jget_sp(th),th));
Jset_ac(save3,th);
Junbind(save2,th);
Jset_wp(save1,th);
return(NO);}
}
void init_tpredicate(void){
(deftpred)("color",c_color,1,1);
(deftpred)("foo",c_foo,1,2);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number;
switch(pred){
case 0: goto color;
}
loop:
next = proof_goto[blist[lp[th]][th].entity][th];
color:
switch(arity){
case 1: goto color_1entry;
default: goto allfail;
}
color_1entry:
pc[th] = Scons(Smake_nondet(&&color_1,th),th);
color_1:
Jinc_proof(th);
switch(clause){
case 0: goto color_1_0;
case 1: goto color_1_1;
case 2: goto color_1_2;
case 3: goto color_1_3;
default: goto allfail;
}
color_1_0:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("red"),th) == YES)
{
goto success;
}
color_1_1:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("green"),th) == YES)
{
goto success;
}
color_1_2:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("blue"),th) == YES)
{
goto success;
}
color_1_3:
Srelease(th);
goto allfail;

success:
if(Sback(pc[th],th) == NIL){
if(Jprove_all(rest,Jget_sp(th),th) == YES) return(YES);
printf("%d ",pc[th]);
if (pc[th] == NIL) return(NO);
else {clause = Sget_choice(pc[th]); goto loop;}}
else{pc[th]=Sback(pc[th],th);goto loop;}

allfail:
if(Sfront(pc[th],th) == NIL) return(NO);
pc[th] = Sbacktrack(Sfront(pc[th],th),th);
if(pc[th] == NIL) return(NO);
else goto loop;
}
