/*
 * File:    main.c
 * Author:  Yasmin Amr
 * Created: 12/28/2023
 * Brief:   External Interrupt APP
 * Target:  Atmega32
 */
/*
#include "../MCAL/EXTI_Driver/EXTI.h"
#include "../hal/SSD_Driver/SSD.h"
#include "util/delay.h"
#include "Timer.h"


void BlinkingLedEXTI0(void)
{
	Decrement_Timer();
}
void BlinkingLedEXTI1(void)
{
	Increment_Timer();
}

int main(void)
{
	SSD_Init();
	EXTI0_voidSetCallBack(BlinkingLedEXTI0);
	EXTI1_voidSetCallBack(BlinkingLedEXTI1);

    while (1) 
    {
		
    }
}
*/

/*
 * main.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Yasmin Amr
 */


#include "../MCAL/DIO_Driver/DIO.h"
#include "../HAL/LED_Driver/LED.h"
#include "../HAL/SSD_Driver/SSD.h"
#include "../HAL/SWITCH_Driver/SWITCH.h"
#include "Timer.h"

int main (void)
{
	LED_voidInit();
	SSD_Init();
	SWITCH_voidInit();

	while(1)
	{
		Increment_Timer();
		Decrement_Timer();
		Start_Timer();
	}
}


