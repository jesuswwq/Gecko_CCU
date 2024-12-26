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
 * @file  Canif.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Canif Driver.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
#include "CanIf_Types.h"
#include "CanIf_Cbk.h"
#include "Can_Cfg.h"
#include "debug.h"

/* Version and Check Begin */
/* Version Info Begin */
#define CANIF_C_VENDOR_ID    0x8C
#define CANIF_C_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_C_AR_RELEASE_MINOR_VERSION    3
#define CANIF_C_AR_RELEASE_REVISION_VERSION 1
#define CANIF_C_SW_MAJOR_VERSION    1
#define CANIF_C_SW_MINOR_VERSION    0
#define CANIF_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CANIF_C_AR_RELEASE_MAJOR_VERSION != MCAL_H_AR_RELEASE_MAJOR_VERSION)\
    || (CANIF_C_AR_RELEASE_MINOR_VERSION != MCAL_H_AR_RELEASE_MINOR_VERSION)\
    || (CANIF_C_AR_RELEASE_REVISION_VERSION != MCAL_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, CanIf.c and Mcal.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CANIF_C_SW_MAJOR_VERSION != MCAL_H_SW_MAJOR_VERSION)\
    || (CANIF_C_SW_MINOR_VERSION != MCAL_H_SW_MINOR_VERSION)\
    || (CANIF_C_SW_PATCH_VERSION != MCAL_H_SW_PATCH_VERSION))
#error "Opps, CanIf.c and Mcal.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CANIF_C_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (CANIF_C_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (CANIF_C_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, CanIf.c and CanIf_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CANIF_C_SW_MAJOR_VERSION != CANIF_TYPES_H_SW_MAJOR_VERSION)\
    || (CANIF_C_SW_MINOR_VERSION != CANIF_TYPES_H_SW_MINOR_VERSION)\
    || (CANIF_C_SW_PATCH_VERSION != CANIF_TYPES_H_SW_PATCH_VERSION))
#error "Opps, CanIf.c and CanIf_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CANIF_C_AR_RELEASE_MAJOR_VERSION != CANIF_CBK_H_AR_RELEASE_MAJOR_VERSION)\
    || (CANIF_C_AR_RELEASE_MINOR_VERSION != CANIF_CBK_H_AR_RELEASE_MINOR_VERSION)\
    || (CANIF_C_AR_RELEASE_REVISION_VERSION != CANIF_CBK_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, CanIf.c and CanIf_Cbk.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CANIF_C_SW_MAJOR_VERSION != CANIF_CBK_H_SW_MAJOR_VERSION)\
    || (CANIF_C_SW_MINOR_VERSION != CANIF_CBK_H_SW_MINOR_VERSION)\
    || (CANIF_C_SW_PATCH_VERSION != CANIF_CBK_H_SW_PATCH_VERSION))
#error "Opps, CanIf.c and CanIf_Cbk.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

uint32 t_cnt = 0;
uint32 r_cnt = 0;

FUNC(void, CANIF_CODE) CanIf_TxConfirmation
(
    VAR(PduIdType, AUTOMATIC) CanTxPduId
)
{
    PRINT("%s[line %d]: Tx complemetes for pdu id 0x%x\n", __FUNCTION__, __LINE__, CanTxPduId);
    t_cnt++;
}

#if defined(CFG_NATIVE_CAN_ROUTING)
extern void Can_MsgRouting(const Can_HwType *HwInfo, const PduInfoType *PduInfo);
#endif  /* CFG_NATIVE_CAN */
/* this api used for can_routing demo now, user need porting it to AUTOSAR PudR layer */

#if defined(AUTOSAR_VERSION_403)
FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    VAR(Can_HwHandleType, CANIF_APPL_DATA) hoh,
    VAR(Can_IdType, CANIF_APPL_DATA) CanId,
    VAR(PduLengthType, CANIF_APPL_DATA) SduLength,
    P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA) SduDataPtr
)
{
    PRINT("%s[line %d]: Rx frame by HRH %d\n", __FUNCTION__, __LINE__, hoh);
    PRINT("\t Frame ID = 0x%x\n", CanId);
    PRINT("\t Frame length = %d\n", SduLength);

    for (uint8 i = 0; i < SduLength; i++) {
        PRINT("\t Frame data[%d] = 0x%2x\n", i, SduDataPtr[i]);
    }
}
#else
FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    PRINT("%s[line %d]: Rx frame by controller %d HRH %d\n", __FUNCTION__, __LINE__,
              Mailbox->ControllerId, Mailbox->Hoh);
    PRINT("\t Frame ID = 0x%x\n", Mailbox->CanId);
    PRINT("\t Frame length = %d\n", PduInfoPtr->SduLength);

    for (uint8 i = 0; i < PduInfoPtr->SduLength; i++) {
        PRINT("\t Frame data[%d] = 0x%2x\n", i, PduInfoPtr->SduDataPtr[i]);
    }
    r_cnt++;
}
#endif


#if defined(AUTOSAR_VERSION_421) || defined(AUTOSAR_VERSION_403)
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode
)
#else
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(Can_ControllerStateType, AUTOMATIC) ControllerMode
)
#endif
{
    // PRINT("%s: Controller %d ControllerMode %d\n", __FUNCTION__, ControllerId, ControllerMode);
}

FUNC(void, CANIF_CODE) CanIf_ControllerBusOff
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    PRINT("%s: Controller %d bus off\n", __FUNCTION__, ControllerId);
}

FUNC(Std_ReturnType, CAN_CODE) CanIf_TriggerTransmit
(
    VAR(PduIdType, AUTOMATIC) TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    PRINT("%s: Fill Tx data for HTH 0x%x\n", __FUNCTION__, TxPduId);
    PduInfoPtr->SduLength = 7U;
    /*uses little endian format. */
    PduInfoPtr->SduDataPtr[3] = 0x11U;
    PduInfoPtr->SduDataPtr[2] = 0x22U;
    PduInfoPtr->SduDataPtr[1] = 0x33U;
    PduInfoPtr->SduDataPtr[0] = 0x44U;
    PduInfoPtr->SduDataPtr[7] = 0x55U;
    PduInfoPtr->SduDataPtr[6] = 0x66U;
    PduInfoPtr->SduDataPtr[5] = 0x77U;

    return E_OK;
}

#ifdef __cplusplus
}
#endif