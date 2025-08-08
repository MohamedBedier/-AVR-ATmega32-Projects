/*************************************************************
 *************************************************************
 *
 * @layerArchitecture : APP
 * @file :  Traffic_Light_APP.h
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
 

#ifndef TRAFFIC_LIGHT_APP_H_
#define TRAFFIC_LIGHT_APP_H_

/**
 * @brief: this function is used to count from 1 to 15 in case of red and green
 * @param Copy_RightSSD : this is a pointer of struct from the configuration struct for Right SSD
 * @param Copy_LeftSSD : this is a pointer of struct from the configuration struct for Left SSD
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8CountfromOneToFifteen(SSD_Config_t *Copy_RightSSD,SSD_Config_t *Copy_LeftSSD);

/**
 * @brief: this function is used to count from 1 to 3 in case of yellow
 * @param Copy_RightSSD : this is a pointer of struct from the configuration struct for Right SSD
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8CountfromOneToThree(SSD_Config_t *Copy_RightSSD);

/**
 * @brief: this function is used to Deactive left SSD And Active right SSD
 * @param Copy_RightSSD : this is a pointer of struct from the configuration struct for Right SSD
 * @param Copy_LeftSSD : this is a pointer of struct from the configuration struct for Left SSD
 * @return : Local_u8ErrorState : this variable to carry error state value
 */
uint8 SSD_u8DeactiveSSDLAndActiveSSDR(SSD_Config_t *Copy_RightSSD,SSD_Config_t *Copy_LeftSSD);

#endif /* TRAFFIC_LIGHT_APP_H_ */
