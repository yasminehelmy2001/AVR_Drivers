/*
 * SWITCH_cfg.c
 *
 * Created: 12/12/2023 12:21:38 PM
 *  Author: yasmi
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
	 .Port=
	 .Pin= 
	 .InputState=
	},
 */
	[FIRST_SWITCH]= {
		.Port= DIO_enumPortD,
		.Pin= DIO_enumPin0,
		.InputState= SWITCH_enumInputInternalPU
	},
	[SECOND_SWITCH]={
		.Port= DIO_enumPortD,
		.Pin= DIO_enumPin1,
		.InputState=SWITCH_enumInputInternalPU
	},
	[THIRD_SWITCH]={
		.Port= DIO_enumPortD,
		.Pin= DIO_enumPin2,
		.InputState=SWITCH_enumInputInternalPU
	}
};