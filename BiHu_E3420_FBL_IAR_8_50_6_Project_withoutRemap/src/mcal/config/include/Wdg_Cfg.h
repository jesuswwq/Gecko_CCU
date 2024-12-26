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
 * @file  Wdg_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 * @date 2023-09-22 17:02:48
 */

#ifndef WDG_CFG_H
#define WDG_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdg_Types.h"

/* Version and Check Begin */
/* Version Info Begin */
#define WDG_CFG_H_VENDOR_ID    0x8C
#define WDG_CFG_H_AR_RELEASE_MAJOR_VERSION    4
#define WDG_CFG_H_AR_RELEASE_MINOR_VERSION    3
#define WDG_CFG_H_AR_RELEASE_REVISION_VERSION 1
#define WDG_CFG_H_SW_MAJOR_VERSION    1
#define WDG_CFG_H_SW_MINOR_VERSION    0
#define WDG_CFG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */
#define WDG_INSTANCE_NUM     (7U)
#define WDG_CHANNEL_NUM      (1U)
#define WDG_VERSION_INFO_API (STD_ON)
#define WDG_REG_WRITE_READBACK_CHECK (STD_ON)
#define WDG_DEV_ERROR_DETECT (STD_ON)
#define WDG_DISABLE_ALLOWED  (STD_ON)
#define WDG_DEBUG_SUPPORT    STD_OFF

#define WDT1_INDEX (0)
#define WDT2_INDEX (1)
#define WDT3_INDEX (2)
#define WDT4_INDEX (3)
#define WDT5_INDEX (4)
#define WDT6_INDEX (5)
#define WDT8_INDEX (6)


#define WDG_PRECOMPILE_SUPPORT (STD_ON)

#if (WDG_REG_WRITE_READBACK_CHECK == STD_ON)
extern void (*WdgReadBackCheck_ErrorNotification)(void);
#endif
extern CONST(Wdg_IndexChannelConfigType, WDG_CONST) Wdg_InstanceChanCfg[7];
#ifdef __cplusplus
}
#endif
#endif /*WDG_CFG_H*/
