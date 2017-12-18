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
25_DADC_H_C_8LED_OUTPUT.lss \

FLASH_IMAGE += \
25_DADC_H_C_8LED_OUTPUT.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 25_DADC_H_C_8LED_OUTPUT.elf secondary-outputs

# Tool invocations
25_DADC_H_C_8LED_OUTPUT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,25_DADC_H_C_8LED_OUTPUT.map -mmcu=atmega32 -o "25_DADC_H_C_8LED_OUTPUT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

25_DADC_H_C_8LED_OUTPUT.lss: 25_DADC_H_C_8LED_OUTPUT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 25_DADC_H_C_8LED_OUTPUT.elf  >"25_DADC_H_C_8LED_OUTPUT.lss"
	@echo 'Finished building: $@'
	@echo ' '

25_DADC_H_C_8LED_OUTPUT.hex: 25_DADC_H_C_8LED_OUTPUT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 25_DADC_H_C_8LED_OUTPUT.elf  "25_DADC_H_C_8LED_OUTPUT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 25_DADC_H_C_8LED_OUTPUT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 25_DADC_H_C_8LED_OUTPUT.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 25_DADC_H_C_8LED_OUTPUT.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:25_DADC_H_C_8LED_OUTPUT.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 25_DADC_H_C_8LED_OUTPUT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
