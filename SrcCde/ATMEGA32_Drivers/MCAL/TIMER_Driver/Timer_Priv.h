/*
* File:    TIMER_Priv.h
* Author:  Yasmin Amr
* Created: 15/1/2024
* Brief:   TIMER Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H

#include "../../LIB/std_types.h"
#include "../../LIB/std_math.h"

/******************************************************************************/
/*                             TIMER TOP VALUES			    	     		  */
/******************************************************************************/
#define TIMER0_TOP_VALUE			(255U)
#define TIMER1_TOP_VALUE			(65536U)
#define TIMER2_TOP_VALUE			(255U)
/******************************************************************************/
/*                             REGISTER ADDRESSES		    	     		  */
/******************************************************************************/
#define TCCR0						*((volatile u8*)0x53)
#define TCNT0						*((volatile u8*)0x52)
#define OCR0						*((volatile u8*)0x5C)
#define TIMSK						*((volatile u8*)0x59)
#define TIFR 						*((volatile u8*)0x58)

/******************************************************************************/
/*							  TIMER 0/2 PRESCALER MODES			     		  */
/******************************************************************************/
#define TIMER_8BIT_NO_CLK_SOURCE				(0U)
#define TIMER_8BIT_NO_PRESCALER					(1U)
#define TIMER_8BIT_PRESCALER_8					(2U)
#define TIMER_8BIT_PRESCALER_8					(2U)
#define TIMER_8BIT_PRESCALER_64					(3U)
#define TIMER_8BIT_PRESCALER_256				(4U)
#define TIMER_8BIT_PRESCALER_1024				(5U)
#define TIMER_8BIT_EXTERNAL_CLK_FALLING_EDGE	(6U)
#define TIMER_8BIT_EXTERNAL_CLK_RISING_EDGE		(7U)

/******************************************************************************/
/*                              TIMER 0/2 MODE MACROS	    	     		  */
/******************************************************************************/
#define TIMER_8BIT_NORMAL_MODE					(0U)
#define TIMER_8BIT_PWM_PHASE_CORRECT			(1U)
#define TIMER_8BIT_CTC_MODE						(2U)
#define TIMER_8BIT_FAST_PWM						(3U)

/******************************************************************************/
/*								TIMER INTERRUPT ENABLE			     		  */
/******************************************************************************/
/*Timer 0 Overflow Interrupt Enable*/
#define TIMER0_OVF_INT_OFF			(0U)
#define TIMER0_OVF_INT_ON			(1U)

/*Timer 0 Compare Match Interrupt Enable*/
#define TIMER0_CMP_INT_OFF			(0U)
#define TIMER0_CMP_INT_ON			(1U)

/******************************************************************************/
/*							    TCCR0 BIT MACROS		     	     		  */
/******************************************************************************/
#define CS00						(0U)
#define CS01						(1U)
#define CS02						(2U)
#define WGM01						(3U)
#define COM00						(4U)
#define COM01						(5U)
#define WGM00						(6U)
#define FOCO						(7U)

/******************************************************************************/
/*							    TIMSK BIT MACROS		     	     		  */
/******************************************************************************/
#define TOIE0						(0U)
#define OCIE0						(1U)
#define TOIE1						(2U)
#define OCIE1B						(3U)
#define OCIE1A						(4U)
#define TICIE1						(5U)
#define TOIE2						(6U)
#define OCIE2						(7U)

/******************************************************************************/
/*							    TIFR BIT MACROS				  	     		  */
/******************************************************************************/
#define TOV0						(0U)
#define OVF0						(1U)
#define TOV1						(2U)
#define OCF1B						(3U)
#define OCF1A						(4U)
#define ICF1						(5U)
#define TOV2						(6U)
#define OCF2						(7U)

/******************************************************************************/
/*								TIMER 0/2 MASKS					       		  */
/******************************************************************************/
#define TIMER_8BIT_TCCR0_PRESCALER_MASK			0xF8
#define TIMER_8BIT_TCCR0_MODE_MASK				0xB7
#define TIMER_8BIT_TCCR0_CMP_MATCH_MODE_MASK	0xCF

/*************************************************************************************************/
/*						TIMER 0/2 COMPARE OUTPUT MODE - NON PWM MODE							 */
/*************************************************************************************************/
#define TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_OC0_DISCONNECTED											(0U)	
#define TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_TOGGLE_OC0_ON_CMP_MATCH									(1U)
#define TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_CLEAR_OC0_ON_CMP_MATCH									(2U)
#define TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_SET_OC0_ON_CMP_MATCH										(3U)

/*************************************************************************************************/
/*						TIMER 0/2 COMPARE OUTPUT MODE - FAST PWM MODE							 */
/*************************************************************************************************/
#define TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_OC0_DISCONNECTED										(0U)
#define TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_NON_INVERTED_MODE										(2U)
#define TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_INVERTED_MODE											(3U)

/*************************************************************************************************/
/*						TIMER 0/2 COMPARE OUTPUT MODE - PHASE CORRECT PWM MODE					 */
/*************************************************************************************************/
#define TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_OC0_DISCONNECTED								(0U)
#define TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_NON_INVERTED_MODE									(2U)
#define TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_INVERTED_MODE										(3U)


#endif /* TIMER_PRIVATE_H_ */