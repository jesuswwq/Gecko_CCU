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
**  @file               : ComM_EcuM.h                                                                                 **
**  @version            : V1.0.0                                                                                      **
**  @author             : darren.zhang                                                                                **
**  @date               : 2022/01/07                                                                                  **
**  @vendor             : isoft                                                                                       **
**  @description        : Communication Manager                                                                       **
**  @specification(s)   : AUTOSAR classic Platform R19-11                                                             **
**                                                                                                                    **
***********************************************************************************************************************/
#ifndef COMM_ECUM_H_
#define COMM_ECUM_H_
/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"

#if (COMM_ECUM_ENABLE == STD_ON)
#include "ComM_Types.h"
/*========================================[external function declarations]============================================*/

BEGIN_C_DECLS
FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication(NetworkHandleType Channel);
#if (COMM_PNC_SUPPORT == STD_ON)
FUNC(void, COMM_CODE) ComM_EcuM_PNCWakeUpIndication(PNCHandleType PNCid);
END_C_DECLS

#endif /* (COMM_PNC_SUPPORT == STD_ON) */

#endif /* (COMM_ECUM_ENABLE == STD_ON) */

#endif /* COMM_ECUM_H_ */
