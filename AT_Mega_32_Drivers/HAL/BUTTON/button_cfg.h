/*
 * button_cfg.h
 *
 *  Created on: 5 Jan 2023
 *      Author: Ahmed
 */

#ifndef HAL_BUTTON_BUTTON_CFG_H_
#define HAL_BUTTON_BUTTON_CFG_H_

#include "../../MCAL/DIO/dio_int.h"


#define MODE				1

#define FULL_BUTTON_PORT	PORT_D

#define BUTTON_PIN			PIN_1
#define BUTTON_PORT			PORT_A

#define POLLING				0
#define PERIODIC			1
#define FULL_PUE			0xFF
#define PUE					1
void Button_String_u8Set_Dir(void);
void Button_Pin_u8Set_Dir(void);
//void Button_String_u8Get_Val(uint8 u8PortIdCopy , uint8* u8pValCopy);
void Button_Pin_u8Get_Val(uint8 * u8pValCopy);

#endif /* HAL_BUTTON_BUTTON_CFG_H_ */
