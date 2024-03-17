/*
 * main.c
 *
 * Created: 12/2/2023 3:04:01 PM
 *  Author: yasmi
 */ 

#include "../MCAL/PORT_Driver/PORT.h"
#include "../MCAL/DIO_Driver/DIO.h"
#include "util/delay.h"

void main (void)
{
	PORT_voidInit(); /*Set PortA-P0 & PortA-P1 as Outputs*/
	
	while(1)
	{
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);
		_delay_ms(1000);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
		_delay_ms(1000);
	}
	
}

