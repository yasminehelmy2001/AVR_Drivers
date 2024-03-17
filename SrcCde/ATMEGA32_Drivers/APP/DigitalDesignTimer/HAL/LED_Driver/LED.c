/*
 * LCD.c
 *
 * Created: 12/11/2023 8:34:14 PM
 *  Author: yasmin
 */ 

#include "../../LIB/std_types.h"
#include "../../MCAL/DIO_Driver/DIO.h"
#include "LED_cfg.h"
#include "LED.h"

/* Extern LCD Configuration Array*/
extern LED_strLedCfg_t LED_strLedArrCfg[LED_COUNT]; 

/*		Map LCD Configuration Array with 4 options
		   1) Port Number
		   2) Pin Number
		   3) On/Off State
		   4) Active High/Low State
		   
		To the DIO Configuration Function that takes 3 inputs
		   1) Port Number
		   2) Pin Number
		   3) Output High/Low	                                         
 */
void LED_voidInit (void)
{
	/* Create a Local Array for LED Configurations*/
	DIO_strDioCfg Loc_strLedArrCfg[LED_COUNT]; 
	
	/*Loop over total LEDs*/
	for(u8 iter=0;iter<LED_COUNT;iter++)
		{	
			/*Copy Port Number*/
			Loc_strLedArrCfg[iter].Port = LED_strLedArrCfg[iter].Port;
			/*Copy Pin Number*/
			Loc_strLedArrCfg[iter].Pin = LED_strLedArrCfg[iter].Pin;
			/*Set Configuration to Output*/
			Loc_strLedArrCfg[iter].PinConfig= DIO_enumOutput;
			
							/*******************Set Output High/Low according to Active State and OnOff State************************/
							
			/*If LED is set to ON & Active State is set to HIGH, sent Logic HIGH on Pin*/
			if((LED_strLedArrCfg[iter].ActiveState ==LED_enumActiveHigh) && (LED_strLedArrCfg[iter].OnOff == LED_enumLedOn))
			{
				Loc_strLedArrCfg[iter].LogicState= DIO_enumLogicHigh;
			}
			/*If LED is set to OFF & Active State is set to LOW, sent Logic HIGH on Pin*/
			else if((LED_strLedArrCfg[iter].ActiveState ==LED_enumActiveLow) && (LED_strLedArrCfg[iter].OnOff == LED_enumLedOff))
			{
				Loc_strLedArrCfg[iter].LogicState= DIO_enumLogicHigh;
			}
			/*If LED is set to OFF & Active State is set to HIGH, sent Logic LOW on Pin*/
			else if((LED_strLedArrCfg[iter].ActiveState ==LED_enumActiveHigh) && (LED_strLedArrCfg[iter].OnOff == LED_enumLedOff))
			{
				Loc_strLedArrCfg[iter].LogicState= DIO_enumLogicLow;
			}
			/*If LED is set to ON & Active State is set to LOW, sent Logic LOW on Pin*/
			else if((LED_strLedArrCfg[iter].ActiveState ==LED_enumActiveLow) && (LED_strLedArrCfg[iter].OnOff == LED_enumLedOn))
			{
				Loc_strLedArrCfg[iter].LogicState= DIO_enumLogicLow;
			}
			}

	/*Send Mapped Array to DIO Configuration Function*/
	DIO_enumSetConfig(Loc_strLedArrCfg, LED_COUNT);
}

 /**
 *@brief : Function to Set a LED Pin to be Logic HIGH or Logic LOW.
 *@param : Led Name, Led State to be Set.
 *@return: Error State.                                                                      
 */
LED_enumErrorStatus_t LED_enumSetLedState(u8 Copy_u8LedName, DIO_enumLogicState_t Copy_u8State)
{
	/*Create an Error Status Variable*/
	LED_enumErrorStatus_t RET_enumErrorStatus= LCD_enumNotOk;
	/*Check if Led Name Exists*/
	if(Copy_u8LedName>=LED_COUNT)
	{
		RET_enumErrorStatus= LCD_enumInvalidLed;
	}
	/*Check if Led State is Valid*/
	else if(Copy_u8State> DIO_enumLogicHigh)
	{
		RET_enumErrorStatus=LCD_enumInvalidState;
	}
	/*All Parameters are Valid, Perform Operation*/
	else
	{
		/*Update Error Status to OK*/
		RET_enumErrorStatus=LCD_enumOk;
		/*Switch on State Parameter*/
		switch(Copy_u8State)
		{
			/*In case of Logic LOW*/
			case DIO_enumLogicLow:
				/*Switch on Active State Configuration*/
				switch(LED_strLedArrCfg[Copy_u8LedName].ActiveState)
				{
					/*If Active Low, Set Pin to HIGH*/
					case LED_enumActiveLow:
						DIO_enumSetPin(LED_strLedArrCfg[Copy_u8LedName].Port,LED_strLedArrCfg[Copy_u8LedName].Pin,DIO_enumLogicHigh);
					break;
					/*If Active High, Set Pin to LOW*/
					case LED_enumActiveHigh:
						DIO_enumSetPin(LED_strLedArrCfg[Copy_u8LedName].Port,LED_strLedArrCfg[Copy_u8LedName].Pin,DIO_enumLogicLow);
					break;
				}
			break;
			/*In case of Logic HIGH*/
			case DIO_enumLogicHigh:
				/*Switch on Active State Configuration*/
				switch(LED_strLedArrCfg[Copy_u8LedName].ActiveState)
				{
					/*If Active Low, Set Pin to LOW*/
					case LED_enumActiveLow:
						DIO_enumSetPin(LED_strLedArrCfg[Copy_u8LedName].Port,LED_strLedArrCfg[Copy_u8LedName].Pin,DIO_enumLogicLow);
					break;
					/*If Active High, Set Pin to HIGH*/
					case LED_enumActiveHigh:
						DIO_enumSetPin(LED_strLedArrCfg[Copy_u8LedName].Port,LED_strLedArrCfg[Copy_u8LedName].Pin,DIO_enumLogicHigh);
					break;
				}
			break;
		}
		
	}
	/*Return Error Status*/
	return RET_enumErrorStatus;
}
