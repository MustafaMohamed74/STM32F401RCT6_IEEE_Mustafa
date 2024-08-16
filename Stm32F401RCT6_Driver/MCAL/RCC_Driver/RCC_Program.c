/*
 * RCC_Program.c
 *
 *  Created on: Aug 14, 2024
 *      Author: 20128
 */


#include "RCC_Interface.h"

/*declare used functions to enhance readability */
void RCC_PLLM_Config();
void RCC_PLLN_Config();
void RCC_PLLP_Config();

void RCC_Init(void){
#if RCC_Clock == RCC_HSE
	/*Enable clock*/
	Set_Bit(RCC_Registers->CR,HSEON);
	/*wait until it stable*/
	while(!Get_Bit(RCC_Registers->CR,HSERDY));
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
	/*Close the PLL to do some configurations*/
	Clr_Bit(RCC_Registers->CR,PLLON);
	Clr_Bit(RCC_Registers->CR,PLLI2SON);
	Set_Bit(RCC_Registers->CR,HSION);
	/*Config Our PLL */
	RCC_PLLM_Config();
	RCC_PLLN_Config();
	RCC_PLLP_Config();
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

void RCC_Enable_peripheral(peripherals_t Peripheral){

	switch (Peripheral) {
	// RCC AHB1 Peripheral Clock Enable Register (RCC_AHB1ENR)
	case RCC_AHB1ENR_GPIOA_EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOA_EN % 32);
		break;
	case RCC_AHB1ENR_GPIOB_EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOB_EN % 32);
		break;
	case RCC_AHB1ENR_GPIOC_EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOC_EN % 32);
		break;
	case RCC_AHB1ENR_GPIOD_EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOD_EN % 32);
		break;
	case RCC_AHB1ENR_GPIOE_EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOE_EN % 32);
		break;
	case RCC_AHB1ENR_GPIOH_EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOH_EN % 32);
		break;
	case RCC_AHB1ENR_CRCEN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_CRCEN % 32);
		break;
	case RCC_AHB1ENR_DMA1EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_DMA1EN % 32);
		break;
	case RCC_AHB1ENR_DMA2EN:
		Set_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_DMA2EN % 32);
		break;

		// RCC APB1 Peripheral Clock Enable Register (RCC_APB1ENR)
	case RCC_APB1ENR_TIM2EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM2EN % 32);
		break;
	case RCC_APB1ENR_TIM3EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM3EN % 32);
		break;
	case RCC_APB1ENR_TIM4EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM4EN % 32);
		break;
	case RCC_APB1ENR_TIM5EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM5EN % 32);
		break;
	case RCC_APB1ENR_WWDGEN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_WWDGEN % 32);
		break;
	case RCC_APB1ENR_SPI2EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_SPI2EN % 32);
		break;
	case RCC_APB1ENR_SPI3EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_SPI3EN % 32);
		break;
	case RCC_APB1ENR_USART2EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_USART2EN % 32);
		break;
	case RCC_APB1ENR_I2C1EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_I2C1EN % 32);
		break;
	case RCC_APB1ENR_I2C2EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_I2C2EN % 32);
		break;
	case RCC_APB1ENR_I2C3EN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_I2C3EN % 32);
		break;
	case RCC_APB1ENR_PWREN:
		Set_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_PWREN % 32);
		break;

		// RCC APB2 Peripheral Clock Enable Register (RCC_APB2ENR)
	case RCC_APB2ENR_TIM1EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM1EN % 32);
		break;
	case RCC_APB2ENR_USART1EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_USART1EN % 32);
		break;
	case RCC_APB2ENR_USART6EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_USART6EN % 32);
		break;
	case RCC_APB2ENR_ADC1EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_ADC1EN % 32);
		break;
	case RCC_APB2ENR_SDIOEN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SDIOEN % 32);
		break;
	case RCC_APB2ENR_SPI1EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SPI1EN % 32);
		break;
	case RCC_APB2ENR_SPI4EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SPI4EN % 32);
		break;
	case RCC_APB2ENR_SYSCFGEN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SYSCFGEN % 32);
		break;
	case RCC_APB2ENR_TIM9EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM9EN % 32);
		break;
	case RCC_APB2ENR_TIM10EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM10EN % 32);
		break;
	case RCC_APB2ENR_TIM11EN:
		Set_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM11EN % 32);
		break;

	default:
		// Handle unknown cases if necessary
		break;
	}
}


void RCC_Disable_peripheral(peripherals_t Peripheral){

switch (Peripheral) {
	// RCC AHB1 Peripheral Clock Enable Register (RCC_AHB1ENR % 32 )
	case RCC_AHB1ENR_GPIOA_EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOA_EN % 32 );
		break;
	case RCC_AHB1ENR_GPIOB_EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOB_EN % 32 );
		break;
	case RCC_AHB1ENR_GPIOC_EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOC_EN % 32 );
		break;
	case RCC_AHB1ENR_GPIOD_EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOD_EN % 32 );
		break;
	case RCC_AHB1ENR_GPIOE_EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOE_EN % 32 );
		break;
	case RCC_AHB1ENR_GPIOH_EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_GPIOH_EN % 32 );
		break;
	case RCC_AHB1ENR_CRCEN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_CRCEN % 32 );
		break;
	case RCC_AHB1ENR_DMA1EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_DMA1EN % 32 );
		break;
	case RCC_AHB1ENR_DMA2EN:
		Clr_Bit(RCC_Registers->AHB1ENR, RCC_AHB1ENR_DMA2EN % 32 );
		break;

		// RCC APB1 Peripheral Clock Enable Register (RCC_APB1ENR % 32 )
	case RCC_APB1ENR_TIM2EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM2EN % 32 );
		break;
	case RCC_APB1ENR_TIM3EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM3EN % 32 );
		break;
	case RCC_APB1ENR_TIM4EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM4EN % 32 );
		break;
	case RCC_APB1ENR_TIM5EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_TIM5EN % 32 );
		break;
	case RCC_APB1ENR_WWDGEN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_WWDGEN % 32 );
		break;
	case RCC_APB1ENR_SPI2EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_SPI2EN % 32 );
		break;
	case RCC_APB1ENR_SPI3EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_SPI3EN % 32 );
		break;
	case RCC_APB1ENR_USART2EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_USART2EN % 32 );
		break;
	case RCC_APB1ENR_I2C1EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_I2C1EN % 32 );
		break;
	case RCC_APB1ENR_I2C2EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_I2C2EN % 32 );
		break;
	case RCC_APB1ENR_I2C3EN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_I2C3EN % 32 );
		break;
	case RCC_APB1ENR_PWREN:
		Clr_Bit(RCC_Registers->APB1ENR, RCC_APB1ENR_PWREN % 32 );
		break;

		// RCC APB2 Peripheral Clock Enable Register (RCC_APB2ENR % 32 )
	case RCC_APB2ENR_TIM1EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM1EN % 32 );
		break;
	case RCC_APB2ENR_USART1EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_USART1EN % 32 );
		break;
	case RCC_APB2ENR_USART6EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_USART6EN % 32 );
		break;
	case RCC_APB2ENR_ADC1EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_ADC1EN % 32 );
		break;
	case RCC_APB2ENR_SDIOEN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SDIOEN % 32 );
		break;
	case RCC_APB2ENR_SPI1EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SPI1EN % 32 );
		break;
	case RCC_APB2ENR_SPI4EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SPI4EN % 32 );
		break;
	case RCC_APB2ENR_SYSCFGEN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_SYSCFGEN % 32 );
		break;
	case RCC_APB2ENR_TIM9EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM9EN % 32 );
		break;
	case RCC_APB2ENR_TIM10EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM10EN % 32 );
		break;
	case RCC_APB2ENR_TIM11EN:
		Clr_Bit(RCC_Registers->APB2ENR, RCC_APB2ENR_TIM11EN % 32 );
		break;

	default:
		// Handle unknown cases if necessary
		break;
	}
}

void RCC_PLLM_Config(){
	uint32 temp_PLLCFGR = RCC_Registers->PLLCFGR;
	temp_PLLCFGR &=(~((uint32)PLLM_MASK));
	temp_PLLCFGR|= (uint32)(PLLM_VALUE << PLLM_pos );
		RCC_Registers->PLLCFGR = temp_PLLCFGR;
}
void RCC_PLLN_Config(){
	uint32 temp_PLLCFGR = RCC_Registers->PLLCFGR;
	temp_PLLCFGR &=(~((uint32)PLLN_MASK));
	temp_PLLCFGR|= (uint32)(PLLN_VALUE << PLLN_pos) ;
		RCC_Registers->PLLCFGR = temp_PLLCFGR;
}
void RCC_PLLP_Config(){
	uint32 temp_PLLCFGR = RCC_Registers->PLLCFGR;
	temp_PLLCFGR &=(~((uint32)PLLP_MASK));
	temp_PLLCFGR|= (uint32)(PLLP_VALUE << PLLP_pos) ;
		RCC_Registers->PLLCFGR = temp_PLLCFGR;
}



//void RCC_Enable_peripheral(uint8 Desired_Bus ,uint8 peripheral){
//
//switch(Desired_Bus){
//case AHP1 :
//	Set_Bit(RCC_Registers->AHB1ENR , peripheral);
//	break ;
//case AHP2 :
//	Set_Bit(RCC_Registers->AHB2ENR , peripheral);
//	break;
//case APB1 :
//	Set_Bit(RCC_Registers->APB1ENR , peripheral);
//	break;
//case APB2 :
//	Set_Bit(RCC_Registers->APB2ENR , peripheral);
//	break;
//}
//}

//void RCC_Disable_peripheral(uint8 Desired_Bus ,uint8 peripheral){
//	switch(Desired_Bus){
//	case AHP1 :
//		Clr_Bit(RCC_Registers->AHB1ENR , peripheral);
//		break ;
//	case AHP2 :
//		Clr_Bit(RCC_Registers->AHB2ENR , peripheral);
//		break;
//	case APB1 :
//		Clr_Bit(RCC_Registers->APB1ENR , peripheral);
//		break;
//	case APB2 :
//		Clr_Bit(RCC_Registers->APB2ENR , peripheral);
//		break;
//	}
//}
