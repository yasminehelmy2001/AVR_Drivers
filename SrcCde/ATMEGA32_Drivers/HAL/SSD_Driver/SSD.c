/*
* File:    SSD.c
* Author:  Yasmin Amr
* Created: 12/16/2023
* Brief:   SSD Driver
* Target:  Atmega32
* Version: 1.00
*/


#include "../../MCAL/DIO_Driver/DIO.h"
#include "SSD.h"

/*extern SSD configuration array*/
extern SSD_strSegmentCfg_t SSD_strSegmentsArrCfg[SEG_NUM];
	
/**
*@brief : SSD Initialization function: SSD numbers, Ports & Pins
*/
void SSD_Init()
{
	/* 
	 * Create a DIO configuration array:
	 * Size= Total number of LEDS in all SSDs
	 */
	DIO_strDioCfg SSD_strSegmentMappingArr[SEG_NUM*SSD_LED_NO];

	/*Create an iterator to count to total number of LEDS in all SSDs*/
	u8 dio_iter=0;
	
	/*loop over all seven segments*/
	for(u8 seg_iter=0;seg_iter<SEG_NUM;seg_iter++)
		{
			    /************************************************************************/
			    /*						MAP LED A CONFIGURATION					        */
			    /************************************************************************/
				
				/*Map LED_A Port Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_A.Port;
				/*Map LED_A Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_A.Pin;
				/*Set LED_A Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				/*If seven segment state is Common Cathode*/
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;
				
				/************************************************************************/
				/*						MAP LED B CONFIGURATION					        */
				/************************************************************************/
				 
				/*Map LED_B Port Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_B.Port;
				/*Map LED_B Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_B.Pin;
				/*Set LED_B Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;
				
				/************************************************************************/
				/*						MAP LED C CONFIGURATION					        */
				/************************************************************************/
				 
				/*Map LED_C Port Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_C.Port;
				/*Map LED_C Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_C.Pin;
				/*Set LED_C Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;
				
				/************************************************************************/
				/*						MAP LED D CONFIGURATION					        */
				/************************************************************************/
				
				/*Map LED_D Port Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_D.Port;
				/*Map LED_D Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_D.Pin;
				/*Set LED_D Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;
				
				/************************************************************************/
				/*						MAP LED E CONFIGURATION					        */
				/************************************************************************/

				/*Map LED_E Port Configuration from SSD configuration array to DIO configuration array*/				
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_E.Port;
				/*Map LED_E Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_E.Pin;
				/*Set LED_E Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;
				
				/************************************************************************/
				/*						MAP LED F CONFIGURATION					        */
				/************************************************************************/
				
				/*Map LED_F Port Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_F.Port;
				/*Map LED_F Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_F.Pin;
				/*Set LED_F Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;
				
				/************************************************************************/
				/*						MAP LED G CONFIGURATION					        */
				/************************************************************************/
				 
				/*Map LED_G Port Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_G.Port;
				/*Map LED_G Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_G.Pin;
				/*Set LED_G Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;
				
				/************************************************************************/
				/*						MAP DOT LED CONFIGURATION				        */
				/************************************************************************/
				 
				/*Map LED_DOT Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Port= SSD_strSegmentsArrCfg[seg_iter].LED_DOT.Port;
				/*Map LED_DOT Pin Configuration from SSD configuration array to DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].Pin= SSD_strSegmentsArrCfg[seg_iter].LED_DOT.Pin;
				/*Set LED_DOT Configuration as output in DIO configuration array*/
				SSD_strSegmentMappingArr[dio_iter].PinConfig= DIO_enumOutput;
				/*If seven segment state is Common Anode*/
				if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonAnode)
				{
					/*Set current pin logic state to HIGH in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicHigh;
				}
				else if(SSD_strSegmentsArrCfg[seg_iter].State== SSD_enumCommonCathode)
				{
					/*Set current pin logic state to LOW in DIO configuration array (LED=OFF) */
					SSD_strSegmentMappingArr[dio_iter].LogicState=DIO_enumLogicLow;
				}
				/*Jump to next LED in same seven segment*/
				dio_iter++;	
	}
	/*Send configuration to DIO Driver*/
	DIO_enumSetConfig(SSD_strSegmentMappingArr,SEG_NUM*8);

}


/**
*@brief : Displays value onto one seven segment display
*@param : Segment name, Value to display
*@return: Error Status
*/
SSD_enumErrorStatus_t SSD_enumSetValue(u8 Copy_u8SegName, u32 Copy_u8DisplayValue)
{
	/*Set SSD error status to not OK*/
	SSD_enumErrorStatus_t RET_enumErrorStatus= SSD_enumNotOk;
	/*Check that SSD display value is between 0 and 9*/
	if(Copy_u8DisplayValue<ZERO || Copy_u8DisplayValue>NINE)
	{
		RET_enumErrorStatus=SSD_enumInvalidValue;
	}
	/*Check if seven segment name is valid*/
	else if(Copy_u8SegName>=SEG_NUM)
	{
		RET_enumErrorStatus=SSD_enumInvalidSegmentName;
	}
	/*All parameters are correct, continue with operation*/
	else
	{
		/*Set SSD error status to OK*/
		RET_enumErrorStatus=SSD_enumOk;
		
		/*Switch on display value*/
		switch(Copy_u8DisplayValue)
		{
													 /************************************************************************/
													 /*						   	 ZERO Display						         */
													 /************************************************************************/
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
			
												/************************************************************************/
												/*						   	 ONE Display						        */
												/************************************************************************/
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
			
												 /************************************************************************/
												 /*						   	 TWO Display						         */
												 /************************************************************************/
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
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
			
												 /************************************************************************/
												 /*						   	 THREE Display						         */
												 /************************************************************************/
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
						 DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicLow);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
			
													/************************************************************************/
													/*						   	 FOUR Display						        */
													/************************************************************************/
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
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
													 /************************************************************************/
													 /*						   	 FIVE Display						         */
													 /************************************************************************/
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
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
												 /************************************************************************/
												 /*						   	 SIX Display						         */
												 /************************************************************************/
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
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
											 /************************************************************************/
											 /*						   	 SEVEN Display						         */
											 /************************************************************************/
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
			
										 /************************************************************************/
										 /*						   	 EIGHT Display						         */
										 /************************************************************************/
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
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicHigh);
					break;
					case SSD_enumCommonCathode:
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_A.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_B.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_C.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_D.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_E.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_F.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_G.Pin,DIO_enumLogicHigh);
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
			
										 /************************************************************************/
										 /*						   	 NINE Display						         */
										 /************************************************************************/
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
						DIO_enumSetPin(SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Port,SSD_strSegmentsArrCfg[Copy_u8SegName].LED_DOT.Pin,DIO_enumLogicLow);
					break;
				}
			break;
		}
	}
	
	/*return error status*/
	return RET_enumErrorStatus;
	
}

/**
*@brief : Counts how many digits in a numeric value(Ex: 123 has 3 values)
*@param : Value to display
*@return: Digits in Value
*/
u8 SSD_u8CountDigits(u32 Copy_u8Value)
{
	/*create counter variable=0*/
	u8 Loc_u8Counter=0;
	/*For all digits inside value*/
	while(Copy_u8Value!=0)
	{
		/*remove last digit of variable*/
		Copy_u8Value=Copy_u8Value/10;
		/*increment digit counter*/
		Loc_u8Counter++;
	}	
	/*return counter*/
	return Loc_u8Counter;
}

/**
*@brief : Displays value onto all seven segment displays
*@param : Value to display
*@return: Error Status
*/
SSD_enumErrorStatus_t SSD_enumSetValueToAll(u32 Copy_u8DisplayValue)
{
	/*Create a variable to store total number of digits in a number*/
	u8 Loc_u8Totaldigits;
	
	/*Set error status to Not OK*/
	SSD_enumErrorStatus_t RET_enumErrorStatus=SSD_enumNotOk;
	
	/*Count number of digits in the Copy_u8DisplayValue parameter*/
	Loc_u8Totaldigits=SSD_u8CountDigits(Copy_u8DisplayValue);
	
	/*Check if total number of digits exceed the total amount of seven segments*/
	if(Loc_u8Totaldigits>SEG_NUM || Copy_u8DisplayValue<ZERO)
	{
		/*Unable to display number due to low SSD's*/
		RET_enumErrorStatus=SSD_enumInvalidInputValue;
	}
	else
	{
		/*Set error status to OK*/
		RET_enumErrorStatus=SSD_enumOk;
		/*Index to point to stack array*/
		u8 Loc_u8CurrentSevenSegment=0;
		/*Create a stack array to store digits of value in reverse order*/
		u8 Loc_u8Stack[SEG_NUM]={0};
		/*Until I store all digits of value in the array*/
		while(Copy_u8DisplayValue!=ZERO)
		{
			/*Store last digit of value in the stack array*/
			Loc_u8Stack[Loc_u8CurrentSevenSegment]=Copy_u8DisplayValue%10;
			/*Remove last digit from value*/
			Copy_u8DisplayValue=Copy_u8DisplayValue/10;
			/*Increment number of displays stored in stack array*/
			Loc_u8CurrentSevenSegment++;
		}
		/*Create an index to point to first element of stack array */
		u8 Loc_u8StackIndex=0;
		/*Index now contains last seven segment display name value*/
		Loc_u8CurrentSevenSegment=SEG_NUM-1;
		/*Loop over all seven segment displays*/
		while(Loc_u8CurrentSevenSegment>=ZERO)
		{
			/*Display first digit of stack array onto last seven segment display*/
			SSD_enumSetValue(Loc_u8CurrentSevenSegment,Loc_u8Stack[Loc_u8StackIndex]);
			/*Increment stack array index*/
			Loc_u8StackIndex++;
			/*Decrement seven segment display name value*/
			Loc_u8CurrentSevenSegment--;
		}
	}
	/*return error status*/
	return RET_enumErrorStatus;
}
