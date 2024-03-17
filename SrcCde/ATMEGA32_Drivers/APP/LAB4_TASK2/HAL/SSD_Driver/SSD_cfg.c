/*
 * SSD_cfg.c
 *
 * Created: 12/16/2023 2:49:21 PM
 *  Author: Yasmin Amr
 */ 

#include "../../LIB/std_types.h"
#include "../../MCAL/DIO_Driver/DIO.h"
#include "SSD_cfg.h"

SSD_strSegmentCfg_t SSD_strSegmentsArrCfg[SEG_NUM]=
{
	[FIRST_SEG]=
	{
		.State= SSD_enumCommonCathode,	
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
	},
	
	
};
