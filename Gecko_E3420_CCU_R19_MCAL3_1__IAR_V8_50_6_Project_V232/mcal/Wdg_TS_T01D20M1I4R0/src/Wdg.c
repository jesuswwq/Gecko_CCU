/********************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \file     Wdg.c                                                                                      *
 * \brief    AUTOSAR 4.3.1 MCAL WDG Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/* Place some description here for why include this file*/
#include "Wdg.h"
#if (WDG_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /*WDG_DEV_ERROR_DETECT*/
#if (WDG_SAFETY_ENABLE == STD_ON)
#include "FuSaMcalReportError.h"
#endif /*WDG_SAFETY_ENABLE*/
#include "SchM_Wdg.h"
#include "Wdg_Cfg.h"
#include "Wdg_Ip.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \name WDG Driver ID Info
 *  @{
 */
/** \brief SemiDriver Instruments Vendor ID */
#define WDG_C_VENDOR_ID    0x8C
/* @} */
/**
 *  \name WDG Driver Module AUTOSAR Version Info
 *
 *  Defines for WDG Driver AUTOSAR version used for compatibility checks
 *  @{
 */
/** \brief AUTOSAR Major version specification implemented by WDG Driver */
#define WDG_C_AR_RELEASE_MAJOR_VERSION    4
/** \brief AUTOSAR Minor  version specification implemented by WDG Driver */
#define WDG_C_AR_RELEASE_MINOR_VERSION    3
/** \brief AUTOSAR Patch version specification implemented by WDG Driver */
#define WDG_C_AR_RELEASE_REVISION_VERSION 1
/* @} */
/**
 *  \name WDG Driver Module SW Version Info
 *
 *  Defines for WDG Driver version used for compatibility checks
 *  @{
 */
/** \brief Driver Implementation Major Version */
#define WDG_C_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_C_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_C_SW_PATCH_VERSION    0
/* @} */

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief Driver Det Error retry times when return E_NOT_OK */
#define WDG_DET_ERROR_FAIL_RETRY_COUNT  (3u)
/** \brief Driver WDG MODULE SETTING array number */
#define WDG_MODE_SETTING_ARRAY_SIZE     (3U)

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/

/*none*/


/** \brief  please input Global Constant Declarations information */
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if ((WDG_INSTANCE1_SUPPORT == STD_ON)\
  || (WDG_INSTANCE2_SUPPORT == STD_ON)\
  || (WDG_INSTANCE3_SUPPORT == STD_ON)\
  || (WDG_INSTANCE4_SUPPORT == STD_ON)\
  || (WDG_INSTANCE5_SUPPORT == STD_ON)\
  || (WDG_INSTANCE6_SUPPORT == STD_ON)\
  || (WDG_INSTANCE8_SUPPORT == STD_ON))

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/*None*/
/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** \brief  please input Global Variable Declarations information */

#if (WDG_INSTANCE1_SUPPORT == STD_ON)
#define WDG1_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg1_MemMap.h"
static const Wdg_ConfigType *Wdg_Config1Ptr = NULL_PTR;
#define WDG1_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg1_MemMap.h"
#endif /*WDG_INSTANCE1_SUPPORT*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)
#define WDG2_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg2_MemMap.h"
static const Wdg_ConfigType *Wdg_Config2Ptr = NULL_PTR;
#define WDG2_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg2_MemMap.h"
#endif /*WDG_INSTANCE2_SUPPORT*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)
#define WDG3_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg3_MemMap.h"
static const Wdg_ConfigType *Wdg_Config3Ptr = NULL_PTR;
#define WDG3_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg3_MemMap.h"
#endif /*WDG_INSTANCE3_SUPPORT*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)
#define WDG4_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg4_MemMap.h"
static const Wdg_ConfigType *Wdg_Config4Ptr = NULL_PTR;
#define WDG4_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg4_MemMap.h"
#endif /*WDG_INSTANCE4_SUPPORT*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)
#define WDG5_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg5_MemMap.h"
static const Wdg_ConfigType *Wdg_Config5Ptr = NULL_PTR;
#define WDG5_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg5_MemMap.h"
#endif /*WDG_INSTANCE5_SUPPORT*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)
#define WDG6_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg6_MemMap.h"
static const Wdg_ConfigType *Wdg_Config6Ptr = NULL_PTR;
#define WDG6_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg6_MemMap.h"
#endif /*WDG_INSTANCE6_SUPPORT*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)
#define WDG8_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg8_MemMap.h"
static const Wdg_ConfigType *Wdg_Config8Ptr = NULL_PTR;
#define WDG8_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg8_MemMap.h"
#endif /*WDG_INSTANCE8_SUPPORT*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
#if (WDG_INSTANCE1_SUPPORT == STD_ON)
#define WDG1_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg1_MemMap.h"
static Wdg_ModuleStatusType Wdg1_Status = WDG_UNINIT;
#define WDG1_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg1_MemMap.h"
#endif /*WDG_INSTANCE1_SUPPORT*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)
#define WDG2_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg2_MemMap.h"
static Wdg_ModuleStatusType Wdg2_Status = WDG_UNINIT;
#define WDG2_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg2_MemMap.h"
#endif /*WDG_INSTANCE2_SUPPORT*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)
#define WDG3_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg3_MemMap.h"
static Wdg_ModuleStatusType Wdg3_Status = WDG_UNINIT;
#define WDG3_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg3_MemMap.h"
#endif /*WDG_INSTANCE3_SUPPORT*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)
#define WDG4_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg4_MemMap.h"
static Wdg_ModuleStatusType Wdg4_Status = WDG_UNINIT;
#define WDG4_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg4_MemMap.h"
#endif /*WDG_INSTANCE4_SUPPORT*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)
#define WDG5_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg5_MemMap.h"
static Wdg_ModuleStatusType Wdg5_Status = WDG_UNINIT;
#define WDG5_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg5_MemMap.h"
#endif /*WDG_INSTANCE5_SUPPORT*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)
#define WDG6_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg6_MemMap.h"
static Wdg_ModuleStatusType Wdg6_Status = WDG_UNINIT;
#define WDG6_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg6_MemMap.h"
#endif /*WDG_INSTANCE6_SUPPORT*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)
#define WDG8_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg8_MemMap.h"
static Wdg_ModuleStatusType Wdg8_Status = WDG_UNINIT;
#define WDG8_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg8_MemMap.h"
#endif /*WDG_INSTANCE8_SUPPORT*/
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
/** *****************************************************************************************************
 * \brief Report Det error or safety error.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_140_ReportError
 *                       (uint16 moduleId,uint8 instanceId,uint8  apiId,Std_ReturnType errorId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)   : moduleId  - ModuleId id is stable (WDG_MODULE_ID).
 *
 * Parameters (in)   : instanceId  - Wdg Instance id and it is depending on hardware.
 *
 * Parameters (in)   : apiId  - AutoSar Service Api interface Id.
 *
 * Parameters (in)   : errorId  - Wdg errorId Id fpr autosar spec define.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK/E_NOT_OK
 *
 * Description        : Report Det error or safety error.
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_005 SWSR_WDG_006 SWSR_WDG_009 SWSR_WDG_015 SWSR_WDG_016 SWSR_WDG_017
 *                      SWSR_WDG_023 SWSR_WDG_024 SWSR_WDG_025 SWSR_WDG_026 SWSR_WDG_027 SWSR_WDG_034
 *                      SWSR_WDG_036
 *******************************************************************************************************/
static void Wdg_140_ReportError(uint16 moduleId, uint8 instanceId, uint8  apiId,
                                Std_ReturnType errorId)
{
    /*#10 log and event report config check*/

    Std_ReturnType ret = E_NOT_OK;
    uint8 count = WDG_DET_ERROR_FAIL_RETRY_COUNT;

    /*#20 log and event report fail retry*/
    while ((E_NOT_OK == ret) && (count > WDT_IP_ZERO))
    {
        /*#30 report DET*/
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        ret =  Det_ReportError(moduleId, instanceId, apiId, (uint8)errorId);
#endif /*WDG_DEV_ERROR_DETECT*/
        count --;
    }

    ret = E_NOT_OK;
    count = WDG_DET_ERROR_FAIL_RETRY_COUNT;

    while ((E_NOT_OK == ret) && (count > WDT_IP_ZERO))
    {
        /*#30 report Safety*/
#if (WDG_SAFETY_ENABLE == STD_ON)
        ret = FuSaMcal_ReportError(moduleId, instanceId, apiId, (uint8)errorId);
#endif /*WDG_SAFETY_ENABLE*/
        count --;
    }
}
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
/** *****************************************************************************************************
 * \brief The Watchdog instanceId valid check for the gloable.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_140_InstanceIdValidCheck(uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)   :  apiId  - AutoSar Service Api interface Id.
 *
 * Parameters (in)   :  instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK/E_NOT_OK
 *
 * Description        : The Watchdog instanceId valid check for the gloable.
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_004 SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Wdg_140_InstanceIdValidCheck(uint8 instanceId)
{
    Std_ReturnType errorId = E_NOT_OK;
    /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

    if (WDT1_INDEX == instanceId)
    {
        errorId = E_OK;
    }/*else not use*/

#endif /* WDG_INSTANCE1_SUPPORT */
    /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

    if (WDT2_INDEX == instanceId)
    {
        errorId = E_OK;
    }/*else not use*/

#endif /* WDG_INSTANCE2_SUPPORT */
    /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

    if (WDT3_INDEX == instanceId)
    {
        errorId = E_OK;
    }/*else not use*/

#endif /* WDG_INSTANCE3_SUPPORT */
    /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

    if (WDT4_INDEX == instanceId)
    {
        errorId = E_OK;
    }/*else not use*/

#endif /* WDG_INSTANCE4_SUPPORT */
    /*#50 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

    if (WDT5_INDEX == instanceId)
    {
        errorId = E_OK;
    }/*else not use*/

#endif /* WDG_INSTANCE5_SUPPORT */
    /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

    if (WDT6_INDEX == instanceId)
    {
        errorId = E_OK;
    }/*else not use*/

#endif /* WDG_INSTANCE6_SUPPORT */
    /*#70 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

    if (WDT8_INDEX == instanceId)
    {
        errorId = E_OK;
    }/*else not use*/

#endif /* WDG_INSTANCE8_SUPPORT */
    return  errorId;
}

/** *****************************************************************************************************
 * \brief The Watchdog instanceId valid check for the config.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_140_InstanceIdMatchConfigCheck
 *                       (const Wdg_ConfigType * configPtr,uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)   :  configPtr  - Pointer to WDG driver configuration set.
 *
 * Parameters (in)   :  instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK/WDG_E_PARAM_POINTER/WDG_E_PARAM_INSTANCE
 *
 * Description        : Get The instanceId Watchdog  Config Point.
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_004 SWSR_WDG_007 SWSR_WDG_011 SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Wdg_140_InstanceIdMatchConfigCheck(
    const Wdg_ConfigType *configPtr, uint8 instanceId)
{
    Std_ReturnType errorId = E_OK;

    /*#10  null point check*/
    if (NULL_PTR == configPtr)
    {
        errorId = WDG_E_PARAM_POINTER;
    }
    else
    {
        /*#20  instanceId match check*/
        if (instanceId != configPtr->currentInstance)
        {
            errorId = WDG_E_PARAM_INSTANCE;
        }/*else not use*/
    }

    return  errorId;
}

/** *****************************************************************************************************
 * \brief Get The instanceId Watchdog  Config Point.
 *
 * \verbatim
 * Syntax             : static const Wdg_ConfigType * Wdg_140_GetInstanceIdConfigPtr(uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : configPtr
 *
 * Description        : Get The instanceId Watchdog  Config Point.
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_004 SWSR_WDG_007 SWSR_WDG_011
 *******************************************************************************************************/
static const Wdg_ConfigType *Wdg_140_GetInstanceIdConfigPtr(uint8 instanceId)
{
    const Wdg_ConfigType *p;

    switch (instanceId)
    {
        /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

    case WDT1_INDEX:
        p = Wdg_Config1Ptr;
        break;
#endif /* WDG_INSTANCE1_SUPPORT */
        /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

    case WDT2_INDEX:
        p = Wdg_Config2Ptr;
        break;
#endif /* WDG_INSTANCE2_SUPPORT */
        /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

    case WDT3_INDEX:
        p = Wdg_Config3Ptr;
        break;
#endif /* WDG_INSTANCE3_SUPPORT */
        /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

    case WDT4_INDEX:
        p = Wdg_Config4Ptr;
        break;
#endif /* WDG_INSTANCE4_SUPPORT */
        /*#50 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

    case WDT5_INDEX:
        p = Wdg_Config5Ptr;
        break;
#endif /* WDG_INSTANCE5_SUPPORT */
        /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

    case WDT6_INDEX:
        p = Wdg_Config6Ptr;
        break;
#endif /* WDG_INSTANCE6_SUPPORT */
        /*#70 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

    case WDT8_INDEX:
        p = Wdg_Config8Ptr;
        break;
#endif /* WDG_INSTANCE8_SUPPORT */

    default:
        p = NULL_PTR;
        break;
    }

    return p;
}

/** *****************************************************************************************************
 * \brief Save The instanceId Watchdog  Config Point.
 *
 * \verbatim
 * Syntax             : void Wdg_140_SetInstanceIdConfigPtr(const Wdg_ConfigType * configPtr,uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr  -  Pointer to WDG driver configuration set.
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Save The instanceId Watchdog  Config Point.
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_004 SWSR_WDG_007 SWSR_WDG_011
 *******************************************************************************************************/
static void Wdg_140_SetInstanceIdConfigPtr(const Wdg_ConfigType *configPtr, uint8 instanceId)
{
    switch (instanceId)
    {
        /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

    case WDT1_INDEX:
        Wdg_Config1Ptr = configPtr;
        break ;
#endif /* WDG_INSTANCE1_SUPPORT */
        /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

    case WDT2_INDEX:
        Wdg_Config2Ptr = configPtr;
        break ;
#endif /* WDG_INSTANCE2_SUPPORT */
        /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

    case WDT3_INDEX:
        Wdg_Config3Ptr = configPtr;
        break ;
#endif /* WDG_INSTANCE3_SUPPORT */
        /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

    case WDT4_INDEX:
        Wdg_Config4Ptr = configPtr;
        break ;
#endif /* WDG_INSTANCE4_SUPPORT */
        /*#50 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

    case WDT5_INDEX:
        Wdg_Config5Ptr = configPtr;
        break ;
#endif /* WDG_INSTANCE5_SUPPORT */
        /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

    case WDT6_INDEX:
        Wdg_Config6Ptr = configPtr;
        break ;
#endif /* WDG_INSTANCE6_SUPPORT */
        /*#70 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

    case WDT8_INDEX:
        Wdg_Config8Ptr = configPtr;
        break ;
#endif /* WDG_INSTANCE8_SUPPORT */

    default:
        /*do nothing*/
        break;
    }
}
#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
/** *****************************************************************************************************
 * \brief The instanceId Watchdog  work status Get.
 *
 * \verbatim
 * Syntax             : static void Wdg_140_GetWorkStatus(uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : WDG_UNINIT/WDG_IDLE/WDG_BUSY
 *
 * Description        : The instanceId Watchdog  work status Get.
 *
 * \endverbatim
 * Traceability       : SW_SM001 SW_SM002 SWSR_WDG_009 SWSR_WDG_010 SWSR_WDG_018 SWSR_WDG_028
 *******************************************************************************************************/
static Wdg_ModuleStatusType Wdg_140_GetWorkStatus(uint8 instanceId)
{
    Wdg_ModuleStatusType workStatus;

    switch (instanceId)
    {
        /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

    case WDT1_INDEX:
        workStatus = Wdg1_Status;
        break;
#endif /* WDG_INSTANCE1_SUPPORT */
        /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

    case WDT2_INDEX:
        workStatus = Wdg2_Status;
        break;
#endif /* WDG_INSTANCE2_SUPPORT */
        /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

    case WDT3_INDEX:
        workStatus = Wdg3_Status;
        break;
#endif /* WDG_INSTANCE3_SUPPORT */
        /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

    case WDT4_INDEX:
        workStatus = Wdg4_Status;
        break;
#endif /* WDG_INSTANCE4_SUPPORT */
        /*#50 judge instanceId whether is WDG_INSTANCE51*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

    case WDT5_INDEX:
        workStatus = Wdg5_Status;
        break;
#endif /* WDG_INSTANCE5_SUPPORT */
        /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

    case WDT6_INDEX:
        workStatus = Wdg6_Status;
        break;
#endif /* WDG_INSTANCE6_SUPPORT */
        /*#70 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

    case WDT8_INDEX:
        workStatus = Wdg8_Status;
        break;
#endif /* WDG_INSTANCE8_SUPPORT */

    default:
        workStatus = WDG_UNINIT;
        break;
    }

    return workStatus;
}

/** *****************************************************************************************************
 * \brief The instanceId Watchdog  work status Set.
 *
 * \verbatim
 * Syntax             : static void Wdg_140_SetWorkStatus(Wdg_ModuleStatusType status,uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : status - Wdg work status(Idle/uninit/busy).
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The instanceId Watchdog  work status Set.
 *
 * \endverbatim
 * Traceability       : SW_SM001 SW_SM002 SWSR_WDG_009 SWSR_WDG_010 SWSR_WDG_018 SWSR_WDG_028
 *******************************************************************************************************/
static void Wdg_140_SetWorkStatus(Wdg_ModuleStatusType status, uint8 instanceId)
{
    /*#10 current wdg status value valid check*/
    if ((WDG_BUSY == status) || (WDG_IDLE == status))
    {
        switch (instanceId)
        {
            /*#20 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

        case WDT1_INDEX:
            Wdg1_Status = status;
            break;
#endif /* WDG_INSTANCE1_SUPPORT */
            /*#30 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

        case WDT2_INDEX:
            Wdg2_Status = status;
            break;
#endif /* WDG_INSTANCE2_SUPPORT */
            /*#40 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

        case WDT3_INDEX:
            Wdg3_Status = status;
            break;
#endif /* WDG_INSTANCE3_SUPPORT */
            /*#50 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

        case WDT4_INDEX:
            Wdg4_Status = status;
            break;
#endif /* WDG_INSTANCE4_SUPPORT */
            /*#60 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

        case WDT5_INDEX:
            Wdg5_Status = status;
            break;
#endif /* WDG_INSTANCE5_SUPPORT */
            /*#70 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

        case WDT6_INDEX:
            Wdg6_Status = status;
            break;
#endif /* WDG_INSTANCE6_SUPPORT */
            /*#80 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

        case WDT8_INDEX:
            Wdg8_Status = status;
            break;
#endif /* WDG_INSTANCE8_SUPPORT */

        default:
            /*do nothing*/
            break;
        }
    }/*else not use*/
}
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
/** *****************************************************************************************************
 * \brief Setting Wdg Config parameters value check wether it is valid.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_140_ConfigCheck(const Wdg_ConfigType * configPtr)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr  - Pointer to WDG driver configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK/WDG_E_PARAM_POINTER/WDG_E_DISABLE_REJECTED/WDG_E_PARAM_CONFIG
 *
 * Description        : Setting Mode Config parameters value check wether it is valid.
 *
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Wdg_140_ConfigCheck(const Wdg_ConfigType *configPtr)
{
    Std_ReturnType errorId = E_OK;

    /*#10 null point check*/
    if (NULL_PTR == configPtr)
    {
        errorId = WDG_E_PARAM_POINTER;
    }
    else
    {
#if (WDG_DISABLE_ALLOWED==STD_OFF)

        /*#20 default off mode check*/
        if (WDGIF_OFF_MODE == configPtr->defaultMode)
        {
            errorId = WDG_E_DISABLE_REJECTED;
        }/*else not use*/

#endif /* WDG_DISABLE_ALLOWED */

        /*#30 default  mode value check*/
        if ((configPtr->defaultMode != WDGIF_FAST_MODE)
                && (configPtr->defaultMode != WDGIF_SLOW_MODE)
                && (configPtr->defaultMode != WDGIF_OFF_MODE))
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

        /*#40 maxtimeout/initTimeout value valid check*/
        if (configPtr->maxTimeout < configPtr->initTimeout)
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

        /*#50 maxtimeout/initTimeout value valid check*/
        if (WDG_IP_MIN_TIME_VAL == configPtr->maxTimeout)
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */

        /*#60 initTimeout value valid check*/
        if (WDG_IP_MIN_TIME_VAL == configPtr->initTimeout)
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/
    }

    return  errorId;
}

/** *****************************************************************************************************
 * \brief Setting Mode Config parameters value check wether it is valid.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_140_InitSettingModeConfigCheck(
 *                      const  Wdg_ModeConfigType *modeSettings,uint16 initTimeout)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)   :  modeSettings  - Wdg condig mode setting parameters point.
 *
 * Parameters (in)   :  initTimeout  - init wdg time out.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK/WDG_E_MODE_FAILED/WDG_E_PARAM_CONFIG
 *
 * Description        : Setting Mode Config parameters value check wether it is valid.
 *
 * \endverbatim
 * Traceability       : SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Wdg_140_InitSettingModeConfigCheck(
    const  Wdg_ModeConfigType *modeSettings, uint16 initTimeout)
{
    Std_ReturnType errorId = E_OK;

    /*#10 null point check*/
    if (NULL_PTR == modeSettings)
    {
        errorId = WDG_E_MODE_FAILED;
    }
    else
    {
        /*#20 clockFrequency value valid check*/
        if ((modeSettings->clockFrequency < WDG_IP_CLK_FREQUENCE)
                && (modeSettings->refreshTime > WDG_IP_MIN_TIME_VAL))
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

        /*#30 refreshTime/timeoutPeriod value valid check*/
        if ((modeSettings->refreshTime > WDG_IP_MAX_TIME_VAL)
                || (modeSettings->timeoutPeriod > WDG_IP_MAX_TIME_VAL))
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

        /*#40 timeoutBehavior value valid check*/
        if (modeSettings->timeoutBehavior > WDG_BOTH)
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

        /*#50 triggerCondition value valid check*/
        if ((modeSettings->triggerCondition != WINDOW_BASED_MODE)
                && (modeSettings->triggerCondition != NO_CONDITION_MODE))
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

        /*#60 refreshTime value valid check*/
        if ((modeSettings->triggerCondition == WINDOW_BASED_MODE)
                && (modeSettings->refreshTime > modeSettings->timeoutPeriod))
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/

        /*#70 refreshTime value valid check*/
        if ((modeSettings->triggerCondition == WINDOW_BASED_MODE)
                && (modeSettings->refreshTime > (uint32)initTimeout))
        {
            errorId = WDG_E_PARAM_CONFIG;
        }/*else not use*/
    }

    return  errorId;
}
/** *****************************************************************************************************
 * \brief This service initializes the WDG driver.
 *
 * \verbatim
 * Syntax             : void Wdg_140_Init(const Wdg_ConfigType *configPtr, uint8 instanceId)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to WDG driver configuration set.
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize all WDG relevant registers with the values of the structure
 *                      referenced by the parameter configPtr
 * \endverbatim
 * Traceability       : SWSR_WDG_007 SWSR_WDG_009 SWSR_WDG_011 SWSR_WDG_012 SWSR_WDG_013 SW_SM002
 *                      SWSR_WDG_014 SWSR_WDG_015 SWSR_WDG_016 SWSR_WDG_017 SWSR_WDG_018 SW_SM001
 *                      SWSR_WDG_020 SWSR_WDG_037 SWSR_WDG_072 SWSR_WDG_073 SWSR_WDG_078 SW_SM006 SW_SM005
 *******************************************************************************************************/
void Wdg_140_Init(const Wdg_ConfigType *configPtr, uint8 instanceId)
{
    Std_ReturnType errorId;
    uint8  i = WDT_IP_ZERO;
    /*#10 instanceId value valid check*/
    errorId = Wdg_140_InstanceIdValidCheck(instanceId);

    if (E_OK == errorId)
    {
        /*#20 instanceId value match config valid check*/
        errorId = Wdg_140_InstanceIdMatchConfigCheck(configPtr, instanceId);
    }
    else
    {
        errorId = WDG_E_PARAM_INSTANCE;
    }

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK == errorId)
    {
        /*#30 wdg init status valid check*/
        if (WDG_UNINIT != Wdg_140_GetWorkStatus(instanceId))
        {
            errorId = WDG_E_INIT_FAILED;
        }/*else not use*/
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */

    if (E_OK == errorId)
    {
        /*#40 wdg config data valid check*/
        errorId = Wdg_140_ConfigCheck(configPtr);
    }/*else not use*/

    while ((E_OK == errorId) && (i < (uint8)WDG_MODE_SETTING_ARRAY_SIZE))
    {
        /*#50 wdg mode config data valid check*/
        errorId = Wdg_140_InitSettingModeConfigCheck(&configPtr->modeSettings[i], configPtr->initTimeout);
        i++;
    }

    if (E_OK == errorId)
    {
        /*#60 enable and init Wdg*/
        errorId = Wdg_Ip_Init(&configPtr->modeSettings[configPtr->defaultMode], configPtr->initTimeout,
                              instanceId);

        if (E_NOT_OK == errorId)
        {
            errorId = WDG_E_INIT_FAILED;
        }
        else
        {
            Wdg_Ip_GlbResetEn(instanceId);
            /*#70 save Wdg config point*/
            Wdg_140_SetInstanceIdConfigPtr(configPtr, instanceId);
#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
            /*#80 switch wdg work statue*/
            Wdg_140_SetWorkStatus(WDG_IDLE, instanceId);
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */

        }
    }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK != errorId)
    {
        Wdg_140_ReportError(WDG_MODULE_ID, instanceId, WDG_INIT_SERVICE_ID, errorId);
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
}

/** *****************************************************************************************************
 * \brief This function triggers the servicing of the watchdog.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Wdg_140_SetMode(WdgIf_ModeType mode, uint8 instanceId)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : mode - User mode (Non-Privileged mode).
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Always returns E_OK, Wdg_SetMode is made available because
 *                      WDG Interface layer expects this function to be present.
 * \endverbatim
 * Traceability       : SWSR_WDG_005 SWSR_WDG_006 SWSR_WDG_007 SWSR_WDG_009 SWSR_WDG_010
 *                      SWSR_WDG_019 SWSR_WDG_020 SWSR_WDG_021 SWSR_WDG_022 SWSR_WDG_023
 *                      SWSR_WDG_024 SWSR_WDG_025 SWSR_WDG_026 SWSR_WDG_027 SWSR_WDG_028  SW_SM007
 *                      SWSR_WDG_044 SWSR_WDG_073 SWSR_WDG_078 SW_SM002 SW_SM001 SW_SM006 SW_SM005
 *******************************************************************************************************/
Std_ReturnType Wdg_140_SetMode(WdgIf_ModeType mode, uint8 instanceId)
{
    Std_ReturnType errorId;
    const Wdg_ConfigType *configPtr;
    /*#10 instanceId value valid check*/
    errorId = Wdg_140_InstanceIdValidCheck(instanceId);

    if (E_NOT_OK == errorId)
    {
        errorId = WDG_E_PARAM_INSTANCE;
    }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK == errorId)
    {
        /*#20 wdg init status valid check*/
        if (Wdg_140_GetWorkStatus(instanceId) !=  WDG_IDLE)
        {
            errorId = WDG_E_DRIVER_STATE;
        }/*else not use*/
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */

    if (E_OK == errorId)
    {
        /*#30 instanceId value match config valid check*/
        configPtr = Wdg_140_GetInstanceIdConfigPtr(instanceId);
        errorId = Wdg_140_InstanceIdMatchConfigCheck(configPtr, instanceId);
    }/*else not use*/

    if (E_OK == errorId)
    {
        /*#40  off mode check*/
#if (WDG_DISABLE_ALLOWED == STD_OFF)

        if (WDGIF_OFF_MODE == mode)
        {
            errorId = WDG_E_DISABLE_REJECTED;
        }/*else not use*/

#endif /* WDG_DISABLE_ALLOWED */

        /*#50 mode value valid check*/
        if (((mode != WDGIF_FAST_MODE)
                && (mode != WDGIF_OFF_MODE)
                && (mode != WDGIF_SLOW_MODE)))
        {
            errorId = WDG_E_PARAM_MODE;
        }/*else not use*/
    }/*else not use*/

    if (E_OK == errorId)
    {
        SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
        /*#60 switch wdg work statue*/
#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
        Wdg_140_SetWorkStatus(WDG_BUSY, instanceId);
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
        /*#70 exec wdg mode switch*/
        errorId = Wdg_Ip_SetMode(&configPtr->modeSettings[mode], instanceId);
        /*#80 switch wdg work statue*/
#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
        Wdg_140_SetWorkStatus(WDG_IDLE, instanceId);
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();

        if (E_NOT_OK == errorId)
        {
            errorId = WDG_E_MODE_FAILED;
        }/*else not use*/
    }/*else not use*/

    if (E_OK != errorId)
    {
#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
        Wdg_140_ReportError(WDG_MODULE_ID, instanceId, WDG_SETMODE_SERVICE_ID, errorId);
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
        errorId = E_NOT_OK;
    }/*else not use*/

    return  errorId;
}

/** *****************************************************************************************************
 * \brief Sets the timeout value for the trigger counter.
 *
 * \verbatim
 * Syntax             : void Wdg_140_SetTriggerCondition(uint16 timeout, uint8 instanceId)
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timeout - Timeout value (milliseconds) for setting the trigger counter
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Always returns E_OK, Wdg_SetMode is made available because
 *                      WDG Interface layer expects this function to be present.
 * \endverbatim
 * Traceability       : SWSR_WDG_003 SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_029 SWSR_WDG_030
 *                      SWSR_WDG_032 SWSR_WDG_033 SWSR_WDG_034 SWSR_WDG_051 SWSR_WDG_073
 *                      SWSR_WDG_075 SWSR_WDG_078 SW_SM002 SW_SM001 SW_SM006 SWSR_WDG_031
 *******************************************************************************************************/
void Wdg_140_SetTriggerCondition(uint16 timeout, uint8 instanceId)
{
    Std_ReturnType errorId;
#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)
    const Wdg_ConfigType *configPtr;
#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
    /*#10 instanceId value valid check*/
    errorId = Wdg_140_InstanceIdValidCheck(instanceId);

    if (E_NOT_OK == errorId)
    {
        errorId = WDG_E_PARAM_INSTANCE;
    }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK == errorId)
    {
        /*#20 wdg init status valid check*/
        if (Wdg_140_GetWorkStatus(instanceId) ==  WDG_UNINIT)
        {
            errorId = WDG_E_DRIVER_STATE;
        }/*else not use*/
    }/*else not use*/

    if (E_OK == errorId)
    {
        /*#30 instanceId value match config valid check*/
        configPtr = Wdg_140_GetInstanceIdConfigPtr(instanceId);
        errorId = Wdg_140_InstanceIdMatchConfigCheck(configPtr, instanceId);
    }/*else not use*/

    if (E_OK == errorId)
    {
        /*#40 timeout value valid check*/
        if (timeout > configPtr->maxTimeout)
        {
            errorId = WDG_E_PARAM_TIMEOUT;
        }/*else not use*/
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */

    if (E_OK == errorId)
    {
        /*#50 exec Set Trigger Condition*/
        SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
        Wdg_Ip_SetTriggerCondition(timeout, instanceId);
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
    }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK != errorId)
    {
        Wdg_140_ReportError(WDG_MODULE_ID, instanceId, WDG_SETTRIGGERCONDITION_SERVICE_ID, errorId);
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
}

#if (STD_ON == WDG_VERSION_INFO_API)
/** *****************************************************************************************************
 * \brief This service returns the version information of this module
 *
 * \verbatim
 * Syntax             : void Wdg_140_Instance1_Wdt_GetVersionInfo(Std_VersionInfoType *verInfoPtr, uint8 instanceId)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : verInfoPtr - Pointer to where to store the version information of this module.
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Return value       : None
 *
 * Description        : This service returns the version information of this module
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_031 SWSR_WDG_051 SW_SM006
 *                      SWSR_WDG_058 SWSR_WDG_073 SWSR_WDG_075 SWSR_WDG_078
 *******************************************************************************************************/
void Wdg_140_GetVersionInfo(Std_VersionInfoType *verInfoPtr, uint8 instanceId)
{
    Std_ReturnType errorId;
    /*#10 instanceId value valid check*/
    errorId = Wdg_140_InstanceIdValidCheck(instanceId);

    if (E_OK == errorId)
    {
        /*#20 null point check*/
        if (NULL_PTR == verInfoPtr)
        {
            errorId = WDG_E_PARAM_POINTER;
        }
        else
        {
            /*#30 obtain version info */
            verInfoPtr->vendorID = WDG_H_VENDOR_ID;
            verInfoPtr->moduleID = WDG_MODULE_ID;
            verInfoPtr->sw_major_version = WDG_H_SW_MAJOR_VERSION;
            verInfoPtr->sw_minor_version = WDG_H_SW_MINOR_VERSION;
            verInfoPtr->sw_patch_version = WDG_H_SW_PATCH_VERSION;
        }
    }
    else
    {
        errorId = WDG_E_PARAM_INSTANCE;
    }

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK != errorId)
    {
        Wdg_140_ReportError(WDG_MODULE_ID, instanceId, WDG_GETVERSIONINFO_SERVICE_ID, errorId);
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
}
#endif  /*WDG_VERSION_INFO_API*/
/** *****************************************************************************************************
 * \brief This function triggers the servicing of the watchdog and feed dog.
 *
 * \verbatim
 * Syntax             : void Wdg_140_TriggerRoutine(uint8 instanceId)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is the watchdog trigger
 * \endverbatim
 * Traceability       : SWSR_WDG_003 SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_031 SWSR_WDG_051 SW_SM002
 *                      SWSR_WDG_058 SWSR_WDG_073 SWSR_WDG_075 SWSR_WDG_078 SW_SM006 SW_SM001
 *******************************************************************************************************/
void Wdg_140_TriggerRoutine(uint8 instanceId)
{
    Std_ReturnType errorId;
    /*#10 instanceId value valid check*/
    errorId = Wdg_140_InstanceIdValidCheck(instanceId);

    if (E_NOT_OK == errorId)
    {
        errorId = WDG_E_PARAM_INSTANCE;
    }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK == errorId)
    {
        /*#20 wdg init status valid check*/
        if (Wdg_140_GetWorkStatus(instanceId) ==  WDG_UNINIT)
        {
            errorId = WDG_E_DRIVER_STATE;
        }/*else not use*/
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */

    if (E_OK == errorId)
    {
        /*#30 exec Set Trigger Routine*/
        SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
        Wdg_Ip_TriggerRoutine(instanceId);
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
    }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK != errorId)
    {
        Wdg_140_ReportError(WDG_MODULE_ID, instanceId, WDG_TRIGGERROUTINE_SERVICE_ID, errorId);
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */
}

/** *****************************************************************************************************
 * \brief This function is interrupt service handle funtion
 *
 * \verbatim
 * Syntax             : void Wdg_140_CommonInterrupt(uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is interrupt service handle funtion
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
void Wdg_140_CommonInterrupt(const uint8  instanceId)
{
    Std_ReturnType errorId = E_OK;
    uint8 instanceIdConverted = instanceId;
    const Wdg_ConfigType *configPtr;

    /*#10 calcule instanceId value*/
    /* If instance == 7, it represents WDT8, which is converted to the location of WDT8 in the array */
    if (WDG_INSTANCE_NUM == instanceId)
    {
        instanceIdConverted = instanceId - 1U;
    }
    else if ((WDG_INSTANCE_NUM - 1U) == instanceId)
    {
        errorId = E_NOT_OK;
    }
    else
    {
        /*do nothing*/
    }

    if (E_OK == errorId)
    {
        /*#20 instanceId value valid check*/
        errorId = Wdg_140_InstanceIdValidCheck(instanceIdConverted);
    }/*else not use*/

    if (E_OK == errorId)
    {
        /*#30 Whether it is expect interrupt check*/
        errorId =  Wdg_Ip_ExpectedInterruptCheck(instanceIdConverted);
        /*#40 clear interrupt*/
        Wdg_Ip_ClearInterruptFlag(instanceIdConverted);
    }/*else not use*/

#if (WDG_SAFETY_ENABLE == STD_ON || WDG_DEV_ERROR_DETECT == STD_ON)

    if (E_OK == errorId)
    {
        /*#50 wdg init status valid check*/
        if (Wdg_140_GetWorkStatus(instanceIdConverted) ==  WDG_UNINIT)
        {
            errorId = E_NOT_OK;
        }/*else not use*/
    }/*else not use*/

#endif /* WDG_SAFETY_ENABLE || WDG_DEV_ERROR_DETECT */

    if (E_OK == errorId)
    {
        /*#60 instanceId value match config valid check*/
        configPtr = Wdg_140_GetInstanceIdConfigPtr(instanceIdConverted);

        if (NULL_PTR == configPtr)
        {
            errorId = E_NOT_OK;
        }/*else not use*/
    }/*else not use*/

    if (E_OK == errorId)
    {
        if (NULL_PTR != configPtr->pfNotification)
        {
            /*#70 notify user*/
            configPtr->pfNotification();
        }/*else not use*/
    }/*else not use*/
}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"
#endif /* WDG_INSTANCE1_SUPPORT||WDG_INSTANCE2_SUPPORT||WDG_INSTANCE3_SUPPORT||WDG_INSTANCE4_SUPPORT||WDG_INSTANCE5_SUPPORT||WDG_INSTANCE6_SUPPORT||WDG_INSTANCE8_SUPPORT */
#ifdef __cplusplus
}
#endif
/* End of file */


