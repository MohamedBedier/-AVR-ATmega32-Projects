/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  APP
 * @file : DCMotorWith_H_BridgeApp.c
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

#include "DCMotor_Cfg.h"
#include "DCMotor_Interface.h"
#include "DCMotor_Private.h"

#include "CLCD_cfg.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"

#include "PORT_Interface.h"
#include "DIO_Interfce.h"

#include "DCMotorWith_H_BridgeApp.h"

/**
 * @brief this function is used to Stop DC MOTOR in app layer and write on CLCD DC M STOP
 * @param Copy_PS_DC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMotorAPP_u8DCStop(DC_Motor_t  *Copy_PS_DC_Motor)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(Copy_PS_DC_Motor != NULL)
	{
		DCMOTOR_u8MotorStop(Copy_PS_DC_Motor);
		CLCD_voidSendCmd(1);
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("DC M STOP");

	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


/**
 * @brief this function is used to Rotate Counter ClockWise DC MOTOR in app layer and write on CLCD DC M Rotate CCW
 * @param Copy_PS_DC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMotorAPP_u8DCRotateCounterClockWise(DC_Motor_t  *Copy_PS_DC_Motor)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(Copy_PS_DC_Motor != NULL)
	{
		DCMOTOR_u8RotateCounterClockWise(Copy_PS_DC_Motor);
		CLCD_voidSendCmd(1);
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("DC M Rotate CCW");
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}



/**
 * @brief this function is used to Rotate Counter ClockWise DC MOTOR in app layer and write on CLCD DC M Rotate CW
 * @param Copy_PS_DC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMotorAPP_u8DCRotateClockWise(DC_Motor_t  *Copy_PS_DC_Motor)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the pointer is equal null or not */
	if(Copy_PS_DC_Motor != NULL)
	{
		DCMOTOR_u8RotateClockWise(Copy_PS_DC_Motor);
		CLCD_voidSendCmd(1);
		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("DC M Rotate CW");
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
