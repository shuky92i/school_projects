/*
 * Code for class WEAPON_SETUP
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1136_9835(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1136_9836(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1136_9837(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1136_9838(EIF_REFERENCE);
extern void F1136_9839(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1136_9840(EIF_REFERENCE);
extern void F1136_9841(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void EIF_Minit1136(void);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {WEAPON_SETUP}.make_default */
void F1136_9835 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "make_default";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1135, Current, 0, 0, 16094);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1135, Current, 16094);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 7516, 0xF80000E8, 0); /* selections_string */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7519, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7516, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 7517, 0xF80000E8, 0); /* output_string */
	tr1 = RTLNSMART(RTWCT(7517, dtype, Dftype(Current)).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7517, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 7525, 0xF80000E8, 0); /* projectile_cost_unites */
	tr1 = RTLNSMART(RTWCT(7525, dtype, Dftype(Current)).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(3,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7525, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
	tr1 = RTLNSMART(RTWCT(7515, dtype, Dftype(Current)).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(4,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 7514, 0x10000000, 1); /* selection_made */
	*(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(6);
	RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
	tr1 = RTMS_EX_H("Standard",8,150062692);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(7);
	ui4_1 = ((EIF_INTEGER_32) 1L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(7518, dtype))(Current, ui4_1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(8);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
#undef up1
#undef ui4_1
}

/* {WEAPON_SETUP}.projectile_damage */
EIF_TYPED_VALUE F1136_9836 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7523,Dtype(Current)));
	return r;
}


/* {WEAPON_SETUP}.projectile_cost */
EIF_TYPED_VALUE F1136_9837 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7524,Dtype(Current)));
	return r;
}


/* {WEAPON_SETUP}.projectile_cost_unites */
EIF_TYPED_VALUE F1136_9838 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(7525,Dtype(Current)));
	return r;
}


/* {WEAPON_SETUP}.select_option */
void F1136_9839 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "select_option";
	RTEX;
#define arg1 arg1x.it_i4
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE ui4_4x = {{0}, SK_INT32};
#define ui4_4 ui4_4x.it_i4
	EIF_TYPED_VALUE ui4_5x = {{0}, SK_INT32};
#define ui4_5 ui4_5x.it_i4
	EIF_TYPED_VALUE ui4_6x = {{0}, SK_INT32};
#define ui4_6 ui4_6x.it_i4
	EIF_TYPED_VALUE ui4_7x = {{0}, SK_INT32};
#define ui4_7 ui4_7x.it_i4
	EIF_TYPED_VALUE ui4_8x = {{0}, SK_INT32};
#define ui4_8 ui4_8x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(4);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,tr2);
	RTLR(3,ur1);
	RTLIU(4);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1135, Current, 0, 1, 16098);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1135, Current, 16098);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 7517, 0xF80000E8, 0); /* output_string */
	tr1 = RTLNSMART(RTWCT(7517, dtype, Dftype(Current)).id);
	tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7516, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr2);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4738, Dtype(tr1)))(tr1, ur1x);
	RTNHOOK(1,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7517, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 7514, 0x10000000, 1); /* selection_made */
	*(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype)) = (EIF_INTEGER_32) arg1;
	RTHOOK(3);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
	if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 1L))) {
		RTHOOK(4);
		RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
		tr1 = RTMS_EX_H("Standard",8,150062692);
		RTAR(Current, tr1);
		*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
		RTHOOK(5);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(5,1);
		tr2 = RTMS_EX_H("Standard",8,150062692);
		ur1 = tr2;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
		RTHOOK(6);
		ui4_1 = ((EIF_INTEGER_32) 10L);
		ui4_2 = ((EIF_INTEGER_32) 10L);
		ui4_3 = ((EIF_INTEGER_32) 0L);
		ui4_4 = ((EIF_INTEGER_32) 1L);
		ui4_5 = ((EIF_INTEGER_32) 0L);
		ui4_6 = ((EIF_INTEGER_32) 1L);
		ui4_7 = ((EIF_INTEGER_32) 1L);
		ui4_8 = ((EIF_INTEGER_32) 1L);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
		RTHOOK(7);
		ui4_1 = ((EIF_INTEGER_32) 70L);
		ui4_2 = ((EIF_INTEGER_32) 5L);
		tr1 = RTMS_EX_H("energy",6,1901415289);
		ur1 = tr1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7526, dtype))(Current, ui4_1x, ui4_2x, ur1x);
	} else {
		RTHOOK(8);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 2L))) {
			RTHOOK(9);
			RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
			tr1 = RTMS_EX_H("Spread",6,2083291492);
			RTAR(Current, tr1);
			*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
			RTHOOK(10);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(10,1);
			tr2 = RTMS_EX_H("Spread",6,2083291492);
			ur1 = tr2;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
			RTHOOK(11);
			ui4_1 = ((EIF_INTEGER_32) 0L);
			ui4_2 = ((EIF_INTEGER_32) 60L);
			ui4_3 = ((EIF_INTEGER_32) 0L);
			ui4_4 = ((EIF_INTEGER_32) 2L);
			ui4_5 = ((EIF_INTEGER_32) 1L);
			ui4_6 = ((EIF_INTEGER_32) 0L);
			ui4_7 = ((EIF_INTEGER_32) 0L);
			ui4_8 = ((EIF_INTEGER_32) 2L);
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
			RTHOOK(12);
			ui4_1 = ((EIF_INTEGER_32) 50L);
			ui4_2 = ((EIF_INTEGER_32) 10L);
			tr1 = RTMS_EX_H("energy",6,1901415289);
			ur1 = tr1;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7526, dtype))(Current, ui4_1x, ui4_2x, ur1x);
		} else {
			RTHOOK(13);
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
			if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 3L))) {
				RTHOOK(14);
				RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
				tr1 = RTMS_EX_H("Snipe",5,1853041253);
				RTAR(Current, tr1);
				*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
				RTHOOK(15);
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				RTNHOOK(15,1);
				tr2 = RTMS_EX_H("Snipe",5,1853041253);
				ur1 = tr2;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
				RTHOOK(16);
				ui4_1 = ((EIF_INTEGER_32) 0L);
				ui4_2 = ((EIF_INTEGER_32) 100L);
				ui4_3 = ((EIF_INTEGER_32) 0L);
				ui4_4 = ((EIF_INTEGER_32) 5L);
				ui4_5 = ((EIF_INTEGER_32) 0L);
				ui4_6 = ((EIF_INTEGER_32) 10L);
				ui4_7 = ((EIF_INTEGER_32) 3L);
				ui4_8 = ((EIF_INTEGER_32) 0L);
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
				RTHOOK(17);
				ui4_1 = ((EIF_INTEGER_32) 1000L);
				ui4_2 = ((EIF_INTEGER_32) 20L);
				tr1 = RTMS_EX_H("energy",6,1901415289);
				ur1 = tr1;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7526, dtype))(Current, ui4_1x, ui4_2x, ur1x);
			} else {
				RTHOOK(18);
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
				if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 4L))) {
					RTHOOK(19);
					RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
					tr1 = RTMS_EX_H("Rocket",6,1830053748);
					RTAR(Current, tr1);
					*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
					RTHOOK(20);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(20,1);
					tr2 = RTMS_EX_H("Rocket",6,1830053748);
					ur1 = tr2;
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
					RTHOOK(21);
					ui4_1 = ((EIF_INTEGER_32) 10L);
					ui4_2 = ((EIF_INTEGER_32) 0L);
					ui4_3 = ((EIF_INTEGER_32) 10L);
					ui4_4 = ((EIF_INTEGER_32) 0L);
					ui4_5 = ((EIF_INTEGER_32) 2L);
					ui4_6 = ((EIF_INTEGER_32) 2L);
					ui4_7 = ((EIF_INTEGER_32) 0L);
					ui4_8 = ((EIF_INTEGER_32) 3L);
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
					RTHOOK(22);
					ui4_1 = ((EIF_INTEGER_32) 100L);
					ui4_2 = ((EIF_INTEGER_32) 10L);
					tr1 = RTMS_EX_H("health",6,1839745640);
					ur1 = tr1;
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7526, dtype))(Current, ui4_1x, ui4_2x, ur1x);
				} else {
					RTHOOK(23);
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
					if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 5L))) {
						RTHOOK(24);
						RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
						tr1 = RTMS_EX_H("Splitter",8,575542386);
						RTAR(Current, tr1);
						*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
						RTHOOK(25);
						tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
						RTNHOOK(25,1);
						tr2 = RTMS_EX_H("Splitter",8,575542386);
						ur1 = tr2;
						(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
						RTHOOK(26);
						ui4_1 = ((EIF_INTEGER_32) 0L);
						ui4_2 = ((EIF_INTEGER_32) 100L);
						ui4_3 = ((EIF_INTEGER_32) 0L);
						ui4_4 = ((EIF_INTEGER_32) 10L);
						ui4_5 = ((EIF_INTEGER_32) 0L);
						ui4_6 = ((EIF_INTEGER_32) 0L);
						ui4_7 = ((EIF_INTEGER_32) 0L);
						ui4_8 = ((EIF_INTEGER_32) 5L);
						(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
						RTHOOK(27);
						ui4_1 = ((EIF_INTEGER_32) 150L);
						ui4_2 = ((EIF_INTEGER_32) 70L);
						tr1 = RTMS_EX_H("energy",6,1901415289);
						ur1 = tr1;
						(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7526, dtype))(Current, ui4_1x, ui4_2x, ur1x);
					}
				}
			}
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(28);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef up1
#undef ur1
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef ui4_4
#undef ui4_5
#undef ui4_6
#undef ui4_7
#undef ui4_8
#undef arg1
}

/* {WEAPON_SETUP}.get_options_string */
EIF_TYPED_VALUE F1136_9840 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "get_options_string";
	RTEX;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(4);
	RTLR(0,tr1);
	RTLR(1,Result);
	RTLR(2,ur1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1135, Current, 0, 0, 16099);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1135, Current, 16099);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	tr1 = RTMS_EX_H("  1:Standard (A single projectile is fired in front)",52,1307967017);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(3);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	tr1 = RTMS_EX_H("    Health:10, Energy:10, Regen:0/1, Armour:0, Vision:1, Move:1, Move Cost:1,",77,116531756);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("    Projectile Damage:70, Projectile Cost:5 (energy)",52,948984617);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(7);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(8);
	tr1 = RTMS_EX_H("  2:Spread (Three projectiles are fired in front, two going diagonal)",69,133236265);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(10);
	tr1 = RTMS_EX_H("    Health:0, Energy:60, Regen:0/2, Armour:1, Vision:0, Move:0, Move Cost:2,",76,1532490028);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(11);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(12);
	tr1 = RTMS_EX_H("    Projectile Damage:50, Projectile Cost:10 (energy)",53,1552202281);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(13);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(14);
	tr1 = RTMS_EX_H("  3:Snipe (Fast and high damage projectile, but only travels via teleporting)",77,2142854441);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(15);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(16);
	tr1 = RTMS_EX_H("    Health:0, Energy:100, Regen:0/5, Armour:0, Vision:10, Move:3, Move Cost:0,",78,49792300);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(17);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(18);
	tr1 = RTMS_EX_H("    Projectile Damage:1000, Projectile Cost:20 (energy)",55,403988521);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(19);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(20);
	tr1 = RTMS_EX_H("  4:Rocket (Two projectiles appear behind to the sides of the Starfighter and accelerates)",90,897733161);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(21);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(22);
	tr1 = RTMS_EX_H("    Health:10, Energy:0, Regen:10/0, Armour:2, Vision:2, Move:0, Move Cost:3,",77,494221612);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(23);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(24);
	tr1 = RTMS_EX_H("    Projectile Damage:100, Projectile Cost:10 (health)",54,1778385193);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(25);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(26);
	tr1 = RTMS_EX_H("  5:Splitter (A single mine projectile is placed in front of the Starfighter)",77,1556062761);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(27);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(28);
	tr1 = RTMS_EX_H("    Health:0, Energy:100, Regen:0/10, Armour:0, Vision:0, Move:0, Move Cost:5,",78,884912428);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(29);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(30);
	tr1 = RTMS_EX_H("    Projectile Damage:150, Projectile Cost:70 (energy)",54,698298921);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(31);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(32);
	tr1 = RTMS_EX_H("  Weapon Selected:",18,1170445114);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(33);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
}

/* {WEAPON_SETUP}.fill_specialized_attributes */
void F1136_9841 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x)
{
	GTCX
	char *l_feature_name = "fill_specialized_attributes";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
#define arg3 arg3x.it_r
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(3);
	RTLR(0,arg3);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU(SK_REF,&arg3);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1135, Current, 0, 3, 16100);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1135, Current, 16100);
	RTCC(arg3, 1135, l_feature_name, 3, eif_new_type(232, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 7523, 0x10000000, 1); /* projectile_damage */
	*(EIF_INTEGER_32 *)(Current + RTWA(7523, dtype)) = (EIF_INTEGER_32) arg1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 7524, 0x10000000, 1); /* projectile_cost */
	*(EIF_INTEGER_32 *)(Current + RTWA(7524, dtype)) = (EIF_INTEGER_32) arg2;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 7525, 0xF80000E8, 0); /* projectile_cost_unites */
	tr1 = RTCCL(arg3);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7525, dtype)) = (EIF_REFERENCE) tr1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
#undef arg3
#undef arg2
#undef arg1
}

void EIF_Minit1136 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
