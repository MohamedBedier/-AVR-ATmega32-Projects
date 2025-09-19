/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : HAL                                **/
/** File Name : DAC_Driver                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "PORT_Interface.h"
#include "CLCD_interface.h"
#include "DIO_Interfce.h"
#include "DAC_Interface.h"

#include <util/delay.h>

int main()
{
	PORT_voidInit();
	f32 Local_f32Counter_I ;
	f32 Local_f32Counter_J ;


	while(1)
	{
		for(Local_f32Counter_I = 0.0 ; Local_f32Counter_I < 5.0 ;Local_f32Counter_I = Local_f32Counter_I + 0.1)
		{
			DAC_voidSetAnalogVolt(Local_f32Counter_I);
			_delay_ms(50);
		}
		for(Local_f32Counter_J = 5.0 ; Local_f32Counter_J >= 0.0 ;Local_f32Counter_J = Local_f32Counter_J - 0.1)
		{
			DAC_voidSetAnalogVolt(Local_f32Counter_J);
			_delay_ms(50);
		}

	}
}
