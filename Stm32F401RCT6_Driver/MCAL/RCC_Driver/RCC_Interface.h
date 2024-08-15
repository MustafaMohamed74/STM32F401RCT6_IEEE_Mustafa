/*
 * RCC_Interface.h
 *
 *  Created on: Aug 14, 2024
 *      Author: 20128
 */

#ifndef RCC_DRIVER_RCC_INTERFACE_H_
#define RCC_DRIVER_RCC_INTERFACE_H_
#include "../LIB/STD_Types.h"
#include "../LIB/Bit_Math.h"
#include "RCC_Registers.h"
#include "RCC_Config.h"

#define AHP1 0
#define AHP2 1
#define APB1 2
#define APB2 3

void RCC_Init(void);
void RCC_Enable_peripheral(uint8 Desired_Bus ,uint8 peripheral);
void RCC_Disable_peripheral(uint8 Desired_Bus ,uint8 peripheral);


#endif /* RCC_DRIVER_RCC_INTERFACE_H_ */
