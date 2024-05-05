/*
 * PROJECT_PROCESSES.c
 *
 * Created: 4/6/2024 8:49:25 PM
 *  Author: Mohamed
 */ 
#include "PROJECT_FUNCTION_HEADERS.h"
#include "PROJECT_PINS.h"
#include "SEVEN_SEGMENT.h"
#include "ADC_FUNCTION.h"
#include "GENERAL_INTERRAPT.h"
#include "EEPROM_INIT.h"
u8 TEMP=0;
u8 TEMP_NEEDED;
u8 MAX_TEMP =75;
u8 EMERGANCY_TEMP=90;
u8 START_STOP_FLAG =0;
/************************************************************************/
/*                         RAED TEMP AT 1S               (T0)           */
/************************************************************************/
 u8 OVERFLOW=0;
 void __vector_11(void) __attribute__((signal,used));
 void __vector_11(void)
 {
 	if(OVERFLOW==61)
 	{
	 	TEMP=THERMOSTAT_READ();
		TEMP_NEEDED=EEPROM_read(0x10);
		SEVEN_SEGMENT_WRITE_DOUBLE(TEMP);
	 	OVERFLOW=0;
 	}
 	else
 	{
	 	OVERFLOW++;
 	}
 }
 /************************************************************************/
 /*                           EMERGANCY                                  */
 /************************************************************************/
 u8 EMERGANCY_FLAG=0;
 void EMERGANCY_CHECK(void)
 {
	 PRE_EMERGANCY();
	 if (TEMP>EMERGANCY_TEMP)
	 {
		 SET_COOLER(OFF);
		 SET_HEATER(0);
		 SET_FIRE_FIGHTING_PUMP(ON);
		 EMERGANCY_FLAG++;
	 } 
	 else
	 {
		 SET_FIRE_FIGHTING_PUMP(OFF);
		 EMERGANCY_FLAG=0;
	 }
 }
 /************************************************************************/
 /*                           MAX TEMP                                   */
 /************************************************************************/
 void PRE_EMERGANCY(void)
 {
	 if (TEMP>MAX_TEMP)
	 {
		 SET_EMERGANCY(ON);
	 }
	 else
	 {
		 SET_EMERGANCY(OFF);
	 }
 }
 /************************************************************************/
 /*                           TEMP CONTROL                               */
 /************************************************************************/
 u8 I=0;
 void __vector_2(void) __attribute__((signal,used));
 void __vector_2(void)
 {
	 if(I!=0)
	 {
		if(TEMP_NEEDED<MAX_TEMP)
		{
			PROJECT_EEPROM_INC();
		} 
	 }
	 I++;
       
 }
 void __vector_3(void) __attribute__((signal,used));
 void __vector_3(void)
 {
	if(TEMP_NEEDED>0)
	{
		PROJECT_EEPROM_DEC();
	} 
 }
 /************************************************************************/
 /*                       START_STOP                                     */
 /************************************************************************/
 void __vector_1(void) __attribute__((signal,used));
 void __vector_1(void)
 {
	 if (START_STOP_FLAG==0)
	 {
		START_STOP_FLAG++;
	 } 
	 else
	 {
		 START_STOP_FLAG=0;
	 }
	  
 }
 u8 COLLER_STATE=0;
 void MAIN_APP(void)
 {
	 EMERGANCY_CHECK();
	 if (START_STOP_FLAG==0)
	 {
		 
		 if(DIO_INPUT(HEATER_COOLER_SLECTION)==0) //heating zoon
		 {
			 SET_COOLER(OFF);
			 COLLER_STATE=0;
			 if(TEMP<TEMP_NEEDED)
			 {
				 while(TEMP<TEMP_NEEDED)
				 {
					 if((START_STOP_FLAG==0)&&DIO_INPUT(HEATER_COOLER_SLECTION)==0)
					 {
					     if (TEMP<TEMP_NEEDED)
					     {
						     SET_HEATER(100-TEMP);
					     }
					     else if(TEMP==TEMP_NEEDED)
					     {
						     SET_HEATER(TEMP_NEEDED);
					     }
					 }
					 else
					 {
					     SET_HEATER(0);
					     break;
					 }
				 }
			 }	 
		 }
		 else if(DIO_INPUT(HEATER_COOLER_SLECTION)==1)//cooling zoon
		 {
			 SET_HEATER(0);
			 if (COLLER_STATE==0)
			 {
				 COLLER_STATE++;
				 while(TEMP>TEMP_NEEDED)
				 {
					 if ((START_STOP_FLAG==0)&&(DIO_INPUT(HEATER_COOLER_SLECTION)==1))
					 {
						 SET_COOLER(ON);
					 }
					 else
					 {
						 SET_COOLER(OFF);
						 break;
					 }
				 }
				 SET_COOLER(OFF);
			 } 
			 else
			 {
				 while(TEMP>(TEMP_NEEDED+5))
				 {
					if ((START_STOP_FLAG==0)&&DIO_INPUT(HEATER_COOLER_SLECTION)==1)
					{
						SET_COOLER(ON);
					}
					else
					{
						SET_COOLER(OFF);
						break;
					} 
				 }
				 SET_COOLER(OFF);
			 }
		 }
	}
	 else
	 {
		 SET_HEATER(0);
		 SET_COOLER(OFF);
		 COLLER_STATE=0;
	 }
}