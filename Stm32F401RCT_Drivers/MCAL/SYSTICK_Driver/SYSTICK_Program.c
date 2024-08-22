/*
 * SYSTICK_Program.c
 *
 *  Created on: Aug 22, 2024
 *      Author: 20128
 *
 *  Description:
 *      This file contains the implementation of the SysTick timer functionalities for the STM32F401RCT6 microcontroller.
 *      It includes initialization, delay functions, and interrupt handling using the SysTick timer.
 *
 *  Overview:
 *      - Initialization of SysTick timer with a specific clock source.
 *      - Functions to create delays in milliseconds and microseconds.
 *      - Functions to start SysTick with interrupts for both milliseconds and microseconds.
 *      - Functions to get remaining and elapsed time from SysTick.
 *      - SysTick interrupt handler function.
 */

#include "../LIB/STD_Types.h"
#include "../LIB/Bit_Math.h"
#include "SYSTICK_Register.h"
#include "SYSTICK_Interface.h"
#include "SYSTICK_Config.h"

/**
 * @brief Initializes the SysTick timer with the configured clock source.
 *
 * This function sets the SysTick clock source based on the predefined configuration.
 * It selects either the AHB clock divided by 1 or by 8.
 */
void SYSTICK_init(void) {
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1
    Set_Bit(SYSTICK_Registers->CTRL, CLKSOURCE);
#elif  SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8
    Clr_Bit(SYSTICK_Registers->CTRL, CLKSOURCE);
#endif
}

/**
 * @brief Creates a delay of specified milliseconds using SysTick timer.
 *
 * @param ms The delay duration in milliseconds.
 */
void SYSTICK_delayMilliSeconds(uint32 ms) {
//	Can be like
	 /* for(uint16 i =0 ; i<=1000 ; i++){
	  SYSTICK_delayMicroSeconds(ms);
	  }*/

#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1
    SYSTICK_Registers->LOAD = ((SYSTICK_CLOCK_SPEED * 1000) * ms) - 1;
#elif  SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8
    SYSTICK_Registers->LOAD = (((SYSTICK_CLOCK_SPEED * 1000) / 8) * ms) - 1;
#endif
    Set_Bit(SYSTICK_Registers->CTRL, ENABLE);

    while (!Get_Bit(SYSTICK_Registers->CTRL, COUNTFLAG));

    Clr_Bit(SYSTICK_Registers->CTRL, ENABLE);
}

/**
 * @brief Creates a delay of specified microseconds using SysTick timer.
 *
 * @param us The delay duration in microseconds.
 */
void SYSTICK_delayMicroSeconds(uint32 us) {
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1
    SYSTICK_Registers->LOAD = (SYSTICK_CLOCK_SPEED * us) - 1;
#elif  SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8
    SYSTICK_Registers->LOAD = ((SYSTICK_CLOCK_SPEED / 8) * us) - 1;
#endif
    Set_Bit(SYSTICK_Registers->CTRL, ENABLE);

    while (!Get_Bit(SYSTICK_Registers->CTRL, COUNTFLAG));

    Clr_Bit(SYSTICK_Registers->CTRL, ENABLE);
}

/**
 * @brief Returns the remaining time in the SysTick timer.
 *
 * @return The remaining time value in SysTick timer.
 */
uint32 SYSTICK_getRemaningTime(void) {
    return SYSTICK_Registers->VAL;
}

/**
 * @brief Returns the elapsed time since the last SysTick timer reload.
 *
 * @return The elapsed time value in SysTick timer.
 */
uint32 SYSTICK_getElapsedTime(void) {
    return (uint32)(0x00FFFFFF) - (uint32)SYSTICK_Registers->VAL;
}

/**
 * @brief Enables the SysTick timer interrupt.
 */
void SYSTICK_enableInterupt(void) {
    Set_Bit(SYSTICK_Registers->CTRL, TICKINT);
}

/**
 * @brief Starts SysTick timer with an interrupt after a specified milliseconds delay.
 *
 * @param ms The delay duration in milliseconds.
 * @param ptr Pointer to the callback function to be executed on SysTick interrupt.
 */
void (*SYSTICK_CALLBACK)(void);
void SYSTICK_startCountMillisecondsIT(uint32 ms, void (*ptr)(void)) {
    SYSTICK_CALLBACK = ptr;
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1
    SYSTICK_Registers->LOAD = (SYSTICK_CLOCK_SPEED *1000 * ms);
#elif  SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8
    SYSTICK_Registers->LOAD = ((SYSTICK_CLOCK_SPEED / 8) * ms);
#endif

    Set_Bit(SYSTICK_Registers->CTRL, ENABLE);
    SYSTICK_enableInterupt();
}

/**
 * @brief Starts SysTick timer with an interrupt after a specified microseconds delay.
 *
 * @param us The delay duration in microseconds.
 * @param ptr Pointer to the callback function to be executed on SysTick interrupt.
 */
void SYSTICK_startCountMicrosecondsIT(uint32 us, void (*ptr)(void)) {
    SYSTICK_CALLBACK = ptr;
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1
    SYSTICK_Registers->LOAD = (SYSTICK_CLOCK_SPEED  * us);
#elif  SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV8
    SYSTICK_Registers->LOAD = ((SYSTICK_CLOCK_SPEED / 8) * us);
#endif

    Set_Bit(SYSTICK_Registers->CTRL, ENABLE);
    SYSTICK_enableInterupt();
}

/**
 * @brief SysTick interrupt handler function.
 *
 * This function is called when the SysTick timer interrupt occurs.
 * It executes the user-defined callback function and disables the timer if configured for non-periodic interrupts.
 */
void SysTick_Handler(void) {
    SYSTICK_CALLBACK();
#if SYSTICK_Interrupt == SYSTICK_Interrupt_NON_PERIODIC
    Clr_Bit(SYSTICK_Registers->CTRL, ENABLE);
    Clr_Bit(SYSTICK_Registers->CTRL, TICKINT);
#endif
}
