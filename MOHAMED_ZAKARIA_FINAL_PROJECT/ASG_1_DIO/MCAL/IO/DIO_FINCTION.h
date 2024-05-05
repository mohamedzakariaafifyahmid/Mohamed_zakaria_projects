/*
 * DIO_FINCTION.h
 *
 * Created: 2/3/2024 10:08:38 AM
 *  Author: Mohamed
 */ 


#ifndef DIO_FINCTION_H_
#define DIO_FINCTION_H_
#include "STD_TYPEDEF.h"
#define HIGH 1
#define LOW  0

#define INPUT  0
#define OUTPUT 1

u8 DIO_INPUT(u8);
void DIO_SIT_BYTE_DIRICTION(u8,u8);
void DIO_SIT_BIT_DIRICTION(u8,u8);
void DIO_SIT_BYTE_VALUO(u8,u8);
void DIO_SIT_BIT_VALUO(u8,u8);
void DIO_TOGGEL_BIT(u8);
void DIO_ACTIVE_PULL_UP(u8);

#define DIO_PINA0 0
#define DIO_PINA1 1
#define DIO_PINA2 2
#define DIO_PINA3 3
#define DIO_PINA4 4
#define DIO_PINA5 5
#define DIO_PINA6 6
#define DIO_PINA7 7

#define DIO_PINB0 8
#define DIO_PINB1 9
#define DIO_PINB2 10
#define DIO_PINB3 11
#define DIO_PINB4 12
#define DIO_PINB5 13
#define DIO_PINB6 14
#define DIO_PINB7 15

#define DIO_PINC0 16
#define DIO_PINC1 17
#define DIO_PINC2 18
#define DIO_PINC3 19
#define DIO_PINC4 20
#define DIO_PINC5 21
#define DIO_PINC6 22
#define DIO_PINC7 23

#define DIO_PIND0 24
#define DIO_PIND1 25
#define DIO_PIND2 26
#define DIO_PIND3 27
#define DIO_PIND4 28
#define DIO_PIND5 29
#define DIO_PIND6 30
#define DIO_PIND7 31

#endif /* DIO_FINCTION_H_ */