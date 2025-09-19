/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : HAL
 * @file :  DAC_Interface.h
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
#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_

/**
 * @brief this function to convert digital signal to analog signal
 * @param Copy_u16Volt : this is the analog volt
 */
void DAC_voidSetAnalogVolt(f32 Copy_uf32Volt);

#endif /* DAC_INTERFACE_H_ */
