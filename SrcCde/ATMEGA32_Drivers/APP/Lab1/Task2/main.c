#include "../MCAL/PORT_Driver/PORT.h"
#include "../MCAL/DIO_Driver/DIO.h"
#include "util/delay.h"

int main(void)
{
	PORT_voidInit();
	
	u8 counter=0;
	DIO_enumLogicState DIO_enumLogicStateValue;
	while (1)
	{
		DIO_enumReadState(DIO_enumPortA,DIO_enumPin4,&DIO_enumLogicStateValue);
		if(DIO_enumLogicStateValue==0)
		{
			_delay_ms(500);
			counter++;
			
			if(counter==16)
			{
				counter=0;
			}
			if(GET_BIT(counter,0)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
			}
			if(GET_BIT(counter,1)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
			}
			if(GET_BIT(counter,2)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin2,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin2,DIO_enumLogicLow);
			}
			if(GET_BIT(counter,3)==1)
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin3,DIO_enumLogicHigh);
			}
			else
			{
				DIO_enumSetPin(DIO_enumPortA,DIO_enumPin3,DIO_enumLogicLow);
			}
		}
	}
}

