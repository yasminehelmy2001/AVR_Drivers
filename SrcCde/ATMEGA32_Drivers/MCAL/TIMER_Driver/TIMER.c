/*
* File:    TIMER.c
* Author:  Yasmin Amr
* Created: 15/1/2024
* Brief:   TIMER Driver
* Target:  Atmega32
* Version: 1.00
*/
#include "../EXTI_Driver/EXTI.h"
#include "TIMER.h"

u8 InitMode=PRE_COMPILE;
u8 PostCompilePrescaler=TIMER_8BIT_NO_PRESCALER;

/******************************************************************************/
/*							Check on Configurations							  */
/******************************************************************************/
#if (((TIMER0_MODE==TIMER_8BIT_CTC_MODE) || (TIMER0_MODE==TIMER_8BIT_NORMAL_MODE)) && (TIMER0_CMP_OUTPUT_MODE>TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_SET_OC0_ON_CMP_MATCH))
	#error "CMP_OUTPUT_MODE Doesn't match TIMER_MODE"
#elif ((TIMER0_MODE==TIMER_8BIT_FAST_PWM) && ((TIMER0_CMP_OUTPUT_MODE<TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_OC0_DISCONNECTED) || (TIMER0_CMP_OUTPUT_MODE> TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_INVERTED_MODE)))
	#error "CMP_OUTPUT_MODE Doesn't match TIMER_MODE"
#elif ((TIMER0_MODE==TIMER_8BIT_PWM_PHASE_CORRECT) && ((TIMER0_CMP_OUTPUT_MODE<TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_OC0_DISCONNECTED) || (TIMER0_CMP_OUTPUT_MODE> TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_INVERTED_MODE)))
	#error "CMP_OUTPUT_MODE Doesn't match TIMER_MODE"
#endif

/******************************************************************************/
/*					GLOBAL POINTER TO FUNCTION FOR CALLBACK		           	  */
/*								-TIMER0 OVERFLOW							  */
/*								-TIMER0 CMP MATCH							  */
/******************************************************************************/
void(*TIMER0_OVF_ISR)(void)=NULL;
void(*TIMER0_CMP_ISR)(void)=NULL;

/**
 * @brief Initialize the Timer 0 (TMR0) driver with pre-compiled settings.
 * 
 * This function performs the initialization of the TMR0 module with a predefined configuration.
 * It should be called before any other TMR0-related functions to ensure the timer is set up correctly.
 */
void TMR0_voidInitPreCompile(void)
{
	InitMode=PRE_COMPILE;
	
	/*Turning on External Interrupt*/
	#if ((TIMER0_OVF_INT_STATE==TIMER0_OVF_INT_ON)||(TIMER0_CMP_INT_STATE==TIMER0_CMP_INT_ON))
			SET_BIT(SREG,GIE_BIT);
		
		/*Setting Interrupt Enable*/	
		#if TIMER0_OVF_INT_STATE==TIMER0_OVF_INT_ON
			SET_BIT(TIMSK,TOIE0);
		#endif
		
		#if TIMER0_CMP_INT_STATE==TIMER0_CMP_INT_ON
			SET_BIT(TIMSK,OCIE0);
		#endif	
					
	#endif 
	
	/******************************************************************************/
	/*									TCCR0 REGISTER				       		  */
	/******************************************************************************/
	
	u8 Local_TCCR0_Register=TCCR0;

	/*Setting Timer Mode*/
	Local_TCCR0_Register&=TIMER_8BIT_TCCR0_MODE_MASK;
	u8 Local_WGM00_Value=GET_BIT(TIMER0_MODE,0);
	u8 Local_WGM01_Value=GET_BIT(TIMER0_MODE,1);
	Local_TCCR0_Register|=(Local_WGM00_Value<<WGM00);
	Local_TCCR0_Register|=(Local_WGM01_Value<<WGM01);
	
	/*Setting Compare Match Mode*/
	Local_TCCR0_Register&=TIMER_8BIT_TCCR0_CMP_MATCH_MODE_MASK;
	Local_TCCR0_Register|=(TIMER0_CMP_OUTPUT_MODE<<COM00);
	TCCR0=Local_TCCR0_Register;
	
}

/**
 * @brief		Initialize the Timer 0 (TMR0) driver with user-provided configuration.
 * 
 * @param		Copy_strTimerConfig Pointer to a TMR0Config_t structure that contains the desired timer configuration.
 * 
 * @return		TMR0_enuErrorStatus_t Error status of the initialization process.
 * 
 * This function allows for post-compilation initialization of the TMR0 module, enabling the user to
 * specify a configuration at run-time. 
 */
TIMER_enumErrorStatus_t TMR0_voidInitPostCompile(TMR0Config_t *Copy_strTimerConfig)
{
		TIMER_enumErrorStatus_t RET_ErrorStatus=TIMER_enumOk;
		
		if(Copy_strTimerConfig==NULL)
		{
			RET_ErrorStatus=TIMER_enumNOk;
		}
		else if(Copy_strTimerConfig->TIMER0_strCmp_Int_State>TIMER0_CMP_INT_ON)
		{
			RET_ErrorStatus=TIMER_enumNOk;

		}
		else if(Copy_strTimerConfig->TIMER0_strCmpOutputMode>TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_SET_OC0_ON_CMP_MATCH)
		{
			RET_ErrorStatus=TIMER_enumNOk;
		}
		else if(Copy_strTimerConfig->TIMER0_strMode>TIMER_8BIT_FAST_PWM)
		{
			RET_ErrorStatus=TIMER_enumNOk;
		}
		else if(Copy_strTimerConfig->TIMER0_strOvfIntState>TIMER0_OVF_INT_ON)
		{
			RET_ErrorStatus=TIMER_enumNOk;
		}
		else if(Copy_strTimerConfig->TIMER0_strPrescaler>TIMER_8BIT_EXTERNAL_CLK_RISING_EDGE)
		{
			RET_ErrorStatus=TIMER_enumNOk;
		}
		else
		{
			RET_ErrorStatus=TIMER_enumOk;
			
			InitMode=POST_COMPILE;

			/*Turning on External Interrupt*/
			if((Copy_strTimerConfig->TIMER0_strOvfIntState==TIMER0_OVF_INT_ON)||(Copy_strTimerConfig->TIMER0_strCmp_Int_State==TIMER0_CMP_INT_ON))
			SET_BIT(SREG,GIE_BIT);
		
			/*Setting Interrupt Enable*/
			if(Copy_strTimerConfig->TIMER0_strOvfIntState==TIMER0_OVF_INT_ON)
			SET_BIT(TIMSK,TOIE0);
		
			if(Copy_strTimerConfig->TIMER0_strOvfIntState==TIMER0_CMP_INT_ON)
			SET_BIT(TIMSK,OCIE0);

			/******************************************************************************/
			/*									TCCR0 REGISTER				       		  */
			/******************************************************************************/
			u8 Local_TCCR0_Register=TCCR0;

			/*Setting Timer Mode*/
		
			Local_TCCR0_Register&=TIMER_8BIT_TCCR0_MODE_MASK;
			u8 Local_WGM00_Value=GET_BIT(Copy_strTimerConfig->TIMER0_strMode,0);
			u8 Local_WGM01_Value=GET_BIT(Copy_strTimerConfig->TIMER0_strMode,1);
			Local_TCCR0_Register|=(Local_WGM00_Value<<WGM00);
			Local_TCCR0_Register|=(Local_WGM01_Value<<WGM01);
		
			/*Setting Compare Match Mode*/
			Local_TCCR0_Register&=TIMER_8BIT_TCCR0_CMP_MATCH_MODE_MASK;
			Local_TCCR0_Register|=(Copy_strTimerConfig->TIMER0_strCmpOutputMode<<COM00);
			TCCR0=Local_TCCR0_Register;
		
			/*Setting Prescaler to Global Variable*/
			PostCompilePrescaler= Copy_strTimerConfig->TIMER0_strPrescaler;

		}
		
		return RET_ErrorStatus;
}

/**
 * @brief Start Timer 0 to begin counting.
 * 
 * @return TMR0_enuErrorStatus_t Error status of the start process.
 * 
 * This function activates TMR0 to start counting based on the previously configured settings.
 * It returns an error status to indicate the success or nature of any failure in starting the timer.
 */
TIMER_enumErrorStatus_t TMR0_enuStart(void)
{	
		TIMER_enumErrorStatus_t RET_ErrorStatus= TIMER_enumOk;
		if(InitMode>POST_COMPILE)
		{
			RET_ErrorStatus=TIMER_enumNOk;
		}
		else if(InitMode==PRE_COMPILE)
		{
			/*Setting Prescaler*/
			u8 Local_TCCR0_Register=TCCR0;
			Local_TCCR0_Register&=TIMER_8BIT_TCCR0_PRESCALER_MASK;
			Local_TCCR0_Register|=TIMER0_PRESCALER;
			TCCR0=Local_TCCR0_Register;
		}
		else if(InitMode==POST_COMPILE)
		{
			/*Setting Prescaler*/
			u8 Local_TCCR0_Register=TCCR0;
			Local_TCCR0_Register&= TIMER_8BIT_TCCR0_PRESCALER_MASK;
			Local_TCCR0_Register|=PostCompilePrescaler;
			TCCR0=Local_TCCR0_Register;

		}		
		else
		{
			//Empty
		}
		return RET_ErrorStatus;

}

/**
*@brief : Function that takes a pointer to a callback function for ISR Timer0 Overflow Interrupt.
*@param : Callback function address
*@return: void
*/
void TIMER0_voidOverflowCallBackFunction(void(*cbf)(void))
{
	TIMER0_OVF_ISR=cbf;
}

/**
*@brief : Function that takes a pointer to a callback function for ISR Timer0 Compare Match Interrupt
*@param : Callback function address
*@return: void
*/
void TIMER0_voidCompareMatchCallBackFunction(void(*cbf)(void))
{
	TIMER0_CMP_ISR=cbf;
}

/******************************************************************************/
/*							TIMER0 OVERFLOW ISR					           	  */
/******************************************************************************/

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_OVF_ISR!=NULL)
	{
		TIMER0_OVF_ISR();
	}
	else
	{
		//Empty for MISRA
	}
}

/******************************************************************************/
/*							TIMER0 COMPARE MATCH ISR			           	  */
/******************************************************************************/

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_CMP_ISR!=NULL)
	{
		TIMER0_CMP_ISR();
	}
	else
	{
		//Empty for MISRA
	}
}


/**
*@brief : Function that generates a PWM signal from input Duty Cycle
*@param : Duty Cycle in Percentage, Timer Mode (Fast PWM/ Phase correct PWM)
*@return: Error Status
*/
TIMER_enumErrorStatus_t TIMER0_enumSetPwmDutyCycle(u8 Copy_u8DutyCyclePercentage, TIMER_enumPwmModes_t Copy_u8PwmMode,TIMER_enumPwmModes_t Copy_u8PWMType)
{
	/*Set Timer Error Status to NOT OK*/
	TIMER_enumErrorStatus_t RET_enumErrorStatus= TIMER_enumNOk;
	
	/*Check if Timer Mode is correct*/
	if (Copy_u8PwmMode>TIMER_PhaseCorrectMode)
	{
		RET_enumErrorStatus= TIMER_enumInvalidPwmMode;
	}
	/*Check if Duty Cycle value is between 0 & 100*/
	else if (Copy_u8DutyCyclePercentage<0 || Copy_u8DutyCyclePercentage>100)
	{
		RET_enumErrorStatus= TIMER_enumInvalidDutyCycle;
	}
	/*Input parameters are correct, proceed with operation*/
	else
	{
		/*Set error status to OK*/
		RET_enumErrorStatus=TIMER_enumOk;
		/*********************************************************/
		/*						FAST PWM MODE					 */
		/*********************************************************/
		if(Copy_u8PwmMode==TIMER_FastPwmMode)
		{
				/*Setting Prescaler to 8*/
				u8 Local_u8PrescalerValue=TIMER_8BIT_PRESCALER_8;
				u8 Local_TCCR0_Register=TCCR0;
				Local_TCCR0_Register&=TIMER_8BIT_TCCR0_PRESCALER_MASK;
				Local_TCCR0_Register|=Local_u8PrescalerValue;
				
				/*Setting Timer Mode to FAST PWM*/
				u8 Local_u8TimerMode=TIMER_8BIT_FAST_PWM;
				Local_TCCR0_Register&=TIMER_8BIT_TCCR0_MODE_MASK;
				u8 Local_WGM00_Value=GET_BIT(Local_u8TimerMode,0);
				u8 Local_WGM01_Value=GET_BIT(Local_u8TimerMode,1);
				Local_TCCR0_Register|=(Local_WGM00_Value<<WGM00);
				Local_TCCR0_Register|=(Local_WGM01_Value<<WGM01);		
						
				/*Setting Compare Match Mode to INVERTED/NON INVERTED MODE*/		
				u8 Local_u8CompareOutputMode;
				if(Copy_u8PWMType==TIMER_Inverted)
				{
					Local_u8CompareOutputMode=TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_INVERTED_MODE;
				}
				else
				{
					u8 Local_u8CompareOutputMode=TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_NON_INVERTED_MODE;
				}
				Local_TCCR0_Register&=TIMER_8BIT_TCCR0_CMP_MATCH_MODE_MASK;
				Local_TCCR0_Register|=(Local_u8CompareOutputMode<<COM00);
				TCCR0=Local_TCCR0_Register;
				
				/* 
				 * Get Compare Value to be put in OCR0
				 * @Note: Duty Cycle of Fast PWM - Non Inverted Mode is (Compare Value)/(Overflow Value)
				 */
				u8 Local_u8CompareValue= ((float)Copy_u8DutyCyclePercentage/100)*TIMER0_TOP_VALUE;
				
				/*Set 0C0 pin to OUTPUT*/
				DIO_enumSetPinConfig(DIO_enumPortB,DIO_enumPin3,DIO_enumOutput);
				
				/*Set Compare value to OCR0*/
				OCR0=Local_u8CompareValue;
	
		}	
		/*********************************************************/
		/*					PWM PHASE CORRECT MODE				 */
		/*********************************************************/
		else if(Copy_u8PwmMode==TIMER_PhaseCorrectMode)
		{
				/*Setting Prescaler to 8*/
				u8 Local_u8PrescalerValue=TIMER_8BIT_PRESCALER_8;
				u8 Local_TCCR0_Register=TCCR0;
				Local_TCCR0_Register&=TIMER_8BIT_TCCR0_PRESCALER_MASK;
				Local_TCCR0_Register|=Local_u8PrescalerValue;
				
				/*Setting Timer Mode to PWM PHASE CORRECT*/
				u8 Local_u8TimerMode=TIMER_8BIT_PWM_PHASE_CORRECT;
				Local_TCCR0_Register&=TIMER_8BIT_TCCR0_MODE_MASK;
				u8 Local_WGM00_Value=GET_BIT(Local_u8TimerMode,0);
				u8 Local_WGM01_Value=GET_BIT(Local_u8TimerMode,1);
				Local_TCCR0_Register|=(Local_WGM00_Value<<WGM00);
				Local_TCCR0_Register|=(Local_WGM01_Value<<WGM01);
				
				/*Setting Compare Match Mode to INVERTED/NON INVERTED MODE*/
				u8 Local_u8CompareOutputMode;
				if(Copy_u8PWMType==TIMER_Inverted)
				{
					Local_u8CompareOutputMode=TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_INVERTED_MODE;
				}
				else
				{
					u8 Local_u8CompareOutputMode=TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_NON_INVERTED_MODE;
				}
				Local_TCCR0_Register&=TIMER_8BIT_TCCR0_CMP_MATCH_MODE_MASK;
				Local_TCCR0_Register|=(Local_u8CompareOutputMode<<COM00);
				TCCR0=Local_TCCR0_Register;
				
				/* 
				 * Get Compare Value to be put in OCR0
				 * @Note: Duty Cycle of PWM Phase correct - Non Inverted Mode is (Compare Value)/(Overflow Value)
				 */
				u8 Local_u8CompareValue= ((float)Copy_u8DutyCyclePercentage/100)*TIMER0_TOP_VALUE;
				
				/*Set 0C0 Pin to OUTPUT*/
				DIO_enumSetPinConfig(DIO_enumPortB,DIO_enumPin3,DIO_enumOutput);
				
				/*Set Compare value to OCR0*/
				OCR0=Local_u8CompareValue;
		}	
		else
		{
			//Empty for MISRA
		}
	}
}