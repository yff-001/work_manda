################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/gcc_arm_none_eabi_9_2_1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./empty_non_sysconfig.o" \
"./event_queue.o" \
"./scheduler.o" \
"./startup_mspm0l130x_gcc.o" \
"./state_machine.o" \
"./ti_msp_dl_config.o" \
"./driver/cpu.o" \
"./driver/gpio.o" \
"./driver/timer.o" \
"./driver/uart.o" \
"./handler/button.o" \
"./handler/communication.o" \
"./handler/display.o" \
"./handler/pon.o" \
"./handler/xtimer.o" \
-Wl,-T"../mspm0l1306.lds" \
$(GEN_CMDS__FLAG) \
"C:/ti/mspm0_sdk_1_30_00_03/source/ti/driverlib/lib/gcc/m0p/mspm0l11xx_l13xx/driverlib.a" \
-l:driverlib.a \
-lgcc \
-lc \
-lm \
-lnosys \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include driver/subdir_vars.mk
-include handler/subdir_vars.mk
-include subdir_rules.mk
-include driver/subdir_rules.mk
-include handler/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
empty_non_sysconfig_LP_MSPM0L1306_nortos_gcc.out 

EXE_OUTPUTS__QUOTED += \
"empty_non_sysconfig_LP_MSPM0L1306_nortos_gcc.out" 


# All Target
all: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "empty_non_sysconfig_LP_MSPM0L1306_nortos_gcc.out"

# Tool invocations
empty_non_sysconfig_LP_MSPM0L1306_nortos_gcc.out: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"C:/ti/gcc_arm_none_eabi_9_2_1/bin/arm-none-eabi-gcc-9.2.1.exe" -march=armv6-m -mthumb -mfloat-abi=soft -D__MSPM0L1306__ -O2 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -mcpu=cortex-m0plus -Wl,-Map,"empty_non_sysconfig_LP_MSPM0L1306_nortos_gcc.map" -nostartfiles -static -Wl,--gc-sections -L"C:/ti/mspm0_sdk_1_30_00_03/source/ti/driverlib/lib/gcc/m0p/mspm0l11xx_l13xx" -L"C:/ti/mspm0_sdk_1_30_00_03/source" -L"C:/Users/xu.y.63/workspace_ccstheia/empty_non_sysconfig_LP_MSPM0L1306_nortos_gcc" -L"C:/ti/gcc_arm_none_eabi_9_2_1/arm-none-eabi/lib/thumb/v6-m/nofp" -march=armv6-m -mthumb -o"empty_non_sysconfig_LP_MSPM0L1306_nortos_gcc.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "empty_non_sysconfig.o" "event_queue.o" "scheduler.o" "startup_mspm0l130x_gcc.o" "state_machine.o" "ti_msp_dl_config.o" "driver\cpu.o" "driver\gpio.o" "driver\timer.o" "driver\uart.o" "handler\button.o" "handler\communication.o" "handler\display.o" "handler\pon.o" "handler\xtimer.o" 
	-$(RM) "empty_non_sysconfig.d" "event_queue.d" "scheduler.d" "startup_mspm0l130x_gcc.d" "state_machine.d" "ti_msp_dl_config.d" "driver\cpu.d" "driver\gpio.d" "driver\timer.d" "driver\uart.d" "handler\button.d" "handler\communication.d" "handler\display.d" "handler\pon.d" "handler\xtimer.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

