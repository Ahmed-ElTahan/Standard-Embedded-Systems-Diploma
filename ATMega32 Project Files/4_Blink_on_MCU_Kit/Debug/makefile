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
4_Blink_on_MCU_Kit.lss \

FLASH_IMAGE += \
4_Blink_on_MCU_Kit.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 4_Blink_on_MCU_Kit.elf secondary-outputs

# Tool invocations
4_Blink_on_MCU_Kit.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,4_Blink_on_MCU_Kit.map -mmcu=atmega32 -o "4_Blink_on_MCU_Kit.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

4_Blink_on_MCU_Kit.lss: 4_Blink_on_MCU_Kit.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 4_Blink_on_MCU_Kit.elf  >"4_Blink_on_MCU_Kit.lss"
	@echo 'Finished building: $@'
	@echo ' '

4_Blink_on_MCU_Kit.hex: 4_Blink_on_MCU_Kit.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 4_Blink_on_MCU_Kit.elf  "4_Blink_on_MCU_Kit.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 4_Blink_on_MCU_Kit.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 4_Blink_on_MCU_Kit.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 4_Blink_on_MCU_Kit.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:4_Blink_on_MCU_Kit.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 4_Blink_on_MCU_Kit.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
