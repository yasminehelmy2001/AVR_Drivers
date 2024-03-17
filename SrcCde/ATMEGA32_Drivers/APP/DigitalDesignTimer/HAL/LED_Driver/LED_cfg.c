/*
* LED_cfg.c
*
* Created: 12/11/2023 8:35:40 PM
*  Author: Yasmin Amr
*/
#include "../../MCAL/DIO_Driver/DIO.h"
#include "LED_cfg.h"


/**
 *@brief : Allocated a Global Array to Set LED Configurations                                           
 */
LED_strLedCfg_t LED_strLedArrCfg[LED_COUNT]=
{
/* Specify the Port Number, Pin Number, OnOff State, and ActiveState in the following way:
 * [LED_ONE_NAME] = {
	 .Port=
	 .Pin= 
	 .OnOff=
	 .ActiveState=
	},
 */
	[START_LED]= {
		.Port= DIO_enumPortA,
		.Pin= DIO_enumPin0,
		.OnOff= LED_enumLedOn,
		.ActiveState=LED_enumActiveHigh
	},
	[STOP_LED]={
		.Port= DIO_enumPortA,
		.Pin= DIO_enumPin1,
		.OnOff= LED_enumLedOff,
		.ActiveState=LED_enumActiveHigh
	}
};