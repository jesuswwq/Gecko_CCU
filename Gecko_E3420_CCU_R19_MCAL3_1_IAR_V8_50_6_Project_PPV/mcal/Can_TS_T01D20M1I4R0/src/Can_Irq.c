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
 * @file  Can_Irq.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Can.h"
#include "Can_IP.h"
/* Version and Check Begin */
/* Version Info Begin */
#define CAN_IRQ_C_VENDOR_ID    0x8C
#define CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION    4
#define CAN_IRQ_C_AR_RELEASE_MINOR_VERSION    3
#define CAN_IRQ_C_AR_RELEASE_REVISION_VERSION 1
#define CAN_IRQ_C_SW_MAJOR_VERSION    1
#define CAN_IRQ_C_SW_MINOR_VERSION    0
#define CAN_IRQ_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION != CAN_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IRQ_C_AR_RELEASE_MINOR_VERSION != CAN_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IRQ_C_AR_RELEASE_REVISION_VERSION != CAN_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_Irq.c and Can.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IRQ_C_SW_MAJOR_VERSION != CAN_H_SW_MAJOR_VERSION)\
    || (CAN_IRQ_C_SW_MINOR_VERSION != CAN_H_SW_MINOR_VERSION)\
    || (CAN_IRQ_C_SW_PATCH_VERSION != CAN_H_SW_PATCH_VERSION))
#error "Opps, Can_Irq.c and Can.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION != CAN_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IRQ_C_AR_RELEASE_MINOR_VERSION != CAN_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IRQ_C_AR_RELEASE_REVISION_VERSION != CAN_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_Irq.c and Can_IP.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IRQ_C_SW_MAJOR_VERSION != CAN_IP_H_SW_MAJOR_VERSION)\
    || (CAN_IRQ_C_SW_MINOR_VERSION != CAN_IP_H_SW_MINOR_VERSION)\
    || (CAN_IRQ_C_SW_PATCH_VERSION != CAN_IP_H_SW_PATCH_VERSION))
#error "Opps, Can_Irq.c and Can_IP.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

/**
 * @brief CAN1-CAN24 interrupt service routine.
 */

#define CAN_ISR(id) \
ISR(Can_Controller##id##IrqHandler)\
{\
    Can_IP_IrqHandler( id##U );\
}

CAN_ISR(0)
CAN_ISR(1)
CAN_ISR(2)
CAN_ISR(3)
CAN_ISR(4)
CAN_ISR(5)
CAN_ISR(6)
CAN_ISR(7)
CAN_ISR(8)
CAN_ISR(9)
CAN_ISR(10)
CAN_ISR(11)
CAN_ISR(12)
CAN_ISR(13)
CAN_ISR(14)
CAN_ISR(15)
CAN_ISR(16)
CAN_ISR(17)
CAN_ISR(18)
CAN_ISR(19)
CAN_ISR(20)
CAN_ISR(21)
CAN_ISR(22)
CAN_ISR(23)

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
