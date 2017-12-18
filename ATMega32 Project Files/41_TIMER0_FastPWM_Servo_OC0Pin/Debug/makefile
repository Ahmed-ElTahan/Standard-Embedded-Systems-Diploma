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
41_TIMER0_FastPWM_Servo_OC0Pin.lss \

FLASH_IMAGE += \
41_TIMER0_FastPWM_Servo_OC0Pin.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 41_TIMER0_FastPWM_Servo_OC0Pin.elf secondary-outputs

# Tool invocations
41_TIMER0_FastPWM_Servo_OC0Pin.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,41_TIMER0_FastPWM_Servo_OC0Pin.map -mmcu=atmega32 -o "41_TIMER0_FastPWM_Servo_OC0Pin.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

41_TIMER0_FastPWM_Servo_OC0Pin.lss: 41_TIMER0_FastPWM_Servo_OC0Pin.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 41_TIMER0_FastPWM_Servo_OC0Pin.elf  >"41_TIMER0_FastPWM_Servo_OC0Pin.lss"
	@echo 'Finished building: $@'
	@echo ' '

41_TIMER0_FastPWM_Servo_OC0Pin.hex: 41_TIMER0_FastPWM_Servo_OC0Pin.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 41_TIMER0_FastPWM_Servo_OC0Pin.elf  "41_TIMER0_FastPWM_Servo_OC0Pin.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 41_TIMER0_FastPWM_Servo_OC0Pin.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 41_TIMER0_FastPWM_Servo_OC0Pin.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 41_TIMER0_FastPWM_Servo_OC0Pin.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:41_TIMER0_FastPWM_Servo_OC0Pin.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 41_TIMER0_FastPWM_Servo_OC0Pin.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
