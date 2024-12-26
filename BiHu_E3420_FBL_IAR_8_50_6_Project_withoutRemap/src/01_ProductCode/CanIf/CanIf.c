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
**  FILENAME    : CanIf.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : The CAN Interface module provides a unique interface to     **
**  manage different CAN hardware device types like CAN Controllers used by   **
**  the definedECU hardware layout.                    						  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR_SWS_CANInterface R19-11	                  **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20130522      WBN             Initial version
 *  V1.0.1     20180511     CChen            update
 *  V1.0.2     20200310   Lianren.Wu         QAC-9.5.0 test
 *  V1.0.3     20200519   Lianren.Wu         add the empty function of call-back
 *                                           RxInd check.
 *  V1.0.4     20200610   Lianren.Wu         modify for QAC-9.5.0 test second.
 *  V1.0.5     20200710   Lianren.Wu         modify CanIf_RxIndication,Unrelated
 *                                           DCM code of 3e 80.
 *  V1.0.6     20231115   Long.Zhu    		 1.Adjust the logic and sort out the source code of can driver related interface.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "CanIf.h"
#include "DP.h"


/* ----------------projectCfg---------------- */

#include "Can.h"
#include "IoExp_TCA6424A_Api.h"
/* ----------------projectCfg end---------------- */
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* ----------------projectCfg---------------- */
#define MCAL_CAN_OBJ_TEST_TX CAN_HRH_TX_RESP
#define MCAL_CAN_OBJ_TEST_OTA CAN_HRH_TX_RESP_OTA
#define MCAL_CAN_CONTROL_0 CanConf_CanController_CANFD7
#define MCAL_CAN_CONTROL_1 CanConf_CanController_CANFD8
/* ----------------projectCfg end---------------- */
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
#if(CANIF_RX_FIFO_ENABLE == STD_ON)
#define RX_BUFFER_SIZE 			 0x200U

typedef struct {                   /*!< Message Buffer ID*/
	/* @type:NONE range:  */
#if(CANTP_FD_SUPPORT == STD_ON)
    uint8 data[64];                   /*!< Data bytes of the FlexCAN message*/
#else
    uint8 data[8];                   /*!< Data bytes of the FlexCAN message*/
#endif
    uint16 dataLen;                    /*!< Length of data in bytes */
} flexcan_msgbuff_t;

typedef struct {
	Can_HwType Mailbox;
	flexcan_msgbuff_t data;
} FifoType;

typedef struct {
    volatile uint32 writeIdx;
    volatile uint32 readIdx;
    volatile boolean full;
    volatile boolean lock;
    volatile FifoType fifo[RX_BUFFER_SIZE];
} FifoCtrl;
#endif
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if(CANIF_RX_FIFO_ENABLE == STD_ON)
static void CanIf_RxIndicationProcess(const Can_HwType * Mailbox,const PduInfoType * PduInfoPtr);
static void CanIf_FIFORxIndication(const Can_HwType * Mailbox,const PduInfoType * PduInfoPtr);
static void CanIf_RxFifoRead(void);
#endif
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if(CANIF_RX_FIFO_ENABLE == STD_ON)
static FifoCtrl rxFifoCtrl;
#endif
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
void CanIf_TestSendData(uint32 id,uint8 *data,uint8 len)
{
   (void)*data;
    Can_PduType Can_PduInfo1;
    uint8 Can_au8Sdu8bytes1[8U] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0x6, 0x6, 0x07U, 0x08};
    Can_PduInfo1.id = id;
    Can_PduInfo1.swPduHandle = 0u;
    Can_PduInfo1.length = 8u;
    Can_PduInfo1.sdu = Can_au8Sdu8bytes1;
    uint8 length = len;
    if(length>8u)
    {
        length =8u;
    }
    DP_Memcpy(Can_au8Sdu8bytes1,data,length);

    (void)Can_Write(MCAL_CAN_OBJ_TEST_TX, &Can_PduInfo1);
}
void CanIf_TestSend(uint32 id)
{
    Can_PduType Can_PduInfo1;
    uint8 Can_au8Sdu8bytes1[8U] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0x6, 0x6, 0x07U, 0x08};
    Can_PduInfo1.id = id;
    Can_PduInfo1.swPduHandle = 0u;
    Can_PduInfo1.length = 8u;
    Can_PduInfo1.sdu = Can_au8Sdu8bytes1;

    (void)Can_Write(MCAL_CAN_OBJ_TEST_TX, &Can_PduInfo1);
    
    Can_PduInfo1.id = id+1;
    (void)Can_Write(MCAL_CAN_OBJ_TEST_OTA, &Can_PduInfo1);
}
/******************************************************************************/
/*
 * Brief               <This service Initializes internal and external interfaces
 * 						of the CAN Interface for the further processing.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
void CanIf_Init(void)
{
/* ----------------projectCfg---------------- */
    Can_Init(&Can_Config);
    Set_TCA1043_To_Normal(TCA6424_CHIP_A);
    Can_SetControllerMode(MCAL_CAN_CONTROL_0, CAN_CS_STARTED);
    Can_SetControllerMode(MCAL_CAN_CONTROL_1, CAN_CS_STARTED);
    // extern void CanIf_TestSend(uint32 id)  ;
    //  CanIf_TestSend(0x666);
/* ----------------projectCfg end---------------- */

#if(CANIF_RX_FIFO_ENABLE == STD_ON)
    rxFifoCtrl.writeIdx = 0u;
    rxFifoCtrl.readIdx = 0u;
    rxFifoCtrl.full = FALSE;
    rxFifoCtrl.lock = FALSE;
#endif
}
/******************************************************************************/
/*
 * Brief               <This service Initializes internal and external interfaces
 * 						of the CAN Interface for the further processing.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
void CanIf_DeInit(void)
{
/* ----------------projectCfg---------------- */
    Can_SetControllerMode(MCAL_CAN_CONTROL_0, CAN_CS_STOPPED);
    Can_SetControllerMode(MCAL_CAN_CONTROL_1, CAN_CS_STOPPED);
/* ----------------projectCfg end---------------- */
}
/******************************************************************************/
/*
 * Brief               <Requests transmission of a PDU.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <PduId: Identifier of the PDU to be transmitted.
 * 					    *PduInfoPtr: Length of and pointer to the PDU data and pointer to MetaData.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType:E_OK: Transmit request has been accepted.
 *									   E_NOT_OK: Transmit request has not been accepted>
 */
/******************************************************************************/
Std_ReturnType CanIf_Transmit(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    /* loop counter */
    uint8 iloop;
    /* store transmit message */
    Can_PduType canPdu;
    /* return result */
    Std_ReturnType retVal = (uint8)E_OK;
    Std_ReturnType             canRes = E_NOT_OK; /* result of can write */
    /* point to canif transmit configuration */
    const CanIf_TxChannelType* pCh = CanIfTxCh;
    for (iloop = (uint8)0u; iloop < (uint8)CANIF_TX_CHANNEL_NUM; iloop++)/*PRQA S 2877*/
    {
        if (pCh[iloop].TpPduId == PduId)
        {
            canPdu.id = pCh[iloop].CanId;
            switch (pCh[iloop].TxcanIdMode)
            {
            case CANIF_TX_EXTENDED_CAN:
                canPdu.id |= 0x80000000U;
                break;
            case CANIF_TX_EXTENDED_FD_CAN:
                canPdu.id |= 0xc0000000U;
                break;
            case CANIF_TX_STANDARD_FD_CAN:
                canPdu.id |= 0x40000000U;
                break;
            default:
                /* CANIF_TX_STANDARD_CAN */
                break;
            }
            canPdu.length = (uint8)PduInfoPtr->SduLength;
            canPdu.sdu = PduInfoPtr->SduDataPtr;
            canPdu.swPduHandle = pCh[iloop].PduId;
/* ----------------projectCfg---------------- */
           canRes = (Std_ReturnType)Can_Write(pCh[iloop].ObjectId, &canPdu);
/* ----------------projectCfg end---------------- */
            break;
        }
    }
    if (canRes != E_OK)
    {
        retVal = (uint8)E_NOT_OK;
    }
    return retVal;
}

/******************************************************************************/
/*
 * Brief               <This service confirms a previously successfully processed transmission of a CAN TxPDU.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <CanTxPduId:L-PDU handle of CAN L-PDU successfully transmitted.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    /* loop counter */
    uint8 iloop;
    /* point to canif configuration */
    const CanIf_TxChannelType* pCh = CanIfTxCh;
    for (iloop = (uint8)0u; iloop < (uint8)CANIF_TX_CHANNEL_NUM; iloop++)/*PRQA S 2877*/
    {
        /* if PduId matches, call confirmation */
        if (pCh[iloop].PduId == CanTxPduId)
        {
            if (NULL_PTR != pCh[iloop].TxConf)
            {
                pCh[iloop].TxConf(pCh[iloop].TpPduId);
            }
            break;
        }
    }
}

/******************************************************************************/
/*
 * Brief               <GetPduHrh>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <pCh, CanId>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 */
/******************************************************************************/
static Std_ReturnType CanIf_GetPduHrh(const CanIf_RxChannelType* pCh, Can_IdType CanId)
{
    Std_ReturnType retVal = (uint8)E_NOT_OK;

    if ((pCh->CanId & pCh->Mask) == (CanId & pCh->Mask))
    {
        switch (pCh->RxcanIdMode)
        {
        case CANIF_RX_EXTENDED_CAN:
            if (CanId >= (Can_IdType)0x80000000U)
            {
                retVal = (uint8)E_OK;
            }
            break;
        case CANIF_RX_EXTENDED_FD_CAN:
            if (CanId >= (Can_IdType)0xc0000000U)
            {
                retVal = (uint8)E_OK;
            }
            break;
        case CANIF_RX_EXTENDED_NO_FD_CAN:
            if ((CanId >= (Can_IdType)0x80000000U) && (CanId < (Can_IdType)0xc0000000U))
            {
                retVal = (uint8)E_OK;
            }
            break;
        case CANIF_RX_STANDARD_CAN:
            if (CanId < (Can_IdType)0x80000000U)
            {
                retVal = (uint8)E_OK;
            }
            break;
        case CANIF_RX_STANDARD_FD_CAN:
            if ((CanId < (Can_IdType)0x80000000U) && (CanId >= (Can_IdType)0x00000400U))
            {
                retVal = (uint8)E_OK;
            }
            break;
        case CANIF_RX_STANDARD_NO_FD_CAN:
            if (CanId < (Can_IdType)0x40000000U)
            {
                retVal = (uint8)E_OK;
            }
            break;
        default:
            /*Nothing*/
            break;
        }
    }
    return retVal;
}

/******************************************************************************/
/*
 * Brief               CAN If Rx Indication
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <Hrh, CanId, CanDlc, *CanSduPtr>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
void CanIf_RxIndication(const Can_HwType * Mailbox,const PduInfoType * PduInfoPtr)
{
#if(CANIF_RX_FIFO_ENABLE == STD_ON)
    CanIf_FIFORxIndication(Mailbox,PduInfoPtr);
}
/******************************************************************************/
/*
 * @brief              [CanIf_RxIndicationProcess description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Mailbox                   description]
 *                     [PduInfoPtr                description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void CanIf_RxIndicationProcess(const Can_HwType * Mailbox,const PduInfoType * PduInfoPtr)
{
#endif
    const CanIf_RxChannelType *pCh = CanIfRxCh; /* point to can if rx configuration */
    uint8 iloop;                                /* loop counter */
    Std_ReturnType retVal;

    for (iloop = 0u; iloop < CANIF_RX_CHANNEL_NUM; iloop++)
    {
        retVal = CanIf_GetPduHrh(&(pCh[iloop]), Mailbox->CanId);
        if ((pCh[iloop].ObjectId == Mailbox->Hoh) && ((Std_ReturnType)E_OK == retVal))
        {
            /* call CanTp rx indication */
            if (NULL_PTR != pCh[iloop].RxInd)
            {
                pCh[iloop].RxInd(pCh[iloop].TpPduId, PduInfoPtr);
            }
            break;
        }
    }
}
#if(CANIF_RX_FIFO_ENABLE == STD_ON)
/******************************************************************************/
/*
 * Brief               CAN If Rx Indication
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <Hrh, CanId, CanDlc, *CanSduPtr>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
static void CanIf_FIFORxIndication(const Can_HwType * Mailbox,const PduInfoType * PduInfoPtr)
{
    volatile FifoType * fifo;
    if(rxFifoCtrl.lock == FALSE)
    {
        fifo = &(rxFifoCtrl.fifo[rxFifoCtrl.writeIdx]);
        fifo->Mailbox.CanId = Mailbox->CanId;
        fifo->Mailbox.Hoh = Mailbox->Hoh;
        fifo->Mailbox.ControllerId = Mailbox->ControllerId;
        fifo->data.dataLen = PduInfoPtr->SduLength;
        DP_Memcpy((uint8*)fifo->data.data,(const uint8 *)PduInfoPtr->SduDataPtr,PduInfoPtr->SduLength);/*PRQA S 0312*/
        if(TRUE == rxFifoCtrl.full)
        {
            rxFifoCtrl.writeIdx = (rxFifoCtrl.writeIdx + 1u) & (RX_BUFFER_SIZE-1u);
            rxFifoCtrl.readIdx = (rxFifoCtrl.readIdx + 1u) & (RX_BUFFER_SIZE-1u);
        }
        else
        {
            rxFifoCtrl.writeIdx = (rxFifoCtrl.writeIdx + 1u) & (RX_BUFFER_SIZE-1u);
            if(rxFifoCtrl.readIdx == rxFifoCtrl.writeIdx)/*PRQA S 0404*/
            {
                rxFifoCtrl.full = TRUE;
            }
        }
    }
}
/************************************************************************************/
/*
 * Brief                This function performs the rx fifo read options
 * ServiceId            <0x08>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            Up Layer
 */
/***********************************************************************************/
static void CanIf_RxFifoRead(void)
{
    Can_HwType MailboxFifo;
    PduInfoType PduInfoFifo;
    volatile FifoType * fifo;


    if((rxFifoCtrl.readIdx == rxFifoCtrl.writeIdx)&&(rxFifoCtrl.full != TRUE))
    {
        /*empty*/
    }
    else
    {
        fifo = &(rxFifoCtrl.fifo[rxFifoCtrl.readIdx]);
        if(rxFifoCtrl.full == TRUE)
        {
            rxFifoCtrl.lock = TRUE;
            rxFifoCtrl.full = FALSE;
        }
        MailboxFifo.CanId = fifo->Mailbox.CanId;
        MailboxFifo.Hoh = fifo->Mailbox.Hoh;
        MailboxFifo.ControllerId = fifo->Mailbox.ControllerId;
        PduInfoFifo.SduLength = (PduLengthType)fifo->data.dataLen;
        PduInfoFifo.SduDataPtr = (uint8*)fifo->data.data;/*PRQA S 0312*/

        CanIf_RxIndicationProcess(&MailboxFifo, &PduInfoFifo);
        rxFifoCtrl.readIdx = (rxFifoCtrl.readIdx + 1u) & (RX_BUFFER_SIZE-1u);
        if(rxFifoCtrl.lock == TRUE)
        {
            rxFifoCtrl.lock = FALSE;
        }
    }


}
#endif
/******************************************************************************/
/*
 * Brief               <CAN If Main Function>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
void CanIf_MainFunction(void)
{
/* ----------------projectCfg---------------- */
  
    Can_MainFunction_Write();
#if 1
    Can_MainFunction_Read();

    Can_MainFunction_Wakeup();

    Can_MainFunction_BusOff();
#endif    
#if(CANIF_RX_FIFO_ENABLE == STD_ON)
    CanIf_RxFifoRead();
#endif	
/* ----------------projectCfg end---------------- */
}
/******************************************************************************/
/*
 * @brief              [CanIf_ControllerBusOff description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [ControllerId           description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void CanIf_ControllerBusOff(uint8 ControllerId)
{
/* ----------------projectCfg---------------- */
    (void)Can_SetControllerMode(ControllerId, CAN_CS_STOPPED);
    Set_TCA1043_To_Normal(TCA6424_CHIP_A);
    (void)Can_SetControllerMode(ControllerId, CAN_CS_STARTED);
/* ----------------projectCfg end---------------- */
}
/******************************************************************************/
/*
 * @brief              [CanIf_ControllerModeIndication description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [ControllerId                   description]
 *                     [ControllerMode                 description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void CanIf_ControllerModeIndication( uint8 ControllerId,
                                     CanIf_ControllerModeType ControllerMode )
{
/* ----------------projectCfg---------------- */
/* ----------------projectCfg end---------------- */
}
