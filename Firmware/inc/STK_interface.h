/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM						*
 * Creation Data:		1 May, 2024		    								*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
//void MSTK_voidSetIntervalSingle();
#endif