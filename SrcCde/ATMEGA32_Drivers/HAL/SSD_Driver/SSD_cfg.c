/*
* File:    SSD_cfg.c
* Author:  Yasmin Amr
* Created: 12/16/2023
* Brief:   SSD Driver
* Target:  Atmega32
* Version: 1.00
*/

#include "../../LIB/std_types.h"
#include "../../MCAL/DIO_Driver/DIO.h"
#include "SSD_cfg.h"

/**
 *
 * Specify the Port Number, Pin Number, and SSD State for each segment in the following Way:
 * [SEGMENT_ONE_NAME] = {
 *   .State=
 *	 .LED_A.Port=
 *	 .LED_A.Pin= 
 *
 *	 .LED_B.Port=
 *	 .LED_B.Pin=
 *
 *    .....................
 *
 *   .LED_DOT.Port=
 *	 .LED_DOT.Pin=
 *  },
 *
 * [SEGMENT_TWO_NAME]= {
 *    .State=
 *	  ............... 
 *    }
 *
 * Pin and Port configurations for each SSD contains 7 LEDs (LED_A,LED_B,LED_C,LED_D,LED_E,LED_F,LED_G,LED_DOT)
 *
 * For each PORT, select .LED_X.Port from options:
 *		1) DIO_enumPortA
 *		2) DIO_enumPortB
 *		3) DIO_enumPortC
 *		4) DIO_enumPortD
 *
 * For each PIN, select .LED_X.Pin from options:
 *		1) DIO_enumPin0
 *		2) DIO_enumPin1
 *		3) DIO_enumPin2
 *		4) DIO_enumPin3
 *		5) DIO_enumPin4
 *		6) DIO_enumPin5
 *		7) DIO_enumPin6
 *		8) DIO_enumPin7
 *
 */

SSD_strSegmentCfg_t SSD_strSegmentsArrCfg[SEG_NUM]=
{
	[FIRST_SEG]=
	{
		.State= SSD_enumCommonAnode,	
		.LED_A.Port=DIO_enumPortA,
		.LED_A.Pin=DIO_enumPin0,
		
		.LED_B.Port=DIO_enumPortA,
		.LED_B.Pin=DIO_enumPin1,
		
		.LED_C.Port=DIO_enumPortA,
		.LED_C.Pin=DIO_enumPin2,
		
		.LED_D.Port=DIO_enumPortA,
		.LED_D.Pin=DIO_enumPin3,
		
		.LED_E.Port=DIO_enumPortA,
		.LED_E.Pin=DIO_enumPin4,
		
		.LED_F.Port=DIO_enumPortA,
		.LED_F.Pin=DIO_enumPin5,
		
		.LED_G.Port=DIO_enumPortA,
		.LED_G.Pin=DIO_enumPin6,
		
		.LED_DOT.Port=DIO_enumPortA,
		.LED_DOT.Pin=DIO_enumPin7
	},
	
	[SECOND_SEG]=
	{
		.State= SSD_enumCommonCathode,
		
		.LED_A.Port=DIO_enumPortB,
		.LED_A.Pin=DIO_enumPin0,
		
		.LED_B.Port=DIO_enumPortB,
		.LED_B.Pin=DIO_enumPin1,
		
		.LED_C.Port=DIO_enumPortB,
		.LED_C.Pin=DIO_enumPin2,
		
		.LED_D.Port=DIO_enumPortB,
		.LED_D.Pin=DIO_enumPin3,
		
		.LED_E.Port=DIO_enumPortB,
		.LED_E.Pin=DIO_enumPin4,
		
		.LED_F.Port=DIO_enumPortB,
		.LED_F.Pin=DIO_enumPin5,
		
		.LED_G.Port=DIO_enumPortB,
		.LED_G.Pin=DIO_enumPin6,
		
		.LED_DOT.Port=DIO_enumPortB,
		.LED_DOT.Pin=DIO_enumPin7
	}
};
