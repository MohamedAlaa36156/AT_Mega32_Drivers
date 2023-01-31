/*
 * int_reg.h
 *
 *  Created on: 13 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_EXT_INT_INT_REG_H_
#define MCAL_EXT_INT_INT_REG_H_




#define GICR_REG		*((volatile uint8 *)0x5B)
/*
 * 			Most 3 Bits to Enable the Interrupts (INT0,INT1,INT2)
 * 			INT0 BIT#6
 * 			INT1 BIT#7
 * 			INT2 BIT#5
 *
 * 			IVCEL	BIT#1  Selects Interrupt Vector Location 	(0) at the start of FLash Memory
 * 																(1) the beginning of the BootLoader section of the Flash.
 * 			IVCE	BIT#0	DONT KNOW YET...
 *
 *
 */

#define GIFR_REG		*((volatile uint8 *)0x5A)

/*
 * 			GIFR REGISTER:
 * 			MOST 3 Bits are for Interrupt Flags (INT0 INT1 INT2)
 * 			INT0 BIT#6
 * 			INT1 BIT#7
 * 			INT2 BIT#5
 * 			Mostly used if u want to clear interrupt flags.
 *
 */


#define MCUCR_REG		*((volatile uint8 *)0x55)
/*
 * 		INTERRUPT 1 and 2 Actions
 * 		MCUCR		BIN0,BIN1 for External Interrupt 0 State
 * 		MCUCR		BIN2,BIN3 for External Interrupt 1 State
 *
 * 		0 0 The low level of INT0 generates an interrupt request.
 *		0 1 Any logical change on INT0 generates an interrupt request.
 *		1 0 The falling edge of INT0 generates an interrupt request.
 *		1 1 The rising edge of INT0 generates an interrupt request.
 */



#define MCUCSR_REG		*((volatile uint8 *)0x54)
/*	INTERRUPT 2 Action
 * 	MCUCSR		BIN6	if 0	INT 2 Acts at Falling Edge
 * 	MCUCSR		BIN6	if 1	INT 2 Acts at Rising Edge
 */
#define SREG_REG		*((volatile uint8 *)0x5F)

/*		Global Interrupt Enable
 * 		SREG	BIN7	if 0 	Global Interrupt Disabled
 * 		SREG	BIN7	if 1 	Global Interrupt Enabled
 */









#endif /* MCAL_EXT_INT_INT_REG_H_ */
