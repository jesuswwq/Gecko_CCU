OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY
{
    FLASH  (r) : ORIGIN = %FLASH_START%, LENGTH = %FLASH_LENGTH%
    IRAM  (rw) : ORIGIN = %IRAM_START%,  LENGTH = %IRAM_LENGTH%
    TCM   (rw) : ORIGIN = %TCM_START%,   LENGTH = %TCM_LENGTH%
}

SECTIONS
{
    /*vector */
    .start_text : {
        __vector_tbl_start = .;
        KEEP(*(.text.vector))
    } > %MEM_TEXT%

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
    } > IRAM AT > %MEM_TEXT%
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
    } > TCM AT > %MEM_TEXT%
    __tcm_func_load_addr = LOADADDR(.tcm_func);

    .iram_data : ALIGN(32) {
        __iram_data_start = .;
        *(.inj_err_iram )
        __iram_data_end   = .;
    } > IRAM AT > %MEM_TEXT%
    __iram_data_load_addr = LOADADDR(.iram_data);

    .tcm_data : ALIGN(32) {
        __tcm_data_start = .;
        *(.inj_err_tcm )
        __tcm_data_end   = .;
    } > TCM AT > %MEM_TEXT%
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
    } > %MEM_TEXT%

    TEST_SECTION : ALIGN(8) {
        __start_TEST_SECTION = .;
        KEEP(*(TEST_SECTION*))
        __stop_TEST_SECTION = .;
    } > %MEM_TEXT%

    shell_cmd : ALIGN(8) {
        __start_shell_cmd = .;
        KEEP(*(shell_cmd*))
        __stop_shell_cmd = .;
    } > %MEM_TEXT%

     .init_array :
    {
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } > %MEM_TEXT%

    .rodata : ALIGN(4) {
        __rodata_start = .;
        *(.rodata .rodata.*)
    } > %MEM_TEXT%

    .data : ALIGN(32) {
        __data_start = .;
        *(.data .data.*)
        . = ALIGN(32);
        __data_end = .;
    } > %MEM_DATA% AT > %MEM_TEXT%
    __load_data_start = LOADADDR(.data);

    .bss (NOLOAD): ALIGN(32) {
        __bss_start = .;
        KEEP(*(.bss.prebss.*))
        *(.bss .bss.*)
        *(.gnu.linkonce.b.*)
        *(COMMON)
        . = ALIGN(32);
        __bss_end = .;
    } > %MEM_TCM%

    .dma_buffer : ALIGN(%DMA_SIZE%) {
        __dma_buffer_start = .;
        *(.dma_buffer)
        . = ALIGN(%DMA_SIZE%);
        __dma_buffer_end   = .;
        __heap_start = .;
    } > IRAM

    .stack (ORIGIN(%MEM_DATA%) + LENGTH(%MEM_DATA%) - %STACK_SZ%) : ALIGN(32) {
        __heap_end = .;
        __stack_start = .;
        . += %STACK_SZ%;
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
