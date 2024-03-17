/*
* File:    TIMER.h
* Author:  Yasmin Amr
* Created: 15/1/2024
* Brief:   TIMER Driver
* Target:  Atmega32
* Version: 1.00
*/

#ifndef TIMER_H_
#define TIMER_H

#include "TIMER_cfg.h"

/**
*@brief : Pre-Defined Timer Delays to use in "TIMER_voidSetTimeTimer0" Function
*/
typedef enum
{
	TIMER_enumDelay100ms,
	TIMER_enumDelay500ms,
	TIMER_enumDelay1s,
	TIMER_enumDelay2s,
	TIMER_enumDelay5s
	}TIMER_enumDelayOptions_t;
	
/**
*@brief : Timer Error Status Enums
*/
typedef enum
{
	TIMER_enumInvalidMode,
	TIMER_enumNOk,
	TIMER_enumOk,
	TIMER_enumInvalidDelayOption,
	TIMER_enumInvalidPwmMode,
	TIMER_enumInvalidDutyCycle
}TIMER_enumErrorStatus_t;
	
typedef enum
{
	TIMER_FastPwmMode,
	TIMER_PhaseCorrectMode
	}TIMER_enumPwmModes_t;

typedef enum
{
	TIMER_Inverted,
	TIMER_NonInverted
	}TIMER_enumPwmType_t;
	
	
/*Structure that contains the desired timer configuration.
*						1) TIMER0_strMode
*							-TIMER_8BIT_NORMAL_MODE
*							- TIMER_8BIT_PWM_PHASE_CORRECT
*							- TIMER_8BIT_CTC_MODE
*							- TIMER_8BIT_FAST_PWM
*
*						2)TIMER0_strPrescaler
*							- TIMER_8BIT_NO_CLK_SOURCE
*							- TIMER_8BIT_NO_PRESCALER
*							- TIMER_8BIT_PRESCALER_8
*							- TIMER_8BIT_PRESCALER_64
*							- TIMER_8BIT_PRESCALER_256
*							- TIMER_8BIT_PRESCALER_1024
*							- TIMER_8BIT_EXTERNAL_CLK_FALLING_EDGE
*							- TIMER_8BIT_EXTERNAL_CLK_RISING_EDGE
*
*						3) TIMER0_strOvfIntState
*							- TIMER0_OVF_INT0_ON
*						    - TIMER0_OVF_INT0_OFF
*
*						4) TIMER0_strCmp_Int_State
*							- TIMER0_CMP_INT_ON
*							- TIMER0_CMP_INT_OFF
*
*						5) TIMER0_strCmpOutputMode
*							@Note: Choose Based on Mode You Selected
* 							If you selected Normal/CTC Mode Select:
*									-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_OC0_DISCONNECTED
*									-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_TOGGLE_OC0_ON_CMP_MATCH
*									-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_CLEAR_OC0_ON_CMP_MATCH
*									-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_SET_OC0_ON_CMP_MATCH
*
* 							If you selected FAST PWM Mode Select:
*									-TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_OC0_DISCONNECTED
*									-TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_NON_INVERTED_MODE
*									-TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_INVERTED_MODE
*
* 							If you selected PHASE CORRECT PWM Mode Select:
*									-TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_OC0_DISCONNECTED
*									-TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_NON_INVERTED_MODE
*									-TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_INVERTED_MODE
**/
typedef struct  
{
	u8 TIMER0_strMode;
	u8 TIMER0_strPrescaler;
	u8 TIMER0_strOvfIntState;
	u8 TIMER0_strCmp_Int_State;
	u8 TIMER0_strCmpOutputMode;
}TMR0Config_t;

/******************************************************************************/
/*								FUNCTION PROTOTYPES				       		  */
/******************************************************************************/

/**
 * @brief Initialize the Timer 0 (TMR0) driver with pre-compiled settings.
 * 
 * This function performs the initialization of the TMR0 module with a predefined configuration.
 * It should be called before any other TMR0-related functions to ensure the timer is set up correctly.
 */
void TMR0_voidInitPreCompile(void);

/**
 * @brief Initialize the Timer 0 (TMR0) driver with user-provided configuration.
 * 
 * @param Copy_strTimerConfig Pointer to a TMR0Config_t structure that contains the desired timer configuration.
 * @return TMR0_enuErrorStatus_t Error status of the initialization process.
 * 
 * This function allows for post-compilation initialization of the TMR0 module, enabling the user to
 * specify a configuration at run-time. 
 */
TIMER_enumErrorStatus_t TMR0_voidInitPostCompile(TMR0Config_t *Copy_strTimerConfig);

/**
 * @brief Set the desired tick time and interrupt source for Timer 0.
 * 
 * @param Copy_u8DesiredTime The desired tick time, which can be one of the predefined constants:
 *        100MS_TICK_TIME, 500MS_TICK_TIME, 1S_TICK_TIME, 2S_TICK_TIME, 5S_TICK_TIME.
 * @param Copy_u8InterruptSource The interrupt source, which can be either OVERFLOW or COMPARE_MATCH.
 * @return TMR0_enuErrorStatus_t Error status of the tick time setting process.
 * 
 * This function configures the tick time for the TMR0 module and specifies whether an interrupt should
 * be generated on an overflow or a compare match event. It returns an error status to indicate the success
 * or nature of any failure in setting the tick time.
 */
TIMER_enumErrorStatus_t TMR0_enuSetTickTimeMS(u8 Copy_u8DesiredTime, u8 Copy_u8InterruptSource);

/**
*@brief : Function that takes a pointer to a callback function for ISR Timer0 Overflow Interrupt.
*@param : Callback function address
*@return: void
*/
void TIMER0_voidOverflowCallBackFunction(void(*cbf)(void));

/**
*@brief : Function that takes a pointer to a callback function for ISR Timer0 Compare Match Interrupt
*@param : Callback function address
*@return: void
*/
void TIMER0_voidCompareMatchCallBackFunction(void(*cbf)(void));

/**
 * @brief Start Timer 0 to begin counting.
 * 
 * @return TMR0_enuErrorStatus_t Error status of the start process.
 * 
 * This function activates TMR0 to start counting based on the previously configured settings.
 * It returns an error status to indicate the success or nature of any failure in starting the timer.
 */
TIMER_enumErrorStatus_t TMR0_enuStart(void);

/**
 * @brief Set the duty cycle for Timer 0 in either Phase Correct PWM mode/Fast PWM Mode.
 * 
 * @param	Copy_u8DutyCyclePercentage   The desired duty cycle value.
 * @param	Copy_u8TimerMode:			 PWM Timer Mode, Takes one of 2 values:
 *												-TIMER_FastPwmMode
 *												-TIMER_PhaseCorrectMode
 * @param	Copy_u8PWMType				The PWM type, which can be either INVERTED or NON_INVERTED.
 *
 * @return	TMR0_enuErrorStatus_t		Error status of the duty cycle setting process.
 * 
 * This function configures the duty cycle for TMR0. Phase Correct Mode allows
 * for finer control of the PWM waveform compared to Fast PWM mode. It returns an error status to indicate
 * the success or nature of any failure in setting the duty cycle.
 */
TIMER_enumErrorStatus_t TIMER0_enumSetPwmDutyCycle(u8 Copy_u8DutyCyclePercentage, TIMER_enumPwmModes_t Copy_u8PwmMode,TIMER_enumPwmModes_t Copy_u8PWMType);


#endif /* TIMER_H_ */