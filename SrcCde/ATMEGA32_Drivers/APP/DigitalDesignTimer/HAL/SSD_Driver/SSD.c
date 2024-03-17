/*
 * SSD.c
 *
 * Created: 12/16/2023 2:49:05 PM
 *  Author: Yasmin Amr
 */ 


#include "../../MCAL/DIO_Driver/DIO.h"
#include "SSD.h"

extern SSD_strSegmentCfg_t SSD_strSegmentsArrCfg[SEG_NUM];
	
void SSD_Init()
{
	
	DIO_strDioCfg SSD_strSegmentMappingArr[SEG_NUM*SSD_LED_NO];

	u8 dio_iter=0;
	
	for(u8 seg_iter=0;seg_iter<SEG_NUM;seg_iter++)
		{
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_A.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_A.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
			
				dio_iter++;
				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_B.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_B.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				
				dio_iter++;
				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_C.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_C.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				
				dio_iter++;
				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_D.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_D.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				
				dio_iter++;
				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_E.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_E.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				
				dio_iter++;
				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_F.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_F.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				
				dio_iter++;
				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_G.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_G.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				
				dio_iter++;
				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_DOT.Port;
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_DOT.Pin;
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				
				dio_iter++;
				
	}
	
	DIO_enumSetConfig(SSD_strSegmentMappingArr,SEG_NUM*8);

}

SSD_enumErrorStatus_t SSD_enumSetValue(u8 Copy_u8SegName, u32 Copy_u8DisplayValue)
{
	SSD_enumErrorStatus_t RET_enumErrorStatus= SSD_enumNotOk;
	if(Copy_u8DisplayValue<ZERO || Copy_u8DisplayValue>NINE)
	{
		RET_enumErrorStatus=SSD_enumInvalidValue;
	}
	else if(Copy_u8SegName>=SEG_NUM)
	{
		RET_enumErrorStatus=SSD_enumInvalidSegmentName;
	}
	else
	{
		RET_enumErrorStatus=SSD_enumOk;
		switch(Copy_u8DisplayValue)
		{
			case ZERO:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				
					case SSD_enumCommonCathode:
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
			case ONE:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
					case SSD_enumCommonCathode:
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
			case TWO:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				}
			break;
			case THREE:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				}
			break;
			case FOUR:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				}
			break;
			case FIVE:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
				break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				}
			break;
			case SIX:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				}
			break;
			case SEVEN:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
				case SSD_enumCommonAnode:
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
				break;
				case SSD_enumCommonCathode:
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
					DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
				break;
				}
			break;
			case EIGHT:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				}
			break;
			case NINE:
				switch(SSD_strSegmentsArrCfg[Copy_u8SegName].State)
				{
					case SSD_enumCommonAnode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
				}
			break;
		}
	}
	
	return RET_enumErrorStatus;
	
}
u8 SSD_u8CountDigits(u32 Copy_u8Value)
{
	u8 Loc_u8Counter=0;
	while(Copy_u8Value!=0)
	{
		Copy_u8Value=Copy_u8Value/10;
		Loc_u8Counter++;
	}	
	return Loc_u8Counter;
}

SSD_enumErrorStatus_t SSD_enumSetValueToAll(u32 Copy_u8DisplayValue)
{
	u8 Loc_u8Totaldigits;
	SSD_enumErrorStatus_t RET_enumErrorStatus=SSD_enumNotOk;
	Loc_u8Totaldigits=SSD_u8CountDigits(Copy_u8DisplayValue);
	if(Loc_u8Totaldigits>SEG_NUM || Copy_u8DisplayValue<ZERO)
	{
		RET_enumErrorStatus=SSD_enumInvalidInputValue;
	}
	else
	{
		RET_enumErrorStatus=SSD_enumOk;
		u8 Loc_u8StackLastValuePosition=0;
		u8 Loc_u8Stack[SEG_NUM]={0};
		while(Copy_u8DisplayValue!=ZERO)
		{
	
			Loc_u8Stack[Loc_u8StackLastValuePosition]=Copy_u8DisplayValue%10;
			Copy_u8DisplayValue=Copy_u8DisplayValue/10;
			Loc_u8StackLastValuePosition++;
		}
		u8 Loc_u8StackIndex=0;
		Loc_u8StackLastValuePosition=SEG_NUM-1;
		while(Loc_u8StackLastValuePosition>=ZERO)
		{
			SSD_enumSetValue(Loc_u8StackLastValuePosition,Loc_u8Stack[Loc_u8StackIndex]);
			Loc_u8StackIndex++;
			Loc_u8StackLastValuePosition--;
			
		}
	}
	
	return RET_enumErrorStatus;
}
