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

#include "DCMotor_Cfg.h"
#include "DCMotor_Interface.h"
#include "DCMotor_Private.h"

#include "CLCD_cfg.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"

#include "PORT_Interface.h"
#include "DIO_Interfce.h"

#include "DCMotorWith_H_BridgeApp.h"


/* configuration of the DC MOTOR */
DC_Motor_t  DC_Motor = {DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN1};


int main(void)
{

	/* initiate the system DC and H_bridge pins and clcd pins */
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{
		/* DC motor rotate clock wise for 5 sec */
		DCMotorAPP_u8DCRotateClockWise(&DC_Motor);
		_delay_ms(5000);

		/* DC motor stop for 3 sec */
		DCMotorAPP_u8DCStop(&DC_Motor);
		_delay_ms(3000);

		/* DC motor rotate Counter clock wise for 5 sec */
		DCMotorAPP_u8DCRotateCounterClockWise(&DC_Motor);
		_delay_ms(5000);

		/* DC motor stop for 3 sec */
		DCMotorAPP_u8DCStop(&DC_Motor);
		_delay_ms(3000);

	}
}

