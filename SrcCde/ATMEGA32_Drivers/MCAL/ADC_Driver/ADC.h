/*
* File:    ADC.h
* Author:  Yasmin Amr
* Created: 11/3/2024
* Brief:   ADC Driver
* Target:  ATMega32
*/

#ifndef ADC_H_
#define ADC_H_

#include "ADC_cfg.h"

/*EOJ Type: Pointer to Function that Takes Void & Returns Void*/
typedef void (*EOJ)(void);	

/**************************************************************************/
/*						Defines								 			  */
/**************************************************************************/
#define ADC_MUX_ADC0		0x00
#define ADC_MUX_ADC1		0x01
#define ADC_MUX_ADC2		0x02
#define ADC_MUX_ADC3		0x03
#define ADC_MUX_ADC4		0x04
#define ADC_MUX_ADC5		0x05
#define ADC_MUX_ADC6		0x06
#define ADC_MUX_ADC7		0x07

/**************************************************************************/
/*						ADC Error Status Enum				 			  */
/**************************************************************************/
typedef enum
{
	ADC_Ok,
	ADC_Nok,
	ADC_NullPointer
	}ADC_ErrorStatus_t;

/**************************************************************************/
/*						ADC Chain Type						 			  */
/**************************************************************************/

/**
 * Struct to store info. about multiple channels contained in a chain that will run 
 * asynchronously. Takes a maximum of 8 channels per chain.
 */
typedef struct {
	u8 length;			/* Enter Number of Channels in Chain */
	u8 channels[8];		/* Enter Channel Number for each Channel*/
	u16 results[8];		/* Stores Result of Each Channel*/
	EOJ APP_function;	/* Function to call When ADC Results are stored for Entire Chain*/
	}ADC_Chain_t; 


/**
 * @brief   Function to Initialize ADC
 */
void ADC_Init (void);

/**
 * @brief   Function to Start Conversion for a Channel Synchronously 
 *
 * @param   1) Channel_Id (ADC_MUX_ADC0->ADC_MUX_ADC7)	
 *			2) ADCResult 
 *
 * @return  Error Status 
 */
ADC_ErrorStatus_t ADC_StartConversionSync  (u8 Channel_Id, u16 * ADCResult);

/**
 * @brief   Function to Start Conversion for a Group of Channels Asynchronously 
 *
 * @param   1) Copy_Chain - Struct to Store Info. about a Chain of Channels 
 *
 * @return  Error Status 
 */
ADC_ErrorStatus_t ADC_StartConversionAsync (ADC_Chain_t *Copy_Chain);




#endif /* ADC_H_ */