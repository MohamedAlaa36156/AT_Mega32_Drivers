/*
 * SPI_INIT.c
 *
 *  Created on: Jan 29, 2023
 *      Author: thund
 */
#include "../../SERV/bit_math.h"
#include "../../SERV/stdtypes.h"
#include "SPI_INIT.h"
#include "../DIO/dio_int.h"
#include "../EXT_INT/int_int.h"



void SPI_Master_Init(void)
{
	SET_BIT(SPCR_REG,SPE_BIT);
	SPCR_REG|=SPI_DATA_TRANSMIT_ORDER;
	SET_BIT(SPCR_REG,MSTR_BIT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_4,OUTPUT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_5,OUTPUT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_6,INPUT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_7,OUTPUT);

	SPCR_REG|=SPI_CLOCK_POLATIRY;
	SPCR_REG|=SPI_CLOCK_PHASE;

	if(GET_BIT(SPI_PRESCALER_4,0)==1)
		{
			SET_BIT(SPCR_REG,SPR0_BIT);
		}
		else
		{
			CLR_BIT(SPCR_REG,SPR0_BIT);
		}

		if(GET_BIT(SPI_PRESCALER_4,1)==1)
		{
			SET_BIT(SPCR_REG,SPR1_BIT);
		}
		else
		{
			CLR_BIT(SPCR_REG,SPR1_BIT);
		}

		if(GET_BIT(SPI_PRESCALER_4,2)==1)
		{
			SET_BIT(SPSR_REG,SPI2X_BIT);
		}
		else
		{
			CLR_BIT(SPSR_REG,SPI2X_BIT);
		}
}



void SPI_SLAVE_Init(void)
{
	SET_BIT(SPCR_REG,SPE_BIT);
	SPCR_REG|=SPI_DATA_TRANSMIT_ORDER;
	CLR_BIT(SPCR_REG,MSTR_BIT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_4,INPUT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_5,INPUT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_6,OUTPUT);
	DIO_u8Set_Pin_Dir(PORT_B,PIN_7,INPUT);

	SPCR_REG|=SPI_CLOCK_POLATIRY;
	SPCR_REG|=SPI_CLOCK_PHASE;
	if(GET_BIT(SPI_PRESCALER_4,0)==1)
		{
			SET_BIT(SPCR_REG,SPR0_BIT);
		}
		else
		{
			CLR_BIT(SPCR_REG,SPR0_BIT);
		}

		if(GET_BIT(SPI_PRESCALER_4,1)==1)
		{
			SET_BIT(SPCR_REG,SPR1_BIT);
		}
		else
		{
			CLR_BIT(SPCR_REG,SPR1_BIT);
		}

		if(GET_BIT(SPI_PRESCALER_4,2)==1)
		{
			SET_BIT(SPSR_REG,SPI2X_BIT);
		}
		else
		{
			CLR_BIT(SPSR_REG,SPI2X_BIT);
		}


}


void SPI_MASTER_Slave_SELECTION_ON(void)
{
	DIO_u8Get_Pin_Val(PORT_B,PIN_4,LOW);
}


void SPI_MASTER_Slave_SELECTION_OFF(void)
{
	DIO_u8Get_Pin_Val(PORT_B,PIN_4,HIGH);
}




void SPI_INT_ENABLE(void)
{
	EXT_INT_Global_Enable();
	SET_BIT(SPCR_REG,SPE_BIT);
}


uint8 SPI_u8_TRANCIEVE_BYTE_POLLING(uint8 u8_Val_Copy)
{
	SPDR_REG=u8_Val_Copy;
	while(!GET_BIT(SPSR_REG,SPIF_BIT));
	return SPDR_REG;
}


sint8 SPI_s8_TRANCIEVE_BYTE_POLLING(sint8 s8_Val_Copy)
{
	SPDR_REG=s8_Val_Copy;
	while(!GET_BIT(SPSR_REG,SPIF_BIT));
	return SPDR_REG;
}

void SPI_u8_Send_STRING_POLLING(const uint8* u8_Str_Copy)
{
	uint8 i=0;
	while(u8_Str_Copy[i]!='\0')
	{
		SPI_u8_TRANCIEVE_BYTE_POLLING(u8_Str_Copy[i]);
		i++;
	}

}

