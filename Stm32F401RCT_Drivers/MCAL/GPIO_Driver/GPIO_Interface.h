/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 20, 2024
 *      Author: 20128
 */

#ifndef GPIO_DRIVER_GPIO_INTERFACE_H_
#define GPIO_DRIVER_GPIO_INTERFACE_H_

/************************ Pins modes *****************************/
#define GPIO_PIN_OUTPUT     	(0b01)
#define GPIO_PIN_INPUT 			(0b00)
#define GPIO_PIN_ALTERNATE 		(0b10)
#define GPIO_PIN_ANALOG 		(0b11)
/************************ Push_Pull / Open Drain *****************************/
#define GPIO_OUTPUT_PushPull 	0
#define GPIO_OUTPUT_OpenDrain 	1
/************************ Pins Speeds *****************************/
#define GPIO_Speed_Low   		(0b00)
#define GPIO_Speed_Medium     	(0b01)
#define GPIO_Speed_High     	(0b10)
#define GPIO_Speed_VeryHigh    (ob11)
/************************ Pins PullUP \ Down   *****************************/
#define GPIO_NoPull   	(0b00)
#define GPIO_PULLUP 	(0b01)
#define GPIO_PULLDOWN 	(0b10)
/************************* Pins values *************************************/
#define GPIO_Pin_High  (0b1)
#define GPIO_Pin_LOW   (0b0)
/****************************   Ports   ************************/
typedef enum{
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C,
}GPIO_Ports;
/***************************** Pins ****************************************/
typedef enum {
    GPIO_PIN_0 = 0,
    GPIO_PIN_1 = 1,
    GPIO_PIN_2 = 2,
    GPIO_PIN_3 = 3,
    GPIO_PIN_4 = 4,
    GPIO_PIN_5 = 5,
    GPIO_PIN_6 = 6,
    GPIO_PIN_7 = 7,
    GPIO_PIN_8 = 8,
    GPIO_PIN_9 = 9,
    GPIO_PIN_10 = 10,
    GPIO_PIN_11 = 11,
    GPIO_PIN_12 = 12,
    GPIO_PIN_13 = 13,
    GPIO_PIN_14 = 14,
    GPIO_PIN_15 = 15
} GPIO_Pins;
/*************************** Pin config ***************************************/
typedef struct {
GPIO_Ports port;
GPIO_Pins pin;
uint8 Speed ;
uint8 Direction ;
uint8 mode ;
}GPIO_Pin_Cofig;
/*********************** Interface functions declaration **********************/

void GPIO_PinConfig(GPIO_Pin_Cofig * config);

void GPIO_SetPinValue(uint8 PortNo, uint8 PinNo ,uint8 Value);

uint8 GPIO_GetPinValue(uint8 PortNo, uint8 PinNo);

void GPIO_TogglePinValue(uint8 PortNo, uint8 PinNo);


#endif /* GPIO_DRIVER_GPIO_INTERFACE_H_ */
