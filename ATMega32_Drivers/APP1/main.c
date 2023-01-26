/*
 * main.c
 *
 *  Created on: 25 Jan 2023
 *      Author: Ahmed
 */

#include "../SERV/stdtypes.h"
#include "../MCAL/DIO/dio_int.h"
#include "../HAL/LCD/lcd_cfg.h"
#include "avr/io.h"
int main(void)
{


	LCD_Init();
	LCD_WRITE_STRING("T_tot:");
	LCD_Write_INT(32769);


	while(1)

	{

	}
	return 0;
}
