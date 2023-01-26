
/*
 * main.c
 *
 *  Created on: 14 Jan 2023
 *      Author: Ahmed
 */

/*
 * main.c
 *
 *  Created on: Dec 23, 2022
 *      Author: thund
 */

#include "../SERV/stdtypes.h"
#include "../MCAL/DIO/dio_int.h"
#include "../MCAL/EXT_INT/int_int.h"
//#include "../HAL/LED_BUZZER/led_buzz_cfg.h"
#include "../HAL/LCD/lcd_cfg.h"
#include "util/delay.h"
#include "avr/interrupt.h"
#include "../SERV/bit_math.h"
#include "../MCAL/ADC/adc_init.h"
#include "../MCAL/TIMER_COUNTER/timer_counter_int.h"
uint8 T1ovf=0;
uint32 Ton_tick=0;
uint32 Ttot_tick=0;
ISR(TIMER1_OVF_vect)
{
	T1ovf++;
}
ISR(TIMER1_CAPT_vect)
{
	static uint8 state=0;
	if(state ==0)
	{
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,ICES1);
		state=1;

	}
	else if(state==1)
	{

		Ton_tick=(ICR1+(T1ovf*65536));
		SET_BIT(TCCR1B,ICES1);

		state=2;
	}
	else if(state==2)
	{
		Ttot_tick=(ICR1+(T1ovf*65536));

		//ICR1=0;
/*->*/	TCNT1=0;
		CLR_BIT(TCCR1B,ICES1);
		T1ovf=0;
		state=1;
	}


	//
	//ISR(TIMER0_OVF_vect)
	//{
	//	static uint8 counter=0;
	//	counter++;
	//	if(counter==30)
	//	{
	//
	//		counter=0;
	//		DIO_u8TOG_Pin_Val(PORT_A,PIN_0);
	//
	//	}
	//}
	//
	//ISR(TIMER1_CAPT_vect)
	//{
	//
	//}
	//
	//
	//void __vector_10 (void) __attribute__ ((signal,__INTR_ATTRS));
	//void __vector_10 (void)
	//{
	//	static uint8_t OVF_counts = 0 ;
	//	OVF_counts++;
	//	if(OVF_counts == 40)
	//	{
	//
	//		PORTA ^=(1<<PA0);
	//		OVF_counts = 0;
	//	}
	//}
	//
	//ISR(TIMER0_COMP_vect)
	//{
	//
	//}
	//void timer0_init()
	//{
	//    // initialize counter
	//    TCNT0 = 0;
	//
	////    SET_BIT(TIMSK,OCIE0);
	////    TIMSK |= (1 << OCIE0) ;
	//
	//
	//
	//    // initialize compare value
	//
	//    EXT_INT_Global_Enable();
	//	// set up timer with prescaler = 1024 and CTC mode
	//
	//    SET_BIT(TCCR0,WGM01);
	//    SET_BIT(TCCR0,WGM00);
	//
	//    SET_BIT(TCCR0,COM00);
	//    SET_BIT(TCCR0,COM01);
	//
	//    CLR_BIT(TCCR0,CS00);
	//    SET_BIT(TCCR0,CS01);
	//    CLR_BIT(TCCR0,CS02);
	//
	//
	//}
	//
	//
	//void main(void)
	//{
	//	DIO_u8Set_Pin_Dir(PORT_B,PIN_3,OUTPUT);
	////	DIO_u8Set_Pin_Dir(PORT_D,PIN_6,INPUT);
	//	DIO_u8Set_Pin_Val(PORT_B,PIN_3,PUE);
	//	LCD_Init();
	////	LCD_Write_INT();
	//	timer0_init();
	//	OCR0=200;
	//
	//
	//	TCCR1A = 0;
	//	TCNT1=0;
	//	TIFR = (1<<ICF1);
	//	TCCR1B = 0x41;
	//
	////	DDRA = 0x01;
	//	OCR0 = 195 ;
	//	TIMSK |= (1<<OCIE0);
	//	SREG |= (1<<7);
	//	TCCR0 |= (1<<WGM01); // CTC Mode
	//
	//	TCCR0 |= (1<<CS00) | (1<<CS02) ;
	//	while(1)
	//	{
	//
	//	}
	//
	//}
	//int main(void)
	//{
	//
	//
	//
	//	while(1)
	//	{
	////
	//	}
	//	return 0;
	//
	//}
	//#include "../SERV/stdtypes.h"
	////#include "../MCAL/ADC/ADC.h"
	//#include "avr/io.h"
	//#include "util/delay.h"
	//int main(void)
	//{
	//	int i=0;
	//	DDRD |= (1<<PD5);	/* Make OC1A pin as output */
	//	TCNT1 = 0;
	//	ICR1 = 20000;
	//	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/8 */
	//	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	//	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS11);
	//	while(1)
	//	{
	//		for(i=1000;i<2000;i++)
	//		{
	//			OCR1A =i ;
	//			_delay_ms(1);
	//		}
	//		for(i=2000;i>1000;i--)
	//		{
	//			OCR1A = i;
	//			_delay_ms(1);
	//
	//		}
	//	}
	//}




	/*
	 * main.c
	 *
	 *  Created on: Dec 24, 2022
	 *      Author: Farid
	 */
	//#include"avr/io.h"
	//#include"avr/delay.h"



	//
	//void main(void)
	//{
	//	DDRA = 0b00000001;
	//	PORTA = 0x01 ;
	//	_delay_ms(1000);
	//	PORTA = 0x00 ;
	//	/*
	//	 * select WDG prescaller (timeout = 2.1s)
	//	 */
	//	WDTCR |= (1<<0) |(1<<1) |(1<<2);
	//
	//	/*
	//	 * Enable WDG
	//	 */
	//	WDTCR |=(1<<WDE);
	//
	//
	//	while(1)
	//	{
	//		__asm__("wdr");
			//WDTCR |=(1<<WDTOE)|(1<<WDE);
			//WDTCR  = 0b00010111;
			//WDTCR |=(1<<WDE)|(1<<0) |(1<<1) |(1<<2);
			//(*(volatile uint8_t *)0x41
}

ISR(TIMER0_COMP_vect)
{
//	static uint8 count=0;
//	static uint8 state=1;
//	if(state==1)
//	{
//		OCR0=count++;
//		if (count==255)
//		{
//			state=0;
//		}
//	}
//	else if(state==0)
//	{
//		OCR0=count--;
//		if (count==0)
//		{
//			state=1;
//		}
//	}
	OCR0=200;
//	LCD_WRITE_STRING("INPUT: ");
//	LCD_Write_INT(OCR0);
//	_delay_ms(50);


}
void timer1_init(void)
{
//	CLR_BIT(TCCR1A,WGM10);
//	CLR_BIT(TCCR1A,WGM11);
//	CLR_BIT(TCCR1A,COM1A0);
//	CLR_BIT(TCCR1A,COM1A1);
//	CLR_BIT(TCCR1A,COM1B0);
//	CLR_BIT(TCCR1A,COM1B1);
//	CLR_BIT(TCCR1B,WGM13);
//	CLR_BIT(TCCR1B,WGM12);
//	CLR_BIT(TCCR1B,ICNC1);
	SET_BIT(TCCR1B,ICES1);
//	TCNT1=0;
	SET_BIT(TIMSK,TICIE1);
	SET_BIT(TIMSK,TOIE1);


//	CLR_BIT(TCCR1B,CS12);
//	CLR_BIT(TCCR1B,CS11);

}

int main(void)
{


	LCD_Init();
	DIO_u8Set_Pin_Dir(PORT_B,PIN_3,OUTPUT);
	Timer_0_Init();
	DIO_u8Set_Pin_Dir(PORT_D,PIN_6,INPUT);
	DIO_u8Set_Pin_Val(PORT_D,PIN_6,PUE);
//	TIFR = (1<<ICF1); /* Clear ICF (Input Capture flag) flag */
//	SET_BIT(TIMSK,TOIE1);
	timer1_init();

	while(1)

	{

		LCD_JMP_UP_Left();
		LCD_WRITE_STRING("ON:200");
		LCD_WRITE_STRING("TON:");
		LCD_Write_INT(Ton_tick);
		LCD_JMP_Bottom_Left();
		LCD_WRITE_STRING("TOT:256");
		LCD_WRITE_STRING("T_tot:");
		LCD_Write_INT(Ttot_tick);
//		_delay_ms(50);
//		LCD_CLR_SCR();
	}
	return 0;
}
//
//ISR(TIMER0_OVF_vect)
//{
//	static uint8 counter=0;
//	counter++;
//	if(counter==30)
//	{
//
//		counter=0;
//		DIO_u8TOG_Pin_Val(PORT_A,PIN_0);
//
//	}
//}
//
//ISR(TIMER1_CAPT_vect)
//{
//
//}
//
//
//void __vector_10 (void) __attribute__ ((signal,__INTR_ATTRS));
//void __vector_10 (void)
//{
//	static uint8_t OVF_counts = 0 ;
//	OVF_counts++;
//	if(OVF_counts == 40)
//	{
//
//		PORTA ^=(1<<PA0);
//		OVF_counts = 0;
//	}
//}
//
//ISR(TIMER0_COMP_vect)
//{
//
//}
//void timer0_init()
//{
//    // initialize counter
//    TCNT0 = 0;
//
////    SET_BIT(TIMSK,OCIE0);
////    TIMSK |= (1 << OCIE0) ;
//
//
//
//    // initialize compare value
//
//    EXT_INT_Global_Enable();
//	// set up timer with prescaler = 1024 and CTC mode
//
//    SET_BIT(TCCR0,WGM01);
//    SET_BIT(TCCR0,WGM00);
//
//    SET_BIT(TCCR0,COM00);
//    SET_BIT(TCCR0,COM01);
//
//    CLR_BIT(TCCR0,CS00);
//    SET_BIT(TCCR0,CS01);
//    CLR_BIT(TCCR0,CS02);
//
//
//}
//
//
//void main(void)
//{
//	DIO_u8Set_Pin_Dir(PORT_B,PIN_3,OUTPUT);
////	DIO_u8Set_Pin_Dir(PORT_D,PIN_6,INPUT);
//	DIO_u8Set_Pin_Val(PORT_B,PIN_3,PUE);
//	LCD_Init();
////	LCD_Write_INT();
//	timer0_init();
//	OCR0=200;
//
//
//	TCCR1A = 0;
//	TCNT1=0;
//	TIFR = (1<<ICF1);
//	TCCR1B = 0x41;
//
////	DDRA = 0x01;
//	OCR0 = 195 ;
//	TIMSK |= (1<<OCIE0);
//	SREG |= (1<<7);
//	TCCR0 |= (1<<WGM01); // CTC Mode
//
//	TCCR0 |= (1<<CS00) | (1<<CS02) ;
//	while(1)
//	{
//
//	}
//
//}
//int main(void)
//{
//
//
//
//	while(1)
//	{
////
//	}
//	return 0;
//
//}
//#include "../SERV/stdtypes.h"
////#include "../MCAL/ADC/ADC.h"
//#include "avr/io.h"
//#include "util/delay.h"
//int main(void)
//{
//	int i=0;
//	DDRD |= (1<<PD5);	/* Make OC1A pin as output */
//	TCNT1 = 0;
//	ICR1 = 20000;
//	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/8 */
//	TCCR1A = (1<<WGM11)|(1<<COM1A1);
//	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS11);
//	while(1)
//	{
//		for(i=1000;i<2000;i++)
//		{
//			OCR1A =i ;
//			_delay_ms(1);
//		}
//		for(i=2000;i>1000;i--)
//		{
//			OCR1A = i;
//			_delay_ms(1);
//
//		}
//	}
//}




/*
 * main.c
 *
 *  Created on: Dec 24, 2022
 *      Author: Farid
 */
//#include"avr/io.h"
//#include"avr/delay.h"



//
//void main(void)
//{
//	DDRA = 0b00000001;
//	PORTA = 0x01 ;
//	_delay_ms(1000);
//	PORTA = 0x00 ;
//	/*
//	 * select WDG prescaller (timeout = 2.1s)
//	 */
//	WDTCR |= (1<<0) |(1<<1) |(1<<2);
//
//	/*
//	 * Enable WDG
//	 */
//	WDTCR |=(1<<WDE);
//
//
//	while(1)
//	{
//		__asm__("wdr");
		//WDTCR |=(1<<WDTOE)|(1<<WDE);
		//WDTCR  = 0b00010111;
		//WDTCR |=(1<<WDE)|(1<<0) |(1<<1) |(1<<2);
		//(*(volatile uint8_t *)0x41
