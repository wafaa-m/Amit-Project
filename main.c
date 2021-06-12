/*
 * Transmitter.c
 *
 * Created: 6/7/2021 1:47:09 AM
 * Author : Wafaa
 */ 

#include "LCD_INTERFACE.h"
#include "LED_INTERFACE.h"

#include "UART_INTERFACE.h"
#include "SPI_INTERFACE.h"

#include "BUZZER.h"

U8 volatile TX=0;
U8 volatile RX=0;

int main (void)
{
	UART_Init();
	LED0_Init();
	LED1_Init();
	LED2_Init();
	LCD_INIT();
	SPI_MASTER_Init();
	SPI_SlaveSelect(0);
	BUZZER_INIT();
	
	LCD_WRITE_STRING((U8*)"WELCOM");
	_delay_ms(1000);
	LCD_CLR();
	LCD_WRITE_STRING((U8*)"Enter 1 for OPEN");
	LCD_2ND_LINE();
	LCD_WRITE_STRING((U8*)"or 2 for CLOSE");
	
	while(1)
	{
		RX = UART_Receive();
		
		if( RX == '1')
		{
			UART_Reset();
			LCD_CLR();
			TX=RX;
			LCD_WRITE_STRING((U8*)"Sending 1...");
			LCD_2ND_LINE();
			LCD_WRITE_STRING((U8*)"Door opening");
			LED0_ON();
			_delay_ms(500);
			LED0_OFF();
			SPI_Transmit(TX);
		}
		else if (RX== '2')
		{
			UART_Reset();
			LCD_CLR();
			TX=RX;
			LCD_WRITE_STRING((U8*)"Sending 2...");
			LCD_2ND_LINE();
			LCD_WRITE_STRING((U8*)"Door closing");
			LED1_ON();
			_delay_ms(500);
			LED1_OFF();
			SPI_Transmit(TX);
		}
		else if (RX!='1' && RX!='2')
		{
			UART_Reset();
			LCD_CLR();
			TX=RX;
			SPI_Transmit(TX);
			LED2_ON();
			BUZZER_ON();
			LCD_WRITE_STRING((U8*)"You entered");
			LCD_2ND_LINE();
			LCD_WRITE_STRING((U8*)" wrong value");
			_delay_ms(1000);
			
			LED2_OFF();
			BUZZER_OFF();
			LCD_CLR();
			LCD_WRITE_STRING((U8*)"Enter 1 for OPEN");
			LCD_2ND_LINE();
			LCD_WRITE_STRING((U8*)"or 2 for CLOSE");
		}
		_delay_ms(500);
	}
}
