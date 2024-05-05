/*
 * TIMER2_FUNCTION.h
 *
 * Created: 3/13/2024 9:58:07 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER2_FUNCTION_H_
#define TIMER2_FUNCTION_H_
/************************************************************************/
/*                          //TCCR2                                     */
/************************************************************************/
#define FOC2		7   //force 
#define WGM20		6   //timer2 mode selection 
#define COM21		5   //OUTPUT TYPE OC2
#define COM20		4   //OUTPUT TYPE OC2
#define WGM21		3  //timer2 mode selection
#define CS22		2  //PRESCALER
#define CS21		1  //PRESCALER
#define CS20		0  //PRESCALER
/************************************************************************/
/*                         TIMSK                                        */
/************************************************************************/
#define TOIE2  6
#define OCIE22 7
/************************************************************************/
/*                        FUNCTION                                      */
/************************************************************************/
void TIMER2_INIT(u8,u8);
//TO SLECT THE TIMER MOOD
#define TIMER2_NORMAL            0
#define TIMER2_PHASE_CORRECT_PWM 1
#define TIMER2_CTC               2
#define TIMER2_FAST_PWM          3
//***********************************************************************
//OUTPUT TYPES
#define  OC2_DISCONNECTED 0
#define  TOGGEL_OC2       1
#define  CLEAN_OC2        2
#define  SET_OC2          3
//**********************************************************************
//PRESCALER
void TIMER2_START(u8);
#define TIMER2_CLK_DIV_1			0
#define TIMER2_CLK_DIV_8			1
#define TIMER2_CLK_DIV_32			2
#define TIMER2_CLK_DIV_64			3
#define TIMER2_CLK_DIV_128			4
#define TIMER2_CLK_DIV_256	        5
#define TIMER2_CLK_DIV_1024     	6
//*********************************************************************
void TIMER2_STOP(void);
//*********************************************************************
//TIMER FREQUANCE
void TIMER2_FREQUANCE(u8);
#define F_TIMER2_62500 0
#define F_TIMER2_7812  1
#define F_TIMER2_1953  2
#define F_TIMER2_976   3
#define F_TIMER2_288   4
#define F_TIMER2_244   5
#define F_TIMER2_61    6
//*******************************************************************
//TO WRITE IN TCNT 
void TIMER2_setPreload(u8 ticks);
//*******************************************************************
//TO READ FROM TCNT
u8 TIMER2_READ_TIMER(void);
//*******************************************************************
//CTC WRITE
void TIMER_CTC2_WRITE(u8);
//*******************************************************************
//PWM
void TIMER_CTC2_WRITE(u8 NUMBER);
//PWM PRESINTAGE
void TIMER2_PHASE_CORRECT_PWM_PRISNTAGE(u8,u8);
#define TOP2 255
#endif /* TIMER2_FUNCTION_H_ */