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
 * \file     Xtrg.c
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
#include "Xtrg_Cfg.h"
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
/*****************************************************************************************
 *                    Global Constant Declarations
 *****************************************************************************************/
#define XTRG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Xtrg_MemMap.h"
/** \brief  global xtrg device configuration */
const Xtrg_DeviceType *Xtrg_GlobalConfig;
#define XTRG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Xtrg_MemMap.h"
/******************************************************************************************
 *                     Global Variable Declarations
 *****************************************************************************************/
#define XTRG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Xtrg_MemMap.h"
/** \brief  xtrg notification enable/disable status */
Xtrg_NotifEnableType Xtrg_NotifEnableStatus[XTRG_INT_NUMBER];
#define XTRG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Xtrg_MemMap.h"

#define XTRG_START_SEC_CODE
#include "Xtrg_MemMap.h"
/** **************************************************************************************
 * \brief This function is used for generating specific Xtrg software
 *          trigger event or pulse.

 * \verbatim
 * Syntax             : void Xtrg_SoftwareTrigger(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SWTriggerType *softwareTriggerCfg)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      softwareTriggerCfg - Xtrg software trigger configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for generating specific Xtrg software
 *                      trigger event or pulse.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_016 SWSR_XTRG_036 SW_SM006
 *****************************************************************************************/
void Xtrg_SoftwareTrigger(const Xtrg_DeviceType *deviceCfg,
                          const Xtrg_SWTriggerType *softwareTriggerCfg)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if ( (NULL_PTR == deviceCfg) || (NULL_PTR == softwareTriggerCfg) )
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    /* #20 check whether swt register is still triggerring last time tirgger */
    else if (XTRG_E_SW_TRIG_TIMEOUT == Xtrg_Ip_SoftwareTrigger(deviceCfg->base, softwareTriggerCfg))
    {
        /* register is not idle */
        errorCode = XTRG_E_SW_TRIG_TIMEOUT;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SOFTWARE_TRIGGER, errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SOFTWARE_TRIGGER, errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for getting the level state of specific
 *          Xtrg software trigger.

 * \verbatim
 * Syntax             : boolean Xtrg_GetSoftwareTrigState(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_SWTrigSelectorType triggerSelector)

 * Service ID[hex]    : 0x01

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      triggerSelector - Xtrg software trigger selector

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : True - High state
 *                      False - Low state

 * Description        : This function is used for getting the level state of specific
 *                      Xtrg software trigger.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_016 SWSR_XTRG_037 SW_SM006
 *****************************************************************************************/
boolean Xtrg_GetSoftwareTrigState(const Xtrg_DeviceType *deviceCfg,
                                  Xtrg_SWTrigSelectorType triggerSelector)
{
    /* software trigger status */
    boolean xtrgSoftwareStatus = XTRG_SWT_STATE_LOW;
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;

        /* #20 check whether status is high */
        if (XTRG_SWT_STATE_HIGH == Xtrg_Ip_GetSoftwareTrigState(deviceCfg->base, triggerSelector))
        {
            /* software trigger high state */
            xtrgSoftwareStatus = XTRG_SWT_STATE_HIGH;
        }
        /* #30 check whether status is low */
        else
        {
            /* software trigger low state */
            xtrgSoftwareStatus = XTRG_SWT_STATE_LOW;
        }
    }

    /* #40 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_GET_SOFTWARE_TRIG_STATE,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_GET_SOFTWARE_TRIG_STATE,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    /* return status */
    return xtrgSoftwareStatus;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg signal matrix.

 * \verbatim
 * Syntax             : void Xtrg_SignalMatrixConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SigMatrixType *sigMatrixCfg)

 * Service ID[hex]    : 0x02

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      sigMatrixCfg - Xtrg signal matrix configuration
 *                      en - Xtrg signal matrix enable/disable

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg signal matrix.
 * \endverbatim
 * Traceability       : SWSR_XTRG_003 SWSR_XTRG_015 SWSR_XTRG_038 SW_SM006
 *****************************************************************************************/
void Xtrg_SignalMatrixConfig(const Xtrg_DeviceType *deviceCfg,
                             const Xtrg_SigMatrixType *sigMatrixCfg,
                             boolean en)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if ((NULL_PTR == deviceCfg) || (NULL_PTR == sigMatrixCfg))
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    /* #20 config signal matrix in ip level */
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_SigMatrixConfig(deviceCfg->base, sigMatrixCfg, en);
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SIGNAL_MATRIX_CONFIG,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SIGNAL_MATRIX_CONFIG,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Mutiplexing Mux.

 * \verbatim
 * Syntax             : void Xtrg_SignalMutiplex(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SignalType *mutiplexSignal)

 * Service ID[hex]    : 0x03

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      mutiplexSignal - Xtrg signal for multiplexing Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Mutiplexing Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_005 SWSR_XTRG_015 SWSR_XTRG_039 SW_SM006
 *****************************************************************************************/
void Xtrg_SignalMutiplex(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_SignalType *mutiplexSignal
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if ((NULL_PTR == deviceCfg) || (NULL_PTR == mutiplexSignal))
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_SigMutiplex(deviceCfg->base, mutiplexSignal);
    }

    /* #20 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SIGNAL_MUTIPLEX,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SIGNAL_MUTIPLEX,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Synchronization Mux.

 * \verbatim
 * Syntax             : void Xtrg_SignalSynchronize(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_SignalType *syncSignalCfg)

 * Service ID[hex]    : 0x04

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      syncSignalCfg - Xtrg signal for epwm/etimer
 *                                      synchronization configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Synchronization
 *                      Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_006 SWSR_XTRG_015 SWSR_XTRG_040 SW_SM006
 *****************************************************************************************/
void Xtrg_SignalSynchronize(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_SignalType *syncSignalCfg
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if ((NULL_PTR == deviceCfg) || (NULL_PTR == syncSignalCfg))
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_SigSynchronize(deviceCfg->base, syncSignalCfg);
    }

    /* #20 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SIGNAL_SYNC,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_SIGNAL_SYNC,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Direct Trigger
 *          Mux configuration.

 * \verbatim
 * Syntax             : void Xtrg_DirectTriggerAdc(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_DrtTrigMuxType *directTriggerCfg)

 * Service ID[hex]    : 0x05

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      directTriggerCfg - Xtrg Direct Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Direct Trigger
 *                      Mux configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007 SWSR_XTRG_015 SWSR_XTRG_041 SW_SM006
 *****************************************************************************************/
void Xtrg_DirectTriggerAdc(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_DrtTrigMuxType *directTriggerCfg
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if ((NULL_PTR == deviceCfg) || (NULL_PTR == directTriggerCfg))
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_DirectTriggerAdc(deviceCfg->base, directTriggerCfg);
    }

    /* #20 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_DIRECT_TRIG_ADC,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_DIRECT_TRIG_ADC,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Indirect Trigger Mux
 *          configuration.

 * \verbatim
 * Syntax             : void Xtrg_IndirectTriggerAdc(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_IndrtTrigMuxType *indirectTriggerCfg)

 * Service ID[hex]    : 0x06

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      indirectTriggerCfg - Xtrg Indirect Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Indirect Trigger Mux
 *                      configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007 SWSR_XTRG_015 SWSR_XTRG_042 SW_SM006
 *****************************************************************************************/
void Xtrg_IndirectTriggerAdc(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_IndrtTrigMuxType *indirectTriggerCfg
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if ((NULL_PTR == deviceCfg) || (NULL_PTR == indirectTriggerCfg))
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_IndirectTriggerAdc(deviceCfg->base, indirectTriggerCfg);
    }

    /* #20 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INDIRECT_TRIG_ADC,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INDIRECT_TRIG_ADC,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for reading the Adc channel conversion value
 *          which is triggered by Xtrg Trigger Mux.

 * \verbatim
 * Syntax             : uint32 Xtrg_ReadTriggeredAdcValue(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_TrigMuxSelectorType trigMuxSelector,
 *                          Xtrg_TrigAdcIndexType triggeredAdc)

 * Service ID[hex]    : 0x07

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      trigMuxSelector - Xtrg Indirect/direct Trigger Mux
 *                      triggeredAdc - Adc triggered by Xtrg trigger Mux

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : adcConvValue - Triggered Adc channel conversion value

 * Description        : This function is used for reading the Adc channel conversion value
 *                      which is triggered by Xtrg Trigger Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_008 SWSR_XTRG_015 SWSR_XTRG_043 SW_SM006
 *****************************************************************************************/
uint32 Xtrg_ReadTriggeredAdcValue(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_TrigMuxSelectorType trigMuxSelector,
    Xtrg_TrigAdcIndexType triggeredAdc
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;
    uint32 adcConvValue = 0U;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        adcConvValue = Xtrg_Ip_ReadTrigAdcValue(deviceCfg->base, trigMuxSelector, triggeredAdc);
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_READ_TRIG_ADC_VALUE,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_READ_TRIG_ADC_VALUE,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return adcConvValue;
}

/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg I/O filter configuration.

 * \verbatim
 * Syntax             : void Xtrg_IOFilterConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          const Xtrg_IOFilterType *ioFilterCfg,
 *                          boolean enable)

 * Service ID[hex]    : 0x08

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      ioFilterCfg - Xtrg I/O filter configuration
 *                      enable - Enable/Disable Xtrg I/O filter configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg I/O filter
 *                      configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_009 SWSR_XTRG_015 SWSR_XTRG_044 SW_SM006
 *****************************************************************************************/
void Xtrg_IOFilterConfig(
    const Xtrg_DeviceType *deviceCfg,
    const Xtrg_IOFilterType *ioFilterCfg,
    boolean enable
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if ((NULL_PTR == deviceCfg) || (NULL_PTR == ioFilterCfg))
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_IOFilterConfig(deviceCfg->base, ioFilterCfg, enable);
    }

    /* #20 if DET enabled,report error code */

#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_IO_FILTER_CONFIG,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_IO_FILTER_CONFIG,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Direct Trigger Mux
 *          priority configuration.

 * \verbatim
 * Syntax             : void Xtrg_DirTrigAdcPrioConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_DrtTrigMuxSelectorType directTmux,
 *                          Xtrg_TmuxTrigPriority priorityCfg)

 * Service ID[hex]    : 0x09

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      directTmux - Xtrg direct trigger mux selectors
 *                      priorityCfg - Xtrg Direct Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Direct Trigger Mux
 *                      priority configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010 SWSR_XTRG_015 SWSR_XTRG_045 SW_SM006
 *****************************************************************************************/
void Xtrg_DirTrigAdcPrioConfig(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_DrtTrigMuxSelectorType directTmux,
    Xtrg_TmuxTrigPriority priorityCfg
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_DirTrigAdcPrioConfig(deviceCfg->base, directTmux, priorityCfg);
    }

    /* #30 if DET enabled,report error code */

#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_DIR_TRIG_ADC_PRIO_CONFIG,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_DIR_TRIG_ADC_PRIO_CONFIG,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Indirect Trigger
 *          Mux priority configuration.

 * \verbatim
 * Syntax             : void Xtrg_InDirTrigAdcPrioConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_IndrtTrigMuxSelectorType indirectTmux,
 *                          Xtrg_TmuxTrigPriority priorityCfg)

 * Service ID[hex]    : 0x0A

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      indirectTmux - Xtrg indirect trigger mux selectors
 *                      priorityCfg - Xtrg Indirect Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Indirect Trigger
 *                      Mux priority configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010 SWSR_XTRG_015 SWSR_XTRG_046 SW_SM006
 *****************************************************************************************/
void Xtrg_InDirTrigAdcPrioConfig
(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_IndrtTrigMuxSelectorType indirectTmux,
    Xtrg_TmuxTrigPriority priorityCfg
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_IndirTrigAdcPrioConfig(deviceCfg->base, indirectTmux, priorityCfg);
    }

    /* #30 if DET enabled,report error code */

#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INDIR_TRIG_ADC_PRIO_CONFIG,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INDIR_TRIG_ADC_PRIO_CONFIG,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for setting Xtrg interrupt configuration.

 * \verbatim
 * Syntax             : void Xtrg_InterruptEnable(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_NormalInterruptType interruptId)

 * Service ID[hex]    : 0x0B

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      interruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for setting Xtrg interrupt configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011 SWSR_XTRG_015 SWSR_XTRG_047 SW_SM006
 *****************************************************************************************/
void Xtrg_InterruptEnable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        Xtrg_GlobalConfig = deviceCfg;
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_InterruptEnable(deviceCfg->base, interruptId);
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INTERRUPT_ENABLED,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INTERRUPT_ENABLED,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if ((XTRG_DEV_ERROR_DETECT == STD_ON) || (XTRG_SAFETY_ENABLE == STD_ON)) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for resetting configuring Xtrg interrupt configuration.

 * \verbatim
 * Syntax             : void Xtrg_InterruptDisable(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_NormalInterruptType interruptId)

 * Service ID[hex]    : 0x0C

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      interruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for resetting configuring Xtrg
 *                      interrupt configuration.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011 SWSR_XTRG_015 SWSR_XTRG_048 SW_SM006
 *****************************************************************************************/
void Xtrg_InterruptDisable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        Xtrg_GlobalConfig = NULL_PTR;
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* disable notif */
        Xtrg_NotifEnableStatus[(uint8)interruptId - (uint8)XTRG_TMUX0_DONE] = XTRG_NOTIF_DISABLED;
        /* call the ip level api */
        Xtrg_Ip_InterruptDisable(deviceCfg->base, interruptId);
    }

    /* #20 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INTERRUPT_DISABLED,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INTERRUPT_DISABLED,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}


/** **************************************************************************************
 * \brief This function is used for setting callback function of Xtrg.

 * \verbatim
 * Syntax             : void Xtrg_CallbackEnable(
 *                          const Xtrg_DeviceType *deviceCfg)

 * Service ID[hex]    : 0x0D

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for setting callback function of Xtrg.
 * \endverbatim
 * Traceability       : SWSR_XTRG_012 SWSR_XTRG_015 SWSR_XTRG_049 SW_SM006
 *****************************************************************************************/
void Xtrg_CallbackEnable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    /* #20 notification is NULL_PTR */
    else if (NULL_PTR == deviceCfg->cb)
    {
        errorCode = XTRG_E_NULL_NOTIF;
    }
    else
    {
        errorCode = XTRG_NO_ERROR;
        Xtrg_NotifEnableStatus[(uint8)interruptId - (uint8)XTRG_TMUX0_DONE] = XTRG_NOTIF_ENABLED;
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_CALLBACK_ENABLED,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_CALLBACK_ENABLED,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void  Xtrg_CallbackDisable(
 *                          const Xtrg_DeviceType *deviceCfg)

 * Service ID[hex]    : 0x0E

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_XTRG_012 SWSR_XTRG_015 SWSR_XTRG_050 SW_SM006
 *****************************************************************************************/
void Xtrg_CallbackDisable(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_NormalInterruptType interruptId
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        Xtrg_NotifEnableStatus[(uint8)interruptId - (uint8)XTRG_TMUX0_DONE] = XTRG_NOTIF_DISABLED;
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_CALLBACK_DISABLED,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_CALLBACK_DISABLED,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function is used for enable/disable direct Tirgger Mux.

 * \verbatim
 * Syntax             : void Xtrg_DirTrigEnableConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_DrtTrigMuxSelectorType directTmux,
 *                          boolean enable)

 * Service ID[hex]    : 0x0F

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      directTmux - Xtrg direct trigger mux selectors
 *                      enable - Xtrg direct trigger mux enable/disable configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for enable/disable direct Tirgger Mux.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_051 SW_SM006
 *****************************************************************************************/
void Xtrg_DirTrigEnableConfig(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_DrtTrigMuxSelectorType directTmux,
    boolean enable
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_DirTrigEnableConfig(deviceCfg->base, directTmux, enable);
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_DIR_TRIG_ENABLE_CONFIG,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_DIR_TRIG_ENABLE_CONFIG,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void Xtrg_IndirTrigEnableConfig(
 *                          const Xtrg_DeviceType *deviceCfg,
 *                          Xtrg_IndrtTrigMuxSelectorType directTmux,
 *                          boolean enable)

 * Service ID[hex]    : 0x10

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : deviceCfg - Xtrg basic device configuration
 *                      indirectTmux - Xtrg indirect trigger mux selectors
 *                      enable - Xtrg direct trigger mux enable/disable configuration
 *
 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_XTRG_015 SWSR_XTRG_052 SW_SM006
 *****************************************************************************************/
void Xtrg_IndirTrigEnableConfig(
    const Xtrg_DeviceType *deviceCfg,
    Xtrg_IndrtTrigMuxSelectorType indirectTmux,
    boolean enable
)
{
    /* xtrg error code */
    Xtrg_ErrorIdType errorCode;

    /* #10 input pointer is NULL_PTR */
    if (NULL_PTR == deviceCfg)
    {
        /* input pointer is NULL_PTR */
        errorCode = XTRG_E_POINTER;
    }
    else
    {
        /* no error */
        errorCode = XTRG_NO_ERROR;
        /* call the ip level api */
        Xtrg_Ip_IndirTrigEnableConfig(deviceCfg->base, indirectTmux, enable);
    }

    /* #30 if DET enabled,report error code */
#if ((STD_ON == XTRG_DEV_ERROR_DETECT) || (STD_ON == XTRG_SAFETY_ENABLE))

    if (XTRG_NO_ERROR != errorCode)
    {
#if (STD_ON == XTRG_DEV_ERROR_DETECT)
        (void)Det_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INDIR_TRIG_ENABLE_CONFIG,
                              errorCode);
#endif /* #if (STD_ON == XTRG_DEV_ERROR_DETECT) */
#if (STD_ON == XTRG_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(XTRG_MODULE_ID, XTRG_INSTANCE_ID, XTRG_API_INDIR_TRIG_ENABLE_CONFIG,
                                   errorCode);
#endif /* #if (STD_ON == XTRG_SAFETY_ENABLE) */
    } /* else not needed */

#else
    /* prevent errorCode from no use */
    XTRG_DUMMY_STATEMENT(errorCode);
#endif /* #if (XTRG_DEV_ERROR_DETECT == STD_ON) */
    return;
}

#define XTRG_STOP_SEC_CODE
#include "Xtrg_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */

