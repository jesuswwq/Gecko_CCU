/***********************************************************************************************************************
**                                                                                                                    **
** Copyright (C) iSOFT   (2022)                                                                                       **
**                                                                                                                    **
** All rights reserved.                                                                                               **
**                                                                                                                    **
** This document contains proprietary information belonging to iSOFT.                                                 **
** Passing on and copying of this document, and communication                                                         **
** of its contents is not permitted without prior written authorization.                                              **
**                                                                                                                    **
************************************************************************************************************************
**                                                                                                                    **
**  FILENAME    : SchM_J1939Tp.h                                                                                      **
**                                                                                                                    **
**  Created on  :                                                                                                     **
**  Author      : darren.zhang                                                                                        **
**  Vendor      :                                                                                                     **
**  DESCRIPTION : Implementation for J1939Tp                                                                          **
**                                                                                                                    **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                                                              **
**                                                                                                                    **
***********************************************************************************************************************/

#ifndef SCHM_J1939TP_H_
#define SCHM_J1939TP_H_

/*==========================[V E R S I O N  I N F O R M A T I O N]====================================================*/
#define SCHM_J1939TP_H_AR_MAJOR_VERSION 1U
#define SCHM_J1939TP_H_AR_MINOR_VERSION 1U
#define SCHM_J1939TP_H_AR_PATCH_VERSION 2U

#define SchM_Enter_J1939Tp_TxChannel(ch)
#define SchM_Exit_J1939Tp_TxChannel(ch)

#define SchM_Enter_J1939Tp_TxConnection()
#define SchM_Exit_J1939Tp_TxConnection()

#define SchM_Enter_J1939Tp_RxChannel(ch)
#define SchM_Exit_J1939Tp_RxChannel(ch)

#define SchM_Enter_J1939Tp_RxConnection()
#define SchM_Exit_J1939Tp_RxConnection()

#endif /* SCHM_J1939TP_H_ */