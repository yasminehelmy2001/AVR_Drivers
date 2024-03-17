/*
* File:    SWITCH.h
* Author:  Yasmin Amr
* Created: 12/12/2023
* Brief:   SWITCH Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef SWITCH_H_
#define SWITCH_H_

#include "SWITCH_cfg.h"

typedef enum
{
	SWITCH_enumNotOk,
	SWITCH_enumOk,
	SWITCH_enumNullPointer,
	SWITCH_enumInvalidSwitch
	}SWITCH_enumErrorStatus_t;
	
typedef enum
{
	SWITCH_enumPressed,
	SWITCH_enumNotPressed
	}SWITCH_enumSwitchState_t;
/**
 *@brief : Function to Set Selected SWITCH to be Logic HIGH or Logic LOW.                                                                      
 */
void SWITCH_voidInit (void);


 /**
 *@brief : Function that Reads Switch State 
 *@param : Switch Name, Pointer to Switch State (Pressed/Not Pressed)
 *@return: Error State.                                                                      
 */
SWITCH_enumErrorStatus_t SWITCH_enuReadSwitchState(u8 Copy_u8SwitchName, SWITCH_enumSwitchState_t* Add_u8State);

#endif /* SWITCH_H_ */