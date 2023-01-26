/*
 * main.c
 *
 *  Created on: Dec 23, 2022
 *      Author: thund
 */

#include "../SERV/stdtypes.h"
//#include "../HAL/KEYPAD/keypad_cfg.h"
#include "../MCAL/DIO/dio_int.h"
#include "../MCAL/EXT_INT/int_int.h"
#include "../HAL/LED_BUZZER/led_buzz_cfg.h"
//#include "../HAL/LCD/lcd_cfg.h"
#include "util/delay.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include "../SERV/bit_math.h"
//ISR(INT2_vect){
//	DIO_u8TOG_Pin_Val(PORT_D,PIN_4);
//
//}


//ISR(TIMER0_OVF_vect)
//{
//	static uint8 OVF_COUNTS=0;
//	OVF_COUNTS++;
//	if(OVF_COUNTS==31)
//	{
//		TCNT0=124;
//		DIO_u8TOG_Pin_Val(PORT_D,PIN_4);
//		OVF_COUNTS=0;
//	}
//
//}



//	TCNT0 = 0;
//
//		TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
//
//		while(!(TIFR & (1<<TOV0)));
//
//		TIFR |= (1<<TOV0);
//
//		TCCR0 = 0 ;
//	void timer_0(void)
//	{
//		TCNT0=0;
//	}
//
////	DIO_u8Set_Pi n_Val(PORT_B,PIN_2,PUE);
//	DIO_u8Set_Pin_Dir(PORT_D,PIN_4,OUTPUT);
//    EXT_INT_Global_Enable();
////    EXT_INT_2_Enable();
//
//    while(1)
//    {
//
//    }
//}


#include <avr/io.h>
#include <avr/interrupt.h>

void timer1_init()
{
    // initialize counter
    TCNT1 = 0;


    TIMSK |= (1 << OCIE1A) | (1 << OCIE1B) ;

	// set up timer with prescaler = 1024 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS12)|(1 << CS10);

    // initialize compare value
    OCR1A = 7812;

    SREG |= (1<<7);
}
void timer0_init()
{
    // initialize counter
    TCNT0 = 0;

//    SET_BIT(TIMSK,OCIE0);
//    TIMSK |= (1 << OCIE0) ;



    // initialize compare value

    EXT_INT_Global_Enable();
//    SREG |= (1<<7);
	// set up timer with prescaler = 1024 and CTC mode

    SET_BIT(TCCR0,WGM01);
    SET_BIT(TCCR0,WGM00);

    SET_BIT(TCCR0,COM00);
    SET_BIT(TCCR0,COM01);

    CLR_BIT(TCCR0,CS00);
    SET_BIT(TCCR0,CS01);
    CLR_BIT(TCCR0,CS02);

//    TCCR0 |= (1 << WGM01)|(1 << CS02)|(1 << CS00);
}


//ISR(TIMER0_COMP_vect)
//{
//	static uint8 ovf_count=0;
//	ovf_count++;
//	if(ovf_count==40)
//	{
//		PORTC ^= (1 << 0);
//		ovf_count=0;
//	}
//
//}

	void main(void)
	{
	//    DDRC |= (1 << 0);
		DIO_u8Set_Pin_Dir(PORT_B,PIN_3,OUTPUT);


		timer0_init();
		uint16 i;
		// loop forever
		while(1)
		{
			for(i=0;i<=255;i++)
			{
				OCR0=i;
				_delay_ms(50);
			}
			for(i=255;i>=1;i--)
			{
				OCR0=i;
				_delay_ms(50);
			}
	//    	for(i=255;i>=0;i--)
	//    	{
	//    		OCR0=i;
	//    		_delay_ms(50);
	//    	}
		}
	}
//	void Timer_0(void)
//	{
//		TCNT0 = 0;
//
//		TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
//
//		while(!(TIFR & (1<<TOV0)));
//
//		TIFR |= (1<<TOV0);
//
//		TCCR0 = 0 ;
//
//	}
//	void main(void)
//	{
//		uint8 count = 0;
//		DDRB |= (1<<PB0);
//		PORTB &= ~(1<<PB0);
//
//		while(1)
//		{
//			PORTB |= (1<<PB0);
//
//			for(count= 0 ; count < 31 ; count++)
//			{
//				Timer_0();
//			}
//
//			PORTB &= ~(1<<PB0);
//
//			for(count = 0 ; count < 31 ; count++)
//			{
//				Timer_0();
//			}
//
//		}
//	}

//
//
//ISR(INT0_vect)
//{
//	Led_Pin_u8Tog_Val();
//}
//
//
//
//int main()
//{
//	EXT_INT_Global_Enable();
//	EXT_INT_0_Enable();
//	Led_Pin_u8Set_Dir();
//	DIO_u8Set_Pin_Val(PORTD,PIN2,PUE);
//
//	while (1)
//	{
//
//	}
//
//
//}
//



//#include "../HAL/LED_BUZZER/led_buzz_cfg.h"

//#include "avr/io.h"
//#include "avr/interrupt.h"
//
//
//ISR(INT0_vect)
//{
//	PORTA ^= (1<<PA0);
//}
//
///*
// * ISR(_VECTOR(1))
//{
//
//}
// */
///*
// * ISR(__vector_1)
//{
//
//}
// */
//
//void main(void)
//{
//	//select LED as output (PA0)
//	DDRA |= (1<<PA0);
//	//activate Pullup for INT0
//	PORTD |= (1<<PD2);
//
//	//select sense cntrl for INT0 "any logical change"
//	MCUCR &= ~(1<<ISC01);
//	MCUCR |= (1<<ISC00);
//
//	//Enable PIE for INT0
//	GICR |=(1<<INT0);
//
//	//Enable GIE
//	SRE

