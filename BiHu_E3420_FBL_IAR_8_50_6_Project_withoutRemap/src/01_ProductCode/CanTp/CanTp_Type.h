
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
**  FILENAME    : CanTp_Type.h                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                             	      **
**  Vendor      :                                                             **
**  DESCRIPTION : TP (ISO 15765-2) source component                           **
**                                                                            **
**  SPECIFICATION(S) : ISO 15765-2	                                          **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230818    long.zhu	         Initial Version
 *  V1.0.1     20231116    Long.Zhu		    1.add wait flow control count.
 */

#ifndef CANTP_TYPE_H_
#define CANTP_TYPE_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "CanTp_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*=======[M A C R O S]========================================================*/
#define CANTP_SF_LEN_12_CANFD_STD (PduLengthType)10
#define CANTP_SF_LEN_16_CANFD_STD (PduLengthType)14
#define CANTP_SF_LEN_20_CANFD_STD (PduLengthType)18
#define CANTP_SF_LEN_24_CANFD_STD (PduLengthType)22
#define CANTP_SF_LEN_32_CANFD_STD (PduLengthType)30
#define CANTP_SF_LEN_48_CANFD_STD (PduLengthType)46
#define CANTP_SF_LEN_64_CANFD_STD (PduLengthType)62

/*=======[M A C R O S]========================================================*/
#define CANTP_FC_STATUS_CTS   0u
#define CANTP_FC_STATUS_WT    1u
#define CANTP_FC_STATUS_OVFLW 2u

/** Flow control status mask */
#define CANTP_PCI_FS_MASK 0x0FU

/** Single frame data length mask */
#define CANTP_PCI_DL              0x0FU

#define CANTP_SEGMENT_NUMBER_MASK 0x0fU

/** max data length of SF FF with standard address */
#define CANTP_STD_ADDR_MAX_SF_LEGNTH 7u
#define CANTP_STD_ADDR_MAX_FF_LENGTH 6u
/** max data length of CF with standard address */
#define CANTP_STD_ADDR_MAX_CF_LENGTH 7u

/** data offset of standard address */
#define CANTP_STD_ADDR_SF_DATA_OFFSET 1u
/** data offset of standard address */
#define CANTP_STD_ADDR_FF_DATA_OFFSET  2u
#define CANTP_STD_ADDR_CF_DATA_OFFSET  1u

#define CANTP_STD_ADDR_FC_BS_OFFSET    1u
#define CANTP_STD_ADDR_FC_STMIN_OFFSET 2u
#define CANTP_STD_ADDR_PCI_OFFSET      0u

/** max data length of SF FF with extended address */
#define CANTP_EXT_ADDR_MAX_SF_LEGNTH 6u
#define CANTP_EXT_ADDR_MAX_FF_LENGTH 5u

/** data offset of extended address */
#define CANTP_EXT_ADDR_SF_DATA_OFFSET 2u
#define CANTP_EXT_ADDR_FF_DATA_OFFSET 3u
#define CANTP_EXT_ADDR_PCI_OFFSET     1u

#define CANTP_DRV_PDU_MAX_LENGTH      8u
#define CANTP_DRV_FDPDU_MAX_LENGTH    64u

#define CANTP_INVALID_INDEX           0xFFU

#define CANTP_MAIN_TICK   GPT_PERIOD_TIME

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/**=======[T Y P E   D E F I N I T I O N S]===================================*/
typedef enum
{
    CANTP_EXTENDED,
    CANTP_STANDARD
} CanTp_Address_FormatType;

typedef enum
{
    CAN_20,
    CAN_FD
} CanTp_CanFrameType;

typedef struct
{
    /*       rxPduId               rxDcmId         */
    /* Can -------------> CanTp -------------> DCM */
    /*       txFcPduId                             */
    /*     <------------                           */
    const PduIdType rxDcmId;
    const PduIdType rxPduId;
    const CanTp_Address_FormatType addressingFormat;
    /* Network Source Address type */
    const uint8 nSa;
    const PduIdType txFcPduId;
    /*can20 or canfd*/
    const CanTp_CanFrameType CanFrameType;
    const PduLengthType RxNPduDLC;
    const PduIdType rxPduType;
} CanTp_RxSduType;

typedef struct
{
    /*         txPduId              txDcmId        */
    /* Can <------------- CanTp <------------- DCM */
    /*        rxFcPduId                            */
    /*      ------------>                          */
    const PduIdType txDcmId;
    const PduIdType txPduId;
    const PduIdType rxFcPduId;
    const CanTp_Address_FormatType addressingFormat;
    const CanTp_CanFrameType CanFrameType;
    /* Network Target Address type */
    const uint8 nTa;
    const PduLengthType TxNPduDLC;
    const uint8 Padding;
} CanTp_TxSduType;

/**=======[T Y P E   D E F I N I T I O N S]===================================*/

typedef struct
{
#if (STD_OFF == CANTP_FD_SUPPORT)
    uint8 data[CANTP_DRV_PDU_MAX_LENGTH];
#else
    uint8 data[CANTP_DRV_FDPDU_MAX_LENGTH];
#endif
    uint8 byteCount;
} CanTp_PduType;

typedef enum
{
    /* Not specified by ISO15765 - used as error return type when decoding frame. */
    CANTP_INVALID_FRAME = 0u,
    CANTP_SINGLE_FRAME,
    CANTP_FIRST_FRAME,
    CANTP_CONSECUTIVE_FRAME,
    /* FC with CTS:Continus to send */
    CANTP_FLOW_CONTROL_CTS_FRAME,
    CANTP_FLOW_CONTROL_WT
} CanTp_Iso15765FrameType;

/*define the PCI Type of N-PDU*/
typedef enum
{
    CANTP_PCI_SF = 0x00u,
    CANTP_PCI_FF = 0x10u,
    CANTP_PCI_CF = 0x20U,
    CANTP_PCI_FC = 0x30U,
    CANTP_PCI_NONE = 0x40U,
    /* PCI mask */
    CANTP_PCI_MASK = 0xF0U
} CanTp_PCIType;

typedef enum
{
    /* IDLE */
    CANTP_IDLE = 0u,
    /* send FC(not overflow) frame */
    CANTP_SEND_FC,
    /* send FC confirmation  */
    /* FC with CTS status confirmation */
    CANTP_SEND_FC_CTS_CONFIRMATION,
    /* send FC(overflow) frame */
    CANTP_SEND_FC_OVFLW,
    /* FC with overflow status confirmation */
    CANTP_SEND_FC_OVFLW_CONFIRMATION,
    /* WAIT Receive CF frame */
    CANTP_WAIT_CF,
    /* WAIT Receive FC frame */
    CANTP_WAIT_FC,
    /* CANTP is in send SF or FF state */
    CANTP_SEND_SF_FF,
    /* send SF confirmation */
    CANTP_SEND_SF_CONFIRMATION,
    /* WAIT Receive FC frame */
    CANTP_SEND_CF,
    /* CANTP is in processing */
    CANTP_PROCESSING,
    /* CANTP is Reception success */
    CANTP_RECEPTION_SUCCESS,
    /* FF, CF process */
    CANTP_WAITING_FOR_FF_TX_CONFIRMATION,
    CANTP_WAITING_FOR_LAST_CF_TX_CONFIRMATION,
    CANTP_WAITING_FOR_CF_TX_CONFIRMATION,
    CANTP_WAITING_FOR_CF_BLOCK_TX_CONFIRMATION
}   CanTp_StateType;

typedef struct
{
    /* Counter keeping track total frames handled, count the CF frame. */
    uint8 framesHandledCount;
    /* In case we are transmitters the remote node can configure this value (only valid for TX). */
    uint8 stmin;
    /* BlockSize (only valid for TX).if FC with BS=0, the runtime BS will be 0xFFFF */
    uint16 bs;
    /* time counter */
    uint16 timeoutCounterValue;
    /* The PDUR make an instance of this. */
    PduInfoType* pdurBuffer;
    /* Number of bytes in PDUR buffer, which has been written to dsm buffer */
    uint16 pdurBufferCount;
    /* Total length of the PDU. */
    PduLengthType transferTotal;
    /* Counter ongoing transfer. */
    uint16 transferCount;
    /* Temp storage of SDU data. */
    CanTp_PduType canFrameBuffer;
    /* Temp storage of Received block size*/
    uint16 CanTp_ReceivedCFBlockSize;
    PduIdType rxDcmId;
    /* receive state machine. */
    CanTp_StateType tpRxState;
    /*FF FD PduLength*/
    PduLengthType FDDL;

    PduIdType txFcId;
}   CanTp_RunTime_RxDataType;

typedef struct
{
    /* Counter keeping track total frames handled, count the CF frame. */
    uint8 framesHandledCount;
    /* In case we are transmitters the remote node can configure this value (only valid for TX). */
    uint8 stmin;
    /* BlockSize (only valid for TX).if FC with BS=0, the runtime BS will be 0xFFFF */
    uint16 bs;
    /* time counter */
    uint16 timeoutCounterValue;
    /* The PDUR make an instance of this. */
    PduInfoType* pdurBuffer;
    /* Number of bytes in PDUR buffer, which has been written to dsm buffer */
    uint16 pdurBufferCount;
    /* Total length of the PDU. */
    PduLengthType transferTotal;
    /* Counter ongoing transfer. */
    uint16 transferCount;
    /* Temp storage of SDU data. */
    CanTp_PduType canFrameBuffer;
    PduIdType txDcmId;
    /* Transfer state machine. */
    CanTp_StateType tpState;
    /* the MinTime to Send CF frame */
    uint8 MinTime2SendCF;
    /*Wait flow control count.*/
    uint32 WTFCCounterValue;
}   CanTp_RunTime_TxDataType;

typedef struct
{
    CanTp_RunTime_RxDataType rx_RunTime;
    CanTp_RunTime_TxDataType tx_RunTime;
} CanTp_RunTime_Type;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* endif of CANTP_TYPE_H_ */

