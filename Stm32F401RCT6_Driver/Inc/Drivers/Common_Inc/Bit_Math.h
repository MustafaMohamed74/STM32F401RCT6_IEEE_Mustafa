/**
 * @file bit_math.h
 * @brief This header file provides bit manipulation macros.
 *
 * This file contains macros for setting, clearing, toggling, and getting the value of specific bits in a variable.
 * It is useful for low-level hardware programming where direct manipulation of bits is required.
 *
 * @author Mustafa Mohamed
 * @date August 13, 2024
 */

#ifndef COMMON_INC_BIT_MATH_H_
#define COMMON_INC_BIT_MATH_H_

/**
 * @brief Sets a specific bit in a variable.
 *
 * This macro sets the bit at the position specified by BitNo in the variable Var.
 *
 * @param Var The variable in which the bit is to be set.
 * @param BitNo The bit number to set (0 for the least significant bit).
 */
#define Set_Bit(Var,BitNo) Var=Var|(1<<BitNo)

/**
 * @brief Clears a specific bit in a variable.
 *
 * This macro clears the bit at the position specified by BitNo in the variable Var.
 *
 * @param Var The variable in which the bit is to be cleared.
 * @param BitNo The bit number to clear (0 for the least significant bit).
 */
#define Clr_Bit(Var,BitNo) Var=Var&(~(1<<BitNo))

/**
 * @brief Toggles a specific bit in a variable.
 *
 * This macro toggles (inverts) the bit at the position specified by BitNo in the variable Var.
 *
 * @param Var The variable in which the bit is to be toggled.
 * @param BitNo The bit number to toggle (0 for the least significant bit).
 */
#define Tog_Bit(Var,BitNo) Var=Var^(1<<BitNo)

/**
 * @brief Gets the value of a specific bit in a variable.
 *
 * This macro retrieves the value of the bit at the position specified by BitNo in the variable Var.
 * The result is either 0 or 1.
 *
 * @param Var The variable from which the bit value is to be retrieved.
 * @param BitNo The bit number to get (0 for the least significant bit).
 * @return The value of the specified bit (0 or 1).
 */
#define Get_Bit(Var,BitNo) ((Var>>BitNo)&1)

#endif /* COMMON_INC_BIT_MATH_H_ */
