/*
* File:    ADC_cfg.h
* Author:  Yasmin Amr
* Created: 11/3/2024
* Brief:   ADC Driver
* Target:  ATMega32
*/

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#include "ADC_private.h"

/**
 * Choose your ADC VREF:
 *			1) ADC_VREF_OFF				
 *			2) ADC_VREF_VCC				
 *			3) ADC_VREF_INTERNAL_25600mV	
 *
 * @note	Vref is the Voltage Represented When All Bits are Equal to One. 
 *			Set Vref= Your Max Sensor Value & Not Lower to Avoid Clipping!!
 * 
 */
#define ADC_VREF				ADC_VREF_VCC

/**
 * Choose your ADC VREF:
 *			1) ADC_PRESCALER_DIV_BY_2				
 *			2) ADC_PRESCALER_DIV_BY_4				
 *			3) ADC_PRESCALER_DIV_BY_8
 *			4) ADC_PRESCALER_DIV_BY_16
 *			5) ADC_PRESCALER_DIV_BY_32
 *			6) ADC_PRESCALER_DIV_BY_64
 *			7) ADC_PRESCALER_DIV_BY_128	
 */
#define ADC_PRESCALER			ADC_PRESCALER_DIV_BY_2

/**
 * Choose to Enable/Disable your Interrupts
 *			1) ADC_DISABLE_INTERRUPTS				
 *			2) ADC_ENABLE_INTERRUPTS				
 */
#define ADC_INTERRUPT_STATE		ADC_ENABLE_INTERRUPTS

/**
 * Choose to Set the Auto Trigger Mode to On or Off(Single Conversion Mode)
 *			1) ADC_SINGLE_CONVERSION				
 *			2) ADC_AUTO_TRIGGER_ON				
 */
#define ADC_AUTO_TRIGGER		ADC_SINGLE_CONVERSION

/**
 * Choose your ADC AUTO TRIGGER MODE
 *			1) ADC_MODE_FREE_RUNNING				
 *			2) ADC_MODE_ANALOG_COMPARATOR				
 *			3) ADC_MODE_EXT0_IRQ
 *			4) ADC_MODE_TIMER0_COMPARE_MATCH
 *			5) ADC_MODE_TIMER0_OVERFLOW
 *			6) ADC_MODE_TIMER_COMPARE_MATCH_B
 *			7) ADC_MODE_TIMER1_OVERFLOW	
 *			8) ADC_MODE_TIMER1_CAPTURE_EVENT
 */
#define ADC_AUTO_TRIGGER_MODE	ADC_MODE_FREE_RUNNING

/**
 * Choose your Data Adjustment Type:
 *			1) ADC_LEFT_ADJUST				
 *			2) ADC_RIGHT_ADJUST				
 */
#define ADC_DATA_ADJUST			ADC_LEFT_ADJUST	

#endif /* ADC_CFG_H_ */