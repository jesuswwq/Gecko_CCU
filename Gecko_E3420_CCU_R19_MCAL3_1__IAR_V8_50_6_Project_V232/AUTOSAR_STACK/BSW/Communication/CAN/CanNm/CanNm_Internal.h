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
**  FILENAME    : CanNm_Internal.h                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>       <REVISION LOG>
 *  V2.0.0       2020-07-29  Wanglili       R19_11 initial version.
 */
#ifndef CANNM_INTERNAL_H_
#define CANNM_INTERNAL_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* CBV(Control bit vector)  consist*/
/* repeat message request bit */
#define CANNM_CBV_BIT_RMP_MASK ((uint8)(0x01u))
/* NM Coordinator sleep ready bit */
#define CANNM_CBV_BIT_CSR_MASK ((uint8)(0x08u))
/* active wakeup bit */
#define CANNM_CBV_BIT_AW_MASK ((uint8)(0x10u))
/* partial Network information bit */
#define CANNM_CBV_BIT_PNI_MASK  ((uint8)(0x40u))

#define CANNM_DEFAULT_NMPDU_LEN (8u)

/* Define in which channel handle EIRA timer */
/*
 * Note: EIRA is related to all channels, but only needs to handle the timer
 * in one of the channels.
 */
#define CANNM_EIRA_HANDLE_CHANNEL (0u)

#if (STD_ON == CANNM_DEV_ERROR_DETECT)
#define CANNM_DET_REPORT(ApiId, ErrorId) ((void)Det_ReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, (ApiId), (ErrorId)))
#else
#define CANNM_DET_REPORT(ApiId, ErrorId)
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */

#define CANNM_DET_REPORTRUNTIMEERROR(ApiId, ErrorId) \
    ((void)Det_ReportRuntimeError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, (ApiId), (ErrorId)))

#define CanNm_GetChannelRTData(ch)          (CanNm_ChRunTime[ch])

#define CanNm_GetChannelConfig(ch)          (CanNm_CfgPtr->ChannelConfig[ch])

#define CanNm_GetPduCbvPosition(ch)         (CanNm_GetChannelConfig(ch).PduCbvPosition)

#define CanNm_GetPduNidPosition(ch)         (CanNm_GetChannelConfig(ch).PduNidPosition)

#define CanNm_GetNodeId(ch)                 (CanNm_GetChannelConfig(ch).NodeId)

#define CanNm_GetComMNetworkHandle(ch)      (CanNm_GetChannelConfig(ch).ComMNetworkHandleRef)

#define CanNm_GetBusLoadReduceEnabled(ch)   (CanNm_GetChannelConfig(ch).BusLoadReductionActive)

#define CanNm_GetCarWakeUpRxEnabled(ch)     (CanNm_GetChannelConfig(ch).CarWakeUpRxEnabled)

#define CanNm_GetCarWakeUpFilterEnabled(ch) (CanNm_GetChannelConfig(ch).CarWakeUpFilterEnabled)

#define CanNm_GetCarWakeUpFilterNodeId(ch)  (CanNm_GetChannelConfig(ch).CarWakeUpFilterNodeId)

#if (STD_ON == CANNM_VER_4_2_2)
#define CanNm_GetNodeIdEnabled(ch)        CANNM_NODE_ID_ENABLED

#define CanNm_GetNodeDetectionEnabled(ch) (CANNM_NODE_DETECTION_ENABLED == STD_ON)

#define CanNm_GetRepeatMsgIndEnabled(ch)  CANNM_REPEAT_MSG_IND_ENABLED
#else
#define CanNm_GetNodeIdEnabled(ch)        (CanNm_GetChannelConfig(ch).NodeIdEnabled)

#define CanNm_GetNodeDetectionEnabled(ch) (CanNm_GetChannelConfig(ch).NodeDetectionEnabled)

#define CanNm_GetRepeatMsgIndEnabled(ch)  (CanNm_GetChannelConfig(ch).RepeatMsgIndEnabled)
#endif

#define CanNm_GetPnInfo()         (*(CanNm_CfgPtr->PnInfo))

#define CanNm_GetPnResetTime()    (CanNm_CfgPtr->PnResetTime)

#define CanNm_GetPnEiraRxNSduId() (CanNm_CfgPtr->CanNmPnEiraRxNSduRef)

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
#define CanNm_GetPnEiraInfo()       (CanNm_InnerGlobal.pnEiraInfo)

#define CanNm_GetPnEiraResetTimer() (CanNm_InnerGlobal.pnEiraResetTimer)
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */

#define CanNm_SetTxPduCbvBit(chIndex, mask)                                                        \
    do                                                                                             \
    {                                                                                              \
        if (CANNM_PDU_OFF != CanNm_GetPduCbvPosition(chIndex))                                     \
        {                                                                                          \
            SchM_Enter_CanNm_Network(chIndex);                                                     \
            CanNm_ChRunTime[chIndex].txPduData[(uint8)CanNm_GetPduCbvPosition(chIndex)] |= (mask); \
            SchM_Exit_CanNm_Network(chIndex);                                                      \
        }                                                                                          \
    } while (0)

#define CanNm_ClrTxPduCbvBit(chIndex, mask)                                                         \
    do                                                                                              \
    {                                                                                               \
        if (CANNM_PDU_OFF != CanNm_GetPduCbvPosition(chIndex))                                      \
        {                                                                                           \
            SchM_Enter_CanNm_Network(chIndex);                                                      \
            CanNm_ChRunTime[chIndex].txPduData[(uint8)CanNm_GetPduCbvPosition(chIndex)] &= ~(mask); \
            SchM_Exit_CanNm_Network(chIndex);                                                       \
        }                                                                                           \
    } while (0)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
    CANNM_UNINIT,
    CANNM_INIT_SUCCESS,
    CANNM_INIT_FAIL
} CanNm_InitStatusType;

typedef enum
{
    CANNM_NETWORK_REQUESTED,
    CANNM_NETWORK_RELEASED
} CanNm_NetRequestStatusType;

typedef enum
{
    CANNM_CSR_IND_INIT,
    CANNM_CSR_IND_CANCELLED,
    CANNM_CSR_IND_INDICATED
} CanNm_CSRIndStatusType;

typedef struct
{
    /* current canNm state */
    Nm_StateType canNmState;
    /* network mode */
    Nm_ModeType cannmMode;
    /* Network request status */
    CanNm_NetRequestStatusType netRequestStatus;
    /* Indicate if CanNm_NetworkRequest was called within two MainFunction */
    boolean netRequestFlg;
    /* Passive startup flag */
    boolean passiveStartUp;

#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
    /* tx ablity */
    boolean canNmTxEnable;
#endif /* STD_ON == CANNM_COM_CONTROL_ENABLED */
    boolean rxPduFlg;
    boolean rxPduExtFlg;

#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
    CanNm_CSRIndStatusType coordReadyToSleepInd;
#endif /* STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT */

/* detected Remote Sleep */
#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
    boolean remoteSleepInd;
    uint16 remoteTimer;
    /*record the remote sleep timer passed before the timer suspended*/
    uint16 remoteTimerpassed;
#endif /* STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED */

#if (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED)
    /* Immediate transmit nm pdu count */
    uint8 immedMsgTxCnt;
#endif /* STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED */

    /* state timer */
    uint16 stateTimer;
    /* nm timeout timer */
    uint16 nmTimeoutTimer;
    boolean stateToutFlg;
    boolean nmToutFlg;

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
    /* tx message cycle timer */
    uint16 msgTxCylceTimer;

    uint16 msgTimeoutTimer;

    /* First NM Pdu send,if need retry */
    boolean retrySendMsgFlag;

    boolean msgToutFlg;

    boolean sendNmMsgFlg;
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
    boolean repeatMessageRequest;
#endif /* STD_ON == CANNM_NODE_DETECTION_ENABLED */

    /* last rx pdu data */
    uint8 rxPduData[CANNM_DEFAULT_PDU_LENGTH];

    /* last tx pdu data */
    uint8 txPduData[CANNM_DEFAULT_PDU_LENGTH];

/* pn function this is ERA*/
#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
    uint8 pnInfoEra[CANNM_PN_INFO_LENGTH];
    uint16 pnEraResetTimer[CANNM_PN_NUM];
/* store pn info */
#endif /* STD_ON == CANNM_PN_ERA_CALC_ENABLED */

#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
    boolean pnRxIndFlg;
    boolean pnFilterEnable;
#endif /* STD_ON == CANNM_GLOBAL_PN_SUPPORT */
} CanNm_InnerChannelType;

#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT) && (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
typedef struct
{
    uint8 pnEiraInfo[CANNM_PN_INFO_LENGTH];
    uint16 pnEiraResetTimer[CANNM_PN_NUM];
} CanNm_InnerGlobalType;
#endif /* (STD_ON == CANNM_GLOBAL_PN_SUPPORT) && (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* CANNM_INTERNAL_H_ */
