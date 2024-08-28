OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY
{
    FLASH  (r)  : ORIGIN = [!"num:inttohex(./LinkerFileConfig/FlashBase)"!], LENGTH = [!"num:inttohex(./LinkerFileConfig/FlashSize)"!]
    IRAM   (rw) : ORIGIN = 0x404000,  LENGTH = [!"num:inttohex(num:i(node:value(./LinkerFileConfig/IramSize)) * 1024 - 16384)"!]
    TCM    (rw) : ORIGIN = 0x40,   LENGTH = 0xFFC0
}

SECTIONS
{
    /*vector */
    .start_text : {
        __vector_tbl_start = .;
        KEEP(*(.text.vector))
    } > [!"./LinkerFileConfig/ROM_LOCATION"!]

    .iram_func : ALIGN(32) {
        __iram_func_start = .;
        /*
        *autosar_*.o      (.text .text*)
        *portASM.o        (.text .text*)
        *port_c.o         (.text .text*)
        *list.o           (.text .text*)
        *heap_3.o         (.text .text*)
        */
        . = ALIGN(32);
        __iram_func_end   = .;
    } > IRAM AT > [!"./LinkerFileConfig/ROM_LOCATION"!]
    __iram_func_load_addr = LOADADDR(.iram_func);

    .tcm_func : ALIGN(32) {
        __tcm_func_start = .;
        KEEP(*(.text.func_safety))
        /*
        *exception.o        (.text .text*)
        *exception_s.o      (.text .text*)
        *interrupt_hldr.o   (.text .text*)
        *plat_interrupt.o   (.text .text*)
        *arm_gicv2.o        (.text .text*)
        *gicv2_main.o       (.text .text*)
        *gicv2_helpers.o    (.text .text*)
        *gic_common.o       (.text .text*)
        */
        __tcm_func_end   = .;
    } > TCM AT > [!"./LinkerFileConfig/ROM_LOCATION"!]
    __tcm_func_load_addr = LOADADDR(.tcm_func);

    .iram_data : ALIGN(32) {
        __iram_data_start = .;
        *(.inj_err_iram )
        __iram_data_end   = .;
    } > IRAM AT > [!"./LinkerFileConfig/ROM_LOCATION"!]
    __iram_data_load_addr = LOADADDR(.iram_data);

    .tcm_data : ALIGN(32) {
        __tcm_data_start = .;
        *(.inj_err_tcm )
        __tcm_data_end   = .;
    } > TCM AT > [!"./LinkerFileConfig/ROM_LOCATION"!]
    __tcm_data_load_addr = LOADADDR(.tcm_data);

    .iram_bss (NOLOAD) : ALIGN(32) {
        __iram_bss_start = .;
        __iram_bss_end   = .;
    } > IRAM

    .tcm_bss (NOLOAD) : ALIGN(32) {
        __tcm_bss_start = .;
        __tcm_bss_end   = .;
    } > TCM

    .text : {
        *(.text*)
    } > [!"./LinkerFileConfig/ROM_LOCATION"!]

    TEST_SECTION : ALIGN(8) {
        __start_TEST_SECTION = .;
        KEEP(*(TEST_SECTION*))
        __stop_TEST_SECTION = .;
    } > [!"./LinkerFileConfig/ROM_LOCATION"!]

    shell_cmd : ALIGN(8) {
        __start_shell_cmd = .;
        KEEP(*(shell_cmd*))
        __stop_shell_cmd = .;
    } > [!"./LinkerFileConfig/ROM_LOCATION"!]

    .rodata : ALIGN(4) {
        __rodata_start = .;
        *(.rodata .rodata.*)
    } > [!"./LinkerFileConfig/ROM_LOCATION"!]

    .data : ALIGN(32) {
        __data_start = .;
        *(.data .data.*)
        . = ALIGN(32);
        __data_end = .;
    } > IRAM AT > [!"./LinkerFileConfig/ROM_LOCATION"!]
    __load_data_start = LOADADDR(.data);

    .bss (NOLOAD): ALIGN(32) {
        __bss_start = .;
        KEEP(*(.bss.prebss.*))
        *(.bss .bss.*)
        *(.gnu.linkonce.b.*)
        *(COMMON)
        . = ALIGN(32);
        __bss_end = .;
        __heap_start = .;
    } > IRAM

    .dma_buffer : ALIGN(64K) {
        __dma_buffer_start = .;
        *(.dma_buffer)
        . = ALIGN(64K);
        __dma_buffer_end   = .;
    } > IRAM

    .stack (ORIGIN(IRAM) + LENGTH(IRAM) - [!"num:inttohex(./LinkerFileConfig/StackSize)"!]) : ALIGN(32) {
        __heap_end = .;
        __stack_start = .;
        . += [!"num:inttohex(./LinkerFileConfig/StackSize)"!];
        . = ALIGN(32);
        __stack_end = .;
    }

    .EPU_LB 0x1210000 : ALIGN(32) {
        __epu_ram_start = .;
        KEEP(*(.EPU_LB))
        . = ALIGN(32);
        __epu_ram_end = .;
    }
    __load_epu_data_start = LOADADDR(.EPU_LB);

    /* Strip unnecessary stuff */
    /DISCARD/ : { *(.comment .note .eh_frame) }
}
