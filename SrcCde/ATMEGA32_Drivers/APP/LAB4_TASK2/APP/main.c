/*
 * File:    main.c
 * Author:  Yasmin Amr
 * Created: 12/28/2023
 * Brief:   External Interrupt APP
 * Target:  Atmega32
 */

#include "../MCAL/EXTI_Driver/EXTI.h"
#include "../hal/SSD_Driver/SSD.h"
#include "util/delay.h"
#include "Timer.h"


void DecrementTimerEXTI0(void)
{
	Decrement_Timer();
}
void IncrementTimerEXTI1(void)
{
	Increment_Timer();
}

int main(void)
{
	SWITCH_voidInit();
	EXTI_voidInit();
	SSD_Init();
	EXTI0_voidSetCallBack(DecrementTimerEXTI0);
	EXTI1_voidSetCallBack(IncrementTimerEXTI1);

    while (1) 
    {
		
    }
}




