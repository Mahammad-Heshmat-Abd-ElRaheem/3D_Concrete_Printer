/****************************************************************************
 * Author:				MAHAMMAD HESHMAT									*
 * Creation Data:		24 April, 2024										*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define		GPIOA_BASE_ADDRESS		0x40020000
#define		GPIOB_BASE_ADDRESS		0x40020400
#define		GPIOC_BASE_ADDRESS		0x40020800 
#define		GPIOD_BASE_ADDRESS		0x40020C00
#define		GPIOE_BASE_ADDRESS		0x40021000
#define		GPIOH_BASE_ADDRESS		0x40021C00 

/************************* GPIOA Registers **********************************/
#define		GPIOA_MODER			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define		GPIOA_OTYPER		*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define		GPIOA_OSPEEDR		*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define		GPIOA_PUPDR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define		GPIOA_IDR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define		GPIOA_ODR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define		GPIOA_BSRR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))
#define		GPIOA_LCKR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x1C))

/************************* GPIOB Registers **********************************/
#define		GPIOB_MODER			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define		GPIOB_OTYPER		*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define		GPIOB_OSPEEDR		*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define		GPIOB_PUPDR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define		GPIOB_IDR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define		GPIOB_ODR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define		GPIOB_BSRR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))
#define		GPIOB_LCKR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x1C))

/************************* GPIOC Registers **********************************/
#define		GPIOC_MODER			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define		GPIOC_OTYPER		*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define		GPIOC_OSPEEDR		*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define		GPIOC_PUPDR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define		GPIOC_IDR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define		GPIOC_ODR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define		GPIOC_BSRR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))
#define		GPIOC_LCKR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x1C))

/************************* GPIOD Registers **********************************/
#define		GPIOD_MODER			*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x00))
#define		GPIOD_OTYPER		*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x04))
#define		GPIOD_OSPEEDR		*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x08))
#define		GPIOD_PUPDR			*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x0C))
#define		GPIOD_IDR			*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x10))
#define		GPIOD_ODR			*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x14))
#define		GPIOD_BSRR			*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x18))
#define		GPIOD_LCKR			*((volatile u32*)(GPIOD_BASE_ADDRESS + 0x1C))

/************************* GPIOE Registers **********************************/
#define		GPIOE_MODER			*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x00))
#define		GPIOE_OTYPER		*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x04))
#define		GPIOE_OSPEEDR		*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x08))
#define		GPIOE_PUPDR			*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x0C))
#define		GPIOE_IDR			*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x10))
#define		GPIOE_ODR			*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x14))
#define		GPIOE_BSRR			*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x18))
#define		GPIOE_LCKR			*((volatile u32*)(GPIOE_BASE_ADDRESS + 0x1C))

/************************* GPIOH Registers **********************************/
#define		GPIOH_MODER			*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x00))
#define		GPIOH_OTYPER		*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x04))
#define		GPIOH_OSPEEDR		*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x08))
#define		GPIOH_PUPDR			*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x0C))
#define		GPIOH_IDR			*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x10))
#define		GPIOH_ODR			*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x14))
#define		GPIOH_BSRR			*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x18))
#define		GPIOH_LCKR			*((volatile u32*)(GPIOH_BASE_ADDRESS + 0x1C))
/****************************************************************************/

#define		PORTA		16
#define		PORTB		17
#define		PORTC		18
#define		PORTD		19
#define		PORTE		20
#define		PORTH		21

#define		MODER_MASK		0b11
#define		PUPDR_MASK		0b11
#define		OSPEEDR_MASK	0b11
#define		OTYPER_MASK		0b1
#define		ODR_MASK		0b1
#define		PIN_OFFSET		2




#endif