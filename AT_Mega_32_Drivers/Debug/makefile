################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SPI_APP/subdir.mk
-include MCAL/TIMER_COUNTER/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LED_BUZZER/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/BUTTON/subdir.mk
-include HAL/7SEGMENT/subdir.mk
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
AT_Mega_32.lss \

FLASH_IMAGE += \
AT_Mega_32.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AT_Mega_32.elf secondary-outputs

# Tool invocations
AT_Mega_32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AT_Mega_32.map -mmcu=atmega32 -o "AT_Mega_32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AT_Mega_32.lss: AT_Mega_32.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AT_Mega_32.elf  >"AT_Mega_32.lss"
	@echo 'Finished building: $@'
	@echo ' '

AT_Mega_32.hex: AT_Mega_32.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AT_Mega_32.elf  "AT_Mega_32.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AT_Mega_32.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AT_Mega_32.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AT_Mega_32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
