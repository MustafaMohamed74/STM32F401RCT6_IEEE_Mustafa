/*
 * GPIO_Program.c
 *
 *  Created on: Aug 20, 2024
 *      Author: 20128
 */

/****************************   Includes  ************************/
#include "../LIB/STD_Types.h"
#include "../LIB/Bit_Math.h"
#include "GPIO_Register.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"

/********************  Functions definition **********************/
void GPIO_SetPinDirection(uint8 PortNo, uint8 PinNo ,uint8 Direction , uint8 pull ){
	if(PortNo >= 0 && PortNo <= 5){
		switch (PortNo){
		case GPIO_PORT_A :
			if(PinNo<13 ){
				/*Set Direction*/
				uint32 temp_MODER_A = GPIOA_Registers->MODER ;
				temp_MODER_A &=(~((((uint32)Pin_Mask_Douple))<<(PinNo*2)));
				temp_MODER_A |= (((uint32)Direction)<<(PinNo*2));
				GPIOA_Registers->MODER = temp_MODER_A;
				/*Set pullUp / pullDown */
				uint32 temp_PUPDR_A = GPIOA_Registers->PUPDR ;
				temp_PUPDR_A &=(~((((uint32)Pin_Mask_Douple))<<(PinNo*2)));
				temp_PUPDR_A |= (((uint32)pull)<<PinNo*2);
				GPIOA_Registers->PUPDR = temp_PUPDR_A;
			}
			break ;

		case GPIO_PORT_B :
			/*Set Direction*/
			uint32 temp_MODER_B = GPIOB_Registers->MODER ;
			temp_MODER_B &=(~((((uint32)Pin_Mask_Douple))<<(PinNo*2)));
			temp_MODER_B |= (((uint32)Direction)<<PinNo*2);
			GPIOB_Registers->MODER = temp_MODER_B;
			/*Set pullUp / pullDown */
			uint32 temp_PUPDR_B = GPIOB_Registers->PUPDR ;
			temp_PUPDR_B &=(~((((uint32)Pin_Mask_Douple))<<(PinNo*2)));
			temp_PUPDR_B |= (((uint32)pull)<<PinNo*2);
			GPIOB_Registers->PUPDR = temp_PUPDR_B;
			break ;

		case GPIO_PORT_C :
			/*Set Direction*/
			uint32 temp_MODER_C = GPIOC_Registers->MODER ;
			temp_MODER_C &=(~((((uint32)Pin_Mask_Douple))<<(PinNo*2)));
			temp_MODER_C |= (((uint32)Direction)<<PinNo*2);
			GPIOC_Registers->MODER = temp_MODER_C;
			/*Set pullUp / pullDown */
			uint32 temp_PUPDR_C = GPIOC_Registers->PUPDR ;
			temp_PUPDR_C &=(~((((uint32)Pin_Mask_Douple))<<(PinNo*2)));
			temp_PUPDR_C |= (((uint32)pull)<<PinNo*2);
			GPIOC_Registers->PUPDR = temp_PUPDR_C;
			break ;
		default :
			/*Nothing*/
		}
	}
}

void GPIO_SetPinValue(uint8 PortNo, uint8 PinNo ,uint8 Value){
	if(PortNo >= 0 && PortNo <= 5){
		switch (PortNo){
		case GPIO_PORT_A :
			if(PinNo<13 ){
				uint32 temp_ODR_A = GPIOA_Registers->ODR ;
				temp_ODR_A &=(~((((uint32)Pin_Mask_Single))<<PinNo));
				temp_ODR_A |= (((uint32)Value)<<PinNo);
				GPIOA_Registers->ODR = temp_ODR_A;
			}
			break ;

		case GPIO_PORT_B :
			uint32 temp_ODR_B = GPIOB_Registers->ODR ;
			temp_ODR_B &=(~((((uint32)Pin_Mask_Single))<<PinNo));
			temp_ODR_B |= (((uint32)Value)<<PinNo);
			GPIOB_Registers->ODR = temp_ODR_B;
			break ;

		case GPIO_PORT_C :
			uint32 temp_ODR_C = GPIOC_Registers->ODR ;
			temp_ODR_C &=(~((((uint32)Pin_Mask_Single))<<PinNo));
			temp_ODR_C |= (((uint32)Value)<<PinNo);
			GPIOC_Registers->ODR = temp_ODR_C;
			break ;

		default :
			/*Nothing*/
		}
	}
}

uint8 GPIO_GetPinValue(uint8 PortNo, uint8 PinNo){
	uint8 LocalReturn = 0 ;
	if(PortNo >= 0 && PortNo <= 5){
		switch (PortNo){
		case GPIO_PORT_A :
			if(PinNo<13 ){
				LocalReturn = Get_Bit(GPIOA_Registers->IDR,PinNo);
			}
			break ;

		case GPIO_PORT_B :
			LocalReturn = Get_Bit(GPIOB_Registers->IDR,PinNo);
			break ;

		case GPIO_PORT_C :
			LocalReturn = Get_Bit(GPIOC_Registers->IDR,PinNo);
			break ;

		default :
			/*Nothing*/
		}
	}
	return LocalReturn ;
}

void GPIO_TogglePinValue(uint8 PortNo, uint8 PinNo){
	if(PortNo >= 0 && PortNo <= 5){
		switch (PortNo){
		case GPIO_PORT_A :
			if(PinNo<13 ){
				Tog_Bit(GPIOA_Registers->ODR,PinNo);
			}
			break ;

		case GPIO_PORT_B :
			Tog_Bit(GPIOB_Registers->ODR,PinNo);
			break ;

		case GPIO_PORT_C :
			Tog_Bit(GPIOC_Registers->ODR,PinNo);
			break ;

		default :
			/*Nothing*/
		}
	}
}
