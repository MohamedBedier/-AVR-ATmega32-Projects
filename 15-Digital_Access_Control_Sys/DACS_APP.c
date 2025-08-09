/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  APP
 * @file :  main.c
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to implement the application
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

#include "CLCD_cfg.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"

#include "SSD_Private.h"
#include "SSD_Cfg.h"
#include "SSD_Interface.h"

#include "LED_Cfg.h"
#include "LED_Private.h"
#include "LED_Interface.h"

#include "DIO_Interfce.h"
#include "PORT_Interface.h"


#include "DACS_APP.h"

/**
 * @brief: this is a function used to initiate the pins of KPD,CLCD,SSD and put the initial state of them
 * @param[in]: void ==> this function dosen't take any argument
 * @return: void ==> this function dosen't return anything
 */
void DACS_voidInitSys(SSD_Config_t *Copy_PS_SSD_t)
{
	PORT_voidInit();
	CLCD_voidInit();
	SSD_u8Display_OFF(Copy_PS_SSD_t);
}

/**
 * @brief: this is a function used to shut down all system
 * @param[in]: Copy_PS_SSD_Config ==> this function take a struct of SSD
 * @return: void ==> this function dosen't return anything
 */
void DACS_SystemShutDown(SSD_Config_t *Copy_PS_SSD_Config)
{
	CLCD_voidSendCmd(1);
	SSD_u8Display_OFF(Copy_PS_SSD_Config);

}

/**
 * @brief: this is a function used to know the user access to the system successfully
 * @param[in]: pointer from the led struct
 * @return: void ==> this function dosen't return anything
 */
void DACS_System_ON(LED_Config_t *Copy_PsLED_Config)
{
	CLCD_voidGoToXY(1,1);
	CLCD_u8SendString("Access Granted");
	LED_u8LedTurnON(Copy_PsLED_Config);
}


/**
 * @brief: this is a function used to AskAndTakeUserIdThenCheckIsValid ===>
 * the system will start with ask the user On CLCD to enter Id then checking on the Id
 * if ID valid ==> ask Password else shutdown the system
 * @param[in]: void ==> this function dosen't take any argument
 * @return: Local_u32IDFourDigits == > This is a four digits of user id
 */
uint32 AskAndTakeUserIdThenCheckIsValid(SSD_Config_t *Copy_PS_SSD_Config)
{
	/* define variables */
	uint8 Local_u8IdDigits= 0xff ;
	uint8 Local_u8IdDigitsCounter= INITIAL_ZERO_VAL ;
	uint32 Local_u32IDFourDigits=INITIAL_ZERO_VAL ;
	uint8 Local_u8PositionInc = INITIAL_ZERO_VAL ;
	/* clear the CLCD */
	CLCD_voidSendCmd(1);
	/* GO TO the initial position (0,0) */
	CLCD_voidGoToXY(0,0);
	/* write on CLCD to ask the user to enter the ID */
	CLCD_u8SendString("Enter_ID:");


	do{
		/* this equation to determine the position of x */
		Local_u8PositionInc = 9 + Local_u8IdDigitsCounter;
		/* GO TO the position of (0,9) to write on the CLCD after the string then increment the position y by 1*/
		CLCD_voidGoToXY(Local_u8PositionInc, 0);

		/* waiting until the user enter a number */
		while (Local_u8IdDigits == 0xff)
		{
			/* take the ID FROM the user from the KPD */
			Local_u8IdDigits = KPD_u8GetPressedKey();
		}

		/* send the number to CLCD */
		CLCD_voidSendNumber(Local_u8IdDigits);
		/* check on the number if it valid or not */
		if (Local_u8IdDigits >= 0 && Local_u8IdDigits <= 9)
		{
			/* this equation to concatinate the four digits */
			Local_u32IDFourDigits = Local_u32IDFourDigits *10 + Local_u8IdDigits;
		}
		/* update the counter of the loop */
		Local_u8IdDigitsCounter++;
		/* put Local_u8IdDigits by 0xff */
		Local_u8IdDigits = 0xff;

	}while(Local_u8IdDigitsCounter < 4);



	/* check if the user enter a valid id or not */
	if(Local_u32IDFourDigits != 1234 && Local_u32IDFourDigits != 5678)
	{
		CLCD_voidGoToXY(3,1);
		CLCD_u8SendString("IN_VALID ID");
		_delay_ms(1000);
		CLCD_voidGoToXY(1,1);
		CLCD_u8SendString("Sys Shut down");
		_delay_ms(1000);
		/* system shut down */
		DACS_SystemShutDown(Copy_PS_SSD_Config);
	}
	/* return the USER ID */
	return Local_u32IDFourDigits;

}


/**
 * @brief: this is a function used to AskAndTakeUserPassWordThenCheckIsValid ===>
 * if ID valid ==> ask Password if the password is correct from the first time enter the system and show on CLCD
 * Access granted and green led is on , else user has 3 time to enter the password if the password is correct at anytime from 3 times
 * enter the system and show on CLCD Access granted and green led is on, if the three time is finished else shutdown the system
 * @param[in]: void ==> this function dosen't take any argument
 * @return: Local_u32PassWordFourDigits == > This is a four digits of user PassWord
 */
uint32 AskAndTakeUserPassWordThenCheckIsValid(void)
{
	/* define variables */
	uint8  Local_u8PassWordDigits= 0xff;
	uint32 Local_u32PassWordFourDigits=INITIAL_ZERO_VAL ;
	uint8  Local_u8PassWordDigitsCounter= INITIAL_ZERO_VAL ;
	uint8  Local_u8PositionInc = INITIAL_ZERO_VAL ;

	/* clear the CLCD */
	CLCD_voidSendCmd(1);
	/* GO TO the initial position (0,0) */
	CLCD_voidGoToXY(0,0);
	/* write on CLCD to ask the user to enter the ID */
	CLCD_u8SendString("PassWord:");

	do{
		/* this equation to determine the position of x */
		Local_u8PositionInc = 9 + Local_u8PassWordDigitsCounter;
		/* GO TO the position of (0,9) to write on the CLCD after the string then increment the position y by 1*/
		CLCD_voidGoToXY(Local_u8PositionInc, 0);

		/* waiting until the user enter a number */
		while (Local_u8PassWordDigits == 0xff)
		{
			/* take the ID FROM the user from the KPD */
			Local_u8PassWordDigits = KPD_u8GetPressedKey();
		}

		/* send the number to CLCD */
		CLCD_voidSendNumber(Local_u8PassWordDigits);
		_delay_ms(300);
		CLCD_voidGoToXY(Local_u8PositionInc, 0);
		CLCD_voidSendData('*');
		/* check on the number if it valid or not */
		if (Local_u8PassWordDigits >= 0 && Local_u8PassWordDigits <= 9)
		{
			/* this equation to concatinate the four digits */
			Local_u32PassWordFourDigits = Local_u32PassWordFourDigits *10 + Local_u8PassWordDigits;
		}
		/* update the counter of the loop */
		Local_u8PassWordDigitsCounter++;
		/* put Local_u8IdDigits by 0xff */
		Local_u8PassWordDigits = 0xff;

	}while(Local_u8PassWordDigitsCounter < 4);

	/* check if the user enter a valid id or not */
	if(Local_u32PassWordFourDigits != 2244 && Local_u32PassWordFourDigits != 6688)
	{
		CLCD_voidGoToXY(3,1);
		CLCD_u8SendString("IN_VALID Pa");
		_delay_ms(1000);
		CLCD_voidSendCmd(1);

		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("Enter Pass Agian");
		CLCD_voidGoToXY(0,1);
		CLCD_u8SendString("U have 3 Times");
		_delay_ms(1000);

		CLCD_voidSendCmd(1);
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("PassWord:");

		Local_u32PassWordFourDigits = 1;
	}
	return Local_u32PassWordFourDigits;

}

/**
 * @brief: this is a function used to AskAndTakeUserPassWordThenCheck ===>
 * if ID valid ==> ask Password if the password is correct from the first time enter the system and show on CLCD
 * Access granted and green led is on , else user has 3 time to enter the password if the password is correct at anytime from 3 times
 * enter the system and show on CLCD Access granted and green led is on, if the three time is finished else shutdown the system
 * @param[in]: void ==> this function dosen't take any argument
 * @return: Local_u32PassWordFourDigits == > This is a four digits of user PassWord
 */
void AskAndTakeUserPassWord_ThreeTimes_ThenCheckIsValid(SSD_Config_t *Copy_PS_SSD_Config ,LED_Config_t *Copy_PsLED_Config )
{

	uint32 Local_u32PassWord;
	uint8 Local_u8RemaingTryingCounter = INITIAL_ZERO_VAL ;
	/* SSD ON to show the number of the remaining trying to enter the password */
	SSD_u8Display_ON(Copy_PS_SSD_Config);

	SSD_u8SetNumber(Copy_PS_SSD_Config , 3);



	for(Local_u8RemaingTryingCounter = 3 ; Local_u8RemaingTryingCounter > 0 ; Local_u8RemaingTryingCounter--)
	{
		Local_u32PassWord = AskAndTakeUserPassWordThenCheckIsValid();

		if (Local_u32PassWord == 2244 || Local_u32PassWord == 6688)
		{
			DACS_System_ON(Copy_PsLED_Config);
			break;
		}else
		{
			SSD_u8SetNumber(Copy_PS_SSD_Config ,Local_u8RemaingTryingCounter -1  );
			//Local_u32PassWord = AskAndTakeUserPassWordThenCheckIsValid();
		}
	}

	if(Local_u32PassWord != 2244 && Local_u32PassWord != 6688)
	{
		DACS_SystemShutDown(Copy_PS_SSD_Config);
	}


}
