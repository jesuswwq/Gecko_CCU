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
 *  @date       <2024-10-14 18:05:47>
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
#define CANTP_CANTP_RX_Diag_FuncReq_OBD                                0xe7u/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_FuncReq_OBD                                 0xe4u/*RxNPdu Id*/

/* CanTpRxNSdu_PhyReq */    
#define CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD                                0xe6u/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_CCU_OBD                                 0xe3u/*RxNPdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_CCU_OBD                               0xe2u/*TxFcNPdu Id*/

/* CanTpTxNSdu_PhyResp */    
#define CANTP_CANTP_TX_Diag_Resp_CCU_OBD                                0xe5u/*TxNSdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_CCU_OBD                                 0xe2u/*TxNPdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_CCU_OBD                               0xe3u/*RxFcNPdu Id*/
/* -------------------- CanTpChannel_BAC -------------------- */

/* CanTpRxNSdu_FuncReq */    
#define CANTP_CANTP_RX_Diag_FuncReq_BAC                                0x1d0u/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_FuncReq_BAC                                 0x14cu/*RxNPdu Id*/

/* CanTpRxNSdu_PhyReq */    
#define CANTP_CANTP_RX_Diag_PhyReq_BAC                                0x1cfu/*RxNSdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_BAC                                 0x1cdu/*RxNPdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_BAC                               0x1ceu/*TxFcNPdu Id*/

/* CanTpTxNSdu_PhyResp */    
#define CANTP_CANTP_TX_Diag_Resp_BAC                                0x1d1u/*TxNSdu Id*/
#define CANTP_CANIF_TX_Diag_Resp_BAC                                 0x1ceu/*TxNPdu Id*/
#define CANTP_CANIF_RX_Diag_PhyReq_BAC                               0x1cdu/*RxFcNPdu Id*/

#endif /* CANTP_PBCFG_H */
