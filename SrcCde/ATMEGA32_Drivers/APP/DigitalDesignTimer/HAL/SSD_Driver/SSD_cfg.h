/*
 * SSD_cfg.h
 *
 * Created: 12/16/2023 2:49:57 PM
 *  Author: Yasmin Amr
 */ 


#ifndef SSD_CFG_H_
#define SSD_CFG_H_

#include "../../MCAL/DIO_Driver/DIO.h"

#define SEG_NUM 2
#define FIRST_SEG 0
#define SECOND_SEG 1
typedef enum
{
	SSD_enumCommonAnode,
	SSD_enumCommonCathode
	}SSD_enumSegmentState_t;
	
typedef struct  
{
	DIO_enumPorts_t Port;
	DIO_enumPins_t Pin;
}SSD_strLedCfg_t;

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

#endif /* SSD_CFG_H_ */