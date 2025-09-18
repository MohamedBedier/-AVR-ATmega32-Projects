/*************************************************************
 *************************************************************
 *
 * @LayerArchitecture:  MCAL
 * @file :  EXTI_Cfg.h
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

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_


/**
 *   @details configure the INT0 sense control, options are :
 * 						                              1- EXTI_u8LOW_LEVEL
 * 						                              2- EXTI_u8ANY_LOGICAL_CHANGE
 * 						                              3- EXTI_u8FALLING_EDGE
 * 						                              4- EXTI_u8RISING_EDGE
*/

#define    INT0_SENSE_CTRL   EXTI_u8FALLING_EDGE


/**
 * @details configure the INT0 initial state , options are :
 * 						                               1-ENABLED
 * 						                               2-DISABLED
 */

#define    INT0_INITIAL_STATE    ENABLED





/**
 *   @details configure the INT1 sense control, options are :
 * 						                              1-EXTI_u8RISING_EDGE
 * 						                              2-EXTI_u8FALLING_EDGE
 * 						                              3-EXTI_u8ANY_LOGICAL_CHANGE
 * 						                              4-EXTI_u8LOW_LEVEL
*/

#define    INT1_SENSE_CTRL   EXTI_u8FALLING_EDGE


/**
 * @details configure the INT1 initial state , options are :
 * 						                               1-ENABLED
 * 						                               2-DISABLED
 */

#define    INT1_INITIAL_STATE    DISABLED


/**
 *   @details configure the INT2 sense control, options are :
 * 						                              1-EXTI_u8RISING_EDGE
 * 						                              2-EXTI_u8FALLING_EDGE
*/

#define    INT2_SENSE_CTRL   EXTI_u8FALLING_EDGE


/**
 * @details configure the INT2 initial state , options are :
 * 						                               1-ENABLED
 * 						                               2-DISABLED
 */

#define    INT2_INITIAL_STATE    DISABLED








#endif /* EXTI_CFG_H_ */
