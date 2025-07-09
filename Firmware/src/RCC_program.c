/****************************************************************************
 * Author:				MAHAMMAD HESHMAT									*
 * Creation Data:		28 April, 2024										*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/

//Liberary Inclusion
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

//Lower Layers Inclusion

//Self Layers Inclusion

//Self Files Inclusion
#include "../include/RCC_interface.h"
#include "../include/RCC_private.h"
#include "../include/RCC_config.h"


/*********** Pre-Build Configuration  ***************/

void RCC_voidInit(void)
{
	#if RCC_CLOCK_SOURCE == RCC_CLK_HSI
		CLR_BIT(RCC_CR,HSEON);
		CLR_BIT(RCC_CR,PLLON);		
		SET_BIT(RCC_CR,HSION);
		
		while (GET_BIT(RCC_CR,HSIRDY) == 0);
	
		CLR_BIT(RCC_CFGR,SW0);
		CLR_BIT(RCC_CFGR,SW1);
		
	#elif RCC_CLOCK_SOURCE == RCC_CLK_HSE
		CLR_BIT(RCC_CR,HSION);
		CLR_BIT(RCC_CR,PLLON);
		SET_BIT(RCC_CR,HSEON);
		
		while (GET_BIT(RCC_CR,HSERDY) == 0);
	
		SET_BIT(RCC_CFGR,SW0);
		CLR_BIT(RCC_CFGR,SW1);
		
	#elif RCC_CLOCK_SOURCE == RCC_CLK_PLL
	
		#if RCC_CLK_PLL_SRC == RCC_CLK_HSI
			CLR_BIT(RCC_PLLCFGR,PLLSRC);
		#elif RCC_CLK_PLL_SRC == RCC_CLK_HSE 
			SET_BIT(RCC_PLLCFGR,PLLSRC);
		#else
			#error "RCC_CLK_PLL_SRC Configuration Error"
		#endif
			CLR_BIT(RCC_CR,PLLON);			//Disable PLL to set M,P and N Factors.
			
			// PLLP Factor Setting
			RCC_PLLCFGR &= (~(RCC_PLLP_FACTOR_MASK << PLLP0 );
			RCC_PLLCFGR |= (RCC_PLLP_DIV << PLLP0 );
			// PLLM Factor Setting
			
			// PLLN Factor Setting
			
			
			CLR_BIT(RCC_CR,HSEON);
			CLR_BIT(RCC_CR,HSION);
			SET_BIT(RCC_CR,PLLON);			//Enable PLL
	#else 
		#error "RCC_CLK_PLL Configuration Error"
	
	#endif

	// AHB Prescaller Setting
	RCC_CFGR &= (~(RCC_AHB_PRESCALLER_MASK << HPRE ));
	RCC_CFGR |= (RCC_AHB_PRESCALLER << HPRE );
	
	// APB1 Prescaller Setting
	RCC_CFGR &= (~(RCC_APB1_PRESCALLER_MASK << PPRE1 ));
	RCC_CFGR |= (RCC_APB1_PRESCALLER << PPRE1 );
	
	// APB2 Prescaller Setting
	RCC_CFGR &= (~(RCC_APB2_PRESCALLER_MASK << PPRE2 ));
	RCC_CFGR |= (RCC_APB2_PRESCALLER << PPRE2 );
	
}


	
/*********** Post-Build Configuration  ***************/

void RCC_voidEnableClockSource (u8 Copy_u8ClockSource)
{
	switch(Copy_u8ClockSource)
	{	
		case RCC_HSI:	SET_BIT(RCC_CR,HSION);
			break;
			
		case RCC_HSE:	SET_BIT(RCC_CR,HSEON);
			break;
			
		case RCC_PLL:	SET_BIT(RCC_CR,PLLON);
			break;
			
		default: 	//error
		break;
	}
}

void RCC_voidDisableClockSource (u8 Copy_u8ClockSource)
{
	switch(Copy_u8ClockSource)
	{
		case RCC_HSI:	CLR_BIT(RCC_CR,HSION);
			break;
			
		case RCC_HSE:	CLR_BIT(RCC_CR,HSEON);
			break;
			
		case RCC_PLL:	CLR_BIT(RCC_CR,PLLON);
			break;
			
		default: 	//error
		break;
	}
}

void RCC_voidEnablePeripheralClock( u8 Copy_u8BusName , u8 Copy_u8PeripheralName )
{
	switch(Copy_u8BusName)
	{
		case AHB1:	SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralName);
		break;
		
		case AHB2:	SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralName);
		break;
		
		case APB1:	SET_BIT(RCC_APB1ENR,Copy_u8PeripheralName);
		break;
		
		case APB2:	SET_BIT(RCC_APB2ENR,Copy_u8PeripheralName);
		break;
		
		default:	//error
		break;
	}
}

void RCC_voidDisablePeripheralClock( u8 Copy_u8BusName , u8 Copy_u8PeripheralName )
{
	switch(Copy_u8BusName)
	{
		case AHB1:	CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralName);
		break;
		
		case AHB2:	CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralName);
		break;
		
		case APB1:	CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralName);
		break;
		
		case APB2:	CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralName);
		break;
		
		default:
		//error
		break;
	}
}
