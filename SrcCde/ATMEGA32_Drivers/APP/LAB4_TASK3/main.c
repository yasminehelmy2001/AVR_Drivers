/*
* File:    main.c
* Author:  Yasmin Amr
* Created: 1/1/2024
* Brief:   TASK4_LAB3: Display Your Name on an LCD while continuously shifting from L to R and from R to L
* Target:  Atmega32
* Version: 1.00
*/

#include "../HAL/LCD_Driver/LCD.h"
#include <util/delay.h>
#include <string.h>

int main(void)
{
	LCD_voidInit();
	char*name="Yasmin Amr";
	LCD_enuWriteCommand(LCD_DDRAM_ADDRESS);
	LCD_enuWriteString(name,strlen(name));
	for(int iter=0;iter<strlen(name);iter++)
	{
		LCD_enuWriteCommand(LCD_SHIFT_DISPLAY_LEFT);
		_delay_ms(250);
	}
	while (1)
	{
		for(int iter=0;iter<strlen(name)+16;iter++)
		{
			LCD_enuWriteCommand(LCD_SHIFT_DISPLAY_RIGHT);
			_delay_ms(250);
		}
		for(int iter=0;iter<strlen(name)+16;iter++)
		{
			LCD_enuWriteCommand(LCD_SHIFT_DISPLAY_LEFT);
			_delay_ms(250);
		}
	}
}

