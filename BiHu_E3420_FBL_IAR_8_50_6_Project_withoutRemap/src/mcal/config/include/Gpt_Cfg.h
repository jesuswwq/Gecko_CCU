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
 * @file  Gpt_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 * @date 2023-09-22 17:02:49
 */

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Types_E3.h"
#include "Det.h"

/* Version and Check Begin */
/* Version Info Begin */
#define GPT_CFG_H_VENDOR_ID    0x8C
#define GPT_CFG_H_AR_RELEASE_MAJOR_VERSION    4
#define GPT_CFG_H_AR_RELEASE_MINOR_VERSION    3
#define GPT_CFG_H_AR_RELEASE_REVISION_VERSION 1
#define GPT_CFG_H_SW_MAJOR_VERSION    1
#define GPT_CFG_H_SW_MINOR_VERSION    0
#define GPT_CFG_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_CFG_H_AR_RELEASE_MAJOR_VERSION != DET_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_CFG_H_AR_RELEASE_MINOR_VERSION != DET_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_CFG_H_AR_RELEASE_REVISION_VERSION != DET_H_AR_RELEASE_REVISION_VERSION))
    #error "Opps, Gpt_Cfg.h and Det.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_CFG_H_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)\
    || (GPT_CFG_H_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)\
    || (GPT_CFG_H_SW_PATCH_VERSION != DET_H_SW_PATCH_VERSION))
    #error "Opps, Gpt_Cfg.h and Det.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define GPT_VERSION_INFO_API (STD_OFF)
#define GPT_DEV_ERROR_DETECT (STD_OFF)
#define GPT_PREDEFTIMER_FUNCTIONALITY_API (STD_ON)
#define GPT_TIME_ELAPSED_API (STD_ON)
#define GPT_TIME_REMAINING_API (STD_ON)
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)
#define GPT_DEINIT_API (STD_ON)
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_OFF)
/* Gpt Pre Compile Switch */

#define GPT_PRECOMPILE_SUPPORT (STD_OFF)

#define GPT_HW_CHANNEL_NUM   (1U)

#define GptConf_GptChannelConfiguration_GptChannelConfiguration_0 (0)

extern CONST(Gpt_ConfigType, GPT_CONST)  GptChannelConfigSet;

#ifdef __cplusplus
}
#endif

#endif /*GPT_CFG_H*/
