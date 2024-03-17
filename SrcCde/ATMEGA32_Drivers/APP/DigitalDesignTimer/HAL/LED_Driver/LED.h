/*
 * LED.h
 *
 * Created: 12/11/2023 8:35:15 PM
 *  Author: yasmi
 */ 


#ifndef LED_H_
#define LED_H_

#include "LED_cfg.h"

typedef enum 
{
	LCD_enumNotOk,
	LCD_enumOk,
	LCD_enumInvalidLed,
	LCD_enumInvalidState
	}LED_enumErrorStatus_t;
/**
 *@brief : Function to Set Selected LEDS to be Logic HIGH or Logic LOW.                                                                      
 */
void LED_voidInit (void);

 /**
 *@brief : Function to Set a LED Pin to be Logic HIGH or Logic LOW.
 *@param : Led Name, Led State to be Set.
 *@return: Error State.                                                                      
 */
LED_enumErrorStatus_t LED_enumSetLedState(u8 Copy_u8LedName, u8 Copy_u8State);


#endif /* LED_H_ */