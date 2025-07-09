/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM						*
 * Creation Data:		1 May, 2024		    								*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define     STK_AHB         0
#define     STK_AHB_DIV_8   1
#define     STK_ENABLE      0
#define     STK_DISABLE     1

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_t;

#define     STK          ((volatile STK_t *)0xE000E010)
#define     ENABLE       0
#define     TICKINT      1
#define     CLKSOURCE    2
#define     COUNTFLAG    16



#endif