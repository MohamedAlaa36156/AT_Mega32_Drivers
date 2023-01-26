/*
 * timer_counter_src.c
 *
 *  Created on: 15 Jan 2023
 *      Author: Ahmed
 */

#include "../../SERV/bit_math.h"
#include "../../SERV/stdtypes.h"
#include "../EXT_INT/int_int.h"
#include "timer_counter_int.h"
#include "timer_counter_reg.h"


void Timer_0_Init (void)
{
	EXT_INT_Global_Enable();
	/*
	 * CLEAR COUNTING REGISTER
	 */
	TCNT0_REG=TCNT0_INIT;
/**********************************/
	/*
	 * SELECT WAVE GENERATION MODE
	 */
	TCCR0_REG|=TIMER_0_WAVE_GEN_MODE;
	/*******************************/
	/*
	 * Choosing Compare Mode
	 */
	TCCR0_REG|=COMPARE_MODE_TIMER_0;
	/**************************/

	/*
	 * Enable Interrupt
	 */

	TIMSK_REG|=TIMER_0_CMP_MATCH_INT_ENABLE;

	/**************************************/

	//#if MODE_TIMER_0== NORMAL
	//	CLR_BIT(TCCR0_REG,WGM00);
	//	CLR_BIT(TCCR0_REG,WGM01);
	//#elif MODE_TIMER_0==PWM_PHASE_CORRECT
	//
	//	SET_BIT(TCCR0_REG,WGM00);
	//	CLR_BIT(TCCR0_REG,WGM01);
	//#elif MODE_TIMER_0==CTC
	//
	//	SET_BIT(TCCR0_REG,WGM00);
	//	CLR_BIT(TCCR0_REG,WGM01);
	//#elif MODE_TIMER_0==FAST_PWM
	//
	//	SET_BIT(TCCR0_REG,WGM00);
	//	SET_BIT(TCCR0_REG,WGM01);
	//#endif

}
void Timer_0_Start_Count(void)
{
	/*
	 * Setting Prescaler
	 */

	TCCR0_REG|=PRESCALING_TIMER_0;

	/************************/
}

void Timer_0_Base_Count_Set(uint8 u8Set_Val_Copy)
{
	TCNT0_REG=u8Set_Val_Copy;

}
void Timer_0_CMP_Max_Set(uint8 u8Set_Val_Copy)
{
	OCR0_REG=u8Set_Val_Copy;
}

void Timer_2_Init (void)
{
	EXT_INT_Global_Enable();

	TCNT2_REG=TCNT2_INIT;

	/*
	 * SELECT WAVE GENERATION MODE
	 */
	TCCR2_REG|=TIMER_2_WAVE_GEN_MODE;

	/*******************************/

	/*
	 * Enable Interrupt
	 */
	TIMSK_REG|=TIMER_2_CMP_MATCH_INT_ENABLE;

	/**************************************/

	/*
	 * Compare Mode
	 */

	TCCR2_REG|=COMPARE_MODE_TIMER_2;

	/**************************/


//#if MODE_TIMER_2== NORMAL
//	CLR_BIT(TCCR2_REG,WGM20);
//	CLR_BIT(TCCR2_REG,WGM21);
//#elif MODE_TIMER_2==PWM_PHASE_CORRECT
//
//	SET_BIT(TCCR2_REG,WGM20);
//	CLR_BIT(TCCR2_REG,WGM21);
//#elif MODE_TIMER_2==CTC
//
//	SET_BIT(TCCR2_REG,WGM20);
//	CLR_BIT(TCCR2_REG,WGM21);
//#elif MODE_TIMER_2==FAST_PWM
//
//	SET_BIT(TCCR2_REG,WGM20);
//	SET_BIT(TCCR2_REG,WGM21);
//#endif
}
void Timer_2_Start_Count(void)
{
	/*
	 * Setting Prescaler
	 */

	TCCR2_REG|=PRESCALING_TIMER_2;

	/************************/
}
void Timer_2_Base_Count_Set(uint8 u8Set_Val_Copy)
{
	TCNT2_REG=u8Set_Val_Copy;

}
void Timer_2_CMP_Max_Set(uint8 u8Set_Val_Copy)
{
	OCR2_REG=u8Set_Val_Copy;
}

void Timer_0_1_Scaler_Reset(void)
{
	/*
	 * Calling This Function Will reset Timer 0 and Timer 1 Prescalers
	 */
	SET_BIT(SFIOR_REG,PSR10_BIT);
}

void Timer_1_Init(void)
{
	TCNT1_REG=TCNT1_INIT_VAL;
	OCR1A_REG=OCR1A_INIT_VAL;
	OCR1B_REG=OCR1B_INIT_VAL;
	if((TIMER_1_COMP_MODE_A==0x00)||(TIMER_1_COMP_MODE_A==0x40)||(TIMER_1_COMP_MODE_A==0x80)||(TIMER_1_COMP_MODE_A==0xC0))
	{
		TCCR1A_REG|=TIMER_1_COMP_MODE_A;
	}
	if((TIMER_1_COMP_MODE_B==0x10)||(TIMER_1_COMP_MODE_B==0x20)||(TIMER_1_COMP_MODE_B==0x30)||(TIMER_1_COMP_MODE_B==0x40))
	{
		TCCR1A_REG|=TIMER_1_COMP_MODE_B;
	}
#if INPUT_CAPTURE_EDGE_SELECT==INPUT_CAPTURE_FALLING
	SET_BIT(TCCR1B_REG,ICES1);
#elif	INPUT_CAPTURE_EDGE_SELECT==INPUT_CAPTURE_RISING
	CLR_BIT(TCCR1B_REG,ICES1);
#endif


#if TIMER_1_INPUT_CPT_INT_EN==ON
	SET_BIT(TIMSK_REG,TICIE1);
#endif
#if TIMER_1_INPUT_CMP_A_INT_EN==ON
	SET_BIT(TIMSK_REG,OCIE1A);
#endif
#if TIMER_1_INPUT_CMP_B_INT_EN==ON
	SET_BIT(TIMSK_REG,OCIE1B);
#endif
#if TIMER_1_INPUT_OVF_INT_EN==ON
	SET_BIT(TIMSK_REG,TOIE1);
#endif

	if(GET_BIT(TIMER_1_WAVE_GEN_MODE,0)==1)
	{
		SET_BIT(TCCR1A_REG,WGM10);
	}
	else
	{
		CLR_BIT(TCCR1A_REG,WGM10);
	}

	if(GET_BIT(TIMER_1_WAVE_GEN_MODE,1)==1)
	{
		SET_BIT(TCCR1A_REG,WGM11);
	}
	else
	{
		CLR_BIT(TCCR1A_REG,WGM11);
	}

	if(GET_BIT(TIMER_1_WAVE_GEN_MODE,2)==1)
	{
		SET_BIT(TCCR1B_REG,WGM12);
	}
	else
	{
		CLR_BIT(TCCR1B_REG,WGM12);
	}

	if(GET_BIT(TIMER_1_WAVE_GEN_MODE,3)==1)
	{
		SET_BIT(TCCR1B_REG,WGM13);
	}
	else
	{
		CLR_BIT(TCCR1B_REG,WGM13);
	}
}

void Timer_1_Start_Count(void)
{
	TCCR1B_REG|=PRESCALING_TIMER_1;
}

void Timer_1_Base_Count_Set(uint16 u16Set_Val_Copy)
{
	TCNT1_REG=u16Set_Val_Copy;

}

void Timer_1_CMP_A_Max_Set(uint16 u16Set_Val_Copy)
{
	OCR1A_REG=u16Set_Val_Copy;
}

void Timer_1_CMP_B_Max_Set(uint16 u16Set_Val_Copy)
{
	OCR1B_REG=u16Set_Val_Copy;
}

void Timer_1_TOG_INP_CPT_UNIT_Sense(void)
{
	TOGGLE_BIT(TCCR1B_REG,ICES1);
}









//void Timer_0_Init (void)
//{
//	EXT_INT_Global_Enable();
//
//	TCNT0_REG=TCNT0_INIT;
//
//#if MODE_TIMER_0== NORMAL
//	CLR_BIT(TCCR0_REG,WGM00);
//	CLR_BIT(TCCR0_REG,WGM01);
//#elif MODE_TIMER_0==PWM_PHASE_CORRECT
//
//	SET_BIT(TCCR0_REG,WGM00);
//	CLR_BIT(TCCR0_REG,WGM01);
//#elif MODE_TIMER_0==CTC
//
//	SET_BIT(TCCR0_REG,WGM00);
//	CLR_BIT(TCCR0_REG,WGM01);
//#elif MODE_TIMER_0==FAST_PWM
//
//	SET_BIT(TCCR0_REG,WGM00);
//	SET_BIT(TCCR0_REG,WGM01);
//#endif
//
//
//
//#if COMPARE_MODE_TIMER_0== NORMAL_COMPARE
//	CLR_BIT(TCCR0_REG,COM00);
//	CLR_BIT(TCCR0_REG,COM01);
//#elif COMPARE_MODE_TIMER_0==PWM_PHASE_CORRECT
//
//	SET_BIT(TCCR0_REG,COM00);
//	CLR_BIT(TCCR0_REG,COM01);
//#elif COMPARE_MODE_TIMER_0==CTC
//
//	SET_BIT(TCCR0_REG,COM00);
//	CLR_BIT(TCCR0_REG,COM01);
//#elif COMPARE_MODE_TIMER_0==FAST_PWM
//
//	SET_BIT(TCCR0_REG,COM00);
//	SET_BIT(TCCR0_REG,COM01);
//#endif
//
//
//
//
//#if PRESCALING_TIMER_0==NO_PRESCALING
//	SET_BIT(TCCR0_REG,CS00);
//	CLR_BIT(TCCR0_REG,CS01);
//	CLR_BIT(TCCR0_REG,CS02);
//#elif	PRESCALING_TIMER_0==PRESCALING_8
//	CLR_BIT(TCCR0_REG,CS00);
//	SET_BIT(TCCR0_REG,CS01);
//	CLR_BIT(TCCR0_REG,CS02);
//#elif	PRESCALING_TIMER_0==PRESCALING_64
//	SET_BIT(TCCR0_REG,CS00);
//	SET_BIT(TCCR0_REG,CS01);
//	CLR_BIT(TCCR0_REG,CS02);
//#elif	PRESCALING_TIMER_0==PRESCALING_256
//	CLR_BIT(TCCR0_REG,CS00);
//	CLR_BIT(TCCR0_REG,CS01);
//	SET_BIT(TCCR0_REG,CS02);
//#elif	PRESCALING_TIMER_0==PRESCALING_1024
//	SET_BIT(TCCR0_REG,CS00);
//	CLR_BIT(TCCR0_REG,CS01);
//	SET_BIT(TCCR0_REG,CS02);
//#elif	PRESCALING_TIMER_0==EXTERNAL_FALLING
//	CLR_BIT(TCCR0_REG,CS00);
//	SET_BIT(TCCR0_REG,CS01);
//	SET_BIT(TCCR0_REG,CS02);
//#elif	PRESCALING_TIMER_0==EXTERNAL_RISING
//	SET_BIT(TCCR0_REG,CS00);
//	SET_BIT(TCCR0_REG,CS01);
//	SET_BIT(TCCR0_REG,CS02);
//#endif
//	TIMSK_REG|=1;
//}
