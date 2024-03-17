/*
 * SSD.h
 *
 * Created: 12/16/2023 2:49:41 PM
 *  Author: Yasmin Amr
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "SSD_Private.h"
#include "SSD_cfg.h"

typedef enum
{
	SSD_enumNotOk,
	SSD_enumOk,
	SSD_enumInvalidValue,
	SSD_enumInvalidSegmentName,
	SSD_enumInvalidInputValue
	}SSD_enumErrorStatus_t;

void SSD_Init(void);
SSD_enumErrorStatus_t SSD_enumSetValue(u8 Copy_u8SegName, u32 Value);
SSD_enumErrorStatus_t SSD_enumSetValueToAll(u32 Value);

#endif /* SSD_H_ */