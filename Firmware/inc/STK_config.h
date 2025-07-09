/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM						*
 * Creation Data:		1 May, 2024		    								*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/*********( Options for: STK_CLK_SRC )********
STK_AHB
STK_AHB_DIV_8
**********************************************/
#define     STK_CLK_SRC     STK_AHB_DIV_8

/*********( Options for: STK_INT_CTRL )********
STK_ENABLE
STK_DISABLE
**********************************************/
#define     STK_INT_CTRL    STK_DISABLE

/*********( Options for: STK_CTRL )************
STK_ENABLE
STK_DISABLE
**********************************************/
#define     STK_CTRL        STK_ENABLE


#endif