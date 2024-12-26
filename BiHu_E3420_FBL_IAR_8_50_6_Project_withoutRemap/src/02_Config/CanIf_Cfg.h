
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
**  FILENAME    : CanIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2023/11/23 14:59:01                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configration file for CanIf.                                **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>     <REVISION LOG>
 *   V1.0.0     20230818     long.zhu        Initial version
 */

#ifndef CANIF_CFG_H_
#define CANIF_CFG_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANIF_TX_CHANNEL_NUM    2u

#define CANIF_RX_CHANNEL_NUM    4u

/*The FIFO function is enabled.*/
#define CANIF_RX_FIFO_ENABLE                    STD_ON
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* CANIF_CFG_H_ */

