################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC_Driver/RCC_Program.c 

OBJS += \
./MCAL/RCC_Driver/RCC_Program.o 

C_DEPS += \
./MCAL/RCC_Driver/RCC_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC_Driver/%.o MCAL/RCC_Driver/%.su MCAL/RCC_Driver/%.cyclo: ../MCAL/RCC_Driver/%.c MCAL/RCC_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-RCC_Driver

clean-MCAL-2f-RCC_Driver:
	-$(RM) ./MCAL/RCC_Driver/RCC_Program.cyclo ./MCAL/RCC_Driver/RCC_Program.d ./MCAL/RCC_Driver/RCC_Program.o ./MCAL/RCC_Driver/RCC_Program.su

.PHONY: clean-MCAL-2f-RCC_Driver

