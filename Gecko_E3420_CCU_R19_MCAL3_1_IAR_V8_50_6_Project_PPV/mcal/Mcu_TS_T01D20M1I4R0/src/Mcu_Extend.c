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
 * \file     Mcu_Extend.c                                                                            *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_Cfg.h"
#if (STD_ON == MCU_DEV_ERROR_DETECT)
#include "Det.h"
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT)*/
#if (STD_ON == MCU_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE)*/
#include "Mcu_ClkCfgNd.h"
#include "Mcu_ResetSig.h"
#include "Mcu_Extend.h"
#include "Mcu.h"
#include "RegBase.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function power on pll and wait the lock status.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Mcu_EnablePll(const Mcu_ClkNodeType *clkPtr, uint32 timesOut)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : clkPtr - Pointer to pllnode
 *                      timesOut - timeout
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function power on pll and wait the lock status.
 * \endverbatim
 * Traceability       : SW_MCU_SM011 SW_SM005
 *******************************************************************************************************/
static Std_ReturnType Mcu_EnablePll(const Mcu_ClkNodeType *clkPtr, uint32 timesOut)
{
    Std_ReturnType errStatus;

    errStatus = Mcu_Ip_ClkEnable(clkPtr);
    if(E_OK == errStatus)
    {
        while (0U != timesOut)
        {
            if(FALSE == Mcu_Ip_ClkIsLocked(clkPtr))
            {
                /*PRQA S 1338 1*/
                timesOut--;
            }
            else
            {
                break;
            }
        }
        if (0U == timesOut)
        {
            errStatus = MCU_E_PLL_NOT_LOCKED;
        } /* else not needed */
    }/* else not needed */
    return errStatus;
}
#endif
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function set clock rate.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_ClkSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to clock node to set rate
 *                      rate - clock rate to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set clock rate.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_ClkSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_SET_RATE);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_ClkSetRate(clkPtr, rate);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_SET_RATE,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_SET_RATE,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return  errStatus;
}
/** *****************************************************************************************************
 * \brief This function get clock rate.
 *
 * \verbatim
 * Syntax             : Mcu_ClkRateType Mcu_ClkGetRate(Mcu_ClkNodeType *clkPtr)
 *
 * Service ID[hex]    : 0x12
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to clock node to get rate
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : clock rate value
 *
 * Description        : This function get clock rate.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Mcu_ClkRateType Mcu_ClkGetRate(Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus;
    Mcu_ClkRateType rate = UINT32_MAX;
    errStatus = Mcu_EnterCheck(MCU_SID_GET_RATE);

    if (E_OK == errStatus)
    {
        rate = Mcu_Ip_ClkGetRate(clkPtr);

        if (rate == UINT32_MAX)
        {
            errStatus = MCU_E_OUTRANGE;
        } /* else not needed */
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GET_RATE,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GET_RATE,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return rate;
}
#ifdef CONFIG_CLK_MONITOR
/** *****************************************************************************************************
 * \brief This function monitor clock rate.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_CkgenMonFreq(Mcu_CkgenMonFreqType *ckgenMonFreqPtr)
 *
 * Service ID[hex]    : 0x13
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : ckgenMonFreqPtr - Pointer to clock monitor node
 *
 * Parameters (out)   : None
 *
 * Return value       : clock monitor status
 *                      0 - the monitor status of clock rate is ok
 *                      !0 - the monitor status of clock rate is not ok
 *
 * Description        : This function monitor clock rate.
 * \endverbatim
 * Traceability       : SWSR_MCU_049 SW_SM001
 *******************************************************************************************************/
uint8 Mcu_CkgenMonFreq(Mcu_CkgenMonFreqType *ckgenMonFreqPtr)
{
    Std_ReturnType errStatus;
    uint8 ret = 0xFFU;

    errStatus = Mcu_EnterCheck(MCU_SID_MONITOR_FREQ);
    if (E_OK == errStatus)
    {
        if (NULL_PTR == ckgenMonFreqPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            ret = Mcu_Ip_CkgenMonFreq(ckgenMonFreqPtr);

            if (0xFFU == ret)
            {
                errStatus = MCU_E_OUTRANGE;
            }
            else
            {
                errStatus = E_OK;
            }
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_MONITOR_FREQ,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_MONITOR_FREQ,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return  ret;

}
/** *****************************************************************************************************
 * \brief This function monitor clock cqm.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_CkgenCqm(Mcu_CkgenCqmType *ckgenCqmPtr)
 *
 * Service ID[hex]    : 0x14
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : ckgenCqmPtr - Pointer to clock cqm monitor node
 *
 * Parameters (out)   : None
 *
 * Return value       : clock monitor status
 *                      0 - the monitor status of clock cqm is ok
 *                      !0 - the monitor status of clock cqm is not ok
 *
 * Description        : This function monitor clock cqm.
 * \endverbatim
 * Traceability       : SWSR_MCU_049 SW_SM001
 *******************************************************************************************************/
uint8 Mcu_CkgenCqm(Mcu_CkgenCqmType *ckgenCqmPtr)
{
    Std_ReturnType errStatus;
    uint8 ret = 0xFFU;

    errStatus = Mcu_EnterCheck(MCU_SID_CQM);

    if (E_OK == errStatus)
    {
        if (NULL_PTR == ckgenCqmPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            ret = Mcu_Ip_CkgenCqm(ckgenCqmPtr);

            if (0xFFu == ret)
            {
                errStatus = MCU_E_OUTRANGE;
            }
            else
            {
                errStatus = E_OK;
            }
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_CQM,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_CQM,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return  ret;

}
#endif

/** *****************************************************************************************************
 * \brief This function set the dcdc detect.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_DcdcFaultDetect(const Dcdc_OvUvCfgType *dcdcCfgPtr)
 *
 * Service ID[hex]    : 0xB
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : dcdcCfgPtr - Pointer to dcdc detect set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set the dcdc detect.
 * \endverbatim
 * Traceability       : SWSR_MCU_052 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_DcdcFaultDetect(const Dcdc_OvUvCfgType *dcdcCfgPtr)
{
    Std_ReturnType errStatus;

    errStatus = Mcu_EnterCheck(MCU_SID_INIT_VD);

    if (E_OK == errStatus)
    {
        if (NULL_PTR == dcdcCfgPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {

            errStatus = Mcu_Ip_DcdcFaultDetect(dcdcCfgPtr);
        } /* else not needed */
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_VD,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_VD,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return  errStatus;
}

/** *****************************************************************************************************
 * \brief This function kickcore.
 *
 * \verbatim
 * Syntax             : void Mcu_SocKickCore(Mcu_KickCoreType core, uint32 entry)
 *
 * Service ID[hex]    : 0x15
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : core - core to reset
 *                      entry - address to remap
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function kickcore.
 * \endverbatim
 * Traceability       : SW_SM001
 *******************************************************************************************************/
void Mcu_SocKickCore(Mcu_KickCoreType core, uint32 entry)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_KICK_CORE);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_SocKickCore(core, entry);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_KICK_CORE,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_KICK_CORE,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return;
}

/** *****************************************************************************************************
 * \brief This function enable temperature monitor.
 *
 * \verbatim
 * Syntax             : void Mcu_PvtInit(void)
 *
 * Service ID[hex]    : 0xA
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
 * Return value       : errorId
 *
 * Description        : This function enable temperature monitor.
 * \endverbatim
 * Traceability       : SWSR_MCU_051 SW_SM001
 *******************************************************************************************************/
void Mcu_PvtInit(void)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_INIT_PVT);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_PvtPrepare();
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_PVT,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_PVT,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
}

/** *****************************************************************************************************
 * \brief This function get temperature value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_PvtGet(Mcu_PvtType *devPtr, float *temperaturePtr)
 *
 * Service ID[hex]    : 0xA
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : devPtr - pointer to pvt device
 *
 * Parameters (inout) : temperaturePtr - pointer to pvt value
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function get temperature value.
 * \endverbatim
 * Traceability       : SWSR_MCU_051 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_PvtGet(Mcu_PvtType *devPtr, float *temperaturePtr)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_INIT_PVT);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_PvtGet(devPtr, temperaturePtr);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_PVT,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_PVT,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}

/** *****************************************************************************************************
 * \brief This function get SF PVT sensor device.
 *
 * \verbatim
 * Syntax             : Mcu_PvtType *Mcu_PvtGetSfDevice(void)
 *
 * Service ID[hex]    : none
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
 * Return value       : SF PVT sensor device
 *
 * Description        : This function get SF PVT sensor device.
 * \endverbatim
 * Traceability       : SWSR_MCU_051
 *******************************************************************************************************/
Mcu_PvtType *Mcu_PvtGetSfDevice(void)
{
    return Mcu_Ip_PvtGetSfDevice();
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function get AP PVT sensor device.
 *
 * \verbatim
 * Syntax             : Mcu_PvtType *Mcu_PvtGetApDevice(void)
 *
 * Service ID[hex]    : none
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
 * Return value       : AP PVT sensor device
 *
 * Description        : This function get AP PVT sensor device.
 * \endverbatim
 * Traceability       : SWSR_MCU_051
 *******************************************************************************************************/
Mcu_PvtType *Mcu_PvtGetApDevice(void)
{
    return Mcu_Ip_PvtGetApDevice();
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function enable temperature monitor for VD.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_PvtForVdInit(const Mcu_PvtForVdType *vDconfigPtr)
 *
 * Service ID[hex]    : 0xA
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : vDconfigPtr - pointer to vd pvt config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function enable temperature monitor for VD.
 * \endverbatim
 * Traceability       : SWSR_MCU_051 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_PvtForVdInit(const Mcu_PvtForVdType *vDconfigPtr)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_INIT_PVT);

    if (E_OK == errStatus)
    {
        if (NULL_PTR == vDconfigPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            errStatus = Mcu_Ip_PvtForVdInit(vDconfigPtr);
        }
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_PVT,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_PVT,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

/** *****************************************************************************************************
 * \brief This function read general register value.
 *
 * \verbatim
 * Syntax             : uint32 Mcu_ResetCtlGeneralRead(const Mcu_ResetGeneralRegType *generalPtr)
 *
 * Service ID[hex]    : 0x16
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : generalPtr - pointer to general register
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : general reg value
 *
 * Description        : This function read general register value.
 * \endverbatim
 *******************************************************************************************************/
uint32 Mcu_ResetCtlGeneralRead(const Mcu_ResetGeneralRegType *generalPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 ret = UINT32_MAX;
    const Mcu_ResetCtlType *ctlPtr;

    if (NULL_PTR != generalPtr)
    {
        ctlPtr = generalPtr->rstCtl;

        if ((NULL_PTR != ctlPtr) && (NULL_PTR != ctlPtr->ops) && (NULL_PTR != ctlPtr->ops->readGeneral))
        {

            ret = ctlPtr->ops->readGeneral(ctlPtr, generalPtr->id);

            errStatus = E_OK;
        } /* else not needed */
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GENERAL_READ,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GENERAL_READ,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return ret;
}

/** *****************************************************************************************************
 * \brief This function Write general register value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_ResetCtlGeneralWrite(const Mcu_ResetGeneralRegType *generalPtr, uint32 val)
 *
 * Service ID[hex]    : 0x17
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : generalPtr - pointer to general register
 *                      val - value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *                      0 if success,
 *                      other error code.
 *
 * Description        : This function Write general register value.
 * \endverbatim
 *******************************************************************************************************/
Std_ReturnType Mcu_ResetCtlGeneralWrite(const Mcu_ResetGeneralRegType *generalPtr, uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    const Mcu_ResetCtlType *ctlPtr;

    if (NULL_PTR != generalPtr)
    {
        ctlPtr = generalPtr->rstCtl;

        if ((NULL_PTR != ctlPtr) && (NULL_PTR != ctlPtr->ops) && (NULL_PTR != ctlPtr->ops->writeGeneral))
        {
            errStatus = ctlPtr->ops->writeGeneral(ctlPtr, generalPtr->id, val);
        } /* else not needed */
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GENERAL_WRITE,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_GENERAL_WRITE,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}

/** *****************************************************************************************************
 * \brief This function write global reset mask.
 *
 * \verbatim
 * Syntax             : void Mcu_RstgenRgGlbResetEn(uint32 base, uint32 msk)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - rstgen base
 *                      msk - value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function write global reset mask.
 * \endverbatim
 *******************************************************************************************************/
void Mcu_RstgenRgGlbResetEn(uint32 base, uint32 msk)
{
    Mcu_Ip_RstgenRgGlbResetEn(base, msk);
}

/** *****************************************************************************************************
 * \brief This function disable rtc ParityErrInt.
 *
 * \verbatim
 * Syntax             : void Mcu_RtcDisableRegParityErrIntEnable(uint32 base)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - rtc base
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disable rtc ParityErrInt.
 * \endverbatim
 *******************************************************************************************************/
void Mcu_RtcDisableRegParityErrIntEnable(uint32 base)
{
    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    Mcu_Ip_RtcDisableRegParityErrIntEnable(base);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function enable rtc ParityErrInt.
 *
 * \verbatim
 * Syntax             : void Mcu_RtcEnableRegParityErrIntEnable(uint32 base)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - rtc base
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function enable rtc ParityErrInt.
 * \endverbatim
 *******************************************************************************************************/
void Mcu_RtcEnableRegParityErrIntEnable(uint32 base)
{
    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    Mcu_Ip_RtcEnableRegParityErrIntEnable(base);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function set rtc wakeup config.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_RtcWakeupConfig(Mcu_RtcAlarmType *manualPtr, const Mcu_RtcAlarmType *rtcPtr)
 *
 * Service ID[hex]    : 0x18
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : manualPtr - pointer to manual cofnig
 *                      rtcPtr - pointer to rtc cofnig
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set rtc wakeup config.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_RtcWakeupConfig(Mcu_RtcAlarmType *manualPtr, const Mcu_RtcAlarmType *rtcPtr)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_RTC_WAKEUP);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_RtcWakeupConfig(manualPtr, rtcPtr);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_RTC_WAKEUP,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_RTC_WAKEUP,
                                   (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}

/** *****************************************************************************************************
 * \brief This function set pmu power contol config.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_PmuPowerControlSignalConfig(const Mcu_PmuStateType pmuMode,
 *                       const Mcu_PwrSigType *pmuPtr)
 *
 * Service ID[hex]    : 0x19
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - pmuMode
 *                      pmuPtr - pointer to pmu cofnig
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set pmu power contol config.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_PmuPowerControlSignalConfig(const Mcu_PmuStateType pmuMode,
        const Mcu_PwrSigType *pmuPtr)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_POWER_CONTROL_SIGNAL);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_PmuPowerControlSignalConfig(pmuMode, pmuPtr);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                              (uint8)MCU_SID_POWER_CONTROL_SIGNAL, (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_POWER_CONTROL_SIGNAL, (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}

/** *****************************************************************************************************
 * \brief This function set clock gate by mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_CkgenXcgSetGatingByMode(uint32 base, uint32 id, uint8 lpMode, boolean en)
 *
 * Service ID[hex]    : 0xF
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - ckgen base
 *                      id - clock gate id
 *                      lpMode - lpMode
 *                      en - on or off
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set clock gate by mode.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_CkgenXcgSetGatingByMode(uint32 base, uint32 id, uint8 lpMode, boolean en)
{
    Std_ReturnType errStatus;
    errStatus = Mcu_EnterCheck(MCU_SID_SET_GATE_BYMODE);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_CkgenXcgSetGatingByMode(base, id, lpMode, en);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_SET_GATE_BYMODE,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_SET_GATE_BYMODE, (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}

/** *****************************************************************************************************
 * \brief This function set seip clock.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_SetSeipClock(boolean enable)
 *
 * Service ID[hex]    : 0xD
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - TRUE-clock is normal; FALSE- clock is 24M.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *                      E_OK for success and E_NOT_OK for failure.
 *
 * Description        : This function set seip clock.
 *                      if pll4 is off, the seip clock is 24M,
                        and when the seip task is required to run, the interface needs to be called to set clock to normal,
                        and after the task is completed, the interface needs to be called to set the clock to 24M.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_SetSeipClock(boolean enable)
{
    Std_ReturnType errStatus;
#ifndef SEMIDRIVE_E3_LITE_SERIES
#ifndef MCU_APBUS_FREQUENCY_NORMAL
    boolean isLocked1;
    boolean isLocked2;
    const Mcu_ClkNodeType *clkPtr = CLK_NODE(g_ckgen_bus_seip_div_root);
    uint32 timesOut = PLL_WAIT_TIME;
#endif
#endif
    errStatus = Mcu_EnterCheck(MCU_SID_SET_SEIP_CLOCK);

    if (E_OK == errStatus)
    {
#ifndef SEMIDRIVE_E3_LITE_SERIES
#ifndef MCU_APBUS_FREQUENCY_NORMAL

        if (TRUE == enable)
        {
            errStatus = Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_sh_clk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_pclk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_hclk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_fd_ref_clk));
            errStatus = errStatus | Mcu_EnablePll(clkPtr->parents[clkPtr->mux], timesOut);
            errStatus = errStatus | Mcu_EnablePll(clkPtr->parents[4], timesOut);

            if (E_OK == errStatus)
            {
                errStatus = Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_div_root));
                errStatus = errStatus | Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_div_p));
                errStatus = errStatus | Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_div_n));
                errStatus = errStatus | Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_root));
            }

        }
        else
        {
            isLocked1 = Mcu_Ip_ClkIsLocked(clkPtr->parents[clkPtr->mux]);
            isLocked2 = Mcu_Ip_ClkIsLocked(clkPtr->parents[4]);

            if ((FALSE == isLocked1) || (FALSE == isLocked2))
            {
                errStatus = Mcu_EnablePll(clkPtr->parents[clkPtr->mux], timesOut);
                errStatus = errStatus | Mcu_EnablePll(clkPtr->parents[4],timesOut);
            }

            if (E_OK == errStatus)
            {
                /*before pll down, Nodes that use this pll need to switch to 24M*/
                errStatus = Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_div_root_preset));
                errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_sh_clk));
                errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_pclk));
                errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_hclk));
                errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_fd_ref_clk));
                errStatus = errStatus | Mcu_Ip_ClkDisable(clkPtr->parents[clkPtr->mux]);
                errStatus = errStatus | Mcu_Ip_ClkDisable(clkPtr->parents[4]);
            }
        }
#else
        if (TRUE == enable)
        {
            errStatus = Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_sh_clk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_pclk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_hclk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_fd_ref_clk));
        }
        else
        {
            errStatus = Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_sh_clk));
            errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_pclk));
            errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_hclk));
            errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_fd_ref_clk));
        }
#endif /** #ifndef MCU_APBUS_FREQUENCY_NORMAL*/
#else

        if (TRUE == enable)
        {
            errStatus = Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_sh_clk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_i_pclk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_i_hclk));
            errStatus = errStatus | Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_seip_i_fd_ref_clk));
        }
        else
        {
            errStatus = Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_sh_clk));
            errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_i_pclk));
            errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_i_hclk));
            errStatus = errStatus | Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_seip_i_fd_ref_clk));
        }

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    }/* else not needed */


    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_SET_SEIP_CLOCK,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_SET_SEIP_CLOCK, (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function set/cancle AP domain PLL force bypass.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_ApPllBybass(boolean bypassEn)
 *
 * Service ID[hex]    : 0x20
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bypassEn - TRUE- set pll bypass; FALSE- cancel pll bypass.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *                      E_OK for success and others for failure.
 *
 * Description        : This function set/cancle AP domain PLL force bypass.
 *                      Pll force bypass, pll output force to fs24M refclock
 *                      set and cancle need use in pairs.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_ApPllBybass(boolean bypassEn)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    uint32 timesOut = PLL_WAIT_TIME;
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_AP_PLL_BYPASS);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 enable ap domain pll bypass and disable pll*/
        if (TRUE == bypassEn)
        {
            Mcu_Ip_PllForceBypass(APB_PLL4_BASE, TRUE);
            Mcu_Ip_PllForceBypass(APB_PLL5_BASE, TRUE);
            Mcu_Ip_PllForceBypass(APB_PLL_LVDS_BASE, TRUE);

            errStatus = Mcu_Ip_ClkDisable(CLK_NODE(g_pll4_root));
            errStatus |= Mcu_Ip_ClkDisable(CLK_NODE(g_pll5_root));
            errStatus |= Mcu_Ip_ClkDisable(CLK_NODE(g_pll_lvds_root));
        }
        /* #30 enable pll and wait pll locked, cancle ap domain pll bypass*/
        else
        {
            errStatus = Mcu_EnablePll(CLK_NODE(g_pll4_root), timesOut);
            errStatus |= Mcu_EnablePll(CLK_NODE(g_pll5_root), timesOut);
            errStatus |= Mcu_EnablePll(CLK_NODE(g_pll_lvds_root), timesOut);

            Mcu_Ip_PllForceBypass(APB_PLL4_BASE, FALSE);
            Mcu_Ip_PllForceBypass(APB_PLL5_BASE, FALSE);
            Mcu_Ip_PllForceBypass(APB_PLL_LVDS_BASE, FALSE);
        }
    }
    /* ----- Development Error Report --------------------------------------- */
    /* #90 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_AP_PLL_BYPASS,
                              (uint8)errStatus);
#endif /** if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE,
                                   (uint8)MCU_SID_AP_PLL_BYPASS, (uint8)errStatus);
#endif /** if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #100 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */
    return errStatus;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
