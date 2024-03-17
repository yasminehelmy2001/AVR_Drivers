/*
 * File:    EXT_INT.h
 * Author:  Yasmin Amr
 * Created: 12/28/2023
 * Brief:   External Interrupt Driver 
 * Target:  Atmega32
 */


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "../DIO_Driver/DIO.h"
#include "EXTI_cfg.h"

 /**
 *@brief : Function to Initialize All Atmega32 External Interrupts (INT0,INT1,INT2)
 */
void EXTI_voidInit(void);

 /**
 *@brief : Function to Set Call Back Function from Application Layer for EXTI0
 */
void EXTI0_voidSetCallBack(void(*cbf)(void));


 /**
 *@brief : Function to Set Call Back Function from Application Layer for EXTI1
 */
void EXTI1_voidSetCallBack(void(*cbf)(void));


 /**
 *@brief : Function to Set Call Back Function from Application Layer for EXTI2
 */
void EXTI2_voidSetCallBack(void(*cbf)(void));

#endif /* EXT_INT_H_ */