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
 * @file  Gpt_Irq_E3.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifndef GPT_IRQ_E3_H
#define GPT_IRQ_E3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
/* Version and Check Begin */
/* Version Info Begin */
#define GPT_IRQ_H_VENDOR_ID    0x8C
#define GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION    4
#define GPT_IRQ_H_AR_RELEASE_MINOR_VERSION    3
#define GPT_IRQ_H_AR_RELEASE_REVISION_VERSION 1
#define GPT_IRQ_H_SW_MAJOR_VERSION    1
#define GPT_IRQ_H_SW_MINOR_VERSION    0
#define GPT_IRQ_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IRQ_H_AR_RELEASE_MAJOR_VERSION != MCAL_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IRQ_H_AR_RELEASE_MINOR_VERSION != MCAL_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IRQ_H_AR_RELEASE_REVISION_VERSION != MCAL_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Irq_E3.h and Mcal.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IRQ_H_SW_MAJOR_VERSION != MCAL_H_SW_MAJOR_VERSION)\
    || (GPT_IRQ_H_SW_MINOR_VERSION != MCAL_H_SW_MINOR_VERSION)\
    || (GPT_IRQ_H_SW_PATCH_VERSION != MCAL_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Irq_E3.h and Mcal.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

void Gpt_Irq1_Handle( void );

void Gpt_Irq2_Handle( void );

void Gpt_Irq3_Handle( void );

void Gpt_Irq4_Handle( void );

void Gpt_Irq5_Handle( void );

void Gpt_Irq6_Handle( void );

#ifdef __cplusplus
}
#endif

#endif /* GPT_IRQ_E3_H */
