################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/User/gui/src/render/block_renderer.cpp \
../Application/User/gui/src/render/box_renderer.cpp \
../Application/User/gui/src/render/color_picker.cpp \
../Application/User/gui/src/render/input_window_renderer.cpp \
../Application/User/gui/src/render/mock_renderer.cpp \
../Application/User/gui/src/render/text_renderer.cpp \
../Application/User/gui/src/render/theme.cpp 

OBJS += \
./Application/User/gui/src/render/block_renderer.o \
./Application/User/gui/src/render/box_renderer.o \
./Application/User/gui/src/render/color_picker.o \
./Application/User/gui/src/render/input_window_renderer.o \
./Application/User/gui/src/render/mock_renderer.o \
./Application/User/gui/src/render/text_renderer.o \
./Application/User/gui/src/render/theme.o 

CPP_DEPS += \
./Application/User/gui/src/render/block_renderer.d \
./Application/User/gui/src/render/box_renderer.d \
./Application/User/gui/src/render/color_picker.d \
./Application/User/gui/src/render/input_window_renderer.d \
./Application/User/gui/src/render/mock_renderer.d \
./Application/User/gui/src/render/text_renderer.d \
./Application/User/gui/src/render/theme.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/gui/src/render/%.o Application/User/gui/src/render/%.su Application/User/gui/src/render/%.cyclo: ../Application/User/gui/src/render/%.cpp Application/User/gui/src/render/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-gui-2f-src-2f-render

clean-Application-2f-User-2f-gui-2f-src-2f-render:
	-$(RM) ./Application/User/gui/src/render/block_renderer.cyclo ./Application/User/gui/src/render/block_renderer.d ./Application/User/gui/src/render/block_renderer.o ./Application/User/gui/src/render/block_renderer.su ./Application/User/gui/src/render/box_renderer.cyclo ./Application/User/gui/src/render/box_renderer.d ./Application/User/gui/src/render/box_renderer.o ./Application/User/gui/src/render/box_renderer.su ./Application/User/gui/src/render/color_picker.cyclo ./Application/User/gui/src/render/color_picker.d ./Application/User/gui/src/render/color_picker.o ./Application/User/gui/src/render/color_picker.su ./Application/User/gui/src/render/input_window_renderer.cyclo ./Application/User/gui/src/render/input_window_renderer.d ./Application/User/gui/src/render/input_window_renderer.o ./Application/User/gui/src/render/input_window_renderer.su ./Application/User/gui/src/render/mock_renderer.cyclo ./Application/User/gui/src/render/mock_renderer.d ./Application/User/gui/src/render/mock_renderer.o ./Application/User/gui/src/render/mock_renderer.su ./Application/User/gui/src/render/text_renderer.cyclo ./Application/User/gui/src/render/text_renderer.d ./Application/User/gui/src/render/text_renderer.o ./Application/User/gui/src/render/text_renderer.su ./Application/User/gui/src/render/theme.cyclo ./Application/User/gui/src/render/theme.d ./Application/User/gui/src/render/theme.o ./Application/User/gui/src/render/theme.su

.PHONY: clean-Application-2f-User-2f-gui-2f-src-2f-render

