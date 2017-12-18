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
57_Intro_to_RTOS_Servo_2Buttons_App.lss \

FLASH_IMAGE += \
57_Intro_to_RTOS_Servo_2Buttons_App.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 57_Intro_to_RTOS_Servo_2Buttons_App.elf secondary-outputs

# Tool invocations
57_Intro_to_RTOS_Servo_2Buttons_App.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,57_Intro_to_RTOS_Servo_2Buttons_App.map -mmcu=atmega32 -o "57_Intro_to_RTOS_Servo_2Buttons_App.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

57_Intro_to_RTOS_Servo_2Buttons_App.lss: 57_Intro_to_RTOS_Servo_2Buttons_App.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 57_Intro_to_RTOS_Servo_2Buttons_App.elf  >"57_Intro_to_RTOS_Servo_2Buttons_App.lss"
	@echo 'Finished building: $@'
	@echo ' '

57_Intro_to_RTOS_Servo_2Buttons_App.hex: 57_Intro_to_RTOS_Servo_2Buttons_App.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 57_Intro_to_RTOS_Servo_2Buttons_App.elf  "57_Intro_to_RTOS_Servo_2Buttons_App.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 57_Intro_to_RTOS_Servo_2Buttons_App.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 57_Intro_to_RTOS_Servo_2Buttons_App.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 57_Intro_to_RTOS_Servo_2Buttons_App.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:57_Intro_to_RTOS_Servo_2Buttons_App.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 57_Intro_to_RTOS_Servo_2Buttons_App.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
