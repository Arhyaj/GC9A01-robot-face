################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tjpegdec/tjpgd.c 

CPP_SRCS += \
../Tjpegdec/JpgDecoder_STM.cpp 

C_DEPS += \
./Tjpegdec/tjpgd.d 

OBJS += \
./Tjpegdec/JpgDecoder_STM.o \
./Tjpegdec/tjpgd.o 

CPP_DEPS += \
./Tjpegdec/JpgDecoder_STM.d 


# Each subdirectory must supply rules for building sources it contributes
Tjpegdec/%.o Tjpegdec/%.su Tjpegdec/%.cyclo: ../Tjpegdec/%.cpp Tjpegdec/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Bsp -I../UserApp -I../jpegdec -I../avi -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Tjpegdec -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Tjpegdec/%.o Tjpegdec/%.su Tjpegdec/%.cyclo: ../Tjpegdec/%.c Tjpegdec/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../UserApp -I../Bsp -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Tjpegdec

clean-Tjpegdec:
	-$(RM) ./Tjpegdec/JpgDecoder_STM.cyclo ./Tjpegdec/JpgDecoder_STM.d ./Tjpegdec/JpgDecoder_STM.o ./Tjpegdec/JpgDecoder_STM.su ./Tjpegdec/tjpgd.cyclo ./Tjpegdec/tjpgd.d ./Tjpegdec/tjpgd.o ./Tjpegdec/tjpgd.su

.PHONY: clean-Tjpegdec

