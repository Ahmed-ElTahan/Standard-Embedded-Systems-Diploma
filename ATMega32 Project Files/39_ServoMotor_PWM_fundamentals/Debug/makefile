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
39_ServoMotor_PWM_fundamentals.lss \

FLASH_IMAGE += \
39_ServoMotor_PWM_fundamentals.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 39_ServoMotor_PWM_fundamentals.elf secondary-outputs

# Tool invocations
39_ServoMotor_PWM_fundamentals.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,39_ServoMotor_PWM_fundamentals.map -mmcu=atmega32 -o "39_ServoMotor_PWM_fundamentals.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

39_ServoMotor_PWM_fundamentals.lss: 39_ServoMotor_PWM_fundamentals.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 39_ServoMotor_PWM_fundamentals.elf  >"39_ServoMotor_PWM_fundamentals.lss"
	@echo 'Finished building: $@'
	@echo ' '

39_ServoMotor_PWM_fundamentals.hex: 39_ServoMotor_PWM_fundamentals.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 39_ServoMotor_PWM_fundamentals.elf  "39_ServoMotor_PWM_fundamentals.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 39_ServoMotor_PWM_fundamentals.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 39_ServoMotor_PWM_fundamentals.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 39_ServoMotor_PWM_fundamentals.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:39_ServoMotor_PWM_fundamentals.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 39_ServoMotor_PWM_fundamentals.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
