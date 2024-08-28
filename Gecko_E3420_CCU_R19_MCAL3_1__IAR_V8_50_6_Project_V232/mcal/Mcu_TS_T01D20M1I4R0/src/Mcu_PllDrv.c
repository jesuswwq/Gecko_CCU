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
 * \file     Mcu_PllDrv.c                                                                            *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Platform_Types.h"
#include "Mcu_PllDrv.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_PllDrvEnable(const Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core))
    {
        errStatus = Mcu_Ip_PllEnable(clkPtr->core->base, clkPtr->id);
    } /* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_PllDrvDisable(const Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core))
    {
        errStatus = Mcu_Ip_PllDisable(clkPtr->core->base, clkPtr->id);
    } /* else not needed */

    return errStatus;
}

/*PRQA S 3673 2*/
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_PllDrvPrepare(Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core) && (NULL_PTR != clkPtr->parent))
    {
        errStatus = Mcu_Ip_PllPrepare(clkPtr->core->base, clkPtr->id,
                                      clkPtr->parent->rate, clkPtr->rate, clkPtr->dsm_en);
    } /* else not needed */

    return errStatus;
}

/*PRQA S 3673 2*/
/** Traceability       : SW_SM006*/
static Mcu_ClkRateType Mcu_Ip_PllDrvGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_PllRateType rate = UINT32_MAX;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core) && (NULL_PTR != clkPtr->parent))
    {
        rate = Mcu_Ip_PllGetRate(clkPtr->core->base, clkPtr->id, clkPtr->parent->rate);
    } /* else not needed */

    return rate;
}

/*PRQA S 3673 2*/
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_PllDrvSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core) && (NULL_PTR != clkPtr->parent))
    {
        errStatus = Mcu_Ip_PllSetRate(clkPtr->core->base, clkPtr->id,
                                      clkPtr->parent->rate, rate);
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
static uint8 Mcu_Ip_PllDrvIsLocked(const Mcu_ClkNodeType *clkPtr)
{
    uint8 pllLocked = 0xFFu;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core))
    {
        pllLocked = Mcu_Ip_PllIsLocked(clkPtr->core->base);
    } /* else not needed */

    return pllLocked;
}

/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_PllDrvConfigSpread(const Mcu_PllSpreadConfigType *pllConfigPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    const Mcu_ClkNodeType *nodePtr;

    if (NULL_PTR != pllConfigPtr)
    {
        nodePtr = pllConfigPtr->pllNode;

        if (NULL_PTR != nodePtr)
        {
            Mcu_Ip_PllSetSscAmplitude(nodePtr->core->base, pllConfigPtr->amplitude);
            Mcu_Ip_PllSetSscFrequency(nodePtr->core->base, pllConfigPtr->frequency);
            errStatus = Mcu_Ip_PllSetSscMode(nodePtr->core->base, pllConfigPtr->mode);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** Traceability       : SW_SM006*/
/*PRQA S 1531 1*/
const struct Mcu_PreClkOpsType Mcu_PllOps =
{
    .prepare = Mcu_Ip_PllDrvPrepare,
    .enable = Mcu_Ip_PllDrvEnable,
    .disable = Mcu_Ip_PllDrvDisable,
    .getRate = Mcu_Ip_PllDrvGetRate,
    .setRate = Mcu_Ip_PllDrvSetRate,
    .isLocked = Mcu_Ip_PllDrvIsLocked,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/* End of file */
