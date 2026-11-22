#include "jump.h"
static int c_append(int arglist, int rest, int th);
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th);
static int c_append(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(0,n,0,arglist,rest,th));
}

void init_tpredicate(void){
(deftpred)("append",c_append,3,1);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,front,back,i,callpred,callprop,varX,varXs,varYs,varZs;
int body[10][THREADSIZE], body1[10][THREADSIZE];
pc[th] = 0; lp[th] = 0; op[th] = 0;
if(!call_flag[th]) proof[th] = 0;
switch(pred){
case 0: goto append;
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
pc[th] = Sbacktrack2(pc[th],th);
if (pc[th] == NIL) {Jset_proof(proof[th],th); return(NO);}
else goto loop;
}
