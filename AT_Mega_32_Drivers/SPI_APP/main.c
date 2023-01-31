/*
 * main.c
 *
 *  Created on: Jan 29, 2023
 *      Author: thund
 */
#include "../SERV/bit_math.h"
#include "../SERV/stdtypes.h"
#include "../MCAL/DIO/dio_int.h"
#include "../MCAL/SPI/SPI_INIT.h"

int main (void)
{
	SPI_Master_Init();
	SPI_MASTER_Slave_SELECTION_ON();

	DIO_u8Set_Pin_Dir(PORT_A,PIN_0,INPUT);
	DIO_u8Set_Pin_Val(PORT_A,PIN_0,PUE);
	uint8 x;


	while (1)
	{
		DIO_u8Get_Pin_Val(PORT_A,PIN_0,&x);

		if(x==1)
		{
			SPI_u8_TRANCIEVE_BYTE_POLLING(0x01);
		}
		else
		{
			SPI_u8_TRANCIEVE_BYTE_POLLING(0x00);
		}
	}
	return 0;
}

