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
**  FILENAME    : LinTp_Types.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Type definitions of LinTp                                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef LINTP_TYPES_H
#define LINTP_TYPES_H

#include "ComStack_Types.h"
#include "LinIf_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (STD_ON == LINIF_TP_SUPPORTED)
/*@req <SWS_LinIf_00629> */
typedef enum
{
    LINTP_APPLICATIVE_SCHEDULE,
    LINTP_DIAG_REQUEST,
    LINTP_DIAG_RESPONSE
} LinTp_Mode;

typedef struct
{
    uint8 LinTpLinIfChannelRef; /* Refer to LinIf channel */
    boolean LinTpDropNotRequestedNad;
    boolean LinTpScheduleChangeDiag;
    NetworkHandleType LinTpChannelRef; /* Refer to ComM */
} LinTp_ChannelConfigType;

typedef struct
{
    uint8 LinTpLinIfChannelRef; /* Refer to LinIf channel */
    uint16 LinTpNcr;
    PduIdType LinTpRxNSduId;
    uint8 LinTpRxNSduNad;
    NetworkHandleType LinTpRxNSduChannelRef; /* Refer to ComM */
    PduIdType LinTpRxNSduPduRef;
} LinTp_RxNSduType;

typedef struct
{
    uint8 LinTpLinIfChannelRef; /* Refer to LinIf channel */
    uint8 LinTpMaxBufReq;
    uint16 LinTpNas;
    uint16 LinTpNcs;
    PduIdType LinTpTxNSduId;
    uint8 LinTpTxNSduNad;
    NetworkHandleType LinTpTxNSduChannelRef; /* Refer to ComM */
    PduIdType LinTpTxNSduPduRef;
} LinTp_TxNSduType;

typedef struct
{
    uint16 LinTpMaxNumberOfRespPendingFrames;
    uint16 LinTpMaxRxNSduCnt;
    uint16 LinTpNumOfRxNSdu;
    uint16 LinTpMaxTxNSduCnt;
    uint16 LinTpNumOfTxNSdu;
    uint16 LinTpP2Max;
    uint16 LinTpP2Timing;
    P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) LinTpChannelConfig;
    P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) LinTpRxNSdu;
    P2CONST(LinTp_TxNSduType, AUTOMATIC, LINIF_APPL_CONST) LinTpTxNSdu;
} LinTp_ConfigType;

#endif /* #if (STD_ON == LINIF_TP_SUPPORTED) */

#endif /* #ifndef LINTP_TYPES_H */
