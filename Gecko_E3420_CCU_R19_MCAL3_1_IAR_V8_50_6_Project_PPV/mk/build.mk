
-include $(CFGDIR)/$(CFG).cfg
-include $(TOPDIR)/arch/$(ARCH)/compiler.mk
-include $(TOPDIR)/arch/$(ARCH)/arch.mk
-include $(TOPDIR)/arch/$(ARCH)/$(CPU)/cpu.mk

FILTER=$(foreach v,$(1),$(foreach x,$(2),$(if $(findstring $(v),$(x)),$(x),)))

CPPCHK = $(TOPDIR)/tools/cppcheck/cppcheck
# Please add FILESDIR=xxx when build/install cppcheck.
# make install FILESDIR=$(TOPDIR)/tools/cppcheck    #Specify folder where cppcheck files are installed
CPPCHKFLAGS = --inconclusive --enable=warning,style --std=c99 -q
#CPPCHKFLAGS = --enable=all --std=c99 -q

ARCH_def = $(subst -,_,$(ARCH))
CPU_def = $(subst -,_,$(CPU))
CDEFINES += -DARCH_$(ARCH_def) -DCPU_$(CPU_def) -DSOC_$(SOC) -DCORE_$(CORE) -DTC_$(TC) -DBOARD_$(BOARD) \
            -DAUTOSAR_OS_NOT_USED -DUSE_SW_VECTOR_MODE -DVCAN

ifdef COV
CDEFINES += -DGCOV_ENABLE -DLIBC_CALL_ISATTY -DLIBC_CALL_FSTAT
endif

ifdef D
CDEFINES += -DDEBUG_LEVEL=$D
else
CDEFINES += -DDEBUG_LEVEL=0
endif

ifdef V
AT :=
SILENT :=
else
AT := @
SILENT := -s
endif

ifdef T
TEST=$(T)
CDEFINES += -DTEST -DTEST_ITEM=$(TEST)
endif

ifdef T
MCAL_CFG=Mcal_Cfg_UT
else
MCAL_CFG=Mcal_Cfg
endif


CINCLUDE += -I$(TOPDIR)/arch/$(ARCH)/\
            -I$(TOPDIR)/soc/\
            -I$(TOPDIR)/driver\
            -I$(TOPDIR)/driver/gic/include\
            -I$(TOPDIR)/driver/gic\
            -I$(TOPDIR)/driver/gic/common\
            -I$(TOPDIR)/driver/gic/lib\
            -I$(TOPDIR)/driver/gic/v2\
            -I$(TOPDIR)/driver/uart\
            -I$(TOPDIR)/driver/uart/sdrv_uart\
            -I$(TOPDIR)/service/\
            -I$(TOPDIR)/$(APP)\
            -I$(TOPDIR)/include\
            -I$(TOPDIR)/include/common\
            -I$(TOPDIR)/include/drivers\
            -I$(TOPDIR)/$(MCAL_CFG)\
            -I$(TOPDIR)/$(MCAL_CFG)/$(CORE)/include\
            -I$(TOPDIR)/$(MCAL_CFG)/$(CORE)\
            -I$(TOPDIR)/$(MCAL_CFG)/$(BOARD)\
            -I$(TOPDIR)/mcal/Lib_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Firewall_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Base_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Mcu_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Mcu_TS_T01D20M1I4R0/include/$(SOC)\
            -I$(TOPDIR)/mcal/Rte_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Det_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Gpt_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Port_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Dio_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Dma_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/CanIf_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/IOExp/include\
            -I$(TOPDIR)/mcal/CanTrcv/include\
            -I$(TOPDIR)/mcal/Wdg_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Pwm_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Icu_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Mailbox_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Adc_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Crypto_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Can_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Lin_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/LinIf_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Sent_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Spi_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/I2c_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Fls_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Fee_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Eth_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/EthTrcv_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/EthIf_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/RebootService/include\
            -I$(TOPDIR)/mcal/IrqM_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/mcal/Xtrg_TS_T01D20M1I4R0/include\
			-I$(TOPDIR)/mcal/Fr_TS_T01D20M1I4R0/include\
            -I$(TOPDIR)/test_suite/demo/mc/Motor_Lib_TS_T01D20M1I4R0/Inc\
            -I$(TOPDIR)/test_suite/demo/mc/Motor_Lib\
            -I$(TOPDIR)/test_suite/demo/mc\
            -I$(TOPDIR)/driver/lld\
            -I$(TOPDIR)/driver/pwm\
            -I$(TOPDIR)/driver/btm\
            -I$(TOPDIR)/driver/spi\
            -I$(TOPDIR)/driver/clk\
            -I$(TOPDIR)/driver/i2c\
            -I$(TOPDIR)/driver/sbc\
            -I$(TOPDIR)/driver/adc\
            -I$(TOPDIR)/driver/Epu\
            -I$(TOPDIR)/driver/timer\

ifdef T
CINCLUDE += -I$(TOPDIR)/$(MCAL_CFG)/$(BOARD)/include
else
CINCLUDE += -I$(TOPDIR)/$(MCAL_CFG)/$(BOARD)/output/include
endif

CINCLUDE += -I$(TOPDIR)/$(MCAL_CFG)/$(BOARD)

ifeq ($(SOC),taishan_l)
CINCLUDE += -I$(TOPDIR)/soc/taishan_l/include
else
CINCLUDE += -I$(TOPDIR)/soc/taishan/include
endif

ifeq ($(SUPPORT_AOS),true)
CINCLUDE += -I$(TOPDIR)/os/aos_wrapper/include\
            -I$(TOPDIR)/os/aos_wrapper/Source/portable/GCC/ARM_CR5

CINCLUDE += -I$(TOPDIR)/test_suite/demo/aos_wrapper_demo
endif
CINCLUDE += -I$(TOPDIR)/os/FreeRTOS/Source/include\
            -I$(TOPDIR)/os/FreeRTOS/Source/portable/GCC/ARM_CR5
