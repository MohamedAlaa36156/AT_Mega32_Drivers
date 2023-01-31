/*
 * lcd_src.c
 *
 *  Created on: 6 Jan 2023
 *      Author: Ahmed
 */
#include "../../SERV/stdtypes.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/DIO/dio_int.h"
#include "util/delay.h"
#include <stdlib.h>
#include "lcd_cfg.h"

const uint8 LCD_u8CustomCharArray[8][8] ={

/*HLCD_u8Custom_Char1*/
									{	0x00,
								        0x00,
										0x07,
										0x05,
										0x1F,
										0x00,
										0x00,
										0x00},

/*HLCD_u8Custom_Char2*/			   {	  0x00,
									  	  0x00,
									  	  0x18,
										  0x04,
										  0x1F,
										  0x00,
										  0x00,
										  0x00},

/*HLCD_u8Custom_Char3*/			{		0x00,
										0x00,
										0x00,
										0x00,
										0x1F,
										0x0A,
										0x0E,
										0x00,},

/*HLCD_u8Custom_Char4*/			   { 0x00,
									 0x00,
									 0x18,
									 0x04,
									 0x1F,
									 0x00,
									 0x00,
									 0x00},

/*HLCD_u8Custom_Char5*/			  {
									  0x00,
									  0x00,
									  0x00,
									  0x00,
									  0x00,
									  0x00,
									  0x00,
									  0x00
                                  },

							{			0x00,
										0x00,
										0x07,
										0x04,
										0x1F,
										0x00,
										0x00,
										0x00},
									{
			/*HLCD_u8Custom_Char6*/ 	0x02,
									 	0x12,
										0x0A,
										0x06,
										0x1F,
										0x00,
										0x00,
										0x00
											},
	/*HLCD_u8Custom_Char7*/			   { 0x00,
										 0x00,
										 0x0E,
										 0x08,
										 0x1E,
										 0x00,
										 0x00,
										 0x00},

											};




void LCD_Write_CMD(uint8 u8CommandCopy)
{
	DIO_u8Set_Pin_Val(LCD_RS_PORT,LCD_RS_PIN,LOW);
	DIO_u8Set_Pin_Val(LCD_RW_PORT,LCD_RW_PIN,LOW);

	DIO_u8Set_Pin_Val(LCD_DATA_PORT_0,LCD_DATA_PIN_0,GET_BIT(u8CommandCopy,0));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_1,LCD_DATA_PIN_1,GET_BIT(u8CommandCopy,1));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_2,LCD_DATA_PIN_2,GET_BIT(u8CommandCopy,2));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_3,LCD_DATA_PIN_3,GET_BIT(u8CommandCopy,3));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_4,LCD_DATA_PIN_4,GET_BIT(u8CommandCopy,4));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_5,LCD_DATA_PIN_5,GET_BIT(u8CommandCopy,5));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_6,LCD_DATA_PIN_6,GET_BIT(u8CommandCopy,6));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_7,LCD_DATA_PIN_7,GET_BIT(u8CommandCopy,7));

//	DIO_u8Set_Port_Val(LCD_DATA_PORT,u8CommandCopy);
	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,LOW);

}

void LCD_Init(void)
{
	uint8 i,j;

	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_0,LCD_DATA_PIN_0,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_1,LCD_DATA_PIN_1,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_2,LCD_DATA_PIN_2,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_3,LCD_DATA_PIN_3,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_4,LCD_DATA_PIN_4,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_5,LCD_DATA_PIN_5,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_6,LCD_DATA_PIN_6,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_DATA_PORT_7,LCD_DATA_PIN_7,OUTPUT);

	DIO_u8Set_Pin_Dir(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
	DIO_u8Set_Pin_Dir(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	_delay_ms(40);

	LCD_Write_CMD(LCD_FUNC_SET);
	_delay_ms(1);
	LCD_Write_CMD(LCD_DISP_CTRL);
	_delay_ms(1);
	LCD_Write_CMD(LCD_DISP_CLR);
	_delay_ms(3);
	LCD_Write_CMD(LCD_ENGLISH_ENT_MOD_SET);



	LCD_Write_CMD(LCD_CGRAM_ADDRESS);


	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			LCD_WRITE_CHAR(LCD_u8CustomCharArray[i][j]);
		}
	}

	LCD_Return_Home();

}
void LCD_CLR_SCR(void)
{
	LCD_Write_CMD(LCD_DISP_CLR);
	_delay_ms(3);
}
void LCD_WRITE_CHAR(uint8 u8CharCopy)
{
	DIO_u8Set_Pin_Val(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	DIO_u8Set_Pin_Val(LCD_RW_PORT,LCD_RW_PIN,LOW);
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_0,LCD_DATA_PIN_0,GET_BIT(u8CharCopy,0));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_1,LCD_DATA_PIN_1,GET_BIT(u8CharCopy,1));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_2,LCD_DATA_PIN_2,GET_BIT(u8CharCopy,2));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_3,LCD_DATA_PIN_3,GET_BIT(u8CharCopy,3));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_4,LCD_DATA_PIN_4,GET_BIT(u8CharCopy,4));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_5,LCD_DATA_PIN_5,GET_BIT(u8CharCopy,5));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_6,LCD_DATA_PIN_6,GET_BIT(u8CharCopy,6));
	DIO_u8Set_Pin_Val(LCD_DATA_PORT_7,LCD_DATA_PIN_7,GET_BIT(u8CharCopy,7));
	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,LOW);


}
void LCD_WRITE_STRING(const uint8* u8pStringCopy)
{
	uint8 i=0;
	while(u8pStringCopy[i]!='\0')
	{
	//	DIO_u8Set_Pin_Val(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	//	DIO_u8Set_Pin_Val(LCD_RW_PORT,LCD_RW_PIN,LOW);
	//	DIO_u8Set_Port_Val(LCD_DATA_PORT,u8pStringCopy[i]);
	//	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	//	_delay_ms(2);
	//	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,LOW);
		LCD_WRITE_CHAR(u8pStringCopy[i]);
		i++;
	}
}
void LCD_WRITE_STRING_Delayed(const uint8* u8pStringCopy,uint16 u8DelayCopy)
{
	uint8 i=0;
	while(u8pStringCopy[i]!='\0')
	{
	//	DIO_u8Set_Pin_Val(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	//	DIO_u8Set_Pin_Val(LCD_RW_PORT,LCD_RW_PIN,LOW);
	//	DIO_u8Set_Port_Val(LCD_DATA_PORT,u8pStringCopy[i]);
	//	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	//	_delay_ms(2);
	//	DIO_u8Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,LOW);
		LCD_WRITE_CHAR(u8pStringCopy[i]);
		_delay_ms(u8DelayCopy);
		i++;
	}
}
void LCD_Entry_Mode_Arabic(void)
{
	LCD_Write_CMD(LCD_ARABIC_ENT_MOD_SET);
	_delay_ms(2);
}
void LCD_GoTo_X_Y(uint8 X,uint8 Y )
{
	switch(Y)
	{
		case 1:
			LCD_Write_CMD(LCD_JMP_TOP_LEFT+X);
			break;
		case 2:
			LCD_Write_CMD(LCD_JMP_BOT_LEFT+X);
			break;
	}

}
void LCD_Return_Home(void)
{
	LCD_Write_CMD(LCD_RET_HOME);
	_delay_ms(2);
}




//void LCD_Write_INT(sint32 s32IntCopy)
void LCD_Write_INT(const sint32 s32IntCopy)
{

	uint8 *str;
//	uint8 *str2;
//	uint8 i;
//	uint8 begin;
//	uint8 isnegative =0;
//	uint8 rem;
//	if(s32IntCopy==0)
//	{
//		str[i++]='0';
//		str[i]='\0';
//	}
//	if(s32IntCopy<0)
//	{
//		isnegative=1;
//		s32IntCopy=-s32IntCopy;
//	}
//	while(s32IntCopy!=0)
//	{
//		rem=s32IntCopy%10;
//		str[i++]=(rem > 9)? (rem-10) + 'a' : rem + '0';
//		s32IntCopy/=10;
//	}
//	if(isnegative==1)
//	{
//		str[i++]='-';
//	}
//	str[i]='\0';
//	for(begin=0;begin<i;begin++,i--)
//	{
//		str2[begin]=str[i];
//	}
//	str2[begin]='\0';

	itoa(s32IntCopy, str, 10);
	LCD_WRITE_STRING(str);
}

/*
 *
 * 			Disply SHifting
 *
 *
 */


void LCD_SHIFT_Cursor_Left(void)
{
	LCD_Write_CMD(LCD_SHIFT_Cursor_LEFT);
	_delay_ms(2);
}


void LCD_SHIFT_Cursor_Right(void)
{
	LCD_Write_CMD(LCD_SHIFT_Cursor_RIGHT);
	_delay_ms(2);
}



void LCD_SHIFT_Display_Right(void)
{
	LCD_Write_CMD(LCD_SHIFT_DSP_RIGHT);
	_delay_ms(2);
}



void LCD_SHIFT_Display_Left(void)
{
	LCD_Write_CMD(LCD_SHIFT_DSP_LEFT);
	_delay_ms(2);
}


void LCD_JMP_Bottom_Left(void)
{
	LCD_Write_CMD(LCD_JMP_BOT_LEFT);
	_delay_ms(2);
}


void LCD_JMP_UP_Left(void)
{
	LCD_Write_CMD(LCD_JMP_TOP_LEFT);
	_delay_ms(2);
}
/*
 *
 * 				END OF DISPLAY SHIFTING
 *
 */

