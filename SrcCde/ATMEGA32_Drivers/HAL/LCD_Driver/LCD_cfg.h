/*
* File:    LCD_cfg.h
* Author:  Yasmin Amr
* Created: 1/1/2024
* Brief:   LCD Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "LCD_Priv.h"

 
/**
 * Select Initialization Mode:
 * 1) For 4-Bit Mode Choose "FOUR_BIT_MODE"
 * 2) For 8-BIT Mode Choose "EIGHT_BIT_MODE"
*/
#define INIT_MODE	EIGHT_BIT_MODE

/**
*@brief : Struct for each LCD pin
*/
typedef struct
{
	u8 Port;
	u8 Pin;
	u8 PinCfg;
}LCD_strPinCfg_t;


#endif /* LCD_CFG_H_ */