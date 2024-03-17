/*
 * DIO.h
 *
 * Created: 12/24/2023 1:45:14 AM
 *  Author: Yasmin Amr
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "DIO_priv.h"


/*******************************************************************************
*                             DIO MACROS									   *
*******************************************************************************/

/*
 * Pin or Channel Macros
 */
#define u8PIN0		0
#define u8PIN1		1
#define u8PIN2		2
#define u8PIN3		3
#define u8PIN4		4
#define u8PIN5		5
#define u8PIN6		6
#define u8PIN7		7
#define u8PIN8		8
#define u8PIN9		9
#define u8PIN10		10
#define u8PIN11		11
#define u8PIN12		12
#define u8PIN13		13
#define u8PIN14		14
#define u8PIN15		15
#define u8PIN16		16
#define u8PIN17		17
#define u8PIN18		18
#define u8PIN19		19
#define u8PIN20		20
#define u8PIN21		21
#define u8PIN22		22
#define u8PIN23		23
#define u8PIN24		14
#define u8PIN25		25
#define u8PIN26		26
#define u8PIN27		27
#define u8PIN28		28
#define u8PIN29		29
#define u8PIN30		30
#define u8PIN31		31

/*
 * Port Name Macros
 */
#define u8PORTA		0
#define u8PORTB		1
#define u8PORTC		2
#define u8PORTD		3

/**
 * Physical Pin State=0V
*/
#define STD_LOW			0x00     

/**
 * Physical Pin State=5V or 3.3V
*/
#define STD_HIGH		0x01

/**
 * Physical Port State=0V
*/
#define PORT_STD_LOW	0x00

/**
 * Physical Port State=5V or 3.3V
*/
#define PORT_STD_HIGH	0xFF


/*******************************************************************************
*                              DIO Data Types					     		   *
*******************************************************************************/

/*
*@brief: Numeric ID of a DIO channel. (0-31)
*/
typedef uint8	Dio_ChannelType;

/*
*@brief: Numeric ID of a DIO port. (0-3)
*/
typedef uint8	Dio_PortType;

/*
*@brief: Channel group, consists of several adjoining channels within a port. Gives you the place of this Channel Group.
*/
typedef struct 
{
	/*
	*@brief: Specifies which bits in the port are part of the channel group. The bits that are set to '1' represent the channels within the group.
	*/
	uint8 mask;
	
	/*
	*@brief: Starting position of the channel group within the port, counted from from LSB. (0-31). Can get it from mask. (first STD_HIGH bit)
	*/
	uint8 offset;
	
	/*
	*@brief: The port on which the Channel group is defined.
	*/
	Dio_PortType port;
	
	}Dio_ChannelGroupType;

/*
*@brief: Possible levels a DIO channel can have.Range: STD_LOW-->STD_HIGH
*/
typedef uint8 Dio_LevelType;


/*
*@brief: Stores Port Level. If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port.
*/
typedef uint8 Dio_PortLevelType;


/*******************************************************************************
*                              DET ERROR MACROS					     		   *
*******************************************************************************/
#define DIO_E_PARAM_INVALID_CHANNEL_ID	0x0A
#define DIO_E_PARAM_INVALID_PORT_ID		0X14
#define DIO_E_PARAM_INVALID_GROUP		0X1F
#define DIO_E_PARAM_POINTER				0X20



/*******************************************************************************
*                             Function Prototypes				     		   *
*******************************************************************************/

/**
*@brief : Returns the level value of the specified DIO channel.
*@param : DIO channel number
*@return: Physical Level of Channel: STD_HIGH/STD_LOW                                                        
*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
*@brief : Writes value to a specified DIO channel 
*@param : Channel number(0-32), Level (STD_HIGH/STD_LOW)
*@return: void
*/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/**
*@brief : Returns the level of all channels of that port. (STD_HIGH/STD_LOW)
*@param : ID of DIO port. (0-3)
*@return: Level of all channels of that port.(STD_HIGH/STD_LOW)
*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
*@brief : Service to set a value of the port. 
*@param : ID of DIO Port, Value to be Written. 
*@return: void
*/
void DIO_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/**
*@brief : This Service reads a subset of the adjoining bits of a port. 
*@param : Pointer to ChannelGroup 
*@return: Level of a subset of the adjoining bits of a port (ex: for bits 2-6 return 0b101100) 
*/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/**
*@brief : Service to set a subset of the adjoining bits of a port to a specified level.
*@param : Pointer to ChannelGroup , Value to be written
*@return: void
*/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

/**
*@brief : Flip the level of a channel
*@param : ID of DIO channel
*@return: The level of the corresponding Pin after flipping. (STD_HIGH/STD_LOW)
*/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/**
*@brief : Service to set the value of a given port with required mask. 
*
*@param : PortId: ID of DIO Port
		  Level: Value to be written to the port 
		  Mask: Channels to be masked in the port (For each bit: 0->Masked, 1->Not Masked)
*
*@return: void
*/
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

#endif /* DIO_H_ */