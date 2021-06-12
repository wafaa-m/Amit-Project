/*
 * LCD_INTERFACE.h
 *
 * Created: 5/30/2021 2:48:13 AM
 *  Author: Wafaa
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_CONFIG.h"

void LCD_INIT (void);
void LCD_WRITE_CMND (U8 command);
void LCD_WRITE_DATA (U8 data);

void LCD_CLR(void);
void LCD_2ND_LINE (void);

void LCD_WRITE_STRING(U8 * string); //define the string using pointer as it is an array of characters
void LCD_WRITE_NUMBER(U32 number);

void LCD_WRITE_CSTM_CHR (U8 loc, U8 *msg);






#endif /* LCD_INTERFACE_H_ */