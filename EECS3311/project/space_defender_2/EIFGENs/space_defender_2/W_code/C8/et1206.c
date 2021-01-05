/*
 * Code for class ETF_MOVE
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1206_10752(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void EIF_Minit1206(void);

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

/* {ETF_MOVE}.move */
void F1206_10752 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "move";
	RTEX;
	struct eif_ex_988 sloc1;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) sloc1.data;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	memset (&sloc1.overhead, 0, OVERHEAD + 0);
	sloc1.overhead.ov_flags = EO_EXP | EO_STACK;
	RT_DFS(&sloc1.overhead, eif_new_type(988, 0x00).id);
	RTLI(6);
	RTLR(0,Current);
	RTLR(1,loc2);
	RTLR(2,loc1);
	RTLR(3,tr1);
	RTLR(4,ur1);
	RTLR(5,tr2);
	RTLIU(6);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	RTLU(SK_INT32, &loc3);
	
	RTEAA(l_feature_name, 1205, Current, 3, 2, 17332);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1205, Current, 17332);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("move_precond(row, column)", EX_PRE);
		ui4_1 = arg1;
		ui4_2 = arg2;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(8257, dtype))(Current, ui4_1x, ui4_2x)).it_b);
		RTTE(tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCK;
		RTHOOK(2);
		RTCT("move_precond(row, column)", EX_PRE);
		ui4_1 = arg1;
		ui4_2 = arg2;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(8257, dtype))(Current, ui4_1x, ui4_2x)).it_b);
		RTTE(tb1, label_2);
		RTCK;
		RTJB;
label_2:
		RTCF;
	}
body:;
	wstdinit(loc1,loc1);
	RTLXI(loc1);
	RTHOOK(3);
	RTDBGAL(2, 0xF80003E0, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(6443, "m", loc1))(loc1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(4);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7399, dtype))(Current)).it_i4);
	if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
		RTHOOK(5);
		RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
		tr1 = RTMS_EX_H("A",1,65);
		ur1 = tr1;
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
		loc3 = (EIF_INTEGER_32) ti4_1;
	} else {
		RTHOOK(6);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7400, dtype))(Current)).it_i4);
		if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
			RTHOOK(7);
			RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
			tr1 = RTMS_EX_H("B",1,66);
			ur1 = tr1;
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
			loc3 = (EIF_INTEGER_32) ti4_1;
		} else {
			RTHOOK(8);
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7401, dtype))(Current)).it_i4);
			if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
				RTHOOK(9);
				RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
				tr1 = RTMS_EX_H("C",1,67);
				ur1 = tr1;
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
				loc3 = (EIF_INTEGER_32) ti4_1;
			} else {
				RTHOOK(10);
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7402, dtype))(Current)).it_i4);
				if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
					RTHOOK(11);
					RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
					tr1 = RTMS_EX_H("D",1,68);
					ur1 = tr1;
					ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
					loc3 = (EIF_INTEGER_32) ti4_1;
				} else {
					RTHOOK(12);
					ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7403, dtype))(Current)).it_i4);
					if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
						RTHOOK(13);
						RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
						tr1 = RTMS_EX_H("E",1,69);
						ur1 = tr1;
						ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
						loc3 = (EIF_INTEGER_32) ti4_1;
					} else {
						RTHOOK(14);
						ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7404, dtype))(Current)).it_i4);
						if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
							RTHOOK(15);
							RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
							tr1 = RTMS_EX_H("F",1,70);
							ur1 = tr1;
							ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
							loc3 = (EIF_INTEGER_32) ti4_1;
						} else {
							RTHOOK(16);
							ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7405, dtype))(Current)).it_i4);
							if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
								RTHOOK(17);
								RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
								tr1 = RTMS_EX_H("G",1,71);
								ur1 = tr1;
								ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
								loc3 = (EIF_INTEGER_32) ti4_1;
							} else {
								RTHOOK(18);
								ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7406, dtype))(Current)).it_i4);
								if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
									RTHOOK(19);
									RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
									tr1 = RTMS_EX_H("H",1,72);
									ur1 = tr1;
									ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
									loc3 = (EIF_INTEGER_32) ti4_1;
								} else {
									RTHOOK(20);
									ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7407, dtype))(Current)).it_i4);
									if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
										RTHOOK(21);
										RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
										tr1 = RTMS_EX_H("I",1,73);
										ur1 = tr1;
										ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
										loc3 = (EIF_INTEGER_32) ti4_1;
									} else {
										RTHOOK(22);
										ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7408, dtype))(Current)).it_i4);
										if ((EIF_BOOLEAN)(arg1 == ti4_1)) {
											RTHOOK(23);
											RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
											tr1 = RTMS_EX_H("J",1,74);
											ur1 = tr1;
											ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6473, "letter_to_row_nb", loc2))(loc2, ur1x)).it_i4);
											loc3 = (EIF_INTEGER_32) ti4_1;
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
	RTHOOK(24);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8255, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTNHOOK(24,1);
	ui4_1 = loc3;
	ui4_2 = (EIF_INTEGER_32) (arg2 + ((EIF_INTEGER_32) 1L));
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(6536, "move", tr1))(tr1, ui4_1x, ui4_2x);
	RTHOOK(25);
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8245, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTNHOOK(25,1);
	tr2 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(7004, "on_change", tr1))(tr1)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
	RTNHOOK(25,2);
	{
		EIF_TYPE_INDEX typarr0[] = {0xFF01,0xFFF9,1,186,0xFF01,0,0xFFFF};
		EIF_TYPE typres0;
		typarr0[5] = Dftype(Current);
		
		typres0 = eif_compound_id(Dftype(Current), typarr0);
		tr1 = RTLNTS(typres0.id, 2, 0);
	}
	((EIF_TYPED_VALUE *)tr1+1)->it_r = Current;
	RTAR(tr1,Current);
	ur1 = RTCCL(tr1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(6513, "notify", tr2))(tr2, ur1x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(26);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
#undef up1
#undef up2
#undef ur1
#undef ui4_1
#undef ui4_2
#undef arg2
#undef arg1
}

void EIF_Minit1206 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
