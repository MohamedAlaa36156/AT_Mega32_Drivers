/*
 * SPI_Config.h
 *
 *  Created on: Jan 29, 2023
 *      Author: thund
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_
/****************************************************************************/
/*																			*/
/* 								SPI_CONFIGURATIONS							*/
/*																			*/
/****************************************************************************/
/****************************************************************************/
/*						SPI	Transmission Order								*/
/* 						**********************								*/
/*	SPI_MSB_TRANSMIT														*/
/*	SPI_LSB_TRANSMIT   						                                */
/************************************************************************** */

#define SPI_DATA_TRANSMIT_ORDER		SPI_MSB_TRANSMIT


/****************************************************************************/
/*																			*/
/*	SPI_PRESCALER_4															*/
/*	SPI_PRESCALER_16			                                  			*/
/*	SPI_PRESCALER_64			                                    		*/
/*	SPI_PRESCALER_128			                                    		*/
/*	SPI_HIGH_SPEED_PRESCALER_2	                                    		*/
/*	SPI_HIGH_SPEED_PRESCALER_8	                                    		*/
/*	SPI_HIGH_SPEED_PRESCALER_32                                    			*/
/*	SPI_HIGH_SPEED_PRESCALER_64                                    			*/
/****************************************************************************/
#define SPI_CLOCK_SETUP	SPI_HIGH_SPEED_PRESCALER_2

/****************************************************************************/
/*						SPI	Clock Polarity									*/
/* 						**********************								*/
/*	RISING_CLOCK_POL														*/
/*	FALLING_CLOCK_POL   						                       		*/
/************************************************************************** */


#define SPI_CLOCK_POLATIRY		RISING_CLOCK_POL


/****************************************************************************/
/*						SPI	Clock Phase										*/
/* 						**********************								*/
/*	SAMPLING_CLOCK_PHASE													*/
/*	SETUP_CLOCK_PHASE   						                       		*/
/************************************************************************** */

#define SPI_CLOCK_PHASE				SAMPLING_CLOCK_PHASE


#endif /* MCAL_SPI_SPI_CONFIG_H_ */
