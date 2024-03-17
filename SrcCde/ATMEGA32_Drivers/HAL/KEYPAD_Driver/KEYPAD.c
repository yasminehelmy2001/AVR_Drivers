/*
* File:    KEYPAD.c
* Author:  Yasmin Amr
* Created: 1/8/2024
* Brief:   KEYPAD Driver
* Target:  Atmega32
* Version: 1.00
*/

#include "KEYPAD.h"
#include "../LCD_Driver/LCD.h"
#include "util/delay.h"

/*******************************************************************************/
/*				   	KEYPAD Row Number Error Checking						   */
/*******************************************************************************/
#if ((KEYPAD_COLUMN_SIZE<2) || (KEYPAD_COLUMN_SIZE>4))
#error "Driver Does Not Support This Column Size"
#endif

/*******************************************************************************/
/*					KEYPAD Column Number Error Checking						   */
/*******************************************************************************/
#if ((KEYPAD_ROW_SIZE<2) || (KEYPAD_ROW_SIZE>4))
#error "Driver Does Not Support This Row Size"
#endif

/*Extern Row Configuration Array*/
extern KEYPAD_strConfig KEYPAD_strRowConfigArray[KEYPAD_ROW_SIZE];	
/*Extern Column Configuration Array*/	
extern KEYPAD_strConfig KEYPAD_strColConfigArray[KEYPAD_COLUMN_SIZE];	
/*Extern Keypad Keys Configuration Array*/
extern u8 KEYPAD_u8Keys[KEYPAD_ROW_SIZE][KEYPAD_COLUMN_SIZE];			

/**
*@brief : Function to Initialize Keypad Ports&Pins, Keys, and Row and Column Sizes.
*/
void KEYPAD_voidInit(void)
{
	/*Create a DIO configuration array for keypad rows*/
	DIO_strDioCfg DIO_strRowConfigArray[KEYPAD_ROW_SIZE];
	/*Create a DIO configuration array for keypad columns*/
	DIO_strDioCfg DIO_strColConfigArray[KEYPAD_ROW_SIZE];
	/*Loop over number of keypad rows*/
	for (u8 iter=0; iter<KEYPAD_ROW_SIZE; iter++)
	{
		/*Copy port from KEYPAD configuration array to DIO configuration array*/
		DIO_strRowConfigArray[iter].Port=KEYPAD_strRowConfigArray[iter].Port;
		/*Copy pin from KEYPAD configuration array to DIO configuration array*/
		DIO_strRowConfigArray[iter].Pin=KEYPAD_strRowConfigArray[iter].Pin;
		/*Set all keypad rows to be internal pull up*/
		DIO_strRowConfigArray[iter].PinConfig=DIO_enumInputInternalPU;
		/*Set logic output value to be dummy*/
		DIO_strRowConfigArray[iter].LogicState=DIO_enumLogicLow; 
	}
	/*Loop over number of keypad columns*/
	for (u8 iter=0; iter<KEYPAD_COLUMN_SIZE; iter++)
	{
		/*Copy port from KEYPAD configuration array to DIO configuration array*/
		DIO_strColConfigArray[iter].Port=KEYPAD_strColConfigArray[iter].Port;
		/*Copy pin from KEYPAD configuration array to DIO configuration array*/
		DIO_strColConfigArray[iter].Pin=KEYPAD_strColConfigArray[iter].Pin;
		/*Set all keypad columns to be output */
		DIO_strColConfigArray[iter].PinConfig=DIO_enumOutput;
		/*Set all keypad columns to be logic HIGH */
		DIO_strColConfigArray[iter].LogicState=DIO_enumLogicHigh;
	}
	/*Send DIO configuration array for keypad rows to DIO Driver to configure*/
	DIO_enumSetConfig(DIO_strRowConfigArray,KEYPAD_ROW_SIZE);
	/*Send DIO configuration array for keypad columns to DIO Driver to configure*/
	DIO_enumSetConfig(DIO_strColConfigArray,KEYPAD_COLUMN_SIZE);
	
}

/*
*@brief : Function to get pressed key character
*@param : Pointer to store pressed key character
*@return: Error Status
*/
KEYPAD_enuErrorStatus_t KEYPAD_enuGetKey(u8*Add_u8Char)
{
	/*Create a return error status variable, set it to NOT OK*/
	KEYPAD_enuErrorStatus_t RET_enuErrorStatus=KEYPAD_enuNOk;
	/*Check if address parameter is NULL*/
	if(Add_u8Char==NULL)
	{
		RET_enuErrorStatus=KEYPAD_enuNullPointer;
	}
	/*All parameters are valid, proceed with operation*/
	else 
	{
		u8 TempVariable=*Add_u8Char;
		/*Set return error status variable to OK*/
		RET_enuErrorStatus=KEYPAD_enuOK;
		/*Create a variable to store logic value of keypad row*/
		DIO_enumLogicState_t DIO_enumLogicState=DIO_enumLogicHigh;
		/*Loop over keypad columns*/
		while(TempVariable==*Add_u8Char)
		{
			for (u8 col_iter=0; col_iter<KEYPAD_COLUMN_SIZE;col_iter++)
			{
				/*Set current column to logic LOW*/
				DIO_enumSetPin(KEYPAD_strColConfigArray[col_iter].Port,KEYPAD_strColConfigArray[col_iter].Pin,DIO_enumLogicLow);
				/*Loop over keypad rows*/
				for(u8 row_iter=0;row_iter<KEYPAD_ROW_SIZE;row_iter++)
				{
					/*Read current row*/
					DIO_enumReadState(KEYPAD_strRowConfigArray[row_iter].Port,KEYPAD_strRowConfigArray[row_iter].Pin,&DIO_enumLogicState);
					/*If current row logic is LOW, it means that the key corresponding to the current column and row is pressed*/
					if(DIO_enumLogicState==DIO_enumLogicLow)
					{
						/*Send the character from the key configuration array corresponding to the current column and row*/
						*Add_u8Char=KEYPAD_u8Keys[row_iter][col_iter];
					}
				}
				/*Set current column to logic HIGH*/
				DIO_enumSetPin(KEYPAD_strColConfigArray[col_iter].Port,KEYPAD_strColConfigArray[col_iter].Pin,DIO_enumLogicHigh);
			}
		}
	}
	return RET_enuErrorStatus;
}