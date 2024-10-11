include $(MKDIR)/build.mk

SUBDIRS += ${DRIVERS}

include $(MKDIR)/objs_subdir.mk
include $(MKDIR)/rules.mk

ifeq ($(ANALYZER),true)
CFG_CFLAGS += -fanalyzer
endif

MODULE_CFLAGS :=