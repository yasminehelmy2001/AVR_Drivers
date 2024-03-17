
#ifndef LED_CFG_H_
#define LED_CFG_H_


/* Enter your number of LEDs*/
#define LED_COUNT 2


/* Use #define with your LED names and ascending numbers 
 * For example:
 * #define LED_ZERO 0
 * #define LED_ONE 1
 * #define LED_TWO 2
*/
#define START_LED 0
#define STOP_LED 1


/**
 *@brief : Led State: On/Off                                                 
 */
typedef enum
{
	LED_enumLedOn,
	LED_enumLedOff
}LED_enumLedState_t;


/**
 *@brief : Led State: Active High or Active Low                                               
 */
typedef enum
{
	LED_enumActiveLow,
	LED_enumActiveHigh
}LED_enumActiveState_t;


/**
 *@brief :Struct for Led Configuration                                             
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
	*@brief : Choose Led to be ON or OFF                                             
	*/
	LED_enumLedState_t OnOff;
	/**
	*@brief : Choose Active State to be HIGH or LOW                                              
	*/
	LED_enumActiveState_t ActiveState;
}LED_strLedCfg_t;

#endif /* LCD_CFG_H_ */