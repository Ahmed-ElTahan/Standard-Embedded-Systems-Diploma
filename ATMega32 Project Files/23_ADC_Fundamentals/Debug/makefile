################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
23_ADC_Fundamentals.lss \

FLASH_IMAGE += \
23_ADC_Fundamentals.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 23_ADC_Fundamentals.elf secondary-outputs

# Tool invocations
23_ADC_Fundamentals.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,23_ADC_Fundamentals.map -mmcu=atmega32 -o "23_ADC_Fundamentals.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

23_ADC_Fundamentals.lss: 23_ADC_Fundamentals.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 23_ADC_Fundamentals.elf  >"23_ADC_Fundamentals.lss"
	@echo 'Finished building: $@'
	@echo ' '

23_ADC_Fundamentals.hex: 23_ADC_Fundamentals.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 23_ADC_Fundamentals.elf  "23_ADC_Fundamentals.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 23_ADC_Fundamentals.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 23_ADC_Fundamentals.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 23_ADC_Fundamentals.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
