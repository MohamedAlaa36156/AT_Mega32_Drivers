/*
 * timer_counter_int.h
 *
 *  Created on: 15 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_TIMER_COUNTER_TIMER_COUNTER_INT_H_
#define MCAL_TIMER_COUNTER_TIMER_COUNTER_INT_H_


#define TCNT0_INIT	0
#define OCR0_INIT	24

#define CS00		0
#define CS01		1
#define CS02		2


#define WGM00		3
#define WGM01		6

#define COM00		4
#define COM01		5

#define FOC0		7
/*
 * Timer 2 Stuff
 */
#define TCNT2_INIT	0

#define CS20		0
#define CS21		1
#define CS22		2


#define WGM20		3
#define WGM21		6

#define COM20		4
#define COM21		5

#define FOC2		7

/*
 *
 *
 */
#define NORMAL				1
#define PWM_PHASE_CORRECT	2
#define CTC					3
#define FAST_PWM			4
/*
 *
 *
 */
#define NORMAL_COMPARE		0x00
#define TOGGLE				0x10
#define CLEAR_ON_COMPARE	0x20
#define SET_ON_COMPARE		0x30


#define NO_SOURCE_OFF_TIMER	0x00
#define NO_PRESCALING		0x01
#define PRESCALING_8		0x02
#define PRESCALING_64		0x03
#define PRESCALING_256		0x04
#define PRESCALING_1024		0x05
#define EXTERNAL_FALLING	0x06
#define EXTERNAL_RISING		0x07

/*
 * TIMER INTERRUPT MODE
 */
#define TIMER_0_OVERFLOW_INT_ENABLE		0x01
#define TIMER_0_CMP_MATCH_INT_ENABLE	0x02
#define TIMER_2_OVERFLOW_INT_ENABLE		0x40
#define TIMER_2_CMP_MATCH_INT_ENABLE	0x80



#define MODE_TIMER_0				FAST_PWM
#define COMPARE_MODE_TIMER_0		SET_ON_COMPARE
#define PRESCALING_TIMER_0			PRESCALING_8
#define TIMER_0_INT_MODE			TIMER_0_CMP_MATCH_INT_ENABLE

#define MODE_TIMER_2				PWM_PHASE_CORRECT
#define COMPARE_MODE_TIMER_2		TOGGLE
#define PRESCALING_TIMER_2			PRESCALING_1024
#define TIMER_2_INT_MODE			TIMER_2_CMP_MATCH_INT_ENABLE


void Timer_0_Init (void);
void Timer_2_Init (void);
#endif /* MCAL_TIMER_COUNTER_TIMER_COUNTER_INT_H_ */
