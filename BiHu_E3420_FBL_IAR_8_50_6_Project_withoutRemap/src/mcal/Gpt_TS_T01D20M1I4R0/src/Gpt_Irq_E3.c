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
 * @file  Gpt_Irq_E3.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Irq_E3.h"
#include "Gpt.h"
/* Version and Check Begin */
/* Version Info Begin */
#define GPT_IRQ_C_VENDOR_ID    0x8C
#define GPT_IRQ_C_AR_RELEASE_MAJOR_VERSION    4
#define GPT_IRQ_C_AR_RELEASE_MINOR_VERSION    3
#define GPT_IRQ_C_AR_RELEASE_REVISION_VERSION 1
#define GPT_IRQ_C_SW_MAJOR_VERSION    1
#define GPT_IRQ_C_SW_MINOR_VERSION    0
#define GPT_IRQ_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IRQ_C_AR_RELEASE_MAJOR_VERSION != GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IRQ_C_AR_RELEASE_MINOR_VERSION != GPT_IRQ_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IRQ_C_AR_RELEASE_REVISION_VERSION != GPT_IRQ_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Irq.c and Gpt_Irq_E3.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IRQ_C_SW_MAJOR_VERSION != GPT_IRQ_H_SW_MAJOR_VERSION)\
    || (GPT_IRQ_C_SW_MINOR_VERSION != GPT_IRQ_H_SW_MINOR_VERSION)\
    || (GPT_IRQ_C_SW_PATCH_VERSION != GPT_IRQ_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Irq.c and Gpt_Irq_E3.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IRQ_C_AR_RELEASE_MAJOR_VERSION != GPT_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IRQ_C_AR_RELEASE_MINOR_VERSION != GPT_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IRQ_C_AR_RELEASE_REVISION_VERSION != GPT_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Irq.c and Gpt.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IRQ_C_SW_MAJOR_VERSION != GPT_H_SW_MAJOR_VERSION)\
    || (GPT_IRQ_C_SW_MINOR_VERSION != GPT_H_SW_MINOR_VERSION)\
    || (GPT_IRQ_C_SW_PATCH_VERSION != GPT_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Irq.c and Gpt.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_ISR(id) \
ISR(Gpt_Irq##id##_Handle)\
{\
    Gpt_Irq(GPT_INDEX_BTM##id);\
}

GPT_ISR(1)
GPT_ISR(2)
GPT_ISR(3)
GPT_ISR(4)
GPT_ISR(5)
GPT_ISR(6)

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
