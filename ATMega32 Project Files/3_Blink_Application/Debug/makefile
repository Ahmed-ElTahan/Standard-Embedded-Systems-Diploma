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
3_Blink_Application.lss \

FLASH_IMAGE += \
3_Blink_Application.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 3_Blink_Application.elf secondary-outputs

# Tool invocations
3_Blink_Application.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,3_Blink_Application.map -mmcu=atmega32 -o "3_Blink_Application.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

3_Blink_Application.lss: 3_Blink_Application.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 3_Blink_Application.elf  >"3_Blink_Application.lss"
	@echo 'Finished building: $@'
	@echo ' '

3_Blink_Application.hex: 3_Blink_Application.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 3_Blink_Application.elf  "3_Blink_Application.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 3_Blink_Application.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 3_Blink_Application.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 3_Blink_Application.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:3_Blink_Application.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 3_Blink_Application.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
