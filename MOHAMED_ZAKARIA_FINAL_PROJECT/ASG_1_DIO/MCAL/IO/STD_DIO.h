/*
 * STD_DIO.h
 *
 * Created: 2/3/2024 10:01:08 AM
 *  Author: Mohamed
 */ 


#ifndef STD_DIO_H_
#define STD_DIO_H_
#include "BIT_MATH.h"

#define READ_BYTE(X) X=0x00   //TO MAKE PORT INPUT
#define WRITE_BYTE(X) X=0xFF  //TO MAKE PORT OUTPUT
#define READ_BITE(PORT,BIT_NUMBER)    RESET_BIT(PORT,BIT_NUMBER) //TO MAKE PIN READ
#define WRITE_BIT(PORT,BIT_NUMBER)    SET_BIT(PORT,BIT_NUMBER)  //TO MAKE PIN WRITE

#endif /* STD_DIO_H_ */