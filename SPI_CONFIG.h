/*
 * SPI_CONFIG.h
 *
 * Created: 5/30/2021 4:33:07 AM
 *  Author: Wafaa
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "CPU_CONFIGRATIONS.h"

/*define status*/
#define MASTER     1
#define SLAVE      0

/*renaming control pins*/
#define SS         DIO_PIN4
#define MOSI       DIO_PIN5
#define MISO       DIO_PIN6
#define CLK        DIO_PIN7

/*define SPI port*/
#define SPI_PORT DDRB

//#define SPI_MODE SLAVE using enum
typedef enum
{
	SPI_NOK=0,
	SPI_OK=1
}SPI_STATUS;

#endif /* SPI_CONFIG_H_ */