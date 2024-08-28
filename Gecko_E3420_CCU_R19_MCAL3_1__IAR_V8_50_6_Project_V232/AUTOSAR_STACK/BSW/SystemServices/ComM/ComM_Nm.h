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
**  @file               : ComM_Nm.h                                                                                   **
**  @version            : V1.0.0                                                                                      **
**  @author             : darren.zhang                                                                                **
**  @date               : 2022/01/07                                                                                  **
**  @vendor             : isoft                                                                                       **
**  @description        : Communication Manager                                                                       **
**  @specification(s)   : AUTOSAR classic Platform R19-11                                                             **
**                                                                                                                    **
***********************************************************************************************************************/
#ifndef COMM_NM_H_
#define COMM_NM_H_
/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"
#if (COMM_USED_MODULE_NM == STD_ON)
#include "ComM_Types.h"
/*========================================[external function declarations]============================================*/
BEGIN_C_DECLS
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType Channel);
FUNC(void, COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel);
FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel);
FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel);
FUNC(void, COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType Channel);
#if (COMM_DYN_PNC_TO_CH_MAPP_SUPPORT == STD_ON)

FUNC(void, COMM_CODE) ComM_Nm_RepeatMessageLeftIndication(NetworkHandleType Channel);
FUNC(void, COMM_CODE) ComM_Nm_PncLearningBitIndication(NetworkHandleType Channel);
#endif /* (COMM_DYN_PNC_TO_CH_MAPP_SUPPORT == STD_ON) */
#if (COMM_SYNC_PNC_SHUTDOWN_ENABLED == STD_ON)
FUNC(void, COMM_CODE) ComM_Nm_ForwardSynchronizedPncShutdown(NetworkHandleType Channel, const uint8* PncBitVectorPtr);
#endif /* (COMM_SYNC_PNC_SHUTDOWN_ENABLED == STD_ON) */

#if (COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_USED_COM != STD_ON)
FUNC(void, COMM_CODE) ComM_Nm_UpdateEIRA(P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr);
FUNC(void, COMM_CODE)
ComM_Nm_UpdateERA(NetworkHandleType Channel, P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr);
#endif /* (COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_USED_COM != STD_ON) */

END_C_DECLS

#endif /* (COMM_USED_MODULE_NM==STD_ON) */

#endif /* COMM_NM_H_ */
