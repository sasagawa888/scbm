#include "jump.h"
static int c_likes(int arglist, int rest, int th);
static int c_fib(int arglist, int rest, int th);
static int c_fact(int arglist, int rest, int th);
static int c_color(int arglist, int rest, int th);
static int c_select1(int arglist, int rest, int th);
static int c_perm1(int arglist, int rest, int th);
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th);
static int c_likes(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(0,n,0,arglist,rest,th));
}

static int c_fib(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(1,n,0,arglist,rest,th));
}

static int c_fact(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(2,n,0,arglist,rest,th));
}

static int c_color(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(3,n,0,arglist,rest,th));
}

static int c_select1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(4,n,0,arglist,rest,th));
}

static int c_perm1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(5,n,0,arglist,rest,th));
}

void init_tpredicate(void){
(deftpred)("likes",c_likes,2,1);
(deftpred)("fib",c_fib,2,1);
(deftpred)("fact",c_fact,2,1);
(deftpred)("color",c_color,1,1);
(deftpred)("select1",c_select1,3,1);
(deftpred)("perm1",c_perm1,2,1);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,varX_,varY_,varZ_,varA_,varN,varN1,varN2,varX,varX1,varX2,varXs,varY,varYs,varZs;
np[th] = 0; rp[th] = 0;
switch(pred){
case 0: goto likes;
case 1: goto fib;
case 2: goto fact;
case 3: goto color;
case 4: goto select1;
case 5: goto perm1;
}
likes:
switch(arity){
case 2: goto likes_2entry;
default: goto allfail;
}
fib:
switch(arity){
case 2: goto fib_2entry;
default: goto allfail;
}
fact:
switch(arity){
case 2: goto fact_2entry;
default: goto allfail;
}
color:
switch(arity){
case 1: goto color_1entry;
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
int likes_2rp;
likes_2entry:
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&success,th);
Sinit_back(&&likes_2,arglist,th);
likes_2:
Jinc_proof(th);
likes_2rp = rp[th];
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
printf("likes");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
likes_2rp = rp[th];
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
int fib_2rp;
fib_2entry:
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&success,th);
Sinit_back(&&fib_2,arglist,th);
fib_2:
Jinc_proof(th);
fib_2rp = rp[th];
switch(clause){
case 0: goto fib_2_0;
case 1: goto fib_2_1;
case 2: goto fib_2_2;
case 3: goto fib_2_3;
default: goto allfail;
}
printf("fib");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
fib_2rp = rp[th];
switch(clause){
case 0: goto fib_2_0;
case 1: goto fib_2_1;
case 2: goto fib_2_2;
case 3: goto fib_2_3;
default: goto allfail;
}
int fact_2rp;
fact_2entry:
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&success,th);
Sinit_back(&&fact_2,arglist,th);
fact_2:
Jinc_proof(th);
fact_2rp = rp[th];
switch(clause){
case 0: goto fact_2_0;
case 1: goto fact_2_1;
case 2: goto fact_2_2;
default: goto allfail;
}
printf("fact");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
fact_2rp = rp[th];
switch(clause){
case 0: goto fact_2_0;
case 1: goto fact_2_1;
case 2: goto fact_2_2;
default: goto allfail;
}
int color_1rp;
color_1entry:
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&success,th);
Sinit_back(&&color_1,arglist,th);
color_1:
Jinc_proof(th);
color_1rp = rp[th];
switch(clause){
case 0: goto color_1_0;
case 1: goto color_1_1;
case 2: goto color_1_2;
case 3: goto color_1_3;
default: goto allfail;
}
printf("color");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
color_1rp = rp[th];
switch(clause){
case 0: goto color_1_0;
case 1: goto color_1_1;
case 2: goto color_1_2;
case 3: goto color_1_3;
default: goto allfail;
}
int select1_3rp;
select1_3entry:
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&success,th);
Sinit_back(&&select1_3,arglist,th);
select1_3:
Jinc_proof(th);
select1_3rp = rp[th];
switch(clause){
case 0: goto select1_3_0;
case 1: goto select1_3_1;
case 2: goto select1_3_2;
default: goto allfail;
}
printf("select1");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
select1_3rp = rp[th];
switch(clause){
case 0: goto select1_3_0;
case 1: goto select1_3_1;
case 2: goto select1_3_2;
default: goto allfail;
}
int perm1_2rp;
perm1_2entry:
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&success,th);
Sinit_back(&&perm1_2,arglist,th);
perm1_2:
Jinc_proof(th);
perm1_2rp = rp[th];
switch(clause){
case 0: goto perm1_2_0;
case 1: goto perm1_2_1;
case 2: goto perm1_2_2;
default: goto allfail;
}
printf("perm1");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
perm1_2rp = rp[th];
switch(clause){
case 0: goto perm1_2_0;
case 1: goto perm1_2_1;
case 2: goto perm1_2_2;
default: goto allfail;
}
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
likes_2_4_0:
clause = 0;
goto likes_2_4_0join;
likes_2_4_0back:
varX= back_stack[rp[th]][1][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
likes_2_4_0join:
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("cats"),NIL,th),th);
next_stack[np[th]+1][1][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&likes_2_4_1,th);
goto likes_2;
likes_2_4_1:
varX= next_stack[np[th]+1][1][th];
back_stack[rp[th]+1][1][th] = varX;
Spush_back(&&likes_2_4_0back,arglist,th);
goto success;
}
likes_2_5:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_atom(arg1,Jmakeconst("kim"),th) == YES && Junify_var(arg2,varX,th) == YES)
{
likes_2_5_0:
clause = 0;
goto likes_2_5_0join;
likes_2_5_0back:
varX= back_stack[rp[th]][1][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
likes_2_5_0join:
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("lee"),NIL,th),th);
next_stack[np[th]+1][1][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&likes_2_5_1,th);
goto likes_2;
likes_2_5_1:
varX= next_stack[np[th]+1][1][th];
back_stack[rp[th]+1][1][th] = varX;
Spush_back(&&likes_2_5_0back,arglist,th);
clause = 0;
goto likes_2_5_1join;
likes_2_5_1back:
varX= back_stack[rp[th]][1][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
likes_2_5_1join:
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("kim"),NIL,th),th);
next_stack[np[th]+1][1][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&likes_2_5_2,th);
goto likes_2;
likes_2_5_2:
varX= next_stack[np[th]+1][1][th];
back_stack[rp[th]+1][1][th] = varX;
Spush_back(&&likes_2_5_1back,arglist,th);
goto success;
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
goto allfail;

fib_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_int(arg1,Jmakeint(0),th) == YES && Junify_int(arg2,Jmakeint(0),th) == YES)
{
goto success;
}
fib_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
if(Junify_int(arg1,Jmakeint(1),th) == YES && Junify_int(arg2,Jmakeint(1),th) == YES)
{
goto success;
}
fib_2_2:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varN1 = Jmakevariant(th);
varN2 = Jmakevariant(th);
varX1 = Jmakevariant(th);
varX2 = Jmakevariant(th);
varN = Jmakevariant(th);
varX = Jmakevariant(th);
Sinc_choice(th);
if(Junify_var(arg1,varN,th) == YES && Junify_var(arg2,varX,th) == YES)
{
fib_2_2_0:
arglist = Jwlistcons(varN1,Jwlistcons(Jwcons(2220,Jwcons(varN,Jwcons(Jmakeint(1),NIL,th),th),th),NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fib_2_2_1,th);
subr_number = 187;
goto builtin_call;
fib_2_2_1:
varN1= next_stack[np[th]+1][1][th];
varN2= next_stack[np[th]+1][2][th];
varX1= next_stack[np[th]+1][3][th];
varX2= next_stack[np[th]+1][4][th];
varN= next_stack[np[th]+1][5][th];
varX= next_stack[np[th]+1][6][th];
clause = 0;
goto fib_2_2_1join;
fib_2_2_1back:
varN1= back_stack[rp[th]][1][th];
varN2= back_stack[rp[th]][2][th];
varX1= back_stack[rp[th]][3][th];
varX2= back_stack[rp[th]][4][th];
varN= back_stack[rp[th]][5][th];
varX= back_stack[rp[th]][6][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
fib_2_2_1join:
arglist = Jwlistcons(varN1,Jwlistcons(varX1,NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fib_2_2_2,th);
goto fib_2;
fib_2_2_2:
varN1= next_stack[np[th]+1][1][th];
varN2= next_stack[np[th]+1][2][th];
varX1= next_stack[np[th]+1][3][th];
varX2= next_stack[np[th]+1][4][th];
varN= next_stack[np[th]+1][5][th];
varX= next_stack[np[th]+1][6][th];
back_stack[rp[th]+1][1][th] = varN1;
back_stack[rp[th]+1][2][th] = varN2;
back_stack[rp[th]+1][3][th] = varX1;
back_stack[rp[th]+1][4][th] = varX2;
back_stack[rp[th]+1][5][th] = varN;
back_stack[rp[th]+1][6][th] = varX;
Spush_back(&&fib_2_2_1back,arglist,th);
arglist = Jwlistcons(varN2,Jwlistcons(Jwcons(2220,Jwcons(varN,Jwcons(Jmakeint(2),NIL,th),th),th),NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fib_2_2_3,th);
subr_number = 187;
goto builtin_call;
fib_2_2_3:
varN1= next_stack[np[th]+1][1][th];
varN2= next_stack[np[th]+1][2][th];
varX1= next_stack[np[th]+1][3][th];
varX2= next_stack[np[th]+1][4][th];
varN= next_stack[np[th]+1][5][th];
varX= next_stack[np[th]+1][6][th];
back_stack[rp[th]+1][1][th] = varN1;
back_stack[rp[th]+1][2][th] = varN2;
back_stack[rp[th]+1][3][th] = varX1;
back_stack[rp[th]+1][4][th] = varX2;
back_stack[rp[th]+1][5][th] = varN;
back_stack[rp[th]+1][6][th] = varX;
Spush_back(&&fib_2_2_1back,arglist,th);
clause = 0;
goto fib_2_2_3join;
fib_2_2_3back:
varN1= back_stack[rp[th]][1][th];
varN2= back_stack[rp[th]][2][th];
varX1= back_stack[rp[th]][3][th];
varX2= back_stack[rp[th]][4][th];
varN= back_stack[rp[th]][5][th];
varX= back_stack[rp[th]][6][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
fib_2_2_3join:
arglist = Jwlistcons(varN2,Jwlistcons(varX2,NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fib_2_2_4,th);
goto fib_2;
fib_2_2_4:
varN1= next_stack[np[th]+1][1][th];
varN2= next_stack[np[th]+1][2][th];
varX1= next_stack[np[th]+1][3][th];
varX2= next_stack[np[th]+1][4][th];
varN= next_stack[np[th]+1][5][th];
varX= next_stack[np[th]+1][6][th];
back_stack[rp[th]+1][1][th] = varN1;
back_stack[rp[th]+1][2][th] = varN2;
back_stack[rp[th]+1][3][th] = varX1;
back_stack[rp[th]+1][4][th] = varX2;
back_stack[rp[th]+1][5][th] = varN;
back_stack[rp[th]+1][6][th] = varX;
Spush_back(&&fib_2_2_3back,arglist,th);
arglist = Jwlistcons(varX,Jwlistcons(Jwcons(2179,Jwcons(varX1,Jwcons(varX2,NIL,th),th),th),NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fib_2_2_5,th);
subr_number = 187;
goto builtin_call;
fib_2_2_5:
varN1= next_stack[np[th]+1][1][th];
varN2= next_stack[np[th]+1][2][th];
varX1= next_stack[np[th]+1][3][th];
varX2= next_stack[np[th]+1][4][th];
varN= next_stack[np[th]+1][5][th];
varX= next_stack[np[th]+1][6][th];
back_stack[rp[th]+1][1][th] = varN1;
back_stack[rp[th]+1][2][th] = varN2;
back_stack[rp[th]+1][3][th] = varX1;
back_stack[rp[th]+1][4][th] = varX2;
back_stack[rp[th]+1][5][th] = varN;
back_stack[rp[th]+1][6][th] = varX;
Spush_back(&&fib_2_2_3back,arglist,th);
goto success;
}
fib_2_3:
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
fact_2_1_0:
arglist = Jwlistcons(varN1,Jwlistcons(Jwcons(2220,Jwcons(varN,Jwcons(Jmakeint(1),NIL,th),th),th),NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varX1;
next_stack[np[th]+1][3][th] = varN;
next_stack[np[th]+1][4][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fact_2_1_1,th);
subr_number = 187;
goto builtin_call;
fact_2_1_1:
varN1= next_stack[np[th]+1][1][th];
varX1= next_stack[np[th]+1][2][th];
varN= next_stack[np[th]+1][3][th];
varX= next_stack[np[th]+1][4][th];
clause = 0;
goto fact_2_1_1join;
fact_2_1_1back:
varN1= back_stack[rp[th]][1][th];
varX1= back_stack[rp[th]][2][th];
varN= back_stack[rp[th]][3][th];
varX= back_stack[rp[th]][4][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
fact_2_1_1join:
arglist = Jwlistcons(varN1,Jwlistcons(varX1,NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varX1;
next_stack[np[th]+1][3][th] = varN;
next_stack[np[th]+1][4][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fact_2_1_2,th);
goto fact_2;
fact_2_1_2:
varN1= next_stack[np[th]+1][1][th];
varX1= next_stack[np[th]+1][2][th];
varN= next_stack[np[th]+1][3][th];
varX= next_stack[np[th]+1][4][th];
back_stack[rp[th]+1][1][th] = varN1;
back_stack[rp[th]+1][2][th] = varX1;
back_stack[rp[th]+1][3][th] = varN;
back_stack[rp[th]+1][4][th] = varX;
Spush_back(&&fact_2_1_1back,arglist,th);
arglist = Jwlistcons(varX,Jwlistcons(Jwcons(2261,Jwcons(varN,Jwcons(varX1,NIL,th),th),th),NIL,th),th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varX1;
next_stack[np[th]+1][3][th] = varN;
next_stack[np[th]+1][4][th] = varX;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&fact_2_1_3,th);
subr_number = 187;
goto builtin_call;
fact_2_1_3:
varN1= next_stack[np[th]+1][1][th];
varX1= next_stack[np[th]+1][2][th];
varN= next_stack[np[th]+1][3][th];
varX= next_stack[np[th]+1][4][th];
back_stack[rp[th]+1][1][th] = varN1;
back_stack[rp[th]+1][2][th] = varX1;
back_stack[rp[th]+1][3][th] = varN;
back_stack[rp[th]+1][4][th] = varX;
Spush_back(&&fact_2_1_1back,arglist,th);
goto success;
}
fact_2_2:
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
select1_3_1_0:
clause = 0;
goto select1_3_1_0join;
select1_3_1_0back:
varX= back_stack[rp[th]][1][th];
varYs= back_stack[rp[th]][2][th];
varY= back_stack[rp[th]][3][th];
varZs= back_stack[rp[th]][4][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
select1_3_1_0join:
arglist = Jwlistcons(varX,Jwlistcons(varYs,Jwlistcons(varZs,NIL,th),th),th);
next_stack[np[th]+1][1][th] = varX;
next_stack[np[th]+1][2][th] = varYs;
next_stack[np[th]+1][3][th] = varY;
next_stack[np[th]+1][4][th] = varZs;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&select1_3_1_1,th);
goto select1_3;
select1_3_1_1:
varX= next_stack[np[th]+1][1][th];
varYs= next_stack[np[th]+1][2][th];
varY= next_stack[np[th]+1][3][th];
varZs= next_stack[np[th]+1][4][th];
back_stack[rp[th]+1][1][th] = varX;
back_stack[rp[th]+1][2][th] = varYs;
back_stack[rp[th]+1][3][th] = varY;
back_stack[rp[th]+1][4][th] = varZs;
Spush_back(&&select1_3_1_0back,arglist,th);
goto success;
}
select1_3_2:
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
perm1_2_1_0:
clause = 0;
goto perm1_2_1_0join;
perm1_2_1_0back:
varZs= back_stack[rp[th]][1][th];
varXs= back_stack[rp[th]][2][th];
varX= back_stack[rp[th]][3][th];
varYs= back_stack[rp[th]][4][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
perm1_2_1_0join:
arglist = Jwlistcons(varX,Jwlistcons(varXs,Jwlistcons(varZs,NIL,th),th),th);
next_stack[np[th]+1][1][th] = varZs;
next_stack[np[th]+1][2][th] = varXs;
next_stack[np[th]+1][3][th] = varX;
next_stack[np[th]+1][4][th] = varYs;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&perm1_2_1_1,th);
goto select1_3;
perm1_2_1_1:
varZs= next_stack[np[th]+1][1][th];
varXs= next_stack[np[th]+1][2][th];
varX= next_stack[np[th]+1][3][th];
varYs= next_stack[np[th]+1][4][th];
back_stack[rp[th]+1][1][th] = varZs;
back_stack[rp[th]+1][2][th] = varXs;
back_stack[rp[th]+1][3][th] = varX;
back_stack[rp[th]+1][4][th] = varYs;
Spush_back(&&perm1_2_1_0back,arglist,th);
clause = 0;
goto perm1_2_1_1join;
perm1_2_1_1back:
varZs= back_stack[rp[th]][1][th];
varXs= back_stack[rp[th]][2][th];
varX= back_stack[rp[th]][3][th];
varYs= back_stack[rp[th]][4][th];
arglist = back_stack[rp[th]][ARGLIST_SCBM][th];
Jset_sp(back_stack[rp[th]][SP_SCBM][th],th);
Jset_wp(back_stack[rp[th]][WP_SCBM][th],th);
Jset_ac(back_stack[rp[th]][AC_SCBM][th],th);
np[th] = back_stack[rp[th]][NP_SCBM][th];
clause = Sget_choice(th);
perm1_2_1_1join:
arglist = Jwlistcons(varZs,Jwlistcons(varYs,NIL,th),th);
next_stack[np[th]+1][1][th] = varZs;
next_stack[np[th]+1][2][th] = varXs;
next_stack[np[th]+1][3][th] = varX;
next_stack[np[th]+1][4][th] = varYs;
next_stack[np[th]+1][ARGLIST_SCBM][th] = arglist;
next_stack[np[th]+1][SP_SCBM][th] = Jget_sp(th);
next_stack[np[th]+1][WP_SCBM][th] = Jget_wp(th);
next_stack[np[th]+1][AC_SCBM][th] = Jget_ac(th);
next_stack[np[th]+1][NP_SCBM][th] = np[th];
Spush_next(&&perm1_2_1_2,th);
goto perm1_2;
perm1_2_1_2:
varZs= next_stack[np[th]+1][1][th];
varXs= next_stack[np[th]+1][2][th];
varX= next_stack[np[th]+1][3][th];
varYs= next_stack[np[th]+1][4][th];
back_stack[rp[th]+1][1][th] = varZs;
back_stack[rp[th]+1][2][th] = varXs;
back_stack[rp[th]+1][3][th] = varX;
back_stack[rp[th]+1][4][th] = varYs;
Spush_back(&&perm1_2_1_1back,arglist,th);
goto success;
}
perm1_2_2:
goto allfail;

success:
if(np[th] == 0){
if(Jprove_all(rest,Jget_sp(th),th) == YES) return(YES);
next = back_goto[rp[th]][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
np[th] = Sget_np(th);
goto *next;
}else{
next = next_goto[np[th]][th];
Spop_next(th);
clause = Sget_choice(th);
goto *next;}
allfail:
Spop_back(th);
if(rp[th]==0) {return(NO);}
next = back_goto[rp[th]][th];
np[th] = Sget_np(th);
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto *next;
false:
if(rp[th]==0) {return(NO);}
next = back_goto[rp[th]][th];
np[th] = Sget_np(th);
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto *next;
builtin_call:
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES)
goto success;
else goto false;
}
