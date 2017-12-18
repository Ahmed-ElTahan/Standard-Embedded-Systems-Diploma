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
19_Transistor_LED_App.lss \

FLASH_IMAGE += \
19_Transistor_LED_App.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 19_Transistor_LED_App.elf secondary-outputs

# Tool invocations
19_Transistor_LED_App.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,19_Transistor_LED_App.map -mmcu=atmega32 -o "19_Transistor_LED_App.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

19_Transistor_LED_App.lss: 19_Transistor_LED_App.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 19_Transistor_LED_App.elf  >"19_Transistor_LED_App.lss"
	@echo 'Finished building: $@'
	@echo ' '

19_Transistor_LED_App.hex: 19_Transistor_LED_App.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 19_Transistor_LED_App.elf  "19_Transistor_LED_App.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 19_Transistor_LED_App.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 19_Transistor_LED_App.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 19_Transistor_LED_App.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:19_Transistor_LED_App.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 19_Transistor_LED_App.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
