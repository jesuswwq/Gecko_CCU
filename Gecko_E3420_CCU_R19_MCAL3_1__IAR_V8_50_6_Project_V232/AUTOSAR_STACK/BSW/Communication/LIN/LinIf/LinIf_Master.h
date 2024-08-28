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
**  FILENAME    : LinIf_Master.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef LINIF_MASTER_H
#define LINIF_MASTER_H

#include "LinIf.h"
#include "LinIf_Internal.h"

#if (STD_ON == LINIF_MASTER_SUPPORT)
/*******************************************************************************
**                      Macros Definitions                                    **
*******************************************************************************/

/*******************************************************************************
**                      Runtime Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/******************************************************************************/
/*
 * Brief               Initializes the LinIf slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_MasterInit(void);

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
FUNC(Std_ReturnType, LINIF_CODE) LinIf_MasterTransmit(NetworkHandleType ch, uint16 frameIdx);

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
FUNC(Std_ReturnType, LINIF_CODE) LinIf_MasterScheduleRequest(NetworkHandleType ch, LinIf_SchHandleType Schedule);

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
FUNC(void, LINIF_CODE) LinIf_MasterGotoSleep(NetworkHandleType ch);

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
FUNC(void, LINIF_CODE) LinIf_SleepProcess(uint8 ch);

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
FUNC(Std_ReturnType, LINIF_CODE) LinIf_MasterWakeUp(NetworkHandleType ch);

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
FUNC(void, LINIF_CODE) LinIf_MasterWakeupConfirmation(EcuM_WakeupSourceType WakeupSource);

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
FUNC(void, LINIF_CODE) LinIf_WakeUpProcess(uint8 ch);

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
FUNC(void, LINIF_CODE) LinIf_SlotTimer(uint8 ch);

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
FUNC(void, LINIF_CODE) LinIf_PrevTransmit(uint8 ch);

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
FUNC(void, LINIF_CODE) LinIf_NextTransmit(uint8 ch);

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
FUNC(void, LINIF_CODE) LinIf_UpdateSchedule(uint8 ch);

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
FUNC(void, LINIF_CODE) LinIf_MoveScheduleToNextEntry(NetworkHandleType ch);

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
FUNC(void, LINIF_CODE) LinIf_ClearEvent(NetworkHandleType ch, uint16 event);

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
FUNC(void, LINIF_CODE) LinIf_SetEvent(NetworkHandleType ch, uint16 event);

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
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
LinIf_GetCurFrameType(NetworkHandleType ch, P2VAR(LinIf_FrameTypeType, AUTOMATIC, LINIF_APPL_DATA) frameType);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

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
FUNC(boolean, LINIF_CODE) LinIf_IsEntryDelayTimeout(NetworkHandleType ch);

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
FUNC(LinIf_ChannelStateType, LINIF_CODE) LinIf_GetChannelState(NetworkHandleType ch);

#endif /* #if (STD_ON == LINIF_MASTER_SUPPORT) */

#endif /* LINIF_SLAVE_H */
