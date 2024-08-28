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
#include "Mcu_AnalogTrim.h"
#include "RegHelper.h"
#include "RegBase.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu.h"
#include "Mcu_Fault.h"
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
#define EFUSE_IP_ANALOG_TRIM_CP_REG (0x1050U)
#define EFUSE_IP_ANALOG_TRIM_CP_EN_OFFSET (19U)
#define EFUSE_IP_ANALOG_TRIM_FT_REG (0x1048U)
#define EFUSE_IP_ANALOG_TRIM_FT_EN_OFFSET (6U)
#define EFUSE_IP_ANALOG_TRIM_BGR33_REG (0x1044U)
#define EFUSE_IP_ANALOG_TRIM_BGR33_SF_VREF_MASK (3U)
#define EFUSE_IP_ANALOG_TRIM_BGR33_AP_VREF_MASK (16U)
#define EFUSE_IP_ANALOG_TRIM_BGR33_AP_IREF_MASK (19U)
#define EFUSE_IP_ANALOG_VD_TRIM1_REG (0x104CU)
#define EFUSE_IP_ANALOG_VD_TRIM2_REG (0x12C4U)
#define EFUSE_IP_ANALOG_VD_TRIM3_REG (0x12C8U)

#define SCR_IP_ANALOG_TRIM_BGR33_AP_VREF_IREF_REG (0x1000U)
#define SCR_IP_ANALOG_TRIM_SF_VREF_OFFSET (3U)
#define SCR_IP_ANALOG_TRIM_SF_VREF_MASK (3U)
#define SCR_IP_ANALOG_TRIM_SF_IREF_OFFSET (6U)
#define SCR_IP_ANALOG_TRIM_SF_IREF_MASK (5U)
#define SCR_IP_ANALOG_TRIM_SF_VREF_IREF_EN_OFFSET (11U)
/* PRQA S 0791 1*/
#define SCR_IP_ANALOG_TRIM_SF_VREF_IREF_EN_MASK (1U)
#define SCR_IP_ANALOG_TRIM_AP_VREF_OFFSET (3U)
#define SCR_IP_ANALOG_TRIM_AP_VREF_MASK (3U)
#define SCR_IP_ANALOG_TRIM_AP_IREF_OFFSET (6U)
#define SCR_IP_ANALOG_TRIM_AP_IREF_MASK (5U)
#define SCR_IP_ANALOG_TRIM_AP_VREF_IREF_EN_OFFSET (11U)
/* PRQA S 0791 1*/
#define SCR_IP_ANALOG_TRIM_AP_VREF_IREF_EN_MASK (1U)

#ifndef SEMIDRIVE_E3_LITE_SERIES
#define SCR_IP_ANALOG_TRIM_BGR33_SF_VREF_IREF_REG (0x1044U)
#else /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
#define EFUSE_IP_ANALOG_TRIM_BGR33_SF_IREF_MASK (19U)
#define SCR_IP_ANALOG_TRIM_BGR33_SF_VREF_IREF_REG (0x1030U)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** **************************************************************************************
 * \brief This function is used for analog trim for bgr33.

 * \verbatim
 * Syntax             : void Mcu_Ip_AnalogTrimBgr33(void)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Uninitialized analog trim bgr33 may lead to vd precision reduction.
 *

 * \endverbatim
 *****************************************************************************************/
void Mcu_Ip_AnalogTrimBgr33(void)
{
    uint32 trimVal;
    uint8 cpTrimSta;
    uint8 ftTrimSta;
    /*bgr33 sf vref trim fuse value*/
    uint32 bgr33SfVrefTrimFuseValue;
    /*bgr33 sf iref trim fuse value*/
    uint32 bgr33SfIrefTrimFuseValue;
#ifndef SEMIDRIVE_E3_LITE_SERIES
    /*bgr33 ap vref trim fuse value*/
    uint32 bgr33ApVrefTrimFuseValue;
    /*bgr33 ap iref trim fuse value*/
    uint32 bgr33ApIrefTrimFuseValue;
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

    /* #10 judge CP Trim and FT Trim did flag*/
    cpTrimSta = (uint8)((REG_READ32(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_TRIM_CP_REG) >>
                         EFUSE_IP_ANALOG_TRIM_CP_EN_OFFSET) & 0x1U);
    ftTrimSta = (uint8)((REG_READ32(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_TRIM_FT_REG) >>
                         EFUSE_IP_ANALOG_TRIM_FT_EN_OFFSET) & 0x1U);

    if ((1U == cpTrimSta) && (1U == ftTrimSta))
    {
        trimVal = REG_READ32(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_TRIM_BGR33_REG);

        /* #20 bgr33 sf vref trim init*/
        bgr33SfVrefTrimFuseValue = (trimVal >> EFUSE_IP_ANALOG_TRIM_BGR33_SF_VREF_MASK) & 0x7U;
        /*write bgr33 sf vref trim fuse value to scr reg*/
        REG_RMW32(APB_SCR_SF_BASE + SCR_IP_ANALOG_TRIM_BGR33_SF_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_SF_VREF_OFFSET, SCR_IP_ANALOG_TRIM_SF_VREF_MASK, bgr33SfVrefTrimFuseValue);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* #30 bgr33 sf iref trim init*/
        bgr33SfIrefTrimFuseValue = 0x15U;
        /*write bgr33 sf iref trim fuse value to scr reg*/
        REG_RMW32(APB_SCR_SF_BASE + SCR_IP_ANALOG_TRIM_BGR33_SF_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_SF_IREF_OFFSET, SCR_IP_ANALOG_TRIM_SF_IREF_MASK, bgr33SfIrefTrimFuseValue);
        /* #40 enable bgr33 sf trim*/
        REG_RMW32(APB_SCR_SF_BASE + SCR_IP_ANALOG_TRIM_BGR33_SF_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_SF_VREF_IREF_EN_OFFSET, SCR_IP_ANALOG_TRIM_SF_VREF_IREF_EN_MASK, 1U);

        /* #50 bgr33 ap vref trim init*/
        bgr33ApVrefTrimFuseValue = (trimVal >> EFUSE_IP_ANALOG_TRIM_BGR33_AP_VREF_MASK) & 0x7U;
        /*write bgr33 ap vref trim fuse value to scr reg*/
        REG_RMW32(APB_SCR_AP_BASE + SCR_IP_ANALOG_TRIM_BGR33_AP_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_AP_VREF_OFFSET, SCR_IP_ANALOG_TRIM_AP_VREF_MASK, bgr33ApVrefTrimFuseValue);

        /* #60 bgr33 ap iref trim init*/
        bgr33ApIrefTrimFuseValue = (trimVal >> EFUSE_IP_ANALOG_TRIM_BGR33_AP_IREF_MASK) & 0x1FU;
        /*write bgr33 ap iref trim fuse value to scr reg*/
        REG_RMW32(APB_SCR_AP_BASE + SCR_IP_ANALOG_TRIM_BGR33_AP_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_AP_IREF_OFFSET, SCR_IP_ANALOG_TRIM_AP_IREF_MASK, bgr33ApIrefTrimFuseValue);
        /* #70 enable bgr33 ap trim*/
        REG_RMW32(APB_SCR_AP_BASE + SCR_IP_ANALOG_TRIM_BGR33_AP_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_AP_VREF_IREF_EN_OFFSET, SCR_IP_ANALOG_TRIM_AP_VREF_IREF_EN_MASK, 1U);
#else /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
        /* #30 bgr33 sf iref trim init*/
        bgr33SfIrefTrimFuseValue = (trimVal >> EFUSE_IP_ANALOG_TRIM_BGR33_SF_IREF_MASK) & 0x1FU;
        /*write bgr33 sf iref trim fuse value to scr reg*/
        REG_RMW32(APB_SCR_SF_BASE + SCR_IP_ANALOG_TRIM_BGR33_SF_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_SF_IREF_OFFSET, SCR_IP_ANALOG_TRIM_SF_IREF_MASK, bgr33SfIrefTrimFuseValue);
        /* #40 enable bgr33 sf trim*/
        REG_RMW32(APB_SCR_SF_BASE + SCR_IP_ANALOG_TRIM_BGR33_SF_VREF_IREF_REG,
                  SCR_IP_ANALOG_TRIM_SF_VREF_IREF_EN_OFFSET, SCR_IP_ANALOG_TRIM_SF_VREF_IREF_EN_MASK, 1U);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    }

    /*when chip hasn't been analog trimmed, do nothing to increase robustness*/
}

/** **************************************************************************************
 * \brief This function is used to convert trim value to offset.

 * \verbatim
 * Syntax             : static sint8 Mcu_Ip_AnalogTrimValToVdOffSet(uint8 inVal)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : inVal - trim value to be converted

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : sint8 - converted value

 * Description        : Converts trim value to an offset
 *

 * \endverbatim
 *****************************************************************************************/
static sint8 Mcu_Ip_AnalogTrimValToVdOffSet(uint8 inVal)
{
    sint8 retVal = 0;

    if (inVal <= 3U)
    {
        retVal = (sint8)inVal;
    }

    switch (inVal)
    {
    case 4:
        retVal = 0;
        break;

    case 5:
        retVal = -3;
        break;

    case 6:
        retVal = -2;
        break;

    case 7:
        retVal = -1;
        break;

    default:
        /*do nothing*/
        break;
    }

    return retVal;
}

/** **************************************************************************************
 * \brief This function is used to convert offset to trim value.

 * \verbatim
 * Syntax             : uint8 Mcu_Ip_AnalogTrimVdOffSetToVal(sint16 inVal)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : inVal - trim value to be converted

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : uint8 - converted value

 * Description        : Converts an offset to trim value
 *

 * \endverbatim
 *****************************************************************************************/
uint8 Mcu_Ip_AnalogTrimVdOffSetToVal(sint16 inVal)
{
    uint8 retVal;

    if (inVal >= 0)
    {
        if (inVal > 3)
        {
            retVal = 3U;
        }
        else
        {
            retVal = (uint8)inVal;
        }
    }

    if (inVal < -3)
    {
        retVal = 5U;
    }

    switch (inVal)
    {
    case -3:
        retVal = 5U;
        break;

    case -2:
        retVal = 6U;
        break;

    case -1:
        retVal = 7U;
        break;

    default:
        /*do nothing*/
        break;
    }

    return retVal;
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** **************************************************************************************
 * \brief This function is used to read vd fuse value.

 * \verbatim
 * Syntax             : Std_ReturnType Mcu_AnalogTrimVd(VdTrimType TrimType,
 * Mcu_AnalogTrimVdSfVinType *vdSfTrim, Mcu_AnalogTrimVdApVinType *vdApTrim)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : TrimType - sw or ate trim
 *                      vdSfTrim - vd sf trim value pointer
 *                      vdApTrim - vd ap trim value pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK - Read vd fuse complete
 *                      E_NOT_OK - Read vd fuse did not complete

 * Description        : Read the vd fuse value

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Mcu_AnalogTrimVd(Mcu_AnalogTrimVdType TrimType, Mcu_AnalogTrimVdSfVinType *vdSfTrim,
                                Mcu_AnalogTrimVdApVinType *vdApTrim)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint8 trimVal;
    uint8 vdEnSta;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_ANALOG_TRIM);

    if (E_OK == errStatus)
    {

        if ((NULL_PTR == vdSfTrim) || (NULL_PTR == vdApTrim))
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {

            /* #20 Gets the bits of whether analog trim is complete */
            if (TrimType == MCU_ATEVDTRIM)
            {
                vdEnSta = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 27) & 0x1U);
            }
            else
            {
                vdEnSta = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM2_REG) >> 16) & 0x1U);
            }

            McuHookBegin_Mcu_AnalogTrimVd();

            if (1U == vdEnSta)
            {

                /* #30 Sf trim*/
                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 0) & 0x7U);
                vdSfTrim->analogTrimVdSfVin0Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 3) & 0x7U);
                vdSfTrim->analogTrimVdSfVin1Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 6) & 0x7U);
                vdSfTrim->analogTrimVdSfVin2Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 9) & 0x7U);
                vdSfTrim->analogTrimVdSfVin3Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 12) & 0x7U);
                vdSfTrim->analogTrimVdSfVin0Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 15) & 0x7U);
                vdSfTrim->analogTrimVdSfVin1Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 18) & 0x7U);
                vdSfTrim->analogTrimVdSfVin2Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 21) & 0x7U);
                vdSfTrim->analogTrimVdSfVin3Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                /* #40 Ap trim*/
                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM2_REG) >> 20) & 0x7U);
                vdApTrim->analogTrimVdApVin1Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM2_REG) >> 23) & 0x7U);
                vdApTrim->analogTrimVdApVin2Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM2_REG) >> 26) & 0x7U);
                vdApTrim->analogTrimVdApVin3Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM2_REG) >> 29) & 0x7U);
                vdApTrim->analogTrimVdApVin1Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM3_REG) >> 0) & 0x7U);
                vdApTrim->analogTrimVdApVin2Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM3_REG) >> 3) & 0x7U);
                vdApTrim->analogTrimVdApVin3Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);
            }
            else
            {
                errStatus = MCU_E_ANALOG_TRIM_FAIL;
            }

            McuHookEnd_Mcu_AnalogTrimVd();
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #50 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_ANALOG_TRIM,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_ANALOG_TRIM,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #60 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return errStatus;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

/** **************************************************************************************
 * \brief This function is used to read vd fuse value.

 * \verbatim
 * Syntax             : Std_ReturnType Mcu_AteAnalogTrimVd(Mcu_AnalogTrimVdSfVinType *vdSfTrim)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdSfTrim - vd sf trim value pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK - Read vd fuse complete
 *                      E_NOT_OK - Read vd fuse did not complete

 * Description        : Read the vd fuse value

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Mcu_AteAnalogTrimVd(Mcu_AnalogTrimVdSfVinType *vdSfTrim)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;
    uint8 trimVal;
    uint8 vdEnSta;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Mcu_EnterCheck(MCU_SID_ANALOG_TRIM);

    if (E_OK == errStatus)
    {

        if (NULL_PTR == vdSfTrim)
        {
            errStatus = MCU_E_PARAM_POINTER;
        }
        else
        {
            /* #20 Gets the bits of whether analog trim is complete */
            vdEnSta = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 27) & 0x1U);

            McuHookBegin_Mcu_AteAnalogTrimVd();

            if ( 1U == vdEnSta)
            {
                /* #30 Sf trim*/
                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 0) & 0x7U);
                vdSfTrim->analogTrimVdSfVin0Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 3) & 0x7U);
                vdSfTrim->analogTrimVdSfVin1Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 6) & 0x7U);
                vdSfTrim->analogTrimVdSfVin2Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 9) & 0x7U);
                vdSfTrim->analogTrimVdSfVin3Uv = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 12) & 0x7U);
                vdSfTrim->analogTrimVdSfVin0Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 15) & 0x7U);
                vdSfTrim->analogTrimVdSfVin1Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 18) & 0x7U);
                vdSfTrim->analogTrimVdSfVin2Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);

                trimVal = ((uint8)(readl(APB_EFUSEC_BASE + EFUSE_IP_ANALOG_VD_TRIM1_REG) >> 21) & 0x7U);
                vdSfTrim->analogTrimVdSfVin3Ov = Mcu_Ip_AnalogTrimValToVdOffSet(trimVal);
            }
            else
            {
                errStatus = MCU_E_ATE_ANALOG_TRIM_FAIL;
            }

            McuHookEnd_Mcu_AteAnalogTrimVd();
        }
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #50 Report errors if any occurred */
#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == MCU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_ANALOG_TRIM,
                              (uint8)errStatus);
#endif /** #if (STD_ON == MCU_DEV_ERROR_DETECT) */
#if (STD_ON == MCU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE, (uint8)MCU_SID_ANALOG_TRIM,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == MCU_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #60 Dummy assignment avoid compiler warning */
        MCU_DUMMY_STATEMENT(errStatus);
    }
#endif /**#if ((STD_ON == MCU_DEV_ERROR_DETECT) || (STD_ON == MCU_SAFETY_ENABLE)) */

    return errStatus;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
