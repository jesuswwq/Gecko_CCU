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
**  FILENAME    : SchM_Dcm.h                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Xinrun.Wang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Dcm Schedule Manager                                        **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

#ifndef SCHM_DCM_H
#define SCHM_DCM_H

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* PRQA S 0342++ */ /* MISRA Rule 20.10 */
#define SchM_Switch_DcmDiagnosticSessionControl(Session)      SchM_Switch_##bsnp##_DcmDiagnosticSessionControl(Session)
#define SchM_Switch_DcmControlDTCSetting(Setting)             SchM_Switch_##bsnp##_DcmControlDTCSetting(Setting)
#define SchM_Switch_DcmEcuReset(Reset)                        SchM_Switch_##bsnp##_DcmEcuReset(Reset)

#define SchM_Switch_bsnp_DcmDiagnosticSessionControl(Session) (Session)
#define SchM_Switch_bsnp_DcmControlDTCSetting(Setting)
#define SchM_Switch_bsnp_DcmEcuReset(Reset) SchM_PerformReset(Reset)

#define SchM_Enter_Dcm(exclusiveArea)       SchM_Enter_Dcm_##exclusiveArea
#define SchM_Exit_Dcm(exclusiveArea)        SchM_Exit_Dcm_##exclusiveArea
/* PRQA S 0342-- */ /* MISRA Rule 20.10 */

#define SchM_Enter_Dcm_Dcm_ChannelCtrl
#define SchM_Exit_Dcm_Dcm_ChannelCtrl

#define SchM_Enter_Dcm_Dcm_MsgCtrl
#define SchM_Exit_Dcm_Dcm_MsgCtrl

#define SchM_Enter_Dcm_Dcm_ConnectionCtrl
#define SchM_Exit_Dcm_Dcm_ConnectionCtrl

#define SchM_Enter_Dcm_Dcm_ProtocolCtrl
#define SchM_Exit_Dcm_Dcm_ProtocolCtrl

#define SchM_Enter_Dcm_Dcm_ProtocolPreemptCtrl
#define SchM_Exit_Dcm_Dcm_ProtocolPreemptCtrl

#define SchM_Enter_Dcm_Dcm_MkCtrl
#define SchM_Exit_Dcm_Dcm_MkCtrl

#define SchM_Enter_Dcm_Dcm_SesCtrl
#define SchM_Exit_Dcm_Dcm_SesCtrl

#define SchM_Enter_Dcm_Dcm_SecCtrl
#define SchM_Exit_Dcm_Dcm_SecCtrl

#define SchM_Enter_Dcm_Dcm_Channel
#define SchM_Exit_Dcm_Dcm_Channel

#define SchM_Enter_Dcm_Dcm_CommCtrl
#define SchM_Exit_Dcm_Dcm_CommCtrl

#define SchM_Enter_Dcm_Dcm_LinkControlCtrl
#define SchM_Exit_Dcm_Dcm_LinkControlCtrl

#define SchM_Enter_Dcm_Dcm_DspProgram
#define SchM_Exit_Dcm_Dcm_DspProgram

#define SchM_Enter_Dcm_Dcm_PageBufferData
#define SchM_Exit_Dcm_Dcm_PageBufferData

#define SchM_Enter_Dcm_Dcm_RoutineControlState
#define SchM_Exit_Dcm_Dcm_RoutineControlState

#endif /* SCHM_DCM_H_ */
