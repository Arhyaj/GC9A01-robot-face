################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../avi/aviparser.cpp 

OBJS += \
./avi/aviparser.o 

CPP_DEPS += \
./avi/aviparser.d 


# Each subdirectory must supply rules for building sources it contributes
avi/%.o avi/%.su avi/%.cyclo: ../avi/%.cpp avi/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Bsp -I../UserApp -I../jpegdec -I../avi -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Tjpegdec -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-avi

clean-avi:
	-$(RM) ./avi/aviparser.cyclo ./avi/aviparser.d ./avi/aviparser.o ./avi/aviparser.su

.PHONY: clean-avi

