/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-10-14 18:05:47>
 */
/*============================================================================*/

/*=======[I N C L U D E S]================================*/
#include "CanTp.h"
#include "CanIf_Cfg.h"
#include "PduR_Cfg.h"

/*=======[I N T E R N A L   D A T A]=======================*/
/* PRQA S 0779,0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
/*CanTpChannel RxSdu address information*/

/* PRQA S 0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_Nar = 70u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_Bs = 8u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_STmin = 20u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_Nar = 70u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_Bs = 8u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_STmin = 20u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_RxNSduType, CANTP_CONST) CanTp_Ch0RxNSdus[2] =
{
    {
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_Bs,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_Nar,
        70u,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_OBD,
        CANTP_CANTP_RX_Diag_FuncReq_OBD,
        CANTP_CANIF_RX_Diag_FuncReq_OBD,
        0xFFu,
        0xFFu,
        0u,
        64u,
        CANTP_PADDING_ON,
        CANTP_CANFD_FUNCTIONAL,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_RxWftMax,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_FuncReq_OBD_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
    {
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_Bs,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_Nar,
        70u,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_CCU_OBD,
        CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD,
        CANTP_CANIF_RX_Diag_PhyReq_CCU_OBD,
        CANTP_CANIF_TX_Diag_Resp_CCU_OBD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCU_OBD,
        0u,
        64u,
        CANTP_PADDING_ON,
        CANTP_CANFD_PHYSICAL,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_RxWftMax,
        &CanTp_Ch0RxSdu_CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*CanTpChannel TxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CANTP_TX_Diag_Resp_CCU_OBD_Nbs = 150u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CANTP_TX_Diag_Resp_CCU_OBD_Ncs = 70u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_TxNSduType, CANTP_CONST) CanTp_Ch0TxNSdus[1] =
{
    {
        70u,
        &CanTp_Ch0TxSdu_CANTP_CANTP_TX_Diag_Resp_CCU_OBD_Nbs,
        &CanTp_Ch0TxSdu_CANTP_CANTP_TX_Diag_Resp_CCU_OBD_Ncs,
        CANTP_STANDARD,
        PDUR_DESTPDU_CANTP_TX_Diag_Resp_CCU_OBD,
        CANTP_CANTP_TX_Diag_Resp_CCU_OBD,
        CANTP_CANIF_TX_Diag_Resp_CCU_OBD,
        CANTP_CANIF_RX_Diag_PhyReq_CCU_OBD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCU_OBD,
        0u,
        64u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_TX,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3,Rule 5.2 */
/*CanTpChannel_BAC RxSdu address information*/

/* PRQA S 0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_Nar = 70u;
static CONST(uint32, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_Bs = 8u;
static CONST(uint8, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_STmin = 20u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_Nar = 70u;
static CONST(uint32, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_Bs = 8u;
static CONST(uint8, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_STmin = 20u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_RxNSduType, CANTP_CONST) CanTp_Ch1RxNSdus[2] =
{
    {
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_Bs,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_Nar,
        70u,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_BAC,
        CANTP_CANTP_RX_Diag_FuncReq_BAC,
        CANTP_CANIF_RX_Diag_FuncReq_BAC,
        0xFFu,
        0xFFu,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_CANFD_FUNCTIONAL,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_RxWftMax,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_FuncReq_BAC_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
    {
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_Bs,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_Nar,
        70u,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_BAC,
        CANTP_CANTP_RX_Diag_PhyReq_BAC,
        CANTP_CANIF_RX_Diag_PhyReq_BAC,
        CANTP_CANIF_TX_Diag_Resp_BAC,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_BAC,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_CANFD_PHYSICAL,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_RxWftMax,
        &CanTp_Ch1RxSdu_CANTP_CANTP_RX_Diag_PhyReq_BAC_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*CanTpChannel_BAC TxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch1TxSdu_CANTP_CANTP_TX_Diag_Resp_BAC_Nbs = 150u;
static CONST(uint32, CANTP_CONST) CanTp_Ch1TxSdu_CANTP_CANTP_TX_Diag_Resp_BAC_Ncs = 70u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_TxNSduType, CANTP_CONST) CanTp_Ch1TxNSdus[1] =
{
    {
        70u,
        &CanTp_Ch1TxSdu_CANTP_CANTP_TX_Diag_Resp_BAC_Nbs,
        &CanTp_Ch1TxSdu_CANTP_CANTP_TX_Diag_Resp_BAC_Ncs,
        CANTP_STANDARD,
        PDUR_DESTPDU_CANTP_TX_Diag_Resp_BAC,
        CANTP_CANTP_TX_Diag_Resp_BAC,
        CANTP_CANIF_TX_Diag_Resp_BAC,
        CANTP_CANIF_RX_Diag_PhyReq_BAC,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_BAC,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_TX,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN_FD,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3,Rule 5.2 */

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_ChannelType, CANTP_CONST) CanTp_CfgChannel[CANTP_CHANNEL_NUMBER] =
{
    {
        CANTP_MODE_FULL_DUPLEX,
        FALSE,
        50u,
        5000u,
        0u,
        0x2u,
        &CanTp_Ch0RxNSdus[0],
        0x1u,
        &CanTp_Ch0TxNSdus[0]
    },
    {
        CANTP_MODE_FULL_DUPLEX,
        FALSE,
        50u,
        5000u,
        0u,
        0x2u,
        &CanTp_Ch1RxNSdus[0],
        0x1u,
        &CanTp_Ch1TxNSdus[0]
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
CONST(CanTp_ConfigType, CANTP_CONST) CanTp_Config =
{
    CANTP_CHANNEL_NUMBER,
    &CanTp_CfgChannel[0]
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*=======[E X T E R N A L   D A T A]===========================*/
/*=======[E N D   O F   F I L E]==============================*/

