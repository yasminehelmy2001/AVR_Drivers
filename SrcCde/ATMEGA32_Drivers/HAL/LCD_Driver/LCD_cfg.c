/*
* File:    LCD_cfg.c
* Author:  Yasmin Amr
* Created: 1/1/2024
* Brief:   LCD Driver
* Target:  Atmega32
* Version: 1.00
*/

/**
 *@Note: Configuring an array of struct in this way with macros does the following:
 *       1) Created a struct for each pin , access struct by array index
 *       2) DIO Driver configures the ports and pins as intended
		 3) Readability: Instead of calling struct by array index 0,1,2, I call them using PIN names , for ex: LCD_strPinCfgArr[RS_PIN].Port
 */

#include "LCD_cfg.h"

/* For 8-BIT Mode, Select Port,Pin, and Pin Configuration for RS PIN, RW PIN, E PIN, AND D0-D7 PINS
 * For 8-BIT Mode, Select Port,Pin, and Pin Configuration for RS PIN, RW PIN, E PIN, AND D4-D7 PINS
 *
 * For each PIN, select .Port from options:
 *		1) DIO_enumPortA
 *		2) DIO_enumPortB
 *		3) DIO_enumPortC
 *		4) DIO_enumPortD
 *
 * For each PIN, select .Pin from options:
 *		1) DIO_enumPin0
 *		2) DIO_enumPin1
 *		3) DIO_enumPin2
 *		4) DIO_enumPin3
 *		5) DIO_enumPin4
 *		6) DIO_enumPin5
 *		7) DIO_enumPin6
 *		8) DIO_enumPin7
 *
 * For each PIN, select .PinCfg from options:
 *		1) DIO_enumOutput
 */
#if ((INIT_MODE == EIGHT_BIT_MODE) || (INIT_MODE ==FOUR_BIT_MODE))

	LCD_strPinCfg_t LCD_strPinCfgArr[]=
	{
			[RS_PIN]=
			{
				.Port= DIO_enumPortA,
				.Pin= DIO_enumPin0,
				.PinCfg=DIO_enumOutput
			},
			[RW_PIN]=
			{
				.Port=DIO_enumPortA,
				.Pin=DIO_enumPin1,
				.PinCfg=DIO_enumOutput
			},
			[E_PIN]=
			{
				.Port=DIO_enumPortA,
				.Pin=DIO_enumPin2,
				.PinCfg=DIO_enumOutput
			},
			
		#if INIT_MODE==EIGHT_BIT_MODE
		
			[D0_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin0,
				.PinCfg=DIO_enumOutput
			},
			[D1_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin1,
				.PinCfg=DIO_enumOutput
			},
			[D2_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin2,
				.PinCfg=DIO_enumOutput
			},
			[D3_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin3,
				.PinCfg=DIO_enumOutput
			},
			
		#endif
		
			[D4_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin4,
				.PinCfg=DIO_enumOutput
			},
			[D5_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin5,
				.PinCfg=DIO_enumOutput
			},
			[D6_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin6,
				.PinCfg=DIO_enumOutput
			},
			[D7_PIN]=
			{
				.Port=DIO_enumPortB,
				.Pin=DIO_enumPin7,
				.PinCfg=DIO_enumOutput
			}
	};
	
#endif


