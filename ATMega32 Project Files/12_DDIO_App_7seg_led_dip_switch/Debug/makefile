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
12_DDIO_App_7seg_led_dip_switch.lss \

FLASH_IMAGE += \
12_DDIO_App_7seg_led_dip_switch.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 12_DDIO_App_7seg_led_dip_switch.elf secondary-outputs

# Tool invocations
12_DDIO_App_7seg_led_dip_switch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,12_DDIO_App_7seg_led_dip_switch.map -mmcu=atmega32 -o "12_DDIO_App_7seg_led_dip_switch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

12_DDIO_App_7seg_led_dip_switch.lss: 12_DDIO_App_7seg_led_dip_switch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 12_DDIO_App_7seg_led_dip_switch.elf  >"12_DDIO_App_7seg_led_dip_switch.lss"
	@echo 'Finished building: $@'
	@echo ' '

12_DDIO_App_7seg_led_dip_switch.hex: 12_DDIO_App_7seg_led_dip_switch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 12_DDIO_App_7seg_led_dip_switch.elf  "12_DDIO_App_7seg_led_dip_switch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 12_DDIO_App_7seg_led_dip_switch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 12_DDIO_App_7seg_led_dip_switch.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 12_DDIO_App_7seg_led_dip_switch.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:12_DDIO_App_7seg_led_dip_switch.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 12_DDIO_App_7seg_led_dip_switch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
