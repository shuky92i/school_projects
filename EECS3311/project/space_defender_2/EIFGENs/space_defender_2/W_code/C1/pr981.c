/*
 * Code for class PROJECTILE
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F981_8503(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F981_8504(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8505(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8506(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8507(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8508(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8509(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8510(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8511(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8512(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8513(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8514(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8515(EIF_REFERENCE);
extern void F981_8516(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F981_8517(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8518(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8519(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8520(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8521(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8522(EIF_REFERENCE);
extern void F981_8523(EIF_REFERENCE);
extern void F981_8524(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F981_8525(EIF_REFERENCE);
extern void F981_8526(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F981_8527(EIF_REFERENCE);
extern EIF_TYPED_VALUE F981_8528(EIF_REFERENCE);
extern void EIF_Minit981(void);

#ifdef __cplusplus
}
#endif

#include "eif_out.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {PROJECTILE}.make */
void F981_8503 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x, EIF_TYPED_VALUE arg5x, EIF_TYPED_VALUE arg6x, EIF_TYPED_VALUE arg7x)
{
	GTCX
	char *l_feature_name = "make";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_b
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_i4
#define arg5 arg5x.it_i4
#define arg6 arg6x.it_i4
#define arg7 arg7x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg7x.type & SK_HEAD) == SK_REF) arg7x.it_i4 = * (EIF_INTEGER_32 *) arg7x.it_r;
	if ((arg6x.type & SK_HEAD) == SK_REF) arg6x.it_i4 = * (EIF_INTEGER_32 *) arg6x.it_r;
	if ((arg5x.type & SK_HEAD) == SK_REF) arg5x.it_i4 = * (EIF_INTEGER_32 *) arg5x.it_r;
	if ((arg4x.type & SK_HEAD) == SK_REF) arg4x.it_i4 = * (EIF_INTEGER_32 *) arg4x.it_r;
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_b = * (EIF_BOOLEAN *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_BOOL,&arg2);
	RTLU(SK_INT32,&arg3);
	RTLU(SK_INT32,&arg4);
	RTLU(SK_INT32,&arg5);
	RTLU(SK_INT32,&arg6);
	RTLU(SK_INT32,&arg7);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 980, Current, 0, 7, 14813);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14813);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6293, 0x10000000, 1); /* id */
	*(EIF_INTEGER_32 *)(Current + RTWA(6293, dtype)) = (EIF_INTEGER_32) arg1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 6294, 0x10000000, 1); /* row_loc */
	*(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype)) = (EIF_INTEGER_32) arg3;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 6295, 0x10000000, 1); /* col_loc */
	*(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype)) = (EIF_INTEGER_32) arg4;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 6296, 0x04000000, 1); /* is_friendly */
	*(EIF_BOOLEAN *)(Current + RTWA(6296, dtype)) = (EIF_BOOLEAN) arg2;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 6291, 0x10000000, 1); /* prev_row_loc */
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
	*(EIF_INTEGER_32 *)(Current + RTWA(6291, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(6);
	RTDBGAA(Current, dtype, 6292, 0x10000000, 1); /* prev_col_loc */
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
	*(EIF_INTEGER_32 *)(Current + RTWA(6292, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 6297, 0x10000000, 1); /* move_steps_per_turn */
	*(EIF_INTEGER_32 *)(Current + RTWA(6297, dtype)) = (EIF_INTEGER_32) arg5;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 6298, 0x10000000, 1); /* move_type */
	*(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype)) = (EIF_INTEGER_32) arg6;
	RTHOOK(9);
	RTDBGAA(Current, dtype, 6299, 0x10000000, 1); /* damage */
	*(EIF_INTEGER_32 *)(Current + RTWA(6299, dtype)) = (EIF_INTEGER_32) arg7;
	RTHOOK(10);
	RTDBGAA(Current, dtype, 6300, 0x04000000, 1); /* is_dead */
	*(EIF_BOOLEAN *)(Current + RTWA(6300, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(11);
	RTDBGAA(Current, dtype, 6301, 0xF80000E8, 0); /* killed_by_entity_name */
	tr1 = RTLNSMART(RTWCT(6301, dtype, Dftype(Current)).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(11,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6301, dtype)) = (EIF_REFERENCE) tr1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(12);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(9);
	RTEE;
#undef arg7
#undef arg6
#undef arg5
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {PROJECTILE}.prev_row_loc */
EIF_TYPED_VALUE F981_8504 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6291,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.prev_col_loc */
EIF_TYPED_VALUE F981_8505 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6292,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.id */
EIF_TYPED_VALUE F981_8506 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6293,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.row_loc */
EIF_TYPED_VALUE F981_8507 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6294,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.col_loc */
EIF_TYPED_VALUE F981_8508 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6295,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.is_friendly */
EIF_TYPED_VALUE F981_8509 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(6296,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.move_steps_per_turn */
EIF_TYPED_VALUE F981_8510 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6297,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.move_type */
EIF_TYPED_VALUE F981_8511 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6298,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.damage */
EIF_TYPED_VALUE F981_8512 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6299,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.is_dead */
EIF_TYPED_VALUE F981_8513 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(6300,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.killed_by_entity_name */
EIF_TYPED_VALUE F981_8514 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6301,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.killed_by_entity_id */
EIF_TYPED_VALUE F981_8515 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6302,Dtype(Current)));
	return r;
}


/* {PROJECTILE}.set_damage */
void F981_8516 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_damage";
	RTEX;
#define arg1 arg1x.it_i4
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 980, Current, 0, 1, 14826);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14826);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6299, 0x10000000, 1); /* damage */
	*(EIF_INTEGER_32 *)(Current + RTWA(6299, dtype)) = (EIF_INTEGER_32) arg1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef arg1
}

/* {PROJECTILE}.perform_move */
void F981_8517 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "perform_move";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_BOOLEAN loc3 = (EIF_BOOLEAN) 0;
	EIF_REFERENCE loc4 = (EIF_REFERENCE) 0;
	struct eif_ex_990 sloc5;
	EIF_REFERENCE loc5 = (EIF_REFERENCE) sloc5.data;
	EIF_REFERENCE loc6 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_BOOLEAN tb3;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	memset (&sloc5.overhead, 0, OVERHEAD + 0);
	sloc5.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc5.overhead, eif_new_type(990, 0x00).id);
	RTLI(9);
	RTLR(0,Current);
	RTLR(1,loc2);
	RTLR(2,loc1);
	RTLR(3,tr1);
	RTLR(4,loc4);
	RTLR(5,loc5);
	RTLR(6,loc6);
	RTLR(7,tr2);
	RTLR(8,ur1);
	RTLIU(9);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	RTLU(SK_BOOL, &loc3);
	RTLU(SK_REF, &loc4);
	RTLU(SK_REF, &loc5);
	RTLU(SK_REF, &loc6);
	
	RTEAA(l_feature_name, 980, Current, 6, 0, 14827);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14827);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	wstdinit(loc5,loc5);
	RTLXI(loc5);
	RTHOOK(1);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(6312, dtype))(Current);
	RTHOOK(2);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	RTDBGAL(4, 0xF80003DB, 0, 0); /* loc4 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6444, "m", loc5))(loc5)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc4 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(4);
	RTDBGAL(3, 0x04000000, 1, 0); /* loc3 */
	loc3 = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(5);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
	ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6464, "snipe_movement", loc2));
	if ((EIF_BOOLEAN) !(EIF_BOOLEAN)(ti4_1 == ti4_2)) {
		RTHOOK(6);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6297, dtype));
		ui4_1 = ti4_1;
		tr1 = RTLN(eif_new_type(221, 0x00).id);
		*(EIF_INTEGER_32 *)tr1 = ((EIF_INTEGER_32) 1L);
		tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4487, "interval", tr1))(tr1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2280, "new_cursor", tr2))(tr2)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		loc6 = (EIF_REFERENCE) RTCCL(tr1);
		for (;;) {
			tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(3711, "after", loc6))(loc6)).it_b);
			if (tb1) break;
			RTHOOK(7);
			tb2 = '\0';
			tb3 = *(EIF_BOOLEAN *)(Current + RTWA(6300, dtype));
			if ((EIF_BOOLEAN) !tb3) {
				tb3 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6314, dtype))(Current)).it_b);
				tb2 = tb3;
			}
			if (tb2) {
				RTHOOK(8);
				(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(6310, dtype))(Current);
				RTHOOK(9);
				tb2 = *(EIF_BOOLEAN *)(Current + RTWA(6296, dtype));
				if (tb2) {
					RTHOOK(10);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6459, "collision_handler", loc2))(loc2)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(10,1);
					tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6432, "debug_string", loc4))(loc4)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(10,2);
					ti4_1 = *(EIF_INTEGER_32 *)(tr2 + RTVA(6278, "friendly_projectile_action_code_delayed", tr2));
					ui4_1 = ti4_1;
					ur1 = RTCCL(Current);
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(6320, "handle_friendly_projectile_initiated_collision", tr1))(tr1, ui4_1x, ur1x);
				} else {
					RTHOOK(11);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6459, "collision_handler", loc2))(loc2)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(11,1);
					tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6432, "debug_string", loc4))(loc4)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(11,2);
					ti4_1 = *(EIF_INTEGER_32 *)(tr2 + RTVA(6280, "enemy_projectile_action_code_delayed", tr2));
					ui4_1 = ti4_1;
					ur1 = RTCCL(Current);
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(6321, "handle_enemy_projectile_initiated_collision", tr1))(tr1, ui4_1x, ur1x);
				}
			}
			RTHOOK(12);
			(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(3712, "forth", loc6))(loc6);
		}
	}
	RTHOOK(13);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
	ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6464, "snipe_movement", loc2));
	if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
		RTHOOK(14);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
		ui4_1 = ti4_1;
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
		ui4_2 = (EIF_INTEGER_32) (ti4_2 + ((EIF_INTEGER_32) 8L));
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6311, dtype))(Current, ui4_1x, ui4_2x);
	}
	RTHOOK(15);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
	ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6465, "rocket_movement", loc2));
	if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
		RTHOOK(16);
		RTDBGAA(Current, dtype, 6297, 0x10000000, 1); /* move_steps_per_turn */
		(*(EIF_INTEGER_32 *)(Current + RTWA(6297, dtype))) *= ((EIF_INTEGER_32) 2L);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(17);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(8);
	RTEE;
#undef up1
#undef ur1
#undef ui4_1
#undef ui4_2
}

/* {PROJECTILE}.generate_projectile_debug_string */
EIF_TYPED_VALUE F981_8518 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "generate_projectile_debug_string";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(6);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Result);
	RTLR(4,ur1);
	RTLR(5,Current);
	RTLIU(6);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14828);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14828);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	tr1 = RTMS_EX_H("    [",5,539222107);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6293, dtype));
	tr1 = c_outi(ti4_1);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H(",",1,44);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	tb1 = *(EIF_BOOLEAN *)(Current + RTWA(6296, dtype));
	if (tb1) {
		RTHOOK(7);
		tr1 = RTMS_EX_H("*",1,42);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	} else {
		RTHOOK(8);
		tr1 = RTMS_EX_H("<",1,60);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	}
	RTHOOK(9);
	tr1 = RTMS_EX_H("]->damage:",10,940043322);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(10);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6299, dtype));
	tr1 = c_outi(ti4_1);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(11);
	tr1 = RTMS_EX_H(", move:",7,457429050);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(12);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6297, dtype));
	tr1 = c_outi(ti4_1);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(13);
	tr1 = RTMS_EX_H(", location:[",12,1084866139);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(14);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
	ui4_1 = ti4_1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6472, "row_nb_to_letter", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(15);
	tr1 = RTMS_EX_H(",",1,44);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(16);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
	tr1 = c_outi((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(17);
	tr1 = RTMS_EX_H("]",1,93);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(18);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ui4_1
}

/* {PROJECTILE}.generate_friendly_projectile_action_debug_string */
EIF_TYPED_VALUE F981_8519 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "generate_friendly_projectile_action_debug_string";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(6);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Result);
	RTLR(4,ur1);
	RTLR(5,Current);
	RTLIU(6);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14829);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14829);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	tr1 = RTMS_EX_H("    A friendly projectile(id:",29,451109434);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6293, dtype));
	tr1 = c_outi(ti4_1);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H(") moves: [",10,422293083);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6291, dtype));
	ui4_1 = ti4_1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6472, "row_nb_to_letter", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(7);
	tr1 = RTMS_EX_H(",",1,44);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(8);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6292, dtype));
	tr1 = c_outi((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("] -> ",5,540550176);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(10);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6314, dtype))(Current)).it_b);
	if (tb1) {
		RTHOOK(11);
		tr1 = RTMS_EX_H("[",1,91);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(12);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
		ui4_1 = ti4_1;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6472, "row_nb_to_letter", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(13);
		tr1 = RTMS_EX_H(",",1,44);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(14);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
		tr1 = c_outi((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
		ur1 = RTCCL(tr1);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(15);
		tr1 = RTMS_EX_H("]",1,93);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	} else {
		RTHOOK(16);
		tr1 = RTMS_EX_H("out of board",12,346402148);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(17);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ui4_1
}

/* {PROJECTILE}.generate_friendly_splitter_projectile_action_debug_string */
EIF_TYPED_VALUE F981_8520 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "generate_friendly_splitter_projectile_action_debug_string";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(6);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Result);
	RTLR(4,ur1);
	RTLR(5,Current);
	RTLIU(6);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14804);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14804);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	tr1 = RTMS_EX_H("    A friendly projectile(id:",29,451109434);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6293, dtype));
	tr1 = c_outi(ti4_1);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H(") stays at: [",13,826386779);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6291, dtype));
	ui4_1 = ti4_1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6472, "row_nb_to_letter", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(7);
	tr1 = RTMS_EX_H(",",1,44);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(8);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6292, dtype));
	tr1 = c_outi((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("]",1,93);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(10);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ui4_1
}

/* {PROJECTILE}.generate_projectile_neutralized_debug_string */
EIF_TYPED_VALUE F981_8521 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "generate_projectile_neutralized_debug_string";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(6);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Result);
	RTLR(4,ur1);
	RTLR(5,Current);
	RTLIU(6);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14805);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14805);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	tr1 = RTMS_EX_H("      A projectile(id:",22,1162734394);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6293, dtype));
	tr1 = c_outi(ti4_1);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H(") at location [",15,829002587);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
	ui4_1 = ti4_1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6472, "row_nb_to_letter", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(7);
	tr1 = RTMS_EX_H(",",1,44);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(8);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
	tr1 = c_outi((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("] has been neutralized.",23,286581806);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(10);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ui4_1
}

/* {PROJECTILE}.generate_enemy_projectile_move_action_debug_string */
EIF_TYPED_VALUE F981_8522 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "generate_enemy_projectile_move_action_debug_string";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(6);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Result);
	RTLR(4,ur1);
	RTLR(5,Current);
	RTLIU(6);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14806);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14806);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	tr1 = RTMS_EX_H("    A enemy projectile(id:",26,1536853050);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6293, dtype));
	tr1 = c_outi(ti4_1);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H(") moves: [",10,422293083);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6291, dtype));
	ui4_1 = ti4_1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6472, "row_nb_to_letter", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(7);
	tr1 = RTMS_EX_H(",",1,44);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(8);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6292, dtype));
	tr1 = c_outi((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("] -> ",5,540550176);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(10);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6314, dtype))(Current)).it_b);
	if (tb1) {
		RTHOOK(11);
		tr1 = RTMS_EX_H("[",1,91);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(12);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
		ui4_1 = ti4_1;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6472, "row_nb_to_letter", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(13);
		tr1 = RTMS_EX_H(",",1,44);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(14);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
		tr1 = c_outi((EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)));
		ur1 = RTCCL(tr1);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
		RTHOOK(15);
		tr1 = RTMS_EX_H("]",1,93);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	} else {
		RTHOOK(16);
		tr1 = RTMS_EX_H("out of board",12,346402148);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(17);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ui4_1
}

/* {PROJECTILE}.perform_dynamic_type_move */
void F981_8523 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "perform_dynamic_type_move";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(4);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14807);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14807);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	tb1 = *(EIF_BOOLEAN *)(Current + RTWA(6296, dtype));
	if (tb1) {
		RTHOOK(3);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6460, "standard_movement", loc2));
		if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
			RTHOOK(4);
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
			ui4_1 = ti4_1;
			ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
			ui4_2 = (EIF_INTEGER_32) (ti4_2 + ((EIF_INTEGER_32) 1L));
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6311, dtype))(Current, ui4_1x, ui4_2x);
		} else {
			RTHOOK(5);
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
			ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6462, "spread_movement_top_right", loc2));
			if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
				RTHOOK(6);
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
				ui4_1 = (EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L));
				ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
				ui4_2 = (EIF_INTEGER_32) (ti4_2 + ((EIF_INTEGER_32) 1L));
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6311, dtype))(Current, ui4_1x, ui4_2x);
			} else {
				RTHOOK(7);
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
				ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6461, "spread_movement_right", loc2));
				if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
					RTHOOK(8);
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
					ui4_1 = ti4_1;
					ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
					ui4_2 = (EIF_INTEGER_32) (ti4_2 + ((EIF_INTEGER_32) 1L));
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6311, dtype))(Current, ui4_1x, ui4_2x);
				} else {
					RTHOOK(9);
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
					ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6463, "spread_movement_bottom_right", loc2));
					if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
						RTHOOK(10);
						ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
						ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
						ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
						ui4_2 = (EIF_INTEGER_32) (ti4_2 + ((EIF_INTEGER_32) 1L));
						(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6311, dtype))(Current, ui4_1x, ui4_2x);
					} else {
						RTHOOK(11);
						ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
						ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6465, "rocket_movement", loc2));
						if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
							RTHOOK(12);
							ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
							ui4_1 = ti4_1;
							ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
							ui4_2 = (EIF_INTEGER_32) (ti4_2 + ((EIF_INTEGER_32) 1L));
							(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6311, dtype))(Current, ui4_1x, ui4_2x);
						} else {
							RTHOOK(13);
							ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6298, dtype));
							ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6466, "splitter_movement", loc2));
							if ((EIF_BOOLEAN)(ti4_1 == ti4_2)) {
							}
						}
					}
				}
			}
		}
	} else {
		RTHOOK(14);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
		ui4_1 = ti4_1;
		ti4_2 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
		ui4_2 = (EIF_INTEGER_32) (ti4_2 - ((EIF_INTEGER_32) 1L));
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6311, dtype))(Current, ui4_1x, ui4_2x);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(15);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
#undef up1
#undef ui4_1
#undef ui4_2
}

/* {PROJECTILE}.set_loc */
void F981_8524 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "set_loc";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(4);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 2, 14808);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14808);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAA(Current, dtype, 6294, 0x10000000, 1); /* row_loc */
	*(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype)) = (EIF_INTEGER_32) arg1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 6295, 0x10000000, 1); /* col_loc */
	*(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype)) = (EIF_INTEGER_32) arg2;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
#undef up1
#undef arg2
#undef arg1
}

/* {PROJECTILE}.sync_prev_loc_to_curr_loc */
void F981_8525 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "sync_prev_loc_to_curr_loc";
	RTEX;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 980, Current, 0, 0, 14809);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14809);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6291, 0x10000000, 1); /* prev_row_loc */
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
	*(EIF_INTEGER_32 *)(Current + RTWA(6291, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 6292, 0x10000000, 1); /* prev_col_loc */
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
	*(EIF_INTEGER_32 *)(Current + RTWA(6292, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {PROJECTILE}.kill */
void F981_8526 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "kill";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_r
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(3);
	RTLR(0,arg2);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 980, Current, 0, 2, 14810);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14810);
	RTCC(arg2, 980, l_feature_name, 2, eif_new_type(232, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6300, 0x04000000, 1); /* is_dead */
	*(EIF_BOOLEAN *)(Current + RTWA(6300, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 6302, 0x10000000, 1); /* killed_by_entity_id */
	*(EIF_INTEGER_32 *)(Current + RTWA(6302, dtype)) = (EIF_INTEGER_32) arg1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 6301, 0xF80000E8, 0); /* killed_by_entity_name */
	tr1 = RTCCL(arg2);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6301, dtype)) = (EIF_REFERENCE) tr1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
#undef arg2
#undef arg1
}

/* {PROJECTILE}.is_on_grid */
EIF_TYPED_VALUE F981_8527 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "is_on_grid";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(4);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_BOOL, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14811);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14811);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(0, 0x04000000, 1,0); /* Result */
	Result = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(2);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	tb1 = '\0';
	tb2 = '\0';
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
	if ((EIF_BOOLEAN) (((EIF_INTEGER_32) 2L) <= ti4_1)) {
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6294, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6449, "row_count", loc2));
		tb2 = (EIF_BOOLEAN) (ti4_1 <= ti4_2);
	}
	if (tb2) {
		tb2 = '\0';
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
		if ((EIF_BOOLEAN) (((EIF_INTEGER_32) 2L) <= ti4_1)) {
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6295, dtype));
			ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6450, "col_count", loc2));
			tb2 = (EIF_BOOLEAN) (ti4_1 <= ti4_2);
		}
		tb1 = tb2;
	}
	if (tb1) {
		RTHOOK(4);
		RTDBGAL(0, 0x04000000, 1,0); /* Result */
		Result = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef up1
}

/* {PROJECTILE}.was_on_grid */
EIF_TYPED_VALUE F981_8528 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "was_on_grid";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(4);
	RTLR(0,loc2);
	RTLR(1,loc1);
	RTLR(2,tr1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_BOOL, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	
	RTEAA(l_feature_name, 980, Current, 2, 0, 14812);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(980, Current, 14812);
	RTIV(Current, RTAL);
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(1);
	RTDBGAL(0, 0x04000000, 1,0); /* Result */
	Result = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(2);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	tb1 = '\0';
	tb2 = '\0';
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6291, dtype));
	if ((EIF_BOOLEAN) (((EIF_INTEGER_32) 2L) <= ti4_1)) {
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6291, dtype));
		ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6449, "row_count", loc2));
		tb2 = (EIF_BOOLEAN) (ti4_1 <= ti4_2);
	}
	if (tb2) {
		tb2 = '\0';
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6292, dtype));
		if ((EIF_BOOLEAN) (((EIF_INTEGER_32) 2L) <= ti4_1)) {
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6292, dtype));
			ti4_2 = *(EIF_INTEGER_32 *)(loc2 + RTVA(6450, "col_count", loc2));
			tb2 = (EIF_BOOLEAN) (ti4_1 <= ti4_2);
		}
		tb1 = tb2;
	}
	if (tb1) {
		RTHOOK(4);
		RTDBGAL(0, 0x04000000, 1,0); /* Result */
		Result = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef up1
}

void EIF_Minit981 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
