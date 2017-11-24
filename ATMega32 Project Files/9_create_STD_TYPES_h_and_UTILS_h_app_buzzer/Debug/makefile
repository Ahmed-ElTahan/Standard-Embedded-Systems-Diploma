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
9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.lss \

FLASH_IMAGE += \
9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf secondary-outputs

# Tool invocations
9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.map -mmcu=atmega32 -o "9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.lss: 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf  >"9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.lss"
	@echo 'Finished building: $@'
	@echo ' '

9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.hex: 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf  "9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 9_create_STD_TYPES_h_and_UTILS_h_app_buzzer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
