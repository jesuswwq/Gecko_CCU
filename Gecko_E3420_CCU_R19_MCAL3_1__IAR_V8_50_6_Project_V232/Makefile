TOPDIR := $(shell pwd)
BUILDDIR := $(TOPDIR)/build
MKDIR := $(TOPDIR)/mk
CFGDIR := $(TOPDIR)/mk/cfg
BIN2HEX := $(TOPDIR)/tools/bin2hex
GOIL := $(TOPDIR)/tools/internal/goil/makefile-unix/goil

$(info TOPDIR=$(TOPDIR))

export TOPDIR
export BUILDDIR
export MKDIR
export CFGDIR
export GOIL

include $(MKDIR)/build.mk
BINDIR := $(BUILDDIR)/$(BOARD)
ELF := $(BINDIR)/$(BINARY_NAME)
LINK_SCRIPT := $(BINDIR)/lnk.ld

SUBDIRS := arch mcal driver service soc ${APP} 
ifdef T
SUBDIRS += Mcal_Cfg_UT
else
SUBDIRS += Mcal_Cfg
endif
ifdef USED_OS
ifeq ($(SUPPORT_AOS),true)
SUBDIRS +=os/aos_wrapper
endif
SUBDIRS += os/$(USED_OS)
endif

ifneq ($(SOC),host)
LINKER_SCRIPT=$(BINDIR)/lnk.ld
LINKER_SCRTIP_IN=arch/$(ARCH)/lnk.in.ld
ifneq ($(TCH),armcc)
LDFLAGS += -T $(LINKER_SCRIPT) -Wl,-Map=$(ELF).map
else
LINKER_SCRTIP_IN=arch/$(ARCH)/lnk.in.scat
LDFLAGS += --entry=_start --scatter=$(LINKER_SCRIPT) --verbose --callgraph --callgraph_file=$(ELF).callgraph
LDFLAGS += --info=sizes,totals,stack,unused --map --list $(ELF).list
endif
endif

ifdef COV
LDFLAGS += -lgcov --coverage
endif

ALL_OBJS = $(sort $(shell find -name "*.o"))

define gcc_elf2bin
	$(AT)$(OBJCOPY) -O binary $(1) -j .start_text  -j .text -j .rodata -j .data\
		-j TEST_SECTION -j shell_cmd -j .iram_func -j .tcm_func \
		-j .iram_data -j .tcm_data -j .EPU_LB --gap-fill 0xFF $(1).bin
endef

define armcc_elf2bin
	fromelf --bin --bincombined --output $(1).bin $(1)
endef

ifneq (${TCH},armcc)
ELF2BIN = gcc_elf2bin
else
ELF2BIN = armcc_elf2bin
endif

define bin2hex_cmdstring
	$(BIN2HEX) rom if=$(ELF).bin width=8 col=1 fmt=hex split=2 part=$(ROM_PART)
endef

BIN2HEX_CMD = bin2hex_cmdstring

ifdef RAPID_STUDIO
define WINDOWS
echo "define WINDOWS"
endef
endif

ifdef WINDOWS
ifeq (${CORE},sec)
SIGN_CMD=$(TOPDIR)/tools/sign_tool/run_sign_sec_windows
else
ifeq (${CORE},safe)
SIGN_CMD=$(TOPDIR)/tools/sign_tool/run_sign_safe_windows
else
SIGN_CMD=echo
endif
endif
else
ifeq (${CORE},sec)
SIGN_CMD=$(TOPDIR)/tools/sign_tool/run_sign_sec
else
ifeq (${CORE},safe)
SIGN_CMD=$(TOPDIR)/tools/sign_tool/run_sign_safe
else
SIGN_CMD=echo
endif
endif
endif

ifeq (${MEM_TEXT},DDR)
ROM_BASE=$(DDR_START)
else ifeq (${MEM_TEXT},IRAM)
ROM_BASE=$(IRAM_START)
else ifeq (${MEM_TEXT},FLASH)
ROM_BASE=$(FLASH_START)
else ifeq (${MEM_TEXT},TCM)
ROM_BASE=$(TCM_START)
else
ROM_BASE=0
endif

ifeq (${BOARD},$(filter ${BOARD},g9_ref_safe g9x_ref_demo II4_safe))
PACK_CMD=$(TOPDIR)/tools/sign_tool/genetate_opsi_pac.sh
else
PACK_CMD=echo
endif

ifdef PL
    define pack_peerloaded_img
        echo "packing safety image..."
        dd of=$(1) if=$(2) seek=256 bs=1024
    endef
else
    define pack_peerloaded_img
        echo "pack_peerloaded_img: nothing to do..."
    endef
endif

.PHONY: rom msg_start mk_folders clean_all cscope help clean $(SUBDIRS) $(LINKER_SCRIPT)

bin: elf
	@echo "To generate bin..."
	$(AT) $(call ${ELF2BIN},${ELF})
ifdef MC_OS
	$(AT) $(call pack_peerloaded_img,${ELF}.bin,build/safe_jumper/safe_jumper.bin.signed.rsa1024)
else
	$(AT) $(call pack_peerloaded_img,${ELF}.bin,build/$(subst sec,safe,$(BOARD))/$(subst sec,safe,$(BOARD))_mcal_testsuite.elf.bin.signed.rsa1024)
endif
	@echo "To sign bin..." ${SIGN_CMD}
	$(AT) ${SIGN_CMD} ${ELF}.bin  $(ROM_BASE)
	@echo "To package DIL&bin..." ${PACK_CMD} ${BOARD}
	$(AT) ${PACK_CMD} ${BOARD}
ifdef RAPID_STUDIO
	$(AT) cp tools/bin/stepstone.bin build/$(BOARD)/stepstone.bin
	$(AT) dd if=build/$(BOARD)/$(BOARD)_mcal_testsuite.elf.bin.signed.rsa1024 of=build/$(BOARD)/stepstone.bin seek=256 bs=1024
	$(AT) mv build/$(BOARD)/stepstone.bin build/$(BOARD)/$(BOARD)_mcal_testsuite.pl.img
	$(AT) tools/sign_tool/run_sign_sec_windows build/$(BOARD)/$(BOARD)_mcal_testsuite.pl.img
	$(AT) mkdir -p rapid_studio_output
	$(AT) mv build/$(BOARD)/$(BOARD)_mcal_testsuite.pl.img.signed.rsa1024 rapid_studio_output
	$(AT) rm build/$(BOARD)/stepstone.bin -rf
endif

hex: bin
	@echo "To generate hex..."
	$(AT) $(call ${BIN2HEX_CMD})

elf: msg_start mk_folders $(SUBDIRS) $(LINKER_SCRIPT)
	@echo "$(LINKER_SCRIPT)"
	@echo "To link objs..."
	$(LD) $(ALL_OBJS)  $(LDFLAGS) $(LIBS) $(LIB_CFILES) $(LIB_HDRs) -lm -o $(ELF)
	$(AT) find -name "*.c.chk" | xargs cat >$(ELF).cppcheck.chk
	$(AT) find -name "*.c.chk" | xargs rm -rf

run: elf
	@echo "To run $(ELF)"
	@$(ELF)

msg_start:
	@echo "To build ${ELF}"

mk_folders:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BINDIR)

$(SUBDIRS):
	$(AT)echo "Enter $(CURDIR)/$@"
	$(AT)make $(SILENT) -C $@

$(LINKER_SCRIPT): $(LINKER_SCRTIP_IN)
	@echo "To generate link script..."
	$(AT) -rm $@ -rf
	$(AT)sed "s/%MEM_TCM%/$(MEM_TCM)/g; s/%DMA_SIZE%/$(DMA_SIZE)/g; s/%FLASH_START%/$(FLASH_START)/g; s/%FLASH_LENGTH%/$(FLASH_LENGTH)/g; s/%IRAM_START%/$(IRAM_START)/g; s/%IRAM_LENGTH%/$(IRAM_LENGTH)/g; s/%TCM_START%/$(TCM_START)/g; s/%TCM_LENGTH%/$(TCM_LENGTH)/g; s/%DDR_START%/$(DDR_START)/g; s/%DDR_LENGTH%/$(DDR_LENGTH)/g; s/%MEM_TEXT%/$(MEM_TEXT)/g; s/%MEM_DATA%/$(MEM_DATA)/g; s/%STACK_SZ%/$(STACK_SZ)/g;" < $< > $@

cscope:
	@echo "To build CSCOPE..."
	@find ${TOPDIR} -name "*.[chsS]" > cscope.files
	@cscope -b -q -k

clean:
	find -L -name "*.[odi]" | xargs rm -rf
	find -L -name "*.gc*" | xargs rm -rf
	find -L -name "*.c.orig" | xargs rm -rf

clean_all: clean
	-rm $(BUILDDIR) -rf

help:
	@echo "Usage: "
	@echo " make CFG=[cfg] [D=1] [T=xxx] [COV=1] [PL=1] [RAPID_STUDIO=1] [USED_OS=xxx] mk_tgt"
	@echo "     CFG        g9_ref_safe/host/, etc. See mk/cfg folder"
	@echo "     D          if provisioned, debug version will be built"
	@echo "     COV        build for coverage (gcov), for SOC=host only"
	@echo "     PL         to peer-load safety image"
	@echo "     RAPID_STUDIO   only for SDRapidStudio project"
	@echo "     USED_OS         the os to be build into, so far FreeRTOS only"
	@echo "     mk_tgt     the target to be 'make'"
	@echo "                    elf/bin/hex   to specify the output file desired"
	@echo "	                   run           clean, make then run elf file. for SOC=host only"
	@echo " To clean the build, run: make clean_all"
	@echo " To create cscope files, run: make cscope"
