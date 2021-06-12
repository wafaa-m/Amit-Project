/*
 * BUZZER.c
 *
 * Created: 2/15/2021 1:12:44 PM
 *  Author: Wafaa
 */ 
#include "BUZZER.h"
/*Initialize portA and pin3 to be output for the buzzer*/

void BUZZER_INIT(void)
{
	DIO_SetPin_Direction(BUZZER_PORT,BUZZER_PIN,DIO_PIN_OUTPUT);
}
/*Activate buzzer function*/
void BUZZER_ON(void)
{
	DIO_SetPin_Value(BUZZER_PORT,BUZZER_PIN,BUZZER_HIGH);
}

/*Deactivate buzzer function*/
void BUZZER_OFF(void)
{
	DIO_SetPin_Value(BUZZER_PORT,BUZZER_PIN,BUZZER_LOW);
}