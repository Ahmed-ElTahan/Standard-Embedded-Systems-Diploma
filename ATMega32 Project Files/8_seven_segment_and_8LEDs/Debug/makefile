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
8_seven_segment_and_8LEDs.lss \

FLASH_IMAGE += \
8_seven_segment_and_8LEDs.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 8_seven_segment_and_8LEDs.elf secondary-outputs

# Tool invocations
8_seven_segment_and_8LEDs.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,8_seven_segment_and_8LEDs.map -mmcu=atmega32 -o "8_seven_segment_and_8LEDs.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

8_seven_segment_and_8LEDs.lss: 8_seven_segment_and_8LEDs.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 8_seven_segment_and_8LEDs.elf  >"8_seven_segment_and_8LEDs.lss"
	@echo 'Finished building: $@'
	@echo ' '

8_seven_segment_and_8LEDs.hex: 8_seven_segment_and_8LEDs.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 8_seven_segment_and_8LEDs.elf  "8_seven_segment_and_8LEDs.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 8_seven_segment_and_8LEDs.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 8_seven_segment_and_8LEDs.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 8_seven_segment_and_8LEDs.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:8_seven_segment_and_8LEDs.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 8_seven_segment_and_8LEDs.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
