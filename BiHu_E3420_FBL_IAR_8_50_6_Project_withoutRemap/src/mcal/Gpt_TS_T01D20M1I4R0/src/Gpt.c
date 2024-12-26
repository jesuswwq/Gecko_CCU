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
 * @file  Gpt.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt.h"
#include "Mcu.h"
#include "arch.h"
#include "Mcu_Cfg.h"

/* Version and Check Begin */
/* Version Info Begin */
#define GPT_C_VENDOR_ID    0x8C
#define GPT_C_AR_RELEASE_MAJOR_VERSION    4
#define GPT_C_AR_RELEASE_MINOR_VERSION    3
#define GPT_C_AR_RELEASE_REVISION_VERSION 1
#define GPT_C_SW_MAJOR_VERSION    1
#define GPT_C_SW_MINOR_VERSION    0
#define GPT_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_C_AR_RELEASE_MAJOR_VERSION != GPT_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_C_AR_RELEASE_MINOR_VERSION != GPT_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_C_AR_RELEASE_REVISION_VERSION != GPT_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt.c and Gpt.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_C_SW_MAJOR_VERSION != GPT_H_SW_MAJOR_VERSION)\
    || (GPT_C_SW_MINOR_VERSION != GPT_H_SW_MINOR_VERSION)\
    || (GPT_C_SW_PATCH_VERSION != GPT_H_SW_PATCH_VERSION))
#error "Opps, Gpt.c and Gpt.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/**
 * @enum Gpt_ChannelStatusType
*/
typedef enum {
    GPT_STATUS_UNKNOW = 0,                      /*! @brief GPT channel status - uninitialized */
    GPT_STATUS_INITIALIZED = 1,                 /*! @brief GPT channel status - initialized */
    GPT_STATUS_STOPPED = 2,                     /*! @brief GPT channel status - stopped */
    GPT_STATUS_EXPIRED = 3,                     /*! @brief GPT channel status - expired */
    GPT_STATUS_RUNNING = 4                      /*! @brief GPT channel status - running */
} Gpt_ChannelStatusType;

/**
 * @enum Gpt_ChannelInfoType
 * @brief  Saved Hardware Info
*/
typedef struct {
    /*! @brief channel mode*/
    Gpt_ChannelModeType eChnMode;
    /*! @brief GPT channel runtime status */
    Gpt_ChannelStatusType eChannelStatus;
    /*! @brief GPT channel has notification enabled at runtime */
    boolean bNotificationEnabled;
} Gpt_ChannelInfoType;

typedef struct {
    const Gpt_ConfigType *Gpt_ptrConfig;
    volatile Gpt_DriverStateType Gpt_eMode;
    Gpt_ChannelInfoType Gpt_aChannelInfo[GPT_HW_CHANNEL_NUM];
    Gpt_ValueType Gpt_aElapsedTime[GPT_HW_CHANNEL_NUM];
    Gpt_ValueType Gpt_aTargetTime[GPT_HW_CHANNEL_NUM];
#if (GPT_HW_CHANNEL_NUM == 1)  /* Cache needs 32byte alignment */
    const uint8 Pading[16];
#elif (GPT_HW_CHANNEL_NUM == 2)
    const uint8 Pading[4];
#endif
} __attribute__((aligned(CACHE_LINE))) Gpt_Ip_Handler;

#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

static VAR(Gpt_Ip_Handler, GPT_VAR) Gpt_Handler[MAX_CORE_NUM];

#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

static VAR(Gpt_PreDefTimerFlag, GPT_VAR) Gpt_PreDefTimerStatus = GPT_PREDEFTIMER_STOP;

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief Verify that the parameters are correct.
 * @details Make sure the module is uninitialized and the param is not null.
 * @param[in] ConfigCfg Parameters to be verified.
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateInitCfg
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigCfg
);

/**
 * @brief Check the channel status for Gpt_StartTimer
 * @details 1.If the channel status is "running", the function will raise the error GPT_E_BUSY.
 *          2.Check if the driver is not initialized.
 * @param[in] ConfigCfg Parameters to be verified.
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_CheckStaStartTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);

/**
 * @brief Check the channel status for Gpt_DeInit
 * @details 1.If the channel status is "running", the function will raise the error GPT_E_BUSY.
 *          2.Check if the driver is initialized.
 * @param[in] pVerInfo Pointer to VersionInfo Structure.
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_CheckChanStaDeInit
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);

/**
 * @brief Check the driver running mode status for Gpt_DeInit
 * @details Check if the driver is normal mode..
 * @param[in] None
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_CheckModuleStaDeInit
(
    void
);

/**
 * @brief Verify that the parameters are correct.
 * @details Make sure the channel id and value is valid.
 * @param[in] channel channel id.
 * @param[in] value timer target value.
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamStartTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(Gpt_ValueType, AUTOMATIC) Value
);

/**
 * @brief Verify that the parameters are not NULL_PTR.
 * @details Make sure the ptr is valid.
 * @param[in] pVerInfo Pointer to VersionInfo Structure.
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamGetVersionInfo
(
    P2CONST(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) pVerInfo
);

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Verify that the parameters are correct.
 * @details
 * @param[in] PredefTimer Selected Predef Timer.
 * @param[in] TimeValuePtr The pointer to TimeValue in RAM
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamGetPredefTime
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2CONST(uint32, AUTOMATIC, GPT_APPL_DATA) TimeValuePtr
);

/**
 * @brief Verify that the Predef Timer channel is correct.
 * @details
 * @param[in] PredefTimer Selected Predef Timer
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidatePredefTimeChanEnabled
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer
);
#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON */

/**
 * @brief Verify that the Notification is configured.
 * @details Make sure the channel notification function is valid.
 * @param[in] channel channel id.
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateNotification
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
);
#endif

/**
 * @brief Verify that the parameters are correct.
 * @details Make sure the channel id is valid.
 * @param[in] channel channel id.
 * @param[in] ServiceID caller function ID
 * @return Result
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
 */
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamCommon
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
);

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateInitCfg
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigCfg
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    do {

        if (Gpt_Handler[Mcu_GetCoreID()].Gpt_eMode == GPT_MODE_INITED) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)GPT_INIT_ID, \
             (uint8)GPT_E_ALREADY_INITIALIZED \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            RetVal = E_NOT_OK;
            break;
        }

#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)

        if (ConfigCfg == NULL_PTR) {
            RetVal = E_NOT_OK;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)GPT_INIT_ID, \
             (uint8)GPT_E_INIT_FAILED \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            break;
        }

#endif /* GPT_PRECOMPILE_SUPPORT == STD_OFF */
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)

        if (NULL_PTR == ConfigCfg->ptrPredefChannelConfig) {
            RetVal = E_NOT_OK;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)GPT_INIT_ID, \
             (uint8)GPT_E_INIT_FAILED \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            break;
        }

#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON */
    } while (0);

    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_CheckStaStartTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (Gpt_Handler[Mcu_GetCoreID()].Gpt_eMode != GPT_MODE_INITED) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_START_TIMER_ID, \
         (uint8)GPT_E_UNINIT \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    if (Gpt_Handler[Mcu_GetCoreID()].Gpt_aChannelInfo[Channel].eChannelStatus == GPT_STATUS_RUNNING) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_START_TIMER_ID, \
         (uint8)GPT_E_BUSY \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */

        RetVal = E_NOT_OK;
    }

    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_CheckChanStaDeInit
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (Gpt_Handler[Mcu_GetCoreID()].Gpt_aChannelInfo[Channel].eChannelStatus == GPT_STATUS_RUNNING) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_DEINIT_ID, \
         (uint8)GPT_E_BUSY \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_CheckModuleStaDeInit
(
    void
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (Gpt_Handler[Mcu_GetCoreID()].Gpt_eMode != GPT_MODE_INITED) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_DEINIT_ID, \
         (uint8)GPT_E_UNINIT \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamStartTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(Gpt_ValueType, AUTOMATIC) Value
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    do {
        if (Channel >= GPT_HW_CHANNEL_NUM) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)GPT_START_TIMER_ID, \
             (uint8)GPT_E_PARAM_CHANNEL \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            RetVal = E_NOT_OK;
            break;
        }

        if (NULL_PTR == Gpt_Handler[Mcu_GetCoreID()].Gpt_ptrConfig) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)GPT_START_TIMER_ID, \
             (uint8)GPT_E_PARAM_VALUE \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            RetVal = E_NOT_OK;
            break;
        }

        if ((Value > (*
                      (Gpt_Handler[Mcu_GetCoreID()].Gpt_ptrConfig->ptrChannelConfig))[Channel].uChannelTickValueMax)
            || (0U == Value)) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)GPT_START_TIMER_ID, \
             (uint8)GPT_E_PARAM_VALUE \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            RetVal = E_NOT_OK;
            break;
        }
    } while (0);

    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamGetVersionInfo
(
    P2CONST(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) pVerInfo
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (NULL_PTR == pVerInfo) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_GET_VERSION_INFO_ID, \
         (uint8)GPT_E_PARAM_POINTER \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamGetPredefTime
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2CONST(uint32, AUTOMATIC, GPT_APPL_DATA) TimeValuePtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (Gpt_Handler[Mcu_GetCoreID()].Gpt_eMode != GPT_MODE_INITED) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_GET_PREDEF_TIME_ID, \
         (uint8)GPT_E_UNINIT \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    if (NULL_PTR == TimeValuePtr) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_GET_PREDEF_TIME_ID, \
         (uint8)GPT_E_PARAM_POINTER \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    if (PredefTimer > GPT_PREDEF_TIMER_1US_32BIT) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_GET_PREDEF_TIME_ID, \
         (uint8)GPT_E_PARAM_PREDEF_TIMER \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidatePredefTimeChanEnabled
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if ((1U + (uint8)PredefTimer) >
        Gpt_Handler[Mcu_GetCoreID()].Gpt_ptrConfig->ptrPredefChannelConfig->u8PredefTimer1us_Num) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)GPT_GET_PREDEF_TIME_ID, \
         (uint8)GPT_E_PARAM_PREDEF_TIMER \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}
#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON */

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateNotification
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    do {
        if (NULL_PTR == Gpt_Handler[Mcu_GetCoreID()].Gpt_ptrConfig) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)GPT_START_TIMER_ID, \
             (uint8)GPT_E_PARAM_POINTER \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            RetVal = E_NOT_OK;
            break;
        }

        if (NULL_PTR == (*
                         (Gpt_Handler[Mcu_GetCoreID()].Gpt_ptrConfig->ptrChannelConfig))[Channel].pfNotification) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError\
            (\
             (uint16)GPT_MODULE_ID, \
             (uint8)GPT_INSTANCE_ID, \
             (uint8)ServiceID, \
             (uint8)GPT_E_PARAM_VALUE \
            );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
            RetVal = E_NOT_OK;
        }
    } while (0);


    return RetVal;
}
#endif

LOCAL_INLINE FUNC(Std_ReturnType, GPT_CODE) Gpt_ValidateParamCommon
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(uint8, AUTOMATIC) ServiceID
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    if (Channel >= GPT_HW_CHANNEL_NUM) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)ServiceID, \
         (uint8)GPT_E_PARAM_CHANNEL \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    if (Gpt_Handler[Mcu_GetCoreID()].Gpt_eMode != GPT_MODE_INITED) {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError\
        (\
         (uint16)GPT_MODULE_ID, \
         (uint8)GPT_INSTANCE_ID, \
         (uint8)ServiceID, \
         (uint8)GPT_E_UNINIT \
        );
#endif /*GPT_DEV_ERROR_DETECT == STD_ON */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

#if (STD_ON == GPT_VERSION_INFO_API)
FUNC(void, AUTOMATIC) Gpt_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VerInfoPtr
)
{
    if (E_OK == Gpt_ValidateParamGetVersionInfo(VerInfoPtr)) {
        VerInfoPtr->vendorID = GPT_H_VENDOR_ID;
        VerInfoPtr->moduleID = GPT_MODULE_ID;
        VerInfoPtr->sw_major_version = GPT_H_SW_MAJOR_VERSION;
        VerInfoPtr->sw_minor_version = GPT_H_SW_MINOR_VERSION;
        VerInfoPtr->sw_patch_version = GPT_H_SW_PATCH_VERSION;
    }

}
#endif /*GPT_VERSION_INFO_API == STD_ON */

FUNC(void, GPT_CODE) Gpt_Init
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr
)
{
    VAR(Gpt_ChannelType, AUTOMATIC) Channel = 0U;
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    if ((Std_ReturnType)E_OK == Gpt_ValidateInitCfg(ConfigPtr)) {
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
        Gpt_Handler[CoreId].Gpt_ptrConfig = &Gpt_CfgVariantPredefined;
        (void)ConfigPtr; /*avoid warning*/
#else
        Gpt_Handler[CoreId].Gpt_ptrConfig = ConfigPtr;
#endif /* GPT_PRECOMPILE_SUPPORT */

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)

        /*start Predef timer*/
        if ((Gpt_PreDefTimerStatus == GPT_PREDEFTIMER_STOP) &&
            (CoreId == 0U)) {
            Gpt_PreDefTimerStatus = GPT_PREDEFTIMER_START;
            Gpt_Ip_StartPreDefTimer(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrPredefChannelConfig);
        }

#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API */

        /* initializes every timer channel that configured*/
        for (Channel = 0; Channel < Gpt_Handler[CoreId].Gpt_ptrConfig->u8ChannelCount; Channel++) {
            if (CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
                Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].bNotificationEnabled = \
                    (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig.bNotificationEnabled;
                Gpt_Handler[CoreId].Gpt_aTargetTime[Channel] = (Gpt_ValueType)0;
                Gpt_Handler[CoreId].Gpt_aElapsedTime[Channel] = (Gpt_ValueType)0;
                Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_INITIALIZED;
                Gpt_Ip_Init(&((*
                               (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig));
            }
        }

        Gpt_Handler[CoreId].Gpt_eMode = GPT_MODE_INITED;
    }
}

#if (GPT_DEINIT_API == STD_ON)
FUNC(void, AUTOMATIC) Gpt_DeInit
(
    void
)
{
    VAR(Gpt_ChannelType, AUTOMATIC) Channel = 0U;
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    do {
        if (E_NOT_OK == Gpt_CheckModuleStaDeInit()) {
            break;
        }

        for (Channel = 0; Channel < Gpt_Handler[CoreId].Gpt_ptrConfig->u8ChannelCount; Channel++) {
            if (E_NOT_OK == Gpt_CheckChanStaDeInit(Channel)) {
                RetVal = E_NOT_OK;
                break;
            }
        }

        if (E_NOT_OK == RetVal) {
            break;
        }

        for (Channel = 0; Channel < Gpt_Handler[CoreId].Gpt_ptrConfig->u8ChannelCount; Channel++) {
            if (CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
                Gpt_Ip_DeInit(&((*
                                 (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig));
                Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_UNKNOW;
                Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChnMode = GPT_CH_MODE_CONTINUOUS;
                Gpt_Handler[CoreId].Gpt_aElapsedTime[Channel] = 0;
                Gpt_Handler[CoreId].Gpt_aTargetTime[Channel] = 0;
            }
        }

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)

        if ((Gpt_PreDefTimerStatus == GPT_PREDEFTIMER_START) &&
            (CoreId == 0U)) {
            Gpt_PreDefTimerStatus = GPT_PREDEFTIMER_STOP;
            Gpt_Ip_PredefDeInit(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrPredefChannelConfig);
        }

#endif
        Gpt_Handler[CoreId].Gpt_eMode = GPT_MODE_UNINIT;
    } while (0);
}
#endif

FUNC(void, GPT_CODE) Gpt_StartTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(Gpt_ValueType, AUTOMATIC) Value
)
{
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    if (E_OK == Gpt_ValidateParamStartTimer(Channel, Value)) {
        if (E_OK == Gpt_CheckStaStartTimer(Channel) &&
            CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
            Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_RUNNING;
            Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChnMode = (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].eChannelMode;
            Gpt_Handler[CoreId].Gpt_aTargetTime[Channel] = Value;
            Gpt_Ip_StartTimer( &((*
                                  (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig), \
                               (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].eChannelMode, Value, \
                                  Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].bNotificationEnabled);
        }

    }
}

FUNC(void, GPT_CODE) Gpt_StopTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    VAR(boolean, AUTOMATIC) pIsExpired = FALSE;
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    if (E_OK == Gpt_ValidateParamCommon(Channel, GPT_STOP_TIMER_ID)) {
        if (GPT_STATUS_RUNNING == Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus &&
            CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
            Gpt_Handler[CoreId].Gpt_aElapsedTime[Channel] = Gpt_Ip_GetTimeElapsed(&((*
                    (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig), \
                    &pIsExpired);
            Gpt_Ip_StopTimer(&((*
                                (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig));

            if (TRUE == (boolean)pIsExpired) {
                Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_EXPIRED;
            } else {
                Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_STOPPED;
            }
        }
    }
}

#if (GPT_TIME_ELAPSED_API == STD_ON)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    VAR(Gpt_ValueType, AUTOMATIC) RetVal = 0;
    VAR(boolean, AUTOMATIC) pIsExpired = FALSE;
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    if (E_OK == Gpt_ValidateParamCommon(Channel, GPT_GET_TIME_ELAPSED_ID)) {
        if (CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
            RetVal = Gpt_Ip_GetTimeElapsed(&((*
                                              (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig), &pIsExpired);

            switch (Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus) {
            case GPT_STATUS_INITIALIZED:
                RetVal = (Gpt_ValueType)0;
                break;

            case GPT_STATUS_RUNNING:
                if (TRUE == pIsExpired) {
                    Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_EXPIRED;
                }

                break;

            case GPT_STATUS_STOPPED:
                RetVal = Gpt_Handler[CoreId].Gpt_aElapsedTime[Channel];
                break;

            case GPT_STATUS_EXPIRED:
                RetVal = Gpt_Handler[CoreId].Gpt_aTargetTime[Channel];

            default:
                break;
            }
        }
    }
    return RetVal;
}
#endif /* GPT_TIME_ELAPSED_API == STD_ON */

#if (GPT_TIME_REMAINING_API == STD_ON)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    VAR(Gpt_ValueType, AUTOMATIC) RetVal = 0;
    VAR(boolean, AUTOMATIC) pIsExpired = FALSE;
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    if (E_OK == Gpt_ValidateParamCommon(Channel, GPT_GET_TIME_REMAINING_ID)) {
        if (CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
            RetVal = Gpt_Ip_GetTimeElapsed(&((*
                                              (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig),
                                           &pIsExpired);

            switch (Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus) {
            case GPT_STATUS_INITIALIZED:
                RetVal = 0;
                break;

            case GPT_STATUS_RUNNING:
                if (TRUE == pIsExpired) {
                    Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_EXPIRED;
                    RetVal = 0;
                } else {
                    RetVal = Gpt_Handler[CoreId].Gpt_aTargetTime[Channel] - RetVal;
                }

                break;

            case GPT_STATUS_STOPPED:
                RetVal = Gpt_Handler[CoreId].Gpt_aTargetTime[Channel] -
                         Gpt_Handler[CoreId].Gpt_aElapsedTime[Channel];
                break;

            case GPT_STATUS_EXPIRED:
                RetVal = 0;
                break;

            default:
                break;
            }
        }
    }

    return RetVal;
}
#endif /* GPT_TIME_REMAINING_API == STD_ON */

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_EnableNotification
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    do {
        if (E_NOT_OK == Gpt_ValidateParamCommon(Channel, GPT_ENABLE_NOTIFICATION_ID)) {
            break;
        }

        if (E_NOT_OK == Gpt_ValidateNotification(Channel, GPT_ENABLE_NOTIFICATION_ID)) {
            break;
        }

        Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].bNotificationEnabled = \
                    (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig.bNotificationEnabled;
        if (CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
            Gpt_Ip_EnableInterrupt(&((*
                                      (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig));
        }

    } while (0);

}

FUNC(void, GPT_CODE) Gpt_DisableNotification
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    do {
        if (E_NOT_OK == Gpt_ValidateParamCommon(Channel, GPT_DISABLE_NOTIFICATION_ID)) {
            break;
        }

        if (E_NOT_OK == Gpt_ValidateNotification(Channel, GPT_DISABLE_NOTIFICATION_ID)) {
            break;
        }

        if (CoreId == (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_CoreId) {
            Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].bNotificationEnabled = (boolean)FALSE;
            Gpt_Ip_DisableInterrupt(&((*
                                       (Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].Gpt_HwChannelConfig));
        }

    } while (0);
}
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

/**
 * @brief Not support mode change.
*/
FUNC(void, GPT_CODE) Gpt_SetMode
(
    VAR(Gpt_ModeType, AUTOMATIC) Mode
)
{
    (void)Mode;
}

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Not support wakeup.
*/
FUNC(void, GPT_CODE) Gpt_DisableWakeup
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    (void)Channel;
}

/**
 * @brief Not support wakeup.
*/
FUNC(void, GPT_CODE) Gpt_EnableWakeup
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
)
{
    (void)Channel;
}

/**
 * @brief Not support wakeup.
*/
FUNC(void, GPT_CODE) Gpt_CheckWakeup
(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource
)
{
    (void)WakeupSource;
}
#endif

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pTimeValue
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_NOT_OK;

    if (E_OK == Gpt_ValidateParamGetPredefTime(PredefTimer, pTimeValue)) {
        if (E_OK == Gpt_ValidatePredefTimeChanEnabled(PredefTimer)) {
            Gpt_Ip_GetPredefTimerValue(Gpt_Handler[Mcu_GetCoreID()].Gpt_ptrConfig->ptrPredefChannelConfig,
                                       PredefTimer, pTimeValue);
            RetVal = E_OK;
        }
    }

    return RetVal;
}
#endif /* GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON */

FUNC(void, AUTOMATIC) Gpt_Irq
(
    VAR(Gpt_HwModule, AUTOMATIC) eModule
)
{
    VAR(uint32, AUTOMATIC) Irq_Status = 0;
    VAR(uint8, AUTOMATIC) i = 0;
    VAR(uint8, AUTOMATIC) HwChannel = 255u;
    VAR(uint8, AUTOMATIC) Channel = 0u;
    VAR(uint8, AUTOMATIC) CoreId = Mcu_GetCoreID();

    do {
        if (NULL_PTR == Gpt_Handler[CoreId].Gpt_ptrConfig) {
            break;
        }

        Irq_Status = Gpt_Ip_GetInterrupt((uint8)eModule);

        if (Irq_Status != 0U) {
            if ((Irq_Status & GPT_IP_HW_CHANNEL_G0_IRQ) > 0U) {
                HwChannel = (uint8)GPT_HW_TIMER_G0;
                Gpt_Ip_ClearInterrupt((uint8)eModule, ((uint8)(Irq_Status & GPT_IP_HW_CHANNEL_G0_IRQ)));
            } else if ((Irq_Status & GPT_IP_HW_CHANNEL_G1_IRQ) > 0U) {
                HwChannel = (uint8)GPT_HW_TIMER_G1;
                Gpt_Ip_ClearInterrupt((uint8)eModule, ((uint8)(Irq_Status & GPT_IP_HW_CHANNEL_G1_IRQ)));
            } else {
                /* avoid warning */
            }
        }

        while ((i < Gpt_Handler[CoreId].Gpt_ptrConfig->u8ChannelCount) && (HwChannel != 255u)) {
            if (((*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[i].Gpt_HwChannelConfig.u8TimerModule
                 == (Gpt_HwModule)eModule)
                && ((*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[i].Gpt_HwChannelConfig.u8HwChannel ==
                    (Gpt_HwChannel)HwChannel)) {
                Channel = i;
                break;
            }

            i++;
        }

        if (GPT_CH_MODE_ONESHOT == Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChnMode) {
            Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].eChannelStatus = GPT_STATUS_EXPIRED;
        }

        if (TRUE == Gpt_Handler[CoreId].Gpt_aChannelInfo[Channel].bNotificationEnabled &&
        (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].pfNotification != NULL_PTR) {
            (*(Gpt_Handler[CoreId].Gpt_ptrConfig->ptrChannelConfig))[Channel].pfNotification();
        }
    } while (0);

}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
