/*
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  CanIf_Cbk.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Canif Driver.
 */
#ifndef CANIF_CBK_H_
#define CANIF_CBK_H_

#include "CanIf_Types.h"
#include "Can_Cfg.h"
/* Version and Check Begin */
/* Version Info Begin */
#define CANIF_CBK_H_VENDOR_ID    0x8C
#define CANIF_CBK_H_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_CBK_H_AR_RELEASE_MINOR_VERSION    3
#define CANIF_CBK_H_AR_RELEASE_REVISION_VERSION 1
#define CANIF_CBK_H_SW_MAJOR_VERSION    1
#define CANIF_CBK_H_SW_MINOR_VERSION    0
#define CANIF_CBK_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CANIF_CBK_H_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (CANIF_CBK_H_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (CANIF_CBK_H_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, CanIf_Cbk.h and CanIf_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CANIF_CBK_H_SW_MAJOR_VERSION != CANIF_TYPES_H_SW_MAJOR_VERSION)\
    || (CANIF_CBK_H_SW_MINOR_VERSION != CANIF_TYPES_H_SW_MINOR_VERSION)\
    || (CANIF_CBK_H_SW_PATCH_VERSION != CANIF_TYPES_H_SW_PATCH_VERSION))
#error "Opps, CanIf_Cbk.h and CanIf_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#ifdef __cplusplus
extern "C" {
#endif

extern FUNC(void, CANIF_CODE) CanIf_TxConfirmation
(
    VAR(PduIdType, AUTOMATIC) CanTxPduId
);

#if defined(AUTOSAR_VERSION_403)
extern FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    VAR(Can_HwHandleType, CANIF_APPL_DATA) hoh,
    VAR(Can_IdType, CANIF_APPL_DATA) CanId,
    VAR(PduLengthType, CANIF_APPL_DATA) SduLength,
    P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA) SduDataPtr
);
#else
extern FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);
#endif

#if defined(AUTOSAR_VERSION_421) || defined(AUTOSAR_VERSION_403)
extern FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode
);
#else
extern FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(Can_ControllerStateType, AUTOMATIC) ControllerMode
);
#endif

extern FUNC(void, CANIF_CODE) CanIf_ControllerBusOff
(
    VAR(uint8, AUTOMATIC) ControllerId
);

extern FUNC(Std_ReturnType, CAN_CODE) CanIf_TriggerTransmit
(
    VAR(PduIdType, AUTOMATIC) TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

#ifdef __cplusplus
}
#endif

#endif
