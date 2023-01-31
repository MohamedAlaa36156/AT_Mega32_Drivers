/*
 * led_buzz_cfg.h
 *
 *  Created on: 5 Jan 2023
 *      Author: Ahmed
 */

#ifndef HAL_LED_BUZZER_LED_BUZZ_CFG_H_
#define HAL_LED_BUZZER_LED_BUZZ_CFG_H_
#include "../../MCAL/DIO/dio_int.h"

#define LED_OFF		LOW
#define LED_ON		HIGH

#define LED_PORT_FULL	PORT_D

#define LED_PORT		PORT_D
#define LED_PIN			PIN_4


#define LED_STRING_ON	ALL_HIGH
#define LED_STRING_OFF	ALL_LOW

//void Led_String_u8Set_Dir(uint8 u8PortIdCopy , uint8 u8DirCopy);
//void Led_Pin_u8Set_Dir(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8 u8DirCopy);
//void Led_String_u8Set_On_Off(uint8 u8PortIdCopy , uint8 u8ValCopy);
//void Led_Pin_u8Set_On_Off(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8 u8ValCopy);
//void Led_Pin_u8Tog_Val(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy );
//


void  Led_String_u8Set_Dir(void);
void Led_Pin_u8Set_Dir(void);
void Led_String_u8Set_On_Off(uint8 u8ValCopy);
void Led_Pin_u8Set_On_Off(uint8 u8ValCopy);
void Led_Pin_u8Tog_Val(void);


#endif /* HAL_LED_BUZZER_LED_BUZZ_CFG_H_ */
