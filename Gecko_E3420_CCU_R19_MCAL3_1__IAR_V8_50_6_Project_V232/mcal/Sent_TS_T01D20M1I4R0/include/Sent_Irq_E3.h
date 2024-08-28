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
 * @file  Sent_Irq_E3.h
 * @brief Semidrive. MCAL Sent
 */


#ifndef SENT_IRQ_E3_H
#define SENT_IRQ_E3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
/* Version and Check Begin */
/* Version Info Begin */
#define SENT_IRQ_H_VENDOR_ID    0x8C
#define SENT_IRQ_H_AR_RELEASE_MAJOR_VERSION    4
#define SENT_IRQ_H_AR_RELEASE_MINOR_VERSION    3
#define SENT_IRQ_H_AR_RELEASE_REVISION_VERSION 1
#define SENT_IRQ_H_SW_MAJOR_VERSION    1
#define SENT_IRQ_H_SW_MINOR_VERSION    0
#define SENT_IRQ_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_IRQ_H_AR_RELEASE_MAJOR_VERSION != MCAL_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_IRQ_H_AR_RELEASE_MINOR_VERSION != MCAL_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_IRQ_H_AR_RELEASE_REVISION_VERSION != MCAL_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_Irq_E3.h and Mcal.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_IRQ_H_SW_MAJOR_VERSION != MCAL_H_SW_MAJOR_VERSION)\
    || (SENT_IRQ_H_SW_MINOR_VERSION != MCAL_H_SW_MINOR_VERSION)\
    || (SENT_IRQ_H_SW_PATCH_VERSION != MCAL_H_SW_PATCH_VERSION))
#error "Opps, Sent_Irq_E3.h and Mcal.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
/*NOTE: Sent module and Gpt module use same interrupt number.*/
ISR(Sent_Irq1_Handle);

ISR(Sent_Irq2_Handle);

#ifndef SEMIDRIVE_E3_LITE_SERIES
ISR(Sent_Irq3_Handle);

ISR(Sent_Irq4_Handle);
#endif

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SENT_IRQ_E3_H */
