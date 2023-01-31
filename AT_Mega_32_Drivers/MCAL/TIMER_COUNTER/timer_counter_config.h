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


#define TIMER_1_WAVE_GEN_MODE					TIMER_1_CTC_OCR1A

/****************************************************************************/
/*																			*/
/* 								TIMER_1_PRESCALER							*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*																			*/
/* 						PRESCALER MODES										*/
/* 						****************									*/
/* 						TIMER_1_NO_SOURCE_OFF_TIMER							*/
/* 						TIMER_1_NO_PRESCALING		                        */
/* 						TIMER_1_PRESCALING_8		                        */
/* 						TIMER_1_PRESCALING_64		                        */
/* 						TIMER_1_PRESCALING_256		                        */
/* 						TIMER_1_PRESCALING_1024		                        */
/* 						TIMER_1_EXTERNAL_FALLING	                        */
/* 						TIMER_1_EXTERNAL_RISING								*/
/*																			*/
/****************************************************************************/
#define PRESCALING_TIMER_1						TIMER_1_PRESCALING_64



/****************************************************************************/
/*																			*/
/* 								TIMER_1_COMPARE_MODE						*/
/*																			*/
/****************************************************************************/
#define TIMER_1_COMP_MODE_A						TIMER_1_SET_COMP_A
#define TIMER_1_COMP_MODE_B						TIMER_1_NORMAL_COMP_B



/****************************************************************************/
/*																			*/
/* 								INPUT_CAPTURE_INIT_SENSE					*/
/*																			*/
/****************************************************************************/

#define INPUT_CAPTURE_EDGE_SELECT				INPUT_CAPTURE_RISING




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

/****************************************************************************/
/*																			*/
/* 							TIMER 0 & 1 COMPARE MODES						*/
/*                          *************************                       */
/*							*NON_PWM*										*/
/*							********                                        */
/* 							*Fast PWM Mode*                                 */
/*							********                                        */
/* 							*Phase Correct PWM*                             */
/*                          *****************                               */
/*							NORMAL_COMPARE									*/
/*							TOGGLE	->	Does nothing on PWM Modes			*/
/*							CLEAR_ON_COMPARE								*/
/*							SET_ON_COMPARE									*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*																			*/
/* 						PRESCALER MODES										*/
/* 						****************									*/
/* 						TIMER_0_NO_SOURCE_OFF_TIMER							*/
/* 						TIMER_0_NO_PRESCALING		                    	*/
/* 						TIMER_0_PRESCALING_8		                   		*/
/* 						TIMER_0_PRESCALING_64		                   		*/
/* 						TIMER_0_PRESCALING_256		                   		*/
/* 						TIMER_0_PRESCALING_1024		                    	*/
/* 						TIMER_0_EXTERNAL_FALLING	                    	*/
/* 						TIMER_0_EXTERNAL_RISING								*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*																			*/
/* 							Timer 0 & 2 Wave Generation Mode				*/
/* 							********************************                */
/*                          TIMER_0_2_NORMAL	                            */
/*                          TIMER_0_2_PWM_PHASE_CORRECT                     */
/*                          TIMER_0_2_CTC                             		*/
/* 							TIMER_0_2_FAST_PWM         					    */
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*																			*/
/* 							TIMER 0 INTERRUPT MODE                          */
/*                         *************************                        */
/* 							TIMER_0_NO_INT                                  */
/* 							TIMER_0_OVERFLOW_INT_ENABLE                     */
/* 							TIMER_0_CMP_MATCH_INT_ENABLE                    */
/* 							TIMER_0_OVF_CMP_INT_ENABLE						*/
/*																			*/
/****************************************************************************/

#define TIMER_0_WAVE_GEN_MODE		TIMER_0_2_FAST_PWM
#define COMPARE_MODE_TIMER_0		SET_ON_COMPARE
#define PRESCALING_TIMER_0			TIMER_0_PRESCALING_8
#define TIMER_0_INT_MODE			TIMER_0_CMP_MATCH_INT_ENABLE

#define TCNT0_INIT_VALUE			0
#define OCR0_INIT_VALUE				30


/****************************************************************************/
/*																			*/
/* 							TIMER_2_CONFIG									*/
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*																			*/
/* 							TIMER 2 COMPARE MODES							*/
/*                          *************************                       */
/*							*NON_PWM*										*/
/*							********                                        */
/* 							*Fast PWM Mode*                                 */
/*							********                                        */
/* 							*Phase Correct PWM*                             */
/*                          *****************                               */
/*							NORMAL_COMPARE									*/
/*							TOGGLE	->	Does nothing on PWM Modes			*/
/*							CLEAR_ON_COMPARE								*/
/*							SET_ON_COMPARE									*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*																			*/
/* 						PRESCALER MODES										*/
/* 						****************									*/
/* 						TIMER_2_NO_SOURCE_OFF_TIMER							*/
/* 						TIMER_2_NO_PRESCALING	                            */
/* 						TIMER_2_PRESCALING_8                                */
/* 						TIMER_2_PRESCALING_32                               */
/* 						TIMER_2_PRESCALING_64                               */
/* 						TIMER_2_PRESCALING_128                              */
/* 						TIMER_2_PRESCALING_256                              */
/* 						TIMER_2_PRESCALING_1024								*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*																			*/
/* 							Timer  2 Wave Generation Mode					*/
/* 							********************************                */
/*                          TIMER_0_2_NORMAL	                            */
/*                          TIMER_0_2_PWM_PHASE_CORRECT                     */
/*                          TIMER_0_2_FAST_PWM                              */
/* 							TIMER_0_2_CTC              					    */
/*																			*/
/****************************************************************************/

/****************************************************************************/
/*																			*/
/* 							TIMER 2 INTERRUPT MODE                          */
/*                         *************************                        */
/* 							TIMER_2_NO_INT                                  */
/* 							TIMER_2_OVERFLOW_INT_ENABLE                     */
/* 							TIMER_2_CMP_MATCH_INT_ENABLE                    */
/* 							TIMER_2_OVF_CMP_INT_ENABLE						*/
/*																			*/
/****************************************************************************/
#define TIMER_2_WAVE_GEN_MODE		TIMER_0_2_CTC
#define COMPARE_MODE_TIMER_2		NORMAL_COMPARE
#define PRESCALING_TIMER_2			TIMER_2_PRESCALING_1024
#define TIMER_2_INT_MODE			TIMER_2_CMP_MATCH_INT_ENABLE

#define TCNT2_INIT_VALUE			0
#define OCR2_INIT_VALUE				195


#endif /* MCAL_TIMER_COUNTER_TIMER_COUNTER_CONFIG_H_ */
