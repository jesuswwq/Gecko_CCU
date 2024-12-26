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
 * @file  Wdg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdg.h"
#include "Det.h"
#include "SchM_Wdg.h"
#include "arch.h"
/* Version and Check Begin */
/* Version Info Begin */
#define WDG_C_VENDOR_ID    0x8C
#define WDG_C_AR_RELEASE_MAJOR_VERSION    4
#define WDG_C_AR_RELEASE_MINOR_VERSION    3
#define WDG_C_AR_RELEASE_REVISION_VERSION 1
#define WDG_C_SW_MAJOR_VERSION    1
#define WDG_C_SW_MINOR_VERSION    0
#define WDG_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_C_AR_RELEASE_MAJOR_VERSION != WDG_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_C_AR_RELEASE_MINOR_VERSION != WDG_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_C_AR_RELEASE_REVISION_VERSION != WDG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg.c and Wdg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_C_SW_MAJOR_VERSION != WDG_H_SW_MAJOR_VERSION)\
    || (WDG_C_SW_MINOR_VERSION != WDG_H_SW_MINOR_VERSION)\
    || (WDG_C_SW_PATCH_VERSION != WDG_H_SW_PATCH_VERSION))
#error "Opps, Wdg.c and Wdg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_C_AR_RELEASE_MAJOR_VERSION != DET_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_C_AR_RELEASE_MINOR_VERSION != DET_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_C_AR_RELEASE_REVISION_VERSION != DET_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg.c and Det.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_C_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)\
    || (WDG_C_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)\
    || (WDG_C_SW_PATCH_VERSION != DET_H_SW_PATCH_VERSION))
#error "Opps, Wdg.c and Det.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_C_AR_RELEASE_MAJOR_VERSION != SCHM_WDG_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_C_AR_RELEASE_MINOR_VERSION != SCHM_WDG_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_C_AR_RELEASE_REVISION_VERSION != SCHM_WDG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg.c and SchM_Wdg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_C_SW_MAJOR_VERSION != SCHM_WDG_H_SW_MAJOR_VERSION)\
    || (WDG_C_SW_MINOR_VERSION != SCHM_WDG_H_SW_MINOR_VERSION)\
    || (WDG_C_SW_PATCH_VERSION != SCHM_WDG_H_SW_PATCH_VERSION))
#error "Opps, Wdg.c and SchM_Wdg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#if (WDG_CHANNEL_NUM == 1)
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config1  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 2)
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config1  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config2  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 3)
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config1  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config2  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config3  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 4)
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config1  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config2  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config3  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config4  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 5)
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config1  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config2  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config3  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config4  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config5  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 6)
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config1  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config2  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config3  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config4  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config5  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config6  __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 7)
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config1  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config2  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config3  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config4  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config5  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config6  __attribute__((aligned(CACHE_LINE)));
static P2CONST(Wdg_ConfigType, WDG_CONST,
               WDG_CONST) pWdg_Config7  __attribute__((aligned(CACHE_LINE)));
#endif

#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

static P2CONST(Wdg_ConfigType *, AUTOMATIC, WDG_APPL_CONST) pWdg_Config_Ptr[WDG_CHANNEL_NUM] = {
#if (WDG_CHANNEL_NUM == 1)
    &pWdg_Config1,
#elif (WDG_CHANNEL_NUM == 2)
    &pWdg_Config1,
    &pWdg_Config2,
#elif (WDG_CHANNEL_NUM == 3)
    &pWdg_Config1,
    &pWdg_Config2,
    &pWdg_Config3,
#elif (WDG_CHANNEL_NUM == 4)
    &pWdg_Config1,
    &pWdg_Config2,
    &pWdg_Config3,
    &pWdg_Config4,
#elif (WDG_CHANNEL_NUM == 5)
    &pWdg_Config1,
    &pWdg_Config2,
    &pWdg_Config3,
    &pWdg_Config4,
    &pWdg_Config5,
#elif (WDG_CHANNEL_NUM == 6)
    &pWdg_Config1,
    &pWdg_Config2,
    &pWdg_Config3,
    &pWdg_Config4,
    &pWdg_Config5,
    &pWdg_Config6,
#elif (WDG_CHANNEL_NUM == 7)
    &pWdg_Config1,
    &pWdg_Config2,
    &pWdg_Config3,
    &pWdg_Config4,
    &pWdg_Config5,
    &pWdg_Config6,
    &pWdg_Config7,
#endif
};

#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#if (WDG_DEV_ERROR_DETECT == STD_ON)
#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#if (WDG_CHANNEL_NUM == 1)
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus1 __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 2)
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus1 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus2 __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 3)
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus1 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus2 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus3 __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 4)
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus1 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus2 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus3 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus4 __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 5)
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus1 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus2 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus3 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus4 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus5 __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 6)
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus1 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus2 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus3 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus4 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus5 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus6 __attribute__((aligned(CACHE_LINE)));
#elif (WDG_CHANNEL_NUM == 7)
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus1 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus2 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus3 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus4 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus5 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus6 __attribute__((aligned(CACHE_LINE)));
static VAR(Wdg_ModuleStatusType, WDG_VAR) eWdg_aStatus7 __attribute__((aligned(CACHE_LINE)));
#endif

#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_START_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

static CONSTP2VAR(Wdg_ModuleStatusType, WDG_CONST,
                  WDG_APPL_DATA) eWdg_aStatus_Ptr[WDG_CHANNEL_NUM] = {
#if (WDG_CHANNEL_NUM == 1)
    &eWdg_aStatus1,
#elif (WDG_CHANNEL_NUM == 2)
    &eWdg_aStatus1,
    &eWdg_aStatus2,
#elif (WDG_CHANNEL_NUM == 3)
    &eWdg_aStatus1,
    &eWdg_aStatus2,
    &eWdg_aStatus3,
#elif (WDG_CHANNEL_NUM == 4)
    &eWdg_aStatus1,
    &eWdg_aStatus2,
    &eWdg_aStatus3,
    &eWdg_aStatus4,
#elif (WDG_CHANNEL_NUM == 5)
    &eWdg_aStatus1,
    &eWdg_aStatus2,
    &eWdg_aStatus3,
    &eWdg_aStatus4,
    &eWdg_aStatus5,
#elif (WDG_CHANNEL_NUM == 6)
    &eWdg_aStatus1,
    &eWdg_aStatus2,
    &eWdg_aStatus3,
    &eWdg_aStatus4,
    &eWdg_aStatus5,
    &eWdg_aStatus6,
#elif (WDG_CHANNEL_NUM == 7)
    &eWdg_aStatus1,
    &eWdg_aStatus2,
    &eWdg_aStatus3,
    &eWdg_aStatus4,
    &eWdg_aStatus5,
    &eWdg_aStatus6,
    &eWdg_aStatus7,
#endif
};

#define WDG_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

#endif

#define WDG_START_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

#if (WDG_DEV_ERROR_DETECT == STD_ON)
static CONST(uint8, WDG_CONST) Wdg_a8Index[WDG_INSTANCE_NUM] = {
    WDT1_INDEX,
    WDT2_INDEX,
    WDT3_INDEX,
    WDT4_INDEX,
    WDT5_INDEX,
    WDT6_INDEX,
    WDT8_INDEX
};
#endif /* WDG_DEV_ERROR_DETECT */

#define WDG_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_MemMap.h"

#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

static FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidateParamInit
(
    VAR(uint8, AUTOMATIC) Wdg_InstanceID,
    VAR(uint8, AUTOMATIC) Wdg_ChannelID
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = E_OK;

    if (NULL_PTR == (*(pWdg_Config_Ptr[Wdg_ChannelID]))) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)WDG_MODULE_ID, \
         (uint8)Wdg_InstanceID, \
         (uint8)WDG_INIT_SERVICE_ID, \
         (uint8)WDG_E_INIT_FAILED \
        );
#endif /* WDG_DEV_ERROR_DETECT */
        Ret = E_NOT_OK;
    } else {
#if (WDG_DISABLE_ALLOWED==STD_OFF)

        if (WDGIF_OFF_MODE == (*(pWdg_Config_Ptr[Wdg_ChannelID]))->Wdg_DefaultMode) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)WDG_MODULE_ID, \
             (uint8)Wdg_InstanceID, \
             (uint8)WDG_INIT_SERVICE_ID, \
             (uint8)WDG_E_DISABLE_REJECTED \
            );
#endif /* WDG_DEV_ERROR_DETECT */
            Ret = E_NOT_OK;
        }

#endif /* WDG_DISABLE_ALLOWED */
    }

    return Ret;
}

static FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidateParamMode
(
    VAR(WdgIf_ModeType, AUTOMATIC) Mode,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = E_OK;
#if (WDG_DISABLE_ALLOWED == STD_OFF)

    if (WDGIF_OFF_MODE == Mode) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)WDG_MODULE_ID, \
         (uint8)Wdg_InstanceID, \
         (uint8)WDG_SETMODE_SERVICE_ID, \
         (uint8)WDG_E_DISABLE_REJECTED \
        );
#endif /* WDG_DEV_ERROR_DETECT */
        Ret = E_NOT_OK;
    } else {
#endif /* WDG_DISABLE_ALLOWED */
#if (WDG_DISABLE_ALLOWED == STD_OFF)
    }

#endif /* WDG_DISABLE_ALLOWED */
    if (Mode != WDGIF_OFF_MODE &&
        Mode != WDGIF_SLOW_MODE &&
        Mode != WDGIF_FAST_MODE ) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)WDG_MODULE_ID, \
         (uint8)Wdg_InstanceID, \
         (uint8)WDG_SETMODE_SERVICE_ID, \
         (uint8)WDG_E_MODE_FAILED \
        );
#endif /* WDG_DEV_ERROR_DETECT */
        Ret = E_NOT_OK;
    }

    (void)Mode;
    (void)Wdg_InstanceID;

    return Ret;
}

static FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelParam
(
    VAR(uint8, AUTOMATIC) Wdg_Channel,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = E_OK;

    if (Wdg_Channel == (uint8)0xffU) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError
            (
             (uint16)WDG_MODULE_ID, 
             (uint8)Wdg_InstanceID, 
             (uint8)WDG_INIT_SERVICE_ID, 
             (uint8)WDG_E_PARAM_CONFIG 
            );
#endif /* WDG_DEV_ERROR_DETECT */
            Ret = E_NOT_OK;
        }
    return Ret;
}

/**
 * @brief Initializes the module
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Init
(
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(uint8, AUTOMATIC) u8channel = 0xFF;
    u8channel = Wdg_InstanceChanCfg[Wdg_InstanceID].Wdg_u8Channel;

    do {
        if (E_NOT_OK == Wdg_ChannelParam(u8channel,Wdg_InstanceID)) {
            break;
        }

        *(pWdg_Config_Ptr[u8channel]) = ConfigPtr;

        if (E_OK == Wdg_ValidateParamInit(Wdg_InstanceID, u8channel)) {
            Wdg_Ip_Init(&((*((*(pWdg_Config_Ptr[u8channel]))->Wdg_ModeSettings))[(*
                          (pWdg_Config_Ptr[u8channel]))->Wdg_DefaultMode]), (*(pWdg_Config_Ptr[u8channel]))->Wdg_InitTimeout,
                        Wdg_InstanceID);
#if (WDG_DEV_ERROR_DETECT == STD_ON)
            *(eWdg_aStatus_Ptr[u8channel]) = WDG_IDLE;
#endif /* WDG_DEV_ERROR_DETECT */
        }
    } while (0);
}

/**
 * @brief Switches the watchdog into the target Mode
 * @param[in]  Mode  WDGIF_OFF_MODE/WDGIF_SlOW_MODE/WDGIF_FAST_MODE
 * @return   Std_ReturnType E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode
(
    VAR(WdgIf_ModeType, AUTOMATIC) Mode,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = E_OK;
    VAR(uint8, AUTOMATIC) u8channel = 0xFF;
    u8channel = Wdg_InstanceChanCfg[Wdg_InstanceID].Wdg_u8Channel;

    do {
        if (E_NOT_OK == Wdg_ChannelParam(u8channel,Wdg_InstanceID)) {
            Ret = E_NOT_OK;
            break;
        }
#if (WDG_DEV_ERROR_DETECT == STD_ON)

        /*PRQA S 2991,2995 2*/
        if (WDG_IDLE == (*(eWdg_aStatus_Ptr[u8channel]))) {
#endif /* WDG_DEV_ERROR_DETECT */
            if (E_OK == Wdg_ValidateParamMode(Mode, Wdg_InstanceID)) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
                *(eWdg_aStatus_Ptr[u8channel]) = WDG_BUSY;
#endif /* WDG_DEV_ERROR_DETECT */
                Wdg_Ip_SetMode(&((*((*(pWdg_Config_Ptr[u8channel]))->Wdg_ModeSettings))[Mode]),
                               Wdg_InstanceID);
#if (WDG_DEV_ERROR_DETECT == STD_ON)
                *(eWdg_aStatus_Ptr[u8channel]) = WDG_IDLE;
#endif /* WDG_DEV_ERROR_DETECT */
            } else {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(
                                      (uint16)WDG_MODULE_ID,
                                      (uint8)Wdg_a8Index[Wdg_InstanceID],
                                      (uint8)WDG_SETMODE_SERVICE_ID,
                                      (uint8)WDG_E_PARAM_MODE );
#endif /* WDG_DEV_ERROR_DETECT */
                Ret = E_NOT_OK;
            }
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        } else {
            (void)Det_ReportError(
                                  (uint16)WDG_MODULE_ID,
                                  (uint8)Wdg_a8Index[Wdg_InstanceID],
                                  (uint8)WDG_SETMODE_SERVICE_ID,
                                  (uint8)WDG_E_DRIVER_STATE );
            Ret = E_NOT_OK;
        }
#endif /* WDG_DEV_ERROR_DETECT */
    } while (0);

    return Ret;
}

/**
 * @brief Sets the timeout value for the trigger counter.
 * @param[in] Timeout Timeout value(ms) for setting the trigger counter
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition
(
    VAR(uint16, AUTOMATIC) Timeout,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    VAR(uint8, AUTOMATIC) u8channel = 0xFF;
    u8channel = Wdg_InstanceChanCfg[Wdg_InstanceID].Wdg_u8Channel;

    do {
        if (E_NOT_OK == Wdg_ChannelParam(u8channel,Wdg_InstanceID)) {
                break;
        }
    
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        if (WDG_UNINIT != (*(eWdg_aStatus_Ptr[u8channel]))) {
#endif /* WDG_DEV_ERROR_DETECT */
            if (Timeout > (*(pWdg_Config_Ptr[u8channel]))->Wdg_MaxTimeout) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(
                                      (uint16)WDG_MODULE_ID,
                                      (uint8)Wdg_a8Index[Wdg_InstanceID],
                                      (uint8)WDG_SETTRIGGERCONDITION_SERVICE_ID,
                                      (uint8)WDG_E_PARAM_TIMEOUT );
#endif /* WDG_DEV_ERROR_DETECT */
            } else {
                Wdg_Ip_SetTriggerCondition(Timeout, Wdg_InstanceID);
            }
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        }

#endif /* WDG_DEV_ERROR_DETECT */
    } while (0);
}

/**
 * @brief Get version information of module
 * @param[in]  VerInfoPtr Pointer to a version structure
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) VerInfoPtr,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{

    if (NULL_PTR == VerInfoPtr) {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)WDG_MODULE_ID, \
         (uint8)Wdg_InstanceID, \
         (uint8)WDG_GETVERSIONINFO_SERVICE_ID, \
         (uint8)WDG_E_PARAM_POINTER \
        );
#endif /*WDG_DEV_ERROR_DETECT == STD_ON */
    } else {
        VerInfoPtr->vendorID = WDG_H_VENDOR_ID;
        VerInfoPtr->moduleID = WDG_MODULE_ID;
        VerInfoPtr->sw_major_version = WDG_H_SW_MAJOR_VERSION;
        VerInfoPtr->sw_minor_version = WDG_H_SW_MINOR_VERSION;
        VerInfoPtr->sw_patch_version = WDG_H_SW_PATCH_VERSION;
    }
}

/**
 * @brief TriggerRoutine, can be used to feed wdg.
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_TriggerRoutine
(
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
)
{
    Wdg_Ip_TriggerRoutine(Wdg_InstanceID);
}

/**
 * @brief Interrupt handler. Be called by ISR(Wdg_Isr_Instance1) in Wdg_Irq.c
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_CommonInterrupt
(
    CONST(uint8, WDG_CONST) Wdg_InstanceID
)
{
    VAR(uint8, AUTOMATIC) u8channel = 0xFF;
    VAR(uint8, AUTOMATIC) u8instance = Wdg_InstanceID;

    /* If instance == 7, it represents WDT8, which is converted to the location of WDT8 in the array */
    if (u8instance == 7) {
        u8instance = WDT8_INDEX;
    }
    
    u8channel = Wdg_InstanceChanCfg[u8instance].Wdg_u8Channel;
    Wdg_Ip_ClearInterruptFlag(u8instance);

    if (NULL_PTR != (*(pWdg_Config_Ptr[u8channel]))->Wdg_pfNotification) {
        (*(pWdg_Config_Ptr[u8channel]))->Wdg_pfNotification();
    }
}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif
