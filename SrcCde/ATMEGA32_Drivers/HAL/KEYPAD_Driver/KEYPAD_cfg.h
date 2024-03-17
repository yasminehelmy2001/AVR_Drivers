/*
* File:    KEYPAD_cfg.h
* Author:  Yasmin Amr
* Created: 1/8/2024
* Brief:   KEYPAD Driver
* Target:  Atmega32
* Version: 1.00
*/

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "../../LIB/std_math.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/DIO_Driver/DIO.h"

/*******************************************************************************/
/*						Choose your ROW SIZE from 2-> 4						   */									   
/*******************************************************************************/
#define KEYPAD_ROW_SIZE 4
/*******************************************************************************/
/*						Choose your COLUMN SIZE from 2-> 4					   */
/*******************************************************************************/
#define KEYPAD_COLUMN_SIZE 4

/**
*@brief : Struct to store Port & Pin of each Keypad Row & Column
*/
typedef struct  
{
	DIO_enumPorts_t Port;
	DIO_enumPins_t Pin;
}KEYPAD_strConfig;


#endif
