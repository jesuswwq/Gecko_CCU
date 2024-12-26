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
 * @file  Wdg_Irq.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdg_Irq.h"
#include "Wdg.h"
/* Version and Check Begin */
/* Version Info Begin */
#define WDG_IRQ_C_VENDOR_ID    0x8C
#define WDG_IRQ_C_AR_RELEASE_MAJOR_VERSION    4
#define WDG_IRQ_C_AR_RELEASE_MINOR_VERSION    3
#define WDG_IRQ_C_AR_RELEASE_REVISION_VERSION 1
#define WDG_IRQ_C_SW_MAJOR_VERSION    1
#define WDG_IRQ_C_SW_MINOR_VERSION    0
#define WDG_IRQ_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_IRQ_C_AR_RELEASE_MAJOR_VERSION != WDG_IRQ_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_IRQ_C_AR_RELEASE_MINOR_VERSION != WDG_IRQ_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_IRQ_C_AR_RELEASE_REVISION_VERSION != WDG_IRQ_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg_Irq.c and Wdg_Irq.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_IRQ_C_SW_MAJOR_VERSION != WDG_IRQ_H_SW_MAJOR_VERSION)\
    || (WDG_IRQ_C_SW_MINOR_VERSION != WDG_IRQ_H_SW_MINOR_VERSION)\
    || (WDG_IRQ_C_SW_PATCH_VERSION != WDG_IRQ_H_SW_PATCH_VERSION))
#error "Opps, Wdg_Irq.c and Wdg_Irq.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_IRQ_C_AR_RELEASE_MAJOR_VERSION != WDG_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_IRQ_C_AR_RELEASE_MINOR_VERSION != WDG_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_IRQ_C_AR_RELEASE_REVISION_VERSION != WDG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg_Irq.c and Wdg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_IRQ_C_SW_MAJOR_VERSION != WDG_H_SW_MAJOR_VERSION)\
    || (WDG_IRQ_C_SW_MINOR_VERSION != WDG_H_SW_MINOR_VERSION)\
    || (WDG_IRQ_C_SW_PATCH_VERSION != WDG_H_SW_PATCH_VERSION))
#error "Opps, Wdg_Irq.c and Wdg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

#define WDG_ISR(id) \
ISR(Wdg_Isr_Instance##id)\
{\
    Wdg_CommonInterrupt(((uint8)id##U) - ((uint8)1));\
}

WDG_ISR(1)
WDG_ISR(2)
WDG_ISR(3)
WDG_ISR(4)
WDG_ISR(5)
WDG_ISR(6)
WDG_ISR(8)

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif
