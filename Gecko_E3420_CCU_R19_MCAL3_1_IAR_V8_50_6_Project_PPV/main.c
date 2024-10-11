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
#include "uart/uart.h"
#include "Mcu.h"
#include "shell/shell.h"
//#include "e3_kick_core.h"
#include "SchM_Base.h"
#include "lnk_sym.h"
#include "debug.h"
#include "EcuM.h"
#include "EcuM_Internal.h"
#include "Port.h"
#include "Lin.h"
#include "Adc.h"
#include "Spi.h"
#include "vPortTaskUsersFPU.h"
#include "Mcu_Extend.h"

char *board_str __attribute__((weak)) = "E3_board";
extern void mpu_init(void);
extern unsigned long VECTOR_TBL_BASE[];


static void c_tcm_section_init(void)
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
static void c_section_init(void)
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
        if (((uint32)__dma_buffer_end - (uint32)__dma_buffer_start) > 0u) {
        mini_memclr_s((void *)__dma_buffer_start, (uint32)__dma_buffer_end - (uint32)__dma_buffer_start);
        arch_clean_invalidate_cache_range((void *)__dma_buffer_start,
                                          (uint32)__dma_buffer_end - (uint32)__dma_buffer_start);
    }

    if ((__os_global_end - __os_global_start) > 0u) {
        mini_memclr_s((void *)__os_global_start, (uint32)__os_global_end - (uint32)__os_global_start);
        arch_clean_invalidate_cache_range((void *)__os_global_start, (uint32)__os_global_end - (uint32)__os_global_start);
    }

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

int main(int argc, char *argv[])
{
    uint8 CoreId = Mcu_GetCoreID();
    //P2CONST(EcuM_GenBSWPbCfgType, AUTOMATIC, CANIF_APPL_DATA) pbCfg = EcuM_ConfigPtr->modulePBCfg;
#ifndef REMAP_USED  
    if ((unsigned long)VECTOR_TBL_BASE != (unsigned long)0x0) {
        /* copy without dependency to libc */
        uint64 *p_dst = (uint64 *)0x0;
        uint64 *p_src = (uint64 *)VECTOR_TBL_BASE;

        for (int i = 0; i < 8; i++) {
            *p_dst++ = *p_src++;
        }
    }
#else
    uint32 remapVector = (*(uint64 *)0x10010);
    if (((unsigned long)remapVector == (unsigned long)(0x101C0000))
    || ((unsigned long)remapVector == (unsigned long)(0x108c0000)))
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
 
    (*(uint64 *)0x10010) = 0u;      
#endif
    mpu_init();
    arch_enable_cache(ICACHE | DCACHE);
    vPortTaskUsesFPU();
    SchM_EXCLUSIVE_AREA_INIT();
    if (CoreId == CPU_ID_SF) {
        c_section_init();
    }
    c_tcm_section_init();
    if (CoreId == CPU_ID_SF) {
        //Mcu_Init(pbCfg->mcuPbCfg);
        Mcu_Init(&Mcu_Cfg);
        Mcu_InitClock((Mcu_ClockType)0);
        //Mcu_PmuCounterInit();
        semphore_init(MAILBOX);
    }
    if (CoreId == CPU_ID_SF) {
    //    Mcu_SocKickCore(KICK_CR5_SX0, (uint32)VECTOR_TBL_BASE);
    //    Mcu_SocKickCore(KICK_CR5_SX1, (uint32)VECTOR_TBL_BASE);
    }
    EcuM_Init();
    return 0;
}

#ifdef __cplusplus
}
#endif
