/*
 * DIO_Priv.h
 *
 * Created: 12/24/2023 3:31:29 AM
 *  Author: Yasmin Amr 
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#include "../LIB/std_types.h"
#include "../LIB/std_math.h"

/*Defining PORT Register Addresses*/
#define DDRA *((volatile uint8*)0x3A)
#define DDRB *((volatile uint8*)0x37)
#define DDRC *((volatile uint8*)0x34)
#define DDRD *((volatile uint8*)0x31)

#define PORTA *((volatile uint8*)0x3B)
#define PORTB *((volatile uint8*)0x38)
#define PORTC *((volatile uint8*)0x35)
#define PORTD *((volatile uint8*)0x32)

#define PINA  *((volatile uint8*)0x39)
#define PINB  *((volatile uint8*)0x36)
#define PINC  *((volatile uint8*)0x33)
#define PIND  *((volatile uint8*)0x30)

#endif /* DIO_PRIV_H_ */