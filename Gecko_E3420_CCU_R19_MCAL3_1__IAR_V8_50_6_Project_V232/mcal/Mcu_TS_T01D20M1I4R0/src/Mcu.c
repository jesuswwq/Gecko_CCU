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
 * \file     Mcu.c                                                                                      *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/31     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"
#include "Mcu.h"
#if (STD_ON == MCU_DEV_ERROR_DETECT)
/** Traceability       : SWSR_MCU_045*/
#include "Det.h"
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT)*/
#if (STD_ON == MCU_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE)*/
#include "Mcu_ResetSig.h"
#include "Mcu_Clk.h"
#include "Mcu_Xtal.h"
#include "Mcu_Dcdc.h"
#include "Mcu_Rstgen.h"
#include "Mcu_ResetDrv.h"
#include "Mcu_Delay.h"
#include "RegBase.h"
#include "Mcu_Extend.h"
#include "Mcu_AnalogTrim.h"
#include "Mcu_Fault.h"
#include "Mcu_KickCore.h"
#include "Mcu_Rtc.h"
#include "Mcu_Cfg.h"
#include "BswM_Check_Action.h"


#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
#include "Mcu_Clk.h"
#include "Mcu_CkgenDrv.h"
#include "Mcu_ClkCfgNd.h"
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef MCU_SW_MAJOR_VERSION
#error "MCU_SW_MAJOR_VERSION is not defined."
#endif

#ifndef MCU_SW_MINOR_VERSION
#error "MCU_SW_MINOR_VERSION is not defined."
#endif

#ifndef MCU_SW_PATCH_VERSION
#error "MCU_SW_PATCH_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef MCU_AR_RELEASE_MAJOR_VERSION
#error "MCU_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef MCU_AR_RELEASE_MINOR_VERSION
#error "MCU_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef MCU_AR_RELEASE_REVISION_VERSION
#error "MCU_AR_RELEASE_REVISION_VERSION is not defined."
#endif

/** \brief  AUTOSAR Major and Minor release version check. */
#if(MCU_AR_RELEASE_MAJOR_VERSION != 4U)
#error "MCU_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(MCU_AR_RELEASE_MINOR_VERSION != 3U)
#error "MCU_AR_RELEASE_MINOR_VERSION does not match."
#endif

#if(MCU_AR_RELEASE_REVISION_VERSION != 1U)
#error "MCU_AR_RELEASE_REVISION_VERSION does not match."
#endif
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define XSPI_NUM 4U
#else
#define XSPI_NUM 2U
#endif

#define XSPI_SCR_NUM (4U * XSPI_NUM)

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/

#define MCU_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Mcu_MemMap.h"
/** \brief  The configuration file pointer initialized in Mcu_init, and used in subsequent interfaces */
static const Mcu_ConfigType *Mcu_CfgPtr;

#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
/** @brief RTC domain PCLK switch reference count. */
sint32 McuRtcSSPclkRef;
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

#define MCU_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/* PRQA S 3218 1*/
static const uint32 xspiBse[XSPI_NUM] =
{
    APB_XSPI1PORTA_BASE,    APB_XSPI1PORTB_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    APB_XSPI2PORTA_BASE,    APB_XSPI2PORTB_BASE,
#endif
};

/* PRQA S 3218 1*/
static const Mcu_ScrSignalType signalScrXspi[XSPI_SCR_NUM] =
{
    MCU_SCR_SF_AAPB_XSPI1A_SRC_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI1A_SRC_UNCERR_CLR,
    MCU_SCR_SF_AAPB_XSPI1A_DST_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI1A_DST_UNCERR_CLR,
    MCU_SCR_SF_AAPB_XSPI1B_SRC_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI1B_SRC_UNCERR_CLR,
    MCU_SCR_SF_AAPB_XSPI1B_DST_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI1B_DST_UNCERR_CLR,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    MCU_SCR_SF_AAPB_XSPI2A_SRC_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI2A_SRC_UNCERR_CLR,
    MCU_SCR_SF_AAPB_XSPI2A_DST_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI2A_DST_UNCERR_CLR,
    MCU_SCR_SF_AAPB_XSPI2B_SRC_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI2B_SRC_UNCERR_CLR,
    MCU_SCR_SF_AAPB_XSPI2B_DST_IRQ_ENB,  MCU_SCR_SF_AAPB_XSPI2B_DST_UNCERR_CLR,
#endif
};
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/** Traceability       : SWSR_MCU_053 SW_SM006*/
static Std_ReturnType Mcu_ResetUsedModule(const Mcu_ResetSigType *const *rstDeassertPtr,
        const Mcu_ModuleType *modulePtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 i;
    const Mcu_ModuleType *modPtr = modulePtr;

    if ((NULL_PTR != rstDeassertPtr) && (NULL_PTR != modulePtr))
    {
        /*sw reset for btm*/
        Mcu_Ip_SocResetBtm();

        /*sw reset for epwm and etimer*/
        for (; *modPtr != MODULE_END; modPtr++)
        {
            Mcu_Ip_SocResetLatentIp(*modPtr);
        }

        for (i = 0U; i < XSPI_NUM; i++)
        {
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i)], 0U);
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i) + 2U], 0U);
            readl(xspiBse[i]);
        }

        /* Release 'reset' of every modules */
        for ( i = 0U; i < Mcu_GetDeassertArraySize(); i++)
        {
            errStatus = Mcu_Ip_ResetCtlReset(rstDeassertPtr[i]);

            if (E_OK != errStatus)
            {
                break;
            }/* else not needed */
        }

        /*clear xspi sem error after xspi reset*/
        for (i = 0U; i < XSPI_NUM; i++)
        {
            readl(xspiBse[i]);
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i) + 1U], 1U);
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i) + 1U], 0U);
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i) + 3U], 1U);
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i) + 3U], 0U);
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i)], 1U);
            Mcu_Ip_SocScrSetBit(&signalScrXspi[(4U * i) + 2U], 1U);
        }

        if (E_OK == errStatus)
        {
            /*clear mailbox sem error after mailbox reset*/
            errStatus = Mcu_Ip_SocResetMailbox();
            /*set dcdc mode after dcdc reset*/
            Mcu_Ip_DcdcModeSet();
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_AssertUnusedModule(const Mcu_ResetSigType *const *rstAssertPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 i;

    if (NULL_PTR != rstAssertPtr)
    {
        for (i = 0U; i < Mcu_GetAssertArraySize(); i++)
        {
            errStatus = Mcu_Ip_ResetCtlAssert(rstAssertPtr[i]);

            if (E_OK != errStatus)
            {
                break;
            } /* else not needed */
        }
    } /* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_EnableUsedClock(const Mcu_ClkNodeType *const *clkEnablePtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 i;

    if (NULL_PTR != clkEnablePtr)
    {
        for (i = 0U; i <  Mcu_GetClkEnableArraySize(); i++)
        {
            errStatus = Mcu_Ip_ClkEnable(clkEnablePtr[i]);

            if (E_OK != errStatus)
            {
                break;
            } /* else not needed */
        }
    } /* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_DisableUnusedClock(const Mcu_ClkNodeType *const *clkDisablePtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 i;

    if (NULL_PTR != clkDisablePtr)
    {
        for (i = 0U; i <  Mcu_GetClkDisableArraySize(); i++)
        {
            errStatus = Mcu_Ip_ClkDisable(clkDisablePtr[i]);

            if (E_OK != errStatus)
            {
                break;
            } /* else not needed */
        }
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_PrepareClockTree(const Mcu_ClkNodeType *const *clkPreparePtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 i;

    if (NULL_PTR != clkPreparePtr)
    {
        for (i = 0U; i < Mcu_GetClkPrepareArraySize(); i++)
        {
            /*PRQA S 0311 1*/
            errStatus = Mcu_Ip_ClkPrepare((Mcu_ClkNodeType *)clkPreparePtr[i]);

            if (E_OK != errStatus)
            {
                break;
            } /* else not needed */
        }
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
static void Mcu_PowerGate(const Mcu_PowerDomType *domPtr)
{
    const Mcu_PowerDomType *domainPtr = domPtr;

    for (; *domainPtr != DOM_END; domainPtr++)
    {
        if (*domainPtr == AP_DOM)
        {
            continue;
        } /* else not needed */

        Mcu_Ip_SocPowerGate(*domainPtr);
    }
}
#if (MCU_PLL_SPREAD == STD_ON)
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_PllSpread(const Mcu_PllSpreadConfigType *pllSpreadPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 i;
    const Mcu_PllSpreadConfigType *pllSpreadTest;

    if (NULL_PTR != pllSpreadPtr)
    {
        pllSpreadTest = pllSpreadPtr;

        for (i = 0U; i <  Mcu_GetPllSpreadArraySize(); i++)
        {
            errStatus = Mcu_Ip_PllDrvConfigSpread(pllSpreadTest);

            if (E_OK != errStatus)
            {
                break;
            } /* else not needed */

            pllSpreadTest++;
        }
    } /* else not needed */

    return errStatus;
}
#endif /**#if (MCU_PLL_SPREAD == STD_ON)*/

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_RamSectionConfig(const Mcu_RamConfigType *cfgPtr)
{
    Std_ReturnType errStatus = E_OK;
    uint32 i;
    uint32 writeCnt;
    uint64 value;
    uint8 *basePtr1;
    uint16 *basePtr2;
    uint32 *basePtr3;
    uint64 *basePtr4;

    if (NULL_PTR == cfgPtr)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        writeCnt = cfgPtr->size / cfgPtr->writeSize;

        switch (cfgPtr->writeSize)
        {
        case 1U:
            /* #10  writing at once a number of 1 byte*/
            value = cfgPtr->defaultValue;
            /*PRQA S 0306 1*/
            basePtr1 = (uint8 *)cfgPtr->base;

            for (i = 0U; i < writeCnt; i++)
            {
                *basePtr1 = (uint8)value;
                basePtr1++;
            }

            break;

        case 2U:
            /* #20  writing at once a number of 2 bytes*/
            value = cfgPtr->defaultValue;
            value = value | (value << 8U);
            /*PRQA S 0306 1*/
            basePtr2 = (uint16 *)cfgPtr->base;

            if ((0U != (cfgPtr->base % 2U)) || (0U != (cfgPtr->size % 2U)))
            {
                errStatus = MCU_E_PARAM_RAMSECTION;
            }
            else
            {
                for (i = 0U; i < writeCnt; i++)
                {
                    *basePtr2 = (uint16)value;
                    basePtr2++;
                }
            }

            break;

        case 4U:
            /* #30  writing at once a number of 4 bytes*/
            value = cfgPtr->defaultValue;
            value = value | (value << 8U);
            value = value | (value << 16U);
            /*PRQA S 0306 1*/
            basePtr3 = (uint32 *)cfgPtr->base;

            if ((0U != (cfgPtr->base % 4U)) || (0U != (cfgPtr->size % 4U)))
            {
                errStatus = MCU_E_PARAM_RAMSECTION;
            }
            else
            {
                for (i = 0U; i < writeCnt; i++)
                {
                    *basePtr3 = (uint32)value;
                    basePtr3++;
                }
            }

            break;

        case 8U:
            /* #40  writing at once a number of 8 bytes*/
            value = cfgPtr->defaultValue;
            value = value | (value << 8U);
            value = value | (value << 16U);
            value = value | (value << 32U);
            /*PRQA S 0306 1*/
            basePtr4 = (uint64 *)cfgPtr->base;

            if ((0U != (cfgPtr->base % 8U)) || (0U != (cfgPtr->size % 8U)))
            {
                errStatus = MCU_E_PARAM_RAMSECTION;
            }
            else
            {
                for (i = 0U; i < writeCnt; i++)
                {
                    *basePtr4 = value;
                    basePtr4++;
                }
            }

            break;

        default:
            errStatus = MCU_E_PARAM_RAMSECTION;
            break;
        }
    }

    return errStatus;
}
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
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
Std_ReturnType Mcu_EnterCheck(const uint8 serviceId)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check Mcu_Init service*/
    if (MCU_SID_INIT == serviceId)
    {
        /* If "Mcu_Init" was already called (i.e. driver is initialized), return error. */
        if (NULL_PTR != Mcu_CfgPtr)
        {
            errStatus = MCU_E_INIT;
        }/* else not needed */
    }
    /* #20 Check other services*/
    else
    {
        /* If "Mcu_Init" was not called (i.e driver is uninitialized), return error. */
        McuHookBegin_Mcu_EnterCheck();

        if (NULL_PTR == Mcu_CfgPtr)
        {
            errStatus = MCU_E_UNINIT;
        }/* else not needed */

        McuHookEnd_Mcu_EnterCheck();
    }

    return errStatus;
}

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
void Mcu_Init(const Mcu_ConfigType *ConfigPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_INIT);

    if (E_OK == errStatus)
    {
        /* #20 Check input parameters for plausibility */
        if (NULL_PTR == ConfigPtr)
        {
            errStatus = MCU_E_INIT_FAILED;
        }
        else
        {
            /* ----- Implementation ----------------------------------------------- */
            /* #201 enable 3.3V power-off reset*/
#if (MCU_3V3POWEROFF_RESET == STD_ON)
            Mcu_Ip_Pmu3v3PorOffReset();
#endif /** #if (MCU_3V3POWEROFF_RESET == STD_ON)*/
            /* #30 enable Bti for core reset*/
            Mcu_Ip_SocBtiEnable();
#ifndef SEMIDRIVE_E3_LITE_SERIES
            /* #40 release GPIOLx if GPIOLx is not used for display*/
#if (STD_ON == MCU_RELEASE_DISPLAY_PIN)
            MCU_Ip_SocDispalyPadRelease();
#endif /** #if (STD_ON == MCU_RELEASE_DISPLAY_PIN)*/
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
            /* #50 dcdc/ldo power down if not use*/
#if (STD_ON == MCU_DCDC_POWERDOWN)
            Mcu_Ip_PmuDcdcEn(FALSE);
#endif/** #if (STD_ON == MCU_DCDC_POWERDOWN)*/

#if (STD_ON == MCU_LDO_POWERDOWN)
            Mcu_Ip_PmuLdoEn(FALSE);
#endif/** #if (STD_ON == MCU_LDO_POWERDOWN)*/
            /* #60 analog trim*/
            Mcu_Ip_Rc24m_Trim();
            Mcu_Ip_AnalogTrimBgr33();

            /* #70 low power RTC mode configure*/
            errStatus = Mcu_Ip_RtcModeConfig(ConfigPtr->rtcModeCfgPtr);

            /* #80 low power control ctrl pilarity configure */
            if ((NULL_PTR != ConfigPtr->pwrCtrlCfgPtr) && (E_OK == errStatus))
            {
                errStatus = Mcu_Ip_RtcModePmuSetPwrCtrlConfig(ConfigPtr->pwrCtrlCfgPtr->config,
                            ConfigPtr->pwrCtrlCfgPtr->runPmu,
                            ConfigPtr->pwrCtrlCfgPtr->pwrupPmu);
            } /* else not needed */

            /* #90 Save configuration pointer in global variable */
            Mcu_CfgPtr = ConfigPtr;

#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
            /* #100 Update RTC domain PCLK reference count*/
            McuRtcSSPclkRef = -1;
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */
        }
    }/* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #100 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
}

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
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    /* Variable used to store current clock configuration */
    const Mcu_ClockConfigType *clkConfigsPtr;
    /* Variable used to store current ip modules*/
    const Mcu_HwIpsConfigType *hwIpsCfgPtr;
    const Mcu_ModuleType *modulePtr;
    /* Variable used to store current domian power configuration*/
    const Mcu_NormalModeConfigType *normalCfgPtr;
    const Mcu_PowerDomType *domPtr;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_INIT_CLOCK);

    /* #20 Check input parameters for plausibility */
    if (E_OK == errStatus)
    {
        hwIpsCfgPtr = Mcu_CfgPtr->hwIpsCfgPtr;
        normalCfgPtr = Mcu_CfgPtr->normalModeCfgPtr;

        if (ClockSetting >= Mcu_CfgPtr->numClkCfgs)
        {
            errStatus = MCU_E_PARAM_CLOCK;
        }
        else
        {
            clkConfigsPtr = Mcu_CfgPtr->clkCfgsPtr[ClockSetting];

            if ((NULL_PTR == hwIpsCfgPtr) || (NULL_PTR == normalCfgPtr))
            {
                errStatus = MCU_E_PARAM_POINTER;
            }
            else
            {
                modulePtr = hwIpsCfgPtr->modules;
                domPtr = normalCfgPtr->dom;

                if ((NULL_PTR == modulePtr) ||  (NULL_PTR == domPtr))
                {
                    errStatus = MCU_E_PARAM_POINTER;
                } /* else not needed */
            }
        }
    } /* else not needed */

    /* ----- Implementation ----------------------------------------------- */
    /* #30 reset used module */
    CALL_RET_CHECK(errStatus, Mcu_ResetUsedModule(clkConfigsPtr->rstDeassert, modulePtr));

    /* #40 Enable used clock.*/
    CALL_RET_CHECK(errStatus, Mcu_EnableUsedClock(clkConfigsPtr->clkEnable));

    /* #50 Prepare clock tree. */
    CALL_RET_CHECK(errStatus, Mcu_PrepareClockTree(clkConfigsPtr->clkPrepare));

    /* #60 disable unused clock */
    CALL_RET_CHECK(errStatus, Mcu_DisableUnusedClock(clkConfigsPtr->clkDisable));

    /* #70 assert unused module */
    CALL_RET_CHECK(errStatus, Mcu_AssertUnusedModule(clkConfigsPtr->rstAssert));

    /* #80 pll spread */
#if (MCU_PLL_SPREAD == STD_ON)
    CALL_RET_CHECK(errStatus, Mcu_PllSpread(clkConfigsPtr->pllSpread));
#endif /**#if (MCU_PLL_SPREAD == STD_ON)*/

    /* #90 power gate unused memory for different part */
    if (E_OK == errStatus)
    {
        Mcu_PowerGate(domPtr);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #100 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_CLOCK,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_CLOCK,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #110 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
    /* Before disabling RTC domain PCLK, disable RTC Timer1/Timer2 parity error interrupt;
    otherwise, unexpected behaviors are triggered. */
    Mcu_Ip_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
    Mcu_Ip_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);
    Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_rtc_pclk));
    McuRtcSSPclkRef = 0;
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

    return errStatus;
}

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
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    /* Variable used to store ram configuration */
    const Mcu_RamConfigType *cfgPtr;
    uint32 i;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Mcu_EnterCheck(MCU_SID_INIT_RAM_SECTION);

    if (E_OK == errStatus)
    {
        if ((0U == Mcu_CfgPtr->numRamSections) || (NULL_PTR == Mcu_CfgPtr->ramCfgsPtr))
        {
            errStatus = MCU_E_PARAM_RAMSECTION;
        }
        else
        {
            /* #20 Check input parameters for plausibility */
            /* PRQA S 0310 1*/
            cfgPtr = (const Mcu_RamConfigType *)Mcu_CfgPtr->ramCfgsPtr;

            for (i = 0; i < Mcu_CfgPtr->numRamSections; i++)
            {
                if (RamSection == cfgPtr->idx)
                {
                    break;
                } /* else not needed */

                cfgPtr++;
            }

            if (i >= Mcu_CfgPtr->numRamSections)
            {
                errStatus = MCU_E_PARAM_RAMSECTION;
            }
            else
            {
                /* ----- Implementation ----------------------------------------------- */
                /* #30  initializes the RAM section wise */
                errStatus = Mcu_RamSectionConfig(cfgPtr);
            }
        }

    }/* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #40 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_RAM_SECTION,
                              (uint8)errStatus);
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_INIT_RAM_SECTION, (uint8)errStatus);
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #50 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}

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
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    /* Variable used to store current pll lock status */
    boolean isLocked;
    Mcu_PllStatusType pllStatus = MCU_PLL_STATUS_UNDEFINED;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
#if (STD_OFF == MCU_NO_PLL)
    errStatus = Mcu_EnterCheck(MCU_SID_GET_PLL_STATUS);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20  Check pll lock states */
        isLocked = Mcu_Ip_PllIsLocked(APB_PLL1_BASE);
        isLocked &= Mcu_Ip_PllIsLocked(APB_PLL2_BASE);
        isLocked &= Mcu_Ip_PllIsLocked(APB_PLL3_BASE);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        isLocked &= Mcu_Ip_PllIsLocked(APB_PLL4_BASE);
        isLocked &= Mcu_Ip_PllIsLocked(APB_PLL5_BASE);
        isLocked &= Mcu_Ip_PllIsLocked(APB_PLL_LVDS_BASE);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

        /* #30 if all pll locked, return locked. otherwise, return unlocked.*/
        if (TRUE == isLocked)
        {
            pllStatus = MCU_PLL_LOCKED;
        }
        else
        {
            pllStatus = MCU_PLL_UNLOCKED;
        }
    }

#else
    errStatus = E_OK;
    isLocked = TRUE;
    MCU_DUMMY_STATEMENT(isLocked);
#endif /**#if (STD_OFF == MCU_NO_PLL)*/
    /* ----- Development Error Report --------------------------------------- */
    /* #40 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GET_PLL_STATUS,
                              (uint8)errStatus);
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_GET_PLL_STATUS, (uint8)errStatus);
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #50 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return pllStatus;
}

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
Mcu_ResetType Mcu_GetResetReason(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    Mcu_ResetType resetType = MCU_RESET_UNDEFINED;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Mcu_EnterCheck(MCU_SID_GET_RESET_REASON);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20  read raw reset reason from register */
        resetType = Mcu_Ip_GetResetReason(APB_RSTGEN_SF_BASE);
    }/* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #40 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GET_RESET_REASON,
                              (uint8)errStatus);
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_GET_RESET_REASON, (uint8)errStatus);
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #50 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return resetType;
}

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
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    /* Variable used to store current reset type */
    Mcu_RawResetType resetRawType = 0xF0000000U;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Mcu_EnterCheck(MCU_SID_GET_RESET_RAW_VALUE);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20  read raw reset reason from register */
        resetRawType = Mcu_Ip_GetResetRawValue(APB_RSTGEN_SF_BASE);
    }/* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                              (uint8)MCU_SID_GET_RESET_RAW_VALUE, (uint8)errStatus);
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_GET_RESET_RAW_VALUE, (uint8)errStatus);
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return resetRawType;
}

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
void Mcu_PerformReset(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Mcu_EnterCheck(MCU_SID_PERFORM_RESET);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20  global reset */
        errStatus = Mcu_Ip_ResetCtlGlobalReset(&rstctl_glb);
    }/* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_PERFORM_RESET,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_PERFORM_RESET,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
}
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
void Mcu_SetMode(Mcu_ModeType McuMode)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint32 timesOut = RTC_ENTER_FAIL_WAIT_TIME;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Mcu_EnterCheck(MCU_SID_SET_MODE);

    if (E_OK == errStatus)
    {
        /* #20 Check input parameters for plausibility */
        if ((MCU_MODE_RTC != McuMode) || (NULL_PTR == Mcu_CfgPtr->rtcModeCfgPtr))
        {
            errStatus = MCU_E_PARAM_MODE;
        }
        else
        {
            if ((NULL_PTR != Mcu_CfgPtr->rtcModeCfgPtr->rtc)
                    && (NULL_PTR != Mcu_CfgPtr->rtcModeCfgPtr->wakeupsrc))
            {
                /* ----- Development Error Report --------------------------------------- */
                /* #30  Enter rtc mode process */
                /* Rtc wakeup Config*/
                errStatus = Mcu_RtcWakeupConfig(&Mcu_PwrRtcSleepTime[MCU_MODE_RTC],
                                                Mcu_CfgPtr->rtcModeCfgPtr->rtc);
                Mcu_Ip_Fs32KTrySwitchToXtal(APB_FS_32K_BASE);
                Mcu_Ip_RtcSetSleepTime(APB_RTC1_BASE,RTC_Timer,RTC_TIMER_MODE_MIN);
            }/* else not needed */

            if (E_OK == errStatus)
            {
                /*LPVD_CTRL:cut down power resume */
                Mcu_Ip_XtalLpvdPowerSwitch(LPVD_POWER_DOWN);

                /* Set to enter rtc mode */
                Mcu_Ip_PmuPwrdown();

                while (timesOut != 0U)
                {
                    errStatus = Mcu_udelay(1000U);
                    timesOut--;
                }

                if (E_OK == errStatus)
                {
                    errStatus = MCU_E_RTC_ENTER_FAIL;
                }

            }/* else not needed */
        }
    }/* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #40 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

#if (STD_ON == MCU_DEV_ERROR_DETECT)
    (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_SET_MODE,
                          (uint8)errStatus);
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
    (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_SET_MODE,
                               (uint8)errStatus);
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE) */
#else
    {
        /* #50 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
}
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
void Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus = E_OK;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == versioninfo)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Retrieve version information */
        versioninfo->vendorID = MCU_VENDOR_ID;
        versioninfo->moduleID = MCU_MODULE_ID;
        versioninfo->sw_major_version = MCU_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = MCU_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = MCU_SW_PATCH_VERSION;
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, MCU_SID_GET_VERSION_INFO,
                              MCU_E_PARAM_POINTER);
#endif /**#if STD_ON == MCU_DEV_ERROR_DETECT*/
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, MCU_SID_GET_VERSION_INFO,
                              MCU_E_PARAM_POINTER);
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE) */
    } /* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
}
#endif /**#if (STD_ON == MCU_VERSION_INFO_API) */

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
