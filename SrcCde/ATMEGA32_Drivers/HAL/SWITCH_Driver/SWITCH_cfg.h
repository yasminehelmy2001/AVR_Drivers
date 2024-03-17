/*
* File:    SWITCH_cfg.H
* Author:  Yasmin Amr
* Created: 12/12/2023
* Brief:   SWITCH Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

/* Enter your number of Switches*/
#define SWITCH_COUNT 2


/* Define your SWITCH names in Ascending Numbers Starting From Zero
 * For example:
 * #define SWITCH_ZERO 0
 * #define SWITCH_ONE 1
 * #define SWITCH_TWO 2
*/
#define START_SWITCH 0
#define STOP_SWITCH 1

/**
 *@brief : Switch State Input Internal Pull up or Input External Pull Down                                          
 */
typedef enum
{
	SWITCH_enumInputInternalPU,
	SWITCH_enumInputExternalPD
}SWITCH_enumInputState_t;


/**
 *@brief :Struct for Switch Configuration                                             
 */
typedef struct
{
	/**
	*@brief : Choose Port Number                                               
	*/
	DIO_enumPorts_t Port;
	/**
	*@brief : Choose Pin Number                                               
	*/
	DIO_enumPins_t Pin;
	/**
	*@brief : Choose Switch Input State                                          
	*/
	SWITCH_enumInputState_t InputState;
	
}SWITCH_strSwitchCfg_t;



#endif /* SWITCH_CFG_H_ */