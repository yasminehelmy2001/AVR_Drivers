/*
* File:    LCD.c
* Author:  Yasmin Amr
* Created: 1/1/2024
* Brief:   LCD Driver
* Target:  Atmega32
* Version: 1.00
*/

#include "LCD.h"
#include <util/delay.h>

/*define array size according to mode*/
#if INIT_MODE ==EIGHT_BIT_MODE
	#define ARRAY_SIZE		EIGHT_BIT_ARRAY_SIZE
#elif INIT_MODE==FOUR_BIT_MODE
	#define ARRAY_SIZE		FOUR_BIT_ARRAY_SIZE
#endif

/*extern LCD configuration array*/
extern LCD_strPinCfg_t LCD_strPinCfgArr[ARRAY_SIZE];

/**
*@brief : Initializes LCD According to initialization mode (4-BIT/8-BIT)
*/
void LCD_voidInit(void)
{
	/*Create a DIO configuration array*/
	DIO_strDioCfgWithoutLogic DIO_strPinCfgArr[ARRAY_SIZE];
	
	/*Copy LCD configuration from LCD array to DIO array*/
	for(u8 iter=0;iter<ARRAY_SIZE;iter++)
	{
		DIO_strPinCfgArr[iter].Port= LCD_strPinCfgArr[iter].Port;
		DIO_strPinCfgArr[iter].Pin=LCD_strPinCfgArr[iter].Pin;
		DIO_strPinCfgArr[iter].PinConfig=LCD_strPinCfgArr[iter].PinCfg;
	}
	
	/*Send configuration to DIO driver*/
	DIO_enumSetConfigWithoutLogic(DIO_strPinCfgArr, ARRAY_SIZE);


	/************************************************************************/
	/*					EIGHT BIT MODE INITIALIZATION				        */
	/************************************************************************/
	#if INIT_MODE==EIGHT_BIT_MODE
	
		/*wait for more than 30ms*/
		_delay_ms(40);
		/*Function set command*/
		LCD_enuWriteCommand(LCD_8BIT_2LINES_5x7);
		/*wait for more than 39us*/
		_delay_ms(2);
		/*Display ON/OFF Control*/
		LCD_enuWriteCommand(LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF);
		/*wait for more than 39us*/
		_delay_ms(2);
		/*Display Clear*/
		LCD_enuWriteCommand(LCD_CLEAR);
		/*wait for more than 1.53 ms*/
		_delay_ms(2);
		/*Entry Mode Set*/
		LCD_enuWriteCommand(LCD_ENTRY_MODE_SET_INC_SHIFT_OFF);
		
		
	/************************************************************************/
	/*					FOUR BIT MODE INITIALIZATION				        */
	/************************************************************************/
	#elif INIT_MODE==FOUR_BIT_MODE
		/*wait for more than 30ms*/
		_delay_ms(40);
		/*Function set*/
		LCD_enuWriteCommand(0b00100000);
		LCD_enuWriteCommand(0b00100000);
		LCD_enuWriteCommand(0b10000000);
		/*wait for more than 39us*/
		_delay_ms(2);
		/*Display ON/OFF Control*/
		LCD_enuWriteCommand(0b00000000);
		LCD_enuWriteCommand(0b11100000);
		/*wait for more than 39 us*/
		_delay_ms(2);
		/*Display Clear*/
		LCD_enuWriteCommand(0b00000000);
		LCD_enuWriteCommand(0b00010000);
		/*wait for more than 1.53ms*/
		_delay_ms(4);
		/*Entry Mode Set*/
		LCD_enuWriteCommand(0b00000000);
		LCD_enuWriteCommand(0b01100000);
		
	#endif
}

LCD_enuErrorStatus LCD_enuWriteCommand(u8 Copy_u8Command)
{

	/*Set to command mode*/
	DIO_enumSetPin(LCD_strPinCfgArr[RS_PIN].Port,LCD_strPinCfgArr[RS_PIN].Pin,DIO_enumLogicLow);
	/*Set to write mode*/
	DIO_enumSetPin(LCD_strPinCfgArr[RW_PIN].Port,LCD_strPinCfgArr[RW_PIN].Pin,DIO_enumLogicLow);
	
	/************************************************************************/
	/*					SENDING COMMAND - EIGHT BIT MODE 			        */
	/************************************************************************/
	
	#if INIT_MODE == EIGHT_BIT_MODE
	u8 Loc_u8Counter=0;
	/*Set command to data pins*/
	for(u8 iter=D0_PIN;iter<=D7_PIN;iter++)
	{
		if(GET_BIT(Copy_u8Command,Loc_u8Counter))
		{
			DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicHigh);
		}
		else
		{
			DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicLow);
		}
		Loc_u8Counter++;
	}
	
	/*Send command: set enable pin to high, delay for 230ns, set enable pin to low*/
	DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicHigh);
	_delay_ms(2);
	DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicLow);
	
	/************************************************************************/
	/*					SENDING COMMAND - FOUR BIT MODE 			        */
	/************************************************************************/
	
	#elif INIT_MODE ==FOUR_BIT_MODE
	/*send higher nibble*/
	u8 Loc_u8Counter=4;
	for(int iter=D4_PIN;iter<=D7_PIN;iter++)
	{
		if(GET_BIT(Copy_u8Command,(Loc_u8Counter)))
		{
			DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicHigh);
		}
		else
		{
			DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicLow);
		}
		Loc_u8Counter++;
	}
	/*Send higher nibble data: set enable pin to high, delay for 230ns, set enable pin to low*/
	DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicHigh);
	_delay_ms(2);
	DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicLow);
	_delay_ms(2);
	
	Loc_u8Counter=0;
	/*send lower nibble*/
	for(int iter=D4_PIN;iter<=D7_PIN;iter++)
	{
		if(GET_BIT(Copy_u8Command,(Loc_u8Counter)))
		{
			DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicHigh);
		}
		else
		{
			DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicLow);
		}
		Loc_u8Counter++;
	}
	/*Send lower nibble data: set enable pin to high, delay for 230ns, set enable pin to low*/
	DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicHigh);
	_delay_ms(2);
	DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicLow);
	_delay_ms(2);
	#endif
	return LCD_enuOK;
}

/**
*@brief : Send data to LCD using data pins: D0-D7
*@param : Data byte
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuWriteData(u8 Copy_u8Data)
{
	/*Set to data mode*/
	DIO_enumSetPin(LCD_strPinCfgArr[RS_PIN].Port,LCD_strPinCfgArr[RS_PIN].Pin,DIO_enumLogicHigh);
	/*Set to write mode*/
	DIO_enumSetPin(LCD_strPinCfgArr[RW_PIN].Port,LCD_strPinCfgArr[RW_PIN].Pin,DIO_enumLogicLow);
	
	/************************************************************************/
	/*						SENDING DATA - EIGHT BIT MODE 			        */
	/************************************************************************/
	#if INIT_MODE==EIGHT_BIT_MODE
		u8 Loc_u8Counter=0;
		/*Set data to data pins*/
		for(int iter=D0_PIN;iter<=D7_PIN;iter++)
		{
			if(GET_BIT(Copy_u8Data,(Loc_u8Counter)))
			{
				DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicLow);
			}
		Loc_u8Counter++;
		}
		/*Send data: set enable pin to high, delay for 230ns, set enable pin to low*/
		DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicHigh);
		_delay_ms(2);
		DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicLow);
		
	/************************************************************************/
	/*						SENDING DATA - FOUR BIT MODE				    */
	/************************************************************************/		
	#elif INIT_MODE==FOUR_BIT_MODE
			/*send higher nibble*/
			u8 Loc_u8Counter=4;
			for(int iter=D4_PIN;iter<=D7_PIN;iter++)
			{
				if(GET_BIT(Copy_u8Data,(Loc_u8Counter)))
				{
					DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicHigh);
				}
				else
				{
					DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicLow);
				}
				Loc_u8Counter++;
			}
			/*Send higher nibble data: set enable pin to high, delay for 230ns, set enable pin to low*/
			DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicHigh);
			_delay_ms(2);
			DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicLow);
			_delay_ms(2);
			
			Loc_u8Counter=0;
			/*send lower nibble*/
			for(int iter=D4_PIN;iter<=D7_PIN;iter++)
			{
				if(GET_BIT(Copy_u8Data,(Loc_u8Counter)))
				{
					DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicHigh);
				}
				else
				{
					DIO_enumSetPin(LCD_strPinCfgArr[iter].Port,LCD_strPinCfgArr[iter].Pin,DIO_enumLogicLow);
				}
				Loc_u8Counter++;
			}
			/*Send lower nibble data: set enable pin to high, delay for 230ns, set enable pin to low*/
			DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicHigh);
			_delay_ms(2);
			DIO_enumSetPin(LCD_strPinCfgArr[E_PIN].Port,LCD_strPinCfgArr[E_PIN].Pin,DIO_enumLogicLow);
			_delay_ms(2);
	#endif
	return LCD_enuOK;

}

/**
*@brief : Sets address counter to specific place on DDRAM
*@param : Copy_u8X: 0(First Line), 1(Second Line)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y)
{
	LCD_enuErrorStatus RET_enuErrorStatus=LCD_enuNOK;
	if(Copy_u8X>1)
	{
		RET_enuErrorStatus=LCD_enuInvalidRow;
	}
	else if (Copy_u8Y>15)
	{
		RET_enuErrorStatus=LCD_enuInvalidColumn;
	}
	else
	{
		RET_enuErrorStatus=LCD_enuOK;
		u8 Loc_u8Location=0;
		if(Copy_u8X==0)
		{
			Loc_u8Location=Copy_u8Y;
		}
		else
		{
			Loc_u8Location=0x40+Copy_u8Y;
		}
		LCD_enuWriteCommand(LCD_DDRAM_ADDRESS+Loc_u8Location);
	}	
	return RET_enuErrorStatus;
}

/**
*@brief : Displays a number from 0-255 on the LCD display
*@param : Number (0-255)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuWriteNumber(u8 Copy_u8Number)
{
	u8 Loc_u8Remainder=Copy_u8Number;
	u8 counter=0;
	u8 Loc_u8RemainderArr[32]={0};
	while(Loc_u8Remainder!=0)
	{
		Loc_u8Remainder=Copy_u8Number%10;
		Loc_u8RemainderArr[counter]=Loc_u8Remainder;
		Loc_u8Remainder=Copy_u8Number/10;
		Copy_u8Number=Copy_u8Number/10;
		counter++;
	}
	while(counter>0)
	{
		counter--;
		LCD_enuWriteData((Loc_u8RemainderArr[counter]+48));
	}
	return LCD_enuOK;
}

/**
*@brief : Prints a string on the LCD display
*@param : String (Array of characters)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuWriteString(char* Copy_pchPattern, u8 Copy_u8Length)
{
	LCD_enuErrorStatus RET_enuErrorStatus=LCD_enuNOK;
	if(Copy_pchPattern==NULL)
	{
		RET_enuErrorStatus=LCD_enuNullPointer;
	}
	else
	{
		RET_enuErrorStatus=LCD_enuOK;
		
		for(u8 iter=0;iter<Copy_u8Length;iter++)
		{
			LCD_enuWriteData(Copy_pchPattern[iter]);
		}
	}
	return RET_enuErrorStatus
}

/**
*@brief : Takes a pattern/character to save in CGRAM & display it
*@param : Pattern, CGRAM Block Number(0-7), Position to display on DDRAM(Copy_u8X,Copy_u8Y)
*@return: Error Status
*/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y)
{
	LCD_enuErrorStatus RET_enuErrorStatus=LCD_enuNOK;
	if(Copy_pu8Pattern==NULL)
	{
		RET_enuErrorStatus=LCD_enuNullPointer;
	}
	else if(Copy_u8CGRAMBlockNumber>7)
	{
		RET_enuErrorStatus=LCD_enuInvalidBlockNumber;
	}
	else if(Copy_u8X>1)
	{
		RET_enuErrorStatus=LCD_enuInvalidRow;
	}
	else if(Copy_u8Y>15)
	{
		RET_enuErrorStatus=LCD_enuInvalidColumn;
	}
	else
	{
		RET_enuErrorStatus=LCD_enuOK;
		u8 Loc_u8CgramAddress=LCD_CGRAM_ADDRESS|(Copy_u8CGRAMBlockNumber*8);
		LCD_enuWriteCommand(Loc_u8CgramAddress);
		for(u8 iter=0;iter<8;iter++)
		{
			LCD_enuWriteData(Copy_pu8Pattern[iter]);
			/*Address will Automatically increment if I/D bit is set in Entry Mode*/
		}
		LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
		LCD_enuWriteData(Copy_u8CGRAMBlockNumber);
	}
	return RET_enuErrorStatus;
}

