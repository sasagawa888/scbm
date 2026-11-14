#include "jump.h"
static int c_append(int arglist, int rest, int th);
static int c_between(int arglist, int rest, int th);
static int c_member(int arglist, int rest, int th);
static int c_select(int arglist, int rest, int th);
static int c_repeat(int arglist, int rest, int th);
static int c_length(int arglist, int rest, int th);
static int c_a(int arglist, int rest, int th);
static int c_test1(int arglist, int rest, int th);
static int c_test2(int arglist, int rest, int th);
static int c_test3(int arglist, int rest, int th);
static int c_test4(int arglist, int rest, int th);
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

static int c_a(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(6,n,0,arglist,rest,th));
}

static int c_test1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(7,n,0,arglist,rest,th));
}

static int c_test2(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(8,n,0,arglist,rest,th));
}

static int c_test3(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(9,n,0,arglist,rest,th));
}

static int c_test4(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(10,n,0,arglist,rest,th));
}

void init_tpredicate(void){
(deftpred)("append",c_append,3,1);
(deftpred)("between",c_between,3,1);
(deftpred)("member",c_member,2,1);
(deftpred)("select",c_select,3,1);
(deftpred)("repeat",c_repeat,0,1);
(deftpred)("length",c_length,2,1);
(deftpred)("a",c_a,1,1);
(deftpred)("test1",c_test1,1,1);
(deftpred)("test2",c_test2,0,1);
(deftpred)("test3",c_test3,0,1);
(deftpred)("test4",c_test4,1,1);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,front,back,i,callpred,callprop,ano_1,varH,varL,varL1,varM,varN,varX,varXs,varY,varYs,varZs;
int body[10][THREADSIZE], body1[10][THREADSIZE];
pc[th] = 0; lp[th] = 0; op[th] = 0;
switch(pred){
case 0: goto append;
case 1: goto between;
case 2: goto member;
case 3: goto select;
case 4: goto repeat;
case 5: goto length;
case 6: goto a;
case 7: goto test1;
case 8: goto test2;
case 9: goto test3;
case 10: goto test4;
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
a:
switch(arity){
case 1: goto a_1entry;
default: goto allfail;
}
test1:
switch(arity){
case 1: goto test1_1entry;
default: goto allfail;
}
test2:
switch(arity){
case 0: goto test2_0entry;
default: goto allfail;
}
test3:
switch(arity){
case 0: goto test3_0entry;
default: goto allfail;
}
test4:
switch(arity){
case 1: goto test4_1entry;
default: goto allfail;
}
append_3entry:
pc[th] = Scons(Smake_nondet(&&append_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
append_3:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto append_3_0;
case 1:goto append_3_1;
case 2:goto append_3_2;
default: goto allfail;
}
between_3entry:
pc[th] = Scons(Smake_nondet(&&between_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
between_3:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto between_3_0;
case 1:goto between_3_1;
case 2:goto between_3_2;
default: goto allfail;
}
member_2entry:
pc[th] = Scons(Smake_nondet(&&member_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
member_2:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto member_2_0;
case 1:goto member_2_1;
case 2:goto member_2_2;
default: goto allfail;
}
select_3entry:
pc[th] = Scons(Smake_nondet(&&select_3,-1,th),NIL,th);
Ssave_arg(arglist,th);
select_3:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto select_3_0;
case 1:goto select_3_1;
case 2:goto select_3_2;
default: goto allfail;
}
repeat_0entry:
pc[th] = Scons(Smake_nondet(&&repeat_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
repeat_0:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto repeat_0_0;
case 1:goto repeat_0_1;
default: goto allfail;
}
length_2entry:
pc[th] = Scons(Smake_nondet(&&length_2,-1,th),NIL,th);
Ssave_arg(arglist,th);
length_2:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto length_2_0;
case 1:goto length_2_1;
case 2:goto length_2_2;
default: goto allfail;
}
a_1entry:
pc[th] = Scons(Smake_nondet(&&a_1,-1,th),NIL,th);
Ssave_arg(arglist,th);
a_1:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto a_1_0;
case 1:goto a_1_1;
case 2:goto a_1_2;
case 3:goto a_1_3;
default: goto allfail;
}
test1_1entry:
pc[th] = Scons(Smake_nondet(&&test1_1,-1,th),NIL,th);
Ssave_arg(arglist,th);
test1_1:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test1_1_0;
case 1:goto test1_1_1;
default: goto allfail;
}
test2_0entry:
pc[th] = Scons(Smake_nondet(&&test2_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
test2_0:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test2_0_0;
case 1:goto test2_0_1;
default: goto allfail;
}
test3_0entry:
pc[th] = Scons(Smake_nondet(&&test3_0,-1,th),NIL,th);
Ssave_arg(arglist,th);
test3_0:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test3_0_0;
case 1:goto test3_0_1;
default: goto allfail;
}
test4_1entry:
pc[th] = Scons(Smake_nondet(&&test4_1,-1,th),NIL,th);
Ssave_arg(arglist,th);
test4_1:
Jinc_proof(th);
switch(clause){
case 0:Sset_state(th);goto test4_1_0;
case 1:goto test4_1_1;
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
arglist = Jwlistcons(varL1,Jwlistcons(Jwcons(2104,Jwcons(varL,Jwcons(Jmakeint(1),NIL,th),th),th),NIL,th),th);
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
repeat_0_0_0_join:
arglist = NIL;
body[0][th] = Smake_nondet(&&repeat_0_0_0,0,th);
Ssave_arg(arglist,th);
goto repeat_0_0_1_join;
repeat_0_0_0:
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto repeat_0;

repeat_0_0_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
repeat_0_1:
Srelease(th);
goto allfail;

length_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_nil(arg1,th) == YES && Junify_int(arg2,Jmakeint(0),th) == YES)
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
arglist = Jwlistcons(varN,Jwlistcons(Jwcons(2104,Jwcons(varM,Jwcons(Jmakeint(1),NIL,th),th),th),NIL,th),th);
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

a_1_0:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
if(Junify_int(arg1,Jmakeint(1),th) == YES)
{
goto success;
}
a_1_1:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
if(Junify_int(arg1,Jmakeint(2),th) == YES)
{
goto success;
}
a_1_2:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
if(Junify_int(arg1,Jmakeint(3),th) == YES)
{
goto success;
}
a_1_3:
Srelease(th);
goto allfail;

test1_1_0:
arg1 = Jcar(arglist);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES)
{
test1_1_0_0_join:
arglist = Jwcons(Jmakecomp("a"),Jwcons(varX,NIL,th),th);
body[0][th] = Smake_det(&&test1_1_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test1_1_0_1_join;
test1_1_0_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
callpred = Jderef(arglist,th);
callprop = Jget_prop(callpred);
switch(callprop){
case(NONDET):
call_flag = 1;
pc[th] = Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th);
call_flag = 0;
goto loop;
case(BUILTIN):
case(DET):
case(TAIL):
if(Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th)==YES) goto success;
else goto failse;
}
test1_1_0_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
test1_1_1:
Srelease(th);
goto allfail;

test2_0_0:
Srelease(th);
Sinc_choice(th);
{
test2_0_0_0_join:
arglist = 1153;
body[0][th] = Smake_det(&&test2_0_0_0,0,th);
Ssave_arg(arglist,th);
goto test2_0_0_1_join;
test2_0_0_0:
callpred = Jderef(arglist,th);
callprop = Jget_prop(callpred);
switch(callprop){
case(NONDET):
call_flag = 1;
pc[th] = Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th);
call_flag = 0;
goto loop;
case(BUILTIN):
case(DET):
case(TAIL):
if(Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th)==YES) goto success;
else goto failse;
}
test2_0_0_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
test2_0_1:
Srelease(th);
goto allfail;

test3_0_0:
Srelease(th);
Sinc_choice(th);
{
test3_0_0_0_join:
arglist = 578;
body[0][th] = Smake_det(&&test3_0_0_0,0,th);
Ssave_arg(arglist,th);
goto test3_0_0_1_join;
test3_0_0_0:
callpred = Jderef(arglist,th);
callprop = Jget_prop(callpred);
switch(callprop){
case(NONDET):
call_flag = 1;
pc[th] = Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th);
call_flag = 0;
goto loop;
case(BUILTIN):
case(DET):
case(TAIL):
if(Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th)==YES) goto success;
else goto failse;
}
test3_0_0_1_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=0;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
test3_0_1:
Srelease(th);
goto allfail;

test4_1_0:
arg1 = Jcar(arglist);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varX,th) == YES)
{
test4_1_0_0_join:
arglist = Jwcons(Jmakecomp("a"),Jwcons(varX,NIL,th),th);
body[0][th] = Smake_det(&&test4_1_0_0,0,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test4_1_0_1_join;
test4_1_0_0:
varX= proof_obj[Sentity(pc[th],th)][0][th];
callpred = Jderef(arglist,th);
callprop = Jget_prop(callpred);
switch(callprop){
case(NONDET):
call_flag = 1;
pc[th] = Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th);
call_flag = 0;
goto loop;
case(BUILTIN):
case(DET):
case(TAIL):
if(Jcallsubr(Jcar(callpred),Jcdr(callpred),NIL,th)==YES) goto success;
else goto failse;
}
test4_1_0_1_join:
arglist = Jwlistcons(varX,Jwlistcons(Jmakeint(1),NIL,th),th);
body[1][th] = Smake_det(&&test4_1_0_1,1,th);
Ssave_arg(arglist,th);
proof_obj[op[th]][0][th] = varX;
goto test4_1_0_2_join;
test4_1_0_1:
varX= proof_obj[Sentity(pc[th],th)][0][th];
subr_number = 64;
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES){
goto success;}
else goto failse;
test4_1_0_2_join:
front = Sfront(pc[th],th);
back = Sback(pc[th],th);
for(i=1;i>=0;i--)back = Scons(body[i][th],back,th);
Sconc(front,back,th);
pc[th] = back;
goto loop;
}
test4_1_1:
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
