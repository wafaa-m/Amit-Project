#include "DIO_INTERFACE.h"

//DIRECTION OF PIN AND PORT = INPUT , OUTPUT
void DIO_SetPin_Direction(U8 PORTID, U8 PINID, U8 DIRECTION)
{
	if(DIRECTION == DIO_PIN_OUTPUT)
	{
		switch (PORTID)
		{
			case DIO_PORTA:  SET_BIT(DDRA, PINID);   break;
			case DIO_PORTB:  SET_BIT(DDRB, PINID);   break;								
			case DIO_PORTC:  SET_BIT(DDRC, PINID);   break;							
			case DIO_PORTD:  SET_BIT(DDRD, PINID);   break;
		}
	}
	else if(DIRECTION == DIO_PIN_INPUT)
	{
		switch (PORTID)
		{
			case DIO_PORTA:  CLR_BIT(DDRA, PINID);  break;
			case DIO_PORTB:  CLR_BIT(DDRB, PINID);  break;
			case DIO_PORTC:  CLR_BIT(DDRC, PINID);  break;
			case DIO_PORTD:  CLR_BIT(DDRD, PINID);  break;
		}
		
	}
}

void DIO_SetPort_Direction(U8 PORTID, U8 DIRECTION)
{
	switch(DIRECTION)
	{
		case DIO_PORT_INPUT:
		switch(PORTID)
		{
			case DIO_PORTA:  DDRA = DIO_PORT_INPUT;  break;
			case DIO_PORTB:  DDRB = DIO_PORT_INPUT;  break;
			case DIO_PORTC:  DDRC = DIO_PORT_INPUT;  break;
			case DIO_PORTD:  DDRD = DIO_PORT_INPUT;  break;
		}
		break;
		case DIO_PORT_OUTPUT:
		switch(PORTID)
		{
			case DIO_PORTA:  DDRA = DIO_PORT_OUTPUT;  break;
			case DIO_PORTB:  DDRB = DIO_PORT_OUTPUT;  break;
			case DIO_PORTC:  DDRC = DIO_PORT_OUTPUT;  break;
			case DIO_PORTD:  DDRD = DIO_PORT_OUTPUT;  break;
		}
		break;
	}
}

//SET PIN AND PORT VALUE= HIGH, LOW
void DIO_SetPin_Value(U8 PORTID, U8 PINID, U8 VALUE)
{
	if (VALUE== DIO_PIN_HIGH)
	{
		switch (PORTID)
		{
			case DIO_PORTA: SET_BIT(PORTA, PINID); break;
			case DIO_PORTB: SET_BIT(PORTB, PINID); break;
			case DIO_PORTC: SET_BIT(PORTC, PINID); break;
			case DIO_PORTD: SET_BIT(PORTD, PINID); break;
		}
	}
	else if (VALUE == DIO_PIN_LOW)
	{
		switch (PORTID)
		{
			case DIO_PORTA:  CLR_BIT(PORTA, PINID); break;
			case DIO_PORTB:  CLR_BIT(PORTB, PINID); break;
			case DIO_PORTC:  CLR_BIT(PORTC, PINID);  break;
			case DIO_PORTD:  CLR_BIT(PORTD, PINID);  break;
		}
	}
}

void DIO_SetPort_Value(U8 PORTID , U8 VALUE)
{
	switch(VALUE)
	{
		case DIO_PORT_LOW:
		switch(PORTID)
		{
			case DIO_PORTA:  PORTA= DIO_PORT_INPUT;  break;
			case DIO_PORTB:  PORTB= DIO_PORT_INPUT;  break;
			case DIO_PORTC:  PORTC= DIO_PORT_INPUT;  break;
			case DIO_PORTD:  PORTD= DIO_PORT_INPUT;  break;
		}
		break;
		case DIO_PORT_HIGH:
		switch(PORTID)
		{
			case DIO_PORTA:  PORTA= DIO_PORT_OUTPUT;  break;
			case DIO_PORTB:  PORTB= DIO_PORT_OUTPUT;  break;
			case DIO_PORTC:  PORTC= DIO_PORT_OUTPUT;  break;
			case DIO_PORTD:  PORTD= DIO_PORT_OUTPUT;  break;
		}
		break;
	}
}

//READ PIN AND PORT VALUE

U8 DIO_ReadPin_Value(U8 PORTID,U8 PINID)
{
	U8 local_u8data= 0xFF;
	switch (PORTID)
	{
		case DIO_PORTA: local_u8data= GET_BIT(PINA, PINID); break;					
		case DIO_PORTB: local_u8data= GET_BIT(PINB, PINID); break;				
		case DIO_PORTC: local_u8data= GET_BIT(PINC, PINID); break;				
		case DIO_PORTD: local_u8data= GET_BIT(PIND, PINID); break;
	}
	return local_u8data;
}

U8 DIO_ReadPort_Value(U8 PORTID)
{
	U8 val = 0;
	switch(PORTID)
	{
		case DIO_PORTA:  val = PINA;  break;
		case DIO_PORTB:  val = PINB;  break;
		case DIO_PORTC:  val = PINC;  break;
		case DIO_PORTD:  val = PIND;  break;
	}
	return val;
}

// PORT AND PIN TOGGLE 
void DIO_TogglPIN(U8 PORTID , U8 PINID)
{
	switch (PORTID)
	{
		case DIO_PORTA: TGL_BIT(PORTA, PINID); break;
		case DIO_PORTB: TGL_BIT(PORTB, PINID); break;
		case DIO_PORTC: TGL_BIT(PORTC, PINID); break;
		case DIO_PORTD: TGL_BIT(PORTD, PINID); break;
	}

}

void DIO_TogglPort(U8 PORTID)
{
	switch(PORTID)
	{
		case DIO_PORTA:  PORTA ^= DIO_PORT_HIGH;  break;
		case DIO_PORTB:  PORTB ^= DIO_PORT_HIGH;  break;
		case DIO_PORTC:  PORTC ^= DIO_PORT_HIGH;  break;
		case DIO_PORTD:  PORTD ^= DIO_PORT_HIGH;  break;
	}
}

//PULL UP RESISTOR 
void DIO_SetPullUpRes(U8 PORTID , U8 PINID)
{
	switch(PORTID)
	{
		case DIO_PORTA : SET_BIT(PORTA,PINID); break;
		case DIO_PORTB : SET_BIT(PORTB,PINID); break;
		case DIO_PORTC : SET_BIT(PORTC,PINID); break;
		case DIO_PORTD : SET_BIT(PORTD,PINID); break;
		default:  break;
	}

}
