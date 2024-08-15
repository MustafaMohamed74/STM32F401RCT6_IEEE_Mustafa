/*
 * RCC_Config.h
 *
 *  Created on: Aug 14, 2024
 *      Author: 20128
 */

#ifndef RCC_DRIVER_RCC_CONFIG_H_
#define RCC_DRIVER_RCC_CONFIG_H_

/* Choose clock from here */
#define RCC_Clock RCC_HSE
/************************************************************/
#define RCC_HSE 0
#define RCC_HSI 1
#define RCC_PLL 2
#define RCC_LSE 3
#define RCC_LSI 4
/************************************************************/
#if RCC_Clock == RCC_HSI
#define CLOCK_Select 0b00
#elif RCC_Clock == RCC_HSE
#define CLOCK_Select 0b01
#elif RCC_Clock == RCC_PLL
#define CLOCK_Select 0b10
#endif

#endif /* RCC_DRIVER_RCC_CONFIG_H_ */
