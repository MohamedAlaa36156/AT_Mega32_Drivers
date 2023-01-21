/*
 * 7segment_src.c
 *
 *  Created on: 5 Jan 2023
 *      Author: Ahmed
 */

#include "../../SERV/stdtypes.h"
#include "../../SERV/bit_math.h"
#include "7segment_cfg.h"

const uint8 u8SevenSegArray[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void  Seven_Seg_u8Set_Dir(void)
{
	DIO_u8Set_Port_Dir(SEVEN_SEGMENT_PORT,FULL_OUTPUT);
}
void Seven_Seg_u8Set_Val(uint8 u8ValCopy)
{
	if((u8ValCopy>=0)&&(u8ValCopy<=9))
	{
		DIO_u8Set_Port_Val(SEVEN_SEGMENT_PORT,u8SevenSegArray[u8ValCopy]);
	}
	else
	{

	}
}
