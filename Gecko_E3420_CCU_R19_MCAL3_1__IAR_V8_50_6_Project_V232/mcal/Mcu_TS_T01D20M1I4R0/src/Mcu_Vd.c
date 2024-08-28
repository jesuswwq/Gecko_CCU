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
 * \file     Mcu_AnalogTrim.c                                                                           *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0U.0U                                                                   *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegBase.h"
#include "RegHelper.h"
#include "Mcu_Vd.h"
#include "debug.h"
#include "Mcu_Delay.h"
#include "Mcu_AnalogTrim.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu.h"
#if (STD_ON == MCU_DEV_ERROR_DETECT)
/** Traceability       : SWSR_MCU_045*/
#include "Det.h"
#endif /**#if (STD_ON == MCU_DEV_ERROR_DETECT)*/
#if (STD_ON == MCU_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif /**#if (STD_ON == MCU_SAFETY_ENABLE)*/

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/

/*PRQA S 3673 1*/
static Std_ReturnType Mcu_Ip_VdClrIntState(Mcu_VdCfgType *vdCfgPtr)
{
    Std_ReturnType errStatus = MCU_E_VD_CLR_STA_FAIL;
    uint32 funcStat;

    if (NULL_PTR != vdCfgPtr)
    {
        /* #10 read FUNC_VDC_STAT*/
        funcStat = readl(vdCfgPtr->base + FUNC_VDC_STAT);
        /* #20 setting FUNC_STAT_EN and FUNC_INT_SIG_EN to '0x0'*/
        REG_RMW32(vdCfgPtr->base + FUNC_VDC_STAT_EN, 0U, 16U, 0U);
        REG_RMW32(vdCfgPtr->base + FUNC_VDC_INT_SIG_EN, 0U, 16U, 0U);

        /* #30 wait for a delay:[(CFG_MSK_CNT+1)+(CFG_FILT*(rise or fall max value)+1)]*clock period*/
        errStatus = Mcu_udelay(6);

        if (E_OK == errStatus)
        {
            /* #40 setting FUNC_STAT_CLR to 1*/
            REG_RMW32(vdCfgPtr->base + FUNC_STAT_CLR, 0U, 16U, funcStat & 0xFFFFU);
            /* #50 setting FUNC_STAT_EN and FUNC_INT_SIG_EN to '0x1'*/
            REG_RMW32(vdCfgPtr->base + FUNC_VDC_STAT_EN, 0U, 16U, vdCfgPtr->intStaEn);
            REG_RMW32(vdCfgPtr->base + FUNC_VDC_INT_SIG_EN, 0U, 16U, vdCfgPtr->intStaEn);
        }
    }

    return errStatus;
}

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/*PRQA S 3673 29*/
/** **************************************************************************************
 * \brief This function is used to get vd interrupt status.

 * \verbatim
 * Syntax             : uint32 Mcu_VdGetIntSta(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : uint32 - vd interrupt status

 * Description        : Get vd interrupt status
 *

 * \endverbatim
 *
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
uint32 Mcu_VdGetIntSta(Mcu_VdCfgType *vdCfgPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint32 retVal = 0;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_VD_STA);

    if (E_OK == errStatus)
    {

        if (NULL_PTR == vdCfgPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            /* #20 Reads the status of the VD int register*/
            retVal = readl(vdCfgPtr->base + FUNC_VDC_STAT);
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_STA,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_STA,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return retVal;
}

/*PRQA S 3673 28*/
/** **************************************************************************************
 * \brief This function is used to get vd dynamic status.

 * \verbatim
 * Syntax             : uint32 Mcu_VdGetDySta(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : uint32 - vd dynamic status

 * Description        : Get vd dynamic status
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
uint32 Mcu_VdGetDySta(Mcu_VdCfgType *vdCfgPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint32 retVal = 0;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_VD_STA);

    if (E_OK == errStatus)
    {

        if (NULL_PTR == vdCfgPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            /* #20 Reads the status of the VD dynamic register*/
            retVal = readl(vdCfgPtr->base + FUNC_DY_STAT);
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_STA,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_STA,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return retVal;
}

/*PRQA S 3673 28*/
/** **************************************************************************************
 * \brief This function is used to clear vd interrupt status.

 * \verbatim
 * Syntax             : void Mcu_VdClrIntSta(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Clear vd interrupt status
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
void Mcu_VdClrIntSta(Mcu_VdCfgType *vdCfgPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_VD_STA);

    if (E_OK == errStatus)
    {
        if (NULL_PTR == vdCfgPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            /*#20 Vd clear int States*/
            errStatus = Mcu_Ip_VdClrIntState(vdCfgPtr);
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_STA,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_STA,
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

/** **************************************************************************************
 * \brief This function is used to initialize voltage detector.

 * \verbatim
 * Syntax             : Std_ReturnType Mcu_VdInit(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK - Initialize voltage detector successfully
 *                      E_NOT_OK - Initialize voltage detector unsuccessfully

 * Description        : Initialize voltage detector
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Mcu_VdInit(Mcu_VdCfgType *vdCfgPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint32 funcStat;
    uint32 vinsetVal;
    uint32 ovThreVal;
    uint32 uvThreVal;
    uint32 cfgFiltVal;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_INIT_VD);

    if (E_OK == errStatus)
    {

        if (NULL_PTR == vdCfgPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {

            /* #20 read FUNC_VDC_STAT*/
            funcStat = readl(vdCfgPtr->base + FUNC_VDC_STAT);
            /*setting FUNC_STAT_EN and FUNC_INT_SIG_EN to '0x0'*/
            REG_RMW32(vdCfgPtr->base + FUNC_VDC_STAT_EN, 0U, 16U, 0U);
            REG_RMW32(vdCfgPtr->base + FUNC_VDC_INT_SIG_EN, 0U, 16U, 0U);
            /*power on volt-det hard macro*/

            /* #30 set VOLT_SEL */
            vinsetVal = (uint32)(vdCfgPtr->voltSel->vin0Sel) | ((uint32)(vdCfgPtr->voltSel->vin1Sel) << 8) |
                        ((uint32)(vdCfgPtr->voltSel->vin2Sel) << 16) | ((uint32)(vdCfgPtr->voltSel->vin3Sel) << 24);
            writel(vinsetVal, vdCfgPtr->base + VOLT_SEL);

            /* #40 set OV_THRE */
            ovThreVal = ((uint32)vdCfgPtr->ovThre->vin0OvThre & 0xFU) | (((uint32)
                        vdCfgPtr->ovThre->vin1OvThre & 0xFU) << 4) | (((uint32)vdCfgPtr->ovThre->vin2OvThre & 0xFU) <<
                                8) | (((uint32)vdCfgPtr->ovThre->vin3OvThre & 0xFU) << 12);
            writel(ovThreVal, vdCfgPtr->base + CFG_OV_THRE);

            /* #50 set UV_THRE */
            uvThreVal = ((uint32)vdCfgPtr->uvThre->vin0UvThre & 0xFU) | (((uint32)
                        vdCfgPtr->uvThre->vin1UvThre & 0xFU) << 4) | (((uint32)vdCfgPtr->uvThre->vin2UvThre & 0xFU) <<
                                8) | (((uint32)vdCfgPtr->uvThre->vin3UvThre & 0xFU) << 12);
            writel(uvThreVal, vdCfgPtr->base + CFG_UV_THRE);

            /* #60 set filter*/
            cfgFiltVal = ((uint32)vdCfgPtr->filtCfg->cfgFfb & 0xFU) | (((uint32)vdCfgPtr->filtCfg->cfgRfb &
                         0xFU) << 4) | (((uint32)vdCfgPtr->filtCfg->cfgSi) << 8);
            REG_RMW32(vdCfgPtr->base + CFG_FILT, 0U, 16U, cfgFiltVal & 0xFFFFU);

            /* #70 According to the TRM manual, wait 2 us*/
            errStatus = Mcu_udelay(2);

            if (E_OK == errStatus)
            {
                /* #80 setting FUNC_STAT_CLR to 1*/
                REG_RMW32(vdCfgPtr->base + FUNC_STAT_CLR, 0U, 16U, funcStat & 0xFFFFU);
                /* #90 setting FUNC_COR_SIG_EN FUNC_UNC_SIG_EN to 0x0*/
                REG_RMW32(vdCfgPtr->base + FUNC_VDC_COR_SIG_EN, 0U, 16U, 0x0);
                REG_RMW32(vdCfgPtr->base + FUNC_UNC_SIG_EN, 0U, 16U, 0x0);
                /* #100 setting FUNC_STAT_EN and FUNC_INT_SIG_EN */
                REG_RMW32(vdCfgPtr->base + FUNC_VDC_STAT_EN, 0U, 16U, vdCfgPtr->intStaEn);
                REG_RMW32(vdCfgPtr->base + FUNC_VDC_INT_SIG_EN, 0U, 16U, vdCfgPtr->intStaEn);
                /* #110 clear status register again*/
                errStatus = Mcu_Ip_VdClrIntState(vdCfgPtr);
                /* #120 setting FUNC_COR_SIG_EN FUNC_UNC_SIG_EN to 0xFFFF*/
                REG_RMW32(vdCfgPtr->base + FUNC_VDC_COR_SIG_EN, 0U, 16U, 0xFFFFU);
                REG_RMW32(vdCfgPtr->base + FUNC_UNC_SIG_EN, 0U, 16U, 0xFFFFU);
            }
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #120 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_VD,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_INIT_VD,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #130 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return errStatus;
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
/*PRQA S 3673 32*/
/** **************************************************************************************
 * \brief This function is used to software calibrates the VD module.

 * \verbatim
 * Syntax             : uint8 Mcu_VdSwTrim(Mcu_VdCfgType *vdCfgPtr,
 *                      Mcu_VdSwtrimType *VdSwTrim, uint8 VdIdealVinSet)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer
 *                      VdSwTrim - vd software trim pointer
 *                      vdIdealVinSet - vd expect vin set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : 0x0-0x7 - return vd efuse value
 *                      0xFF - vd software calibrates unsuccessfully

 * Description        : Initialize voltage detector
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM005 SW_SM006
 *****************************************************************************************/
uint8 Mcu_VdSwTrim(Mcu_VdCfgType *vdCfgPtr, Mcu_VdSwtrimType *vdSwTrim, uint8 vdIdealVinSet)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint32 DySta;
    uint8 Rlt = 1;
    uint32 calibreFlag;
    uint16 loopTimeout = 0;
    sint16 fuseValue = 0;
    uint8 valToFuse = 0xFFU;
    uint32 vinsetVal;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_VD_TRIM);

    if (E_OK == errStatus)
    {
        if ((NULL_PTR == vdCfgPtr) || (NULL_PTR == vdSwTrim))
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {

            while (( 1U == Rlt) && (loopTimeout < 255U))
            {
                loopTimeout ++;
                /* #20 According to the TRM manual, wait for at least 1us, then check status*/
                errStatus = Mcu_udelay(4);

                if (E_OK == errStatus)
                {
                    DySta = readl(vdCfgPtr->base + FUNC_DY_STAT);

                    calibreFlag = DySta & (vdSwTrim->calibreBit);

                    if ( 0U != calibreFlag)
                    {

                        Rlt = 0;

                        /* #30 The vinset of the warning point minus the ideal vinset*/
                        switch (vdSwTrim->vinSel)
                        {
                        case 0:
                            fuseValue = ((sint16)(vdCfgPtr->voltSel->vin0Sel) - (sint16)vdIdealVinSet);
                            break;

                        case 1:
                            fuseValue = ((sint16)(vdCfgPtr->voltSel->vin1Sel) - (sint16)vdIdealVinSet);
                            break;

                        case 2:
                            fuseValue = ((sint16)(vdCfgPtr->voltSel->vin2Sel) - (sint16)vdIdealVinSet);
                            break;

                        case 3:
                            fuseValue = ((sint16)(vdCfgPtr->voltSel->vin3Sel) - (sint16)vdIdealVinSet);
                            break;

                        default:
                            /*do nothing*/
                            break;
                        }

                        /* #40 get fuse value*/
                        valToFuse = Mcu_Ip_AnalogTrimVdOffSetToVal(fuseValue);
                    }
                    else
                    {
                        /* #50 let vinset approach the warning point*/
                        /*PRQA S 4434,1860 18*/
                        switch (vdSwTrim->vinSel)
                        {
                        case 0:
                            vdCfgPtr->voltSel->vin0Sel = vdCfgPtr->voltSel->vin0Sel + vdSwTrim->step;
                            break;

                        case 1:
                            vdCfgPtr->voltSel->vin1Sel = vdCfgPtr->voltSel->vin1Sel + vdSwTrim->step;
                            break;

                        case 2:
                            vdCfgPtr->voltSel->vin2Sel = vdCfgPtr->voltSel->vin2Sel + vdSwTrim->step;
                            break;

                        case 3:
                            vdCfgPtr->voltSel->vin3Sel = vdCfgPtr->voltSel->vin3Sel + vdSwTrim->step;
                            break;

                        default:
                            /*do nothing*/
                            break;
                        }

                        /* #60 Set the VD Volt Sel register*/
                        vinsetVal = (uint32)(vdCfgPtr->voltSel->vin0Sel) | (((uint32)vdCfgPtr->voltSel->vin1Sel) << 8) |
                                    (((uint32)vdCfgPtr->voltSel->vin2Sel) << 16) | (((uint32)vdCfgPtr->voltSel->vin3Sel) << 24);
                        writel(vinsetVal, vdCfgPtr->base + VOLT_SEL);
                    }
                }
            }
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #70 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_TRIM,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_TRIM,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #80 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return valToFuse;
}
#endif/*end of MACRO SEMIDRIVE_E3_LITE_SERIES*/

/*PRQA S 3673 28*/
/** **************************************************************************************
 * \brief This function is used to set vd VOLT_SEL.

 * \verbatim
 * Syntax             : void Mcu_VdVoltSelSet(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Set vd VOLT_SEL
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
void Mcu_VdVoltSelSet(Mcu_VdCfgType *vdCfgPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint32 vinsetVal;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_VD_VOLT_SEL);

    if (E_OK == errStatus)
    {

        if (NULL_PTR == vdCfgPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            /* #20 Set the VD Volt Sel register*/
            vinsetVal = (uint32)(vdCfgPtr->voltSel->vin0Sel) | (((uint32)vdCfgPtr->voltSel->vin1Sel) << 8) |
                        (((uint32)vdCfgPtr->voltSel->vin2Sel) << 16) | (((uint32)vdCfgPtr->voltSel->vin3Sel) << 24);
            writel(vinsetVal, vdCfgPtr->base + VOLT_SEL);
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_VOLT_SEL,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_VOLT_SEL,
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

/*PRQA S 3673 28*/
/** **************************************************************************************
 * \brief This function is used to get vd VOLT_SEL.

 * \verbatim
 * Syntax             : void Mcu_VdVoltSelGet(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Get vd VOLT_SEL
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
uint32 Mcu_VdVoltSelGet(Mcu_VdCfgType *vdCfgPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint32 retVal = 0;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_VD_VOLT_SEL);

    if (E_OK == errStatus)
    {

        if (NULL_PTR == vdCfgPtr)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            /* #20 Reads the status of the VD dynamic register*/
            retVal = readl(vdCfgPtr->base + VOLT_SEL);
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_VOLT_SEL,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_VD_VOLT_SEL,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return retVal;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
