/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : APP
 * @file :  DACS_APP.h
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

#ifndef DACS_APP_H_
#define DACS_APP_H_



#define   INITIAL_ZERO_VAL          0u


/**
 * @brief: this is a function used to initiate the pins of KPD,CLCD,SSD and put the initial state of them
 * @param[in]: void ==> this function dosen't take any argument
 * @return: void ==> this function dosen't return anything
 */
void DACS_voidInitSys(SSD_Config_t *Copy_PS_SSD_t);

/**
 * @brief: this is a function used to shut down all system
 * @param[in]: Copy_PS_SSD_Config ==> this function take a struct of SSD
 * @return: void ==> this function dosen't return anything
 */
void DACS_SystemShutDown(SSD_Config_t *Copy_PS_SSD_Config);

/**
 * @brief: this is a function used to know the user access to the system successfully
 * @param[in]: pointer from the led struct
 * @return: void ==> this function dosen't return anything
 */
void DACS_System_ON(LED_Config_t *Copy_PsLED_Config);

/**
 * @brief: this is a function used to AskAndTakeUserIdThenCheckIsValid ===>
 * the system will start with ask the user On CLCD to enter Id then checking on the Id
 * if ID valid ==> ask Password else shutdown the system
 * @param[in]: void ==> this function dosen't take any argument
 * @return: Local_u32IDFourDigits == > This is a four digits of user id
 */
uint32 AskAndTakeUserIdThenCheckIsValid(SSD_Config_t *Copy_PS_SSD_Config);


/**
 * @brief: this is a function used to AskAndTakeUserPassWordThenCheckIsValid ===>
 * if ID valid ==> ask Password if the password is correct from the first time enter the system and show on CLCD
 * Access granted and green led is on , else user has 3 time to enter the password if the password is correct at anytime from 3 times
 * enter the system and show on CLCD Access granted and green led is on, if the three time is finished else shutdown the system
 * @param[in]: void ==> this function dosen't take any argument
 * @return: Local_u32PassWordFourDigits == > This is a four digits of user PassWord
 */
uint32 AskAndTakeUserPassWordThenCheckIsValid(void);

void AskAndTakeUserPassWord_ThreeTimes_ThenCheckIsValid(SSD_Config_t *Copy_PS_SSD_Config ,LED_Config_t *Copy_PsLED_Config );

#endif /* DACS_APP_H_ */
