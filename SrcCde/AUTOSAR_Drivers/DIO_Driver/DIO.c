/*
 * DIO.c
 *
 * Created: 12/24/2023 1:45:05 AM
 *  Author: Yasmin Amr
 */ 

#include "DIO.h"

/**
*@brief : Returns the level value of the specified DIO channel.
*@param : DIO channel number
*@return: Physical Level of Channel: STD_HIGH/STD_LOW
*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	/*If channel number is not valid*/
	if(ChannelId>u8PIN31)
	{
		/*DET Error Calling!*/
	}	
	/*Channel number is valid*/
	else
	{
		/*Create a return variable with an initial value*/
		Dio_LevelType RET_OutputLevel=STD_LOW;
		/*Create Local Variable to store Port Number (0-3)*/
		uint8 Loc_u8PortNumber=ChannelId/8;
		/*Create Local Variable to store Pin Number (0-7)*/
		uint8 Loc_u8PinNumber=ChannelId%8;
		/*Switch on Port Number*/
		switch(Loc_u8PortNumber)
		{
			/*PORTA Case*/
			case u8PORTA:
				/*If current channel state is STD_LOW*/
				if(GET_BIT(PINA,Loc_u8PinNumber)==STD_LOW)
				{
					/*return STD_LOW*/
					RET_OutputLevel=STD_LOW;
				}
				/*If current channel state is STD_HIGH*/
				else if(GET_BIT(PINA,Loc_u8PinNumber)==STD_HIGH)
				{
					/*return STD_HIGH*/
					RET_OutputLevel=STD_HIGH;
				}
				/*Else case for MISRA*/
				else
				{
					/*Do Nothing*/
				}
			break;
			/*PORTB Case*/
			case u8PORTB:
				/*If current channel state is STD_LOW*/
				if(GET_BIT(PINB,Loc_u8PinNumber)==STD_LOW)
				{
					/*return STD_LOW*/
					RET_OutputLevel=STD_LOW;
				}
				/*If current channel state is STD_HIGH*/
				else if(GET_BIT(PINB,Loc_u8PinNumber)==STD_HIGH)
				{
					/*return STD_HIGH*/
					RET_OutputLevel=STD_HIGH;
				}
				/*Else case for MISRA*/
				else
				{
					/*Do Nothing*/
				}	
			break;
			/*PORTC Case*/
			case u8PORTC:
				/*If current channel state is STD_LOW*/
				if(GET_BIT(PINC,Loc_u8PinNumber)==STD_LOW)
				{
					/*return STD_LOW*/
					RET_OutputLevel=STD_LOW;
				}
				/*If current channel state is STD_HIGH*/
				else if(GET_BIT(PINC,Loc_u8PinNumber)==STD_HIGH)
				{
					/*return STD_HIGH*/
					RET_OutputLevel=STD_HIGH;
				}
				/*Else case for MISRA*/
				else
				{
					/*Do Nothing*/
				}	
			break;
			/*PORTD Case*/
			case u8PORTD:
				/*If current channel state is STD_LOW*/
				if(GET_BIT(PIND,Loc_u8PinNumber)==STD_LOW)
				{
					/*return STD_LOW*/
					RET_OutputLevel=STD_LOW;
				}
				/*If current channel state is STD_HIGH*/
				else if(GET_BIT(PIND,Loc_u8PinNumber)==STD_HIGH)
				{
					/*return STD_HIGH*/
					RET_OutputLevel=STD_HIGH;
				}
				/*Else case for MISRA*/
				else
				{
					/*Do Nothing*/
				}
			break;
			/*Default case for MISRA*/
			default:
				/*Do Nothing*/
			break;
				}
			/*return channel level */
			return RET_OutputLevel;
	}
}

/**
*@brief : Writes value to a specified DIO channel
*@param : Channel number(0-32), Level (STD_HIGH/STD_LOW)
*@return: void
*/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	/*If channel number is not valid*/
	if(ChannelId>u8PIN31)
	{
		/*DET Error Calling!*/
	}
	/*Channel number is valid*/
	else
	{
		/*Create Local Variable to store Port Number (0-3)*/
		uint8 Loc_u8PortNumber=ChannelId/8;
		/*Create Local Variable to store Pin Number (0-7)*/
		uint8 Loc_u8PinNumber=ChannelId%8;
		/*Switch on Channel/Pin Number*/
		switch(Loc_u8PortNumber)
		{
			/*PORTA Case*/
			case u8PORTA:
				/*If pin not set as input, continue with configuration*/
				if(GET_BIT(DDRA,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Switch on input level parameter*/
					switch(Level)
					{
						/*STD_LOW Case*/
						case STD_LOW:
							/*Set PORTA-PINx to STD_LOW*/
							CLR_BIT(PORTA,Loc_u8PinNumber);
						break;
						/*STD_HIGH Case*/
						case STD_HIGH:
							/*Set PORTA-PINx to STD_HIGH*/
							SET_BIT(PORTA,Loc_u8PinNumber);
						break;
						/*Default case for MISRA*/
						default:
						/*Do Nothing*/
						break;
					}
				}
				else
				{
					/*Do Nothing*/
				}
			break;
			/*PORTB Case*/
			case u8PORTB:
			/*If pin not set as input, continue with configuration*/
				if(GET_BIT(DDRB,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Switch on input level parameter*/
					switch(Level)
					{
						/*STD_LOW Case*/
						case STD_LOW:
							/*Set PORTB-PINx to STD_LOW*/
							CLR_BIT(PORTB,Loc_u8PinNumber);
						break;
						case STD_HIGH:
							/*Set PORTB-PINx to STD_HIGH*/
							SET_BIT(PORTB,Loc_u8PinNumber);
						break;
						/*Default case for MISRA*/
						default:
						/*Do Nothing*/
						break;
					}
				}
				else
				{
					/*Do Nothing*/
				}
			break;
			/*PORTC Case*/
			case u8PORTC:
				/*If pin not set as input, continue with configuration*/
				if(GET_BIT(DDRC,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Switch on input level parameter*/
					switch(Level)
					{
						/*STD_LOW Case*/
						case STD_LOW:
							/*Set PORTC-PINx to STD_LOW*/
							CLR_BIT(PORTC,Loc_u8PinNumber);
						break;
						case STD_HIGH:
							/*Set PORTC-PINx to STD_HIGH*/
							SET_BIT(PORTC,Loc_u8PinNumber);
						break;
						/*Default case for MISRA*/
						default:
						/*Do Nothing*/
						break;
					}
				}
				else
				{
					/*Do Nothing*/
				}
			break;
			/*PORTD Case*/
			case u8PORTD:
				/*If pin not set as input, continue with configuration*/
				if(GET_BIT(DDRD,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Switch on input level parameter*/
					switch(Level)
					{
						/*STD_LOW Case*/
						case STD_LOW:
							/*Set PORTD-PINx to STD_LOW*/
							CLR_BIT(PORTD,Loc_u8PinNumber);
						break;
						/*Set PORTD-PINx to STD_LOW*/
						case STD_HIGH:
							/*Set PORTD-PINx to STD_HIGH*/
							SET_BIT(PORTD,Loc_u8PinNumber);
						break;
						/*Default case for MISRA*/
						default:
						/*Do Nothing*/
						break;
					}
				}
				else
				{
					/*Do Nothing*/
				}
			break;
			/*Default case for MISRA*/
			default:
			/*Do Nothing*/
			break;
			
		}
	}
}

/**
*@brief : Returns the level of all channels of that port. (STD_HIGH/STD_LOW)
*@param : ID of DIO port. (0-3)
*@return: Level of all channels of that port.(STD_HIGH/STD_LOW)
*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	/*Check validity of port number parameter*/
	if(PortId>u8PORTD)
	{
		/*DET ERROR CONTROL*/
	}
	/* Parameter is valid, continue with operation*/
	else
	{
		/*Create return variable*/
		Dio_PortLevelType RET_u8PortLevel=STD_LOW;
		/*Switch on Port*/
		switch(PortId)
		{
			/*PORTA case*/
			case u8PORTA:
				/*Return PORTA level value*/
				RET_u8PortLevel=PINA;
			break;
			/*PORTB case*/
			case u8PORTB:
				/*Return PORTB level value*/
				RET_u8PortLevel=PINB;
			break;
			/*PORTB case*/
			case u8PORTC:
				/*Return PORTC level value*/
				RET_u8PortLevel=PINC;
			break;
			/*PORTB case*/
			case u8PORTD:
				/*Return PORTD level value*/
				RET_u8PortLevel=PIND;
			break;
			/*Default case for MISRA*/
			default:
			/*Do Nothing*/
			break;
		}
			/*return PORTx level value*/
			return RET_u8PortLevel;	
		
	}
}

/**
*@brief : Service to set a value of the port.
*@param : ID of DIO Port, Value to be Written.
*@return: void
*/
void DIO_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
		/*Check validity of port number parameter*/
		if(PortId>u8PORTD)
		{
			/*DET ERROR CONTROL*/
		}
		/* Parameter is valid, continue with operation*/
		else
		{
			/*Switch on Port*/
			switch(PortId)
			{		
				/*Set Level to PORTA*/
				case u8PORTA:
					PORTA=Level;
				break;
				/*Set Level to PORTB*/
				case u8PORTB:
					PORTB=Level;
				break;
				/*Set Level to PORTC*/
				case u8PORTC:
					PORTC=Level;
				break;
				/*Set Level to PORTD*/
				case u8PORTD:
					PORTD=Level;
				break;
				/*Default case for MISRA*/
				default:
				/*Do Nothing*/
				break;
			}
		}
}

/**
*@brief : This Service reads a subset of the adjoining bits of a port.
*@param : Pointer to ChannelGroup
*@return: Level of a subset of the adjoining bits of a port (ex: for bits 2-6 return 0b101100)
*/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	
	/*Check if null pointer exists*/
	if(ChannelGroupIdPtr==NULL)
	{
		//DET ERROR CALL
	}
	/*Pointer not NULL, continue with operation*/
	else
	{
		/*Store current channel value (STD_HIGH/ STD_LOW)*/
		uint8 Loc_u8CurrentMaskChannelValue=STD_HIGH;
		
		/*Counter for mask bits equal to one*/
		uint8 Loc_u8NumOfBitsInChannelGroup=0;
		
		/*Iteration starts from offset*/
		uint8 iter=(ChannelGroupIdPtr->offset);
		
		/*While the current bit in the mask is equal to STD_HIGH*/
		while(Loc_u8CurrentMaskChannelValue==STD_HIGH)
		{
			/*Check if next mask bit is equal to STD_HIGH*/
			Loc_u8CurrentMaskChannelValue= GET_BIT(ChannelGroupIdPtr->mask,iter);
			
			/*Increment Counter*/
			Loc_u8NumOfBitsInChannelGroup++;
			
			/*Jump to Next Iteration*/
			iter++;
		}	
		/*Decrement Last Count*/
		Loc_u8NumOfBitsInChannelGroup--;
		
		/*Decrement Last Iteration*/
		iter--;
		
		/*Create a variable to store the value of the channel group*/
		Dio_PortLevelType Loc_u8ChannelGroupValue=STD_LOW;
		
		/*Set bits in Loc_u8ChannelGroupValue according to counter (number of channels in channel group)*/
		for(uint8 iter=0; iter<Loc_u8NumOfBitsInChannelGroup; iter++)
		{
			SET_BIT(Loc_u8ChannelGroupValue,iter);
		}
		
		/*clear the rest of the bits*/
		for(uint8 iter=Loc_u8NumOfBitsInChannelGroup; iter<u8PIN8; iter++)
		{
			CLR_BIT(Loc_u8ChannelGroupValue,iter);
		}
		
		/*AND the result with the original PORT value shifted right by offset value to get Channel Group Value*/
		switch(ChannelGroupIdPtr->port)
		{
			case u8PORTA:
				Loc_u8ChannelGroupValue&= ((PINA) >> (ChannelGroupIdPtr->offset));
			break;
			case u8PORTB:
				Loc_u8ChannelGroupValue&= ((PINB) >> (ChannelGroupIdPtr->offset));
			break;
			case u8PORTC:
				Loc_u8ChannelGroupValue&= ((PINC) >> (ChannelGroupIdPtr->offset));
			break;
			case u8PORTD:
				Loc_u8ChannelGroupValue&= ((PIND) >> (ChannelGroupIdPtr->offset));
			break;
			/*Default case for MISRA*/
			default:
			/*Do Nothing*/
			break;
		}
		
		/*Return channel group value*/
		return Loc_u8ChannelGroupValue;
	}
}

/**
*@brief : Service to set a subset of the adjoining bits of a port to a specified level.
*@param : Pointer to ChannelGroup , Value to be written
*@return: void
*/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
	/*Check if null pointer exists*/
	if(ChannelGroupIdPtr==NULL)
	{
		//DET ERROR CALL
	}
	
	/*Pointer not NULL, continue with operation*/
	else
	{
			/*Store current channel value (STD_HIGH/ STD_LOW)*/
			uint8 Loc_u8CurrentPortChannelValue=STD_HIGH;
			/*Counter for mask bits equal to one*/
			uint8 Loc_u8NumOfBitsInChannelGroup=0;
			/*Iteration starts from offset*/
			uint8 iter=(ChannelGroupIdPtr->offset);
			/*While the current bit in the mask is equal to STD_HIGH*/
			while(Loc_u8CurrentPortChannelValue==STD_HIGH)
			{
				/*Check if next mask bit is equal to STD_HIGH*/
				Loc_u8CurrentPortChannelValue= GET_BIT(ChannelGroupIdPtr->mask,iter);
				/*Increment Counter*/
				Loc_u8NumOfBitsInChannelGroup++;
				/*Jump to Next Iteration*/
				iter++;
			}
			/*Decrement Last Iteration*/
			iter--;
			/*Decrement Last Count*/
			Loc_u8NumOfBitsInChannelGroup--;
			/*Create a local variable to store port value*/
			uint8 Loc_u8ChannelGroupPort=0x00;
					/*Switch on port*/
					switch(ChannelGroupIdPtr->port)
					{
						/*PORTA case*/
						case u8PORTA:
						/*Store PORTA value in variable*/
						Loc_u8ChannelGroupPort=PINA;
						break;
						/*PORTB case*/
						case u8PORTB:
						/*Store PORTB value in variable*/
						Loc_u8ChannelGroupPort=PINB;
						break;
						/*PORTC case*/
						case u8PORTC:
						/*Store PORTC value in variable*/
						Loc_u8ChannelGroupPort=PINC;
						break;
						/*PORTD case*/
						case u8PORTD:
						/*Store PORTD value in variable*/
						Loc_u8ChannelGroupPort=PIND;
						break;
						/*Default case for MISRA*/
						default:
						/*Do Nothing*/
						break;
					}
			/*Loop over number of bits in channel group*/
			for(uint8 iter=0; iter<Loc_u8NumOfBitsInChannelGroup;iter++)
			{
				/*Get the logic level of a bit from the level variable*/
				uint8 Loc_u8ValueBit=GET_BIT(Level,iter);
		
				/*Switch on logic level of the bit*/
				switch(Loc_u8ValueBit)
				{
					/*If low*/
					case STD_LOW:
						/*Clear the corresponding channel group bit*/
						CLR_BIT(Loc_u8ChannelGroupPort,(iter+ChannelGroupIdPtr->offset));
					break;
					/*If high*/
					case STD_HIGH:
						/*Set the corresponding channel group bit*/
						SET_BIT(Loc_u8ChannelGroupPort,(iter+ChannelGroupIdPtr->offset));
					break;
					/*Default case for MISRA*/
					default:
					/*Do Nothing*/
					break;
				}
			}
			/*Apply changes to port*/
			DIO_WritePort(ChannelGroupIdPtr->port,Loc_u8ChannelGroupPort) ;
	}
}

/**
*@brief : Flip the level of a channel
*@param : ID of DIO channel
*@return: The level of the corresponding Pin after flipping. (STD_HIGH/STD_LOW)
*/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	if(ChannelId>31)
	{
		//DET ERROR HANDLING
	}
	else
	{
		/*Create Local Variable to store Port Number (0-3)*/
		uint8 Loc_u8PortNumber=ChannelId/8;
		
		/*Create Local Variable to store Pin Number (0-7)*/
		uint8 Loc_u8PinNumber=ChannelId%8;
		
		/*Create return variable to store the flipped channel level*/ 
		Dio_LevelType RET_u8ChannelLevel=STD_LOW;
		
		/*Switch on port*/
		switch(Loc_u8PortNumber)
		{
			/*PORTA Case*/
			case u8PORTA:
				/*If pin is NOT configured as input*/ 
				if(GET_BIT(DDRA,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Read channel level*/
					RET_u8ChannelLevel=Dio_ReadChannel(ChannelId);
					/*Invert channel level*/
					if(RET_u8ChannelLevel==STD_LOW)
					{
						Dio_WriteChannel(ChannelId,STD_HIGH);
						RET_u8ChannelLevel=STD_HIGH;
					}
					/*Invert channel level*/
					else if(RET_u8ChannelLevel==STD_HIGH)
					{
						Dio_WriteChannel(ChannelId,STD_LOW);
						RET_u8ChannelLevel=STD_LOW;
					}
					/*Else case for MISRA*/
					else
					{
						/*Do Nothing*/
					}
				}
				/*If pin is configured as input*/
				else
				{
					/*Do Nothing*/
				}
			break;
			/*PORTB Case*/
			case u8PORTB:
				/*If pin is NOT configured as input*/
				if(GET_BIT(DDRB,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Read channel level*/
					RET_u8ChannelLevel=Dio_ReadChannel(ChannelId);
					/*Invert channel level*/
					if(RET_u8ChannelLevel==STD_LOW)
					{
						Dio_WriteChannel(ChannelId,STD_HIGH);
						RET_u8ChannelLevel=STD_HIGH;
					}
					/*Invert channel level*/
					else if(RET_u8ChannelLevel==STD_HIGH)
					{
						Dio_WriteChannel(ChannelId,STD_LOW);
						RET_u8ChannelLevel=STD_LOW;
					}
					/*Else case for MISRA*/
					else
					{
						/*Do Nothing*/
					}
				}
				/*If pin is configured as input*/
				else
				{
					/*Do Nothing*/
				}
			break;
			/*PORTC Case*/
			case u8PORTC:
				/*If pin is NOT configured as input*/
				if(GET_BIT(DDRC,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Read channel level*/
					RET_u8ChannelLevel=Dio_ReadChannel(ChannelId);
					
					/*Invert channel level from STD_LOW to STD_HIGH*/
					if(RET_u8ChannelLevel==STD_LOW)
					{
						Dio_WriteChannel(ChannelId,STD_HIGH);
						RET_u8ChannelLevel=STD_HIGH;
					}
					
					/*Invert channel level from STD_HIGH to STD_LOW*/
					else if(RET_u8ChannelLevel==STD_HIGH)
					{
						Dio_WriteChannel(ChannelId,STD_LOW);
						RET_u8ChannelLevel=STD_LOW;
					}
				}
				/*If pin is configured as input*/
				else
				{
					/*Do Nothing*/
				}
			break;
			/*PORTD Case*/
			case u8PORTD:
				/*If pin is NOT configured as input*/
				if(GET_BIT(DDRD,Loc_u8PinNumber)!=STD_LOW)
				{
					/*Read channel level*/
					RET_u8ChannelLevel=Dio_ReadChannel(ChannelId);	
					/*Invert channel level from STD_LOW to STD_HIGH*/
					if(RET_u8ChannelLevel==STD_LOW)
					{
						Dio_WriteChannel(ChannelId,STD_HIGH);
						RET_u8ChannelLevel=STD_HIGH;
					}		
					/*Invert channel level from STD_HIGH to STD_LOW*/
					else if(RET_u8ChannelLevel==STD_HIGH)
					{
						Dio_WriteChannel(ChannelId,STD_LOW);
						RET_u8ChannelLevel=STD_LOW;
					}
					/*Else case for MISRA*/
					else
					{
						/*Do Nothing*/
					}
				}
				/*If pin is configured as input*/
				else
				{
					/*Do Nothing*/
				}
			break;
			/*Default case for MISRA*/
			default:
			/*Do Nothing*/
			break;
		}
		/*Return flipped channel level*/
		return RET_u8ChannelLevel;	
	}
	
}

/**
*@brief : Service to set the value of a given port with required mask. 
*
*@param : PortId: ID of DIO Port
		  Level: Value to be written to the port 
		  Mask: Channels to be masked in the port (For each bit: 0->Masked, 1->Not Masked)
*
*@return: void
*/
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
	/*Loop over 8 pins*/
	for(uint8 iter=0;iter<u8PIN8;iter++)
	{
			/*Switch on port number*/
			switch(PortId)
			{
				/*PORTA case*/
				case u8PORTA:
					/*If pin is not input*/
					if(GET_BIT(DDRA,iter)!=STD_LOW)
					{
						/*if pin is not masked*/
						if(GET_BIT(Mask,iter)==STD_HIGH)
						{
							/*write the pin to the specified level*/
							Dio_WriteChannel(iter,Level);
						}
						/*if pin is masked*/
						else
						{
							/*Do Nothing*/
						}
					}
					/*If pin is input*/
					else
					{
						/*Do Nothing*/
					}
				break;
				/*PORTB case*/
				case u8PORTB:
					/*If pin is not input*/
					if(GET_BIT(DDRB,iter)!=STD_LOW)
					{
						/*and if pin is not masked*/
						if(GET_BIT(Mask,iter)==STD_HIGH)
						{
							/*write the pin to the specified level*/
							Dio_WriteChannel(iter+8,Level);
						}
						/*if pin is masked*/
						else
						{
							/*Do Nothing*/
						}
					}
					/*If pin is input*/
					else
					{
						/*Do Nothing*/
					}
				break;
				/*PORTC case*/
				case u8PORTC:
					/*If pin is not input*/
					if(GET_BIT(DDRC,iter)!=STD_LOW)
					{
						/*if pin is not masked*/
						if(GET_BIT(Mask,iter)==STD_HIGH)
						{
							/*write the pin to the specified level*/
							Dio_WriteChannel(iter+16,Level);
						}
						/*if pin is masked*/
						else
						{
							/*Do Nothing*/
						}
					}
					/*If pin is input*/
					else
					{
						/*Do Nothing*/
					}
				break;
				/*PORTD case*/
				case u8PORTD:
					/*If pin is not input*/
					if(GET_BIT(DDRD,iter)!=STD_LOW)
					{
						/*if pin is not masked*/
						if(GET_BIT(Mask,iter)==STD_HIGH)
						{
							/*write the pin to the specified level*/
							Dio_WriteChannel(iter+24,Level);
						}
						/*if pin is masked*/
						else
						{
							/*Do Nothing*/
						}
					}
					/*If pin is input*/
					else
					{
						/*Do Nothing*/
					}
				break;
				/*Default case for MISRA*/
				default:
				/*Do Nothing*/
				break;
			}
	}
}

