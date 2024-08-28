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
 *  \file     Wdg_140_Instance2_Wdt.h                                                                   *
 *  \brief    This file contains interface header for WDG2 MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef WDG_140_INSTANCE2_WDT_H
#define WDG_140_INSTANCE2_WDT_H

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
 * type, with common or separate Hardware Objects E3 support WDT1~WDT6,WDT8 corresponding
 * the instanceId 1~6 and 8.
 */

/** @{ */
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Wdg_140_Instance2_Cfg.h"
/**
 *
 * \addtogroup MCAL_WDG2_API WDG2 API Driver
 */
/** @{ */

/**
 *  \name Wdg2 Driver Module SW Version Info
 *  Defines for Wdg Driver version used for compatibility checks
 * @{
 */
/** \brief Driver Implementation Major Version */
#define WDG_140_INSTANCE2_WDT_H_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_140_INSTANCE2_WDT_H_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_140_INSTANCE2_WDT_H_SW_PATCH_VERSION    0
/* @} */


/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

/*none*/

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

#if (WDG_INSTANCE2_SUPPORT == STD_ON)
/** *****************************************************************************************************
 * \brief This service initializes the WDG2 driver.
 *
 * \verbatim
 * Syntax             : void Wdg_140_Instance2_Wdt_Init(const Wdg_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ConfigPtr - Pointer to WDG driver configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize all WDG2 relevant registers with the values of the structure
 *                      referenced by the parameter ConfigPtr
 * \endverbatim
 * Traceability       : SWSR_WDG_007 SWSR_WDG_009 SWSR_WDG_011 SWSR_WDG_012 SWSR_WDG_013 SW_SM002
 *                      SWSR_WDG_014 SWSR_WDG_015 SWSR_WDG_016 SWSR_WDG_017 SWSR_WDG_018 SW_SM001
 *                      SWSR_WDG_020 SWSR_WDG_037 SWSR_WDG_072 SWSR_WDG_073 SWSR_WDG_078 SW_SM006 SW_SM005
 *******************************************************************************************************/
void  Wdg_140_Instance2_Wdt_Init(const Wdg_ConfigType *ConfigPtr);

/** *****************************************************************************************************
 * \brief This function triggers the servicing of the watchdog.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Wdg_140_Instance2_Wdt_SetMode(WdgIf_ModeType Mode)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Mode - User mode (Non-Privileged mode).
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
Std_ReturnType Wdg_140_Instance2_Wdt_SetMode(WdgIf_ModeType Mode);

/** *****************************************************************************************************
 * \brief Sets the timeout value for the trigger counter.
 *
 * \verbatim
 * Syntax             : void Wdg_140_Instance2_Wdt_SetTriggerCondition(uint16 timeout)
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : mode - Timeout value (milliseconds) for setting the trigger counter
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Sets the timeout value for the trigger counter.
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_003 SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_029 SWSR_WDG_030
 *                      SWSR_WDG_032 SWSR_WDG_033 SWSR_WDG_034 SWSR_WDG_051 SWSR_WDG_073
 *                      SWSR_WDG_075 SWSR_WDG_078 SW_SM002 SW_SM001 SW_SM006 SWSR_WDG_031
 *******************************************************************************************************/
void  Wdg_140_Instance2_Wdt_SetTriggerCondition(uint16 timeout);

/** *****************************************************************************************************
 * \brief This function triggers the servicing of the watchdog and feed dog.
 *
 * \verbatim
 * Syntax             : void Wdg_140_Instance2_Wdt_TriggerRoutine()
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
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
void  Wdg_140_Instance2_Wdt_TriggerRoutine(void);

#if (STD_ON == WDG_VERSION_INFO_API)

/** *****************************************************************************************************
 * \brief This service returns the version information of this module
 *
 * \verbatim
 * Syntax             : void Wdg_140_Instance2_Wdt_GetVersionInfo(Std_VersionInfoType* verInfoPtr)
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
 *
 * Return value       : None
 *
 * Description        : This service returns the version information of this module
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_031 SWSR_WDG_051 SW_SM006
 *                      SWSR_WDG_058 SWSR_WDG_073 SWSR_WDG_075 SWSR_WDG_078
 *******************************************************************************************************/
void  Wdg_140_Instance2_Wdt_GetVersionInfo(Std_VersionInfoType *verInfoPtr);
#endif /* STD_ON == WDG_VERSION_INFO_API */
#endif /* WDG_INSTANCE2_SUPPORT == STD_ON */
/** @} */
#ifdef __cplusplus
}
#endif
/** @} */
#endif /* WDG_140_INSTANCE2_WDT_H */
/* End of file */

