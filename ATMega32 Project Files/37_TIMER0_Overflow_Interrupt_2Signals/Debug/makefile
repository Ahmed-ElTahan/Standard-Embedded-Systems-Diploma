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
37_TIMER0_Overflow_Interrupt_2Signals.lss \

FLASH_IMAGE += \
37_TIMER0_Overflow_Interrupt_2Signals.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 37_TIMER0_Overflow_Interrupt_2Signals.elf secondary-outputs

# Tool invocations
37_TIMER0_Overflow_Interrupt_2Signals.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,37_TIMER0_Overflow_Interrupt_2Signals.map -mmcu=atmega32 -o "37_TIMER0_Overflow_Interrupt_2Signals.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

37_TIMER0_Overflow_Interrupt_2Signals.lss: 37_TIMER0_Overflow_Interrupt_2Signals.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 37_TIMER0_Overflow_Interrupt_2Signals.elf  >"37_TIMER0_Overflow_Interrupt_2Signals.lss"
	@echo 'Finished building: $@'
	@echo ' '

37_TIMER0_Overflow_Interrupt_2Signals.hex: 37_TIMER0_Overflow_Interrupt_2Signals.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 37_TIMER0_Overflow_Interrupt_2Signals.elf  "37_TIMER0_Overflow_Interrupt_2Signals.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 37_TIMER0_Overflow_Interrupt_2Signals.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 37_TIMER0_Overflow_Interrupt_2Signals.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 37_TIMER0_Overflow_Interrupt_2Signals.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:37_TIMER0_Overflow_Interrupt_2Signals.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 37_TIMER0_Overflow_Interrupt_2Signals.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
