/***********************************************************************************************************************
**                                                                                                                    **
** Copyright (C) iSOFT   (2022)                                                                                       **
**                                                                                                                    **
** All rights reserved.                                                                                               **
**                                                                                                                    **
** This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and     **
** communication of its contents is not permitted without prior written authorization.                                **
**                                                                                                                    **
************************************************************************************************************************
**                                                                                                                    **
**  @file               : ComM_Dcm.h                                                                                  **
**  @version            : V1.0.0                                                                                      **
**  @author             : darren.zhang                                                                                **
**  @date               : 2022/01/07                                                                                  **
**  @vendor             : isoft                                                                                       **
**  @description        : Communication Manager                                                                       **
**  @specification(s)   : AUTOSAR classic Platform R19-11                                                             **
**                                                                                                                    **
***********************************************************************************************************************/

#ifndef COMM_DCM_H_
#define COMM_DCM_H_
/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"
#if (COMM_DCM_INDICATION == STD_ON)
#include "ComM_Types.h"
/*========================================[external function declarations]============================================*/
BEGIN_C_DECLS
FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel);
FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel);
END_C_DECLS
#endif /* (COMM_DCM_INDICATION == STD_ON) */

#endif /* COMM_DCM_H_ */
