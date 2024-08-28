
$(C_OBJ): %.o:%.c
	@echo "Compiling $(CURDIR)/$<"
	$(AT)$(SCAN_BUILD) $(CC) $(COMMON_CFLAGS) $(ARCH_CFLAGS) $(MODULE_CFLAGS) $(THUMBCFLAGS) $(CFG_CFLAGS)  $(CINCLUDE) $(CDEFINES) -MMD -o $@ -c $<
	# $(AT)$(SCAN_BUILD) $(CC) $(COMMON_CFLAGS) $(ARCH_CFLAGS) $(MODULE_CFLAGS) $(THUMBCFLAGS) $(CFG_CFLAGS)  $(CINCLUDE) $(CDEFINES) -MMD -o $@.i -E $<
ifdef DC
	$(AT)$(CPPCHK) $(CPPCHKFLAGS) $(CINCLUDE) $(CDEFINES) -D__GNUC__ --output-file=$<.chk $<
endif

$(S_OBJ): %.o: %.S
	@echo "Compiling $(CURDIR)/$<"
	$(AT)$(CC) $(COMMON_CFLAGS) $(ARCH_CFLAGS) $(MODULE_CFLAGS) $(CFG_CFLAGS) $(CINCLUDE) $(CDEFINES) -DASSEMBLY -o $@ -c $<
