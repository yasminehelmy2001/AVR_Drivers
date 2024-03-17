/*
* File:    SSD_cfg.h
* Author:  Yasmin Amr
* Created: 12/16/2023
* Brief:   SSD Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

#include "../../MCAL/DIO_Driver/DIO.h"

/*Define your seven segment count as follows:
 *		#define SEG_NUM	3
 *
 *
 * Define your seven segment name with ascending numbers starting from 0
 * Example:
 *		#define FIRST_SEG	0
 *		#define SECOND_SEG	1
 *		#define THIRD_SEG	2
 */

#define SEG_NUM 3
#define FIRST_SEG 0
#define SECOND_SEG 1
#define THIRD_SEG 2


/**
*@brief : Enum to store segment state: Common Anode/ Common Cathode
*/
typedef enum
{
	SSD_enumCommonAnode,
	SSD_enumCommonCathode
	}SSD_enumSegmentState_t;

/**
*@brief : Struct to store Port and Pin of each SSD LED
*/
typedef struct
{
	DIO_enumPorts_t Port;
	DIO_enumPins_t Pin;
}SSD_strLedCfg_t;

/**
*@brief : Struct to store SSD LED Objects
*/
typedef struct  
{
	SSD_enumSegmentState_t State;  
	SSD_strLedCfg_t LED_A; 
	SSD_strLedCfg_t LED_B; 
	SSD_strLedCfg_t LED_C; 
	SSD_strLedCfg_t LED_D; 
	SSD_strLedCfg_t LED_E; 
	SSD_strLedCfg_t LED_F; 
	SSD_strLedCfg_t LED_G; 	
	SSD_strLedCfg_t LED_DOT; 
}SSD_strSegmentCfg_t;

/**
*@brief : Struct to store Port and Pin of each SSD LED
*/
typedef struct
{
	DIO_enumPorts_t Port;
	DIO_enumPins_t Pin;
}SSD_strLedCfg_t;

#endif /* SSD_CFG_H_ */