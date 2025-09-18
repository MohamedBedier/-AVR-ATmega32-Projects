/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  GIE_Reg.h
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
#ifndef GIE_REG_H_
#define GIE_REG_H_

/* Global interrupt Register(GIE) */
#define    GIE_u8SREG     *((volatile uint8*)0x5f)

#endif /* GIE_REG_H_ */
