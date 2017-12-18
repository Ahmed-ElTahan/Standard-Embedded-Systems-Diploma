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
40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.lss \

FLASH_IMAGE += \
40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf secondary-outputs

# Tool invocations
40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.map -mmcu=atmega32 -o "40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.lss: 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf  >"40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.lss"
	@echo 'Finished building: $@'
	@echo ' '

40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.hex: 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf  "40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 40_ServoMotor_PWM_fundamentals_2Buttons_2Directions.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
