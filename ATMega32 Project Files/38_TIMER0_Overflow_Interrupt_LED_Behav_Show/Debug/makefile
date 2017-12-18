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
38_TIMER0_Overflow_Interrupt_LED_Behav_Show.lss \

FLASH_IMAGE += \
38_TIMER0_Overflow_Interrupt_LED_Behav_Show.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf secondary-outputs

# Tool invocations
38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,38_TIMER0_Overflow_Interrupt_LED_Behav_Show.map -mmcu=atmega32 -o "38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

38_TIMER0_Overflow_Interrupt_LED_Behav_Show.lss: 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf  >"38_TIMER0_Overflow_Interrupt_LED_Behav_Show.lss"
	@echo 'Finished building: $@'
	@echo ' '

38_TIMER0_Overflow_Interrupt_LED_Behav_Show.hex: 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf  "38_TIMER0_Overflow_Interrupt_LED_Behav_Show.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:38_TIMER0_Overflow_Interrupt_LED_Behav_Show.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 38_TIMER0_Overflow_Interrupt_LED_Behav_Show.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
