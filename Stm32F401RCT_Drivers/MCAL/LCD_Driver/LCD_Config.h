/*
 * LCD_Config.h
 *
 *  Created on: Aug 23, 2024
 *      Author: 20128
 */

#ifndef LCD_DRIVER_LCD_CONFIG_H_
#define LCD_DRIVER_LCD_CONFIG_H_

#define CONTROL_PORT GPIO_PORT_B

#define RS_PIN GPIO_PIN_2
#define RW_PIN GPIO_PIN_1
#define E_PIN GPIO_PIN_0

#define DATA_PORT GPIO_PORT_A

#define DATA_D4_PIN GPIO_PIN_0
#define DATA_D5_PIN GPIO_PIN_1
#define DATA_D6_PIN GPIO_PIN_2
#define DATA_D7_PIN GPIO_PIN_3

#define LCD_8Bit_Mode 0
#define LCD_4Bit_Mode 1
// for 4-bit mode choose 1
//for 8-bit mode choose 0
#define LCD_Mode LCD_4Bit_Mode


#endif /* LCD_DRIVER_LCD_CONFIG_H_ */
