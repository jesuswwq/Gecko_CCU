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
 * @file  Sent_PBCfg.c
 * @brief Semidrive. MCAL Sent
 * @date 2024-03-08 16:29:00
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Sent_Cfg.h"
/* Version and Check Begin */
/* Version Info Begin */
#define SENT_PBCFG_C_VENDOR_ID    0x8C
#define SENT_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4
#define SENT_PBCFG_C_AR_RELEASE_MINOR_VERSION    3
#define SENT_PBCFG_C_AR_RELEASE_REVISION_VERSION 1
#define SENT_PBCFG_C_SW_MAJOR_VERSION    1
#define SENT_PBCFG_C_SW_MINOR_VERSION    0
#define SENT_PBCFG_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((SENT_PBCFG_C_AR_RELEASE_MAJOR_VERSION != SENT_CFG_H_AR_RELEASE_MAJOR_VERSION)\
    || (SENT_PBCFG_C_AR_RELEASE_MINOR_VERSION != SENT_CFG_H_AR_RELEASE_MINOR_VERSION)\
    || (SENT_PBCFG_C_AR_RELEASE_REVISION_VERSION != SENT_CFG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Sent_PBCfg.c and Sent_Cfg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((SENT_PBCFG_C_SW_MAJOR_VERSION != SENT_CFG_H_SW_MAJOR_VERSION)\
    || (SENT_PBCFG_C_SW_MINOR_VERSION != SENT_CFG_H_SW_MINOR_VERSION)\
    || (SENT_PBCFG_C_SW_PATCH_VERSION != SENT_CFG_H_SW_PATCH_VERSION))
#error "Opps, Sent_PBCfg.c and Sent_Cfg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

extern FUNC (void, SENT_CODE) Sent_frameover_test0(void);
extern FUNC (void, SENT_CODE) Sent_frameover_test1(void);

#define SENT_START_SEC_CONST_UNSPECIFIED
#include "Sent_MemMap.h"

static CONST(Sent_HwChannelConfigType, SENT_CONST) HwChannelConfig0 = {
    .u8TimerModule = (SENT_INDEX_ETIMER2),
    .u8HwChannel = (SENT_HW_CPT_A),
    .eFastChannel = (SENT_STANDARD_FORMAT),
    .eDataBitNum = (SENT_DATA_WIDTH_24_BIT),
    .u8LowPulseWid = (5),
    .u8FifoWml = (7),
    .bFiterEnable = (TRUE),
    .u8SampleInterval = (4),
    .u8FiterBandwidth = (7),
    .bPausePulse = (TRUE),
    .bNotifyFrameOver = TRUE,
    .pfFrameOverNotification = Sent_frameover_test0,
};
static CONST(Sent_HwChannelConfigType, SENT_CONST) HwChannelConfig1 = {
    .u8TimerModule = (SENT_INDEX_ETIMER2),
    .u8HwChannel = (SENT_HW_CPT_B),
    .eFastChannel = (SENT_STANDARD_FORMAT),
    .eDataBitNum = (SENT_DATA_WIDTH_12_BIT),
    .u8LowPulseWid = (5),
    .u8FifoWml = (7),
    .bFiterEnable = (TRUE),
    .u8SampleInterval = (4),
    .u8FiterBandwidth = (7),
    .bPausePulse = (FALSE),
    .bNotifyFrameOver = TRUE,
    .pfFrameOverNotification = Sent_frameover_test1,
};

static CONST(Sent_ChannelConfigType, SENT_CONST) Sent_ChannelConfigs[2] =
{
    {
        (50000),
        &HwChannelConfig0
    },
    {
        (200000),
        &HwChannelConfig1
    },
};

CONST(Sent_ConfigType, SENT_CONST) Sent_Config =
{
    &Sent_ChannelConfigs,
};

#define SENT_STOP_SEC_CONST_UNSPECIFIED
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif
