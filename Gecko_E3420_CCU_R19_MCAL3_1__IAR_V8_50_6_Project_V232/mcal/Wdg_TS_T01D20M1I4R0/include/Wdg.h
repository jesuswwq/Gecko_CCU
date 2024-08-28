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
 *  \file     Wdg.h                                                                                     *
 *  \brief    This file contains interface header for WDG MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef WDG_H
#define WDG_H

/**
 *
 * \addtogroup MCAL_WDG_API WDG Driver
 *
 * The WDG Driver MCAL provides low level access to onbaord WDG peripheral
 * present on Device.Wdg's timeout behavior(RESET/INTERRUPT),timeout counter,
 * trigger condition mode(window/normal mode) and timeout externel signal
 * output support and so on.
 * The WDG Driver implements a standardized interface specified in the
 * AUTOSAR_SWS_WDGDriver document.For example Wdg_init,Wdg_SetMode,Wdg_GetVersion,
 * Wdg_SetTriggerCondition,and Wdg_SetTriggerRoutine interface,and support
 * instanceId 1~6 and 8.So each of the above interfaces have it own independent name.
 * The WDG Driver is part of the Communication Stack in the AUTOSAR Basic
 * Software (BSW),include EcuM,WdgM,WdgIf can call corresponding interface,reference
 * AUTOSAR_SWS_WDGDriver.pdf sequence discription.
 * The WDG Hardware Unit cntrolled by WDG Driver combines one or several WDG controllers,
 * which may be located on-chip or as external standalone devices of the same
 * type, with common or separate
 */

/** @{ */

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Wdg_Types.h"
#include "Wdg_Cfg.h"
#ifdef __cplusplus
extern "C"
{
#endif
/**
 *
 * \addtogroup MCAL_WDG_MACROS WDG Driver Macros
 */
/** @{ */
/**
 *  \name WDG Driver Macros ID Info
 *  @{
 */
/** \brief SemiDriver Instruments Vendor ID */
#define WDG_H_VENDOR_ID    0x8C
/** \brief WDG Driver Module ID */
#define WDG_MODULE_ID          102U
/* @} */
/**
*  \name WDG Driver Macros version Info
 *  Defines for WDG Driver Macros AUTOSAR version used for compatibility checks
 *  @{
 */
/** \brief AUTOSAR Major version specification implemented by WDG Driver */
#define WDG_H_AR_RELEASE_MAJOR_VERSION    4
/** \brief AUTOSAR Minor  version specification implemented by WDG Driver */
#define WDG_H_AR_RELEASE_MINOR_VERSION    3
/** \brief AUTOSAR Patch version specification implemented by WDG Driver */
#define WDG_H_AR_RELEASE_REVISION_VERSION 1
/* @} */
/**
 *  \name WDG Driver Module SW Version Info
 *  Defines for WDG Driver version used for compatibility checks
 *  @{
 */
/** \brief Driver Implementation Major Version */
#define WDG_H_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_H_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_H_SW_PATCH_VERSION    0
/* @} */

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \name WDG Error Codes
 *  Error codes returned by Driver functions
 *  @{
 */
/** \brief ERROR:Invalid driver state */
/** Traceability: SWSR_WDG_004 SWSR_WDG_009 */
#define WDG_E_DRIVER_STATE     0x10U
/** \brief ERROR:Invalid mode param */
/** Traceability: SWSR_WDG_004 SWSR_WDG_025 SWSR_WDG_026 */
#define WDG_E_PARAM_MODE       0x11U
/** \brief ERROR:Invalid config param */
/** Traceability: SWSR_WDG_004 SWSR_WDG_017 */
#define WDG_E_PARAM_CONFIG     0x12U
/** \brief ERROR:Invalid timeout value */
/** Traceability: SWSR_WDG_004 SWSR_WDG_034 */
#define WDG_E_PARAM_TIMEOUT    0x13U
/** \brief ERROR:Invalid NULL ptr param */
/** Traceability: SWSR_WDG_004 SWSR_WDG_036 */
#define WDG_E_PARAM_POINTER    0x14U
/** \brief ERROR:Invalid configuration set selection */
#define WDG_E_INIT_FAILED      0x15U
/** \brief ERROR:extern Failed mode for set mode failed*/
/** Traceability: SWSR_WDG_004 SWSR_WDG_005 SWSR_WDG_016 SWSR_WDG_023 */
#define WDG_E_MODE_FAILED      0x20U
/** \brief ERROR:Invalid OFF mode not allow error selection */
/** Traceability: SWSR_WDG_004 SWSR_WDG_006 SWSR_WDG_015 SWSR_WDG_024 */
#define WDG_E_DISABLE_REJECTED 0x21U
/** \brief ERROR:Invalid instance selection */
#define WDG_E_PARAM_INSTANCE   0x80U
/* @} */

/**
 *  \name WDG Service Ids
 *  The Service Id is one of the argument to Det_ReportError function and is
 *  used to identify the source of the error
 *  @{
 */
/** \brief Wdg_Init() */
/** Traceability: SWSR_WDG_012 */
#define WDG_INIT_SERVICE_ID                 0x00u
/** \brief Wdg_SetMode() */
/** Traceability: SWSR_WDG_019 */
#define WDG_SETMODE_SERVICE_ID              0x10u
/** \brief Wdg_SetTriggerCondition() */
/** Traceability: SWSR_WDG_030 */
#define WDG_SETTRIGGERCONDITION_SERVICE_ID  0x03u
/** \brief Wdg_GetVersionInfo() */
/** Traceability: SWSR_WDG_035 */
#define WDG_GETVERSIONINFO_SERVICE_ID       0x04u
/** \brief Wdg_Trigger() */
/** Traceability: SWSR_WDG_060 */
#define WDG_TRIGGERROUTINE_SERVICE_ID       0x05u
/* @} */
/** @} */
/** @} */
/** @} */


/** \brief For no waring for unuse parameters */
#define WDG_DUMMY_STATEMENT(ret)            ((void)ret)

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/

/*none */

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/*none*/

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/*none*/

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#if ((WDG_INSTANCE1_SUPPORT == STD_ON)\
  || (WDG_INSTANCE2_SUPPORT == STD_ON)\
  || (WDG_INSTANCE3_SUPPORT == STD_ON)\
  || (WDG_INSTANCE4_SUPPORT == STD_ON)\
  || (WDG_INSTANCE5_SUPPORT == STD_ON)\
  || (WDG_INSTANCE6_SUPPORT == STD_ON)\
  || (WDG_INSTANCE8_SUPPORT == STD_ON))

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
void  Wdg_140_Init(const Wdg_ConfigType *configPtr, uint8 instanceId);

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
Std_ReturnType Wdg_140_SetMode(WdgIf_ModeType mode, uint8 instanceId);

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
void  Wdg_140_SetTriggerCondition(uint16 timeout, uint8 instanceId);
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
void  Wdg_140_GetVersionInfo(Std_VersionInfoType *verInfoPtr, uint8 instanceId);
#endif /*WDG_VERSION_INFO_API*/

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
void  Wdg_140_TriggerRoutine(uint8 instanceId);

/** *****************************************************************************************************
 * \brief This function is interrupt service handle funtion
 *
 * \verbatim
 * Syntax             : void Wdg_140_CommonInterrupt(uint8 instanceId)
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
 * Description        : This function is interrupt service handle funtion
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004
 *******************************************************************************************************/
void Wdg_140_CommonInterrupt(const uint8  instanceId);
#endif/* WDG_INSTANCE1_SUPPORT||WDG_INSTANCE2_SUPPORT||WDG_INSTANCE3_SUPPORT||WDG_INSTANCE4_SUPPORT||WDG_INSTANCE5_SUPPORT||WDG_INSTANCE6_SUPPORT||WDG_INSTANCE8_SUPPORT */
#ifdef __cplusplus
}

#endif
#endif /* WDG_H */
/* End of file */

