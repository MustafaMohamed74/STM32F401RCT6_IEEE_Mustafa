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
#include "../../LIB/STD_Types.h"

/***************************Includes_End************************/

/************************** Macros_Start*********************/

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
#define RCC_Registers  (((RCC_RegDef *)(RCC_Base_Address)))

#define LS2B_MASK      (0X00000003) //mask for the least significant 2 bits
#define PLLM_MASK      (0X0000001F) //mask for the least significant 5 bits
#define PLLN_MASK      (0X00003FE0) //mask for the bits from 6 to 14
#define PLLP_MASK      (0X00030000) //mask for the bits 16 and 17

/************************** Macros_end********************/

/********************TypeDefines_Start*****************/

/**
 * @brief RCC Registers Map Structure
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
} RCC_RegDef;

typedef enum {
    HSION       = 0,  // Bit 0
    HSIRDY      = 1,  // Bit 1
    HSITRIM_0   = 3,  // Bit 3
    HSITRIM_1   = 4,  // Bit 4
    HSITRIM_2   = 5,  // Bit 5
    HSITRIM_3   = 6,  // Bit 6
    HSITRIM_4   = 7,  // Bit 7
    HSICAL_0    = 8,  // Bit 8
    HSICAL_1    = 9,  // Bit 9
    HSICAL_2    = 10, // Bit 10
    HSICAL_3    = 11, // Bit 11
    HSICAL_4    = 12, // Bit 12
    HSICAL_5    = 13, // Bit 13
    HSICAL_6    = 14, // Bit 14
    HSICAL_7    = 15, // Bit 15
    HSEON       = 16, // Bit 16
    HSERDY      = 17, // Bit 17
    HSEBYP      = 18, // Bit 18
    CSSON       = 19, // Bit 19
    PLLON       = 24, // Bit 24
    PLLRDY      = 25, // Bit 25
    PLLI2SON    = 26, // Bit 26
    PLLI2SRDY   = 27  // Bit 27
} CR_Bits;

typedef enum {
    SW0         = 0,  // Bit 0
    SW1         = 1,  // Bit 1
    SWS0        = 2,  // Bit 2
    SWS1        = 3,  // Bit 3
    HPRE0       = 4,  // Bit 4
    HPRE1       = 5,  // Bit 5
    HPRE2       = 6,  // Bit 6
    HPRE3       = 7,  // Bit 7
    PPRE1_0     = 10, // Bit 10
    PPRE1_1     = 11, // Bit 11
    PPRE1_2     = 12, // Bit 12
    PPRE2_0     = 13, // Bit 13
    PPRE2_1     = 14, // Bit 14
    PPRE2_2     = 15, // Bit 15
    RTCPRE_0    = 16, // Bit 16
    RTCPRE_1    = 17, // Bit 17
    RTCPRE_2    = 18, // Bit 18
    RTCPRE_3    = 19, // Bit 19
    RTCPRE_4    = 20, // Bit 20
    MCO1        = 21, // Bit 21
    I2SSRC      = 23, // Bit 23
    MCO1PRE_0   = 24, // Bit 24
    MCO1PRE_1   = 25, // Bit 25
    MCO1PRE_2   = 26, // Bit 26
    MCO2        = 27, // Bit 27
    MCO2PRE_0   = 28, // Bit 28
    MCO2PRE_1   = 29, // Bit 29
    MCO2PRE_2   = 30  // Bit 30
} RCC_CFGR_Bits;

typedef enum {
    PLLM0       = 0,  // Bit 0
    PLLM1       = 1,  // Bit 1
    PLLM2       = 2,  // Bit 2
    PLLM3       = 3,  // Bit 3
    PLLM4       = 4,  // Bit 4
    PLLM5       = 5,  // Bit 5
    PLLN0       = 6,  // Bit 6
    PLLN1       = 7,  // Bit 7
    PLLN2       = 8,  // Bit 8
    PLLN3       = 9,  // Bit 9
    PLLN4       = 10, // Bit 10
    PLLN5       = 11, // Bit 11
    PLLN6       = 12, // Bit 12
    PLLN7       = 13, // Bit 13
    PLLN8       = 14, // Bit 14
    PLLP0       = 16, // Bit 16
    PLLP1       = 17, // Bit 17
    PLLSRC      = 22, // Bit 22
    PLLQ0       = 24, // Bit 24
    PLLQ1       = 25, // Bit 25
    PLLQ2       = 26, // Bit 26
    PLLQ3       = 27  // Bit 27
} RCC_PLLCFGR_Bits;

typedef enum {
    // RCC AHB1 Peripheral Clock Enable Register (RCC_AHB1ENR)
    RCC_AHB1ENR_GPIOA_EN = 0,
    RCC_AHB1ENR_GPIOB_EN = 1,
    RCC_AHB1ENR_GPIOC_EN = 2,
    RCC_AHB1ENR_GPIOD_EN = 3,
    RCC_AHB1ENR_GPIOE_EN = 4,
    RCC_AHB1ENR_GPIOH_EN = 7,
    RCC_AHB1ENR_CRCEN = 12,
    RCC_AHB1ENR_DMA1EN = 21,
    RCC_AHB1ENR_DMA2EN = 22,

    // RCC APB1 Peripheral Clock Enable Register (RCC_APB1ENR)
    RCC_APB1ENR_TIM2EN = 0 + 32 ,
    RCC_APB1ENR_TIM3EN = 1 + 32,
    RCC_APB1ENR_TIM4EN = 2 +32 ,
    RCC_APB1ENR_TIM5EN = 3 +32 ,
    RCC_APB1ENR_WWDGEN = 11 + 32 ,
    RCC_APB1ENR_SPI2EN = 14 + 32 ,
    RCC_APB1ENR_SPI3EN = 15 + 32 ,
    RCC_APB1ENR_USART2EN = 17 + 32,
    RCC_APB1ENR_I2C1EN = 21 + 32,
    RCC_APB1ENR_I2C2EN = 22 + 32 ,
    RCC_APB1ENR_I2C3EN = 23 + 32 ,
    RCC_APB1ENR_PWREN = 28 + 32 ,

    // RCC APB2 Peripheral Clock Enable Register (RCC_APB2ENR)
    RCC_APB2ENR_TIM1EN = 0 + 64 ,
    RCC_APB2ENR_USART1EN = 4 + 64,
    RCC_APB2ENR_USART6EN = 5 + 64 ,
    RCC_APB2ENR_ADC1EN = 8 + 64 ,
    RCC_APB2ENR_SDIOEN = 11 + 64 ,
    RCC_APB2ENR_SPI1EN = 12 + 64,
    RCC_APB2ENR_SPI4EN = 13 + 64 ,
    RCC_APB2ENR_SYSCFGEN = 14 + 64,
    RCC_APB2ENR_TIM9EN = 16 + 64 ,
    RCC_APB2ENR_TIM10EN = 17 + 64,
    RCC_APB2ENR_TIM11EN = 18 + 64,
} peripherals_t;

/********************TypeDefines_End*****************/

#endif /* DRIVERS_RCC_DRIVER_RCC_REGISTERS_H_ */
 
