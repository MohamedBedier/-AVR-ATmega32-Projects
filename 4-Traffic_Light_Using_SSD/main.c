/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : APP                                **/
/** File Name : main.c                                      **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

/* Include our libraries  */
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


/* define the left SSD display as common cathode , connected on PORTA , the enable of it on PA7 */
SSD_Config_t SSDL_t ={SSD_COMMON_CATHODE,DIO_u8PORTA,DIO_u8PORTA,DIO_u8PIN7};
/* define the Right SSD display as common cathode , connected on PORTB , the enable of it on PB7 */
SSD_Config_t SSDR_t ={SSD_COMMON_CATHODE,DIO_u8PORTB,DIO_u8PORTB,DIO_u8PIN7};

/* define the struct of Three led :---> LED_RED on PC0 , LED_YELLOW on PC1 , and LED_GREEN on PC0 and all as source connection */
LED_Config_t  LED_RED = {SOURCE_CONNECTION , DIO_u8PORTC ,  DIO_u8PIN0};
LED_Config_t  LED_YELLOW = {SOURCE_CONNECTION , DIO_u8PORTC ,  DIO_u8PIN1};
LED_Config_t  LED_GREEN = {SOURCE_CONNECTION , DIO_u8PORTC ,  DIO_u8PIN2};

/* there are the prototype of functions */
void SSD_voidCountfromOneToFifteen(void);
void SSD_voidCountfromOneToThree(void);
void SSD_voidDeactiveSSLAndActiveSSDR(void);
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
		SSD_voidDeactiveSSLAndActiveSSDR();

		/* RED LED IS ON , green and yellow off */
		LED_u8LedTurnON(&LED_RED);

		/* at the start Red led on for 15 Sec for peaple walk and cross the street */
		SSD_voidCountfromOneToFifteen();


		/* RED LED IS OFF */
		LED_u8LedTurnOff(&LED_RED);

		SSD_voidDeactiveSSLAndActiveSSDR();

		/* yellow LED IS ON , green and red off */
		LED_u8LedTurnON(&LED_YELLOW);

		/* yellow led is on 3 sec to know people ready to stop */
		SSD_voidCountfromOneToThree();

		/* Yellow LED IS OFF */
		LED_u8LedTurnOff(&LED_YELLOW);


		/* green LED IS ON , red and yellow off */
		LED_u8LedTurnON(&LED_GREEN);

		/* green led is on 15 sec  */
		SSD_voidCountfromOneToFifteen();

		/* Green LED IS OFF */
		LED_u8LedTurnOff(&LED_GREEN);

		SSD_voidDeactiveSSLAndActiveSSDR();


		/* yellow LED IS ON , green and red off */
		LED_u8LedTurnON(&LED_YELLOW);

		SSD_voidCountfromOneToThree();

		/* Yellow LED IS OFF */
		LED_u8LedTurnOff(&LED_YELLOW);

	}
}


void SSD_voidCountfromOneToFifteen(void)
{
	/* Define variables */
	sint32 Local_s32CountI , Local_s32CountJ ;

	/* this loop to count untill 0 to 9 for Red */
	for(Local_s32CountI = 1 ; Local_s32CountI < 10 ;Local_s32CountI++)
	{
		SSD_u8SetNumber(&SSDR_t, Local_s32CountI);
		_delay_ms(1000);

	}
	SSD_u8Display_ON(&SSDL_t);
	/* this loop to count untill 10 to 15 for Red*/
	for(Local_s32CountJ = 0 ; Local_s32CountJ < 6 ;Local_s32CountJ++)
	{
		SSD_u8SetNumber(&SSDL_t,1);
		SSD_u8SetNumber(&SSDR_t,Local_s32CountJ);
		_delay_ms(1000);
	}

}

void SSD_voidCountfromOneToThree(void)
{
	/* Define variables */
	sint32 Local_s32CountI ;

	/* this loop to count untill 0 to 3 for Yellow */
	for(Local_s32CountI = 1 ; Local_s32CountI < 4 ;Local_s32CountI++)
	{
		SSD_u8SetNumber(&SSDR_t, Local_s32CountI);
		_delay_ms(1000);
	}

}

void SSD_voidDeactiveSSLAndActiveSSDR(void)
{
	/* active the right SSD to count untill 9 again */
	SSD_u8Display_ON(&SSDR_t);

	/* deactive the left SSD to save power */
	SSD_u8Display_OFF(&SSDL_t);
}
