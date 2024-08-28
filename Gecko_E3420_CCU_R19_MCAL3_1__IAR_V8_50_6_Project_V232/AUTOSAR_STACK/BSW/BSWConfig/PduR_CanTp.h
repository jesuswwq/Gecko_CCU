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
**  FILENAME    : PduR_CanTp.h                                                **
**                                                                            **
**  Created on  : 2023/10/23 13:54:49                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : API declaration supplied by PDUR to CANTP                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef  PDUR_CANTP_H
#define  PDUR_CANTP_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PDUR_CANTP_H_AR_MAJOR_VERSION      4u
#define PDUR_CANTP_H_AR_MINOR_VERSION      2u
#define PDUR_CANTP_H_AR_PATCH_VERSION      2u
#define PDUR_CANTP_H_SW_MAJOR_VERSION      2u
#define PDUR_CANTP_H_SW_MINOR_VERSION      0u
#define PDUR_CANTP_H_SW_PATCH_VERSION      0u

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define PduR_CanTpStartOfReception    PduR_TpStartOfReception
#define PduR_CanTpCopyRxData          PduR_TpCopyRxData
#define PduR_CanTpRxIndication        PduR_TpRxIndication
#define PduR_CanTpCopyTxData          PduR_TpCopyTxData
#define PduR_CanTpTxConfirmation      PduR_TpTxConfirmation

#endif

