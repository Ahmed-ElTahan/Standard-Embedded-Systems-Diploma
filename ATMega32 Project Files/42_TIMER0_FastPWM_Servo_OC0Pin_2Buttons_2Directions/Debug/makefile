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
42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.lss \

FLASH_IMAGE += \
42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf secondary-outputs

# Tool invocations
42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.map -mmcu=atmega32 -o "42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.lss: 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf  >"42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.lss"
	@echo 'Finished building: $@'
	@echo ' '

42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.hex: 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf  "42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 42_TIMER0_FastPWM_Servo_OC0Pin_2Buttons_2Directions.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
