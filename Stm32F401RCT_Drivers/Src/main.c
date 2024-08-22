/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "../LIB/STD_Types.h"
#include "../LIB/Bit_Math.h"
#include "../MCAL/RCC_Driver/RCC_Interface.h"
#include "../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "../MCAL/SYSTICK_Driver/SYSTICK_Interface.h"

void SYSTICK_INTRRUPT(void);

int main(void)
{
	GPIO_Pin_Cofig Led ;
	Led.port = GPIO_PORT_A ;
	Led.pin = GPIO_PIN_0 ;
	Led.Direction = GPIO_PIN_OUTPUT ;
	Led.mode = GPIO_OUTPUT_PushPull ;
	Led.Speed = GPIO_Speed_VeryHigh ;

	GPIO_Pin_Cofig Led2 ;
	Led2.port = GPIO_PORT_A ;
	Led2.pin = GPIO_PIN_2 ;
	Led2.Direction = GPIO_PIN_OUTPUT ;
	Led2.mode = GPIO_OUTPUT_PushPull ;
	Led2.Speed = GPIO_Speed_VeryHigh ;

	RCC_Init();
	RCC_Enable_peripheral(RCC_AHB1ENR_GPIOA_EN);
	RCC_Enable_peripheral(RCC_AHB1ENR_GPIOB_EN);
	GPIO_PinConfig(&Led);
	GPIO_PinConfig(&Led2);
//	GPIO_SetPinValue(GPIO_PORT_A, GPIO_PIN_2, GPIO_Pin_LOW);
	GPIO_SetPinValue(GPIO_PORT_A, GPIO_PIN_0, GPIO_Pin_High);
//	SYSTICK_startCountMillisecondsIT(1000,SYSTICK_INTRRUPT);
	//	SYSTICK_startCountMicrosecondsIT(1000000,SYSTICK_INTRRUPT);

	while(1){
		//
		GPIO_SetPinValue(GPIO_PORT_A, GPIO_PIN_0, GPIO_Pin_LOW);
		//		GPIO_SetPinValue(GPIO_PORT_A, GPIO_PIN_2, GPIO_Pin_LOW);
		//
		SYSTICK_delayMilliSeconds(1000);
		GPIO_SetPinValue(GPIO_PORT_A, GPIO_PIN_0, GPIO_Pin_High);
		//		GPIO_SetPinValue(GPIO_PORT_A, GPIO_PIN_2, GPIO_Pin_High);
		//
		SYSTICK_delayMilliSeconds(1000);

	}
}

void SYSTICK_INTRRUPT(void){
	GPIO_TogglePinValue(GPIO_PORT_A, GPIO_PIN_2);
}
