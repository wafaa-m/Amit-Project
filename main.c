/*
 * Receiver.c
 *
 * Created: 6/8/2021 1:28:43 AM
 * Author : Wafaa
 */ 

#include <avr/io.h>

#include "LED_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "SPI_INTERFACE.h"
#include "MOTOR_INTERFACE.h"

U8 volatile RX;

int main(void)
{	
   SPI_SLAVE_INIT();
   LED0_Init();
   LED1_Init();
   LED2_Init();
    LCD_INIT();
   MOTOR1_INIT();
 
   while(1)
   {
		  RX=SPI_Receive();
		   if (RX == '1')
		   {
			   LCD_CLR();
			   LED1_OFF();
			   LED2_OFF();
			   LED0_ON();
			   LCD_WRITE_STRING((U8*)"Door is opening");
			   MOTOR1_ENABLE();
			   MOTOR1_CW();
			   _delay_ms(2000);
			   MOTOR1_DISABLE();
			   LED0_OFF();
		   }
		   else if (RX =='2')
		   {
			   MOTOR1_DISABLE();
			   LCD_CLR();
			   LED0_OFF();
			   LED2_OFF();
			   LED1_ON();
			   LCD_WRITE_STRING((U8*)"Door is closing");
			   MOTOR1_ENABLE();
			   MOTOR1_CCW();
			   _delay_ms(2000);
			   MOTOR1_DISABLE();
			   LED1_OFF();
		   }
		  else if(RX!='1' && RX!='2')
		   {
			   MOTOR1_DISABLE();
			   LED0_OFF();     
			   LED1_OFF();         
			   LCD_CLR();
			   
			   LED2_ON();
			   LCD_WRITE_STRING((U8*)"Wrong value");
			   LCD_2ND_LINE();
			   LCD_WRITE_STRING((U8*)"enter valid one");
			   _delay_ms(1000);
			   LED2_OFF();
			   LCD_CLR();
		   }
		   _delay_ms(500);
	   }
	  
   return 0 ;
}