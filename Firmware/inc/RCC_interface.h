/****************************************************************************
 * Author:				MAHAMMAD HESHMAT									*
 * Creation Data:		28 April, 2024										*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/

#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H
/****************************************
for : 	Copy_u8ClockSource   			*/
#define		RCC_HSI 	0
#define		RCC_HSE 	1
#define		RCC_PLL 	2
/*****************************************/
/****************************************
for :	Copy_u8PeripheralName			 */

//FOR AHB1 BUS
#define		RCC_AHB1_GPIOA		0
#define		RCC_AHB1_GPIOB		1
#define		RCC_AHB1_GPIOC		2
#define		RCC_AHB1_GPIOD		3
#define		RCC_AHB1_GPIOE		4
#define		RCC_AHB1_GPIOH		7
#define		RCC_AHB1_CRC		12
#define		RCC_AHB1_DMA1		21
#define		RCC_AHB1_DMA2		22

//FOR AHB2 BUS
#define		RCC_AHB2_OTGFS		7

//FOR APB1 BUS
#define		RCC_APB1_TIM2		0
#define		RCC_APB1_TIM3		1
#define		RCC_APB1_TIM4		2
#define		RCC_APB1_TIM5		3
#define		RCC_APB1_WWDG		11
#define		RCC_APB1_SPI2		14
#define		RCC_APB1_SPI3		15
#define		RCC_APB1_USART2		17
#define		RCC_APB1_I2C1		21
#define		RCC_APB1_I2C2		22
#define		RCC_APB1_I2C3		23
#define		RCC_APB1_PWR		28

//FOR APB2 BUS
#define		RCC_APB2_TIM1		0
#define		RCC_APB2_USART1		4
#define		RCC_APB2_USART6		5
#define		RCC_APB2_ADC1		8
#define		RCC_APB2_SDIO		11
#define		RCC_APB2_SPI1		12
#define		RCC_APB2_SPI4		13
#define		RCC_APB2_SYSCFG		14
#define		RCC_APB2_TIM9		16
#define		RCC_APB2_TIM10		17
#define		RCC_APB2_TIM11		18
/*****************************************/
/****************************************
for : 	Copy_u8BusName					 */
#define		RCC_AHB1		10
#define		RCC_AHB2		11
#define		RCC_APB1		12
#define		RCC_APB2		13
/*****************************************/

void RCC_voidInit(void);
void RCC_voidEnableClockSource (u8 Copy_u8ClockSource);
void RCC_voidDisableClockSource (u8 Copy_u8ClockSource);
void RCC_voidEnablePeripheralClock( u8 Copy_u8BusName , u8 Copy_u8PeripheralName );
void RCC_voidDisablePeripheralClock( u8 Copy_u8BusName , u8 Copy_u8PeripheralName );

#endif