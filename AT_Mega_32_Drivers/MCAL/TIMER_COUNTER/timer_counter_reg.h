/*
 * timer_counter_reg.h
 *
 *  Created on: 15 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_TIMER_COUNTER_TIMER_COUNTER_REG_H_
#define MCAL_TIMER_COUNTER_TIMER_COUNTER_REG_H_
/*
 * Timer 0
 */
/********************************************************/
/*
 * Timer 0 Configuration Register
 */
#define TCCR0_REG		*((volatile uint8 *)0x53)

/*
 * 	Timer 0 Overflow Register
 */
#define TCNT0_REG		*((volatile uint8 *)0x52)

/*
 * Timer 0 Compare Match Register
 */
#define OCR0_REG		*((volatile uint8 *)0x5C)

/*
 * RESET Timer 0 and Timer 1 Prescaler on setting Bit 0
 */
#define SFIOR_REG		*((volatile uint8 *)0x50)
/********************************************************/
/*
 * TIMER 2
 */
/********************************************************/
/*
 * Timer 2 Register Configuration
 */
#define TCCR2_REG		*((volatile uint8 *)0x45)

/*
 * 	Timer 2 Overflow Register
 */
#define TCNT2_REG		*((volatile uint8 *)0x44)

/*
 * Timer 2 Compare Match Register
 */
#define OCR2_REG		*((volatile uint8 *)0x43)
/********************************************************/

/*
 * General Timer Registers
 */
/*
 * Timers Interrupt Configuration Register
 */
#define TIMSK_REG		*((volatile uint8 *)0x59)

/*
 * Timers Interrupt Flags
 */
#define TIFR_REG		*((volatile uint8 *)0x58)
/*************************************************************************************************************/
/*
 *
 */
/*************************************			Timer 1 Registers 			***********************************/
#define TCCR1A_REG		*((volatile uint8 *)0x4F)

#define TCCR1B_REG		*((volatile uint8 *)0x4E)

#define TCNT1L_REG		*((volatile uint8 *)0x4C)

#define TCNT1H_REG		*((volatile uint8 *)0x4D)

#define TCNT1_REG		*((volatile uint16 *)0x4C)

#define OCR1AL_REG		*((volatile uint8 *)0x4A)

#define OCR1AH_REG		*((volatile uint8 *)0x4B)

#define OCR1A_REG		*((volatile uint16 *)0x4A)

#define OCR1BL_REG		*((volatile uint8 *)0x48)

#define OCR1BH_REG		*((volatile uint8 *)0x49)

#define OCR1B_REG		*((volatile uint16 *)0x48)

#define ICR1L_REG		*((volatile uint8 *)0x46)

#define ICR1H_REG		*((volatile uint8 *)0x47)

#define ICR1_REG		*((volatile uint16 *)0x46)










#endif /* MCAL_TIMER_COUNTER_TIMER_COUNTER_REG_H_ */
