/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  GIE_Private.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used to hide any thing from the user
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */
#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_

/* this is a macro to define (bit7 = I) in SREG register to enable or disable GIE  */
#define  GIE_u8SREG_I    7u



#endif /* GIE_PRIVATE_H_ */
