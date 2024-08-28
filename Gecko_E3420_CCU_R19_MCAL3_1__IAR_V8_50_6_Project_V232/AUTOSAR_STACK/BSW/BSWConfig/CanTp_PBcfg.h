/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-11-13 14:42:40>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H

/*======== [I N C L U D E S]========================*/
#include "Std_Types.h"

/*========[V E R S I O N  I N F O R M A T I O N]=========*/
#define CANTP_CFG_H_AR_MAJOR_VERSION 4U
#define CANTP_CFG_H_AR_MINOR_VERSION 5U
#define CANTP_CFG_H_AR_PATCH_VERSION 0U
#define CANTP_CFG_H_SW_MAJOR_VERSION 2U
#define CANTP_CFG_H_SW_MINOR_VERSION 1U
#define CANTP_CFG_H_SW_PATCH_VERSION 1U

/*========[M A C R O S] ==========================*/
/* Total number of channel used in CanTp module. */
#define CANTP_CHANNEL_NUMBER                        0x2u

/*configuration MACRO addressing mode for cutting*/
#define CANTP_EXTENDED_ADDRESSING_SUPPORT           STD_OFF
#define CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT       STD_OFF
#define CANTP_MIXED_ADDRESSING_SUPPORT              STD_OFF
#define CANTP_MIXED29_ADDRESSING_SUPPORT            STD_OFF

/* -------------------- CanTpChannel -------------------- */

/* CanTpRxNSdu_FuncReq */    
#define CANTP_CANTP_RX_Diag_FuncReq_OBD                                0x106u/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_FuncReq_OBD                                 0x103u/*RxNPdu Id*/

/* CanTpRxNSdu_PhyReq */    
#define CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD                                0x105u/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_CCU_OBD                                 0x102u/*RxNPdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_CCU_OBD                               0x101u/*TxFcNPdu Id*/

/* CanTpTxNSdu_PhyResp */    
#define CANTP_CANTP_TX_Diag_Resp_CCU_OBD                                0x104u/*TxNSdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_CCU_OBD                                 0x101u/*TxNPdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_CCU_OBD                               0x102u/*RxFcNPdu Id*/
/* -------------------- CanTpChannel_BAC -------------------- */

/* CanTpRxNSdu_FuncReq */    
#define CANTP_CANTP_RX_Diag_FuncReq_BAC                                0x1f6u/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_FuncReq_BAC                                 0x170u/*RxNPdu Id*/

/* CanTpRxNSdu_PhyReq */    
#define CANTP_CANTP_RX_Diag_PhyReq_BAC                                0x1f5u/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_BAC                                 0x1f3u/*RxNPdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_BAC                               0x1f4u/*TxFcNPdu Id*/

/* CanTpTxNSdu_PhyResp */    
#define CANTP_CANTP_TX_Diag_Resp_BAC                                0x1f7u/*TxNSdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_BAC                                 0x1f4u/*TxNPdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_BAC                               0x1f3u/*RxFcNPdu Id*/

#endif /* CANTP_PBCFG_H */
