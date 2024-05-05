/*
 * IO_ADDRESSES1.h
 *
 * Created: 2/3/2024 9:54:22 AM
 *  Author: Mohamed
 */ 


#ifndef IO_ADDRESSES1_H_
#define IO_ADDRESSES1_H_
#include "IO_ADDRESSES1.h"
//ADDRESSES OF PORT A
#define DDRA *(volatile u8*)0x3A
#define PORTA *(volatile u8*)0x3B
#define PINA *(volatile u8*)0x39
//ADDRESSES OF PORT B
#define DDRB *(volatile u8*)0x37
#define PORTB *(volatile u8*)0x38
#define PINB *(volatile u8*)0x36
//ADDRESSES OF PORT C
#define DDRC *(volatile u8*)0x34
#define PORTC *(volatile u8*)0x35
#define PINC *(volatile u8*)0x33
//ADDRESSES OF PORT D
#define DDRD *(volatile u8*)0x31
#define PORTD *(volatile u8*)0x32
#define PIND *(volatile u8*)0x30

#endif /* IO_ADDRESSES1_H_ */