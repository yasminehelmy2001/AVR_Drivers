/*
* File:    LCD_Priv.h
* Author:  Yasmin Amr
* Created: 1/1/2024
* Brief:   LCD Driver
* Target:  Atmega32
* Version: 1.00
*/


#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#include "../../LIB/std_types.h"
#include "../../MCAL/DIO_Driver/DIO.h"

/************************************************************************/
/*					       4-BIT/8-BIT MODE SELECT		                */
/************************************************************************/
#define FOUR_BIT_MODE		(0U)	
#define EIGHT_BIT_MODE		(1U)

/************************************************************************/
/*					           LCD PINS			                        */
/************************************************************************/
#define RS_PIN		(0U)
#define RW_PIN		(1U)
#define E_PIN		(2U)
#define D0_PIN		(3U)
#define D1_PIN		(4U)
#define D2_PIN		(5U)
#define D3_PIN		(6U)
#define D4_PIN		(7U)
#define D5_PIN		(8U)
#define D6_PIN		(9U)
#define D7_PIN		(10U)

/************************************************************************/
/*					 4-BIT/8-BIT LCD PIN NUMBER COUNT                   */
/************************************************************************/
#define FOUR_BIT_ARRAY_SIZE		(7U)		
#define EIGHT_BIT_ARRAY_SIZE	(11U)

#endif /* LCD_PRIV_H_ */