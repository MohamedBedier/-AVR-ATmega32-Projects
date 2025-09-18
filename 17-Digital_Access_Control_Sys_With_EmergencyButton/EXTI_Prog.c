/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  EXTI_Program.c
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


#include "STD_TYPES.h"
#include "defines.h"
#include "BIT_MATH.h"

#include "EXTI_Reg.h"
#include "EXTI_Cfg.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"



#include "PORT_Interface.h"
#include "DIO_Interfce.h"


/* array of pointer to function to hold ISR callbacks */
static void (*EXTI_pfINTFuncPtr[3]) (void) ={NULL};

/**
 * @brief: this function is used to initiate INT0
 */
void  EXTI_voidInitInt0(void)
{
	/* implement INT0 Sense control configuration */

#if   INT0_SENSE_CTRL == EXTI_u8LOW_LEVEL

	/* The low level of INT0 generates an interrupt request  EXTI_u8MCUCR_ISC00 =0 & EXTI_u8MCUCR_ISC01 = 0*/
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);

#elif   INT0_SENSE_CTRL == EXTI_u8ANY_LOGICAL_CHANGE

	/* Any logical change on INT0 generates an interrupt request  EXTI_u8MCUCR_ISC00 = 1 & EXTI_u8MCUCR_ISC01 = 0 */
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);

#elif   INT0_SENSE_CTRL == EXTI_u8FALLING_EDGE

	/* The falling edge of INT0 generates an interrupt request  EXTI_u8MCUCR_ISC00 = 0 & EXTI_u8MCUCR_ISC01 = 1*/
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);

#elif   INT0_SENSE_CTRL == EXTI_u8RISING_EDGE

	/* The rising edge of INT0 generates an interrupt request  EXTI_u8MCUCR_ISC00 = 1 & EXTI_u8MCUCR_ISC01 = 1*/
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);

#else
#error Wrong INT0_SENSE_CTRL configuration options
#endif

	/* implement INT0_INITIAL_STATE configuration */

#if    INT0_INITIAL_STATE == DISABLED

	CLR_BIT(EXTI_u8GICR,EXTI_u8GICR_INT0);

#elif  INT0_INITIAL_STATE == ENABLED

	SET_BIT(EXTI_u8GICR,EXTI_u8GICR_INT0);

#else
#error Wrong INT0_INITIAL_STATE configuration options
#endif

}

/**
 * @brief: this function is used to initiate INT1
 */
void  EXTI_voidInitInt1(void)
{
	/* implement INT1 Sense control configuration */

#if   INT1_SENSE_CTRL == EXTI_u8LOW_LEVEL

	/* The low level of INT1 generates an interrupt request  EXTI_u8MCUCR_ISC10 =0 & EXTI_u8MCUCR_ISC11 = 0*/
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);

#elif   INT1_SENSE_CTRL == EXTI_u8ANY_LOGICAL_CHANGE

	/* Any logical change on INT1 generates an interrupt request  EXTI_u8MCUCR_ISC10 = 1 & EXTI_u8MCUCR_ISC11 = 0 */
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);

#elif   INT1_SENSE_CTRL == EXTI_u8FALLING_EDGE

	/* The falling edge of INT1 generates an interrupt request  EXTI_u8MCUCR_ISC10 = 0 & EXTI_u8MCUCR_ISC11 = 1*/
	CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);

#elif   INT1_SENSE_CTRL == EXTI_u8RISING_EDGE

	/* The rising edge of INT1 generates an interrupt request  EXTI_u8MCUCR_ISC10 = 1 & EXTI_u8MCUCR_ISC11 = 1*/
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);
	SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);

#else
#error Wrong INT0_SENSE_CTRL configuration options
#endif

	/* implement INT1_INITIAL_STATE configuration */

#if    INT1_INITIAL_STATE == DISABLED

	CLR_BIT(EXTI_u8GICR,EXTI_u8GICR_INT1);

#elif  INT1_INITIAL_STATE == ENABLED

	SET_BIT(EXTI_u8GICR,EXTI_u8GICR_INT1);

#else
#error Wrong INT1_INITIAL_STATE configuration options
#endif
}

/**
 * @brief: this function is used to initiate INT2
 */
void  EXTI_voidInitInt2(void)
{
	/* implement INT2 Sense control configuration */
#if   INT2_SENSE_CTRL == EXTI_u8RISING_EDGE

	/* The rising edge of INT2 generates an interrupt request  EXTI_u8MCUCSR_ISC2= 1*/
	SET_BIT(EXTI_u8MCUCSR,EXTI_u8MCUCSR_ISC2);

#elif   INT2_SENSE_CTRL ==EXTI_u8FALLING_EDGE

	/* The falling edge of INT2 generates an interrupt request EXTI_u8MCUCSR_ISC2= 0*/
	CLR_BIT(EXTI_u8MCUCSR,EXTI_u8MCUCSR_ISC2);

#else
#error Wrong INT2_SENSE_CTRL configuration options
#endif

	/* implement INT2_INITIAL_STATE configuration */

#if    INT2_INITIAL_STATE == DISABLED

	CLR_BIT(EXTI_u8GICR,EXTI_u8GICR_INT2);

#elif  INT2_INITIAL_STATE == ENABLED

	SET_BIT(EXTI_u8GICR,EXTI_u8GICR_INT2);

#else
#error Wrong INT2_INITIAL_STATE configuration options
#endif
}

/**
 * @brief : this function is used to change sense control at the run time process
 * @param[in] Copy_u8INT_Select : this variable is used to determine which EXTI you choice
 * @param[in] Copy_u8Sense_Select : this variable is used to determine which sense control selected
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 EXTI_u8SetSenseControl(uint8 Copy_u8INT_Num  ,uint8 Copy_u8Sense)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState= OK;

	/* check on EXTI number */
	if(Copy_u8INT_Num == EXTI_u8INT0)
	{

		/* check on sense control options for INT0 */
		switch(Copy_u8Sense)
		{
		case EXTI_u8LOW_LEVEL:CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);break;
		case EXTI_u8ANY_LOGICAL_CHANGE:SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);break;
		case EXTI_u8FALLING_EDGE:CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);break;
		case EXTI_u8RISING_EDGE:SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC00);SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC01);break;
		default:Local_u8ErrorState =NOK;break;/* update Error state value  */
		}

	}else if(Copy_u8INT_Num == EXTI_u8INT1)
	{
		/* check on sense control options for INT1 */
		switch(Copy_u8Sense)
		{
		case EXTI_u8LOW_LEVEL:CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);break;
		case EXTI_u8ANY_LOGICAL_CHANGE:SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);break;
		case EXTI_u8FALLING_EDGE:CLR_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);break;
		case EXTI_u8RISING_EDGE:SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC10);SET_BIT(EXTI_u8MCUCR,EXTI_u8MCUCR_ISC11);break;
		default:Local_u8ErrorState =NOK;break;/* update Error state value  */
		}
	}else if(Copy_u8INT_Num == EXTI_u8INT2)
	{
		/* check on sense control options for INT2 */
		switch(Copy_u8Sense)
		{
		case EXTI_u8FALLING_EDGE:CLR_BIT(EXTI_u8MCUCSR,EXTI_u8MCUCSR_ISC2);break;
		case EXTI_u8RISING_EDGE:SET_BIT(EXTI_u8MCUCSR,EXTI_u8MCUCSR_ISC2);break;
		default:Local_u8ErrorState =NOK;break;/* update Error state value  */
		}

	}else
	{
		/* update Error state value  */
		Local_u8ErrorState =NOK;
	}
	return Local_u8ErrorState;
}

/**
 * @brief : this function is used to Enable EXTI at the run time process
 * @param[in] Copy_u8IntNum : this variable is used to determine which EXTI you choice
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8  EXTI_u8Enable(uint8 Copy_u8IntNum)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState= OK;

	/* check on EXTI number */
	switch (Copy_u8IntNum)
	{
	case EXTI_u8INT0:SET_BIT(EXTI_u8GICR,EXTI_u8GICR_INT0);break;
	case EXTI_u8INT1:SET_BIT(EXTI_u8GICR,EXTI_u8GICR_INT1);break;
	case EXTI_u8INT2:SET_BIT(EXTI_u8GICR,EXTI_u8GICR_INT2);break;
	default:Local_u8ErrorState =NOK;break;/* update Error state value  */
	}

	return Local_u8ErrorState;
}

/**
 * @brief : this function is used to Disable EXTI at the run time process
 * @param[in] Copy_u8IntNum : this variable is used to determine which EXTI you choice
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8  EXTI_u8Disable(uint8 Copy_u8IntNum)
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState= OK;

	/* check on EXTI number */
	switch (Copy_u8IntNum)
	{
	case EXTI_u8INT0:CLR_BIT(EXTI_u8GICR,EXTI_u8GICR_INT0);break;
	case EXTI_u8INT1:CLR_BIT(EXTI_u8GICR,EXTI_u8GICR_INT1);break;
	case EXTI_u8INT2:CLR_BIT(EXTI_u8GICR,EXTI_u8GICR_INT2);break;
	default:Local_u8ErrorState =NOK;break;/* update Error state value  */
	}

	return Local_u8ErrorState;
}


/**
 * @brief: this function is used to call back ISR Implementation in the application layer
 * @param Copy_u8IntNum : this variable is used to carry EXTI Number
 * @param Copy_pfFuncPtr : this is a pointer to function which carrying  ISR Implementation address
 * @return : Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 EXTI_u8SetCallBack(uint8 Copy_u8IntNum , void (*Copy_pfFuncPtr)(void))
{
	/* this is a variable to carry Error state value  */
	uint8 Local_u8ErrorState = OK;

	/* check on the value of the pointer NULL or NOT */
	if(Copy_pfFuncPtr != NULL)
	{
		/* assign the address of the function  */
		EXTI_pfINTFuncPtr[Copy_u8IntNum] =Copy_pfFuncPtr;
	}else
	{
		/* update Error state value  */
		Local_u8ErrorState =NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

/* implementation of the ISR */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pfINTFuncPtr[EXTI_u8INT0] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT0]();
	}
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pfINTFuncPtr[EXTI_u8INT1] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT1]();
	}
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pfINTFuncPtr[EXTI_u8INT2] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT2]();
	}
}

