/*
 * int_src.c
 *
 *  Created on: 13 Jan 2023
 *      Author: Ahmed
 */

#include "../../SERV/bit_math.h"
#include "../../SERV/stdtypes.h"
#include "int_int.h"
#include "int_reg.h"
#include "int_conf.h"


void EXT_INT_Global_Enable(void)
{
	SET_BIT(SREG_REG,GLOBAL_INT_BIT);
}

//void EXT_INT_0_Enable(void)
//{
//
//	SET_BIT(GICR_REG,INT_0_EABLE);
//#if INT_0_SENSE_CONTROL	==	LOW_LEVEL_INT_REQ
//	CLR_BIT(MCUCR_REG,ISC00);
//	CLR_BIT(MCUCR_REG,ISC01);
//
//#elif	INT_0_SENSE_CONTROL	==	ANY_LOGICAL_LEVEL
//	SET_BIT(MCUCR_REG,ISC00);
//	CLR_BIT(MCUCR_REG,ISC01);
//
//#elif	INT_0_SENSE_CONTROL	==	FALLING_EDGE
//	CLR_BIT(MCUCR_REG,ISC00);
//	SET_BIT(MCUCR_REG,ISC01);
//
//#elif	INT_0_SENSE_CONTROL	==	RISING_EDGE
//	SET_BIT(MCUCR_REG,ISC00);
//	SET_BIT(MCUCR_REG,ISC01);
//#endif
//
//}


void EXT_INT_0_Enable(void)
{
	SET_BIT(GICR_REG,INT_0_EABLE);
	MCUCR_REG|=INT_0_SENSE_CONTROL;

}
void EXT_INT_0_ChMod(uint8 u8modecpy)
{
	if((u8modecpy==INT_0_LOW_LEVEL_REQ)||( u8modecpy==  INT_0_ANY_LOGICAL_LEVEL) || (u8modecpy==INT_0_FALLING_EDGE) || (u8modecpy==INT_0_RISING_EDGE))
	{
		MCUCR_REG|=u8modecpy;
	}
}


//void EXT_INT_1_Enable(void)
//{
//	SET_BIT(GICR_REG,INT_1_EABLE);
//
//#if INT_1_SENSE_CONTROL	==	LOW_LEVEL_INT_REQ
//	CLR_BIT(MCUCR_REG,ISC10);
//	CLR_BIT(MCUCR_REG,ISC11);
//
//#elif	INT_1_SENSE_CONTROL	==	ANY_LOGICAL_LEVEL
//	SET_BIT(MCUCR_REG,ISC10);
//	CLR_BIT(MCUCR_REG,ISC11);
//
//#elif	INT_1_SENSE_CONTROL	==	FALLING_EDGE
//	CLR_BIT(MCUCR_REG,ISC10);
//	SET_BIT(MCUCR_REG,ISC11);
//
//#elif	INT_1_SENSE_CONTROL	==	RISING_EDGE
//	SET_BIT(MCUCR_REG,ISC10);
//	SET_BIT(MCUCR_REG,ISC11);
//#endif
//
//}
void EXT_INT_1_Enable(void)
{
	SET_BIT(GICR_REG,INT_0_EABLE);
	MCUCR_REG|=INT_1_SENSE_CONTROL;
}

void EXT_INT_1_ChMod(uint8 u8modecpy)
{
	if((u8modecpy==INT_1_LOW_LEVEL_REQ)||( u8modecpy==  INT_1_ANY_LOGICAL_LEVEL) || (u8modecpy==INT_1_FALLING_EDGE) || (u8modecpy==INT_1_RISING_EDGE))
	{
		MCUCR_REG|=u8modecpy;
	}
}

void EXT_INT_2_Enable(void)
{
	SET_BIT(GICR_REG,INT_2_EABLE);
#if INT_2_SENSE_CONTROL	==	RISING_EDGE
	CLR_BIT(MCUCSR_REG,ISC2);
#elif	INT_1_SENSE_CONTROL	==	FALLING_EDGE
	SET_BIT(MCUCSR_REG,ISC2);
#endif
}
void EXT_INT_2_Toggle(void)
{
	TOGGLE_BIT(MCUCSR_REG,ISC2);
}
void EXT_INT_Global_Disable(void)
{
	CLR_BIT(SREG_REG,GLOBAL_INT_BIT);
}
void EXT_INT_Global_Toggle(void)
{
	TOGGLE_BIT(SREG_REG,GLOBAL_INT_BIT);
}



