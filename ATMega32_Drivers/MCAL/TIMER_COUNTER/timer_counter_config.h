/*
 * timer_counter_config.h
 *
 *  Created on: 26 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_TIMER_COUNTER_TIMER_COUNTER_CONFIG_H_
#define MCAL_TIMER_COUNTER_TIMER_COUNTER_CONFIG_H_
/****************************************************************************/
/*																			*/
/* 								TIMER_1_CONFIG 								*/
/*																			*/
/****************************************************************************/


/****************************************************************************/
/*																			*/
/* 							Timer 1 Wave Generation Mode					*/
/*																			*/
/****************************************************************************/
/*																			*/
/*	TIMER_1_NORMAL															*/
/*	TIMER_1_PWM_PHS_8					                                    */
/*	TIMER_1_PWM_PHS_9					                                    */
/*	TIMER_1_PWM_PHS_10					                                    */
/*	TIMER_1_CTC_OCR1A					                                    */
/*	TIMER_1_FAST_PWM_8_BIT				                                    */
/*	TIMER_1_FAST_PWM_9_BIT				                                    */
/*	TIMER_1_FAST_PWM_10_BIT				                                    */
/*	TIMER_1_PWM_PHS_FREQ_CORRECT_ICR1	                                    */
/*	TIMER_1_PWM_PHS_FREQ_CORRECT_OCR1A	                                    */
/*	TIMER_1_PWM_PHS_FREQ_ICR1			                                    */
/*	TIMER_1_PWM_PHS_FREQ_OCR1A			                                    */
/*	TIMER_1_CTC_ICR1					                                    */
/*	TIMER_1_FAST_PWM_ICR1				                                    */
/*	TIMER_1_FAST_PWM_OCR1A				                                    */
/*																			*/
/************************************************************************** */


#define TIMER_1_WAVE_GEN_MODE					TIMER_1_NORMAL

/****************************************************************************/
/*																			*/
/* 								TIMER_1_PRESCALER							*/
/*																			*/
/****************************************************************************/
#define PRESCALING_TIMER_1			PRESCALING_8



/****************************************************************************/
/*																			*/
/* 								TIMER_1_COMPARE_MODE						*/
/*																			*/
/****************************************************************************/
#define TIMER_1_COMP_MODE_A			TIMER_1_SET_COMP_A
#define TIMER_1_COMP_MODE_B			TIMER_1_NORMAL_COMP_B



/****************************************************************************/
/*																			*/
/* 								INPUT_CAPTURE_INIT_SENSE					*/
/*																			*/
/****************************************************************************/

#define INPUT_CAPTURE_EDGE_SELECT	INPUT_CAPTURE_RISING




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
/* 							TIMER_0_CONFIG									*/
/*																			*/
/****************************************************************************/

#define TIMER_0_WAVE_GEN_MODE		TIMER_0_2_NORMAL
#define COMPARE_MODE_TIMER_0		CLEAR_ON_COMPARE
#define PRESCALING_TIMER_0			PRESCALING_8
#define TIMER_0_INT_MODE			TIMER_0_CMP_MATCH_INT_ENABLE



/****************************************************************************/
/*																			*/
/* 							TIMER_2_CONFIG									*/
/*																			*/
/****************************************************************************/
#define TIMER_2_WAVE_GEN_MODE		TIMER_0_2_NORMAL
#define COMPARE_MODE_TIMER_2		TOGGLE
#define PRESCALING_TIMER_2			PRESCALING_1024
#define TIMER_2_INT_MODE			TIMER_2_CMP_MATCH_INT_ENABLE




#endif /* MCAL_TIMER_COUNTER_TIMER_COUNTER_CONFIG_H_ */
