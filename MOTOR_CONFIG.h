/*
 * MOTOR_CONFIG.h
 *
 * Created: 5/30/2021 4:00:40 AM
 *  Author: Wafaa
 */ 

/*
1- Macros
2- Renaming port names
3- Renaming pin names
4- Renaming status
*/

#ifndef MOTOR_CONFIG_H_
#define MOTOR_CONFIG_H_

#include "CPU_CONFIGRATIONS.h"

//define ports
#define MOTOR_CTRL_PORT   DIO_PORTD
#define MOTOR_DATA_PORT   DIO_PORTC

//define control pins
#define MOTOR_EN1        DIO_PIN4
#define MOTOR_EN2        DIO_PIN5

//define data pins
#define MOTOR1_A1        DIO_PIN3
#define MOTOR1_A2        DIO_PIN4
#define MOTOR1_A3        DIO_PIN5
#define MOTOR1_A4        DIO_PIN6

//define status
#define MOTOR_LOW        DIO_PIN_LOW
#define MOTOR_HIGH       DIO_PIN_HIGH
#define MOTOR_OUTPUT     DIO_PIN_OUTPUT

#endif /* MOTOR_CONFIG_H_ */