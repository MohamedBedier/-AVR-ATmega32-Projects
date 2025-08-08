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


#include "SSD_Private.h"
#include "SSD_Cfg.h"
#include "SSD_Interface.h"

#include "LED_Cfg.h"
#include "LED_Private.h"
#include "LED_Interface.h"

#include "DIO_Interfce.h"
#include "PORT_Interface.h"
#include "Traffic_Light_APP.h"


/* define the left SSD display as common cathode , connected on PORTA , the enable of it on PA7 */
SSD_Config_t SSDL_t ={SSD_COMMON_CATHODE,DIO_u8PORTA,DIO_u8PORTA,DIO_u8PIN7};
/* define the Right SSD display as common cathode , connected on PORTB , the enable of it on PB7 */
SSD_Config_t SSDR_t ={SSD_COMMON_CATHODE,DIO_u8PORTB,DIO_u8PORTB,DIO_u8PIN7};

/* define the struct of Three led :---> LED_RED on PC0 , LED_YELLOW on PC1 , and LED_GREEN on PC0 and all as source connection */
LED_Config_t  LED_RED = {SOURCE_CONNECTION , DIO_u8PORTC ,  DIO_u8PIN0};
LED_Config_t  LED_YELLOW = {SOURCE_CONNECTION , DIO_u8PORTC ,  DIO_u8PIN1};
LED_Config_t  LED_GREEN = {SOURCE_CONNECTION , DIO_u8PORTC ,  DIO_u8PIN2};


int main(void)
{
	/* set Direction for PORTA , PORTB , PORTC , PORTD as o/p */
	PORT_voidInit();

	/* at the start of the system the three led off */
	LED_u8LedTurnOff(&LED_RED);
	LED_u8LedTurnOff(&LED_YELLOW);
	LED_u8LedTurnOff(&LED_GREEN);

	/* at the start of the system the two SSD off */
	SSD_u8Display_OFF(&SSDL_t);
	SSD_u8Display_OFF(&SSDR_t);

	/* supper loop  */
	while(1)
	{
		/* at the first : SSDL is off to save power and SSDR Is on to count from 1 to 9 */
		SSD_u8DeactiveSSDLAndActiveSSDR(&SSDR_t,&SSDL_t);

		/* RED LED IS ON , green and yellow off */
		LED_u8LedTurnON(&LED_RED);

		/* at the start Red led on for 15 Sec for peaple walk and cross the street */
		SSD_u8CountfromOneToFifteen(&SSDR_t,&SSDL_t);


		/* RED LED IS OFF */
		LED_u8LedTurnOff(&LED_RED);

		/* after the project count from 1 to 15 the system is going to count 1 to 3  SSDL is off to save power  */
		SSD_u8DeactiveSSDLAndActiveSSDR(&SSDR_t,&SSDL_t);

		/* yellow LED IS ON , green and red off */
		LED_u8LedTurnON(&LED_YELLOW);

		/* yellow led is on 3 sec to know people ready to stop */
		SSD_u8CountfromOneToThree(&SSDR_t);

		/* Yellow LED IS OFF */
		LED_u8LedTurnOff(&LED_YELLOW);


		/* green LED IS ON , red and yellow off */
		LED_u8LedTurnON(&LED_GREEN);

		/* green led is on 15 sec  */
		SSD_u8CountfromOneToFifteen(&SSDR_t,&SSDL_t);

		/* Green LED IS OFF */
		LED_u8LedTurnOff(&LED_GREEN);

		/* after the project count from 1 to 15 the system is going to count 1 to 3  SSDL is off to save power  */
		SSD_u8DeactiveSSDLAndActiveSSDR(&SSDR_t,&SSDL_t);


		/* yellow LED IS ON , green and red off */
		LED_u8LedTurnON(&LED_YELLOW);

		/* yellow led is on 3 sec to know people ready to stop */
		SSD_u8CountfromOneToThree(&SSDR_t);

		/* Yellow LED IS OFF */
		LED_u8LedTurnOff(&LED_YELLOW);

	}
}
