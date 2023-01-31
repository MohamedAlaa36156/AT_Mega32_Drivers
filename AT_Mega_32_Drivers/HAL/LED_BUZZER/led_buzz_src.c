/*
 * led_buzz_src.c
 *
 *  Created on: 5 Jan 2023
 *      Author: Ahmed
 */
#include "../../SERV/stdtypes.h"
#include "../../SERV/bit_math.h"
#include "led_buzz_cfg.h"

/*
 * 		Enable Output on Full Port.
 *
 */
void  Led_String_u8Set_Dir(void)
{
	DIO_u8Set_Port_Dir(LED_PORT_FULL,FULL_OUTPUT);
}



void Led_Pin_u8Set_Dir(void)
{
	DIO_u8Set_Pin_Dir(LED_PORT,LED_PIN,OUTPUT);
}



void Led_String_u8Set_On_Off(uint8 u8ValCopy)
{
	DIO_u8Set_Port_Val(LED_PORT_FULL,u8ValCopy);
}



void Led_Pin_u8Set_On_Off(uint8 u8ValCopy)
{
	DIO_u8Set_Pin_Val(LED_PORT,LED_PIN,u8ValCopy);
}



void Led_Pin_u8Tog_Val(void)
{
	DIO_u8TOG_Pin_Val(LED_PORT,LED_PIN);
}
