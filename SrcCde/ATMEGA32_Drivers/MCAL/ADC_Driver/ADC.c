/*
* File:    ADC.c
* Author:  Yasmin Amr
* Created: 11/3/2024
* Brief:   ADC Driver
* Target:  ATMega32
*/

#include "../../LIB/std_math.h"
#include "ADC.h"


/**************************************************************************/
/*						Implementation Values/Masks			 			  */
/**************************************************************************/
#define ADC_SHIFT_8					(8U)
#define ADC_SHIFT_6					(6U)
#define ADC_VREF_MASK				0xC0
#define ADC_PRESCALER_MASK			0x07
#define ADC_MUX_MASK				0x07
#define ADC_INTERRUPT_ENABLE_MASK	0x08
#define ADC_DATA_ADJUST_MASK		0x20
#define ADC_AUTO_TRIGGER_MASK		0x20


/**************************************************************************/
/*						Static Function Prototypes			 			  */
/**************************************************************************/

/**
 * @brief   Function to Select a Channel for ADC Peripheral 
 *
 * @param   Channel_Id (ADC_MUX_ADC0->ADC_MUX_ADC7) 
 *
 * @return  Void 
 */
static ADC_ErrorStatus_t ADC_SelectChannel (u8 Channel_Id);

/**
 * @brief   Function to Return the Result of the Latest ADC Conversion
 *
 * @param   Void
 *
 * @return  u16 - Result of Conversion 
 */
static u16 ADC_GetResult(void);


/**************************************************************************/
/*						Global/Static Variables				 			  */
/**************************************************************************/
/*Global Chain for ISR to Modify*/
ADC_Chain_t* Global_Chain=NULL;
/*Global Index Tracker for Channel*/
u8 chain_curr_index=0;
u8 ADC_State=idle;

/**
 * @brief   Function to Select a Channel for ADC Peripheral 
 *
 * @param   Channel_Id (ADC_MUX_ADC0->ADC_MUX_ADC7) 
 *
 * @return  Void 
 */
static ADC_ErrorStatus_t ADC_SelectChannel (u8 Channel_Id)
{
	ADC_ErrorStatus_t RET_ErrorStatus=ADC_Ok;
	if(Channel_Id>ADC_MUX_ADC7)
	{
		RET_ErrorStatus=ADC_Nok;
	}
	u8 Loc_ADMUX=ADMUX;
	Loc_ADMUX&=~ADC_MUX_MASK;
	Loc_ADMUX|=(Channel_Id);
	ADMUX=Loc_ADMUX;
	return RET_ErrorStatus;
}

/**
 * @brief   Function to Return the Result of the Latest ADC Conversion
 *
 * @param   Void
 *
 * @return  u16 - Result of Conversion 
 */
static u16 ADC_GetResult(void)
{
	u16 ADCResult=0;
	if(ADC_DATA_ADJUST==ADC_RIGHT_ADJUST)
	{
		ADCResult= ((u16)ADCL | (u16)(ADCH<<ADC_SHIFT_8));
	}
	else
	{
		ADCResult = ((ADCL >> ADC_SHIFT_6) | (u16)(ADCH << ADC_SHIFT_8));
	}
	return ADCResult;
}

/**
 * @brief   Function to Initialize ADC
 */
void ADC_Init (void)
{
	/*Enable Global Interrupts*/
	SET_BIT(SREG,GIE_BIT);

	/*Setting VREF Value, Set Data Adjust(Left/Right)*/
	u8 Loc_Register=ADMUX;
	Loc_Register&=~ADC_VREF_MASK;
	Loc_Register|=ADC_VREF;
	Loc_Register&=~ADC_DATA_ADJUST_MASK;
	Loc_Register|=ADC_DATA_ADJUST;
	ADMUX=Loc_Register;
	
	/*Set Prescaler, Set Interrupt State(Enabled/Disabled), Modify Auto Trigger Enable*/
	Loc_Register=ADCSRA;
	Loc_Register&=~ADC_PRESCALER_MASK;
	Loc_Register|=ADC_PRESCALER;
	Loc_Register&=~ADC_INTERRUPT_ENABLE_MASK;
	Loc_Register|=ADC_INTERRUPT_STATE;
	Loc_Register&=~ADC_AUTO_TRIGGER_MASK;
	Loc_Register|=ADC_AUTO_TRIGGER;
	ADCSRA= Loc_Register;
	
	/*Enable ADC*/
	ADCSRA|=(1<<ADC_ADEN);
}

/**
 * @brief   Function to Start Conversion for a Channel Synchronously 
 *
 * @param   1) Channel_Id (ADC_MUX_ADC0->ADC_MUX_ADC7)	
 *			2) ADCResult 
 *
 * @return  Error Status 
 */
ADC_ErrorStatus_t ADC_StartConversionSync  (u8 Channel_Id, u16 * ADCResult)
{
	ADC_ErrorStatus_t RET_ErrorStatus=ADC_Ok;
	if(ADCResult==NULL)
	{
		RET_ErrorStatus=ADC_NullPointer;
	}
	else if(Channel_Id>ADC_MUX_ADC7)
	{
		RET_ErrorStatus=ADC_Nok;
	}
	else
	{
		/*Select Channel*/
		ADC_SelectChannel(Channel_Id);
		/*Start Conversion*/
		ADCSRA|=(1<<ADC_ADSC);
		/*Wait for Conversion to End*/
		while((ADCSRA&(1<<ADC_ADIF))==0);
		/*Clear Interrupt Flag*/
		ADCSRA|=(1<<ADC_ADIF);
		/*Store Result*/
		*ADCResult=ADC_GetResult();
	}
	return RET_ErrorStatus;
}

/**
 * @brief   Function to Start Conversion for a Group of Channels Asynchronously 
 *
 * @param   1) Copy_Chain - Struct to Store Info. about a Chain of Channels 
 *
 * @return  Error Status 
 */
ADC_ErrorStatus_t ADC_StartConversionAsync (ADC_Chain_t *Copy_Chain)
{
	ADC_ErrorStatus_t RET_ErrorStatus=ADC_Ok;
	if(Copy_Chain==NULL)
	{
		RET_ErrorStatus=ADC_NullPointer;
	}
	else if(Copy_Chain->APP_function==NULL)
	{
		RET_ErrorStatus=ADC_NullPointer;
	}
	else
	{
		for(int i=0;i<(Copy_Chain->length)-1;i++)
		{
			if(Copy_Chain->channels[i]>ADC_MUX_ADC7)
			{
				RET_ErrorStatus=ADC_Nok;
			}
			else
			{
				//Do Nothing
			}
		}
		if(ADC_State==idle)
		{
			/*ADC State now busy*/
			ADC_State=busy;
			/*Enable ADC Interrupt*/
			ADCSRA|=(1<<ADC_ADIE);
			/*Enable Single Conversion Mode*/
			ADCSRA&=~(1<<ADC_ADATE);
			/*Store Address of Chain in Global Variable*/
			Global_Chain=Copy_Chain;
			/*Select Channel*/
			ADC_SelectChannel(Copy_Chain->channels[0]);
			/*Start Conversion*/
			ADCSRA|=(1<<ADC_ADSC);
		}
		else
		{
			//Error, State is Busy
		}
	}

}

/**
 * @brief   ADC Conversion Complete ISR
 */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{	

	if(chain_curr_index<(Global_Chain->length))
	{
		/*Store Result of Current Index*/
		Global_Chain->results[chain_curr_index]=ADC_GetResult();
		/*Increment Index*/
		chain_curr_index++;
		/*Select Next Channel*/
		ADC_SelectChannel(Global_Chain->channels[chain_curr_index]);
		/*Start Conversion*/
		ADCSRA|=(1<<ADC_ADSC);	
	}
	else
	{
		/*Reset Index*/
		chain_curr_index=0;
		/*Call CallBack Function*/
		Global_Chain->APP_function();
		/*ADC State now idle*/
		ADC_State=idle;
	}
}