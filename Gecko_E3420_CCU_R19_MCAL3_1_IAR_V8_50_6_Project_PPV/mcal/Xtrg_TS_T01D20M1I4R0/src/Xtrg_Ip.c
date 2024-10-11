/** **************************************************************************************
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 * \file     Xtrg_Ip.c
 * \brief    AUTOSAR 4.3.1 MCAL can Driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/08/04     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Xtrg.h"
#include "Xtrg_Ip.h"
#include "RegHelper.h"
#include "Xtrg_Fault.h"
#include "Mcal.h"
/*****************************************************************************************
 *                    Global Constant Declarations
 *****************************************************************************************/
#define XTRG_START_SEC_CONST_UNSPECIFIED
#include "Xtrg_MemMap.h"
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief  signal index in different mux */
static const Xtrg_SignalIndexType IndexInDiffMux[XTRG_SIG_GROUP_CNT] =
{
    /** \brief  signal index in swt signal input group */
    /** \brief  signal index in swt signal input group */
    [XTRG_SWT_INPUT_GROUP] =
    {
        .sigNumber = SWT_I_NUMBER,
        .ssigNumber = 0U,
        .syncmuxNumber = 0U,
    },
    /** \brief  signal index in trigger signal input group */
    [XTRG_TRG_INPUT_GROUP] =
    {
        .sigNumber = TRG_I_NUMBER,
        .ssigNumber = 8U,
        .smuxNumber = 84U,
    },
    /** \brief  signal index in normal signal input group */
    [XTRG_SIG_INPUT_GROUP] =
    {
        .sigNumber = SIG_I_NUMBER,
        .ssigNumber = 16U,
        .smuxNumber = 16U,
    },
    /** \brief  signal index in sync signal input group */
    [XTRG_SYNC_INPUT_GROUP] =
    {
        .sigNumber = SYNC_I_NUMBER,
        .ssigNumber = 84U,
        .syncmuxNumber = 24U,
    },
    /** \brief  signal index in i/o signal input group */
    [XTRG_IO_INPUT_GROUP] =
    {
        .sigNumber = IO_I_NUMBER,
        .ssigNumber = 104U,
        .smuxNumber = 92U,
    },
    /** \brief  signal index in trigger id signal input group */
    [XTRG_TID_INPUT_GROUP] =
    {
        .sigNumber = TID_I_NUMBER,
    },
    /** \brief  signal index in normal signal output group */
    [XTRG_SIG_OUTPUT_GROUP] =
    {
        .sigNumber = SIG_O_NUMBER,
    },
    /** \brief  signal index in i/o signal output group */
    [XTRG_IO_OUTPUT_GROUP] =
    {
        .sigNumber = IO_O_NUMBER,
    },
    /** \brief  signal index in sync signal output group */
    [XTRG_SYNC_OUTPUT_GROUP] =
    {
        .sigNumber = SYNC_O_NUMBER,
    },
    /** \brief  signal index in signal matrix signal output group */
    [XTRG_SSIG_OUTPUT_GROUP] =
    {
        .sigNumber = SSIG_NUMBER,
        .smuxNumber = 0U,
        .syncmuxNumber = 8U,
    },
};
#else
/** \brief  signal index in different mux */
static const Xtrg_SignalIndexType IndexInDiffMux[XTRG_SIG_GROUP_CNT] =
{
    /** \brief  signal index in swt signal input group */
    [XTRG_SWT_INPUT_GROUP] =
    {
        .sigNumber = SWT_I_NUMBER,
        .ssigNumber = 0U,
        .syncmuxNumber = 0U,
    },
    /** \brief  signal index in trigger signal input group */
    [XTRG_TRG_INPUT_GROUP] =
    {
        .sigNumber = TRG_I_NUMBER,
        .ssigNumber = 8U,
        .smuxNumber = 54U,
    },
    /** \brief  signal index in normal signal input group */
    [XTRG_SIG_INPUT_GROUP] =
    {
        .sigNumber = SIG_I_NUMBER,
        .ssigNumber = 12U,
        .smuxNumber = 16U,
    },
    /** \brief  signal index in sync signal input group */
    [XTRG_SYNC_INPUT_GROUP] =
    {
        .sigNumber = SYNC_I_NUMBER,
        .ssigNumber = 50U,
        .syncmuxNumber = 24U,
    },
    /** \brief  signal index in i/o signal input group */
    [XTRG_IO_INPUT_GROUP] =
    {
        .sigNumber = IO_I_NUMBER,
        .ssigNumber = 60U,
        .smuxNumber = 58U,
    },
    /** \brief  signal index in trigger id signal input group */
    [XTRG_TID_INPUT_GROUP] =
    {
        .sigNumber = TID_I_NUMBER,
    },
    /** \brief  signal index in normal signal output group */
    [XTRG_SIG_OUTPUT_GROUP] =
    {
        .sigNumber = SIG_O_NUMBER,
    },
    /** \brief  signal index in i/o signal output group */
    [XTRG_IO_OUTPUT_GROUP] =
    {
        .sigNumber = IO_O_NUMBER,
    },
    /** \brief  signal index in sync signal output group */
    [XTRG_SYNC_OUTPUT_GROUP] =
    {
        .sigNumber = SYNC_O_NUMBER,
    },
    /** \brief  signal index in signal matrix signal output group */
    [XTRG_SSIG_OUTPUT_GROUP] =
    {
        .sigNumber = SSIG_NUMBER,
        .smuxNumber = 0U,
        .syncmuxNumber = 8U,
    },
};
#endif
#define XTRG_STOP_SEC_CONST_UNSPECIFIED
#include "Xtrg_MemMap.h"
#define XTRG_START_SEC_CODE
#include "Xtrg_MemMap.h"
/** **************************************************************************************
 * \brief This function is used to modified xtrg register.

 * \verbatim
 * Syntax             : static void Xtrg_WriteRegister(
 *                          volatile uint32 address,
 *                          uint8 startBit,
 *                          uint8 bitWidth,
 *                          uint32 value)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : address - Xtrg register address
 *                      startBit - start bit of target register
 *                      bitWidth - the width which is ready to modify
 *                      value - the target value which is ready to write into register

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used to modified xtrg register.
 * \endverbatim
 *****************************************************************************************/
static void Xtrg_WriteRegister(volatile uint32 address, uint8 startBit, uint8 bitWidth,
                               uint32 value)
{
    /* #10 get register current value */
    uint32 tempValue = *((volatile uint32 *)(address));
    /* #20 reset bit field which is ready to modify */
    tempValue &= ~(((uint32)(1UL << bitWidth) - 1UL) << startBit);
    /* #30 modify tartge bit field */
    tempValue |= (value << startBit) & (((uint32)(1UL << bitWidth) - 1UL) << startBit);
    /* #40 writer register */
    *((volatile uint32 *)(address)) = tempValue;
    return;
}

/** **************************************************************************************
 * \brief This function is used for generating specific Xtrg software trigger event or
 *          pulse in IP level.

 * \verbatim
 * Syntax             : Xtrg_ErrorIdType Xtrg_Ip_SoftwareTrigger(volatile uint32 base,
 *                          const Xtrg_SWTriggerType *ipSoftwareTrigCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipSoftwareTrigCfg - Xtrg software trigger configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : errorId: Xtrg error id

 * Description        : This function is used for generating specific Xtrg software
 *                      trigger event or pulse in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_014
 *****************************************************************************************/
Xtrg_ErrorIdType Xtrg_Ip_SoftwareTrigger(volatile uint32 base,
        const Xtrg_SWTriggerType *ipSoftwareTrigCfg)
{
    /* xtrg error id */
    Xtrg_ErrorIdType errorId;
    /* the time of reading register */
    uint16 readTime = 0U;

    /* #10 readl register to confrim last trigger is done */
    for (; readTime < XTRG_SWT_POLLING_TIME; readTime++)
    {
        /* last trigger is done */
        if (0U == readl(base + XTRG_SW_TRG_CTRL))
        {
            /* no error */
            errorId = 0U;
            break;
        }
        /* last trigger is not done,time out */
        else
        {
            /* polling time out */
            errorId = XTRG_E_SW_TRIG_TIMEOUT;
        }
    }

    XtrgFaultInj_Xtrg_Ip_SoftwareTriggerTimeOut();

    /* #20check whether time out*/
    if (0U == errorId)
    {
        /* check whether pulse event */
        if (XTRG_SWT_PULSE_EVENT == ipSoftwareTrigCfg->trigEvent)
        {
            /* config trigger pulse */
            Xtrg_WriteRegister(base + (uint32)XTRG_SW_TRG_PULSE_WIDTH((uint32)ipSoftwareTrigCfg->trigSelector),
                               (uint8)XTRG_SW_TRG_PULSE_START_BIT((uint8)ipSoftwareTrigCfg->trigSelector),
                               XTRG_SW_TRG_PULSE_BITWIDTH_EACH,
                               (uint32)ipSoftwareTrigCfg->pulseWidth);
        } /* else not needed */

        /* config trigger */
        Xtrg_WriteRegister(base + XTRG_SW_TRG_CTRL,
                           XTRG_SW_TRG_BITWIDTH_EACH * (uint8)ipSoftwareTrigCfg->trigSelector, XTRG_SW_TRG_BITWIDTH_EACH,
                           (uint32)XTRG_BIT_ENABLE << (uint8)ipSoftwareTrigCfg->trigEvent);
    } /* else not needed */

    /* return error id */
    return errorId;
}

/** **************************************************************************************
 * \brief This function is used for getting the level state of specific Xtrg software
 *          trigger in IP level.

 * \verbatim
 * Syntax             : boolean Xtrg_Ip_GetSoftwareTrigState(
 *                          volatile uint32 base,
 *                          Xtrg_SWTrigSelectorType ipTrigSelector)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipTrigSelector - Xtrg software trigger selector

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : XTRG_SWT_STATE_HIGH: High State
 *                      XTRG_SWT_STATE_LOW: Low State

 * Description        : This function is used for getting the level state of specific Xtrg software
 *                      trigger in IP level.
 * \endverbatim
 *****************************************************************************************/
boolean Xtrg_Ip_GetSoftwareTrigState(volatile uint32 base, Xtrg_SWTrigSelectorType ipTrigSelector)
{
    boolean softwareStatus;

    /* #10 readl register */
    if (XTRG_SWT_STATE_HIGH == (((readl(base + XTRG_SW_TRG_STATUS) >> (uint8)ipTrigSelector)) &
                                XTRG_BIT_ENABLE) )
    {
        /* state high */
        softwareStatus = XTRG_SWT_STATE_HIGH;
    }
    else
    {
        /* state low */
        softwareStatus = XTRG_SWT_STATE_LOW;
    }

    /* return software trigger status */
    return softwareStatus;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg signal matrix in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_SigMatrixConfig(
 *                          volatile uint32 base,
 *                          const Xtrg_SigMatrixType *ipSigMatrixCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipSigMatrixCfg - Xtrg signal matrix configuration
 *                      ipEnable - Xtrg signal matrix enable/disable

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg signal matrix
 *                      in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_003
 *****************************************************************************************/
void Xtrg_Ip_SigMatrixConfig(volatile uint32 base,
                             const Xtrg_SigMatrixType *ipSigMatrixCfg, boolean ipSseEnable)
{
    /* each signal matrix at most can config 5 signals */
    uint8 matrixSigIndex = 0U;
    /* signal group index */
    uint32 groupIndex;
    /* signal index in one signal group */
    uint32 signalGroupIndex;
    /* the first 4 inputs of the signal logic matrix */
    uint32 sig4 = 0U;
    /* the fifth input of the signal logic matrix */
    uint32 sig5 = 0U;
    /* information about signal detect mode and detailed edge detect mode */
    uint32 matrixCtrl = 0U;

    if (TRUE == ipSseEnable)
    {
        for (; matrixSigIndex < XTRG_SSE_SIGNAL_CNT; matrixSigIndex++)
        {
            /* #10 get group kind of each input signal */
            groupIndex = XTRG_SIGNAL_GROUP_INDEX(
                             ipSigMatrixCfg->matrixInputCfg[matrixSigIndex].matrixInput);
            /* #20 get the signal index in signal matrix signal group */
            signalGroupIndex = XTRG_SIGNAL_WITHOUT_GROUP_INDEX(
                                   ipSigMatrixCfg->matrixInputCfg[matrixSigIndex].matrixInput);

            /* first 4 input */
            if ( 4U > matrixSigIndex)
            {
                /* for first four signal,each signal owns 8 bits */
                /* merge the 4 input signal index in the signal matrix signal group */
                sig4 |= (IndexInDiffMux[groupIndex].ssigNumber + signalGroupIndex) <<
                        (matrixSigIndex * XTRG_SSE_IN_BIT_WIDTH);
            }
            else
            {
                /* the fifth input has another register to writel */
                sig5 = IndexInDiffMux[groupIndex].ssigNumber + signalGroupIndex;
            }

            /* for 5 input signals,each signal can be config with level/edge detect mode */
            /* for edge detect mode, positive/nagetive detect mode can be chosen */
            matrixCtrl |= ((uint32)ipSigMatrixCfg->matrixInputCfg[matrixSigIndex].edgeDetect <<
                           (XTRG_SSE_CTRL_SSE_MODE_START_BIT + matrixSigIndex)) |
                          ((uint32)ipSigMatrixCfg->matrixInputCfg[matrixSigIndex].edgeDetectMode <<
                           (XTRG_SSE_CTRL_SSE_EDGE_SEL_START_BIT + (XTRG_SSE_CTRL_SSE_EDGE_SEL_BITWIDTH_EACH *
                                   matrixSigIndex)));
        }

        matrixCtrl |= (uint32)XTRG_BIT_ENABLE;
        /* #30 config which 4 first input signals */
        writel(sig4, (base + (uint32)XTRG_SSE_IN_0_3_SEL((uint32)ipSigMatrixCfg->matrixSelector)));
        /* #40 config the fifth input signals */
        writel(sig5, (base + (uint32)XTRG_SSE_IN_4_SEL((uint32)ipSigMatrixCfg->matrixSelector)));
        /* #50 config the truth table of 5 inputs */
        writel(ipSigMatrixCfg->truthTable, (base + XTRG_SSE_REG((uint32)ipSigMatrixCfg->matrixSelector)));
        /* #60 enable matrix and config detect mode */
        Xtrg_WriteRegister((base + XTRG_SSE_CTRL((uint32)ipSigMatrixCfg->matrixSelector)),
                           XTRG_SSE_CTRL_BIT_START, XTRG_SSE_CTRL_BIT_WIDTH, matrixCtrl);
    }
    else
    {
        matrixCtrl |= (uint32)XTRG_BIT_DISABLE;
        /* if disable,then configure disable */
        Xtrg_WriteRegister((base + XTRG_SSE_CTRL((uint32)ipSigMatrixCfg->matrixSelector)),
                           XTRG_SSE_CTRL_BIT_START, XTRG_SSE_CTRL_ENABLE_BIT_WIDTH, matrixCtrl);
    }


    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Mutiplexing Mux in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_SigMutiplex(
                            volatile uint32 base,
                            const Xtrg_SignalType *ipMutiplexSignal)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipMutiplexSignal - Xtrg signal for multiplexing Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Mutiplexing
 *                      Mux in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_005
 *****************************************************************************************/
void Xtrg_Ip_SigMutiplex(
    volatile uint32 base,
    const Xtrg_SignalType *ipMutiplexSignal
)
{
    /* target output signal is normal signal group */
    if (XTRG_SIG_OUTPUT_GROUP == (XTRG_SIGNAL_GROUP_INDEX(
                                      ipMutiplexSignal->signalOutput)))
    {
        /* #10 config input signal into output register */
        writel((IndexInDiffMux[(XTRG_SIGNAL_GROUP_INDEX(
                                    ipMutiplexSignal->signalInput))].smuxNumber +
                XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipMutiplexSignal->signalInput)),
               (base + XTRG_SIG_O_SEL(XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipMutiplexSignal->signalOutput))));
    }
    /* target output signal is i/o signal group */
    else if (XTRG_IO_OUTPUT_GROUP == XTRG_SIGNAL_GROUP_INDEX(
                 ipMutiplexSignal->signalOutput))
    {
        /* #10 config input signal into output register */
        writel((IndexInDiffMux[XTRG_SIGNAL_GROUP_INDEX(
                                   ipMutiplexSignal->signalInput)].smuxNumber +
                XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipMutiplexSignal->signalInput)),
               (base + XTRG_IO_O_SEL(XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipMutiplexSignal->signalOutput))));
        /* #20 enable i/o out config */
        Xtrg_WriteRegister((base + XTRG_IO_OUT_EN(XTRG_SIGNAL_WITHOUT_GROUP_INDEX(
                                ipMutiplexSignal->signalOutput))),
                           (uint8)(XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipMutiplexSignal->signalOutput) %
                                   XTRG_IO_OUT_REGISTER_BITWIDTH),
                           XTRG_IO_OUT_EACH_BIT_WIDTH, XTRG_BIT_ENABLE);
    }
    else
    {
        /* do nothing */
    }

    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Synchronization Mux in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_SigSynchronize(
 *                          volatile uint32 base,
 *                          const Xtrg_SignalType *ipSyncSignalCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipSyncSignalCfg - Xtrg signal for multiplexing Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Synchronization
 *                      Mux in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_006
 *****************************************************************************************/
void Xtrg_Ip_SigSynchronize(
    volatile uint32 base,
    const Xtrg_SignalType *ipSyncSignalCfg
)
{
    /* #10 config register */
    writel((IndexInDiffMux[XTRG_SIGNAL_GROUP_INDEX(
                               ipSyncSignalCfg->signalInput)].syncmuxNumber +
            XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipSyncSignalCfg->signalInput)),
           (base + XTRG_SYNC_O_SEL(XTRG_SIGNAL_WITHOUT_GROUP_INDEX(
                                       ipSyncSignalCfg->signalOutput))));
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Direct Trigger Mux
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_DirectTriggerAdc(
 *                          volatile uint32 base,
 *                          const Xtrg_DrtTrigMuxType *ipDirectTriggerCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipDirectTriggerCfg - Xtrg Direct Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Direct Trigger Mux
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007
 *****************************************************************************************/
void Xtrg_Ip_DirectTriggerAdc(
    volatile uint32 base,
    const Xtrg_DrtTrigMuxType *ipDirectTriggerCfg
)
{
    uint32 trigSource;
    uint32 decodeCfg[2];
    uint8 targetLutIndex = 0U;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    decodeCfg[0] = 0UL;
    decodeCfg[1] = 0UL;

    /* #10 check whether trigger soucr is from epwm/etimer */
    if (XTRG_TRG_INPUT_GROUP == (XTRG_SIGNAL_GROUP_INDEX(
                                     ipDirectTriggerCfg->triggerSource)))
    {
        /* trigger source is from epwm/etimer */
        trigSource = XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipDirectTriggerCfg->triggerSource);
    }
    else
    {
        /* trigger source is from ssig */
        trigSource = TRG_I_NUMBER + XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipDirectTriggerCfg->triggerSource);
    }

    /* #20 config trigger source and trigger id */
    writel(((trigSource << XTRG_TMUX0_DRT_CTRL_TRG_SEL_START_BIT) + (uint32)
            (ipDirectTriggerCfg->tidSignal)),
           (base + XTRG_TMUX0_DRT_CTRL((uint32)ipDirectTriggerCfg->directTmux)));

    for (; targetLutIndex < XTRG_TMUX0_DRT_DECODE_CNT_TOTAL; targetLutIndex++)
    {
        if (targetLutIndex < XTRG_TMUX0_DRT_DECODE_CNT_EACH_REG)
        {
            /* #30 config target lut 0 */
            decodeCfg[0] |= (uint32)ipDirectTriggerCfg->targetCfg[targetLutIndex] << (targetLutIndex *
                            XTRG_TMUX0_DRT_DECODE_BITWIDTH_EACH);
        }
        else
        {
            /* #40 config target lut 1 */
            decodeCfg[1] |= (uint32)ipDirectTriggerCfg->targetCfg[targetLutIndex] << ((
                                targetLutIndex - XTRG_TMUX0_DRT_DECODE_CNT_EACH_REG) *
                            XTRG_TMUX0_DRT_DECODE_BITWIDTH_EACH);
        }
    }

    /* #50 writel into target lut0 register */
    writel(decodeCfg[0], (base + XTRG_TMUX0_DRT_DECODE_SEL((uint32)ipDirectTriggerCfg->directTmux,
                          XTRG_TMUX0_DRT_DECODE_REG1)));
    /* #60 writel into target lut1 register */
    writel(decodeCfg[1], (base + XTRG_TMUX0_DRT_DECODE_SEL((uint32)ipDirectTriggerCfg->directTmux,
                          XTRG_TMUX0_DRT_DECODE_REG2)));
    /* #70 config tmux time out 0xFF(max_value) */
    /* every count is 16 apb clock */
    Xtrg_WriteRegister(base + XTRG_TMUX_DONE_MON_CNT, XTRG_TMUX_DONE_MON_CNT_CONFIG_START_BIT,
                       XTRG_TMUX_DONE_MON_CNT_CONFIG_BITWIDTH, XTRG_TMUX_DONE_MON_CNT_MAX_VALUE);
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Indirect Trigger Mux
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IndirectTriggerAdc(
 *                          volatile uint32 base,
 *                          const Xtrg_IndrtTrigMuxType *ipIndirectTriggerCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipIndirectTriggerCfg - Xtrg Indirect Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Indirect Trigger Mux
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007
 *****************************************************************************************/
void Xtrg_Ip_IndirectTriggerAdc(
    volatile uint32 base,
    const Xtrg_IndrtTrigMuxType *ipIndirectTriggerCfg
)
{
    uint32 trigSource;
    uint32 decodeCfg[2];
    uint8 targetLutIndex = 0U;
    uint32 targetTidValue;
    uint32 tempTidPool[2];
    uint8 tidPoolIndex = 0U;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata in some compiler */
    decodeCfg[0] = 0UL;
    decodeCfg[1] = 0UL;
    tempTidPool[0] = 0UL;
    tempTidPool[1] = 0UL;

    /* #10 check whether trigger soucr is from epwm/etimer */
    if (XTRG_TRG_INPUT_GROUP == (XTRG_SIGNAL_GROUP_INDEX(ipIndirectTriggerCfg->triggerSource)))
    {
        /* trigger source is from epwm/etimer */
        trigSource = XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipIndirectTriggerCfg->triggerSource);
    }
    else
    {
        /* trigger source is from ssig */
        trigSource = TRG_I_NUMBER + XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipIndirectTriggerCfg->triggerSource);
    }

    targetTidValue = ((uint32)ipIndirectTriggerCfg->tidPool[(uint8)
                      ipIndirectTriggerCfg->targetTidIndex][0] <<
                      5U) +
                     (uint32)ipIndirectTriggerCfg->tidPool[(uint8)ipIndirectTriggerCfg->targetTidIndex][1];


    /* #20 config TEAM_VAL TRG_SEL and TERM_TID */
    writel(((targetTidValue << XTRG_TMUX0_INDRT_CTRL_TREM_TID_START_BIT) | (trigSource
            << XTRG_TMUX0_INDRT_CTRL_TRG_SEL_START_BIT) |
            ((uint32)ipIndirectTriggerCfg->targetTidIndex)),
           (base + XTRG_TMUX0_INDRT_CTRL((uint32)ipIndirectTriggerCfg->indirectTmux)));


    for (; targetLutIndex < XTRG_TMUX0_INDRT_DECODE_CNT_TOTAL; targetLutIndex++)
    {
        if (targetLutIndex < XTRG_TMUX0_INDRT_DECODE_CNT_EACH_REG)
        {
            /* #30 config target lut 0 */
            decodeCfg[0] |= (uint32)ipIndirectTriggerCfg->targetCfg[targetLutIndex] << (targetLutIndex *
                            XTRG_TMUX0_INDRT_DECODE_BITWIDTH_EACH);
        }
        else
        {
            /* #40 config target lut 1 */
            decodeCfg[1] |= (uint32)ipIndirectTriggerCfg->targetCfg[targetLutIndex] << ((
                                targetLutIndex - XTRG_TMUX0_INDRT_DECODE_CNT_EACH_REG) *
                            XTRG_TMUX0_INDRT_DECODE_BITWIDTH_EACH);
        }
    }

    /* #50 writel into target lut0 register */
    writel(decodeCfg[0], base + XTRG_TMUX0_INDRT_DECODE_SEL((uint32)ipIndirectTriggerCfg->indirectTmux,
            XTRG_TMUX0_INDRT_DECODE_REG1));
    /* #60 writel into target lut1 register */
    writel(decodeCfg[1], base + XTRG_TMUX0_INDRT_DECODE_SEL((uint32)ipIndirectTriggerCfg->indirectTmux,
            XTRG_TMUX0_INDRT_DECODE_REG2));


    for (; tidPoolIndex < XTRG_TMUX0_INDRT_TID_POOL_CNT_TOTAL; tidPoolIndex++)
    {
        if (tidPoolIndex < XTRG_TMUX0_INDRT_TID_POOL_CNT_EACH_REG)
        {
            /* get tidpool0 register value */
            tempTidPool[0] |= ((uint32)ipIndirectTriggerCfg->tidPool[tidPoolIndex][0] <<
                               (XTRG_TMUX0_INDRT_TID_POOL_TARGET_START_BIT + (tidPoolIndex *
                                       XTRG_TMUX0_INDRT_TID_POOL_BITWIDTH_EACH))) +
                              (((uint32)ipIndirectTriggerCfg->tidPool[tidPoolIndex][1]) << (tidPoolIndex *
                                      XTRG_TMUX0_INDRT_TID_POOL_BITWIDTH_EACH));
        }
        else
        {
            /* get tidpool1 register value */
            tempTidPool[1] |= ((uint32)ipIndirectTriggerCfg->tidPool[tidPoolIndex][0] <<
                               (XTRG_TMUX0_INDRT_TID_POOL_TARGET_START_BIT + ((tidPoolIndex -
                                       XTRG_TMUX0_INDRT_TID_POOL_CNT_EACH_REG)  * XTRG_TMUX0_INDRT_TID_POOL_BITWIDTH_EACH))) +
                              (((uint32)ipIndirectTriggerCfg->tidPool[tidPoolIndex][1]) << ((tidPoolIndex -
                                      XTRG_TMUX0_INDRT_TID_POOL_CNT_EACH_REG) * XTRG_TMUX0_INDRT_TID_POOL_BITWIDTH_EACH));
        }
    }

    /* #70 writel into tidpool0 register */
    writel(tempTidPool[0],
           base + XTRG_TMUX0_INDRT_TID_POOL((uint32)ipIndirectTriggerCfg->indirectTmux,
                                            XTRG_TMUX0_INDRT_TID_POOL_REG1));
    /* #80 writel into tidpool1 register */
    writel(tempTidPool[1],
           (base + XTRG_TMUX0_INDRT_TID_POOL((uint32)ipIndirectTriggerCfg->indirectTmux,
                   XTRG_TMUX0_INDRT_TID_POOL_REG2)));

    /* #70 config tmux time out 0xFF(max_value) */
    /* every count is 16 apb clock */
    Xtrg_WriteRegister(base + XTRG_TMUX_DONE_MON_CNT, XTRG_TMUX_DONE_MON_CNT_CONFIG_START_BIT,
                       XTRG_TMUX_DONE_MON_CNT_CONFIG_BITWIDTH, XTRG_TMUX_DONE_MON_CNT_MAX_VALUE);
    return;
}

/** **************************************************************************************
 * \brief This function is used for reading the Adc channel conversion value
 *          which is triggered by Xtrg Trigger Mux in IP level.

 * \verbatim
 * Syntax             : uint32 Xtrg_Ip_ReadTrigAdcValue(
 *                          volatile uint32 base,
 *                          Xtrg_TrigMuxSelectorType ipTrigMuxSelector,
 *                          Xtrg_TrigAdcIndexType ipTriggeredAdc)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipTrigMuxSelector - Xtrg Indirect/direct Trigger Mux
 *                      ipTriggeredAdc - Adc triggered by Xtrg trigger Mux

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ipConversionValue: conversion value of triggered Adc channel

 * Description        : This function is used for reading the Adc channel conversion value
 *                      which is triggered by Xtrg Trigger Mux in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_008
 *****************************************************************************************/
uint32 Xtrg_Ip_ReadTrigAdcValue(
    volatile uint32 base,
    Xtrg_TrigMuxSelectorType ipTrigMuxSelector,
    Xtrg_TrigAdcIndexType ipTriggeredAdc
)
{
    uint32 trigResult;
    /* #10 record register value */
    trigResult = readl(base + XTRG_TMUX_ADC_RSLT((uint32)ipTriggeredAdc, (uint32)ipTrigMuxSelector));
    return trigResult;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Indirect Trigger
 *        Mux configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IOFilterConfig(
 *                          volatile uint32 base,
 *                          const Xtrg_IOFilterType *ipIoFilterCfg,
 *                          boolean ipEnable)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipIoFilterCfg - Xtrg I/O filter configuration
 *                      ipEnable - Enable/Disable Xtrg I/O filter configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Indirect Trigger
 *                      Mux configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_009
 *****************************************************************************************/
void Xtrg_Ip_IOFilterConfig(
    volatile uint32 base,
    const Xtrg_IOFilterType *ipIoFilterCfg,
    boolean ipEnable
)
{
    uint32 configValue;
    /* #10 io filter get configuration */
    configValue = ((ipIoFilterCfg->samplingIntvl - 1U) << XTRG_IO_FLAT_SMPL_INTVAL_START_BIT) |
                  ((ipIoFilterCfg->negDetIntvl - 2U) << XTRG_IO_FLAT_NEG_BAND_WID_START_BIT) |
                  ((ipIoFilterCfg->posDetIntvl - 2U) << XTRG_IO_FLAT_POS_BAND_WID_START_BIT) |
                  ((uint32)ipIoFilterCfg->ioFilterMode << XTRG_IO_FLAT_FLT_EDGE_SEL_START_BIT) | (uint32)ipEnable;
    /* #20 write into register */
    writel(configValue, (base + XTRG_IO_FLAT(XTRG_SIGNAL_WITHOUT_GROUP_INDEX(ipIoFilterCfg->ioInput))));
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Direct Trigger Mux priority
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_DirTrigAdcPrioConfig(
 *                          volatile uint32 base,
 *                          Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
 *                          Xtrg_TmuxTrigPriority ipPriorityCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipDirectTmux - Xtrg direct trigger mux selectors
 *                      ipPriorityCfg - Xtrg direct Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Direct Trigger Mux priority
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010
 *****************************************************************************************/
void Xtrg_Ip_DirTrigAdcPrioConfig(
    volatile uint32 base,
    Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
    Xtrg_TmuxTrigPriority ipPriorityCfg
)
{
    /* #10 write into register */
    Xtrg_WriteRegister(base + XTRG_TMUX_ARB_CTRL0,
                       ((uint8)ipDirectTmux * XTRG_TMUX_ARB_CTRL0_EACH_TMUX_BITWIDTH),
                       XTRG_TMUX_ARB_CTRL0_EACH_TMUX_BITWIDTH,
                       (uint32)ipPriorityCfg);
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Indirect Trigger Mux priority
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IndirTrigAdcPrioConfig(
 *                          volatile uint32 base,
 *                          Xtrg_IndrtTrigMuxSelectorType ipIndirectTmux,
 *                          Xtrg_TmuxTrigPriority ipPriorityCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipIndirectTmux - Xtrg indirect trigger mux selectors
 *                      ipPriorityCfg - Xtrg indirect Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Indirect Trigger Mux priority
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010
 *****************************************************************************************/
void Xtrg_Ip_IndirTrigAdcPrioConfig(
    volatile uint32 base,
    Xtrg_IndrtTrigMuxSelectorType ipIndirectTmux,
    Xtrg_TmuxTrigPriority ipPriorityCfg
)
{
    /* #10 write into register */
    Xtrg_WriteRegister((base + XTRG_TMUX_ARB_CTRL1),
                       ((uint8)ipIndirectTmux * XTRG_TMUX_ARB_CTRL1_EACH_TMUX_BITWIDTH),
                       XTRG_TMUX_ARB_CTRL1_EACH_TMUX_BITWIDTH,
                       (uint32)ipPriorityCfg);
    return;
}

/** **************************************************************************************
 * \brief This function is used for setting Xtrg interrupt configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_InterruptEnable(
 *                          volatile uint32 base,
 *                          Xtrg_NormalInterruptType ipInterruptId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipInterruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for setting Xtrg interrupt configuration
 *                      in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011
 *****************************************************************************************/
void Xtrg_Ip_InterruptEnable(
    volatile uint32 base,
    Xtrg_NormalInterruptType ipInterruptId
)
{
    /* #10 enable related interrupt status enable register */
    Xtrg_WriteRegister(base + XTRG_FUNC_INT_STA_EN, (uint8)ipInterruptId, XTRG_FUN_INT_EACH_BITWIDTH,
                       XTRG_BIT_ENABLE);
    /* #20 enable related interrupt signal enable register */
    Xtrg_WriteRegister(base + XTRG_FUNC_INT_SIG_EN, (uint8)ipInterruptId, XTRG_FUN_INT_EACH_BITWIDTH,
                       XTRG_BIT_ENABLE);
    return;
}

/** **************************************************************************************
 * \brief This function is used for resetting configuring Xtrg interrupt
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_InterruptDisable(
 *                          volatile uint32 base,
 *                          Xtrg_NormalInterruptType ipInterruptId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipInterruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for resetting configuring Xtrg interrupt
 *                          configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011
 *****************************************************************************************/
void Xtrg_Ip_InterruptDisable(
    volatile uint32 base,
    Xtrg_NormalInterruptType ipInterruptId
)
{
    /* #10 disable related interrupt status enable register */
    Xtrg_WriteRegister(base + XTRG_FUNC_INT_STA_EN, (uint8)ipInterruptId, XTRG_FUN_INT_EACH_BITWIDTH,
                       XTRG_BIT_DISABLE);
    /* #20 disable related interrupt signal enable register */
    Xtrg_WriteRegister(base + XTRG_FUNC_INT_SIG_EN, (uint8)ipInterruptId, XTRG_FUN_INT_EACH_BITWIDTH,
                       XTRG_BIT_DISABLE);
    /* #30 clear interrupt status register */
    Xtrg_WriteRegister(base + XTRG_FUNC_INT_STA, (uint8)ipInterruptId, XTRG_FUN_INT_EACH_BITWIDTH,
                       XTRG_BIT_ENABLE);
    return;
}

/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void Xtrg_Ip_DirTrigEnableConfig(
 *                          volatile uint32 base,
 *                          Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
 *                          boolean en)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipDirectTmux - Xtrg Direct Trigger Mux configuration
 *                      en - Xtrg direct trigger mux enable/disable configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function returns the version information of this module.
 * \endverbatim
 *****************************************************************************************/
void Xtrg_Ip_DirTrigEnableConfig(
    volatile uint32 base,
    Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
    boolean en
)
{
    /* #10 writer into register */
    Xtrg_WriteRegister(base + XTRG_TMUX_DEC_EN, (uint8)ipDirectTmux,
                       XTRG_TMUX_DEC_EN_EACH_TMUX_BITWIDTH,
                       (uint32)en);
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring Indirect Trigger enable/disable
 *          in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IndirTrigEnableConfig(
 *                          volatile uint32 base,
 *                          Xtrg_IndrtTrigMuxSelectorType ipInDirectTmux,
 *                          boolean en)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipInDirectTmux - Xtrg Indirect Trigger Mux configuration
 *                      en - Xtrg indirect trigger mux enable/disable configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Indirect Trigger
 *                      enable/disable in IP level.
 * \endverbatim
 *****************************************************************************************/
void Xtrg_Ip_IndirTrigEnableConfig(
    volatile uint32 base,
    Xtrg_IndrtTrigMuxSelectorType ipInDirectTmux,
    boolean en
)
{
    /* #10 writer into register */
    Xtrg_WriteRegister(base + XTRG_TMUX_DEC_EN,
                       (uint8)ipInDirectTmux + XTRG_TMUX_DEC_EN_INDRT_START_BIT,
                       XTRG_TMUX_DEC_EN_EACH_TMUX_BITWIDTH,
                       (uint32)en);
    return;
}

/** **************************************************************************************
 * \brief This function is used for get interrupt bit for Xtrg interrupt.

 * \verbatim
 * Syntax             : static Xtrg_ErrorIdType Xtrg_InterruptBitGet(
 *                          Xtrg_NormalInterruptType *event)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : event - Xtrg interrupt event

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : irqError: Xtrg error number

 * Description        : This function is used for get interrupt bit for Xtrg interrupt.
 * \endverbatim
 * Traceability       : SWSR_XTRG_013
 *****************************************************************************************/
static Xtrg_ErrorIdType Xtrg_InterruptBitGet(uint8 *event)
{
    /* get int status register value */
    uint32 irqState = readl(XTRG_REG_BASE + XTRG_FUNC_INT_STA);
    /* int event index */
    uint8 irqIndex = 0U;
    /* interrupt valid flag */
    boolean intValid = FALSE;
    /* error id */
    Xtrg_ErrorIdType irqError;

    /* get interrupt bit */
    for (; irqIndex < XTRG_INT_NUMBER; irqIndex++)
    {
        /* #10 check which interrupt bit is triggered */
        if (XTRG_BIT_ENABLE == ((irqState >> ((uint8)XTRG_TMUX0_DONE + irqIndex)) &
                                (uint32)XTRG_BIT_ENABLE))
        {

            /* record triggered int event */
            event[irqIndex] = (uint8)XTRG_TMUX0_DONE + irqIndex;
            /* change interrupt valid flag to TRUE */
            intValid = TRUE;

        }
        else
        {
            /* related int status is not triggered */
            event[irqIndex] = XTRG_BIT_DISABLE;
        }
    }

    /* #20 find no triggered int */
    if (FALSE == intValid)
    {
        /* no match int bit */
        irqError = XTRG_E_INT_NO_MATCH;
    }
    else
    {
        /* no error */
        irqError = XTRG_NO_ERROR;
    }

    return irqError;
}

/** **************************************************************************************
 * \brief This function is used for handling Xtrg interrupts.

 * \verbatim
 * Syntax             : void Xtrg_InterruptHandler(void)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for handling Xtrg interrupts.
 * \endverbatim
 * Traceability       : SWSR_XTRG_016
 *****************************************************************************************/
static void Xtrg_InterruptHandler(void)
{
    /* int event */
    uint8 irqEvent[XTRG_INT_NUMBER];
    /* int event index */
    uint8 intStaIndex = 0U;
    /* #10 get error id */
    Xtrg_ErrorIdType irqErrorStatus = Xtrg_InterruptBitGet(irqEvent);

    XtrgFaultInj_Xtrg_InterruptHandleNoMatch();

    /* #20 no match error happened,mask and clear all interrupt bits,do nothing */
    if (XTRG_E_INT_NO_MATCH == irqErrorStatus)
    {
        /* valid interrupt bits can not be found */
        /* clear all int bits */
        Xtrg_WriteRegister(XTRG_REG_BASE + XTRG_FUNC_INT_STA, XTRG_FUN_INT_START_BIT,
                           XTRG_INT_NUMBER,
                           XTRG_FUN_INT_ALL_BIT_SET);
    }
    /* #30 process interrupt normally */
    else
    {
        /* check all interrupt events */
        for (; intStaIndex < XTRG_INT_NUMBER; intStaIndex++)
        {
            /* related int event is valid */
            if (XTRG_BIT_DISABLE != irqEvent[intStaIndex])
            {
                /* clear int bit */
                Xtrg_WriteRegister(XTRG_REG_BASE + XTRG_FUNC_INT_STA, irqEvent[intStaIndex],
                                   XTRG_FUN_INT_EACH_BITWIDTH,
                                   XTRG_BIT_ENABLE);

                /* #40 check related event notif whether is enabled */
                if (XTRG_NOTIF_ENABLED == Xtrg_NotifEnableStatus[intStaIndex])
                {
                    /* call notification */
                    Xtrg_GlobalConfig->cb(Xtrg_GlobalConfig->arg, irqEvent[intStaIndex]);
                } /* else not needed */
            }
        }
    }

    XtrgFaultInj_XtrgFaultIntErrorStatus();
    return;
}

ISR(Xtrg_IrqHandler)
{
    Xtrg_InterruptHandler();
}

#define XTRG_STOP_SEC_CODE
#include "Xtrg_MemMap.h"

#ifdef __cplusplus
}
#endif
