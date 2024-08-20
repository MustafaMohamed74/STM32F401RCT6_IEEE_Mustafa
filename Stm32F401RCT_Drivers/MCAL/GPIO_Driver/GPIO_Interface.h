/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 20, 2024
 *      Author: 20128
 */

#ifndef GPIO_DRIVER_GPIO_INTERFACE_H_
#define GPIO_DRIVER_GPIO_INTERFACE_H_

/****************************   Defines   ************************/
#define GPIO_PIN_0   			0
#define GPIO_PIN_1   			1
#define GPIO_PIN_2   			2
#define GPIO_PIN_3   			3
#define GPIO_PIN_4   			4
#define GPIO_PIN_5   			5
#define GPIO_PIN_6   			6
#define GPIO_PIN_7   			7
#define GPIO_PIN_8   			8
#define GPIO_PIN_9   			9
#define GPIO_PIN_10  			10
#define GPIO_PIN_11  			11
#define GPIO_PIN_12  			12
#define GPIO_PIN_13  			13
#define GPIO_PIN_14  			14
#define GPIO_PIN_15  			15

#define GPIO_PORT_A 0
#define GPIO_PORT_B 1
#define GPIO_PORT_C 2
#define GPIO_PORT_D 3
#define GPIO_PORT_E 4
#define GPIO_PORT_H 5
/************************ Ports modes *****************************/
#define GPIO_PORT_OUTPUT 		(0b01)
#define GPIO_PORT_INPUT 		(0X00000000)
#define GPIO_PORT_ALTERNATE 	(0XAAAAAAAA)
#define GPIO_PORT_ANALOG 		(0XFFFFFFFF)
/************************ Pins modes *****************************/
#define GPIO_PIN_OUTPUT     	(0b01)
#define GPIO_PIN_INPUT 			(0b00)
#define GPIO_PIN_ALTERNATE 		(0b10)
#define GPIO_PIN_ANALOG 		(0b11)
/************************ Push_Pull / Open Drain *****************************/
#define GPIO_OUTPUT_PushPull 	0
#define GPIO_OUTPUT_OpenDrain 	1
/************************ Pins Speeds *****************************/
#define GPIO_OUTPUT_LowSpeed   		(0b00)
#define GPIO_OUTPUT_MediumSpeed   	(0b01)
#define GPIO_OUTPUT_HighSpeed   	(0b10)
#define GPIO_OUTPUT_VeryHighSpeed   (ob11)
/************************ Pins PullUP \ Down   *****************************/
#define GPIO_NoPull   	(0b00)
#define GPIO_PULLUP 	(0b01)
#define GPIO_PULLDOWN 	(0b10)
/************************ Ports PullUP \ Down   *****************************/
#define GPIO_Port_NoPull   	(0x0000)
#define GPIO_Port_PULLUP 	(0x5555)
#define GPIO_Port_PULLDOWN 	(0xAAAA)
/************************* Ports values *************************************/
#define GPIO_Port_High (0xFFFF)
#define GPIO_Port_LOW  (0x0000)
/************************* Pins values *************************************/
#define GPIO_Pin_High  (0b1)
#define GPIO_Pin_LOW   (0b0)

/*********************** Interface functions declaration **********************/

void GPIO_SetPortDirection(uint8 PortNo, uint32 Direction, uint32 Pull);
void GPIO_SetPinDirection(uint8 PortNo, uint8 PinNo ,uint8 Direction , uint8 pull);

void GPIO_SetPortValue(uint8 PortNo, uint16 Value);
void GPIO_SetPinValue(uint8 PortNo, uint8 PinNo ,uint8 Value);

uint32 GPIO_GetPortValue(uint8 PortNo);
uint8 GPIO_GetPinValue(uint8 PortNo, uint8 PinNo);

void GPIO_TogglePortValue(uint8 PortNo);
void GPIO_TogglePinValue(uint8 PortNo, uint8 PinNo);


#endif /* GPIO_DRIVER_GPIO_INTERFACE_H_ */
