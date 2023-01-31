/*
 * dio_cfg.h
 *
 *  Created on: Dec 23, 2022
 *      Author: thund
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#include "../../SERV/stdtypes.h"

//Ports Configurations

#define PORT_A		0
#define PORT_B		1
#define PORT_C		2
#define PORT_D		3

//Pins Configurations


#define PIN_0		0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_4		4
#define PIN_5		5
#define PIN_6		6
#define PIN_7		7


//Direction  Either Input or Output

#define INPUT		0
#define OUTPUT		1

//Direction for a Full PORT
#define FULL_INPUT	0x00
#define FULL_OUTPUT	0xFF

//OUTPUT VALUE

#define LOW			0
#define HIGH		1
#define ALL_LOW		0x00
#define ALL_HIGH	0xFF


#define PUE			1

#define E_OK		0
#define E_NOK		1




/*************************SET/Get PORT *************************/

uint8 DIO_u8Set_Port_Dir(uint8 u8PortIdCopy , uint8 	u8DirCopy		);
uint8 DIO_u8Set_Port_Val(uint8 u8PortIdCopy , uint8 	u8ValCopy		);
uint8 DIO_u8Get_Port_Val(uint8 u8PortIdCopy , uint8 * 	u8pValCopy		);
uint8 DIO_u8TOG_PORT_Val (uint8  u8PortIdCopy );


/*************************SET/GET Pins*************************/


uint8 DIO_u8Set_Pin_Dir(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8   u8DirCopy);
uint8 DIO_u8Set_Pin_Val(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8   u8ValCopy);
uint8 DIO_u8Get_Pin_Val(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8 * u8pValCopy);
uint8 DIO_u8TOG_Pin_Val(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy );







#endif /* MCAL_DIO_DIO_INT_H_ */
