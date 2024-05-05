/*
 * BIT_MATH.h
 *
 * Created: 2/3/2024 9:44:55 AM
 *  Author: Mohamed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,BIT_NUMBER)    x|=(1<<BIT_NUMBER)
#define RESET_BIT(x,BIT_NUMBER)  x&=~(1<<BIT_NUMBER)
#define TOGGEL_BIT(x,BIT_NUMBER) x^=(1<<BIT_NUMBER)
#define GET_BIT(x,BIT_NUMBER)    ((x>>BIT_NUMBER)&1)
#define SIT_BYTE(X)              X=0xFF;
#define RESET_BYTE(X)            X=0x00;

#endif /* BIT_MATH_H_ */