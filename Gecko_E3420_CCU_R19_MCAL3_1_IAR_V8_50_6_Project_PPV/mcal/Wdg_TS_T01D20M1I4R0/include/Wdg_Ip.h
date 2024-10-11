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
 *  \file     Wdg_Ip.h                                                                                  *
 *  \brief    This file contains interface header for WDG MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef WDG_IP_H
#define WDG_IP_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/

#include "Wdg_Types.h"
#include "Wdg_Cfg.h"
#include "Wdg_140_Instance1_Cfg.h"
#include "Wdg_140_Instance2_Cfg.h"
#include "Wdg_140_Instance3_Cfg.h"
#include "Wdg_140_Instance4_Cfg.h"
#include "Wdg_140_Instance5_Cfg.h"
#include "Wdg_140_Instance6_Cfg.h"
#include "Wdg_140_Instance8_Cfg.h"
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

/** \brief SemiDriver Instruments Vendor ID */
#define WDG_IP_H_VENDOR_ID    0x8C
/**
 *  \brief WDG Driver Module version Info
 *  Defines for WDG version define
 */
/** \brief AUTOSAR Major version specification implemented by WDG Driver */
#define WDG_IP_H_AR_RELEASE_MAJOR_VERSION    4
/** \brief AUTOSAR Minor  version specification implemented by WDG Driver */
#define WDG_IP_H_AR_RELEASE_MINOR_VERSION    3
/** \brief AUTOSAR Patch version specification implemented by WDG Driver */
#define WDG_IP_H_AR_RELEASE_REVISION_VERSION 1

/** \brief Driver Implementation Major Version */
#define WDG_IP_H_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_IP_H_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_IP_H_SW_PATCH_VERSION    0

/**
 *  \brief WDG Driver Module  Value Setting Info
 *
 *  Defines for WDG value define
 */
/** \brief Driver Wdg main clk Frequence */
#define WDG_IP_CLK_FREQUENCE (24000000u)
/** \brief Driver max time value */
#define WDG_IP_MAX_TIME_VAL  (0x3FFFu)
/** \brief Driver min time value */
#define WDG_IP_MIN_TIME_VAL  (0x0u)
/** \brief define 0 = zero */
#define WDT_IP_ZERO       (0x0U)
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
 * Syntax             : Std_ReturnType Wdg_Ip_Init
 *                      (const Wdg_ModeConfigType *pModeSetting, uint16 initTimeout, uint8 instanceId)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pModeSetting - Pointer to WDG driver mode configuration set.
 *
 * Parameters (in)    : initTimeout - init wdg time out.
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_NOT_OK/E_OK
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize all WDG relevant registers with the values of the structure
 *                      referenced by the parameter configPtr
 * \endverbatim
 * Traceability       : SWSR_WDG_007 SWSR_WDG_009 SWSR_WDG_011 SWSR_WDG_012 SWSR_WDG_013
 *                      SWSR_WDG_014 SWSR_WDG_015 SWSR_WDG_016 SWSR_WDG_017 SWSR_WDG_018
 *                      SWSR_WDG_020 SWSR_WDG_037 SWSR_WDG_072 SWSR_WDG_073 SWSR_WDG_078
 *******************************************************************************************************/
Std_ReturnType  Wdg_Ip_Init(const Wdg_ModeConfigType *pModeSetting, uint16 initTimeout,
                            uint8 instanceId);

/** *****************************************************************************************************
 * \brief This function triggers the servicing of the watchdog.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Wdg_Ip_SetMode(const Wdg_ModeConfigType *pModeSetting, uint8 instanceId)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pModeSetting - Pointer to WDG driver mode configuration set.
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_NOT_OK/E_OK
 *
 * Description        : Always returns E_OK, Wdg_SetMode is made available because
 *                      WDG Interface layer expects this function to be present.
 * \endverbatim
 * Traceability       : SWSR_WDG_005 SWSR_WDG_006 SWSR_WDG_007 SWSR_WDG_009 SWSR_WDG_010
 *                      SWSR_WDG_019 SWSR_WDG_020 SWSR_WDG_021 SWSR_WDG_022 SWSR_WDG_023
 *                      SWSR_WDG_024 SWSR_WDG_025 SWSR_WDG_026 SWSR_WDG_027 SWSR_WDG_028
 *                      SWSR_WDG_044 SWSR_WDG_073 SWSR_WDG_078
 *******************************************************************************************************/
Std_ReturnType  Wdg_Ip_SetMode(const Wdg_ModeConfigType *pModeSetting, uint8 instanceId);


/** *****************************************************************************************************
 * \brief Sets the timeout value for the trigger counter.
 *
 * \verbatim
 * Syntax             : void Wdg_Ip_SetTriggerCondition(uint16 timeout, uint8 instanceId)
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
 * Traceability       : SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_029 SWSR_WDG_030 SWSR_WDG_031
 *                      SWSR_WDG_032 SWSR_WDG_033 SWSR_WDG_034 SWSR_WDG_051 SWSR_WDG_073
 *                      SWSR_WDG_075
 *******************************************************************************************************/
void  Wdg_Ip_SetTriggerCondition(uint16 timeout, uint8 instanceId);

/** *****************************************************************************************************
 * \brief This function Wdg Ip clear interrupt state.
 *
 * \verbatim
 * Syntax             : void Wdg_Ip_ClearInterruptFlag(uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :  This function Wdg Ip clear interrupt state.
 * \endverbatim
 * Traceability       : SWSR_WDG_074
 *******************************************************************************************************/
void  Wdg_Ip_ClearInterruptFlag(uint8 instanceId);

/** *****************************************************************************************************
 * \brief This function checks if wdt HW interrupt as expected or not
 *
 * \verbatim
 * Syntax             : Std_ReturnType Wdg_Ip_ExpectedInterruptCheck(uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_NOT_OK/E_OK
 *
 * Description        : This function checks if wdt HW interrupt as expected or not
 * \endverbatim
 * Traceability       : SW_SM004
 *******************************************************************************************************/
Std_ReturnType Wdg_Ip_ExpectedInterruptCheck(uint8 instanceId);
/** *****************************************************************************************************
 * \brief This function triggers the servicing of the watchdog and feed dog.
 *
 * \verbatim
 * Syntax             : void Wdg_Ip_TriggerRoutine(uint8 instanceId)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is the watchdog trigger
 * \endverbatim
 * Traceability       : SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_031 SWSR_WDG_051
 *                      SWSR_WDG_058 SWSR_WDG_073 SWSR_WDG_075
 *******************************************************************************************************/
void  Wdg_Ip_TriggerRoutine(uint8 instanceId);
/** *****************************************************************************************************
 * \brief This function wdg gloable reset enable.
 *
 * \verbatim
 * Syntax             : void Wdg_Ip_GlbResetEn(uint8 instanceId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : wdg gloable reset enable.
 * \endverbatim
 * Traceability       : SWSR_WDG_075
 *******************************************************************************************************/
void  Wdg_Ip_GlbResetEn(uint8 instanceId);
#endif /* WDG_INSTANCE1_SUPPORT||WDG_INSTANCE2_SUPPORT||WDG_INSTANCE3_SUPPORT||WDG_INSTANCE4_SUPPORT||WDG_INSTANCE5_SUPPORT||WDG_INSTANCE6_SUPPORT||WDG_INSTANCE8_SUPPORT */
#ifdef __cplusplus
}
#endif

#endif  /* WDG_IP_H */
/* End of file */
