#include "jump.h"
static int c_append(int arglist, int rest, int th);
static int c_between(int arglist, int rest, int th);
static int c_member(int arglist, int rest, int th);
static int c_select(int arglist, int rest, int th);
static int c_repeat(int arglist, int rest, int th);
static int c_length(int arglist, int rest, int th);
static int c_not(int arglist, int rest, int th);
static int c_color(int arglist, int rest, int th);
static int c_foo(int arglist, int rest, int th);
static int c_likes(int arglist, int rest, int th);
static int c_fact(int arglist, int rest, int th);
static int c_perm1(int arglist, int rest, int th);
static int c_test16(int arglist, int rest, int th);
static int c_test(int arglist, int rest, int th);
static int c_test1(int arglist, int rest, int th);
static int c_queen(int arglist, int rest, int th);
static int c_queen2(int arglist, int rest, int th);
static int c_qdelete(int arglist, int rest, int th);
static int c_nodiag(int arglist, int rest, int th);
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th);
static int c_append(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(0,n,0,arglist,rest,th));
}

static int c_between(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(1,n,0,arglist,rest,th));
}

static int c_member(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(2,n,0,arglist,rest,th));
}

static int c_select(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(3,n,0,arglist,rest,th));
}

static int c_repeat(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(4,n,0,arglist,rest,th));
}

static int c_length(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(5,n,0,arglist,rest,th));
}

static int c_not(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(6,n,0,arglist,rest,th));
}

static int c_color(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(7,n,0,arglist,rest,th));
}

static int c_foo(int arglist, int rest, int th){
int arg1,varX,n,body,save1,save2,save3,goal,cont,clause,res;
Sinc_proof(th);
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
return(user_scbm(8,n,0,arglist,rest,th));
}

static int c_fact(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(9,n,0,arglist,rest,th));
}

static int c_perm1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(10,n,0,arglist,rest,th));
}

static int c_test16(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(11,n,0,arglist,rest,th));
}

static int c_test(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(12,n,0,arglist,rest,th));
}

static int c_test1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(13,n,0,arglist,rest,th));
}

static int c_queen(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(14,n,0,arglist,rest,th));
}

static int c_queen2(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(15,n,0,arglist,rest,th));
}

static int c_qdelete(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(16,n,0,arglist,rest,th));
}

static int c_nodiag(int arglist, int rest, int th){
int arg1,arg2,arg3,varD1,varN,varL,varB,varD,ano_2,ano_1,n,body,save1,save2,save3,goal,cont,clause,res;
save1 = Jget_wp(th);
save2 = Jget_sp(th);
save3 = Jget_ac(th);
Sinc_proof(th);
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
if(Jnot_numeqp(Jderef(varD,th),Jminus(Jderef(varN,th),Jderef(varB,th),th)) && Sinc_proof(th)==YES)
if(Jnot_numeqp(Jderef(varD,th),Jminus(Jderef(varB,th),Jderef(varN,th),th)) && Sinc_proof(th)==YES)
if(Junify(varD1,Jplus(Jderef(varD,th),1073741825,th),th)==YES && Sinc_proof(th)==YES)
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
void init_tpredicate(void){
(deftpred)("append",c_append,3,1);
(deftpred)("between",c_between,3,1);
(deftpred)("member",c_member,2,1);
(deftpred)("select",c_select,3,1);
(deftpred)("repeat",c_repeat,0,1);
(deftpred)("length",c_length,2,1);
(deftpred)("not",c_not,1,1);
(deftpred)("color",c_color,1,1);
(deftpred)("foo",c_foo,1,2);
(deftpred)("likes",c_likes,2,1);
(deftpred)("fact",c_fact,2,1);
(deftpred)("perm1",c_perm1,2,1);
(deftpred)("test16",c_test16,0,1);
(deftpred)("test",c_test,0,1);
(deftpred)("test1",c_test1,0,1);
(deftpred)("queen",c_queen,2,1);
(deftpred)("queen2",c_queen2,3,1);
(deftpred)("qdelete",c_qdelete,4,1);
(deftpred)("nodiag",c_nodiag,3,3);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,front,back,i,callpred,callprop,ano_1,varA,varData,varH,varHistory,varL,varL1,varM,varN,varN1,varOut,varQ,varR,varT,varX,varX1,varXs,varY,varYs,varZs;
int body[10][THREADSIZE], body1[10][THREADSIZE];
pc[th] = 0; lp[th] = 0; op[th] = 0;
if(!call_flag[th]) proof[th] = 0;
switch(pred){
case 0: goto append;
case 1: goto between;
case 2: goto member;
case 3: goto select;
case 4: goto repeat;
case 5: goto length;
case 6: goto not;
case 7: goto color;
case 8: goto likes;
case 9: goto fact;
case 10: goto perm1;
case 11: goto test16;
case 12: goto test;
case 13: goto test1;
case 14: goto queen;
case 15: goto queen2;
case 16: goto qdelete;
}
loop:
if(pc[th] == NIL) goto success;
next = proof_goto[blist[pc[th]][th].entity][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto *next;
append:
switch(arity){
case 3: goto append_3entry;
default: goto allfail;
}
between:
switch(arity){
case 3: goto between_3entry;
default: goto allfail;
}
member:
switch(arity){
case 2: goto member_2entry;
default: goto allfail;
}
select:
switch(arity){
case 3: goto select_3entry;
default: goto allfail;
}
repeat:
switch(arity){
case 0: goto repeat_0entry;
default: goto allfail;
}
length:
switch(arity){
case 2: goto length_2entry;
default: goto allfail;
}
not:
switch(arity){
case 1: goto not_1entry;
default: goto allfail;
}
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
perm1:
switch(arity){
case 2: goto perm1_2entry;
default: goto allfail;
}
test16:
switch(arity){
case 0: goto test16_0entry;
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
append_3entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&append_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&append_3,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
append_3:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto append_3_0;
case 1:goto append_3_1;
case 2:goto append_3_2;
default: goto allfail;
}
between_3entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&between_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&between_3,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
between_3:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto between_3_0;
case 1:goto between_3_1;
case 2:goto between_3_2;
default: goto allfail;
}
member_2entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&member_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&member_2,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
member_2:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto member_2_0;
case 1:goto member_2_1;
case 2:goto member_2_2;
default: goto allfail;
}
select_3entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&select_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&select_3,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
select_3:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto select_3_0;
case 1:goto select_3_1;
case 2:goto select_3_2;
default: goto allfail;
}
repeat_0entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&repeat_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&repeat_0,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
repeat_0:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto repeat_0_0;
case 1:goto repeat_0_1;
case 2:goto repeat_0_2;
default: goto allfail;
}
length_2entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&length_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&length_2,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
length_2:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto length_2_0;
case 1:goto length_2_1;
case 2:goto length_2_2;
default: goto allfail;
}
not_1entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&not_1,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&not_1,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
not_1:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto not_1_0;
case 1:goto not_1_1;
case 2:goto not_1_2;
default: goto allfail;
}
color_1entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&color_1,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&color_1,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
color_1:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto color_1_0;
case 1:goto color_1_1;
case 2:goto color_1_2;
case 3:goto color_1_3;
default: goto allfail;
}
likes_2entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&likes_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&likes_2,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
likes_2:
Sinc_proof(th);
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
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&fact_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&fact_2,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
fact_2:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto fact_2_0;
case 1:goto fact_2_1;
case 2:goto fact_2_2;
default: goto allfail;
}
perm1_2entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&perm1_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&perm1_2,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
perm1_2:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto perm1_2_0;
case 1:goto perm1_2_1;
case 2:goto perm1_2_2;
default: goto allfail;
}
test16_0entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&test16_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&test16_0,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
test16_0:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test16_0_0;
case 1:goto test16_0_1;
default: goto allfail;
}
test_0entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&test_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&test_0,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
test_0:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test_0_0;
case 1:goto test_0_1;
default: goto allfail;
}
test1_0entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&test1_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&test1_0,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
test1_0:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test1_0_0;
case 1:goto test1_0_1;
default: goto allfail;
}
queen_2entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&queen_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&queen_2,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
queen_2:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto queen_2_0;
case 1:goto queen_2_1;
default: goto allfail;
}
queen2_3entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&queen2_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&queen2_3,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
queen2_3:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto queen2_3_0;
case 1:goto queen2_3_1;
case 2:goto queen2_3_2;
default: goto allfail;
}
qdelete_4entry:
if(!call_flag[th]){pc[th] = Scons(Smake_nondet(&&qdelete_4,-1,th),NIL,th);
Ssave_arg(arglist,th);
} else {
i = pc[th] = Sreplace(pc[th],Smake_nondet(&&qdelete_4,-1,th),th);
Ssave_arg(arglist,th);
return(i);
}
qdelete_4:
Sinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto qdelete_4_0;
case 1:goto qdelete_4_1;
case 2:goto qdelete_4_2;
default: goto allfail;
}
append_3_0:
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
append_3_1:
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
append_3_1_0_join:
arglist = Jwlistcons(varXs,Jwlistcons(varYs,Jwlistcons(varZs,NIL,th),th),th);
body[0][th] = Smake_nondet(&&append_3_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varXs;
proof_obj[op[th]][1][th] = varYs;
proof_obj[op[th]][2][th] = varX;
proof_obj[op[th]][3][th] = varZs;
goto append_3_1_1_join;
append_3_1_0:
varXs= proof_obj[Sentity(pc[th],th)][0][th];
varYs= proof_obj[Sentity(pc[th],th)][1][th];
varX= proof_obj[Sentity(pc[th],th)][2][th];
varZs= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto append_3;

append_3_1_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
append_3_2:
Srelease(th);
goto allfail;

between_3_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varH = Jmakevariant(th);
varL = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varL,th) == YES && Junify_var(arg2,varH,th) == YES && Junify_var(arg3,varL,th) == YES)
{
between_3_0_0_join:
arglist = Jwlistcons(varL,Jwlistcons(varH,NIL,th),th);
body[0][th] = Smake_det(&&between_3_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varH;
proof_obj[op[th]][1][th] = varL;
goto between_3_0_1_join;
between_3_0_0:
varH= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
subr_number = 88;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
between_3_0_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
between_3_1:
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
between_3_1_0_join:
arglist = Jwlistcons(varL,Jwlistcons(varH,NIL,th),th);
body[0][th] = Smake_det(&&between_3_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varL;
proof_obj[op[th]][2][th] = varH;
proof_obj[op[th]][3][th] = varX;
goto between_3_1_1_join;
between_3_1_0:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
varH= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
subr_number = 77;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
between_3_1_1_join:
arglist = Jwlistcons(varL1,Jwlistcons(Jwcons(2104,Jwcons(varL,Jwcons(1073741825,NIL,th),th),th),NIL,th),th);
body[1][th] = Smake_det(&&between_3_1_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varL;
proof_obj[op[th]][2][th] = varH;
proof_obj[op[th]][3][th] = varX;
goto between_3_1_2_join;
between_3_1_1:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
varH= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
subr_number = 187;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
between_3_1_2_join:
arglist = Jwlistcons(varL1,Jwlistcons(varH,Jwlistcons(varX,NIL,th),th),th);
body[2][th] = Smake_nondet(&&between_3_1_2,2,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varL1;
proof_obj[op[th]][1][th] = varL;
proof_obj[op[th]][2][th] = varH;
proof_obj[op[th]][3][th] = varX;
goto between_3_1_3_join;
between_3_1_2:
varL1= proof_obj[Sentity(pc[th],th)][0][th];
varL= proof_obj[Sentity(pc[th],th)][1][th];
varH= proof_obj[Sentity(pc[th],th)][2][th];
varX= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto between_3;

between_3_1_3_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=2;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
between_3_2:
Srelease(th);
goto allfail;

member_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
ano_1 = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES && Junify_pair(arg2,Jwlistcons(varX,ano_1,th),th) == YES)
{
goto success;
}
member_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
ano_1 = Jmakevariant(th);
varXs = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES && Junify_pair(arg2,Jwlistcons(ano_1,varXs,th),th) == YES)
{
member_2_1_0_join:
arglist = Jwlistcons(varX,Jwlistcons(varXs,NIL,th),th);
body[0][th] = Smake_nondet(&&member_2_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
proof_obj[op[th]][1][th] = ano_1;
proof_obj[op[th]][2][th] = varXs;
goto member_2_1_1_join;
member_2_1_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
ano_1= proof_obj[Sentity(pc[th],th)][1][th];
varXs= proof_obj[Sentity(pc[th],th)][2][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto member_2;

member_2_1_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
member_2_2:
Srelease(th);
goto allfail;

select_3_0:
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
select_3_1:
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
select_3_1_0_join:
arglist = Jwlistcons(varX,Jwlistcons(varYs,Jwlistcons(varZs,NIL,th),th),th);
body[0][th] = Smake_nondet(&&select_3_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
proof_obj[op[th]][1][th] = varYs;
proof_obj[op[th]][2][th] = varY;
proof_obj[op[th]][3][th] = varZs;
goto select_3_1_1_join;
select_3_1_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
varYs= proof_obj[Sentity(pc[th],th)][1][th];
varY= proof_obj[Sentity(pc[th],th)][2][th];
varZs= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto select_3;

select_3_1_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
select_3_2:
Srelease(th);
goto allfail;

repeat_0_0:
Srelease(th);
Sinc_choice(th);
{
goto success;
}
repeat_0_1:
Srelease(th);
Sinc_choice(th);
{
repeat_0_1_0_join:
arglist = NIL;
body[0][th] = Smake_nondet(&&repeat_0_1_0,0,th);
Ssave_arg(arglist,th);
goto repeat_0_1_1_join;
repeat_0_1_0:
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto repeat_0;

repeat_0_1_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
repeat_0_2:
Srelease(th);
goto allfail;

length_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_nil(arg1,th) == YES && Junify_int(arg2,1073741824,th) == YES)
{
goto success;
}
length_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varM = Jmakevariant(th);
ano_1 = Jmakevariant(th);
varXs = Jmakevariant(th);
varN = Jmakevariant(th);
Sinc_choice(th);
if(Junify_pair(arg1,Jwlistcons(ano_1,varXs,th),th) == YES && Junify_var(arg2,varN,th) == YES)
{
length_2_1_0_join:
arglist = Jwlistcons(varXs,Jwlistcons(varM,NIL,th),th);
body[0][th] = Smake_nondet(&&length_2_1_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varM;
proof_obj[op[th]][1][th] = ano_1;
proof_obj[op[th]][2][th] = varXs;
proof_obj[op[th]][3][th] = varN;
goto length_2_1_1_join;
length_2_1_0:
varM= proof_obj[Sentity(pc[th],th)][0][th];
ano_1= proof_obj[Sentity(pc[th],th)][1][th];
varXs= proof_obj[Sentity(pc[th],th)][2][th];
varN= proof_obj[Sentity(pc[th],th)][3][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto length_2;

length_2_1_1_join:
arglist = Jwlistcons(varN,Jwlistcons(Jwcons(2104,Jwcons(varM,Jwcons(1073741825,NIL,th),th),th),NIL,th),th);
body[1][th] = Smake_det(&&length_2_1_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varM;
proof_obj[op[th]][1][th] = ano_1;
proof_obj[op[th]][2][th] = varXs;
proof_obj[op[th]][3][th] = varN;
goto length_2_1_2_join;
length_2_1_1:
varM= proof_obj[Sentity(pc[th],th)][0][th];
ano_1= proof_obj[Sentity(pc[th],th)][1][th];
varXs= proof_obj[Sentity(pc[th],th)][2][th];
varN= proof_obj[Sentity(pc[th],th)][3][th];
subr_number = 187;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
length_2_1_2_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=1;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
length_2_2:
Srelease(th);
goto allfail;

not_1_0:
arg1 = Jcar(arglist);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES)
{
not_1_0_0_join:
arglist = varX;
body[0][th] = Smake_det(&&not_1_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto not_1_0_1_join;
not_1_0_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
callpred = Jderef(arglist,th);
callprop = Jget_prop(callpred);
switch(callprop){
case(NONDET):
call_flag[th] = 1;
pc[th] = Jcallsubr(Jget_pred(callpred),Jget_arg(callpred),NIL,th);
call_flag[th] = 0;
goto loop;
case(BUILTIN):
case(DET):
case(TAIL):
if(Jcallsubr(Jget_pred(callpred),Jget_arg(callpred),NIL,th)==YES) goto success;
else goto failse;
}
not_1_0_1_join:
body[1][th] = Smake_det(&&not_1_0_1,1,th);
Ssave_arg(arglist,th);
goto not_1_0_2_join;
not_1_0_1:
varX= proof_obj[Sentity(pc[th],th)][0][th];
pc[th] = Scut(pc[th],th); goto loop;
not_1_0_2_join:
body[2][th] = Smake_det(&&not_1_0_2,2,th);
Ssave_arg(arglist,th);
goto not_1_0_3_join;
not_1_0_2:
goto failse;
not_1_0_3_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=2;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
not_1_1:
arg1 = Jcar(arglist);
Srelease(th);
ano_1 = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,ano_1,th) == YES)
{
goto success;
}
not_1_2:
Srelease(th);
goto allfail;

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
if(Junify_int(arg1,1073741824,th) == YES && Junify_int(arg2,1073741825,th) == YES)
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
arglist = Jwlistcons(varN1,Jwlistcons(Jwcons(2144,Jwcons(varN,Jwcons(1073741825,NIL,th),th),th),NIL,th),th);
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
arglist = Jwlistcons(varX,Jwlistcons(Jwcons(2184,Jwcons(varN,Jwcons(varX1,NIL,th),th),th),NIL,th),th);
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
goto select_3;

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

test16_0_0:
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
{
test16_0_0_0_join:
arglist = Jwlistcons(1073741825,Jwlistcons(1073741840,Jwlistcons(varX,NIL,th),th),th);
body[0][th] = Smake_nondet(&&test16_0_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test16_0_0_1_join;
test16_0_0_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto between_3;

test16_0_0_1_join:
arglist = NIL;
body[1][th] = Smake_nondet(&&test16_0_0_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test16_0_0_2_join;
test16_0_0_1:
varX= proof_obj[Sentity(pc[th],th)][0][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto test1_0;

test16_0_0_2_join:
body[2][th] = Smake_det(&&test16_0_0_2,2,th);
Ssave_arg(arglist,th);
goto test16_0_0_3_join;
test16_0_0_2:
goto failse;
test16_0_0_3_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=2;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
test16_0_1:
Srelease(th);
goto allfail;

test_0_0:
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
{
test_0_0_0_join:
arglist = Jwlistcons(Jwlistcons(1073741825,Jwlistcons(1073741826,Jwlistcons(1073741827,Jwlistcons(1073741828,Jwlistcons(1073741829,Jwlistcons(1073741830,Jwlistcons(1073741831,Jwlistcons(1073741832,Jwlistcons(1073741833,NIL,th),th),th),th),th),th),th),th),th),Jwlistcons(varX,NIL,th),th);
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
subr_number = 1167;
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
subr_number = 771;
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
arglist = Jwlistcons(Jwlistcons(1073741825,Jwlistcons(1073741826,Jwlistcons(1073741827,Jwlistcons(1073741828,Jwlistcons(1073741829,Jwlistcons(1073741830,Jwlistcons(1073741831,Jwlistcons(1073741832,Jwlistcons(1073741833,NIL,th),th),th),th),th),th),th),th),th),Jwlistcons(varX,NIL,th),th);
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
arglist = Jwlistcons(varHistory,Jwlistcons(varQ,Jwlistcons(1073741825,NIL,th),th),th);
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

success:
if(Sback(pc[th],th) == NIL){
if(Jprove_all(rest,Jget_sp(th),th) == YES) {Jset_proof(proof[th],th); return(YES);}
pc[th] = Sbacktrack1(pc[th],th);
if (pc[th] == NIL) return(NO);
else goto loop;}
else{pc[th]=Sback(pc[th],th);goto loop;}

allfail:
Sreset_choice(th);
pc[th] = Sbacktrack2(pc[th],th);
if(pc[th] == NIL) {Jset_proof(proof[th],th); return(NO);}
else goto loop;
failse:
pc[th] = Sbacktrack1(pc[th],th);
if (pc[th] == NIL) {Jset_proof(proof[th],th); return(NO);}
else goto loop;
}
