/****************************************************************************
 * Author:				MAHAMMAD HESHMAT									*
 * Creation Data:		28 April, 2024										*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/


#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

/* options:
			RCC_CLK_HSI
			RCC_CLK_HSE
			RCC_CLK_PLL
*/
#define 	RCC_CLOCK_SOURCE 	RCC_CLK_HSI

/* options:
			RCC_CLK_HSI
			RCC_CLK_HSE
*/
#define 	RCC_CLK_PLL_SRC		RCC_CLK_HSI

/*  Main PLL division factor for main system clock 
	Set and cleared by software to control the frequency of the general PLL output clock
	PLL output clock frequency = VCO frequency / PLLP
	NOTE: 2 is default
	options:
	RCC_PLLP_FACTOR_2
	RCC_PLLP_FACTOR_4
	RCC_PLLP_FACTOR_6
	RCC_PLLP_FACTOR_8
*/
#define		RCC_PLLP_DIV	RCC_PLLP_FACTOR_2

/*  PLLM: Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock Set and cleared by software to divide the PLL and PLLI2S input clock before the VCO.
	These bits can be written only when the PLL and PLLI2S are disabled.

	Caution: The software has to set these bits correctly to ensure that the VCO input frequency ranges from 1 to 2 MHz. 
	It is recommended to select a frequency of 2 MHz to limit PLL jitter.
	
	VCO input frequency = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63
	000000: PLLM = 0, wrong configuration
	000001: PLLM = 1, wrong configuration
*/
#define		RCC_PLLM_DIV	0b001000	//==> 8

/*	PLLN: Main PLL (PLL) multiplication factor for VCOSet and cleared by software to control the multiplication factor of the VCO.
	These bits canbe written only when PLL is disabled.
	Only half-word and word accesses are allowed towrite these bits.
	
	Caution: The software has to set these bits correctly to ensure that the VCO output frequency is between 192 and 432 MHz.
	VCO output frequency = VCO input frequency × PLLN with 192 ≤ PLLN ≤ 432
	000000000: PLLN = 0, wrong configuration
	000000001: PLLN = 1, wrong configuration
	110110001: PLLN = 433, wrong configuration
	...
	111111111: PLLN = 511, wrong configuration
*/
#define		RCC_PLLN_MUL	0b001010011	//==> 83

/* options:
			RCC_AHB_DIV_1	
			RCC_AHB_DIV_2	
			RCC_AHB_DIV_4	
			RCC_AHB_DIV_8	
			RCC_AHB_DIV_16	
			RCC_AHB_DIV_64	
			RCC_AHB_DIV_128
			RCC_AHB_DIV_256
			RCC_AHB_DIV_512
*/
#define		RCC_AHB_PRESCALLER		RCC_AHB_DIV_2

/* options:
			RCC_APB1_DIV_1	
			RCC_APB1_DIV_2	
			RCC_APB1_DIV_4	
			RCC_APB1_DIV_8	
			RCC_APB1_DIV_16	
*/
#define		RCC_APB1_PRESCALLER		RCC_APB1_DIV_1

/* options:
			RCC_APB2_DIV_1	
			RCC_APB2_DIV_2	
			RCC_APB2_DIV_4	
			RCC_APB2_DIV_8	
			RCC_APB2_DIV_16	
*/
#define		RCC_APB2_PRESCALLER		RCC_APB2_DIV_1












 	
#endif
