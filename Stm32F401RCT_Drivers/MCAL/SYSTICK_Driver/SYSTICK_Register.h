/*
 * SYSTICK_Register.h
 *
 *  Created on: Aug 22, 2024
 *      Author: 20128
 */

#ifndef SYSTICK_DRIVER_SYSTICK_REGISTER_H_
#define SYSTICK_DRIVER_SYSTICK_REGISTER_H_

#define SYSTICK_Base_Address  	(0xE000E010)

#define SYSTICK_Registers    	((SYSTICK_TypeDef *)(SYSTICK_Base_Address))

typedef struct{
	volatile uint32 CTRL;
	volatile uint32 LOAD;
	volatile uint32 VAL;
	volatile uint32 CALIB;
}SYSTICK_TypeDef;

typedef enum{
	ENABLE = 0 ,
	TICKINT = 1,
	CLKSOURCE = 2,
	COUNTFLAG = 16,
}SYSTICK_CTRL_Register;
#endif /* SYSTICK_DRIVER_SYSTICK_REGISTER_H_ */
