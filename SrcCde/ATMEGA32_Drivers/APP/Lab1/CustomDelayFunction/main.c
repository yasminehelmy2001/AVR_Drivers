/*
 * CustomDelayFunction.c
 *
 * Created: 11/29/2023 10:13:23 AM
 * Author : yasmi
 */ 


#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

void Delay_Function_ms (double delay_count_ms)
{
		
	for(int i=0;i<delay_count_ms;i++)              /*takes delay time in ms*/
	{
		for(int j=0;j<(F_CPU/1000)/10;j++)    
		      
		/*	Time per cycle=1/8us, 
		 *  F_CPU/1000=8000,
		 *  Loop time= 8000*(1/8)us=1000us
		 *  So each outer loop, 1000us=1ms will pass
		 *  We divided by 10 as we have approximately 10 assembly instructions in this function which will each take up 1/8us
		*/
		
		{
			/*Do Nothing*/
			asm("NOP");
		}
	}
}

int main(void)
{
	/*Set Port A as Output*/
	DDRA=0xFF;     
    
    while (1) 
    {
		/*Set Port A as High*/
		PORTA=0xFF;
		/*Delay 1000ms*/      
		Delay_Function_ms(1000);   
		/*Set Port A as Low*/  
		PORTA=0x00;		 
		/*Delay 1000ms*/
		Delay_Function_ms(1000);		
    }
}

