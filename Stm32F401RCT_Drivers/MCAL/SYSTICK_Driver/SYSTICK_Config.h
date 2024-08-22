/*
 * SYSTICK_Config.h
 *
 *  Created on: Aug 22, 2024
 *      Author: 20128
 */

#ifndef SYSTICK_DRIVER_SYSTICK_CONFIG_H_
#define SYSTICK_DRIVER_SYSTICK_CONFIG_H_

#define SYSTICK_AHB_DIV1 1
#define SYSTICK_AHB_DIV8 0

/*Choose source from here */
#define SYSTICK_CLOCK_SOURCE SYSTICK_AHB_DIV8

/*Write your system clock speed in MHz*/
#define SYSTICK_CLOCK_SPEED 25

/*Interrupt periodic or not  */
#define SYSTICK_Interrupt_PERIODIC 0
#define SYSTICK_Interrupt_NON_PERIODIC 1

#define SYSTICK_Interrupt SYSTICK_Interrupt_PERIODIC

#endif /* SYSTICK_DRIVER_SYSTICK_CONFIG_H_ */
