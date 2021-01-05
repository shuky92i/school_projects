/*
 * Code for class EV_GTK_DEPENDENT_APPLICATION_IMP
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void F1246_11110(EIF_REFERENCE);
extern void F1246_11111(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11112(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1246_11113(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1246_11114(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11115(EIF_REFERENCE);
extern void F1246_11116(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11117(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11118(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11119(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11120(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11121(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11122(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11123(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11124(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11125(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11126(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11127(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1246_11128(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11129(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11130(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11131(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11132(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11134(EIF_REFERENCE);
extern EIF_TYPED_VALUE F1246_11135(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F1246_11136(EIF_REFERENCE);
extern void F1246_11137(EIF_REFERENCE);
extern void F1246_11138(EIF_REFERENCE);
extern void F1246_11139(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F1246_11140(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void EIF_Minit1246(void);

#ifdef __cplusplus
}
#endif

#include <string.h>
#include "ev_c_util.h"
#include <ev_gtk.h>
#include "eif_out.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef INLINE_F1246_11127
static EIF_INTEGER_32 inline_F1246_11127 (EIF_POINTER arg1, EIF_POINTER arg2)
{
	return strcmp ((const char*) arg1, (const char*) arg2);
	;
}
#define INLINE_F1246_11127
#endif
#ifndef INLINE_F1246_11135
static EIF_POINTER inline_F1246_11135 (EIF_POINTER arg1)
{
	#ifdef GDK_WINDOWING_X11
	return (EIF_POINTER) gdk_x11_screen_get_window_manager_name ((GdkScreen*) arg1);
#else
	return "unknown";
#endif
	;
}
#define INLINE_F1246_11135
#endif
#ifndef INLINE_F1246_11136
static void inline_F1246_11136 (void)
{
	{
	gtk_rc_parse_string ("style \"default-style\" {\n GtkWindow::resize-grip-height = 0\n GtkWindow::resize-grip-width = 0\n}\n  class \"GtkWidget\" style  \"default-style\" ");
}
	;
}
#define INLINE_F1246_11136
#endif
#ifndef INLINE_F1246_11137
static void inline_F1246_11137 (void)
{
	{
	gtk_rc_parse_string ("style \"v2-combo-style\" {\n GtkComboBox::appears-as-list = 1\n }\n  widget \"*.v2combobox\" style : highest  \"v2-combo-style\" " );
}
	;
}
#define INLINE_F1246_11137
#endif
#ifndef INLINE_F1246_11138
static void inline_F1246_11138 (void)
{
	{
	gtk_rc_parse_string ("style \"v2-toolbar-style\" {\n GtkToolbar::shadow-type = none\n }\n  widget \"*.v2toolbar\" style : highest  \"v2-toolbar-style\" " );
}
	;
}
#define INLINE_F1246_11138
#endif
#ifndef INLINE_F1246_11139
static void inline_F1246_11139 (EIF_POINTER arg1, EIF_POINTER* arg2, EIF_INTEGER_32* arg3)
{
	{
				PangoFontFamily **families;
				gchar **l_name_array = NULL;
				gint i;
				pango_context_list_families (gtk_widget_get_pango_context ((GtkWidget*) arg1), &families, arg3);

				
				l_name_array = malloc (*arg3 * sizeof (gchar*));
				
				for (i=0; i < *arg3; i++)
				{
					 l_name_array [i] = (gchar *) pango_font_family_get_name (families[i]);
				}
				
				g_free (families);
				
				*(EIF_POINTER *) arg2 = (EIF_POINTER *) l_name_array;
			}
	;
}
#define INLINE_F1246_11139
#endif
#ifndef INLINE_F1246_11140
static EIF_POINTER inline_F1246_11140 (EIF_POINTER arg1, EIF_INTEGER_32 arg2)
{
	return (EIF_POINTER) ((EIF_POINTER) *((gchar**) arg1 + (int) (arg2 - 1)))
	;
}
#define INLINE_F1246_11140
#endif

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.gtk_dependent_initialize */
void F1246_11110 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "gtk_dependent_initialize";
	RTEX;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17761);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17761);
	RTIV(Current, RTAL);
	RTHOOK(1);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(8573, dtype))(Current);
	RTHOOK(2);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(8574, dtype))(Current);
	RTHOOK(3);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(8575, dtype))(Current);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.gtk_dependent_launch_initialize */
void F1246_11111 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "gtk_dependent_launch_initialize";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(4);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,tr2);
	RTLR(3,ur1);
	RTLIU(4);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17762);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17762);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tb1 = '\0';
	tb2 = '\0';
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5153, 969))(Current)).it_i4);
	if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 1L))) {
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5154, 969))(Current)).it_i4);
		tb2 = (EIF_BOOLEAN) (ti4_1 <= ((EIF_INTEGER_32) 2L));
	}
	if (tb2) {
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5155, 969))(Current)).it_i4);
		tb1 = (EIF_BOOLEAN) (ti4_1 < ((EIF_INTEGER_32) 8L));
	}
	if (tb1) {
		RTHOOK(2);
		tr1 = RTMS_EX_H("This application is designed for Gtk 1.2.8 and above, your current version is 1.2.",82,489488942);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5155, 969))(Current)).it_i4);
		RTNHOOK(2,1);
		tr2 = c_outi(ti4_1);
		ur1 = RTCCL(tr2);
		tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4721, "plus", tr1))(tr1, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		tr1 = RTMS_EX_H(" and may cause some unexpected behavior\012",40,593619978);
		ur1 = tr1;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4721, "plus", tr2))(tr2, ur1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(30, dtype))(Current, ur1x);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
#undef up1
#undef ur1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.pixel_value_from_point_value */
EIF_TYPED_VALUE F1246_11112 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "pixel_value_from_point_value";
	RTEX;
#define arg1 arg1x.it_i4
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU(SK_INT32,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 1, 17763);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17763);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0x10000000, 1,0); /* Result */
	tr8_1 = (EIF_REAL_64) (((EIF_INTEGER_32) 4L));
	ti4_1 = (EIF_INTEGER_32) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (arg1) /  (EIF_REAL_64) (((EIF_INTEGER_32) 3L))) * tr8_1) + (EIF_REAL_64) 0.5));
	Result = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
#undef arg1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.point_value_from_pixel_value */
EIF_TYPED_VALUE F1246_11113 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "point_value_from_pixel_value";
	RTEX;
#define arg1 arg1x.it_i4
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU(SK_INT32,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 1, 17764);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17764);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0x10000000, 1,0); /* Result */
	tr8_1 = (EIF_REAL_64) (((EIF_INTEGER_32) 3L));
	ti4_1 = (EIF_INTEGER_32) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (arg1) /  (EIF_REAL_64) (((EIF_INTEGER_32) 4L))) * tr8_1) + (EIF_REAL_64) 0.5));
	Result = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
#undef arg1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.pango_layout */
RTOID (F1246_11114)
EIF_TYPED_VALUE F1246_11114 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "pango_layout";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_POINTER tp1;
	EIF_POINTER tp2;
	RTCDD;
	RTSN;
	RTDA;
	RTLD;
	
#define Result RTOTRB(EIF_POINTER)
	RTOTDB(EIF_POINTER, F1246_11114);
	dtype = Dtype(Current);

	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_POINTER, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17765);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17765);
	RTIV(Current, RTAL);
	RTOTP;
	RTHOOK(1);
	RTDBGAL(0, 0x40000000, 1,0); /* Result */
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8570, dtype))(Current)).it_p);
	up1 = tp1;
	tp2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(36, dtype))(Current)).it_p);
	up2 = tp2;
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6072, 970))(Current, up1x, up2x)).it_p);
	Result = (EIF_POINTER) tp1;
	RTVI(Current, RTAL);
	RTRS;
	RTOTE;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_POINTER; r.it_p = Result; return r; }
#undef up1
#undef up2
#undef Result
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.pango_iter */
EIF_TYPED_VALUE F1246_11115 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "pango_iter";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_POINTER tp1;
	EIF_POINTER Result = ((EIF_POINTER) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_POINTER, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17766);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17766);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0x40000000, 1,0); /* Result */
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8551, dtype))(Current)).it_p);
	up1 = tp1;
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(6067, 970))(Current, up1x)).it_p);
	Result = (EIF_POINTER) tp1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_POINTER; r.it_p = Result; return r; }
#undef up1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.initialize_default_font_values */
void F1246_11116 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "initialize_default_font_values";
	RTEX;
	EIF_REFERENCE loc1 = (EIF_REFERENCE) 0;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_REFERENCE loc3 = (EIF_REFERENCE) 0;
	EIF_BOOLEAN loc4 = (EIF_BOOLEAN) 0;
	EIF_REFERENCE loc5 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc6 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc7 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc8 = (EIF_REFERENCE) 0;
	EIF_REFERENCE loc9 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE uw1x = {{0}, SK_CHAR32};
#define uw1 uw1x.it_c4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_CHARACTER_32 tw1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(10);
	RTLR(0,loc1);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLR(3,tr2);
	RTLR(4,loc3);
	RTLR(5,loc2);
	RTLR(6,loc9);
	RTLR(7,loc8);
	RTLR(8,ur1);
	RTLR(9,loc5);
	RTLIU(10);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	RTLU(SK_REF, &loc1);
	RTLU(SK_REF, &loc2);
	RTLU(SK_REF, &loc3);
	RTLU(SK_BOOL, &loc4);
	RTLU(SK_REF, &loc5);
	RTLU(SK_INT32, &loc6);
	RTLU(SK_INT32, &loc7);
	RTLU(SK_REF, &loc8);
	RTLU(SK_REF, &loc9);
	
	RTEAA(l_feature_name, 1245, Current, 9, 0, 17767);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTAOMS(11115,6);
	RTDBGEAA(1245, Current, 17767);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(1, 0xF80000EE, 0, 0); /* loc1 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8566, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTNHOOK(1,1);
	tr2 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4703, "as_lower", tr1))(tr1)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
	loc1 = (EIF_REFERENCE) RTCCL(tr2);
	RTHOOK(2);
	RTDBGAL(3, 0xF800011C, 0, 0); /* loc3 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8569, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc3 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	RTDBGAL(2, 0xF800011C, 0, 0); /* loc2 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8568, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc2 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(4);
	RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
	loc6 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(5);
	RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2386, "count", loc2))(loc2)).it_i4);
	loc7 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(6);
	RTDBGAL(9, 0xF80000EE, 0, 0); /* loc9 */
	RTCOMS32(tr1,11115,0,"S\000\000\000a\000\000\000n\000\000\000s\000\000\000",4,1398894195);
	loc9 = (EIF_REFERENCE) tr1;
	RTHOOK(7);
	RTDBGAA(Current, dtype, 8555, 0xF80000EE, 0); /* default_font_name_internal */
	tr1 = RTCCL(loc9);
	RTAR(Current, tr1);
	*(EIF_REFERENCE *)(Current + RTWA(8555, dtype)) = (EIF_REFERENCE) tr1;
	for (;;) {
		RTHOOK(8);
		if ((EIF_BOOLEAN) (loc4 || (EIF_BOOLEAN) (loc6 > loc7))) break;
		RTHOOK(9);
		RTDBGAL(8, 0xF80000EE, 0, 0); /* loc8 */
		ui4_1 = loc6;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2369, "i_th", loc3))(loc3, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		loc8 = (EIF_REFERENCE) RTCCL(tr1);
		RTHOOK(10);
		ur1 = RTCCL(loc8);
		ui4_1 = ((EIF_INTEGER_32) 1L);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(4692, "substring_index", loc1))(loc1, ur1x, ui4_1x)).it_i4);
		if ((EIF_BOOLEAN)(ti4_1 == ((EIF_INTEGER_32) 1L))) {
			RTHOOK(11);
			tb1 = '\01';
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8555, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			if (!RTCEQ(tr1, loc9)) {
				ti4_1 = *(EIF_INTEGER_32 *)(loc8 + RTVA(4910, "count", loc8));
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8555, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				RTNHOOK(11,1);
				ti4_2 = *(EIF_INTEGER_32 *)(tr1 + RTVA(4910, "count", tr1));
				tb1 = (EIF_BOOLEAN) (ti4_1 > ti4_2);
			}
			if (tb1) {
				RTHOOK(12);
				RTDBGAA(Current, dtype, 8555, 0xF80000EE, 0); /* default_font_name_internal */
				ui4_1 = loc6;
				tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2369, "i_th", loc2))(loc2, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
				tr1 = RTCCL(tr1);
				RTAR(Current, tr1);
				*(EIF_REFERENCE *)(Current + RTWA(8555, dtype)) = (EIF_REFERENCE) tr1;
			}
			RTHOOK(13);
			RTDBGAL(4, 0x04000000, 1, 0); /* loc4 */
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8555, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			RTNHOOK(13,1);
			ti4_1 = *(EIF_INTEGER_32 *)(tr1 + RTVA(4910, "count", tr1));
			ti4_2 = *(EIF_INTEGER_32 *)(loc1 + RTVA(4910, "count", loc1));
			loc4 = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 == ti4_2);
		}
		RTHOOK(14);
		RTDBGAL(6, 0x10000000, 1, 0); /* loc6 */
		loc6++;
	}
	RTHOOK(15);
	RTDBGAL(5, 0xF800011E, 0, 0); /* loc5 */
	tw1 = (EIF_CHARACTER_32) (EIF_CHARACTER_8) ' ';
	uw1 = tw1;
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4720, "split", loc1))(loc1, uw1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc5 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(16);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2331, "compare_objects", loc5))(loc5);
	RTHOOK(17);
	RTDBGAA(Current, dtype, 8557, 0x10000000, 1); /* default_font_point_height_internal */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2794, "last", loc5))(loc5)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	RTNHOOK(17,1);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4707, "to_integer", tr1))(tr1)).it_i4);
	*(EIF_INTEGER_32 *)(Current + RTWA(8557, dtype)) = (EIF_INTEGER_32) ti4_1;
	RTHOOK(18);
	tb1 = '\01';
	RTCOMS32(tr1,11115,1,"i\000\000\000t\000\000\000a\000\000\000l\000\000\000i\000\000\000c\000\000\000",6,1841824099);
	ur1 = tr1;
	tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2326, "has", loc5))(loc5, ur1x)).it_b);
	if (!tb2) {
		RTCOMS32(tr1,11115,2,"o\000\000\000b\000\000\000l\000\000\000i\000\000\000q\000\000\000u\000\000\000e\000\000\000",7,1996202853);
		ur1 = tr1;
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2326, "has", loc5))(loc5, ur1x)).it_b);
		tb1 = tb2;
	}
	if (tb1) {
		RTHOOK(19);
		RTDBGAA(Current, dtype, 8559, 0x10000000, 1); /* default_font_style_internal */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7498, 1131))(Current)).it_i4);
		*(EIF_INTEGER_32 *)(Current + RTWA(8559, dtype)) = (EIF_INTEGER_32) ti4_1;
	} else {
		RTHOOK(20);
		RTDBGAA(Current, dtype, 8559, 0x10000000, 1); /* default_font_style_internal */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7497, 1131))(Current)).it_i4);
		*(EIF_INTEGER_32 *)(Current + RTWA(8559, dtype)) = (EIF_INTEGER_32) ti4_1;
	}
	RTHOOK(21);
	RTCOMS32(tr1,11115,3,"b\000\000\000o\000\000\000l\000\000\000d\000\000\000",4,1651469412);
	ur1 = tr1;
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2326, "has", loc5))(loc5, ur1x)).it_b);
	if (tb1) {
		RTHOOK(22);
		RTDBGAA(Current, dtype, 8561, 0x10000000, 1); /* default_font_weight_internal */
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7495, 1131))(Current)).it_i4);
		*(EIF_INTEGER_32 *)(Current + RTWA(8561, dtype)) = (EIF_INTEGER_32) ti4_1;
	} else {
		RTHOOK(23);
		RTCOMS32(tr1,11115,4,"l\000\000\000i\000\000\000g\000\000\000h\000\000\000t\000\000\000",5,1769214068);
		ur1 = tr1;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2326, "has", loc5))(loc5, ur1x)).it_b);
		if (tb1) {
			RTHOOK(24);
			RTDBGAA(Current, dtype, 8561, 0x10000000, 1); /* default_font_weight_internal */
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7493, 1131))(Current)).it_i4);
			*(EIF_INTEGER_32 *)(Current + RTWA(8561, dtype)) = (EIF_INTEGER_32) ti4_1;
		} else {
			RTHOOK(25);
			RTCOMS32(tr1,11115,5,"s\000\000\000u\000\000\000p\000\000\000e\000\000\000r\000\000\000b\000\000\000o\000\000\000l\000\000\000d\000\000\000",9,607903332);
			ur1 = tr1;
			tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2326, "has", loc5))(loc5, ur1x)).it_b);
			if (tb1) {
				RTHOOK(26);
				RTDBGAA(Current, dtype, 8561, 0x10000000, 1); /* default_font_weight_internal */
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7496, 1131))(Current)).it_i4);
				*(EIF_INTEGER_32 *)(Current + RTWA(8561, dtype)) = (EIF_INTEGER_32) ti4_1;
			} else {
				RTHOOK(27);
				RTDBGAA(Current, dtype, 8561, 0x10000000, 1); /* default_font_weight_internal */
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(7494, 1131))(Current)).it_i4);
				*(EIF_INTEGER_32 *)(Current + RTWA(8561, dtype)) = (EIF_INTEGER_32) ti4_1;
			}
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(28);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(11);
	RTEE;
#undef up1
#undef up2
#undef ur1
#undef ui4_1
#undef uw1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_name */
EIF_TYPED_VALUE F1246_11117 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "default_font_name";
	RTEX;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_REFERENCE tr1 = NULL;
	EIF_BOOLEAN tb1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(3);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,Result);
	RTLIU(3);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17768);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17768);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8562, dtype))(Current)).it_b);
	if (tb1) {
		RTHOOK(2);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(8553, dtype))(Current);
	}
	RTHOOK(3);
	RTDBGAL(0, 0xF80000EE, 0,0); /* Result */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8555, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_name_internal */
EIF_TYPED_VALUE F1246_11118 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_REF;
	r.it_r = *(EIF_REFERENCE *)(Current + RTWA(8555,Dtype(Current)));
	return r;
}


/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_point_height */
EIF_TYPED_VALUE F1246_11119 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "default_font_point_height";
	RTEX;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17770);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17770);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8562, dtype))(Current)).it_b);
	if (tb1) {
		RTHOOK(2);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(8553, dtype))(Current);
	}
	RTHOOK(3);
	RTDBGAL(0, 0x10000000, 1,0); /* Result */
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(8557, dtype));
	Result = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_point_height_internal */
EIF_TYPED_VALUE F1246_11120 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(8557,Dtype(Current)));
	return r;
}


/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_style */
EIF_TYPED_VALUE F1246_11121 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "default_font_style";
	RTEX;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17772);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17772);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8562, dtype))(Current)).it_b);
	if (tb1) {
		RTHOOK(2);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(8553, dtype))(Current);
	}
	RTHOOK(3);
	RTDBGAL(0, 0x10000000, 1,0); /* Result */
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(8559, dtype));
	Result = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_style_internal */
EIF_TYPED_VALUE F1246_11122 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(8559,Dtype(Current)));
	return r;
}


/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_weight */
EIF_TYPED_VALUE F1246_11123 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "default_font_weight";
	RTEX;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17774);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17774);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8562, dtype))(Current)).it_b);
	if (tb1) {
		RTHOOK(2);
		(FUNCTION_CAST(void, (EIF_REFERENCE)) RTWF(8553, dtype))(Current);
	}
	RTHOOK(3);
	RTDBGAL(0, 0x10000000, 1,0); /* Result */
	ti4_1 = *(EIF_INTEGER_32 *)(Current + RTWA(8561, dtype));
	Result = (EIF_INTEGER_32) ti4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(4);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_weight_internal */
EIF_TYPED_VALUE F1246_11124 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = *(EIF_INTEGER_32 *)(Current + RTWA(8561,Dtype(Current)));
	return r;
}


/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.font_settings_changed */
EIF_TYPED_VALUE F1246_11125 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "font_settings_changed";
	RTEX;
	EIF_POINTER loc1 = (EIF_POINTER) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE up3x = {{0}, SK_POINTER};
#define up3 up3x.it_p
	EIF_POINTER tp1;
	EIF_POINTER tp2;
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_BOOL, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_POINTER, &loc1);
	
	RTEAA(l_feature_name, 1245, Current, 1, 0, 17776);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17776);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8565, dtype))(Current)).it_p);
	up1 = tp1;
	tr1 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8567, dtype))(Current)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
	RTNHOOK(1,1);
	tp2 = *(EIF_POINTER *)(tr1 + RTVA(8506, "item", tr1));
	up2 = tp2;
	up3 = (EIF_POINTER *) &(loc1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6092, 970))(Current, up1x, up2x, up3x);
	RTHOOK(2);
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(36, dtype))(Current)).it_p);
	if ((EIF_BOOLEAN)(loc1 != tp1)) {
		RTHOOK(3);
		tp1 = *(EIF_POINTER *)(Current + RTWA(8563, dtype));
		tp2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(36, dtype))(Current)).it_p);
		if ((EIF_BOOLEAN)(tp1 != tp2)) {
			RTHOOK(4);
			RTDBGAL(0, 0x04000000, 1,0); /* Result */
			tp1 = *(EIF_POINTER *)(Current + RTWA(8563, dtype));
			up1 = tp1;
			up2 = loc1;
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(8564, dtype))(Current, up1x, up2x)).it_i4);
			Result = (EIF_BOOLEAN) (EIF_BOOLEAN)(ti4_1 != ((EIF_INTEGER_32) 0L));
			RTHOOK(5);
			if (Result) {
				RTHOOK(6);
				tp1 = *(EIF_POINTER *)(Current + RTWA(8563, dtype));
				up1 = tp1;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5252, 969))(Current, up1x);
				RTHOOK(7);
				RTDBGAA(Current, dtype, 8563, 0x40000000, 1); /* previous_font_settings */
				*(EIF_POINTER *)(Current + RTWA(8563, dtype)) = (EIF_POINTER) loc1;
			} else {
				RTHOOK(8);
				up1 = loc1;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5252, 969))(Current, up1x);
			}
		} else {
			RTHOOK(9);
			RTDBGAL(0, 0x04000000, 1,0); /* Result */
			Result = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
			RTHOOK(10);
			RTDBGAA(Current, dtype, 8563, 0x40000000, 1); /* previous_font_settings */
			*(EIF_POINTER *)(Current + RTWA(8563, dtype)) = (EIF_POINTER) loc1;
		}
	} else {
		RTHOOK(11);
		RTDBGAL(0, 0x04000000, 1,0); /* Result */
		Result = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(12);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef up1
#undef up2
#undef up3
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.previous_font_settings */
EIF_TYPED_VALUE F1246_11126 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_POINTER;
	r.it_p = *(EIF_POINTER *)(Current + RTWA(8563,Dtype(Current)));
	return r;
}


/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.c_strcmp */
EIF_TYPED_VALUE F1246_11127 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "c_strcmp";
	RTEX;
#define arg1 arg1x.it_p
#define arg2 arg2x.it_p
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_p = * (EIF_POINTER *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_p = * (EIF_POINTER *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_INT32, &Result);
	RTLU(SK_POINTER,&arg1);
	RTLU(SK_POINTER,&arg2);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 2, 17778);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 1);
	RTDBGEAA(1245, Current, 17778);
	RTIV(Current, RTAL);
	Result = inline_F1246_11127 ((EIF_POINTER) arg1, (EIF_POINTER) arg2);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(1);
	RTDBGLE;
	RTMD(1);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
#undef arg2
#undef arg1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_gtk_settings */
RTOID (F1246_11128)
EIF_TYPED_VALUE F1246_11128 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "default_gtk_settings";
	RTEX;
	EIF_POINTER tp1;
	RTCDD;
	RTSN;
	RTDA;
	RTLD;
	
#define Result RTOTRB(EIF_POINTER)
	RTOTDB(EIF_POINTER, F1246_11128);
	dtype = Dtype(Current);

	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_POINTER, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17779);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17779);
	RTIV(Current, RTAL);
	RTOTP;
	RTHOOK(1);
	RTDBGAL(0, 0x40000000, 1,0); /* Result */
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5127, 969))(Current)).it_p);
	Result = (EIF_POINTER) tp1;
	RTVI(Current, RTAL);
	RTRS;
	RTOTE;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_POINTER; r.it_p = Result; return r; }
#undef Result
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.default_font_description */
EIF_TYPED_VALUE F1246_11129 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "default_font_description";
	RTEX;
	EIF_POINTER loc1 = (EIF_POINTER) 0;
	EIF_REFERENCE loc2 = (EIF_REFERENCE) 0;
	EIF_REFERENCE loc3 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE up3x = {{0}, SK_POINTER};
#define up3 up3x.it_p
	EIF_POINTER tp1;
	EIF_POINTER tp2;
	EIF_REFERENCE tr1 = NULL;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(5);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,loc2);
	RTLR(3,loc3);
	RTLR(4,Result);
	RTLIU(5);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_POINTER, &loc1);
	RTLU(SK_REF, &loc2);
	RTLU(SK_REF, &loc3);
	
	RTEAA(l_feature_name, 1245, Current, 3, 0, 17780);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTAOMS(11128,1);
	RTDBGEAA(1245, Current, 17780);
	RTIV(Current, RTAL);
	RTHOOK(1);
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8565, dtype))(Current)).it_p);
	up1 = tp1;
	tr1 = ((up2x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8567, dtype))(Current)), (((up2x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up2x.it_r = RTBU(up2x))), (up2x.type = SK_POINTER), up2x.it_r);
	RTNHOOK(1,1);
	tp2 = *(EIF_POINTER *)(tr1 + RTVA(8506, "item", tr1));
	up2 = tp2;
	up3 = (EIF_POINTER *) &(loc1);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(6092, 970))(Current, up1x, up2x, up3x);
	RTHOOK(2);
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(36, dtype))(Current)).it_p);
	if ((EIF_BOOLEAN)(loc1 != tp1)) {
		RTHOOK(3);
		RTDBGAL(2, 0xF80004DA, 0, 0); /* loc2 */
		tr1 = RTLN(eif_new_type(1242, 0x01).id);
		up1 = loc1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(8503, Dtype(tr1)))(tr1, up1x);
		RTNHOOK(3,1);
		loc2 = (EIF_REFERENCE) RTCCL(tr1);
		RTHOOK(4);
		RTDBGAL(3, 0xF80000EE, 0, 0); /* loc3 */
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(8507, "string", loc2))(loc2)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		loc3 = (EIF_REFERENCE) RTCCL(tr1);
	}
	RTHOOK(5);
	tb1 = '\01';
	if (!(EIF_BOOLEAN)(loc3 == NULL)) {
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4659, "is_empty", loc3))(loc3)).it_b);
		tb1 = tb2;
	}
	if (tb1) {
		RTHOOK(6);
		RTDBGAL(0, 0xF80000EE, 0,0); /* Result */
		RTCOMS32(tr1,11128,0,"S\000\000\000a\000\000\000n\000\000\000s\000\000\000 \000\000\0001\000\000\0000\000\000\000",7,948715824);
		Result = (EIF_REFERENCE) tr1;
	} else {
		RTHOOK(7);
		RTDBGAL(0, 0xF80000EE, 0,0); /* Result */
		Result = (EIF_REFERENCE) RTCCL(loc3);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(8);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef up2
#undef up3
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.gtk_font_name_setting */
RTOID (F1246_11130)
EIF_TYPED_VALUE F1246_11130 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "gtk_font_name_setting";
	RTEX;
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	RTCDD;
	RTSN;
	RTDA;
	RTLD;
	
#define Result RTOTRR
	RTOTDR(F1246_11130);
	dtype = Dtype(Current);

	RTLI(4);
	RTLR(0,tr1);
	RTLR(1,tr2);
	RTLR(2,ur1);
	RTLR(3,Current);
	RTLIU(4);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17781);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17781);
	RTIV(Current, RTAL);
	RTOTP;
	RTHOOK(1);
	RTDBGAL(0, 0xF80004DA, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(1242, 0x00).id);
	tr2 = RTMS_EX_H("gtk-font-name",13,1067777893);
	ur1 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(8509, Dtype(tr1)))(tr1, ur1x);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTVI(Current, RTAL);
	RTRS;
	RTOTE;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef Result
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.font_names_on_system */
RTOID (F1246_11131)
EIF_TYPED_VALUE F1246_11131 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "font_names_on_system";
	RTEX;
	EIF_POINTER loc1 = (EIF_POINTER) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc4 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE up2x = {{0}, SK_POINTER};
#define up2 up2x.it_p
	EIF_TYPED_VALUE up3x = {{0}, SK_POINTER};
#define up3 up3x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_POINTER tp1;
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	RTCDD;
	RTSN;
	RTDA;
	RTLD;
	
#define Result RTOTRR
	RTOTDR(F1246_11131);
	dtype = Dtype(Current);

	RTLI(5);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,loc4);
	RTLR(3,tr2);
	RTLR(4,ur1);
	RTLIU(5);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_POINTER, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_REF, &loc4);
	
	RTEAA(l_feature_name, 1245, Current, 4, 0, 17782);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17782);
	RTIV(Current, RTAL);
	RTOTP;
	RTHOOK(1);
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8570, dtype))(Current)).it_p);
	up1 = tp1;
	up2 = (EIF_POINTER *) &(loc1);
	up3 = (EIF_INTEGER_32 *) &(loc3);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(8576, dtype))(Current, up1x, up2x, up3x);
	RTHOOK(2);
	RTDBGAL(0, 0xF800011C, 0,0); /* Result */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,284,0xFF01,238,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ui4_1 = loc3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(3081, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(2,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	loc2 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(4);
	RTDBGAL(4, 0xF80004DA, 0, 0); /* loc4 */
	tr1 = RTLN(eif_new_type(1242, 0x01).id);
	tr2 = RTMS_EX_H("",0,0);
	ur1 = tr2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(8509, Dtype(tr1)))(tr1, ur1x);
	RTNHOOK(4,1);
	loc4 = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		RTHOOK(5);
		if ((EIF_BOOLEAN) (loc2 > loc3)) break;
		RTHOOK(6);
		up1 = loc1;
		ui4_1 = loc2;
		tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(8577, dtype))(Current, up1x, ui4_1x)).it_p);
		up1 = tp1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(8511, "share_from_pointer", loc4))(loc4, up1x);
		RTHOOK(7);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(8507, "string", loc4))(loc4)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr1);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2339, "extend", Result))(Result, ur1x);
		RTHOOK(8);
		RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
		loc2++;
	}
	RTHOOK(9);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2331, "compare_objects", Result))(Result);
	RTHOOK(10);
	free(loc1);
	RTVI(Current, RTAL);
	RTRS;
	RTOTE;
	RTHOOK(11);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(6);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef up2
#undef up3
#undef ur1
#undef ui4_1
#undef Result
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.font_names_on_system_as_lower */
RTOID (F1246_11132)
EIF_TYPED_VALUE F1246_11132 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "font_names_on_system_as_lower";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc3 = (EIF_REFERENCE) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE tr2 = NULL;
	EIF_INTEGER_32 ti4_1;
	RTCDD;
	RTSN;
	RTDA;
	RTLD;
	
#define Result RTOTRR
	RTOTDR(F1246_11132);
	dtype = Dtype(Current);

	RTLI(5);
	RTLR(0,loc3);
	RTLR(1,Current);
	RTLR(2,tr1);
	RTLR(3,tr2);
	RTLR(4,ur1);
	RTLIU(5);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_REF, &loc3);
	
	RTEAA(l_feature_name, 1245, Current, 3, 0, 17783);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17783);
	RTIV(Current, RTAL);
	RTOTP;
	RTHOOK(1);
	RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
	loc1 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(2);
	RTDBGAL(3, 0xF800011C, 0, 0); /* loc3 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(8568, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc3 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2386, "count", loc3))(loc3)).it_i4);
	loc2 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(4);
	RTDBGAL(0, 0xF800011C, 0,0); /* Result */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,284,0xFF01,238,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ui4_1 = loc2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(3081, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(4,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	for (;;) {
		RTHOOK(5);
		if ((EIF_BOOLEAN) (loc1 > loc2)) break;
		RTHOOK(6);
		ui4_1 = loc1;
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2369, "i_th", loc3))(loc3, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		tr2 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4703, "as_lower", tr1))(tr1)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		ur1 = RTCCL(tr2);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2339, "extend", Result))(Result, ur1x);
		RTHOOK(7);
		RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
		loc1++;
	}
	RTHOOK(8);
	(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(2331, "compare_objects", Result))(Result);
	RTVI(Current, RTAL);
	RTRS;
	RTOTE;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ui4_1
#undef Result
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.window_manager_name */
EIF_TYPED_VALUE F1246_11134 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "window_manager_name";
	RTEX;
	EIF_POINTER loc1 = (EIF_POINTER) 0;
	EIF_POINTER loc2 = (EIF_POINTER) 0;
	EIF_POINTER loc3 = (EIF_POINTER) 0;
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_POINTER tp1;
	EIF_REFERENCE tr1 = NULL;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(3);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLR(2,Result);
	RTLIU(3);
	RTLU (SK_REF, &Result);
	RTLU (SK_REF, &Current);
	RTLU(SK_POINTER, &loc1);
	RTLU(SK_POINTER, &loc2);
	RTLU(SK_POINTER, &loc3);
	
	RTEAA(l_feature_name, 1245, Current, 3, 0, 17784);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(1245, Current, 17784);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(1, 0x40000000, 1, 0); /* loc1 */
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(5817, 970))(Current)).it_p);
	loc1 = (EIF_POINTER) tp1;
	RTHOOK(2);
	RTDBGAL(2, 0x40000000, 1, 0); /* loc2 */
	up1 = loc1;
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(5819, 970))(Current, up1x)).it_p);
	loc2 = (EIF_POINTER) tp1;
	RTHOOK(3);
	RTDBGAL(3, 0x40000000, 1, 0); /* loc3 */
	up1 = loc2;
	tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(8572, dtype))(Current, up1x)).it_p);
	loc3 = (EIF_POINTER) tp1;
	RTHOOK(4);
	RTDBGAL(0, 0xF80000E8, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(232, 0x01).id);
	up1 = loc3;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4739, Dtype(tr1)))(tr1, up1x);
	RTNHOOK(4,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(5);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.gdk_x11_screen_get_window_manager_name */
EIF_TYPED_VALUE F1246_11135 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "gdk_x11_screen_get_window_manager_name";
	RTEX;
#define arg1 arg1x.it_p
	EIF_POINTER Result = ((EIF_POINTER) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_p = * (EIF_POINTER *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_POINTER, &Result);
	RTLU(SK_POINTER,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 1, 17785);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 1);
	RTDBGEAA(1245, Current, 17785);
	RTIV(Current, RTAL);
	Result = inline_F1246_11135 ((EIF_POINTER) arg1);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(1);
	RTDBGLE;
	RTMD(1);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_POINTER; r.it_p = Result; return r; }
#undef arg1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.initialize_window_style */
void F1246_11136 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "initialize_window_style";
	RTEX;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17786);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 1);
	RTDBGEAA(1245, Current, 17786);
	RTIV(Current, RTAL);
	inline_F1246_11136 ();
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(1);
	RTDBGLE;
	RTMD(1);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.initialize_combo_box_style */
void F1246_11137 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "initialize_combo_box_style";
	RTEX;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17787);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 1);
	RTDBGEAA(1245, Current, 17787);
	RTIV(Current, RTAL);
	inline_F1246_11137 ();
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(1);
	RTDBGLE;
	RTMD(1);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.initialize_tool_bar_style */
void F1246_11138 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "initialize_tool_bar_style";
	RTEX;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 0, 17788);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 1);
	RTDBGEAA(1245, Current, 17788);
	RTIV(Current, RTAL);
	inline_F1246_11138 ();
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(1);
	RTDBGLE;
	RTMD(1);
	RTLE;
	RTLO(2);
	RTEE;
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.retrieve_available_fonts */
void F1246_11139 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x)
{
	GTCX
	char *l_feature_name = "retrieve_available_fonts";
	RTEX;
#define arg1 arg1x.it_p
#define arg2 arg2x.it_p
#define arg3 arg3x.it_p
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_p = * (EIF_INTEGER_32* *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_p = * (EIF_POINTER* *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_p = * (EIF_POINTER *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_VOID, NULL);
	RTLU(SK_POINTER,&arg1);
	RTLU(SK_POINTER,&arg2);
	RTLU(SK_POINTER,&arg3);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 3, 17789);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 1);
	RTDBGEAA(1245, Current, 17789);
	RTIV(Current, RTAL);
	inline_F1246_11139 ((EIF_POINTER) arg1, (EIF_POINTER*) arg2, (EIF_INTEGER_32*) arg3);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(1);
	RTDBGLE;
	RTMD(1);
	RTLE;
	RTLO(5);
	RTEE;
#undef arg3
#undef arg2
#undef arg1
}

/* {EV_GTK_DEPENDENT_APPLICATION_IMP}.gchar_array_i_th */
EIF_TYPED_VALUE F1246_11140 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "gchar_array_i_th";
	RTEX;
#define arg1 arg1x.it_p
#define arg2 arg2x.it_i4
	EIF_POINTER tp1;
	EIF_POINTER Result = ((EIF_POINTER) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_p = * (EIF_POINTER *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_POINTER, &Result);
	RTLU(SK_POINTER,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 1245, Current, 0, 2, 17790);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 1);
	RTDBGEAA(1245, Current, 17790);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("an_index_valid", EX_PRE);
		RTTE((EIF_BOOLEAN) (arg2 > ((EIF_INTEGER_32) 0L)), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("array_valid", EX_PRE);
		tp1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(36, dtype))(Current)).it_p);
		RTTE((EIF_BOOLEAN)(arg1 != tp1), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	Result = inline_F1246_11140 ((EIF_POINTER) arg1, (EIF_INTEGER_32) arg2);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(1);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_POINTER; r.it_p = Result; return r; }
#undef arg2
#undef arg1
}

void EIF_Minit1246 (void)
{
	GTCX
	RTOTS (11114,F1246_11114)
	RTOTS (11128,F1246_11128)
	RTOTS (11130,F1246_11130)
	RTOTS (11131,F1246_11131)
	RTOTS (11132,F1246_11132)
}


#ifdef __cplusplus
}
#endif
