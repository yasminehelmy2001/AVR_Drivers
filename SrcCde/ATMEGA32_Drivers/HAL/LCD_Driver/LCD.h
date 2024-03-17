/*
* File:    LCD.h
* Author:  Yasmin Amr
* Created: 1/1/2024
* Brief:   LCD Driver
* Target:  Atmega32
* Version: 1.00
*/

#ifndef LCD_H_
#define LCD_H_

#include "LCD_cfg.h"

/************************************************************************/
/*					           LCD COMMANDS		                        */
/************************************************************************/
#define LCD_CLEAR								0x01
#define LCD_RETURN_HOME							0x02
#define LCD_ENTRY_MODE_SET_DEC_SHIFT_OFF		0x04
#define LCD_ENTRY_MODE_SET_INC_SHIFT_OFF		0x06
#define LCD_ENTRY_MODE_SET_DEC_SHIFT_ON			0x05
#define LCD_ENTRY_MODE_SET_DEC_SHIFT_ON			0x05
#define LCD_ENTRY_MODE_SET_INC_SHIFT_ON			0x07
#define LCD_DISPLAY_OFF_CURSOR_OFF_BLINK_OFF	0x08
#define LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF		0x0C
#define LCD_DISPLAY_ON_CURSOR_ON_BLINK_OFF		0x0E
#define LCD_DISPLAY_ON_CURSOR_ON_BLINK_ON		0x0F
#define LCD_DISPLAY_ON_CURSOR_OFF_BLINK_ON		0x0D
#define LCD_SHIFT_CURSOR_LEFT					0x10
#define LCD_SHIFT_CURSOR_RIGHT					0x14
#define LCD_SHIFT_DISPLAY_LEFT					0x18
#define LCD_SHIFT_DISPLAY_RIGHT					0x1C
#define LCD_8BIT_2LINES_5x7						0x38	/*Function Set*/
#define LCD_4BIT_2LINES_5x7						0x28	/*Function Set*/
#define LCD_CGRAM_ADDRESS						0x40	/*Start of CGRAM Address*/					
#define LCD_DDRAM_ADDRESS						0x80	/*Start of DDRAM Address*/


/**
*@brief : LCD error status enums
*/
typedef enum
{
	LCD_enuOK,
	LCD_enuNOK,
	LCD_enuNullPointer,
	LCD_enuInvalidBlockNumber,
	LCD_enuInvalidRow,
	LCD_enuInvalidColumn
	}LCD_enuErrorStatus;


/**
*@brief : Initializes LCD According to initialization mode (4-BIT/8-BIT)
*/
void LCD_voidInit(void);

/**
*@brief : Send command onto data pins D0-D7
*@param : Command byte
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuWriteCommand(u8 Copy_u8Command);

/**
*@brief : Send data to LCD using data pins: D0-D7
*@param : Data byte
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuWriteData(u8 Copy_u8Data);

/**
*@brief : Sets address counter to specific place on DDRAM
*@param : Copy_u8X: 0(First Line), 1(Second Line)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);

/**
*@brief : Displays a number from 0-255 on the LCD display
*@param : Number (0-255)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuWriteNumber(u8 Copy_u8Number);

/**
*@brief : Prints a string on the LCD display
*@param : String (Array of characters)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuWriteString(char* Copy_pchPattern, u8 Copy_u8Length);

/**
*@brief : Takes a pattern/character to save in CGRAM & display it 
*@param : Pattern, CGRAM Block Number(0-7), Position to display on DDRAM(Copy_u8X,Copy_u8Y)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);


#endif /* LCD_H_ */