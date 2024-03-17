/*
* File:    KEYPAD_cfg.c
* Author:  Yasmin Amr
* Created: 1/8/2024
* Brief:   KEYPAD Driver
* Target:  Atmega32
* Version: 1.00
*/

#include "KEYPAD.h"

/**
 * In this array, use the Keypad Row Macros for the Index Name,
 * Write the values you want your keypad to display in each Row (Between single quotations!)
 * Note: The values in each row must equal the Keypad Column Size!
 * Example:
 *	 #define KEYPAD_ROW_SIZE		3
 *	 #define KEYPAD_COLUMN_SIZE		3 
 *
 * u8 KEYPAD_u8Keys[KEYPAD_ROW_SIZE][KEYPAD_COLUMN_SIZE]=
 *	{
 *		[ROW_ONE]={'7','8','9'},
 *		[ROW_TWO]={'4','5','6'},
 *		[ROW_THREE]={'1','2','3'}
 *	}
 */

u8 KEYPAD_u8Keys[KEYPAD_ROW_SIZE][KEYPAD_COLUMN_SIZE]=
{
	[ROW_ONE]={'7','8','9','/'},
	[ROW_TWO]={'4','5','6','*'},
	[ROW_THREE]={'1','2','3','-'},
	[ROW_FOUR]={' ','0','=','+'}
};

/**
 * Specify the Port Number, Pin Number, for each keypad row in the following way:
 *		[ROW_ONE] = 
 *		{
 *			.Port=
 *			.Pin= 
 *		},
 *		[ROW_TWO] =
 *		{
 *			.Port=
 *			.Pin=
 *		}
 *
 * NOTE: Use the ROW Macros for Index Name
 *
 * For each PORT, select from options:
 *		1) DIO_enumPortA
 *		2) DIO_enumPortB
 *		3) DIO_enumPortC
 *		4) DIO_enumPortD
 *
 * For each PIN, select from options:
 *		1) DIO_enumPin0
 *		2) DIO_enumPin1
 *		3) DIO_enumPin2
 *		4) DIO_enumPin3
 *		5) DIO_enumPin4
 *		6) DIO_enumPin5
 *		7) DIO_enumPin6
 *		8) DIO_enumPin7
 */
KEYPAD_strConfig KEYPAD_strRowConfigArray [KEYPAD_ROW_SIZE]=
{
	[ROW_ONE]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin0
	},
	[ROW_TWO]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin1
	},
	[ROW_THREE]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin2
	},
	[ROW_FOUR]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin3
	}
};

/**
 * Specify the Port Number, Pin Number, for each keypad column in the following way:
 *		[COL_ONE] = 
 *		{
 *			.Port=
 *			.Pin= 
 *		},
 *		[COL_TWO] =
 *		{
 *			.Port=
 *			.Pin=
 *		}
 *
 * NOTE: Use the COLUMN Macros for Index Name
 *
 * For each PORT, select from options:
 *		1) DIO_enumPortA
 *		2) DIO_enumPortB
 *		3) DIO_enumPortC
 *		4) DIO_enumPortD
 *
 * For each PIN, select from options:
 *		1) DIO_enumPin0
 *		2) DIO_enumPin1
 *		3) DIO_enumPin2
 *		4) DIO_enumPin3
 *		5) DIO_enumPin4
 *		6) DIO_enumPin5
 *		7) DIO_enumPin6
 *		8) DIO_enumPin7
 */
KEYPAD_strConfig KEYPAD_strColConfigArray [KEYPAD_COLUMN_SIZE]=
{
	[COL_ONE]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin4
	},
	[COL_TWO]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin5
	},
	[COL_THREE]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin6
	},
	[COL_FOUR]=
	{
		.Port= DIO_enumPortC,
		.Pin= DIO_enumPin7
	}
};