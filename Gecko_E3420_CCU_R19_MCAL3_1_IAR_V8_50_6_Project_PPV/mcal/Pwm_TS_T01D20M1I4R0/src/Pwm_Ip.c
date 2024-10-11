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
 * \file     Pwm_Ip.c                                                                                   *
 * \brief    AUTOSAR 4.3.1 MCAL PWM Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_Modules.h"
#include "Pwm_Ip.h"
#include "SchM_Pwm.h"

#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
#if (STD_ON == PWM_CFG_ENABLE_CORE0 )
static Pwm_HandlerConfigType Pwm_HandlerCore0;
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE0 ) */

#if (STD_ON == PWM_CFG_ENABLE_CORE1)
static Pwm_HandlerConfigType Pwm_HandlerCore1;
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE1) */

#if (STD_ON == PWM_CFG_ENABLE_CORE2)
static Pwm_HandlerConfigType Pwm_HandlerCore2;
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE2) */

#if (STD_ON == PWM_CFG_ENABLE_CORE3)
static Pwm_HandlerConfigType Pwm_HandlerCore3;
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE3) */

#if (STD_ON == PWM_CFG_ENABLE_CORE4)
static Pwm_HandlerConfigType Pwm_HandlerCore4;
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE4) */

#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** \brief  PWM multi-core handler  */
Pwm_HandlerConfigType* const Pwm_HandlerPtr[PWM_MAX_CORE_NUM] =
{
#if (STD_ON == PWM_CFG_ENABLE_CORE0 )
    &Pwm_HandlerCore0,
#else
    NULL_PTR,
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE0 ) */
#if (STD_ON == PWM_CFG_ENABLE_CORE1)
    &Pwm_HandlerCore1,
#else
    NULL_PTR,
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE1) */
#if (STD_ON == PWM_CFG_ENABLE_CORE2)
    &Pwm_HandlerCore2,
#else
    NULL_PTR,
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE2) */
#if (STD_ON == PWM_CFG_ENABLE_CORE3)
    &Pwm_HandlerCore3,
#else
    NULL_PTR,
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE3) */
#if (STD_ON == PWM_CFG_ENABLE_CORE4)
    &Pwm_HandlerCore4,
#else
    NULL_PTR,
#endif /** #if (STD_ON == PWM_CFG_ENABLE_CORE4) */
};

/* EPWM counter type list *//* PRQA S 3218 1 */
static const Pwm_CntType Pwm_EpwmCntType[PMW_IP_EPWM_COUNTER_NUMBER] = { PWM_CNT_G0, PWM_CNT_G1 };

/* ETMR counter type list *//* PRQA S 3218 1 */
static const Pwm_CntType Pwm_EtmrCntType[PMW_IP_ETMR_COUNTER_NUMBER] =
{ PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C, PWM_LCNT_D };

/* PWM hardware moduler list *//* PRQA S 3218 1 */
static const Pwm_HrdControllerType Pwm_HrdControl[8] =
{
    EPWM1_MODULE_INDEX, EPWM2_MODULE_INDEX, EPWM3_MODULE_INDEX, EPWM4_MODULE_INDEX,
    ETIMER1_MODULE_INDEX, ETIMER2_MODULE_INDEX, ETIMER3_MODULE_INDEX, ETIMER4_MODULE_INDEX
};

#if (STD_ON == PWM_DMA_SUPPORTED)
/* DMA PWM Peripheral id list *//* PRQA S 3218 1 */
static const Dma_PeripheralIdType Pwm_DmaPeripheralId[8] =
{
    DMA_EPWM1_INDEX, DMA_EPWM2_INDEX, DMA_EPWM3_INDEX, DMA_EPWM4_INDEX,
    DMA_ETIMER1_INDEX, DMA_ETIMER2_INDEX, DMA_ETIMER3_INDEX, DMA_ETIMER4_INDEX
};

/* DMA PWM Peripheral sub id list *//* PRQA S 3218 1 */
static const Dma_SubIdType Pwm_DmaSubId[4] =
{ DMA_PWM_FIFO_A, DMA_PWM_FIFO_B, DMA_PWM_FIFO_C, DMA_PWM_FIFO_D };

/* Dma supported burst length *//* PRQA S 3218 1 */
static const Dma_BurstLengthType Pwm_DmaBurstLength[16] =
{
    DMA_BURST_LENGTH_1, DMA_BURST_LENGTH_2, DMA_BURST_LENGTH_3, DMA_BURST_LENGTH_4,
    DMA_BURST_LENGTH_5, DMA_BURST_LENGTH_6, DMA_BURST_LENGTH_7, DMA_BURST_LENGTH_8,
    DMA_BURST_LENGTH_9, DMA_BURST_LENGTH_10, DMA_BURST_LENGTH_11, DMA_BURST_LENGTH_12,
    DMA_BURST_LENGTH_13, DMA_BURST_LENGTH_14, DMA_BURST_LENGTH_15, DMA_BURST_LENGTH_16
};
#endif

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief Get current core ID.
 *
 * \verbatim
 * Syntax             : uint8 Pwm_Ip_GetCoreID(void)
 *
 * Service ID[hex]    : None
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
 * Return value       : CPU_ID_SF, CPU_ID_SP0, CPU_ID_SP1, CPU_ID_SX0, CPU_ID_SX1
 *
 * Description        : Assignment Pwm_Handler base address of PWM registers.
 *
 * \endverbatim
 * Traceability       :
 *******************************************************************************************************/
uint8 Pwm_Ip_GetCoreID(void)
{
    return GetCoreID();
}

/** *****************************************************************************************************
 * \brief Assignment Pwm_Handler base address of PWM registers.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_SetBaseAddr(void)
 *
 * Service ID[hex]    : None
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
 * Return value       : None
 *
 * Description        : Assignment Pwm_Handler base address of PWM registers.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_025
 *******************************************************************************************************/
void Pwm_Ip_SetBaseAddr(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType *coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set epwm and etimer base addresses */
    coreHandlerPtr->baseAddr[0] = PWM_IP_EPWM1_BASE;
    coreHandlerPtr->baseAddr[1] = PWM_IP_EPWM2_BASE;
    coreHandlerPtr->baseAddr[4] = PWM_IP_ETMR1_BASE;
    coreHandlerPtr->baseAddr[5] = PWM_IP_ETMR2_BASE;
#if (8U == EPWM_AND_ETIMER_MODULE_TOTAL_NUMBER)
    coreHandlerPtr->baseAddr[2] = PWM_IP_EPWM3_BASE;
    coreHandlerPtr->baseAddr[3] = PWM_IP_EPWM4_BASE;
    coreHandlerPtr->baseAddr[6] = PWM_IP_ETMR3_BASE;
    coreHandlerPtr->baseAddr[7] = PWM_IP_ETMR4_BASE;
#endif /** #if (8U == EPWM_AND_ETIMER_MODULE_TOTAL_NUMBER) */
}

/** *****************************************************************************************************
 * \brief Get the channel class type of PWM channel.
 *
 * \verbatim
 * Syntax             : Pwm_ChannelClassType Pwm_Ip_ValidateChannelClass(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : PWM_VARIABLE_PERIOD         - The PWM channel has a variable period.
 *                      PWM_FIXED_PERIOD            - The PWM channel has a fixed period.
 *                      PWM_FIXED_PERIOD_SHIFTED    - The PWM channel has a fixed shifted period.
 *
 * Description        : Get the channel class type of PWM channel.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007
 *******************************************************************************************************/
Pwm_ChannelClassType Pwm_Ip_ValidateChannelClass(Pwm_ChannelType channelNumber)
{
    /* ----- Local Variables ---------------------------------------------- */
    boolean channelFound = (boolean)FALSE;
    Pwm_ModuleType moduleNum;
    Pwm_ChannelType channelNum;
    Pwm_ChannelType subChannelNum;
    Pwm_ModuleType curModule;
    Pwm_ChannelType curChannel;
    Pwm_ChannelType curSubChannel;
    Pwm_ChannelType logicChannel = 0U;
    Pwm_ChannelClassType channelClass = PWM_VARIABLE_PERIOD;
    Pwm_CntType counterSelect;

    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr = NULL_PTR;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* #20 Get pwm moudle total number */
    moduleNum = configPtr->moduleNum;

    /* ----- Implementation ----------------------------------------------- */
    /* #30 Loop all modules and channels to find the right channel */
    for (curModule = ((uint8)0U);  ((curModule < moduleNum) && (FALSE == channelFound));
            curModule++)
    {
        moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
        channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
        /* Get the channel number */
        channelNum = moduleCfgPtr->channelNum;
        /* #40 Loop channels to find the rigth channel */
        for (curChannel = ((uint8)0U); curChannel < channelNum; curChannel++)
        {
            /* Get the subchannel number */
            if ((boolean)TRUE == channelGroupCfgPtr->channelGroup[curChannel].bothCmpOutput)
            {
                subChannelNum = 2;
            }
            else
            {
                subChannelNum = 1;
            }
            /* #50 Loop subchannels to find the rigth channel */
            for (curSubChannel = ((uint8)0U); curSubChannel < subChannelNum;
                 curSubChannel++)
            {
                logicChannel++;
                if (channelNumber == logicChannel)
                {
                    /* Find the right chanel, break */
                    channelFound = (boolean)TRUE;
                    break;
                } /* else not needed */
            }

            /* Find the right chanel, break */
            if ((boolean)TRUE == channelFound)
            {
                break;
            } /* else not needed */
        }
    }

    if (NULL_PTR != moduleCfgPtr)
    {
        /* #60 Get the channel class */
        counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;
        channelClass = moduleCfgPtr->countCfg[counterSelect].channelClass;
    } /* else not needed */

    return channelClass;
}

#if ((STD_ON == PWM_SET_DUTY_CYCLE_API) || (STD_ON == PWM_SET_PERIOD_AND_DUTY_API)          \
    || (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API) || (STD_ON == PWM_NOTIFICATION_SUPPORTED)     \
    || (STD_ON == PWM_GET_OUTPUT_STATE_API))
/** *****************************************************************************************************
 * \brief Get the hardware module ID, channel ID and sub channel ID.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_GetHardwareChannel(
 *                          Pwm_ChannelType channelNumber,
 *                          Pwm_ModuleType* curModuleIdPtr,
 *                          Pwm_ChannelType* curChannelIdPtr,
 *                          uint8* curSubChannelIdPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : curModuleIdPtr      - Point to numeric identifier of the PWM hardware module.
 *                      curChannelIdPtr     - Point to numeric identifier of the PWM hardware channel.
 *                      curSubChannelIdPtr  - Point to numeric identifier of the PWM hardware sub
 *                                            channel.
 *
 * Return value       : None
 *
 * Description        : Get the hardware module ID, channel ID and sub channel ID.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007
 *******************************************************************************************************/
static void Pwm_Ip_GetHardwareChannel
(
    Pwm_ChannelType channelNumber,
    Pwm_ModuleType* curModuleIdPtr,
    Pwm_ChannelType* curChannelIdPtr,
    uint8* curSubChannelIdPtr
)
{
    /* ----- Local Variables ---------------------------------------------- */
    boolean channelFound = (boolean)FALSE;
    Pwm_ModuleType moduleNum;
    Pwm_ChannelType channelNum;
    Pwm_ChannelType subChannelNum;
    Pwm_ModuleType curModule;
    Pwm_ChannelType curChannel;
    Pwm_ChannelType curSubChannel;
    Pwm_ChannelType logicChannel = 0U;

    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get pwm moudle total number */
    moduleNum = configPtr->moduleNum;
    /* #30 Loop all modules and channels to find the right channel */
    for (curModule = ((uint8)0U);  curModule < moduleNum;  curModule++)
    {
        moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
        channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
        /* Get the channel number */
        channelNum = moduleCfgPtr->channelNum;
        /* #40 Loop channels to find the rigth channel */
        for (curChannel = ((uint8)0U); curChannel < channelNum; curChannel++)
        {
            /* Get the subchannel number */
            if ((boolean)TRUE == channelGroupCfgPtr->channelGroup[curChannel].bothCmpOutput)
            {
                subChannelNum = 2;
            }
            else
            {
                subChannelNum = 1;
            }
            /* #50 Loop subchannels to find the rigth channel */
            for (curSubChannel = ((uint8)0U); curSubChannel < subChannelNum; curSubChannel++)
            {
                logicChannel++;
                if (channelNumber == logicChannel)
                {
                    /* Out point parameters assignment */
                    *curModuleIdPtr = curModule;
                    *curChannelIdPtr = curChannel;
                    *curSubChannelIdPtr = (uint8)curSubChannel;
                    /* Find the right chanel, break */
                    channelFound = (boolean)TRUE;
                    break;
                } /* else not needed */
            }
            /* Find the right chanel, break */
            if ((boolean)TRUE == channelFound)
            {
                break;
            } /* else not needed */
        }
        /* Find the right chanel, break */
        if ((boolean)TRUE == channelFound)
        {
            break;
        } /* else not needed */
    }
}
#endif /** #if ((STD_ON == PWM_SET_DUTY_CYCLE_API) || (STD_ON == PWM_SET_PERIOD_AND_DUTY_API)           \
                || (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API) || (STD_ON == PWM_NOTIFICATION_SUPPORTED)     \
                || (STD_ON == PWM_GET_OUTPUT_STATE_API)) */

/** *****************************************************************************************************
 * \brief Check the hardware controller type is ETIMER or not.
 *
 * \verbatim
 * Syntax             : static boolean Pwm_Ip_IsEtimerModule(
 *                          Pwm_HrdControllerType moduleId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : moduleId - Numeric identifier of the controller.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE    - Controller type is ETIMER controller.
 *                      FALSE   - Controller type is EPWM controller.
 *
 * Description        : Check the hardware controller type is ETIMER or not.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007
 *******************************************************************************************************/
static boolean Pwm_Ip_IsEtimerModule(Pwm_HrdControllerType moduleId)
{
    /* ----- Local Variables ---------------------------------------------- */
    boolean retVal = (boolean)FALSE;

    /* ----- Implementation ----------------------------------------------- */
    /* Determine the module type based on the module id */
    if (moduleId > EPWM4_MODULE_INDEX)
    {
        retVal = (boolean)TRUE;
    } /* else not needed */
    return retVal;
}

/** *****************************************************************************************************
 * \brief Check Pwm IRQ enable and status is set not not.
 *
 * \verbatim
 * Syntax             : static boolean Pwm_Ip_IrqCheck(
 *                          uint32 base,
 *                          Pwm_HrdControllerType moduleId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base        - Pwm controller baseAddress.s
 *                      moduleId    - Numeric identifier of the controller.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE    - IRQ enable and status is set.
 *                      FALSE   - IRQ enable and status is not set.
 *
 * Description        : Check Pwm IRQ enable and status is set not not.
 *
 * \endverbatim
 * Traceability       : SW_SM004
 *******************************************************************************************************/
static boolean Pwm_Ip_IrqCheck(uint32 base, Pwm_HrdControllerType moduleId)
{
    /* ----- Local Variables ---------------------------------------------- */
    boolean retVal = (boolean)FALSE;
    uint32 intStatus;
    uint32 intEnable;
    uint32 intSignal;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Read out the IRQ enable and status */
    intStatus = REG_READ32(base);
    intEnable = REG_READ32(base + PWM_IP_CORE_INT_STA_EN_REG);
    intSignal = REG_READ32(base + PWM_IP_CORE_INT_SIG_EN_REG);

    /* #20 Check the IRQ enable and status */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        if ((intStatus & intEnable & intSignal & (PWM_IP_ETMR_INT_CNT_OVF_EN(0U)
                | PWM_IP_ETMR_INT_CNT_OVF_EN(1U) | PWM_IP_ETMR_INT_CNT_OVF_EN(2U)
                | PWM_IP_ETMR_INT_CNT_OVF_EN(3U))) > 0U)
        {
            retVal = (boolean)TRUE;
        }
    }
    else
    {
        if (0UL != (intStatus & intEnable & intSignal & (PWM_IP_EPWM_INT_CNT_OVF_EN(0U)
                | PWM_IP_EPWM_INT_CNT_OVF_EN(1U))))
        {
            retVal = (boolean)TRUE;
        }
    }

    return retVal;
}

/** *****************************************************************************************************
 * \brief Clear the interrupt status of Pwm controller.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_ClearIntStatus(
 *                          uint32 base)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base - Pwm controller baseAddress.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Clear the interrupt status of Pwm controller.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_026
 *******************************************************************************************************/
static void Pwm_Ip_ClearIntStatus(uint32 base)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 intStatus;

    /* ----- Implementation ----------------------------------------------- */
    /* The PWM interrupt status register offset is 0, not need to add offset. */
    /* #10 Read out the interrupt status */
    intStatus = REG_READ32(base);
    /* #20 Clear out the interrupt status */
    REG_WRITE32(intStatus, base);
}

/** *****************************************************************************************************
 * \brief Set PWM counter overflow value.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Pwm_Ip_SetOverflow(
 *                          const Pwm_ModuleType curModule,
 *                          const Pwm_CntType counterSelect,
 *                          const Pwm_PeriodType period)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : curModule       - Numeric identifier of the PWM hardware module.
 *                      counterSelect   - Type of counter type: PWM_CNT_G0, PWM_CNT_G1,
 *                                        PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C, PWM_LCNT_D.
 *                      period          - The period of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK                          - Set overflow successful.
 *                      PWM_E_COUNTER_OUT_OF_RANGE    - Set overflow failed, counter out of range.
 *
 * Description        : Set PWM counter overflow value.
 *                      EPWM controller counter can only select PWM_CNT_G0, PWM_CNT_G1.
 *                      ETIMER controller counter can only select PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C,
 *                      PWM_LCNT_D.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_094
 *******************************************************************************************************/
static Std_ReturnType Pwm_Ip_SetOverflow
(
    const Pwm_ModuleType curModule,
    const Pwm_CntType counterSelect,
    const Pwm_PeriodType period
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    uint16 dividerNum;
    uint32 moduleClk;
    uint64 counterValue = 0;
    Pwm_HrdControllerType moduleId;
    uint32 etmrCounter;
    uint32 epwmCounter;
    uint32 tempAddr;
    uint32 tempValue;

    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_HwModuleConfigType* moduleHwCfgPtr;
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get module id and module configure */
    moduleHwCfgPtr = &(configPtr->moduleHwCfgPtr[curModule]);
    moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
    moduleId = moduleCfgPtr->moduleId;

    /* #30 Get module clock and divider */
    /* ovf = period*clk/divider, EBTresos make sure the OVFValue less than 0xFFFF FFFF */
    dividerNum = moduleHwCfgPtr->dividerNum;
    moduleClk = moduleHwCfgPtr->moduleClk;
    if (period > 0U)
    {
        /* #40 Calculated the counter overflow value */
        counterValue = ((uint64)moduleClk / 1000000UL * period / ((uint64)dividerNum + 1U)
                / 1000UL) - 1U;
    } /* else not needed */

    /* #50 Check overflow value */
    if (counterValue > PMW_IP_CORE_COUNTER_VALUE_MAX)
    {
        errorId = PWM_E_COUNTER_OUT_OF_RANGE;
    }
    else
    {
        /* #50 Write the overflow value and upload */
        coreHandlerPtr->counterOvfValue[moduleId][counterSelect] = period;
        if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
        {
            etmrCounter = (uint32)counterSelect - (uint32)PWM_LCNT_A;
            /* Write ovf value */
            REG_WRITE32((uint32)counterValue, coreHandlerPtr->baseAddr[moduleId]
                    + PWM_IP_ETMR_LCNT_OVF_N(etmrCounter));
            /* Force reload */
            tempAddr = coreHandlerPtr->baseAddr[moduleId] + PWM_IP_ETMR_LCNT_CFG_N(etmrCounter);
            tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_ETMR_CNT_OVF_UPD_OFFSET);
            REG_WRITE32(tempValue, tempAddr);
        }
        else
        {
            epwmCounter = (uint32)counterSelect;
            /* Write ovf value */
            REG_WRITE32((uint32)counterValue, coreHandlerPtr->baseAddr[moduleId]
                    + PWM_IP_EPWM_CNT_OVF_N(epwmCounter));
            /* Force reload */
            tempAddr = coreHandlerPtr->baseAddr[moduleId] + PWM_IP_EPWM_CNT_CFG_N(epwmCounter);
            tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_EPWM_CNT_OVF_UPD_OFFSET);
            REG_WRITE32(tempValue, tempAddr);
        }
    }

    return errorId;
}

/** *****************************************************************************************************
 * \brief Config PWM clock.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Pwm_Ip_ConfigClock(
 *                          uint32 base,
 *                          uint8 scrClkSel,
 *                          uint16 dividerNum)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base        - Pwm controller baseAddress.
 *                      scrClkSel   - Pwm controll source clock select.
 *                      dividerNum  - Pwm controll clock divider number.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK                        - Set clock successful.
 *                      PWM_E_CONFIG_CLK_TIMEOUT    - Set clock timeout.
 *
 * Description        : Config PWM clock.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_090
 *******************************************************************************************************/
static Std_ReturnType Pwm_Ip_ConfigClock(uint32 base, uint8 scrClkSel, uint16 dividerNum)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    uint16 loopCnt = 0;
    uint32 tempAddr;
    uint32 tempValue;
    uint32 clkChangeUpd;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Set clock source */
    tempAddr = base + PWM_IP_CORE_CLK_CONFIG_REG;
    tempValue = REG_READ32(tempAddr) & (~(PWM_IP_CORE_CLK_SRC_SEL_MASK <<
            PWM_IP_CORE_CLK_SRC_SEL_OFFSET));
    tempValue  |= ((uint32)scrClkSel << PWM_IP_CORE_CLK_SRC_SEL_OFFSET);
    REG_WRITE32(tempValue, tempAddr);
    /* #20 Set clock divide numbfer */
    tempAddr = base + PWM_IP_CORE_CLK_CONFIG_REG;
    tempValue = REG_READ32(tempAddr) & (~PWM_IP_CORE_CLK_DIV_NUM_MASK);
    tempValue  |= (uint32)dividerNum;
    REG_WRITE32(tempValue, tempAddr);
    /* #30 Upload clock config */
    tempAddr = base + PWM_IP_CORE_CLK_CONFIG_REG;
    tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_CORE_CLK_CHANGE_UPD_OFFSET);
    REG_WRITE32(tempValue, tempAddr);

    /* #40 Wait clock config valid */
    /* Normally wait 2 apb clk and 2 timer clk */
    clkChangeUpd = REG_READ32(base + PWM_IP_CORE_CLK_CONFIG_REG)
            & (0x01UL << PWM_IP_CORE_CLK_CHANGE_UPD_OFFSET);
    while (clkChangeUpd > 0U)
    {
        loopCnt++;
        if (loopCnt >= PMW_IP_CORE_WAIT_CLK_TIMEOUT)
        {
            /* Wait clock valid timeout */
            errorId = PWM_E_CONFIG_CLK_TIMEOUT;
            break;
        } /* else not needed */
        /* Read clock config change */
        clkChangeUpd = REG_READ32(base + PWM_IP_CORE_CLK_CONFIG_REG)
            & (0x01UL << PWM_IP_CORE_CLK_CHANGE_UPD_OFFSET);
    }
    return errorId;
}

/** *****************************************************************************************************
 * \brief Set PWM duty cycle value.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Pwm_Ip_SetDuty(
 *                          const Pwm_ModuleType curModule,
 *                          const Pwm_CntType counterSelect,
 *                          const uint8 channelId,
 *                          const uint8 subChannel,
 *                          const uint16 duty)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : curModule       - Numeric identifier of the PWM hardware module.
 *                      counterSelect   - Type of counter type: PWM_CNT_G0, PWM_CNT_G1,
 *                                        PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C, PWM_LCNT_D.
 *                      channelId       - Numeric identifier of the PWM channel.
 *                      subChannel      - Numeric identifier of the PWM hardware sub channel.
 *                      duty            - The duty of the PWM channel., Min=0x0000 Max=0x8000.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set duty successful.
 *                      Others  - Set duty failed.
 *
 * Description        : Set PWM duty cycle value.
 *                      EPWM controller counter can only select PWM_CNT_G0, PWM_CNT_G1.
 *                      ETIMER controller counter can only select PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C,
 *                      PWM_LCNT_D.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_015 SWSR_PWM_026 SWSR_PWM_045
 *******************************************************************************************************/
static Std_ReturnType Pwm_Ip_SetDuty
(
    const Pwm_ModuleType curModule,
    const Pwm_CntType counterSelect,
    const uint8 channelId,
    const uint8 subChannel,
    const uint16 duty
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    uint32 moduleClk;
    uint64 cmpValue;
    uint16 dividerNum;
    Pwm_HrdControllerType moduleId;
    uint32 tempAddr;
    uint32 tempValue;

    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_HwModuleConfigType* moduleHwCfgPtr;
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* ----- Implementation ----------------------------------------------- */
    if (duty > PWM_IP_DUTY_100)
    {
        errorId = PWM_E_DUTYCYCLE_OUT_OF_RANGE;
    }
    else
    {
        /* #20 Get module id and module configure */
        moduleHwCfgPtr = &(configPtr->moduleHwCfgPtr[curModule]);
        moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
        moduleId = moduleCfgPtr->moduleId;
        /* #30 Get module clock and divider number */
        dividerNum = moduleHwCfgPtr->dividerNum;
        moduleClk = moduleHwCfgPtr->moduleClk;
        /* #40 Calculated the compare value */
        cmpValue = (uint64)moduleClk / 1000000UL
                * coreHandlerPtr->counterOvfValue[moduleId][counterSelect]
                * duty / ((uint64)dividerNum + 1U) / 1000UL / PWM_IP_DUTY_100;

        /* #50 Check compare value */
        if (cmpValue > PMW_IP_CORE_COMPARE_VALUE_MAX)
        {
            errorId = PWM_E_COMPARE_OUT_OF_RANGE;
        }
        else
        {
            /* #60 Check compare value and upload */
            /* write cmp value */
            REG_WRITE32((uint32)cmpValue, coreHandlerPtr->baseAddr[moduleId]
                    + PWM_IP_CORE_CMP_A_00_VAL_REG
                    + ((uint32)channelId * PWM_IP_CORE_CMP_CHANNEL_REG_GAP)
                    + ((uint32)subChannel * PWM_IP_CORE_CMP_SUBCHANNEL_REG_GAP));
            /* upload cmp value */
            tempAddr = coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_CMP_CTRL_REG;
            tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_CORE_CMP_VAL_UPD_OFFSET(channelId));
            REG_WRITE32(tempValue, tempAddr);
        }
    }

    return errorId;
}

#if (STD_ON == PWM_DMA_SUPPORTED)
/** *****************************************************************************************************
 * \brief Config PWM DMA channel.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Pwm_Ip_ConfigDmaChannel(
 *                          uint32 base,
 *                          Pwm_HrdControllerType moduleId,
 *                          uint8 channel,
 *                          const Pwm_ChannelDmaCfgType* dmaCfgPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base        - Pwm controller baseAddress.
 *                      moduleId    - Numeric identifier of the controller.
 *                      channel     - Numeric identifier of the PWM channel.
 *                      dmaCfgPtr   - Pointer to DMA configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set config DMA channel successful.
 *                      Others  - Set config DMA channel failed.
 *
 * Description        : Config PWM DMA channel.
 *                      This function is available if the PWM_DMA_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_093
 *******************************************************************************************************/
static Std_ReturnType Pwm_Ip_ConfigDmaChannel
(
    uint32 base,
    Pwm_HrdControllerType moduleId,
    uint8 channel,
    const Pwm_ChannelDmaCfgType* dmaCfgPtr
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    Dma_ChannelConfigType* dmaChannel;
    Dma_DeviceConfigType dmaCfg;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    Dma_InstanceConfigType dmaALConfigData;
    Dma_PeripheralIdType moduleIndex = Pwm_DmaPeripheralId[(uint32)moduleId];
    Dma_SubIdType dmaSubChannel = Pwm_DmaSubId[(uint32)channel];

    /* #20 Get DMA configure params */
    if (E_OK != Dma_GetConfigParams(moduleIndex, dmaSubChannel, DMA_MODULE_PWM, &dmaALConfigData))
    {
        errorId = PWM_E_CONFIG_DMA_CHANNEL;
    }
    else
    {
        /* #30 Require DMA channel */
        dmaChannel = Dma_RequestChannelWithId(dmaALConfigData.controller,
                dmaALConfigData.channelId);
    }

    if(E_OK == errorId)
    {
        /* ----- Implementation ----------------------------------------------- */
        /*PRQA S 0306  1*/
        coreHandlerPtr->dmaChannel[coreHandlerPtr->dmaInitSeq] = (uint32)dmaChannel;
        coreHandlerPtr->dmaInitSeq++;

        /* #40 Check DMA channel */
        if ((NULL_PTR == dmaChannel) || (NULL_PTR == dmaCfgPtr->srcDataPtr))
        {
            errorId =  PWM_E_CONFIG_DMA_CHANNEL;
        }
        else
        {
            dmaChannel->irqCallback = NULL_PTR;
            errorId = Dma_InitConfigChannel(&dmaCfg);
            if (E_OK != errorId)
            {
                errorId =  PWM_E_CONFIG_DMA_CHANNEL;
            }
            else
            {
                dmaCfg.direction = DMA_MEMORY_TO_DEVICE;
                /*PRQA S 0306  1*/
                //dmaCfg.srcAddress = Mcal_AddressConvert((uint32)dmaCfgPtr->srcDataPtr);
                dmaCfg.dstAddress = base + PWM_IP_CORE_FIFO_N((uint32)channel);
                dmaCfg.srcBusWidth = DMA_BEAT_SIZE_4_BYTE;
                dmaCfg.dstBusWidth = DMA_BEAT_SIZE_4_BYTE;
                /* DMA max burst length = fifoWml + 1 */
                dmaCfg.srcMaxBurst = Pwm_DmaBurstLength[(uint32)dmaCfgPtr->fifoWml];
                dmaCfg.dstMaxBurst = Pwm_DmaBurstLength[(uint32)dmaCfgPtr->fifoWml];
                dmaCfg.periodLength = (uint32)(dmaCfgPtr->totalNum * 4U);
                dmaCfg.srcPortSelect = DMA_PORT_AXI64;
                dmaCfg.dstPortSelect = DMA_PORT_AHB32;
                dmaCfg.srcIncDirection = DMA_BURST_INCREMENTAL;
                dmaCfg.dstIncDirection = DMA_BURST_FIXED;
                dmaCfg.loopMode = DMA_LOOP_MODE_1;
                dmaCfg.transaction = DMA_CYCLIC;
                dmaCfg.bufferMode = DMA_CIRCULAR_BUFFER;
                dmaCfg.flowControl = DMA_DIR_MEMORY_TO_DEVICE;
                dmaCfg.transferMode = DMA_TRANSFER_MODE_CONTINUOUS;
                dmaCfg.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;

                /* #50 Config and prepare DMA channel */
                errorId = Dma_ConfigChannel(dmaChannel, &dmaCfg);
                if (E_OK != errorId)
                {
                    errorId =  PWM_E_CONFIG_DMA_CHANNEL;
                }
                else
                {
                    errorId = Dma_PrepareTransmission(dmaChannel, dmaCfgPtr->totalNum * 4U);
                }

                if (E_OK != errorId)
                {
                    errorId =  PWM_E_CONFIG_DMA_CHANNEL;
                }
                else
                {
#if (STD_OFF == PWM_NO_CACHEABLE_NEEDED)
                    /* #60 Flush cache and start DMA */
                    /*PRQA S 0306  1*/
                    Dma_FlushCache((uint32)(dmaCfgPtr->srcDataPtr),
                            PWM_ROUNDUP(dmaCfgPtr->totalNum * 4U, 32U));
#endif /** #if (STD_OFF == PWM_NO_CACHEABLE_NEEDED) */
                    errorId = Dma_Start(dmaChannel);
                }

                if (E_OK != errorId)
                {
                    errorId =  PWM_E_CONFIG_DMA_CHANNEL;
                }
            }
        }
    } /* else not needed */
    return errorId;
}
#endif /** #if (STD_ON == PWM_DMA_SUPPORTED) */

/** *****************************************************************************************************
 * \brief Enable or disable PWM interrupt status and signal.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_SetStaSigInt(
 *                          uint32 base,
 *                          uint32 sta,
 *                          uint32 sig,
 *                          boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base    - Pwm controller baseAddress.
 *                      sta     - PWM interrupt status bits.
 *                      sig     - PWM interrupt signal bit.
 *                      enable  - TRUE: enable, FALSE: disable
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Enable or disable PWM interrupt status and signal.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026
 *******************************************************************************************************/
static void Pwm_Ip_SetStaSigInt(uint32 base, uint32 sta, uint32 sig, boolean enable)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 enSta;

    /* ----- Implementation ----------------------------------------------- */
    if ((boolean)TRUE == enable)
    {
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();
        /* #10 Read out interrupt status enable register */
        enSta = REG_READ32(base + PWM_IP_CORE_INT_STA_EN_REG);
        /* #20 Write interrupt status enable register */
        REG_WRITE32(enSta | sta, base + PWM_IP_CORE_INT_STA_EN_REG);
        /* #30 Read out interrupt signal enable register */
        enSta = REG_READ32(base + PWM_IP_CORE_INT_SIG_EN_REG);
        /* #40 Write interrupt signal enable register */
        REG_WRITE32(enSta | sig, base + PWM_IP_CORE_INT_SIG_EN_REG);
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();
    }
    else
    {
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();
        /* #50 Read out interrupt status enable register */
        enSta = REG_READ32(base + PWM_IP_CORE_INT_STA_EN_REG);
        /* #60 Write interrupt status enable register */
        REG_WRITE32(enSta & (~sta), base + PWM_IP_CORE_INT_STA_EN_REG);
        /* #70 Read out interrupt signal enable register */
        enSta = REG_READ32(base + PWM_IP_CORE_INT_SIG_EN_REG);
        /* #80 Write interrupt signal enable register */
        REG_WRITE32(enSta & (~sig), base + PWM_IP_CORE_INT_SIG_EN_REG);
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();
    }
}

#if (STD_ON == PWM_DMA_SUPPORTED)
/** *****************************************************************************************************
 * \brief Set PWM DMA watermark level.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_SetDmaWatermarkLevel(
 *                          uint32 base,
 *                          Pwm_HrdControllerType moduleId,
 *                          uint8 channelId,
 *                          uint8 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base        - Pwm controller baseAddress.
 *                      moduleId    - Numeric identifier of the controller.
 *                      channelId   - Numeric identifier of the PWM channel.
 *                      value       - Watermark level register value to write.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set PWM DMA watermark level.
 *                      This function is available if the PWM_DMA_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_093
 *******************************************************************************************************/
static void Pwm_Ip_SetDmaWatermarkLevel
(
    uint32 base,
    Pwm_HrdControllerType moduleId,
    uint8 channelId,
    uint8 value
)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 tempAddr;
    uint32 tempValue;

    /* ----- Implementation ----------------------------------------------- */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        /* #10 Write ETMR DMA watermark level register */
        tempAddr = base + PWM_IP_ETMR_DMA_WML_REG;
        tempValue = REG_READ32(tempAddr) & (~(PWM_IP_ETMR_DMA_WML_CHN_MASK <<
                PWM_IP_ETMR_DMA_WML_OFFSET_N(channelId)));
        tempValue  |= ((uint32)value << PWM_IP_ETMR_DMA_WML_OFFSET_N(channelId));
        REG_WRITE32(tempValue, tempAddr);
    }
    else
    {
        if ((uint8)PWM_IP_CMP_CHANNEL_A == channelId)
        {
            /* #20 Write EWPM1 DMA watermark level register */
            tempAddr = base + PWM_IP_EPWM_DMA_WML_REG;
            tempValue = REG_READ32(tempAddr) & (~PWM_IP_EPWM_DMA_WML_CHN_A_MASK);
            tempValue  |= (uint32)value;
            REG_WRITE32(tempValue, tempAddr);
        }
        else if ((uint8)PWM_IP_CMP_CHANNEL_B == channelId)
        {
            /* #30 Write EWPM2 DMA watermark level register */
            tempAddr = base + PWM_IP_EPWM_DMA_WML_REG;
            tempValue = REG_READ32(tempAddr) & (~(PWM_IP_EPWM_DMA_WML_CHN_B_MASK <<
                    PWM_IP_EPWM_DMA_WML_CHN_B_OFFSET));
            tempValue  |= ((uint32)value << PWM_IP_EPWM_DMA_WML_CHN_B_OFFSET);
            REG_WRITE32(tempValue, tempAddr);
        }
        else if ((uint8)PWM_IP_CMP_CHANNEL_C == channelId)
        {
            /* #40 Write EWPM3 DMA watermark level register */
            tempAddr = base + PWM_IP_EPWM_DMA_WML_REG;
            tempValue = REG_READ32(tempAddr) & (~(PWM_IP_EPWM_DMA_WML_CHN_C_MASK <<
                    PWM_IP_EPWM_DMA_WML_CHN_C_OFFSET));
            tempValue  |= ((uint32)value << PWM_IP_EPWM_DMA_WML_CHN_C_OFFSET);
            REG_WRITE32(tempValue, tempAddr);
        }
        else if ((uint8)PWM_IP_CMP_CHANNEL_D == channelId)
        {
            /* #50 Write EWPM4 DMA watermark level register */
            tempAddr = base + PWM_IP_EPWM_DMA_WML_REG;
            tempValue = REG_READ32(tempAddr) & (~(PWM_IP_EPWM_DMA_WML_CHN_D_MASK <<
                    PWM_IP_EPWM_DMA_WML_CHN_D_OFFSET));
            tempValue  |= ((uint32)value << PWM_IP_EPWM_DMA_WML_CHN_D_OFFSET);
            REG_WRITE32(tempValue, tempAddr);
        }
        else
        {
            /* do nothing */
        }
    }
}
#endif /** #if (STD_ON == PWM_DMA_SUPPORTED) */

/** *****************************************************************************************************
 * \brief Set PWM channel compare initialized configure.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_SetCompareInitConfig(
 *                          uint32 base,
 *                          Pwm_ChannelType curChannel,
 *                          const Pwm_ModuleConfigType* moduleConfigPtr,
 *                          const Pwm_ChannelGroupType* channelGroupConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base                    - Pwm controller baseAddress.
 *                      curChannel              - Numeric identifier of the PWM hardware module.
 *                      moduleConfigPtr         - Pointer to controller configuration set.
 *                      channelGroupConfigPtr   - Pointer to channel configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set PWM channel compare initialized configure.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026
 *******************************************************************************************************/
static void Pwm_Ip_SetCompareInitConfig
(
    uint32 base,
    Pwm_ChannelType curChannel,
    const Pwm_ModuleConfigType* moduleConfigPtr,
    const Pwm_ChannelGroupType* channelGroupConfigPtr
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Pwm_HrdControllerType moduleId;
    uint32 channelId;
    uint32 cmpBothOutput;
    uint32 tempAddr;
    uint32 tempValue;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Get module id, channel id and compare both out config */
    moduleId = moduleConfigPtr->moduleId;
    channelId = (uint32)channelGroupConfigPtr->channelGroup[curChannel].channelId;
    cmpBothOutput = (uint32)channelGroupConfigPtr->channelGroup[curChannel].bothCmpOutput;

    /* #20 Set cmp0/cmp1 output and set single compare mode */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        tempAddr = base + PWM_IP_ETMR_CMP_CONFIG_N(channelId);
        /* Set etimer cmp0/cmp1 both output or only cmp0 output */
        tempValue = REG_READ32(tempAddr) & (~PWM_IP_ETMR_CMP_OUT_MODE_MASK);
        tempValue |= cmpBothOutput;
        /* Set etimer single compare mode */
        tempValue &= ~(PWM_IP_ETMR_CMP_MODE_MODE_MASK << PWM_IP_ETMR_CMP_MODE_MODE_OFFSET);
        REG_WRITE32(tempValue, tempAddr);
    }
    else
    {
        tempAddr = base + PWM_IP_CORE_CHN_DMA_CTRL_REG;
        /* Set epwm cmp0/cmp1 both output or only cmp0 output */
        tempValue = REG_READ32(tempAddr) & (~(PWM_IP_EPWM_CMP_N_OUT_MODE_MASK <<
                PWM_IP_EPWM_CMP_N_OUT_MODE_OFFSET(channelId)));
        tempValue |= (cmpBothOutput << PWM_IP_EPWM_CMP_N_OUT_MODE_OFFSET(channelId));
        /* Set epwm single compare mode */
        tempValue &= ~(PWM_IP_EPWM_CMP_N_MODE_MASK << PWM_IP_EPWM_CMP_N_MODE_OFFSET(channelId));
        REG_WRITE32(tempValue, tempAddr);
    }

    if ((uint8)PWM_IP_CMP_CHANNEL_A == channelId)
    {
        if ((boolean)TRUE == moduleConfigPtr->eidConfig.eidEnable)
        {
            /* #30 Set eid value and upload */
            if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
            {
                /* Set etimer eid value */
                tempAddr = base + PWM_IP_ETMR_CMP_A_EID_REG;
                tempValue = REG_READ32(tempAddr) & (~PWM_IP_ETMR_CMP_A_EID_CMP00_MASK);
                tempValue |= moduleConfigPtr->eidConfig.eidValue;
                REG_WRITE32(tempValue, tempAddr);
                /* Upload etimer eid value */
                tempAddr = base + PWM_IP_CORE_CMP_CTRL_REG;
                tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_CORE_CMP_A_EID_UPD_OFFSET);
                REG_WRITE32(tempValue, tempAddr);
            }
            else
            {
                /* Set epwm eid value */
                tempAddr = base + PWM_IP_EPWM_CMP_A_EID_REG;
                tempValue = REG_READ32(tempAddr) & (~PWM_IP_EPWM_CMP_A_EID_CMP00_MASK);
                tempValue |= moduleConfigPtr->eidConfig.eidValue;
                REG_WRITE32(tempValue, tempAddr);
                /* Upload epwm eid value */
                tempAddr = base + PWM_IP_CORE_CMP_CTRL_REG;
                tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_CORE_CMP_A_EID_UPD_OFFSET);
                REG_WRITE32(tempValue, tempAddr);
            }

            /* #40 Set cmp_a pulse width */
            tempAddr = base + PWM_IP_CORE_CMP_A_PULSE_WID0_REG;
            tempValue = REG_READ32(tempAddr) & (~PWM_IP_CORE_CMP_A_PULSE_WID0_CMP00_MASK);
            tempValue |= 24U;
            REG_WRITE32(tempValue, tempAddr);
            /* #50 Set cmp event out mode */
            REG_WRITE32(PWM_IP_CORE_CMP_EVENT_OUT_CMP00_LEVEL_HIGH
                    | PWM_IP_CORE_CMP_EVENT_OUT_CMP10_LEVEL_HIGH
                    | PWM_IP_CORE_CMP_EVENT_OUT_CMP0_OVF_LEVEL_LOW
                    | PWM_IP_CORE_CMP_EVENT_OUT_CMP1_OVF_LEVEL_LOW,
                    base + PWM_IP_CORE_CMP_EVENT_OUT_MODE(channelId));
        }
        else
        {
            /* #60 Set cmp event out mode */
            REG_WRITE32(PWM_IP_CORE_CMP_EVENT_OUT_CMP00_LEVEL_HIGH
                    | PWM_IP_CORE_CMP_EVENT_OUT_CMP10_LEVEL_HIGH
                    | PWM_IP_CORE_CMP_EVENT_OUT_CMP0_OVF_LEVEL_LOW
                    | PWM_IP_CORE_CMP_EVENT_OUT_CMP1_OVF_LEVEL_LOW,
                    base + PWM_IP_CORE_CMP_EVENT_OUT_MODE(channelId));
        }
    }
    else
    {
        /* #70 Set cmp event out mode */
        REG_WRITE32(PWM_IP_CORE_CMP_EVENT_OUT_CMP00_LEVEL_HIGH
                | PWM_IP_CORE_CMP_EVENT_OUT_CMP10_LEVEL_HIGH
                | PWM_IP_CORE_CMP_EVENT_OUT_CMP0_OVF_LEVEL_LOW
                | PWM_IP_CORE_CMP_EVENT_OUT_CMP1_OVF_LEVEL_LOW,
                base + PWM_IP_CORE_CMP_EVENT_OUT_MODE(channelId));
    }
}

/** *****************************************************************************************************
 * \brief Disable Pwm interrupt and clear interrupt status.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_DisableAndClearInterrupt(
 *                          uint32 base
 *                          Pwm_HrdControllerType moduleId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base        - Pwm controller baseAddress.
 *                      moduleId    - Numeric identifier of the controller.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Disable Pwm interrupt and clear interrupt status.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_094
 *******************************************************************************************************/
static void Pwm_Ip_DisableAndClearInterrupt(uint32 base, Pwm_HrdControllerType moduleId)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Disable Pwm interrupt*/
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        /* Disable etimer interrupt*/
        Pwm_Ip_SetStaSigInt(base, PMW_IP_ETMR_INT_STA_EN, PMW_IP_ETMR_INT_SIG_EN, (boolean)FALSE);
    }
    else
    {
        /* Disable epwm interrupt*/
        Pwm_Ip_SetStaSigInt(base, PMW_IP_EPWM_INT_STA_EN, PMW_IP_EPWM_INT_SIG_EN, (boolean)FALSE);
    }
    /* #20 Clear Pwm interrupt*/
    Pwm_Ip_ClearIntStatus(base);
}

/** *****************************************************************************************************
 * \brief Enable Pwm counters.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_SetCounterEnable(
 *                          Pwm_HrdControllerType moduleId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : moduleId    - Numeric identifier of the controller.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Enable Pwm counters.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026
 *******************************************************************************************************/
static void Pwm_Ip_SetCounterEnable(Pwm_HrdControllerType moduleId)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 tempAddr;
    uint32 tempValue;
    uint8 curCounterSel;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set Pwm module counters enable */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        /* Loop all etimer counters */
        for (curCounterSel = ((uint8)0u); curCounterSel < PMW_IP_ETMR_COUNTER_NUMBER;
                curCounterSel++)
        {
            /* Set etimer counters enable */
            tempAddr = coreHandlerPtr->baseAddr[moduleId]
                    + PWM_IP_ETMR_LCNT_EN_N((uint32)curCounterSel);
            tempValue = REG_READ32(tempAddr) | 1UL;
            REG_WRITE32(tempValue, tempAddr);
        }
    }
    else
    {
        /* Loop all epwm counters */
        for (curCounterSel = ((uint8)0u); curCounterSel < PMW_IP_EPWM_COUNTER_NUMBER;
                curCounterSel++)
        {
            /* Set epwm counters enable */
            tempAddr = coreHandlerPtr->baseAddr[moduleId]
                    + PWM_IP_EPWM_CNT_EN_N((uint32)curCounterSel);
            tempValue = REG_READ32(tempAddr) | 1UL;
            REG_WRITE32(tempValue, tempAddr);
        }
    }
}

#if ((STD_ON == PWM_DMA_SUPPORTED) && (STD_ON == PWM_DE_INIT_API))
/** *****************************************************************************************************
 * \brief Clear Pwm FIFO remain data.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_ClearFifo(
 *                          uint32 base
 *                          Pwm_HrdControllerType moduleId,
 *                          uint8 channelId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base        - Pwm controller baseAddress.
 *                      moduleId    - Numeric identifier of the controller.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Clear Pwm FIFO remain data.
 *                      This function is available if the PWM_DMA_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026
 *******************************************************************************************************/
static void Pwm_Ip_ClearFifo(uint32 base, Pwm_HrdControllerType moduleId, uint8 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 tempAddr;
    uint32 tempValue;

    /* ----- Implementation ----------------------------------------------- */
    /* Clear remaining FIFO value */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        /* Clear etimer remaining FIFO value */
        tempAddr = base + PWM_IP_CORE_SW_RST_REG;
        tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_ETMR_RST_CH_OFFSET_N(channelId));
        REG_WRITE32(tempValue, tempAddr);
    }
    else
    {
        /* Clear epwm remaining FIFO value */
        tempAddr = base + PWM_IP_CORE_SW_RST_REG;
        tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_EPWM_RST_CH_OFFSET_N(channelId));
        REG_WRITE32(tempValue, tempAddr);
    }
}
#endif  /** #if ((STD_ON == PWM_DMA_SUPPORTED) && (STD_ON == PWM_DE_INIT_API)) */

#if (STD_ON == PWM_DE_INIT_API)
/** *****************************************************************************************************
 * \brief Set Pwm output de-initialized state.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Pwm_Ip_SetOutputDeinitState(
 *                          Pwm_ModuleType curModule,
 *                          Pwm_CntType counterSelect,
 *                          uint8 channelId,
 *                          boolean bothCmpOutput,
 *                          const Pwm_OutputStateType* idleStatusPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : curModule       - Numeric identifier of the PWM hardware module.
 *                      counterSelect   - Type of counter type: PWM_CNT_G0, PWM_CNT_G1,
 *                                        PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C, PWM_LCNT_D.
 *                      channelId       - Numeric identifier of the PWM channel.
 *                      bothCmpOutput   - Only cmp0 output or both cmp0 and cmp1 out.
 *                      idleStatusPtr   - Point to compare output state.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set Pwm output de-initialized state successful.
 *                      Others  - Set Pwm output de-initialized state failed.
 *
 * Description        : Set Pwm output de-initialized state.
 *                      EPWM controller counter can only select PWM_CNT_G0, PWM_CNT_G1.
 *                      ETIMER controller counter can only select PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C,
 *                      PWM_LCNT_D.
 *                      This function is available if the PWM_DE_INIT_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_094
 *******************************************************************************************************/
static Std_ReturnType Pwm_Ip_SetOutputDeinitState
(
    Pwm_ModuleType curModule,
    Pwm_CntType counterSelect,
    uint8 channelId,
    boolean bothCmpOutput,
    const Pwm_OutputStateType* idleStatusPtr
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Set subchannel_0 output state */
    if (PWM_HIGH == idleStatusPtr[0])
    {
        /* Set subchannel_0 duty */
        errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, PWM_IP_SUBCHANNEL_0,
                PWM_IP_DUTY_0);
    }
    else
    {
        /* Set subchannel_0 duty */
        errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, PWM_IP_SUBCHANNEL_0,
                PWM_IP_DUTY_100);
    }

    if (((Std_ReturnType)E_OK == errorId) && ((boolean)TRUE == bothCmpOutput))
    {
        /* #20 Set subchannel_1 output state */
        if (PWM_HIGH == idleStatusPtr[1])
        {
            /* Set subchannel_1 duty */
            errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, PWM_IP_SUBCHANNEL_1,
                    PWM_IP_DUTY_0);
        }
        else
        {
            /* Set subchannel_1 duty */
            errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, PWM_IP_SUBCHANNEL_1,
                    PWM_IP_DUTY_100);
        }
    } /* else not needed */

    return errorId;
}
#endif /** #if (STD_ON == PWM_DE_INIT_API) */

/** *****************************************************************************************************
 * \brief Set Pwm counter overflow initialized configure.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Pwm_Ip_SetOverflowInitConfig(
 *                          Pwm_HrdControllerType moduleId,
 *                          Pwm_ModuleType curModule,
 *                          const Pwm_ModuleConfigType* moduleCfgPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : moduleId           - Numeric identifier of the controller.
 *                      curModule          - Numeric identifier of the PWM hardware module.
 *                      channelGroupCfgPtr  - Point to Pwm module configure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set Pwm counter overflow initialized configure successful.
 *                      Others  - Set Pwm counter overflow initialized configure failed.
 *
 * Description        : Set Pwm counter overflow initialized configure.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_094
 *******************************************************************************************************/
static Std_ReturnType Pwm_Ip_SetOverflowInitConfig
(
    Pwm_HrdControllerType moduleId,
    Pwm_ModuleType curModule,
    const Pwm_ModuleConfigType* moduleCfgPtr
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint8 curCounterSel;

    /* ----- Implementation ----------------------------------------------- */
    /* Set module counter overflow */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        /* Loop all etimer counters */
        for (curCounterSel = 0U; curCounterSel < PMW_IP_ETMR_COUNTER_NUMBER; curCounterSel++)
        {
            /* Set etimer counter overflow */
            errorId = Pwm_Ip_SetOverflow(curModule, Pwm_EtmrCntType[curCounterSel],
                    moduleCfgPtr->countCfg[(uint32)Pwm_EtmrCntType[curCounterSel]].period);
            if (E_OK != errorId)
            {
                break;
            } /* else not needed */
        }
    }
    else
    {
        /* Loop all ewpm counters */
        for (curCounterSel = 0U; curCounterSel < PMW_IP_EPWM_COUNTER_NUMBER; curCounterSel++)
        {
            /* Set epwm counter overflow */
            errorId = Pwm_Ip_SetOverflow(curModule, Pwm_EpwmCntType[curCounterSel],
                    moduleCfgPtr->countCfg[curCounterSel].period);
            if (E_OK != errorId)
            {
                break;
            } /* else not needed */
        }
    }

    return errorId;
}

/** *****************************************************************************************************
 * \brief Set Pwm channel duty initialized configure.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Pwm_Ip_SetDutyInitConfig(
 *                          const Pwm_ModuleType curModule,
 *                          uint8 curChannel,
 *                          const Pwm_ChannelGroupType* channelGroupCfgPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : curModule           - Numeric identifier of the PWM hardware module.
 *                      curChannel          - Numeric identifier of the PWM hardware channel.
 *                      channelGroupCfgPtr  - Point to Pwm channel group configure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set Pwm channel duty initialized configure successful.
 *                      Others  - Set Pwm channel duty initialized configure failed.
 *
 * Description        : Set Pwm channel duty initialized configure.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026 SWSR_PWM_094
 *******************************************************************************************************/
static Std_ReturnType Pwm_Ip_SetDutyInitConfig
(
    const Pwm_ModuleType curModule,
    uint8 curChannel,
    const Pwm_ChannelGroupType* channelGroupCfgPtr
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint16 dutyCycle;
    Pwm_OutputStateType polarity;
    uint8 channelId;
    boolean bothCmpOutput;
    Pwm_CntType counterSelect;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Get channel id, selected counter and compare both out config */
    channelId = channelGroupCfgPtr->channelGroup[curChannel].channelId;
    counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;
    bothCmpOutput = channelGroupCfgPtr->channelGroup[curChannel].bothCmpOutput;
    /* #20 Get subchannel_0 duty cycle and polarity*/
    dutyCycle = channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[0].dutyCycle;
    polarity = channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[0].polarity;

    /* #30 polarity inverse if need */
    if (PWM_HIGH == polarity)
    {
        dutyCycle = PWM_IP_DUTY_100 - dutyCycle;
    } /* else not needed */

    /* #40  Set subchannel_0 duty */
    errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, PWM_IP_SUBCHANNEL_0, dutyCycle);
    if ((E_OK == errorId) && ((boolean)TRUE == bothCmpOutput))
    {
        /* #50 Get subchannel_1 duty cycle and polarity*/
        dutyCycle = channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[1].dutyCycle;
        polarity = channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[1].polarity;

        /* #60 polarity inverse if need */
        if (PWM_HIGH == polarity)
        {
            dutyCycle = PWM_IP_DUTY_100 - dutyCycle;
        } /* else not needed */

        /* #70  Set subchannel_1 duty */
        errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, PWM_IP_SUBCHANNEL_1,
                dutyCycle);
    }
    else
    {
        /* do nothing */
    }

    return errorId;
}

/** *****************************************************************************************************
 * \brief Pwm channel select counter.
 *
 * \verbatim
 * Syntax             : static void Pwm_Ip_SelectCounter(
 *                          uint32 base,
 *                          Pwm_HrdControllerType moduleId,
 *                          uint8 channelId,
 *                          Pwm_CntType counterSelect)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base            - Pwm controller baseAddress.
 *                      moduleId        - Numeric identifier of the controller.
 *                      channelId       - Numeric identifier of the PWM channelId.
 *                      counterSelect   - Type of counter type: PWM_CNT_G0, PWM_CNT_G1,
 *                                        PWM_LCNT_A, PWM_LCNT_B, PWM_LCNT_C, PWM_LCNT_D.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Pwm channel select counter.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_026
 *******************************************************************************************************/
static void Pwm_Ip_SelectCounter
(
    uint32 base,
    Pwm_HrdControllerType moduleId,
    uint8 channelId,
    Pwm_CntType counterSelect
)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 tempAddr;
    uint32 tempValue;

    /* ----- Implementation ----------------------------------------------- */
    /* Channel select counter */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        /* #10 etimer channel select counter */
        tempAddr = base + PWM_IP_ETMR_CMP_CONFIG_N((uint32)channelId);
        tempValue = REG_READ32(tempAddr) & (~(PWM_IP_ETMR_CMP_CNT_SEL_MASK <<
                PWM_IP_ETMR_CMP_CNT_SEL_OFFSET));
        tempValue  |= (PWM_IP_ETMR_CMP_CNT_SEL_LCNT << PWM_IP_ETMR_CMP_CNT_SEL_OFFSET);
        REG_WRITE32(tempValue, tempAddr);
    }
    else
    {
        /* #20 epwm channel select counter */
        tempAddr = base + PWM_IP_EPWM_CMP_CONFIG_N((uint32)channelId);
        tempValue = REG_READ32(tempAddr) & (~(PWM_IP_EPWM_CMP_CNT_SEL_MASK <<
                PWM_IP_EPWM_CMP_CNT_SEL_OFFSET));
        tempValue  |= ((uint32)counterSelect << PWM_IP_EPWM_CMP_CNT_SEL_OFFSET);
        REG_WRITE32(tempValue, tempAddr);
    }
}

/*PRQA S 2755 29*/
/** *****************************************************************************************************
 * \brief PWM IP initialization.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_Init(
 *                          const Pwm_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ConfigPtr   - Pointer to Pwm configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Pwm IP initialization successful.
 *                      Others  - Pwm IP initialization failed.
 *
 * Description        : PWM IP initialization.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_025 SWSR_PWM_026 SWSR_PWM_027 SWSR_PWM_028 SWSR_PWM_029 SWSR_PWM_030
 *                      SWSR_PWM_093 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_Init(const Pwm_ConfigType* ConfigPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    Pwm_HrdControllerType moduleId;
    Pwm_ModuleType moduleNum;
    Pwm_ChannelType channelNum;
    Pwm_ModuleType curModule;
    uint8 curChannel;
    uint8 scrClkSel;
    uint16 dividerNum;
    uint8 channelId;
    uint32 tempAddr;
    uint32 tempValue;
    Pwm_CntType counterSelect;
#if (STD_ON == PWM_DMA_SUPPORTED)
    Pwm_ChannelDmaCfgType dmaCfg;
    boolean enableDma;
#endif /** #if (STD_ON == PWM_DMA_SUPPORTED) */
    const Pwm_HwModuleConfigType* moduleHwCfgPtr;
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set global variable dmaInitSeq and dmaDeinitSeq to 0 */
    coreHandlerPtr->dmaInitSeq = 0;
    coreHandlerPtr->dmaDeinitSeq = 0;
    /* Get module total number */
    moduleNum = ConfigPtr->moduleNum;
    /* Loop all moudles */
    for (curModule = ((uint8)0U); curModule < moduleNum;  curModule++)
    {
        /* Get module configure pointer */
        moduleCfgPtr = &(ConfigPtr->moduleCfgPtr[curModule]);
        /* Check the assign core id */
        if (coreId != moduleCfgPtr->coreId)
        {
            /* core id not match, continue */
            continue;
        } /* else not needed */

        /* Get channel configure pointer and module id */
        channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
        moduleId = moduleCfgPtr->moduleId;

        /* #30 Disable and clear interrupt first */
        Pwm_Ip_DisableAndClearInterrupt(coreHandlerPtr->baseAddr[moduleId], moduleId);

        /* #40 Selectmodule clk and config clock divider */
        moduleHwCfgPtr = &(ConfigPtr->moduleHwCfgPtr[curModule]);
        scrClkSel = moduleHwCfgPtr->scrClkSel;
        dividerNum = moduleHwCfgPtr->dividerNum;
        errorId = Pwm_Ip_ConfigClock(coreHandlerPtr->baseAddr[moduleId], scrClkSel, dividerNum);
        if (E_OK == errorId)
        {
            /* #50 Set counters initialized confugure value */
            errorId = Pwm_Ip_SetOverflowInitConfig(moduleId, curModule, moduleCfgPtr);
        } /* else not needed */

        if (E_OK == errorId)
        {
            /* Get channel total number */
            channelNum = moduleCfgPtr->channelNum;
            /* Loop all channels */
            for (curChannel = ((uint8)0U); curChannel < channelNum; curChannel++)
            {
                /* Get channel id and selected counter */
                channelId = channelGroupCfgPtr->channelGroup[curChannel].channelId;
                counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;

                /* #501 Disable correctable and uncorrectable interrupt. */
                /* Disable correctable interrupt status enable register */
                tempValue = REG_READ32(coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_COR_ERR_INT_STA_EN);
                tempValue = tempValue & (~PWM_IP_COR_ERR_CMP_N_REG_NO_UPD_EN(channelId))
                                      & (~PWM_IP_COR_ERR_CMP_N_REG_UPD_TWICE_EN(channelId));
                REG_WRITE32(tempValue, (coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_COR_ERR_INT_STA_EN));
                /* Disable correctable interrupt status signal register */
                tempValue = REG_READ32(coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_COR_ERR_INT_SIG_EN);
                tempValue = tempValue & (~PWM_IP_COR_ERR_CMP_N_REG_NO_UPD_SIG(channelId))
                                      & (~PWM_IP_COR_ERR_CMP_N_REG_UPD_TWICE_SIG(channelId));
                REG_WRITE32(tempValue, (coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_COR_ERR_INT_SIG_EN));
                /* Disable uncorrectable interrupt status enable register */
                tempValue = REG_READ32(coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_UNC_ERR_INT_STA_EN);
                tempValue = tempValue & (~PWM_IP_UNC_ERR_CMP_N_REG_NO_UPD_EN(channelId))
                                      & (~PWM_IP_UNC_ERR_CMP_N_REG_UPD_TWICE_EN(channelId));
                REG_WRITE32(tempValue, (coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_UNC_ERR_INT_STA_EN));
                /* Disable uncorrectable interrupt status signal register */
                tempValue = REG_READ32(coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_UNC_ERR_INT_SIG_EN);
                tempValue = tempValue & (~PWM_IP_UNC_ERR_CMP_N_REG_NO_UPD_SIG(channelId))
                                      & (~PWM_IP_UNC_ERR_CMP_N_REG_UPD_TWICE_SIG(channelId));
                REG_WRITE32(tempValue, (coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_UNC_ERR_INT_SIG_EN));

                /* #502 Clear correctable and uncorrectable status. */
                /* Read out correctable interrupt status register */
                tempValue = REG_READ32(coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_COR_ERR_INT_STA);
                tempValue = tempValue & (PWM_IP_COR_ERR_CMP_N_REG_NO_UPD_STA(channelId)
                                      | PWM_IP_COR_ERR_CMP_N_REG_UPD_TWICE_STA(channelId));
                /* Clear correctable interrupt status register */
                REG_WRITE32(tempValue, (coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_COR_ERR_INT_STA));
                /* Read out uncorrectable interrupt status register */
                tempValue = REG_READ32(coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_UNC_ERR_INT_STA);
                tempValue = tempValue & (PWM_IP_UNC_ERR_CMP_N_REG_NO_UPD_STA(channelId)
                                      | PWM_IP_UNC_ERR_CMP_N_REG_UPD_TWICE_STA(channelId));
                /* Clear uncorrectable interrupt status register */
                REG_WRITE32(tempValue, (coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_UNC_ERR_INT_STA));

                /* channel select counter */
                Pwm_Ip_SelectCounter(coreHandlerPtr->baseAddr[moduleId], moduleId, channelId,
                        counterSelect);

                /* #60 Config DMA or set duty initialized confugure */
    #if (STD_ON == PWM_DMA_SUPPORTED)
                /* Get DMA enable confugure */
                enableDma = channelGroupCfgPtr->channelGroup[curChannel].dmaCfg.enableDma;
                if ((boolean)TRUE == enableDma)
                {
                    /* DMA struct variable assignment */
                    dmaCfg.enableDma = enableDma;
                    dmaCfg.fifoWml = channelGroupCfgPtr->channelGroup[curChannel].dmaCfg.fifoWml;
                    dmaCfg.totalNum = channelGroupCfgPtr->channelGroup[curChannel].dmaCfg.totalNum;
                    dmaCfg.srcDataPtr = channelGroupCfgPtr->channelGroup[curChannel].dmaCfg.srcDataPtr;

                    /* DMA upload cmp value  */
                    errorId = Pwm_Ip_ConfigDmaChannel(coreHandlerPtr->baseAddr[moduleId], moduleId,
                            channelId, &dmaCfg);
                    if (E_OK == errorId)
                    {
                        /* Set fifo water mark level */
                        Pwm_Ip_SetDmaWatermarkLevel(coreHandlerPtr->baseAddr[moduleId], moduleId, channelId,
                                                dmaCfg.fifoWml);

                        /* Enable dma with pwm channel */
                        tempAddr = coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_CHN_DMA_CTRL_REG;
                        tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_CORE_CHN_DMA_EN_OFFSET(channelId));
                        REG_WRITE32(tempValue, tempAddr);
                    } /* else not needed */
                }
                else
    #endif /** #if (STD_ON == PWM_DMA_SUPPORTED) */
                {
                    /* Set Pwm channel duty initialized value. */
                    errorId = Pwm_Ip_SetDutyInitConfig(curModule, curChannel, channelGroupCfgPtr);
                }

                if (E_OK != errorId)
                {
                    break;
                } /* else not needed */

                /* #70 Configure select */
                Pwm_Ip_SetCompareInitConfig(coreHandlerPtr->baseAddr[moduleId], curChannel,
                        moduleCfgPtr, channelGroupCfgPtr);

                /* #80 Set compare enable */
                tempAddr = coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_CMP_CTRL_REG;
                tempValue = REG_READ32(tempAddr) | (1UL << PWM_IP_CORE_CMP_EN_OFFSET(channelId));
                REG_WRITE32(tempValue, tempAddr);
            }
        }

        if (E_OK != errorId)
        {
            /* Error during initialization, break */
            break;
        } /* else not needed */

        /* #90 Enabled counters */
        Pwm_Ip_SetCounterEnable(moduleId);
    }

    return errorId;
}

#if (STD_ON == PWM_DE_INIT_API)
/** *****************************************************************************************************
 * \brief PWM IP de-initialization.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_Deinit(void)
 *
 * Service ID[hex]    : None
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
 * Return value       : E_OK    - Pwm IP de-initialization successful.
 *                      Others  - Pwm IP de-initialization failed.
 *
 * Description        : PWM IP de-initialization.
 *                      This function is available if the PWM_DE_INIT_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_036 SWSR_PWM_037 SWSR_PWM_038 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_Deinit(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    Pwm_HrdControllerType moduleId;
    Pwm_ModuleType moduleNum;
    Pwm_ModuleType curModule;
    Pwm_ChannelType channelNum;
    Pwm_ChannelType curChannel;
    uint8 channelId;
    boolean bothCmpOutput;
    Pwm_CntType counterSelect;
    Pwm_OutputStateType idleStatus[2];
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType* coreHandlerPtr = Pwm_HandlerPtr[coreId];
#if (STD_ON == PWM_DMA_SUPPORTED)
    uint32 tempAddr;
    uint32 tempValue;
    boolean enableDma;
    Dma_ChannelConfigType* chan;
#endif /** #if (STD_ON == PWM_DMA_SUPPORTED) */
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* Get module total number */
    moduleNum = configPtr->moduleNum;
    /* Loop all moudles */
    for (curModule = ((uint8)0U); curModule < moduleNum; curModule++)
    {
        /* #20 Get module configure pointer */
        moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
        /* Check the assign core id */
        if (coreId != moduleCfgPtr->coreId)
        {
            /* core id not match, continue */
            continue;
        } /* else not needed */

        /* Get channel configure pointer, module id and channel number */
        channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
        moduleId = moduleCfgPtr->moduleId;
        channelNum = moduleCfgPtr->channelNum;
        /* Loop all channels */
        for (curChannel = ((uint8)0U); curChannel < channelNum; curChannel++)
        {
            /* Get channel id */
            channelId = channelGroupCfgPtr->channelGroup[curChannel].channelId;
#if (STD_ON == PWM_DMA_SUPPORTED)
            /* Get DMA enable confugure */
            enableDma = channelGroupCfgPtr->channelGroup[curChannel].dmaCfg.enableDma;

            if ((boolean)TRUE == enableDma)
            {
                /* #30 Disable compare interrupt */
                if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
                {
                    /* Disable etimer compare interrupt */
                    Pwm_Ip_SetStaSigInt(coreHandlerPtr->baseAddr[moduleId],
                            PWM_IP_ETMR_INT_CMP_EN(channelId),
                            PWM_IP_ETMR_INT_CMP_EN(channelId), (boolean)FALSE);
                }
                else
                {
                    /* Disable epwm compare interrupt */
                    Pwm_Ip_SetStaSigInt(coreHandlerPtr->baseAddr[moduleId],
                            PWM_IP_EPWM_INT_CMP_EN(channelId),
                            PWM_IP_EPWM_INT_CMP_EN(channelId), (boolean)FALSE);
                }

                /*PRQA S 0306  1*/
                chan = (Dma_ChannelConfigType *)(coreHandlerPtr->dmaChannel[coreHandlerPtr->dmaDeinitSeq]);
                coreHandlerPtr->dmaDeinitSeq++;
                if (E_OK != Dma_Stop(chan))
                {
                    errorId = PWM_E_CONFIG_DMA_CHANNEL;
                }
                else if (E_OK != Dma_ReleaseChannel(chan))
                {
                    errorId = PWM_E_CONFIG_DMA_CHANNEL;
                }
                else
                {
                    /* #40 Disable dma with pwm channel */
                    tempAddr = coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_CHN_DMA_CTRL_REG;
                    tempValue = REG_READ32(tempAddr) & (~(PWM_IP_CORE_CHN_DMA_EN_MASK <<
                            PWM_IP_CORE_CHN_DMA_EN_OFFSET(channelId)));
                    REG_WRITE32(tempValue, tempAddr);

                    /* #50 Disable compare */
                    tempAddr = coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_CMP_CTRL_REG;
                    tempValue = REG_READ32(tempAddr) & (~(PWM_IP_CORE_CMP_EN_MASK <<
                            PWM_IP_CORE_CMP_EN_OFFSET(channelId)));
                    REG_WRITE32(tempValue, tempAddr);

                    /* #60 Clear remaining fifo value */
                    Pwm_Ip_ClearFifo(coreHandlerPtr->baseAddr[moduleId], moduleId, channelId);
                }
            }
            else
#endif /** #if (STD_ON == PWM_DMA_SUPPORTED) */
            {
                /* Get select counter, both compare output config and idle status configure */
                bothCmpOutput = channelGroupCfgPtr->channelGroup[curChannel].bothCmpOutput;
                counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;
                idleStatus[0] =
                    channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[0].idleStatus;
                idleStatus[1] =
                    channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[1].idleStatus;
                /* #70 Set output deinit state */
                errorId = Pwm_Ip_SetOutputDeinitState(curModule, counterSelect, channelId,
                        bothCmpOutput, idleStatus);
            }

            if (E_OK != errorId)
            {
                break;
            } /* else not needed */
        }

        if (E_OK != errorId)
        {
            /* Error during de-initialization, break */
            break;
        } /* else not needed */

        /* #80 Disable interrupt and clear interrupt status */
        Pwm_Ip_DisableAndClearInterrupt(coreHandlerPtr->baseAddr[moduleId], moduleId);
    }

    return errorId;
}
#endif /** #if (STD_ON == PWM_DE_INIT_API) */

#if (STD_ON == PWM_SET_DUTY_CYCLE_API)
/** *****************************************************************************************************
 * \brief Set the duty cycle of the PWM channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_SetDutyCycle(
 *                          Pwm_ChannelType channelNumber,
 *                          uint16 dutyCycle)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber   - Numeric identifier of the PWM channel.
 *                      dutyCycle       - The duty of the PWM channel., Min=0x0000 Max=0x8000.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set duty cycle successful.
 *                      Others  - Set duty cycle failed.
 *
 * Description        : Set the duty cycle of the PWM channel.
 *                      This function is available if the PWM_SET_DUTY_CYCLE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_015 SWSR_PWM_042 SWSR_PWM_043 SWSR_PWM_044
 *                      SWSR_PWM_045 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_SetDutyCycle(Pwm_ChannelType channelNumber, uint16 dutyCycle)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    Pwm_ModuleType curModule = 0x0U;
    Pwm_ChannelType curChannel = 0x0U;
    uint8 subChannel = 0;
    Pwm_OutputStateType polarity;
    uint8 channelId;
    Pwm_CntType counterSelect;
    uint16 dutyValue = dutyCycle;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get right moduleid and channel */
    Pwm_Ip_GetHardwareChannel(channelNumber, &curModule, &curChannel, &subChannel);
    /* #30 Get module configure point, cahnnel configure point, polarity, channel id, counter */
    moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
    channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
    polarity = channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[subChannel].polarity;
    channelId = channelGroupCfgPtr->channelGroup[curChannel].channelId;
    counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;

    /* #40 polarity inverse if need */
    if (PWM_HIGH == polarity)
    {
        dutyValue = PWM_IP_DUTY_100 - dutyValue;
    } /* else not needed */

    /* #50 Set channel duty */
    errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, subChannel, dutyValue);

    return errorId;
}
#endif /** #if (STD_ON == PWM_SET_DUTY_CYCLE_API) */

#if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API)
/** *****************************************************************************************************
 * \brief Set the period and the duty cycle of the PWM channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_SetPeriodAndDuty(
 *                          Pwm_ChannelType channelNumber,
 *                          Pwm_PeriodType period,
 *                          uint16 dutyCycle)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber   - Numeric identifier of the PWM channel.
 *                      period          - Period of the PWM signal.
 *                      dutyCycle       - The duty of the PWM channel., Min=0x0000 Max=0x8000.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set period and the duty cycle successful.
 *                      Others  - Set period and the duty cycle failed.
 *
 * Description        : Set the period and the duty cycle of the PWM channel.
 *                      This function is available if the PWM_SET_PERIOD_AND_DUTY_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_015 SWSR_PWM_043 SWSR_PWM_044 SWSR_PWM_045
 *                      SWSR_PWM_050 SWSR_PWM_051 SWSR_PWM_056 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_SetPeriodAndDuty
(
    Pwm_ChannelType channelNumber,
    Pwm_PeriodType period,
    uint16 dutyCycle
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = E_OK;
    Pwm_ModuleType curModule = 0x0U;
    Pwm_ChannelType curChannel = 0x0U;
    uint8 subChannel = 0;
    Pwm_OutputStateType polarity;
    uint8 channelId;
    Pwm_CntType counterSelect;
    uint16 dutyValue = dutyCycle;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get right moduleid and channel */
    Pwm_Ip_GetHardwareChannel(channelNumber, &curModule, &curChannel, &subChannel);
    /* #30 Get module configure point, cahnnel configure point, polarity, channel id, counter */
    moduleCfgPtr = &(coreHandlerPtr->configPtr->moduleCfgPtr[curModule]);
    channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
    counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;
    channelId = channelGroupCfgPtr->channelGroup[curChannel].channelId;
    polarity = channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[subChannel].polarity;

    /* #40 Check channel class */
    if (PWM_VARIABLE_PERIOD == moduleCfgPtr->countCfg[counterSelect].channelClass)
    {
        /* #50 Set duty cycle and period */
        if (period > 0U)
        {
            /* Set counter overflow */
            errorId = Pwm_Ip_SetOverflow(curModule, counterSelect, period);
            if (E_OK == errorId)
            {
                /* Polarity inverse if need */
                if (PWM_HIGH == polarity)
                {
                    dutyValue = PWM_IP_DUTY_100 - dutyValue;
                } /* else not needed */

                /* Set channel duty cycle */
                errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, subChannel,
                        dutyValue);
            }
        }
        else
        {
            /* Polarity inverse if need */
            if (PWM_HIGH == polarity)
            {
                /* Set channel duty cycle */
                errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, subChannel,
                        PWM_IP_DUTY_100);
            }
            else
            {
                /* Set channel duty cycle */
                errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, subChannel,
                        PWM_IP_DUTY_0);
            }
        }
    } /* else not needed */

    return errorId;
}
#endif /** #if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API) */

#if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API)
/** *****************************************************************************************************
 * \brief Set PWM channel output status to idle.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_SetOutputToIdle(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set PWM channel output status to idle successful.
 *                      Others  - Set PWM channel output status to idle failed.
 *
 * Description        : Set PWM channel output status to idle.
 *                      This function is available if the PWM_SET_OUTPUT_TO_IDLE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_057 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_SetOutputToIdle
(
    Pwm_ChannelType channelNumber
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    Pwm_ModuleType curModule = 0x0U;
    Pwm_ChannelType curChannel = 0x0U;
    uint8 subChannel = 0;
    uint8 channelId;
    Pwm_CntType counterSelect;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get right moduleid and channel */
    Pwm_Ip_GetHardwareChannel(channelNumber, &curModule, &curChannel, &subChannel);
    /* #30 Get module configure point, cahnnel configure point, channel id, counter */
    moduleCfgPtr = &(coreHandlerPtr->configPtr->moduleCfgPtr[curModule]);
    channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
    channelId = channelGroupCfgPtr->channelGroup[curChannel].channelId;
    counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;

    /* #40 Set channel output idle state */
    if (PWM_HIGH ==
        channelGroupCfgPtr->channelGroup[curChannel].subChannelGroup[subChannel].idleStatus)
    {
        /* Set channel duty */
        errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, subChannel, PWM_IP_DUTY_0);
    }
    else
    {
        /* Set channel duty */
        errorId = Pwm_Ip_SetDuty(curModule, counterSelect, channelId, subChannel, PWM_IP_DUTY_100);
    }

    return errorId;
}
#endif /** #if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API) */

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
/** *****************************************************************************************************
 * \brief Disable notification of PWM channel.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_DisableNotification(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Disable notification of PWM channel.
 *                      This function is available if the PWM_NOTIFICATION_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_080
 *******************************************************************************************************/
void Pwm_Ip_DisableNotification(Pwm_ChannelType channelNumber)
{
    /* ----- Local Variables ---------------------------------------------- */
    Pwm_ModuleType curModule = 0x0U;
    Pwm_ChannelType curChannel = 0x0U;
    uint8 subChannel = 0;
    uint32 disValue;
    Pwm_HrdControllerType moduleId;
    uint32 channelId;
    uint32 counterSelect;
    uint32 etmrCounter;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get right moduleid and channel */
    Pwm_Ip_GetHardwareChannel(channelNumber, &curModule, &curChannel, &subChannel);
    /* #30 Get module configure point, cahnnel configure point, module id, channel id, counter */
    moduleCfgPtr = &(coreHandlerPtr->configPtr->moduleCfgPtr[curModule]);
    moduleId = moduleCfgPtr->moduleId;
    channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
    channelId = (uint32)channelGroupCfgPtr->channelGroup[curChannel].channelId;
    counterSelect = (uint32)channelGroupCfgPtr->channelGroup[curChannel].counterSelect;

    /* #40 Disable interrupt */
    if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
    {
        /* Disable etimer interrupt */
        etmrCounter = counterSelect - (uint32)PWM_LCNT_A;
        disValue = PWM_IP_ETMR_INT_CMP_EN(channelId)
                | PWM_IP_ETMR_INT_CNT_OVF_EN(etmrCounter);
    }
    else
    {
        /* Disable epwm interrupt */
        disValue = PWM_IP_EPWM_INT_CMP_EN(channelId)
                | PWM_IP_EPWM_INT_CNT_OVF_EN(counterSelect);
    }
    /* #50 Disable status and signal interrupt */
    Pwm_Ip_SetStaSigInt(coreHandlerPtr->baseAddr[moduleId], disValue, disValue, (boolean)FALSE);
    /* #60 Clear interrupt status */
    Pwm_Ip_ClearIntStatus(coreHandlerPtr->baseAddr[moduleId]);
}
#endif /** #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
/** *****************************************************************************************************
 * \brief Enable notification of PWM channel.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_EnableNotification(
 *                          Pwm_ChannelType channelNumber,
 *                          Pwm_EdgeNotificationType notification)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Enable notification of PWM channel.
 *                      This function is available if the PWM_NOTIFICATION_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_073 SWSR_PWM_074 SWSR_PWM_080
 *******************************************************************************************************/
void Pwm_Ip_EnableNotification
(
    Pwm_ChannelType channelNumber,
    Pwm_EdgeNotificationType notification
)
{
    /* ----- Local Variables ---------------------------------------------- */
    Pwm_ModuleType curModule = 0x0U;
    Pwm_ChannelType curChannel = 0x0U;
    uint8 subChannel = 0;
    Pwm_HrdControllerType moduleId;
    Pwm_CntType counterSelect;
    uint32 etmrCounter;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get right moduleid and channel */
    Pwm_Ip_GetHardwareChannel(channelNumber, &curModule, &curChannel, &subChannel);
    /* #30 Get module configure point, cahnnel configure point, module id, counter */
    moduleCfgPtr = &(coreHandlerPtr->configPtr->moduleCfgPtr[curModule]);
    moduleId = moduleCfgPtr->moduleId;
    channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
    counterSelect = channelGroupCfgPtr->channelGroup[curChannel].counterSelect;

    /* #40 Enable counter overflow interrupt */
    /* Notification only support falling edge */
    if (PWM_FALLING_EDGE == notification)
    {
        if ((boolean)TRUE == Pwm_Ip_IsEtimerModule(moduleId))
        {
            /* Enable etimer counter overflow interrupt */
            etmrCounter = (uint32)counterSelect - (uint32)PWM_LCNT_A;
            Pwm_Ip_SetStaSigInt(coreHandlerPtr->baseAddr[moduleId],
                    PWM_IP_ETMR_INT_CNT_OVF_EN(etmrCounter),
                    PWM_IP_ETMR_INT_CNT_OVF_EN(etmrCounter), (boolean)TRUE);
        }
        else
        {
            /* Enable epwm counter overflow interrupt */
            Pwm_Ip_SetStaSigInt(coreHandlerPtr->baseAddr[moduleId],
                    PWM_IP_EPWM_INT_CNT_OVF_EN((uint32)counterSelect),
                    PWM_IP_EPWM_INT_CNT_OVF_EN((uint32)counterSelect), (boolean)TRUE);
        }
    } /* else not needed */
}
#endif /** #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

#if (STD_ON == PWM_GET_OUTPUT_STATE_API)
/** *****************************************************************************************************
 * \brief Get output status of PWM channel.
 *
 * \verbatim
 * Syntax             : Pwm_OutputStateType Pwm_Ip_GetOutputState(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : PWM_LOW     - The PWM channel is in low state.
 *                      PWM_HIGH    - The PWM channel is in high state.
 *
 * Description        : Get output status of PWM channel.
 *                      This function is available if the PWM_GET_OUTPUT_STATE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_067
 *******************************************************************************************************/
Pwm_OutputStateType Pwm_Ip_GetOutputState(Pwm_ChannelType channelNumber)
{
    /* ----- Local Variables ---------------------------------------------- */
    Pwm_ModuleType curModule = 0x0U;
    Pwm_ChannelType curChannel = 0x0U;
    uint8 subChannel = 0;
    Pwm_HrdControllerType moduleId;
    uint8 channelId;
    uint32 signalStatus;
    uint32 bitStatus;
    Pwm_OutputStateType outputStatus;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Get right moduleid and channel */
    Pwm_Ip_GetHardwareChannel(channelNumber, &curModule, &curChannel, &subChannel);
    /* #30 Get module configure point, cahnnel configure point, module id, channel id */
    moduleCfgPtr = &(coreHandlerPtr->configPtr->moduleCfgPtr[curModule]);
    moduleId = moduleCfgPtr->moduleId;
    channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
    channelId = channelGroupCfgPtr->channelGroup[curChannel].channelId;
    /* #40 Read signal status register */
    signalStatus = REG_READ32(coreHandlerPtr->baseAddr[moduleId] + PWM_IP_CORE_SIGNAL_STATUS_REG)
            & PWM_IP_CORE_COMPARE_SIGNAL_MASK;
    /* #50 Calculated output bit status */
    bitStatus = (signalStatus >> ((channelId * PWM_IP_CORE_COM_SIG_CHANNEL_GAP) + subChannel))
            & 0x1U;
    if (0U == bitStatus)
    {
        outputStatus = PWM_LOW;
    }
    else
    {
        outputStatus = PWM_HIGH;
    }

    return outputStatus;
}
#endif /** #if (STD_ON == PWM_GET_OUTPUT_STATE_API) */

/** *****************************************************************************************************
 * \brief PWM interrupt handler.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_Irq(
 *                          Pwm_HrdControllerIrqType hardController)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hardController - Pwm controller irq index: PWM1_MODULE_IRQ_INDEX,
 *                                       PWM2_MODULE_IRQ_INDEX, PWM3_MODULE_IRQ_INDEX,
 *                                       PWM4_MODULE_IRQ_INDEX, PWM5_MODULE_IRQ_INDEX,
 *                                       PWM6_MODULE_IRQ_INDEX, PWM7_MODULE_IRQ_INDEX,
 *                                       PWM8_MODULE_IRQ_INDEX.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : PWM interrupt handler, clear irq status and call notification function.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_089 SW_SM003 SW_SM004
 *******************************************************************************************************/
void Pwm_Ip_Irq(Pwm_HrdControllerIrqType hardController)
{
    /* ----- Local Variables ---------------------------------------------- */
    Pwm_ModuleType curModule;
    Pwm_ModuleType moduleNum;
    Pwm_HrdControllerType moduleId = EPWM1_MODULE_INDEX;
    uint32 moduleBaseAddr;
    boolean checkIrq = FALSE;
    uint32 controlId = (uint32)hardController;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Check Pwm init state */
    if (PWM_STATE_INIT != coreHandlerPtr->globalState)
    {
        /* #30 Disable and clear pwm interrupt */
        moduleBaseAddr = PWM_IP_EPWM1_BASE + (PWM_IP_MODULE_ADDR_GAP * controlId);
        Pwm_Ip_DisableAndClearInterrupt(moduleBaseAddr, Pwm_HrdControl[controlId]);
    }
    else
    {
        /* Get module total number */
        moduleNum = configPtr->moduleNum;
        /* Loop all moudles */
        for (curModule = ((uint8)0U);  curModule < moduleNum;  curModule++)
        {
            /* #40 Get module configure pointer and module id */
            moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
            moduleId = moduleCfgPtr->moduleId;
            /* #50 Accord module base address find the right Pwm module */
            if ((coreHandlerPtr->baseAddr[0] + (PWM_IP_MODULE_ADDR_GAP * controlId)) ==
                    coreHandlerPtr->baseAddr[moduleId])
            {
                /* #60 Check the IRQ enable and status is set or not */
                checkIrq = Pwm_Ip_IrqCheck(coreHandlerPtr->baseAddr[moduleId], moduleId);
                break;
            } /* else not needed */
        }

        /* #70 Clear interrupt status */
        Pwm_Ip_ClearIntStatus(coreHandlerPtr->baseAddr[moduleId]);

        if ((boolean)TRUE == checkIrq)
        {
            /* #80 Check notification in module configure point */
            if (NULL_PTR != moduleCfgPtr->notificationPtr)
            {
                /* #90 Call notification callback function */
                moduleCfgPtr->notificationPtr();
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */
}

/** *****************************************************************************************************
 * \brief Get the core id assigned by the PWM channel.
 *
 * \verbatim
 * Syntax             : Pwm_CoreIdType Pwm_Ip_GetModuleAssignCoreId(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Core ID - 0:sf 1:sx0 2:sx1 3:sp0 4:sp1.
 *
 * Description        : Get the core id assigned by the PWM channel.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007
 *******************************************************************************************************/
Pwm_CoreIdType Pwm_Ip_GetModuleAssignCoreId(Pwm_ChannelType channelNumber)
{
    /* ----- Local Variables ---------------------------------------------- */
    boolean channelFound = (boolean)FALSE;
    Pwm_ModuleType moduleNum;
    Pwm_ChannelType channelNum;
    Pwm_ChannelType subChannelNum;
    Pwm_ModuleType curModule;
    Pwm_ChannelType curChannel;
    Pwm_ChannelType curSubChannel;
    Pwm_ChannelType logicChannel = 0U;
    /* #10 Get core id and pwm handler */
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];
    const Pwm_ModuleConfigType* moduleCfgPtr = NULL_PTR;
    const Pwm_ChannelGroupType* channelGroupCfgPtr;
    const Pwm_ConfigType* configPtr = coreHandlerPtr->configPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* Get module total number */
    moduleNum = configPtr->moduleNum;
    /* Loop all moudles */
    for (curModule = ((uint8)0U);  ((curModule < moduleNum) && (FALSE == channelFound));
            curModule++)
    {
        /* #20 Get module configure pointer and channel configure pointer */
        moduleCfgPtr = &(configPtr->moduleCfgPtr[curModule]);
        channelGroupCfgPtr = moduleCfgPtr->channelGroupCfgPtr;
        /* Get channel total number */
        channelNum = moduleCfgPtr->channelNum;
        /* Loop all channels */
        for (curChannel = ((uint8)0U); curChannel < channelNum; curChannel++)
        {
            /* Get subchannel total number */
            if ((boolean)TRUE == channelGroupCfgPtr->channelGroup[curChannel].bothCmpOutput)
            {
                subChannelNum = 2;
            }
            else
            {
                subChannelNum = 1;
            }
            /* Loop all subchannels */
            for (curSubChannel = ((uint8)0U); curSubChannel < subChannelNum;
                 curSubChannel++)
            {
                logicChannel++;
                /* #30 Find the right channel */
                if (channelNumber == logicChannel)
                {
                    /* Find the right channel, break */
                    channelFound = (boolean)TRUE;
                    break;
                } /* else not needed */
            }

            if ((boolean)TRUE == channelFound)
            {
                /* Find the right channel, break */
                break;
            } /* else not needed */
        }
    }

    /* #40 Check module configure point */
    if (NULL_PTR != moduleCfgPtr)
    {
        /* #50 assignment coreId */
        coreId = moduleCfgPtr->coreId;
    } /* else not needed */

    return coreId;
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
