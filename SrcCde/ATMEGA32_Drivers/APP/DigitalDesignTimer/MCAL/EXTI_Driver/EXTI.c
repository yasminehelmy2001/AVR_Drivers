/*
* File:    EXT_INT.c
* Author:  Yasmin Amr
* Created: 12/28/2023
* Brief:   External Interrupt Driver  
* Target:  Atmega32
*/

/** 
*@Note: In Initialization of MCUCR Register: We created a local variable 
*		 to store MCUCR register value in order to set all values at once.
*		 Without it, we would need to clear and set the bits in TWO steps, 
*		 which would cause undefined behavior if an interrupt occurred 
*		 between these two steps.
*/

#include "EXTI.h"

/******************************************************************************/
/*					GLOBAL POINTER TO FUNCTION FOR CALLBACK		           	  */
/*								EXTI0,EXTI1,EXTI2							  */
/******************************************************************************/
void(*EXTI0_ISR)(void)=NULL;
void(*EXTI1_ISR)(void)=NULL;
void(*EXTI2_ISR)(void)=NULL;

/******************************************************************************/
/*                             CHECK ON CONFIGURATION		               	  */
/******************************************************************************/
 
 
#if !((INT0_CFG==INT0_LOW)||(INT0_CFG==INT0_FE)||(INT0_CFG==INT0_RE)||(INT0_CFG==INT0_LC))
	#error "Invalid INT0 Configuration"
#endif

#if !((INT1_CFG==INT1_LOW)||(INT1_CFG==INT1_FE)||(INT1_CFG==INT1_RE)||(INT1_CFG==INT1_LC))
	#error "Invalid INT1 Configuration"
#endif

#if !((INT2_CFG==INT2_LOW)||(INT2_CFG==INT2_FE)||(INT2_CFG==INT2_RE)||(INT2_CFG==INT2_LC))
	#error "Invalid INT2 Configuration"
#endif
 
 
/**
*@brief : Function to Initialize All Atmega32 External Interrupts (INT0,INT1,INT2)
*/
void EXTI_voidInit(void)
{
	
	/******************************************************************************/
	/*                             GLOBAL INT INITIALIZATION	            	  */
	/******************************************************************************/

	#if ((INT0_ENABLED == INT_ON) || (INT1_ENABLED == INT_ON) || (INT2_ENABLED == INT_ON))
		/* Enable global interrupt */
		SET_BIT(SREG, 7);
	#endif
	
	/******************************************************************************/
	/*                             EXT_INT0 INITIALIZATION	             		  */
	/******************************************************************************/

	#if INT0_ENABLED == INT_ON
	
		/*Create a local variable to store MCUCR value*/
		u8 Loc_u8RegValueInt0=MCUCR;
		
		/*Clear INT0 bits in MCUCR register*/
		Loc_u8RegValueInt0&=INT0_MASK;
		
		/*Set configuration bits from options:
		 * 1) INT0_LOW
		 * 2) INT0-LC
		 * 3) INT0_FE
		 * 4) INT0-RE
		 */
		Loc_u8RegValueInt0|=INT0_CFG;
		
		/*Send configured variable to MCUCR*/
		MCUCR=Loc_u8RegValueInt0;
	
		/*Enable INT0*/
		SET_BIT(GICR,INT0_BIT);
	
	#elif INT0_ENABLED == INT_OFF
		/*Disable INT0*/
		CLR_BIT(GICR,INT0_BIT);
		
	#else
		#error("Invalid INT0 Enabling Configuration")
	
	#endif
	
	/******************************************************************************/
	/*                             EXT_INT1 INITIALIZATION	             		  */
	/******************************************************************************/
	
	#if INT1_ENABLED == INT_ON
	
		/*Create a local variable to store MCUCR value*/
		u8 Loc_u8RegValueInt1=MCUCR;
		
		/*Clear INT1 bits in MCUCR register*/
		Loc_u8RegValueInt1&=INT1_MASK;
		
		/*Set configuration bits from options:
		 * 1) INT1_LOW
		 * 2) INT1-LC
		 * 3) INT1_FE
		 * 4) INT1-RE
		 */
		Loc_u8RegValueInt1|=(INT1_CFG<<2);
		
		/*Send configured variable to MCUCR*/
		MCUCR=Loc_u8RegValueInt1;
	
		/*Enable INT1*/
		SET_BIT(GICR,INT1_BIT);
	
	#elif INT1_ENABLED == INT_OFF
		/*Disable INT1*/
		CLR_BIT(GICR,INT1_BIT);
		
	#else
		#error("Invalid INT1 Enabling Configuration")
	
	#endif

	/******************************************************************************/
	/*                             EXT_INT2 INITIALIZATION	             		  */
	/******************************************************************************/
	
	#if INT2_ENABLED ==INT_ON

		/* Set ISC2 configuration bit in MCUSCR register*/
		#if INT2_CFG==INT2_FE
			CLR_BIT(MCUCSR,ISC2_BIT);
		#elif INT2_CFG==INT2_RE
			SET_BIT(MCUCSR,ISC2_BIT);
		#endif
		
		/*Enable INT2*/
		SET_BIT(GICR,INT2_BIT);
	
	#elif INT1_ENABLED == INT_OFF
		/*Disable INT2*/
		CLR_BIT(GICR,INT2_BIT);
		
	#else
		#error("Invalid INT2 Enabling Configuration")
	#endif
	
}


/**
*@brief : Function to Set Call Back Function from Application Layer for EXTI0
*/	
void EXTI0_voidSetCallBack(void(*cbf)(void))
{
	EXTI0_ISR=cbf;
}

/**
*@brief : Function to Set Call Back Function from Application Layer for EXTI1
*/
void EXTI1_voidSetCallBack(void(*cbf)(void))
{
	EXTI1_ISR=cbf;
}

/**
*@brief : Function to Set Call Back Function from Application Layer for EXTI2
*/
void EXTI2_voidSetCallBack(void(*cbf)(void))
{
	EXTI2_ISR=cbf;
}

/******************************************************************************/
/*									EXTI0_ISR					           	  */
/******************************************************************************/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI0_ISR!=NULL)
	{
		EXTI0_ISR();
	}
	else
	{
		
	}
	
}
/******************************************************************************/
/*									EXTI1_ISR					           	  */
/******************************************************************************/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI1_ISR!=NULL)
	{
		EXTI1_ISR();
	}
	else
	{
		
	}
}
/******************************************************************************/
/*									EXTI2_ISR					           	  */
/******************************************************************************/

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI2_ISR!=NULL)
	{
		EXTI2_ISR();
	}
	else
	{
		
	}
}