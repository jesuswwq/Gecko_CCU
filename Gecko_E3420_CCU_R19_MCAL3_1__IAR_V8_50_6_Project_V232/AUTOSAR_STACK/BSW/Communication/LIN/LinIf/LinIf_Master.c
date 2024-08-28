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
**  FILENAME    : LinIf_Master.c                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>   <DATE>     <AUTHOR>   <REVISION LOG>
 * V2.0.0      20200721   HuRongbo   Initial version
 * V2.0.1      20220908   HuRongbo
 *  1> Change LINIF_E_RESPONSE to runtime error
 * V2.0.2      20221114   HuRongbo
 *  1> Change private variable keyword from static to macro LINTP_LOCAL
 * V2.0.3      20221208   ZhaoTong
 *  1> Change event-trigger frame notify the upper layer through the associated
 *     unconditional frame PDU
 * V2.0.4      20221226   ZhaoTong
 *    1> Fix incorrect lin channel parameter passing in LIN_DRIVER_API()
 *    (JIRA: PRD0042022-509)
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "LinIf.h"
#if (STD_ON == LINIF_MASTER_SUPPORT)
#include "LinIf_Master.h"
#include "SchM_LinIf.h"
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (LINIF_TP_SUPPORTED == STD_ON)
#include "LinTp_Master.h"
#endif

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
    P2CONST(LinIf_ScheduleTableType, AUTOMATIC, LINIF_APPL_DATA) CurSchedule;
    P2CONST(LinIf_ScheduleTableType, AUTOMATIC, LINIF_APPL_DATA) ResSchedule;
    P2CONST(LinIf_ScheduleTableType, AUTOMATIC, LINIF_APPL_DATA) RdySchedule;
    P2CONST(LinIf_EntryType, AUTOMATIC, LINIF_APPL_CONST) CurEntry;
    Lin_PduType TxPdu;
    PduIdType TxPduId;
    uint16 CurEntryIndex;
    uint16 ResEntryIndex;
    LinIf_SchHandleType CollisionResolvingRef;
    LinIf_ChannelStateType LinIfChannelState;
    uint16 RootEvent;
    uint16_least Timer;
    boolean WakeupFlag;
} LinIf_MasterRuntimeType;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"

static FUNC(P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_CONST), LINIF_CODE)
    LinIf_GetTransmitPending(P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);

static FUNC(void, LINIF_CODE) LinIf_SendSporadic(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);

static FUNC(void, LINIF_CODE)
    LinIf_SendEventTrigger(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);

static FUNC(void, LINIF_CODE)
    LinIf_SendUnconditional(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);

static FUNC(void, LINIF_CODE) LinIf_MemCopyFixedFrame(
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Dst, /* PRQA S 3432 */
    P2CONST(LinIf_FixedFrameSduType, AUTOMATIC, LINIF_APPL_CONST) Src);

static FUNC(void, LINIF_CODE)
    LinIf_SendNodeConfiguration(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);

#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
static FUNC(void, LINIF_CODE) LinIf_SendMRF(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);

static FUNC(void, LINIF_CODE) LinIf_SendSRF(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);
#endif

static FUNC(void, LINIF_CODE) LinIf_SetPduInfo(
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) pdu, /* PRQA S 3432 */
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame);

static FUNC(void, LINIF_CODE)
    LinIf_HandleEntryTail(P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) chPtr /* PRQA S 3432 */
    );

static FUNC(void, LINIF_CODE) LinIf_SwitchScheduleNotify(uint8 ch);

static FUNC(void, LINIF_CODE) LinIf_SwitchNewSchedule(uint8 ch);

static FUNC(void, LINIF_CODE) LinIf_SwitchNewEntry(uint8 ch);

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if !defined(LINIF_LOCAL)
#define LINIF_LOCAL static
#endif

#define LINIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinIf_MemMap.h"

/* All channels global buffer information */
LINIF_LOCAL VAR(LinIf_MasterRuntimeType, LINIF_VAR) LinIf_MasterChRtData[LINIF_MASTER_CHANNEL_NUMBER];

#define LINIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LinIf_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the LinIf master channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_MasterInit(void) /* PRQA S 1532 */
{
    NetworkHandleType idx;
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) chPtr;         /* PRQA S 3432 */

    for (idx = 0; idx < LINIF_MASTER_CHANNEL_NUMBER; idx++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    {
        chPtr = LINIF_CH(idx);

        /*@req <SWS_LinIf_00290>*/
        /* Locked */
        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /*@req <SWS_LinIf_00507>*/
        /* Set the state of channel */
        if (LINIF_STARTUP_NORMAL == LINIF_GET_STARTUP_STATE(idx))
        {
            chPtr->LinIfChannelState = LINIF_CHANNEL_OPERATIONAL;
        }
        else
        {
            chPtr->LinIfChannelState = LINIF_CHANNEL_SLEEP;
        }

        /*@req <SWS_LinIf_00233>*/
        /* Reset channel */
        chPtr->CurSchedule = NULL_PTR;
        chPtr->ResSchedule = NULL_PTR;
        chPtr->RdySchedule = NULL_PTR;
        chPtr->CurEntry = NULL_PTR;
        chPtr->CurEntryIndex = 0;
        chPtr->ResEntryIndex = 0;
        chPtr->RootEvent = LINIF_EVENT_NONE;
        chPtr->Timer = 0;
        chPtr->WakeupFlag = FALSE;

        /* Unlocked */
        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
    }
}

/******************************************************************************/
/*
 * Brief               Transmit request process in master node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 *                     frameIdx: Frame Index
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_MasterTransmit(/* PRQA S 1532 */
                     NetworkHandleType ch,
                     uint16 frameIdx)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    Std_ReturnType ret;

    if (NULL_PTR == chPtr->CurSchedule)
    {
        /*@req <SWS_LinIf_00719>*/
        ret = E_NOT_OK;
    }
    else
    {
        /* Locked */
        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /*@req <SWS_LinIf_00341>,<SWS_LinIf_00730>*/
        /* Set transmit request flag */
        LINIF_GET_TRANSMIT_REQ(frameIdx) = TRUE;

        /* Unlocked */
        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        ret = E_OK;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Transmit request process in master node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 *                     frameIdx: Frame Index
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_MasterScheduleRequest(                             /* PRQA S 1532 */
                            NetworkHandleType ch,
                            LinIf_SchHandleType Schedule /* PRQA S 3334 */
)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    Std_ReturnType ret = E_NOT_OK; /* PRQA S 2981 */           /* MISRA Rule 2.2 */

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
    if ((LINIF_CHANNEL_SLEEP == chPtr->LinIfChannelState)
        || ((LINIF_NULL_SCHEDULE_INDEX != Schedule)
            && ((Schedule < LINIF_GET_SCHEDULE_OFS(ch))
                || ((LINIF_GET_SCHEDULE_NUM(ch) + LINIF_GET_SCHEDULE_OFS(ch)) <= Schedule))))
    {
        /*@req <SWS_LinIf_00567>*/
        LinIf_Det_ReportError(LINIF_SCHEDULEREQUEST_ID, LINIF_E_SCHEDULE_REQUEST_ERROR);
    }
    else
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
    {
        if (LINIF_NULL_SCHEDULE_INDEX == Schedule)
        {
            chPtr->RdySchedule = NULL_PTR;
        }
        else
        {
            Schedule -= LINIF_GET_SCHEDULE_OFS(ch);
            chPtr->RdySchedule = &LINIF_GET_SCHEDULE(ch, Schedule);
        }

        /* Set schedule request flag */
        LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_REQ);
        ret = E_OK;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Go-to-sleep process in master node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE)
LinIf_MasterGotoSleep(/* PRQA S 1532 */
                      NetworkHandleType ch)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    /*@req <SWS_LinIf_00488>*/
    /* Set sleep request flag */
    LINIF_SET_EVENT(LINIF_EVENT_SLEEP);
}

/******************************************************************************/
/*
 * Brief: Process sleep state transmit
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SleepProcess(uint8 ch) /* PRQA S 1532 */
{
    uint8* sdu = NULL_PTR;
    uint8 linDriver;
    uint8 linChannel;
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    if (!LINIF_IS_TIMEOUT(ch))
    {
        return;
    }

    if (LINIF_IS_EVENT(LINIF_EVENT_SLEEP))
    {
        linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        if (!LINIF_IS_EVENT(LINIF_EVENT_GOTO_SLEEP))
        {
            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            if (LINIF_CHANNEL_SLEEP != chPtr->LinIfChannelState)
            {
                /*@req <SWS_LinIf_00453>*/
                /* Send a goto-sleep request on bus */
                (void)LIN_DRIVER_API(linDriver).LinGoToSleep(linChannel);
                /* Set sleep frame slot time */
                chPtr->Timer = LINIF_SLEEP_MODE_FRAME_DELAY;

                /* Set goto-sleep flag */
                LINIF_SET_EVENT(LINIF_EVENT_GOTO_SLEEP);
                /* Prepare sleep */
                chPtr->LinIfChannelState = LINIF_CHANNEL_GOTO_SLEEP;
            }
            else
            {
                /*@req <SWS_LinIf_00597>*/
                /* Internal goto-sleep request */
                (void)LIN_DRIVER_API(linDriver).LinGoToSleepInternal(linChannel);

                /*@req <SWS_LinIf_00557>*/
                /* Notify upper */
                USER_GOTO_SLEEP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), TRUE);
            }

            /*@req <SWS_LinIf_00712>*/
            /* Clear wakeup flag */
            chPtr->WakeupFlag = FALSE;

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
        }
        else
        {
            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            Lin_StatusType st = LIN_DRIVER_API(linDriver).LinGetStatus(linChannel, &sdu);
            if (LIN_CH_SLEEP == st)
            {
                /*@req <SWS_LinIf_00455>*/
                chPtr->LinIfChannelState = LINIF_CHANNEL_SLEEP;

                /*@req <SWS_LinIf_00293>,<SWS_LinIf_00444>*/
                /* Switch the current used schedule table to the NULL_SCHEDULE */
                chPtr->RdySchedule = NULL_PTR;
                chPtr->CurSchedule = NULL_PTR;
                chPtr->CurEntry = NULL_PTR;
                chPtr->CurEntryIndex = 0;
                chPtr->ResSchedule = NULL_PTR;
                chPtr->ResEntryIndex = 0;
                chPtr->RootEvent = LINIF_EVENT_NONE;
/* chPtr->Timer = 0; */
#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
                LinTp_MasterChannelInit(ch);
#endif
                /* Set change schedule flag */
                /* LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_REQ); */

                /*@req <SWS_LinIf_00495> */
                /* Notify upper change to NULL_SCHEDULE */
                USER_SCHEDULE_REQUEST_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), 0u);

                /*@req <SWS_LinIf_00557>*/
                /* Notify upper */
                USER_GOTO_SLEEP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), TRUE);
            }
            else
            {
                /*@req <SWS_LinIf_00558>*/
                /* Notify upper */
                USER_GOTO_SLEEP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), FALSE);

                /* Go-to-sleep not successful,state back to OPERATIONAL */
                chPtr->LinIfChannelState = LINIF_CHANNEL_OPERATIONAL;
            }

            LINIF_CLR_EVENT(LINIF_EVENT_SLEEP);
            LINIF_CLR_EVENT(LINIF_EVENT_GOTO_SLEEP);

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
        }
    }
    else
    {
        /* Only for MISRA-C */
    }
}

/******************************************************************************/
/*
 * Brief: Process wake-up state transmit
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_MasterWakeUp(/* PRQA S 1532 */
                   NetworkHandleType ch)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    uint8 linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
    uint8 linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
    Std_ReturnType ret;

    if (LINIF_CHANNEL_SLEEP == chPtr->LinIfChannelState)
    {
        if (TRUE == chPtr->WakeupFlag)
        {
            /*@req <SWS_LinIf_00713>,<SWS_LinIf_00721>*/
            ret = LIN_DRIVER_API(linDriver).LinWakeupInternal(linChannel);
        }
        else
        {
            /*@req <SWS_LinIf_00296>,<SWS_LinIf_00720>*/
            ret = LIN_DRIVER_API(linDriver).LinWakeup(linChannel);
        }

        /*@req <SWS_LinIf_00720>,<SWS_LinIf_00721>*/
        if (E_OK == ret)
        {
            /*@req <SWS_LinIf_00478>*/
            chPtr->LinIfChannelState = LINIF_CHANNEL_OPERATIONAL;
        }
    }
    else if (LINIF_CHANNEL_OPERATIONAL == chPtr->LinIfChannelState)
    {
        /*@req <SWS_LinIf_00459>*/
        /* requested go-to-sleep command is not executed,clear it */
        if (LINIF_IS_EVENT(LINIF_EVENT_SLEEP))
        {
            LINIF_CLR_EVENT(LINIF_EVENT_SLEEP);
        }
        else
        {
        }
        /*@req <SWS_LinIf_00432>*/
        ret = E_OK;
    }
    else
    {
        /* LINIF_CHANNEL_GOTO_SLEEP */
        /* This case the AUTOSAR specification is not describe */
        ret = E_NOT_OK;
    }

    /*@req <SWS_LinIf_00720>,<SWS_LinIf_00721>*/
    if (E_OK == ret)
    {
        /*@req <SWS_LinIf_00714>*/
        chPtr->WakeupFlag = FALSE;
    }

    /* Set notify upper layer flag according to request result */
    if (E_OK == ret)
    {
        LINIF_SET_EVENT(LINIF_EVENT_WAKEUP_E_OK);
    }
    else
    {
        LINIF_SET_EVENT(LINIF_EVENT_WAKEUP_E_NOT_OK);
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief: Wakeup confirmation process in master node
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE)
LinIf_MasterWakeupConfirmation(/* PRQA S 1532 */
                               EcuM_WakeupSourceType WakeupSource)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) chPtr; /* PRQA S 3432 */
    EcuM_WakeupSourceType wakeupSource;
    NetworkHandleType ch;

    /*check all Lin driver channel to find the wake-up source*/
    for (ch = 0; ch < LINIF_MASTER_CHANNEL_NUMBER; ch++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    {
        chPtr = LINIF_CH(ch);
        chPtr->WakeupFlag = TRUE;
    }
#if (LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON)
    // /*check all Lin driver channel to find the wake-up source*/
    // for (ch = 0; ch < LINIF_MASTER_CHANNEL_NUMBER; ch++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    // {
    //     wakeupSource = LINIF_GET_LIN_DRIVER_WAKEUP_SOURCE(ch);
    //     if (0u != (WakeupSource & wakeupSource))
    //     {
    //         /*@req <SWS_LinIf_00716>*/
    //         chPtr = LINIF_CH(ch);
    //         chPtr->WakeupFlag = TRUE;
    //         break;
    //     }
    // }
#endif

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
#if (LINIF_LIN_TRCV_WAKEUP_SUPPORT == STD_ON)
    /*check all Lin transceiver channel to find the wake-up source*/
    for (ch = 0; ch < LINIF_MASTER_CHANNEL_NUMBER; ch++)
    {
        wakeupSource = LINIF_GET_LIN_TRCV_WAKEUP_SOURCE(ch);
        if (0u != (WakeupSource & wakeupSource))
        {
            /*@req <SWS_LinIf_00716>*/
            chPtr = LINIF_CH(ch);
            chPtr->WakeupFlag = TRUE;
            break;
        }
    }
#endif
#endif
}

/******************************************************************************/
/*
 * Brief: Process wake-up state transmit
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_WakeUpProcess(uint8 ch)           /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    /* Notify Uppler layer LinIf_Wakeup process result */
    if (LINIF_IS_EVENT(LINIF_EVENT_WAKEUP_E_OK))
    {
        /*@req <SWS_LinIf_00496>*/
        USER_WAKEUP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), TRUE);

        LINIF_CLR_EVENT(LINIF_EVENT_WAKEUP_E_OK);
    }
    else if (LINIF_IS_EVENT(LINIF_EVENT_WAKEUP_E_NOT_OK))
    {
        /*@req <SWS_LinIf_00670>*/
        USER_WAKEUP_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), FALSE);

        LINIF_CLR_EVENT(LINIF_EVENT_WAKEUP_E_NOT_OK);
    }
    else
    {
        /* Only for MISRA-C */
    }
}

/******************************************************************************/
/*
 * Brief: Frame slot timer
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: Std_ReturnType
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SlotTimer(uint8 ch) /* PRQA S 1532 */
{
    if (LinIf_MasterChRtData[ch].Timer > 0u)
    {
        /* Locked */
        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /* The current frame slot counter minus 1 */
        LinIf_MasterChRtData[ch].Timer--;

        /* Unlocked */
        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
    }
}

/******************************************************************************/
/*
 * Brief: Process the preview frame transmission
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_PrevTransmit(uint8 ch)            /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    if (chPtr->CurSchedule != NULL_PTR)
    {
        P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST)
        frame = &LINIF_GET_FRAME(ch, (chPtr->CurEntry->LinIfFrameRef - LINIF_GET_FRAME_OFS(ch)));

        if (LINIF_IS_EVENT(LINIF_EVENT_HEADER | LINIF_EVENT_RESPONSE)
#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
            || (TRUE == LinTp_IsWaitEventSet(ch)) /* PRQA S 3415 */
#endif
        )
        {
            P2CONST(LinIf_TxPduType, AUTOMATIC, LINIF_APPL_DATA) txPduPtr;
            P2CONST(LinIf_RxPduType, AUTOMATIC, LINIF_APPL_DATA) rxPduPtr;
            P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) sdu = NULL_PTR; /* PRQA S 3432 */
            PduInfoType pduInfo;
            uint8 linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
            uint8 linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
            Lin_StatusType st = LIN_DRIVER_API(linDriver).LinGetStatus(linChannel, &sdu);
            P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_CONST) sub;
            P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) fra;
            uint16 frameIdx;
            P2CONST(LinIf_ScheduleTableType, AUTOMATIC, LINIF_APPL_DATA) triSchedule;
            P2CONST(LinIf_EntryType, AUTOMATIC, LINIF_APPL_CONST) triEntry;
            uint8 idx;

            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /* Clear flag of header and response */
            LINIF_CLR_EVENT(LINIF_EVENT_HEADER | LINIF_EVENT_RESPONSE);

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            switch (frame->LinIfPduDirection->LinIfPduDirectionId)
            {
            case LINIF_RX_PDU:
                if (st == LIN_RX_OK)
                {
#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
                    if (frame->LinIfFrameType == LINIF_SRF)
                    {
                        /* Receiving parse */
                        LinTp_RxEventParse(ch, sdu);
                    }
                    else
#endif /* #if (LINIF_TP_SUPPORTED == STD_ON) */
                    {
                        /* Locked */
                        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        /* Next entry */
                        chPtr->CurEntryIndex++;

                        /* Unlocked */
                        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        if (!LINIF_IS_EVENT(LINIF_EVENT_NCSRF_SEND))
                        {
                            /* Save PDU information */
                            pduInfo.SduDataPtr = sdu;
                            pduInfo.SduLength = frame->LinIfLength;

                            /* event-triggered frame */
                            if (frame->LinIfFrameType == LINIF_EVENT_TRIGGERED)
                            {
                                /* get the corresponding collision resolving schedule table */
                                idx = chPtr->CurEntry->LinIfCollisionResolvingRef - LINIF_GET_SCHEDULE_OFS(ch);
                                triSchedule = &LINIF_GET_SCHEDULE(ch, idx);
                                for (frameIdx = 0; frameIdx < triSchedule->LinIfNumOfEntry; frameIdx++)
                                {
                                    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
                                    triEntry = (triSchedule->LinIfEntry) + frameIdx;
                                    /* PRQA S 0488 -- */ /* MISRA Rule 18.4 */
                                    frame = &LINIF_GET_GLOBAL_FRAME(triEntry->LinIfFrameRef);
                                    /* the PID of the unconditional frame in the first byte of the response data.*/
                                    if (pduInfo.SduDataPtr[0] == frame->LinIfFrameId)
                                    {
                                        /*@req <SWS_LinIf_00033> */
                                        /* Notify upper */
                                        rxPduPtr = frame->LinIfPduDirection->LinIfRxPdu;
                                        rxPduPtr->LinIfRxIndicationUL(rxPduPtr->LinIfRxPduRef, &pduInfo);
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                /*@req <SWS_LinIf_00033> */
                                /* Notify upper */
                                rxPduPtr = frame->LinIfPduDirection->LinIfRxPdu;
                                rxPduPtr->LinIfRxIndicationUL(rxPduPtr->LinIfRxPduRef, &pduInfo);
                            }
                        }
                        else
                        {
                            /*@req <SWS_LinIf_00404> */
                            /* Clear the flag of NC SRF header */
                            LINIF_CLR_EVENT(LINIF_EVENT_NCSRF_SEND);
                        }
                    }
                }
                else
                {
                    if (LINIF_SRF != frame->LinIfFrameType)
                    {
                        /* Locked */
                        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        /* Next entry */
                        chPtr->CurEntryIndex++;

                        /* Unlocked */
                        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
                    }

                    switch (frame->LinIfFrameType)
                    {
                    case LINIF_UNCONDITIONAL:
/*@req <SWS_LinIf_00254>,<SWS_LinIf_00466> */
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
                        /* Notify upper */
                        LinIf_ReportRuntimeError(LINIF_MAINFUNCTION_ID, LINIF_E_RESPONSE);
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */
                        break;

                    case LINIF_EVENT_TRIGGERED:
                        if ((st == LIN_RX_ERROR) || (st == LIN_RX_BUSY))
                        {
                            /* Locked */
                            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                            /*@req <SWS_LinIf_00259>,<SWS_LinIf_00588>,
                              <SWS_LinIf_00176> */
                            /* Set collision resolving flag */
                            LINIF_SET_EVENT(LINIF_EVENT_COLLISION);
                            chPtr->CollisionResolvingRef = chPtr->CurEntry->LinIfCollisionResolvingRef;

                            /* Unlocked */
                            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
                        }
                        else
                        {
                            /* Case: st == LIN_RX_NO_RESPONSE */
                            /*@req <SWS_LinIf_00258> */
                        }
                        break;

#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
                    case LINIF_SRF:
                        /* Next entry */
                        chPtr->CurEntryIndex++;
                        break;
#endif /* (LINIF_TP_SUPPORTED == STD_ON) */

#if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON)
                    case LINIF_ASSIGN_NAD:
                    case LINIF_CONDITIONAL:
#endif /*#if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED==STD_ON)*/
                    case LINIF_ASSIGN:
                    case LINIF_ASSIGN_FRAME_ID_RANGE:
                    case LINIF_FREE:
                    case LINIF_SAVE_CONFIGURATION:
                    case LINIF_UNASSIGN:
                        /* Clear the flag of NC SRF header */
                        LINIF_CLR_EVENT(LINIF_EVENT_NCSRF_SEND);

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
                        /*@req <SWS_LinIf_00405> */
                        LinIf_Det_ReportError(LINIF_MAINFUNCTION_ID, LINIF_E_NC_NO_RESPONSE);
#endif
                        break;

                    default:
                        /* Other Frame Type */
                        break;
                    }
                }
                break;

            case LINIF_TX_PDU:
                if (st == LIN_TX_OK)
                {
                    switch (frame->LinIfFrameType)
                    {
                    case LINIF_UNCONDITIONAL:
                        /*@req <SWS_LinIf_00128> */
                        /* Notify upper */
                        txPduPtr = frame->LinIfPduDirection->LinIfTxPdu;
                        txPduPtr->LinIfTxConfirmationUL(txPduPtr->LinIfTxPduRef);

                        /* Locked */
                        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        /* Next entry */
                        chPtr->CurEntryIndex++;

                        /* Unlocked */
                        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
                        break;

                    case LINIF_SPORADIC:
                        sub = LinIf_GetTransmitPending(frame);
                        frameIdx = sub->LinIfSubstitutionFrameRef;
                        fra = &LINIF_GET_FRAME(ch, (frameIdx - LINIF_GET_FRAME_OFS(ch)));

                        /*@req <SWS_LinIf_00128> */
                        /* Notify upper */
                        txPduPtr = fra->LinIfPduDirection->LinIfTxPdu;
                        txPduPtr->LinIfTxConfirmationUL(txPduPtr->LinIfTxPduRef);

                        /* Locked */
                        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        /* Next entry */
                        chPtr->CurEntryIndex++;

                        /* Unlocked */
                        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        /*@req <SWS_LinIf_00463> */
                        /* A sporadic frame is transmitted successfully,
                           reset the pending flag */
                        LINIF_GET_TRANSMIT_REQ(frameIdx) = FALSE;
                        break;

#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
                    case LINIF_MRF:
                        LinTp_MasterTxSuccessHandle(ch);
                        break;
#endif

#if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON)
                    case LINIF_ASSIGN_NAD:
                    case LINIF_CONDITIONAL:
#endif
                    case LINIF_ASSIGN:
                    case LINIF_ASSIGN_FRAME_ID_RANGE:
                    case LINIF_FREE:
                    case LINIF_SAVE_CONFIGURATION:
                    case LINIF_UNASSIGN:
                        /* Locked */
                        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        /* Next entry */
                        chPtr->CurEntryIndex++;
                        LINIF_CLR_EVENT(LINIF_EVENT_NCMRF_SEND);
                        LINIF_SET_EVENT(LINIF_EVENT_NCSRF_SEND);

                        /* Unlocked */
                        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
                        break;

                    default:
                        /* Other Frame Type */
                        break;
                    }
                }
                else
                {
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
                    if ((st == LIN_TX_ERROR) || (st == LIN_TX_BUSY))
                    {
                        /*@req <SWS_LinIf_00036>,<SWS_LinIf_00465> */
                        /* Notify upper */
                        LinIf_ReportRuntimeError(LINIF_MAINFUNCTION_ID, LINIF_E_RESPONSE);
                    }
#endif /* #if (LINIF_DEV_ERROR_DETECT == STD_ON) */

#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
                    if (frame->LinIfFrameType == LINIF_MRF)
                    {
                        LinTp_MasterTxErrorHandle(ch, st);
                    }
                    else
#endif
                    {
                        /* Locked */
                        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        /* Next entry */
                        chPtr->CurEntryIndex++;

                        /* Unlocked */
                        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                        if (LINIF_IS_EVENT(LINIF_EVENT_NCMRF_SEND))
                        {
                            LINIF_CLR_EVENT(LINIF_EVENT_NCMRF_SEND);
                        }
                    }
                }
                break;

            case LINIF_INTERNAL_PDU:
            case LINIF_SLAVE_TO_SLAVE_PDU:
                /* Locked */
                SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                /* Next entry */
                chPtr->CurEntryIndex++;

                /* Unlocked */
                SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
                break;

            default:
                /* Other type PDU */
                break;
            }
        }
        else
        {
            if (LINIF_SPORADIC == frame->LinIfFrameType)
            {
                /* Locked */
                SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

                /* Next entry */
                chPtr->CurEntryIndex++;

                /* Unlocked */
                SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief: Process the next frame transmission
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_NextTransmit(uint8 ch)            /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame;

    if (chPtr->CurSchedule == NULL_PTR)
    {
        return;
    }

    frame = &LINIF_GET_FRAME(ch, (chPtr->CurEntry->LinIfFrameRef - LINIF_GET_FRAME_OFS(ch)));

    switch (frame->LinIfFrameType)
    {
    /* Sporadic frame */
    case LINIF_SPORADIC:
        LinIf_SendSporadic(ch, frame);
        break;

    /* Event-Trigger frame */
    case LINIF_EVENT_TRIGGERED:
        LinIf_SendEventTrigger(ch, frame);
        break;

    /* Unconditional frame */
    case LINIF_UNCONDITIONAL:
        LinIf_SendUnconditional(ch, frame);
        break;

#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
    /* Master request frame */
    case LINIF_MRF:
        LinIf_SendMRF(ch, frame);
        break;

    /* Slave response frame */
    case LINIF_SRF:
        LinIf_SendSRF(ch, frame);
        break;
#endif /* #if ((LINIF_TP_SUPPORTED == STD_ON) && \
               (STD_ON == LINIF_MASTER_SUPPORT)) */

#if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON)
    case LINIF_ASSIGN_NAD:
    case LINIF_CONDITIONAL:
#endif /* #if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON) */
    case LINIF_ASSIGN:
    case LINIF_ASSIGN_FRAME_ID_RANGE:
    case LINIF_FREE:
    case LINIF_SAVE_CONFIGURATION:
    case LINIF_UNASSIGN:
        LinIf_SendNodeConfiguration(ch, frame);
        break;

    default:
        /* Other type frame */
        break;
    }
}

/******************************************************************************/
/*
 * Brief: Updates the schedule strategy
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_UpdateSchedule(uint8 ch)          /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    /*@req <SWS_LinIf_00393> */
    if (LINIF_IS_EVENT(LINIF_EVENT_COLLISION))
    {
        LINIF_CLR_EVENT(LINIF_EVENT_COLLISION);

        /* Set 'collision-back' and 'notify' event */
        LINIF_SET_EVENT(LINIF_EVENT_INTERRUPT_BACK | LINIF_EVENT_SCHEDULE_CONF);

        /* Save schedule and entry information  */
        chPtr->ResSchedule = chPtr->CurSchedule;
        /*@req <SWS_LinIf_00485> */
        /* Save entry information */
        if (LINIF_CONTINUE_AT_IT_POINT == chPtr->CurSchedule->LinIfResumePosition)
        {
            chPtr->ResEntryIndex = chPtr->CurEntryIndex % chPtr->CurSchedule->LinIfNumOfEntry;
        }
        else
        {
            chPtr->ResEntryIndex = 0;
        }

        /*@req <SWS_LinIf_00176> */
        /* Switch to the collision resolving schedule table  */
        chPtr->CurSchedule = &LINIF_GET_SCHEDULE(ch, chPtr->CollisionResolvingRef - LINIF_GET_SCHEDULE_OFS(ch));
        chPtr->CurEntryIndex = 0;
    }
    else if (LINIF_IS_EVENT(LINIF_EVENT_SCHEDULE_REQ))
    {
        /* Uppler layer request NULL_SCHEDULE */
        if (NULL_PTR == chPtr->RdySchedule)
        {
            /*@req <SWS_LinIf_00444> */
            chPtr->CurSchedule = NULL_PTR;
            chPtr->CurEntry = NULL_PTR;
            chPtr->CurEntryIndex = 0;
            chPtr->ResSchedule = NULL_PTR;
            chPtr->ResEntryIndex = 0;
            chPtr->RootEvent = LINIF_EVENT_NONE;
            chPtr->Timer = 0;
#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
            LinTp_MasterChannelInit(ch);
#endif

            /* Clear Schedule Request flag */
            LINIF_CLR_EVENT(LINIF_EVENT_SCHEDULE_REQ);
            /* Set 'notify' event */
            LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_CONF);
        }
        else
        {
            /* Switch to the new schedule */
            LinIf_SwitchNewSchedule(ch);
        }
    }
    else
    {
        /* Nothing to do here */
    }

    /* Handles the last entry */
    LinIf_HandleEntryTail(chPtr);

    /* Process switch schedule notification */
    LinIf_SwitchScheduleNotify(ch);

    /* Switch to the new entry */
    LinIf_SwitchNewEntry(ch);
}

/******************************************************************************/
/*
 * Brief: Request the schedule table move to next entry
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_MoveScheduleToNextEntry(NetworkHandleType ch) /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA)             /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    /* Move to next entry */
    chPtr->CurEntryIndex++;
}

/******************************************************************************/
/*
 * Brief: Clear LinIf master event,LinTp master used the API interact with
 *        LinIf master
 * Param-Name[in]: ch, event
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_ClearEvent(NetworkHandleType ch, uint16 event) /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA)              /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    LINIF_CLR_EVENT(event);
}

/******************************************************************************/
/*
 * Brief: Set LinIf master event,LinTp master used the API interact with
 *        LinIf master
 * Param-Name[in]: ch, event
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SetEvent(NetworkHandleType ch, uint16 event) /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA)            /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    LINIF_SET_EVENT(event);
}

/******************************************************************************/
/*
 * Brief: Request the schedule table move to next entry
 * Param-Name[in]: ch, event
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)
LinIf_GetCurFrameType(                                                                 /* PRQA S 1532 */
                      NetworkHandleType ch,
                      P2VAR(LinIf_FrameTypeType, AUTOMATIC, LINIF_APPL_DATA) frameType /* PRQA S 3432 */
)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame;
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != chPtr->CurEntry)
    {
        frame = &LINIF_GET_FRAME(ch, (chPtr->CurEntry->LinIfFrameRef - LINIF_GET_FRAME_OFS(ch)));
        *frameType = frame->LinIfFrameType;
        ret = E_OK;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief: Request the schedule table move to next entry
 * Param-Name[in]: ch, event
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(boolean, LINIF_CODE) LinIf_IsEntryDelayTimeout(NetworkHandleType ch) /* PRQA S 1532 */
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA)            /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    boolean ret;

    if (LINIF_IS_TIMEOUT(ch))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief: Gets the channel state
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: Std_ReturnType
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(LinIf_ChannelStateType, LINIF_CODE)
LinIf_GetChannelState(/* PRQA S 1532 */
                      NetworkHandleType ch)
{
    return LinIf_MasterChRtData[ch].LinIfChannelState;
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief: Sends a sporadic frame.
 * Param-Name[in]: ch, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_CONST), LINIF_CODE)
    LinIf_GetTransmitPending(P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_CONST)
    sub = &frame->LinIfSubstitutionFrames[0];
    P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_CONST)
    retSub = NULL_PTR;
    uint8 idx;
    uint16 frameIdx;

    for (idx = 0u; idx < frame->LinIfNumOfSubstitutionFrame; idx++)
    {
        frameIdx = sub->LinIfSubstitutionFrameRef;
        if (TRUE == LINIF_GET_TRANSMIT_REQ(frameIdx))
        {
            retSub = sub;
            break;
        }
        sub++;
    }

    return retSub;
}

/******************************************************************************/
/*
 * Brief: Sends a sporadic frame.
 * Param-Name[in]: ch, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SendSporadic(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    P2CONST(LinIf_SubstitutionFramesType, AUTOMATIC, LINIF_APPL_CONST)
    sub = LinIf_GetTransmitPending(frame);
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    if (sub != NULL_PTR)
    {
        P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST)
        fra = &LINIF_GET_FRAME(ch, (sub->LinIfSubstitutionFrameRef - LINIF_GET_FRAME_OFS(ch)));
        PduInfoType pduInfo;
        uint8 sdu[8];
        P2CONST(LinIf_TxPduType, AUTOMATIC, LINIF_APPL_DATA) txPduPtr;
        Std_ReturnType ret;
        uint8 linDriver;
        uint8 linChannel;

        txPduPtr = fra->LinIfPduDirection->LinIfTxPdu;
        /* Get the data part of the frame from upper layer */
        pduInfo.SduDataPtr = &sdu[0];
        pduInfo.SduLength = fra->LinIfLength;
        /*@req <SWS_LinIf_00225>*/
        ret = txPduPtr->LinIfTxTriggerTransmitUL(txPduPtr->LinIfTxPduRef, &pduInfo);

        if (E_OK == ret)
        {
            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /* Set the header information */
            LinIf_SetPduInfo(&chPtr->TxPdu, fra);
            /* Set the response information */
            chPtr->TxPdu.SduPtr = pduInfo.SduDataPtr;

            /* Set the flag of header and response */
            LINIF_SET_EVENT(LINIF_EVENT_HEADER | LINIF_EVENT_RESPONSE);

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /*@req <SWS_LinIf_00226>*/
            /* Send frame */
            linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
            linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
            (void)LIN_DRIVER_API(linDriver).LinSendFrame(linChannel, &chPtr->TxPdu);
        }
        else
        {
            /*@req <SWS_LinIf_00706>*/
            /* When copy data fail from uppler layer,LinIf shall not transmit
               the frame */
        }
    }
}

/******************************************************************************/
/*
 * Brief: Sends a event trigger frame
 * Param-Name[in]: ch, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE)
    LinIf_SendEventTrigger(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    uint8 linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
    uint8 linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);

    /* Send header */
    LinIf_SetPduInfo(&chPtr->TxPdu, frame);
    chPtr->TxPdu.SduPtr = NULL_PTR;
    (void)LIN_DRIVER_API(linDriver).LinSendFrame(linChannel, &chPtr->TxPdu);

    /* Locked */
    SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

    /* Set the flag of header */
    LINIF_SET_EVENT(LINIF_EVENT_HEADER);

    /* Unlocked */
    SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
}

/******************************************************************************/
/*
 * Brief: Sends a unconditional frame
 * Param-Name[in]: ch, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE)
    LinIf_SendUnconditional(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    uint8 sdu[8];
    PduInfoType pduInfo;
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    P2CONST(LinIf_TxPduType, AUTOMATIC, LINIF_APPL_DATA) txPduPtr;
    Std_ReturnType ret = E_OK;
    uint8 linDriver;
    uint8 linChannel;

    if (LINIF_TX_PDU == frame->LinIfPduDirection->LinIfPduDirectionId)
    {
        txPduPtr = frame->LinIfPduDirection->LinIfTxPdu;
        /* Get the data part of the frame from upper layer */
        pduInfo.SduDataPtr = &sdu[0];
        pduInfo.SduLength = frame->LinIfLength;
        /*@req <SWS_LinIf_00225>*/
        ret = txPduPtr->LinIfTxTriggerTransmitUL(txPduPtr->LinIfTxPduRef, &pduInfo);

        if (E_OK == ret)
        {
            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /* Set the response information */
            chPtr->TxPdu.SduPtr = pduInfo.SduDataPtr;

            /* Set the flag of response */
            LINIF_SET_EVENT(LINIF_EVENT_RESPONSE);

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
        }
    }
    else
    {
        chPtr->TxPdu.SduPtr = NULL_PTR;
    }

    if (E_OK == ret)
    {
        /* Locked */
        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /* Set the header information */
        LinIf_SetPduInfo(&chPtr->TxPdu, frame);
        /* Set the flag of header */
        LINIF_SET_EVENT(LINIF_EVENT_HEADER);

        /* Unlocked */
        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /*@req <SWS_LinIf_00226>*/
        /* Send frame */
        linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        (void)LIN_DRIVER_API(linDriver).LinSendFrame(linChannel, &chPtr->TxPdu);
    }
    else
    {
        /*@req <SWS_LinIf_00706>*/
        /* When copy data fail from uppler layer,LinIf shall not transmit
           the frame */
    }
}

/******************************************************************************/
/*
 * Brief: Copies the memory block
 * Param-Name[in]: Src, len
 * Param-Name[out]: Dst
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_MemCopyFixedFrame(
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Dst, /* PRQA S 3432 */
    P2CONST(LinIf_FixedFrameSduType, AUTOMATIC, LINIF_APPL_CONST) Src)
{
    uint8 idx;

    for (idx = 0u; idx < 8u; idx++)
    {
        Dst[idx] = Src->LinIfFixedFrameSduByte[idx].LinIfFixedFrameSduByteVal;
    }
}

/******************************************************************************/
/*
 * Brief: Send a Node Configuration frame
 * Param-Name[in]: ch, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE)
    LinIf_SendNodeConfiguration(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    uint8 sdu[8];
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    uint8 linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
    uint8 linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);

    /* MRF */
    if (LINIF_TX_PDU == frame->LinIfPduDirection->LinIfPduDirectionId)
    {
        /* Locked */
        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /* Set the header information */
        LinIf_SetPduInfo(&chPtr->TxPdu, frame);

        LinIf_MemCopyFixedFrame(sdu, frame->LinIfFixedFrameSdu);
        /* Set the response information */
        chPtr->TxPdu.SduPtr = sdu;

        /* Set the flag of header and response */
        LINIF_SET_EVENT(LINIF_EVENT_HEADER | LINIF_EVENT_RESPONSE);
        /* Set the flag of NC MRF */
        LINIF_SET_EVENT(LINIF_EVENT_NCMRF_SEND);

        /* Unlocked */
        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /* Send frame */
        (void)LIN_DRIVER_API(linDriver).LinSendFrame(linChannel, &chPtr->TxPdu);
    }
    /* SRF */
    else if (LINIF_RX_PDU == frame->LinIfPduDirection->LinIfPduDirectionId)
    {
        if (LINIF_IS_EVENT(LINIF_EVENT_NCSRF_SEND))
        {
            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /* Set the header information */
            LinIf_SetPduInfo(&chPtr->TxPdu, frame);
            /* Set the response information */
            chPtr->TxPdu.SduPtr = NULL_PTR;

            /* Set the flag of header and response */
            LINIF_SET_EVENT(LINIF_EVENT_HEADER);

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /* Send frame */
            (void)LIN_DRIVER_API(linDriver).LinSendFrame(linChannel, &chPtr->TxPdu);
        }
        else
        {
            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /*@req <SWS_LinIf_00709>*/
            /* Next entry */
            chPtr->CurEntryIndex++;

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
        }
    }
    else
    {
        /* Only for MISRA-C */
    }
}

#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
/******************************************************************************/
/*
 * Brief: Sends a MRF frame
 * Param-Name[in]: ch, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SendMRF(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    uint8 linDriver;
    uint8 linChannel;
    uint8 sdu[8u];
    Std_ReturnType ret;

    ret = LinTp_MasterGetMRFResponse(ch, sdu);
    if (E_OK == ret)
    {
        /* Set up SDU buffer pointer */
        chPtr->TxPdu.SduPtr = sdu;

        /* Send header and response */
        LinIf_SetPduInfo(&chPtr->TxPdu, frame);
        linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        (void)LIN_DRIVER_API(linDriver).LinSendFrame(linChannel, &chPtr->TxPdu);
    }
}

/******************************************************************************/
/*
 * Brief: Sends a SRF frame
 * Param-Name[in]: ch, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SendSRF(uint8 ch, P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    uint8 linDriver;
    uint8 linChannel;

    if (FALSE == LinTp_IsStopSRFSendEventSet(ch))
    {
        /* Send header */
        LinIf_SetPduInfo(&chPtr->TxPdu, frame);
        chPtr->TxPdu.SduPtr = NULL_PTR;
        linDriver = LINIF_GET_LIN_DRIVER_ID(ch);
        linChannel = LINIF_GET_LIN_CHANNEL_ID(ch);
        (void)LIN_DRIVER_API(linDriver).LinSendFrame(linChannel, &chPtr->TxPdu);

        /* Locked */
        SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

        /* Set the flag of header */
        LINIF_SET_EVENT(LINIF_EVENT_HEADER);

        /* Unlocked */
        SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
    }
}
#endif /* #if ((LINIF_TP_SUPPORTED == STD_ON) && \
               (STD_ON == LINIF_MASTER_SUPPORT)) */

/******************************************************************************/
/*
 * Brief: Sets the PDU information
 * Param-Name[in]: pdu, frame
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SetPduInfo(
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) pdu, /* PRQA S 3432 */
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame)
{
    /* Save DL and PID */
    pdu->Dl = frame->LinIfLength;
    pdu->Pid = frame->LinIfProtectedId;

    /* Save checksum type */
    if (LINIF_ENHANCED == frame->LinIfChecksumType)
    {
        /* Enhanced frame */
        pdu->Cs = LIN_ENHANCED_CS;
    }
    else
    {
        /* Classic frame */
        pdu->Cs = LIN_CLASSIC_CS;
    }

    /* Save direction */
    switch (frame->LinIfPduDirection->LinIfPduDirectionId)
    {
    case LINIF_RX_PDU:
        pdu->Drc = LIN_SLAVE_RESPONSE;
        break;

    case LINIF_TX_PDU:
        pdu->Drc = LIN_MASTER_RESPONSE;
        break;

    case LINIF_SLAVE_TO_SLAVE_PDU:
        pdu->Drc = LIN_SLAVE_TO_SLAVE;
        break;

    /*case LINIF_INTERNAL_PDU:*/
    default:
        /*Other type PDU */
        break;
    }
}

/******************************************************************************/
/*
 * Brief: Handles the last entry
 * Param-Name[in]: ch, chPtr
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function called by 'LinIf_SwitchNewSchedule'
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE)
    LinIf_HandleEntryTail(P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) chPtr /* PRQA S 3432 */
    )
{
    /* Locked */
    SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

    /* If it is the last entry */
    if ((chPtr->CurSchedule != NULL_PTR) && (LINIF_IS_ENTRY_TAIL(ch)))
    {
        if (LINIF_IS_EVENT(LINIF_EVENT_SCHEDULE_REQ))
        {
            LINIF_CLR_EVENT(LINIF_EVENT_SCHEDULE_REQ);

            /* Switch to a new schedule */
            chPtr->CurSchedule = chPtr->RdySchedule;
            chPtr->CurEntryIndex = 0;

            if (LINIF_RUN_CONTINUOUS == chPtr->RdySchedule->LinIfRunMode)
            {
                chPtr->ResSchedule = NULL_PTR;
                chPtr->ResEntryIndex = 0;

                if (LINIF_IS_EVENT(LINIF_EVENT_INTERRUPT_BACK))
                {
                    /* Clear INTERRUPT_BACK flag */
                    LINIF_CLR_EVENT(LINIF_EVENT_INTERRUPT_BACK);
                }
            }
            else
            {
                /* LINIF_RUN_ONCE == chPtr->RdySchedule->LinIfRunMode */
                /* Hold the value of ResSchedule and ResEntryIndex */
            }

            /* Set 'notify' event */
            LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_CONF);
        }
        else if (LINIF_IS_EVENT(LINIF_EVENT_INTERRUPT_BACK))
        {
            /* Clear INTERRUPT_BACK flag */
            LINIF_CLR_EVENT(LINIF_EVENT_INTERRUPT_BACK);

            /*@req <SWS_LinIf_00397> */
            /* Resume schedule and entry */
            chPtr->CurSchedule = chPtr->ResSchedule;
            chPtr->CurEntryIndex = chPtr->ResEntryIndex;
            chPtr->ResSchedule = NULL_PTR;
            chPtr->ResEntryIndex = 0;

            /* Set 'notify' event */
            LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_CONF);
        }
        else
        {
            /* Update entry information */
            chPtr->CurEntryIndex = 0;
        }
    }

    /* Unlocked */
    SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
}

/******************************************************************************/
/*
 * Brief: Process switch schedule notify
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SwitchScheduleNotify(uint8 ch)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    LinIf_SchHandleType idx;

    /* Check notification event */
    if (LINIF_IS_EVENT(LINIF_EVENT_SCHEDULE_CONF))
    {
        /* Clear notification event */
        LINIF_CLR_EVENT(LINIF_EVENT_SCHEDULE_CONF);

        if (chPtr->CurSchedule == NULL_PTR)
        {
            idx = LINIF_NULL_SCHEDULE_INDEX;
        }
        else
        {
            idx = chPtr->CurSchedule->LinIfScheduleTableIndex;
        }

        /*@req <SWS_LinIf_00495> */
        /* Notify upper */
        USER_SCHEDULE_REQUEST_CONFIRMATION(ch, LINIF_GET_COMM_NETWORK(ch), idx);
    }
}

/******************************************************************************/
/*
 * Brief: Switches to a new schedule
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SwitchNewSchedule(uint8 ch)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);
    P2CONST(LinIf_FrameType, AUTOMATIC, LINIF_APPL_CONST) frame;
    uint16 frameIdx;

    /* Locked */
    SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

    if (chPtr->CurSchedule == NULL_PTR)
    {
        /* Setting up a new schedule */
        chPtr->CurSchedule = chPtr->RdySchedule;
        chPtr->CurEntryIndex = 0;
        chPtr->ResSchedule = NULL_PTR;
        chPtr->ResEntryIndex = 0;

        /* Clear Schedule Request flag */
        LINIF_CLR_EVENT(LINIF_EVENT_SCHEDULE_REQ);
        /* Set 'notify' event */
        LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_CONF);

        if (LINIF_RUN_ONCE == chPtr->RdySchedule->LinIfRunMode)
        {
            /* If schecule type is RUN_ONCE,should set flag to stop schedule
               after it run_once */
            LINIF_SET_EVENT(LINIF_EVENT_INTERRUPT_BACK);
        }
    }
    else
    {
        if (LINIF_RUN_CONTINUOUS == chPtr->CurSchedule->LinIfRunMode)
        {
            /* Clear Schedule Request flag */
            LINIF_CLR_EVENT(LINIF_EVENT_SCHEDULE_REQ);

            frameIdx = chPtr->RdySchedule->LinIfEntry[0].LinIfFrameRef - LINIF_GET_FRAME_OFS(ch);
            frame = &LINIF_GET_FRAME(ch, frameIdx);
            if (((LINIF_RUN_ONCE == chPtr->RdySchedule->LinIfRunMode)
                 && ((LINIF_MRF != frame->LinIfFrameType) && (LINIF_SRF != frame->LinIfFrameType)))
#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
                || (((LINIF_MRF == frame->LinIfFrameType) || (LINIF_SRF == frame->LinIfFrameType))
                    && (TRUE == LinTp_GetScheduleChangeDiag(ch))) /* PRQA S 3415 */
#endif
            )
            {
                /* Set 'interrupt-back' and 'notify' event */
                if (LINIF_RUN_ONCE == chPtr->RdySchedule->LinIfRunMode)
                {
                    LINIF_SET_EVENT(LINIF_EVENT_INTERRUPT_BACK);

                    /* Save schedule information  */
                    chPtr->ResSchedule = chPtr->CurSchedule;

                    /*@req <SWS_LinIf_00485> */
                    /* Save entry information */
                    if (LINIF_CONTINUE_AT_IT_POINT == chPtr->CurSchedule->LinIfResumePosition)
                    {
                        chPtr->ResEntryIndex = chPtr->CurEntryIndex % chPtr->CurSchedule->LinIfNumOfEntry;
                    }
                    else
                    {
                        chPtr->ResEntryIndex = 0;
                    }
                }
                LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_CONF);
            }
            else
            {
                /* Set 'notify' event */
                LINIF_SET_EVENT(LINIF_EVENT_SCHEDULE_CONF);

                chPtr->ResSchedule = NULL_PTR;
                chPtr->ResEntryIndex = 0;
            }

            /*@req <SWS_LinIf_00028> */
            /* Switch to a new schedule */
            chPtr->CurSchedule = chPtr->RdySchedule;
            chPtr->CurEntryIndex = 0;
        }
        else
        {
        }
    }

    /* Unlocked */
    SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
}

/******************************************************************************/
/*
 * Brief: Switches to a new entry
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) LinIf_SwitchNewEntry(uint8 ch)
{
    P2VAR(LinIf_MasterRuntimeType, AUTOMATIC, LINIF_APPL_DATA) /* PRQA S 3432 */
    chPtr = LINIF_CH(ch);

    if (chPtr->CurSchedule != NULL_PTR)
    {
        /* If it's not last entry */
        if (!LINIF_IS_ENTRY_TAIL(ch)
#if ((LINIF_TP_SUPPORTED == STD_ON) && (STD_ON == LINIF_MASTER_SUPPORT))
            /* TP buffer not enough */
            && (FALSE == LinTp_IsStopMRFOrSRFSendEventSet(ch)) /* PRQA S 3415 */
#endif
        )
        {
            /* Locked */
            SCHM_ENTER_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);

            /* Setting up a new entry */
            chPtr->CurEntry = &chPtr->CurSchedule->LinIfEntry[chPtr->CurEntryIndex];
            chPtr->Timer = chPtr->CurEntry->LinIfDelay;

            /* Unlocked */
            SCHM_EXIT_LINIF(LINIF_MODULE_ID, LINIF_AREA_EXEC);
        }
    }
}

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"

#endif /* #if (STD_ON == LINIF_MASTER_SUPPORT) */
