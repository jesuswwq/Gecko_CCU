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

#ifdef __cplusplus
extern "C" {
#endif

#include <mini_libc.h>
#include <arch.h>
#include "Mcu.h"
#include "Port.h"
#include "irq_num.h"
#include "Mcu_Mpu.h"
#include "irq.h"
#include "IrqM_Cfg.h"
#include "Mcu.h"
#include "Mcu_Soc.h"
#include "e3_kick_core.h"
#include "Gpt.h"
#include "mbox.h"
#include "SchM_Base.h"
#include "Gpt_Irq_E3.h"
#include "lnk_sym.h"
#include "debug.h"
#include "Rte_Inc.h"



char *board_str __attribute__((weak)) = "E3_board";
extern uint32 board_init(void);


extern void mpu_init(void);
extern unsigned long VECTOR_TBL_BASE[];

 void c_tcm_section_init(void)
{
    if (((uint32)__tcm_func_end - (uint32)__tcm_func_start) > 0u) {
        mini_memcpy_s((void *)__tcm_func_start, (void *)__tcm_func_load_addr,
                      (uint32)__tcm_func_end - (uint32)__tcm_func_start);
    }

    if (((uint32)__tcm_data_end - (uint32)__tcm_data_start) > 0u) {
        mini_memcpy_s((void *)__tcm_data_start, (void *)__tcm_data_load_addr,
                      (uint32)__tcm_data_end - (uint32)__tcm_data_start);
    }

    if (((uint32)__tcm_bss_end - (uint32)__tcm_bss_start) > 0u) {
        mini_memclr_s((void *)__tcm_bss_start, (uint32)__tcm_bss_end - (uint32)__tcm_bss_start);
    }
}
 void c_section_init(void)
{
    if (((uint32)__iram_func_end - (uint32)__iram_func_start) > 0u) {
        mini_memcpy_s((void *)__iram_func_start, (void *)__iram_func_load_addr,
                      (uint32)__iram_func_end - (uint32)__iram_func_start);
        arch_clean_invalidate_cache_range((void *)__iram_func_start,
                                          (uint32)__iram_func_end - (uint32)__iram_func_start);
    }

    if (((uint32)__iram_data_end - (uint32)__iram_data_start) > 0u) {
        mini_memcpy_s((void *)__iram_data_start, (void *)__iram_data_load_addr,
                      (uint32)__iram_data_end - (uint32)__iram_data_start);
        arch_clean_invalidate_cache_range((void *)__iram_data_start,
                                          (uint32)__iram_data_end - (uint32)__iram_data_start);
    }

    if (((uint32)__iram_bss_end - (uint32)__iram_bss_start) > 0u) {
        mini_memclr_s((void *)__iram_bss_start, (uint32)__iram_bss_end - (uint32)__iram_bss_start);
        arch_clean_invalidate_cache_range((void *)__iram_bss_start,
                                          (uint32)__iram_bss_end - (uint32)__iram_bss_start);
    }
#if defined PROJECT_FLS || RTE_PARTITION_SWAP_ON == STD_ON
    if (((uint32)__data_end - (uint32)__data_start) > 0u) {
        mini_memcpy_s((void *)__data_start, (void *)__load_data_start,
                      (uint32)__data_end - (uint32)__data_start);
        arch_clean_invalidate_cache_range((void *)__data_start,
                                          (uint32)__data_end - (uint32)__data_start);
    }
#endif
#if defined(_IAR_C_) || defined(_GHS_C_)

    if (((uint32)__mcalbss_end - (uint32)__mcalbss_start) > 0u) {
        mini_memclr_s((void *)__mcalbss_start, (uint32)__mcalbss_end - (uint32)__mcalbss_start);
        arch_clean_invalidate_cache_range((void *)__mcalbss_start,
                                          (uint32)__mcalbss_end - (uint32)__mcalbss_start);
    }

    if (((uint32)__mcaldata_end - (uint32)__mcaldata_start) > 0u) {
        mini_memcpy_s((void *)__mcaldata_start, (void *)__load_mcaldata_start,
                      (uint32)__mcaldata_end - (uint32)__mcaldata_start);
        arch_clean_invalidate_cache_range((void *)__mcaldata_start,
                                          (uint32)__mcaldata_end - (uint32)__mcaldata_start);
    }

#endif
}

#if (RTE_PARTITION_SWAP_ON == STD_ON)
#include "Fls.h"
#include "taishan_reset_drv.h"
extern void c_tcm_section_init(void);
extern void c_section_init(void);
extern reset_ctl_t g_rstgen_saf;
extern reset_ctl_t g_rstgen_ap;
extern sint32 taishan_reset_init(reset_ctl_t *rst_ctl, taishan_reset_ctl_t *taishan_rst_ctl);
extern taishan_reset_ctl_t taishan_rstgen_sf_dev;
extern taishan_reset_ctl_t taishan_rstgen_ap_dev;
boolean FlashInitSwap(void)
{
    c_tcm_section_init();
    c_section_init();

    taishan_reset_init(&g_rstgen_saf, &taishan_rstgen_sf_dev);
    taishan_reset_init(&g_rstgen_ap, &taishan_rstgen_ap_dev);
    Fls_Init(&Fls_ConfigData);
    return TRUE;
}
#endif

int main(int argc, char *argv[])
{
#if defined PROJECT_FLS
    Rte_FlashInit();
    Rte_FlsTest();
    while(1);
#else
#ifndef PROJECT_APP
#if (RTE_CFG_JUMP_APP_RESET_ENABLE == STD_ON)
    Rte_ResetJump_Check();
#endif    
#endif
    uint8 CoreId = Mcu_GetCoreID();
#if ((defined PROJECT_APP) && (RTE_PARTITION_SWAP_ON == STD_ON))
    uint32 remapVector = (*(uint64 *)RTE_CFG_VECTOR_APP_ADDR);
    if (((unsigned long)remapVector == (unsigned long)RTE_CFG_APP_START_FLASH_ADDR)
    || ((unsigned long)remapVector ==
    (unsigned long)(RTE_CFG_APP_START_FLASH_ADDR + RTE_CFG_APP_START_FLASH_OFFSET)))
    {
        if ((*(uint64 *)0u) == 0u)
        {
            /* copy without dependency to libc */
            uint64 *p_dst = (uint64 *)0x0;
            uint64 *p_src = (uint64 *)remapVector;

            for (int i = 0; i < 8; i++)
            {
                *p_dst++ = *p_src++;
            }
        }
    }

    (*(uint64 *)RTE_CFG_VECTOR_APP_ADDR) = 0u;
#ifdef PROJECT_DE
    volatile uint8 i = 1;
    while(i);
#endif
#else
    if ((unsigned long)VECTOR_TBL_BASE != (unsigned long)0x0) {
        /* copy without dependency to libc */
        uint64 *p_dst = (uint64 *)0x0;
        uint64 *p_src = (uint64 *)VECTOR_TBL_BASE;

        for (int i = 0; i < 8; i++) {
            *p_dst++ = *p_src++;
        }
    }
#endif
    mpu_init();
    arch_enable_cache(ICACHE | DCACHE);
    SchM_EXCLUSIVE_AREA_INIT();
    if (CoreId == CPU_ID_SF) {
        c_section_init();
    }
    c_tcm_section_init();
    if (CoreId == CPU_ID_SF) {
        Mcu_Init(&Mcu_Cfg);
        Mcu_InitClock((Mcu_ClockType)0);
        Port_Init(&Port_Cfg);
    }

    Mcu_PmuCounterInit();
    irq_initialize(VIC1_BASE, IRQ_MAX_INTR_NUM);

    if (CoreId == CPU_ID_SF) {

        semphore_init(MAILBOX);
        //board_init();
    }
    extern void board_dma_init(void);
    board_dma_init();

    /* interrupt */
    //IrqM_Init();
    if (CoreId == CPU_ID_SF) {
        //soc_kick_core(KICK_CR5_SP, (uint32)VECTOR_TBL_BASE);
        //soc_kick_core(KICK_CR5_SX, (uint32)VECTOR_TBL_BASE);
    }

    /* ECU Initialize */
    extern void Appl_EcuStartup(void);
    (void)Appl_EcuStartup();

    for(;;)
    {
extern void Appl_MainFunction(void) ;

        Appl_MainFunction();
#ifndef PROJECT_APP
extern void FL_MainFunction(void);
        FL_MainFunction();
#endif
    }
#endif
}

#ifdef __cplusplus
}
#endif
