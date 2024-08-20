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
/*in case your choose is PLL Make you configurations here*/
#define PLLM 15 //THIS VALUE CAN BE BETWEEN 2 and 63 (2 ≤PLLM ≤63)
#define PLLN 192//THIS VALUE CAN BE BETWEEN 192 AND 432 (192 ≤PLLN ≤432)
#define PLLP 8 //THIS VALUE CAN BE 2,4,6,8
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
/************************************************************/
#define PLLM_VALUE PLLM
#define PLLN_VALUE PLLN

#define PLLM_pos 0
#define PLLN_pos 6
#define PLLP_pos 16

#if PLLP == 2
#define PLLP_VALUE 0b00
#elif PLLP == 4
#define PLLP_VALUE 0b01
#elif PLLP == 6
#define PLLP_VALUE 0b10
#elif PLLP == 8
#define PLLP_VALUE 0b11
#endif

#endif /* RCC_DRIVER_RCC_CONFIG_H_ */
