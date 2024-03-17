/*
* File:    main.c
* Author:  Yasmin Amr
* Created: 11/3/2024
* Brief:   ADC Testing
* Target:  ATMega32
*/

#include "../HAL/LED_Driver/LED.h"
#include "../MCAL/ADC_Driver/ADC.h"

		ADC_Chain_t Loc_chain;

void APPChainEnd(void) {

  	f32 step= (f32)5/1024;
  	f32 analog= ((Loc_chain.results[0])*step);

	if((u16)analog>2)
	{
		LED_enumSetLedState(START_LED,DIO_enumLogicHigh);

	}
	else
	{
		LED_enumSetLedState(START_LED,DIO_enumLogicLow);
	}
}


int main(void)
{
	u16 result=0;
	LED_voidInit();
	ADC_Init();
		Loc_chain.length=1;
		Loc_chain.channels[0]=ADC_MUX_ADC0;
		Loc_chain.APP_function=APPChainEnd;
while (1) 
    {	
		ADC_StartConversionAsync (&Loc_chain);
    }
}
