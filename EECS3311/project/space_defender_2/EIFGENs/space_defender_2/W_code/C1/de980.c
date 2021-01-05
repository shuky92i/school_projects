/*
 * Code for class DEBUG_MODE
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F980_8474(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8475(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8476(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8477(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8478(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8479(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8480(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8481(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8482(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8483(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8484(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8485(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8486(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8487(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8488(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8489(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8490(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8491(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8492(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8493(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8494(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8495(EIF_REFERENCE);
extern EIF_TYPED_VALUE F980_8496(EIF_REFERENCE);
extern void F980_8497(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F980_8498(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F980_8499(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F980_8500(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F980_8501(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F980_8502(EIF_REFERENCE);
extern void EIF_Minit980(void);

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

/* {DEBUG_MODE}.make_default */
void F980_8474 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "make_default";
	RTEX;
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
	
	RTEAA(l_feature_name, 979, Current, 0, 0, 14775);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(979, Current, 14775);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6263, 0xF80000E8, 0); /* enemy */
	tr1 = RTMS_EX_H("  Enemy:",8,771839290);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6263, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 6264, 0xF80000E8, 0); /* projectile */
	tr1 = RTMS_EX_H("  Projectile:",13,1819787322);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6264, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 6265, 0xF80000E8, 0); /* natural_enemy_spawn */
	tr1 = RTMS_EX_H("  Natural Enemy Spawn:",22,1895383098);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6265, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(4);
	RTDBGAA(Current, dtype, 6266, 0xF80000E8, 0); /* friendly_projectile_action */
	tr1 = RTMS_EX_H("  Friendly Projectile Action:",29,1605476154);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6266, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(5);
	RTDBGAA(Current, dtype, 6267, 0xF80000E8, 0); /* friendly_projectile_action_delayed */
	tr1 = RTMS_EX_H("",0,0);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6267, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(6);
	RTDBGAA(Current, dtype, 6268, 0xF80000E8, 0); /* enemy_projectile_action */
	tr1 = RTMS_EX_H("  Enemy Projectile Action:",26,453348154);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6268, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 6269, 0xF80000E8, 0); /* enemy_projectile_action_delayed */
	tr1 = RTMS_EX_H("",0,0);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6269, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(8);
	RTDBGAA(Current, dtype, 6270, 0xF80000E8, 0); /* starfighter_action */
	tr1 = RTMS_EX_H("  Starfighter Action:",21,1991522874);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6270, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(9);
	RTDBGAA(Current, dtype, 6271, 0xF80000E8, 0); /* starfighter_action_delayed */
	tr1 = RTMS_EX_H("",0,0);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6271, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(10);
	RTDBGAA(Current, dtype, 6272, 0xF80000E8, 0); /* enemy_action */
	tr1 = RTMS_EX_H("  Enemy Action:",15,1431342394);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6272, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(11);
	RTDBGAA(Current, dtype, 6273, 0xF80000E8, 0); /* enemy_action_delayed */
	tr1 = RTMS_EX_H("",0,0);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6273, dtype)) = (EIF_REFERENCE) tr1;
	RTHOOK(12);
	RTDBGAA(Current, dtype, 6274, 0x10000000, 1); /* enemy_code */
	*(EIF_INTEGER_32 *)(Current + RTWA(6274, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(13);
	RTDBGAA(Current, dtype, 6275, 0x10000000, 1); /* projetile_code */
	*(EIF_INTEGER_32 *)(Current + RTWA(6275, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(14);
	RTDBGAA(Current, dtype, 6276, 0x10000000, 1); /* natural_enemy_spawn_code */
	*(EIF_INTEGER_32 *)(Current + RTWA(6276, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 2L);
	RTHOOK(15);
	RTDBGAA(Current, dtype, 6277, 0x10000000, 1); /* friendly_projectile_action_code */
	*(EIF_INTEGER_32 *)(Current + RTWA(6277, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 3L);
	RTHOOK(16);
	RTDBGAA(Current, dtype, 6278, 0x10000000, 1); /* friendly_projectile_action_code_delayed */
	*(EIF_INTEGER_32 *)(Current + RTWA(6278, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 4L);
	RTHOOK(17);
	RTDBGAA(Current, dtype, 6279, 0x10000000, 1); /* enemy_projectile_action_code */
	*(EIF_INTEGER_32 *)(Current + RTWA(6279, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 5L);
	RTHOOK(18);
	RTDBGAA(Current, dtype, 6280, 0x10000000, 1); /* enemy_projectile_action_code_delayed */
	*(EIF_INTEGER_32 *)(Current + RTWA(6280, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 6L);
	RTHOOK(19);
	RTDBGAA(Current, dtype, 6281, 0x10000000, 1); /* starfighter_action_code */
	*(EIF_INTEGER_32 *)(Current + RTWA(6281, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 7L);
	RTHOOK(20);
	RTDBGAA(Current, dtype, 6282, 0x10000000, 1); /* starfighter_action_code_delayed */
	*(EIF_INTEGER_32 *)(Current + RTWA(6282, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 8L);
	RTHOOK(21);
	RTDBGAA(Current, dtype, 6283, 0x10000000, 1); /* enemy_action_code */
	*(EIF_INTEGER_32 *)(Current + RTWA(6283, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 9L);
	RTHOOK(22);
	RTDBGAA(Current, dtype, 6284, 0x10000000, 1); /* enemy_action_code_delayed */
	*(EIF_INTEGER_32 *)(Current + RTWA(6284, dtype)) = (EIF_INTEGER_32) ((EIF_INTEGER_32) 10L);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(23);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {DEBUG_MODE}.enemy */
EIF_TYPED_VALUE F980_8475 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6263,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.projectile */
EIF_TYPED_VALUE F980_8476 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6264,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.natural_enemy_spawn */
EIF_TYPED_VALUE F980_8477 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6265,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.friendly_projectile_action */
EIF_TYPED_VALUE F980_8478 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6266,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.friendly_projectile_action_delayed */
EIF_TYPED_VALUE F980_8479 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6267,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_projectile_action */
EIF_TYPED_VALUE F980_8480 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6268,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_projectile_action_delayed */
EIF_TYPED_VALUE F980_8481 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6269,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.starfighter_action */
EIF_TYPED_VALUE F980_8482 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6270,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.starfighter_action_delayed */
EIF_TYPED_VALUE F980_8483 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6271,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_action */
EIF_TYPED_VALUE F980_8484 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6272,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_action_delayed */
EIF_TYPED_VALUE F980_8485 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(6273,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_code */
EIF_TYPED_VALUE F980_8486 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6274,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.projetile_code */
EIF_TYPED_VALUE F980_8487 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6275,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.natural_enemy_spawn_code */
EIF_TYPED_VALUE F980_8488 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6276,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.friendly_projectile_action_code */
EIF_TYPED_VALUE F980_8489 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6277,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.friendly_projectile_action_code_delayed */
EIF_TYPED_VALUE F980_8490 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6278,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_projectile_action_code */
EIF_TYPED_VALUE F980_8491 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6279,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_projectile_action_code_delayed */
EIF_TYPED_VALUE F980_8492 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6280,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.starfighter_action_code */
EIF_TYPED_VALUE F980_8493 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6281,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.starfighter_action_code_delayed */
EIF_TYPED_VALUE F980_8494 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6282,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_action_code */
EIF_TYPED_VALUE F980_8495 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6283,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.enemy_action_code_delayed */
EIF_TYPED_VALUE F980_8496 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(6284,Dtype(Current)));
	return r;
}


/* {DEBUG_MODE}.set_enemy_projectile_action_delayed */
void F980_8497 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_enemy_projectile_action_delayed";
	RTEX;
#define arg1 arg1x.it_r
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 979, Current, 0, 1, 14798);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(979, Current, 14798);
	RTCC(arg1, 979, l_feature_name, 1, eif_new_type(232, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6269, 0xF80000E8, 0); /* enemy_projectile_action_delayed */
	tr1 = RTCCL(arg1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6269, dtype)) = (EIF_REFERENCE) tr1;
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

/* {DEBUG_MODE}.set_enemy_action_delayed */
void F980_8498 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_enemy_action_delayed";
	RTEX;
#define arg1 arg1x.it_r
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 979, Current, 0, 1, 14799);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(979, Current, 14799);
	RTCC(arg1, 979, l_feature_name, 1, eif_new_type(232, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6273, 0xF80000E8, 0); /* enemy_action_delayed */
	tr1 = RTCCL(arg1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6273, dtype)) = (EIF_REFERENCE) tr1;
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

/* {DEBUG_MODE}.set_starfighter_action_delayed */
void F980_8499 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_starfighter_action_delayed";
	RTEX;
#define arg1 arg1x.it_r
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 979, Current, 0, 1, 14800);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(979, Current, 14800);
	RTCC(arg1, 979, l_feature_name, 1, eif_new_type(232, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6271, 0xF80000E8, 0); /* starfighter_action_delayed */
	tr1 = RTCCL(arg1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6271, dtype)) = (EIF_REFERENCE) tr1;
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

/* {DEBUG_MODE}.set_friendly_projectile_action_delayed */
void F980_8500 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "set_friendly_projectile_action_delayed";
	RTEX;
#define arg1 arg1x.it_r
	EIF_REFERENCE tr1 = NULL;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(3);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 979, Current, 0, 1, 14801);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(979, Current, 14801);
	RTCC(arg1, 979, l_feature_name, 1, eif_new_type(232, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 6267, 0xF80000E8, 0); /* friendly_projectile_action_delayed */
	tr1 = RTCCL(arg1);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(6267, dtype)) = (EIF_REFERENCE) tr1;
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

/* {DEBUG_MODE}.insert_entry */
void F980_8501 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "insert_entry";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(5);
	RTLR(0,arg2);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLR(3,tr2);
	RTLR(4,ur1);
	RTLIU(5);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 979, Current, 0, 2, 14802);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(979, Current, 14802);
	RTCC(arg2, 979, l_feature_name, 2, eif_new_type(232, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("0 <= container_code and container_code <= 10", EX_PRE);
		RTTE((EIF_BOOLEAN) ((EIF_BOOLEAN) (((EIF_INTEGER_32) 0L) <= arg1) && (EIF_BOOLEAN) (arg1 <= ((EIF_INTEGER_32) 10L))), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6274, dtype));
	if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
		RTHOOK(3);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6263, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(3,1);
		tr2 = RTMS_EX_H("\012",1,10);
		ur1 = tr2;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
		RTHOOK(4);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6263, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(4,1);
		ur1 = RTCCL(arg2);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
	} else {
		RTHOOK(5);
		ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6275, dtype));
		if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
			RTHOOK(6);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6264, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(6,1);
			tr2 = RTMS_EX_H("\012",1,10);
			ur1 = tr2;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
			RTHOOK(7);
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6264, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(7,1);
			ur1 = RTCCL(arg2);
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
		} else {
			RTHOOK(8);
			ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6276, dtype));
			if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
				RTHOOK(9);
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6265, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				RTNHOOK(9,1);
				tr2 = RTMS_EX_H("\012",1,10);
				ur1 = tr2;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
				RTHOOK(10);
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6265, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				RTNHOOK(10,1);
				ur1 = RTCCL(arg2);
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
			} else {
				RTHOOK(11);
				ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6277, dtype));
				if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
					RTHOOK(12);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6266, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(12,1);
					tr2 = RTMS_EX_H("\012",1,10);
					ur1 = tr2;
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
					RTHOOK(13);
					tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6266, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
					RTNHOOK(13,1);
					ur1 = RTCCL(arg2);
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
				} else {
					RTHOOK(14);
					ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6278, dtype));
					if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
						RTHOOK(15);
						tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6267, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
						RTNHOOK(15,1);
						ti4_1 = *(EIF_INTEGER_32 *)(tr1 + RTVA(4768, "count", tr1));
						if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
							RTHOOK(16);
							tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6267, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
							RTNHOOK(16,1);
							tr2 = RTMS_EX_H("\012",1,10);
							ur1 = tr2;
							(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
						}
						RTHOOK(17);
						tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6267, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
						RTNHOOK(17,1);
						ur1 = RTCCL(arg2);
						(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
					} else {
						RTHOOK(18);
						ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6279, dtype));
						if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
							RTHOOK(19);
							tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6268, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
							RTNHOOK(19,1);
							tr2 = RTMS_EX_H("\012",1,10);
							ur1 = tr2;
							(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
							RTHOOK(20);
							tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6268, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
							RTNHOOK(20,1);
							ur1 = RTCCL(arg2);
							(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
						} else {
							RTHOOK(21);
							ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6280, dtype));
							if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
								RTHOOK(22);
								tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6269, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
								RTNHOOK(22,1);
								ti4_1 = *(EIF_INTEGER_32 *)(tr1 + RTVA(4768, "count", tr1));
								if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
									RTHOOK(23);
									tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6269, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
									RTNHOOK(23,1);
									tr2 = RTMS_EX_H("\012",1,10);
									ur1 = tr2;
									(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
								}
								RTHOOK(24);
								tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6269, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
								RTNHOOK(24,1);
								ur1 = RTCCL(arg2);
								(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
							} else {
								RTHOOK(25);
								ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6281, dtype));
								if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
									RTHOOK(26);
									tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6270, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
									RTNHOOK(26,1);
									tr2 = RTMS_EX_H("\012",1,10);
									ur1 = tr2;
									(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
									RTHOOK(27);
									tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6270, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
									RTNHOOK(27,1);
									ur1 = RTCCL(arg2);
									(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
								} else {
									RTHOOK(28);
									ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6282, dtype));
									if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
										RTHOOK(29);
										tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6271, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
										RTNHOOK(29,1);
										ti4_1 = *(EIF_INTEGER_32 *)(tr1 + RTVA(4768, "count", tr1));
										if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
											RTHOOK(30);
											tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6271, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
											RTNHOOK(30,1);
											tr2 = RTMS_EX_H("\012",1,10);
											ur1 = tr2;
											(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
										}
										RTHOOK(31);
										tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6271, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
										RTNHOOK(31,1);
										ur1 = RTCCL(arg2);
										(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
									} else {
										RTHOOK(32);
										ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6283, dtype));
										if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
											RTHOOK(33);
											tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6272, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
											RTNHOOK(33,1);
											tr2 = RTMS_EX_H("\012",1,10);
											ur1 = tr2;
											(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
											RTHOOK(34);
											tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6272, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
											RTNHOOK(34,1);
											ur1 = RTCCL(arg2);
											(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
										} else {
											RTHOOK(35);
											ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(6284, dtype));
											if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
												RTHOOK(36);
												tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6273, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
												RTNHOOK(36,1);
												ti4_1 = *(EIF_INTEGER_32 *)(tr1 + RTVA(4768, "count", tr1));
												if ((EIF_BOOLEAN) (ti4_1 > ((EIF_INTEGER_32) 0L))) {
													RTHOOK(37);
													tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6273, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
													RTNHOOK(37,1);
													tr2 = RTMS_EX_H("\012",1,10);
													ur1 = tr2;
													(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
												}
												RTHOOK(38);
												tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6273, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
												RTNHOOK(38,1);
												ur1 = RTCCL(arg2);
												(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", tr1))(tr1, ur1x);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(39);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
#undef up1
#undef ur1
#undef arg2
#undef arg1
}

/* {DEBUG_MODE}.out */
EIF_TYPED_VALUE F980_8502 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "out";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
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
	RTLR(2,Current);
	RTLR(3,ur1);
	RTLIU(4);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 979, Current, 0, 0, 14803);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(979, Current, 14803);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWC(4643, Dtype(tr1)))(tr1);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6263, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(3);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(4);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6264, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(5);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(6);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6266, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(7);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(8);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6268, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(9);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(10);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6270, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(11);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(12);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6272, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(13);
	tr1 = RTMS_EX_H("\012",1,10);
	ur1 = tr1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	RTHOOK(14);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6265, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4821, "append", Result))(Result, ur1x);
	if (RTAL & CK_ENSURE) {
		RTHOOK(15);
		RTCT("out_not_void", EX_POST);
		if ((EIF_BOOLEAN)(Result != NULL)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(16);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
}

void EIF_Minit980 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
