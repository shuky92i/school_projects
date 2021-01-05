/*
 * Code for class EFFECT
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F1134_9817(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9818(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9819(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9820(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9821(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9822(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9823(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9824(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9825(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9826(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9827(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1134_9828(EIF_REFERENCE);
extern void F1134_9831(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void EIF_Minit1134(void);

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

/* {EFFECT}.health */
EIF_TYPED_VALUE F1134_9817 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7506,Dtype(Current)));
	return r;
}


/* {EFFECT}.energy */
EIF_TYPED_VALUE F1134_9818 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7507,Dtype(Current)));
	return r;
}


/* {EFFECT}.regen_health */
EIF_TYPED_VALUE F1134_9819 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7508,Dtype(Current)));
	return r;
}


/* {EFFECT}.regen_energy */
EIF_TYPED_VALUE F1134_9820 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7509,Dtype(Current)));
	return r;
}


/* {EFFECT}.armour */
EIF_TYPED_VALUE F1134_9821 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7510,Dtype(Current)));
	return r;
}


/* {EFFECT}.vision */
EIF_TYPED_VALUE F1134_9822 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7511,Dtype(Current)));
	return r;
}


/* {EFFECT}.move */
EIF_TYPED_VALUE F1134_9823 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7512,Dtype(Current)));
	return r;
}


/* {EFFECT}.move_cost */
EIF_TYPED_VALUE F1134_9824 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7513,Dtype(Current)));
	return r;
}


/* {EFFECT}.selection_made */
EIF_TYPED_VALUE F1134_9825 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(7514,Dtype(Current)));
	return r;
}


/* {EFFECT}.selection_made_string */
EIF_TYPED_VALUE F1134_9826 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(7515,Dtype(Current)));
	return r;
}


/* {EFFECT}.selections_string */
EIF_TYPED_VALUE F1134_9827 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(7516,Dtype(Current)));
	return r;
}


/* {EFFECT}.output_string */
EIF_TYPED_VALUE F1134_9828 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(7517,Dtype(Current)));
	return r;
}


/* {EFFECT}.fill_attributes */
void F1134_9831 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x, EIF_TYPED_VALUE arg5x, EIF_TYPED_VALUE arg6x, EIF_TYPED_VALUE arg7x, EIF_TYPED_VALUE arg8x)
{
	GTCX
	char *l_feature_name = "fill_attributes";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_i4
#define arg5 arg5x.it_i4
#define arg6 arg6x.it_i4
#define arg7 arg7x.it_i4
#define arg8 arg8x.it_i4
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg8x.type & SK_HEAD) == SK_REF) arg8x.it_i4 = * (EIF_INTEGER_32 *) arg8x.it_r;
	if ((arg7x.type & SK_HEAD) == SK_REF) arg7x.it_i4 = * (EIF_INTEGER_32 *) arg7x.it_r;
	if ((arg6x.type & SK_HEAD) == SK_REF) arg6x.it_i4 = * (EIF_INTEGER_32 *) arg6x.it_r;
	if ((arg5x.type & SK_HEAD) == SK_REF) arg5x.it_i4 = * (EIF_INTEGER_32 *) arg5x.it_r;
	if ((arg4x.type & SK_HEAD) == SK_REF) arg4x.it_i4 = * (EIF_INTEGER_32 *) arg4x.it_r;
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU(SK_INT32,&arg3);
	RTLU(SK_INT32,&arg4);
	RTLU(SK_INT32,&arg5);
	RTLU(SK_INT32,&arg6);
	RTLU(SK_INT32,&arg7);
	RTLU(SK_INT32,&arg8);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1133, Current, 0, 8, 16080);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1133, Current, 16080);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 7506, 0x10000000, 1); /* health */
	*(EIF_INTEGER_32 *)(Current + RTWA(7506, dtype)) = (EIF_INTEGER_32) arg1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 7507, 0x10000000, 1); /* energy */
	*(EIF_INTEGER_32 *)(Current + RTWA(7507, dtype)) = (EIF_INTEGER_32) arg2;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 7508, 0x10000000, 1); /* regen_health */
	*(EIF_INTEGER_32 *)(Current + RTWA(7508, dtype)) = (EIF_INTEGER_32) arg3;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 7509, 0x10000000, 1); /* regen_energy */
	*(EIF_INTEGER_32 *)(Current + RTWA(7509, dtype)) = (EIF_INTEGER_32) arg4;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 7510, 0x10000000, 1); /* armour */
	*(EIF_INTEGER_32 *)(Current + RTWA(7510, dtype)) = (EIF_INTEGER_32) arg5;
	RTHOOK(6);
	RTDBGAA(Current, dtype, 7511, 0x10000000, 1); /* vision */
	*(EIF_INTEGER_32 *)(Current + RTWA(7511, dtype)) = (EIF_INTEGER_32) arg6;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 7512, 0x10000000, 1); /* move */
	*(EIF_INTEGER_32 *)(Current + RTWA(7512, dtype)) = (EIF_INTEGER_32) arg7;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 7513, 0x10000000, 1); /* move_cost */
	*(EIF_INTEGER_32 *)(Current + RTWA(7513, dtype)) = (EIF_INTEGER_32) arg8;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(10);
	RTEE;
#undef arg8
#undef arg7
#undef arg6
#undef arg5
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

void EIF_Minit1134 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
