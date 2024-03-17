/*
* File:    main.c
* Author:  Yasmin Amr
* Created: 11/3/2024
* Brief:   ADC Testing
* Target:  ATMega32
*/

#include "../HAL/LED_Driver/LED.h"
#include "../MCAL/ADC_Driver/ADC.h"

int main(void)
{
	u16 result=0;
	LED_voidInit();
	ADC_Init();
while (1) 
    {	
		ADC_StartConversionSync(ADC_MUX_ADC0,&result);
		f32 step= (f32)5/1024;
		f32 analog= result*step;
		
		if((u16)analog>2)
		{
		LED_enumSetLedState(START_LED,DIO_enumLogicHigh);

		}
		else
		{
			LED_enumSetLedState(START_LED,DIO_enumLogicLow);
		}

    }
}
