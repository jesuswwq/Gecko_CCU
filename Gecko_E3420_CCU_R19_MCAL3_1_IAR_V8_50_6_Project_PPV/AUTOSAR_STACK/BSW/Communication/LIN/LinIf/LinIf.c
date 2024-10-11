/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinIf.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for LinIf                                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>   <DATE>     <AUTHOR>   <REVISION LOG>
 * V1.0.0      20171201   HuRongbo   Initial version
 * V2.0.0      20200814   HuRongbo   Update for R19-11
 * V2.0.1      20210812   HuRongbo   Bug fix
 * V2.0.2      20220711   HuRongbo   QAC check issue fix
 * V2.0.3      20220921   HuRongbo
 *    1> Delete Det check in LinIf_MainFunction() (JIRA:PRD0032020-219)
 * V2.0.4      20221114   HuRongbo
 *    1> Fix incorrect parameter passing in LinIf_GetPIDTable()
 *    (JIRA: PRD0032020-234)
 * V2.0.5      20221226   ZhaoTong
 *    1> Fix incorrect lin channel parameter passing in LIN_DRIVER_API()
 *    (JIRA: PRD0042022-509)
 *******************************************************************************/

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:LinIf<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 1532 MISRA Rule 8.7 .<br>
    Reason:In order to make the module code structure clear, the functions are classified.

    \li PRQA S 1504 MISRA Rule 8.7 .<br>
    Reason:Global variables "LinIf_Status" may be used by other unit in other Configuration projects.

    \li PRQA S 2981 MISRA Rule 2.2 .<br>
    Reason:Init may be necessary for return variant.

    \li PRQA S 3219 MISRA Rule 2.1 .<br>
    Reason:Function "LinIf_CheckTxPduId" may be used in other Configuration projects.

    \li PRQA S 2877 MISRA Rule 4.1 .<br>
    Reason:for loop condition is a macro definition, which varies in different projs.

    \li PRQA S 0488 MISRA Rule 18.4 .<br>
    Reason:The offending items are array pointer operations,no effect and reserved

    \li PRQA S 2982 MISRA Rule 2.2 .<br>
    Reason:After resetting all members of the structure, effective values are overwritten for specific members, no
  effect and reserved
 */

/*******************************************************************************
**                      Version Information Definitions                       **
*******************************************************************************/
#define LINIF_C_AR_RELEASE_MAJOR_VERSION    4U
#define LINIF_C_AR_RELEASE_MINOR_VERSION    5U
#define LINIF_C_AR_RELEASE_REVISION_VERSION 0U

#define LINIF_C_SW_MAJOR_VERSION            2U
#define LINIF_C_SW_MINOR_VERSION            0U
#define LINIF_C_SW_PATCH_VERSION            5U

/*******************************************************************************
**                               Includes                                     **
*******************************************************************************/
#include "LinIf.h"
#include "LinIf_Cbk.h"
#include "LinIf_Internal.h"
#if (STD_ON == LINIF_MASTER_SUPPORT)
#include "LinIf_Master.h"
#endif
#if (STD_ON == LINIF_SLAVE_SUPPORT)
#include "LinIf_Slave.h"
#endif
#if (LINIF_TP_SUPPORTED == STD_ON)
#include "LinTp_Master.h"
#include "LinTp_Slave.h"
#include "LinTp_Internal.h"
#endif

/*******************************************************************************
**                             Version Check                                  **
*******************************************************************************/
#if (LINIF_C_AR_RELEASE_MAJOR_VERSION != LINIF_H_AR_RELEASE_MAJOR_VERSION)
#error "LinIf.c : Mismatch in Specification Major Version"
#endif
#if (LINIF_C_AR_RELEASE_MINOR_VERSION != LINIF_H_AR_RELEASE_MINOR_VERSION)
#error "LinIf.c : Mismatch in Specification Minor Version"
#endif
#if (LINIF_C_AR_RELEASE_REVISION_VERSION != LINIF_H_AR_RELEASE_REVISION_VERSION)
#error "LinIf.c : Mismatch in Specification Revision Version"
#endif
#if (LINIF_C_SW_MAJOR_VERSION != LINIF_H_SW_MAJOR_VERSION)
#error "LinIf.c : Mismatch in Specification Major Version"
#endif
#if (LINIF_C_SW_MINOR_VERSION != LINIF_H_SW_MINOR_VERSION)
#error "LinIf.c : Mismatch in Specification Minor Version"
#endif

/*******************************************************************************
**                            Macros Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Runtime Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"

static FUNC(P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_CONST), LINIF_CODE)
    LinIf_GetSubstitution(PduIdType TxPduId);

static FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckTxPduId(PduIdType TxPduId);

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(NetworkHandleType channel);

static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(NetworkHandleType channel);

#if (STD_ON == LINIF_MASTER_SUPPORT)
static FUNC(void, LINIF_CODE) LinIf_MasterMainHandle(void);
#endif

#if (STD_ON == LINIF_SLAVE_SUPPORT)
static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle(void);
#endif

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define LINIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"
/* The status of LINIF */
VAR(LinIf_StatusType, LINIF_VAR) LinIf_Status = LINIF_UNINIT; /* PRQA S 1504 */ /* MISRA Rule 8.7 */
#define LINIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"
/* Global configuration pointer of LINIF */
P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST)
LinIf_ConfigPtr = NULL_PTR;
#define LINIF_STOP_SEC_VAR_INIT_PTR
#include "LinIf_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the LIN Interface.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the LIN Interface configuration
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE)
LinIf_Init /* PRQA S 1503 */
    (P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr)
{
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (NULL_PTR == ConfigPtr)
    {
        LinIf_Det_ReportError(LINIF_INIT_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        /*@req <SWS_LinIf_00371>,<SWS_LinIf_00373>*/
        LinIf_ConfigPtr = ConfigPtr;

#if (STD_ON == LINIF_MASTER_SUPPORT)
        LinIf_MasterInit();
#endif

#if (STD_ON == LINIF_SLAVE_SUPPORT)
        LinIf_SlaveInit();
#endif

        /*@req <SWS_LinIf_00381>*/
        /* Set the status of LINIF */
        LinIf_Status = LINIF_INIT;
    }
}

/******************************************************************************/
/*
 * Brief               Indicates a request.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      LinTxPduId: Upper layer identification of the LIN frame
 *                                 to be transmitted (not the LIN protected ID).
 *                     PduInfoPtr: This parameter is not used by this call.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     Transmit request has been accepted.
 *                     E_NOT_OK: Transmit request has not been accepted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_Transmit /* PRQA S 1503,1532 */ /* MISRA Rule 2.1,8.7 */
    (PduIdType LinTxPduId, P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) PduInfoPtr)
{
    Std_ReturnType ret = E_NOT_OK;

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_TRANSMIT_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (NULL_PTR == PduInfoPtr)
    {
        /*@req <SWS_LinIf_00570>*/
        LinIf_Det_ReportError(LINIF_TRANSMIT_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (E_NOT_OK == LinIf_CheckTxPduId(LinTxPduId))
    {
        /*@req <SWS_LinIf_00575>*/
        LinIf_Det_ReportError(LINIF_TRANSMIT_ID, LINIF_E_PARAMETER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_APPL_CONST)
        subPtr = LinIf_GetSubstitution(LinTxPduId);
        uint16 frameIdx;
        uint8 ch;

        if (NULL_PTR == subPtr)
        {
            /*@req <SWS_LinIf_00700>*/
            /*
             * The Pdu belongs to a non-sporadic frame or non-event-triggered
             * frame,shall return E_OK.
             */
            ret = E_OK;
        }
        else
        {
            frameIdx = subPtr->LinIfSubstitutionFrameRef;

            for (ch = 0; ch < LINIF_NUMBER_OF_CHANNELS; ch++)
            {
                if ((frameIdx >= LINIF_GET_FRAME_OFS(ch))
                    && (frameIdx < (LINIF_GET_FRAME_NUM(ch) + LINIF_GET_FRAME_OFS(ch))))
                {
                    if (LINIF_MASTER == LINIF_GET_NODETYPE(ch))
                    {
#if (STD_ON == LINIF_MASTER_SUPPORT)
                        ret = LinIf_MasterTransmit(ch, frameIdx);
#endif
                    }
                    else
                    {
#if (STD_ON == LINIF_SLAVE_SUPPORT)
                        ret = LinIf_SlaveTransmit(frameIdx);
#endif
                    }

                    break;
                }
                else
                {
                    /* Only for MISRA-C */
                }
            }
        }
    }
    LINIF_NOUSED(PduInfoPtr);

    return ret;
}

/******************************************************************************/
/*
 * Brief               Requests a schedule table to be executed.
 * ServiceId           0x05
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel:  Channel index.
 *                     Schedule: Identification of the new schedule to be set.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     Schedule table request has been accepted.
 *                     E_NOT_OK: Schedule table switch request has not been
 *                               accepted.
 */
/******************************************************************************/
#if (STD_ON == LINIF_MASTER_SUPPORT)
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_ScheduleRequest /* PRQA S 1503 */                      /* PRQA S 1532 */
    (NetworkHandleType Channel, LinIf_SchHandleType Schedule /* PRQA S 3334 */
    )
{
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_SCHEDULEREQUEST_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00563>*/
        LinIf_Det_ReportError(LINIF_SCHEDULEREQUEST_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        ret = LinIf_MasterScheduleRequest(ch, Schedule);
    }

    return ret;
}
#endif

/******************************************************************************/
/*
 * Brief               Initiates a transition into the Sleep Mode on the
 *                     selected channel.
 * ServiceId           0x06
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Channel:  Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     Request to go to sleep has been accepted or
 *                               sleep transition is already in progress or
 *                               controller is already in sleep state.
 *                     E_NOT_OK: Request to go to sleep has not been accepted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_GotoSleep /* PRQA S 1503 */ /* PRQA S 1532 */
    (NetworkHandleType Channel)
{
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_GOTOSLEEP_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00564>*/
        LinIf_Det_ReportError(LINIF_GOTOSLEEP_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        if (LINIF_MASTER == LINIF_GET_NODETYPE(ch))
        {
#if (STD_ON == LINIF_MASTER_SUPPORT)
            LinIf_MasterGotoSleep(ch);
#endif
        }
        else
        {
#if (STD_ON == LINIF_SLAVE_SUPPORT)
            LinIf_SlaveGotoSleep(ch);
#endif
        }

        ret = E_OK;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Initiates the wake up process.
 * ServiceId           0x07
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel:  Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     Request to wake up has been accepted or the
 *                               controller is not in sleep state.
 *                     E_NOT_OK: Request to wake up has not been accepted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_Wakeup /* PRQA S 1503 */ /* PRQA S 1532 */
    (NetworkHandleType Channel)
{
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_WAKEUP_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00565>*/
        LinIf_Det_ReportError(LINIF_WAKEUP_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        if (LINIF_MASTER == LINIF_GET_NODETYPE(ch))
        {
#if (STD_ON == LINIF_MASTER_SUPPORT)
            ret = LinIf_MasterWakeUp(ch);
#endif
        }
        else
        {
#if (STD_ON == LINIF_SLAVE_SUPPORT)
            ret = LinIf_SlaveWakeUp(ch);
#endif
        }
    }

    return ret;
}

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
/******************************************************************************/
/*
 * Brief               Set the given LIN transceiver to the given mode.
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel:  Identification of the LIN channel.
 *                     TransceiverMode: Requested mode transition.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     The transceiver state has been changed to the
 *                               requested mode.
 *                     E_NOT_OK: The transceiver state change has failed or
 *                               the parameter is out of the allowed range.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_SetTrcvMode /* PRQA S 1503 */
    (NetworkHandleType Channel, LinTrcv_TrcvModeType TransceiverMode)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    uint8 linChannel;

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_SETTRCVMODE_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00539>*/
        LinIf_Det_ReportError(LINIF_SETTRCVMODE_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if ((LINTRCV_TRCV_MODE_NORMAL != TransceiverMode) && (LINTRCV_TRCV_MODE_STANDBY != TransceiverMode)
        && (LINTRCV_TRCV_MODE_SLEEP != TransceiverMode))
    {
        /*@req <SWS_LinIf_00540>*/
        LinIf_Det_ReportError(LINIF_SETTRCVMODE_ID, LINIF_E_TRCV_INV_MODE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        /*@req <SWS_LinIf_00536>,<SWS_LinIf_00537>,<SWS_LinIf_00538>*/
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        ret = LinTrcv_SetOpMode(linChannel, TransceiverMode);
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Returns the actual state of a LIN Transceiver Driver.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel:  Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     TransceiverModePtr:  Pointer to a memory location where
 *                                          output value will be stored.
 * Return              E_OK:     The call of the LIN Transceiver Driver's API
 *                               service has returned E_OK.
 *                     E_NOT_OK: The call of the LIN Transceiver Driver's API
 *                               service has returned E_NOT_OK or channel
 *                               parameter is invalid or pointer is NULL.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_GetTrcvMode                                                               /* PRQA S 1503 */
    (NetworkHandleType Channel,
     P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA) TransceiverModePtr /* PRQA S 3432 */
    )
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    uint8 linChannel;

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_GETTRCVMODE_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00546>*/
        LinIf_Det_ReportError(LINIF_GETTRCVMODE_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (NULL_PTR == TransceiverModePtr)
    {
        /*@req <SWS_LinIf_00571>*/
        LinIf_Det_ReportError(LINIF_GETTRCVMODE_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        /*@req <SWS_LinIf_00541>*/
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        ret = LinTrcv_GetOpMode(linChannel, TransceiverModePtr);
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Returns the reason for the wake up that has been detected
 *                     by the LIN Transceiver Driver.
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel:  Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     TrcvWuReasonPtr: Pointer to a memory location where output
 *                                      value will be stored.
 * Return              E_OK:     The call of the LIN Transceiver Driver's API
 *                               service has returned E_OK.
 *                     E_NOT_OK: The call of the LIN Transceiver Driver's API
 *                               service has returned E_NOT_OK or channel
 *                               parameter is invalid or pointer is NULL.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_GetTrcvWakeupReason                                            /* PRQA S 1503 */
    (NetworkHandleType Channel,
     P2VAR(LinTrcv_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
     TrcvWuReasonPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    uint8 linChannel;
    LinTrcv_TrcvModeType transceiverMode = LINTRCV_TRCV_MODE_SLEEP;

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_GETTRCVWAKEUPREASON_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00549>*/
        LinIf_Det_ReportError(LINIF_GETTRCVWAKEUPREASON_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (NULL_PTR == TrcvWuReasonPtr)
    {
        /*@req <SWS_LinIf_00573>*/
        LinIf_Det_ReportError(LINIF_GETTRCVWAKEUPREASON_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (ch < LINIF_NUMBER_OF_CHANNELS)
    {
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        (void)LinTrcv_GetOpMode(linChannel, &transceiverMode);
        if (LINTRCV_TRCV_MODE_NORMAL != transceiverMode)
        {
            /*@req <SWS_LinIf_00572>*/
            LinIf_Det_ReportError(LINIF_GETTRCVWAKEUPREASON_ID, LINIF_E_TRCV_NOT_NORMAL);
            detNoErr = FALSE;
        }
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        /*@req <SWS_LinIf_00548>*/
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        ret = LinTrcv_GetBusWuReason(linChannel, TrcvWuReasonPtr);
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               This API enables, disables and clears the notification
 *                     for wakeup events on the addressed network.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel:           Identification of the LIN channel.
 *                     LinTrcvWakeupMode: Requested transceiver wake up reason.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK:     The call of the LIN Transceiver Driver's API
 *                               service has returned E_OK.
 *                     E_NOT_OK: The call of the LIN Transceiver Driver's API
 *                               service has returned E_NOT_OK or channel or
 *                               mode parameter is invalid.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_SetTrcvWakeupMode /* PRQA S 1503 */
    (NetworkHandleType Channel, LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode)
{
    Std_ReturnType ret = E_NOT_OK;
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);
    uint8 linChannel;

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_SETTRCVWAKEUPREASON_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00595>*/
        LinIf_Det_ReportError(LINIF_SETTRCVWAKEUPREASON_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if ((LINTRCV_WUMODE_ENABLE != LinTrcvWakeupMode) && (LINTRCV_WUMODE_DISABLE != LinTrcvWakeupMode)
        && (LINTRCV_WUMODE_CLEAR != LinTrcvWakeupMode))
    {
        /*@req <SWS_LinIf_00596>*/
        LinIf_Det_ReportError(LINIF_SETTRCVWAKEUPREASON_ID, LINIF_E_PARAMETER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        /*@req <SWS_LinIf_00551>*/
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        ret = LinTrcv_SetWakeupMode(linChannel, LinTrcvWakeupMode);
    }

    return ret;
}
#endif

#if (LINIF_CANCEL_TRANSMIT_SUPPORTED == STD_ON)
/******************************************************************************/
/*
 * Brief               A dummy method introduced for interface compatibility.
 * ServiceId           0x0c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      LinTxPduId: Upper layer identification of the LIN frame
 *                                 for which a cancellation should be done.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_NOT_OK: Cancel Transmit request has not been accepted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_CancelTransmit /* PRQA S 1503 */
    (PduIdType LinTxPduId)
{
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_CANCELTRANSMIT_ID, LINIF_E_UNINIT);
    }
    if (E_NOT_OK == LinIf_CheckTxPduId(LinTxPduId))
    {
        /*@req <SWS_LinIf_00594>*/
        LinIf_Det_ReportError(LINIF_CANCELTRANSMIT_ID, LINIF_E_PARAMETER);
    }
#endif

    /*@req <SWS_LinIf_00649>*/
    return E_NOT_OK;
}
#endif

/******************************************************************************/
/*
 * Brief               The main processing function of the LIN Interface.
 * ServiceId           0x80
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_MainFunction(void) /* PRQA S 1503,1532 */ /* MISRA Rule 2.1,8.7 */
{

    if ((LINIF_INIT == LinIf_Status)
#if (LINIF_TP_SUPPORTED == STD_ON)
        && (LINTP_INIT == LinTp_Status)
#endif /* #if (LINIF_TP_SUPPORTED == STD_ON) */
    )
    {
#if (STD_ON == LINIF_MASTER_SUPPORT)
        LinIf_MasterMainHandle();
#endif

#if (STD_ON == LINIF_SLAVE_SUPPORT)
        LinIf_SlaveMainHandle();
#endif
    }
}
#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"

#if (LINIF_WAKEUP_SUPPORT == STD_ON)
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Will be called when the EcuM has been notified about a
 *                     wakeup on a specific LIN channel.
 * ServiceId           0x60
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WakeupSource: Source device, which initiated the wakeup
 *                                   event: LIN controller or LIN transceiver.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK: No error has occurred during execution of the API.
 *                     E_NOT_OK: An error has occurred during execution of the
 *                               API or invalid WakeupSource.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_CheckWakeup /* PRQA S 1503 */
    (EcuM_WakeupSourceType WakeupSource)
{
    Std_ReturnType ret = E_NOT_OK;

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_CHECKWAKEUP_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((ECUM_WKSOURCE_POWER != WakeupSource) && (ECUM_WKSOURCE_RESET != WakeupSource)
        && (ECUM_WKSOURCE_INTERNAL_RESET != WakeupSource) && (ECUM_WKSOURCE_INTERNAL_WDG != WakeupSource)
        && (ECUM_WKSOURCE_EXTERNAL_WDG != WakeupSource))
    {
        /*@req <SWS_LinIf_00566>*/
        LinIf_Det_ReportError(LINIF_CHECKWAKEUP_ID, LINIF_E_PARAM_WAKEUPSOURCE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        uint8 ch;
        uint8 linDriver;
        uint8 linChannel;
        EcuM_WakeupSourceType wakeupSource;
        P2CONST(LinIf_ChannelType, AUTOMATIC, LINIF_APPL_CONST) chCfgPtr;

#if (LINIF_WAKEUP_SUPPORT == STD_ON)
        /*check all Lin driver channel to find the wake-up source*/
        for (ch = 0; ch < LINIF_NUMBER_OF_CHANNELS; ch++)
        {
#if (LINIF_LIN_TRCV_WAKEUP_SUPPORT == STD_ON)
            chCfgPtr = &LINIF_GET_CHANNEL(ch);
            if (NULL_PTR != chCfgPtr->LinIfTransceiverDrvConfig)
            {
                wakeupSource = LINIF_GET_LIN_TRCV_WAKEUP_SOURCE(ch);
                if (0u != (WakeupSource & wakeupSource))
                {
                    /*@req <SWS_LinIf_00503>*/
                    ret = LinTrcv_CheckWakeup(ch);
                    break;
                }
            }
            else
#endif
            {
                wakeupSource = LINIF_GET_LIN_DRIVER_WAKEUP_SOURCE(ch);
                if (0u != (WakeupSource & wakeupSource))
                {
                    /*@req <SWS_LinIf_00503>*/
                    linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
                    linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
                    ret = LIN_DRIVER_API(linDriver).LinCheckWakeup(linChannel);
                    break;
                }
            }
        }
#endif
    }

    return ret;
}
#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver or LIN Transceiver Driver will call this
 *                     function to report the wake up source after the
 *                     successful wakeup detection during CheckWakeup or after
 *                     power on by bus.
 * ServiceId           0x61
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WakeupSource: Source device, which initiated the wakeup
 *                                   event: LIN controller or LIN transceiver.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE)
LinIf_WakeupConfirmation /* PRQA S 1503,1532 */ /* MISRA Rule 2.1,8.7 */
    (EcuM_WakeupSourceType WakeupSource)
{
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_UNINIT == LinIf_Status)
    {
        /*@req <SWS_LinIf_00535>*/
        LinIf_Det_ReportError(LINIF_WAKEUPCONFIRMATION_ID, LINIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((ECUM_WKSOURCE_POWER != WakeupSource) && (ECUM_WKSOURCE_RESET != WakeupSource)
        && (ECUM_WKSOURCE_INTERNAL_RESET != WakeupSource) && (ECUM_WKSOURCE_INTERNAL_WDG != WakeupSource)
        && (ECUM_WKSOURCE_EXTERNAL_WDG != WakeupSource))
    {
        /*@req <SWS_LinIf_00717>*/
        LinIf_Det_ReportError(LINIF_WAKEUPCONFIRMATION_ID, LINIF_E_PARAM_WAKEUPSOURCE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == LINIF_MASTER_SUPPORT)
        LinIf_MasterWakeupConfirmation(WakeupSource);
#endif

#if (STD_ON == LINIF_SLAVE_SUPPORT)
        LinIf_SlaveWakeupConfirmation(WakeupSource);
#endif
    }
}
#define LINIF_STOP_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
#endif /* #if (LINIF_WAKEUP_SUPPORT == STD_ON) */

#if (STD_ON == LINIF_SLAVE_SUPPORT)
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Retrieves all assigned PID values. The order is congruent
 *                     to the LIN frame index.
 *                     Only applicable for LIN slave nodes.
 * ServiceId           0x72
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel: Identification of the LIN channel.
 * Param-Name[in/out]  PidBuffer: Pointer to existing buffer to which the
 *                                current assigned PID values are copied to.
 *                     PidBufferLength: Pointer to actual length of provided
 *                                      buffer. After successful return,it
 *                                      contains the number of copied PID values
 * Param-Name[out]     None
 * Return              E_OK: Request has been accepted.
 *                     E_NOT_OK: Request has not been accepted, development or
 *                               production error occurred.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_GetPIDTable(                                                               /* PRQA S 1503 */
                  NetworkHandleType Channel,
                  P2VAR(Lin_FramePidType, AUTOMATIC, LINIF_APPL_DATA) PidBuffer, /* PRQA S 3432 */
                  P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) PidBufferLength       /* PRQA S 3432 */
)
{
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00818>*/
        LinIf_Det_ReportError(LINIF_GETPIDTABLE_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if ((NULL_PTR == PidBuffer) || (NULL_PTR == PidBufferLength))
    {
        /*@req <SWS_LinIf_00819>,<SWS_LinIf_00820>*/
        LinIf_Det_ReportError(LINIF_GETPIDTABLE_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((NULL_PTR != PidBufferLength) && (*PidBufferLength > 0u) && (ch < LINIF_NUMBER_OF_CHANNELS)
        && (*PidBufferLength < LINIF_GET_FRAME_NUM(ch)))
    {
        /*@req <SWS_LinIf_00821>*/
        LinIf_Det_ReportError(LINIF_GETPIDTABLE_ID, LINIF_E_PARAMETER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        /*@req <SWS_LinIf_00816>,<SWS_LinIf_00828>*/
        if ((NULL_PTR != PidBufferLength) && (*PidBufferLength > 0u)) /* PRQA S 2995 */
        {
            LinIf_SlaveGetPIDTable(ch, PidBuffer);
        }

        ret = E_OK;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Sets all assigned PID values. The order is congruent to
 *                     the LIN frame index.
 *                     Only applicable for LIN slave nodes.
 * ServiceId           0x73
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     PidBuffer: Pointer to buffer which contains the PID
 *                                values to configure.
 *                     PidBufferLength: Number of PID values in the provided
 *                                      buffer.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK: Request has been accepted.
 *                     E_NOT_OK: Request has not been accepted, development or
 *                               production error occurred.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_SetPIDTable(                                                               /* PRQA S 1503 */
                  NetworkHandleType Channel,
                  P2VAR(Lin_FramePidType, AUTOMATIC, LINIF_APPL_DATA) PidBuffer, /* PRQA S 3432 */
                  uint8 PidBufferLength)
{
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00825>*/
        LinIf_Det_ReportError(LINIF_SETPIDTABLE_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (NULL_PTR == PidBuffer)
    {
        /*@req <SWS_LinIf_00826>*/
        LinIf_Det_ReportError(LINIF_SETPIDTABLE_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((ch < LINIF_NUMBER_OF_CHANNELS) && (PidBufferLength < LINIF_GET_FRAME_NUM(ch)))
    {
        /*@req <SWS_LinIf_00827>*/
        LinIf_Det_ReportError(LINIF_SETPIDTABLE_ID, LINIF_E_PARAMETER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        /*@req <SWS_LinIf_00823>*/
        LinIf_SlaveSetPIDTable(ch, PidBuffer);

        ret = E_OK;
    }
    LINIF_NOUSED(PidBufferLength);

    return ret;
}

/******************************************************************************/
/*
 * Brief               Reports the current configured NAD.
 *                     Only applicable for LIN slave nodes.
 * ServiceId           0x70
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel: Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     Nad: Configured NAD of slave.
 * Return              E_OK: Request has been accepted.
 *                     E_NOT_OK: Request has not been accepted, development or
 *                               production error occurred.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_GetConfiguredNAD(                                             /* PRQA S 1503 */
                       NetworkHandleType Channel,
                       P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Nad /* PRQA S 3432 */
)
{
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00831>*/
        LinIf_Det_ReportError(LINIF_GETCONFIGUREDNAD_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (NULL_PTR == Nad)
    {
        /*@req <SWS_LinIf_00832>*/
        LinIf_Det_ReportError(LINIF_GETCONFIGUREDNAD_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        /*@req <SWS_LinIf_00830>*/
        LinIf_SlaveGetConfiguredNAD(ch, Nad);

        ret = E_OK;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Sets the current configured NAD.
 *                     Only applicable for LIN slave nodes.
 * ServiceId           0x71
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     Nad: Configured NAD to set as new slave NAD.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK: Request has been accepted.
 *                     E_NOT_OK: Request has not been accepted, development or
 *                               production error occurred.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_SetConfiguredNAD(/* PRQA S 1503 */
                       NetworkHandleType Channel,
                       uint8 Nad)
{
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    NetworkHandleType ch = LinIf_GetLinIfChannel(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00835>*/
        LinIf_Det_ReportError(LINIF_SETCONFIGUREDNAD_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (0u == Nad)
    {
        /*@req <SWS_LinIf_00836>*/
        LinIf_Det_ReportError(LINIF_SETCONFIGUREDNAD_ID, LINIF_E_PARAMETER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        /*@req <SWS_LinIf_00834>*/
        LinIf_SlaveSetConfiguredNAD(ch, Nad);

        ret = E_OK;
    }

    return ret;
}
#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFHEADERINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     received LIN header. This function is only applicable for
 *                     LIN slave nodes
 * ServiceId           0x78
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     Nad: Configured NAD to set as new slave NAD.
 * Param-Name[in/out]  PduPtr: Pointer to PDU providing the received PID and
 *                     pointer to the SDU data buffer as in parameter. Upon
 *                     return, the length, checksum type and frame response type
 *                     are received as out parameter. If the frame response type
 *                     is LIN_FRAMERESPONSE_TX, then the SDU data buffer
 *                     contains the transmission data.
 * Param-Name[out]     None
 * Return              E_OK: Request has been accepted.
 *                     E_NOT_OK: Request has not been accepted, development or
 *                               production error occurred.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_HeaderIndication(                                                      /* PRQA S 1503 */
                       NetworkHandleType Channel,
                       P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr /* PRQA S 3432 */
)
{
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00843>*/
        LinIf_Det_ReportError(LINIF_HEADERINDICATION_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (NULL_PTR == PduPtr)
    {
        /*@req <SWS_LinIf_00844>*/
        LinIf_Det_ReportError(LINIF_HEADERINDICATION_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        ret = LinIf_SlaveHeaderIndication(ch, PduPtr);
    }

    return ret;
}
#define LINIF_STOP_SEC_LINIFHEADERINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFRXINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     successfully received response and provides the reception
 *                     data to the LIN Interface. This function is only
 *                     applicable for LIN slave nodes.
 * ServiceId           0x79
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     Lin_SduPtr: pointer to a shadow buffer or memory mapped
 *                     LIN Hardware receive buffer where the current SDU is
 *                     stored. This pointer is only valid if the response is
 *                     received.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE)
LinIf_RxIndication(                                                    /* PRQA S 1503 */
                   NetworkHandleType Channel,
                   P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr /* PRQA S 3432 */
)
{
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    boolean detNoErr = TRUE;
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00849>*/
        LinIf_Det_ReportError(LINIF_RXINDICATION_ID, LINIF_E_NONEXISTENT_CHANNEL);
        detNoErr = FALSE;
    }
    if (NULL_PTR == Lin_SduPtr)
    {
        /*@req <SWS_LinIf_00850>*/
        LinIf_Det_ReportError(LINIF_RXINDICATION_ID, LINIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        LinIf_SlaveRxIndication(ch, Lin_SduPtr);
    }
}
#define LINIF_STOP_SEC_LINIFRXINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     successfully transmitted response.
 *                     This function is only applicable for LIN slave nodes.
 * ServiceId           0x7a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE)
LinIf_TxConfirmation(/* PRQA S 1503 */
                     NetworkHandleType Channel)
{
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00855>*/
        LinIf_Det_ReportError(LINIF_TXCONFIRMATION_ID, LINIF_E_NONEXISTENT_CHANNEL);
    }
    else
#endif
    {
        LinIf_SlaveTxConfirmation(ch);
    }
}
#define LINIF_STOP_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     detected error event during header or response processing
 *                     This function is only applicable for LIN slave nodes
 * ServiceId           0x7b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     ErrorStatus: Type of detected error.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE)
LinIf_LinErrorIndication(/* PRQA S 1503 */
                         NetworkHandleType Channel,
                         Lin_SlaveErrorType ErrorStatus)
{
    NetworkHandleType ch = LinIf_GetLinIfChannelByDriverChId(Channel);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    if (LINIF_NUMBER_OF_CHANNELS == ch)
    {
        /*@req <SWS_LinIf_00855>*/
        LinIf_Det_ReportError(LINIF_LINERRORINDICATION_ID, LINIF_E_NONEXISTENT_CHANNEL);
    }
    else
#endif
    {
        LinIf_SlaveLinErrorIndication(ch, ErrorStatus);
    }
}
#define LINIF_STOP_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#endif /* STD_ON == LINIF_SLAVE_SUPPORT */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief: Gets the frame reference by Tx PduId
 * Param-Name[in]: id
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: LinIf_FrameType*
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_CONST), LINIF_CODE)
    LinIf_GetSubstitution(PduIdType TxPduId)
{
    P2CONST(LinIf_TxPduType, AUTOMATIC, LINIF_APPL_CONST) txPduPtr;
    P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_APPL_CONST) subPtr;
    uint16 idx, frameIdx;

    for (idx = 0; idx < LINIF_GET_SUB_NUM(); idx++)
    {
        subPtr = &LINIF_GET_SUB_FRAME(idx);
        frameIdx = subPtr->LinIfSubstitutionFrameRef;
        txPduPtr = LINIF_GET_GLOBAL_FRAME(frameIdx).LinIfPduDirection->LinIfTxPdu;

        if (txPduPtr->LinIfTxPduId == TxPduId)
        {
            return subPtr;
        }
    }

    return NULL_PTR;
}

/******************************************************************************/
/*
 * Brief: Check the TxPduId is valid
 * Param-Name[in]: id
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: Std_ReturnType
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
/* PRQA S 3219 ++ */ /* MISRA Rule 2.1 */
static FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckTxPduId(PduIdType TxPduId)
/* PRQA S 3219 -- */ /* MISRA Rule 2.1 */
{
    P2CONST(LinIf_TxPduType, AUTOMATIC, LINIF_APPL_CONST) txPduPtr;
    uint16 idx;

    for (idx = 0; idx < LINIF_GET_TXPDU_NUM(); idx++)
    {
        txPduPtr = &LINIF_GET_TXPDU(idx);
        if (txPduPtr->LinIfTxPduId == TxPduId)
        {
            return E_OK;
        }
    }

    return E_NOT_OK;
}

/******************************************************************************/
/*
 * Brief: Get LinIf channel id by network(ComM Channel id)
 * Param-Name[in]: channel: Lin channel index
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: uint8
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(NetworkHandleType channel)
{
    NetworkHandleType idx = LINIF_NUMBER_OF_CHANNELS;

    if (LINIF_INIT == LinIf_Status)
    {
        for (idx = 0; idx < LINIF_NUMBER_OF_CHANNELS; idx++)
        {
            if (LINIF_GET_COMM_NETWORK(idx) == channel)
            {
                return idx;
            }
        }
    }

    return idx;
}

/******************************************************************************/
/*
 * Brief: Get LinIf channel id by Lin Driver channel Id
 * Param-Name[in]: channel: Lin channel index
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: uint8
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(NetworkHandleType channel)
{
    NetworkHandleType idx = LINIF_NUMBER_OF_CHANNELS;

    if (LINIF_INIT == LinIf_Status)
    {
        for (idx = 0; idx < LINIF_NUMBER_OF_CHANNELS; idx++)
        {
            if (LINIF_GET_LIN_CHANNEL_ID(idx) == channel)
            {
                return idx;
            }
        }
    }

    return idx;
}

/******************************************************************************/
/*
 * Brief: LinIf master main function
 * Param-Name[in]: None
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
#if (STD_ON == LINIF_MASTER_SUPPORT)
static FUNC(void, LINIF_CODE) LinIf_MasterMainHandle(void)
{
    uint8 ch;

    for (ch = 0u; ch < LINIF_MASTER_CHANNEL_NUMBER; ch++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    {
        LinIf_SlotTimer(ch);
        LinIf_WakeUpProcess(ch);
        LinIf_SleepProcess(ch);

        if (LINIF_CHANNEL_OPERATIONAL == LinIf_GetChannelState(ch))
        {
            if (TRUE == LinIf_IsEntryDelayTimeout(ch))
            {
                LinIf_PrevTransmit(ch);
            }

#if (LINIF_TP_SUPPORTED == STD_ON)
            LinTp_RxProcess(ch);
            LinTp_TxProcess(ch);
            LinTp_HandleTimers(ch);
#endif

            if (TRUE == LinIf_IsEntryDelayTimeout(ch))
            {
#if (LINIF_TP_SUPPORTED == STD_ON)
                if (FALSE == LinTp_IsWaitEventSet(ch))
#endif /* #if (LINIF_TP_SUPPORTED == STD_ON) */
                {
                    LinIf_UpdateSchedule(ch);
                    LinIf_NextTransmit(ch);
                }
            }
        }
    }
}
#endif

/******************************************************************************/
/*
 * Brief: LinIf slave main function
 * Param-Name[in]: None
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
#if (STD_ON == LINIF_SLAVE_SUPPORT)
static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle(void)
{
    uint8 ch;

    for (ch = LINIF_MASTER_CHANNEL_NUMBER; ch < LINIF_NUMBER_OF_CHANNELS; ch++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    {
        LinIf_SlaveMainFunction(ch);

#if (LINIF_TP_SUPPORTED == STD_ON)
        LinTp_SlaveMainFunction(ch);
#endif
    }
}
#endif /* #if (STD_ON == LINIF_SLAVE_SUPPORT) */

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"
