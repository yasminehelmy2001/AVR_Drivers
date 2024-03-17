/*
* File:    SWITCH_cfg.c
* Author:  Yasmin Amr
* Created: 12/12/2023
* Brief:   SWITCH Driver
* Target:  Atmega32
* Version: 1.00
*/

#include "../../MCAL/DIO_Driver/DIO.h"
#include "SWITCH_cfg.h"

/**
 *@brief : Allocated a Global Array to Set SWITCH Configurations                                           
 */
SWITCH_strSwitchCfg_t SWITCH_strSwitchArrCfg[SWITCH_COUNT]=
{
/* Specify the Port Number, Pin Number, InputState in the Following Way:
 * [SWITCH_ONE_NAME] = {
 *	 .Port=
 *	 .Pin= 
 *	 .InputState=
 *	},
 *
 * For each PORT, select .Port from options:
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
 * For each Input State, select .InputState from options:
 *
 *		1)SWITCH_enumInputInternalPU
 *		2)SWITCH_enumInputExternalPD
 */
 
	[START_SWITCH]= {
		.Port= DIO_enumPortA,
		.Pin= DIO_enumPin0,
		.InputState= SWITCH_enumInputInternalPU
	},
	[STOP_SWITCH]={
		.Port= DIO_enumPortA,
		.Pin= DIO_enumPin1,
		.InputState=SWITCH_enumInputInternalPU
	}
};