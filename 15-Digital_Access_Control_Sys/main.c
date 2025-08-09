/*************************************************************/
/*************************************************************/
/**                                                         **/
/** LayerArchitecture : APP                                 **/
/** File Name : main.c                                      **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

/* include the library of the application */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
#include <util/delay.h>

#include "CLCD_cfg.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"

#include "SSD_Private.h"
#include "SSD_Cfg.h"
#include "SSD_Interface.h"

#include "LED_Cfg.h"
#include "LED_Private.h"
#include "LED_Interface.h"

#include "DACS_APP.h"

#include "DIO_Interfce.h"
#include "PORT_Interface.h"

/* theses are the configuration struct for the led and the SSD */
SSD_Config_t SSD_t ={SSD_COMMON_CATHODE,DIO_u8PORTB,DIO_u8PORTB,DIO_u8PIN7};
LED_Config_t GreenLed_t = {SOURCE_CONNECTION , DIO_u8PORTD ,DIO_u8PIN3};



int main(void)
{
	/* this variable to carry ID of the user */
	uint32 Local_u32UserID = INITIAL_ZERO_VAL;
	/* this variable to carry pass of the user */
	uint32 Local_u32UserPassWord = INITIAL_ZERO_VAL;

	/* this function is used to initiate the system PORT, CLCD , AND SSD_En Off at the first to save power  */
	DACS_voidInitSys(&SSD_t);

	/* Ask the ID from the user */
	Local_u32UserID = AskAndTakeUserIdThenCheckIsValid(&SSD_t);
	/* this delay to see the 4 digits of the id  */
	_delay_ms(300);
	/* check if the ID is valid or not */
	if(Local_u32UserID == 1234 || Local_u32UserID == 5678)
	{
		/* Ask the PassWord from the user */
		Local_u32UserPassWord = AskAndTakeUserPassWordThenCheckIsValid() ;

		/* check if the PassWord is valid or not */
		if(Local_u32UserPassWord == 2244 || Local_u32UserPassWord == 6688)
		{
			/* if the password valid system is on and a green led is on  */
			DACS_System_ON(&GreenLed_t);
		}else if (Local_u32UserPassWord == 1)
		{
			/* reask the password from the user and he has a 3 times for trying */
			AskAndTakeUserPassWord_ThreeTimes_ThenCheckIsValid(&SSD_t ,&GreenLed_t);
		}else
		{
			;
		}
	}else
	{
		;
	}



}
