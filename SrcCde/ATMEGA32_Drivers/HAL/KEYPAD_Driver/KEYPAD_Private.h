/*
 * KEYPAD_Private.h
 *
 * Created: 2/10/2024 1:08:08 AM
 *  Author: yasmi
 */ 


#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_

#include "KEYPAD_cfg.h"

/*******************************************************************************/
/*					ROW Macros based on Configuration						   */
/*******************************************************************************/

#if KEYPAD_ROW_SIZE==2
	#define ROW_ONE		0
	#define ROW_TWO		1
#endif

#if KEYPAD_ROW_SIZE==3
	#define ROW_ONE		0
	#define ROW_TWO		1
	#define ROW_THREE	2
#endif

#if KEYPAD_ROW_SIZE==4
	#define ROW_ONE		0
	#define ROW_TWO		1
	#define ROW_THREE	2
	#define ROW_FOUR	3
#endif

/*******************************************************************************/
/*					COLUMN Macros based on Configuration					   */
/*******************************************************************************/

#if KEYPAD_COLUMN_SIZE==2
	#define COL_ONE		0
	#define COL_TWO		1
#endif

#if KEYPAD_COLUMN_SIZE==3
	#define COL_ONE		0
	#define COL_TWO		1
	#define COL_THREE	2
#endif

#if KEYPAD_COLUMN_SIZE==4
	#define COL_ONE		0
	#define COL_TWO		1
	#define COL_THREE	2
	#define COL_FOUR	3
#endif

#endif /* KEYPAD_PRIVATE_H_ */