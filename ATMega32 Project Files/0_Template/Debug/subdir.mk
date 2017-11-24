################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DADC.c \
../DDIO.c \
../HKPD.c \
../HLCD.c \
../HSeven_Segment_DDIO.c \
../HStepper_Motor.c \
../SCompareArryas.c \
../main.c 

OBJS += \
./DADC.o \
./DDIO.o \
./HKPD.o \
./HLCD.o \
./HSeven_Segment_DDIO.o \
./HStepper_Motor.o \
./SCompareArryas.o \
./main.o 

C_DEPS += \
./DADC.d \
./DDIO.d \
./HKPD.d \
./HLCD.d \
./HSeven_Segment_DDIO.d \
./HStepper_Motor.d \
./SCompareArryas.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


