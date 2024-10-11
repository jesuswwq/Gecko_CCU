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
**  @file               : ComM_Ch.h                                                                                   **
**  @version            : V1.0.0                                                                                      **
**  @author             : darren.zhang                                                                                **
**  @date               : 022/01/07                                                                                   **
**  @vendor             : isoft                                                                                       **
**  @description        : Communication Manager                                                                       **
**  @specification(s)   : AUTOSAR classic Platform R19-11                                                             **
**                                                                                                                    **
***********************************************************************************************************************/

#ifndef COMM_CH_H_
#define COMM_CH_H_

/*=================================================[inclusions]=======================================================*/

/*====================================================[macros]========================================================*/
#define COMM_BUS_SLEEP             0xffu
#define COMM_CH_CFG_IS(chCfg, vlu) (0u != ((chCfg)->cfgMask[COMM_VLU_MAPU32_BYTE(vlu)] & COMM_VLU_MAPU32_MASK(vlu)))

/*=============================================[type definitions]=====================================================*/

#if (COMM_CHANNEL_NUMBER > 0u)

typedef struct
{

#define COMM_SPEC_NOCOM_NOPENDING_REQ COMM_NO_COM_NO_PENDING_REQUEST
#define COMM_SPEC_NOCOM_REQ_PENDING   COMM_NO_COM_REQUEST_PENDING
#define COMM_SPEC_FULL_COM_REQ        COMM_FULL_COM_NETWORK_REQUESTED
#define COMM_SPEC_FULL_READY_SLEEP    COMM_FULL_COM_READY_SLEEP
#define COMM_SPEC_SILENT_COM          COMM_SILENT_COM
    uint8 specMode;
#define COMM_REQMODE_FULL_COMMUNICATION                     0x0u
#define COMM_REQMODE_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST 0x1u
    uint8 reqMode;
    /** \brief indication of nmif mode */
#if (COMM_USED_MODULE_NM == STD_ON)
#define COMM_NM_IND_BUS_SLEEP        0x0u
#define COMM_NM_IND_PREPARE_BUSSLEEP 0x1u
#define COMM_NM_IND_NETWORK_MODE     0x3u
    uint8 nmInd;
#endif /* (COMM_USED_MODULE_NM == STD_ON) */
    /** \brief indication of actual bus mode */
    ComM_ModeType busSmIndMode;
    /** \brief requested actual bus mode */
    ComM_ModeType busSmReqMode;
    /* function mask */
#define COMM_FUN_ALLOW_STU       0x0u
#define COMM_FUN_DCM_STU         0x1u
#define COMM_FUN_PASSIVE_WAKEUP  0x2u
#define COMM_FUN_LIMIT_WAKEUP    0x3u
#define COMM_FUN_LIMIT_NOCOM_REQ 0x4u
#if (COMM_RESET_AFTER_FORCING_NOCOMM == STD_ON)
#define COMM_FUN_LIMIT_NOCOM_FORCE 0x5u
#endif /* (COMM_RESET_AFTER_FORCING_NOCOMM == STD_ON) */
#define COMM_FUN_NMIF_REQ     0x6u
#define COMM_FUN_REQUEST_MODE 0x7u
#define COMM_FUN_BUSSM_IND    0x8u
    uint32 funcMask[1];
    uint32 reqCnt;
    uint8* reqMask;
#if (defined(COMM_NM_VARIANT_LIGHT) || defined(COMM_NM_VARIANT_NONE))
    uint32 durationTmr;
#endif /* (defined(COMM_NM_VARIANT_LIGHT) || defined(COMM_NM_VARIANT_NONE)) */
} ComM_ChVarType;

/*========================================[external function declarations]============================================*/

BEGIN_C_DECLS
FUNC(void, COMM_CODE)
ComM_ChInit(P2CONST(ComM_ChannelConfigType, AUTOMATIC, COMM_APPL_CONST) chCfgPtr, uint32 chNum);
#if defined(COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR)
FUNC(void, COMM_CODE)
ComM_ChWrtieNvmData(void);
#endif /* defined(COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR) */

FUNC(void, COMM_CODE)
ComM_ChGetState(uintx chIdx, ComM_StateType* chStu);

void ComM_ChGetMaxAllowMode(uintx chIdx, ComM_ModeType* chMode);

FUNC(void, COMM_CODE)
ComM_ChGetInhibitionStu(uintx chIdx, ComM_InhibitionStatusType* chStu);

FUNC(Std_ReturnType, COMM_CODE)
ComM_ChGetCurrentComMode(uintx chIdx, ComM_ModeType* ComMode);

FUNC(void, COMM_CODE) ComM_ChFuncSwitchHandle(uintx chIdx, uintx funcIdex, boolean flag);

FUNC(void, COMM_CODE) ComM_ChComAllow(uintx chIdx, boolean allowed);

FUNC(void, COMM_CODE) ComM_ChBusSmModeInd(uintx chIdx, ComM_ModeType comMode);

FUNC(void, COMM_CODE) ComM_ChNmModeInd(uintx chIdx, uint8 indMode);

FUNC(Std_ReturnType, COMM_CODE) ComM_ChRequstCommMode(uintx chIdx, uintx reqIdex, ComM_ModeType comMode);

FUNC(void, COMM_CODE) ComM_ChEcuMWakeup(uintx chIdx);

FUNC(void, COMM_CODE) ComM_ChPassiveWakeup(uintx chIdx);

FUNC(void, COMM_CODE) ComM_ChProcessTimer(uint8 chIdx);

#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
FUNC(Std_ReturnType, COMM_CODE) ComM_ChLimitWakeUp(uintx chIdx, boolean stu);
#endif /* (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) */

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
FUNC(Std_ReturnType, COMM_CODE) ComM_ChLimitNoCom(uintx chIdx, boolean stu);
#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON) */

#if (COMM_DCM_INDICATION == STD_ON)
FUNC(void, COMM_CODE) ComM_ChDiagIndication(uintx chIdx, boolean flag);
#endif /* (COMM_DCM_INDICATION==STD_ON) */

FUNC(void, COMM_CODE) ComM_ChSetEcuGroupCls(ComM_InhibitionStatusType Status);

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON) && defined(COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR)
FUNC(Std_ReturnType, COMM_CODE)
ComM_ChReadInhibitCounter(P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA)
                              counterValue /* PRQA S 3432 */ /* MISRA Rule 20.7 */);
FUNC(Std_ReturnType, COMM_CODE) ComM_ChResetInhibitCounter(void);
#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON) && defined(COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR) */

#if ((COMM_USER_MODESWITCH_NOTIFY == STD_ON) && (COMM_USER_NUMBER > 0))
FUNC(void, COMM_CODE)
ComM_UserStateChangeNotify(P2CONST(ComM_UserConfigType, AUTOMATIC, COMM_APPL_CONST) usrCfgPtr, ComM_ModeType mode);
#endif /* ((COMM_USER_MODESWITCH_NOTIFY == STD_ON) && (COMM_USER_NUMBER > 0)) */

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_USER_NUMBER > 0))
FUNC(void, COMM_CODE) ComM_ClearUserRequestByChLimit(uintx chIdx);
#endif /* ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_USER_NUMBER > 0)) */

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
FUNC(Std_ReturnType, COMM_CODE)
ComM_ChRequstCommModeLimitCheck(uintx chIdx, uintx reqIdex, ComM_ModeType comMode);
#endif /* ((COMM_MODE_LIMITATION_ENABLED == STD_ON)  || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)) */

END_C_DECLS

#endif /* (COMM_CHANNEL_NUMBER > 0u) */

#endif /* COMM_CH_H_ */
