/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : MCAL
 * @file :  GIE_Interface.h
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
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/**
 * @brief : this function to open global interrupt
 */
void   GIE_u8GIE_Enabled(void);

/**
 * @brief : this function to close global interrupt
 */
void   GIE_u8GIE_Disable(void);

#endif /* GIE_INTERFACE_H_ */
