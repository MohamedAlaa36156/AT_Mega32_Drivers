/*
 * keypad_src.c
 *
 *  Created on: 7 Jan 2023
 *      Author: Ahmed
 */
#include "../../SERV/stdtypes.h"
#include "../../MCAL/DIO/dio_int.h"
#include "util/delay.h"
#include "keypad_init.h"
#include "keypad_config.h"



void Keypad_Int(void)
{
	/*
	 * Set Row and Columns as Input
	 */

	DIO_u8Set_Pin_Dir(PORTC1,PINC1,INPUT);
	DIO_u8Set_Pin_Dir(PORTC2,PINC2,INPUT);
	DIO_u8Set_Pin_Dir(PORTC3,PINC3,INPUT);
	DIO_u8Set_Pin_Dir(PORTC4,PINC4,INPUT);
	DIO_u8Set_Pin_Dir(PORTR1,PINR1,OUTPUT);
	DIO_u8Set_Pin_Dir(PORTR2,PINR2,OUTPUT);
	DIO_u8Set_Pin_Dir(PORTR3,PINR3,OUTPUT);
	DIO_u8Set_Pin_Dir(PORTR4,PINR4,OUTPUT);

	/*
	 * 	Set PULL UP
	 */

	DIO_u8Set_Pin_Val(PORTC1,PINC1,PUE);
	DIO_u8Set_Pin_Val(PORTC2,PINC2,PUE);
	DIO_u8Set_Pin_Val(PORTC3,PINC3,PUE);
	DIO_u8Set_Pin_Val(PORTC4,PINC4,PUE);
	DIO_u8Set_Pin_Val(PORTR1,PINR1,HIGH);
	DIO_u8Set_Pin_Val(PORTR2,PINR2,HIGH);
	DIO_u8Set_Pin_Val(PORTR3,PINR3,HIGH);
	DIO_u8Set_Pin_Val(PORTR4,PINR4,HIGH);

}



uint8 Keypad_u8Selector(void)
{
	uint8 port_col[4]={PORTC1,PORTC2,PORTC3,PORTC4};
	uint8 port_row[4]={PORTR1,PORTR2,PORTR3,PORTR4};
	uint8 pin_col[4]={PINC1,PINC2,PINC3,PINC4};
	uint8 pin_row[4]={PINR1,PINR2,PINR3,PINR4};
	uint8 Local_Col_Count,Local_Row_Count;
	uint8 Local_Button_Status;
	uint8 Local_Return_Status=KEY_NOT_PRESSED;
	uint8 KEYPAD_au8KeyVal[KEYPAD_ROWS][KEYPAD_COLS]=
	{
			{
				1,	//ROW 0 Col 0
				2,	//ROW 0 Col 1
				3,	//ROW 0 Col 2
				4,	//ROW 0 Col 3
			},
			{
				5,	//ROW 1 Col 0
				6,	//ROW 1 Col 1
				7,	//ROW 1 Col 2
				8,	//ROW 1 Col 3
			},
			{
				9,	//ROW 2 Col 0
				10,	//ROW 2 Col 1
				11,	//ROW 2 Col 2
				12,	//ROW 2 Col 3
			},
			{
				13,	//ROW 3 Col 0
				14,	//ROW 3 Col 1
				15,	//ROW 3 Col 2
				16,	//ROW 3 Col 3
			}
	};


	for(Local_Row_Count=0;Local_Row_Count<KEYPAD_ROWS;Local_Row_Count++)
	{

		DIO_u8Set_Pin_Val(port_row[Local_Row_Count],pin_row[Local_Row_Count],LOW);
		for(Local_Col_Count=0;Local_Col_Count<KEYPAD_COLS;Local_Col_Count++)
		{

			DIO_u8Get_Pin_Val(port_col[Local_Col_Count],pin_col[Local_Col_Count],&Local_Button_Status);
			if(Local_Button_Status==0)
			{
				Local_Return_Status=KEYPAD_au8KeyVal[Local_Row_Count][Local_Col_Count];
#if KEYPAD_MODE==KEYPAD_POLLING
				while(Local_Button_Status==0)
				{
					DIO_u8Get_Pin_Val(port_col[Local_Col_Count],pin_col[Local_Col_Count],&Local_Button_Status);
				}

#elif KEYPAD_MODE==KEYPAD_PERIODIC
				//ACTION
				_delay_ms(15);
				DIO_u8Get_Pin_Val(port_col[Local_Col_Count],pin_col[Local_Col_Count],&Local_Button_Status);
				if(Local_Button_Status==0)
				{
					Local_Return_Status=KEYPAD_au8KeyVal[Local_Row_Count][Local_Col_Count];

				}
#endif



			}

		}

		DIO_u8Set_Pin_Val(port_row[Local_Row_Count],pin_row[Local_Row_Count],HIGH);
	}


	return	Local_Return_Status;
}






