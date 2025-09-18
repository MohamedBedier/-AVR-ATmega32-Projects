/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : MCAL
 * @file :  EXTI_Interface.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file Include function's prototypes, any macros ,and any information for the user
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*******************************************/
/*******************************************/
/*******        define macros        *******/
/*******************************************/
/*******************************************/

/**
 * @brief:these are the options of EXTI (INT0,INT1,INT2)
 */
#define   EXTI_u8INT0     0u
#define   EXTI_u8INT1     1u
#define   EXTI_u8INT2     2u

/**
 * @brief: these are the options of sence control
 */
#define   EXTI_u8LOW_LEVEL               0u
#define   EXTI_u8ANY_LOGICAL_CHANGE      1u
#define   EXTI_u8FALLING_EDGE            2u
#define   EXTI_u8RISING_EDGE             3u


#define    EXTI_u8MCUCR_ISC00   0u   /*@brief : Interrupt sense control 0 bit 0 */
#define    EXTI_u8MCUCR_ISC01   1u   /*@brief : Interrupt sense control 0 bit 1 */

#define    EXTI_u8MCUCR_ISC10   2u   /*@brief : Interrupt sense control 1 bit 0 */
#define    EXTI_u8MCUCR_ISC11   3u   /*@brief : Interrupt sense control 1 bit 1 */


#define    EXTI_u8MCUCSR_ISC2   6u /*@brief : Interrupt sense control 2  */


#define    EXTI_u8GICR_INT2      5u /*@brief : INT1 control bit  */
#define    EXTI_u8GICR_INT0      6u /*@brief : INT0 control bit  */
#define    EXTI_u8GICR_INT1      7u /*@brief : INT2 control bit  */



#define    EXTI_u8GIFR_INT2      5u /*@brief : Interrupt sense control 1 bit 0 */
#define    EXTI_u8GIFR_INT0      6u /*@brief : Interrupt sense control 1 bit 0 */
#define    EXTI_u8GIFR_INT1      7u /*@brief : Interrupt sense control 1 bit 0 */


/**
 * @brief: this function is used to initiate INT0
 */
void  EXTI_voidInitInt0(void);

/**
 * @brief: this function is used to initiate INT1
 */
void  EXTI_voidInitInt1(void);

/**
 * @brief: this function is used to initiate INT2
 */
void  EXTI_voidInitInt2(void);


/**
 * @brief : this function is used to change sense control at the run time process
 * @param[in] Copy_u8INT_Select : this variable is used to determine which EXTI you choice
 * @param[in] Copy_u8Sense_Select : this variable is used to determine which sense control selected
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 EXTI_u8SetSenseControl(uint8 Copy_u8INT_Num  ,uint8 Copy_u8Sense);

/**
 * @brief : this function is used to Enable EXTI at the run time process
 * @param[in] Copy_u8IntNum : this variable is used to determine which EXTI you choice
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8  EXTI_u8Enable(uint8 Copy_u8IntNum);

/**
 * @brief : this function is used to Disable EXTI at the run time process
 * @param[in] Copy_u8IntNum : this variable is used to determine which EXTI you choice
 * @return: Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8  EXTI_u8Disable(uint8 Copy_u8IntNum);


/**
 * @brief: this function is used to call back ISR Implementation in the application layer
 * @param Copy_u8IntNum : this variable is used to carry EXTI Number
 * @param Copy_pfFuncPtr : this is a pointer to function which carrying  ISR Implementation address
 * @return : Local_u8ErrorState : this variable to carry error state value [OK or NOK ]
 */
uint8 EXTI_u8SetCallBack(uint8 Copy_u8IntNum , void (*Copy_pfFuncPtr)(void));



#endif /* EXTI_INTERFACE_H_ */
