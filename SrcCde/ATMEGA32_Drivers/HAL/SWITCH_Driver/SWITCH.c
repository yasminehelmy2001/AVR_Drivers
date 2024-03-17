/*
* File:    SWITCH.c
* Author:  Yasmin Amr
* Created: 12/12/2023
* Brief:   SWITCH Driver
* Target:  Atmega32
* Version: 1.00
*/

#include "../../LIB/std_types.h"
#include "../../MCAL/DIO_Driver/DIO.h"
#include "SWITCH.h"

/*Define Dummy Value for Logic High/Low Configuration*/
#define DUMMY_VALUE 0x00;

/* Extern LCD Configuration Array*/
extern SWITCH_strSwitchCfg_t SWITCH_strSwitchArrCfg[SWITCH_COUNT]; 

/**
 *@brief : Function to Set Selected SWITCH to be Logic HIGH or Logic LOW.                                                                      
 */
void SWITCH_voidInit (void)
{
	
/*		Map SWITCH Configuration Array with 4 options
		   1) Port Number
		   2) Pin Number
		   3) Input State
		   
		To the DIO Configuration Function that takes 3 inputs
		   1) Port Number
		   2) Pin Number
		   3) Pin Configuration
		   4) Logic HIGH or LOW	                                         
 */
                                  
	/* Create a Local Array for SWITCH Configurations*/
	DIO_strDioCfg Loc_strSwitchArrCfg[SWITCH_COUNT]; 
	
	/*Loop over total SWITCHs*/
	for(u8 iter=0;iter<SWITCH_COUNT;iter++)
		{	
			/*Copy Port Number*/
			Loc_strSwitchArrCfg[iter].Port = SWITCH_strSwitchArrCfg[iter].Port;
			
			/*Copy Pin Number*/
			Loc_strSwitchArrCfg[iter].Pin = SWITCH_strSwitchArrCfg[iter].Pin;
			
			/*Set Input Configuration*/
			switch(SWITCH_strSwitchArrCfg[iter].InputState)
			{
				case SWITCH_enumInputInternalPU:
					Loc_strSwitchArrCfg[iter].PinConfig= DIO_enumInputInternalPU;
				break;
				case SWITCH_enumInputExternalPD:
					Loc_strSwitchArrCfg[iter].PinConfig= DIO_enumInputExternalPD;
				break;
			}
			
			/*Set Logic HIGH/LOW as Dummy Value*/
			Loc_strSwitchArrCfg[iter].LogicState= DUMMY_VALUE;
		}

	/*Send Mapped Array to DIO Configuration Function*/
	DIO_enumSetConfig(Loc_strSwitchArrCfg, SWITCH_COUNT);
}

 /**
 *@brief : Function that Reads Switch State 
 *@param : Switch Name, Pointer to Switch State (Pressed/Not Pressed)
 *@return: Error State.                                                                      
 */
SWITCH_enumErrorStatus_t SWITCH_enuReadSwitchState(u8 Copy_u8SwitchName, SWITCH_enumSwitchState_t* Add_u8State)
{
	/*Set return error status to Not OK*/
	SWITCH_enumErrorStatus_t RET_enumErrorStatus= SWITCH_enumNotOk;
	
	/*Check if switch name is valid*/
	if(Copy_u8SwitchName>=SWITCH_COUNT)
	{
		RET_enumErrorStatus=SWITCH_enumInvalidSwitch;
	}
	
	/*Check if pointer parameter is NULL*/
	else if(Add_u8State==NULL)
	{
		RET_enumErrorStatus=SWITCH_enumNullPointer;
	}
	
	/*All parameters are valid, proceed with operation*/
	else
	{
		/*Set return error status to OK*/
		RET_enumErrorStatus=SWITCH_enumOk;
		
		/*Create a variable to store DIO logic state*/
		DIO_enumLogicState_t Loc_enumSwitchLogicState;
		
		/*Read switch value (Logic HIGH/ Logic LOW)*/
		DIO_enumReadState(SWITCH_strSwitchArrCfg[Copy_u8SwitchName].Port,SWITCH_strSwitchArrCfg[Copy_u8SwitchName].Pin,&Loc_enumSwitchLogicState);
		
		/*Switch on State Parameter*/
		switch(SWITCH_strSwitchArrCfg[Copy_u8SwitchName].InputState)
		{
			    /*If input pull up*/
				case SWITCH_enumInputInternalPU:
					/*Switch on switch logic state*/
					switch(Loc_enumSwitchLogicState)
						{
							/*If high --> switch is not pressed*/
							case DIO_enumLogicHigh:
								*Add_u8State=SWITCH_enumNotPressed;
							break;
							/*If low --> switch is pressed*/
							case DIO_enumLogicLow:
								*Add_u8State=SWITCH_enumPressed;
							break;
						}
				break;
				/*If input pull down*/
				case SWITCH_enumInputExternalPD:
					switch(Loc_enumSwitchLogicState)
					{
						/*If high --> switch is pressed*/
						case DIO_enumLogicHigh:
							*Add_u8State=SWITCH_enumPressed;
						break;
						/*If low --> switch is not pressed*/
						case DIO_enumLogicLow:
							*Add_u8State=SWITCH_enumNotPressed;
						break;
					}
				break;
		}
	}
	/*Return error status*/
	return RET_enumErrorStatus;
}
