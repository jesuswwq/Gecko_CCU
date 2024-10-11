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
**  FILENAME    : PduR_Internal.h                                             **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : PDUR internal header for internal API declarations          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef PDUR_INTERNAL_H
#define PDUR_INTERNAL_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR.h"
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
    boolean NeedGateWayOnTheFly;
    uint8 ActiveTpBufferId;
    boolean TpTxConfirmation;
    PduLengthType TxBufferOffset;
} PduR_GateWayDestTpRunTimeType;

#if (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)
typedef enum
{
    PDUR_BUSY = 0u,
    PDUR_IDLE
} PduR_DestStateType;
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (PDUR_TP_BUFFER_SUM > 0u)

extern VAR(PduR_TpBufferTableType, PDUR_VAR_POWER_ON_INIT) PduR_TpBuffer[PDUR_TP_BUFFER_SUM];

#endif

#if (PDUR_TX_BUFFER_SUM > 0u)

extern CONST(PduR_TxBufferTableType, PDUR_CONST) PduR_TxBuffer[PDUR_TX_BUFFER_SUM];

#endif

#if (PDUR_DEFAULT_VALUE_LENGTH > 0u)

extern CONST(uint8, PDUR_CONST) PduR_Default_value[PDUR_DEFAULT_VALUE_LENGTH];

#endif

extern CONST(PduRBswModuleType, PDUR_CONST) PduR_BswModuleConfigData[PDUR_BSW_MODULE_SUM];

/*********************************
** define in PduR_Internal.c   **
**********************************/
/*all route dest pdus is enable or disable*/
#if (PDUR_DEST_PDU_SUM > 0u)

extern VAR(boolean, PDUR_VAR) PduRIsEnabled[PDUR_DEST_PDU_SUM];

#else

extern P2VAR(boolean, PDUR_VAR, PDUR_APPL_DATA) PduRIsEnabled;

#endif
/*******************************************************************************
**                      External function declarations                        **
*******************************************************************************/

extern FUNC(void, PDUR_CODE) PduR_InitHandle(void);

#if ((0u < PDUR_ROUTING_PATH_GROUP_MAX) && (PDUR_TX_BUFFER_SUM > 0u))
extern FUNC(void, PDUR_CODE) PduR_DestPduDefaultValueSet(PduIdType DestPduId, uint16 TxBufferId);
#endif

#if (STD_ON == PDUR_TX_CONFIRMATION)
extern FUNC(void, PDUR_CODE) PduR_MulticastIfPduTxConfirmationHandle(
    PduIdType TxMPduStateId,
    PduIdType UpPduId,
    PduR_UpIfTxConfirmation_FuncPtrType UpIfTxConfirmationApi);
#endif

#if ((STD_ON == PDUR_TX_CONFIRMATION) && (PDUR_TX_BUFFER_SUM > 0u))
extern FUNC(void, PDUR_CODE) PduR_IfTxConfirmationGatewayHandle(PduIdType TxPduId);
#endif

#if (STD_ON == PDUR_TRANSMIT_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_MulticastIfPduTxPending(PduIdType TxPduId);
#endif /*(STD_ON == PDUR_TRANSMIT_SUPPORT)*/

#if ((STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
extern FUNC(void, PDUR_CODE) PduR_GateWayDirectBufferHandle(
    PduR_LoIfTransmit_FuncPtrType pduR_LoIfTransmitApi,
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr);
#endif

#if (STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_StartOfReceptionToOneTpHandle(
    PduIdType SrcPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType Length,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
#endif                   /*STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT*/

#if (STD_ON == PDUR_TP_COPYRXDATA)
/*Rx Tp Pdu gateway to only one Tp Module Pdu handle,when copy Rx Data*/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyRxDataToOneTpHandle(
#if (0u < PDUR_TP_BUFFER_SUM)
    PduIdType SrcPduId,
#endif
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr);
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
#endif                   /*STD_ON == PDUR_TP_COPYRXDATA*/

#if (STD_ON == PDUR_TP_RXINDICATION)
/*Rx Tp Pdu gateway to only one Tp Module Pdu handle,when Rx Indication*/
extern FUNC(void, PDUR_CODE) PduR_RxIndicationToOneTpHandle(PduIdType SrcPduId, PduIdType DestPduId);
#endif /*STD_ON == PDUR_TP_RXINDICATION*/

#if (STD_ON == PDUR_TP_COPYTXDATA)
/*one Tp Pdu route to one Tp Pdu,the dest pdu copy tx data handle*/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_OneDestCopyTxDataFromTpHandle(
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
#endif                   /*STD_ON == PDUR_TP_COPYTXDATA*/

#if ((0u < PDUR_DEST_GATEWAY_TP_PDU_SUM) || (STD_ON == PDUR_TP_RXINDICATION) || (STD_ON == PDUR_TP_TXCONFIRMATION))
/*clear buffer and gateway state for gateway tp pdu*/
extern FUNC(void, PDUR_CODE) PduR_ClearBufferAndStateOfGateWayTpPdu(PduIdType PduRSrcPduId);
#endif /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM) || (STD_ON == PDUR_TP_RXINDICATION) || (STD_ON == \
          PDUR_TP_TXCONFIRMATION)*/

#if ((PDUR_TP_BUFFER_SUM > 0u) || (PDUR_TX_BUFFER_SUM > 0u))
/*copy data from source to dest*/
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
extern FUNC(void, PDUR_CODE) PduR_Memcpy(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) dest,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) source,
    PduLengthType length);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#endif

#if (((STD_ON == PDUR_TRIGGER_TRANSMIT) || (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)) && (PDUR_TX_BUFFER_SUM > 0u))
/*clear the buffer(the buffer data have transmit,Whether or not it succeeds)*/
extern FUNC(void, PDUR_CODE) PduR_DeQueueBuffer(PduIdType PduId);
#endif /*(((STD_ON == PDUR_TRIGGER_TRANSMIT)           \
         || (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)) \
         && (PDUR_TX_BUFFER_SUM > 0u))*/

#if ((STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
extern FUNC(void, PDUR_CODE)
    PduR_EnQueueBuffer(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfo);
#endif /*(STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u)*/

#endif /*STD_OFF == PDUR_ZERO_COST_OPERATION*/

#endif /* end of PDUR_INTERNAL_H */
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
