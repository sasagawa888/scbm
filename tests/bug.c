#include "jump.h"
static int c_color(int arglist, int rest, int th);
static int c_likes(int arglist, int rest, int th);
static int c_select1(int arglist, int rest, int th);
static int c_perm1(int arglist, int rest, int th);
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th);
static int c_color(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(0,n,0,arglist,rest,th));
}

static int c_likes(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(1,n,0,arglist,rest,th));
}

static int c_select1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(2,n,0,arglist,rest,th));
}

static int c_perm1(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
Ssave_arg(arglist,th);
return(user_scbm(3,n,0,arglist,rest,th));
}

void init_tpredicate(void){
(deftpred)("color",c_color,1,1);
(deftpred)("likes",c_likes,2,1);
(deftpred)("select1",c_select1,3,1);
(deftpred)("perm1",c_perm1,2,1);
}
void init_declare(void){
int body,th; th=0;
}
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th){
void *next;
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,varX_,varY_,varZ_,varA_,varX,varXs,varY,varYs,varZs;
np[th] = 0; rp[th] = 0; back_stack[0][AC_SCBM][th] = Jget_ac(th);
Spush_next(&&success,th);
switch(pred){
case 0: goto color;
case 1: goto likes;
case 2: goto select1;
case 3: goto perm1;
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
int color_1rp;
color_1entry:
Spush_back(&&color_1,arglist,th);
color_1:
printf("color");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
color_1rp = rp[th];
switch(clause){
case 0: goto color_1_0;
case 1: goto color_1_1;
case 2: goto color_1_2;
case 3: goto color_1_3;
default: goto allfail;
}
int likes_2rp;
likes_2entry:
Spush_back(&&likes_2,arglist,th);
likes_2:
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
int select1_3rp;
select1_3entry:
Spush_back(&&select1_3,arglist,th);
select1_3:
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
Spush_back(&&perm1_2,arglist,th);
perm1_2:
printf("perm1");Jprint(arglist); Jprint(Jderef(arglist,th));Sprint("");Jinc_proof(th);
perm1_2rp = rp[th];
switch(clause){
case 0: goto perm1_2_0;
case 1: goto perm1_2_1;
case 2: goto perm1_2_2;
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
likes_2_4_0:
Sprint(" path_likes_2_4_0");
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("cats"),NIL,th),th);
back_stack[rp[th]+1][1][th] = varX;
Spush_back(&&likes_2_4_0back,arglist,th);
goto likes_2_4_0join;
likes_2_4_0back:
Sprint(" back_likes_2_4_0");
varX= back_stack[rp[th]+1][1][th];
likes_2_4_0join:
Sprint(" join_likes_2_4_0");
next_stack[np[th]+1][1][th] = varX;
Sprint(" end_likes_2_4_0");
Spush_next(&&success,th);
clause = Sget_choice(th);
goto likes_2;
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
Sprint(" path_likes_2_5_0");
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("lee"),NIL,th),th);
Spush_back(&&likes_2_5_0back,arglist,th);
goto likes_2_5_0join;
likes_2_5_0back:
Sprint(" back_likes_2_5_0");
varX= back_stack[rp[th]+1][1][th];
likes_2_5_0join:
Sprint(" join_likes_2_5_0");
next_stack[np[th]+1][1][th] = varX;
Sprint(" next_likes_2_5_1");
Spush_next(&&likes_2_5_1,th);
clause = Sget_choice(th);
goto likes_2;
likes_2_5_1:
Sprint(" path_likes_2_5_1");
varX= next_stack[np[th]+1][1][th];
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("kim"),NIL,th),th);
back_stack[rp[th]+1][1][th] = varX;
Spush_back(&&likes_2_5_1back,arglist,th);
goto likes_2_5_1join;
likes_2_5_1back:
Sprint(" back_likes_2_5_1");
varX= back_stack[rp[th]+1][1][th];
likes_2_5_1join:
Sprint(" join_likes_2_5_1");
next_stack[np[th]+1][1][th] = varX;
Sprint(" end_likes_2_5_1");
Spush_next(&&success,th);
clause = Sget_choice(th);
goto likes_2;
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
Sprint(" path_select1_3_1_0");
arglist = Jwlistcons(varX,Jwlistcons(varYs,Jwlistcons(varZs,NIL,th),th),th);
back_stack[rp[th]+1][1][th] = varX;
back_stack[rp[th]+1][2][th] = varYs;
back_stack[rp[th]+1][3][th] = varY;
back_stack[rp[th]+1][4][th] = varZs;
Spush_back(&&select1_3_1_0back,arglist,th);
goto select1_3_1_0join;
select1_3_1_0back:
Sprint(" back_select1_3_1_0");
varX= back_stack[rp[th]+1][1][th];
varYs= back_stack[rp[th]+1][2][th];
varY= back_stack[rp[th]+1][3][th];
varZs= back_stack[rp[th]+1][4][th];
select1_3_1_0join:
Sprint(" join_select1_3_1_0");
next_stack[np[th]+1][1][th] = varX;
next_stack[np[th]+1][2][th] = varYs;
next_stack[np[th]+1][3][th] = varY;
next_stack[np[th]+1][4][th] = varZs;
Sprint(" end_select1_3_1_0");
Spush_next(&&success,th);
clause = Sget_choice(th);
goto select1_3;
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
Sprint(" path_perm1_2_1_0");
arglist = Jwlistcons(varX,Jwlistcons(varXs,Jwlistcons(varZs,NIL,th),th),th);
Spush_back(&&perm1_2_1_0back,arglist,th);
goto perm1_2_1_0join;
perm1_2_1_0back:
Sprint(" back_perm1_2_1_0");
varZs= back_stack[rp[th]+1][1][th];
varXs= back_stack[rp[th]+1][2][th];
varX= back_stack[rp[th]+1][3][th];
varYs= back_stack[rp[th]+1][4][th];
perm1_2_1_0join:
Sprint(" join_perm1_2_1_0");
next_stack[np[th]+1][1][th] = varZs;
next_stack[np[th]+1][2][th] = varXs;
next_stack[np[th]+1][3][th] = varX;
next_stack[np[th]+1][4][th] = varYs;
Sprint(" next_perm1_2_1_1");
Spush_next(&&perm1_2_1_1,th);
clause = Sget_choice(th);
goto select1_3;
perm1_2_1_1:
Sprint(" path_perm1_2_1_1");
varZs= next_stack[np[th]+1][1][th];
varXs= next_stack[np[th]+1][2][th];
varX= next_stack[np[th]+1][3][th];
varYs= next_stack[np[th]+1][4][th];
arglist = Jwlistcons(varZs,Jwlistcons(varYs,NIL,th),th);
back_stack[rp[th]+1][1][th] = varZs;
back_stack[rp[th]+1][2][th] = varXs;
back_stack[rp[th]+1][3][th] = varX;
back_stack[rp[th]+1][4][th] = varYs;
//Spush_back(&&perm1_2_1_1back,arglist,th);
goto perm1_2_1_1join;
perm1_2_1_1back:
Sprint(" back_perm1_2_1_1");
varZs= back_stack[rp[th]+1][1][th];
varXs= back_stack[rp[th]+1][2][th];
varX= back_stack[rp[th]+1][3][th];
varYs= back_stack[rp[th]+1][4][th];
perm1_2_1_1join:
Sprint(" join_perm1_2_1_1");
next_stack[np[th]+1][1][th] = varZs;
next_stack[np[th]+1][2][th] = varXs;
next_stack[np[th]+1][3][th] = varX;
next_stack[np[th]+1][4][th] = varYs;
Sprint(" end_perm1_2_1_1");
Spush_next(&&success,th);
clause = Sget_choice(th);
goto perm1_2;
}
perm1_2_2:
goto allfail;

success:
Sprint("success");if(np[th] == 0){
if(Jprove_all(rest,Jget_sp(th),th) == YES) return(YES);
next = back_goto[rp[th]][th];
clause = Sget_choice(th);
arglist = Sget_arg(th);
np[th] = Sget_np(th);
Spush_next(&&success,th);
goto *next;
}else{
next = next_goto[np[th]][th];
Spop_next(th);
clause = Sget_choice(th);
goto *next;}
allfail:
Sprint("allfail");Spop_back(th);
if(rp[th]==0) {return(NO);}
next = back_goto[rp[th]][th];
np[th] = Sget_np(th);
clause = Sget_choice(th);
arglist = Sget_arg(th);
goto *next;
false:
Sprint("false");if(rp[th]==0) {return(NO);}
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
