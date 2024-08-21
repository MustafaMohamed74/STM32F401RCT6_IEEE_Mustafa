/*
 * GPIO_Register.h
 *
 *  Created on: Aug 20, 2024
 *      Author: 20128
 */

#ifndef GPIO_DRIVER_GPIO_REGISTER_H_
#define GPIO_DRIVER_GPIO_REGISTER_H_
/****************************   Includes  ************************/
#include "../LIB/STD_Types.h"
/****************************   Defines   ************************/
#define GPIO_Base_Address  	(0x40020000)
#define GPIO_Offset        	(0X400)
#define GPIOA_Base_Address 	(GPIO_Base_Address + (GPIO_Offset*0))
#define GPIOB_Base_Address 	(GPIO_Base_Address + (GPIO_Offset*1))
#define GPIOC_Base_Address 	(GPIO_Base_Address + (GPIO_Offset*2))
#define GPIOD_Base_Address 	(GPIO_Base_Address + (GPIO_Offset*3))
#define GPIOE_Base_Address 	(GPIO_Base_Address + (GPIO_Offset*4))
#define GPIOH_Base_Address 	(GPIO_Base_Address + (GPIO_Offset*5))

#define GPIOA_Registers    	((GPIO_TypeDef *)(GPIOA_Base_Address))
#define GPIOB_Registers 	((GPIO_TypeDef *)(GPIOB_Base_Address))
#define GPIOC_Registers 	((GPIO_TypeDef *)(GPIOC_Base_Address))
#define GPIOD_Registers 	((GPIO_TypeDef *)(GPIOD_Base_Address))
#define GPIOE_Registers 	((GPIO_TypeDef *)(GPIOE_Base_Address))
#define GPIOH_Registers 	((GPIO_TypeDef *)(GPIOH_Base_Address))

#define Pin_Mask_Douple           (0X3)
#define Pin_Mask_Single	          (0X1)

/**************************** TYPE Defines ***********************/
typedef struct {
	volatile uint32 MODER;     // Offset 0x00: GPIOx_MODER (mode register)
	volatile uint32 OTYPER;    // Offset 0x04: GPIOx_OTYPER (output type register)
	volatile uint32 OSPEEDR;   // Offset 0x08: GPIOx_OSPEEDR (output speed register)
	volatile uint32 PUPDR;     // Offset 0x0C: GPIOx_PUPDR (pull-up/pull-down register)
	volatile uint32 IDR;       // Offset 0x10: GPIOx_IDR (input data register)
	volatile uint32 ODR;       // Offset 0x14: GPIOx_ODR (output data register)
	volatile uint32 BSRR;      // Offset 0x18: GPIOx_BSRR (bit set/reset register)
	volatile uint32 LCKR;      // Offset 0x1C: GPIOx_LCKR (configuration lock register)
	volatile uint32 AFRL;      // Offset 0x20: GPIOx_AFRL (alternate function low register)
	volatile uint32 AFRH;      // Offset 0x24: GPIOx_AFRH (alternate function high register)
} GPIO_TypeDef;


#endif /* GPIO_DRIVER_GPIO_REGISTER_H_ */
