/*
 * Class KL_CHARACTER_ROUTINES
 */

#include "eif_macros.h"


#ifdef __cplusplus
extern "C" {
#endif

static const EIF_TYPE_INDEX egt_0_1025 [] = {0xFF01,232,0xFFFF};
static const EIF_TYPE_INDEX egt_1_1025 [] = {0xFF01,245,1024,0xFFFF};
static const EIF_TYPE_INDEX egt_2_1025 [] = {0xFF01,1024,0xFFFF};
static const EIF_TYPE_INDEX egt_3_1025 [] = {0,0xFFFF};
static const EIF_TYPE_INDEX egt_4_1025 [] = {0,0xFFFF};
static const EIF_TYPE_INDEX egt_5_1025 [] = {0xFF01,1024,0xFFFF};
static const EIF_TYPE_INDEX egt_6_1025 [] = {0xFF01,1024,0xFFFF};
static const EIF_TYPE_INDEX egt_7_1025 [] = {0,0xFFFF};
static const EIF_TYPE_INDEX egt_8_1025 [] = {0xFF01,15,0xFFFF};
static const EIF_TYPE_INDEX egt_9_1025 [] = {0xFF01,232,0xFFFF};
static const EIF_TYPE_INDEX egt_10_1025 [] = {0xFF01,232,0xFFFF};
static const EIF_TYPE_INDEX egt_11_1025 [] = {0xFF01,25,0xFFFF};
static const EIF_TYPE_INDEX egt_12_1025 [] = {0xFF01,1024,0xFFFF};
static const EIF_TYPE_INDEX egt_13_1025 [] = {0xFF01,1130,0xFFFF};


static const struct desc_info desc_1025[] = {
	{EIF_GENERIC(NULL), 0xFFFFFFFF, 0xFFFFFFFF},
	{EIF_GENERIC(egt_0_1025), 0, 0xFFFFFFFF},
	{EIF_GENERIC(egt_1_1025), 1, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 2, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 3, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 4, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 5, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 6, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 7, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 8, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 9, 0xFFFFFFFF},
	{EIF_GENERIC(egt_2_1025), 10, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 11, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 12, 0xFFFFFFFF},
	{EIF_GENERIC(egt_3_1025), 13, 0xFFFFFFFF},
	{EIF_GENERIC(egt_4_1025), 14, 0xFFFFFFFF},
	{EIF_GENERIC(egt_5_1025), 15, 0xFFFFFFFF},
	{EIF_GENERIC(egt_6_1025), 16, 0xFFFFFFFF},
	{EIF_GENERIC(egt_7_1025), 17, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 18, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 19, 0xFFFFFFFF},
	{EIF_GENERIC(egt_8_1025), 20, 0xFFFFFFFF},
	{EIF_GENERIC(egt_9_1025), 21, 0xFFFFFFFF},
	{EIF_GENERIC(egt_10_1025), 22, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 23, 0xFFFFFFFF},
	{EIF_GENERIC(egt_11_1025), 24, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 25, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 26, 0xFFFFFFFF},
	{EIF_GENERIC(NULL), 27, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0801 /*1024*/), 28, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x01C7 /*227*/), 29, 0xFFFFFFFF},
	{EIF_GENERIC(egt_12_1025), 30, 0xFFFFFFFF},
	{EIF_GENERIC(egt_13_1025), 15084, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 15089, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0191 /*200*/), 15090, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0185 /*194*/), 15085, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0185 /*194*/), 15086, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0185 /*194*/), 15087, 0xFFFFFFFF},
	{EIF_NON_GENERIC(0x0185 /*194*/), 15088, 0xFFFFFFFF},
};
void Init1025(void)
{
	IDSC(desc_1025, 0, 1024);
	IDSC(desc_1025 + 1, 1, 1024);
	IDSC(desc_1025 + 32, 568, 1024);
	IDSC(desc_1025 + 33, 876, 1024);
}


#ifdef __cplusplus
}
#endif
