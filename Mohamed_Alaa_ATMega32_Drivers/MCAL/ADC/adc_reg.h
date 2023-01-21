/*
 * adc_reg.h
 *
 *  Created on: 18 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_


#define ADC_REG			*((volatile uint16 *)0x24)

#define ADCL_REG		*((volatile uint8 *)0x24)

#define ADCH_REG		*((volatile uint8 *)0x25)

#define ADCSRA_REG		*((volatile uint8 *)0x26)

#define ADMUX_REG		*((volatile uint8 *)0x27)



#define SFIOR_REG		*((volatile uint8 *)0x50)

#endif /* MCAL_ADC_ADC_REG_H_ */
