/*
 * LED_CONFIG.h
 *
 * Created: 2/6/2021 5:10:42 PM
 *  Author: Wafaa
 */ 


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
/*
1- Macros
2- Renaming port names
3- Renaming pin names
4- Renaming status
*/

#include "CPU_CONFIGRATIONS.h"


#define LED0_PORT      DIO_PORTC                  //naming port
#define LED0_PIN       DIO_PIN2                   //naming pin
#define LED0_OUTPUT    DIO_PIN_OUTPUT             //define direction
#define LED0_HIGH      DIO_PIN_HIGH               //status
#define LED0_LOW       DIO_PIN_LOW                //status

#define LED1_PORT      DIO_PORTC                  //naming port
#define LED1_PIN       DIO_PIN7                   //naming pin
#define LED1_OUTPUT    DIO_PIN_OUTPUT             //define direction
#define LED1_HIGH      DIO_PIN_HIGH               //status
#define LED1_LOW       DIO_PIN_LOW                //status

#define LED2_PORT      DIO_PORTD                 //naming port
#define LED2_PIN       DIO_PIN3                  //naming pin
#define LED2_OUTPUT    DIO_PIN_OUTPUT            //define direction
#define LED2_HIGH      DIO_PIN_HIGH              //status
#define LED2_LOW       DIO_PIN_LOW               //status
 


#endif /* LED_CONFIG_H_ */