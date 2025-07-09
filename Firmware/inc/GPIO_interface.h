/****************************************************************************
 * Author:				MAHAMMAD HESHMAT									*
 * Creation Data:		24 April, 2024										*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
 
#ifndef		GPIO_INTERFACE_H
#define		GPIO_INTERFACE_H

/*********( copy_u8Port )**************/
#define		GPIO_PORTA		16
#define		GPIO_PORTB		17
#define		GPIO_PORTC		18
#define		GPIO_PORTD		19
#define		GPIO_PORTE		20
#define		GPIO_PORTH		21
/**************************************/

/*********( copy_u8Pin )***************/
#define		GPIO_PIN0		0
#define		GPIO_PIN1		1
#define		GPIO_PIN2		2
#define		GPIO_PIN3		3
#define		GPIO_PIN4		4
#define		GPIO_PIN5		5
#define		GPIO_PIN6		6
#define		GPIO_PIN7		7
#define		GPIO_PIN8		8
#define		GPIO_PIN9		9
#define		GPIO_PIN10		10
#define		GPIO_PIN11		11
#define		GPIO_PIN12		12
#define		GPIO_PIN13		13
#define		GPIO_PIN14		14
#define		GPIO_PIN15		15
/**************************************/

/*********( copy_u8Mode )**************/
#define		GPIO_INPUT		0b00
#define		GPIO_OUTPUT		0b01
#define		GPIO_AF			0b10
#define		GPIO_ANALOG		0b11
/**************************************/

/*********( copy_u8OutputMode )*******/
#define		GPIO_OPEN_DRAIN		0b1
#define		GPIO_PUSH_PULL		0b0
/*************************************/

/********( copy_u8Speed )*******************************/
#define		GPIO_LOW_SPEED				0b00	//1MHZ	
#define		GPIO_MEDIUM_SPEED			0b01	//8MHZ	
#define		GPIO_HIGH_SPEED				0b10	//50MHZ	
#define		GPIO_VERY_HIGH_SPEED		0b11	//AHBBUS
/*******************************************************/

/********( copy_u8Value )*************/
#define		GPIO_HIGH		0b1
#define		GPIO_LOW		0b0
/*************************************/

/*********( copy_u8State )************/
#define		GPIO_FLOAT		0b00
#define		GPIO_PULLUP		0b01
#define		GPIO_PULLDOWN	0b10
/*************************************/

void MGPIO_VoidSetPin_Mode( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode );
void MGPIO_VoidSetPin_OutputMode( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8OutputMode );
void MGPIO_VoidSetPin_OutputSpeed( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Speed );
void MGPIO_VoidSetPin_Value( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value );
void MGPIO_VoidSetPin_PUPD( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8State );
u8 MGPIO_u8GetPinValue( u8 copy_u8Port , u8 copy_u8Pin );


#endif