/*
 * RCC_Program.c
 *
 *  Created on: Aug 14, 2024
 *      Author: 20128
 */


#include "RCC_Interface.h"

void RCC_Init(void){
#if RCC_Clock == RCC_HSE
	/*Enable clock*/
	Set_Bit(RCC_Registers->CR,HSEON);
	/*wait until it stable*/
	while(Get_Bit(RCC_Registers->CR,HSERDY));
	/*choose the clock source*/
	uint32 temp_CFGR = RCC_Registers->CFGR ;
	temp_CFGR &=(~((uint32)LS2B_MASK));
	temp_CFGR |= (uint32)CLOCK_Select ;
	RCC_Registers->CFGR = temp_CFGR;
	/*close other sources*/
	Clr_Bit(RCC_Registers->CR,HSION);
	Clr_Bit(RCC_Registers->CR,PLLON);
#elif RCC_Clock == RCC_HSI
	/*Enable clock*/
	Set_Bit(RCC_Registers->CR,HSION);
	/*wait until it stable*/
	while(Get_Bit(RCC_Registers->CR,HSIRDY));
	/*choose the clock source*/
	uint32 temp_CFGR = RCC_Registers->CFGR ;
	temp_CFGR &=(~((uint32)LS2B_MASK));
	temp_CFGR |= (uint32)CLOCK_Select ;
	RCC_Registers->CFGR = temp_CFGR;
	/*close other sources*/
	Clr_Bit(RCC_Registers->CR,PLLON);
	Clr_Bit(RCC_Registers->CR,HSEON);
#elif RCC_Clock == RCC_PLL
	/*Enable clock*/
	Set_Bit(RCC_Registers->CR,PLLON);
	/*wait until it stable*/
	while(Get_Bit(RCC_Registers->CR,PLLRDY));
	/*choose the clock source*/
	uint32 temp_CFGR = RCC_Registers->CFGR ;
	temp_CFGR &=(~((uint32)LS2B_MASK));
	temp_CFGR |= (uint32)CLOCK_Select ;
	RCC_Registers->CFGR = temp_CFGR;
	/*close other sources*/
	Clr_Bit(RCC_Registers->CR,HSEON);
	Clr_Bit(RCC_Registers->CR,HSION);
#endif
}
void RCC_Enable_peripheral(uint8 Desired_Bus ,uint8 peripheral){

switch(Desired_Bus){
case AHP1 :
	Set_Bit(RCC_Registers->AHB1ENR , peripheral);
	break ;
case AHP2 :
	Set_Bit(RCC_Registers->AHB2ENR , peripheral);
	break;
case APB1 :
	Set_Bit(RCC_Registers->APB1ENR , peripheral);
	break;
case APB2 :
	Set_Bit(RCC_Registers->APB2ENR , peripheral);
	break;
}
}

void RCC_Disable_peripheral(uint8 Desired_Bus ,uint8 peripheral){
	switch(Desired_Bus){
	case AHP1 :
		Clr_Bit(RCC_Registers->AHB1ENR , peripheral);
		break ;
	case AHP2 :
		Clr_Bit(RCC_Registers->AHB2ENR , peripheral);
		break;
	case APB1 :
		Clr_Bit(RCC_Registers->APB1ENR , peripheral);
		break;
	case APB2 :
		Clr_Bit(RCC_Registers->APB2ENR , peripheral);
		break;
	}
}
