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
 * \file     Wdg_Ip.c                                                                                   *
 * \brief    AUTOSAR 4.3.1 MCAL can Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "__regs_base.h"
#include "Wdg_Reg.h"
#include "RegHelper.h"
#include "Wdg_Ip.h"
#include "Wdg_Cfg.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \name WDG Driver ID Info
 *  @{
 */
/** \brief SemiDriver Instruments Vendor ID */
#define WDG_IP_C_VENDOR_ID    0x8C
/**
 *  \name WDG Driver Module AUTOSAR Version Info
 *
 *  Defines for WDG Driver AUTOSAR version used for compatibility checks
 *  @{
 */
/** \brief AUTOSAR Major version specification implemented by WDG Driver */
#define WDG_IP_C_AR_RELEASE_MAJOR_VERSION    4
/** \brief AUTOSAR Minor  version specification implemented by WDG Driver */
#define WDG_IP_C_AR_RELEASE_MINOR_VERSION    3
/** \brief AUTOSAR Patch version specification implemented by WDG Driver */
#define WDG_IP_C_AR_RELEASE_REVISION_VERSION 1
/* @} */
/**
 *  \name WDG Driver Module SW Version Info
 *
 *  Defines for WDG Driver version used for compatibility checks
 *  @{
 */
/** \brief Driver Implementation Major Version */
#define WDG_IP_C_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_IP_C_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_IP_C_SW_PATCH_VERSION    0
/* @} */
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief Only register interrupt for timeout */
#define INTERRUPT_MASK    (0x4U)
/** \brief wdt check register write value correct's times */
#define WDT_IP_WAIT_CHECK_TIMES (10000U)
/** \brief wdt time cnt from 1 start count,so add 1 form parameters */
#define WDT_IP_CNT_COUNT      (0x1U)
/** \brief Driver function enable*/
#define WDG_IP_FUNCTION_ENABLE  (0x1u)
/** \brief Driver function disable*/
#define WDG_IP_FUNCTION_DISABLE  (0x0u)
/** \brief Driver Wdg main clk div number */
#define WDG_IP_CLK_DIV_NUM (23999U)
/** \brief Driver Wdg main clk*/
#define WDG_IP_CLK_SRC_MAIN (0U)
/** \brief Driver Wdg global reset control offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_OFF              (0x204U)
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief Driver Wdg global reset control offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_BIT_WIDTH        (2U)
/** \brief Driver Wdg global reset control offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL          (3UL)
/** \brief Driver Wdg global reset WDT6 BIT offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_WDT6_OFF         (15U)
/** \brief Driver Wdg global reset WDT5 BIT offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_WDT5_OFF         (7U)
/** \brief Driver Wdg global reset WDT4 BIT offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_WDT4_OFF         (13U)
/** \brief Driver Wdg global reset WDT3 BIT offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_WDT3_OFF         (5U)
#else
#define WDG_IP_GLOBAL_RESET_CONTROL_BIT_WIDTH        (1U)
/** \brief Driver Wdg global reset control offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL          (1UL)
#endif /*SEMIDRIVE_E3_LITE_SERIES*/
/** \brief Driver Wdg global reset WDT2 BIT offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_WDT2_OFF         (11U)
/** \brief Driver Wdg global reset WDT1 BIT offset*/
#define WDG_IP_GLOBAL_RESET_CONTROL_WDT1_OFF         (3U)

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** \brief  please input Global Variable Declarations information */

#if ((WDG_INSTANCE1_SUPPORT == STD_ON)\
  || (WDG_INSTANCE2_SUPPORT == STD_ON)\
  || (WDG_INSTANCE3_SUPPORT == STD_ON)\
  || (WDG_INSTANCE4_SUPPORT == STD_ON)\
  || (WDG_INSTANCE5_SUPPORT == STD_ON)\
  || (WDG_INSTANCE6_SUPPORT == STD_ON)\
  || (WDG_INSTANCE8_SUPPORT == STD_ON))

#if (WDG_INSTANCE1_SUPPORT == STD_ON)
#define WDG1_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg1_MemMap.h"
static  uint32 Wdg1_Ip_TimeRatio = WDT_IP_ZERO;
#define WDG1_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg1_MemMap.h"
#endif /*WDG_INSTANCE1_SUPPORT*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)
#define WDG2_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg2_MemMap.h"
static  uint32 Wdg2_Ip_TimeRatio = WDT_IP_ZERO;
#define WDG2_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg2_MemMap.h"
#endif /*WDG_INSTANCE2_SUPPORT*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)
#define WDG3_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg3_MemMap.h"
static  uint32 Wdg3_Ip_TimeRatio = WDT_IP_ZERO;
#define WDG3_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg3_MemMap.h"
#endif /*WDG_INSTANCE3_SUPPORT*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)
#define WDG4_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg4_MemMap.h"
static  uint32 Wdg4_Ip_TimeRatio = WDT_IP_ZERO;
#define WDG4_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg4_MemMap.h"
#endif /*WDG_INSTANCE4_SUPPORT*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)
#define WDG5_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg5_MemMap.h"
static  uint32 Wdg5_Ip_TimeRatio = WDT_IP_ZERO;
#define WDG5_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg5_MemMap.h"
#endif /*WDG_INSTANCE5_SUPPORT*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)
#define WDG6_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg6_MemMap.h"
static  uint32 Wdg6_Ip_TimeRatio = WDT_IP_ZERO;
#define WDG6_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg6_MemMap.h"
#endif /*WDG_INSTANCE6_SUPPORT*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)
#define WDG8_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg8_MemMap.h"
static  uint32 Wdg8_Ip_TimeRatio = WDT_IP_ZERO;
#define WDG8_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#include "Wdg8_MemMap.h"
#endif /*WDG_INSTANCE8_SUPPORT*/

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

/** *****************************************************************************************************
 * \brief  Get the instanceId Watchdog base addr.
 *
 * \verbatim
 * Syntax             : uint32 Wdg_Ip_GetBaseAddr(uint8 instanceId)
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
 * Return value       : baseAddr
 *
 * Description        : Get the instanceId Watchdog base addr.
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_007
 *******************************************************************************************************/
static uint32 Wdg_Ip_GetBaseAddr(uint8 instanceId)
{
    uint32 baseAddr;

    switch (instanceId)
    {
        /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

    case WDT1_INDEX:
        baseAddr = APB_WDT1_BASE;
        break;
#endif /*WDG_INSTANCE1_SUPPORT*/
        /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

    case WDT2_INDEX:
        baseAddr = APB_WDT2_BASE;
        break;
#endif /*WDG_INSTANCE2_SUPPORT*/
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

    case WDT3_INDEX:
        baseAddr = APB_WDT3_BASE;
        break;
#endif /*WDG_INSTANCE3_SUPPORT*/
        /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

    case WDT4_INDEX:
        baseAddr = APB_WDT4_BASE;
        break;
#endif /*WDG_INSTANCE4_SUPPORT*/
        /*#50 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

    case WDT5_INDEX:
        baseAddr = APB_WDT5_BASE;
        break;
#endif /*WDG_INSTANCE5_SUPPORT*/
        /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

    case WDT6_INDEX:

        baseAddr = APB_WDT6_BASE;

        break;
#endif /*WDG_INSTANCE6_SUPPORT*/
#endif /*SEMIDRIVE_E3_LITE_SERIES*/
        /*#70 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

    case WDT8_INDEX:
        baseAddr = APB_WDT8_BASE;
        break;
#endif /*WDG_INSTANCE8_SUPPORT*/

    default:
        baseAddr = WDT_IP_ZERO;
        break;
    }

    return baseAddr;
}

/** *****************************************************************************************************
 * \brief Get the time ratio for 24MHZ clk frequence
 *
 * \verbatim
 * Syntax             : uint32 Wdg_Ip_GetTimeRatio(uint8 instanceId)
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
 * Return value       : timeRatio
 *
 * Description        : Get the time ratio for 24MHZ clk frequence
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_008 SWSR_WDG_021 SWSR_WDG_029 SWSR_WDG_030 SWSR_WDG_031
 *                      SWSR_WDG_032 SWSR_WDG_033 SWSR_WDG_034
 *******************************************************************************************************/
static uint32 Wdg_Ip_GetTimeRatio(uint8 instanceId)
{
    uint32 timeRatio;

    switch (instanceId)
    {
        /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

    case WDT1_INDEX:
        timeRatio = Wdg1_Ip_TimeRatio;
        break;
#endif /*WDG_INSTANCE1_SUPPORT*/
        /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

    case WDT2_INDEX:
        timeRatio = Wdg2_Ip_TimeRatio;
        break;
#endif /*WDG_INSTANCE2_SUPPORT*/
        /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

    case WDT3_INDEX:
        timeRatio = Wdg3_Ip_TimeRatio;
        break;
#endif /*WDG_INSTANCE3_SUPPORT*/
        /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

    case WDT4_INDEX:
        timeRatio = Wdg4_Ip_TimeRatio;
        break;
#endif /*WDG_INSTANCE4_SUPPORT*/
        /*#50 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

    case WDT5_INDEX:
        timeRatio = Wdg5_Ip_TimeRatio;
        break;
#endif /*WDG_INSTANCE5_SUPPORT*/
        /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

    case WDT6_INDEX:
        timeRatio = Wdg6_Ip_TimeRatio;
        break;
#endif /*WDG_INSTANCE6_SUPPORT*/
        /*#70 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

    case WDT8_INDEX:
        timeRatio = Wdg8_Ip_TimeRatio;
        break;
#endif /*WDG_INSTANCE8_SUPPORT*/

    default:
        timeRatio = WDT_IP_ZERO;
        break;
    }

    return timeRatio;
}

/** *****************************************************************************************************
 * \brief Set the time ratio for 24MHZ clk frequence
 *
 * \verbatim
 * Syntax             : void Wdg_Ip_SetTimeRatio(uint32 timeRatio,uint8 instanceId)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (in)    : timeRatio - 24MHZ clk frequence after div period .
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set the time ratio for 24MHZ clk frequence
 *
 * \endverbatim
 * Traceability       : SWSR_WDG_008 SWSR_WDG_021 SWSR_WDG_029 SWSR_WDG_030 SWSR_WDG_031
 *                      SWSR_WDG_032 SWSR_WDG_033 SWSR_WDG_034
 *******************************************************************************************************/
static void Wdg_Ip_SetTimeRatio(uint32 timeRatio, uint8 instanceId)
{
    switch (instanceId)
    {
        /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)

    case WDT1_INDEX:
        Wdg1_Ip_TimeRatio = timeRatio;
        break;
#endif /*WDG_INSTANCE1_SUPPORT*/
        /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)

    case WDT2_INDEX:
        Wdg2_Ip_TimeRatio = timeRatio;
        break;
#endif /*WDG_INSTANCE2_SUPPORT*/
        /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)

    case WDT3_INDEX:
        Wdg3_Ip_TimeRatio = timeRatio;
        break;
#endif /*WDG_INSTANCE3_SUPPORT*/
        /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)

    case WDT4_INDEX:
        Wdg4_Ip_TimeRatio = timeRatio;
        break;
#endif /*WDG_INSTANCE4_SUPPORT*/
        /*#50 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)

    case WDT5_INDEX:
        Wdg5_Ip_TimeRatio = timeRatio;
        break;
#endif /*WDG_INSTANCE5_SUPPORT*/
        /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)

    case WDT6_INDEX:
        Wdg6_Ip_TimeRatio = timeRatio;
        break;
#endif /*WDG_INSTANCE6_SUPPORT*/
        /*#70 judge instanceId whether is WDG_INSTANCE8*/
#if (WDG_INSTANCE8_SUPPORT == STD_ON)

    case WDT8_INDEX:
        Wdg8_Ip_TimeRatio = timeRatio;
        break;
#endif /*WDG_INSTANCE8_SUPPORT*/

    default:
        /*do nothing*/
        break;
    }
}


/** *****************************************************************************************************
 * \brief This service wait ctrl register releatcate register bit clear or set.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType  Wdg_Ip_WaitCtrlBaseState(uint32 base,uint32 offset,boolean val)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (in)    : offset  - ctrl register offset bit
 *
 * Parameters (in)    : val - wait expect val
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service wait ctrl register releatcate register bit clear or set.
 * \endverbatim
 * Traceability       : SWSR_WDG_007 SWSR_WDG_011 SWSR_WDG_012 SWSR_WDG_013
 *                      SWSR_WDG_014 SW_SM005
 *******************************************************************************************************/
static Std_ReturnType  Wdg_Ip_WaitCtrlBaseState(uint32 base, uint32 offset, boolean val)
{
    uint32 tms = WDT_IP_ZERO;
    Std_ReturnType ret = E_NOT_OK;
    uint32 wdtSta;
    uint32 count = ((WDT_IP_WAIT_CHECK_TIMES / WDT_IP_WAIT_CHECK_TIMES) * 320UL);

    /*#10 null point check*/
    if (WDT_IP_ZERO != base)
    {
        wdtSta = ((REG_READ32(base + WDT_CTRL_OFF) >> offset) & WDG_IP_FUNCTION_ENABLE);

        /*#20 wait base state clear or set*/
        while ((tms < count) && (wdtSta != val))
        {
            /*wait until turn off wdg,delay 3 clk for 24M*/
            ++tms;
            wdtSta = ((REG_READ32(base + WDT_CTRL_OFF) >> offset) & WDG_IP_FUNCTION_ENABLE);
        }

        if (tms < count)
        {
            ret = E_OK;
        } /*else not use*/
    } /*else not use*/

    return ret;
}


/** *****************************************************************************************************
 * \brief This service set base wdg mode off for the WDG driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_Ip_SetModeOff(uint32 base)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service set base wdg mode off for the WDG driver.
 * \endverbatim
 * Traceability       : SWSR_WDG_007 SWSR_WDG_011 SWSR_WDG_012 SWSR_WDG_013
 *                      SWSR_WDG_014 SW_SM005
 *******************************************************************************************************/
static Std_ReturnType Wdg_Ip_SetModeOff(uint32 base)
{
    Std_ReturnType  retVal;

    /*#10 null point check*/
    if (WDT_IP_ZERO == base)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 disable wdt*/
        REG_RMW32(base + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
        retVal = Wdg_Ip_WaitCtrlBaseState(base, BM_WDT_CTRL_WDT_EN_STA, WDG_IP_FUNCTION_DISABLE);

        if (E_OK == retVal)
        {
            REG_RMW32(base + WDT_INT_OFF, WDT_0BIT_OFFSET, WDT_3BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
        } /*else not use*/
    }

    return retVal;
}

/** *****************************************************************************************************
 * \brief This service set base wdg enable for the WDG driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_Ip_SetWdtEnable(uint32 base)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service set base wdg enable for the WDG driver.
 * \endverbatim
 * Traceability       : SWSR_WDG_007 SWSR_WDG_011 SWSR_WDG_012 SWSR_WDG_013
 *                      SWSR_WDG_014 SW_SM005
 *******************************************************************************************************/
static Std_ReturnType Wdg_Ip_SetWdtEnable(uint32 base)
{
    Std_ReturnType  retVal;

    /*#10 null point check*/
    if (WDT_IP_ZERO == base)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 enable wdt*/
        REG_RMW32(base + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);

        /*#30 wait wdt enable complete*/
        retVal = Wdg_Ip_WaitCtrlBaseState(base, BM_WDT_CTRL_WDT_EN_STA, WDG_IP_FUNCTION_ENABLE);

        /*#40 enable soft reset*/
        if (E_OK == retVal)
        {
            REG_RMW32(base + WDT_CTRL_OFF, BM_WDT_CTRL_SOFT_RST, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);

            /*#50 wait wdt soft reset complete*/
            retVal = Wdg_Ip_WaitCtrlBaseState(base, BM_WDT_CTRL_SOFT_RST, WDG_IP_FUNCTION_DISABLE);
        } /*else not use*/
    }

    return retVal;
}
/** *****************************************************************************************************
 * \brief This service set base wdg work mode for the WDG driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_Ip_SetTriggerConditionMode
 *                      (Wdg_TriggerConditionType triggerCondition,uint32 base)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (in)    : triggerCondition  - Wdg work mode window or normal mode
 *
 * Parameters (in)    : refreshTime  - Wdg when only work window refresh time,
 *                                     refreshTime~initTimeout is feed dog time
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service set base wdg work mode for the WDG driver.
 * \endverbatim
 * Traceability       : SWSR_WDG_019
 *******************************************************************************************************/
static Std_ReturnType Wdg_Ip_SetTriggerConditionMode(Wdg_TriggerConditionType triggerCondition,
        uint32 refreshTime, uint32 base)
{
    Std_ReturnType  retVal = E_OK;

    /*#10 null point check*/
    if (WDT_IP_ZERO == base)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 wdt trigger mode setting*/
        switch (triggerCondition)
        {
        case NO_CONDITION_MODE:
            /*wdt normal trigger mode setting*/
            REG_WRITE32((uint32)((uint32)WDG_IP_FUNCTION_ENABLE << BM_WDT_WRC_CTL_MODE0_EN),
                        base + WDT_WRC_CTL_OFF);
            break;

        case WINDOW_BASED_MODE:
            /*wdt window trigger mode setting*/
            REG_WRITE32((refreshTime + WDT_IP_CNT_COUNT), base + WDT_WRC_VAL_OFF);
            REG_WRITE32((WDG_IP_FUNCTION_ENABLE << BM_WDT_WRC_CTL_MODE1_EN) | (WDG_IP_FUNCTION_ENABLE <<
                        BM_WDT_WRC_CTL_MODE0_EN),
                        base + WDT_WRC_CTL_OFF);
            break;

        default:
            retVal = E_NOT_OK;
            break;
        }
    }

    return retVal;
}

/** *****************************************************************************************************
 * \brief This service set base wdg wtc value function Enable for the WDG driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_Ip_WdtWtc
 *                      (uint32 base,uint32 clockFrequency,uint32 initTimeout,uint8 instanceId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (in)    : clockFrequency  - Wdg Instance id clk frequence
 *
 * Parameters (in)    : initTimeout  - User time out value(ms) setting
 *
 * Parameters (in)    : instanceId  - Wdg Instance id and it is depending on hardware id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service set base wdg wtc value function Enable for the WDG driver.
 * \endverbatim
 * Traceability       : SWSR_WDG_008 SWSR_WDG_021 SWSR_WDG_029 SWSR_WDG_030 SWSR_WDG_031
 *                      SWSR_WDG_032 SWSR_WDG_033 SWSR_WDG_034
 *******************************************************************************************************/
static Std_ReturnType Wdg_Ip_WdtWtc(uint32 base, uint32 clockFrequency, uint32 initTimeout,
                                    uint8 instanceId)
{
    Std_ReturnType  retVal = E_OK;
    uint32 regVal;
    uint32 timeRatio;

    /*#10 null point check and clockFrequency value valid check*/
    if ((WDT_IP_ZERO == base) || (WDT_IP_ZERO == clockFrequency))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 wtc value calculate*/
        regVal = REG_READ32(base + WDT_CTRL_OFF);
        timeRatio = clockFrequency / WDG_IP_CLK_FREQUENCE;
        Wdg_Ip_SetTimeRatio(timeRatio, instanceId);
        /*#30 clk div setting */
        regVal |= (uint32)(FV_WDT_CTRL_PRE_DIV_NUM(WDG_IP_CLK_DIV_NUM)) << WDT_16BIT_OFFSET;
#if (WDG_DEBUG_SUPPORT == STD_ON)
        regVal |= WDG_IP_FUNCTION_ENABLE << BM_WDT_CTRL_DBG_HALT_EN;
#endif /*WDG_DEBUG_SUPPORT*/
        /*#40 autoreset function enable*/
        regVal |= WDG_IP_FUNCTION_ENABLE << BM_WDT_CTRL_AUTO_RESTART;
        regVal |= WDG_IP_FUNCTION_ENABLE << BM_WDT_CTRL_WTC_SRC;
        REG_WRITE32(regVal, base + WDT_CTRL_OFF);
        /*#40 wtc value setting*/
        regVal = ((uint32)initTimeout + WDT_IP_CNT_COUNT) * Wdg_Ip_GetTimeRatio(instanceId);

        REG_WRITE32(regVal, base + WDT_WTC_OFF);
        /* Using main_clk: source clock is ss 24M*/
        REG_RMW32(base + WDT_CTRL_OFF, WDT_2BIT_OFFSET, WDT_3BIT_WIDTH,
                  FV_WDT_CTRL_CLK_SRC(WDG_IP_CLK_SRC_MAIN));
    }

    return retVal;
}

/** *****************************************************************************************************
 * \brief This service set base wdg timeout extern singnal function Enable for the WDG driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_Ip_WdtExternSignalEnable(uint32 base)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service set base wdg timeout extern singnal function Enable for the WDG driver.
 * \endverbatim
 * Traceability       : SWSR_WDG_080
 *******************************************************************************************************/
static Std_ReturnType Wdg_Ip_WdtExternSignalEnable(uint32 base)
{
    Std_ReturnType  retVal = E_OK;

    /*#10 null point check*/
    if (WDT_IP_ZERO == base)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 external signal output enable setting*/
        REG_RMW32(base + WDT_EXT_RST_CTL_OFF, BM_WDT_EXT_RST_CTL_EXT_RST_MODE, WDT_1BIT_WIDTH,
                  WDG_IP_FUNCTION_DISABLE);
        REG_RMW32(base + WDT_EXT_RST_CTL_OFF, BM_WDT_EXT_RST_CTL_EXT_RST_EN, WDT_1BIT_WIDTH,
                  WDG_IP_FUNCTION_ENABLE);
    }

    return retVal;
}

/** *****************************************************************************************************
 * \brief This service set base wdg init for the WDG driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_Ip_WdtCtrolInit(uint32 base)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service set base wdg init for the WDG driver.
 * \endverbatim
 * Traceability       : SWSR_WDG_079 SW_SM005
 *******************************************************************************************************/
static Std_ReturnType Wdg_Ip_WdtCtrolInit(uint32 base)
{
    Std_ReturnType  retVal;

    /*#10 null point check*/
    if (WDT_IP_ZERO == base)
    {
        retVal = E_NOT_OK;
    }
    else
    {
#if defined(SEMIDRIVE_E3_SERIES) || defined(SEMIDRIVE_E3_LITE_SERIES)
        /* #11 If the chip is lbist, register WDT_EXT_RST_CTL and RST_REQ_The MON register will not be reset. */
        /* JIRA ID TAISHANL-69  */
        REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_WDT_EN, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
        REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_DBG_HALT_EN, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
        REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_WDT_EN_SRC, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
        REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_SOFT_RST, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
        retVal = Wdg_Ip_WaitCtrlBaseState(base, BM_WDT_CTRL_SOFT_RST, WDG_IP_FUNCTION_ENABLE);

        if (E_OK == retVal)
        {
            REG_RMW32((base + WDT_LOCK_OFF), BM_WDT_LOCK_EXT_RST_LOCK, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
            REG_RMW32((base + WDT_EXT_RST_CTL_OFF), BM_WDT_EXT_RST_CTL_EXT_RST_EN, WDT_1BIT_WIDTH,
                      WDG_IP_FUNCTION_DISABLE);
            REG_RMW32((base + WDT_EXT_RST_CTL_OFF), BM_WDT_EXT_RST_CTL_RST_WIN, WDT_8BIT_WIDTH, 0UL);
            REG_RMW32((base + WDT_EXT_RST_CTL_OFF), BM_WDT_EXT_RST_CTL_EXT_RST_MODE, WDT_1BIT_WIDTH,
                      WDG_IP_FUNCTION_DISABLE);
            REG_RMW32((base + WDT_EXT_RST_CTL_OFF), BM_WDT_EXT_RST_CTL_RST_CNT, WDT_16BIT_WIDTH, 0XffUL);
            REG_RMW32((base + RST_REQ_MON_OFF), BM_RST_REQ_MON_INT_RST_REQ_REC, WDT_1BIT_WIDTH,
                      WDG_IP_FUNCTION_ENABLE);
            REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_WDT_EN, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
            REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_DBG_HALT_EN, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
            REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_WDT_EN_SRC, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
        }/*else not use*/

#endif /** #if defined(SEMIDRIVE_E3_SERIES) || defined(SEMIDRIVE_E3_LITE_SERIES) */
        /*#20 clear wdt enable bit and select wdt enable source*/
        REG_RMW32((base + WDT_CTRL_OFF), BM_WDT_CTRL_WDT_EN, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
        REG_RMW32(base + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN_SRC, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);

        /*#30 wait wdt enable bit setting complete*/
        retVal = Wdg_Ip_WaitCtrlBaseState(base, BM_WDT_CTRL_WDT_EN_STA, WDG_IP_FUNCTION_DISABLE);

        /*#40 wdt reset bit setting*/
        if (E_OK == retVal)
        {
            REG_RMW32(base + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_WDT_RST_EN, WDT_1BIT_WIDTH,
                      WDG_IP_FUNCTION_ENABLE);
        } /*else not use*/
    }

    return retVal;
}

/** *****************************************************************************************************
 * \brief This service set wdg timeort behavior for the WDG driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Wdg_Ip_SetTimeOutBehavior
 *                             (Wdg_TimeoutBehaviorType timeoutBehavior,uint32 base)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timeoutBehavior - Wdg timeout Behavior.
 *
 * Parameters (in)    : base  - Wdg Instance id base Addr
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK\E_NOT_OK
 *
 * Description        : This service set wdg timeort behavior for the WDG driver.
 * \endverbatim
 * Traceability       : SWSR_WDG_075
 *******************************************************************************************************/
static Std_ReturnType Wdg_Ip_SetTimeOutBehavior(Wdg_TimeoutBehaviorType timeoutBehavior,
        uint32 base)
{
    Std_ReturnType  retVal = E_OK;

    /*#10 null point check*/
    if (WDT_IP_ZERO == base)
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 timeoutBehavior behavior setting*/
        if (WDG_INTERRUPT == timeoutBehavior)
        {
            /* enable timeout interrupt and disable wdt reset function*/
            REG_RMW32(base + WDT_INT_OFF, WDT_0BIT_OFFSET, WDT_3BIT_WIDTH, INTERRUPT_MASK);
            REG_RMW32(base + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, WDT_1BIT_WIDTH,
                      WDG_IP_FUNCTION_DISABLE);
        }
        else if (WDG_RESET == timeoutBehavior)
        {
            /* default Level mode */
            /* disable timeout interrupt and enable wdt reset function*/
            REG_RMW32(base + WDT_INT_OFF, WDT_0BIT_OFFSET, WDT_3BIT_WIDTH, WDG_IP_FUNCTION_DISABLE);
            /*Set delay time between overflow and reset. Maxium 2.7ms for 24MHz reference clk.*/
            REG_RMW32(base + WDT_RST_CTL_OFF, WDT_0BIT_OFFSET, WDT_16BIT_WIDTH, 0xFFU);
            REG_RMW32(base + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_RST_WIN, WDT_8BIT_WIDTH, 0xFFU);
            REG_RMW32(base + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, WDT_1BIT_WIDTH,
                      WDG_IP_FUNCTION_ENABLE);
        }
        else if (WDG_BOTH == timeoutBehavior)
        {
            /* enable timeout interrupt and enable wdt reset function*/
            REG_RMW32(base + WDT_INT_OFF, WDT_0BIT_OFFSET, WDT_3BIT_WIDTH, INTERRUPT_MASK);
            /*Set delay time between overflow and reset. Maxium 2.7ms for 24MHz reference clk.*/
            REG_RMW32(base + WDT_RST_CTL_OFF, WDT_0BIT_OFFSET, WDT_16BIT_WIDTH, WDG_IP_MAX_TIME_VAL);
            REG_RMW32(base + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_RST_WIN, WDT_8BIT_WIDTH, 0xFFU);
            REG_RMW32(base + WDT_RST_CTL_OFF, BM_WDT_RST_CTL_INT_RST_EN, WDT_1BIT_WIDTH,
                      WDG_IP_FUNCTION_ENABLE);
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

/** *****************************************************************************************************
 * \brief This service initializes the WDG driver.
 *
 * \verbatim
 * Syntax             : void Wdg_Ip_Init
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
 * Return value       : E_OK/E_NOT_OK
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize all WDG relevant registers with the values of the structure
 *                      referenced by the parameter configPtr
 * \endverbatim
 * Traceability       : SWSR_WDG_007 SWSR_WDG_009 SWSR_WDG_011 SWSR_WDG_012 SWSR_WDG_013 SW_SM005
 *                      SWSR_WDG_014 SWSR_WDG_015 SWSR_WDG_016 SWSR_WDG_017 SWSR_WDG_018
 *                      SWSR_WDG_020 SWSR_WDG_037 SWSR_WDG_072 SWSR_WDG_073 SWSR_WDG_078
 *******************************************************************************************************/
Std_ReturnType Wdg_Ip_Init(const Wdg_ModeConfigType *pModeSetting, uint16 initTimeout,
                           uint8 instanceId)
{
    Std_ReturnType retVal;
    uint32 base = Wdg_Ip_GetBaseAddr(instanceId);

    /*#10 null point check*/
    if ((WDT_IP_ZERO == base) || (NULL_PTR == pModeSetting))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 wdg register init*/
        retVal = Wdg_Ip_WdtCtrolInit(base);
    }/*else not to use*/

    if (E_OK == retVal)
    {
        /*#30 wdg TimeOut Behavior setting*/
        retVal = Wdg_Ip_SetTimeOutBehavior(pModeSetting->timeoutBehavior, base);
    }/*else not to use*/

    /* Level mode */
    if ((E_OK == retVal) && (TRUE == pModeSetting->externalSignalEnable))
    {
        /*#40 wdg TimeOut external signal output setting*/
        retVal = Wdg_Ip_WdtExternSignalEnable(base);
    }/*else not to use*/

    if (E_OK == retVal)
    {
        if (WDT_IP_ZERO != pModeSetting->clockFrequency)
        {
            /*#50 wdg TimeOut value setting*/
            retVal = Wdg_Ip_WdtWtc(base, pModeSetting->clockFrequency, (uint32)initTimeout, instanceId);

            /*PRQA S 2991,2995 2*/
            if (E_OK == retVal)
            {
                /*#60 wdg trigger mode setting*/
                retVal = Wdg_Ip_SetTriggerConditionMode(pModeSetting->triggerCondition, pModeSetting->refreshTime,
                                                        base);
            }/*else not to use*/

            if (E_OK == retVal)
            {
                /*#70 wdg start work*/
                retVal = Wdg_Ip_SetWdtEnable(base);
            }/*else not to use*/
        }/*else not to use*/
    }/*else not to use*/

    return retVal;
}

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
 * Return value       :  E_NOT_OK/E_OK
 *
 * Description        : Always returns E_OK, Wdg_SetMode is made available because
 *                      WDG Interface layer expects this function to be present.
 * \endverbatim
 * Traceability       : SWSR_WDG_005 SWSR_WDG_006 SWSR_WDG_007 SWSR_WDG_009 SWSR_WDG_010
 *                      SWSR_WDG_019 SWSR_WDG_020 SWSR_WDG_021 SWSR_WDG_022 SWSR_WDG_023
 *                      SWSR_WDG_024 SWSR_WDG_025 SWSR_WDG_026 SWSR_WDG_027 SWSR_WDG_028
 *                      SWSR_WDG_044 SWSR_WDG_073 SWSR_WDG_078 SW_SM005
 *******************************************************************************************************/
Std_ReturnType Wdg_Ip_SetMode(const Wdg_ModeConfigType *pModeSetting, uint8 instanceId)
{
    Std_ReturnType retVal;
    uint32 base = Wdg_Ip_GetBaseAddr(instanceId);

    /*#10 null point check*/
    if ((WDT_IP_ZERO == base) || (NULL_PTR == pModeSetting))
    {
        retVal = E_NOT_OK;
    }
    else
    {
        /*#20 wdt enable source select*/
        REG_RMW32(base + WDT_CTRL_OFF, BM_WDT_CTRL_WDT_EN_SRC, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
        /*#30 wdg TimeOut Behavior setting*/
        retVal = Wdg_Ip_SetTimeOutBehavior(pModeSetting->timeoutBehavior, base);
    }

    /* Level mode */
    if ((E_OK == retVal) && (TRUE == pModeSetting->externalSignalEnable))
    {
        /*#40 wdg TimeOut external signal output setting*/
        retVal = Wdg_Ip_WdtExternSignalEnable(base);
    }/*else not to use*/

    if (E_OK == retVal)
    {
        if (WDT_IP_ZERO != pModeSetting->clockFrequency)
        {
            /*#50 wdg TimeOut value setting*/
            retVal = Wdg_Ip_WdtWtc(base, pModeSetting->clockFrequency, (uint32)pModeSetting->timeoutPeriod,
                                   instanceId);

            /*PRQA S 2991,2995 2*/
            if (E_OK == retVal)
            {
                /*#60 wdg trigger mode setting*/
                retVal = Wdg_Ip_SetTriggerConditionMode(pModeSetting->triggerCondition, pModeSetting->refreshTime,
                                                        base);
            }/*else not to use*/

            if (E_OK == retVal)
            {
                /*#70 wdg start work*/
                retVal = Wdg_Ip_SetWdtEnable(base);
            }/*else not to use*/
        }
        else
        {
            /*#70 wdg start mode off work*/
            retVal = Wdg_Ip_SetModeOff(base);
        }

    }/*else not to use*/

    return retVal;
}

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
void Wdg_Ip_SetTriggerCondition(uint16 timeout, uint8 instanceId)
{
    uint32 base = Wdg_Ip_GetBaseAddr(instanceId);

    /*#10 null point check*/
    if (WDT_IP_ZERO != base)
    {
        /*#20 trigger wdt*/
        REG_RMW32(base + WDT_WRC_CTL_OFF, BM_WDT_WRC_CTL_REFR_TRIG, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);

        /*#30 set timeout value*/
        /*For SWS_Wdg_00140, if users pass '0',wdg will almost reset immediately*/
        if (WDG_IP_MIN_TIME_VAL == timeout)
        {
            REG_WRITE32(0x2UL, base + WDT_WTC_OFF);
        }
        else
        {
            REG_WRITE32(((uint32)timeout + WDT_IP_CNT_COUNT) * Wdg_Ip_GetTimeRatio(instanceId),
                        base + WDT_WTC_OFF);
        }

        /*#40 retrigger wdt*/
        REG_RMW32(base + WDT_WRC_CTL_OFF, BM_WDT_WRC_CTL_REFR_TRIG, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
    }/*else not to use*/
}


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
 * Description        : This function Wdg Ip clear interrupt state.
 * \endverbatim
 * Traceability       : SWSR_WDG_074
 *******************************************************************************************************/
void Wdg_Ip_ClearInterruptFlag(uint8 instanceId)
{
    uint32 base = Wdg_Ip_GetBaseAddr(instanceId);

    /*#10 null point check*/
    if (WDT_IP_ZERO != base)
    {
        /*#20 clear interrupt bit*/
        REG_RMW32(base + WDT_INT_OFF, BM_WDT_INT_OVFLOW_INT_CLR, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
    }/*else not to use*/
}

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
Std_ReturnType Wdg_Ip_ExpectedInterruptCheck(uint8 instanceId)
{
    Std_ReturnType ret = E_NOT_OK;
    uint32 enable;
    uint32 state;
    uint32 base = Wdg_Ip_GetBaseAddr(instanceId);

    /*#10 null point check*/
    if (WDT_IP_ZERO != base)
    {
        /*#20 obtain wdt interrupt enable bit and interrut state*/
        enable = REG_READ32(base + WDT_INT_OFF) & WDT_3BIT_MASK;
        state = ((REG_READ32(base + WDT_INT_OFF) >> WDT_3BIT_OFFSET) & WDT_3BIT_MASK);

        /*#30 judge whether it is expect interrupt*/
        if ((enable & state) > WDT_IP_ZERO)
        {
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }/*else not to use*/

    return ret;
}

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
 * Traceability       : SWSR_WDG_008 SWSR_WDG_009 SWSR_WDG_031 SWSR_WDG_051 SW_SM002 SW_SM001
 *                      SWSR_WDG_058 SWSR_WDG_073 SWSR_WDG_075
 *******************************************************************************************************/
void Wdg_Ip_TriggerRoutine(uint8 instanceId)
{
    uint32 base = Wdg_Ip_GetBaseAddr(instanceId);

    /*#10 null point check*/
    if (WDT_IP_ZERO != base)
    {
        /*#20 trigger wdt*/
        REG_RMW32(base + WDT_WRC_CTL_OFF, BM_WDT_WRC_CTL_REFR_TRIG, WDT_1BIT_WIDTH, WDG_IP_FUNCTION_ENABLE);
    }/*else not to use*/
}
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
void  Wdg_Ip_GlbResetEn(uint8 instanceId)
{
    uint32 val;

    if (instanceId < WDT8_INDEX)
    {
        val = REG_READ32(APB_RSTGEN_SF_BASE + WDG_IP_GLOBAL_RESET_CONTROL_OFF);
        /*#10 judge instanceId whether is WDG_INSTANCE1*/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)
        val = val |  (WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL << WDG_IP_GLOBAL_RESET_CONTROL_WDT1_OFF);
#endif /*WDG_INSTANCE1_SUPPORT*/
        /*#20 judge instanceId whether is WDG_INSTANCE2*/
#if (WDG_INSTANCE2_SUPPORT == STD_ON)
        val = val |  (WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL << WDG_IP_GLOBAL_RESET_CONTROL_WDT2_OFF);
#endif /*WDG_INSTANCE2_SUPPORT*/
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /*#30 judge instanceId whether is WDG_INSTANCE3*/
#if (WDG_INSTANCE3_SUPPORT == STD_ON)
        val = val |  (WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL << WDG_IP_GLOBAL_RESET_CONTROL_WDT3_OFF);
#endif /*WDG_INSTANCE3_SUPPORT*/
        /*#40 judge instanceId whether is WDG_INSTANCE4*/
#if (WDG_INSTANCE4_SUPPORT == STD_ON)
        val = val |  (WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL << WDG_IP_GLOBAL_RESET_CONTROL_WDT4_OFF);
#endif /*WDG_INSTANCE4_SUPPORT*/
        /*#50 judge instanceId whether is WDG_INSTANCE5*/
#if (WDG_INSTANCE5_SUPPORT == STD_ON)
        val = val |  (WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL << WDG_IP_GLOBAL_RESET_CONTROL_WDT5_OFF);
#endif /*WDG_INSTANCE5_SUPPORT*/
        /*#60 judge instanceId whether is WDG_INSTANCE6*/
#if (WDG_INSTANCE6_SUPPORT == STD_ON)
        val = val |  (WDG_IP_GLOBAL_RESET_CONTROL_BIT_VAL << WDG_IP_GLOBAL_RESET_CONTROL_WDT6_OFF);
#endif /*WDG_INSTANCE6_SUPPORT*/
#endif /*SEMIDRIVE_E3_LITE_SERIES*/
        REG_WRITE32(val, APB_RSTGEN_SF_BASE + WDG_IP_GLOBAL_RESET_CONTROL_OFF);
    }
}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"
#endif /* WDG_INSTANCE1_SUPPORT||WDG_INSTANCE2_SUPPORT||WDG_INSTANCE3_SUPPORT||WDG_INSTANCE4_SUPPORT||WDG_INSTANCE5_SUPPORT||WDG_INSTANCE6_SUPPORT||WDG_INSTANCE8_SUPPORT */
#ifdef __cplusplus
}
#endif
/* End of file */
