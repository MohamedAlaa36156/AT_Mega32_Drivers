/*
 * 7segment_cfg.h
 *
 *  Created on: 5 Jan 2023
 *      Author: Ahmed
 */

#ifndef HAL_7SEGMENT_7SEGMENT_CFG_H_
#define HAL_7SEGMENT_7SEGMENT_CFG_H_

#include "../../MCAL/DIO/dio_int.h"

#define SEVEN_SEGMENT_PORT	PORT_C

void  Seven_Seg_u8Set_Dir(void);
void Seven_Seg_u8Set_Val(uint8 u8ValCopy);
//void Seven_Seg_u8Set_Pov(uint8 u8PortIdCopy , uint8 u8ValCopy);
#endif /* HAL_7SEGMENT_7SEGMENT_CFG_H_ */
