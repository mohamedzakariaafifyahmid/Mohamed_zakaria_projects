/*
 * TIMER0.c
 *
 * Created: 3/1/2024 5:45:58 PM
 *  Author: Mohamed
 */ 
#include "STD_TYPEDEF.h"
#include "BIT_MATH.h"
#include "GENERAL_INTERRAPT.h"
#include "TIMER0.h"
#include "TIMER_COUNTER_ADDRESES.h"
#include "DIO_FINCTION.h"
void TIMER0_INIT(u8 TYPE,u8 STATE)
{
	GENERAL_INTERRAPT_ENABLE;
	if(TYPE==TIMER0_NORMAL)
	{
		RESET_BIT(TCCR0,WGM00);
		RESET_BIT(TCCR0,WGM01);
		SET_BIT(TIMSK, TOIE0);
	}
	else if (TYPE==TIMER0_PHASE_CORRECT_PWM)
	{
		//RESET THE FORCED
		RESET_BIT(TCCR0,FOC0);
		SET_BIT(TCCR0,WGM00);
		RESET_BIT(TCCR0,WGM01);
		
		if (STATE==OC0_DISCONNECTED)
		{
			RESET_BIT(TCCR0,COM00);
			RESET_BIT(TCCR0,COM01);
		}
		else if (STATE==CLEAN_OC0)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PINB3,OUTPUT);
			RESET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}
		else if (STATE==SET_OC0)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PINB3,OUTPUT);
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}
	}
	else if (TYPE==TIMER0_CTC)
	{
		//SET THE FORCED
		SET_BIT(TCCR0,FOC0);  
		SET_BIT(TIMSK,OCIE0);
		RESET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		if (STATE==OC0_DISCONNECTED)
		{
			RESET_BIT(TCCR0,COM00);
			RESET_BIT(TCCR0,COM01);
		}
		else if (STATE==TOGGEL_OC0)
 		{
 			DIO_SIT_BIT_DIRICTION(DIO_PINB3,OUTPUT);
 			SET_BIT(TCCR0,COM00);
			RESET_BIT(TCCR0,COM01);
		}
 		else if (STATE==CLEAN_OC0)
 		{
 			DIO_SIT_BIT_DIRICTION(DIO_PINB3,OUTPUT);
 			RESET_BIT(TCCR0,COM00);
 			SET_BIT(TCCR0,COM01);
 		}
 		else if (STATE==SET_OC0)
 		{
 			DIO_SIT_BIT_DIRICTION(DIO_PINB3,OUTPUT);
 			SET_BIT(TCCR0,COM00);
 			SET_BIT(TCCR0,COM01);
 		}
	}
	else if (TYPE==TIMER0_FAST_PWM)
	{
		//SET THE FORCED
		RESET_BIT(TCCR0,FOC0);
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		if (STATE==OC0_DISCONNECTED)
		{
			RESET_BIT(TCCR0,COM00);
			RESET_BIT(TCCR0,COM01);
		}
		else if (STATE==CLEAN_OC0)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PINB3,OUTPUT);
			RESET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}
		else if (STATE==SET_OC0)
		{
			DIO_SIT_BIT_DIRICTION(DIO_PINB3,OUTPUT);
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}
	}
}
void TIMER0_START(u8 PRESCALER)
{
	if (PRESCALER==TIMER0_CLK_DIV_1)
	{
		SET_BIT(TCCR0,CS00);
		RESET_BIT(TCCR0,CS01);
		RESET_BIT(TCCR0,CS02);
	} 
	else if (PRESCALER==TIMER0_CLK_DIV_8)
	{
		RESET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		RESET_BIT(TCCR0,CS02);
	}
	else if(PRESCALER==TIMER0_CLK_DIV_64)
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		RESET_BIT(TCCR0,CS02);
	}
	else if(PRESCALER==TIMER0_CLK_DIV_256)
	{
		RESET_BIT(TCCR0,CS00);
		RESET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}
	else if(PRESCALER==TIMER0_CLK_DIV_1024)
	{
		SET_BIT(TCCR0,CS00);
		RESET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}
	else if(PRESCALER==TIMER0_CLK_EXTERNAL_FALLING)
	{
		RESET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}
	else if(PRESCALER==TIMER0_CLK_EXTERNAL_RISING)
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}
}
void TIMER0_STOP(void)
{
	RESET_BIT(TCCR0,CS00);
	RESET_BIT(TCCR0,CS01);
	RESET_BIT(TCCR0,CS02);
}
void TIMER0_setPreload(u8 ticks)
{
	TCNT0 = ticks;
}
u8 TIMER0_READ_TIMER(void)
{
	return TCNT0;
}

void (*OV_ptr)();

void TIMER0_setCallback( void (*APP_func)() )
{
	OV_ptr = APP_func;
}

//*******************************************************************************************************************
//CTC
void TIMER_CTC0_WRITE(u8 NUMBER)
{
	OCR0=NUMBER;
}

void (*CTC_ptr)();

void TIMER0_setCallbackCTC( void (*APP_func)() )
{
	CTC_ptr=APP_func;
}


void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	CTC_ptr();
}
//**********************************************************************************************************************
//PWM_TIMER0_PHASE_CORRECT_PWM
void TIMER0_PHASE_CORRECT_PWM_PRISNTAGE(u8 STATE,u8 DUTEY)
{
	if (STATE==CLEAN_OC0)
	{
		OCR0=((DUTEY*(TOP0+1))/100)-1;
	} 
	else if(STATE==SET_OC0)
	{
		
	}
}
void TIMER0_FREQUANCE(u8 F)
{
	if (F==F_62500)
	{
		TIMER0_START(TIMER0_CLK_DIV_1);
	}
	else if (F==F_7812)
	{
		TIMER0_START(TIMER0_CLK_DIV_8);
	}
	else if (F==F_976)
	{
		TIMER0_START(TIMER0_CLK_DIV_64);
	}
	else if (F==F_244)
	{
		TIMER0_START(TIMER0_CLK_DIV_256);
	}
	else if (F==F_61)
	{
		TIMER0_START(TIMER0_CLK_DIV_1024);
	}
}