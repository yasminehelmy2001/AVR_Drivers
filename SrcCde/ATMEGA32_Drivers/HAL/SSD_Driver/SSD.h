/*
* File:    SSD.h
* Author:  Yasmin Amr
* Created: 12/16/2023
* Brief:   SSD Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef SSD_H_
#define SSD_H_

#include "SSD_Private.h"
#include "SSD_cfg.h"

/**
*@brief : SSD error status enums
*/
typedef enum
{
	SSD_enumNotOk,
	SSD_enumOk,
	SSD_enumInvalidValue,
	SSD_enumInvalidSegmentName,
	SSD_enumInvalidInputValue
	}SSD_enumErrorStatus_t;


/**
*@brief : SSD Initialization function: SSD numbers, Ports & Pins
*/
void SSD_Init(void);

/**
*@brief : Displays value onto one seven segment display
*@param : Segment name, Value to display
*@return: Error Status
*/
SSD_enumErrorStatus_t SSD_enumSetValue(u8 Copy_u8SegName, u32 Value);

/**
*@brief : Displays value onto all seven segment displays
*@param : Value to display
*@return: Error Status
*/
SSD_enumErrorStatus_t SSD_enumSetValueToAll(u32 Value);

#endif /* SSD_H_ */