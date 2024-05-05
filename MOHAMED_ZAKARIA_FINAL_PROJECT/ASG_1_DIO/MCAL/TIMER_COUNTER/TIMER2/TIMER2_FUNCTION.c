/*
 * TIMER2_FUNCTION.c
 *
 * Created: 3/13/2024 9:57:35 PM
 *  Author: Mohamed
 */ 
#include "STD_TYPEDEF.h"
#include "BIT_MATH.h"
#include "GENERAL_INTERRAPT.h"
#include "TIMER0.h"
#include "TIMER_COUNTER_ADDRESES.h"
#include "DIO_FINCTION.h"
#include "TIMER2_FUNCTION.h"
void TIMER2_INIT(u8 TYPE,u8 STATE)
{
	GENERAL_INTERRAPT_ENABLE;
	/************************************************************************/
	/*                        normal mood                                   */
	/************************************************************************/
	if(TYPE==TIMER2_NORMAL)
	{
		RESET_BIT(TCCR2,WGM20);
		RESET_BIT(TCCR2,WGM21);
		SET_BIT(TIMSK,TOIE2);
	}
	/************************************************************************/
	/*                      PHASE CORRECT PWM                               */
	/************************************************************************/
	else if (TYPE==TIMER2_PHASE_CORRECT_PWM)
	{
		//RESET THE FORCED
		RESET_BIT(TCCR2,FOC2); 
		SET_BIT(TCCR2,WGM20);
		RESET_BIT(TCCR2,WGM21);
		if (STATE==OC2_DISCONNECTED)
		{
			RESET_BIT(TCCR2,COM20);
			RESET_BIT(TCCR2,COM21);
		}
		else if (STATE==CLEAN_OC2)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PIND7,OUTPUT);
			RESET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		}
		else if (STATE==SET_OC2)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PIND7,OUTPUT);
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		}
	}
	/************************************************************************/
	/*                             CTC                                      */
	/************************************************************************/
	else if (TYPE==TIMER2_CTC)
	{
		//SET THE FORCED
		SET_BIT(TCCR2,FOC2);
		SET_BIT(TIMSK,OCIE22);
		RESET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		if (STATE==OC2_DISCONNECTED)
		{
			RESET_BIT(TCCR2,COM20);
			RESET_BIT(TCCR2,COM21);
		}
		else if (STATE==TOGGEL_OC2)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PIND7,OUTPUT);
			SET_BIT(TCCR2,COM20);
			RESET_BIT(TCCR2,COM21);
		}
		else if (STATE==CLEAN_OC2)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PIND7,OUTPUT);
			RESET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		}
		else if (STATE==SET_OC2)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PIND7,OUTPUT);
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		}
	}
	/************************************************************************/
	/*                          FAST PWM                                    */
	/************************************************************************/
	else if (TYPE==TIMER2_FAST_PWM)
	{
		//SET THE FORCED
		RESET_BIT(TCCR2,FOC2);
		SET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		if (STATE==OC2_DISCONNECTED)
		{
			RESET_BIT(TCCR2,COM20);
			RESET_BIT(TCCR2,COM21);
		}
		else if (STATE==CLEAN_OC2)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PIND7,OUTPUT);
			RESET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		}
		else if (STATE==SET_OC2)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PIND7,OUTPUT);
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		}
	}
}
void TIMER2_START(u8 PRESCALER)
{
	if (PRESCALER==TIMER2_CLK_DIV_1)
	{
		SET_BIT(TCCR2,CS20);
		RESET_BIT(TCCR2,CS21);
		RESET_BIT(TCCR2,CS22);
	}
	else if (PRESCALER==TIMER2_CLK_DIV_8)
	{
		RESET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		RESET_BIT(TCCR2,CS22);
	}
	else if(PRESCALER==TIMER2_CLK_DIV_32)
	{
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		RESET_BIT(TCCR2,CS22);
	}
 	else if(PRESCALER==TIMER2_CLK_DIV_64)
 	{
 		RESET_BIT(TCCR2,CS20);
 		RESET_BIT(TCCR2,CS21);
 		SET_BIT(TCCR2,CS22);
 	}
	else if(PRESCALER==TIMER2_CLK_DIV_128)
	{
		SET_BIT(TCCR0,CS20);
		RESET_BIT(TCCR0,CS21);
		SET_BIT(TCCR0,CS22);
	}
	else if(PRESCALER==TIMER2_CLK_DIV_256)
	{
		RESET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
	}
	else if(PRESCALER==TIMER2_CLK_DIV_1024)
	{
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
	}
}
 void TIMER2_STOP(void)
 {
 	RESET_BIT(TCCR0,CS20);
 	RESET_BIT(TCCR0,CS21);
 	RESET_BIT(TCCR0,CS22);
 }
 void TIMER2_FREQUANCE(u8 F)
 {
 	if (F==F_TIMER2_62500)
 	{
 		TIMER2_START(TIMER2_CLK_DIV_1);
 	}
 	else if (F==F_TIMER2_7812)
 	{
 		TIMER2_START(TIMER2_CLK_DIV_8);
 	}
 	else if (F==F_TIMER2_1953)
 	{
 		TIMER2_START(TIMER2_CLK_DIV_32);
 	}
 	else if (F==F_TIMER2_976)
 	{
 		TIMER2_START(TIMER2_CLK_DIV_64);
 	}
 	else if (F==F_TIMER2_288)
 	{
 		TIMER2_START(TIMER2_CLK_DIV_128);
 	}
 	else if (F==F_TIMER2_244)
 	{
 		TIMER2_START(TIMER2_CLK_DIV_256);
 	}
 	else if (F==F_TIMER2_61)
 	{
 		TIMER2_START(TIMER0_CLK_DIV_1024);
 	}
 }
void TIMER2_setPreload(u8 ticks)
{
	TCNT2 = ticks;
} 
u8 TIMER2_READ_TIMER(void)
{
	return TCNT2;
}
void (*OV2_ptr)();
//CALL BACK FUNCTION
void TIMER2_setCallback( void (*APP_func)() )
{
	OV2_ptr = APP_func;
}

//OVER LOOD INTERRAPT
void __vector_5(void) __attribute__((signal,used));
void __vector_5(void)
{
	OV2_ptr();
}
//*****************************************************************************************
//CTC 
void TIMER_CTC2_WRITE(u8 NUMBER)
{
	OCR2=NUMBER;
}
void (*CTC2_ptr)();
//CTC CALL BACK FUNCTION
void TIMER2_setCallbackCTC( void (*APP_func)() )
{
	CTC2_ptr=APP_func;
}

// CTC2 INTTRABT
void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	CTC2_ptr();
}
/************************************************************************/
/*                             PWM                                      */
/************************************************************************/
void TIMER2_PWM_WRITE(u8 NUMBER)
{
	OCR2=NUMBER;
}
void TIMER2_PHASE_CORRECT_PWM_PRISNTAGE(u8 STATE,u8 DUTEY)
{
	if (STATE==CLEAN_OC2)
	{
		OCR2=((DUTEY*TOP2)/100);
	}
	else if(STATE==SET_OC2)
	{
		
	}
}