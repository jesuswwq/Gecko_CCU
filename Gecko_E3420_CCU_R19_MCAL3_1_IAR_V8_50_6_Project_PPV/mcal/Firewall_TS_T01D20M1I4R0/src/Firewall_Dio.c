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
 * \file     Firewall_Dio.c                                                                             *
 * \brief    MCAL Firewall Dio Module Driver                                                            *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall_Dio_Cfg.h"
#include "Firewall_DioReg.h"
#include "Firewall_Dio.h"
#include "RegHelper.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  The base address of GPIO_SF controller. */
#define FIREWALL_APB_GPIO_SF_BASE (0xF0740000u)
/** \brief  The base address of GPIO_AP controller. */
#define FIREWALL_APB_GPIO_AP_BASE (0xF3120000u)

#define FIREWALL_START_SEC_CODE
#include "Firewall_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
static Std_ReturnType Firewall_DioGetChannelBase(uint16 *channelId, uint32 *dioBase);
static void Firewall_DioRuleSpaceLock(void);
static Std_ReturnType Firewall_DioSelectCore(const Firewall_DioChannelCfgType *dioChannelCfgPtr, uint8 dioCoreId);
static Std_ReturnType Firewall_DioPermissionConfigure(const Firewall_DioCoreCfgType *dioCoreCfgPtr);

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function Configure the dio rule space and perimissions.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_DioRuleSpaceConfigure
 *                      (
 *                          const Firewall_DioCoreCfgType *dioCoreCfgPtr,
 *                          uint8 coreNum,
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : No reentrant
 *
 * Parameters (in)    : dioCoreCfgPtr - The pointer to the dio cores' configuration
 *                      coreNum - The number of the core configurations
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configure the dio rule space and perimissions success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_DIO_CORE_NUM: The number of the core configurations is unvalid.
 *
 * Description        : This function Configure the dio rule space and perimissions.
 *                      This function should be called only once.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_008 SWSR_FIREWALL_016 SWSR_FIREWALL_018 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_DioRuleSpaceConfigure(const Firewall_DioCoreCfgType *dioCoreCfgPtr, uint8 coreNum)
{
    Std_ReturnType errId = (Std_ReturnType)E_NOT_OK;
    uint8 coreId;

    /* #10 Check the parameters. */
    if (NULL_PTR == dioCoreCfgPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (FIREWALL_DIO_CORE_MAXNUM < coreNum)
    {
        errId = (Std_ReturnType)FIREWALL_E_DIO_CORE_NUM;
    }
    else
    {
        /* #20 Configure the rule of dio pins. */
        for (coreId = 0U; coreId < coreNum; ++coreId)
        {
            /* Assign dio pins to the specified core. */
            errId = Firewall_DioSelectCore(&dioCoreCfgPtr[coreId].dioChannelCfg, dioCoreCfgPtr[coreId].dioCoreId);
            if ((Std_ReturnType)E_OK == errId)
            {
                /* Configure the permissions of dio pins for the core. */
                errId = Firewall_DioPermissionConfigure(&dioCoreCfgPtr[coreId]);
            } /* else not needed */

            if ((Std_ReturnType)E_OK != errId)
            {
                break;
            } /* else not needed */
        }

        if ((Std_ReturnType)E_OK == errId)
        {
            /* Lock configurations of dio pins. */
            Firewall_DioRuleSpaceLock();
        } /* else not needed */
    }

    return errId;
}

/** *****************************************************************************************************
 * \brief This function get the base address of the dio controller.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_DioGetChannelBase
 *                      (
 *                          uint16 *channelId,
 *                          uint32 *dioBase,
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : channelId - The id of the pin channel
 *
 * Parameters (out)   : dioBase - The base address of the dio controller
 *
 * Return value       : E_OK: Get the specified dio base address success.
 *                      FIREWALL_E_DIO_CHANNEL_ID: The id of the pin channel is unvalid.
 *
 * Description        : This function get the base address of the dio controller.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_016 SM006
 *******************************************************************************************************/
static Std_ReturnType Firewall_DioGetChannelBase(uint16 *channelId, uint32 *dioBase)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;

    /* #10 Check the parameters. */
    if ((NULL_PTR == channelId) || (NULL_PTR == dioBase))
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (FIREWALL_DIO_CHANNEL_MAXNUM <= *channelId)
    {
        errId = (Std_ReturnType)FIREWALL_E_DIO_CHANNEL_ID;
    }
    else
    {
        /* #20 Get the base address of the dio controller. */
        if (FIREWALL_DIO_SF_MAXNUM > *channelId)
        {
            *dioBase = FIREWALL_APB_GPIO_SF_BASE;
        }
#ifndef SEMIDRIVE_E3_LITE_SERIES
        else
        {
            *channelId -= FIREWALL_DIO_SF_MAXNUM;
            *dioBase = FIREWALL_APB_GPIO_AP_BASE;
        }
#endif
    }

    return errId;
}

/** *****************************************************************************************************
 * \brief This function Configure the dio pin rule space.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_DioSelectCore
 *                      (
 *                          const Firewall_DioChannelCfgType *dioChannelCfgPtr,
 *                          uint8 dioCoreId,
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : No reentrant
 *
 * Parameters (in)    : dioChannelCfgPtr - The pointer to the dio pin configurations
 *                      dioCoreId - The id of the core
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configure the dio rule space and perimissions success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_DIO_CHANNEL_NUM: The number of the dio pin channels is unvalid.
 *
 * Description        : This function Configure the dio pin rule space.
 *                      This function is called by Firewall_DioRuleSpaceConfigure().
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_016 SM006
 *******************************************************************************************************/
static Std_ReturnType Firewall_DioSelectCore(const Firewall_DioChannelCfgType *dioChannelCfgPtr, uint8 dioCoreId)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint32 dioBase = 0U;
    uint16 channelId;
    uint16 channelCfgNum;
    uint16 channelNum;
    uint32 tempVal;

    /* #10 Check the parameters. */
    if (NULL_PTR == dioChannelCfgPtr->dioChannelID)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (FIREWALL_DIO_CHANNEL_MAXNUM < dioChannelCfgPtr->dioChannelNum)
    {
        errId = (Std_ReturnType)FIREWALL_E_DIO_CHANNEL_NUM;
    }
    else
    {
        channelCfgNum = dioChannelCfgPtr->dioChannelNum;

        /* #20 Assign dio pins to the specified core. */
        for (channelNum = 0U; channelNum < channelCfgNum; ++channelNum)
        {
            channelId = dioChannelCfgPtr->dioChannelID[channelNum];
            errId = Firewall_DioGetChannelBase(&channelId, &dioBase);
            if ((Std_ReturnType)E_OK == errId)
            {
                switch (dioCoreId)
                {
                    case 0: /* SF */
                        REG_WRITE32((uint32)FIREWALL_DIO_DGSEL_SF << FIREWALL_DIO_RGN_DGSEL_BIT,
                                    dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
                        break;

                    case 1: /* SX0 */
                        REG_WRITE32((uint32)FIREWALL_DIO_DGSEL_SX0 << FIREWALL_DIO_RGN_DGSEL_BIT,
                                    dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
                        break;

                    case 2: /* SX1 */
                        REG_WRITE32((uint32)FIREWALL_DIO_DGSEL_SX1 << FIREWALL_DIO_RGN_DGSEL_BIT,
                                    dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
                        break;

                    case 3: /* SP0 */
                        REG_WRITE32((uint32)FIREWALL_DIO_DGSEL_SP0 << FIREWALL_DIO_RGN_DGSEL_BIT,
                                    dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
                        break;

                    case 4: /* SP1 */
                        REG_WRITE32((uint32)FIREWALL_DIO_DGSEL_SP1 << FIREWALL_DIO_RGN_DGSEL_BIT,
                                    dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
                        break;

                    default:
                    {
                        errId = (Std_ReturnType)FIREWALL_E_DIO_CORE_ID;
                        break;
                    }
                }

                /* Enable the assignment of the dio pin. */
                tempVal = REG_READ32(dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
                REG_WRITE32(tempVal | (uint32)FIREWALL_DIO_RGN_EN, dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
            } /* else not needed */
        }
    }

    return errId;
}

/** *****************************************************************************************************
 * \brief This function Configure the permissions of the dio pin for the core.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_DioPermissionConfigure
 *                      (
 *                          const Firewall_DioCoreCfgType *dioCoreCfgPtr,
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : No reentrant
 *
 * Parameters (in)    : dioCoreCfgPtr - The pointer to the dio core's configurations
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configure the dio rule space and perimissions success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_DIO_CORE_ID: The id of the core is unvalid.
 *
 * Description        : This function Configure the permissions of the dio pin for the core.
 *                      This function is called by Firewall_DioRuleSpaceConfigure().
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_016 SM006
 *******************************************************************************************************/
static Std_ReturnType Firewall_DioPermissionConfigure(const Firewall_DioCoreCfgType *dioCoreCfgPtr)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint32 tempVal;

    /* #10 Check the parameters. */
    if (NULL_PTR == dioCoreCfgPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else
    {
        /* #20 Configure permissions of dio pins for the specified core. */
        switch (dioCoreCfgPtr->dioCoreId)
        {
            case 0:
                /* Configure permissions of dio pins for all core domains.
                 * The permissions of the SF domain is depend on EB configurations.
                 */
                tempVal = (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SF));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SF));

                tempVal = (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_USER_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioPrivilegedPermission) << FIREWALL_DIO_DOM7_PRIVILEGED_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioUserPermission) << FIREWALL_DIO_DOM7_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SF));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SF));
                break;

            case 1:
                /* Configure permissions of dio pins for all core domains.
                 * The permissions of the SX0 domain is depend on EB configurations.
                 */
                tempVal = (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SX0));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SX0));

                tempVal = ((uint32)dioCoreCfgPtr->dioPrivilegedPermission) << FIREWALL_DIO_DOM4_PRIVILEGED_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioUserPermission) << FIREWALL_DIO_DOM4_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SX0));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SX0));
                break;

            case 2:
                /* Configure permissions of dio pins for all core domains.
                 * The permissions of the SX1 domain is depend on EB configurations.
                 */
                tempVal = (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SX1));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SX1));

                tempVal = (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_USER_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioPrivilegedPermission) << FIREWALL_DIO_DOM5_PRIVILEGED_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioUserPermission) << FIREWALL_DIO_DOM5_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SX1));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SX1));
                break;

            case 3:
                /* Configure permissions of dio pins for all core domains.
                 * The permissions of the SP0 domain is depend on EB configurations.
                 */
                tempVal = (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_USER_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioPrivilegedPermission) << FIREWALL_DIO_DOM2_PRIVILEGED_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioUserPermission) << FIREWALL_DIO_DOM2_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM3_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SP0));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SP0));

                tempVal = (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SP0));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SP0));
                break;

            case 4:
                /* Configure permissions of dio pins for all core domains.
                 * The permissions of the SP1 domain is depend on EB configurations.
                 */
                tempVal = (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_RW << FIREWALL_DIO_DOM0_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM1_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM2_USER_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioPrivilegedPermission) << FIREWALL_DIO_DOM3_PRIVILEGED_BIT;
                tempVal |= ((uint32)dioCoreCfgPtr->dioUserPermission) << FIREWALL_DIO_DOM3_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SP1));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER0N_ADDR(FIREWALL_DIO_DGSEL_SP1));

                tempVal = (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM4_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM5_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM6_USER_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_PRIVILEGED_BIT;
                tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_DIO_DOM7_USER_BIT;
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SP1));
                REG_WRITE32(tempVal, FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER1N_ADDR(FIREWALL_DIO_DGSEL_SP1));
                break;

            default:
            {
                errId = (Std_ReturnType)FIREWALL_E_DIO_CORE_ID;
                break;
            }
        }
    }

    return errId;
}

/** *****************************************************************************************************
 * \brief This function locks the configurations of the dio rule space and perimissions.
 *
 * \verbatim
 * Syntax             : void Firewall_DioRuleSpaceLock
 *                      (
 *                          void
 *                      )
 *
 * Service ID[hex]    : None
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
 * Return value       : None
 *
 * Description        : This function locks the configurations of the dio rule space and perimissions.
 *                      This function is called by Firewall_DioRuleSpaceConfigure().
 *                      This function should be called after Firewall_DioSelectCore() and
 *                      Firewall_DioPermissionConfigure().
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_008
 *******************************************************************************************************/
static void Firewall_DioRuleSpaceLock(void)
{
    uint32 dioBase = 0U;
    uint16 channelId;
    uint16 channelNum;
    uint32 tempVal;
    uint8 coreId;

    /* #10 Lock the assignment of all dio pins. */
    for (channelNum = 0U; channelNum < FIREWALL_DIO_CHANNEL_MAXNUM; ++channelNum)
    {
        channelId = channelNum;
        (void)Firewall_DioGetChannelBase(&channelId, &dioBase);
        tempVal = REG_READ32(dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
        REG_WRITE32(tempVal | (uint32)FIREWALL_DIO_RGN_LOCK, dioBase + FIREWALL_DIO_DGSELN_ADDR(channelId));
    }

    /* #20 Lock the permissions dio pins for different cores. */
    for (coreId = 0U; coreId < FIREWALL_DIO_CORE_MAXNUM; ++coreId)
    {
        REG_WRITE32((uint32)FIREWALL_DIO_DOM_PER_LOCK,
                    FIREWALL_APB_GPIO_SF_BASE + FIREWALL_DIO_DOM_PER_LOCKN_ADDR(coreId));
        REG_WRITE32((uint32)FIREWALL_DIO_DOM_PER_LOCK,
                    FIREWALL_APB_GPIO_AP_BASE + FIREWALL_DIO_DOM_PER_LOCKN_ADDR(coreId));
    }
}

#define FIREWALL_STOP_SEC_CODE
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
