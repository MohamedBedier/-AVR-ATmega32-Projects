/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  GIE_Program.c
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to implement the functions
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/


/***************************************************************************
****************************************************************************
*******        include all libraries you need in this section        *******
****************************************************************************
****************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_Reg.h"
#include "GIE_Cfg.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"

void GIE_u8GIE_Enabled(void)
{
	/* Set bit 7 in SREG register to open GIE  */
	//SET_BIT(GIE_u8SREG,GIE_u8SREG_I);

	/*inline assembly instruction to set I bit  */
	__asm __volatile("SEI");
}
void  GIE_u8GIE_Disable(void)
{
	/* Set bit 7 in SREG register to close GIE  */
	//CLR_BIT(GIE_u8SREG,GIE_u8SREG_I);

	/*inline assembly instruction to clear I bit  */
	__asm __volatile("CLI");
}

