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
 * @file  Sent_Ip_E3.h
 * @brief Semidrive. MCAL Sent
 */


#ifndef SENT_IP_E3_H
#define SENT_IP_E3_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Sent_Cfg.h"
#include "Sent_Types_E3.h"
/* Version and Check Begin */
/* Version Info Begin */
#define SENT_IP_H_VENDOR_ID    0x8C
#define SENT_IP_H_AR_RELEASE_MAJOR_VERSION    4
#define SENT_IP_H_AR_RELEASE_MINOR_VERSION    3
#define SENT_IP_H_AR_RELEASE_REVISION_VERSION 1
#define SENT_IP_H_SW_MAJOR_VERSION    1
#define SENT_IP_H_SW_MINOR_VERSION    0
#define SENT_IP_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_IP_H_AR_RELEASE_MAJOR_VERSION != SENT_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_IP_H_AR_RELEASE_MINOR_VERSION != SENT_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_IP_H_AR_RELEASE_REVISION_VERSION != SENT_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_Ip_E3.h and Sent_Types_E3.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_IP_H_SW_MAJOR_VERSION != SENT_TYPES_H_SW_MAJOR_VERSION)\
    || (SENT_IP_H_SW_MINOR_VERSION != SENT_TYPES_H_SW_MINOR_VERSION)\
    || (SENT_IP_H_SW_PATCH_VERSION != SENT_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Sent_Ip_E3.h and Sent_Types_E3.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#ifndef SEMIDRIVE_E3_LITE_SERIES
#define TIMER_MODULE_NUMBER     (4U)
#else
#define TIMER_MODULE_NUMBER     (2U)
#endif
#define LOCAL_CHANNEL_NUMBER    (4U)

extern VAR(Sent_Channel, AUTOMATIC) Sent_FrameInfo[SENT_NUM_CHANNELS];

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) Sent_Ip_SetBaseAddr
(
    void
);

FUNC(void, SENT_CODE) Sent_Ip_ChannelInit
(
    VAR(uint8, AUTOMATIC) eChannel,
    P2CONST(Sent_ChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pChannelConfig
);

FUNC(void, SENT_CODE) Sent_Ip_ChannelDeInit
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_ChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pChannelConfig
);

FUNC(void, SENT_CODE) Sent_Ip_StartReciever
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_HwChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pHwChannelConfig
);

FUNC(void, SENT_CODE) Sent_Ip_StopReciever
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_HwChannelConfigType, AUTOMATIC, SENT_APPL_CONST) pHwChannelConfig
);

FUNC(void, SENT_CODE) Sent_Ip_Parse_Massage
(
    VAR(uint8, AUTOMATIC) ChannelId,
    P2CONST(Sent_ChannelConfigType, SENT_CONST, SENT_APPL_DATA) ChannelConfig
);

FUNC(uint32, AUTOMATIC) Sent_Ip_GetInterrupt
(
    VAR(uint8, AUTOMATIC) eModule
);

FUNC(void, AUTOMATIC) Sent_Ip_ClearInterrupt
(
    VAR(uint8, AUTOMATIC) eModule,
    VAR(uint8, AUTOMATIC) Position
);

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /*SENT_IP_E3_H*/
