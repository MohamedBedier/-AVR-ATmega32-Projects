/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  HAL
 * @file :  DAC_Cfg.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file is used if we build the driver as pre-build configuration
 *		    ,the user must define any requirements in this file before the compilation process
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */
#ifndef DAC_CFG_H_
#define DAC_CFG_H_

#define  DAC_u8PORT            DIO_u8PORTB

#define  DAC_u8Resolution      8u

#define  MC_u8MaxVolt          5.0

#endif /* DAC_CFG_H_ */
