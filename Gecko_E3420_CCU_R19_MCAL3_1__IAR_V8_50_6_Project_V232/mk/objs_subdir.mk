
C_SRC ?= $(wildcard *.c)
C_ARM_SRC ?=
S_SRC ?= $(wildcard *.S)
s_SRC ?= $(wildcard *.s)

C_OBJ := $(C_SRC:.c=.o)
C_ARM_OBJ := $(C_ARM_SRC:.c=.o)
S_OBJ := $(S_SRC:.S=.o)
s_OBJ := $(s_SRC:.s=.o)

DEP := $(C_OBJ:.o=.d)
DEP += $(C_ARM_OBJ:.o=.d)

OBJS := $(C_OBJ) $(S_OBJ) $(s_OBJ) $(C_ARM_OBJ)

always: $(OBJS) $(SUBDIRS)

$(SUBDIRS):
	$(AT)echo "Enter $(CURDIR)/$@"
	$(AT)make $(SILENT) -C $@

.PHONY: always $(SUBDIRS) clean

clean:
	-rm $(OBJS) -rf

-include $(DEP)
