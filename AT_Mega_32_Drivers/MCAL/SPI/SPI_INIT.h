/*
 * SPI_INIT.h
 *
 *  Created on: Jan 29, 2023
 *      Author: thund
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_


#include "SPI_REG.h"
#include "SPI_Config.h"

#define SPR0_BIT		0
#define SPR1_BIT		1
#define CPHA_BIT		2
#define CPOL_BIT		3
#define MSTR_BIT		4
#define DORD_BIT		5
#define SPE_BIT			6
#define SPIE_BIT		7

#define SPI2X_BIT		0
#define WCOL_BIT		6
#define SPIF_BIT		7


#define SPI_MSB_TRANSMIT				0x00
#define SPI_LSB_TRANSMIT				0x20



#define SPI_SLAVE				0x00
#define SPI_MASTER				0x10



#define SPI_PRESCALER_4							0x00
#define SPI_PRESCALER_16						0x01
#define SPI_PRESCALER_64						0x02
#define SPI_PRESCALER_128						0x03
#define SPI_HIGH_SPEED_PRESCALER_2				0x04
#define SPI_HIGH_SPEED_PRESCALER_8				0x05
#define SPI_HIGH_SPEED_PRESCALER_32				0x06
#define SPI_HIGH_SPEED_PRESCALER_64				0x07




#define RISING_CLOCK_POL		0x00
#define FALLING_CLOCK_POL		0x08


#define SAMPLING_CLOCK_PHASE		0x00
#define SETUP_CLOCK_PHASE			0x04


void SPI_Master_Init(void);

void SPI_SLAVE_Init(void);

void SPI_MASTER_Slave_SELECTION_ON(void);

void SPI_MASTER_Slave_SELECTION_OFF(void);

void SPI_INT_ENABLE(void);

uint8 SPI_u8_TRANCIEVE_BYTE_POLLING(uint8 u8_Val_Copy);

sint8 SPI_s8_TRANCIEVE_BYTE_POLLING(sint8 s8_Val_Copy);

void SPI_u8_Send_STRING_POLLING(const uint8* u8_Str_Copy);



#endif /* MCAL_SPI_SPI_INIT_H_ */
