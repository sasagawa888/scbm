#include "jump.h"
static int c_fib(int arglist, int rest, int th);
static int c_color(int arglist, int rest, int th);
static int c_likes(int arglist, int rest, int th);
static int c_select1(int arglist, int rest, int th);
static int c_perm1(int arglist, int rest, int th);
static int user_scbm(int pred, int arity, int clause, int arglist, int rest, int th);
static int c_fib(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(0,n,0,arglist,rest,th));
}

static int c_color(int arglist, int rest, int th){
int n;
n = Jlength(arglist);
return(user_scbm(1,n,0,arglist,rest,th));
}

static int c_likes(int arglist, int rest, int th){
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

void init_tpredicate(void){
(deftpred)("fib",c_fib,2,1);
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
int arg1,arg2,arg3,arg4,arg5,aeg6,arg7,arg8,arg9,arg10,subr_number,varN,varN1,varN2,varX,varX1,varX2,varXs,varY,varYs,varZs;
np[th] = 0; rp[th] = 0;
Spush_back(&&allfail,arglist,th);
Spush_next(&&success,th);
switch(pred){
case 0: goto fib;
case 1: goto color;
case 2: goto likes;
case 3: goto select1;
case 4: goto perm1;
}
fib:
switch(arity){
case 2: goto fib_2;
default: goto allfail;
}
color:
switch(arity){
case 1: goto color_1;
default: goto allfail;
}
likes:
switch(arity){
case 2: goto likes_2;
default: goto allfail;
}
select1:
switch(arity){
case 3: goto select1_3;
default: goto allfail;
}
perm1:
switch(arity){
case 2: goto perm1_2;
default: goto allfail;
}
fib_2:
Jinc_proof(th);
switch(clause){
case 0: goto fib_2_0;
case 1: goto fib_2_1;
case 2: goto fib_2_2;
case 3: goto fib_2_3;
default: goto allfail;
}
printf("fib rp=%d np=%d", rp[th], np[th]);Jprint(arglist); Jprint(Jderef(arglist,th));Snewline();Jinc_proof(th);
switch(clause){
case 0: goto fib_2_0;
case 1: goto fib_2_1;
case 2: goto fib_2_2;
case 3: goto fib_2_3;
default: goto allfail;
}
color_1:
Jinc_proof(th);
switch(clause){
case 0: goto color_1_0;
case 1: goto color_1_1;
case 2: goto color_1_2;
case 3: goto color_1_3;
default: goto allfail;
}
printf("color rp=%d np=%d", rp[th], np[th]);Jprint(arglist); Jprint(Jderef(arglist,th));Snewline();Jinc_proof(th);
switch(clause){
case 0: goto color_1_0;
case 1: goto color_1_1;
case 2: goto color_1_2;
case 3: goto color_1_3;
default: goto allfail;
}
likes_2:
Jinc_proof(th);
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
printf("likes rp=%d np=%d", rp[th], np[th]);Jprint(arglist); Jprint(Jderef(arglist,th));Snewline();Jinc_proof(th);
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
select1_3:
Jinc_proof(th);
switch(clause){
case 0: goto select1_3_0;
case 1: goto select1_3_1;
case 2: goto select1_3_2;
default: goto allfail;
}
printf("select1 rp=%d np=%d", rp[th], np[th]);Jprint(arglist); Jprint(Jderef(arglist,th));Snewline();Jinc_proof(th);
switch(clause){
case 0: goto select1_3_0;
case 1: goto select1_3_1;
case 2: goto select1_3_2;
default: goto allfail;
}
perm1_2:
Jinc_proof(th);
switch(clause){
case 0: goto perm1_2_0;
case 1: goto perm1_2_1;
case 2: goto perm1_2_2;
default: goto allfail;
}
printf("perm1 rp=%d np=%d", rp[th], np[th]);Jprint(arglist); Jprint(Jderef(arglist,th));Snewline();Jinc_proof(th);
switch(clause){
case 0: goto perm1_2_0;
case 1: goto perm1_2_1;
case 2: goto perm1_2_2;
default: goto allfail;
}
fib_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
Sset_back(&&fib_2_1,th);
if(Junify_int(arg1,Jmakeint(0),th) == YES && Junify_int(arg2,Jmakeint(0),th) == YES)
{
goto success;
}
fib_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
Sset_back(&&fib_2_2,th);
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
Sset_back(&&fib_2_3,th);
if(Junify_var(arg1,varN,th) == YES && Junify_var(arg2,varX,th) == YES)
{
fib_2_2_0:
Jdebug(th);
back_stack[rp[th]+1][1][th] = varN1;
back_stack[rp[th]+1][2][th] = varN2;
back_stack[rp[th]+1][3][th] = varX1;
back_stack[rp[th]+1][4][th] = varX2;
back_stack[rp[th]+1][5][th] = varN;
back_stack[rp[th]+1][6][th] = varX;
arglist = Jwlistcons(varN1,Jwlistcons(Jwcons(2220,Jwcons(varN,Jwcons(Jmakeint(1),NIL,th),th),th),NIL,th),th);
Spush_back(&&fib_2_3,arglist,th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
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
arglist = Jwlistcons(varN1,Jwlistcons(varX1,NIL,th),th);
Spush_back(&&fib_2_3,arglist,th);
goto fib_2_2_1join;
fib_2_2_1back:
varN1= back_stack[rp[th]+1][1][th];
varN2= back_stack[rp[th]+1][2][th];
varX1= back_stack[rp[th]+1][3][th];
varX2= back_stack[rp[th]+1][4][th];
varN= back_stack[rp[th]+1][5][th];
varX= back_stack[rp[th]+1][6][th];
fib_2_2_1join:
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
Spush_next(&&fib_2_2_2,th);
clause = Sget_choice(th);
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
arglist = Jwlistcons(varN2,Jwlistcons(Jwcons(2220,Jwcons(varN,Jwcons(Jmakeint(2),NIL,th),th),th),NIL,th),th);
Spush_back(&&fib_2_2_1back,arglist,th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
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
arglist = Jwlistcons(varN2,Jwlistcons(varX2,NIL,th),th);
goto fib_2_2_3join;
fib_2_2_3back:
varN1= back_stack[rp[th]+1][1][th];
varN2= back_stack[rp[th]+1][2][th];
varX1= back_stack[rp[th]+1][3][th];
varX2= back_stack[rp[th]+1][4][th];
varN= back_stack[rp[th]+1][5][th];
varX= back_stack[rp[th]+1][6][th];
fib_2_2_3join:
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
Spush_next(&&fib_2_2_4,th);
clause = Sget_choice(th);
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
arglist = Jwlistcons(varX,Jwlistcons(Jwcons(2179,Jwcons(varX1,Jwcons(varX2,NIL,th),th),th),NIL,th),th);
Spush_back(&&fib_2_2_3back,arglist,th);
next_stack[np[th]+1][1][th] = varN1;
next_stack[np[th]+1][2][th] = varN2;
next_stack[np[th]+1][3][th] = varX1;
next_stack[np[th]+1][4][th] = varX2;
next_stack[np[th]+1][5][th] = varN;
next_stack[np[th]+1][6][th] = varX;
Spush_next(&&fib_2_2_5,th);
subr_number = 187;
goto builtin_call;
fib_2_2_5:
goto success;
}
fib_2_3:
Sreset_back(th);
goto allfail;

color_1_0:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
Sset_back(&&color_1_1,th);
if(Junify_atom(arg1,Jmakeconst("red"),th) == YES)
{
goto success;
}
color_1_1:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
Sset_back(&&color_1_2,th);
if(Junify_atom(arg1,Jmakeconst("green"),th) == YES)
{
goto success;
}
color_1_2:
arg1 = Jcar(arglist);
Srelease(th);
Sinc_choice(th);
Sset_back(&&color_1_3,th);
if(Junify_atom(arg1,Jmakeconst("blue"),th) == YES)
{
goto success;
}
color_1_3:
Sreset_back(th);
goto allfail;

likes_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
Sset_back(&&likes_2_1,th);
if(Junify_atom(arg1,Jmakeconst("kim"),th) == YES && Junify_atom(arg2,Jmakeconst("robin"),th) == YES)
{
goto success;
}
likes_2_1:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
Sset_back(&&likes_2_2,th);
if(Junify_atom(arg1,Jmakeconst("sandy"),th) == YES && Junify_atom(arg2,Jmakeconst("lee"),th) == YES)
{
goto success;
}
likes_2_2:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
Sset_back(&&likes_2_3,th);
if(Junify_atom(arg1,Jmakeconst("sandy"),th) == YES && Junify_atom(arg2,Jmakeconst("kim"),th) == YES)
{
goto success;
}
likes_2_3:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
Sset_back(&&likes_2_4,th);
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
Sset_back(&&likes_2_5,th);
if(Junify_atom(arg1,Jmakeconst("sandy"),th) == YES && Junify_var(arg2,varX,th) == YES)
{
likes_2_4_0:
back_stack[rp[th]+1][1][th] = varX;
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("cats"),NIL,th),th);
Spush_back(&&likes_2_5,arglist,th);
goto likes_2_4_0join;
likes_2_4_0back:
varX= back_stack[rp[th]+1][1][th];
likes_2_4_0join:
next_stack[np[th]+1][1][th] = varX;
Spush_next(&&likes_2_4_1,th);
clause = Sget_choice(th);
goto likes_2;
likes_2_4_1:
goto success;
}
likes_2_5:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
Sset_back(&&likes_2_6,th);
if(Junify_atom(arg1,Jmakeconst("kim"),th) == YES && Junify_var(arg2,varX,th) == YES)
{
likes_2_5_0:
back_stack[rp[th]+1][1][th] = varX;
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("lee"),NIL,th),th);
Spush_back(&&likes_2_6,arglist,th);
goto likes_2_5_0join;
likes_2_5_0back:
varX= back_stack[rp[th]+1][1][th];
likes_2_5_0join:
next_stack[np[th]+1][1][th] = varX;
Spush_next(&&likes_2_5_1,th);
clause = Sget_choice(th);
goto likes_2;
likes_2_5_1:
varX= next_stack[np[th]+1][1][th];
back_stack[rp[th]+1][1][th] = varX;
arglist = Jwlistcons(varX,Jwlistcons(Jmakeconst("kim"),NIL,th),th);
Spush_back(&&likes_2_5_0back,arglist,th);
goto likes_2_5_1join;
likes_2_5_1back:
varX= back_stack[rp[th]+1][1][th];
likes_2_5_1join:
next_stack[np[th]+1][1][th] = varX;
Spush_next(&&likes_2_5_2,th);
clause = Sget_choice(th);
goto likes_2;
likes_2_5_2:
goto success;
}
likes_2_6:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
varX = Jmakevariant(th);
Sinc_choice(th);
Sset_back(&&likes_2_7,th);
if(Junify_var(arg1,varX,th) == YES && Junify_var(arg2,varX,th) == YES)
{
goto success;
}
likes_2_7:
Sreset_back(th);
goto allfail;

select1_3_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
arg3 = Jnth(arglist,3);
Srelease(th);
varX = Jmakevariant(th);
varXs = Jmakevariant(th);
Sinc_choice(th);
Sset_back(&&select1_3_1,th);
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
Sset_back(&&select1_3_2,th);
if(Junify_var(arg1,varX,th) == YES && Junify_pair(arg2,Jwlistcons(varY,varYs,th),th) == YES && Junify_pair(arg3,Jwlistcons(varY,varZs,th),th) == YES)
{
select1_3_1_0:
back_stack[rp[th]+1][1][th] = varX;
back_stack[rp[th]+1][2][th] = varYs;
back_stack[rp[th]+1][3][th] = varY;
back_stack[rp[th]+1][4][th] = varZs;
arglist = Jwlistcons(varX,Jwlistcons(varYs,Jwlistcons(varZs,NIL,th),th),th);
Spush_back(&&select1_3_2,arglist,th);
goto select1_3_1_0join;
select1_3_1_0back:
varX= back_stack[rp[th]+1][1][th];
varYs= back_stack[rp[th]+1][2][th];
varY= back_stack[rp[th]+1][3][th];
varZs= back_stack[rp[th]+1][4][th];
select1_3_1_0join:
next_stack[np[th]+1][1][th] = varX;
next_stack[np[th]+1][2][th] = varYs;
next_stack[np[th]+1][3][th] = varY;
next_stack[np[th]+1][4][th] = varZs;
Spush_next(&&select1_3_1_1,th);
clause = Sget_choice(th);
goto select1_3;
select1_3_1_1:
goto success;
}
select1_3_2:
Sreset_back(th);
goto allfail;

perm1_2_0:
arg1 = Jcar(arglist);
arg2 = Jnth(arglist,2);
Srelease(th);
Sinc_choice(th);
Sset_back(&&perm1_2_1,th);
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
Sset_back(&&perm1_2_2,th);
if(Junify_var(arg1,varXs,th) == YES && Junify_pair(arg2,Jwlistcons(varX,varYs,th),th) == YES)
{
perm1_2_1_0:
back_stack[rp[th]+1][1][th] = varZs;
back_stack[rp[th]+1][2][th] = varXs;
back_stack[rp[th]+1][3][th] = varX;
back_stack[rp[th]+1][4][th] = varYs;
arglist = Jwlistcons(varX,Jwlistcons(varXs,Jwlistcons(varZs,NIL,th),th),th);
Spush_back(&&perm1_2_2,arglist,th);
goto perm1_2_1_0join;
perm1_2_1_0back:
varZs= back_stack[rp[th]+1][1][th];
varXs= back_stack[rp[th]+1][2][th];
varX= back_stack[rp[th]+1][3][th];
varYs= back_stack[rp[th]+1][4][th];
perm1_2_1_0join:
next_stack[np[th]+1][1][th] = varZs;
next_stack[np[th]+1][2][th] = varXs;
next_stack[np[th]+1][3][th] = varX;
next_stack[np[th]+1][4][th] = varYs;
Spush_next(&&perm1_2_1_1,th);
clause = Sget_choice(th);
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
arglist = Jwlistcons(varZs,Jwlistcons(varYs,NIL,th),th);
Spush_back(&&perm1_2_1_0back,arglist,th);
goto perm1_2_1_1join;
perm1_2_1_1back:
varZs= back_stack[rp[th]+1][1][th];
varXs= back_stack[rp[th]+1][2][th];
varX= back_stack[rp[th]+1][3][th];
varYs= back_stack[rp[th]+1][4][th];
perm1_2_1_1join:
next_stack[np[th]+1][1][th] = varZs;
next_stack[np[th]+1][2][th] = varXs;
next_stack[np[th]+1][3][th] = varX;
next_stack[np[th]+1][4][th] = varYs;
Spush_next(&&perm1_2_1_2,th);
clause = Sget_choice(th);
goto perm1_2;
perm1_2_1_2:
goto success;
}
perm1_2_2:
Sreset_back(th);
goto allfail;

success:
if(np[th] == 0){
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
if(rp[th]==0) {return(NO);}
next = back_goto[rp[th]][th];
np[th] = Sget_np(th);
Spop_back(th);
arglist = Sget_arg(th);
goto *next;
builtin_call:
if(Jcallsubr(subr_number,Jderef(arglist,th),NIL,th) == YES)
goto success;
else goto allfail;
}
