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
**  @file               : ComM_BusSM.h                                                                                **
**  @version            : V1.0.0                                                                                      **
**  @author             : darren.zhang                                                                                **
**  @date               : 2022/04/05                                                                                  **
**  @vendor             : isoft                                                                                       **
**  @description        : Communication Manager                                                                       **
**  @specification(s)   : AUTOSAR classic Platform R19-11                                                             **
**                                                                                                                    **
***********************************************************************************************************************/

#ifndef COMM_BUSSM_H
#define COMM_BUSSM_H

/*=================================================[inclusions]=======================================================*/
#include "ComM_Types.h"
#include "ComM_Cfg.h"

/*======================================[external function definitions]===============================================*/
BEGIN_C_DECLS
#if (COMM_BUSNM_MODEIND_PARAUSEDPTR == STD_ON)
FUNC(void, COMM_CODE)
ComM_BusSM_ModeIndication(
    NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode /* PRQA S 3432 */ /* MISRA Rule 20.7 */);

#else
FUNC(void, COMM_CODE)
ComM_BusSM_ModeIndication(NetworkHandleType Channel, ComM_ModeType ComMode);
#endif /* (COMM_BUSNM_MODEIND_PARAUSEDPTR == STD_ON) */

FUNC(void, COMM_CODE) ComM_BusSM_BusSleepMode(NetworkHandleType Channel);
END_C_DECLS

#endif /* COMM_BUSSM_H */
