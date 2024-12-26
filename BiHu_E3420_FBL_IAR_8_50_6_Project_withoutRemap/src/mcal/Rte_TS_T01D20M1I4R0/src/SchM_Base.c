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
/**
 * @file  SchM_Base.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Rte Emulation
 */
#include "SchM_Base.h"
#include <arch_irq.h>

#ifdef EN_UNIFIED_IMAGE
#include "Mcu.h"
#include "cdefs.h"
static volatile  uint32 Critical_NestedCount[5]   _SECTION(.dma_buffer);
static volatile  uint32 Critical_SavedCPSRValue[5] _SECTION(.dma_buffer);
#else
static volatile  uint32 Critical_NestedCount[1];
static volatile  uint32 Critical_SavedCPSRValue[1];
#endif


FUNC(void, RTE_CODE) SchM_EXCLUSIVE_AREA_INIT(void)
{
#ifdef EN_UNIFIED_IMAGE
    uint8 coreid = arch_get_cpuid();
#else
    uint8 coreid = 0;
#endif
    Critical_NestedCount[coreid] = 0;
}

/**
 * @brief Enter/Exit routines for Critical Area.
 */
FUNC(void, RTE_CODE) SchM_Enter_EXCLUSIVE_AREA(void)
{
#ifdef EN_UNIFIED_IMAGE
    uint8 coreid = arch_get_cpuid();
#else
    uint8 coreid = 0;
#endif
    uint32 cpsr = arch_irq_save();
    Critical_NestedCount[coreid]++;
    if (Critical_NestedCount[coreid] == 1U){
        Critical_SavedCPSRValue[coreid] = cpsr;
    }
}
/**
 * @brief Enter/Exit routines for Critical Area.
 */
FUNC(void, RTE_CODE) SchM_Exit_EXCLUSIVE_AREA(void)
{
#ifdef EN_UNIFIED_IMAGE
    uint8 coreid = arch_get_cpuid();
#else
    uint8 coreid = 0;
#endif
    arch_irq_disable();
    if(Critical_NestedCount[coreid]){
        Critical_NestedCount[coreid]--;
        if(Critical_NestedCount[coreid] == 0U){
            if(!prev_irq_is_masked(Critical_SavedCPSRValue[coreid])){
                arch_irq_enable();
            }
        }
    }
}
