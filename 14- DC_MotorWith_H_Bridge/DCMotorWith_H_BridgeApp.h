/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : APP
 * @file :  DCMotorWith_H_BridgeApp.h
 * @author: MOHAMED BEDIER MOHAMED
 * @brief:  this file Include function's prototypes, any macros ,and any information about application
 *          this file is created by the user
 * @version:  1.00
 *
 *************************************************************
 *************************************************************/

/**  this is a preprocessor directives commonly used to create "include guards" in header files.
 *   These guards prevent the contents of a header file from being included multiple times
 *   during compilation, which can lead to redefinition errors.
 */
#ifndef DCMOTORWITH_H_BRIDGEAPP_H_
#define DCMOTORWITH_H_BRIDGEAPP_H_


/**
 * @brief this function is used to Stop DC MOTOR in app layer and write on CLCD DC M STOP
 * @param Copy_PS_DC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMotorAPP_u8DCStop(DC_Motor_t  *Copy_PS_DC_Motor);

/**
 * @brief this function is used to Rotate Counter ClockWise DC MOTOR in app layer and write on CLCD DC M Rotate CW
 * @param Copy_PS_DC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMotorAPP_u8DCRotateCounterClockWise(DC_Motor_t  *Copy_PS_DC_Motor);

/**
 * @brief this function is used to Rotate Counter ClockWise DC MOTOR in app layer and write on CLCD DC M Rotate CW
 * @param Copy_PS_DC_Motor : this is a pointer from the configuration structure for the DC motor
 * @return Local_u8ErrorState : this is a variable used to carry error state value
 */
uint8 DCMotorAPP_u8DCRotateClockWise(DC_Motor_t  *Copy_PS_DC_Motor);



#endif /* DCMOTORWITH_H_BRIDGEAPP_H_ */
