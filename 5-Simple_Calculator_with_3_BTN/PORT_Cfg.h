/*************************************************************/
/*************************************************************/
/**                                                         **/
/**  LayerArchitecture : MCAL                               **/
/** File Name : PORT_Cfg.h                                  **/
/** Auther    : MOHAMED BEDIER MOHAMED                      **/
/** Verision :  1.00                                        **/
/**                                                         **/
/*************************************************************/
/*************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/* Configre pins direction , options  : 1- INPUT
 	 	 	 		 	 	 	 	 	2- OUTPUT*/

/* Set CTRL pins :  RS , RW , E ON PortA pins 0 , 1 , 2  as OUTPUT*/
#define  PORTA_PIN0_DIR    OUTPUT
#define  PORTA_PIN1_DIR    OUTPUT
#define  PORTA_PIN2_DIR    OUTPUT
#define  PORTA_PIN3_DIR    OUTPUT
#define  PORTA_PIN4_DIR    OUTPUT
#define  PORTA_PIN5_DIR    OUTPUT
#define  PORTA_PIN6_DIR    OUTPUT
#define  PORTA_PIN7_DIR    OUTPUT

/* we are going to use 3 buttons and they are defineded as input on PORTB pin 0 , 1 ,2 */
#define  PORTB_PIN0_DIR    OUTPUT
#define  PORTB_PIN1_DIR    OUTPUT
#define  PORTB_PIN2_DIR    OUTPUT
#define  PORTB_PIN3_DIR    INPUT
#define  PORTB_PIN4_DIR    INPUT
#define  PORTB_PIN5_DIR    INPUT
#define  PORTB_PIN6_DIR    INPUT
#define  PORTB_PIN7_DIR    INPUT

/* we work as EIGHT_BIT_MODE , and use PORTC for data as OUTPUT */
#define  PORTC_PIN0_DIR    OUTPUT
#define  PORTC_PIN1_DIR    OUTPUT
#define  PORTC_PIN2_DIR    OUTPUT
#define  PORTC_PIN3_DIR    OUTPUT
#define  PORTC_PIN4_DIR    OUTPUT
#define  PORTC_PIN5_DIR    OUTPUT
#define  PORTC_PIN6_DIR    OUTPUT
#define  PORTC_PIN7_DIR    OUTPUT



#define  PORTD_PIN0_DIR    INPUT
#define  PORTD_PIN1_DIR    INPUT
#define  PORTD_PIN2_DIR    INPUT
#define  PORTD_PIN3_DIR    INPUT
#define  PORTD_PIN4_DIR    INPUT
#define  PORTD_PIN5_DIR    INPUT
#define  PORTD_PIN6_DIR    INPUT
#define  PORTD_PIN7_DIR    INPUT


/* Configure the initial value , options for input pin :   1- FLOATING
 	 	 	 	 	 	 	 	 	 	 	 	 	 	   2- PULLED_UP

 	 	 	 	 	 	 	 	 options for output pin :  1- LOW
 	 	 	 	 	 	 	 	 	 	 	 	 	 	   2- HIGH
 	 	 	 	 	 	 	 	 	 	 	 	 	 	    	 	 	 	 */

#define  PORTA_PIN0_INITIAL_VAL    HIGH
#define  PORTA_PIN1_INITIAL_VAL    HIGH
#define  PORTA_PIN2_INITIAL_VAL    HIGH
#define  PORTA_PIN3_INITIAL_VAL    HIGH
#define  PORTA_PIN4_INITIAL_VAL    HIGH
#define  PORTA_PIN5_INITIAL_VAL    HIGH
#define  PORTA_PIN6_INITIAL_VAL    HIGH
#define  PORTA_PIN7_INITIAL_VAL    HIGH

/* ACTIVE Internal pullup resistance on PORTB  pins 0 , 1 , 2 */
#define  PORTB_PIN0_INITIAL_VAL    HIGH
#define  PORTB_PIN1_INITIAL_VAL    HIGH
#define  PORTB_PIN2_INITIAL_VAL    HIGH
#define  PORTB_PIN3_INITIAL_VAL    HIGH
#define  PORTB_PIN4_INITIAL_VAL    HIGH
#define  PORTB_PIN5_INITIAL_VAL    HIGH
#define  PORTB_PIN6_INITIAL_VAL    HIGH
#define  PORTB_PIN7_INITIAL_VAL    HIGH



#define  PORTC_PIN0_INITIAL_VAL    FLOATING
#define  PORTC_PIN1_INITIAL_VAL    FLOATING
#define  PORTC_PIN2_INITIAL_VAL    FLOATING
#define  PORTC_PIN3_INITIAL_VAL    FLOATING
#define  PORTC_PIN4_INITIAL_VAL    FLOATING
#define  PORTC_PIN5_INITIAL_VAL    FLOATING
#define  PORTC_PIN6_INITIAL_VAL    FLOATING
#define  PORTC_PIN7_INITIAL_VAL    FLOATING



#define  PORTD_PIN0_INITIAL_VAL    PULLED_UP
#define  PORTD_PIN1_INITIAL_VAL    PULLED_UP
#define  PORTD_PIN2_INITIAL_VAL    PULLED_UP
#define  PORTD_PIN3_INITIAL_VAL    PULLED_UP
#define  PORTD_PIN4_INITIAL_VAL    PULLED_UP
#define  PORTD_PIN5_INITIAL_VAL    PULLED_UP
#define  PORTD_PIN6_INITIAL_VAL    PULLED_UP
#define  PORTD_PIN7_INITIAL_VAL    PULLED_UP




#endif /* PORT_CFG_H_ */
