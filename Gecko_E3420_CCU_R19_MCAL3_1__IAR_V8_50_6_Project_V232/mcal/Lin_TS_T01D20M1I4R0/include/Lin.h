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
 * @file  Lin.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#if !defined (LIN_H)
#define LIN_H

#ifdef __cplusplus
extern "C" {
#endif

/*****************Version Information************/
#define LIN_AR_MAJOR_VERSION  4U
#define LIN_AR_MINOR_VERSION  3U
#define LIN_AR_PATCH_VERSION  1U

#define LIN_SW_MAJOR_VERSION  1U
#define LIN_SW_MINOR_VERSION  0U
#define LIN_SW_PATCH_VERSION  0U

#define LIN_VENDOR_ID         0x8C

#include "Lin_GeneralTypes.h"
#include "Lin_Hw.h"
#include "Lin_Cfg.h"

#ifndef LIN_CONFIGURATION_VARIANT_PRECOMPILE
#define LIN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef LIN_CONFIGURATION_VARIANT_LINKTIME
#define LIN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef LIN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define LIN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif

#if(STD_ON == LIN_DEV_ERROR_DETECT)
/* Lin Driver module was not initialized*/
#define LIN_E_UNINT                       0x00
/* Lin Channel ID is out of Range*/
#define LIN_E_INVALID_CHANNEL             0x02
/* Pointer is out of Range*/
#define LIN_E_INVALID_POINTER             0x03
/* State transition is not valid*/
#define LIN_E_STATE_TRANSITION            0x04
/* Pointer is out of Range*/
#define LIN_E_PARAM_POINTER               0x05

/* Service id's for fls functions */
#define LIN_INIT_ID                          0x00
#define LIN_SENDFRAME_ID                     0x01
#define LIN_GOTOSLEEP_ID                     0x02
#define LIN_WAKEUP_ID                        0x03
#define LIN_WAKEUPINTERNAL_ID                0x04
#define LIN_GETSTATUS_ID                     0x05
#define LIN_GOTOSLEEPINTERNAL_ID             0x06
#define LIN_GETVERSIONINFO_ID                0x07
#define LIN_CHECKWAKEUP_ID                   0x08
#endif

#define LIN_MODULE_ID                       82U

#define LIN_E_NO_ERROR                     0xFFu

#define LIN_DET_ERROR                  (STD_ON)
#define LIN_DEV_ERROR                   STD_ON
#define LIN_DEV_ERROR_REPORT            STD_ON
#define LIN_GETVERSIONINFO_SERVICE_ID  ((uint8)0x01u)
#define LIN_MAXBYTES_LINFRAME           0x08

#define LIN_MAXNUMBER_FRAMES             12




#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
void Lin_DeInit(void);

void Lin_Init(const Lin_ConfigType *Config );

Std_ReturnType Lin_GoToSleep(uint8 Channel);

Std_ReturnType Lin_GoToSleepInternal(uint8 Channel);

Std_ReturnType Lin_Wakeup(uint8 Channel);

Std_ReturnType Lin_WakeupInternal(uint8 Channel);

Lin_StatusType Lin_GetStatus(uint8 Channel, uint8 **Lin_SduPtr);

Std_ReturnType Lin_CheckWakeup(uint8 Channel);

Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr);

#if(LIN_VERSION_INFO_API == STD_ON)
FUNC(void, LIN_CODE) Lin_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC,
                                        LIN_APPL_VAR) versioninfo);
#endif
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /* LIN_H */
