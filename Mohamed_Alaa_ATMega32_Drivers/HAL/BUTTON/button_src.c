/*
 * button_src.c
 *
 *  Created on: 5 Jan 2023
 *      Author: Ahmed
 */
#include "../../SERV/stdtypes.h"
#include "../../MCAL/DIO/dio_int.h"
#include "button_cfg.h"
void Button_String_u8Set_Dir(void)
{
	DIO_u8Set_Port_Dir(FULL_BUTTON_PORT,FULL_INPUT);
	DIO_u8Set_Port_Val(FULL_BUTTON_PORT,FULL_PUE);
}
void Button_Pin_u8Set_Dir(void)
{
	DIO_u8Set_Pin_Dir(BUTTON_PORT,BUTTON_PIN,FULL_INPUT);
	DIO_u8Set_Pin_Val(BUTTON_PORT,BUTTON_PIN,PUE);
}
//void Button_String_u8Get_Val(uint8 u8PortIdCopy , uint8* u8pValCopy)
//{
//
//	DIO_u8Get_Port_Val(u8PortIdCopy,*u8pValCopy);
//}
void Button_Pin_u8Get_Val(uint8 * u8pValCopy)
{
	DIO_u8Get_Pin_Val(BUTTON_PORT,BUTTON_PIN,u8pValCopy);
}
