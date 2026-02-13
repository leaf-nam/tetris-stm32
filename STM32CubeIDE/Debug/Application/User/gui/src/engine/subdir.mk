################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/User/gui/src/engine/engine.cpp \
../Application/User/gui/src/engine/multi_engine.cpp \
../Application/User/gui/src/engine/solo_engine.cpp 

OBJS += \
./Application/User/gui/src/engine/engine.o \
./Application/User/gui/src/engine/multi_engine.o \
./Application/User/gui/src/engine/solo_engine.o 

CPP_DEPS += \
./Application/User/gui/src/engine/engine.d \
./Application/User/gui/src/engine/multi_engine.d \
./Application/User/gui/src/engine/solo_engine.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/gui/src/engine/%.o Application/User/gui/src/engine/%.su Application/User/gui/src/engine/%.cyclo: ../Application/User/gui/src/engine/%.cpp Application/User/gui/src/engine/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-gui-2f-src-2f-engine

clean-Application-2f-User-2f-gui-2f-src-2f-engine:
	-$(RM) ./Application/User/gui/src/engine/engine.cyclo ./Application/User/gui/src/engine/engine.d ./Application/User/gui/src/engine/engine.o ./Application/User/gui/src/engine/engine.su ./Application/User/gui/src/engine/multi_engine.cyclo ./Application/User/gui/src/engine/multi_engine.d ./Application/User/gui/src/engine/multi_engine.o ./Application/User/gui/src/engine/multi_engine.su ./Application/User/gui/src/engine/solo_engine.cyclo ./Application/User/gui/src/engine/solo_engine.d ./Application/User/gui/src/engine/solo_engine.o ./Application/User/gui/src/engine/solo_engine.su

.PHONY: clean-Application-2f-User-2f-gui-2f-src-2f-engine

