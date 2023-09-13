################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include libr/subdir.mk
-include 2-hal/servo/subdir.mk
-include 2-hal/DC_motor/subdir.mk
-include 2-hal/CLCD/subdir.mk
-include 1-mcal/7-USART/subdir.mk
-include 1-mcal/6-TIMER/subdir.mk
-include 1-mcal/5-ADC/subdir.mk
-include 1-mcal/4-EXTI/subdir.mk
-include 1-mcal/3-GIE/subdir.mk
-include 1-mcal/2-PORT/subdir.mk
-include 1-mcal/11-WTDOG/subdir.mk
-include 1-mcal/10-internal_EEPROM/subdir.mk
-include 1-mcal/1-DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MCU_1.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: MCU_1.elf secondary-outputs

# Tool invocations
MCU_1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MCU_1.map -mmcu=atmega32 -o "MCU_1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MCU_1.lss: MCU_1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MCU_1.elf  >"MCU_1.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MCU_1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MCU_1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MCU_1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
