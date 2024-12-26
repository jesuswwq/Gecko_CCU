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
 * @file  Gpt_Ip_E3.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifndef GPT_IP_E3_H
#define GPT_IP_E3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Compiler.h"
#include "Gpt_Cfg.h"
#include "Mcu_Modules.h"
#include "Gpt_Types_E3.h"
/* Version and Check Begin */
/* Version Info Begin */
#define GPT_IP_H_VENDOR_ID    0x8C
#define GPT_IP_H_AR_RELEASE_MAJOR_VERSION    4
#define GPT_IP_H_AR_RELEASE_MINOR_VERSION    3
#define GPT_IP_H_AR_RELEASE_REVISION_VERSION 1
#define GPT_IP_H_SW_MAJOR_VERSION    1
#define GPT_IP_H_SW_MINOR_VERSION    0
#define GPT_IP_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IP_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Ip_E3.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IP_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (GPT_IP_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (GPT_IP_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Ip_E3.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IP_H_AR_RELEASE_MAJOR_VERSION != COMPILER_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_MINOR_VERSION != COMPILER_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_REVISION_VERSION != COMPILER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Ip_E3.h and Compiler.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IP_H_SW_MAJOR_VERSION != COMPILER_H_SW_MAJOR_VERSION)\
    || (GPT_IP_H_SW_MINOR_VERSION != COMPILER_H_SW_MINOR_VERSION)\
    || (GPT_IP_H_SW_PATCH_VERSION != COMPILER_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Ip_E3.h and Compiler.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IP_H_AR_RELEASE_MAJOR_VERSION != GPT_CFG_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_MINOR_VERSION != GPT_CFG_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_REVISION_VERSION != GPT_CFG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Ip_E3.h and Gpt_Cfg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IP_H_SW_MAJOR_VERSION != GPT_CFG_H_SW_MAJOR_VERSION)\
    || (GPT_IP_H_SW_MINOR_VERSION != GPT_CFG_H_SW_MINOR_VERSION)\
    || (GPT_IP_H_SW_PATCH_VERSION != GPT_CFG_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Ip_E3.h and Gpt_Cfg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_IP_H_AR_RELEASE_MAJOR_VERSION != MCU_MODULES_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_MINOR_VERSION != MCU_MODULES_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_IP_H_AR_RELEASE_REVISION_VERSION != MCU_MODULES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt_Ip_E3.h and Mcu_Modules.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_IP_H_SW_MAJOR_VERSION != MCU_MODULES_H_SW_MAJOR_VERSION)\
    || (GPT_IP_H_SW_MINOR_VERSION != MCU_MODULES_H_SW_MINOR_VERSION)\
    || (GPT_IP_H_SW_PATCH_VERSION != MCU_MODULES_H_SW_PATCH_VERSION))
#error "Opps, Gpt_Ip_E3.h and Mcu_Modules.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define GPT_IP_HW_CHANNEL_G0_IRQ    0x5U
#define GPT_IP_HW_CHANNEL_G1_IRQ    0xAU

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_Ip_StartPreDefTimer
(
    P2CONST(Gpt_PredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pPredefCfg
);

FUNC(void, GPT_CODE) Gpt_Ip_GetPredefTimerValue
(
    P2CONST(Gpt_PredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pPredefCfg,
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pTimeValue
);
#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API */

FUNC(void, GPT_CODE) Gpt_Ip_Init
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
);

FUNC(void, GPT_CODE) Gpt_Ip_DeInit
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
);

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_Ip_PredefDeInit
(
    P2CONST(Gpt_PredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pPredefCfg
);
#endif

FUNC(void, GPT_CODE) Gpt_Ip_StartTimer
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig,
    VAR(Gpt_ChannelModeType, AUTOMATIC) Mode,
    VAR(Gpt_ValueType, AUTOMATIC) Value,
    VAR(boolean, AUTOMATIC) bNotificationEnabled
);

FUNC(void, GPT_CODE) Gpt_Ip_StopTimer
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
);

FUNC(Gpt_ValueType, GPT_CODE) Gpt_Ip_GetTimeElapsed
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig,
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pIsExpried
);

FUNC(void, AUTOMATIC) Gpt_Ip_EnableInterrupt
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
);

FUNC(void, AUTOMATIC) Gpt_Ip_DisableInterrupt
(
    P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig
);

FUNC(uint32, AUTOMATIC) Gpt_Ip_GetInterrupt
(
    VAR(uint8, AUTOMATIC) eModule
);

FUNC(void, AUTOMATIC) Gpt_Ip_ClearInterrupt
(
    VAR(uint8, AUTOMATIC) eModule,
    VAR(uint8, AUTOMATIC) Position
);

#ifdef __cplusplus
}
#endif

#endif /*GPT_IP_E3_H*/
