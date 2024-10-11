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
 * \file     Mcu_Clk.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/01     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_GeneralTypes.h"
#include "Mcu_Clk.h"
#include "Mcu_Ckgen.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ClkPrepare(Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    Mcu_ClkCoreType const *corePtr;

    if (NULL_PTR != clkPtr)
    {
        corePtr = clkPtr->core;

        if ((NULL_PTR != corePtr) && (NULL_PTR != corePtr->ops)  && (NULL_PTR != corePtr->ops->prepare) )
        {
            errStatus = corePtr->ops->prepare(clkPtr);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ClkSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    Mcu_ClkCoreType const *corePtr;
    uint32 divNum = 0U;
    uint8 selectParent;

    if (NULL_PTR != clkPtr)
    {
        corePtr = clkPtr->core;

        if ((NULL_PTR != corePtr) && (NULL_PTR != corePtr->ops)
                && (NULL_PTR != corePtr->ops->setRate))
        {
            errStatus = E_OK;

            if ((clkPtr->parentsNum > 1U) && (NULL_PTR != corePtr->ops->selectParent))
            {
                selectParent = corePtr->ops->selectParent(clkPtr, rate, &divNum);

                if (MCU_CLK_PARENT_NUM == selectParent)
                {
                    errStatus = MCU_E_OUTRANGE;
                }
            }

            if (E_OK == errStatus)
            {
                errStatus = corePtr->ops->setRate(clkPtr, rate);

                if (E_OK == errStatus)
                {
                    clkPtr->rate = rate;
                } /* else not needed */
            }

        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
Mcu_ClkRateType Mcu_Ip_ClkGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkCoreType const *corePtr;
    Mcu_ClkRateType rate = UINT32_MAX;

    if (NULL_PTR != clkPtr)
    {
        corePtr = clkPtr->core;

        if ((NULL_PTR != corePtr) && (NULL_PTR != corePtr->ops)  && (NULL_PTR != corePtr->ops->getRate))
        {
            if (clkPtr->mux < MCU_CLK_PARENT_NUM)
            {
                if (NULL_PTR == clkPtr->parent)
                {
                    clkPtr->parent = clkPtr->parents[clkPtr->mux];
                }

                rate = corePtr->ops->getRate(clkPtr);
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */

    return rate;
}

/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ClkDisable(const Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    Mcu_ClkCoreType const *corePtr;

    if (NULL_PTR != clkPtr)
    {
        corePtr = clkPtr->core;

        if ((NULL_PTR != corePtr) && (NULL_PTR != corePtr->ops)  && (NULL_PTR != corePtr->ops->disable))
        {
            errStatus = corePtr->ops->disable(clkPtr);

            if (NULL_PTR != corePtr->ops->lowpowerCgset)
            {
                errStatus = errStatus | corePtr->ops->lowpowerCgset(clkPtr, CKGEN_HIB_MODE, FALSE);
                errStatus = errStatus | corePtr->ops->lowpowerCgset(clkPtr, CKGEN_SLP_MODE, FALSE);
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ClkEnable(const Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    Mcu_ClkCoreType const *corePtr;

    if (NULL_PTR != clkPtr)
    {
        corePtr = clkPtr->core;

        if ((NULL_PTR != corePtr) && (NULL_PTR != corePtr->ops)  && (NULL_PTR != corePtr->ops->enable))
        {
            errStatus = corePtr->ops->enable(clkPtr);

            if (NULL_PTR != corePtr->ops->lowpowerCgset)
            {
                errStatus = errStatus | corePtr->ops->lowpowerCgset(clkPtr, CKGEN_HIB_MODE, TRUE);
                errStatus = errStatus | corePtr->ops->lowpowerCgset(clkPtr, CKGEN_SLP_MODE, TRUE);
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
uint8 Mcu_Ip_ClkIsGated(const Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkCoreType const *corePtr;
    uint8 isGated = 0xFFu;

    if (NULL_PTR != clkPtr)
    {
        corePtr = clkPtr->core;

        if ((NULL_PTR != corePtr) && (NULL_PTR != corePtr->ops)  && (NULL_PTR != corePtr->ops->isGated))
        {
            isGated = corePtr->ops->isGated(clkPtr);
        } /* else not needed */
    } /* else not needed */

    return isGated;
}

/** Traceability       : SW_MCU_SM011*/
uint8 Mcu_Ip_ClkIsLocked(const Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkCoreType const *corePtr;
    uint8 isLocked = 0xFFu;

    if (NULL_PTR != clkPtr)
    {
        corePtr = clkPtr->core;

        if ((NULL_PTR != corePtr) && (NULL_PTR != corePtr->ops)  && (NULL_PTR != corePtr->ops->isLocked))
        {
            isLocked = corePtr->ops->isLocked(clkPtr);
        } /* else not needed */
    } /* else not needed */

    return isLocked;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
