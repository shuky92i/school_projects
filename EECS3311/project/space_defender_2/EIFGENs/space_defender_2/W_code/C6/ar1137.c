/*
 * Code for class ARMOUR_SETUP
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1137_9842(EIF_REFERENCE);
extern void F1137_9843(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1137_9844(EIF_REFERENCE);
extern void EIF_Minit1137(void);

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

/* {ARMOUR_SETUP}.make_default */
void F1137_9842 (EIF_REFERENCE Current)
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
	
	RTEAA(l_feature_name, 1136, Current, 0, 0, 16101);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1136, Current, 16101);
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
	RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
	tr1 = RTLNSMART(RTWCT(7515, dtype, Dftype(Current)).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(3,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 7514, 0x10000000, 1); /* selection_made */
	*(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(5);
	RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
	tr1 = RTMS_EX_H("None",4,1315925605);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(6);
	ui4_1 = ((EIF_INTEGER_32) 1L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(7518, dtype))(Current, ui4_1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(7);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
#undef up1
#undef ui4_1
}

/* {ARMOUR_SETUP}.select_option */
void F1137_9843 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
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
	
	RTEAA(l_feature_name, 1136, Current, 0, 1, 16102);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1136, Current, 16102);
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
		tr1 = RTMS_EX_H("None",4,1315925605);
		RTAR(Current, tr1);
		*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
		RTHOOK(5);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(5,1);
		tr2 = RTMS_EX_H("None",4,1315925605);
		ur1 = tr2;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
		RTHOOK(6);
		ui4_1 = ((EIF_INTEGER_32) 50L);
		ui4_2 = ((EIF_INTEGER_32) 0L);
		ui4_3 = ((EIF_INTEGER_32) 1L);
		ui4_4 = ((EIF_INTEGER_32) 0L);
		ui4_5 = ((EIF_INTEGER_32) 0L);
		ui4_6 = ((EIF_INTEGER_32) 0L);
		ui4_7 = ((EIF_INTEGER_32) 1L);
		ui4_8 = ((EIF_INTEGER_32) 0L);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
	} else {
		RTHOOK(7);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 2L))) {
			RTHOOK(8);
			RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
			tr1 = RTMS_EX_H("Light",5,1768968308);
			RTAR(Current, tr1);
			*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
			RTHOOK(9);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(9,1);
			tr2 = RTMS_EX_H("Light",5,1768968308);
			ur1 = tr2;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
			RTHOOK(10);
			ui4_1 = ((EIF_INTEGER_32) 75L);
			ui4_2 = ((EIF_INTEGER_32) 0L);
			ui4_3 = ((EIF_INTEGER_32) 2L);
			ui4_4 = ((EIF_INTEGER_32) 0L);
			ui4_5 = ((EIF_INTEGER_32) 3L);
			ui4_6 = ((EIF_INTEGER_32) 0L);
			ui4_7 = ((EIF_INTEGER_32) 0L);
			ui4_8 = ((EIF_INTEGER_32) 1L);
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
		} else {
			RTHOOK(11);
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
			if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 3L))) {
				RTHOOK(12);
				RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
				tr1 = RTMS_EX_H("Medium",6,1836796781);
				RTAR(Current, tr1);
				*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
				RTHOOK(13);
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				RTNHOOK(13,1);
				tr2 = RTMS_EX_H("Medium",6,1836796781);
				ur1 = tr2;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
				RTHOOK(14);
				ui4_1 = ((EIF_INTEGER_32) 100L);
				ui4_2 = ((EIF_INTEGER_32) 0L);
				ui4_3 = ((EIF_INTEGER_32) 3L);
				ui4_4 = ((EIF_INTEGER_32) 0L);
				ui4_5 = ((EIF_INTEGER_32) 5L);
				ui4_6 = ((EIF_INTEGER_32) 0L);
				ui4_7 = ((EIF_INTEGER_32) 0L);
				ui4_8 = ((EIF_INTEGER_32) 3L);
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
			} else {
				RTHOOK(15);
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(7514, dtype));
				if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 4L))) {
					RTHOOK(16);
					RTDBGAA(Current, dtype, 7515, 0xF80000E8, 0); /* selection_made_string */
					tr1 = RTMS_EX_H("Heavy",5,1701439097);
					RTAR(Current, tr1);
					*(EIF_REFERENCE *)(Current + RTWA(7515, dtype)) = (EIF_REFERENCE) tr1;
					RTHOOK(17);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7517, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(17,1);
					tr2 = RTMS_EX_H("Heavy",5,1701439097);
					ur1 = tr2;
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
					RTHOOK(18);
					ui4_1 = ((EIF_INTEGER_32) 200L);
					ui4_2 = ((EIF_INTEGER_32) 0L);
					ui4_3 = ((EIF_INTEGER_32) 4L);
					ui4_4 = ((EIF_INTEGER_32) 0L);
					ui4_5 = ((EIF_INTEGER_32) 10L);
					ui4_6 = ((EIF_INTEGER_32) 0L);
					ui4_7 = ((EIF_INTEGER_32) -1L);
					ui4_8 = ((EIF_INTEGER_32) 5L);
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(7520, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ui4_4x, ui4_5x, ui4_6x, ui4_7x, ui4_8x);
				}
			}
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(19);
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

/* {ARMOUR_SETUP}.get_options_string */
EIF_TYPED_VALUE F1137_9844 (EIF_REFERENCE Current)
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
	
	RTEAA(l_feature_name, 1136, Current, 0, 0, 16103);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1136, Current, 16103);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	tr1 = RTMS_EX_H("  1:None",8,346370661);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(3);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	tr1 = RTMS_EX_H("    Health:50, Energy:0, Regen:1/0, Armour:0, Vision:0, Move:1, Move Cost:0",75,2001352752);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("  2:Light",9,1026397044);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(7);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(8);
	tr1 = RTMS_EX_H("    Health:75, Energy:0, Regen:2/0, Armour:3, Vision:0, Move:0, Move Cost:1",75,1320076849);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(10);
	tr1 = RTMS_EX_H("  3:Medium",10,717006701);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(11);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(12);
	tr1 = RTMS_EX_H("    Health:100, Energy:0, Regen:3/0, Armour:5, Vision:0, Move:0, Move Cost:3",76,547436595);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(13);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(14);
	tr1 = RTMS_EX_H("  4:Heavy",9,1965500793);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(15);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(16);
	tr1 = RTMS_EX_H("    Health:200, Energy:0, Regen:4/0, Armour:10, Vision:0, Move:-1, Move Cost:5",78,1931210293);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(17);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(18);
	tr1 = RTMS_EX_H("  Armour Selected:",18,159625530);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(19);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
}

void EIF_Minit1137 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
