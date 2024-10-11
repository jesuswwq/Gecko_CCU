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
**  FILENAME    : PduR_CanIf.h                                                **
**                                                                            **
**  Created on  : 2023/09/14 17:09:19                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : API declaration supplied by PDUR to CANIF                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef  PDUR_CANIF_H
#define  PDUR_CANIF_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PDUR_CANIF_H_AR_MAJOR_VERSION      4u
#define PDUR_CANIF_H_AR_MINOR_VERSION      2u
#define PDUR_CANIF_H_AR_PATCH_VERSION      2u

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define PduR_CanIfRxIndication               PduR_IfRxIndication
#define PduR_CanIfTxConfirmation             PduR_IfTxConfirmation
#define PduR_CanIfTriggerTransmit            PduR_IfTriggerTransmit
#endif

