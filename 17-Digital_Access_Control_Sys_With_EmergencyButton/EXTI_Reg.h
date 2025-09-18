/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  EXTI_Reg.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to carry memory map addressess for the DIO Registers
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

/* MCU Control Register */
#define    EXTI_u8MCUCR    *((volatile uint8*)0x55)
/* MCU Control and Status Register */
#define    EXTI_u8MCUCSR   *((volatile uint8*)0x54)
/* General Interrupt Control Register */
#define    EXTI_u8GICR     *((volatile uint8*)0x5B)
/* General Interrupt Flag Register */
#define    EXTI_u8GIFR     *((volatile uint8*)0x5A)




#endif /* EXTI_REG_H_ */
