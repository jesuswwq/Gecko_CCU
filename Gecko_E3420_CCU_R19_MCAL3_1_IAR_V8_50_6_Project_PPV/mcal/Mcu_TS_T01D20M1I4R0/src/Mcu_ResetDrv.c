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
 * \file     Mcu_ResetDrv.c                                                                            *
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
#include "RegHelper.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_ResetDrv.h"
#include "Mcu_Rstgen.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_ResetDrvReleaseCtl(const Mcu_ResetCtlType *rstCtlPtr, uint32 id,
        boolean release)
{
    Std_ReturnType ret = MCU_E_PARAM_POINTER;

    if (NULL_PTR != rstCtlPtr)
    {

        switch (MCU_RESET_TYPE(id))
        {
        case MCU_RESET_CORE:
            ret = Mcu_Ip_RstgenLldCoreControl(
                      rstCtlPtr->base, MCU_RESET_INDEX(id), release);
            break;

        case MCU_RESET_MODULE:
            ret = Mcu_Ip_RstgenLldModuleControl(
                      rstCtlPtr->base, MCU_RESET_INDEX(id), release);
            break;

        case MCU_RESET_MISSION:
            ret = Mcu_Ip_RstgenLldMissionControl(
                      rstCtlPtr->base, MCU_RESET_INDEX(id), release);
            break;

        default:
            ret = MCU_E_PARAM_CONFIG;
            break;
        }
    } /* else not needed */

    return ret;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_ResetDrvAssert(const Mcu_ResetCtlType *rstCtlPtr, uint32 id)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != rstCtlPtr)
    {
        errStatus = Mcu_Ip_ResetDrvReleaseCtl(rstCtlPtr, id, FALSE);
    } /* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_ResetDrvDeassert(const Mcu_ResetCtlType *rstCtlPtr, uint32 id)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != rstCtlPtr)
    {
        errStatus = Mcu_Ip_ResetDrvReleaseCtl(rstCtlPtr, id, TRUE);
    } /* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_ResetDrvReset(const Mcu_ResetCtlType *rstCtlPtr, uint32 id)
{
    Std_ReturnType ret = MCU_E_PARAM_POINTER;

    if (NULL_PTR != rstCtlPtr)
    {
        switch (MCU_RESET_TYPE(id))
        {
        case MCU_RESET_CORE:
            ret = Mcu_Ip_RstgenLldCoreReset(rstCtlPtr->base, MCU_RESET_INDEX(id));
            break;

        case MCU_RESET_MODULE:
            ret = Mcu_Ip_RstgenLldModuleControl(
                      rstCtlPtr->base, MCU_RESET_INDEX(id), FALSE);

            if (E_OK == ret)
            {
                ret = Mcu_Ip_RstgenLldModuleControl(
                          rstCtlPtr->base, MCU_RESET_INDEX(id), TRUE);
            } /* else not needed */

            break;

        case MCU_RESET_MISSION:
            ret = Mcu_Ip_RstgenLldMissionControl(
                      rstCtlPtr->base, MCU_RESET_INDEX(id), FALSE);

            if (E_OK == ret)
            {
                ret = Mcu_Ip_RstgenLldMissionControl(
                          rstCtlPtr->base, MCU_RESET_INDEX(id), TRUE);
            } /* else not needed */

            break;

        default:
            ret = MCU_E_PARAM_CONFIG;
            break;
        }
    } /* else not needed */

    return ret;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_ResetDrvGlobalReset(const struct Mcu_PreResetCtlType *rstSfCtlPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != rstSfCtlPtr)
    {
        Mcu_Ip_RstgenLldGlobalReset(rstSfCtlPtr->base);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;

}

static uint32 Mcu_Ip_ResetDrvStatus(const Mcu_ResetCtlType *rstCtlPtr, uint32 id)
{
    uint32 assertStatus = UINT32_MAX;

    if (NULL_PTR != rstCtlPtr)
    {
        switch (MCU_RESET_TYPE(id))
        {
        case MCU_RESET_CORE:
            assertStatus = (uint32)Mcu_Ip_RstgenLldGetCoreResetStatus(
                               rstCtlPtr->base, MCU_RESET_INDEX(id));
            break;

        case MCU_RESET_MODULE:
            assertStatus = (uint32)Mcu_Ip_RstgenLldGetModuleResetStatus(
                               rstCtlPtr->base, MCU_RESET_INDEX(id));
            break;

        case MCU_RESET_MISSION:
            assertStatus = (uint32)Mcu_Ip_RstgenLldGetMissionResetStatus(
                               rstCtlPtr->base, MCU_RESET_INDEX(id));
            break;

        default:
            assertStatus = UINT32_MAX;
            break;
        }

        if (0U == assertStatus)
        {
            assertStatus = 1U;
        }
        else if (1U == assertStatus)
        {
            assertStatus = 0U;
        }
        else
        {
            /*do nothing*/
        }
    } /* else not needed */

    return assertStatus;
}

static uint32 Mcu_Ip_ResetDrvReadGeneral(const Mcu_ResetCtlType *rstCtlPtr, uint32 id)
{
    uint32 ret = UINT32_MAX;

    if (NULL_PTR != rstCtlPtr)
    {
        if (id < MCU_RESET_GENERAL_REG_NUM)
        {
            ret = Mcu_Ip_RstgenLldReadGeneralReg(rstCtlPtr->base, id);
        } /* else not needed */
    } /* else not needed */

    return ret;
}

static Std_ReturnType Mcu_Ip_ResetDrvWriteGeneral(const Mcu_ResetCtlType *rstCtlPtr, uint32 id,
        uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != rstCtlPtr)
    {
        if (id < MCU_RESET_GENERAL_REG_NUM)
        {
            Mcu_Ip_RstgenLldWriteGeneralReg(rstCtlPtr->base, id, val);
            errStatus = E_OK;
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** Traceability       : SW_SM006*/
/*PRQA S 1531 1*/
const Mcu_ResetCtlOpsType Mcu_RstCtlOps =
{
    .assertSig   =  Mcu_Ip_ResetDrvAssert,
    .deassert =  Mcu_Ip_ResetDrvDeassert,
    .reset    =  Mcu_Ip_ResetDrvReset,
    .status   =  Mcu_Ip_ResetDrvStatus,
    .readGeneral  = Mcu_Ip_ResetDrvReadGeneral,
    .writeGeneral = Mcu_Ip_ResetDrvWriteGeneral,
    .globalReset = Mcu_Ip_ResetDrvGlobalReset,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/* End of file */
