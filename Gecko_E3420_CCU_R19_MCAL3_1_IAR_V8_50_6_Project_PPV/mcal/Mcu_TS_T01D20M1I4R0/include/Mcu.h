/** *****************************************************************************************************
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
 *  \file     Mcu.h                                                                                     *
 *  \brief    This file contains interface header for MCU MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/01     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"
{
#endif
/**
 *
 * \defgroup MCAL_MCU MCU Driver
 * The Mcu Driver MCAL provides the service for basic microcontroller initialization.<br>
 * The Mcu Driver implements a standardized interface specified in the AUTOSAR_SWS_McuDriver document.<br>
 * The Mcu Driver is part of the AUTOSAR MCAL<br>
 * The Mcu Driver is implemented in two layers of E3 family,
 * one is the MCU service layer, which is mainly provide users with external interface functions for or mcu initialization,
 * clock initialization, ram initialization, activation of reduced power mode, reset and reset reason, etc.
 * And other is MCU_IP layer provide the hardware service layer, which is mainly responsible for registers reading and writing. etc. <br>
 *
 * \sa MCAL_MCU_MACRO
 * \sa MCAL_MCU_CFG
 * \sa MCAL_MCU_API
 *
 * \{
 */
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_GeneralTypes.h"
/** Traceability       : SWSR_MCU_001*/
#include "Mcu_Cfg.h"
#include "Mcu_Rtc.h"
#include "Mcu_RtcMode.h"
#include "Mcu_PllDrv.h"
#include "Mcu_Reset.h"
#include "Mcu_Soc.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_MCU_MACRO MCU Macro.
 *
 * This files defines MCU MCAL macros.
 *  @{
 */
/** \} */

/**
 *  \defgroup MCAL_MCU_API MCU API.
 *
 * This files defines MCU MCAL API.
 *  @{
 */
/** \} */

/**
 *  \defgroup MCAL_MCU_CFG MCU Configuration.
 *
 * This files defines MCU MCAL Configuration.
 *  @{
 */
/** \} */

/**
 *  \addtogroup MCAL_MCU_MACRO MCU Macro
 *  @{
 *
 */

/**
 *  \name Mcu Driver Module SW Version Info
 *
 *  Defines for MCU Driver version used for compatibility checks
 *  @{
 */

#define MCU_VENDOR_ID 0x8C
/** \} */
/** \} */
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/


/** Traceability       : SWSR_MCU_009 SWSR_MCU_011*/
typedef enum
{
    MCU_PLL_LOCKED = 0x5Au,           /**< @brief PLL is locked. */
    MCU_PLL_UNLOCKED = 0xA5U,         /**< @brief PLL is unlocked. */
    MCU_PLL_STATUS_UNDEFINED = 0xF0U, /**< @brief PLL Status is unknown. */
} Mcu_PllStatusType;

typedef struct
{
    const Mcu_ClkNodeType *const *clkPrepare;
    const Mcu_ClkNodeType *const *clkEnable;
    const Mcu_ClkNodeType *const *clkDisable;
    const Mcu_ResetSigType *const *rstDeassert;
    const Mcu_ResetSigType *const *rstAssert;
    const Mcu_PllSpreadConfigType *pllSpread;
} Mcu_ClockConfigType;


typedef struct
{
    const Mcu_PowerDomType *dom;
} Mcu_NormalModeConfigType;



/**
* \brief   Mcu_ConfigType [SWS_Mcu_0024]
*
* \details A pointer to such a structure is provided to the MCU initialization routines for
*          configuration.
*/
/** Traceability       : SWSR_MCU_007 SWSR_MCU_008*/
typedef struct
{
    Mcu_RamSectionType numRamSections;
    Mcu_ClockType numClkCfgs;
#if (0U != MCU_MAX_RAMCFGS )
    const Mcu_RamConfigType (*ramCfgsPtr)[MCU_MAX_RAMCFGS];
#else
    const Mcu_RamConfigType (*ramCfgsPtr);
#endif
    const Mcu_ClockConfigType(*clkCfgsPtr)[MCU_MAX_CLKCFGS];
    const Mcu_HwIpsConfigType *hwIpsCfgPtr;
    const Mcu_NormalModeConfigType *normalModeCfgPtr;
    const Mcu_RtcModeConfigType *rtcModeCfgPtr;
    const Mcu_PmuCtrlConfigType *pwrCtrlCfgPtr;
} Mcu_ConfigType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#if defined(CFG_MULTI_CORE_OS)
extern const Mcu_ConfigType Mcu_Cfg[];
#else
extern const Mcu_ConfigType Mcu_Cfg;
#endif /**#if defined(CFG_MULTI_CORE_OS)*/
/** *****************************************************************************************************
 * \brief This function check whether driver is initialized.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_EnterCheck(const uint8 serviceId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : serviceId - Module Service Id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return the errorId, which record current error status.
 *
 * Description        : This function shall check whether driver is initialized, if driver is
 *                      initialized when check in  MCU_SID_INIT service, return error; otherwise if
 *                      driver is not initialized when check in other services, return error.
 * \endverbatim
 * Traceability       : SWSR_MCU_046 SWSR_MCU_048 SW_SM002 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_EnterCheck(const uint8 serviceId);
/** *****************************************************************************************************
 * \brief This service initializes the MCU driver.
 *
 * \verbatim
 * Syntax             : void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize the MCU module, i.e.make the configuration settings for power down,
 *                      clock and RAM sections visible within the MCU module.
 * \endverbatim
 * Traceability       : SWSR_MCU_021 SWSR_MCU_054 SWSR_MCU_055 SW_SM002
 *                      SW_SM006
 *******************************************************************************************************/
void Mcu_Init(const Mcu_ConfigType *ConfigPtr);

/** *****************************************************************************************************
 * \brief This service initializes the PLL and other MCU specific clock options.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ClockSetting - Clock setting id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : This service initializes the PLL and other MCU specific clock options.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SWSR_MCU_025 SWSR_MCU_026 SWSR_MCU_027
 *                      SWSR_MCU_046 SWSR_MCU_053 SWSR_MCU_054 SWSR_MCU_055
 *                      SW_SM006 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);

/** *****************************************************************************************************
 * \brief This service initializes the RAM section wise.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : RamSection - Selects RAM memory section provided in configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : This service initializes the RAM section wise.
 * \endverbatim
 * Traceability       : SWSR_MCU_022 SWSR_MCU_023 SWSR_MCU_024 SWSR_MCU_046
 *                      SWSR_MCU_047 SWSR_MCU_054 SWSR_MCU_055 SW_SM006
 *                      SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);

/** *****************************************************************************************************
 * \brief This service provides the lock status of the PLL.
 *
 * \verbatim
 * Syntax             : Mcu_PllStatusType Mcu_GetPllStatus(void)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : PLL lock status
 *
 * Description        : This service provides the lock status of the PLL.
 * \endverbatim
 * Traceability       : SWSR_MCU_010 SWSR_MCU_028 SWSR_MCU_029 SWSR_MCU_030
 *                      SWSR_MCU_031 SWSR_MCU_054 SWSR_MCU_055 SW_SM001
 *******************************************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void);

/** *****************************************************************************************************
 * \brief The service reads the reset type from the hardware, if supported.
 *
 * \verbatim
 * Syntax             : Mcu_PllStatusType Mcu_GetPllStatus(void)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : reset type
 *
 * Description        : This service provides the lock status of the PLL.
 * \endverbatim
 * Traceability       : SWSR_MCU_003 SWSR_MCU_032 SWSR_MCU_033 SWSR_MCU_034
 *                      SW_SM001
 *******************************************************************************************************/
Mcu_ResetType Mcu_GetResetReason(void);

/** *****************************************************************************************************
 * \brief The service reads the reset type from the hardware register, if supported.
 *
 * \verbatim
 * Syntax             : Mcu_RawResetType Mcu_GetResetRawValue(void)
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Reset raw value
 *
 * Description        : The service reads the reset type from the hardware register, if supported.
 * \endverbatim
 * Traceability       : SWSR_MCU_035 SWSR_MCU_036 SWSR_MCU_037 SW_SM001
 *******************************************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void);

/** Traceability       : SWSR_MCU_041*/
#if (STD_ON == MCU_PERFORM_RESET_API)
/** *****************************************************************************************************
 * \brief The service performs a microcontroller reset.
 *
 * \verbatim
 * Syntax             : Mcu_RawResetType Mcu_GetResetRawValue(void)
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Reset raw value
 *
 * Description        : The service performs a microcontroller reset.
 *                      The function Mcu_PerformReset is only available if MCU_PERFORM_RESET_API is set to TRUE.
 *                      If set to FALSE, the function Mcu_PerformReset is not applicable
 * \endverbatim
 * Traceability       : SWSR_MCU_002 SWSR_MCU_038 SWSR_MCU_039 SWSR_MCU_040
 *                      SWSR_MCU_054 SWSR_MCU_055 SW_SM001
 *******************************************************************************************************/
void Mcu_PerformReset(void);
#endif /**#if (STD_ON == MCU_PERFORM_RESET_API)*/

/** *****************************************************************************************************
 * \brief This service activates the MCU power modes.
 *
 * \verbatim
 * Syntax             : void Mcu_SetMode(Mcu_ModeType McuMode)
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Reset raw value
 *
 * Description        : This service activates the MCU power modes(RTC mode)
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_046
 *                      SWSR_MCU_054 SWSR_MCU_055 SW_SM006 SW_SM001 SW_SM005
 *******************************************************************************************************/
void Mcu_SetMode(Mcu_ModeType McuMode);

#if (STD_ON == MCU_VERSION_INFO_API)
/** *****************************************************************************************************
 * \brief Get version information of this driver.
 *
 * \verbatim
 * Syntax             : void Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo)
 *
 * Service ID[hex]    : 0x09
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version information of this module.
 *
 * Return value       : None
 *
 * Description        : This function returns the version information of this module
 *                      The version information include : Module ID, Vendor ID.
 *                      Vendor specific version numbers.
 *   -                  This function is available if the MCU_VERSION_INFO_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_044
 *******************************************************************************************************/
void Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /**#if(STD_ON == MCU_VERSION_INFO_API)*/

#ifdef __cplusplus
}
#endif

#endif /* MCU_H */
/* End of file */
