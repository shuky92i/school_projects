/*
 * Code for class EV_CHARACTER_FORMAT_RANGE_INFORMATION
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1519_15221(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1519_15222(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15223(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15224(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15225(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15226(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15227(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15228(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15229(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1519_15230(EIF_REFERENCE);
extern void EIF_Minit1519(void);

#ifdef __cplusplus
}
#endif

#include "eif_misc.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.make_with_flags */
void F1519_15221 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "make_with_flags";
	RTEX;
#define arg1 arg1x.it_i4
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_BOOLEAN tb3;
	EIF_BOOLEAN tb4;
	EIF_BOOLEAN tb5;
	EIF_BOOLEAN tb6;
	EIF_BOOLEAN tb7;
	EIF_BOOLEAN tb8;
	EIF_BOOLEAN tb9;
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
	
	RTEAA(l_feature_name, 1518, Current, 0, 1, 21330);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1518, Current, 21330);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("valid_flags", EX_PRE);
		ui4_1 = arg1;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(6504, dtype))(Current, ui4_1x)).it_b);
		RTTE(tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 11122, 0x04000000, 1); /* font_family */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6495, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11122, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(3);
	RTDBGAA(Current, dtype, 11123, 0x04000000, 1); /* font_weight */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6496, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11123, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(4);
	RTDBGAA(Current, dtype, 11124, 0x04000000, 1); /* font_shape */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6497, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11124, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(5);
	RTDBGAA(Current, dtype, 11125, 0x04000000, 1); /* font_height */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6498, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11125, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(6);
	RTDBGAA(Current, dtype, 11126, 0x04000000, 1); /* color */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6499, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11126, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(7);
	RTDBGAA(Current, dtype, 11127, 0x04000000, 1); /* background_color */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6500, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11127, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(8);
	RTDBGAA(Current, dtype, 11128, 0x04000000, 1); /* effects_striked_out */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6501, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11128, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(9);
	RTDBGAA(Current, dtype, 11129, 0x04000000, 1); /* effects_underlined */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6502, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11129, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	RTHOOK(10);
	RTDBGAA(Current, dtype, 11130, 0x04000000, 1); /* effects_vertical_offset */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6503, 1012))(Current)).it_i4);
	ui4_1 = ti4_1;
	ti4_1 = eif_bit_or(arg1,ui4_1);
	*(EIF_BOOLEAN *)(Current + RTWA(11130, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == arg1);
	if (RTAL & CK_ENSURE) {
		RTHOOK(11);
		RTCT("attributes_set", EX_POST);
		tb1 = '\0';
		tb2 = '\0';
		tb3 = '\0';
		tb4 = '\0';
		tb5 = '\0';
		tb6 = '\0';
		tb7 = '\0';
		tb8 = '\0';
		tb9 = *(EIF_BOOLEAN *)(Current + RTWA(11122, dtype));
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6495, 1012))(Current)).it_i4);
		ui4_1 = ti4_1;
		ti4_1 = eif_bit_or(arg1,ui4_1);
		if ((EIF_BOOLEAN)(tb9 == (EIF_BOOLEAN)(ti4_1 == arg1))) {
			tb9 = *(EIF_BOOLEAN *)(Current + RTWA(11123, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6496, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb8 = (EIF_BOOLEAN)(tb9 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb8) {
			tb8 = *(EIF_BOOLEAN *)(Current + RTWA(11124, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6497, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb7 = (EIF_BOOLEAN)(tb8 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb7) {
			tb7 = *(EIF_BOOLEAN *)(Current + RTWA(11125, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6498, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb6 = (EIF_BOOLEAN)(tb7 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb6) {
			tb6 = *(EIF_BOOLEAN *)(Current + RTWA(11126, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6499, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb5 = (EIF_BOOLEAN)(tb6 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb5) {
			tb5 = *(EIF_BOOLEAN *)(Current + RTWA(11127, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6500, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb4 = (EIF_BOOLEAN)(tb5 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb4) {
			tb4 = *(EIF_BOOLEAN *)(Current + RTWA(11128, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6501, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb3 = (EIF_BOOLEAN)(tb4 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb3) {
			tb3 = *(EIF_BOOLEAN *)(Current + RTWA(11129, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6502, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb2 = (EIF_BOOLEAN)(tb3 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb2) {
			tb2 = *(EIF_BOOLEAN *)(Current + RTWA(11130, dtype));
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(6503, 1012))(Current)).it_i4);
			ui4_1 = ti4_1;
			ti4_1 = eif_bit_or(arg1,ui4_1);
			tb1 = (EIF_BOOLEAN)(tb2 == (EIF_BOOLEAN)(ti4_1 == arg1));
		}
		if (tb1) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(12);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
#undef ui4_1
#undef arg1
}

/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.font_family */
EIF_TYPED_VALUE F1519_15222 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11122,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.font_weight */
EIF_TYPED_VALUE F1519_15223 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11123,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.font_shape */
EIF_TYPED_VALUE F1519_15224 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11124,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.font_height */
EIF_TYPED_VALUE F1519_15225 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11125,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.color */
EIF_TYPED_VALUE F1519_15226 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11126,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.background_color */
EIF_TYPED_VALUE F1519_15227 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11127,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.effects_striked_out */
EIF_TYPED_VALUE F1519_15228 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11128,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.effects_underlined */
EIF_TYPED_VALUE F1519_15229 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11129,Dtype(Current)));
	return r;
}


/* {EV_CHARACTER_FORMAT_RANGE_INFORMATION}.effects_vertical_offset */
EIF_TYPED_VALUE F1519_15230 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(11130,Dtype(Current)));
	return r;
}


void EIF_Minit1519 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
