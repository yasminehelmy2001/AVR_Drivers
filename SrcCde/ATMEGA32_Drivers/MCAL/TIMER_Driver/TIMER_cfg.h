/*
* File:    TIMER_cfg.h
* Author:  Yasmin Amr
* Created: 15/1/2024
* Brief:   TIMER Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef TIMER_CFG_H_
#define TIMER_CFG_H

#include "Timer_Priv.h"

/******************************************************************************/
/*							TIMER 0 CONFIGURATIONS			    	     	  */
/******************************************************************************/

/* Choose Mode from
 * 1) TIMER_8BIT_NORMAL_MODE
 * 2) TIMER_8BIT_PWM_PHASE_CORRECT
 * 3) TIMER_8BIT_CTC_MODE
 * 4) TIMER_8BIT_FAST_PWM
 *
 * @Note: Before using OCO pin, you MUST set the pin to OUTPUT first!
 *
 */
#define TIMER0_MODE		TIMER_8BIT_FAST_PWM

/* Choose Mode from
 * 1) TIMER_8BIT_NO_CLK_SOURCE
 * 2) TIMER_8BIT_NO_PRESCALER
 * 3) TIMER_8BIT_PRESCALER_8
 * 4) TIMER_8BIT_PRESCALER_64
 * 5) TIMER_8BIT_PRESCALER_256
 * 6) TIMER_8BIT_PRESCALER_1024
 * 7) TIMER_8BIT_EXTERNAL_CLK_FALLING_EDGE
 * 8) TIMER_8BIT_EXTERNAL_CLK_RISING_EDGE
 *
 * @Note: - Choices 1 to 6 will enable TIMER mode
 *		  - Choices 7 and 8 will enable COUNTER mode
 */
#define TIMER0_PRESCALER		TIMER_8BIT_PRESCALER_8

/* Choose To Initially Enable Timer0 Overflow Using:
 * 1) TIMER0_OVF_INT0_ON
 * 2) TIMER0_OVF_INT0_OFF
 *
 *	@Note: In CTC mode, if you have BOTH the Overflow Interrupt and Compare
 *		   Match Interrupt enabled, the TCNT0 value will not clear on compare, and
 *		   will continue to count till 0xFF to generate an overflow interrupt.
 */
#define TIMER0_OVF_INT_STATE	TIMER0_OVF_INT_OFF

/* Choose To Initially Enable Timer0 Compare Match Using:
 * 1) TIMER0_CMP_INT0_ON
 * 2) TIMER0_CMP_INT0_OFF
 *
 *	@Note: In CTC mode, if you have BOTH the Overflow Interrupt and Compare
 *		   Match Interrupt enabled, the TCNT0 value will not clear on compare, and
 *		   will continue to count till 0xFF to generate an overflow interrupt.
 */
#define TIMER0_CMP_INT_STATE	TIMER0_CMP_INT_OFF

/* @Note: Choose Based on Mode You Selected
 * If you selected Normal/CTC Mode Select:
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_OC0_DISCONNECTED
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_TOGGLE_OC0_ON_CMP_MATCH
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_CLEAR_OC0_ON_CMP_MATCH
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_NON_PWM_SET_OC0_ON_CMP_MATCH
 *
 * If you selected FAST PWM Mode Select:
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_OC0_DISCONNECTED
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_NON_INVERTED_MODE
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_INVERTED_MODE
 *
 * If you selected PHASE CORRECT PWM Mode Select:
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_OC0_DISCONNECTED
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_NON_INVERTED_MODE
 *		-TIMER_8BIT_CMP_OUTPUT_MODE_PHASE_CORRECT_PWM_INVERTED_MODE
 */
#define TIMER0_CMP_OUTPUT_MODE		TIMER_8BIT_CMP_OUTPUT_MODE_FAST_PWM_NON_INVERTED_MODE

#endif /* TIMER_PRIVATE_H_ */