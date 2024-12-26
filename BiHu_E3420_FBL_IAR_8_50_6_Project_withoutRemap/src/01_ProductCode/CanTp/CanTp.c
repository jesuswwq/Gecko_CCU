/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : CanTp.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : TP (ISO 15765-2) source component.                          **
**                                                                            **
**  SPECIFICATION(S) : None                     		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *    V1.0.0    20190101   Lianren Wu    New Version
 *    V1.0.1    20200309   Lianren Wu    modify state of CanTp for the function
 *                                       of full-duplex communication.
 *    V1.0.2    20200312   Lianren Wu    modify the question: sendNRC(0x78),not continue run.
 *    V1.0.3    20200314   Lianren Wu    recode for the full-duplex test, the test is pass.
 *    V1.0.4    20200325   Lianren Wu    modify: if notification the DCM success,the  call
 *                                       CanTp_Init15765Runtime_RxData to init the rxData.
 *    V1.0.5    20200328   Lianren Wu    modify: if the stim of rxFC is reserved value,
 *                                       then set the stim to 127ms.
 *    V1.0.6    20200329   Lianren Wu    modify: AFTER rx FC frame,set the timeout as CANTP_N_CS.
 *    V1.0.7    20200403   Lianren Wu    modify: FF receive judge the Pdu length of FF is large then
 *                                       CANTP_STD_ADDR_MAX_SF_LEGNTH, not the CANTP_STD_ADDR_MAX_SF_LEGNTH +1.
 *                                       add FC overflow Tx confirmation.
 *    V1.0.8    20200425   Lianren Wu    QAC 9.5 Test.
 *    V1.0.9    20200425   Lianren Wu    solve the problem of receive Multiple SF Frame and the
 *                                       timeout of SNEDING NRC 78.
 *    V1.0.10   20200606   Lianren Wu    change the type of timeoutCounterValue of CanTp_RunTime_RxDataType
 *                                       and CanTp_RunTime_TxDataType to uint16
 *    V1.0.11   20200710   Lianren Wu    add the rx SF (3e 80) handle in CanTp_ReceiveSingleFrame.
 *    V1.0.12   20210326   Lianren Wu    add the check of PduAddressin when receive Continue Frame.
 *    V1.0.13   20231116   Long.Zhu		 1.There is an upper limit to the number of FC.WAIT.
 *										 2.Non-standard macro substitution.
 *										 3.Unified Boolean type definition.
 *    V1.0.14   20240403   Chunjun.Hua   1.fix bug of not responding SF after FF
 *                                       2.fix bug of not responding FF after FF
 *                                       3.fix bug of not responding new request while sending CF in duplex mode
 *    V1.0.15   20240424   Chunjun.hua   QAC fix
 *    V1.0.16   20240513   yaowei.shen  Modify the CANFD single-frame format error response.
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:CanTp .<br>
  RuleSorce:puhua-rule2024.rcf 1.0.2

    \li PRQA S 499  Rule 12.2 .<br>
    Reason: Right operand of shift operator is greater than or equal to the width of the essential type of the left operand.
    
    \li PRQA S 2877  Dir 4.1 .<br>
    Reason: Loop control variable is defined by macro according to actual situation.

    \li PRQA S 2983  Dir 2.2 .<br>
    Reason: Whether the value will be used depends on loop times.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_Cfg.h"
#include "CanIf.h"
#include "Dcm_Internel.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static uint8 CanTp_FindIndexFromRxChannel(
    PduIdType CanTp_pduId,
    const PduInfoType* CanTp_objRxPtr,
    uint8* const CanTp_pci,
    uint8* const CanTp_pciOffset);

#if (STD_ON == CANTP_FD_SUPPORT)
static boolean CanTp_checkLastCF(PduLengthType CF_DL, PduLengthType CAN_DL, uint8 Offset);
static boolean CanTp_checkSF(PduLengthType SF_DL, PduLengthType CAN_DL, uint8 Offset);
#endif

static uint8 CanTp_FindTpTxConfirmIndexFromRxChannel(PduIdType const CanTp_txPduId);

#if (STD_ON == CANTP_RX_PADDING_CHECK)
static boolean CanTp_FramePaddingCheck(
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_checkDataOffset,
    const PduLengthType PduLength);
#endif

#if (STD_ON == CANTP_TX_PADDING_ON)
static void CanTp_FrameAddPadding(
    const CanTp_TxSduType* const CanTp_txConfig,PduInfoType* const CanTp_pduInfo);
#endif

#if (STD_ON == CANTP_FD_SUPPORT)
static void CanTp_FDFrameAddPadding(
    const CanTp_TxSduType* const CanTp_txConfig,
    PduInfoType* const CanTp_pduInfo,
    const PduLengthType SduLength);
#endif

static void CanTp_ReceiveSingleFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_RxSduType* const CanTp_rxConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_dataLength,
    const uint8 CanTp_pciOffset);

static void CanTp_ReceiveFirstFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_RxSduType* const CanTp_rxConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const PduLengthType pduLength,
    const uint8 Offset);

static void CanTp_ReceiveConsecutiveFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_RxSduType* const CanTp_rxConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_pciOffset);

static void CanTp_ReceiveFlowControlFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_TxSduType* const CanTp_txConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_pciOffset);

static void CanTp_WaitSForLastCFBufProcess(
    const CanTp_RxSduType* const CanTp_rxConfig,
    CanTp_RunTime_Type* const CanTp_RunTime);

static BufReq_ReturnType CanTp_WaitCFBufProcess(
    const CanTp_RxSduType* const CanTp_rxConfig,
    CanTp_RunTime_Type* const CanTp_runtime);

static BufReq_ReturnType CanTp_CopySegmentToRxBuffer(
    const CanTp_RxSduType* const CanTp_rxConfig,
    CanTp_RunTime_RxDataType* const CanTp_rxRuntime);

static boolean CanTp_CopyDataToMsgFromTxBuf(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_TxDataType* const CanTp_txRuntime,
    PduInfoType* const CanTp_pduInfo,
    const uint8 actualPayloadLength);

static CanTp_Iso15765FrameType CanTp_calcTxFrameType(
    const CanTp_TxSduType* const CanTp_txConfig,
    const CanTp_RunTime_TxDataType* const CanTp_txRuntime);

static void CanTp_SendTxFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_Iso15765FrameType CanTp_framType);

static void CanTp_SendSingleFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    PduInfoType* const CanTp_pduInfo);

static void CanTp_SendFirstFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    PduInfoType* const CanTp_pduInfo);

static void CanTp_SendFlowControlFrame(
    const CanTp_RxSduType* const CanTp_rxConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    BufReq_ReturnType const CanTp_flowStatus);

static void CanTp_SendConsecutiveFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    PduInfoType* const CanTp_pduInfo);

static boolean CanTp_Send_Check(CanTp_RunTime_Type* const canTpRunTime);

static boolean CanTp_Send_FC_TimeOut_Check(CanTp_RunTime_Type* const canTpRunTime);

static boolean CanTp_Send_TimeOut_Check(CanTp_RunTime_Type* const canTpRunTime);

#if (STD_ON == CANTP_FD_SUPPORT)
static PduLengthType CanTp_MatchDLC(PduLengthType frameDL);
#endif

static uint16 CanTp_ConvertMsToMainCycles(uint16 x);
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* static global variable  */
static CanTp_RunTime_Type CanTp_Runtime;

static void CanTp_Init15765Runtime_RxData(CanTp_RunTime_RxDataType* const CanTp_runtime);

static void CanTp_Init15765Runtime_TxData(CanTp_RunTime_TxDataType* const CanTp_runtime);

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/********************************************************************************/
/****
 * brief            : CanTp_Init
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <NONE>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
void CanTp_Init(void) 
{
    /* initial runtime item for TX and RX*/
    CanTp_Init15765Runtime_TxData(&CanTp_Runtime.tx_RunTime);
    CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
}

/********************************************************************************/
/****
 * brief            : CanTp_RxIndication
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CanTp_pduId:ID of the received PDU.
 * 					   CanTp_objRxPtr:Contains the length (SduLength) of the received PDU, a pointer to a
 *						buffer (SduDataPtr) containing the PDU, and the MetaData related to this
 *						PDU.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
void CanTp_RxIndication(PduIdType CanTp_pduId, const PduInfoType* CanTp_objRxPtr) 
{
    PduLengthType pduLength;
    /* PCI: Protocol Control Information */
    uint8 iloop;
    uint8 CanTp_pci = (uint8)0u;
    uint8 CanTp_pciOffset = (uint8)0u;
    uint8 Offset;
    /* find CanTp_pduId from received message is the valid PDUID or not */
    iloop = CanTp_FindIndexFromRxChannel(CanTp_pduId, CanTp_objRxPtr, &CanTp_pci, &CanTp_pciOffset);
    Offset = CanTp_pciOffset;
    /* if the return index not equal to CANTP_INVALID_INDEX, this means the PDUID is a valid PDUID. */
    if ((uint8)CANTP_INVALID_INDEX != iloop)
    {
        switch (CanTp_pci & (uint8)CANTP_PCI_MASK)
        {
        case (uint8)CANTP_PCI_SF:
            /* get the data length of SF */
            /*PCI is byte[0]*/
            pduLength = ((PduLengthType)CanTp_pci);
#if (STD_ON == CANTP_FD_SUPPORT)
            if (((PduLengthType)0x0u == pduLength) && (CAN_FD == CanTp_RxSdu[iloop].CanFrameType)
                && (CanTp_objRxPtr->SduLength > (PduLengthType)8u))
            {
                pduLength = (PduLengthType)CanTp_objRxPtr->SduDataPtr[Offset + 1u];
                Offset += (uint8)1u;
            }           		
            else if((0x0u != pduLength) && (CanTp_objRxPtr->SduLength > 8u))
            {
                pduLength = 0u;
            }
            else
            {
                /* empty */
            }
#endif
            /* check the valid frame for SF
             * 1. pduLength > CanTp_objRxPtr->SduLength(Rx PDU length) - (1u + CanTp_pciOffset)
             * 2. pduLength not match FD length
             * 3. pduLength == zero any all of above, it should be an invalid frame. */
            if (((CanTp_objRxPtr->SduLength - ((PduLengthType)1u + (PduLengthType)Offset)) < pduLength)
#if (STD_ON == CANTP_FD_SUPPORT)
                || ((CanTp_objRxPtr->SduLength != CanTp_MatchDLC(CanTp_objRxPtr->SduLength))
                    && (CanTp_objRxPtr->SduLength > (PduLengthType)CANTP_DRV_PDU_MAX_LENGTH))
                || ((boolean)FALSE
                    == CanTp_checkSF(pduLength, CanTp_MatchDLC(CanTp_objRxPtr->SduLength), CanTp_pciOffset))
#endif
                || ((PduLengthType)0U == pduLength) || (CanTp_objRxPtr->SduLength > CanTp_RxSdu[iloop].RxNPduDLC))
            {
                /* invalid frame */
            }
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
            else if (CANTP_IDLE != CanTp_Runtime.tx_RunTime.tpState)
            {
                /* invalid frame */
            }
#endif
            else
            {
                /* deal with single frame */
                CanTp_ReceiveSingleFrame(&CanTp_Runtime, &CanTp_RxSdu[iloop], CanTp_objRxPtr, (uint8)pduLength, Offset);
            }
            break;
        case (uint8)CANTP_PCI_FF:
            /* 1. first frame length must be 8 (the max length of class can)*/
            /* 2. function address is only support single frame */
            /* 3. the pduLength of FF should lager than the max of SF'length any not all of above, it should be an
             * invalid frame */
            if ((CANTP_DRV_PDU_MAX_LENGTH > CanTp_objRxPtr->SduLength)
#if (STD_ON == CANTP_FD_SUPPORT)
                || (
                    (CanTp_objRxPtr->SduLength != CanTp_MatchDLC(CanTp_objRxPtr->SduLength))
                    && (CanTp_objRxPtr->SduLength > (uint16)CANTP_DRV_PDU_MAX_LENGTH)
                    )
#endif
                || (RX_PHYSICAL_ADDRESSING != CanTp_RxSdu[iloop].rxPduType)
                || (CanTp_objRxPtr->SduLength > CanTp_RxSdu[iloop].RxNPduDLC))
            {
                /* invalid frame */
            }
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
            else if (CANTP_IDLE != CanTp_Runtime.tx_RunTime.tpState)
            {
                /* invalid frame */
            }
#endif
            else
            {
                /* get the data length of FF */
                pduLength =
                    (((PduLengthType)CanTp_pci & 0x0Fu) << 8u) + (PduLengthType)CanTp_objRxPtr->SduDataPtr[Offset + 1u];
                Offset += (uint8)2u;
                if ((uint16)0x0u == pduLength)
                {
                    pduLength = ((PduLengthType)CanTp_objRxPtr->SduDataPtr[Offset] << 24u) |      /*PRQA S 0499*/
                                ((PduLengthType)CanTp_objRxPtr->SduDataPtr[Offset + 1u] << 16u) | /*PRQA S 0499*/
                                ((PduLengthType)CanTp_objRxPtr->SduDataPtr[Offset + 2u] << 8u)
                                | (PduLengthType)CanTp_objRxPtr->SduDataPtr[Offset + 3u];
                    Offset += (uint8)4U;
                    if (pduLength <= (uint16)4095u)
                    {
                        pduLength = (uint16)0U;
                    }
                }
                /* 3. the pduLength of FF should lager than the max of SF'length any not all of above, it should be an
                 * invalid frame.*/
                if (((CanTp_objRxPtr->SduLength == (uint16)8U) && (pduLength < (uint16)(8u - (uint16)CanTp_pciOffset)))
                    || ((CanTp_objRxPtr->SduLength > (uint16)8U)
                        && (pduLength < (uint16)(CanTp_objRxPtr->SduLength - CanTp_pciOffset - 1U))))
                {
                    /* invalid frame */
                }
                else
                {
                    /* deal with physics address FF */
                    CanTp_ReceiveFirstFrame(&CanTp_Runtime, &CanTp_RxSdu[iloop], CanTp_objRxPtr, pduLength, Offset);
                }
            }
            break;
        case (uint8)CANTP_PCI_CF:
            /* deal with consecutive frame
             * 1. the state should be in the state of wait CF; if not, it should be an invalid frame. */
            /* 2. function address is only support single frame */
            if ((CANTP_WAIT_CF == CanTp_Runtime.rx_RunTime.tpRxState)
                && (((PduIdType)RX_PHYSICAL_ADDRESSING == CanTp_RxSdu[iloop].rxPduType)))
            {
#if (STD_ON == CANTP_FD_SUPPORT)
                if (((CanTp_objRxPtr->SduLength != CanTp_MatchDLC(CanTp_objRxPtr->SduLength))
                     && (CanTp_objRxPtr->SduLength >= (uint16)8u))
                    || (CanTp_objRxPtr->SduLength > CanTp_RxSdu[iloop].RxNPduDLC))
                {
                    /*idle*/
                }
                else
#endif
                {
                    CanTp_ReceiveConsecutiveFrame(&CanTp_Runtime, &CanTp_RxSdu[iloop], CanTp_objRxPtr, Offset);
                }
            }
            break;
        case (uint8)CANTP_PCI_FC:
            /* 1. when receive FC frame, it should send FF first, and set the tpState of RuntimeData to
             * CANTP_WAITING_FOR_FC_RX state. (here index is the )
             * 2. the RX PDU length should larger than 3,
             * 3. should be physical address. */
#if (STD_ON == CANTP_FD_SUPPORT)
            if ((((CanTp_objRxPtr->SduLength != CanTp_MatchDLC(CanTp_objRxPtr->SduLength))
                 && (CanTp_objRxPtr->SduLength >= (uint16)8u)))
                || (CanTp_objRxPtr->SduLength > CanTp_RxSdu[CanTp_TxSdu[iloop].rxFcPduId].RxNPduDLC))
            {
                /*idle*/
            }
            else
#endif
                if ((CANTP_WAIT_FC == CanTp_Runtime.tx_RunTime.tpState) && (CanTp_objRxPtr->SduLength >= (uint16)3u)
                    && ((PduIdType)RX_PHYSICAL_ADDRESSING == CanTp_RxSdu[CanTp_TxSdu[iloop].rxFcPduId].rxPduType))
            {
                /* we only receive FC with CTS */
                if ((uint8)CANTP_FC_STATUS_CTS == (uint8)(CanTp_pci & (uint8)CANTP_PCI_FS_MASK))
                {
                    /* RX, FC; in the TX-channel configuration */
                    /* deal with a flow control frame */
                    CanTp_ReceiveFlowControlFrame(&CanTp_Runtime, &CanTp_TxSdu[iloop], CanTp_objRxPtr, Offset);
                }
                /* fixme : if rx flow control frame is WT or  overflow, how the TP-module handle. */
                else if ((uint8)CANTP_FC_STATUS_WT == (uint8)(CanTp_pci & (uint8)CANTP_PCI_FS_MASK))
                {
                    /* set tx state to wait flow control frame */
                    CanTp_Runtime.tx_RunTime.tpState = CANTP_WAIT_FC;

                    /*There is an upper limit to the number of FC.WAIT.*/
                    if(CanTp_Runtime.tx_RunTime.WTFCCounterValue <= CANTP_N_WFTmax)
                    {
                        CanTp_Runtime.tx_RunTime.timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_BS));
                        CanTp_Runtime.tx_RunTime.WTFCCounterValue++;
                    }
                }
                else if ((uint8)CANTP_FC_STATUS_OVFLW == (uint8)(CanTp_pci & (uint8)CANTP_PCI_FS_MASK))
                {
                    /* receive 0x32  OVFLW, then free buffer of DCM, set tp state to idle */
                    PduR_TxConfirmation(CanTp_TxSdu[iloop].txDcmId, NTFRSLT_E_NOT_OK);
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
                    CanTp_Init();
#else
                    CanTp_Init15765Runtime_TxData(&CanTp_Runtime.tx_RunTime);
#endif
                }
                else
                {
                    /* empty */
                }
            }
            else
            {
                /* empty */
            }
            break;
        default:
            /* empty */
            break;
        }
    }
    else
    {
        /*empty */
    }
}

/********************************************************************************/
/****
 * brief            :CanTp_TxConfirmation
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CanTp_pduId:ID of the PDU that has been transmitted.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
void CanTp_TxConfirmation(const PduIdType CanTp_pduId) 
{
    uint8 iloop;
    uint8 CanTp_listIndex = (uint8)CANTP_INVALID_INDEX;
    /* find tp index from tx channel */
    CanTp_RunTime_Type* CanTp_runtimeItem = &CanTp_Runtime;

    for (iloop = (uint8)0U; iloop < (uint8)CANTP_TX_CHANNEL_NUM; iloop++)/*PRQA S 2877*/
    {
        /* search tp index */
        if ((CanTp_TxSdu[iloop].txPduId == CanTp_pduId)
            && ((CANTP_SEND_SF_CONFIRMATION == CanTp_runtimeItem->tx_RunTime.tpState)
                || (CANTP_WAITING_FOR_FF_TX_CONFIRMATION == CanTp_runtimeItem->tx_RunTime.tpState)
                || (CANTP_WAITING_FOR_CF_TX_CONFIRMATION == CanTp_runtimeItem->tx_RunTime.tpState)
                || (CANTP_WAITING_FOR_LAST_CF_TX_CONFIRMATION == CanTp_runtimeItem->tx_RunTime.tpState)
                || (CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION == CanTp_runtimeItem->tx_RunTime.tpState)))
        {
            CanTp_listIndex = iloop;
            break;
        }
    }
    if ((uint8)CANTP_INVALID_INDEX != CanTp_listIndex)
    {
        /* tx:SF, CF or FF confirmation, tx channel */
        switch (CanTp_runtimeItem->tx_RunTime.tpState)
        {
        case CANTP_SEND_SF_CONFIRMATION:
        case CANTP_WAITING_FOR_LAST_CF_TX_CONFIRMATION:
            /* transmit ok */
            /* set the cantp state to idle */
            PduR_TxConfirmation(CanTp_TxSdu[CanTp_listIndex].txDcmId, (NotifResultType)NTFRSLT_OK);
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
            CanTp_Init();
#else
            CanTp_Init15765Runtime_TxData(&CanTp_runtimeItem->tx_RunTime);
#endif
            break;
        case CANTP_WAITING_FOR_FF_TX_CONFIRMATION:
        case CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION:
            /* wait flow control frame */
            CanTp_runtimeItem->tx_RunTime.tpState = CANTP_WAIT_FC;
            CanTp_runtimeItem->tx_RunTime.timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_BS));
            break;
        case CANTP_WAITING_FOR_CF_TX_CONFIRMATION:
            /* set the min time to send CF*/
            CanTp_runtimeItem->tx_RunTime.MinTime2SendCF = CanTp_runtimeItem->tx_RunTime.stmin;
            CanTp_runtimeItem->tx_RunTime.timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_CS));
            CanTp_runtimeItem->tx_RunTime.tpState = CANTP_SEND_CF;
            break;
        default:
            /* empty */
            break;
        }
    }
    else
    {
        /* TX: FC, rx channel */
        /* find tp index from rx channel, the FC confirmation */
        CanTp_listIndex = CanTp_FindTpTxConfirmIndexFromRxChannel(CanTp_pduId);
        if ((uint8)CANTP_INVALID_INDEX != CanTp_listIndex)
        {
            if (CANTP_SEND_FC_CTS_CONFIRMATION == CanTp_runtimeItem->rx_RunTime.tpRxState)
            {
                /* FC confirmation */
                CanTp_runtimeItem->rx_RunTime.tpRxState = CANTP_WAIT_CF;
                CanTp_runtimeItem->rx_RunTime.timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_CR));
            }
            else if (CANTP_SEND_FC_OVFLW_CONFIRMATION == CanTp_runtimeItem->rx_RunTime.tpRxState)
            {
                /* wrong state */
                PduR_RxIndication((PduIdType)CanTp_RxSdu[CanTp_listIndex].rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
                CanTp_Init();
#else
                CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
            }
            /* todo  add the another FC handle */
            else
            {
                /* wrong state */
                PduR_RxIndication((PduIdType)CanTp_RxSdu[CanTp_listIndex].rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
                CanTp_Init();
#else
                CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
            }
        }
    }

    return;
}

/********************************************************************************/
/****
 * brief            : CanTp_Transmit
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CanTp_txSduId:Identifier of the PDU to be transmitted.
 * 					   CanTp_txInfoPtr: Length of and pointer to the PDU data and pointer to Meta
 *										Data.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <Std_ReturnType:
 * 						E_OK: Transmit request has been accepted.
 *						E_NOT_OK: Transmit request has not been accepted.>
 */
/********************************************************************************/
Std_ReturnType CanTp_Transmit(const PduIdType CanTp_txSduId, const PduInfoType* CanTp_txInfoPtr) 
{
    uint8 iloop;
    /* point to the message transmitted */
    CanTp_RunTime_TxDataType* CanTp_txRuntime;

    /* find tp list index from SduId which should be send */
    uint8 index = (uint8)CANTP_INVALID_INDEX;

    for (iloop = (uint8)0U; iloop < (uint8)CANTP_TX_CHANNEL_NUM; iloop++) /*PRQA S 2877*/
    {
        if (CanTp_txSduId == CanTp_TxSdu[iloop].txDcmId)
        {
            index = iloop;
            break;
        }
    }
    if ((uint8)CANTP_INVALID_INDEX != index)
    {
        if (CANTP_IDLE == CanTp_Runtime.tx_RunTime.tpState)
        {
            CanTp_txRuntime = &CanTp_Runtime.tx_RunTime;
            /* the TP state is IDLE state, and then change the trans state to prepare sent */
            CanTp_txRuntime->transferTotal = CanTp_txInfoPtr->SduLength;

            CanTp_txRuntime->txDcmId = CanTp_txSduId;

            /* change state to send SF or FF state */
            CanTp_txRuntime->tpState = CANTP_SEND_SF_FF;

            /* immediate send FF or SF */
            CanTp_txRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(0u));

            CanTp_txRuntime->MinTime2SendCF = (uint8)1u;

            CanTp_Runtime.rx_RunTime.tpRxState = CANTP_IDLE;
        }
    }
    return (uint8)E_OK;
}

/********************************************************************************/
/****
 * brief            :The main function for scheduling the CAN TP.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <NONE>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
void CanTp_MainFunction(void)
{
    boolean processContinue;

    CanTp_RunTime_Type* CanTp_runtimeItem = &CanTp_Runtime;

    /* notification DCM if delay of DCM is processing */
    if ((CANTP_IDLE == CanTp_runtimeItem->tx_RunTime.tpState)
        && (CANTP_RECEPTION_SUCCESS == CanTp_runtimeItem->rx_RunTime.tpRxState))
    {
        PduR_RxIndication((PduIdType)CanTp_runtimeItem->rx_RunTime.rxDcmId, (NotifResultType)NTFRSLT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
        CanTp_Init();
#else
        CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
    }
    /* process the FC frame of send or send timeout*/
    processContinue = CanTp_Send_FC_TimeOut_Check(CanTp_runtimeItem);

    /* if the FC frame of send or send timeout process false, then check the CF FF SF send  */
    if ((boolean)TRUE != processContinue)
    {
        processContinue = CanTp_Send_Check(CanTp_runtimeItem);
    }

    /* if the FC frame of send or send timeout process false, and the send any frame is false, then check the CF FF SF
     * send timeout  */
    if ((boolean)TRUE != processContinue)
    {
        (void)CanTp_Send_TimeOut_Check(CanTp_runtimeItem);
    }
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/********************************************************************************/
/****
 * brief            :CanTp_Init15765Runtime_RxData
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <NONE>
 * param[out]       : <NONE>
 * param[in/out]    : <CanTp_runtime:cantp state machine data pointer.>
 * return           : <NONE>
 */
/********************************************************************************/
static void CanTp_Init15765Runtime_RxData(CanTp_RunTime_RxDataType* const CanTp_runtime)
{
    /* reset CF frame count  */
    CanTp_runtime->framesHandledCount = (uint8)0u;

    /* reset the timeout value for CANTP module */
    CanTp_runtime->timeoutCounterValue = (uint8)0U;

    /* clear the pdur buffer and count*/
    CanTp_runtime->pdurBuffer = NULL_PTR;

    CanTp_runtime->pdurBufferCount = (uint16)0U;

    /* clear the transfer total data count  */
    CanTp_runtime->transferTotal = (uint16)0U;
    /* clear the already transfer data count  */
    CanTp_runtime->transferCount = (uint16)0U;

    CanTp_runtime->canFrameBuffer.byteCount = (uint8)0u;

    CanTp_runtime->CanTp_ReceivedCFBlockSize = (uint8)0u;

    CanTp_runtime->rxDcmId = (PduIdType)0u;

    CanTp_runtime->txFcId = (PduIdType)0u;
    /* set rxState to IDLE*/
    CanTp_runtime->tpRxState = CANTP_IDLE;
}

/********************************************************************************/
/****
 * brief            : CanTp_Init15765Runtime_TxData
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <NONE>
 * param[out]       : <NONE>
 * param[in/out]    : <CanTp_runtime:cantp state machine data pointer.>
 * return           : <NONE>
 */
/********************************************************************************/
static void CanTp_Init15765Runtime_TxData(CanTp_RunTime_TxDataType* const CanTp_runtime)
{
    /* reset CF frame count  */
    CanTp_runtime->framesHandledCount = (uint8)0u;

    /* reset the timeout value for CANTP module */
    CanTp_runtime->timeoutCounterValue = (uint8)0U;

    /* clear the pdur buffer and count*/
    CanTp_runtime->pdurBuffer = NULL_PTR;

    CanTp_runtime->pdurBufferCount = (uint16)0U;

    /* clear the transfer total data count  */
    CanTp_runtime->transferTotal = (uint16)0U;
    /* clear the already transfer data count  */
    CanTp_runtime->transferCount = (uint16)0U;
    CanTp_runtime->canFrameBuffer.byteCount = (uint8)0u;

    CanTp_runtime->txDcmId = (PduIdType)0u;
    /* set rxState to IDLE*/
    CanTp_runtime->tpState = CANTP_IDLE;
    /* reset MinTime to Send CF  */
    CanTp_runtime->MinTime2SendCF = (uint8)0u;
    /* reset Wait flow control count. */
    CanTp_runtime->WTFCCounterValue = (uint8)0u;
}

#if (STD_ON == CANTP_FD_SUPPORT)
/********************************************************************************/
/****
 * brief            : Check SF and last CF.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <SF_DL:SF length.
 * 					   CAN_DL:CAN frame length.
 * 					   Offset:Valid frame data offset.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
static boolean CanTp_checkSF(PduLengthType SF_DL, PduLengthType CAN_DL, uint8 Offset)
{
    boolean retVal = (boolean)FALSE;
    switch (CAN_DL)
    {
    case 12U:
        if ((SF_DL >= (PduLengthType)(8u - (PduLengthType)Offset)) && (SF_DL <= (PduLengthType)(10u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 16U:
        if ((SF_DL >= (PduLengthType)(11u - (PduLengthType)Offset)) && (SF_DL <= (PduLengthType)(14u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 20U:
        if ((SF_DL >= (PduLengthType)(15u - (PduLengthType)Offset)) && (SF_DL <= (PduLengthType)(18u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 24U:
        if ((SF_DL >= (PduLengthType)(19u - (PduLengthType)Offset)) && (SF_DL <= (PduLengthType)(22u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 32U:
        if ((SF_DL >= (PduLengthType)(23u - (PduLengthType)Offset)) && (SF_DL <= (PduLengthType)(30u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 48U:
        if ((SF_DL >= (PduLengthType)(31u - (PduLengthType)Offset)) && (SF_DL <= (PduLengthType)(46u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 64U:
        if ((SF_DL >= (PduLengthType)(47u - (PduLengthType)Offset)) && (SF_DL <= (PduLengthType)(62u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    default:
        if (CAN_DL <= (PduLengthType)8u)
        {
            retVal = (boolean)TRUE;
        }
        break;
    }
    return retVal;
}

/********************************************************************************/
/****
 * brief            : Check last CF.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CF_DL:CF length.
 * 					   CAN_DL:CAN frame length.
 * 					   Offset:Valid frame data offset.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <boolean:check result>
 */
/********************************************************************************/
static boolean CanTp_checkLastCF(PduLengthType CF_DL, PduLengthType CAN_DL, uint8 Offset)
{
    boolean retVal = (boolean)FALSE;
    switch (CAN_DL)
    {
    case 12U:
        if ((CF_DL >= (PduLengthType)(8u - (PduLengthType)Offset)) && (CF_DL <= (PduLengthType)(11u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 16U:
        if ((CF_DL >= (PduLengthType)(12u - (PduLengthType)Offset)) && (CF_DL <= (PduLengthType)(15u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 20U:
        if ((CF_DL >= (PduLengthType)(16u - (PduLengthType)Offset)) && (CF_DL <= (PduLengthType)(19u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 24U:
        if ((CF_DL >= (PduLengthType)(20u - (PduLengthType)Offset)) && (CF_DL <= (PduLengthType)(23u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 32U:
        if ((CF_DL >= (PduLengthType)(24u - (PduLengthType)Offset)) && (CF_DL <= (PduLengthType)(31u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 48U:
        if ((CF_DL >= (PduLengthType)(32u - (PduLengthType)Offset)) && (CF_DL <= (PduLengthType)(47u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    case 64U:
        if ((CF_DL >= (48u - (PduLengthType)Offset)) && (CF_DL <= (63u - (PduLengthType)Offset)))
        {
            retVal = (boolean)TRUE;
        }
        break;
    default:
        if (CAN_DL <= (PduLengthType)8u)
        {
            retVal = (boolean)TRUE;
        }
        break;
    }
    return retVal;
}
#endif

/********************************************************************************/
/***
 * brief            : Find index from Rx channel.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CanTp_pduId:ID of the received PDU.
 * 						CanTp_objRxPtr:Length of and pointer to the PDU data and pointer to MetaData.>
 * param[out]       : <NONE>
 * param[in/out]    : <CanTp_pci : FrameType>
 *                     CanTp_pciOffset: PCI Position
 * return           : <NONE>
 */
/********************************************************************************/
static uint8 CanTp_FindIndexFromRxChannel(
    PduIdType CanTp_pduId,
    const PduInfoType* CanTp_objRxPtr,
    uint8* const CanTp_pci,
    uint8* const CanTp_pciOffset)
{
    uint8 iloop;
    uint8 index = (uint8)CANTP_INVALID_INDEX;
    boolean processContinue = TRUE;

    /* check it rx pdu id in CanTp_RxSdu */
    for (iloop = (uint8)0u; (iloop < (uint8)CANTP_RX_CHANNEL_NUM) && (processContinue == TRUE); iloop++)
    {
        /* check is this channel */
        if (CanTp_RxSdu[iloop].rxPduId == CanTp_pduId)
        {
            if (CANTP_STANDARD == CanTp_RxSdu[iloop].addressingFormat)
            {
                *CanTp_pciOffset = (uint8)0u;
                *CanTp_pci = CanTp_objRxPtr->SduDataPtr[*CanTp_pciOffset];
                if((*CanTp_pci & (uint8)CANTP_PCI_MASK) != CANTP_PCI_FC )
                {
                    index = iloop;
                    processContinue = FALSE;
                }
            }
            else if (
                (CANTP_EXTENDED == CanTp_RxSdu[iloop].addressingFormat)
                && (CanTp_RxSdu[iloop].nSa == CanTp_objRxPtr->SduDataPtr[0u]))
            {
                *CanTp_pciOffset = (uint8)1u;
                *CanTp_pci = CanTp_objRxPtr->SduDataPtr[*CanTp_pciOffset];
                if((*CanTp_pci & (uint8)CANTP_PCI_MASK) != CANTP_PCI_FC )
                {
                    index = iloop;
                    processContinue = FALSE;
                }
            }
            else
            {
                /* empty */
            }
        }
    }

    /* if not in the CanTp_RxSdu,  check it rx-pdu id in CanTp_TxSdu, --rxFcPduId */
    if ((((uint8)CANTP_INVALID_INDEX != index) && ((*CanTp_pci & (uint8)CANTP_PCI_MASK) == CANTP_PCI_FC ))
    ||((uint8)CANTP_INVALID_INDEX == index))
    {
        if(index != CANTP_INVALID_INDEX)
        {
            index = CANTP_INVALID_INDEX;
        }
        processContinue = TRUE;
        for (iloop = (uint8)0U; (iloop < (uint8)CANTP_TX_CHANNEL_NUM) && (processContinue == TRUE); iloop++)/*PRQA S 2877*/
        {
            /* check it is the receiver channel pdu-id */
            if (CanTp_pduId == CanTp_TxSdu[iloop].rxFcPduId)
            {
                if (CANTP_STANDARD == CanTp_TxSdu[iloop].addressingFormat)
                {
                    *CanTp_pciOffset = (uint8)0u;
                    *CanTp_pci = CanTp_objRxPtr->SduDataPtr[*CanTp_pciOffset];
                    if((*CanTp_pci & (uint8)CANTP_PCI_MASK) == CANTP_PCI_FC )
                    {
                        index = iloop;
                        processContinue = FALSE;/*PRQA S 2983*/
                    }
                }
                else if (
                    (CANTP_EXTENDED == CanTp_TxSdu[iloop].addressingFormat)
                    && (CanTp_TxSdu[iloop].nTa == CanTp_objRxPtr->SduDataPtr[0u]))
                {
                    *CanTp_pciOffset = (uint8)1u;
                    *CanTp_pci = CanTp_objRxPtr->SduDataPtr[*CanTp_pciOffset];
                    if((*CanTp_pci & (uint8)CANTP_PCI_MASK) == CANTP_PCI_FC )
                    {
                        index = iloop;
                        processContinue = FALSE;/*PRQA S 2983*/
                    }
                }
                else
                {
                    /* empty */
                }
            }
        }
    }
    return index;
}

/********************************************************************************/
/****
 * @brief           : Frame padding check.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_objRxPtr:Length of and pointer to the PDU data and pointer to MetaData.
 * 						CanTp_checkDataOffset:Check data offset.
 * 						PduLength:Pdu length.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <boolean:Check result.>
 */
/********************************************************************************/
#if (CANTP_RX_PADDING_CHECK == STD_ON)
static boolean CanTp_FramePaddingCheck(
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_checkDataOffset,
    const PduLengthType PduLength)
{
    uint8 iloop;
    boolean checkOk = (boolean)TRUE;

    /* receive sdu length must be 8 or FDDL*/
    if (PduLength == CanTp_objRxPtr->SduLength)
    {
#if (CANTP_RX_PADDING_VAL_CHECK == STD_ON)
        /* the offset of data end */
        for (iloop = CanTp_checkDataOffset; iloop < PduLength; iloop++)
        {
            if ((uint8)RX_CANTP_PADDING_VALUE != CanTp_objRxPtr->SduDataPtr[iloop])
            {
                /* check error */
                checkOk = (boolean)FALSE;
                break;
            }
        }
#else
        (void)CanTp_checkDataOffset;
#endif
    }
    else
    {
        checkOk = (boolean)FALSE;
    }
    return checkOk;
}
#endif

/********************************************************************************/
/****
 * @brief           : Receive single frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <canTpRunTime:Cantp state machine data pointer.
 * 					   CanTp_rxConfig:Receive configuration pointer.
 * 					   CanTp_objRxPtr:Length of and pointer to the PDU data and pointer to MetaData.
 * 					   CanTp_dataLength:Data length.
 * 					   CanTp_pciOffset:pci offset.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_ReceiveSingleFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_RxSduType* const CanTp_rxConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_dataLength,
    const uint8 CanTp_pciOffset)
{
    uint8 iloop;
    uint8 dataOffset = CanTp_pciOffset + (uint8)1u;
    CanTp_RunTime_RxDataType* CanTp_rxRuntime = &(canTpRunTime->rx_RunTime);

    const CanTp_RunTime_TxDataType * CanTp_txRuntime = &(canTpRunTime->tx_RunTime);

#if (CANTP_RX_PADDING_CHECK == STD_ON)
    boolean paddingCheckOk;
    /* padding check */
    paddingCheckOk = CanTp_FramePaddingCheck(
        CanTp_objRxPtr,
        (CanTp_dataLength + dataOffset),
#if (STD_ON == CANTP_FD_SUPPORT)
        CanTp_MatchDLC(CanTp_objRxPtr->SduLength)
#else
        CANTP_DRV_PDU_MAX_LENGTH
#endif
    );
    if ((boolean)TRUE == paddingCheckOk)
#endif
    {
        /* if get 02 3e 80 by function address */
        if (((uint8)0x02u == CanTp_dataLength) && ((uint8)0x3Eu == CanTp_objRxPtr->SduDataPtr[dataOffset])
            && (0x80u == CanTp_objRxPtr->SduDataPtr[dataOffset + 1u])
            && ((uint16)RX_FUNCTIONAL_ADDRESSING == CanTp_rxConfig->rxPduType))
        {
            /* refresh S3 timer */
            PduR_StartP3cTimer();
        }
        else
        {

#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
			if(
				!(
					(CanTp_txRuntime->tpState ==CANTP_SEND_SF_FF)
					||(CanTp_txRuntime->tpState == CANTP_WAIT_FC)
					|| (CanTp_txRuntime->tpState == CANTP_SEND_CF)
					|| (CanTp_txRuntime->tpState == CANTP_SEND_SF_CONFIRMATION)
					|| (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_FF_TX_CONFIRMATION)
					|| (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION)
					|| (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_TX_CONFIRMATION)
				)
			)
#else
			if(
				(CanTp_txRuntime->tpState ==CANTP_SEND_SF_FF)
				||(CanTp_txRuntime->tpState == CANTP_WAIT_FC)
				|| (CanTp_txRuntime->tpState == CANTP_SEND_CF)
				|| (CanTp_txRuntime->tpState == CANTP_SEND_SF_CONFIRMATION)
				|| (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_FF_TX_CONFIRMATION)
				|| (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION)
				|| (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_TX_CONFIRMATION)
			)
			{
				CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
				/* wrong state */
				PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, NTFRSLT_E_NOT_OK);
			}
#endif
			{

			switch (CanTp_rxRuntime->tpRxState)
			{
				/* if sf reception in idle or waitCF state*/
				case CANTP_IDLE:
				case CANTP_WAIT_CF:
                case CANTP_SEND_FC_CTS_CONFIRMATION:
				/* if sf reception in wait cf/send fc/send fc cts confirmation: state, discard the received data
				 * cancel the dcm data */
				if((CANTP_WAIT_CF == CanTp_rxRuntime->tpRxState) || (CanTp_rxRuntime->tpRxState == CANTP_SEND_FC_CTS_CONFIRMATION))
				{
					PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_E_CANCELATION_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
					CanTp_Init();
#else
					CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
				}
				/* the CanTp_Length is the length of N_DATA, N-AI N_PCI N_DATA */
				for (iloop = (uint8)0u; iloop < CanTp_dataLength; iloop++)
				{
					/* copy data to local buffer */
					CanTp_rxRuntime->canFrameBuffer.data[iloop] = CanTp_objRxPtr->SduDataPtr[dataOffset + iloop];
				}
				/* set the SF length */
				CanTp_rxRuntime->canFrameBuffer.byteCount = CanTp_dataLength;
				/* set the total RX data, in SF Frame, is the same of canFrameBuffer.byteCount */
				CanTp_rxRuntime->transferTotal = (uint16)CanTp_dataLength;
				/* wait single frame buffer */
				CanTp_WaitSForLastCFBufProcess(CanTp_rxConfig, canTpRunTime);
				break;
			case CANTP_SEND_FC:
				/* not idle state, reset state */
				PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
				CanTp_Init();
#else
				CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
				break;
			default:
				/* empty */
				break;
			}

            }

        }
    }
}

/********************************************************************************/
/****
 * @brief           :CanTp_ReceiveFirstFrame
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <canTpRunTime:Cantp state machine data pointer.
 * 					   CanTp_rxConfig:Receive configuration pointer.
 * 					   CanTp_objRxPtr:Length of and pointer to the PDU data and pointer to MetaData.
 * 					   pduLength:Pdu length.
 * 					   Offset:Valid frame data offset.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_ReceiveFirstFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_RxSduType* const CanTp_rxConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const PduLengthType pduLength,
    const uint8 Offset)
{
    uint8 iloop;
    CanTp_RunTime_RxDataType* const CanTp_rxRuntime = &(canTpRunTime->rx_RunTime);
    
    const CanTp_RunTime_TxDataType * CanTp_txRuntime = &(canTpRunTime->tx_RunTime);
    BufReq_ReturnType Can_ret;

#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
    if(
        !(
            (CanTp_txRuntime->tpState ==CANTP_SEND_SF_FF)
            ||(CanTp_txRuntime->tpState == CANTP_WAIT_FC)
            || (CanTp_txRuntime->tpState == CANTP_SEND_CF)
            || (CanTp_txRuntime->tpState == CANTP_SEND_SF_CONFIRMATION)
            || (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_FF_TX_CONFIRMATION)
            || (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION)
            || (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_TX_CONFIRMATION)
        )
    )
#else
    if(
        (CanTp_txRuntime->tpState ==CANTP_SEND_SF_FF)
        ||(CanTp_txRuntime->tpState == CANTP_WAIT_FC)
        || (CanTp_txRuntime->tpState == CANTP_SEND_CF)
        || (CanTp_txRuntime->tpState == CANTP_SEND_SF_CONFIRMATION)
        || (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_FF_TX_CONFIRMATION)
        || (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION)
        || (CanTp_txRuntime->tpState ==CANTP_WAITING_FOR_CF_TX_CONFIRMATION)
    )
    {
        CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
        /* wrong state */
        PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, NTFRSLT_E_NOT_OK);
    }
#endif
{
    switch (CanTp_rxRuntime->tpRxState)
    {
    /* if sf reception in idle or waitCF state*/
    case CANTP_IDLE:
    case CANTP_WAIT_CF:
    case CANTP_SEND_FC_CTS_CONFIRMATION:
        /* if FF reception in wait cf state, discard the received data
         * init the rx runtime data */
        if ((CANTP_WAIT_CF == CanTp_rxRuntime->tpRxState) || (CanTp_rxRuntime->tpRxState == CANTP_SEND_FC_CTS_CONFIRMATION))
        {
            PduR_RxIndication((PduIdType)(CanTp_rxConfig->rxDcmId), (NotifResultType)NTFRSLT_E_CANCELATION_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
            CanTp_Init();
#else
            CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
        }
        /* byteCnt is the max frame byte count*/
        CanTp_rxRuntime->canFrameBuffer.byteCount = (uint8)CanTp_objRxPtr->SduLength - Offset;
        for (iloop = (uint8)0u; iloop < CanTp_rxRuntime->canFrameBuffer.byteCount; iloop++)
        {
            /* copy data to local buffer */
            /* byteCnt is the max frame byte count*/
            CanTp_rxRuntime->canFrameBuffer.data[iloop] = CanTp_objRxPtr->SduDataPtr[Offset + iloop];
        }
        /* transferTotal is the total length of transfer data */
        CanTp_rxRuntime->transferTotal = pduLength;

        /* FF frame set the frames count to 1, because the first sn of CF handle should be 1. */
        CanTp_rxRuntime->framesHandledCount = (uint8)1u;
        /*store FF FD SduLength*/
        CanTp_rxRuntime->FDDL = CanTp_objRxPtr->SduLength;
        /** N_Br timeout for receive FF than to send FC frame */
        CanTp_rxRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_BR));
		
		 CanTp_rxRuntime->txFcId = CanTp_rxConfig->txFcPduId;

        Can_ret = CanTp_WaitCFBufProcess(CanTp_rxConfig, canTpRunTime);
		
		/* send FC_CTS */
        if(CanTp_rxRuntime->tpRxState != CANTP_SEND_FC_CTS_CONFIRMATION)
        {
		    CanTp_SendFlowControlFrame(CanTp_rxConfig, canTpRunTime, Can_ret);
        }

        break;
    case CANTP_SEND_FC:
        /* not idle state, reset state */
        PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
        CanTp_Init();
#else
        CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
        break;
    default:
        /* empty */
        break;
    }
}
}

/********************************************************************************/
/****
 * @brief           : Receive consecutive frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <canTpRunTime:cantp state machine data pointer.
 * 					   CanTp_rxConfig:Receive configuration pointer.
 * 					   CanTp_objRxPtr:Length of and pointer to the PDU data and pointer to MetaData.
 * 					   CanTp_pciOffset:pci offset.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_ReceiveConsecutiveFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_RxSduType* const CanTp_rxConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_pciOffset)
{
    uint8 iloop;
    boolean lastCF = (boolean)FALSE;
    uint8 dataCount;
    CanTp_RunTime_RxDataType* const CanTp_rxRuntime = &(canTpRunTime->rx_RunTime);

    PduLengthType const bytesLeftToCopy = CanTp_rxRuntime->transferTotal - (PduLengthType)CanTp_rxRuntime->transferCount;
    uint8 const CanTp_sn = CanTp_objRxPtr->SduDataPtr[CanTp_pciOffset] & (uint8)CANTP_SEGMENT_NUMBER_MASK;

    boolean rocessContinue = (boolean)TRUE;

#if (CANTP_RX_PADDING_CHECK == STD_ON)
    boolean paddingCheckOk = (boolean)TRUE;
#endif

    if (CanTp_objRxPtr->SduLength < CanTp_rxRuntime->FDDL)
    {
        if (CanTp_objRxPtr->SduLength < (uint16)(bytesLeftToCopy + 1u))
        {
            rocessContinue = (boolean)FALSE;
        }
    }
    if ((boolean)TRUE == rocessContinue)
    {
        if (CanTp_sn != CanTp_rxRuntime->framesHandledCount)
        {
            PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_E_WRONG_SN);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
            CanTp_Init();
#else
            CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
        }
        else
        {
            CanTp_rxRuntime->framesHandledCount++;
            /* increase for sn */
            CanTp_rxRuntime->framesHandledCount &= (uint8)CANTP_SEGMENT_NUMBER_MASK;
            if (bytesLeftToCopy <= (uint16)(CanTp_rxRuntime->FDDL - 1u - (PduLengthType)CanTp_pciOffset))
            {
                /* last cf of this message */
                dataCount = (uint8)bytesLeftToCopy;
                lastCF = (boolean)TRUE;
            }
            else
            {
                /* depends on addressing CanTp_format used. */
                dataCount = (uint8)(CanTp_rxRuntime->FDDL - 1u - (PduLengthType)CanTp_pciOffset);
            }
#if (CANTP_RX_PADDING_CHECK == STD_ON)
            if ((boolean)TRUE == lastCF)
            {
                /* padding check */
                paddingCheckOk = CanTp_FramePaddingCheck(
                    CanTp_objRxPtr,
                    (uint8)(dataCount + CANTP_STD_ADDR_CF_DATA_OFFSET + CanTp_pciOffset),
#if (STD_ON == CANTP_FD_SUPPORT)
                    CanTp_MatchDLC(CanTp_objRxPtr->SduLength)
#else
                    (PduLengthType)CANTP_DRV_PDU_MAX_LENGTH
#endif
                );
            }
            if ((boolean)TRUE == paddingCheckOk)
#endif
            {
                /* copy data */
                for (iloop = (uint8)0U; iloop < dataCount; iloop++)
                {
                    /* copy to buffer */
                    CanTp_rxRuntime->pdurBuffer->SduDataPtr[CanTp_rxRuntime->pdurBufferCount] =
                        CanTp_objRxPtr->SduDataPtr[iloop + CanTp_pciOffset + (uint8)CANTP_STD_ADDR_CF_DATA_OFFSET];
                    CanTp_rxRuntime->pdurBufferCount++;
                }
                /* calc transfer counter */
                CanTp_rxRuntime->transferCount += (uint16)dataCount;
                CanTp_rxRuntime->CanTp_ReceivedCFBlockSize++;
                if ((boolean)TRUE == lastCF)
                {
#if (STD_ON == CANTP_FD_SUPPORT)
                    /*dataCount - 1u mean FD SF*/
                    if ((boolean)FALSE
                        == CanTp_checkLastCF((dataCount), CanTp_MatchDLC(CanTp_objRxPtr->SduLength), CanTp_pciOffset))
                    {
                        PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
                        CanTp_Init();
#else
                        CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
                    }
                    else
#endif
                    {
                        /* last CF, complete */
                        /* buffer ok */
                        CanTp_rxRuntime->tpRxState = CANTP_RECEPTION_SUCCESS;
                        CanTp_rxRuntime->rxDcmId = (PduIdType)CanTp_rxConfig->rxDcmId;
                        if (CANTP_IDLE == canTpRunTime->tx_RunTime.tpState)
                        {
                            PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
                            CanTp_Init();
#else
                            CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
                        }
                      
                    }
                }
                else
                {
                    if (CanTp_rxRuntime->FDDL != CanTp_objRxPtr->SduLength)
                    {
                        PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
                        CanTp_Init();
#else
                        CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
                    }
                    /* reset time counter */
                    CanTp_rxRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_CR));
                    /* if Block Size != 0 */
#if (0u != CANTP_Tx_FC_BS)
                    if (CanTp_rxRuntime->CanTp_ReceivedCFBlockSize >= (uint16)CANTP_Tx_FC_BS)
                    {
                        CanTp_rxRuntime->tpRxState = CANTP_SEND_FC;
                        CanTp_rxRuntime->CanTp_ReceivedCFBlockSize = (uint16)0u;
                        /** N_Br timeout for receive FF than to send FC frame */
                        CanTp_rxRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_BR));
                    }
#endif
                }
            }
        }
    }
}

/********************************************************************************/
/****
 * @brief           : Receive flow control frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <canTpRunTime:cantp state machine data pointer.
 * 					   CanTp_txConfig:Send configuration pointer.
 * 					   CanTp_objRxPtr:Length of and pointer to the PDU data and pointer to MetaData.
 * 					   CanTp_pciOffset:pci offset.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_ReceiveFlowControlFrame(
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_TxSduType* const CanTp_txConfig,
    const PduInfoType* const CanTp_objRxPtr,
    const uint8 CanTp_pciOffset)
{
    uint8 stminOffset = (uint8)(CANTP_STD_ADDR_FC_STMIN_OFFSET + CanTp_pciOffset);
    uint8 bsOffeset = (uint8)(CANTP_STD_ADDR_FC_BS_OFFSET + CanTp_pciOffset);

    CanTp_RunTime_TxDataType* const CanTp_txRuntime = &(canTpRunTime->tx_RunTime);

#if (STD_ON == CANTP_RX_PADDING_CHECK)
    boolean paddingCheckOk;
    /* padding check */
    paddingCheckOk = CanTp_FramePaddingCheck(CanTp_objRxPtr, stminOffset + 1U, CANTP_DRV_PDU_MAX_LENGTH);
    if ((boolean)TRUE == paddingCheckOk)
#endif
    {
        CanTp_txRuntime->bs = (uint16)CanTp_objRxPtr->SduDataPtr[bsOffeset];
        if ((uint16)0u == CanTp_txRuntime->bs)
        {
            CanTp_txRuntime->bs = (uint16)0xFFFFu;
        }
        if (((CanTp_objRxPtr->SduDataPtr[stminOffset] > (uint8)0x7FU)
             && (CanTp_objRxPtr->SduDataPtr[stminOffset] < (uint8)0xF1U))
            || (CanTp_objRxPtr->SduDataPtr[stminOffset] > (uint8)0xF9U))
        {
            /* if STmin is reserved value, treat STmin as the max value(0x7F - 127 ms) see chapter 6.5.5.6 ST error
             * handling */
            CanTp_txRuntime->stmin = (uint8)0x7FU;
        }
        else
        {
            /* get STmin value */
            /* if STmin is not 0-7f(1-127ms), set the STmin to 0. add 1 -> is for operate in CanTp_Mainfunction */
            if (CanTp_objRxPtr->SduDataPtr[stminOffset] > (uint8)0x7FU)
            {
                CanTp_txRuntime->stmin = (uint8)(0u + 1u);
            }
            else
            {
                CanTp_txRuntime->stmin =
                    (uint8)(CanTp_ConvertMsToMainCycles((uint8)CanTp_objRxPtr->SduDataPtr[stminOffset]) + 1u);
            }
        }
        /* set the min time to send CF*/
        CanTp_txRuntime->MinTime2SendCF = CanTp_txRuntime->stmin;
        /* clear time, send data immediately */
        CanTp_txRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_CS));
        CanTp_txRuntime->tpState = CANTP_SEND_CF;
    }
    (void)CanTp_txConfig;
}

/********************************************************************************/
/***
 * @brief           :CanTp_WaitSForLastCFBufProcess
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <NONE>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_WaitSForLastCFBufProcess(
    const CanTp_RxSduType* const CanTp_rxConfig,
    CanTp_RunTime_Type* const CanTp_RunTime)
{
    CanTp_RunTime_RxDataType* const CanTp_rxRunTimeItem = &(CanTp_RunTime->rx_RunTime);

    BufReq_ReturnType Can_ret = CanTp_CopySegmentToRxBuffer(CanTp_rxConfig, CanTp_rxRunTimeItem);

    if (BUFREQ_OK == Can_ret)
    {
        /* buffer ok */
        CanTp_rxRunTimeItem->tpRxState = CANTP_RECEPTION_SUCCESS;
        CanTp_rxRunTimeItem->rxDcmId = (PduIdType)CanTp_rxConfig->rxDcmId;
        if (CANTP_IDLE == CanTp_RunTime->tx_RunTime.tpState)
        {
            PduR_RxIndication((PduIdType)CanTp_rxConfig->rxDcmId, (NotifResultType)NTFRSLT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
            CanTp_Init();
#else
            CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
        }
    }
    else
    {
        /* if the buffer is not OK */
        /* init to idle state */
        /* fixme : those code is needed or not */
        PduR_RxIndication((PduIdType)CanTp_rxRunTimeItem->rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
        CanTp_Init();
#else
        CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
    }
}

/********************************************************************************/
/***
 * @brief           : Wait CF buffer process
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_rxConfig:CanTp_rxConfig:Receive configuration pointer.
 * 						CanTp_runtime:cantp state machine data pointer.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static BufReq_ReturnType CanTp_WaitCFBufProcess(const CanTp_RxSduType* const CanTp_rxConfig, CanTp_RunTime_Type* const CanTp_runtime)
{
    CanTp_RunTime_RxDataType* const CanTp_rxRuntime = &(CanTp_runtime->rx_RunTime);

    BufReq_ReturnType Can_ret = CanTp_CopySegmentToRxBuffer(CanTp_rxConfig, CanTp_rxRuntime);

    if (BUFREQ_OK == Can_ret)
    {
        CanTp_rxRuntime->tpRxState = CANTP_SEND_FC;
    }
    else if (BUFREQ_E_NOT_OK == Can_ret)
    {
        CanTp_Init15765Runtime_RxData(&CanTp_runtime->rx_RunTime);
    }
    else
    {
        /* send overflow status control */
        CanTp_rxRuntime->tpRxState = CANTP_SEND_FC_OVFLW;
    }

    return Can_ret;
}

/********************************************************************************/
/***
 * @brief           : Copy segment to rx buffer.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_rxConfig:CanTp_rxConfig:Receive configuration pointer.
 * 						CanTp_rxRuntime:cantp state machine data pointer.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <BufReq_ReturnType:Copy result.>
 */
/********************************************************************************/
static BufReq_ReturnType CanTp_CopySegmentToRxBuffer(
    const CanTp_RxSduType* const CanTp_rxConfig,
    CanTp_RunTime_RxDataType* const CanTp_rxRuntime)
{
    uint8 iloop;
    BufReq_ReturnType Can_ret = BUFREQ_E_NOT_OK;

	if (NULL_PTR == CanTp_rxRuntime->pdurBuffer)
	{
		/* buffer should be enough for message */
		Can_ret = PduR_ProvideRxBuffer(
			(PduIdType)CanTp_rxConfig->rxDcmId,
			CanTp_rxRuntime->transferTotal,
			&CanTp_rxRuntime->pdurBuffer);
	}
	if ((NULL_PTR != CanTp_rxRuntime->pdurBuffer)
		&& (CanTp_rxRuntime->pdurBuffer->SduLength > CanTp_rxRuntime->pdurBufferCount))
	{
		Can_ret = BUFREQ_OK;
		for (iloop = (uint8)0U; iloop < CanTp_rxRuntime->canFrameBuffer.byteCount; iloop++)
		{
			/* copy local buffer value to provided buffer from DCM */
			CanTp_rxRuntime->pdurBuffer->SduDataPtr[CanTp_rxRuntime->pdurBufferCount] =
				CanTp_rxRuntime->canFrameBuffer.data[iloop];
			CanTp_rxRuntime->transferCount++;
			CanTp_rxRuntime->pdurBufferCount++;
		}
	}

    return Can_ret;
}

/********************************************************************************/
/***
 * @brief           : calculate tx frame type.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txConfig:Send configuration pointer.
 * 						CanTp_txRuntime:cantp state machine data pointer.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <CanTp_Iso15765FrameType:frame type>
 */
/********************************************************************************/
static CanTp_Iso15765FrameType CanTp_calcTxFrameType(
    const CanTp_TxSduType* const CanTp_txConfig,
    const CanTp_RunTime_TxDataType* const CanTp_txRuntime)
{
    CanTp_Iso15765FrameType Can_ret;
    PduLengthType offest = (uint16)0U;
    if (CANTP_STANDARD == CanTp_txConfig->addressingFormat)
    {
        offest = (uint16)1U;
    }
    else if (CANTP_EXTENDED == CanTp_txConfig->addressingFormat)
    {
        offest = (uint16)2U;
    }
    else
    {
        /*idle*/
    }
    if (CanTp_txConfig->TxNPduDLC > (uint16)8u)
    {
        /*TX_DL > 8,CANTP_STANDARD FF_DLmin is TX_DL - 1*/
        /*TX_DL > 8,CANTP_EXTENDED FF_DLmin is TX_DL - 2*/
        if (CanTp_txRuntime->transferTotal >= (uint16)(CanTp_txConfig->TxNPduDLC - offest))
        {
            /* first frame */
            Can_ret = CANTP_FIRST_FRAME;
        }
        else
        {
            /* single frame */
            Can_ret = CANTP_SINGLE_FRAME;
        }
    }
    else
    {
        /*TX_DL = 8,CANTP_STANDARD FF_DLmin is TX_DL - 1*/
        /*TX_DL = 8,CANTP_EXTENDED FF_DLmin is TX_DL - 2*/
        if (CanTp_txRuntime->transferTotal >= (uint16)(9u - offest))
        {
            /* first frame */
            Can_ret = CANTP_FIRST_FRAME;
        }
        else
        {
            /* single frame */
            Can_ret = CANTP_SINGLE_FRAME;
        }
    }
    return Can_ret;
}

/********************************************************************************/
/***
 * @brief           : Send Frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txConfig:Send configuration pointer.
 * 						canTpRunTime:cantp state machine data pointer.
 * 						CanTp_framType:fram type.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_SendTxFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    const CanTp_Iso15765FrameType CanTp_framType)
{
#if (STD_OFF == CANTP_FD_SUPPORT)
    uint8 sduData[CANTP_DRV_PDU_MAX_LENGTH];
#else
    uint8 sduData[CANTP_DRV_FDPDU_MAX_LENGTH];
#endif
    PduInfoType CanTp_pduInfo;
    CanTp_pduInfo.SduLength = (uint16)0U;
    CanTp_pduInfo.SduDataPtr = sduData;
    if (CANTP_STANDARD == CanTp_txConfig->addressingFormat)
    {
        /*idle*/
    }
    else if (CANTP_EXTENDED == CanTp_txConfig->addressingFormat)
    {
        CanTp_pduInfo.SduDataPtr[CanTp_pduInfo.SduLength] = CanTp_txConfig->nTa;
        CanTp_pduInfo.SduLength++;
    }
    else
    {
        /*idle*/
    }
    switch (CanTp_framType)
    {
    case CANTP_SINGLE_FRAME:
        /* send single frame */
        CanTp_SendSingleFrame(CanTp_txConfig, canTpRunTime, &CanTp_pduInfo);
        break;
    case CANTP_FIRST_FRAME:
        /* send first frame */
        CanTp_SendFirstFrame(CanTp_txConfig, canTpRunTime, &CanTp_pduInfo);
        break;
    case CANTP_CONSECUTIVE_FRAME:
        /* send consecutive frame */
        CanTp_SendConsecutiveFrame(CanTp_txConfig, canTpRunTime, &CanTp_pduInfo);
        break;
    default:
        /* empty */
        break;
    }
}

/********************************************************************************/
/***
 * @brief           : Send single frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txConfig:Send configuration pointer.
 * 						canTpRunTime:cantp state machine data pointer.
 * 						CanTp_pduInfo:Length of and pointer to the PDU data and pointer to MetaData.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_SendSingleFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    PduInfoType* const CanTp_pduInfo)
{
    boolean framPrepare;
    PduLengthType offest = (uint16)0U;
    CanTp_RunTime_TxDataType* const CanTp_txRuntime = &(canTpRunTime->tx_RunTime);
    if (CANTP_STANDARD == CanTp_txConfig->addressingFormat)
    {
        offest = (uint16)0U;
    }
    else if (CANTP_EXTENDED == CanTp_txConfig->addressingFormat)
    {
        offest = (uint16)1U;
    }
    else
    {
        /*idle*/
    }
    if ((CanTp_txRuntime->transferTotal + offest) <= (uint16)7u)
    {
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)CanTp_txRuntime->transferTotal;
        CanTp_pduInfo->SduLength++;
    }
    else
    {
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)0U;
        CanTp_pduInfo->SduLength++;
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)CanTp_txRuntime->transferTotal;
        CanTp_pduInfo->SduLength++;
    }
    framPrepare = CanTp_CopyDataToMsgFromTxBuf(
        CanTp_txConfig,
        CanTp_txRuntime,
        CanTp_pduInfo,
        (uint8)CanTp_txRuntime->transferTotal);
    if ((boolean)TRUE == framPrepare)
    {
        /* load time of N_As */
        (void)CanIf_Transmit(CanTp_txConfig->txPduId, CanTp_pduInfo);
        /* TIME CANTP_N_AS is for any frame that send */
        CanTp_txRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_AS));
        CanTp_txRuntime->tpState = CANTP_SEND_SF_CONFIRMATION;
    }
    else
    {
        PduR_TxConfirmation(CanTp_txConfig->txDcmId, (NotifResultType)NTFRSLT_E_NO_BUFFER);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
        CanTp_Init();
#else
        CanTp_Init15765Runtime_TxData(&canTpRunTime->tx_RunTime);
#endif
    }
}

/********************************************************************************/
/***
 * @brief           : Send first frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txConfig:Send configuration pointer.
 * 						canTpRunTime:cantp state machine data pointer.
 * 						CanTp_pduInfo:Length of and pointer to the PDU data and pointer to MetaData.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_SendFirstFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    PduInfoType* const CanTp_pduInfo)
{
    boolean framPrepare;
    CanTp_RunTime_TxDataType* const CanTp_txRuntime = &(canTpRunTime->tx_RunTime);
    if ((uint16)4095u >= CanTp_txRuntime->transferTotal)
    {
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] =
            (uint8)CANTP_PCI_FF | (uint8)((CanTp_txRuntime->transferTotal & (uint16)0x0F00U) >> (uint8)8U);
        CanTp_pduInfo->SduLength++;
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)(CanTp_txRuntime->transferTotal & (uint16)0xFFu);
        CanTp_pduInfo->SduLength++;
    }
    else
    {
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)CANTP_PCI_FF;
        CanTp_pduInfo->SduLength++;
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)0U;
        CanTp_pduInfo->SduLength++;
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)0U;
        CanTp_pduInfo->SduLength++;
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)0U;
        CanTp_pduInfo->SduLength++;
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] =
            (uint8)((CanTp_txRuntime->transferTotal & (uint16)0x0F00U) >> (uint8)8U);
        CanTp_pduInfo->SduLength++;
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)(CanTp_txRuntime->transferTotal & (uint16)0xFFu);
        CanTp_pduInfo->SduLength++;
    }
    framPrepare = CanTp_CopyDataToMsgFromTxBuf(
        CanTp_txConfig,
        CanTp_txRuntime,
        CanTp_pduInfo,
        (uint8)(CanTp_txConfig->TxNPduDLC - CanTp_pduInfo->SduLength));
    if ((boolean)TRUE == framPrepare)
    {
        (void)CanIf_Transmit(CanTp_txConfig->txPduId, CanTp_pduInfo);
        /* + 1 is because the consecutive frame numbering begins with 1 and not */
        CanTp_txRuntime->framesHandledCount = (uint8)1U;
        CanTp_txRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_AS));
        CanTp_txRuntime->tpState = CANTP_WAITING_FOR_FF_TX_CONFIRMATION;
    }
    else
    {
        /* frame error */
        PduR_TxConfirmation(CanTp_txConfig->txDcmId, (NotifResultType)NTFRSLT_E_NO_BUFFER);
#if (CANTP_MODE_HALF_DUPLEX == STD_ON)
        CanTp_Init();
#else
        CanTp_Init15765Runtime_TxData(&canTpRunTime->tx_RunTime);
#endif
    }
}

/********************************************************************************/
/***
 * @brief           : Send consecutive frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txConfig:Send configuration pointer.
 * 						canTpRunTime:cantp state machine data pointer.
 * 						CanTp_pduInfo:Length of and pointer to the PDU data and pointer to MetaData.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_SendConsecutiveFrame(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    PduInfoType* const CanTp_pduInfo)
{
    uint8 cfActualPayload;
    boolean lastFrame = (boolean)FALSE;

    CanTp_RunTime_TxDataType* const CanTp_txRuntime = &(canTpRunTime->tx_RunTime);

    const PduLengthType txDataRemain = CanTp_txRuntime->transferTotal - (PduLengthType)CanTp_txRuntime->transferCount;

    CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)CANTP_PCI_CF + CanTp_txRuntime->framesHandledCount;
    CanTp_pduInfo->SduLength++;
    cfActualPayload = (uint8)(CanTp_txConfig->TxNPduDLC - CanTp_pduInfo->SduLength);
    /* Calculate number of valid bytes that reside in this CF */
    if (txDataRemain <= (uint16)cfActualPayload)
    {
        /* Last frame. */
        cfActualPayload = (uint8)(txDataRemain);
        lastFrame = (boolean)TRUE;
    }
    /* copy data to can message */
    (void)CanTp_CopyDataToMsgFromTxBuf(CanTp_txConfig, CanTp_txRuntime, CanTp_pduInfo, cfActualPayload);
    /* change tp state */
    if ((boolean)TRUE == lastFrame)
    {
        /* this is the last frame of this message */
        CanTp_txRuntime->tpState = CANTP_WAITING_FOR_LAST_CF_TX_CONFIRMATION;
    }
    else
    {
        if (CanTp_txRuntime->bs > (uint16)0u)
        {
            CanTp_txRuntime->bs--;
        }
        if (CanTp_txRuntime->bs > (uint16)0u)
        {
            /* for receiver side the block size is zero */
            CanTp_txRuntime->tpState = CANTP_WAITING_FOR_CF_TX_CONFIRMATION;
        }
        else
        {
            /* bs = 0u */
            CanTp_txRuntime->tpState = CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION;
        }
    }
    CanTp_txRuntime->framesHandledCount = (CanTp_txRuntime->framesHandledCount + 1u) & (uint8)CANTP_SEGMENT_NUMBER_MASK;
    CanTp_txRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_AS));
    /* send frame */
    (void)CanIf_Transmit(CanTp_txConfig->txPduId, CanTp_pduInfo);
}

/********************************************************************************/
/***
 * @brief           : Send flow control frame.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_rxConfig:Receive configuration pointer.
 * 					   canTpRunTime:cantp state machine data pointer.
 * 					   CanTp_flowStatus:flow status.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_SendFlowControlFrame(
    const CanTp_RxSduType* const CanTp_rxConfig,
    CanTp_RunTime_Type* const canTpRunTime,
    BufReq_ReturnType const CanTp_flowStatus)
{
    PduInfoType CanTp_pduInfo;
#if (STD_OFF == CANTP_FD_SUPPORT)
    uint8 sduData[CANTP_DRV_PDU_MAX_LENGTH];
#else
    uint8 sduData[CANTP_DRV_FDPDU_MAX_LENGTH];
#endif
    uint8 iloop;
    uint8 chIdx = 0u;
    CanTp_RunTime_RxDataType* const CanTp_rxRuntime = &(canTpRunTime->rx_RunTime);

    CanTp_pduInfo.SduDataPtr = sduData;
    CanTp_pduInfo.SduLength = (uint16)0u;
    for (iloop = (uint8)0u; iloop < (uint8)CANTP_TX_CHANNEL_NUM; iloop++) /*PRQA S 2877*/
    {
        if (CanTp_rxConfig->txFcPduId == CanTp_TxSdu[iloop].txPduId)
        {
            chIdx = iloop;
            break;
        }
    }
    if (CANTP_STANDARD == CanTp_rxConfig->addressingFormat)
    {
        /*idle*/
    }
    else if (CANTP_EXTENDED == CanTp_rxConfig->addressingFormat)
    {
        CanTp_pduInfo.SduDataPtr[CanTp_pduInfo.SduLength] = CanTp_TxSdu[chIdx].nTa;
        CanTp_pduInfo.SduLength++;
    }
    else
    {
        /*idle*/
    }
    if (BUFREQ_OK == CanTp_flowStatus)
    {
        /* add PCI, and STmin */
        CanTp_pduInfo.SduDataPtr[CanTp_pduInfo.SduLength] = (uint8)CANTP_PCI_FC | (uint8)CANTP_FC_STATUS_CTS;
        CanTp_pduInfo.SduLength++;
        CanTp_pduInfo.SduDataPtr[CanTp_pduInfo.SduLength] = (uint8)CANTP_Tx_FC_BS;
        CanTp_pduInfo.SduLength++;
        CanTp_pduInfo.SduDataPtr[CanTp_pduInfo.SduLength] = (uint8)CANTP_Tx_FC_STMIN;
        CanTp_pduInfo.SduLength++;
    }
    else
    {
        CanTp_pduInfo.SduDataPtr[CanTp_pduInfo.SduLength] = (uint8)CANTP_PCI_FC | (uint8)CANTP_FC_STATUS_OVFLW;
        CanTp_pduInfo.SduLength++;
    }
    /* add padding */
#if (STD_ON == CANTP_TX_PADDING_ON)
    CanTp_FrameAddPadding(&(CanTp_TxSdu[chIdx]),&CanTp_pduInfo);
#endif
#if (STD_ON == CANTP_FD_SUPPORT)
    CanTp_FDFrameAddPadding(&(CanTp_TxSdu[chIdx]), &CanTp_pduInfo, (uint16)8u);
#endif
    /* send frame */
    (void)CanIf_Transmit(CanTp_rxConfig->txFcPduId, &CanTp_pduInfo);
    /* maybe should for a tolerant value */
    CanTp_rxRuntime->timeoutCounterValue = (uint16)(CanTp_ConvertMsToMainCycles(CANTP_N_AR));
    if (BUFREQ_OK == CanTp_flowStatus)
    {
        CanTp_rxRuntime->tpRxState = CANTP_SEND_FC_CTS_CONFIRMATION;
    }
    else if (BUFREQ_E_OVFL == CanTp_flowStatus)
    {
        CanTp_rxRuntime->tpRxState = CANTP_SEND_FC_OVFLW_CONFIRMATION;
    }
    else
    {
        /* empty */
    }
}

/********************************************************************************/
/***
 * @brief           : Copy data to message from Tx buff.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txConfig:Send configuration pointer.
 * 						CanTp_txRuntime:cantp state machine data pointer.
 * 						CanTp_pduInfo:Length of and pointer to the PDU data and pointer to MetaData.
 * 						actualPayloadLength:actual payload length.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <boolean>
 */
/********************************************************************************/
static boolean CanTp_CopyDataToMsgFromTxBuf(
    const CanTp_TxSduType* const CanTp_txConfig,
    CanTp_RunTime_TxDataType* const CanTp_txRuntime,
    PduInfoType* const CanTp_pduInfo,
    const uint8 actualPayloadLength)
{
    uint8 iloop;
    boolean framPrepare = (boolean)FALSE;
    if (NULL_PTR == CanTp_txRuntime->pdurBuffer)
    {
        /* first get buffer */
        (void)PduR_ProvideTxBuffer(CanTp_txConfig->txDcmId, &CanTp_txRuntime->pdurBuffer);
    }
    if (NULL_PTR != CanTp_txRuntime->pdurBuffer)
    {
        /* buffer ok, copy data */
        for (iloop = (uint8)0U; iloop < actualPayloadLength; iloop++)
        {
            /* copy local buffer to provided buffer by DCM */
            CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] =
                CanTp_txRuntime->pdurBuffer->SduDataPtr[CanTp_txRuntime->pdurBufferCount];
            CanTp_txRuntime->transferCount++;
            CanTp_pduInfo->SduLength++;
            CanTp_txRuntime->pdurBufferCount++;
        }
        framPrepare = (boolean)TRUE;
    }
#if (STD_ON == CANTP_TX_PADDING_ON)
    CanTp_FrameAddPadding(CanTp_txConfig,CanTp_pduInfo);
#endif
#if (STD_ON == CANTP_FD_SUPPORT)
    CanTp_FDFrameAddPadding(CanTp_txConfig, CanTp_pduInfo, CanTp_pduInfo->SduLength);
#endif
    return framPrepare;
}

/********************************************************************************/
/****
 * @brief           :if less than TxNPduDLC, add padding to message
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txConfig:Send configuration pointer.
 * 						CanTp_pduInfo:Length of and pointer to the PDU data and pointer to MetaData.
 * 						SduLength:Sdu length.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
#if (CANTP_FD_SUPPORT == STD_ON)
static void CanTp_FDFrameAddPadding(
    const CanTp_TxSduType* const CanTp_txConfig,
    PduInfoType* const CanTp_pduInfo,
    const PduLengthType SduLength)
{
    PduLengthType TxDLC = CanTp_MatchDLC(SduLength);
    for (; CanTp_pduInfo->SduLength < TxDLC; CanTp_pduInfo->SduLength++)
    {
        /* add padding */
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)CanTp_txConfig->Padding;
    }
    (void)CanTp_txConfig;
}
#endif

#if (STD_ON == CANTP_TX_PADDING_ON)
/********************************************************************************/
/****
 * @brief           :if less than 8, add padding to message
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_pduInfo:Contains the length (SduLength) of the received PDU, a pointer to a
 * 						buffer (SduDataPtr) containing the PDU, and the MetaData related to this PDU.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static void CanTp_FrameAddPadding(
    const CanTp_TxSduType* const CanTp_txConfig,PduInfoType* const CanTp_pduInfo)
{
    for (; CanTp_pduInfo->SduLength < (uint16)CANTP_DRV_PDU_MAX_LENGTH; CanTp_pduInfo->SduLength++)
    {
        /* add padding */
        CanTp_pduInfo->SduDataPtr[CanTp_pduInfo->SduLength] = (uint8)(uint8)CanTp_txConfig->Padding;
    }
}
#endif

/********************************************************************************/
/***
 * @brief           :CanTp_FindTpTxConfirmIndexFromRxChannel
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <CanTp_txPduId:Identifier of the PDU to be transmitted.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <uint8:Search result.>
 */
/********************************************************************************/
static uint8 CanTp_FindTpTxConfirmIndexFromRxChannel(PduIdType const CanTp_txPduId)
{
    uint8 iloop;
    uint8 rx_Index = (uint8)CANTP_INVALID_INDEX;
    uint8 tx_Index = (uint8)CANTP_INVALID_INDEX;
    for (iloop = (uint8)0U; iloop < (uint8)CANTP_TX_CHANNEL_NUM; iloop++) /*PRQA S 2877*/
    {
        if (CanTp_txPduId == CanTp_TxSdu[iloop].txPduId)
        {
            tx_Index = iloop;
            break;
        }
    }
    if ((uint8)CANTP_INVALID_INDEX != tx_Index)
    {
        for (iloop = (uint8)0U; iloop < (uint8)CANTP_RX_CHANNEL_NUM; iloop++)
        {
            if ((CanTp_txPduId == CanTp_RxSdu[iloop].txFcPduId)
                && (CanTp_RxSdu[iloop].rxPduId == CanTp_TxSdu[tx_Index].rxFcPduId))
            {
                rx_Index = iloop;
                break;
            }
        }
    }
    return rx_Index;
}

/********************************************************************************/
/***
 * @brief           : if STIM is timeout,then send CF FRAME
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * @param[in]       : <canTpRunTime:cantp state machine data pointer.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <uint8:Check result.>
 */
/********************************************************************************/
static boolean CanTp_Send_Check(CanTp_RunTime_Type* const canTpRunTime)
{
    uint8 iloop;
    CanTp_Iso15765FrameType frameType;

    boolean processContinue = (boolean)FALSE;

    /* Decrement timeout counter, if not already zero. */
    if (canTpRunTime->tx_RunTime.MinTime2SendCF > (uint8)0u)
    {
        canTpRunTime->tx_RunTime.MinTime2SendCF--;
        /* wait for min-time to send CF timeout */
        if ((uint8)0u == canTpRunTime->tx_RunTime.MinTime2SendCF)
        {
            for (iloop = (uint8)0u; iloop < (uint8)CANTP_TX_CHANNEL_NUM; iloop++) /*PRQA S 2877*/
            {
                if (canTpRunTime->tx_RunTime.txDcmId == CanTp_TxSdu[iloop].txDcmId)
                {
                    processContinue = (boolean)TRUE;
                    break;
                }
            }
        }
    }
    /* if find the send dcmID */
    if ((boolean)TRUE == processContinue)
    {
        switch (canTpRunTime->tx_RunTime.tpState)
        {
        case CANTP_SEND_CF:
            /* send CF */
            CanTp_SendTxFrame(&CanTp_TxSdu[iloop], canTpRunTime, CANTP_CONSECUTIVE_FRAME);
            break;
        case CANTP_SEND_SF_FF:
            /* for calc frame type, SF or FF */
            /* calc the frame type which should be sent */
            frameType = CanTp_calcTxFrameType(&CanTp_TxSdu[iloop], &canTpRunTime->tx_RunTime);
            /* send frame SF or FF */
            CanTp_SendTxFrame(&CanTp_TxSdu[iloop], canTpRunTime, frameType);
            break;
        default:
            /* empty */
            break;
        }
    }
    return processContinue;
}

/********************************************************************************/
/***
 * @brief           : if send FC timeout,,then send FC FRAME
 *                    if timeout in the wait CF or CONFIRMATION state, then notify
 *                    the DCM not ok.
 * @param[in]       : <canTpRunTime:cantp state machine data pointer.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <uint8:Check result.>
 */
/********************************************************************************/
static boolean CanTp_Send_FC_TimeOut_Check(CanTp_RunTime_Type* const canTpRunTime)
{
    uint8 iloop;
    boolean processContinue = (boolean)FALSE;

    /* Decrement timeout counter, if not already zero. */
    if (canTpRunTime->rx_RunTime.timeoutCounterValue > (uint16)0u)
    {
        canTpRunTime->rx_RunTime.timeoutCounterValue--;
        /* wait for send or rx indication timeout */
        if ((uint16)0u == canTpRunTime->rx_RunTime.timeoutCounterValue)
        {
            for (iloop = (uint8)0u; iloop < (uint8)CANTP_RX_CHANNEL_NUM; iloop++)
            {
                if(CanTp_RxSdu[iloop].txFcPduId == canTpRunTime->rx_RunTime.txFcId)
                {
                    processContinue = (boolean)TRUE;
                    break;
                }
            }
        }
    }
    /* if timeout,and the rxpduID is RX_PHYSICAL_ADDRESSING */
    if ((boolean)TRUE == processContinue)
    {
        switch (canTpRunTime->rx_RunTime.tpRxState)
        {
        case CANTP_SEND_FC:
            /* send FC_CTS */
            CanTp_SendFlowControlFrame(&CanTp_RxSdu[iloop], canTpRunTime, BUFREQ_OK);
            break;
        case CANTP_SEND_FC_OVFLW:
            /* send FC_OVFLW */
            CanTp_SendFlowControlFrame(&CanTp_RxSdu[iloop], canTpRunTime, BUFREQ_E_OVFL);
            break;
        /* wait CFtimeout  */
        case CANTP_WAIT_CF:
        /* send FC timeout  */
        case CANTP_SEND_FC_CTS_CONFIRMATION:
        case CANTP_SEND_FC_OVFLW_CONFIRMATION:
            /* init to idle state */
            PduR_RxIndication((PduIdType)CanTp_RxSdu[iloop].rxDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
            CanTp_Init();
#else
            CanTp_Init15765Runtime_RxData(&CanTp_Runtime.rx_RunTime);
#endif
            break;
        default:
            /* empty */
            break;
        }
    }
    return processContinue;
}

/********************************************************************************/
/***
 * @brief           : if send any frame  timeout,,then send FC FRAME, then notify
 *                    the DCM handle is not OK.
 * @param[in]       : <canTpRunTime:cantp state machine data pointer.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <NONE>
 */
/********************************************************************************/
static boolean CanTp_Send_TimeOut_Check(CanTp_RunTime_Type* const canTpRunTime)
{
    uint8 iloop;
    boolean processContinue = (boolean)FALSE;

    if (canTpRunTime->tx_RunTime.timeoutCounterValue > (uint16)0u)
    {
        canTpRunTime->tx_RunTime.timeoutCounterValue--;
        if ((uint16)0u == canTpRunTime->tx_RunTime.timeoutCounterValue)
        {
            for (iloop = (uint8)0u; iloop < (uint8)CANTP_TX_CHANNEL_NUM; iloop++) /*PRQA S 2877*/
            {
                if (canTpRunTime->tx_RunTime.txDcmId == CanTp_TxSdu[iloop].txDcmId)
                {
                    processContinue = (boolean)TRUE;
                    break;
                }
            }
        }
    }
    /* if find the send dcmID */
    if ((boolean)TRUE == processContinue)
    {
        switch (canTpRunTime->tx_RunTime.tpState)
        {
            /*TODO: change by tao.yu,because N_Cs timeout not require in ISO 15765-2*/
#if 0
            case CANTP_SEND_CF:
            /* wait for flow control frame timeout  */
#endif
        case CANTP_WAIT_FC:
        /* first frame tx confirmation */
        case CANTP_WAITING_FOR_FF_TX_CONFIRMATION:
        /* last CF of this message */
        case CANTP_WAITING_FOR_LAST_CF_TX_CONFIRMATION:
        /* wait for CF tx confirmation */
        case CANTP_WAITING_FOR_CF_TX_CONFIRMATION:
        /* CF tx confirmation ,if confirmation then wait FC frame */
        case CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION:
            /* transmit data timeout */
            PduR_TxConfirmation(CanTp_TxSdu[iloop].txDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
            CanTp_Init();
#else
            CanTp_Init15765Runtime_TxData(&canTpRunTime->tx_RunTime);
#endif
            break;
        /* SF TX Confirmation timeout handle */
        case CANTP_SEND_SF_CONFIRMATION:
            /* transmit data timeout */
            PduR_TxConfirmation(CanTp_TxSdu[iloop].txDcmId, (NotifResultType)NTFRSLT_E_NOT_OK);
#if (STD_ON == CANTP_MODE_HALF_DUPLEX)
            CanTp_Init();
#else
            CanTp_Init15765Runtime_TxData(&canTpRunTime->tx_RunTime);
#endif
            /* initialize rx buffer status */
            PduR_Service_RxFinish();
            break;
        default:
            /* empty */
            break;
        }
    }
    return processContinue;
}

#if (STD_ON == CANTP_FD_SUPPORT)

/********************************************************************************/
/***
 * @brief           : match CanFd Data length.
 * @param[in]       : <frameDL:frame Data length.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <PduLengthType:Data length.>
 */
/********************************************************************************/
static PduLengthType CanTp_MatchDLC(PduLengthType frameDL)
{
    uint8 iloop;
    PduLengthType len = 8u;
    /* ISO 11898-1:2014 define the DLC table */
    const uint8 canDL[8] = {8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    for (iloop = (uint8)0U; iloop < (uint8)8u; iloop++)
    {
        if (frameDL <= canDL[iloop])
        {
            len = canDL[iloop];
            break;
        }
    }
    return len;
}
#endif
/********************************************************************************/
/***
 * @brief           : calc the cycle time .
 * @param[in]       : <x:Convert value.>
 * @param[out]      : <NONE>
 * @param[in/out]   : <NONE>
 * @return          : <uint32>
 */
/********************************************************************************/
static uint16 CanTp_ConvertMsToMainCycles(uint16 x)
{
    return (((x) + 1u) / CANTP_MAIN_TICK);
}
/* =======================[END OF FILE]===========================================*/
