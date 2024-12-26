
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
**  FILENAME    : CanTp_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/04/11 14:38:23                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : TP (ISO 15765-2) Configration file.                         **
**                                                                            **
**  SPECIFICATION(S) : ISO 15765-2                                            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230818   long.zhu           Initial Version
 */

#ifndef CANTP_CFG_H
#define CANTP_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "GptIf_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* @type:NONE range:  */
#define CANTP_RX_PADDING_CHECK      STD_ON

/* @type:NONE range:  */
#define CANTP_RX_PADDING_VAL_CHECK  STD_OFF

/* @type:NONE range:  */
#define CANTP_FD_SUPPORT            STD_ON

/* @type:NONE range:NONE note:auto generate */
#define CANTP_TX_PADDING_ON         STD_ON

/* @type:define range:GPT_PERIOD_TIME note:auto generate */
#define CANTP_MAIN_TICK             GPT_PERIOD_TIME

#define CANTP_Tx_FC_BS              (8u)

/** Minimum time the sender shall wait between transmissions of two N-PDU */
/* @type:uint8 range:0~255 note:uint-ms */
#define CANTP_Tx_FC_STMIN           (0u)

/** N_As timeout for transmission of any CAN frame */
/* @type:uint8 range:0~255 note:uint-ms */
#define CANTP_N_AS                  70u

/** Timeout for transmission of a CAN frame (ms) */
/* @type:uint8 range:0~255 note:uint-ms */
#define CANTP_N_AR                  70u

/** N_Bs timeout */
/* @type:uint8 range:0~255 note:uint-ms */
#define CANTP_N_BS                  150u

/** N_Br timeout for receive FF than to send FC frame */
/* @type:uint8 range:0~255 note:uint-ms */
#define CANTP_N_BR                  0u

/** Time out for consecutive frames (ms) */
/* @type:uint8 range:0~255 note:uint-ms */
#define CANTP_N_CR                  150u

/** Time out for tx consecutive frames (ms) */
/* @type:uint8 range:0~255 note:uint-ms */
#define CANTP_N_CS                  150u

/** TX frame padding value */
#define TX_CANTP_PADDING_VALUE      0x55u

/** RX ADDRESS Index of physical */
#define RX_PHYSICAL_ADDRESSING      0x0u
/** Rx ADDRESS Index of function */
#define RX_FUNCTIONAL_ADDRESSING    0x1u

/* @type:uint8 range:1~255 note:reference to num of CanTp_TxSdu */
#define CANTP_TX_CHANNEL_NUM        2u

/* @type:uint8 range:1~255 note:reference to num of CanTp_RxSdu */
#define CANTP_RX_CHANNEL_NUM        4u

/*Half-duplex communication enable.*/
#define CANTP_MODE_HALF_DUPLEX      STD_OFF

/*Maximum number of FC.WAIT frame transmissions.*/
#define CANTP_N_WFTmax              255u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif/* endif of CANTP_CFG_H */

