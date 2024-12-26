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
 * @file  Dio.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dio.h"
#include "Dio_IP.h"
/* Version and Check Begin */
/* Version Info Begin */
#define DIO_C_VENDOR_ID    0x8C
#define DIO_C_AR_RELEASE_MAJOR_VERSION    4
#define DIO_C_AR_RELEASE_MINOR_VERSION    3
#define DIO_C_AR_RELEASE_REVISION_VERSION 1
#define DIO_C_SW_MAJOR_VERSION    1
#define DIO_C_SW_MINOR_VERSION    0
#define DIO_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_C_AR_RELEASE_MAJOR_VERSION != DIO_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_C_AR_RELEASE_MINOR_VERSION != DIO_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_C_AR_RELEASE_REVISION_VERSION != DIO_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio.c and Dio.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_C_SW_MAJOR_VERSION != DIO_H_SW_MAJOR_VERSION)\
    || (DIO_C_SW_MINOR_VERSION != DIO_H_SW_MINOR_VERSION)\
    || (DIO_C_SW_PATCH_VERSION != DIO_H_SW_PATCH_VERSION))
#error "Opps, Dio.c and Dio.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_C_AR_RELEASE_MAJOR_VERSION != DIO_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_C_AR_RELEASE_MINOR_VERSION != DIO_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_C_AR_RELEASE_REVISION_VERSION != DIO_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Dio.c and Dio_IP.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_C_SW_MAJOR_VERSION != DIO_IP_H_SW_MAJOR_VERSION)\
    || (DIO_C_SW_MINOR_VERSION != DIO_IP_H_SW_MINOR_VERSION)\
    || (DIO_C_SW_PATCH_VERSION != DIO_IP_H_SW_PATCH_VERSION))
#error "Opps, Dio.c and Dio_IP.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Dio_LevelType, AUTOMATIC) RetVal = (Dio_LevelType)STD_LOW;
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    /* Return value should be zero for errors*/
    RetVal = (Dio_LevelType)STD_LOW;

    if (DIO_MAXNOOFCHANNEL <= ChannelId) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID,
                              DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        RetVal = Dio_Ip_ReadChannel(ChannelId);
    }

    return RetVal;
}

FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType,  AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,    AUTOMATIC) Level
)
{
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if (DIO_MAXNOOFCHANNEL <= ChannelId) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID,
                              DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        Dio_Ip_WriteChannel(ChannelId, Level);
    }
}

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) RetVal = (Dio_PortLevelType) STD_LOW;

    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if (DIO_MAXNOOFPORT < PortId) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT_SID,
                              DIO_E_PARAM_INVALID_PORT_ID);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        RetVal = Dio_Ip_ReadPort(PortId);
    }

    return RetVal;
}

FUNC(void, DIO_CODE) Dio_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
)
{
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if (DIO_MAXNOOFPORT < PortId) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_PORT_SID,
                              DIO_E_PARAM_INVALID_PORT_ID);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        Dio_Ip_WritePort(PortId, Level);
    }
}

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) RetVal = (Dio_PortLevelType) STD_LOW;
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if (ChannelGroupIdPtr == NULL_PTR) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP_SID,
                              DIO_E_PARAM_INVALID_GROUP);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        RetVal = Dio_Ip_ReadChannelGroup(ChannelGroupIdPtr);
    }
    return RetVal;
}

FUNC (void, DIO_CODE) Dio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
)
{
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if (ChannelGroupIdPtr == NULL_PTR) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP_SID,
                              DIO_E_PARAM_INVALID_GROUP);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        Dio_Ip_WriteChannelGroup(ChannelGroupIdPtr, Level);
    }
}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Dio_LevelType, AUTOMATIC) RetVal = (Dio_LevelType)STD_LOW;
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if (DIO_MAXNOOFCHANNEL <= ChannelId) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID,
                              DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        RetVal = Dio_Ip_FlipChannel(ChannelId);
    }
    return RetVal;
}
#endif

#if (DIO_MASKEDWRITEPORT_API == STD_ON)
FUNC(void, DIO_CODE) Dio_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
)
{
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if (DIO_MAXNOOFPORT < PortId) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_MASK_WRITE_PORT_SID,
                              DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        Dio_Ip_MaskedWritePort(PortId, Level, Mask);
    }
}
#endif

FUNC(void, DIO_CODE) Dio_GetVersionInfo
(
    CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) versionInfo
)
{
    if (NULL_PTR != versionInfo) {
        versionInfo->vendorID = DIO_H_VENDOR_ID;
        versionInfo->moduleID = DIO_MODULE_ID;
        versionInfo->sw_major_version = DIO_H_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = DIO_H_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = DIO_H_SW_PATCH_VERSION;
    } else {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID,
                              DIO_E_PARAM_POINTER);
#endif
    }
}

FUNC(void, DIO_CODE) Dio_SetPinInterruptDetect
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(Dio_DetectionType, AUTOMATIC) InterruptType
)
{
    VAR(Std_ReturnType, AUTOMATIC) DetErrFlag = (Std_ReturnType)E_NOT_OK;

    if ((InterruptType != DIO_LOW_LEVEL) &&
        (InterruptType != DIO_HIGH_LEVEL) &&
        (InterruptType != DIO_RISING_EDGE) &&
        (InterruptType != DIO_FALLING_EDGE) &&
        (InterruptType != DIO_BOTH_EDGE) &&
        (InterruptType != DIO_NONE)) {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_MASK_EN_INT_SID,
                              DIO_E_PARAM_INVALID_INT_TYPE);
#endif
        DetErrFlag = (Std_ReturnType)E_OK;
    } else {
        /* No action required, Required by MISRA  */
    }

    if ((Std_ReturnType)E_NOT_OK == DetErrFlag) {
        Dio_Ip_EnablePinInterruptDetect(ChannelId, InterruptType);
    }
}

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif
