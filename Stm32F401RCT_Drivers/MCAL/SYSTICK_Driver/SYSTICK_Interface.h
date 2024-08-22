/*
 * SYSTICK_Interface.h
 *
 *  Created on: Aug 22, 2024
 *      Author: 20128
 */

#ifndef SYSTICK_DRIVER_SYSTICK_INTERFACE_H_
#define SYSTICK_DRIVER_SYSTICK_INTERFACE_H_

//Initialization
void SYSTICK_init(void);
//Delay functions
void SYSTICK_delayMilliSeconds(uint32 ms);
void SYSTICK_delayMicroSeconds(uint32 us);
//Helper functions
uint32 SYSTICK_getRemaningTime(void);
uint32 SYSTICK_getElapsedTime(void);
void SYSTICK_enableInterupt(void);
//Interrupt Functions
void SYSTICK_startCountMillisecondsIT(uint32 ms, void (*ptr)(void));
void SYSTICK_startCountMicrosecondsIT(uint32 ms, void (*ptr)(void));

#endif /* SYSTICK_DRIVER_SYSTICK_INTERFACE_H_ */
