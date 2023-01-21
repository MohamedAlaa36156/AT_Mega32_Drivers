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

void Timer_0_Init (void)
{
	EXT_INT_Global_Enable();

	TCNT0_REG=TCNT0_INIT;

#if MODE_TIMER_0== NORMAL
	CLR_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
#elif MODE_TIMER_0==PWM_PHASE_CORRECT

	SET_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
#elif MODE_TIMER_0==CTC

	SET_BIT(TCCR0_REG,WGM00);
	CLR_BIT(TCCR0_REG,WGM01);
#elif MODE_TIMER_0==FAST_PWM

	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
#endif
	/*
	 * Enable Interrupt
	 */
	TIMSK_REG|=TIMER_0_CMP_MATCH_INT_ENABLE;
	/*
	 * Compare Mode
	 */
	TCCR0_REG|=COMPARE_MODE_TIMER_0;
/**************************/
	/*
	 * Setting Prescaler
	 */

	TCCR0_REG|=PRESCALING_TIMER_0;
/************************/



}

void Timer_2_Init (void)
{
	EXT_INT_Global_Enable();

	TCNT2_REG=TCNT2_INIT;

#if MODE_TIMER_2== NORMAL
	CLR_BIT(TCCR2_REG,WGM20);
	CLR_BIT(TCCR2_REG,WGM21);
#elif MODE_TIMER_2==PWM_PHASE_CORRECT

	SET_BIT(TCCR2_REG,WGM20);
	CLR_BIT(TCCR2_REG,WGM21);
#elif MODE_TIMER_2==CTC

	SET_BIT(TCCR2_REG,WGM20);
	CLR_BIT(TCCR2_REG,WGM21);
#elif MODE_TIMER_2==FAST_PWM

	SET_BIT(TCCR2_REG,WGM20);
	SET_BIT(TCCR2_REG,WGM21);
#endif

	/*
	 * Enable Interrupt
	 */
	TIMSK_REG|=TIMER_2_CMP_MATCH_INT_ENABLE;
	/*
	 * Compare Mode
	 */
	TCCR2_REG|=COMPARE_MODE_TIMER_2;
/**************************/
	/*
	 * Setting Prescaler
	 */

	TCCR2_REG|=PRESCALING_TIMER_2;
/************************/



}

