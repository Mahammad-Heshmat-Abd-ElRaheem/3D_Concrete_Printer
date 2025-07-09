/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM						*
 * Creation Data:		1 May, 2024		    								*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
// Liberary Inclusion
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
// Self Files Inclusion
#include "../include/STK_interface.h"
#include "../include/STK_private.h"
#include "../include/STK_config.h"

void MSTK_voidInit(void)
{
    // Choose the Clock Source For Systick
    #if STK_CLK_SRC == STK_AHB
        SET_BIT(STK->CTRL, CLKSOURCE);
    #elif STK_CLK_SRC == STK_AHB_DIV_8
        CLR_BIT(STK->CTRL, CLKSOURCE);
    #else
        #error "STK_CLK_SRC Configuration Error"
    #endif

    // Control The Systick Interrupt
    #if STK_INT_CTRL == STK_DISABLE
        CLR_BIT(STK->CTRL, TICKINT);
    #elif STK_INT_CTRL == STK_ENABLE
        SET_BIT(STK->CTRL, TICKINT);
    #else
        #error "STK_INT_CTRL Configuration Error"
    #endif

    // Control The Systick Enable/Disable
    #if STK_CTRL == STK_DISABLE
        CLR_BIT(STK->CTRL, ENABLE);
    #elif STK_CTRL == STK_ENABLE
        SET_BIT(STK->CTRL, ENABLE);
    #else
        #error "STK_CTRL Configuration Error"
    #endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    // Load The Ticks Value into the LOAD Register
    STK -> LOAD = Copy_u32Ticks;
    // Polling (Busy Wait) on the flag
    while( GET_BIT( STK->CTRL , COUNTFLAG ) == 0 );
    // Flag Clearance
    STK -> VAL = 0;
}
