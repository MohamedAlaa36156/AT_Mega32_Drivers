/*
 * int_conf.h
 *
 *  Created on: 15 Jan 2023
 *      Author: Ahmed
 */

#ifndef MCAL_EXT_INT_INT_CONF_H_
#define MCAL_EXT_INT_INT_CONF_H_
/*
 *
 *	SENSE CONTROL
 *	******************
// *	LOW_LEVEL_INT_REQ
// *	ANY_LOGICAL_LEVEL
// *	FALLING_EDGE
// *	RISING_EDGE
 *
 *
 *
 *	INT_0_LOW_LEVEL_REQ
 *	INT_0_ANY_LOGICAL_LEVEL
 *	INT_0_FALLING_EDGE
 *	INT_0_RISING_EDGE
 *
 *
 *	INT_1_LOW_LEVEL_REQ
 *	INT_1_ANY_LOGICAL_LEVEL
 *	INT_1_FALLING_EDGE
 *	INT_1_RISING_EDGE
 */

#define INT_0_SENSE_CONTROL	INT_0_LOW_LEVEL_REQ
#define INT_1_SENSE_CONTROL	INT_1_LOW_LEVEL_REQ
#define INT_2_SENSE_CONTROL	FALLING_EDGE

#endif /* MCAL_EXT_INT_INT_CONF_H_ */
