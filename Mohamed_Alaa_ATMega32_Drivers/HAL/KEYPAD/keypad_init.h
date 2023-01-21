/*
 * keypad_cfg.h
 *
 *  Created on: 7 Jan 2023
 *      Author: Ahmed
 */

#ifndef HAL_KEYPAD_KEYPAD_INIT_H_
#define HAL_KEYPAD_KEYPAD_INIT_H_




//#define COLUMN_START	PINC1
//#define COLUMN_END		PINC4

//#define	ROW_START		PINR1
//#define ROW_END			PINR4

//#define KEYPAD_NO_COL		4
//#define KEYPAD_NO_ROW		4



#define KEYPAD_ROWS			4
#define KEYPAD_COLS			4

#define KEYPAD_PERIODIC		1
#define KEYPAD_POLLING		2


#define KEY_NOT_PRESSED		0xFF



void Keypad_Int(void);
uint8 Keypad_u8Selector(void);




#endif /* HAL_KEYPAD_KEYPAD_INIT_H_ */
