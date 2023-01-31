/*
 * main.c
 *
 *  Created on: Jan 29, 2023
 *      Author: thund
 */
#include "../SERV/bit_math.h"
#include "../SERV/stdtypes.h"
//#include "../MCAL/EXT_INT/int_int.h"
#include "../MCAL/TIMER_COUNTER/timer_counter_int.h"

#include "../MCAL/DIO/dio_int.h"
//#include "avr/io.h"
//#include "avr/interrupt.h"

void __vector_4(void) __attribute__((signal,__INTR_ATTRS));
void __vector_4 (void)
{
	static uint16 counter=0;
	counter++;
	if(counter==31)
	{
		DIO_u8TOG_Pin_Val(PORT_A,PIN_0);
		counter=0;
	}
}

//void Timer_0_test(void)
//{
//
//	SET_BIT(SREG,7);
//	TCNT0=124;
//
//	SET_BIT(TIMSK,TOIE0);
//	SET_BIT(TCCR0,CS00);
//	SET_BIT(TCCR0,CS02);
//}


int main(void)
{

	DIO_u8Set_Pin_Dir(PORT_B,PIN_3,OUTPUT);
	DIO_u8Set_Pin_Val(PORT_B,PIN_3,HIGH);
//	Timer_0_test();

	Timer_1_Init();
	Timer_1_Start_Count();

	while(1)
	{

	}
	return 0;

}

