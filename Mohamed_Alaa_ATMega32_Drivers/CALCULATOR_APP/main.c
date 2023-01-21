#include "../SERV/stdtypes.h"
#include "../HAL/KEYPAD/keypad_cfg.h"
#include "../MCAL/DIO/dio_int.h"
#include "../HAL/LCD/lcd_cfg.h"
#include "util/delay.h"
sint32 myAtoi(const char* str)
{
    // Initialize result
    sint32 res = 0;



    uint8 i = 0;


    for (; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    // Return result with sign
    return res;
}
int main(void)
{
	uint8 j=0;
	LCD_Init();
	Keypad_Int();
	LCD_WRITE_STRING_Delayed("Welcome !!",123);
	do{
		j++;
		LCD_SHIFT_Display_Right();
		_delay_ms(100);
		}while(j!=10);
	LCD_CLR_SCR();
	uint8 	str1[32]={};
	uint8 	op;
	sint32	num1;
	sint32	num2;
	uint8 	i=0;
	uint8 	key ;
	sint32 result;
	while(1)
	{

		do{
			key=Keypad_u8Selector();
		}while(key==KEY_NOT_PRESSED);

		switch(key)
		{
			case 1:
				LCD_WRITE_CHAR('1');
				str1[i]='1';
				str1[i+1]='\0';
				i++;
			break;
			case 2:
				LCD_WRITE_CHAR('2');
				str1[i]='2';
				str1[i+1]='\0';
				i++;
			break;
			case 3:	LCD_WRITE_CHAR('3');
			str1[i]='3';
			str1[i+1]='\0';
			i++;
			break;
			case 4:
			if(i!=0)
				{
				LCD_WRITE_CHAR('+');
				num1=myAtoi(str1);
				i=0;
				op='+';
				}

			break;
			case 5:	LCD_WRITE_CHAR('4');
			str1[i]='4';
			str1[i+1]='\0';
			i++;
			break;
			case 6:	LCD_WRITE_CHAR('5');
			str1[i]='5';
			str1[i+1]='\0';
			i++;
			break;
			case 7:	LCD_WRITE_CHAR('6');
			str1[i]='6';
			str1[i+1]='\0';
			i++;
			break;
			case 8:
				if(i!=0)
				{
					LCD_WRITE_CHAR('-');
					num1=myAtoi(str1);
					i=0;
					op='-';
				}
			break;
			case 9:	LCD_WRITE_CHAR('7');
			str1[i]='7';
			str1[i+1]='\0';
			i++;
			break;
			case 10:LCD_WRITE_CHAR('8');
			str1[i]='8';
			str1[i+1]='\0';
			i++;
			break;
			case 11:LCD_WRITE_CHAR('9');
			str1[i]='9';
			str1[i+1]='\0';
			i++;
			break;
			case 12:
			if(i!=0)
				{
					LCD_WRITE_CHAR('*');
					num1=myAtoi(str1);
					i=0;
					op='*';
				}
			break;
			case 13:
				if(i!=0)
				{
					LCD_JMP_Bottom_Left();
					LCD_WRITE_CHAR('=');
					num2=myAtoi(str1);

				}
			break;
			case 14:LCD_WRITE_CHAR('0');
			str1[i]='0';
			str1[i+1]='\0';
			i++;
			break;
			case 15:LCD_CLR_SCR();
					LCD_WRITE_STRING_Delayed("DELETE",120);
					LCD_CLR_SCR();
					num1=0;
					num2=0;
					op=' ';
					i=0;
			break;
			case 16:
				if(i!=0)
				{
					LCD_WRITE_CHAR('/');
					num1=myAtoi(str1);
					i=0;
					op='/';
				}
			break;

		}

		if(key==13)
		{
			switch(op)
			{
			case '+':
				result=num1+num2;
				LCD_Write_INT(result);
				LCD_JMP_UP_Left();
				break;
			case '-':
				result=num1-num2;
				LCD_Write_INT(result);
				LCD_JMP_UP_Left();
				break;

			case '*':
				result=num1*num2;
				LCD_Write_INT(result);
				LCD_JMP_UP_Left();
				break;
			case '/':
				result=num1/num2;
				LCD_Write_INT(result);
				LCD_JMP_UP_Left();
				break;

			}
		}
	}

	return 0;
}

