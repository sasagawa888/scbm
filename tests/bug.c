#include "jump.h"
static int c_color(int arglist, int rest, int th);
static int c_foo(int arglist, int rest, int th);
static int c_likes(int arglist, int rest, int th);
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
static int c_likes(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(1,n,0,arglist,rest,th));
}

void init_tpredicate(void){
(deftpred)("color",c_color,1,1);
(deftpred)("foo",c_foo,1,2);
(deftpred)("likes",c_likes,2,1);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,front,back,i,varX;
int body[10][THREADSIZE];
switch(pred){
case 0: goto color;
case 1: goto likes;
}
loop:
next = proof_goto[blist[pc[th]][th].entity][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto *next;
color:
switch(arity){
case 1: goto color_1entry;
default: goto allfail;
}
likes:
switch(arity){
case 2: goto likes_2entry;
default: goto allfail;
}
color_1entry:
pc[th] = Scons(Smake_nondet(&&color_1,-1,th),NIL,th);
Ssave_arg(arglist,th);
color_1:
printf("color1");Jprint(Jderef(arglist,th));printf("  ");Jinc_proof(th);
switch(clause){
case 0: goto color_1_0;
case 1: goto color_1_1;
case 2: goto color_1_2;
case 3: goto color_1_3;
default: goto allfail;
}
likes_2entry:
pc[th] = Scons(Smake_nondet(&&likes_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
likes_2:
printf("likes2");Jprint(Jderef(arglist,th));printf("  ");Jinc_proof(th);
switch(clause){
case 0: goto likes_2_0;
case 1: goto likes_2_1;
case 2: goto likes_2_2;
case 3: goto likes_2_3;
case 4: goto likes_2_4;
case 5: goto likes_2_5;
case 6: goto likes_2_6;
case 7: goto likes_2_7;
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

likes_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("kim"),th) == YES && Junify_atom(arg2,Jmakeconst("robin"),th) == YES)
{
goto success;
}
likes_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("sandy"),th) == YES && Junify_atom(arg2,Jmakeconst("lee"),th) == YES)
{
goto success;
}
likes_2_2:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("sandy"),th) == YES && Junify_atom(arg2,Jmakeconst("kim"),th) == YES)
{
goto success;
}
likes_2_3:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("robin"),th) == YES && Junify_atom(arg2,Jmakeconst("cats"),th) == YES)
{
goto success;
}
likes_2_4:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("sandy"),th) == YES && Junify_var(arg2,varX,th) == YES)
{
likes_2_4_0_join:
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("cats"),NIL,th),th);
body[0][th] = Smake_nondet(&&likes_2_4_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto likes_2_4_1_join;
likes_2_4_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto likes_2;

likes_2_4_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
likes_2_5:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("kim"),th) == YES && Junify_var(arg2,varX,th) == YES)
{
likes_2_5_0_join:
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("lee"),NIL,th),th);
body[0][th] = Smake_nondet(&&likes_2_5_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto likes_2_5_1_join;
likes_2_5_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto likes_2;

likes_2_5_1_join:
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("kim"),NIL,th),th);
body[1][th] = Smake_nondet(&&likes_2_5_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto likes_2_5_2_join;
likes_2_5_1:
varX= proof_obj[Sentity(pc[th],th)][0][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto likes_2;

likes_2_5_2_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=1;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
likes_2_6:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES && Junify_var(arg2,varX,th) == YES)
{
goto success;
}
likes_2_7:
Srelease(th);
goto allfail;

success:
if(Sback(pc[th],th) == NIL){
if(Jprove_all(rest,Jget_sp(th),th) == YES) return(YES);
pc[th] = Sbacktrack1(pc[th],th);
if (pc[th] == NIL) return(NO);
else goto loop;}
else{pc[th]=Sback(pc[th],th);goto loop;}

allfail:
printf("allfail ");Sdump(th);Sreset_choice(th);
failse:
if(Sfront(pc[th],th) == NIL) return(NO);
pc[th] = Sbacktrack2(Sfront(pc[th],th),th);
if(pc[th] == NIL) return(NO);
else goto loop;
}
