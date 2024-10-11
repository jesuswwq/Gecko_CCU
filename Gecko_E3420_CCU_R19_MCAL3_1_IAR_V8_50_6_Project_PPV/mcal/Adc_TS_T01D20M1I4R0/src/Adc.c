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
 * \file     Adc.c
 * \brief    AUTOSAR 4.3.1 MCAL Adc external driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Adc.h"
#include "Adc_Types.h"
#include "Adc_ConfigTypes.h"
#include "SchM_Adc.h"
#include "Adc.h"
#include "Adc_Hw_E3.h"
#include "Adc_Version.h"
/** Traceability       : SWSR_ADC_032 */
#include "Std_Types.h"
#if(ADC_DEV_ERROR_DETECT == STD_ON)
/** Traceability       : SWSR_ADC_153 SWSR_ADC_154 */
#include "Det.h"
#endif /* #if(ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
#include "FuSaMcalReportError.h"
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
/******************************************************************************************
 *                     Global Variable Declarations
 *****************************************************************************************/
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"
/** \brief  indicate whether adc is initialized */
Adc_GlobalStateType Adc_GlobalState;
/** \brief  save all group information */
Adc_GroupStatusType Adc_AllGroupInfo[ADC_USED_GROUP_COUNT];
/** \brief  save the user config */
const Adc_ConfigType *Adc_GlobalConfigPtr;
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"

/*****************************************************************************************
 *                           Private Variable Definitions
 *****************************************************************************************/
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"
#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/** \brief  inticate whether power change starts of not */
static Adc_PowerChangeType Adc_PowerStateChange;
/** \brief  adc current power state */
/** Traceability       : SWSR_ADC_027 */
static Adc_PowerStateType Adc_CurrentPowerState;
/** \brief  adc target power state */
/** Traceability       : SWSR_ADC_027 */
static Adc_PowerStateType Adc_TargetPowerState;
#endif /* #if (ADC_POWER_STATE_SUPPORTED == STD_ON) */
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************************
 *                                  Private Function Declarations
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckInitAlready(void);
static inline Adc_ErrorIdType Adc_CheckInitPointer(const Adc_ConfigType *adcConfigPtr);
static inline Adc_ErrorIdType Adc_CheckCircularGroup(Adc_GroupType grpId);
static inline Adc_ErrorIdType Adc_CheckParameterGroup(Adc_GroupType grpId);
static inline Adc_ErrorIdType Adc_CheckSetupAndReadPointer(const Adc_ValueGroupType *bufferPtr);
static inline Adc_ErrorIdType Adc_CheckGetStreamPointer(Adc_ValueGroupType **pointToSamplePtr);
static inline Adc_ErrorIdType Adc_CheckGroupBusySetup(Adc_GroupType grpId);
static inline Adc_ErrorIdType Adc_ReadApiCheckGroupIdle(Adc_GroupType grpId);
#if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON) \
|| (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON))
static Adc_ErrorIdType Adc_CheckSingleGroup(Adc_GroupType grpId);
#endif /* #if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON)
|| (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)) */
#if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON))
static Adc_ErrorIdType Adc_CheckNoGroupConverting(void);
#endif /* #if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON)) */
static void Adc_ResetGroupStatus(const Adc_ConfigType *AdcConfigPtr);
static void Adc_SetupResultBufferDetail(Adc_GroupType grpId, Adc_ValueGroupType *bufferPtr);
static void Adc_UpdGrpStaForSingleOneShotReadApi(Adc_GroupType singleOneShotGrpId,
        const Adc_GroupConfigType *groupCfgPtr);
static void Adc_UpdGrpStaForSingleContiReadApi(Adc_GroupType singleContiGrpId);
static void Adc_UpdGrpStaForLinearReadApi(Adc_GroupType linearGrpId);
static void Adc_UpdGrpStaForCircularReadApi(Adc_GroupType circularGrpId);
static void Adc_ReadOrGetUpdateGroupStatus(Adc_GroupType grpId);
static Adc_StreamNumSampleType Adc_GetStreamLastPointerDetail(Adc_GroupType grpId,
        Adc_ValueGroupType **pointToSamplePtr);
#if (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
static inline Adc_ErrorIdType Adc_CheckGroupTriggSrc(Adc_GroupType grpId,
        Adc_TriggerSourceType trigSource);
static inline Adc_ErrorIdType Adc_CheckBufferUninit(Adc_GroupType grpId);
static Adc_ErrorIdType Adc_CheckGroupBusyStartApi(Adc_GroupType grpId);
static Adc_ErrorIdType Adc_StopApiCheckGroupIdle(Adc_GroupType grpId);
#if (ADC_HW_TRIGGER_API == STD_ON)
static Adc_ErrorIdType Adc_CheckHWTrigStartApi(Adc_GroupType grpId);
static inline Adc_ErrorIdType Adc_CheckHWTriggerring(void);
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_READ_GROUP_API == STD_ON)
static void Adc_ReadGroupDetail(Adc_GroupType grpId, Adc_ValueGroupType *dataBufferBase);
#endif /* #if (ADC_READ_GROUP_API == STD_ON) */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
static inline Adc_ErrorIdType ADC_CheckNotifCapability(Adc_GroupType grpId);
#endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
static inline Adc_ErrorIdType Adc_CheckPowerResultPointer(const Adc_PowerStateRequestResultType
        *resultPtr);
static inline Adc_ErrorIdType Adc_CheckPowerStatePointer(const Adc_PowerStateType *statePtr);
static inline Adc_ErrorIdType Adc_CheckPrePowerStateValid(Adc_PowerStateType targetState);
static inline Adc_PowerCheckType Adc_CheckCurAndTarPowerState(Adc_PowerStateType powerState);
static inline Adc_ErrorIdType Adc_CheckPowerStatePrepare(void);
#endif /* #if (ADC_POWER_STATE_SUPPORTED == STD_ON) */
#if (ADC_VERSION_INFO_API == STD_ON)
static inline Adc_ErrorIdType Adc_CheckVersionPtr(const Std_VersionInfoType *versioninfo);
#endif /* #if (ADC_VERSION_INFO_API == STD_ON) */


/******************************************************************************************
 *                          Global Function Declarations
 *****************************************************************************************/
/** **************************************************************************************
 * \brief This function initializes the ADC hardware units and driver.

 * \verbatim
 * Syntax             : void Adc_Init(
 *                          const Adc_ConfigType* ConfigPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : ConfigPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Initializes the ADC hardware units and driver.
 * \endverbatim
 * Traceability       : SWSR_ADC_051 SWSR_ADC_052 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM002 SW_SM006
 *****************************************************************************************/
void Adc_Init(const Adc_ConfigType *ConfigPtr)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether Adc has been initialized */
    if (ADC_E_ALREADY_INITIALIZED == Adc_CheckInitAlready())
    {
        errorId = ADC_E_ALREADY_INITIALIZED;
    }
    /* #20 check whether ConfigPtr is NULL_PTR */
    else if (ADC_E_PARAM_POINTER == Adc_CheckInitPointer(ConfigPtr))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #30 check whether init in ip level failed */
    else if (ADC_E_INIT_FAIL == Adc_Ip_Init(ConfigPtr))
    {
        errorId = ADC_E_INIT_FAIL;
    }
    else
    {
        /* #40 init group status and Adc power state */
        Adc_ResetGroupStatus(ConfigPtr);
#if (ADC_POWER_STATE_SUPPORTED == STD_ON) /* AdcLowPowerStatesSupport enabled */
        Adc_CurrentPowerState = ADC_FULL_POWER;
        Adc_TargetPowerState = ADC_FULL_POWER;
        Adc_PowerStateChange = ADC_POWER_CHANGE_NOT_START;
#endif /* AdcLowPowerStatesSupport enabled */
        Adc_GlobalConfigPtr = ConfigPtr;
        /* reset adc analog part to full power state */
        /** Traceability       : SWSR_ADC_028 */
        Adc_Ip_SetPowerState(ADC_FULL_POWER);
        Adc_GlobalState = ADC_GLOBAL_STATE_INIT;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #50 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_INIT, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_INIT, errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
#if(ADC_DEINIT_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns all ADC HW Units to a state comparable to
 *        their power on reset state.

 * \verbatim
 * Syntax             : void Adc_DeInit(
 *                          void)

 * Service ID[hex]    : 0x01

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Returns all ADC HW Units to a state comparable to
 *                      their power on reset state.
 * \endverbatim
 * Traceability       : SWSR_ADC_066 SWSR_ADC_068 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *****************************************************************************************/
void Adc_DeInit(void)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check Adc whether is initialized already */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check all groups whether are in ADC_IDLE */
    else if (ADC_E_BUSY == Adc_CheckNoGroupConverting())
    {
        errorId = ADC_E_BUSY;
    }

#if (ADC_HW_TRIGGER_API == STD_ON)
    /* 30 check hw groups whether are triggering implictly */
    else if (ADC_E_HW_BUSY == Adc_CheckHWTriggerring())
    {
        errorId = ADC_E_HW_BUSY;
    }

#endif
    /* #40 deinit all register value */
    else if (ADC_E_DEINIT_FAIL == Adc_Ip_DeInit())
    {
        errorId = ADC_E_DEINIT_FAIL;
    }
    else
    {
        /* #50 deinit group status and Adc power state */
        Adc_GlobalState = ADC_GLOBAL_STATE_UNINIT;
        Adc_ResetGroupStatus(Adc_GlobalConfigPtr);
#if (ADC_POWER_STATE_SUPPORTED == STD_ON) /* AdcLowPowerStatesSupport enabled */
        Adc_CurrentPowerState = ADC_FULL_POWER;
        Adc_TargetPowerState = ADC_FULL_POWER;
#endif /* AdcLowPowerStatesSupport enabled */
        Adc_GlobalConfigPtr = NULL_PTR;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #60 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_DEINIT, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_DEINIT, errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
#endif /* #if(ADC_DEINIT_API == STD_ON) */
/** **************************************************************************************
 * \brief This function provides Adc Group with a result buffer.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_SetupResultBuffer(
 *                          Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
 *

 * Service ID[hex]    : 0x0c

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC channel group
 *                      DataBufferPtr - Pointer to result data buffer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK: result buffer pointer initialized correctly
 *                      E_NOT_OK: operation failed or development error

 * Description        : Initializes ADC driver with the group specific result buffer
 *                      start address where the conversion results will be stored.
 *                      The application has to ensure that the application buffer,
 *                      where DataBufferPtr points to, can hold all the conversion
 *                      results of the specified group.
 *                      The initialization with Adc_SetupResultBuffer is required
 *                      after reset, before a group conversion can be started.
 * \endverbatim
 * Traceability       : SWSR_ADC_059 SWSR_ADC_060 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group,
                                     Adc_ValueGroupType *DataBufferPtr)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    Std_ReturnType setStatus = E_NOT_OK;

    /* #10 check whether the Adc is already intialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId input parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the Group is doing conversion */
    else if (ADC_E_BUSY == Adc_CheckGroupBusySetup(Group))
    {
        errorId = ADC_E_BUSY;
    }
    /* #40 check whether the DataBufferPtr is NULL_PTR. */
    else if (ADC_E_PARAM_POINTER == Adc_CheckSetupAndReadPointer((const Adc_ValueGroupType *)
             DataBufferPtr))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    else
    {
        /* #50 set DataBufferPtr as the group result buffer */
        Adc_SetupResultBufferDetail(Group, DataBufferPtr);
        setStatus = E_OK;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #60 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_SETUP_RESULT_BUFFER, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_SETUP_RESULT_BUFFER,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return setStatus;
}
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/** **************************************************************************************
 * \brief This function start the conversion of all channels of the requested
 *        ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_StartGroupConversion(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x02

 * Sync/Async         : Asynchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Start the conversion of all channels of the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_073 SWSR_ADC_074 SWSR_ADC_075 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_StartGroupConversion(Adc_GroupType Group)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the group trigger source is software trigger */
    else if (ADC_E_WRONG_TRIGG_SRC == Adc_CheckGroupTriggSrc(Group, ADC_TRIGG_SRC_SW))
    {
        errorId = ADC_E_WRONG_TRIGG_SRC;
    }
    /* #40 check whether the group result buffer is not set */
    else if (ADC_E_BUFFER_UNINIT == Adc_CheckBufferUninit(Group))
    {
        errorId = ADC_E_BUFFER_UNINIT;
    }
    else
    {
        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00();

        /* #50 check whether any group is busy in the unit which the group belongs to */
        if (ADC_E_BUSY == Adc_CheckGroupBusyStartApi(Group))
        {
            errorId = ADC_E_BUSY;
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();
        }

#if (ADC_HW_TRIGGER_API == STD_ON)
        /* 60 check hw groups whether are triggering implictly */
        else if (ADC_E_HW_BUSY == Adc_CheckHWTrigStartApi(Group))
        {
            errorId = ADC_E_BUSY;
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();
        }

#endif
        else
        {
            /* #60 update other information */
            Adc_AllGroupInfo[Group].groupStatus = ADC_BUSY;
            Adc_AllGroupInfo[Group].groupConvFinishTime = 0U;
            Adc_AllGroupInfo[Group].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
            Adc_AllGroupInfo[Group].groupConvFinishIndex = 0U;
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();

            /* #70 check whether start failed */
            if (ADC_E_START_FAIL == Adc_Ip_StartGroupConversion(Group))
            {
                errorId = ADC_E_START_FAIL;
                /* change group status to ADC_IDLE */
                Adc_AllGroupInfo[Group].groupStatus = ADC_IDLE;
            }
            else
            {
                /* no error */
                errorId = ADC_NO_ERROR;
            }
        }
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #90 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_START_GROUP_CONVERSION,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_START_GROUP_CONVERSION,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
/** **************************************************************************************
 * \brief This function stop the conversion of all channels of the requested
 *        ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_StopGroupConversion(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x03

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Stop the conversion of all channels of the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_084 SWSR_ADC_085 SWSR_ADC_087 SWSR_ADC_088 SWSR_ADC_089
 *                      SWSR_ADC_194 SW_SM001 SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_StopGroupConversion(Adc_GroupType Group)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the group trigger source is software trigger */
    else if (ADC_E_WRONG_TRIGG_SRC == Adc_CheckGroupTriggSrc(Group, ADC_TRIGG_SRC_SW))
    {
        errorId = ADC_E_WRONG_TRIGG_SRC;
    }
    /* #40 check whether the group is already in ADC_IDLE */
    else if (ADC_E_IDLE == Adc_StopApiCheckGroupIdle(Group))
    {
        errorId = ADC_E_IDLE;
    }
    /* #50 check whether cleaing fifo is time out */
    else if (ADC_E_STOP_FAIL == Adc_Ip_StopGroupConversion(Group))
    {
        errorId = ADC_E_STOP_FAIL;
    }
    else
    {
        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01();
        /* #60 change group status to ADC_IDLE */
        Adc_AllGroupInfo[Group].groupStatus = ADC_IDLE;
        /* #70 change other group information */
        Adc_AllGroupInfo[Group].groupConvFinishTime = 0U;
        Adc_AllGroupInfo[Group].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
        Adc_AllGroupInfo[Group].groupConvFinishIndex = 0U;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) /* AdcGrpNotifCapability enabeld */
        /* #80 disabled group notification */
        Adc_AllGroupInfo[Group].groupNotifStatus = ADC_NOTIFICATION_DISABLED;
#endif /* AdcGrpNotifCapability enabeld */
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01();
        /* no error */
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #90 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_STOP_GROUP_CONVERSION,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_STOP_GROUP_CONVERSION,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
#endif /* #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_READ_GROUP_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns the latest round conversion value of the requested Group.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_ReadGroup(
 *                          Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)

 * Service ID[hex]    : 0x04

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC channel group

 * Parameters (inout) : None

 * Parameters (out)   : DataBufferPtr - ADC results of all channels of the selected group
 *                      are stored in the data buffer addressed with the pointer

 * Return value       : E_OK: results are available and written to the data buffer
 *                      E_NOT_OK: no results are available or development error occured

 * Description        : Reads the group conversion result of the last completed conversion
 *                      round of the requested group and stores the channel values starting
 *                      at the DataBufferPtr address. The group channel values are stored
 *                      in ascending channel number order (in contrast to the storage layout
 *                      of the result buffer if streaming access is configured).
 * \endverbatim
 * Traceability       : SWSR_ADC_011 SWSR_ADC_095 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *                      SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    /* read status */
    Std_ReturnType readResult = E_NOT_OK;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the DataBufferPtr is NULL_PTR */
    else if (ADC_E_PARAM_POINTER == Adc_CheckSetupAndReadPointer((const Adc_ValueGroupType *)
             DataBufferPtr))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #40 check whether the group stores at least one round conversion value */
    else if (ADC_E_IDLE == Adc_ReadApiCheckGroupIdle(Group))
    {
        errorId = ADC_E_IDLE;
    }
    else
    {
        /* #50 detailed reading group operation */
        Adc_ReadGroupDetail(Group, DataBufferPtr);
        /* #60 Update group infomation after reading conversion values */
        Adc_ReadOrGetUpdateGroupStatus(Group);
        /* read result is OK */
        readResult = E_OK;
        /* no error */
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #70 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_READ_GROUP, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_READ_GROUP, errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return readResult;
}
#endif /* #if (ADC_READ_GROUP_API == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
/** **************************************************************************************
 * \brief This function enables the hardware trigger for the requested ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_EnableHardwareTrigger(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x05

 * Sync/Async         : Asynchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Enables the hardware trigger for the requested ADC Channel group
 * \endverbatim
 * Traceability       : SWSR_ADC_166 SWSR_ADC_167 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *                      SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_EnableHardwareTrigger (Adc_GroupType Group)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the group trigger source is hardware trigger */
    else if (ADC_E_WRONG_TRIGG_SRC == Adc_CheckGroupTriggSrc(Group, ADC_TRIGG_SRC_HW))
    {
        errorId = ADC_E_WRONG_TRIGG_SRC;
    }
    /* #40 check whether the group result buffer is not set. */
    else if (ADC_E_BUFFER_UNINIT == Adc_CheckBufferUninit(Group))
    {
        errorId = ADC_E_BUFFER_UNINIT;
    }
    else
    {
        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02();

        /* #50 check whether any group is busy in the Unit which the group belongs to. */
        if (ADC_E_BUSY == Adc_CheckGroupBusyStartApi(Group))
        {
            errorId = ADC_E_BUSY;
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02();
        }
        /* 60 check hw groups whether are triggering implictly */
        else if (ADC_E_HW_BUSY == Adc_CheckHWTrigStartApi(Group))
        {
            errorId = ADC_E_BUSY;
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02();
        }
        else
        {
            /* change group status to ADC_BUSY */
            Adc_AllGroupInfo[Group].groupStatus = ADC_BUSY;
            /* #70 mark adc hardware trigger is enabled */
            Adc_AllGroupInfo[Group].groupHardwareTrigger = ADC_HARDWARE_TRIGGERRING;
            /* #80 change other group information */
            Adc_AllGroupInfo[Group].groupConvFinishTime = 0U;
            Adc_AllGroupInfo[Group].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
            Adc_AllGroupInfo[Group].groupConvFinishIndex = 0U;
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02();

            /* 90 check whether cleaing fifo is time out */
            if (ADC_E_START_FAIL == Adc_Ip_EnableHardwareTrigger(Group))
            {
                errorId = ADC_E_START_FAIL;
                /* change group status to ADC_IDLE */
                Adc_AllGroupInfo[Group].groupStatus = ADC_IDLE;
                /* mark adc hardware trigger is disabled */
                Adc_AllGroupInfo[Group].groupHardwareTrigger = ADC_HARDWARE_NO_TRIGGERRING;
            }
            else
            {
                /* no error */
                errorId = ADC_NO_ERROR;
            }
        }
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #100 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_ENABLE_HARDWARE_TRIGGER,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_ENABLE_HARDWARE_TRIGGER,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
/** **************************************************************************************
 * \brief This function disables the hardware trigger for the requested
 *        ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_DisableHardwareTrigger(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x06

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function disables the hardware trigger for the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_179 SWSR_ADC_180 SWSR_ADC_181 SWSR_ADC_182 SWSR_ADC_192
 *                      SWSR_ADC_194 SW_SM001 SW_SM006 SW_SM007
 *****************************************************************************************/
void Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the group trigger source is hardware trigger */
    else if (ADC_E_WRONG_TRIGG_SRC == Adc_CheckGroupTriggSrc(Group, ADC_TRIGG_SRC_HW))
    {
        errorId = ADC_E_WRONG_TRIGG_SRC;
    }
    /* #40 check whether the group is already in ADC_IDLE */
    else if (ADC_E_IDLE == Adc_StopApiCheckGroupIdle(Group))
    {
        errorId = ADC_E_IDLE;
    }
    /* #50 check whether cleaing fifo is time out */
    else if (ADC_E_STOP_FAIL == Adc_Ip_DisableHardwareTrigger(Group))
    {
        errorId = ADC_E_STOP_FAIL;
    }
    else
    {
        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();
        /* #60 change group status to ADC_IDLE */
        Adc_AllGroupInfo[Group].groupStatus = ADC_IDLE;
        /* #70 mark adc hardware trigger is disabled */
        Adc_AllGroupInfo[Group].groupHardwareTrigger = ADC_HARDWARE_NO_TRIGGERRING;
        /* #80 change other group information */
        Adc_AllGroupInfo[Group].groupConvFinishTime = 0U;
        Adc_AllGroupInfo[Group].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
        Adc_AllGroupInfo[Group].groupConvFinishIndex = 0U;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) /* AdcGrpNotifCapability enabeld */
        Adc_AllGroupInfo[Group].groupNotifStatus = ADC_NOTIFICATION_DISABLED;
#endif /* AdcGrpNotifCapability enabeld */
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
        /* no error */
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #90 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_DISABLE_HARDWARE_TRIGGER,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_DISABLE_HARDWARE_TRIGGER,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
#if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/** **************************************************************************************
 * \brief This function enables the notification mechanism for
 *        the requested ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_EnableGroupNotification(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x07

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function enables the notification mechanism for
 *                      the requested ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_018 SWSR_ADC_104 SWSR_ADC_105 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
void Adc_EnableGroupNotification(Adc_GroupType Group)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the group notification is NULL_PTR */
    else if (ADC_E_NOTIF_CAPABILITY == ADC_CheckNotifCapability(Group))
    {
        errorId = ADC_E_NOTIF_CAPABILITY;
    }
    else
    {
        /* #40 Enable the group notification software flag. */
        Adc_AllGroupInfo[Group].groupNotifStatus = ADC_NOTIFICATION_ENABLED;
        /* no error */
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #50 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_ENABLE_GROUP_NOTIFICATION,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_API_ENABLE_GROUP_NOTIFICATION, errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
/** **************************************************************************************
 * \brief This function disables the notification mechanism for the
 *        requested ADC Channel group.

 * \verbatim
 * Syntax             : void Adc_DisableGroupNotification(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x08

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function disables the notification mechanism for the
 *                      requested ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_110 SWSR_ADC_111 SWSR_ADC_192 SWSR_ADC_194 SW_SM001
 *                      SW_SM006
 *****************************************************************************************/
void Adc_DisableGroupNotification(Adc_GroupType Group)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    /* #30 check whether the group notification is NULL_PTR */
    else if (ADC_E_NOTIF_CAPABILITY == ADC_CheckNotifCapability(Group))
    {
        errorId = ADC_E_NOTIF_CAPABILITY;
    }
    else
    {
        /* #40 Enable the group notification software flag */
        Adc_AllGroupInfo[Group].groupNotifStatus = ADC_NOTIFICATION_DISABLED;
        /* no error */
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #50 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_DISABLE_GROUP_NOTIFICATION,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID,
                                   ADC_API_DISABLE_GROUP_NOTIFICATION, errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
#endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
/** **************************************************************************************
 * \brief This function returns the conversion status of the requested ADC Channel group.

 * \verbatim
 * Syntax             : Adc_StatusType Adc_GetGroupStatus(
 *                          Adc_GroupType Group)

 * Service ID[hex]    : 0x09

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : Conversion status for the requested group

 * Description        : This function returns the conversion status of the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_012 SWSR_ADC_116 SWSR_ADC_117 SWSR_ADC_118 SWSR_ADC_119
 *                      SWSR_ADC_120 SWSR_ADC_192 SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    Adc_StatusType grpStatus = ADC_IDLE;

    /* #10 check whether ADC is already initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
    }
    /* #20 check whether the grpId parameter is out of range */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
    }
    else
    {
        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();
        /* #30 get the group status */
        grpStatus = Adc_AllGroupInfo[Group].groupStatus;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
        /* no error */
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #40 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_GROUP_STATUS, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_GROUP_STATUS,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return grpStatus;
}
/** **************************************************************************************
 * \brief This function returns the number of valid samples per channel and points to
 *        a position of the last completed conversion.

 * \verbatim
 * Syntax             : Adc_StreamNumSampleType Adc_GetStreamLastPointer(
 *                          Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr)

 * Service ID[hex]    : 0x0b

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : Group - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : PtrToSamplePtr - Pointer to result buffer pointer

 * Return value       : Number of valid samples per channel

 * Description        : Returns the number of valid samples per channel, stored in the
 *                      result buffer.Reads a pointer, pointing to a position in the
 *                      group result buffer. With the pointer position, the results of
 *                      all group channels of the last completed conversion round can be
 *                      accessed.With the pointer and the return value, all valid group
 *                      conversion results can be accessed (the user has to take the
 *                      layout of the result buffer into account).
 * \endverbatim
 * Traceability       : SWSR_ADC_010 SWSR_ADC_123 SWSR_ADC_126 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group,
        Adc_ValueGroupType **PtrToSamplePtr)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    Adc_StreamNumSampleType resultConut = 0U;

    /* #10 check whether the DataBufferPtr is NULL_PTR. */
    /*PRQA S 0310  2*/
    if (ADC_E_PARAM_POINTER == Adc_CheckGetStreamPointer(PtrToSamplePtr))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #20 check whether ADC is already initialized. */
    else if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
        *PtrToSamplePtr = NULL_PTR;
    }
    /* #30 check whether the grpId parameter is out of range. */
    else if (ADC_E_PARAM_GROUP == Adc_CheckParameterGroup(Group))
    {
        errorId = ADC_E_PARAM_GROUP;
        *PtrToSamplePtr = NULL_PTR;
    }
    /* #40 check the group whether stores at least one round conversion value. */
    else if (ADC_E_IDLE == Adc_ReadApiCheckGroupIdle(Group))
    {
        errorId = ADC_E_IDLE;
        *PtrToSamplePtr = NULL_PTR;
    }
    else
    {
        /* #50 Detailed getting group operation. */
        resultConut = Adc_GetStreamLastPointerDetail(Group, PtrToSamplePtr);
        /* #60 Update Group infomation after getting last pointer. */
        Adc_ReadOrGetUpdateGroupStatus(Group);
        /* no error */
        errorId = ADC_NO_ERROR;
    } /* else not needed */

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #70 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_STREAM_LAST_POINTER,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_STREAM_LAST_POINTER,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return resultConut;
}
#if (ADC_VERSION_INFO_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void Adc_GetVersionInfo(
 *                          Std_VersionInfoType* versioninfo)

 * Service ID[hex]    : 0x0a

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : versioninfo - Pointer to where to store the version information
 *                      of this module

 * Return value       : None

 * Description        : Returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_ADC_131 SWSR_ADC_192 SWSR_ADC_194 SW_SM006
 *****************************************************************************************/
void Adc_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    /* error code number */
    Adc_ErrorIdType errorId;

    /* #10 check whether the input parameter pointer is NULL_PTR */
    if (ADC_E_PARAM_POINTER == Adc_CheckVersionPtr(versioninfo))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #20 get adc module information */
    else
    {
        (versioninfo)->vendorID = (uint16)ADC_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)ADC_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)ADC_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)ADC_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)ADC_SW_PATCH_VERSION;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #30 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_VERSION_INFO, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_VERSION_INFO,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return;
}
#endif /* #if (ADC_VERSION_INFO_API == STD_ON) */
#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/** **************************************************************************************
 * \brief This function sets Adc power state.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_SetPowerState(
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x10

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED: Power state change executed
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized
 *                      ADC_SEQUENCE_ERROR: wrong API call sequence

 * Return value       : E_OK: Power Mode changed
 *                      E_NOT_OK: request rejected

 * Description        : This API configures the Adc module so that it enters the already
 *                      prepared power state, chosen between a predefined set of configured
 *                      ones.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_027 SWSR_ADC_030 SWSR_ADC_133 SWSR_ADC_135
 *                      SWSR_ADC_192 SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType *Result)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    Std_ReturnType setResult = E_NOT_OK;

    /* #10 check whether the input parameter is NULL_PTR */
    if (ADC_E_PARAM_POINTER == Adc_CheckPowerResultPointer(Result))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #20 check whether ADC is already initialized */
    else if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
        *Result = ADC_NOT_INIT;
    }
    /* #30 check whether all adc groups are idle */
    else if (ADC_E_BUSY == Adc_CheckNoGroupConverting())
    {
        errorId = ADC_E_NOT_DISENGAGED;
        *Result = ADC_TRANS_NOT_POSSIBLE;
    }
    /* #40 check whether Adc_PreparePowerState has been called */
    else if (ADC_E_PERIPHERAL_NOT_PREPARED == Adc_CheckPowerStatePrepare())
    {
        errorId = ADC_E_PERIPHERAL_NOT_PREPARED;
        *Result = ADC_SEQUENCE_ERROR;
    }
    else
    {
        /* #50 check whether target state is not current power state */
        if (ADC_POWER_DIFF == Adc_CheckCurAndTarPowerState(Adc_CurrentPowerState))
        {
            /* #60 if target state is not current power state,change power state */
            Adc_Ip_SetPowerState(Adc_TargetPowerState);
        } /* else not needed */

        Adc_CurrentPowerState = Adc_TargetPowerState;
        Adc_PowerStateChange = ADC_POWER_CHANGE_NOT_START;
        *Result = ADC_SERVICE_ACCEPTED;
        setResult = (Std_ReturnType)E_OK;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #70 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_SET_POWER_STATE, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_SET_POWER_STATE,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return setResult;
}
/** **************************************************************************************
 * \brief This function returns the current power state of the ADC HW unit.

 * \verbatim
 * Syntax             : Std_ReturnType GetCurrentPowerState(
 *                          Adc_PowerStateType* CurrentPowerState,
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x11

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : CurrentPowerState - The current power mode of the ADC HW Unit
 *                      is returned in this parameter
 *                      Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED: Current power mode was returned
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized

 * Return value       : E_OK: Mode could be read
 *                      E_NOT_OK: Service is rejected

 * Description        : This API returns the current power state of the ADC HW unit.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_024 SWSR_ADC_027 SWSR_ADC_142 SWSR_ADC_192
 *                      SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType *CurrentPowerState,
                                        Adc_PowerStateRequestResultType *Result)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    Std_ReturnType getCurrentResult = E_NOT_OK;

    /* #10 check whether the input parameter result pointer is NULL_PTR */
    if (ADC_E_PARAM_POINTER == Adc_CheckPowerResultPointer(Result))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #20 check whether ADC is already initialized */
    else if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
        *Result = ADC_NOT_INIT;
    }
    /* #30 check whether the input parameter power state pointer is NULL_PTR */
    else if (ADC_E_PARAM_POINTER == Adc_CheckPowerStatePointer(CurrentPowerState))
    {
        errorId = ADC_E_PARAM_POINTER;
        *Result = ADC_SEQUENCE_ERROR;
    }
    else
    {
        /* #40 pointer to current power state */
        *CurrentPowerState = Adc_CurrentPowerState;
        *Result = ADC_SERVICE_ACCEPTED;
        getCurrentResult = E_OK;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #50 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_CURRENT_POWER_STATE,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_CURRENT_POWER_STATE,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return getCurrentResult;
}
/** **************************************************************************************
 * \brief This function rreturns the Target power state of the ADC HW unit.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_GetTargetPowerState(
 *                          Adc_PowerStateType* TargetPowerState
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x12

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : configPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : TargetPowerState - The Target power mode of the ADC HW Unit
 *                      is returned in this parameter
 *                      Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED:Target power mode was returned
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized

 * Return value       : E_OK: Mode could be read
 *                      E_NOT_OK: Service is rejected

 * Description        : This function rreturns the Target power state of the ADC HW unit.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_024 SWSR_ADC_027 SWSR_ADC_144 SWSR_ADC_145
 *                      SWSR_ADC_192 SWSR_ADC_194 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType *TargetPowerState,
                                       Adc_PowerStateRequestResultType *Result)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    Std_ReturnType getTargetResult = E_NOT_OK;

    /* #10 check whether the input parameter result pointer is NULL_PTR */
    if (ADC_E_PARAM_POINTER == Adc_CheckPowerResultPointer(Result))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #20 check whether ADC is already initialized */
    else if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
        *Result = ADC_NOT_INIT;
    }
    /* #30 check whether the input parameter power state pointer is NULL_PTR */
    else if (ADC_E_PARAM_POINTER == Adc_CheckPowerStatePointer(TargetPowerState))
    {
        errorId = ADC_E_PARAM_POINTER;
        *Result = ADC_SEQUENCE_ERROR;
    }
    else
    {
        /* #40 pointer to target power state */
        *TargetPowerState = Adc_TargetPowerState;
        *Result = ADC_SERVICE_ACCEPTED;
        getTargetResult = E_OK;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #50 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_TARGET_POWER_STATE,
                              errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_GET_TARGET_POWER_STATE,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return getTargetResult;
}
/** **************************************************************************************
 * \brief This function starts the needed process to allow the ADC HW module to enter the
 *        requested power state.

 * \verbatim
 * Syntax             : Std_ReturnType Adc_PreparePowerState(
 *                          Adc_PowerStateType PowerState,
 *                          Adc_PowerStateRequestResultType* Result)

 * Service ID[hex]    : 0x13

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : PowerState - The target power state intended to be attained

 * Parameters (inout) : None

 * Parameters (out)   : Result - If the API returns E_OK:
 *                      ADC_SERVICE_ACCEPTED: ADC Module power state preparation was
 *                      started.
 *                      If the API returns E_NOT_OK:
 *                      ADC_NOT_INIT: ADC Module not initialized
 *                      ADC_SEQUENCE_ERROR: wrong API call sequence (Current
 *                      Power State = Target Power State)
 *                      ADC_POWER_STATE_NOT_SUPP: ADC Module does not
 *                      support the requested power state
 *                      ADC_TRANS_NOT_POSSIBLE: ADC Module cannot transition
 *                      directly from the current power state

 * Return value       : E_OK: Preparation process started
 *                      E_NOT_OK: Service is rejected

 * Description        : This function starts the needed process to allow the ADC HW module to enter the
 *                      requested power state.
 * \endverbatim
 * Traceability       : SWSR_ADC_023 SWSR_ADC_025 SWSR_ADC_027 SWSR_ADC_030
 *                      SWSR_ADC_134 SWSR_ADC_147 SWSR_ADC_192 SWSR_ADC_194
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState,
                                     Adc_PowerStateRequestResultType *Result)
{
    /* error code number */
    Adc_ErrorIdType errorId;
    Std_ReturnType prepareResult = E_NOT_OK;

    /* #10 check whether the input parameter pointer is NULL_PTR */
    if (ADC_E_PARAM_POINTER == Adc_CheckPowerResultPointer(Result))
    {
        errorId = ADC_E_PARAM_POINTER;
    }
    /* #20 check whether ADC is already initialized */
    else if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        errorId = ADC_E_UNINIT;
        *Result = ADC_NOT_INIT;
    }
    /* #30 check whether the target power state is valid */
    else if (ADC_E_POWER_STATE_NOT_SUPPORTED == Adc_CheckPrePowerStateValid(PowerState))
    {
        errorId = ADC_E_POWER_STATE_NOT_SUPPORTED;
        *Result = ADC_POWER_STATE_NOT_SUPP;
    }
    /* #40 check whether the target power state is the same as current target power state */
    else if (ADC_POWER_SAME == Adc_CheckCurAndTarPowerState(PowerState))
    {
        errorId = ADC_E_PREPARE_SAME_STATE;
        *Result = ADC_SEQUENCE_ERROR;
    }
    else
    {
        /* #50 set target power state */
        Adc_TargetPowerState = PowerState;
        *Result = ADC_SERVICE_ACCEPTED;
        Adc_PowerStateChange = ADC_POWER_CHANGE_START;
        prepareResult = E_OK;
        errorId = ADC_NO_ERROR;
    }

#if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON))

    /* #60 if DET is enabled,reprot DET error first meet */
    if (ADC_NO_ERROR != errorId)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_PREPARE_POWER_STATE, errorId);
#endif /* #if (ADC_DEV_ERROR_DETECT == STD_ON) */
#if (ADC_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError((uint16)ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_API_PREPARE_POWER_STATE,
                                   errorId);
#endif /** #if (ADC_SAFETY_ENABLE == STD_ON) */
    } /* else not needed */

#else
    ADC_DUMMY_STATEMENT(errorId);
#endif /* #if ((ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON)) */
    return prepareResult;
}
#endif /* #if (ADC_POWER_STATE_SUPPORTED == STD_ON) */
/** **************************************************************************************
 * \brief This function checks whether Adc Driver is already initialized.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckInitAlready(
 *                          void)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function checks whether Adc Driver is already initialized
 * \endverbatim
 * Traceability       : SWSR_ADC_058 SW_SM002
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckInitAlready(void)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether Adc has been initialized */
    if (ADC_GLOBAL_STATE_INIT == Adc_GlobalState)
    {
        errorStatus = ADC_E_ALREADY_INITIALIZED;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether Adc_Init is called with a NULL_PTR.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckInitPointer(
 *                          const Adc_ConfigType* adcConfigPtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : adcConfigPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_PARAM_POINTER: Input configuration is NULL_PTR
 *                      Others: No error

 * Description        : This function checks whether Adc_Init is called with a NULL_PTR.
 * \endverbatim
 * Traceability       : SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckInitPointer(const Adc_ConfigType *adcConfigPtr)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the buffer is NULL_PTR */
    if (NULL_PTR == adcConfigPtr)
    {
        errorStatus = ADC_E_PARAM_POINTER;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether circular mode group is triggerring.

 * \verbatim
 * Syntax             : void Adc_CheckCircularGroup(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_BUSY  :Group is converting
 *                      Others: No error

 * Description        : This function checks whether circular mode group is triggerring.
 * \endverbatim
 * Traceability       : SWSR_ADC_069 SWSR_ADC_071 SWSR_ADC_080 SWSR_ADC_081 SWSR_ADC_134
 *                      SWSR_ADC_138 SWSR_ADC_172
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckCircularGroup(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorValue = 0U;

    /* #10 check whether group status is ADC_STREAM_COMPLETED */
    if (ADC_STREAM_COMPLETED == Adc_AllGroupInfo[grpId].groupStatus)
    {
        /* #20 check whether group is steaming access mode */
        if (ADC_ACCESS_MODE_STREAMING == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].groupAccessMode)
        {
            /* #30 check whether group is circular buffer mode */
            if (ADC_STREAM_BUFFER_CIRCULAR == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].strBufferMode)
            {
                errorValue = ADC_E_BUSY;
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */

    return errorValue;
}
/** **************************************************************************************
 * \brief This function checks whether group id is out of range.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckParameterGroup(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_PARAM_GROUP:  Input group id is out of range.
 *                      Others: No error

 * Description        : This function checks whether group id is out of range
 * \endverbatim
 * Traceability       : SWSR_ADC_062 SWSR_ADC_078 SWSR_ADC_092 SWSR_ADC_102
 *                      SWSR_ADC_107 SWSR_ADC_113 SWSR_ADC_121 SWSR_ADC_129
 *                      SWSR_ADC_174 SWSR_ADC_185 SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckParameterGroup(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether groupId is out of range */
    if (grpId >= Adc_GlobalConfigPtr->groupCountAllUnit)
    {
        errorStatus = ADC_E_PARAM_GROUP;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether pointer is NULL_PTR.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckSetupAndReadPointer(
 *                          const Adc_ValueGroupType* bufferPtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : bufferPtr - Pointer supplied by user

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_PARAM_POINTER: Input pointer is NULL_PTR
 *                      Other: No error

 * Description        : This function checks whether pointer is NULL_PTR.
 * \endverbatim
 * Traceability       : SWSR_ADC_065 SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckSetupAndReadPointer(const Adc_ValueGroupType *bufferPtr)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the buffer is NULL_PTR */
    if (NULL_PTR == bufferPtr)
    {
        errorStatus = ADC_E_PARAM_POINTER;
    } /* else not needed */

    return errorStatus;
}
/*PRQA S 3673  31*/
/** **************************************************************************************
 * \brief This function checks whether the input pointer is NULL_PTR
 *        for Adc_GetStreamLastPointer.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckGetStreamPointer(
 *                          Adc_ValueGroupType ** pointToSamplePtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : configPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_PARAM_POINTER: Input pointer is NULL_PTR
 *                      Others: No error

 * Description        : This function checks whether the input pointer is NULL_PTR
 *                      for Adc_GetStreamLastPointer.
 * \endverbatim
 * Traceability       : SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckGetStreamPointer(
    Adc_ValueGroupType **pointToSamplePtr)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the buffer is NULL_PTR. */
    if (NULL_PTR == pointToSamplePtr)
    {
        errorStatus = ADC_E_PARAM_POINTER;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether current group is ADC_IDLE or not.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckGroupBusySetup(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_BUSY: Group is not ADC_IDLE
 *                      Others: No error

 * Description        : This function checks whether current group is ADC_IDLE or not.
 * \endverbatim
 * Traceability       : SWSR_ADC_063
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckGroupBusySetup(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether group is already ADC_IDLE */
    if (ADC_IDLE != Adc_AllGroupInfo[grpId].groupStatus)
    {
        errorStatus = ADC_E_BUSY;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether group has updated at least one round conversion
 *        values.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_ReadApiCheckGroupIdle(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_IDLE: No conversion values can be get
 *                      Other: No errors

 * Description        : This function checks whether group has updated at least one
 *                      round conversion values.
 * \endverbatim
 * Traceability       : SWSR_ADC_013 SWSR_ADC_101 SWSR_ADC_126 SWSR_ADC_128
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_ReadApiCheckGroupIdle(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the group stores at least one round conversion value */
    if (ADC_CONVERSION_NO_UPDATE == Adc_AllGroupInfo[grpId].groupValueStatus)
    {
        errorStatus = ADC_E_IDLE;
    } /* else not needed */

    return errorStatus;
}
#if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON) \
|| (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON))
/** **************************************************************************************
 * \brief This function checks whether single access group is triggerring.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_CheckSingleGroup(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_BUSY  :Group is converting
 *                      Others: No error

 * Description        : This function checks whether single access group is triggerring.
 * \endverbatim
 * Traceability       : SWSR_ADC_069 SWSR_ADC_071 SWSR_ADC_080 SWSR_ADC_081 SWSR_ADC_134
 *                      SWSR_ADC_138 SWSR_ADC_172
 *****************************************************************************************/
static Adc_ErrorIdType Adc_CheckSingleGroup(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorValue = 0U;

    /* #10 check whether group status is ADC_STREAM_COMPLETED */
    if (ADC_STREAM_COMPLETED == Adc_AllGroupInfo[grpId].groupStatus)
    {
        /* #20 check whether group is single access mode */
        if (ADC_ACCESS_MODE_SINGLE == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].groupAccessMode)
        {
            /* #30 check group trigger source */
            if (ADC_TRIGG_SRC_SW == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].triggerSource)
            {
                /* #40 check whether group is continuous conversion mode */
                if (ADC_CONV_MODE_CONTINUOUS == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].groupConvMode)
                {
                    errorValue = ADC_E_BUSY;
                } /* else not needed */
            }
            else
            {
                /* hw trigger group single access and one-shot will repeat conversion */
                errorValue = ADC_E_BUSY;
            }
        } /* else not needed */
    } /* else not needed */

    return errorValue;
}
#endif /* #if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON)
|| (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)) */
#if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON))
/** **************************************************************************************
 * \brief This function checks whether any group is converting.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_CheckNoGroupConverting(
 *                          Dvoid)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : void

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_BUSY: There is any group converting
 *                      Other:  No group is converting

 * Description        : This function checks whether any group is converting.
 * \endverbatim
 * Traceability       : SWSR_ADC_069 SWSR_ADC_071 SWSR_ADC_134 SWSR_ADC_138
 *****************************************************************************************/
static Adc_ErrorIdType Adc_CheckNoGroupConverting(void)
{
    Adc_ErrorIdType errorStatus = 0U;
    Adc_GroupType groupIndex = 0U;

    /* check all group status */
    for (; groupIndex < Adc_GlobalConfigPtr->groupCountAllUnit; groupIndex++)
    {
        /* #10 whether any group is ADC_BUSY */
        if (ADC_BUSY == Adc_AllGroupInfo[groupIndex].groupStatus)
        {
            errorStatus = ADC_E_BUSY;
        }
        /* #20 whether any group is ADC_COMPLETED */
        else if (ADC_COMPLETED == Adc_AllGroupInfo[groupIndex].groupStatus)
        {
            errorStatus = ADC_E_BUSY;
        }
        /* #30 whether any group is ADC_STREAM_COMPLETED and buffer circular mode  */
        else if (ADC_E_BUSY == Adc_CheckCircularGroup(groupIndex))
        {
            errorStatus = ADC_E_BUSY;
        }
        /* #40 whether any group is ADC_STREAM_COMPLETED and single access mode */
        /* check continous mode for software trigger and one-shot mode for hardware trigger */
        else if (ADC_E_BUSY == Adc_CheckSingleGroup(groupIndex))
        {
            errorStatus = ADC_E_BUSY;
        }
        else
        {
            /* do nothing */
        }

        /* check whether ADC_E_BUSY has happened */
        if (ADC_E_BUSY == errorStatus)
        {
            break;
        }
    }

    return errorStatus;
}
#endif /* #if ((ADC_POWER_STATE_SUPPORTED == STD_ON) || (ADC_DEINIT_API == STD_ON)) */
/** **************************************************************************************
 * \brief This function resets all group information.

 * \verbatim
 * Syntax             : static void Adc_ResetGroupStatus(
 *                          const Adc_ConfigType* AdcConfigPtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : AdcConfigPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function resets all group information
 * \endverbatim
 * Traceability       : SWSR_ADC_056 SWSR_ADC_057
 *****************************************************************************************/
static void Adc_ResetGroupStatus(const Adc_ConfigType *AdcConfigPtr)
{
    Adc_GroupType groupIndex = 0U;

#if (ADC_OVERVOLTAGE_DETECT == STD_ON) /* AdcOverVoltageDetect enabled */
    Adc_ChannelType channelIndex = 0U;
#endif /* AdcOverVoltageDetect enabled */

    for (; groupIndex < AdcConfigPtr->groupCountAllUnit; groupIndex++)
    {
        /* #10 all Adc groups status are changed to ADC_IDLE */
        Adc_AllGroupInfo[groupIndex].groupStatus = ADC_IDLE;
        /* #20 all adc groups are conversion done */
        Adc_AllGroupInfo[groupIndex].groupConvStatus = ADC_ALREADY_FINISHED_CONVERTED;
        /* #30 no conversion results can be available */
        Adc_AllGroupInfo[groupIndex].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) /* AdcGrpNotifCapability enabeld */
        /* #40 group nofification is disabled */
        Adc_AllGroupInfo[groupIndex].groupNotifStatus = ADC_NOTIFICATION_DISABLED;
#endif /* AdcGrpNotifCapability enabeld */
#if(ADC_HW_TRIGGER_API == STD_ON)
        Adc_AllGroupInfo[groupIndex].groupHardwareTrigger = ADC_HARDWARE_NO_TRIGGERRING;
#endif /* #if(ADC_HW_TRIGGER_API == STD_ON) */
        /* #50 no conversion round has been finished yet */
        Adc_AllGroupInfo[groupIndex].groupConvFinishTime = 0U;
        /* #60 release all group result buffer */
        AdcConfigPtr->adcGroupCfgPtr[groupIndex].bufferBasePtr = NULL_PTR;
        /* if detect overVoltage is STD_ON */
#if (ADC_OVERVOLTAGE_DETECT == STD_ON)
        /* #70 all groups are not detected yet */
        Adc_AllGroupInfo[groupIndex].groupDetectStatus = ADC_GROUP_UNDETECTED;

        for (; channelIndex < AdcConfigPtr->adcGroupCfgPtr[groupIndex].channelCount; channelIndex++)
        {
            /* #80 all channels in groups are normal status now */
            Adc_AllGroupInfo[groupIndex].channelDetectStatus[channelIndex] = ADC_CHANNE_DET_NORMAL;
        }

        channelIndex = 0U;
#endif
    }
}
/** **************************************************************************************
 * \brief This function sets and initializes result buffer for requested group.

 * \verbatim
 * Syntax             : static void Adc_SetupResultBufferDetail(
 *                          Adc_GroupType grpId, Adc_ValueGroupType* bufferPtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group
 *                      bufferPtr - Group result buffer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function sets and initializes result buffer for
 *                      requested group.
 * \endverbatim
 * Traceability       : SWSR_ADC_060
 *****************************************************************************************/
static void Adc_SetupResultBufferDetail(Adc_GroupType grpId, Adc_ValueGroupType *bufferPtr)
{
    /* group configuration */
    const Adc_GroupConfigType *groupCfg = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId];
    /* value index */
    uint32 valueIndex = 0UL;

    for (; valueIndex < (groupCfg->samplingTime * groupCfg->channelCount); valueIndex++)
    {
        /* initialize buffer */
        bufferPtr[valueIndex] = 0UL;
    }

    /* set buffer for group */
    Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].bufferBasePtr = bufferPtr;
    return;
}
/** **************************************************************************************
 * \brief This function updates group status for single access & one-shot mode gorups.

 * \verbatim
 * Syntax             : static void Adc_UpdGrpStaForSingleOneShotReadApi(
 *                          Adc_GroupType singleOneShotGrpId,
 *                          const Adc_GroupConfigType* groupCfgPtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : singleOneShotGrpId - Numeric ID of requested ADC Channel group
 *                      groupCfgPtr - Group configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function updates group status for single access &
 *                      one-shot mode gorups.
 * \endverbatim
 * Traceability       : SWSR_ADC_098 SWSR_ADC_099
 *****************************************************************************************/
static void Adc_UpdGrpStaForSingleOneShotReadApi(Adc_GroupType singleOneShotGrpId,
        const Adc_GroupConfigType *groupCfgPtr)
{
    if (ADC_STREAM_COMPLETED == Adc_AllGroupInfo[singleOneShotGrpId].groupStatus)
    {
        if (ADC_TRIGG_SRC_SW == groupCfgPtr->triggerSource)
        {
            /*#10 single access & one-shot & software trigger group change status to ADC_IDLE */
            Adc_AllGroupInfo[singleOneShotGrpId].groupStatus = ADC_IDLE;
        }
        else
        {
            /*#20 single access & one-shot & hardware trigger group change status to ADC_BUSY */
            Adc_AllGroupInfo[singleOneShotGrpId].groupStatus = ADC_BUSY;
        }
    } /* else not needed */

    /* #30 change other group infomation */
    Adc_AllGroupInfo[singleOneShotGrpId].groupConvFinishTime = 0U;
    Adc_AllGroupInfo[singleOneShotGrpId].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
    Adc_AllGroupInfo[singleOneShotGrpId].groupConvFinishIndex = 0U;
}
/** **************************************************************************************
 * \brief This function updates group status for single access & continuous mode &
 *        software trigger gorups.

 * \verbatim
 * Syntax             : static void Adc_UpdGrpStaForSingleContiReadApi(
 *                          Adc_GroupType singleContiGrpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : singleContiGrpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function updates group status for single access &
 *                      continuous mode & software trigger gorups.
 * \endverbatim
 * Traceability       : SWSR_ADC_098
 *****************************************************************************************/
static void Adc_UpdGrpStaForSingleContiReadApi(Adc_GroupType singleContiGrpId)
{
    if (ADC_STREAM_COMPLETED == Adc_AllGroupInfo[singleContiGrpId].groupStatus)
    {
        /* #10 single access & continuous & software trigger group change status to ADC_BUSY */
        Adc_AllGroupInfo[singleContiGrpId].groupStatus = ADC_BUSY;
    } /* else not needed */

    /* #20 change other group infomation */
    Adc_AllGroupInfo[singleContiGrpId].groupConvFinishTime = 0U;
    Adc_AllGroupInfo[singleContiGrpId].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
    Adc_AllGroupInfo[singleContiGrpId].groupConvFinishIndex = 0U;
}
/** **************************************************************************************
 * \brief This function updates group status for streaming access & linear mode
 *        gorups.

 * \verbatim
 * Syntax             : static void Adc_UpdGrpStaForLinearReadApi(
 *                          Adc_GroupType linearGrpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : linearGrpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function updates group status for streaming access
 *                      & linear mode gorups.
 * \endverbatim
 * Traceability       : SWSR_ADC_099 SWSR_ADC_127
 *****************************************************************************************/
static void Adc_UpdGrpStaForLinearReadApi(Adc_GroupType linearGrpId)
{
    if (ADC_COMPLETED == Adc_AllGroupInfo[linearGrpId].groupStatus)
    {
        /* #10 when group is ADC_COMPLETED */
        /* streaming access & linear buffer group change status to ADC_BUSY */
        Adc_AllGroupInfo[linearGrpId].groupStatus = ADC_BUSY;
    }
    else if (ADC_STREAM_COMPLETED == Adc_AllGroupInfo[linearGrpId].groupStatus)
    {
        /* #20 when group is ADC_STREAM_COMPLETED */
        /* streaming access & linear buffer group change status to ADC_IDLE */
        Adc_AllGroupInfo[linearGrpId].groupStatus = ADC_IDLE;
    }
    else
    {
        /* do nothing */
    }

    /* #30 change other group infomation */
    Adc_AllGroupInfo[linearGrpId].groupConvFinishTime = 0U;
    Adc_AllGroupInfo[linearGrpId].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
    Adc_AllGroupInfo[linearGrpId].groupConvFinishIndex = 0U;
    return;
}
/** **************************************************************************************
 * \brief This function updates group status for streaming access & circular mode
 *        gorups.

 * \verbatim
 * Syntax             : static void Adc_UpdGrpStaForCircularReadApi(
 *                          Adc_GroupType circularGrpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : circularGrpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function updates group status for streaming access
 *                      & circular mode mode gorups.
 * \endverbatim
 * Traceability       : SWSR_ADC_098 SWSR_ADC_127
 *****************************************************************************************/
static void Adc_UpdGrpStaForCircularReadApi(Adc_GroupType circularGrpId)
{
    if ((ADC_COMPLETED == Adc_AllGroupInfo[circularGrpId].groupStatus) ||
            (ADC_STREAM_COMPLETED == Adc_AllGroupInfo[circularGrpId].groupStatus))
    {
        /* #10 when group is ADC_COMPLETED/ADC_STREAM_COMPLETED */
        /* streaming access & circular buffer group change status to ADC_BUSY */
        Adc_AllGroupInfo[circularGrpId].groupStatus = ADC_BUSY;
    }
    else
    {
        /* do nothing */
    }

    /* #20 change other group infomation */
    Adc_AllGroupInfo[circularGrpId].groupConvFinishTime = 0U;
    Adc_AllGroupInfo[circularGrpId].groupValueStatus = ADC_CONVERSION_NO_UPDATE;
    Adc_AllGroupInfo[circularGrpId].groupConvFinishIndex = 0U;
    return;
}
/** **************************************************************************************
 * \brief This function updates group status for Adc_ReadGroup/Adc_GetStreamLastPointer.

 * \verbatim
 * Syntax             : static void Adc_ReadOrGetUpdateGroupStatus(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function updates group status for Adc_ReadGroup
 *                      /Adc_GetStreamLastPointer.
 * \endverbatim
 * Traceability       : SWSR_ADC_098 SWSR_ADC_099 SWSR_ADC_127
 *****************************************************************************************/
static void Adc_ReadOrGetUpdateGroupStatus(Adc_GroupType grpId)
{
    const Adc_GroupConfigType *grpCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId];

    /* #10 group is single access mode */
    if (ADC_ACCESS_MODE_SINGLE == grpCfgPtr->groupAccessMode)
    {
        /* #20 group is one-shot mode */
        if (ADC_CONV_MODE_ONESHOT == grpCfgPtr->groupConvMode)
        {
            /* enter critical zone */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
            Adc_UpdGrpStaForSingleOneShotReadApi(grpId, grpCfgPtr);
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
        }
        /* #30 group is continuous mode */
        else
        {
            /* enter critical zone */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
            Adc_UpdGrpStaForSingleContiReadApi(grpId);
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
        }
    }
    /* #40 group is streaming access mode */
    else
    {
        /* #50 group is linear buffer mode */
        if (ADC_STREAM_BUFFER_LINEAR == grpCfgPtr->strBufferMode)
        {
            /* enter critical zone */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
            Adc_UpdGrpStaForLinearReadApi(grpId);
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
        }
        /* #60 group is circular buffer mode */
        else
        {
            /* enter critical zone */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
            Adc_UpdGrpStaForCircularReadApi(grpId);
            /* exit critical zone */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
        }
    }

    return;
}
/** **************************************************************************************
 * \brief This function points to the latest result of the first group channel of the
 *        last completed conversion round.

 * \verbatim
 * Syntax             : static Adc_StreamNumSampleType Adc_GetStreamLastPointerDetail(
 *                          Adc_GroupType grpId,
 *                          Adc_ValueGroupType** pointToSamplePtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group
 *                      pointToSamplePtr - Pointer to result buffer pointer

 * Parameters (inout) : None

 * Parameters (out)   : pointToSamplePtr -

 * Return value       : The number of valid samples per channel, stored in the
 *                      ADC result buffer.

 * Description        : This function points to the latest result of the first group
 *                      channel of the last completed conversion round.
 * \endverbatim
 * Traceability       : SWSR_ADC_124 SWSR_ADC_125
 *****************************************************************************************/
static Adc_StreamNumSampleType Adc_GetStreamLastPointerDetail(Adc_GroupType grpId,
        Adc_ValueGroupType **pointToSamplePtr)
{
    Adc_StreamNumSampleType finishTime;
    /* #10 get the group configuration through grpId */
    const Adc_GroupConfigType  *grpCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId];
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05();
    /* #20 get the position of the last round conversion value of the first channel */
    /*PRQA S 0488  1*/
    *pointToSamplePtr = grpCfgPtr->bufferBasePtr + (Adc_AllGroupInfo[grpId].groupConvFinishIndex - 1UL);
    /* #30 get group conversion finished time */
    finishTime = Adc_AllGroupInfo[grpId].groupConvFinishTime;
    /* exit critical zone */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
    return finishTime;
}
#if (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/** **************************************************************************************
 * \brief This function checks whether group trigger source can match related Apis.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckGroupTriggSrc(
 *                          Adc_GroupType grpId,
 *                          Adc_TriggerSourceType trigSource)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group
 *                      trigSource - target trigger source of related Apis

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_WRONG_TRIGG_SRC:  Wrong trigger source
 *                      Other: No error

 * Description        : This function checks whether group trigger source can match
 *                      related Apis.
 * \endverbatim
 * Traceability       : SWSR_ADC_076 SWSR_ADC_079 SWSR_ADC_090 SWSR_ADC_170 SWSR_ADC_175
 *                      SWSR_ADC_183 SWSR_ADC_186 SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckGroupTriggSrc(Adc_GroupType grpId,
        Adc_TriggerSourceType trigSource)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the trigger source can match */
    if (trigSource != Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].triggerSource)
    {
        errorStatus = ADC_E_WRONG_TRIGG_SRC;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether group has set up result buffer.

 * \verbatim
 * Syntax             : static inline Adc_ErrorId Adc_CheckBufferUninit(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_BUFFER_UNINIT: Group has not set up result buffer
 *                      Others: No errors

 * Description        : This function checks whether group has set up result buffer
 * \endverbatim
 * Traceability       : SWSR_ADC_061 SWSR_ADC_083 SWSR_ADC_168 SWSR_ADC_178
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckBufferUninit(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the group result buffer is NULL_PTR */
    if (NULL_PTR == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].bufferBasePtr)
    {
        errorStatus = ADC_E_BUFFER_UNINIT;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether current unit is busy due to other groups.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_CheckGroupBusyStartApi(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_BUSY: Other groups in current unit are busy
 *                      Others: No errors

 * Description        : This function checks whether current unit is busy due to other groups.
 * \endverbatim
 * Traceability       : SWSR_ADC_021 SWSR_ADC_080 SWSR_ADC_081 SWSR_ADC_172 SWSR_ADC_173
 *****************************************************************************************/
static Adc_ErrorIdType Adc_CheckGroupBusyStartApi(Adc_GroupType grpId)
{
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;
    /* group configuration */
    const Adc_GroupConfigType *grpCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId];
    /* group index */
    Adc_GroupType grpIndex = 0U;
    /* unit configuration which input group belongs to */
    const Adc_HwUnitConfigType *adcUnitCfgPtr =
        &Adc_GlobalConfigPtr->adcUnitCfgPtr[grpCfgPtr->belongUnitLogicalId];
    /* the first group id in this unit */
    Adc_GroupType groupStartIndex = adcUnitCfgPtr->startGroupIdInUnit;

    for (; grpIndex < adcUnitCfgPtr->groupCountPerUnit; grpIndex++)
    {
        /* #10 whether any group is ADC_BUSY */
        if (ADC_BUSY == Adc_AllGroupInfo[groupStartIndex + grpIndex].groupStatus)
        {
            errorStatus = ADC_E_BUSY;
        }
        /* #20 whether any group is ADC_COMPLETED */
        else if (ADC_COMPLETED == Adc_AllGroupInfo[groupStartIndex + grpIndex].groupStatus)
        {
            errorStatus = ADC_E_BUSY;
        }
        /* #30 whether any group is ADC_STREAM_COMPLETED and buffer circular mode  */
        else if (ADC_E_BUSY == Adc_CheckCircularGroup(groupStartIndex + grpIndex))
        {
            errorStatus = ADC_E_BUSY;
        }
        /* #40 whether any group is ADC_STREAM_COMPLETED and single access mode */
        /* check continous mode for software trigger and one-shot mode for hardware trigger */
        else if (ADC_E_BUSY == Adc_CheckSingleGroup(groupStartIndex + grpIndex))
        {
            errorStatus = ADC_E_BUSY;
        }
        else
        {
            /* do nothing */
        }

        /* check whether ADC_E_BUSY has happened already */
        if (ADC_E_BUSY == errorStatus)
        {
            break;
        }
    }

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether current group is already ADC_IDLE.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_StopApiCheckGroupIdle(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_IDLE: current group is alreay ADC_IDLE
 *                      Others: No error

 * Description        : his function checks whether current group is already ADC_IDLE.
 * \endverbatim
 * Traceability       : SWSR_ADC_093 SWSR_ADC_188
 *****************************************************************************************/
static Adc_ErrorIdType Adc_StopApiCheckGroupIdle(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether group is already ADC_IDLE */
    if (ADC_IDLE == Adc_AllGroupInfo[grpId].groupStatus)
    {
#if(ADC_HW_TRIGGER_API == STD_ON) /* AdcHwTriggerApi enabled */

        /* #20 check whether group is hardware trigger */
        if (ADC_TRIGG_SRC_HW == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].triggerSource)
        {
            /* #30 hardware trigger is disabled already */
            if (ADC_HARDWARE_NO_TRIGGERRING == Adc_AllGroupInfo[grpId].groupHardwareTrigger)
            {
                errorStatus = ADC_E_IDLE;
            }/* else not needed */
        }
        /* #40 software trigger group is idle already */
        else
#endif /* AdcHwTriggerApi enabled */
        {
            errorStatus = ADC_E_IDLE;
        }
    } /* else not needed */

    return errorStatus;
}
#if (ADC_HW_TRIGGER_API == STD_ON)
/** **************************************************************************************
 * \brief This function check whether current unit hardware trigger is enabled.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_CheckHWTrigStartApi(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_HW_BUSY: current unit hardware trigger is enabled
 *                      Others: No error

 * Description        : This function check whether current unit hardware trigger is
 *                       enabled.
 * \endverbatim
 * Traceability       : SWSR_ADC_021
 *****************************************************************************************/
static Adc_ErrorIdType Adc_CheckHWTrigStartApi(Adc_GroupType grpId)
{
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;
    /* group configuration */
    const Adc_GroupConfigType *grpCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId];
    /* unit configuration which input group belongs to */
    const Adc_HwUnitConfigType *adcUnitCfgPtr =
        &Adc_GlobalConfigPtr->adcUnitCfgPtr[grpCfgPtr->belongUnitLogicalId];
    /* group index */
    Adc_GroupType grpIndex = 0U;
    /* the first group id in this unit */
    Adc_GroupType groupStartIndex = adcUnitCfgPtr->startGroupIdInUnit;

    for (; grpIndex < adcUnitCfgPtr->groupCountPerUnit; grpIndex++)
    {
        if (grpId != (groupStartIndex + grpIndex))
        {
            /* #10 check whether group is hardware triggerring */
            if (ADC_HARDWARE_TRIGGERRING == Adc_AllGroupInfo[groupStartIndex + grpIndex].groupHardwareTrigger)
            {
                errorStatus = ADC_E_HW_BUSY;
            } /* else not needed */
        }
    }

    return errorStatus;
}

static inline Adc_ErrorIdType Adc_CheckHWTriggerring(void)
{
    Adc_ErrorIdType errorValue = 0U;
    Adc_GroupType grpIndex = 0U;

    for (; grpIndex < Adc_GlobalConfigPtr->groupCountAllUnit; grpIndex++)
    {
        /* #10 check whether group is hardware triggerring */
        if (ADC_HARDWARE_TRIGGERRING == Adc_AllGroupInfo[grpIndex].groupHardwareTrigger)
        {
            errorValue = ADC_E_HW_BUSY;
        } /* else not needed */
    }

    return errorValue;
}
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_READ_GROUP_API == STD_ON)
/** **************************************************************************************
 * \brief This function reads the latest round conversion values of the requested group.

 * \verbatim
 * Syntax             : static void Adc_ReadGroupDetail(
 *                          Adc_GroupType grpId,
 *                          Adc_ValueGroupType* dataBufferBase)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : dataBufferBase - Read result buffer supplied by user

 * Return value       : None

 * Description        : This function reads the latest round conversion values of the
 *                      requested group.
 * \endverbatim
 * Traceability       : SWSR_ADC_096
 *****************************************************************************************/
static void Adc_ReadGroupDetail(Adc_GroupType grpId, Adc_ValueGroupType *dataBufferBase)
{
    /* #10 get the group configuration through groupId */
    const Adc_GroupConfigType *grpCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId];
    /* #20 get the conversion value interval for every channel */
    uint32 bufferInterval = grpCfgPtr->samplingTime;
    /* #30 group channel number */
    Adc_ChannelType numberOfChannel = 0U;
    /* temp group result buffer */
    const Adc_ValueGroupType *latestValuePtr;
    /* enter critical zone. */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04();
    /* #40 get the position of the last round conversion value of the first channel */
    /*PRQA S 0488  1*/
    latestValuePtr = grpCfgPtr->bufferBasePtr + (Adc_AllGroupInfo[grpId].groupConvFinishIndex - 1UL);

    for (; numberOfChannel < grpCfgPtr->channelCount; numberOfChannel++)
    {
        /* #50 move the latest round conversion value from result buffer to DataBufferPtr */
        dataBufferBase[numberOfChannel] = *latestValuePtr;
        /*PRQA S 0488  1*/
        latestValuePtr += bufferInterval;
    }

    /* exit critical zone. */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04();
    return;
}
#endif /* #if (ADC_READ_GROUP_API == STD_ON) */
#if(ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/** **************************************************************************************
 * \brief This function checks whether group notification is NULL_PTR.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType ADC_CheckNotifCapability(
 *                          Adc_GroupType grpId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : grpId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_NOTIF_CAPABILITY: Group notification is NULL_PTR
 *                      Others: No error

 * Description        : This function checks whether group notification is NULL_PTR.
 * \endverbatim
 * Traceability       : SWSR_ADC_108 SWSR_ADC_114 SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType ADC_CheckNotifCapability(Adc_GroupType grpId)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the group notification is NULL_PTR */
    if (NULL_PTR == Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].notificationPtr)
    {
        errorStatus = ADC_E_NOTIF_CAPABILITY;
    } /* else not needed */

    return errorStatus;
}
#endif /* #if(ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/** **************************************************************************************
 * \brief This function checks whether the Adc_PowerStateRequestResultType
 *        input pointer is NULL_PTR.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckPowerResultPointer(
 *                          const Adc_PowerStateRequestResultType* resultPtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : resultPtr - Pointer to result of using the Api

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_PARAM_POINTER: input pointer is NULL_PTR
 *                      Others: No errors

 * Description        : This function checks whether the Adc_PowerStateRequestResultType
 *                      input pointer is NULL_PTR.
 * \endverbatim
 * Traceability       : SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckPowerResultPointer(const Adc_PowerStateRequestResultType
        *resultPtr)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the buffer is NULL_PTR */
    if (NULL_PTR == resultPtr)
    {
        errorStatus = ADC_E_PARAM_POINTER;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether the Adc_PowerStateType input pointer is NULL_PTR.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType(
 *                          const Adc_PowerStateType* statePtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : statePtr - Pointer to power state

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_PARAM_POINTER: input pointer is NULL_PTR
 *                      Others: No errors

 * Description        : This function checks whether the Adc_PowerStateType input
 *                      pointer is NULL_PTR.
 * \endverbatim
 * Traceability       : SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckPowerStatePointer(const Adc_PowerStateType *statePtr)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the statePtr is NULL_PTR */
    if (NULL_PTR == statePtr)
    {
        errorStatus = ADC_E_PARAM_POINTER;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether target power state is valid.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckPrePowerStateValid(
 *                          Adc_PowerStateType targetState)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : targetState - target power state

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function checks whether target power state is valid.
 * \endverbatim
 * Traceability       : SWSR_ADC_136 SWSR_ADC_139 SWSR_ADC_151 SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckPrePowerStateValid(Adc_PowerStateType targetState)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the prepare power state is supported */
    if (ADC_LOW_POWER < targetState)
    {
        errorStatus = ADC_E_POWER_STATE_NOT_SUPPORTED;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether the target power is the same as current power.

 * \verbatim
 * Syntax             : static inline Adc_PowerCheckType Adc_CheckCurAndTarPowerState(
 *                          Adc_PowerStateType powerState)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : powerState - target power state

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function checks whether the target power is the
 *                      same as current power.
 * \endverbatim
 * Traceability       : SWSR_ADC_149
 *****************************************************************************************/
static inline Adc_PowerCheckType Adc_CheckCurAndTarPowerState(Adc_PowerStateType powerState)
{
    Adc_PowerCheckType checkStatus = ADC_POWER_SAME;

    /* #10 check powerstate is the same as target power state */
    if (Adc_TargetPowerState != powerState)
    {
        checkStatus = ADC_POWER_DIFF;
    } /* else not needed */

    return checkStatus;
}
/** **************************************************************************************
 * \brief This function checks whether Adc_PreparePowerState is used before.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckPowerStatePrepare(
 *                          void)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_PERIPHERAL_NOT_PREPARED: Adc_PreparePowerState is
 *                      not used before.
 *                      Others: No errors

 * Description        : This function checks whether Adc_PreparePowerState is used
 *                      before.
 * \endverbatim
 * Traceability       : SWSR_ADC_026 SWSR_ADC_141 SWSR_ADC_134
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckPowerStatePrepare(void)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check Adc_PreparePowerState is used before Adc_SetPowerState */
    if (ADC_POWER_CHANGE_NOT_START == Adc_PowerStateChange)
    {
        errorStatus = ADC_E_PERIPHERAL_NOT_PREPARED;
    } /* else not needed */

    return errorStatus;
}
#endif /* #if (ADC_POWER_STATE_SUPPORTED == STD_ON) */
#if (ADC_VERSION_INFO_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : static inline Adc_ErrorIdType Adc_CheckVersionPtr(
 *                          const Std_VersionInfoType* versioninfo)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : versioninfo - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_ADC_132 SW_SM006
 *****************************************************************************************/
static inline Adc_ErrorIdType Adc_CheckVersionPtr(const Std_VersionInfoType *versioninfo)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether the input parameter pointer is NULL_PTR */
    if (NULL_PTR == versioninfo)
    {
        errorStatus = ADC_E_PARAM_POINTER;
    } /* else not needed */

    return errorStatus;
}
#endif /* #if (ADC_VERSION_INFO_API == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */

