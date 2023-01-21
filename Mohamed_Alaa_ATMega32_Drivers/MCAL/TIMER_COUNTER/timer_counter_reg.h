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


#endif /* MCAL_TIMER_COUNTER_TIMER_COUNTER_REG_H_ */
