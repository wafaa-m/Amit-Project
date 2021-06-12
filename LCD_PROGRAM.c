/*
 * LCD_PROGRAM.c
 *
 * Created: 5/30/2021 2:48:30 AM
 *  Author: Wafaa
 */ 
#include "LCD_INTERFACE.h"

/*initialization of LCD*/
void LCD_INIT (void) 
{
	#if LCD_MODE==LCD_4BIT_MODE
	//define direction for control
	DIO_SetPin_Direction(LCD_CNTROL_PORT, LCD_RS, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CNTROL_PORT, LCD_RW, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CNTROL_PORT, LCD_E, LCD_OUTPUT);
	//define direction for data
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_DATA4, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_DATA5, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_DATA6, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DATA_PORT, LCD_DATA7, LCD_OUTPUT);
	//define commands from lcd data sheet
	LCD_WRITE_CMND(0x33); //work in  4bit mode
	LCD_WRITE_CMND(0x32); //work in  4bit mode
	LCD_WRITE_CMND(0x28); //use 4bit mode
	LCD_WRITE_CMND(0x02); //return home
	LCD_WRITE_CMND(0x0C); //display on cursor off
	LCD_WRITE_CMND(0x01); //clear screen
	LCD_WRITE_CMND(0x06); //increment cursor right
	
	
	#elif LCD_MODE==LCD_8BIT_MODE
	
	#else
	#warning "Error mode, try again"
	#endif
}
/*function to send a command to LCD*/
void LCD_WRITE_CMND (U8 command)
{
	//register select pin will select the command register register select (RS logic(0) command)
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_RS,LCD_LOW);
	
	//read write pin will write on lcd read write register
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_RW,LCD_LOW);
	
	//be sure that enable is disabled enable register
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_LOW);
	
	//send high nipple of the command without changing old port A pins(0-3)
	PORTA =(command & 0xf0)|(PORTA&0x0f);
	//send high pulse 1ms
	 DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_HIGH);
	 _delay_ms(1);
	 DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_LOW);
	 
	 //send low nipple of the command without changing old port A pins(0-3)
	 PORTA =(command <<4)|(PORTA&0x0f);
	 //send high pulse 1ms
	 DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_HIGH);
	 _delay_ms(1);
	 DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_LOW);
	 //wait for the control to finish the command
	 _delay_ms(5); 
}

/*function to display a character*/
void LCD_WRITE_DATA (U8 data)
{
	//register select pin will select the data register register select (RS logic(1) data)
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_RS,LCD_HIGH);
	
	//read write pin will write on lcd read write register
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_RW,LCD_LOW);
	
	//be sure that enable is disabled enable register
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_LOW);
	
	//send high nipple of the data without changing old port A pins(0-3)
	PORTA =(data & 0xf0)|(PORTA & 0x0f);
	
	//send high pulse 1ms
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_LOW);
	
	//send low nipple of the data without changing old port A pins(0-3)
	PORTA =(data <<4)|(PORTA & 0x0f);
	
	//send high pulse 1ms
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_HIGH);
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CNTROL_PORT,LCD_E,LCD_LOW);
	//wait for the control to finish the command
	_delay_ms(5);
}

/*using a pointer to integer to read the whole characters of a string and display it on LCD*/
void LCD_WRITE_STRING(U8 * str)
{
	while(* str!='\0')
	{
		LCD_WRITE_DATA(* str);
		_delay_ms(10);
		str++;
	}
}

/*function to write a number*/
void LCD_WRITE_NUMBER(U32 number)
{
	U8 num[10];
	ltoa (number,(U8*)num,10); //long type of array
	LCD_WRITE_STRING(num);
}

/*function to clear the LCD*/
void LCD_CLR(void)
{
	LCD_WRITE_CMND(0x01);
}

/*function to write on the second line*/
void LCD_2ND_LINE (void)
{
	LCD_WRITE_CMND(0xC0);			
}

/*function to write custom character*/
void LCD_WRITE_CSTM_CHR (U8 loc, U8 *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD_WRITE_CMND (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)					/* Write 8 byte for generation of 1 character */
		LCD_WRITE_DATA(msg[i]);
	}
}
