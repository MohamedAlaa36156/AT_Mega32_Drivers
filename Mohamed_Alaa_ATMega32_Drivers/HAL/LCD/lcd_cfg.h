/*
 * lcd_cfg.h
 *
 *  Created on: 6 Jan 2023
 *      Author: Ahmed
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#define LCD_RS_PORT		PORT_B
#define LCD_RW_PORT		PORT_B
#define LCD_EN_PORT		PORT_B



#define LCD_RS_PIN		PIN_0
#define LCD_RW_PIN		PIN_1
#define LCD_EN_PIN		PIN_2


#define LCD_DATA_PORT_0		PORT_C
#define LCD_DATA_PIN_0		PIN_0

#define LCD_DATA_PORT_1		PORT_C
#define LCD_DATA_PIN_1		PIN_1

#define LCD_DATA_PORT_2		PORT_C
#define LCD_DATA_PIN_2		PIN_2

#define LCD_DATA_PORT_3		PORT_C
#define LCD_DATA_PIN_3		PIN_3

#define LCD_DATA_PORT_4		PORT_C
#define LCD_DATA_PIN_4		PIN_4

#define LCD_DATA_PORT_5		PORT_C
#define LCD_DATA_PIN_5		PIN_5

#define LCD_DATA_PORT_6		PORT_C
#define LCD_DATA_PIN_6		PIN_6

#define LCD_DATA_PORT_7		PORT_C
#define LCD_DATA_PIN_7		PIN_7


#define LCD_FUNC_SET				0x38
#define LCD_DISP_CTRL				0x0E	//0x0C
#define LCD_DISP_CLR				0x01
#define LCD_ENGLISH_ENT_MOD_SET		0x06
#define LCD_RET_HOME				0x02
#define LCD_ARABIC_ENT_MOD_SET		0x04

#define LCD_CGRAM_ADDRESS			0x40



#define LCD_JMP_TOP_LEFT	0x80
#define LCD_JMP_BOT_LEFT 	0xC0



#define LCD_SHIFT_Cursor_LEFT		0x10
#define LCD_SHIFT_Cursor_RIGHT		0x14



#define LCD_SHIFT_DSP_RIGHT		0x1C
#define LCD_SHIFT_DSP_LEFT		0x18

void LCD_Write_CMD(uint8 u8CommandCopy);
void LCD_Init(void);
void LCD_CLR_SCR(void);
void LCD_WRITE_CHAR(uint8 u8CharCopy);
void LCD_WRITE_STRING(const uint8* u8pStringCopy);
void LCD_Return_Home(void);
void LCD_Write_INT(const uint32 u8IntCopy);
void LCD_WRITE_STRING_Delayed(const uint8* u8pStringCopy,uint16 u8DelayCopy);



void LCD_SHIFT_Line_Right(void);
void LCD_SHIFT_Line_Left(void);


void LCD_SHIFT_Display_Right(void);
void LCD_SHIFT_Display_Shift(void);
void LCD_JMP_Bottom_Left(void);
void LCD_JMP_UP_Left(void);
void LCD_GoTo_X_Y(uint8 X,uint8 Y );

void LCD_Write_Special_Char(uint8 * u8pCustCharCopy);

#endif /* HAL_LCD_LCD_CFG_H_ */
