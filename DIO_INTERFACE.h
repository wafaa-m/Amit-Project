#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_CONFIG.h"

/*proto types*/

//PIN DIRECTION AND VALUE
void DIO_SetPin_Direction(U8 PORTID, U8 PINID, U8 DIRECTION);
void DIO_SetPin_Value(U8 PORTID, U8 PINID, U8 VALUE);
void DIO_TogglPIN(U8 PORTID, U8 PINID);
U8 DIO_ReadPin_Value(U8 PORTID , U8 PINID);


//PORT DIRECTION AND VALUE
void DIO_SetPort_Direction(U8 PORTID, U8 DIRECTION);
void DIO_SetPort_Value(U8 PORTID , U8 VALUE);
void DIO_TogglPORT(U8 PORTID);
U8 DIO_ReadPort_Value(U8 PORTID);

void DIO_SetPullUpRes(U8 PORTID , U8 PINID);



#endif