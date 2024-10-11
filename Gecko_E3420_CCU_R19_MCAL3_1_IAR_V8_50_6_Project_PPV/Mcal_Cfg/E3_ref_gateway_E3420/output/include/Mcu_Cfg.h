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
 *  \file     Mcu_Cfg.h                                                                                 *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2024-03-08 16:29:00     <td>1.0.0                                                                *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_GeneralTypes.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_MCU_MACRO Mcu Macro.
 *
 * This files defines Mcu MCAL macros.
 *  @{
 */

 /**
 *  \name Mcu Module generation version.
 *
 *  @{
 */
/** \brief  Generate Autosar Specific Version Information. */
#define MCU_AR_RELEASE_MAJOR_VERSION                                    (4U)
#define MCU_AR_RELEASE_MINOR_VERSION                                    (3U)
#define MCU_AR_RELEASE_REVISION_VERSION                                 (1U)

/** \brief  Generate Vendor Specific Version Information. */
#define MCU_SW_MAJOR_VERSION                                            (3U)
#define MCU_SW_MINOR_VERSION                                            (1U)
#define MCU_SW_PATCH_VERSION                                            (0U)
/** @} */


#define MCU_MAX_RAMCFGS  0U
#define MCU_MAX_MODECFGS 4U
#define MCU_MAX_CLKCFGS  1U

#define MCU_DEV_ERROR_DETECT (STD_OFF)
#define MCU_SAFETY_ENABLE (STD_ON)
#define MCU_VERSION_INFO_API (STD_OFF)
#define MCU_PERFORM_RESET_API (STD_ON)
#define MCU_RELEASE_DISPLAY_PIN (STD_ON)
#define MCU_NO_PLL (STD_OFF)

#define MCU_APDOMAIN_POWERDOWN (STD_OFF)
#define MCU_LDO_POWERDOWN (STD_OFF)
#define MCU_DCDC_POWERDOWN (STD_OFF)
#define MCU_SF_FREQUENCY_HALVED (STD_OFF)
#define MCU_SP_FREQUENCY_HALVED (STD_OFF)
#define MCU_SX_FREQUENCY_HALVED (STD_OFF)
#define MCU_PLL4_POWERDOWN (STD_OFF)
#define MCU_PLL5_POWERDOWN (STD_OFF)
#define MCU_PLL_LVDS_POWERDOWN (STD_OFF)

#define MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK (STD_OFF)

#define MCU_PVT_AP_ENABLE (STD_OFF)

#define MCU_PLL_SPREAD_NUM  0U
#define MCU_PLL_SPREAD STD_OFF

#define McuConf_McuClockSettingConfig_McuClockSettingConfig_0   ((Mcu_ClockType)0U)




#define EXPECT_CORE_CLOCK_SF  (600U*1000000U)
#define EXPECT_CORE_CLOCK_SP  (600U*1000000U)
#define EXPECT_CORE_CLOCK_SX  (600U*1000000U)

#define MAX_CORE_NUM  3U

#define MCU_CLK_CAN24M_ENABLE

#define RTC_ENTER_FAIL_WAIT_TIME  3600000U

/*PRQA S 3684  6*/
extern const Mcu_ClkNodeType * const Mcu_ClkPrepareArray[];
extern const Mcu_ClkNodeType * const Mcu_ClkEnableArray[];
extern const Mcu_ClkNodeType * const Mcu_ClkDisableArray[];
extern const Mcu_ResetSigType * const Mcu_XspiResetArray[];
extern const Mcu_ResetSigType * const Mcu_DeassertArray[];
extern const Mcu_ResetSigType * const Mcu_AssertArray[];
#if (STD_ON == MCU_PLL_SPREAD)
extern const Mcu_PllSpreadConfigType Mcu_PllSpreadConfigs[MCU_PLL_SPREAD_NUM];
#endif /** #if (MCU_PLL_SPREAD == STD_ON)*/
uint32 Mcu_GetClkEnableArraySize(void);
uint32 Mcu_GetClkPrepareArraySize(void);
uint32 Mcu_GetDeassertArraySize(void);
uint32 Mcu_GetAssertArraySize(void);
uint32 Mcu_GetXspiResetArraySize(void);
uint32 Mcu_GetClkDisableArraySize(void);
uint32 Mcu_GetPllSpreadArraySize(void);
#if (MCU_PLL_SPREAD == STD_ON)
uint32 Mcu_GetPllSpreadArraySize(void);
#endif /**#if (MCU_PLL_SPREAD == STD_ON)*/
extern const Mcu_PvtConfigType  Mcu_PvtCfg;

#if (STD_ON == MCU_PVT_AP_ENABLE)
extern const Mcu_PvtConfigType  Mcu_PvtCfg_AP;
#endif /** #if (STD_ON == MCU_PVT_AP_ENABLE)*/
/** @} */
#ifdef __cplusplus
}
#endif

#endif /* MCU_CFG_H */
/* End of file */
