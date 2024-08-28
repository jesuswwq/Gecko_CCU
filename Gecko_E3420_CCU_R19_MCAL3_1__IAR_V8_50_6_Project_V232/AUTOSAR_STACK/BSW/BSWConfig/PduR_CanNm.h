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
**  FILENAME    : PduR_CanNm.h                                                **
**                                                                            **
**  Created on  : 2023/10/10 15:11:49                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : API declaration supplied by PDUR to CANNM                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef PDUR_CANNM_H
#define PDUR_CANNM_H
/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "PduR.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PDUR_CANNM_H_AR_MAJOR_VERSION      4u
#define PDUR_CANNM_H_AR_MINOR_VERSION      2u
#define PDUR_CANNM_H_AR_PATCH_VERSION      2u
#define PDUR_CANNM_H_SW_MAJOR_VERSION      2u
#define PDUR_CANNM_H_SW_MINOR_VERSION      0u
#define PDUR_CANNM_H_SW_PATCH_VERSION      0u

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define PduR_CanNmRxIndication               PduR_IfRxIndication
#define PduR_CanNmTxConfirmation             PduR_IfTxConfirmation
#define PduR_CanNmTriggerTransmit            PduR_IfTriggerTransmit

#endif

