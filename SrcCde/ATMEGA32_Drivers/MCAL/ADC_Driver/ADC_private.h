/*
* File:    ADC_private.h
* Author:  Yasmin Amr
* Created: 11/3/2024
* Brief:   ADC Driver
* Target:  ATMega32
*/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "../../LIB/std_types.h"

/**************************************************************************/
/*						ADC Register Addresses				 			  */
/**************************************************************************/
#define ADMUX							*((volatile u8*)0x27)
#define ADCSRA							*((volatile u8*)0x26)
#define ADCH							*((volatile u8*)0x25)
#define ADCL							*((volatile u8*)0x24)

/**************************************************************************/
/*						ADC VREF OPTIONS					 			  */
/**************************************************************************/
#define ADC_VREF_OFF					0X00
#define ADC_VREF_VCC					0X40
#define ADC_VREF_INTERNAL_25600mV		0X70

/**************************************************************************/
/*						ADC BIT OFFSETS						 			  */
/**************************************************************************/
#define ADC_ADEN						(7U)
#define ADC_ADIE						(3U)
#define ADC_ADLAR						(5U)
#define ADC_ADSC						(6U)
#define ADC_ADATE						(5U)
#define ADC_ADIF						(4U)
/**************************************************************************/
/*						ADC PRESCALER OPTIONS				 			  */
/**************************************************************************/
#define ADC_PRESCALER_DIV_BY_2			0x01	
#define ADC_PRESCALER_DIV_BY_4			0x02
#define ADC_PRESCALER_DIV_BY_8			0x03
#define ADC_PRESCALER_DIV_BY_16			0x04
#define ADC_PRESCALER_DIV_BY_32			0x05
#define ADC_PRESCALER_DIV_BY_64			0x06
#define ADC_PRESCALER_DIV_BY_128		0x07

/**************************************************************************/
/*						ADC INTERRUPT ENABLE OPTIONS		 			  */
/**************************************************************************/
#define ADC_DISABLE_INTERRUPTS			0x00
#define ADC_ENABLE_INTERRUPTS			0x08

/**************************************************************************/
/*						ADC AUTO TRIGGER ENABLE/DISABLE		 			  */
/**************************************************************************/
#define ADC_SINGLE_CONVERSION			0x00
#define ADC_AUTO_TRIGGER_ON				0x20

/**************************************************************************/
/*						ADC AUTO TRIGGER SOURCE				 			  */
/**************************************************************************/
#define ADC_MODE_FREE_RUNNING				0x00
#define ADC_MODE_ANALOG_COMPARATOR			0x01
#define ADC_MODE_EXT0_IRQ					0x02
#define ADC_MODE_TIMER0_COMPARE_MATCH		0x03
#define ADC_MODE_TIMER0_OVERFLOW			0x04
#define ADC_MODE_TIMER_COMPARE_MATCH_B		0x05
#define ADC_MODE_TIMER1_OVERFLOW			0x06
#define ADC_MODE_TIMER1_CAPTURE_EVENT		0x07

/**************************************************************************/
/*						ADC DATA REGISTER ADJUST			 			  */
/**************************************************************************/
#define	ADC_RIGHT_ADJUST	0x00
#define ADC_LEFT_ADJUST		0x20


/**************************************************************************/
/*						Chain States						 			  */
/**************************************************************************/
#define idle				(0U)
#define busy				(1U)

/**************************************************************************/
/*						Global Interrupt Defines			 			  */
/**************************************************************************/
#define GIE_BIT	(7U)
#define SREG    *(( volatile u8*) 0x5F)

#endif /* ADC_PRIVATE_H_ */