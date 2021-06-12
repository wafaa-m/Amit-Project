/*
 * LED.h
 *
 * Created: 2/6/2021 5:11:01 PM
 *  Author: Wafaa
 */ 


#ifndef LED_H_
#define LED_H_

/*
1- Macros
2- User define data types (if exist){struct,union,enum}
3- Global variables (if exist)
4- Function prototype
*/

#include "LED_CONFIG.h"

//Function prototype
void LED0_Init(void); 
void LED0_ON(void);
void LED0_OFF(void);
void LED0_TGL(void);

void LED1_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED1_TGL(void);

void LED2_Init(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED2_TGL(void);

#endif /* LED_H_ */