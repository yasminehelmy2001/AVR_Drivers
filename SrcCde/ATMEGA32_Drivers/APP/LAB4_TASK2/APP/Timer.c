/*
 * File:    Timer.c
 * Author:  Yasmin Amr
 * Created: 12/28/2023
 * Brief:   SSD Increment/Decrement Timer Functionalities 
 * Target:  Atmega32
 */

#include "../MCAL/DIO_Driver/DIO.h"
#include "../HAL/LED_Driver/LED.h"
#include "../HAL/SSD_Driver/SSD.h"
#include "../HAL/SWITCH_Driver/SWITCH.h"
#include "Timer.h"
#include "util/delay.h"

u8 TIMER_u8FirstSevSegcounter=ZERO;
u8 TIMER_u8SecondSevSegcounter=ZERO;
u8 TIMER_u8ThirdSevSegcounter=ZERO;
u8 TIMER_u8SwitchFlag=ZERO;

void Decrement_Timer(void)
{
    SWITCH_enumSwitchState_t Loc_enumSwitchState=SWITCH_enumNotPressed;
    SWITCH_enuReadSwitchState(FIRST_SWITCH, &Loc_enumSwitchState);
    if (Loc_enumSwitchState == SWITCH_enumPressed)
    {
        _delay_ms(100);

        if (TIMER_u8FirstSevSegcounter > ZERO && TIMER_u8FirstSevSegcounter <= NINE)
        {
            TIMER_u8FirstSevSegcounter--;
        }
        else if (TIMER_u8FirstSevSegcounter == ZERO)
        {
        	TIMER_u8FirstSevSegcounter = NINE;
        	if(TIMER_u8SecondSevSegcounter!=ZERO)
        	{
            TIMER_u8SecondSevSegcounter--;
        	}
        	else
        	{
        		TIMER_u8SecondSevSegcounter=FIVE;
        	}
        }

        SSD_enumSetValue(FIRST_SEG, TIMER_u8FirstSevSegcounter);
        SSD_enumSetValue(SECOND_SEG, TIMER_u8SecondSevSegcounter);
    }
}
void Increment_Timer(void)
{
    SWITCH_enumSwitchState_t Loc_enumSwitchState=SWITCH_enumNotPressed;
    SWITCH_enuReadSwitchState(SECOND_SWITCH, &Loc_enumSwitchState);
    if (Loc_enumSwitchState == SWITCH_enumPressed)
    {
        _delay_ms(100);

        if (TIMER_u8FirstSevSegcounter >= ZERO && TIMER_u8FirstSevSegcounter < NINE)
        {
            TIMER_u8FirstSevSegcounter++;
        }
        else if (TIMER_u8FirstSevSegcounter == NINE)
        {
            TIMER_u8FirstSevSegcounter = ZERO;

            if (TIMER_u8SecondSevSegcounter < FIVE)
            {
                TIMER_u8SecondSevSegcounter++;
            }
            else
            {
                TIMER_u8SecondSevSegcounter = ZERO;
            }
        }

        SSD_enumSetValue(FIRST_SEG, TIMER_u8FirstSevSegcounter);
        SSD_enumSetValue(SECOND_SEG, TIMER_u8SecondSevSegcounter);
    }
}


void Start_Timer(void)
{
	SWITCH_enumSwitchState_t Loc_enumSwitchState;
	SWITCH_enuReadSwitchState(THIRD_SWITCH,&Loc_enumSwitchState);
	if(Loc_enumSwitchState==SWITCH_enumPressed || TIMER_u8SwitchFlag==ONE)
	{
		TIMER_u8SwitchFlag=ONE;
		_delay_ms(100);

		        if (TIMER_u8FirstSevSegcounter > ZERO && TIMER_u8FirstSevSegcounter <= NINE)
		        {
		            TIMER_u8FirstSevSegcounter--;
		        }
		        else if (TIMER_u8FirstSevSegcounter == ZERO)
		        {

		        	if(TIMER_u8SecondSevSegcounter!=ZERO)
		        	{
		        		TIMER_u8FirstSevSegcounter = NINE;
		        		TIMER_u8SecondSevSegcounter--;
		        	}
		        	else
		        	{
		        		TIMER_u8SecondSevSegcounter=ZERO;
		        	}

		        }

		        SSD_enumSetValue(FIRST_SEG, TIMER_u8FirstSevSegcounter);
		        SSD_enumSetValue(SECOND_SEG, TIMER_u8SecondSevSegcounter);
		        
				if(TIMER_u8SecondSevSegcounter==ZERO && TIMER_u8FirstSevSegcounter==ZERO)
		        {
		        	TIMER_u8SwitchFlag=ZERO;
		        }
		        else
		        {
		        	/*Do Nothing*/
		        }
	}
}
