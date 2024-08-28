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
 * @file  Sent.h
 * @brief Semidrive. MCAL Sent
 */


#ifndef SENT_H
#define SENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Sent_Ip_E3.h"

/* Version and Check Begin */
/* Version Info Begin */
#define SENT_H_VENDOR_ID    0x8C
#define SENT_H_AR_RELEASE_MAJOR_VERSION    4
#define SENT_H_AR_RELEASE_MINOR_VERSION    3
#define SENT_H_AR_RELEASE_REVISION_VERSION 1
#define SENT_H_SW_MAJOR_VERSION    1
#define SENT_H_SW_MINOR_VERSION    0
#define SENT_H_SW_PATCH_VERSION    0

/* Version Info End */
#define SENT_SET_ACTIVATION_CONDITION_ID (0x03u)
/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_H_AR_RELEASE_MAJOR_VERSION != SENT_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_H_AR_RELEASE_MINOR_VERSION != SENT_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_H_AR_RELEASE_REVISION_VERSION != SENT_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent.h and Sent_Types_E3.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_H_SW_MAJOR_VERSION != SENT_TYPES_H_SW_MAJOR_VERSION)\
    || (SENT_H_SW_MINOR_VERSION != SENT_TYPES_H_SW_MINOR_VERSION)\
    || (SENT_H_SW_PATCH_VERSION != SENT_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Sent.h and Sent_Types_E3.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define SENT_MODULE_ID                   (2049u)
#define SENT_INSTANCE_ID                 (0u)

#define SENT_E_PARAM_CHANNEL             (0x0Au)
#define SENT_E_UNINIT                    (0x0Bu)
#define SENT_E_ALREADY_INITIALIZED       (0x0Cu)

#define SENT_INIT_ID                     (0x01u)
#define SENT_DEINIT_ID                   (0x02u)
#define SENT_START_RECIEVER_ID           (0x03u)
#define SENT_STOP_RECIEVER_ID            (0x04u)
#define SENT_GET_FRAME_INFO_ID           (0x05u)


#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

FUNC(void, SENT_CODE) Sent_Init
(
    P2CONST(Sent_ConfigType, AUTOMATIC, SENT_APPL_CONST) ConfigPtr
);

#if (SENT_DEINIT_API == STD_ON)
FUNC(void, SENT_CODE) Sent_DeInit
(
    void
);
#endif /* SENT_DEINIT_API == STD_ON */

FUNC(void, SENT_CODE) Sent_StartReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel
);

FUNC(void, SENT_CODE) Sent_StopReciever
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel
);

FUNC(boolean, SENT_CODE) Sent_GetFrameInfo
(
    VAR(Sent_ChannelType, AUTOMATIC) Channel,
    P2VAR(Sent_ErrType, AUTOMATIC, SENT_APPL_DATA) pError,
    P2VAR(Sent_Frame, AUTOMATIC, SENT_APPL_DATA) pFrameInfo
);

FUNC(void, SENT_CODE) Sent_IrqCommon
(
    VAR(uint8, AUTOMATIC) eModule
);

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /*SENT_H*/
