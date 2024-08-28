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
 * \file     Mcu_Reset.c                                                                                *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_GeneralTypes.h"
#include "Mcu_Reset.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/**
 * \brief Assert a reset signal.
 * The reset singal will stay asserted until reset_deassert() is called.
 *
 * \param[in] rstSigPtr Reset signal.
 * \return 0 if OK, or a negative error code.
 */
/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ResetCtlAssert(const Mcu_ResetSigType *rstSigPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    const Mcu_ResetCtlType *ctlPtr;

    if (NULL_PTR != rstSigPtr)
    {
        ctlPtr = rstSigPtr->rstCtl;

        if ((NULL_PTR != ctlPtr) && (NULL_PTR != ctlPtr->ops) && (NULL_PTR != ctlPtr->ops->assertSig))
        {

            errStatus = ctlPtr->ops->assertSig(ctlPtr, rstSigPtr->id);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/**
 * \brief Deassert a reset signal.
 *
 * \param[in] rstSigPtr Reset signal.
 * \return 0 if OK, or a negative error code.
 */
/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ResetCtlDeassert(const Mcu_ResetSigType *rstSigPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    const Mcu_ResetCtlType *ctlPtr;

    if (NULL_PTR != rstSigPtr)
    {
        ctlPtr = rstSigPtr->rstCtl;

        if ((NULL_PTR != ctlPtr) && (NULL_PTR != ctlPtr->ops) && (NULL_PTR != ctlPtr->ops->deassert))
        {

            errStatus = ctlPtr->ops->deassert(ctlPtr, rstSigPtr->id);

        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/**
 * \brief Assert a reset signal, and deassert automatically.
 *
 * \param[in] rstSigPtr Reset signal.
 * \return 0 if OK, or a negative error code.
 */
/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ResetCtlReset(const Mcu_ResetSigType *rstSigPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    const Mcu_ResetCtlType *ctlPtr;

    if (NULL_PTR != rstSigPtr)
    {
        ctlPtr = rstSigPtr->rstCtl;

        if ((NULL_PTR != ctlPtr) && (NULL_PTR != ctlPtr->ops) && (NULL_PTR != ctlPtr->ops->reset))
        {


            errStatus = ctlPtr->ops->reset(ctlPtr, rstSigPtr->id);

        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/**
 * \brief Check reset signal status.
 *
 * \param[in] rstSigPtr Reset signal.
 * \return 0 if deasserted, positive if asserted,
 *         or a negative error code.
 */
/** Traceability       : SW_SM006*/
uint32 Mcu_Ip_ResetCtlStatus(const Mcu_ResetSigType *rstSigPtr)
{
    uint32 assertSatus = UINT32_MAX;
    const Mcu_ResetCtlType *ctlPtr;

    if (NULL_PTR != rstSigPtr)
    {
        ctlPtr = rstSigPtr->rstCtl;

        if ((NULL_PTR != ctlPtr) && (NULL_PTR != ctlPtr->ops) && (NULL_PTR != ctlPtr->ops->status))
        {
            assertSatus = ctlPtr->ops->status(ctlPtr, rstSigPtr->id);
        } /* else not needed */
    } /* else not needed */

    return assertSatus;
}

/**
 * \brief Initialize the reset controller.
 *
 * \param[in] rst_ctl Common reset controller.
 * \return 0 if OK, or a negative error code.
 */


/**
 * \brief Global reset.
 *
 * \param[in] rstGlbCtlPrt Global reset controller.
 */
/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_ResetCtlGlobalReset(const Mcu_ResetGlbCtlType *rstGlbCtlPrt)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    const Mcu_ResetCtlType *rstSfCtl;

    if (NULL_PTR != rstGlbCtlPrt)
    {
        rstSfCtl = rstGlbCtlPrt->rstSfCtl;

        if ((NULL_PTR != rstSfCtl) && (NULL_PTR != rstSfCtl->ops)
                && (NULL_PTR != rstSfCtl->ops->globalReset))
        {
            errStatus = rstSfCtl->ops->globalReset(rstSfCtl);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}



#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
