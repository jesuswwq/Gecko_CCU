/*
* SEMIDRIVE Copyright Statement
* Copyright (c) SEMIDRIVE. All rights reserved
*
* This software and all rights therein are owned by SEMIDRIVE, and are
* protected by copyright law and other relevant laws, regulations and
* protection. Without SEMIDRIVE's prior written consent and/or related rights,
* please do not use this software or any potion thereof in any form or by any
* means. You may not reproduce, modify or distribute this software except in
* compliance with the License. Unless required by applicable law or agreed to
* in writing, software distributed under the License is distributed on
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/
#include "asm_def.h"
#include "Memory_Map.h"
#include "lnk_sym.h"
#include "Rte_Fl_Cfg.h"


    ASM_PUBLIC reset_hdlr
    ASM_PUBLIC _start

    ASM_EXTERN  __data_start, __data_end
    ASM_EXTERN  __bss_start, __bss_end
    ASM_EXTERN  __stack_start, __stack_end
    ASM_EXTERN  __load_data_start
    ASM_EXTERN  main, arch_disable_interrupt,arch_get_cpuid
	ASM_EXTERN  VECTOR_TBL_BASE

#if defined(_IAR_C_)
    SECTION .text:CODE(2)
    ARM
#else
    .section ".text"
    .arm
#endif

    /* CR5 in svc mode once being released from reset */
_start:
reset_hdlr:
	mov r0, #0
	mov r1, #0
	mov r2, #0
	mov r3, #0
	mov r4, #0
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	mov r9, #0
	mov r10, #0
	mov r11, #0
	mov r12, #0
	mov sp, r0
	mov lr, #0
	mrs r4, cpsr	/* save the CPSR */
	msr spsr_fsxc, r4	/*load spsr with value from cpsr*/
#if 0
.in
	ldr r3,=0xcec00
        ldr r0,=0x4cf000	;source address
	ldr r1,=0x100c1000	;target address
/*
.st
        cmp r6, #1
	beq .cp
        cmp r6, #2
	beq .cl
        b .st
.cl
	ldr r2,=0
	str r2,[r0]
	add r0, #4
	subs r3, #1
        cmp r3, #0
	beq .in
        b .cl
*/
.cp:

	ldr r2,[r1]
	str r2,[r0]
	add r0, #4
	add r1, #4
	subs r3, #1
        cmp r3, #0
	beq .lp
        b .cp
.lp:

	ldr r0,=0X4EFFC
	ldr r2,=0X5A
	str r2,[r0]
        cmp r5, #0
	beq 0x4cf000
        b .lp
#endif

#ifndef EN_UNIFIED_IMAGE
	ldr r0, =__stack_end
#else
	ldr r1, =__stack_end
	bl arch_get_cpuid
	/* r11 hold the cpu id  */
	mov r11, r0
	/* cpuid * 0x4000 @ r0 */
	lsl r0, r11, #14
	/* stack size 16k */
	sub r0, r1, r0
#endif

	/* Initialize banked ARM registers */
	cps #MODE_SYS
	mov sp, r0
	mov lr, #0
    sub r0, r0, #0x2000
	cps #MODE_ABT
	mov sp, r0
	mov lr, #0
	msr spsr_fsxc, r4	/*load spsr with value from cpsr*/
    sub r0, r0, #0x100
	cps #MODE_UND
	mov sp, r0
	mov lr, #0
	msr spsr_fsxc, r4	/*load spsr with value from cpsr*/
    sub r0, r0, #0x100
	cps #MODE_IRQ
	mov sp, r0
	mov lr, #0
	msr spsr_fsxc, r4	/*load spsr with value from cpsr*/
    sub r0, r0, #0x400
	cps #MODE_FIQ
	mov r8, #0
	mov r9, #0
	mov r10, #0
	mov r12, #0
	mov sp, r0
	mov lr, #0
	msr spsr_fsxc, r4	/*load spsr with value from cpsr*/
    sub r0, r0, #0x200
	/* switch back to Supervisor mode and disable its interrupt */
	cpsid i, #MODE_SVC
	mov sp, r0

#if defined(CFG_ARCH_FPU)
	ldr r0, =0x00F00000
	mcr p15, 0, r0, c1, c0, 2	/* Enable coprocessor access in CPACR */
	ldr r2, =0x40000000
	vmsr fpexc, r2	/* Enable FPU access so that VFP registers can be initialized */
	vmov D0, r5, r6	/* r5/6 is 0 now */
	vmov D1, r5, r6
	vmov D2, r5, r6
	vmov D3, r5, r6
	vmov D4, r5, r6
	vmov D5, r5, r6
	vmov D6, r5, r6
	vmov D7, r5, r6
	vmov D8, r5, r6
	vmov D9, r5, r6
	vmov D10, r5, r6
	vmov D11, r5, r6
	vmov D12, r5, r6
	vmov D13, r5, r6
	vmov D14, r5, r6
	vmov D15, r5, r6
#endif
	mrc p15, 0, r0, c1, c0, 0 /* Read SCTLR */
	ldr r1, =0xFFFFFFF8
	and r0, r0,r1       /* disable L1 cache/alignment check/mpu, this is reset value. */
	mcr p15, 0, r0, c1, c0, 0 /* Write SCTLR */
#if defined(CFG_ARCH_DIS_BRANCH_PREDICT)
	/* Disable Branch prediction in case somehow it fetch from some
	 * memory which is not enabled yet */
	mrc p15, 0, r0, c1, c0, 1	// ACTLR
	orr r0, r0, #(0x1 << 17)	// Set RSDIS to disable return stack
	orr r0, r0, #(0x1 << 16)	// BP=10: branch always not taken and history table updates disabled
	bic r0, r0, #(0x1 << 15)
	mcr p15, 0, r0, c1, c0, 1
	isb
#endif

	mrc p15, 0, r0, c1, c0, 0	// SCTLR
	orr r0, r0, #(0x01 << 1)	// SCTLR.A
#if defined(CFG_ARCH_R7_MPU_BG_EN)
	orr r0, r0, #(0x01 << 17)	// SCTLR.BR	MPU background region enable
#endif
	mcr p15, 0, r0, c1, c0, 0
	isb
	dsb

#if defined(CFG_ARCH_LLPP_EN)
	mrc p15, 0, r0, c15, c0, 1
	tst r0, #(0x1F << 2)	/* Size Mask*/
	beq	.no_pp_present
	orr r0, r0, #1				/* Enable LLPP Normal AXI interface */
	mcr p15, 0, r0, c15, c0, 1
.no_pp_present:
#endif

#if defined(CFG_ARCH_CR5_AHB_EN)
	mrc p15, 0, r0, c15, c0, 3
	tst r0, #(0x1F << 2)	/* Size Mask*/
	beq	.no_ahb_present
	orr r0, #1				/* Enable AHB interface */
	mcr p15, 0, r0, c15, c0, 3
.no_ahb_present:
#endif

#if defined(CFG_ARCH_TCM)
	mrc p15, 0, r0, c0, c0, 2	// Read TCMTR (TCM Type Register)
	// r0: ATCM & BTCM availability
	mrc p15, 0, r0, c9, c1, 1	// Read ATCM Region Register
	// r0 now contains ATCM size in bits[6:2]
	mrc p15, 0, r0, c9, c1, 0	// Read BTCM Region Register
	// r0 now contains BTCM size in bits[6:2]
	lsr r0, r0, #2
	and r0, r0, #0x1f	// BTCM Region Register [6:2] : Size
	mov r1, #0x200
	lsl r1, r1, r0		// r1: BTCM size
	add r2, r1, r1		/* Save TCM size */
	// Write to TCMTR.size will be ignored
	ldr r0, =0x0
	add r1, r0, r1	/* r1 = BTCM_BASE + BTCM_SZ */
	orr r0, r0, #1	// Enable BTCM
	mcr p15, 0, r0, c9, c1, 0
	orr r1, r1, #1	// Enable ATCM
	mcr p15, 0, r1, c9, c1, 1
	/* clear TCM */
	mov r0, #0
	mov r4, #0
	mov r5, #0
#ifdef PROJECT_DE
	mov r6, #0
.st
	cmp r6, #1
	beq .tcm_clr_loop
	cmp r6, #2
	beq .skip_tcm_clr
	b .st
#endif
.tcm_clr_loop:
          cmp r0, #RTE_CFG_PROGRAM_FLAG_ADDR
          beq .tcm_clr_jump
#ifdef  PROJECT_APP
          ldr r5 ,=RTE_CFG_VECTOR_APP_ADDR
          cmp r0, r5
          mov r5,#0
          beq .tcm_clr_jump
#endif
#if (RTE_PARTITION_SWAP_ON == STD_ON)
          ldr r5 ,=RTE_DATA_FORC_SWAP_TCM_ADDR
          cmp r0, r5
          mov r5,#0
          beq .tcm_clr_jump
#endif 
#if (RTE_CFG_JUMP_APP_RESET_ENABLE == STD_ON)
          ldr r5 ,=RTE_CFG_JUMP_APP_ADDR
          cmp r0, r5
          mov r5,#0
          beq .tcm_clr_jump
#endif
#if (PROJECT_SPECIAL == STD_ON)
          ldr r5 ,=RTE_DATA_RESETCAUSE_TCM_ADDR
          cmp r0, r5
          mov r5,#0
          beq .tcm_clr_jump
#endif		  
	cmp r0, r2
	bhs .skip_tcm_clr
	stmia r0!, {r4-r5}
	b .tcm_clr_loop
.tcm_clr_jump:
/*
        mov r5, #RTE_CFG_PROGRAM_FLAG_ADDR
        LDR r4, [r5]
        mov r5, #0
	stmia r0!, {r4-r5}
        mov r4, #0*/
        add r0, #8
        b .tcm_clr_loop
.skip_tcm_clr:

#endif
	/* !!! linker script shall make sure __mcaldata_start/__mcalbss_start and the
	 * size (if not zero) shall be 32 bytes aligned
	 */
	/* only sf core cp load data */
	cmp r11, #0
	bne	.skip_data_cp
	ldr r0, =__load_data_start
	ldr r1, =__data_start
	ldr r2, =__data_end

	cmp r0, r1
	beq .skip_data_cp
.data_cp_loop:
	cmp r1, r2
	bhs	.skip_data_cp
	ldmia r0!, {r3-r10}
	stmia r1!, {r3-r10}
	b .data_cp_loop

.skip_data_cp:

	cmp r11, #0
	bne	.bss_clr_done
    ldr r0, =__bss_start
    ldr r1, =__bss_end
	mov r2, #0
	mov r3, #0
	mov r4, #0
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	mov r9, #0
.bss_clr_loop:
	cmp r0, r1
	bhs .bss_clr_done
 	stmia r0!, {r2-r9}
	b .bss_clr_loop

.bss_clr_done:

	/* !!! linker script shall make sure __stack_start and size shall be 8
	 * bytes aligned
	 */
	cmp r11, #0
	bne	.stack_clr_done
#if defined(CFG_SOC_RAM_ECC)
	ldr r0, =__stack_start
	ldr r1, =__stack_end
	ldr r2, =0x5AA5F00F
	ldr r3, =0xA55A0FF0
	mov r4, r2
	mov r5, r3
	mov r6, r2
	mov r7, r3
	mov r8, r2
	mov r9, r3
stack_clr_loop:
    stmia r0!, {r2-r9}
	cmp r0, r1
	blo	stack_clr_loop
#endif

.stack_clr_done:

    cps #MODE_SYS

	bl arch_disable_interrupt

	mov r0, #0
	mov r1, #0
	bl main

loop:
      	b loop

#if defined(_IAR_C_)
    END
#endif
