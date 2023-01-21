/*
 * adc_init.h
 *
 *  Created on: 18 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_

/*
 * ADMUX REGISTER
 */

/*
 * SELECT ADC CHANNEL AND GAIN
 */
#define ADMUX0	0
#define ADMUX1	1
#define ADMUX2	2
#define ADMUX3	3
#define ADMUX4	4
/****************/
/*
 * ADLAR -> EITHER SELECT LOW EIGHT BITS(IGNORING HIGHST 2) OR HIGH EIGHT BITS (IGNORING LOWEST 2)
 */
#define ADLAR	5
/***************/

/*
 * SELECT INPUT REFRENCE
 */
#define REFS0	6
#define REFS1	7
/***************/
/******************************/

/*
 * ADCSRA REGISTER
 */
/*
 * ADPS ->PRESCALER SELECTOR
 */
#define ADPS0	0
#define ADPS1	1
#define ADPS2	2
/***************/

/*
 * ADIE -> ADC INTERRUPT ENABLE
 */
#define ADIE	3
/**************/
/*
 *ADIF -> ADC INTERRUPT FLAG
 */
#define ADIF	4
/**************/

/*
 *ADATE ENABLES AUTO TRIGGER REFERED TO THE RUNNING MODE IN SFIOR REGISTER
 */
#define ADATE	5
/***************/

/*
 * ADSC -> ADC START CONVERSION MODE  (0 SINGLE CONVERSION MODE - 1 FREE RUNNING MODE)
 */
#define ADSC	6
/***************/

/*
 * ADEN -> ENABLE ADC
 */
#define ADEN	7
/***************/
/*******************************************/
#define ADC_ADJUST_RIGHT	0
#define ADC_ADJUST_LEFT		1


#define ADC_ADJUST_RESULT	ADC_ADJUST_RIGHT
/********************************************/



/**********************************************/
#define ADC_EXTERNAL_INPUT			1
#define ADC_INTERNAL_VCC			2
#define ADC_INTERNAL_2_56V			3

#define ADC_INPUT_REFRENCE		ADC_INTERNAL_VCC
/***********************************************/


/************************************************/
#define ADC_PRESCALER_2		1
#define ADC_PRESCALER_4		2
#define ADC_PRESCALER_8		3
#define ADC_PRESCALER_16	4
#define ADC_PRESCALER_32	5
#define ADC_PRESCALER_64	6
#define ADC_PRESCALER_128	7

#define ADC_PRESCALER_SELECTOR	ADC_PRESCALER_64

/************************************************/
/*
 * CHANNEL SELECTING
 */
#define CLEAR_MUX_MUSK			0xE0

#define SINGLE_ENDED_ADC0		0
#define SINGLE_ENDED_ADC1		1
#define SINGLE_ENDED_ADC2		2
#define SINGLE_ENDED_ADC3		3
#define SINGLE_ENDED_ADC4		4
#define SINGLE_ENDED_ADC5		5
#define SINGLE_ENDED_ADC6		6
#define SINGLE_ENDED_ADC7		7

#define ADC_MUX_CHANNEL_SELECTOR	SINGLE_ENDED_ADC0

/******************************************/
/*
 * CONVERSION MODE :
 * 1)SINGLE CONVERSION MODE
 * 2)INT CONVERSION MODE
 */

#define ADC_SINGLE_CONFERSION		55
#define ADC_AUTO_TRIGGER_SOURCE 	66

#define ADC_FREE_RUNNING_MODE		0x00
#define ADC_ANALOG_CMP_MODE			0x20
#define ADC_EXT_INT_REQ_MODE		0x40
#define ADC_TIMER_0_CMP_MODE		0x60
#define ADC_TIMER_0_OVF_MODE		0x80
#define ADC_TIMER_1_CMP__MODE		0xA0
#define ADC_TIMER_1_OVF_MODE		0xC0
#define ADC_TIMER_1_CPT_EVENT_MODE	0xE0

#define ADC_TRIGGER_MODE	ADC_EXT_INT_REQ_MODE

#define ADC_CONVERSION_MODE		ADC_SINGLE_CONFERSION

/**********************************************/
#define ADC_FREE_RUNNING__MODE			1
#define ADC_ANALOG_COMPARATOR_MODE		2
#define ADC_EXT_INT_REQ_0_MODE			3
#define ADC_TIMER_0_CMP_MATCH_MODE		4
#define ADC_TIMER_0_OVERFLOW_MODE		5
#define ADC_TIMER_1_CMP_MATCH_B_MODE	6
#define ADC_TIMER_1_OVERFLOW_MODE		7
#define ADC_TIMER_1_CAPTURE_EVENT_MODE	8

#define ADC_TRIGGER_SOURCE_MODE		ADC_FREE_RUNNING_MODE

/***********************************************/

void ADC_INIT(void);
uint16 ADC_u16_Read_(void);


#endif /* MCAL_ADC_ADC_INIT_H_ */
