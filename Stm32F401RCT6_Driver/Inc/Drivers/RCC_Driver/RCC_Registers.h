/**
 * @file RCC_Registers.h
 * @brief This header file provides the register definitions for the RCC (Reset and Clock Control) module.
 *
 * This file contains the structure and macros necessary to access and manipulate the RCC registers
 * in a microcontroller. It allows low-level control over the clock and reset functionalities
 * by directly interfacing with the hardware registers.
 *
 * @details The RCC module is responsible for configuring and controlling the system clock, peripheral clocks,
 * and reset functionality in the microcontroller. This header file provides direct access to the RCC registers
 * via a struct that maps each register to its corresponding address offset.
 *
 * @author Mustafa Mohamed
 * @date August 13, 2024
 */

#ifndef DRIVERS_RCC_DRIVER_RCC_REGISTERS_H_
#define DRIVERS_RCC_DRIVER_RCC_REGISTERS_H_

/***************************Includes_Start**********************/
#include "../Common_Inc/STD_Types.h"

/***************************Includes_End************************/

/************************** Macros_Begining*********************/

/**
 * @brief Base address of the RCC module.
 *
 * This macro defines the base memory address where the RCC module registers
 * are located in the microcontroller's memory map.
 */
#define RCC_Base_Address (0x40023800)

/**
 * @brief Macro for accessing the RCC registers.
 *
 * This macro allows easy access to the RCC registers by treating them as a structure.
 * It dereferences the base address of the RCC module to the defined RCC_typeDef structure.
 */
#define RCC_Registers    (*((RCC_typeDef*)(RCC_Base_Address)))

/************************** Macros_end********************/

/********************TypeDefines_Begining*****************/

/**
 * @brief RCC Register Map Structure
 *
 * This structure represents the register map of the RCC (Reset and Clock Control) module.
 * Each member corresponds to a register at a specific address offset. This structure allows
 * direct manipulation of the RCC registers through a pointer to the base address of the RCC module.
 */
typedef struct {
    volatile uint32 CR;            /**< 0x00 - Clock control register */
    volatile uint32 PLLCFGR;       /**< 0x04 - PLL configuration register */
    volatile uint32 CFGR;          /**< 0x08 - Clock configuration register */
    volatile uint32 CIR;           /**< 0x0C - Clock interrupt register */
    volatile uint32 AHB1RSTR;      /**< 0x10 - AHB1 peripheral reset register */
    volatile uint32 AHB2RSTR;      /**< 0x14 - AHB2 peripheral reset register */
    volatile uint32 RESERVED0[2];  /**< 0x18-0x1C - Reserved */
    volatile uint32 APB1RSTR;      /**< 0x20 - APB1 peripheral reset register */
    volatile uint32 APB2RSTR;      /**< 0x24 - APB2 peripheral reset register */
    volatile uint32 RESERVED1[2];  /**< 0x28-0x2C - Reserved */
    volatile uint32 AHB1ENR;       /**< 0x30 - AHB1 peripheral clock enable register */
    volatile uint32 AHB2ENR;       /**< 0x34 - AHB2 peripheral clock enable register */
    volatile uint32 RESERVED2[2];  /**< 0x38-0x3C - Reserved */
    volatile uint32 APB1ENR;       /**< 0x40 - APB1 peripheral clock enable register */
    volatile uint32 APB2ENR;       /**< 0x44 - APB2 peripheral clock enable register */
    volatile uint32 RESERVED3[2];  /**< 0x48-0x4C - Reserved */
    volatile uint32 AHB1LPENR;     /**< 0x50 - AHB1 peripheral clock enable in low power mode register */
    volatile uint32 AHB2LPENR;     /**< 0x54 - AHB2 peripheral clock enable in low power mode register */
    volatile uint32 RESERVED4[2];  /**< 0x58-0x5C - Reserved */
    volatile uint32 APB1LPENR;     /**< 0x60 - APB1 peripheral clock enable in low power mode register */
    volatile uint32 APB2LPENR;     /**< 0x64 - APB2 peripheral clock enable in low power mode register */
    volatile uint32 RESERVED5[2];  /**< 0x68-0x6C - Reserved */
    volatile uint32 BDCR;          /**< 0x70 - Backup domain control register */
    volatile uint32 CSR;           /**< 0x74 - Clock control & status register */
    volatile uint32 RESERVED6[2];  /**< 0x78-0x7C - Reserved */
    volatile uint32 SSCGR;         /**< 0x80 - Spread spectrum clock generation register */
    volatile uint32 PLLI2SCFGR;    /**< 0x84 - PLLI2S configuration register */
    volatile uint32 DCKCFGR;       /**< 0x8C - Dedicated clocks configuration register */
} RCC_typeDef;

/********************TypeDefines_Begining*****************/
#endif /* DRIVERS_RCC_DRIVER_RCC_REGISTERS_H_ */
