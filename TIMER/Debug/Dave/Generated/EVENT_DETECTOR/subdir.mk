################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/EVENT_DETECTOR/event_detector.c \
../Dave/Generated/EVENT_DETECTOR/event_detector_conf.c 

OBJS += \
./Dave/Generated/EVENT_DETECTOR/event_detector.o \
./Dave/Generated/EVENT_DETECTOR/event_detector_conf.o 

C_DEPS += \
./Dave/Generated/EVENT_DETECTOR/event_detector.d \
./Dave/Generated/EVENT_DETECTOR/event_detector_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/EVENT_DETECTOR/%.o: ../Dave/Generated/EVENT_DETECTOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F100x2048 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

