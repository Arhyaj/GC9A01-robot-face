################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jpegdec/JPEGDEC.cpp 

S_UPPER_SRCS += \
../jpegdec/s3_simd_420.S \
../jpegdec/s3_simd_444.S \
../jpegdec/s3_simd_dequant.S 

OBJS += \
./jpegdec/JPEGDEC.o \
./jpegdec/s3_simd_420.o \
./jpegdec/s3_simd_444.o \
./jpegdec/s3_simd_dequant.o 

S_UPPER_DEPS += \
./jpegdec/s3_simd_420.d \
./jpegdec/s3_simd_444.d \
./jpegdec/s3_simd_dequant.d 

CPP_DEPS += \
./jpegdec/JPEGDEC.d 


# Each subdirectory must supply rules for building sources it contributes
jpegdec/%.o jpegdec/%.su jpegdec/%.cyclo: ../jpegdec/%.cpp jpegdec/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Bsp -I../UserApp -I../jpegdec -I../avi -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Tjpegdec -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
jpegdec/%.o: ../jpegdec/%.S jpegdec/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-jpegdec

clean-jpegdec:
	-$(RM) ./jpegdec/JPEGDEC.cyclo ./jpegdec/JPEGDEC.d ./jpegdec/JPEGDEC.o ./jpegdec/JPEGDEC.su ./jpegdec/s3_simd_420.d ./jpegdec/s3_simd_420.o ./jpegdec/s3_simd_444.d ./jpegdec/s3_simd_444.o ./jpegdec/s3_simd_dequant.d ./jpegdec/s3_simd_dequant.o

.PHONY: clean-jpegdec

