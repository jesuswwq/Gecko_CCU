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
**  FILENAME    : XcpOnEth.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Transport Layer:XCP on Ethernet                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-02-12  qinchun.yang    Initial version.Distinguish between
 *                                              different transport layers
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 */
/*============================================================================*/
/*=======[I N C L U D E S]====================================================*/
#include "Xcp_Internal.h"

#if (XCP_ON_ETHERNET_ENABLE == STD_ON)
/*=======[E X T E R N A L   D A T A]==========================================*/
#define XCP_START_SEC_VAR_CLEARED_16
#include "Xcp_MemMap.h"
VAR(uint16, XCP_VAR) Xcp_EthRxCounter;
VAR(uint16, XCP_VAR) Xcp_EthTxCounter;
#define XCP_STOP_SEC_VAR_CLEARED_16
#include "Xcp_MemMap.h"

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE
#include "Xcp_MemMap.h"
/******************************************************************************/
/*
 * @brief               <Xcp callback Function>
 *
 * <Indication of a received PDU from a lower layer communication interface module.> .
 * Service ID   :       <(0x42)>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant for different PduIds. Non reentrant for the same PduId.>
 * @param[in]           <RxPduId>/<PduInfoPtr>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 */
/******************************************************************************/
FUNC(void, XCP_SOADIFRXINDICATION_CODE)
Xcp_SoAdRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, XCP_APPL_DATA) PduInfoPtr)
{
    uint16 counter = 0u;
    uint16 len = 0u;

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if ((boolean)TRUE != Xcp_RxIndCheckDetErr(RxPduId, PduInfoPtr))
#else
    XCP_AVOID_WARNNING(RxPduId);
#endif /* XCP_DEV_ERROR_DETECT == STD_ON */
    {
        Xcp_CopyU1BufferToU2(&(PduInfoPtr->SduDataPtr[2u]), &counter, LOW_BYTE_FIRST);
        /*XCP Header(Ethernet) length is 4 bytes
         * byte0/byte1:LEN:LEN is the number of bytes in the original XCP Packet
         * byte2/byte3:CTR:The CTR value in the XCP Header allows detection of missing Packets.
         * */
        if (counter != Xcp_EthRxCounter)
        {
            /*Missing packets detect*/
            /*TODO*/
        }
        Xcp_EthRxCounter = counter + 1u;
        Xcp_CopyU1BufferToU2(&(PduInfoPtr->SduDataPtr[0u]), &len, LOW_BYTE_FIRST);
        Xcp_RxIndication(len, &(PduInfoPtr->SduDataPtr[4u]));
    }
    return;
}
#define XCP_STOP_SEC_SOADIFRXINDICATION_CALLBACK_CODE
#include "Xcp_MemMap.h"

#define XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
#include "Xcp_MemMap.h"
/******************************************************************************/
/*
 * @brief               <Xcp callback Function>
 *
 * <The lower layer communication interface module confirms the transmission of a PDU, or the failure to transmit a PD.>
 * . Service ID   :       <(0x40)> Sync/Async   :       <Synchronous> Reentrancy           <Reentrant for different
 * PduIds. Non reentrant for the same PduId.>
 * @param[in]           <TxPduId>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 */
/******************************************************************************/
FUNC(void, XCP_SOADIFTXCONFIRMATION_CODE)
Xcp_SoAdTxConfirmation(PduIdType TxPduId)
{
#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if ((boolean)FALSE == Xcp_TxIndCheckDetErr())
#endif /* (XCP_DEV_ERROR_DETECT == STD_ON) */
    {
        Xcp_TxConfirmation(TxPduId);
    }
    return;
}
#define XCP_STOP_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
#include "Xcp_MemMap.h"
#endif /*XCP_ON_ETHERNET_ENABLE == STD_ON*/
