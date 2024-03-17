/*
* File:    SSD_Private.h
* Author:  Yasmin Amr
* Created: 12/17/2023
* Brief:   SSD Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_

#include "../../LIB/std_types.h"

/************************************************************************/
/*							Number Macros						        */
/************************************************************************/
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9

/************************************************************************/
/*						Number of LEDs in each SSD				        */
/************************************************************************/
#define SSD_LED_NO 8

/**
*@brief : Counts how many digits in a numeric value(Ex: 123 has 3 values)
*@param : Value to display
*@return: Digits in Value
*/
u8 SSD_u8CountDigits(u32 Value);

#endif /* SSD_PRIVATE_H_ */