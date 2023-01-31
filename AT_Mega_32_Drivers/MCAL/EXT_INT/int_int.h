/*
 * int_int.h
 *
 *  Created on: 13 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_EXT_INT_INT_INT_H_
#define MCAL_EXT_INT_INT_INT_H_


#define GLOBAL_INT_BIT		7


#define INT_0_EABLE			6

#define INT_1_EABLE			7

#define INT_2_EABLE			5


//#define LOW_LEVEL_INT_REQ	1
//#define ANY_LOGICAL_LEVEL	2
//#define FALLING_EDGE		3
//#define RISING_EDGE		4
#define INT_0_LOW_LEVEL_REQ			0x00
#define INT_0_ANY_LOGICAL_LEVEL		0x01
#define INT_0_FALLING_EDGE			0x02
#define INT_0_RISING_EDGE			0x03


#define INT_1_LOW_LEVEL_REQ			0x00
#define INT_1_ANY_LOGICAL_LEVEL		0x04
#define INT_1_FALLING_EDGE			0x08
#define INT_1_RISING_EDGE			0x0C


#define ISC00				0
#define ISC01				1
#define ISC10				2
#define ISC11				3
#define ISC2 				6



//#if INT_0_SENSE_CONTROL	==	LOW_LEVEL_INT_REQ
//#define ISC00 0
//#define ISC01 0
//#elif	INT_0_SENSE_CONTROL	==	ANY_LOGICAL_LEVEL
//#define ISC00 0
//#define ISC01 1
//#elif	INT_0_SENSE_CONTROL	==	FALLING_EDGE
//#define ISC00 1
//#define ISC01 0
//#elif	INT_0_SENSE_CONTROL	==	RISING_EDGE
//#define ISC00 1
//#define ISC01 1
//#endif

//#if INT_1_SENSE_CONTROL	==	LOW_LEVEL_INT_REQ
//#define ISC10 0
//#define ISC11 0
//#elif	INT_1_SENSE_CONTROL	==	ANY_LOGICAL_LEVEL
//#define ISC10 0
//#define ISC11 1
//#elif	INT_1_SENSE_CONTROL	==	FALLING_EDGE
//#define ISC10 1
//#define ISC11 0
//#elif	INT_1_SENSE_CONTROL	==	RISING_EDGE
//#define ISC10 1
//#define ISC11 1
//#endif

//#if INT_2_SENSE_CONTROL	==	FALLING_EDGE
//#define ISC2 0
//
//#elif	INT_2_SENSE_CONTROL	==	RISING_EDGE
//
//#define ISC2 1
//#endif
//

//#define LOW_LEVEL_INT_REQ			0
//#define ANY_LOGICAL_CHANGE_INT_REQ	1
//#define FALLING_EDGE_INT_REQ		0
//#define FALLING_EDGE_INT_REQ		1


void EXT_INT_Global_Enable(void);
void EXT_INT_0_Enable(void);
void EXT_INT_1_Enable(void);
void EXT_INT_2_Enable(void);


void EXT_INT_Global_Disable(void);
void EXT_INT_Global_Toggle(void);

void EXT_INT_2_Toggle(void);

void EXT_INT_1_ChMod(uint8 u8modecpy);
void EXT_INT_0_ChMod(uint8 u8modecpy);



#endif /* MCAL_EXT_INT_INT_INT_H_ */
