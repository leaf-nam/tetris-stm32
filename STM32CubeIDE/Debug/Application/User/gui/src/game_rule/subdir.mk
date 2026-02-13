################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/User/gui/src/game_rule/action_resolver.cpp \
../Application/User/gui/src/game_rule/key_mapper.cpp \
../Application/User/gui/src/game_rule/rule.cpp \
../Application/User/gui/src/game_rule/rule_blitz.cpp \
../Application/User/gui/src/game_rule/rule_factory.cpp \
../Application/User/gui/src/game_rule/rule_forty_lines.cpp \
../Application/User/gui/src/game_rule/rule_versus.cpp \
../Application/User/gui/src/game_rule/rule_zen.cpp \
../Application/User/gui/src/game_rule/wall_kick.cpp 

OBJS += \
./Application/User/gui/src/game_rule/action_resolver.o \
./Application/User/gui/src/game_rule/key_mapper.o \
./Application/User/gui/src/game_rule/rule.o \
./Application/User/gui/src/game_rule/rule_blitz.o \
./Application/User/gui/src/game_rule/rule_factory.o \
./Application/User/gui/src/game_rule/rule_forty_lines.o \
./Application/User/gui/src/game_rule/rule_versus.o \
./Application/User/gui/src/game_rule/rule_zen.o \
./Application/User/gui/src/game_rule/wall_kick.o 

CPP_DEPS += \
./Application/User/gui/src/game_rule/action_resolver.d \
./Application/User/gui/src/game_rule/key_mapper.d \
./Application/User/gui/src/game_rule/rule.d \
./Application/User/gui/src/game_rule/rule_blitz.d \
./Application/User/gui/src/game_rule/rule_factory.d \
./Application/User/gui/src/game_rule/rule_forty_lines.d \
./Application/User/gui/src/game_rule/rule_versus.d \
./Application/User/gui/src/game_rule/rule_zen.d \
./Application/User/gui/src/game_rule/wall_kick.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/gui/src/game_rule/%.o Application/User/gui/src/game_rule/%.su Application/User/gui/src/game_rule/%.cyclo: ../Application/User/gui/src/game_rule/%.cpp Application/User/gui/src/game_rule/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-gui-2f-src-2f-game_rule

clean-Application-2f-User-2f-gui-2f-src-2f-game_rule:
	-$(RM) ./Application/User/gui/src/game_rule/action_resolver.cyclo ./Application/User/gui/src/game_rule/action_resolver.d ./Application/User/gui/src/game_rule/action_resolver.o ./Application/User/gui/src/game_rule/action_resolver.su ./Application/User/gui/src/game_rule/key_mapper.cyclo ./Application/User/gui/src/game_rule/key_mapper.d ./Application/User/gui/src/game_rule/key_mapper.o ./Application/User/gui/src/game_rule/key_mapper.su ./Application/User/gui/src/game_rule/rule.cyclo ./Application/User/gui/src/game_rule/rule.d ./Application/User/gui/src/game_rule/rule.o ./Application/User/gui/src/game_rule/rule.su ./Application/User/gui/src/game_rule/rule_blitz.cyclo ./Application/User/gui/src/game_rule/rule_blitz.d ./Application/User/gui/src/game_rule/rule_blitz.o ./Application/User/gui/src/game_rule/rule_blitz.su ./Application/User/gui/src/game_rule/rule_factory.cyclo ./Application/User/gui/src/game_rule/rule_factory.d ./Application/User/gui/src/game_rule/rule_factory.o ./Application/User/gui/src/game_rule/rule_factory.su ./Application/User/gui/src/game_rule/rule_forty_lines.cyclo ./Application/User/gui/src/game_rule/rule_forty_lines.d ./Application/User/gui/src/game_rule/rule_forty_lines.o ./Application/User/gui/src/game_rule/rule_forty_lines.su ./Application/User/gui/src/game_rule/rule_versus.cyclo ./Application/User/gui/src/game_rule/rule_versus.d ./Application/User/gui/src/game_rule/rule_versus.o ./Application/User/gui/src/game_rule/rule_versus.su ./Application/User/gui/src/game_rule/rule_zen.cyclo ./Application/User/gui/src/game_rule/rule_zen.d ./Application/User/gui/src/game_rule/rule_zen.o ./Application/User/gui/src/game_rule/rule_zen.su ./Application/User/gui/src/game_rule/wall_kick.cyclo ./Application/User/gui/src/game_rule/wall_kick.d ./Application/User/gui/src/game_rule/wall_kick.o ./Application/User/gui/src/game_rule/wall_kick.su

.PHONY: clean-Application-2f-User-2f-gui-2f-src-2f-game_rule

