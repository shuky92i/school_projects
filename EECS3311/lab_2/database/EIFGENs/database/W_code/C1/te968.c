/*
 * Code for class TEST_ENVIRONMENT
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F968_7337(EIF_REFERENCE);
extern EIF_TYPED_VALUE F968_7338(EIF_REFERENCE);
extern EIF_TYPED_VALUE F968_7339(EIF_REFERENCE);
extern void F968_7340(EIF_REFERENCE);
extern void F968_7341(EIF_REFERENCE);
extern void F968_7342(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F968_7343(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F968_7344(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void EIF_Minit968(void);

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

/* {TEST_ENVIRONMENT}.db_int_int */
EIF_TYPED_VALUE F968_7337 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(5113,Dtype(Current)));
	return r;
}


/* {TEST_ENVIRONMENT}.db_int_str */
EIF_TYPED_VALUE F968_7338 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(5114,Dtype(Current)));
	return r;
}


/* {TEST_ENVIRONMENT}.db_str_str */
EIF_TYPED_VALUE F968_7339 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(5115,Dtype(Current)));
	return r;
}


/* {TEST_ENVIRONMENT}.reset_as_tree_db */
void F968_7340 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "reset_as_tree_db";
	RTEX;
	EIF_REFERENCE tr1 = NULL;
	RTCFDT;
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
	
	RTEAA(l_feature_name, 967, Current, 0, 0, 13623);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(967, Current, 13623);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 5113, 0xF80003E7, 0); /* db_int_int */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,1013,221,221,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5385, Dtype(tr1)))(tr1);
	RTNHOOK(1,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5113, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 5114, 0xF80003EE, 0); /* db_int_str */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,1008,221,0xFF01,232,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5385, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5114, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 5115, 0xF80003FD, 0); /* db_str_str */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,1023,0xFF01,232,0xFF01,232,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5385, Dtype(tr1)))(tr1);
	RTNHOOK(3,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5115, dtype)) = (EIF_REFERENCE) tr1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {TEST_ENVIRONMENT}.reset_as_linear_db */
void F968_7341 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "reset_as_linear_db";
	RTEX;
	EIF_REFERENCE tr1 = NULL;
	RTCFDT;
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
	
	RTEAA(l_feature_name, 967, Current, 0, 0, 13624);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(967, Current, 13624);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 5113, 0xF80003E7, 0); /* db_int_int */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,1032,221,221,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5388, Dtype(tr1)))(tr1);
	RTNHOOK(1,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5113, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 5114, 0xF80003EE, 0); /* db_int_str */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,1028,221,0xFF01,232,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5388, Dtype(tr1)))(tr1);
	RTNHOOK(2,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5114, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 5115, 0xF80003FD, 0); /* db_str_str */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,1030,0xFF01,232,0xFF01,232,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(dftype, typarr0)));
		tr1 = RTLN(typres0.id);
	}
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(5388, Dtype(tr1)))(tr1);
	RTNHOOK(3,1);
	tr1 = RTCCL(tr1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(5115, dtype)) = (EIF_REFERENCE) tr1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {TEST_ENVIRONMENT}.env_int_int */
void F968_7342 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "env_int_int";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(2);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 967, Current, 0, 1, 13625);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(967, Current, 13625);
	RTCC(arg1, 967, l_feature_name, 1, RTWCT(5113, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ui4_1 = ((EIF_INTEGER_32) 1L);
	ui4_2 = ((EIF_INTEGER_32) 1L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(2);
	ui4_1 = ((EIF_INTEGER_32) 2L);
	ui4_2 = ((EIF_INTEGER_32) 2L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(3);
	ui4_1 = ((EIF_INTEGER_32) 3L);
	ui4_2 = ((EIF_INTEGER_32) 3L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(4);
	ui4_1 = ((EIF_INTEGER_32) 4L);
	ui4_2 = ((EIF_INTEGER_32) 4L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(5);
	ui4_1 = ((EIF_INTEGER_32) 5L);
	ui4_2 = ((EIF_INTEGER_32) 5L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(6);
	ui4_1 = ((EIF_INTEGER_32) 6L);
	ui4_2 = ((EIF_INTEGER_32) 6L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(7);
	ui4_1 = ((EIF_INTEGER_32) 7L);
	ui4_2 = ((EIF_INTEGER_32) 7L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(8);
	ui4_1 = ((EIF_INTEGER_32) 8L);
	ui4_2 = ((EIF_INTEGER_32) 8L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(9);
	ui4_1 = ((EIF_INTEGER_32) 9L);
	ui4_2 = ((EIF_INTEGER_32) 9L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTHOOK(10);
	ui4_1 = ((EIF_INTEGER_32) 10L);
	ui4_2 = ((EIF_INTEGER_32) 10L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ui4_2x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ui4_1
#undef ui4_2
#undef arg1
}

/* {TEST_ENVIRONMENT}.env_int_str */
void F968_7343 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "env_int_str";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,tr1);
	RTLR(2,ur1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 967, Current, 0, 1, 13626);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(967, Current, 13626);
	RTCC(arg1, 967, l_feature_name, 1, RTWCT(5114, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ui4_1 = ((EIF_INTEGER_32) 1L);
	tr1 = RTMS_EX_H("a",1,97);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(2);
	ui4_1 = ((EIF_INTEGER_32) 2L);
	tr1 = RTMS_EX_H("b",1,98);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(3);
	ui4_1 = ((EIF_INTEGER_32) 3L);
	tr1 = RTMS_EX_H("c",1,99);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(4);
	ui4_1 = ((EIF_INTEGER_32) 4L);
	tr1 = RTMS_EX_H("d",1,100);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(5);
	ui4_1 = ((EIF_INTEGER_32) 5L);
	tr1 = RTMS_EX_H("e",1,101);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(6);
	ui4_1 = ((EIF_INTEGER_32) 6L);
	tr1 = RTMS_EX_H("f",1,102);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(7);
	ui4_1 = ((EIF_INTEGER_32) 7L);
	tr1 = RTMS_EX_H("g",1,103);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(8);
	ui4_1 = ((EIF_INTEGER_32) 8L);
	tr1 = RTMS_EX_H("h",1,104);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(9);
	ui4_1 = ((EIF_INTEGER_32) 9L);
	tr1 = RTMS_EX_H("i",1,105);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTHOOK(10);
	ui4_1 = ((EIF_INTEGER_32) 10L);
	tr1 = RTMS_EX_H("j",1,106);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ui4_1x, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ui4_1
#undef arg1
}

/* {TEST_ENVIRONMENT}.env_str_str */
void F968_7344 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "env_str_str";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(6);
	RTLR(0,arg1);
	RTLR(1,tr1);
	RTLR(2,ur1);
	RTLR(3,tr2);
	RTLR(4,ur2);
	RTLR(5,Current);
	RTLIU(6);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 967, Current, 0, 1, 13627);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(967, Current, 13627);
	RTCC(arg1, 967, l_feature_name, 1, RTWCT(5115, dtype, Dftype(Current)), 0x00);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tr1 = RTMS_EX_H("a",1,97);
	ur1 = tr1;
	tr2 = RTMS_EX_H("a",1,97);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(2);
	tr1 = RTMS_EX_H("b",1,98);
	ur1 = tr1;
	tr2 = RTMS_EX_H("b",1,98);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(3);
	tr1 = RTMS_EX_H("c",1,99);
	ur1 = tr1;
	tr2 = RTMS_EX_H("c",1,99);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(4);
	tr1 = RTMS_EX_H("d",1,100);
	ur1 = tr1;
	tr2 = RTMS_EX_H("d",1,100);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(5);
	tr1 = RTMS_EX_H("e",1,101);
	ur1 = tr1;
	tr2 = RTMS_EX_H("e",1,101);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(6);
	tr1 = RTMS_EX_H("f",1,102);
	ur1 = tr1;
	tr2 = RTMS_EX_H("f",1,102);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(7);
	tr1 = RTMS_EX_H("g",1,103);
	ur1 = tr1;
	tr2 = RTMS_EX_H("g",1,103);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(8);
	tr1 = RTMS_EX_H("h",1,104);
	ur1 = tr1;
	tr2 = RTMS_EX_H("h",1,104);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("i",1,105);
	ur1 = tr1;
	tr2 = RTMS_EX_H("i",1,105);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTHOOK(10);
	tr1 = RTMS_EX_H("j",1,106);
	ur1 = tr1;
	tr2 = RTMS_EX_H("j",1,106);
	ur2 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5376, "insert", arg1))(arg1, ur1x, ur2x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ur1
#undef ur2
#undef arg1
}

void EIF_Minit968 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
