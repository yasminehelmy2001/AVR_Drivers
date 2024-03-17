/*
* File:    KEYPAD.h
* Author:  Yasmin Amr
* Created: 1/8/2024
* Brief:   KEYPAD Driver
* Target:  Atmega32
* Version: 1.00
*/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "KEYPAD_Private.h"

typedef enum
{
	KEYPAD_enuNullPointer,
	KEYPAD_enuOK,
	KEYPAD_enuNOk
	
}KEYPAD_enuErrorStatus_t;

/**
*@brief : Function to Initialize Keypad Ports&Pins, Keys, and Row and Column Sizes.
*/
void KEYPAD_voidInit(void);

/**
*@brief : Function to get pressed key character
*@param : Pointer to store pressed key character
*@return: Error Status
*/
KEYPAD_enuErrorStatus_t KEYPAD_enuGetKey(u8*Add_u8Char);

#endif