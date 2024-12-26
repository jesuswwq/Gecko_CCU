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

#define SchM_Enter_Dcm_Dcm_ChannelCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_ChannelCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_MsgCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_MsgCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_ConnectionCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_ConnectionCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_ProtocolCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_ProtocolCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_ProtocolPreemptCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_ProtocolPreemptCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_MkCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_MkCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_SesCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_SesCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_SecCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_SecCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_Channel SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_Channel ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_CommCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_CommCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_LinkControlCtrl SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_LinkControlCtrl ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_DspProgram SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_DspProgram ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_PageBufferData SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_PageBufferData ResumeAllInterrupts()

#define SchM_Enter_Dcm_Dcm_RoutineControlState SuspendAllInterrupts()
#define SchM_Exit_Dcm_Dcm_RoutineControlState ResumeAllInterrupts()

#endif /* SCHM_DCM_H_ */
