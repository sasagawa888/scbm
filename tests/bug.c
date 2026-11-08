#include "jump.h"
static int c_color(int arglist, int rest, int th);
static int c_foo(int arglist, int rest, int th);
static int c_likes(int arglist, int rest, int th);
static int c_fact(int arglist, int rest, int th);
static int c_select1(int arglist, int rest, int th);
static int c_perm1(int arglist, int rest, int th);
static int c_test(int arglist, int rest, int th);
static int c_test1(int arglist, int rest, int th);
static int c_queen(int arglist, int rest, int th);
static int c_queen2(int arglist, int rest, int th);
static int c_qdelete(int arglist, int rest, int th);
static int c_nodiag(int arglist, int rest, int th);
static int c_append1(int arglist, int rest, int th);
static int c_between1(int arglist, int rest, int th);
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

static int c_fact(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(2,n,0,arglist,rest,th));
}

static int c_select1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(3,n,0,arglist,rest,th));
}

static int c_perm1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(4,n,0,arglist,rest,th));
}

static int c_test(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(5,n,0,arglist,rest,th));
}

static int c_test1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(6,n,0,arglist,rest,th));
}

static int c_queen(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(7,n,0,arglist,rest,th));
}

static int c_queen2(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(8,n,0,arglist,rest,th));
}

static int c_qdelete(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(9,n,0,arglist,rest,th));
}

static int c_nodiag(int arglist, int rest, int th){
int arg1,arg2,arg3,varD1,varN,varL,varB,varD,ano_2,ano_1,n,body,save1,save2,save3,goal,cont,clause,res;
save1 = Jget_wp(th);
save2 = Jget_sp(th);
save3 = Jget_ac(th);
Jinc_proof(th);
n = Jarity_count(arglist);
if(n == 3){
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
loop3:
ano_2 = Jmakevariant(th);
ano_1 = Jmakevariant(th);
if(Junify_nil(arg1,th) == YES && Junify_var(arg2,ano_2,th) == YES && Junify_var(arg3,ano_1,th) == YES)
{Junbind(save2,th);
Jset_ac(save3,th);
return(YES);}
varD1 = Jmakevariant(th);
varN = Jmakevariant(th);
varL = Jmakevariant(th);
varB = Jmakevariant(th);
varD = Jmakevariant(th);
if(Junify_pair(arg1,Jwlistcons(varN,varL,th),th) == YES && Junify_var(arg2,varB,th) == YES && Junify_var(arg3,varD,th) == YES)
if(Jnot_numeqp(Jderef(varD,th),Jminus(Jderef(varN,th),Jderef(varB,th),th)) && Jinc_proof(th)==YES)
if(Jnot_numeqp(Jderef(varD,th),Jminus(Jderef(varB,th),Jderef(varN,th),th)) && Jinc_proof(th)==YES)
if(Junify(varD1,Jplus(Jderef(varD,th),Jmakeint(1),th),th)==YES && Jinc_proof(th)==YES)
{
arg1 = Jcopy_work(Jderef(varL,th),th);
arg2 = Jcopy_work(Jderef(varB,th),th);
arg3 = Jcopy_work(Jderef(varD1,th),th);
Junbind(save2,th);
Jset_ac(save3,th);
goto loop3;
}
else return(NO);}
}
static int c_append1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(10,n,0,arglist,rest,th));
}

static int c_between1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(11,n,0,arglist,rest,th));
}

void init_tpredicate(void){
(deftpred)("color",c_color,1,1);
(deftpred)("foo",c_foo,1,2);
(deftpred)("likes",c_likes,2,1);
(deftpred)("fact",c_fact,2,1);
(deftpred)("select1",c_select1,3,1);
(deftpred)("perm1",c_perm1,2,1);
(deftpred)("test",c_test,0,1);
(deftpred)("test1",c_test1,0,1);
(deftpred)("queen",c_queen,2,1);
(deftpred)("queen2",c_queen2,3,1);
(deftpred)("qdelete",c_qdelete,4,1);
(deftpred)("nodiag",c_nodiag,3,3);
(deftpred)("append1",c_append1,3,1);
(deftpred)("between1",c_between1,3,1);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,front,back,i,ano_1,varA,varData,varH,varHistory,varL,varL1,varM,varN,varN1,varOut,varQ,varR,varT,varX,varX1,varXs,varY,varYs,varZs;
int body[10][THREADSIZE];
pc[th] = 0; lp[th] = 0; op[th] = 0;
switch(pred){
case 0: goto color;
case 1: goto likes;
case 2: goto fact;
case 3: goto select1;
case 4: goto perm1;
case 5: goto test;
case 6: goto test1;
case 7: goto queen;
case 8: goto queen2;
case 9: goto qdelete;
case 10: goto append1;
case 11: goto between1;
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
fact:
switch(arity){
case 2: goto fact_2entry;
default: goto allfail;
}
select1:
switch(arity){
case 3: goto select1_3entry;
default: goto allfail;
}
perm1:
switch(arity){
case 2: goto perm1_2entry;
default: goto allfail;
}
test:
switch(arity){
case 0: goto test_0entry;
default: goto allfail;
}
test1:
switch(arity){
case 0: goto test1_0entry;
default: goto allfail;
}
queen:
switch(arity){
case 2: goto queen_2entry;
default: goto allfail;
}
queen2:
switch(arity){
case 3: goto queen2_3entry;
default: goto allfail;
}
qdelete:
switch(arity){
case 4: goto qdelete_4entry;
default: goto allfail;
}
append1:
switch(arity){
case 3: goto append1_3entry;
default: goto allfail;
}
between1:
switch(arity){
case 3: goto between1_3entry;
default: goto allfail;
}
color_1entry:
pc[th] = Scons(Smake_nondet(&&color_1,-1,th),NIL,th);
Ssave_arg(arglist,th);
color_1:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto color_1_0;
case 1:goto color_1_1;
case 2:goto color_1_2;
case 3:goto color_1_3;
default: goto allfail;
}
likes_2entry:
pc[th] = Scons(Smake_nondet(&&likes_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
likes_2:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto likes_2_0;
case 1:goto likes_2_1;
case 2:goto likes_2_2;
case 3:goto likes_2_3;
case 4:goto likes_2_4;
case 5:goto likes_2_5;
case 6:goto likes_2_6;
case 7:goto likes_2_7;
default: goto allfail;
}
fact_2entry:
pc[th] = Scons(Smake_nondet(&&fact_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
fact_2:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto fact_2_0;
case 1:goto fact_2_1;
case 2:goto fact_2_2;
default: goto allfail;
}
select1_3entry:
pc[th] = Scons(Smake_nondet(&&select1_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
select1_3:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto select1_3_0;
case 1:goto select1_3_1;
case 2:goto select1_3_2;
default: goto allfail;
}
perm1_2entry:
pc[th] = Scons(Smake_nondet(&&perm1_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
perm1_2:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto perm1_2_0;
case 1:goto perm1_2_1;
case 2:goto perm1_2_2;
default: goto allfail;
}
test_0entry:
pc[th] = Scons(Smake_nondet(&&test_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
test_0:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test_0_0;
case 1:goto test_0_1;
default: goto allfail;
}
test1_0entry:
pc[th] = Scons(Smake_nondet(&&test1_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
test1_0:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test1_0_0;
case 1:goto test1_0_1;
default: goto allfail;
}
queen_2entry:
pc[th] = Scons(Smake_nondet(&&queen_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
queen_2:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto queen_2_0;
case 1:goto queen_2_1;
default: goto allfail;
}
queen2_3entry:
pc[th] = Scons(Smake_nondet(&&queen2_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
queen2_3:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto queen2_3_0;
case 1:goto queen2_3_1;
case 2:goto queen2_3_2;
default: goto allfail;
}
qdelete_4entry:
pc[th] = Scons(Smake_nondet(&&qdelete_4,-1,th),NIL,th);
Ssave_arg(arglist,th);
qdelete_4:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto qdelete_4_0;
case 1:goto qdelete_4_1;
case 2:goto qdelete_4_2;
default: goto allfail;
}
append1_3entry:
pc[th] = Scons(Smake_nondet(&&append1_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
append1_3:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto append1_3_0;
case 1:goto append1_3_1;
case 2:goto append1_3_2;
default: goto allfail;
}
between1_3entry:
pc[th] = Scons(Smake_nondet(&&between1_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
between1_3:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto between1_3_0;
case 1:goto between1_3_1;
case 2:goto between1_3_2;
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

fact_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_int(arg1,Jmakeint(0),th) == YES && Junify_int(arg2,Jmakeint(1),th) == YES)
{
goto success;
}
fact_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varN1 = Jmakevariant(th);
varX1 = Jmakevariant(th);
varN = Jmakevariant(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varN,th) == YES && Junify_var(arg2,varX,th) == YES)
{
fact_2_1_0_join:
arglist = Jwlistcons(varN1,Jwlistcons(Jwcons(2220,Jwcons(varN,Jwcons(Jmakeint(1),NIL,th),th),th),NIL,th),th);
body[0][th] = Smake_det(&&fact_2_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varN1;
proof_obj[op[th]][1][th] = varX1;
proof_obj[op[th]][2][th] = varN;
proof_obj[op[th]][3][th] = varX;
goto fact_2_1_1_join;
fact_2_1_0:
varN1= proof_obj[Sentity(pc[th],th)][0][th];
varX1= proof_obj[Sentity(pc[th],th)][1][th];
varN= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
subr_number = 187;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
fact_2_1_1_join:
arglist = Jwlistcons(varN1,Jwlistcons(varX1,NIL,th),th);
body[1][th] = Smake_nondet(&&fact_2_1_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varN1;
proof_obj[op[th]][1][th] = varX1;
proof_obj[op[th]][2][th] = varN;
proof_obj[op[th]][3][th] = varX;
goto fact_2_1_2_join;
fact_2_1_1:
varN1= proof_obj[Sentity(pc[th],th)][0][th];
varX1= proof_obj[Sentity(pc[th],th)][1][th];
varN= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto fact_2;

fact_2_1_2_join:
arglist = Jwlistcons(varX,Jwlistcons(Jwcons(2261,Jwcons(varN,Jwcons(varX1,NIL,th),th),th),NIL,th),th);
body[2][th] = Smake_det(&&fact_2_1_2,2,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varN1;
proof_obj[op[th]][1][th] = varX1;
proof_obj[op[th]][2][th] = varN;
proof_obj[op[th]][3][th] = varX;
goto fact_2_1_3_join;
fact_2_1_2:
varN1= proof_obj[Sentity(pc[th],th)][0][th];
varX1= proof_obj[Sentity(pc[th],th)][1][th];
varN= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
subr_number = 187;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
fact_2_1_3_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=2;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
fact_2_2:
Srelease(th);
goto allfail;

select1_3_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varX = Jmakevariant(th);
varXs = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES && Junify_pair(arg2,Jwlistcons(varX,varXs,th),th) == YES && Junify_var(arg3,varXs,th) == YES)
{
goto success;
}
select1_3_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varX = Jmakevariant(th);
varYs = Jmakevariant(th);
varY = Jmakevariant(th);
varZs = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES && Junify_pair(arg2,Jwlistcons(varY,varYs,th),th) == YES && Junify_pair(arg3,Jwlistcons(varY,varZs,th),th) == YES)
{
select1_3_1_0_join:
arglist = Jwlistcons(varX,Jwlistcons(varYs,Jwlistcons(varZs,NIL,th),th),th);
body[0][th] = Smake_nondet(&&select1_3_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
proof_obj[op[th]][1][th] = varYs;
proof_obj[op[th]][2][th] = varY;
proof_obj[op[th]][3][th] = varZs;
goto select1_3_1_1_join;
select1_3_1_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
varYs= proof_obj[Sentity(pc[th],th)][1][th];
varY= proof_obj[Sentity(pc[th],th)][2][th];
varZs= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto select1_3;

select1_3_1_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
select1_3_2:
Srelease(th);
goto allfail;

perm1_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_nil(arg1,th) == YES && Junify_nil(arg2,th) == YES)
{
goto success;
}
perm1_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varZs = Jmakevariant(th);
varXs = Jmakevariant(th);
varX = Jmakevariant(th);
varYs = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varXs,th) == YES && Junify_pair(arg2,Jwlistcons(varX,varYs,th),th) == YES)
{
perm1_2_1_0_join:
arglist = Jwlistcons(varX,Jwlistcons(varXs,Jwlistcons(varZs,NIL,th),th),th);
body[0][th] = Smake_nondet(&&perm1_2_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varZs;
proof_obj[op[th]][1][th] = varXs;
proof_obj[op[th]][2][th] = varX;
proof_obj[op[th]][3][th] = varYs;
goto perm1_2_1_1_join;
perm1_2_1_0:
varZs= proof_obj[Sentity(pc[th],th)][0][th];
varXs= proof_obj[Sentity(pc[th],th)][1][th];
varX= proof_obj[Sentity(pc[th],th)][2][th];
varYs= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto select1_3;

perm1_2_1_1_join:
arglist = Jwlistcons(varZs,Jwlistcons(varYs,NIL,th),th);
body[1][th] = Smake_nondet(&&perm1_2_1_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varZs;
proof_obj[op[th]][1][th] = varXs;
proof_obj[op[th]][2][th] = varX;
proof_obj[op[th]][3][th] = varYs;
goto perm1_2_1_2_join;
perm1_2_1_1:
varZs= proof_obj[Sentity(pc[th],th)][0][th];
varXs= proof_obj[Sentity(pc[th],th)][1][th];
varX= proof_obj[Sentity(pc[th],th)][2][th];
varYs= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto perm1_2;

perm1_2_1_2_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=1;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
perm1_2_2:
Srelease(th);
goto allfail;

test_0_0:
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
{
test_0_0_0_join:
arglist = Jwlistcons(Jwlistcons(Jmakeint(1),Jwlistcons(Jmakeint(2),Jwlistcons(Jmakeint(3),Jwlistcons(Jmakeint(4),Jwlistcons(Jmakeint(5),Jwlistcons(Jmakeint(6),Jwlistcons(Jmakeint(7),Jwlistcons(Jmakeint(8),Jwlistcons(Jmakeint(9),NIL,th),th),th),th),th),th),th),th),th),Jwlistcons(varX,NIL,th),th);
body[0][th] = Smake_nondet(&&test_0_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test_0_0_1_join;
test_0_0_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto queen_2;

test_0_0_1_join:
arglist = Jwlistcons(varX,NIL,th);
body[1][th] = Smake_det(&&test_0_0_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test_0_0_2_join;
test_0_0_1:
varX= proof_obj[Sentity(pc[th],th)][0][th];
subr_number = 1204;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
test_0_0_2_join:
arglist = NIL;
body[2][th] = Smake_det(&&test_0_0_2,2,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test_0_0_3_join;
test_0_0_2:
varX= proof_obj[Sentity(pc[th],th)][0][th];
subr_number = 808;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
test_0_0_3_join:
body[3][th] = Smake_det(&&test_0_0_3,3,th);
Ssave_arg(arglist,th);
goto test_0_0_4_join;
test_0_0_3:
goto failse;
test_0_0_4_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=3;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
test_0_1:
Srelease(th);
goto allfail;

test1_0_0:
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
{
test1_0_0_0_join:
arglist = Jwlistcons(Jwlistcons(Jmakeint(1),Jwlistcons(Jmakeint(2),Jwlistcons(Jmakeint(3),Jwlistcons(Jmakeint(4),Jwlistcons(Jmakeint(5),Jwlistcons(Jmakeint(6),Jwlistcons(Jmakeint(7),Jwlistcons(Jmakeint(8),Jwlistcons(Jmakeint(9),NIL,th),th),th),th),th),th),th),th),th),Jwlistcons(varX,NIL,th),th);
body[0][th] = Smake_nondet(&&test1_0_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test1_0_0_1_join;
test1_0_0_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto queen_2;

test1_0_0_1_join:
body[1][th] = Smake_det(&&test1_0_0_1,1,th);
Ssave_arg(arglist,th);
goto test1_0_0_2_join;
test1_0_0_1:
goto failse;
test1_0_0_2_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=1;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
test1_0_1:
Srelease(th);
goto allfail;

queen_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varData = Jmakevariant(th);
varOut = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varData,th) == YES && Junify_var(arg2,varOut,th) == YES)
{
queen_2_0_0_join:
arglist = Jwlistcons(varData,Jwlistcons(NIL,Jwlistcons(varOut,NIL,th),th),th);
body[0][th] = Smake_nondet(&&queen_2_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varData;
proof_obj[op[th]][1][th] = varOut;
goto queen_2_0_1_join;
queen_2_0_0:
varData= proof_obj[Sentity(pc[th],th)][0][th];
varOut= proof_obj[Sentity(pc[th],th)][1][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto queen2_3;

queen_2_0_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
queen_2_1:
Srelease(th);
goto allfail;

queen2_3_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
ano_1 = Jmakevariant(th);
Sinc_choice(th);
if(Junify_nil(arg1,th) == YES && Junify_var(arg2,ano_1,th) == YES && Junify_nil(arg3,th) == YES)
{
goto success;
}
queen2_3_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varL1 = Jmakevariant(th);
varH = Jmakevariant(th);
varT = Jmakevariant(th);
varHistory = Jmakevariant(th);
varQ = Jmakevariant(th);
varM = Jmakevariant(th);
Sinc_choice(th);
if(Junify_pair(arg1,Jwlistcons(varH,varT,th),th) == YES && Junify_var(arg2,varHistory,th) == YES && Junify_pair(arg3,Jwlistcons(varQ,varM,th),th) == YES)
{
queen2_3_1_0_join:
arglist = Jwlistcons(varQ,Jwlistcons(varH,Jwlistcons(varT,Jwlistcons(varL1,NIL,th),th),th),th);
body[0][th] = Smake_nondet(&&queen2_3_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varH;
proof_obj[op[th]][2][th] = varT;
proof_obj[op[th]][3][th] = varHistory;
proof_obj[op[th]][4][th] = varQ;
proof_obj[op[th]][5][th] = varM;
goto queen2_3_1_1_join;
queen2_3_1_0:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varH= proof_obj[Sentity(pc[th],th)][1][th];
varT= proof_obj[Sentity(pc[th],th)][2][th];
varHistory= proof_obj[Sentity(pc[th],th)][3][th];
varQ= proof_obj[Sentity(pc[th],th)][4][th];
varM= proof_obj[Sentity(pc[th],th)][5][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto qdelete_4;

queen2_3_1_1_join:
arglist = Jwlistcons(varHistory,Jwlistcons(varQ,Jwlistcons(Jmakeint(1),NIL,th),th),th);
body[1][th] = Smake_det(&&queen2_3_1_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varH;
proof_obj[op[th]][2][th] = varT;
proof_obj[op[th]][3][th] = varHistory;
proof_obj[op[th]][4][th] = varQ;
proof_obj[op[th]][5][th] = varM;
goto queen2_3_1_2_join;
queen2_3_1_1:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varH= proof_obj[Sentity(pc[th],th)][1][th];
varT= proof_obj[Sentity(pc[th],th)][2][th];
varHistory= proof_obj[Sentity(pc[th],th)][3][th];
varQ= proof_obj[Sentity(pc[th],th)][4][th];
varM= proof_obj[Sentity(pc[th],th)][5][th];
subr_number = Jmakecomp("nodiag");
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES)
goto success;
else goto failse;
queen2_3_1_2_join:
arglist = Jwlistcons(varL1,Jwlistcons(Jwlistcons(varQ,varHistory,th),Jwlistcons(varM,NIL,th),th),th);
body[2][th] = Smake_nondet(&&queen2_3_1_2,2,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varH;
proof_obj[op[th]][2][th] = varT;
proof_obj[op[th]][3][th] = varHistory;
proof_obj[op[th]][4][th] = varQ;
proof_obj[op[th]][5][th] = varM;
goto queen2_3_1_3_join;
queen2_3_1_2:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varH= proof_obj[Sentity(pc[th],th)][1][th];
varT= proof_obj[Sentity(pc[th],th)][2][th];
varHistory= proof_obj[Sentity(pc[th],th)][3][th];
varQ= proof_obj[Sentity(pc[th],th)][4][th];
varM= proof_obj[Sentity(pc[th],th)][5][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto queen2_3;

queen2_3_1_3_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=2;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
queen2_3_2:
Srelease(th);
goto allfail;

qdelete_4_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
arg4 = Jnth(arglist,4);
Srelease(th);
varA = Jmakevariant(th);
varL = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varA,th) == YES && Junify_var(arg2,varA,th) == YES && Junify_var(arg3,varL,th) == YES && Junify_var(arg4,varL,th) == YES)
{
goto success;
}
qdelete_4_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
arg4 = Jnth(arglist,4);
Srelease(th);
varX = Jmakevariant(th);
varH = Jmakevariant(th);
varT = Jmakevariant(th);
varA = Jmakevariant(th);
varR = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES && Junify_var(arg2,varA,th) == YES && Junify_pair(arg3,Jwlistcons(varH,varT,th),th) == YES && Junify_pair(arg4,Jwlistcons(varA,varR,th),th) == YES)
{
qdelete_4_1_0_join:
arglist = Jwlistcons(varX,Jwlistcons(varH,Jwlistcons(varT,Jwlistcons(varR,NIL,th),th),th),th);
body[0][th] = Smake_nondet(&&qdelete_4_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
proof_obj[op[th]][1][th] = varH;
proof_obj[op[th]][2][th] = varT;
proof_obj[op[th]][3][th] = varA;
proof_obj[op[th]][4][th] = varR;
goto qdelete_4_1_1_join;
qdelete_4_1_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
varH= proof_obj[Sentity(pc[th],th)][1][th];
varT= proof_obj[Sentity(pc[th],th)][2][th];
varA= proof_obj[Sentity(pc[th],th)][3][th];
varR= proof_obj[Sentity(pc[th],th)][4][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto qdelete_4;

qdelete_4_1_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
qdelete_4_2:
Srelease(th);
goto allfail;

append1_3_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varYs = Jmakevariant(th);
Sinc_choice(th);
if(Junify_nil(arg1,th) == YES && Junify_var(arg2,varYs,th) == YES && Junify_var(arg3,varYs,th) == YES)
{
goto success;
}
append1_3_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varXs = Jmakevariant(th);
varYs = Jmakevariant(th);
varX = Jmakevariant(th);
varZs = Jmakevariant(th);
Sinc_choice(th);
if(Junify_pair(arg1,Jwlistcons(varX,varXs,th),th) == YES && Junify_var(arg2,varYs,th) == YES && Junify_pair(arg3,Jwlistcons(varX,varZs,th),th) == YES)
{
append1_3_1_0_join:
arglist = Jwlistcons(varXs,Jwlistcons(varYs,Jwlistcons(varZs,NIL,th),th),th);
body[0][th] = Smake_nondet(&&append1_3_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varXs;
proof_obj[op[th]][1][th] = varYs;
proof_obj[op[th]][2][th] = varX;
proof_obj[op[th]][3][th] = varZs;
goto append1_3_1_1_join;
append1_3_1_0:
varXs= proof_obj[Sentity(pc[th],th)][0][th];
varYs= proof_obj[Sentity(pc[th],th)][1][th];
varX= proof_obj[Sentity(pc[th],th)][2][th];
varZs= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto append1_3;

append1_3_1_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
append1_3_2:
Srelease(th);
goto allfail;

between1_3_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varH = Jmakevariant(th);
varL = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varL,th) == YES && Junify_var(arg2,varH,th) == YES && Junify_var(arg3,varL,th) == YES)
{
between1_3_0_0_join:
arglist = Jwlistcons(varL,Jwlistcons(varH,NIL,th),th);
body[0][th] = Smake_det(&&between1_3_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varH;
proof_obj[op[th]][1][th] = varL;
goto between1_3_0_1_join;
between1_3_0_0:
varH= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
subr_number = 88;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
between1_3_0_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
between1_3_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varL1 = Jmakevariant(th);
varL = Jmakevariant(th);
varH = Jmakevariant(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varL,th) == YES && Junify_var(arg2,varH,th) == YES && Junify_var(arg3,varX,th) == YES)
{
between1_3_1_0_join:
arglist = Jwlistcons(varL,Jwlistcons(varH,NIL,th),th);
body[0][th] = Smake_det(&&between1_3_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varL;
proof_obj[op[th]][2][th] = varH;
proof_obj[op[th]][3][th] = varX;
goto between1_3_1_1_join;
between1_3_1_0:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
varH= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
subr_number = 77;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
between1_3_1_1_join:
arglist = Jwlistcons(varL1,Jwlistcons(Jwcons(2179,Jwcons(varL,Jwcons(Jmakeint(1),NIL,th),th),th),NIL,th),th);
body[1][th] = Smake_det(&&between1_3_1_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varL;
proof_obj[op[th]][2][th] = varH;
proof_obj[op[th]][3][th] = varX;
goto between1_3_1_2_join;
between1_3_1_1:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
varH= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
subr_number = 187;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
between1_3_1_2_join:
arglist = Jwlistcons(varL1,Jwlistcons(varH,Jwlistcons(varX,NIL,th),th),th);
body[2][th] = Smake_nondet(&&between1_3_1_2,2,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varL;
proof_obj[op[th]][2][th] = varH;
proof_obj[op[th]][3][th] = varX;
goto between1_3_1_3_join;
between1_3_1_2:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
varH= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto between1_3;

between1_3_1_3_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=2;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
between1_3_2:
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
Sreset_choice(th);
pc[th] = Sbacktrack2(pc[th],th);
if(pc[th] == NIL) return(NO);
else goto loop;
failse:
pc[th] = Sbacktrack1(pc[th],th);
if (pc[th] == NIL) return(NO);
else goto loop;
}
