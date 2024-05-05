/*
 * GENERAL_INTERRAPT.h
 *
 * Created: 2/16/2024 9:39:03 PM
 *  Author: Mohamed
 */ 


#ifndef GENERAL_INTERRAPT_H_
#define GENERAL_INTERRAPT_H_
#include "BIT_MATH.h"
#include "INTERRUPT_ADRESSES.h"
//TO ENABLE THE INTERRAPT
#define GENERAL_INTERRAPT_ENABLE SET_BIT(SREG,7)
//TO DESAPLE THE INTERRAPT
#define GENERAL_INTERRAPT_DESABLE RESET_BIT(SREG,7)
#endif /* GENERAL_INTERRAPT_H_ */