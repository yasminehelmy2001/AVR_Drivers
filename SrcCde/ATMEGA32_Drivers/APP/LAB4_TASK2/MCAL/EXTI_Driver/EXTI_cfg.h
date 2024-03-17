/*
 * File:    EXT_INT_cfg.h
 * Author:  Yasmin Amr
 * Created: 12/28/2023
 * Brief:   External Interrupt Driver
 * Target:  Atmega32
 */

#ifndef EXT_INT_CFG_H_
#define EXT_INT_CFG_H_

#include "EXTI_PRIV.h"

/*******************************************************************************/
/* Choose to enable which interrupts from INT0, INT1, INT2                     */
/*		- INT_ON: Enable Interrupt											   */
/*		- INT_OFF: Disable Interrupt										   */
/*******************************************************************************/

#define INT0_ENABLED	INT_ON
#define INT1_ENABLED	INT_ON
#define INT2_ENABLED	INT_ON

/*******************************************************************************/
/* Choose INT0, INT1 & INT2 Configurations:                                    */
/*		- INT0_LOW: Cause an interrupt at Logical "LOW" (0V)				   */
/*		- INT0_LC:	Cause an interrupt at logical change					   */
/*		- INT0_FE:	Cause an interrupt at falling edge						   */
/*		- INT0_RE:	Cause an interrupt at rising edge					       */   
/*																			   */
/* Change number after "INT0" according to interrupt number:				   */
/*		-INT0, INT1, INT2													   */
/*******************************************************************************/

#define INT0_CFG	INT0_LOW
#define INT1_CFG	INT0_LOW
#define INT2_CFG	INT2_FE


#endif /* EXT_INT_CFG_H_ */