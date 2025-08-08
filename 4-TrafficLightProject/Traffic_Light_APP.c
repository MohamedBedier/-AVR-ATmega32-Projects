/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  APP
 * @file :  Traffic_Light_APP.c
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to implement the functions of the application
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/


/***************************************************************************
****************************************************************************
*******        include all libraries you need in this section        *******
****************************************************************************
****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
#include <util/delay.h>


#include "SSD_Private.h"
#include "SSD_Cfg.h"
#include "SSD_Interface.h"

#include "LED_Cfg.h"
#include "LED_Private.h"
#include "LED_Interface.h"

#include "DIO_Interfce.h"
#include "PORT_Interface.h"

#include "Traffic_Light_APP.h"

/**
 * @brief: this function is used to count from 1 to 15 in case of red and green
 * @param Copy_RightSSD : this is a pointer of struct from the configuration struct for Right SSD
 * @param Copy_LeftSSD : this is a pointer of struct from the configuration struct for Left SSD
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8CountfromOneToFifteen(SSD_Config_t *Copy_RightSSD,SSD_Config_t *Copy_LeftSSD)
{

	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;
	/* Define variables */
	sint32 Local_s32CountI , Local_s32CountJ ;

	if((Copy_RightSSD != NULL) && (Copy_LeftSSD != NULL))
	{
		/* this loop to count untill 0 to 9 for Red */
		for(Local_s32CountI = 1 ; Local_s32CountI < 10 ;Local_s32CountI++)
		{
			SSD_u8SetNumber(Copy_RightSSD, Local_s32CountI);
			_delay_ms(1000);

		}
		SSD_u8Display_ON(Copy_LeftSSD);
		/* this loop to count untill 10 to 15 for Red*/
		for(Local_s32CountJ = 0 ; Local_s32CountJ < 6 ;Local_s32CountJ++)
		{
			SSD_u8SetNumber(Copy_LeftSSD,1);
			SSD_u8SetNumber(Copy_RightSSD,Local_s32CountJ);
			_delay_ms(1000);
		}

	}else
	{
		/* Update the value of Local_u8ErrorState */
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;

}


/**
 * @brief: this function is used to count from 1 to 3 in case of yellow
 * @param Copy_RightSSD : this is a pointer of struct from the configuration struct for Right SSD
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8CountfromOneToThree(SSD_Config_t *Copy_RightSSD)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* Define variables */
	sint32 Local_s32CountI ;

	if(Copy_RightSSD != NULL)
	{
		/* this loop to count untill 0 to 3 for Yellow */
		for(Local_s32CountI = 1 ; Local_s32CountI < 4 ;Local_s32CountI++)
		{
			SSD_u8SetNumber(Copy_RightSSD, Local_s32CountI);
			_delay_ms(1000);
		}
	}else
	{
		/* Update the value of Local_u8ErrorState */
		Local_u8ErrorState =NULL_PTR_ERR;
	}
	return Local_u8ErrorState;


}

/**
 * @brief: this function is used to Deactive left SSD And Active right SSD
 * @param Copy_RightSSD : this is a pointer of struct from the configuration struct for Right SSD
 * @param Copy_LeftSSD : this is a pointer of struct from the configuration struct for Left SSD
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8DeactiveSSDLAndActiveSSDR(SSD_Config_t *Copy_RightSSD,SSD_Config_t *Copy_LeftSSD)
{

	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	if((Copy_RightSSD != NULL) && (Copy_LeftSSD != NULL))
	{
		/* active the right SSD to count untill 9 again */
		SSD_u8Display_ON(Copy_RightSSD);

		/* deactive the left SSD to save power */
		SSD_u8Display_OFF(Copy_LeftSSD);
	}else
	{
		/* Update the value of Local_u8ErrorState */
		Local_u8ErrorState =NULL_PTR_ERR;
	}

	return Local_u8ErrorState;

}
