/*
 * timer_counter_int.h
 *
 *  Created on: 15 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_TIMER_COUNTER_TIMER_COUNTER_INT_H_
#define MCAL_TIMER_COUNTER_TIMER_COUNTER_INT_H_
#include "timer_counter_config.h"

#define ON			1
#define OFF			0
/****************************************************************************/
/*																			*/
/* 							TIMER 0 Register Bits							*/
/*																			*/
/****************************************************************************/


#define CS00		0
#define CS01		1
#define CS02		2


#define WGM00		3
#define WGM01		6

#define COM00		4
#define COM01		5

#define FOC0		7


/*
 * SFIOR -> Reseting Timer 0 and Timer 1 Prescalers Bits
 */
#define PSR10_BIT	0
/****************************************************************************/
/*																			*/
/* 								Timer 1 									*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*																			*/
/* 								TCCR1A_REG 									*/
/*																			*/
/****************************************************************************/

#define WGM10		0
#define WGM11		1
#define FOC1B		2
#define FOC1A		3
#define COM1B0		4
#define COM1B1		5
#define COM1A0		6
#define COM1A1		7

/****************************************************************************/
/*																			*/
/* 								TCCR1B_REG 									*/
/*																			*/
/****************************************************************************/

#define CS10		0
#define CS11		1
#define CS12		2
#define WGM12		3
#define WGM13		4

#define ICES1		6
#define ICNC1		7
/***************************************************************************/
#define	TIMER_1_NORMAL_COMP_A		0x00
#define	TIMER_1_TOGGLE_COMP_A		0x40
#define	TIMER_1_CLR_COMP_A			0x80
#define	TIMER_1_SET_COMP_A			0xC0

#define	TIMER_1_NORMAL_COMP_B		0x00
#define	TIMER_1_TOGGLE_COMP_B		0x10
#define	TIMER_1_CLR_COMP_B			0x20
#define	TIMER_1_SET_COMP_B			0x30


/****************************************************************************/
/*																			*/
/* 								TCNT_REG 									*/
/*																			*/
/****************************************************************************/
#define TCNT1L_INIT_VAL		0
#define TCNT1H_INIT_VAL		0
#define TCNT1_INIT_VAL		0
/****************************************************************************/
/*																			*/
/* 								OCR1A_REG 									*/
/*																			*/
/****************************************************************************/
#define OCR1AL_INIT_VAL		0
#define OCR1AH_INIT_VAL		0
#define OCR1A_INIT_VAL		0

/****************************************************************************/
/*																			*/
/* 								OCR1B_REG 									*/
/*																			*/
/****************************************************************************/
#define OCR1BL_INIT_VAL		0
#define OCR1BH_INIT_VAL		0
#define OCR1B_INIT_VAL		0
/****************************************************************************/
/*																			*/
/* 								ICR1_REG 									*/
/*																			*/
/****************************************************************************/
#define ICR1L_INIT_VAL		0
#define ICR1H_INIT_VAL		0
#define ICR1_INIT_VAL		0
/****************************************************************************/
/*																			*/
/* 								TIMSK_REG 									*/
/*																			*/
/****************************************************************************/

#define TOIE1				2
#define OCIE1B				3
#define OCIE1A				4
#define TICIE1				5
/*****************************************************************************/
/****************************************************************************/
/*																			*/
/* 								TIFR_REG 									*/
/*																			*/
/****************************************************************************/

#define TOV1				2
#define OCF1B				3
#define OCF1A				4
#define ICF1				5
/*****************************************************************************/

/***************************************************************************/
/****************************************************************************/
/*																			*/
/*	 						Timer 1	INPUT_CAPTURE_MODE						*/
/*																			*/
/****************************************************************************/
#define INPUT_CAPTURE_FALLING		0x77
#define INPUT_CAPTURE_RISING		0x88

/****************************************************************************/
/*																			*/
/* 							TIMER_1_INTERRUPT_CONFIG						*/
/*																			*/
/****************************************************************************/
#define TIMER_1_INPUT_CPT_INT_EN		ON
#define TIMER_1_INPUT_CMP_A_INT_EN		OFF
#define TIMER_1_INPUT_CMP_B_INT_EN		OFF
#define TIMER_1_INPUT_OVF_INT_EN		ON

/****************************************************************************/
/*																			*/
/* 								TIMER_2_STUFF								*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*																			*/
/* 							TIMER 2 REGISTER BITS							*/
/*																			*/
/****************************************************************************/


#define CS20		0
#define CS21		1
#define CS22		2


#define WGM20		3
#define WGM21		6

#define COM20		4
#define COM21		5

#define FOC2		7


/****************************************************************************/
/*																			*/
/* 							Timer 0 & 2 Wave Generation Mode				*/
/*																			*/
/****************************************************************************/

#define TIMER_0_2_NORMAL				0x00
#define TIMER_0_2_PWM_PHASE_CORRECT		0x08
#define TIMER_0_2_CTC					0x40
#define TIMER_0_2_FAST_PWM				0x48

/****************************************************************************/
/*																			*/
/* 							Timer 1 Wave Generation Mode					*/
/*																			*/
/****************************************************************************/
#define TIMER_1_NORMAL							0x00
#define TIMER_1_PWM_PHS_8						0x01
#define TIMER_1_PWM_PHS_9						0x02
#define TIMER_1_PWM_PHS_10						0x03
#define TIMER_1_CTC_OCR1A						0x04
#define TIMER_1_FAST_PWM_8_BIT					0x05
#define TIMER_1_FAST_PWM_9_BIT					0x06
#define TIMER_1_FAST_PWM_10_BIT					0x07
#define TIMER_1_PWM_PHS_FREQ_CORRECT_ICR1		0x08
#define TIMER_1_PWM_PHS_FREQ_CORRECT_OCR1A		0x09
#define TIMER_1_PWM_PHS_FREQ_ICR1				0x0A
#define TIMER_1_PWM_PHS_FREQ_OCR1A				0x0B
#define TIMER_1_CTC_ICR1						0x0C
#define TIMER_1_FAST_PWM_ICR1					0x0E
#define TIMER_1_FAST_PWM_OCR1A					0x0F

/***************************************************************************/
/****************************************************************************/
/*																			*/
/* 							TIMER 0 & 1 COMPARE MODES						*/
/*																			*/
/****************************************************************************/

#define NORMAL_COMPARE		0x00
#define TOGGLE				0x10
#define CLEAR_ON_COMPARE	0x20
#define SET_ON_COMPARE		0x30
/****************************************************************************/
/*																			*/
/* 							PRESCALER Timer 0 MODES							*/
/*																			*/
/****************************************************************************/

#define TIMER_0_NO_SOURCE_OFF_TIMER	0x00
#define TIMER_0_NO_PRESCALING		0x01
#define TIMER_0_PRESCALING_8		0x02
#define TIMER_0_PRESCALING_64		0x03
#define TIMER_0_PRESCALING_256		0x04
#define TIMER_0_PRESCALING_1024		0x05
#define TIMER_0_EXTERNAL_FALLING	0x06
#define TIMER_0_EXTERNAL_RISING		0x07
/****************************************************************************/
/*																			*/
/* 							PRESCALER Timer 1 MODES							*/
/*																			*/
/****************************************************************************/

#define TIMER_1_NO_SOURCE_OFF_TIMER	0x00
#define TIMER_1_NO_PRESCALING		0x01
#define TIMER_1_PRESCALING_8		0x02
#define TIMER_1_PRESCALING_64		0x03
#define TIMER_1_PRESCALING_256		0x04
#define TIMER_1_PRESCALING_1024		0x05
#define TIMER_1_EXTERNAL_FALLING	0x06
#define TIMER_1_EXTERNAL_RISING		0x07
/****************************************************************************/
/*																			*/
/* 							PRESCALER Timer 2 MODES							*/
/*																			*/
/****************************************************************************/

#define TIMER_2_NO_SOURCE_OFF_TIMER	0x00
#define TIMER_2_NO_PRESCALING	    0x01
#define TIMER_2_PRESCALING_8        0x02
#define TIMER_2_PRESCALING_32       0x03
#define TIMER_2_PRESCALING_64       0x04
#define TIMER_2_PRESCALING_128      0x05
#define TIMER_2_PRESCALING_256      0x06
#define TIMER_2_PRESCALING_1024		0x07



/****************************************************************************/
/*																			*/
/* 							TIMER 0 INTERRUPT MODE							*/
/*																			*/
/****************************************************************************/

#define TIMER_0_NO_INT					0x00
#define TIMER_0_OVERFLOW_INT_ENABLE		0x01
#define TIMER_0_CMP_MATCH_INT_ENABLE	0x02
#define TIMER_0_OVF_CMP_INT_ENABLE		0x03

/****************************************************************************/
/*																			*/
/* 							TIMER 2 INTERRUPT MODE							*/
/*																			*/
/****************************************************************************/

#define TIMER_2_NO_INT					0x00
#define TIMER_2_OVERFLOW_INT_ENABLE		0x40
#define TIMER_2_CMP_MATCH_INT_ENABLE	0x80
#define TIMER_2_OVF_CMP_INT_ENABLE		0xC0



/****************************************************************************/
/*																			*/
/* 							TIMER_0_FUNCTIONS								*/
/*																			*/
/****************************************************************************/


void Timer_0_Init (void);
void Timer_0_Start_Count(void);
void Timer_0_Base_Count_Set(uint8 u8Set_Val_Copy);
void Timer_0_CMP_Max_Set(uint8 u8Set_Val_Copy);

/****************************************************************************/
/*																			*/
/* 							TIMER_2_FUNCTIONS								*/
/*																			*/
/****************************************************************************/

void Timer_2_Init (void);
void Timer_2_Start_Count(void);
void Timer_2_Base_Count_Set(uint8 u8Set_Val_Copy);
void Timer_2_CMP_Max_Set(uint8 u8Set_Val_Copy);


/****************************************************************************/
/*																			*/
/* 							TIMER_1_FUNCTIONS								*/
/*																			*/
/****************************************************************************/

void Timer_1_Init(void);
void Timer_1_Start_Count(void);
void Timer_1_Base_Count_Set(uint16 u16Set_Val_Copy);
void Timer_1_CMP_A_Max_Set(uint16 u16Set_Val_Copy);
void Timer_1_CMP_B_Max_Set(uint16 u16Set_Val_Copy);
void Timer_1_TOG_INP_CPT_UNIT_Sense(void);

/****************************************************************************/
/*																			*/
/* 							COMBINED FUNCTIONS								*/
/*																			*/
/****************************************************************************/

void Timer_0_1_Scaler_Reset(void);


#endif /* MCAL_TIMER_COUNTER_TIMER_COUNTER_INT_H_ */
