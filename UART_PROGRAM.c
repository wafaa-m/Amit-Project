/*
 * UART_PROGRAM.c
 *
 * Created: 5/30/2021 4:27:53 AM
 *  Author: Wafaa
 */ 

#include "UART_INTERFACE.h"

/*Resiting UART Control and Status Register B–UCSRB*/
void UART_Reset(void)
{
	CLR_BIT(UCSRB,RXEN);
	_delay_ms(50);
	SET_BIT(UCSRB,RXEN);
}

void UART_Init(void)
{		
	/*Enable Transmitter and Receiver bits*/
	UCSRB = (1 << RXEN) | (1 << TXEN);
	
	/*Full configuration for UART*/
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0) ;
	
	/*Baud rate value variable*/
	U16 UBRR_Val = 0;
	/*Baud Rate Calculations*/
	UBRR_Val = ((((U32)FRQ) / ((U32)16 * BAUDRATE)) - 1);   //00000000 11110101 00111001
	UBRRH = 0;      //0000 0000
	UBRRL = 103;    //0011 0011
}

void UART_Transmit(U8 data)
{
	while(GET_BIT(UCSRA, UDRE) != 1);
	UDR = data;
}
U8 UART_Receive(void)
{
	while(GET_BIT(UCSRA, RXC) != 1);
	return UDR;
}
void UART_Transmit_Str(U8* str)
{
	while (*str != '\0')
	{
		UART_Transmit(*str);
		str++;
	}
}
U8* UART_Receive_Str(void)
{
	static U8* str;
	while (UART_Receive() != '\0')
	{
		*str = UART_Receive();
		str++;
	}
	return str;
}
