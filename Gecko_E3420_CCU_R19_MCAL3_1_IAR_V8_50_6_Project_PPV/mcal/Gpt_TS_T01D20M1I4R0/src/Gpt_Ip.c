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
 * \file     Gpt_Ip.c                                                                                   *
 * \brief    AUTOSAR 4.3.1 MCAL GPT Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Gpt_Ip.h"
#include "Gpt_Register.h"
#include "RegHelper.h"
#include "Gpt.h"
#include "SchM_Gpt.h"
#include "Gpt_Fault.h"

#define GPT_START_SEC_CONST_32
#include "Gpt_MemMap.h"

/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
/** BTM base address */
static const uint32 BTM_BASE_ADDR32[GPT_IP_MAX_MODULE] =
{
    APBMUX_BTM1_BASE,
    APBMUX_BTM2_BASE,
    APBMUX_BTM3_BASE,
    APBMUX_BTM4_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    APBMUX_BTM5_BASE,
    APBMUX_BTM6_BASE
#endif
};

#define GPT_STOP_SEC_CONST_32
#include "Gpt_MemMap.h"


#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * Syntax             : void Gpt_GetCoreId(void)
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
 * Description        : get core ID,Used for multi-core support of multi-core GPT.
 *
 * Traceability       : SWSR_GPT_087 SWSR_GPT_020 SWSR_GPT_027
 *******************************************************************************************************/
uint32 Gpt_GetCoreId(void)
{
    return Mcu_GetCoreID();
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateInitCfg(const Gpt_ConfigType *config)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : config - Incoming configuration information.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check configuration information.
 *
 * Traceability       : SW_SM006 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateInitCfg(const Gpt_ConfigType *config)
{
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 check pointer */
    if (NULL_PTR == Gpt_Handler[coreId])
    {
        errorId = GPT_E_INIT_FAILED;
    }
    else
    {
        /* #20 check driver mode */
        if (GPT_MODE_INITED == Gpt_Handler[coreId]->driverMode)
        {
            errorId = GPT_E_ALREADY_INITIALIZED;
        }
        else
        {
            /* #30 check parameter pointer */
            if (NULL_PTR == config)
            {
                errorId = GPT_E_INIT_FAILED;
            }
            else
            {
#if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
                /* #40 check predeftimer pointer */
                if (NULL_PTR == config->predefChannelConfig)
                {
                    errorId = GPT_E_INIT_FAILED;
                } /* else not needed */

#endif /** #if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */
            }
        }
    }

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_CheckStaStartTimer(Gpt_ChannelType channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel Id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check channel information.
 *
 * Traceability       : SWSR_GPT_054 SWSR_GPT_055 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_CheckStaStartTimer(Gpt_ChannelType channel)
{
    Std_ReturnType errorId = E_OK;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 check driver mode */
    if (GPT_MODE_INITED != Gpt_Handler[coreId]->driverMode)
    {
        errorId = GPT_E_UNINIT;
    }
    else
    {
        /* #20 check channel status */
        if (GPT_STATUS_RUNNING == Gpt_Handler[coreId]->channelInfo[channel].channelStatus)
        {
            errorId = GPT_E_BUSY;
        }
        else
        {
            /* #30 check channel core ID */
            if (coreId != (*(Gpt_Handler[coreId]->config->channelConfig))[channel].gptCoreId)
            {
                errorId = GPT_E_PARAM_CHANNEL;
            } /* else not needed */
        }
    }

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : static Std_ReturnType  Gpt_CheckChanStaDeInit(Gpt_ChannelType channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel Id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check channel status.If running, return error ID.
 *
 * Traceability       : SWSR_GPT_030
 *******************************************************************************************************/
static Std_ReturnType Gpt_CheckChanStaDeInit(Gpt_ChannelType channel)
{
    Std_ReturnType errorId = E_OK;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 check channel status */
    if (GPT_STATUS_RUNNING == Gpt_Handler[coreId]->channelInfo[channel].channelStatus)
    {
        errorId = GPT_E_BUSY;
    } /* else not needed */

    return errorId;
}

#if (STD_ON == GPT_DEINIT_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_CheckModuleStaDeInit(void)
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
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check all channel status.
 *
 * Traceability       : SWSR_GPT_031 SWSR_GPT_030
 *******************************************************************************************************/
Std_ReturnType Gpt_CheckModuleStaDeInit(void)
{
    Std_ReturnType errorId = E_OK;
    uint32 coreId = Gpt_GetCoreId();
    Gpt_ChannelType channel;

    /* #10 check driver status */
    if (Gpt_Handler[coreId]->driverMode != GPT_MODE_INITED)
    {
        errorId = GPT_E_UNINIT;
    }
    else
    {
        /* #20 check channel status */
        for (channel = 0; channel < Gpt_Handler[coreId]->config->channelCount; channel++)
        {
            /* #30 check channel is running */
            errorId = Gpt_CheckChanStaDeInit(channel);

            if (E_OK != errorId)
            {
                break;
            } /* else not needed */
        }
    }

    return errorId;
}
#endif /** #if (STD_ON == GPT_DEINIT_API) */

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateParamStartTimer(Gpt_ChannelType channel,
 *                                                       Gpt_ValueType value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel Id.
 *                      value - counter value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check channel ID and value.
 *
 * Traceability       : SWSR_GPT_052 SWSR_GPT_053 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateParamStartTimer(Gpt_ChannelType channel, Gpt_ValueType value)
{
    Std_ReturnType errorId = E_OK;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 check channel range */
    if (channel >= GPT_HW_CHANNEL_NUM)
    {
        errorId = GPT_E_PARAM_CHANNEL;
    }
    else
    {
        /* #20 check config point */
        if (NULL_PTR == Gpt_Handler[coreId]->config)
        {
            errorId = GPT_E_UNINIT;
        }
        else
        {
            /* #30 check channel range */
            if ((value > (*(Gpt_Handler[coreId]->config->channelConfig))[channel].channelTickValueMax)
                    || (0U == value))
            {
                errorId = GPT_E_PARAM_VALUE;
            } /* else not needed */
        }
    }

    return errorId;
}


#if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateParamGetPredefTime(Gpt_PredefTimerType predefTimer,
 *                                                          const uint32 *timeValuePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefTimer - predeftimer bits
 *                      timeValuePtr - timer value
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check predeftimer bits and time value
 *
 * Traceability       : SWSR_GPT_078 SWSR_GPT_080 SWSR_GPT_081 SWSR_GPT_082 SWSR_GPT_083
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateParamGetPredefTime(Gpt_PredefTimerType predefTimer,
        const uint32 *timeValuePtr)
{
    Std_ReturnType errorId = E_OK;
    uint32 coreId = Gpt_GetCoreId();
    uint32 preTimerEnable;

    /* #10 check driver mode */
    if (GPT_MODE_INITED != Gpt_Handler[coreId]->driverMode)
    {

        errorId = GPT_E_UNINIT;
    }
    else
    {
        /* #20 check parameter point */
        if (NULL_PTR == timeValuePtr)
        {

            errorId = GPT_E_PARAM_POINTER;
        }
        else
        {
            /* #30 check parameter enumeration Range */
            if (predefTimer > GPT_PREDEF_TIMER_1US_32BIT)
            {

                errorId = GPT_E_PARAM_PREDEF_TIMER;
            }
            else
            {
                /* #40 check config enumeration Range */
                if ((1U + (uint8)predefTimer) >
                        Gpt_Handler[coreId]->config->predefChannelConfig->predefTimer1usNum)
                {
                    errorId = GPT_E_PARAM_PREDEF_TIMER;
                }
                else
                {
                    /* #50 check predeftimer enable bit */
                    preTimerEnable = REG_READ32(GPT_CNT_G0_EN_ADDR32(
                                        Gpt_Handler[coreId]->config->predefChannelConfig->timerHwModule)) & 0X01UL;
                    if (0X01UL != preTimerEnable)
                    {
                        errorId = GPT_E_PARAM_PREDEF_TIMER;
                    } /* else not needed */
                }
            }
        }
    }

    return errorId;
}
#endif /** #if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */

#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateNotification(Gpt_ChannelType channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel ID
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check notification pointer.
 *
 * Traceability       : SWSR_GPT_065 SWSR_GPT_069 SWSR_GPT_071 SWSR_GPT_074
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateNotification(Gpt_ChannelType channel)
{
    Std_ReturnType errorId = E_OK;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 check config point */
    if (NULL_PTR == Gpt_Handler[coreId]->config)
    {
        errorId = GPT_E_PARAM_POINTER;
    }
    else
    {
        /* #20 check config notification point */
        if (NULL_PTR == (*(Gpt_Handler[coreId]->config->channelConfig))[channel].notification)
        {
            errorId = GPT_E_PARAM_CHANNEL;
        } /* else not needed */
    }

    return errorId;
}
#endif /** #if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API) */

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateParamCommon(Gpt_ChannelType channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel ID
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check driver status and channel ID.
 *
 * Traceability       : SWSR_GPT_037 SWSR_GPT_038 SWSR_GPT_043 SWSR_GPT_045 SWSR_GPT_046
 *                      SWSR_GPT_061 SWSR_GPT_062 SWSR_GPT_065 SWSR_GPT_068 SWSR_GPT_071
 *                      SWSR_GPT_073 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateParamCommon(Gpt_ChannelType channel)
{
    Std_ReturnType errorId = E_OK;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 check channel ID */
    if (channel >= GPT_HW_CHANNEL_NUM)
    {

        errorId = GPT_E_PARAM_CHANNEL;
    }
    else
    {
        /* #20 check driver mode */
        if (GPT_MODE_INITED != Gpt_Handler[coreId]->driverMode)
        {
            errorId = GPT_E_UNINIT;
        }
        else
        {
            /* #30 check channel core ID */
            if (coreId != (*(Gpt_Handler[coreId]->config->channelConfig))[channel].gptCoreId)
            {
                errorId = GPT_E_PARAM_CHANNEL;
            } /* else not needed */

        }
    }

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateIrq(Gpt_HwModule hwModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwModule - HW module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check if the interrupt is expected.
 *
 * Traceability       : SWSR_GPT_084 SW_SM003 SW_SM004
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateIrq(Gpt_HwModule hwModule)
{
    Std_ReturnType errorId = E_OK;
    uint32 irqStatus;
    Gpt_ChannelType channel;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 get interrupt status */
    irqStatus = Gpt_Ip_GetInterrupt((uint8)hwModule);

    /* Error Inject Point */
    GptHookBegin_Gpt_UnexpectedInterruption();

    /* #20 check private handler point and driver mode */
    if ((NULL_PTR == Gpt_Handler[coreId]) ||
            (GPT_MODE_INITED != Gpt_Handler[coreId]->driverMode))
    {
        /* #30 check irq bit */
        if ((irqStatus & GPT_IP_HW_CHANNEL_G0_IRQ) > 0U)
        {
            /* #40 clear G0 irq */
            Gpt_Ip_ClearInterrupt((uint8)hwModule, ((uint8)(irqStatus & GPT_IP_HW_CHANNEL_G0_IRQ)));
            errorId = E_NOT_OK;
        } /* else not needed */

        /* #50 check irq bit */
        if ((irqStatus & GPT_IP_HW_CHANNEL_G1_IRQ) > 0U)
        {
            /* #60 clear G1 irq */
            Gpt_Ip_ClearInterrupt((uint8)hwModule, ((uint8)(irqStatus & GPT_IP_HW_CHANNEL_G1_IRQ)));
            errorId = E_NOT_OK;
        } /* else not needed */
        GptHookEnd_Gpt_UnexpectedInterruption();
    }
    else
    {
        /* #70 check irq bit */
        if ((irqStatus & GPT_IP_HW_CHANNEL_G0_IRQ) > 0U)
        {
            /* #80 check channel status */
            for (channel = 0; channel < Gpt_Handler[coreId]->config->channelCount; channel++)
            {
                /* Error Inject Point */
                GptHookBegin_Gpt_InitUnexpectedInterruption();
                /* #90 channel is not  GPT_STATUS_RUNNING.It is an unexpected interruption.*/
                if ((GPT_STATUS_RUNNING != (Gpt_Handler[coreId]->channelInfo)[channel].channelStatus) &&
                        (hwModule == (*(Gpt_Handler[coreId]->config->channelConfig))[channel].hwChannelConfig.timerHwModule)
                        &&
                        (GPT_HW_TIMER_G0 == (*
                                            (Gpt_Handler[coreId]->config->channelConfig))[channel].hwChannelConfig.hwChannel))
                {
                    Gpt_Ip_ClearInterrupt((uint8)hwModule, ((uint8)(irqStatus & GPT_IP_HW_CHANNEL_G0_IRQ)));
                    errorId = E_NOT_OK;
                    break;
                } /* else not needed */
                GptHookEnd_Gpt_InitUnexpectedInterruption();
            }
        } /* else not needed */

        if ((irqStatus & GPT_IP_HW_CHANNEL_G1_IRQ) > 0U)
        {
            /* #100 check channel status */
            for (channel = 0; channel < Gpt_Handler[coreId]->config->channelCount; channel++)
            {
                /* Error Inject Point */
                GptHookBegin_Gpt_InitUnexpectedInterruption();
                /* #110 channel is not  GPT_STATUS_RUNNING.It is an unexpected interruption.*/
                if ((GPT_STATUS_RUNNING != (Gpt_Handler[coreId]->channelInfo)[channel].channelStatus) &&
                        (hwModule == (*(Gpt_Handler[coreId]->config->channelConfig))[channel].hwChannelConfig.timerHwModule)
                        &&
                        (GPT_HW_TIMER_G1 == (*
                                            (Gpt_Handler[coreId]->config->channelConfig))[channel].hwChannelConfig.hwChannel))
                {
                    Gpt_Ip_ClearInterrupt((uint8)hwModule, ((uint8)(irqStatus & GPT_IP_HW_CHANNEL_G1_IRQ)));
                    errorId = E_NOT_OK;
                    break;
                } /* else not needed */
                GptHookEnd_Gpt_InitUnexpectedInterruption();
            }
        } /* else not needed */
    }

    return errorId;
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_Init(const Gpt_HwChannelConfigType *hwChannelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    :  hwChannelConfigPtr - configuration structure
 *                        for initializing the module.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initializes the GPT driver.
 *
 * Traceability       : SWSR_GPT_019 SWSR_GPT_018 SWSR_GPT_085 SW_SM005
 *******************************************************************************************************/
void Gpt_Ip_Init(const Gpt_HwChannelConfigType *hwChannelConfigPtr)
{
    uint32 tmrCntInitConfig;
    uint32 tmrCntSiVal;
    uint32 tms = 0UL;
    uint32 tmsStatus;

    /* #10 disable interrupt. */
    REG_WRITE32(0x00UL, GPT_INT_STA_EN_ADDR32(hwChannelConfigPtr->timerHwModule));
    REG_WRITE32(0x00UL, GPT_INT_SIG_EN_ADDR32(hwChannelConfigPtr->timerHwModule));
    tmrCntSiVal = ((hwChannelConfigPtr->prescaler) << GPT_CNT_SI_VAL_MASK_START);
    tmrCntInitConfig = tmrCntSiVal | GPT_CNT_INC_VAL;

    /* #20 config apb clk register */
    if (hwChannelConfigPtr->clockRef == GPT_CLOCKREF_APB)
    {
        REG_WRITE32(tmrCntInitConfig, GPT_CNT_G0_CFG_ADDR32(hwChannelConfigPtr->timerHwModule));
    }
    /* #30 config xtal 24M clk register */
    else
    {
        REG_WRITE32(tmrCntInitConfig, GPT_CNT_G1_CFG_ADDR32(hwChannelConfigPtr->timerHwModule));
        REG_WRITE32(GPT_CNT_G1_UPD_FLAG_SI_MASK, GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule));

        /* #40Delay a while unitl si values be synced,need 4 at pclk+4 at 24m_clk*/
        tmsStatus = REG_READ32(GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule)) &
                 GPT_CNT_G1_UPD_FLAG_SI_MASK;
        while ((tmsStatus > 0UL) &&
                (tms < 10000U))
        {
            tmsStatus = REG_READ32(GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule)) &
                 GPT_CNT_G1_UPD_FLAG_SI_MASK;
            ++tms;
        };
    }
}

#if (STD_ON == GPT_DEINIT_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_DeInit(const Gpt_HwChannelConfigType *hwChannelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    : hwChannelConfigPtr - configuration structure
 *                        for deinit the module.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Deinitializes the GPT driver.
 *
 * Traceability       : SWSR_GPT_026
 *******************************************************************************************************/
void Gpt_Ip_DeInit(const Gpt_HwChannelConfigType *hwChannelConfigPtr)
{
    /* #10 disable register/config/over flow. */
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(hwChannelConfigPtr->timerHwModule) +
              (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)), 0, 1U, 0U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32((uint32)(hwChannelConfigPtr->timerHwModule)),
              GPT_CNT_SI_VAL_MASK_START, GPT_CNT_SI_VAL_MASK_WIDTH, 1U);
    REG_RMW32(GPT_CNT_G1_CFG_ADDR32((uint32)(hwChannelConfigPtr->timerHwModule)),
              GPT_CNT_SI_VAL_MASK_START, GPT_CNT_SI_VAL_MASK_WIDTH, 1U);
    REG_WRITE32(GPT_CNT_G1_UPD_FLAG_SI_MASK, GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule));
    REG_WRITE32(0x0U, GPT_CNT_G0_OVF_ADDR32(hwChannelConfigPtr->timerHwModule) +
                (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)));

    /* #20 disable interrupt. */
    REG_RMW32((GPT_INT_SIG_EN_ADDR32((hwChannelConfigPtr->timerHwModule))),
                (GPT_IP_OVFINT_EN_MASK_START(hwChannelConfigPtr->hwChannel)), 1U, 0U);
    REG_RMW32(GPT_INT_STA_EN_ADDR32(hwChannelConfigPtr->timerHwModule),
                GPT_IP_OVFINT_EN_MASK_START(hwChannelConfigPtr->hwChannel), 1U, 0U);

    /* #30 disable G0 config. */
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(hwChannelConfigPtr->timerHwModule) +
              (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)), 0, 1U, 0U);

    if (hwChannelConfigPtr->hwChannel == GPT_HW_TIMER_G1)
    {
        /* #40 disable G1 update register. */
        REG_WRITE32(GPT_CNT_G1_UPD_FLAG_OVF_MASK, GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule));
    } /* else not needed */
}
#endif /** #if (STD_ON == GPT_DEINIT_API) */

#if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_PredefDeInit(const Gpt_PredefChannelConfigType *predefCfgPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefCfgPtr - predef time config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : deinit predef timer driver.
 *
 * Traceability       : SWSR_GPT_028
 *******************************************************************************************************/
void Gpt_Ip_PredefDeInit(const Gpt_PredefChannelConfigType *predefCfgPtr)
{
    /* #10 disable BTM G0 register */
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(predefCfgPtr->timerHwModule),
              0, 1U, 0U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(predefCfgPtr->timerHwModule),
              GPT_CNT_SI_VAL_MASK_START, 8U, 0x1U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(predefCfgPtr->timerHwModule), 0, 1U, 0U);
    REG_WRITE32(0x0U, GPT_CNT_G0_OVF_ADDR32(predefCfgPtr->timerHwModule));
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_StartPreDefTimer(const Gpt_PredefChannelConfigType *predefCfgPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefCfgPtr - predef timer config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : predef timer start timing.
 *
 * Traceability       : SWSR_GPT_007 SWSR_GPT_008
 *******************************************************************************************************/
void Gpt_Ip_StartPreDefTimer(const Gpt_PredefChannelConfigType *predefCfgPtr)
{
    uint32 prescaler;
    uint32 apbClk = GPT_BUS_CLK;

    /* #10 config over flow register. */
    switch (predefCfgPtr->predefTimer1usNum)
    {
    case 3:
        REG_WRITE32(0xffffffffU, GPT_CNT_G0_OVF_ADDR32(predefCfgPtr->timerHwModule));
        break;

    case 2:
        REG_WRITE32(0xffffffU, GPT_CNT_G0_OVF_ADDR32(predefCfgPtr->timerHwModule));
        break;

    case 1:
        REG_WRITE32(0xffffU, GPT_CNT_G0_OVF_ADDR32(predefCfgPtr->timerHwModule));
        break;

    default:
         /* Do Nothing */
        break;
    }

    /* #20 Generate 1us/tick */
    prescaler = (apbClk / GPT_TIME_US) - 1UL;
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(predefCfgPtr->timerHwModule),
              GPT_CNT_SI_VAL_MASK_START, 8UL, prescaler & 0xFFUL);
    /* #30 set g0 continous */
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(predefCfgPtr->timerHwModule), 0, 1U, 1U);
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(predefCfgPtr->timerHwModule), 0, 1U, 1U);
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_GetPredefTimerValue(const Gpt_PredefChannelConfigType *predefCfgPtr,
 *                                                      Gpt_PredefTimerType predefTimer,
 *                                                      uint32 *timeValuePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefCfgPtr - predef time config
 *                      predefTimer - predef timer bits
 *
 * Parameters (inout) : uint32 *timeValuePtr - predef time value
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Obtain the value of the timer
 *
 * Traceability       : SWSR_GPT_076 SWSR_GPT_077 SWSR_GPT_078 SWSR_GPT_088 SWSR_GPT_089
 *******************************************************************************************************/
void Gpt_Ip_GetPredefTimerValue(const Gpt_PredefChannelConfigType *predefCfgPtr,
                                Gpt_PredefTimerType predefTimer, uint32 *timeValuePtr)
{
    /* #10 get predeftimer register */
    switch (predefTimer)
    {
    case GPT_PREDEF_TIMER_1US_16BIT:
        *timeValuePtr = REG_READ32(GPT_CNT_G0_VAL_ADDR32((uint32)(predefCfgPtr->timerHwModule))) & 0xffffU;
        break;

    case GPT_PREDEF_TIMER_1US_24BIT:
        *timeValuePtr = REG_READ32(GPT_CNT_G0_VAL_ADDR32((uint32)(predefCfgPtr->timerHwModule))) &
                        0xffffffU;
        break;

    case GPT_PREDEF_TIMER_1US_32BIT:
        *timeValuePtr = REG_READ32(GPT_CNT_G0_VAL_ADDR32((uint32)(predefCfgPtr->timerHwModule))) &
                        0xffffffffU;
        break;

    default:
        *timeValuePtr = 0U;
        break;
    }
}
#endif /** #if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_StartTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr,
 *                                              Gpt_ChannelModeType channelMode,
 *                                              Gpt_ValueType value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwChannelConfigPtr - channel config
 *                      channelMode - channel mode
 *                      value - over flow value
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Starts a timer channel.
 *
 * Traceability       : SWSR_GPT_004 SWSR_GPT_005 SWSR_GPT_048 SWSR_GPT_049 SWSR_GPT_050
 *                      SWSR_GPT_085 SW_SM005
 *******************************************************************************************************/
void Gpt_Ip_StartTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr,
                       Gpt_ChannelModeType channelMode, Gpt_ValueType value)
{
    uint32 tms = 0U;
    uint32 tmsStatus;

    /* #10 config continuous register */
    if (GPT_CH_MODE_CONTINUOUS == channelMode)
    {
        REG_RMW32(GPT_CNT_G0_CFG_ADDR32(hwChannelConfigPtr->timerHwModule) +
                  (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)), 0, 1U, 1U);
    }
    /* #20 config one shot register */
    else
    {
        REG_RMW32(GPT_CNT_G0_CFG_ADDR32(hwChannelConfigPtr->timerHwModule) +
                  (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)), 0, 1U, 0U);
    }

    /* #30 config over flow register */
    REG_WRITE32((uint32)value, GPT_CNT_G0_OVF_ADDR32(hwChannelConfigPtr->timerHwModule) +
                (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)));

    /* #40 polling G1 register status */
    if (hwChannelConfigPtr->hwChannel == GPT_HW_TIMER_G1)
    {
        REG_WRITE32(GPT_CNT_G1_UPD_FLAG_OVF_MASK, GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule));

        /* #50 Delay a while unitl si values be synced,need 4 at pclk+4 at 24m_clk*/
        tmsStatus = REG_READ32(GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule)) &
                 GPT_CNT_G1_UPD_FLAG_OVF_MASK;
        while ((tmsStatus > 0UL) &&
                (tms < 10000U))
        {
            tmsStatus = REG_READ32(GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule)) &
                 GPT_CNT_G1_UPD_FLAG_OVF_MASK;
            ++tms;
        };
    } /* else not needed */

    /* #60 enable interrupt */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    REG_RMW32(GPT_INT_SIG_EN_ADDR32(hwChannelConfigPtr->timerHwModule),
              GPT_IP_OVFINT_EN_MASK_START(hwChannelConfigPtr->hwChannel), 1U, 1U);
    REG_RMW32(GPT_INT_STA_EN_ADDR32(hwChannelConfigPtr->timerHwModule),
              GPT_IP_OVFINT_EN_MASK_START(hwChannelConfigPtr->hwChannel), 1U, 1U);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();

    /* #70 cnt enable */
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(hwChannelConfigPtr->timerHwModule) +
              (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)), 0, 1U, 1U);
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_StopTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr);
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant (but not for the same timer channel)
 *
 * Parameters (in)    : hwChannelConfigPtr - channel config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Stops a timer channel.
 *
 * Traceability       : SWSR_GPT_056 SWSR_GPT_057 SWSR_GPT_060
 *******************************************************************************************************/
void Gpt_Ip_StopTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr)
{
    /* #10 disable config */
    REG_RMW32(GPT_CNT_G0_EN_ADDR32(hwChannelConfigPtr->timerHwModule) +
              (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)), 0, 1U, 0U);
    REG_RMW32(GPT_CNT_G0_CFG_ADDR32(hwChannelConfigPtr->timerHwModule) +
              (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)), 0, 1U, 0U);
    REG_WRITE32(0x0U, GPT_CNT_G0_OVF_ADDR32(hwChannelConfigPtr->timerHwModule) +
                (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)));

    /* #20 disable G1 update regiseter */
    if (hwChannelConfigPtr->hwChannel == GPT_HW_TIMER_G1)
    {
        REG_WRITE32(GPT_CNT_G1_UPD_FLAG_OVF_MASK, GPT_CNT_G1_UPD_ADDR32(hwChannelConfigPtr->timerHwModule));
    } /* else not needed */

    /* #30 disable interrupt */
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    REG_RMW32(GPT_INT_SIG_EN_ADDR32(hwChannelConfigPtr->timerHwModule),
              GPT_IP_OVFINT_EN_MASK_START(hwChannelConfigPtr->hwChannel), 1U, 0U);
    REG_RMW32(GPT_INT_STA_EN_ADDR32(hwChannelConfigPtr->timerHwModule),
              GPT_IP_OVFINT_EN_MASK_START(hwChannelConfigPtr->hwChannel), 1U, 0U);
    if (GPT_HW_TIMER_G0 == hwChannelConfigPtr->hwChannel)
    {
        Gpt_Ip_ClearInterrupt((uint8)(hwChannelConfigPtr->timerHwModule), GPT_IP_HW_CHANNEL_G0_IRQ);
    }
    else
    {
        Gpt_Ip_ClearInterrupt((uint8)(hwChannelConfigPtr->timerHwModule), GPT_IP_HW_CHANNEL_G1_IRQ);
    }

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}

/** *****************************************************************************************************
 * Syntax             : Gpt_ValueType Gpt_Ip_GetTimeElapsed(const Gpt_HwChannelConfigType
 *                                                          *hwChannelConfigPtr,boolean *isExpried)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwChannelConfigPtr - channel config.
 *
 * Parameters (inout) : isExpried - is expried
 *
 * Parameters (out)   : None
 *
 * Return value       : Gpt_ValueType Elapsed timer value (in number of ticks)
 *
 * Description        : Returns the time already elapsed.
 *
 * Traceability       : SWSR_GPT_032 SWSR_GPT_033 SWSR_GPT_035 SWSR_GPT_043
 *******************************************************************************************************/
Gpt_ValueType Gpt_Ip_GetTimeElapsed(const Gpt_HwChannelConfigType *hwChannelConfigPtr,
                                    boolean *isExpried)
{
    uint32 overflowValue;
    uint32 CounterValue;
    uint32 CounterEnable;

    /* #10 get counter enable status */
    CounterEnable = REG_READ32(GPT_CNT_G0_EN_ADDR32(hwChannelConfigPtr->timerHwModule) +
                               (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel))) & 0x1U;
    /* #20 get over flow value */
    overflowValue = REG_READ32(GPT_CNT_G0_OVF_ADDR32(hwChannelConfigPtr->timerHwModule) +
                               (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)));
    /* #30 get counter value */
    CounterValue = REG_READ32(GPT_CNT_G0_VAL_ADDR32(hwChannelConfigPtr->timerHwModule) +
                              (GPT_IP_REG_OFFSET_20H * (uint32)(hwChannelConfigPtr->hwChannel)));

    /* #40 if counter enable status is 0.Indicates that the interrupt has been triggered */
    if (CounterEnable == 0UL)
    {
        *isExpried = TRUE;
        CounterValue = overflowValue;
    }
    else
    {
        *isExpried = FALSE;
    }

    return (Gpt_ValueType)CounterValue;
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_GetInterrupt(uint8 hwModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwModule - GPT hw module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : get interrupt status.
 *******************************************************************************************************/
uint32 Gpt_Ip_GetInterrupt(uint8 hwModule)
{
    uint32 value;

    /* #10 get interrupt status */
    value = REG_READ32(GPT_INT_STA_ADDR32(hwModule));
    return value;
}

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_ClearInterrupt(uint8 hwModule,uint8 position);
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwModule - GPT hw module.
 *                      position - G0 or G1 interrupt status
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : clear interrupt status.
 *******************************************************************************************************/
void Gpt_Ip_ClearInterrupt(uint8 hwModule, uint8 position)
{
    /* #10 clear interrupt status */
    REG_WRITE32( (uint32)(position), GPT_INT_STA_ADDR32(hwModule));
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */
