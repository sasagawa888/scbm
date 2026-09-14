#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "mpl.h"


typedef void (*tpred)(char *, int (*pred)(int, int, int), int, int);
typedef void (*tuser)(char *, int (*user)(int, int), int weight, int spec);


char *get_name(int x)
{
    return (GET_NAME(x));
}

// cppcheck-suppress resourceLeak
void dynamic_link(int x)
{
    char str[STRSIZE];
    void *hmod;
    int (*abi_version)(void);

    int (*init_f0)(int x, scbm_function y);
    int (*init_f1)(int x, scbm_function y);
    int (*init_f2)(int x, scbm_function y);
    int (*init_f3)(int x, scbm_function y);
    int (*init_f4)(int x, scbm_function y);
    int (*init_f5)(int x, scbm_function y);
    int (*init_f6)(int x, scbm_function y);
    int (*init_f7)(int x, scbm_function y);
    void (*init_deftpred)(tpred x);
    void (*init_deftinfix)(tuser x);
    void (*init_tpredicate)();
    void (*init_declare)();

    if (snprintf(str, sizeof(str), "%s%s",
		 strchr(GET_NAME(x), '/') ? "" : "./", GET_NAME(x)) >= sizeof(str))
	exception(RESOURCE_ERR, makestr("module path length"), x, 0);

    dlerror();
    hmod = dlopen(str, RTLD_NOW | RTLD_LOCAL);
    if (hmod == NULL) {
	const char *err = dlerror();
	fprintf(stderr, "dlopen error: %s\n", err ? err : "unknown error");
	exception(SYSTEM_ERR, makestr("load"), x, 0);
    }

    abi_version = dlsym(hmod, "scbm_abi_version");
    if (!abi_version || abi_version() != SCBM_ABI_VERSION)
	goto incompatible;

    init_f0 = dlsym(hmod, "init0");
    init_f1 = dlsym(hmod, "init1");
    init_f2 = dlsym(hmod, "init2");
    init_f3 = dlsym(hmod, "init3");
    init_f4 = dlsym(hmod, "init4");
    init_f5 = dlsym(hmod, "init5");
    init_f6 = dlsym(hmod, "init6");
    init_f7 = dlsym(hmod, "init7");
    init_deftpred = dlsym(hmod, "init_deftpred");
    init_deftinfix = dlsym(hmod, "init_deftinfix");
    init_tpredicate = dlsym(hmod, "init_tpredicate");
    init_declare = dlsym(hmod, "init_declare");

    if (!init_f0 || !init_f1 || !init_f2 || !init_f3 || !init_f4 ||
	!init_f5 || !init_f6 || !init_f7 || !init_deftpred || !init_deftinfix ||
	!init_tpredicate || !init_declare)
	goto incompatible;

#define REGISTER(table, index, function) \
    do { \
	if (init_f##table(index, (scbm_function)function) != YES) \
	    goto incompatible; \
    } while (0)

    //argument-0 type
    REGISTER(0, CHECKGBC_IDX, checkgbc);
    REGISTER(0, GBC_IDX, gbc);
    REGISTER(0, FRESHCELL_IDX, freshcell);
    REGISTER(0, DEBUG_IDX, debug);
    REGISTER(0, STEPPER_IDX, stepper);

    //argument-1 type
    REGISTER(1, CAR_IDX, car);
    REGISTER(1, CDR_IDX, cdr);
    REGISTER(1, CADR_IDX, cadr);
    REGISTER(1, CADDR_IDX, caddr);
    REGISTER(1, CAAR_IDX, caar);
    REGISTER(1, CADAR_IDX, cadar);
    REGISTER(1, PRINT_IDX, print);
    REGISTER(1, LENGTH_IDX, length);
    REGISTER(1, GET_INT_IDX, get_int);
    REGISTER(1, LISTP_IDX, listp);
    REGISTER(1, STRUCTUREP_IDX, structurep);
    REGISTER(1, VARIABLEP_IDX, variablep);
    REGISTER(1, GET_SP_IDX, get_sp);
    REGISTER(1, GET_WP_IDX, get_wp);
    REGISTER(1, GET_AC_IDX, get_ac);
    REGISTER(1, INC_PROOF_IDX, inc_proof);
    REGISTER(1, MAKEVARIANT_IDX, makevariant);
    REGISTER(1, RANDOM_IDX, f_random);
    REGISTER(1, ADD_DYNAMIC_IDX, add_dynamic);
    REGISTER(1, BIGX_TO_PARMANENT_IDX, bigx_to_parmanent);
    REGISTER(1, ARITY_COUNT_IDX, arity_count);

    
    //argument-2 type
    REGISTER(2, CONS_IDX, cons);
    REGISTER(2, EQP_IDX, eqp);
    REGISTER(2, EQUALP_IDX, equalp);
    REGISTER(2, NUMEQP_IDX, numeqp);
    REGISTER(2, SMALLERP_IDX, smallerp);
    REGISTER(2, EQSMALLERP_IDX, eqsmallerp);
    REGISTER(2, GREATERP_IDX, greaterp);
    REGISTER(2, EQGREATERP_IDX, eqgreaterp);
    REGISTER(2, LISTCONS_IDX, listcons);
    REGISTER(2, LIST2_IDX, list2);
    REGISTER(2, SET_CAR_IDX, set_car);
    REGISTER(2, SET_CDR_IDX, set_cdr);
    REGISTER(2, SET_AUX_IDX, set_aux);
    REGISTER(2, NOT_NUMEQP_IDX, not_numeqp);
    REGISTER(2, SET_VAR_IDX, set_var);
    REGISTER(2, NTH_IDX, nth);
    REGISTER(2, UNBIND_IDX, unbind);
    REGISTER(2, SET_SP_IDX, set_sp);
    REGISTER(2, SET_WP_IDX, set_wp);
    REGISTER(2, SET_AC_IDX, set_ac);
    REGISTER(2, DEREF_IDX, deref);
    REGISTER(2, WLIST1_IDX, wlist1);
    REGISTER(2, SIN_IDX, f_sin);
    REGISTER(2, ASIN_IDX, f_asin);
    REGISTER(2, COS_IDX, f_cos);
    REGISTER(2, ACOS_IDX, f_acos);
    REGISTER(2, TAN_IDX, f_tan);
    REGISTER(2, ATAN_IDX, f_atan);
    REGISTER(2, EXP_IDX, f_exp);
    REGISTER(2, LOG_IDX, f_log);
    REGISTER(2, LN_IDX, f_ln);
    REGISTER(2, LIST1_IDX, list1);
    REGISTER(2, RANDI_IDX, f_randi);
    REGISTER(2, SQRT_IDX, f_sqrt);
    REGISTER(2, INTEGER_IDX, f_integer);
    REGISTER(2, ABS_IDX, f_abs);
    REGISTER(2, COMPLEMENT_IDX, f_complement);
    REGISTER(2, UNIFY_NIL_IDX, unify_nil);
    REGISTER(2, COPY_WORK_IDX, copy_work);
    


    //argument-3
    REGISTER(3, LIST3_IDX, list3);
    REGISTER(3, ERRORCOMP_IDX, errorcomp);
    REGISTER(3, WLISTCONS_IDX, wlistcons);
    REGISTER(3, UNIFY_IDX, unify);
    REGISTER(3, UNIFY_PAIR_IDX, unify_pair);
    REGISTER(3, UNIFY_VAR_IDX, unify_var);
    REGISTER(3, UNIFY_INT_IDX, unify_int);
    REGISTER(3, UNIFY_FLT_IDX, unify_flt);
    REGISTER(3, UNIFY_BIG_IDX, unify_big);
    REGISTER(3, UNIFY_STR_IDX, unify_str);
    REGISTER(3, UNIFY_ATOM_IDX, unify_atom);
    REGISTER(3, PROVE_ALL_IDX, prove_all);
    REGISTER(3, WCONS_IDX, wcons);
    REGISTER(3, WLIST2_IDX, wlist2);
    REGISTER(3, ADDTAIL_BODY_IDX, addtail_body);
    REGISTER(3, PLUS_IDX, f_plus);
    REGISTER(3, MINUS_IDX, f_minus);
    REGISTER(3, MULT_IDX, f_mult);
    REGISTER(3, DIVIDE_IDX, f_divide);
    REGISTER(3, REMAINDER_IDX, s_remainder);
    REGISTER(3, QUOTIENT_IDX, quotient);
    REGISTER(3, MOD_IDX, f_mod);
    REGISTER(3, EXPT_IDX, f_expt);
    REGISTER(3, LEFTSHIFT_IDX, f_leftshift);
    REGISTER(3, RIGHTSHIFT_IDX, f_rightshift);
    REGISTER(3, LOGICALAND_IDX, f_logicaland);
    REGISTER(3, LOGICALOR_IDX, f_logicalor);
    REGISTER(3, XOR_IDX, f_xor);
    REGISTER(3, ROUND_IDX, f_round);
    REGISTER(3, DIV_IDX, f_div);
    REGISTER(3, CALL_NONDET_IDX, call_nondet);
    REGISTER(3, CALL_DET_IDX, call_det);
    

    //argument-1 string type
    REGISTER(4, MAKECONST_IDX, makeconst);
    REGISTER(4, MAKEPRED_IDX, makepred);
    REGISTER(4, MAKEVAR_IDX, makevar);
    REGISTER(4, MAKEANONY_IDX, makeanony);
    REGISTER(4, MAKESTRFLT_IDX, makestrflt);
    REGISTER(4, MAKECOMP_IDX, makecomp);
    REGISTER(4, MAKESYS_IDX, makesys);
    REGISTER(4, MAKEOPE_IDX, makeope);
    REGISTER(4, MAKEUSER_IDX, makeuser);
    REGISTER(4, MAKESTRLONG_IDX, makestrlong);
    REGISTER(4, MAKEBIGX_IDX, makebigx);
    REGISTER(4, MAKESTR_IDX, makestr);
    REGISTER(4, MAKEFUNC_IDX, makefunc);

    /* argument 4 */
    REGISTER(5, CALLSUBR_IDX, callsubr);
    REGISTER(5, WLIST3_IDX, wlist3);
    

    /* argument-1 return char* */
    REGISTER(6, GETNAME_IDX, get_name);

    /* argument-1 return double */
    REGISTER(7, GET_FLT_IDX, get_flt);

    /* argument 5 */
    //non

    init_deftpred((tpred) defcompiled);
    init_deftinfix((tuser) definfixcomp);
    init_tpredicate();
    init_declare();
#undef REGISTER
    link_flag = 1;
    /* Registered predicates retain pointers into this module. */
    return;

  incompatible:
    dlclose(hmod);
    exception(SYSTEM_ERR, makestr("incompatible module; recompile source"), x, 0);
}
