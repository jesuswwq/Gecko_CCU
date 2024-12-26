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
 * @file  Wdg_140_Instance2_Cfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 * @date 2023-09-22 17:02:48
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdg_Cfg.h"
#include "Wdg_140_Instance2_Cfg.h"
/* Version and Check Begin */
/* Version Info Begin */
#define WDG_INSTANCE2_PBCFG_C_VENDOR_ID    0x8C
#define WDG_INSTANCE2_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4
#define WDG_INSTANCE2_PBCFG_C_AR_RELEASE_MINOR_VERSION    3
#define WDG_INSTANCE2_PBCFG_C_AR_RELEASE_REVISION_VERSION 1
#define WDG_INSTANCE2_PBCFG_C_SW_MAJOR_VERSION    1
#define WDG_INSTANCE2_PBCFG_C_SW_MINOR_VERSION    0
#define WDG_INSTANCE2_PBCFG_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_INSTANCE2_PBCFG_C_AR_RELEASE_MAJOR_VERSION != WDG_140_INSTANCE2_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_INSTANCE2_PBCFG_C_AR_RELEASE_MINOR_VERSION != WDG_140_INSTANCE2_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_INSTANCE2_PBCFG_C_AR_RELEASE_REVISION_VERSION != WDG_140_INSTANCE2_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg_140_Instance2_PBCfg.c and Wdg_140_Instance2.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_INSTANCE2_PBCFG_C_SW_MAJOR_VERSION != WDG_140_INSTANCE2_H_SW_MAJOR_VERSION)\
    || (WDG_INSTANCE2_PBCFG_C_SW_MINOR_VERSION != WDG_140_INSTANCE2_H_SW_MINOR_VERSION)\
    || (WDG_INSTANCE2_PBCFG_C_SW_PATCH_VERSION != WDG_140_INSTANCE2_H_SW_PATCH_VERSION))
#error "Opps, Wdg_140_Instance2_PBCfg.c and Wdg_140_Instance2.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */



#define WDG_START_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

CONST(Wdg_ConfigType, WDG_CONST) Wdg_Config2 =
{
    
    .Wdg_InitTimeout = 0U,
    .Wdg_MaxTimeout  = 0U,
    .Wdg_DefaultMode = WDGIF_OFF_MODE,
    .Wdg_CurrentInstance = 0,
    .Wdg_pfNotification = NULL_PTR,
    .Wdg_ModeSettings = NULL_PTR,
};


#define WDG_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif
