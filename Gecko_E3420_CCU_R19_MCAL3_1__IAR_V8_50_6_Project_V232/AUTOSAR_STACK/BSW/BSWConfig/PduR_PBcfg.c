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
**  FILENAME    : PduR_PBcfg.c                                                **
**                                                                            **
**  Created on  : 2024/06/17 10:36:47                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "CanIf.h"
#include "CanTp.h"
#include "Com_Cbk.h"
#include "Dcm.h"
#include "Dcm_Cbk.h"
#include "CanNm.h"
#include "LinIf.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_PBCFG_C_AR_MAJOR_VERSION  4u
#define PDUR_PBCFG_C_AR_MINOR_VERSION  2u
#define PDUR_PBCFG_C_AR_PATCH_VERSION  2u

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PDUR_PBCFG_C_AR_MAJOR_VERSION != PDUR_PBCFG_H_AR_MAJOR_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_PBCFG_C_AR_MINOR_VERSION != PDUR_PBCFG_H_AR_MINOR_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_PBCFG_C_AR_PATCH_VERSION != PDUR_PBCFG_H_AR_PATCH_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRDestPduType,PDUR_CONST)
PduR_DestPduConfigData[PDUR_DEST_PDU_SUM] =
{
    {
        PDUR_DESTPDU_INCA_CRO_XCP,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_INCA_CRO_XCP,
        CANIF_TXPDU_INCA_CRO_XCP,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_TMSR_DTO_XCP,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_TMSR_DTO_XCP,
        COM_RXPDU_COM_TMSR_DTO_XCP,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CanNm_CAN5_CANFD3_user,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_CAN5_CANFD3_user,
        CANNM_USER_TX_PDU_2,
        PDUR_CANNM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CanNm_CAN2_CANFD6_user,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_CAN2_CANFD6_user,
        CANNM_USER_TX_PDU_1,
        PDUR_CANNM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CanNm_CAN1_CANFD8_user,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_CAN1_CANFD8_user,
        CANNM_USER_TX_PDU_0,
        PDUR_CANNM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_10_Torque_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_10_Torque_CHA,
        CANIF_TXPDU_VCU_10_Torque_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BCM_4_CruiseSw_PM_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_BCM_4_CruiseSw_PM_CHA,
        CANIF_TXPDU_BCM_4_CruiseSw_PM_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CCU_VehInfo_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_CCU_VehInfo_CHA,
        CANIF_TXPDU_CCU_VehInfo_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_D_Status_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_D_Status_CHA,
        CANIF_TXPDU_VCU_D_Status_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BCM_B_Package_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_BCM_B_Package_CHA,
        CANIF_TXPDU_BCM_B_Package_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_3_State_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_3_State_CHA,
        CANIF_TXPDU_AC_3_State_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_FCM_D_CHA_2_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_FCM_D_CHA,
        CANIF_TXPDU_FCM_D_CHA_2_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_FCM_D_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCM_D_CHA,
        COM_RXPDU_COM_FCM_D_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_FCM_B_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCM_B_CHA,
        COM_RXPDU_COM_FCM_B_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_FCM_A_CHA_2_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_FCM_A_CHA,
        CANIF_TXPDU_FCM_A_CHA_2_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_FCM_A_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCM_A_CHA,
        COM_RXPDU_COM_FCM_A_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_FCM_23_Obj0109_2_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_FCM_23_Obj0109_CHA,
        CANIF_TXPDU_FCM_23_Obj0109_2_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_FCM_23_Obj0109_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCM_23_Obj0109_CHA,
        COM_RXPDU_COM_FCM_23_Obj0109_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_FCM_24_Obj1018_CHA_2_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_FCM_24_Obj1018_CHA,
        CANIF_TXPDU_FCM_24_Obj1018_CHA_2_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_FCM_24_Obj1018_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCM_24_Obj1018_CHA,
        COM_RXPDU_COM_FCM_24_Obj1018_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_FCM_25_Line123_CHA_2_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_FCM_25_Line123_CHA,
        CANIF_TXPDU_FCM_25_Line123_CHA_2_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_FCM_25_Line123_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCM_25_Line123_CHA,
        COM_RXPDU_COM_FCM_25_Line123_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_FCM_ObjTrackID_CHA_2_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_FCM_ObjTrackID_CHA,
        CANIF_TXPDU_FCM_ObjTrackID_CHA_2_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_FCM_ObjTrackID_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCM_ObjTrackID_CHA,
        COM_RXPDU_COM_FCM_ObjTrackID_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ESC_WheelPulseTime_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ESC_WheelPulseTime_CHA,
        COM_RXPDU_COM_ESC_WheelPulseTime_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ESC_A_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ESC_A_CHA,
        COM_RXPDU_COM_ESC_A_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ESC_7_FuncStatus_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_ESC_7_FuncStatus_CHA,
        CANIF_TXPDU_ESC_7_FuncStatus_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ESC_7_FuncStatus_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_ESC_7_FuncStatus_CHA,
        CANIF_TXPDU_ESC_7_FuncStatus_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ESC_7_FuncStatus_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_ESC_7_FuncStatus_CHA,
        CANIF_TXPDU_ESC_7_FuncStatus_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ESC_7_FuncStatus_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ESC_7_FuncStatus_CHA,
        COM_RXPDU_COM_ESC_7_FuncStatus_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_EHB_B_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_EHB_B_CHA,
        COM_RXPDU_COM_EHB_B_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_EHB_A_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_EHB_A_CHA,
        CANIF_TXPDU_EHB_A_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_EHB_A_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_EHB_A_CHA,
        CANIF_TXPDU_EHB_A_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_EHB_A_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_EHB_A_CHA,
        COM_RXPDU_COM_EHB_A_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_SRS_2_YRSOriginalSts_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_SRS_2_YRSOriginalSts_CHA,
        COM_RXPDU_COM_SRS_2_YRSOriginalSts_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_SRS_3_YRSActualSts_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_SRS_3_YRSActualSts_CHA,
        COM_RXPDU_COM_SRS_3_YRSActualSts_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_SRS_1_Status_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_SRS_1_Status_CHA,
        CANIF_TXPDU_SRS_1_Status_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_SRS_1_Status_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_SRS_1_Status_CHA,
        CANIF_TXPDU_SRS_1_Status_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_SRS_1_Status_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_SRS_1_Status_CHA,
        COM_RXPDU_COM_SRS_1_Status_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_EPS_3_LatDrvAndEPSSts_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_EPS_3_LatDrvAndEPSSts_CHA,
        COM_RXPDU_COM_EPS_3_LatDrvAndEPSSts_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_EPS_2_StrWhlAng_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_EPS_2_StrWhlAng_CHA,
        COM_RXPDU_COM_EPS_2_StrWhlAng_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_EPS_1_Status_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_EPS_1_Status_CHA,
        CANIF_TXPDU_EPS_1_Status_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_EPS_1_Status_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_EPS_1_Status_CHA,
        COM_RXPDU_COM_EPS_1_Status_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_PP_InformAndStatus_CHA_2_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_PP_InformAndStatus_CHA,
        CANIF_TXPDU_PP_InformAndStatus_CHA_2_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_PP_InformAndStatus_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_PP_InformAndStatus_CHA,
        COM_RXPDU_COM_PP_InformAndStatus_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CRRR_A_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CRRR_A_CHA,
        CANIF_TXPDU_CRRR_A_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CRRR_A_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CRRR_A_CHA,
        COM_RXPDU_COM_CRRR_A_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CRRR_10_Posn_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CRRR_10_Posn_CHA,
        COM_RXPDU_COM_CRRR_10_Posn_CHA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CCU_VehInfo_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_CCU_VehInfo_BOD,
        CANIF_TXPDU_CCU_VehInfo_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_ACStatuts_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_ACStatuts_BOD,
        CANIF_TXPDU_AC_ACStatuts_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_COMP_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_COMP_BOD,
        CANIF_TXPDU_AC_COMP_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_7_DrvRange_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_7_DrvRange_BOD,
        CANIF_TXPDU_VCU_7_DrvRange_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_1_Command_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_1_Command_BOD,
        CANIF_TXPDU_AC_1_Command_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_HVCH_Command_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_HVCH_Command_BOD,
        CANIF_TXPDU_HVCH_Command_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_3_State_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_3_State_BOD,
        CANIF_TXPDU_AC_3_State_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_2_State_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_2_State_BOD,
        CANIF_TXPDU_AC_2_State_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_8_status_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_8_status_BOD,
        CANIF_TXPDU_AC_8_status_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BCM_ESCLCommand_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_BCM_ESCLCommand_BOD,
        CANIF_TXPDU_BCM_ESCLCommand_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TMS_LINTestData1_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TMS_LINTestData1_BOD,
        CANIF_TXPDU_TMS_LINTestData1_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TMS_LINTestData2_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TMS_LINTestData2_BOD,
        CANIF_TXPDU_TMS_LINTestData2_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TMS_LINTestData3_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TMS_LINTestData3_BOD,
        CANIF_TXPDU_TMS_LINTestData3_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_CCP_PanelStatus_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CCP_PanelStatus_BOD,
        COM_RXPDU_COM_CCP_PanelStatus_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CCP_PanelStatus_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CCP_PanelStatus_BOD,
        CANIF_TXPDU_CCP_PanelStatus_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_SCS_RiSwitchSts_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_SCS_RiSwitchSts_BOD,
        COM_RXPDU_COM_SCS_RiSwitchSts_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_SCS_RiSwitchSts_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_SCS_RiSwitchSts_BOD,
        CANIF_TXPDU_SCS_RiSwitchSts_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_SCS_RiSwitchSts_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_SCS_RiSwitchSts_BOD,
        CANIF_TXPDU_SCS_RiSwitchSts_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_SCS_LeSwitchSts_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_SCS_LeSwitchSts_BOD,
        COM_RXPDU_COM_SCS_LeSwitchSts_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_SCS_LeSwitchSts_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_SCS_LeSwitchSts_BOD,
        CANIF_TXPDU_SCS_LeSwitchSts_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_SCS_LeSwitchSts_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_SCS_LeSwitchSts_BOD,
        CANIF_TXPDU_SCS_LeSwitchSts_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_TPMS_Info_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_TPMS_Info_BOD,
        COM_RXPDU_COM_TPMS_Info_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TPMS_Info_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_TPMS_Info_BOD,
        CANIF_TXPDU_TPMS_Info_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TPMS_Info_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_TPMS_Info_BOD,
        CANIF_TXPDU_TPMS_Info_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ESCL_ESCLStatus_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ESCL_ESCLStatus_BOD,
        COM_RXPDU_COM_ESCL_ESCLStatus_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_AVAS_State_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_AVAS_State_BOD,
        COM_RXPDU_COM_AVAS_State_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AVAS_State_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_AVAS_State_BOD,
        CANIF_TXPDU_AVAS_State_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_COMP_AC_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COMP_AC_BOD,
        COM_RXPDU_COM_COMP_AC_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ACCM_Version_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ACCM_Version_BOD,
        COM_RXPDU_COM_ACCM_Version_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_HVCH_Status1_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HVCH_Status1_BOD,
        COM_RXPDU_COM_HVCH_Status1_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_HVCH_Status2_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HVCH_Status2_BOD,
        COM_RXPDU_COM_HVCH_Status2_BOD,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_3_OprtCmd_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_3_OprtCmd_EPT,
        CANIF_TXPDU_VCU_3_OprtCmd_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_4_ChrgCmd_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_4_ChrgCmd_EPT,
        CANIF_TXPDU_VCU_4_ChrgCmd_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_B_AcclPedal_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_B_AcclPedal_EPT,
        CANIF_TXPDU_VCU_B_AcclPedal_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_1_InvCmd_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_1_InvCmd_EPT,
        CANIF_TXPDU_VCU_1_InvCmd_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_0_Value_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_0_Value_EPT,
        CANIF_TXPDU_VCU_0_Value_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_C_OprtCmd_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_C_OprtCmd_EPT,
        CANIF_TXPDU_VCU_C_OprtCmd_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CCU_VehInfo_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_CCU_VehInfo_EPT,
        CANIF_TXPDU_CCU_VehInfo_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BCM_IMMOAuthResp1_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_BCM_IMMOAuthResp1_EPT,
        CANIF_TXPDU_BCM_IMMOAuthResp1_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_1_MainState_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_1_MainState_EPT,
        COM_RXPDU_COM_BMS_1_MainState_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BMS_1_MainState_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_BMS_1_MainState_EPT,
        CANIF_TXPDU_BMS_1_MainState_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_2_BatState_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_2_BatState_EPT,
        COM_RXPDU_COM_BMS_2_BatState_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BMS_2_BatState_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_BMS_2_BatState_EPT,
        CANIF_TXPDU_BMS_2_BatState_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_3_DC_ChargeState_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_3_DC_ChargeState_EPT,
        COM_RXPDU_COM_BMS_3_DC_ChargeState_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_4_AC_ChargeState_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_4_AC_ChargeState_EPT,
        COM_RXPDU_COM_BMS_4_AC_ChargeState_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_10_DC_ChargeStates_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_10_DC_ChargeStates_EPT,
        COM_RXPDU_COM_BMS_10_DC_ChargeStates_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BMS_10_DC_ChargeStates_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_BMS_10_DC_ChargeStates_EPT,
        CANIF_TXPDU_BMS_10_DC_ChargeStates_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_5_BatTemp_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_5_BatTemp_EPT,
        COM_RXPDU_COM_BMS_5_BatTemp_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_6_DischrgRecup_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_6_DischrgRecup_EPT,
        COM_RXPDU_COM_BMS_6_DischrgRecup_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_7_CellVolt_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_7_CellVolt_EPT,
        COM_RXPDU_COM_BMS_7_CellVolt_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_8_TempVoltLimit_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_8_TempVoltLimit_EPT,
        COM_RXPDU_COM_BMS_8_TempVoltLimit_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_9_BattInfo_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_9_BattInfo_EPT,
        COM_RXPDU_COM_BMS_9_BattInfo_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_A_GB_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_A_GB_EPT,
        COM_RXPDU_COM_BMS_A_GB_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BMS_A_GB_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_BMS_A_GB_EPT,
        CANIF_TXPDU_BMS_A_GB_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_B_GB_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_B_GB_EPT,
        COM_RXPDU_COM_BMS_B_GB_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BMS_B_GB_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_BMS_B_GB_EPT,
        CANIF_TXPDU_BMS_B_GB_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_C_GB_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_C_GB_EPT,
        COM_RXPDU_COM_BMS_C_GB_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BMS_C_GB_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_BMS_C_GB_EPT,
        CANIF_TXPDU_BMS_C_GB_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_BMS_D_GB_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BMS_D_GB_EPT,
        COM_RXPDU_COM_BMS_D_GB_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BMS_D_GB_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_BMS_D_GB_EPT,
        CANIF_TXPDU_BMS_D_GB_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPU_OBC_3_CP_CC_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_IPU_OBC_3_CP_CC_EPT,
        COM_RXPDU_COM_IPU_OBC_3_CP_CC_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPU_DCC_1_State_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_IPU_DCC_1_State_EPT,
        COM_RXPDU_COM_IPU_DCC_1_State_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPU_OBC_1_State_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_IPU_OBC_1_State_EPT,
        COM_RXPDU_COM_IPU_OBC_1_State_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_IPU_OBC_1_State_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_IPU_OBC_1_State_EPT,
        CANIF_TXPDU_IPU_OBC_1_State_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPU_DCC_2_ChrgInValue_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_IPU_DCC_2_ChrgInValue_EPT,
        COM_RXPDU_COM_IPU_DCC_2_ChrgInValue_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPU_OBC_2_Inlet_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_IPU_OBC_2_Inlet_EPT,
        COM_RXPDU_COM_IPU_OBC_2_Inlet_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_IPU_OBC_4_state_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_IPU_OBC_4_state_EPT,
        COM_RXPDU_COM_IPU_OBC_4_state_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_IPU_OBC_4_state_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_IPU_OBC_4_state_EPT,
        CANIF_TXPDU_IPU_OBC_4_state_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_INV_1_Value_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_INV_1_Value_EPT,
        COM_RXPDU_COM_INV_1_Value_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_INV_1_Value_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_INV_1_Value_EPT,
        CANIF_TXPDU_INV_1_Value_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_INV_2_Value_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_INV_2_Value_EPT,
        COM_RXPDU_COM_INV_2_Value_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_INV_3_Value_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_INV_3_Value_EPT,
        COM_RXPDU_COM_INV_3_Value_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_INV_4_Value_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_INV_4_Value_EPT,
        COM_RXPDU_COM_INV_4_Value_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_INV_5_Values_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_INV_5_Values_EPT,
        COM_RXPDU_COM_INV_5_Values_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_INV_IMMO_Req_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_INV_IMMO_Req_EPT,
        COM_RXPDU_COM_INV_IMMO_Req_EPT,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_DispInfo_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_DispInfo_BAC,
        CANIF_TXPDU_VCU_DispInfo_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CCU_VehInfo_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_CCU_VehInfo_BAC,
        CANIF_TXPDU_CCU_VehInfo_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_VCU_D_Status_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_VCU_D_Status_BAC,
        CANIF_TXPDU_VCU_D_Status_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_ACStatuts_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_ACStatuts_BAC,
        CANIF_TXPDU_AC_ACStatuts_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BCM_B_Package_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_BCM_B_Package_BAC,
        CANIF_TXPDU_BCM_B_Package_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_3_State_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_AC_3_State_BAC,
        CANIF_TXPDU_AC_3_State_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BCM_HFSData_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_BCM_HFSData_BAC,
        CANIF_TXPDU_BCM_HFSData_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ICU_Info_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ICU_Info_BAC,
        COM_RXPDU_COM_ICU_Info_BAC,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ICU_Info_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_ICU_Info_BAC,
        CANIF_TXPDU_ICU_Info_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_HU_B_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HU_B_BAC,
        COM_RXPDU_COM_HU_B_BAC,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_HU_A_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HU_A_BAC,
        COM_RXPDU_COM_HU_A_BAC,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_HU_A_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_HU_A_BAC,
        CANIF_TXPDU_HU_A_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_ICU_2_Odo_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_ICU_2_Odo_BAC,
        COM_RXPDU_COM_ICU_2_Odo_BAC,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ICU_2_Odo_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_ICU_2_Odo_BAC,
        CANIF_TXPDU_ICU_2_Odo_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ICU_2_Odo_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_ICU_2_Odo_BAC,
        CANIF_TXPDU_ICU_2_Odo_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_ICU_2_Odo_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_ICU_2_Odo_BAC,
        CANIF_TXPDU_ICU_2_Odo_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_HU_C_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HU_C_BAC,
        COM_RXPDU_COM_HU_C_BAC,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_HU_C_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_HU_C_BAC,
        CANIF_TXPDU_HU_C_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_TBOX_BJS_Time_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_TBOX_BJS_Time_BAC,
        COM_RXPDU_COM_TBOX_BJS_Time_BAC,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TBOX_BJS_Time_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_TBOX_BJS_Time_BAC,
        CANIF_TXPDU_TBOX_BJS_Time_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TBOX_BJS_Time_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_TBOX_BJS_Time_BAC,
        CANIF_TXPDU_TBOX_BJS_Time_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TBOX_BJS_Time_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_TBOX_BJS_Time_BAC,
        CANIF_TXPDU_TBOX_BJS_Time_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_CCU_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_CCU_OBD,
        DCM_DCM_RX_Phy_Diag_PhyReq_CCU_OBD,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_DCM_RX_Diag_FuncReq_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_OBD,
        DCM_DCM_RX_Diag_FuncReq_OBD,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANTP_TX_Diag_Resp_CCU_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD,
        CANTP_CANTP_TX_Diag_Resp_CCU_OBD,
        PDUR_CANTP,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_MCU_RX_EPT,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_MCU_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_MCU_RX_EPT,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_MCU_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_BMS_RX_EPT,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_BMS_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_BMS_RX_EPT,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_BMS_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_ESC_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESC_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_ESC_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESC_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_EHB_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EHB_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_EHB_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EHB_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_EPS_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EPS_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_EPS_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EPS_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_PP_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PP_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_PP_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PP_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_FCM_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FCM_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_FCM_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FCM_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_FRM_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FRM_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_FRM_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FRM_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRL_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRL_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRR_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRR_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_SRS_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SRS_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_SRS_RX_CHA,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SRS_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD,
        CANIF_TXPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_FuncReq_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD,
        CANIF_TXPDU_CANIF_TX_Diag_FuncReq_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD,
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD,
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD,
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESC_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_EHB_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_EPS_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_PP_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_FCM_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_FRM_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_SRS_TX_CHA,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_MCU_TX_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_BMS_TX_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD,
        CANIF_TXPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_PTC_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PTC_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_PTC_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PTC_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_SCS_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SCS_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_SCS_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SCS_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_CCP_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCP_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_CCP_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCP_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_AVAS_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_AVAS_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESCL_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESCL_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ACCM_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ACCM_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_TPMS_BAC,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_TPMS_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CDCICU_OBD,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_Resp_CDCICU_BAC,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CDCICU_OBD,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_BAC,
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_BAC,
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_BAC,
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_FRM_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        TRUE,
        TRUE,
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC,
        CANIF_TXPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_HP_EXV_Cmd_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN1,
        LINIF_TXPDU_HP_EXV_Cmd_LIN1,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_HP_EXV__Rsp_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HP_EXV__Rsp_LIN1,
        COM_RXPDU_Com_HP_EXV__Rsp_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BAT_EXV_Cmd_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN1,
        LINIF_TXPDU_BAT_EXV_Cmd_LIN1,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN1,
        COM_RXPDU_Com_BAT_EXV_Rsp_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_EXV_Cmd_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN1,
        LINIF_TXPDU_AC_EXV_Cmd_LIN1,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_AC_EXV_Rsp_LIN1,
        COM_RXPDU_Com_AC_EXV_Rsp_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_MCV_Cmd_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_MCV_Cmd_LIN1,
        LINIF_TXPDU_MCV_Cmd_LIN1,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_MCV_Sts_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MCV_Sts_LIN1,
        COM_RXPDU_Com_MCV_Sts_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BCV_Cmd_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_BCV_Cmd_LIN1,
        LINIF_TXPDU_BCV_Cmd_LIN1,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_BCV_Sts_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BCV_Sts_LIN1,
        COM_RXPDU_Com_BCV_Sts_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_PMP_Cmd_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_PMP_Cmd_LIN1,
        LINIF_TXPDU_PMP_Cmd_LIN1,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_MotPMP_Sts_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MotPMP_Sts_LIN1,
        COM_RXPDU_Com_MotPMP_Sts_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_BatPMP_Sts_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BatPMP_Sts_LIN1,
        COM_RXPDU_Com_BatPMP_Sts_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_AcPMP_Sts_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_AcPMP_Sts_LIN1,
        COM_RXPDU_Com_AcPMP_Sts_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_HP_EXV_Version_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HP_EXV_Version_LIN1,
        COM_RXPDU_Com_HP_EXV_Version_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_Bat_EXV_Version_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Bat_EXV_Version_LIN1,
        COM_RXPDU_Com_Bat_EXV_Version_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_MCV_Version_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MCV_Version_LIN1,
        COM_RXPDU_Com_MCV_Version_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_BCV_Version_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BCV_Version_LIN1,
        COM_RXPDU_Com_BCV_Version_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_AcPMP_Version_LIN1,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_AcPMP_Version_LIN1,
        COM_RXPDU_Com_AcPMP_Version_LIN1,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_AC_EXV_Cmd_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN2,
        LINIF_TXPDU_AC_EXV_Cmd_LIN2,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_AC_EXV_Rsp_LIN2,
        COM_RXPDU_Com_AC_EXV_Rsp_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_AcPMP_Sts_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_AcPMP_Sts_LIN2,
        COM_RXPDU_Com_AcPMP_Sts_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_AcPMP_Version_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_AcPMP_Version_LIN2,
        COM_RXPDU_Com_AcPMP_Version_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_BAT_EXV_Cmd_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN2,
        LINIF_TXPDU_BAT_EXV_Cmd_LIN2,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN2,
        COM_RXPDU_Com_BAT_EXV_Rsp_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_BatPMP_Sts_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_BatPMP_Sts_LIN2,
        COM_RXPDU_Com_BatPMP_Sts_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_Bat_EXV_Version_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Bat_EXV_Version_LIN2,
        COM_RXPDU_Com_Bat_EXV_Version_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_C3WV_Cmd_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_C3WV_Cmd_LIN2,
        LINIF_TXPDU_C3WV_Cmd_LIN2,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_C3WV_Sts_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_C3WV_Sts_LIN2,
        COM_RXPDU_Com_C3WV_Sts_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_C5WV_Cmd_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_C5WV_Cmd_LIN2,
        LINIF_TXPDU_C5WV_Cmd_LIN2,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_C5WV_Sts_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_C5WV_Sts_LIN2,
        COM_RXPDU_Com_C5WV_Sts_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_HP_EXV_Cmd_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN2,
        LINIF_TXPDU_HP_EXV_Cmd_LIN2,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_HP_EXV_Rsp_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HP_EXV_Rsp_LIN2,
        COM_RXPDU_Com_HP_EXV_Rsp_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_HP_EXV_Version_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_HP_EXV_Version_LIN2,
        COM_RXPDU_Com_HP_EXV_Version_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_MotPMP_Sts_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MotPMP_Sts_LIN2,
        COM_RXPDU_Com_MotPMP_Sts_LIN2,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_PMP_Cmd_LIN2,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_PMP_Cmd_LIN2,
        LINIF_TXPDU_PMP_Cmd_LIN2,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CCU_FCLCommand_LIN3,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_CCU_FCLCommand_LIN3,
        LINIF_TXPDU_CCU_FCLCommand_LIN3,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_FCLL_Status_LIN3,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCLL_Status_LIN3,
        COM_RXPDU_Com_FCLL_Status_LIN3,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_FCLR_Status_LIN3,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_FCLR_Status_LIN3,
        COM_RXPDU_Com_FCLR_Status_LIN3,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_Frm_InterlockStatus_LIN3,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Frm_InterlockStatus_LIN3,
        COM_RXPDU_Com_Frm_InterlockStatus_LIN3,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Com_Frm_InterlockToVehicle_LIN3,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Frm_InterlockToVehicle_LIN3,
        COM_RXPDU_Com_Frm_InterlockToVehicle_LIN3,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_Frm_VehicleToInterlock_LIN3,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_Frm_VehicleToInterlock_LIN3,
        LINIF_TXPDU_Frm_VehicleToInterlock_LIN3,
        PDUR_LINIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_BAC,
        DCM_DCM_RX_Phy_Diag_PhyReq_BAC,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_DCM_RX_Diag_FuncReq_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_BAC,
        DCM_DCM_RX_Diag_FuncReq_BAC,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANTP_TX_Diag_Resp_BAC,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_DCM_TX_Diag_Resp_BAC,
        CANTP_CANTP_TX_Diag_Resp_BAC,
        PDUR_CANTP,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CanNm_CAN6_CANFD5_user,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_Com_CAN6_CANFD5_user,
        CANNM_USER_TX_PDU_3,
        PDUR_CANNM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD_2A,
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRSrcPduType,PDUR_CONST)
PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
    {
        PDUR_SRCPDU_COM_INCA_CRO_XCP,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_INCA_CRO_XCP,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_TMSR_DTO_XCP,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_TMSR_DTO_XCP,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_Com_CAN5_CANFD3_user,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_CAN5_CANFD3_user,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_Com_CAN2_CANFD6_user,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_CAN2_CANFD6_user,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_Com_CAN1_CANFD8_user,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_CAN1_CANFD8_user,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_10_Torque_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_10_Torque_CHA,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_BCM_4_CruiseSw_PM_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_BCM_4_CruiseSw_PM_CHA,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_CCU_VehInfo_CHA,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_D_Status_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_D_Status_CHA,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_BCM_B_Package_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_BCM_B_Package_CHA,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_3_State_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_3_State_CHA,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_FCM_D_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_FCM_D_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_FCM_B_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_FCM_B_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_FCM_A_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_FCM_A_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_FCM_23_Obj0109_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_FCM_23_Obj0109_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_FCM_24_Obj1018_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_FCM_24_Obj1018_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_FCM_25_Line123_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_FCM_25_Line123_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_FCM_ObjTrackID_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_FCM_ObjTrackID_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ESC_WheelPulseTime_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ESC_WheelPulseTime_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ESC_A_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ESC_A_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ESC_7_FuncStatus_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ESC_7_FuncStatus_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_EHB_B_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_EHB_B_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_EHB_A_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_EHB_A_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_SRS_2_YRSOriginalSts_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_SRS_2_YRSOriginalSts_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_SRS_3_YRSActualSts_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_SRS_3_YRSActualSts_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_SRS_1_Status_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_SRS_1_Status_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_EPS_3_LatDrvAndEPSSts_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_EPS_3_LatDrvAndEPSSts_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_EPS_2_StrWhlAng_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_EPS_2_StrWhlAng_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_EPS_1_Status_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_EPS_1_Status_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_PP_InformAndStatus_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_PP_InformAndStatus_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CRRR_A_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CRRR_A_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CRRR_10_Posn_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CRRR_10_Posn_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_CCU_VehInfo_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_ACStatuts_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_ACStatuts_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_COMP_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_COMP_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_7_DrvRange_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_7_DrvRange_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_1_Command_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_1_Command_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_HVCH_Command_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_HVCH_Command_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_3_State_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_3_State_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_2_State_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_2_State_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_8_status_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_8_status_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_BCM_ESCLCommand_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_BCM_ESCLCommand_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TMS_LINTestData1_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TMS_LINTestData1_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TMS_LINTestData2_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TMS_LINTestData2_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TMS_LINTestData3_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TMS_LINTestData3_BOD,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_CCP_PanelStatus_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CCP_PanelStatus_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_SCS_RiSwitchSts_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_SCS_RiSwitchSts_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_SCS_LeSwitchSts_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_SCS_LeSwitchSts_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_TPMS_Info_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_TPMS_Info_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ESCL_ESCLStatus_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ESCL_ESCLStatus_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_AVAS_State_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_AVAS_State_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_COMP_AC_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_COMP_AC_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ACCM_Version_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ACCM_Version_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_HVCH_Status1_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_HVCH_Status1_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_HVCH_Status2_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_HVCH_Status2_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_COM_VCU_3_OprtCmd_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_3_OprtCmd_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_4_ChrgCmd_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_4_ChrgCmd_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_B_AcclPedal_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_B_AcclPedal_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_1_InvCmd_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_1_InvCmd_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_0_Value_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_0_Value_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_C_OprtCmd_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_C_OprtCmd_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_CCU_VehInfo_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_BCM_IMMOAuthResp1_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_BCM_IMMOAuthResp1_EPT,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_BMS_1_MainState_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_1_MainState_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_2_BatState_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_2_BatState_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_3_DC_ChargeState_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_3_DC_ChargeState_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_4_AC_ChargeState_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_4_AC_ChargeState_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_10_DC_ChargeStates_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_10_DC_ChargeStates_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_5_BatTemp_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_5_BatTemp_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_6_DischrgRecup_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_6_DischrgRecup_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_7_CellVolt_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_7_CellVolt_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_8_TempVoltLimit_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_8_TempVoltLimit_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_9_BattInfo_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_9_BattInfo_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_A_GB_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_A_GB_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_B_GB_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_B_GB_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_C_GB_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_C_GB_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_BMS_D_GB_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_BMS_D_GB_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPU_OBC_3_CP_CC_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPU_OBC_3_CP_CC_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPU_DCC_1_State_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPU_DCC_1_State_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPU_OBC_1_State_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPU_OBC_1_State_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPU_DCC_2_ChrgInValue_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPU_DCC_2_ChrgInValue_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPU_OBC_2_Inlet_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPU_OBC_2_Inlet_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_IPU_OBC_4_state_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_IPU_OBC_4_state_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_INV_1_Value_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_INV_1_Value_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_INV_2_Value_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_INV_2_Value_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_INV_3_Value_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_INV_3_Value_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_INV_4_Value_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_INV_4_Value_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_INV_5_Values_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_INV_5_Values_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_INV_IMMO_Req_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_INV_IMMO_Req_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_COM_VCU_DispInfo_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_DispInfo_BAC,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_CCU_VehInfo_BAC,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_VCU_D_Status_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_VCU_D_Status_BAC,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_ACStatuts_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_ACStatuts_BAC,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_BCM_B_Package_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_BCM_B_Package_BAC,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_AC_3_State_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_AC_3_State_BAC,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_BCM_HFSData_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_BCM_HFSData_BAC,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_ICU_Info_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ICU_Info_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_HU_B_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_HU_B_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_HU_A_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_HU_A_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_ICU_2_Odo_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_ICU_2_Odo_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_HU_C_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_HU_C_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_TBOX_BJS_Time_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_TBOX_BJS_Time_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_CCU_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CANTP_RX_Diag_PhyReq_CCU_OBD,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CANTP_RX_Diag_FuncReq_OBD,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        DCM_DCM_TX_Diag_Resp_CCU_OBD,
        PDUR_DCM,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_MCU_RX_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_MCU_RX_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_BMS_RX_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_BMS_RX_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ESC_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_ESC_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_EHB_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_EHB_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_EPS_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_EPS_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_PP_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_PP_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_FCM_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_FCM_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_FRM_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_FRM_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_SRS_RX_CHA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_SRS_RX_CHA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_FuncReq_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FRM_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_PTC_RX_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_PTC_RX_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_SCS_RX_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_SCS_RX_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CCP_RX_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_CCP_RX_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_Resp_CDCICU_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_Resp_CDCICU_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_FuncReq_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FRM_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_HP_EXV_Cmd_LIN1,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_HP_EXV__Rsp_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_BAT_EXV_Cmd_LIN1,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_AC_EXV_Cmd_LIN1,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_AC_EXV_Rsp_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_MCV_Cmd_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_MCV_Cmd_LIN1,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_MCV_Sts_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_BCV_Cmd_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_BCV_Cmd_LIN1,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_BCV_Sts_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_PMP_Cmd_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_PMP_Cmd_LIN1,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_MotPMP_Sts_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_BatPMP_Sts_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_AcPMP_Sts_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_HP_EXV_Version_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Bat_EXV_Version_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_MCV_Version_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_BCV_Version_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_AcPMP_Version_LIN1,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_AC_EXV_Cmd_LIN2,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_AC_EXV_Rsp_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_AcPMP_Sts_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_AcPMP_Version_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_BAT_EXV_Cmd_LIN2,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_BatPMP_Sts_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Bat_EXV_Version_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_C3WV_Cmd_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_C3WV_Cmd_LIN2,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_C3WV_Sts_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_C5WV_Cmd_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_C5WV_Cmd_LIN2,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_C5WV_Sts_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_HP_EXV_Cmd_LIN2,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_HP_EXV_Rsp_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_HP_EXV_Version_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_MotPMP_Sts_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_PMP_Cmd_LIN2,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_PMP_Cmd_LIN2,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_Com_CCU_FCLCommand_LIN3,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_CCU_FCLCommand_LIN3,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_FCLL_Status_LIN3,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_FCLR_Status_LIN3,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Frm_InterlockStatus_LIN3,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Frm_InterlockToVehicle_LIN3,
        TRUE,
        PDUR_UNUSED_UINT16,
        0xffff,
        PDUR_LINIF,

    },
    {
        PDUR_SRCPDU_Com_Frm_VehicleToInterlock_LIN3,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_Frm_VehicleToInterlock_LIN3,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CANTP_RX_Diag_PhyReq_BAC,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CANTP_RX_Diag_FuncReq_BAC,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_DCM_TX_Diag_Resp_BAC,
        TRUE,
        PDUR_UNUSED_UINT16,
        DCM_DCM_TX_Diag_Resp_BAC,
        PDUR_DCM,

    },
    {
        PDUR_SRCPDU_Com_CAN6_CANFD5_user,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_Com_CAN6_CANFD5_user,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD_2A,
        TRUE,
        PDUR_UNUSED_UINT16,
        DCM_DCM_TX_Diag_Resp_CCU_OBD_2A,
        PDUR_DCM,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

/* PRQA S 0779,0779 ++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_INCA_CRO[1] =
{
    PDUR_DESTPDU_INCA_CRO_XCP,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TMSR_DTO[1] =
{
    PDUR_DESTPDU_COM_TMSR_DTO_XCP,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_NM_CAN5_CANFD3[1] =
{
    PDUR_DESTPDU_CanNm_CAN5_CANFD3_user,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_NM_CAN2_CANFD6[1] =
{
    PDUR_DESTPDU_CanNm_CAN2_CANFD6_user,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_NM_CAN1_CANFD8[1] =
{
    PDUR_DESTPDU_CanNm_CAN1_CANFD8_user,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_10_Torque_CHA[1] =
{
    PDUR_DESTPDU_VCU_10_Torque_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BCM_4_CruiseSw_PM_CHA[1] =
{
    PDUR_DESTPDU_BCM_4_CruiseSw_PM_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CCU_VehInfo_CHA[1] =
{
    PDUR_DESTPDU_CCU_VehInfo_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_D_Status_CHA[1] =
{
    PDUR_DESTPDU_VCU_D_Status_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BCM_B_Package_CHA[1] =
{
    PDUR_DESTPDU_BCM_B_Package_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_3_State_CHA[1] =
{
    PDUR_DESTPDU_AC_3_State_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_FCM_D_CHA[2] =
{
    PDUR_DESTPDU_FCM_D_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_D_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_FCM_B_CHA[1] =
{
    PDUR_DESTPDU_COM_FCM_B_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_FCM_A_CHA[2] =
{
    PDUR_DESTPDU_FCM_A_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_A_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_FCM_23_Obj0109_CHA[2] =
{
    PDUR_DESTPDU_FCM_23_Obj0109_2_BAC,
    PDUR_DESTPDU_COM_FCM_23_Obj0109_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_FCM_24_Obj1018_CHA[2] =
{
    PDUR_DESTPDU_FCM_24_Obj1018_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_24_Obj1018_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_FCM_25_Line123_CHA[2] =
{
    PDUR_DESTPDU_FCM_25_Line123_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_25_Line123_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_FCM_ObjTrackID_CHA[2] =
{
    PDUR_DESTPDU_FCM_ObjTrackID_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_ObjTrackID_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ESC_WheelPulseTime_CHA[1] =
{
    PDUR_DESTPDU_COM_ESC_WheelPulseTime_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ESC_A_CHA[1] =
{
    PDUR_DESTPDU_COM_ESC_A_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ESC_7_FuncStatus_CHA[4] =
{
    PDUR_DESTPDU_ESC_7_FuncStatus_EPT,
    PDUR_DESTPDU_ESC_7_FuncStatus_BOD,
    PDUR_DESTPDU_ESC_7_FuncStatus_BAC,
    PDUR_DESTPDU_COM_ESC_7_FuncStatus_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_EHB_B_CHA[1] =
{
    PDUR_DESTPDU_COM_EHB_B_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_EHB_A_CHA[3] =
{
    PDUR_DESTPDU_EHB_A_BOD,
    PDUR_DESTPDU_EHB_A_BAC,
    PDUR_DESTPDU_COM_EHB_A_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_SRS_2_YRSOriginalSts_CHA[1] =
{
    PDUR_DESTPDU_COM_SRS_2_YRSOriginalSts_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_SRS_3_YRSActualSts_CHA[1] =
{
    PDUR_DESTPDU_COM_SRS_3_YRSActualSts_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_SRS_1_Status_CHA[3] =
{
    PDUR_DESTPDU_SRS_1_Status_EPT,
    PDUR_DESTPDU_SRS_1_Status_BAC,
    PDUR_DESTPDU_COM_SRS_1_Status_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_EPS_3_LatDrvAndEPSSts_CHA[1] =
{
    PDUR_DESTPDU_COM_EPS_3_LatDrvAndEPSSts_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_EPS_2_StrWhlAng_CHA[1] =
{
    PDUR_DESTPDU_COM_EPS_2_StrWhlAng_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_EPS_1_Status_CHA[2] =
{
    PDUR_DESTPDU_EPS_1_Status_BAC,
    PDUR_DESTPDU_COM_EPS_1_Status_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_PP_InformAndStatus_CHA[2] =
{
    PDUR_DESTPDU_PP_InformAndStatus_CHA_2_BAC,
    PDUR_DESTPDU_COM_PP_InformAndStatus_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CRRR_A_CHA[2] =
{
    PDUR_DESTPDU_CRRR_A_BAC,
    PDUR_DESTPDU_COM_CRRR_A_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CRRR_10_Posn_CHA[1] =
{
    PDUR_DESTPDU_COM_CRRR_10_Posn_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CCU_VehInfo_BOD[1] =
{
    PDUR_DESTPDU_CCU_VehInfo_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_ACStatuts_BOD[1] =
{
    PDUR_DESTPDU_AC_ACStatuts_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_COMP_BOD[1] =
{
    PDUR_DESTPDU_AC_COMP_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_7_DrvRange_BOD[1] =
{
    PDUR_DESTPDU_VCU_7_DrvRange_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_1_Command_BOD[1] =
{
    PDUR_DESTPDU_AC_1_Command_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HVCH_Command_BOD[1] =
{
    PDUR_DESTPDU_HVCH_Command_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_3_State_BOD[1] =
{
    PDUR_DESTPDU_AC_3_State_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_2_State_BOD[1] =
{
    PDUR_DESTPDU_AC_2_State_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_8_status_BOD[1] =
{
    PDUR_DESTPDU_AC_8_status_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BCM_ESCLCommand_BOD[1] =
{
    PDUR_DESTPDU_BCM_ESCLCommand_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TMS_LINTestData1_BOD[1] =
{
    PDUR_DESTPDU_TMS_LINTestData1_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TMS_LINTestData2_BOD[1] =
{
    PDUR_DESTPDU_TMS_LINTestData2_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TMS_LINTestData3_BOD[1] =
{
    PDUR_DESTPDU_TMS_LINTestData3_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CCP_PanelStatus_BOD[2] =
{
    PDUR_DESTPDU_COM_CCP_PanelStatus_BOD,
    PDUR_DESTPDU_CCP_PanelStatus_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_SCS_RiSwitchSts_BOD[3] =
{
    PDUR_DESTPDU_COM_SCS_RiSwitchSts_BOD,
    PDUR_DESTPDU_SCS_RiSwitchSts_CHA,
    PDUR_DESTPDU_SCS_RiSwitchSts_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_SCS_LeSwitchSts_BOD[3] =
{
    PDUR_DESTPDU_COM_SCS_LeSwitchSts_BOD,
    PDUR_DESTPDU_SCS_LeSwitchSts_CHA,
    PDUR_DESTPDU_SCS_LeSwitchSts_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TPMS_Info_BOD[3] =
{
    PDUR_DESTPDU_COM_TPMS_Info_BOD,
    PDUR_DESTPDU_TPMS_Info_CHA,
    PDUR_DESTPDU_TPMS_Info_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ESCL_ESCLStatus_BOD[1] =
{
    PDUR_DESTPDU_COM_ESCL_ESCLStatus_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AVAS_State_BOD[2] =
{
    PDUR_DESTPDU_COM_AVAS_State_BOD,
    PDUR_DESTPDU_AVAS_State_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_COMP_AC_BOD[1] =
{
    PDUR_DESTPDU_COM_COMP_AC_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ACCM_Version_BOD[1] =
{
    PDUR_DESTPDU_COM_ACCM_Version_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HVCH_Status1_BOD[1] =
{
    PDUR_DESTPDU_COM_HVCH_Status1_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HVCH_Status2_BOD[1] =
{
    PDUR_DESTPDU_COM_HVCH_Status2_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_3_OprtCmd_EPT[1] =
{
    PDUR_DESTPDU_VCU_3_OprtCmd_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_4_ChrgCmd_EPT[1] =
{
    PDUR_DESTPDU_VCU_4_ChrgCmd_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_B_AcclPedal_EPT[1] =
{
    PDUR_DESTPDU_VCU_B_AcclPedal_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_1_InvCmd_EPT[1] =
{
    PDUR_DESTPDU_VCU_1_InvCmd_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_0_Value_EPT[1] =
{
    PDUR_DESTPDU_VCU_0_Value_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_C_OprtCmd_EPT[1] =
{
    PDUR_DESTPDU_VCU_C_OprtCmd_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CCU_VehInfo_EPT[1] =
{
    PDUR_DESTPDU_CCU_VehInfo_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BCM_IMMOAuthResp1_EPT[1] =
{
    PDUR_DESTPDU_BCM_IMMOAuthResp1_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_1_MainState_EPT[2] =
{
    PDUR_DESTPDU_COM_BMS_1_MainState_EPT,
    PDUR_DESTPDU_BMS_1_MainState_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_2_BatState_EPT[2] =
{
    PDUR_DESTPDU_COM_BMS_2_BatState_EPT,
    PDUR_DESTPDU_BMS_2_BatState_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_3_DC_ChargeState_EPT[1] =
{
    PDUR_DESTPDU_COM_BMS_3_DC_ChargeState_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_4_AC_ChargeState_EPT[1] =
{
    PDUR_DESTPDU_COM_BMS_4_AC_ChargeState_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_10_DC_ChargeStates_EPT[2] =
{
    PDUR_DESTPDU_COM_BMS_10_DC_ChargeStates_EPT,
    PDUR_DESTPDU_BMS_10_DC_ChargeStates_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_5_BatTemp_EPT[1] =
{
    PDUR_DESTPDU_COM_BMS_5_BatTemp_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_6_DischrgRecup_EPT[1] =
{
    PDUR_DESTPDU_COM_BMS_6_DischrgRecup_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_7_CellVolt_EPT[1] =
{
    PDUR_DESTPDU_COM_BMS_7_CellVolt_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_8_TempVoltLimit_EPT[1] =
{
    PDUR_DESTPDU_COM_BMS_8_TempVoltLimit_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_9_BattInfo_EPT[1] =
{
    PDUR_DESTPDU_COM_BMS_9_BattInfo_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_A_GB_EPT[2] =
{
    PDUR_DESTPDU_COM_BMS_A_GB_EPT,
    PDUR_DESTPDU_BMS_A_GB_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_B_GB_EPT[2] =
{
    PDUR_DESTPDU_COM_BMS_B_GB_EPT,
    PDUR_DESTPDU_BMS_B_GB_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_C_GB_EPT[2] =
{
    PDUR_DESTPDU_COM_BMS_C_GB_EPT,
    PDUR_DESTPDU_BMS_C_GB_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BMS_D_GB_EPT[2] =
{
    PDUR_DESTPDU_COM_BMS_D_GB_EPT,
    PDUR_DESTPDU_BMS_D_GB_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPU_OBC_3_CP_CC_EPT[1] =
{
    PDUR_DESTPDU_COM_IPU_OBC_3_CP_CC_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPU_DCC_1_State_EPT[1] =
{
    PDUR_DESTPDU_COM_IPU_DCC_1_State_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPU_OBC_1_State_EPT[2] =
{
    PDUR_DESTPDU_COM_IPU_OBC_1_State_EPT,
    PDUR_DESTPDU_IPU_OBC_1_State_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPU_DCC_2_ChrgInValue_EPT[1] =
{
    PDUR_DESTPDU_COM_IPU_DCC_2_ChrgInValue_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPU_OBC_2_Inlet_EPT[1] =
{
    PDUR_DESTPDU_COM_IPU_OBC_2_Inlet_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_IPU_OBC_4_state_EPT[2] =
{
    PDUR_DESTPDU_COM_IPU_OBC_4_state_EPT,
    PDUR_DESTPDU_IPU_OBC_4_state_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_INV_1_Value_EPT[2] =
{
    PDUR_DESTPDU_COM_INV_1_Value_EPT,
    PDUR_DESTPDU_INV_1_Value_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_INV_2_Value_EPT[1] =
{
    PDUR_DESTPDU_COM_INV_2_Value_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_INV_3_Value_EPT[1] =
{
    PDUR_DESTPDU_COM_INV_3_Value_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_INV_4_Value_EPT[1] =
{
    PDUR_DESTPDU_COM_INV_4_Value_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_INV_5_Values_EPT[1] =
{
    PDUR_DESTPDU_COM_INV_5_Values_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_INV_IMMO_Req_EPT[1] =
{
    PDUR_DESTPDU_COM_INV_IMMO_Req_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_DispInfo_BAC[1] =
{
    PDUR_DESTPDU_VCU_DispInfo_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_CCU_VehInfo_BAC[1] =
{
    PDUR_DESTPDU_CCU_VehInfo_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_VCU_D_Status_BAC[1] =
{
    PDUR_DESTPDU_VCU_D_Status_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_ACStatuts_BAC[1] =
{
    PDUR_DESTPDU_AC_ACStatuts_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BCM_B_Package_BAC[1] =
{
    PDUR_DESTPDU_BCM_B_Package_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_AC_3_State_BAC[1] =
{
    PDUR_DESTPDU_AC_3_State_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_BCM_HFSData_BAC[1] =
{
    PDUR_DESTPDU_BCM_HFSData_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ICU_Info_BAC[2] =
{
    PDUR_DESTPDU_COM_ICU_Info_BAC,
    PDUR_DESTPDU_ICU_Info_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HU_B_BAC[1] =
{
    PDUR_DESTPDU_COM_HU_B_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HU_A_BAC[2] =
{
    PDUR_DESTPDU_COM_HU_A_BAC,
    PDUR_DESTPDU_HU_A_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_ICU_2_Odo_BAC[4] =
{
    PDUR_DESTPDU_COM_ICU_2_Odo_BAC,
    PDUR_DESTPDU_ICU_2_Odo_EPT,
    PDUR_DESTPDU_ICU_2_Odo_CHA,
    PDUR_DESTPDU_ICU_2_Odo_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_HU_C_BAC[2] =
{
    PDUR_DESTPDU_COM_HU_C_BAC,
    PDUR_DESTPDU_HU_C_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TBOX_BJS_Time_BAC[4] =
{
    PDUR_DESTPDU_COM_TBOX_BJS_Time_BAC,
    PDUR_DESTPDU_TBOX_BJS_Time_EPT,
    PDUR_DESTPDU_TBOX_BJS_Time_CHA,
    PDUR_DESTPDU_TBOX_BJS_Time_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Rx_Diag_Phy_OBD[1] =
{
    PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_CCU_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Rx_Diag_Fun_OBD[1] =
{
    PDUR_DESTPDU_DCM_RX_Diag_FuncReq_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Tx_Diag_Resp_OBD[1] =
{
    PDUR_DESTPDU_CANTP_TX_Diag_Resp_CCU_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_MCU_EPT_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_BMS_EPT_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_IPUDCC_EPT_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_ESC_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_EHB_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_EPS_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_PP_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_FCM_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_FRM_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_CRRL_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_CRRR_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_SRS_CHA_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_CDCICU_OBD_ToBAC[1] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_FuncReq_OBD_To_BAC_BOD_CHA_EPT[4] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_FuncReq_BAC,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_PTC_OBD_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_SCS_OBD_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_CCP_OBD_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_AVAS_OBD_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_ESCL_OBD_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_ACCM_OBD_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_TPMS_OBD_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_ESC_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_EHB_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_EPS_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_PP_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_FCM_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_FRM_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_CRRL_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_CRRR_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_SRS_OBD_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_MCU_OBD_To_EPT[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_BMS_OBD_To_EPT[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_IPUDCC_OBD_To_EPT[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_PTC_BOD_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_SCS_BOD_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_CCP_BOD_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_AVAS_BOD_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_ESCL_BOD_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_ACCM_BOD_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_TPMS_BOD_To_BAC_OBD[2] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_Resp_CDCICU_BAC_To_OBD[1] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CDCICU_OBD,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_MCU_BAC_To_EPT[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_BMS_BAC_To_EPT[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_IPUDCC_BAC_To_EPT[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_FuncReq_BAC_To_EPT_CHA_BOD[3] =
{
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT_1,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_ESC_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_EHB_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_EPS_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_PP_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_FCM_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_FRM_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_CRRL_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_CRRR_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_SRS_BAC_To_CHA[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_PTC_BAC_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_SCS_BAC_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_CCP_BAC_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_AVAS_BAC_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_ESCL_BAC_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_ACCM_BAC_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Diag_PhyReq_TPMS_BAC_To_BOD[1] =
{
    PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_HP_EXV_Cmd_LIN1[1] =
{
    PDUR_DESTPDU_HP_EXV_Cmd_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_HP_EXV__Rsp_LIN1[1] =
{
    PDUR_DESTPDU_Com_HP_EXV__Rsp_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BAT_EXV_Cmd_LIN1[1] =
{
    PDUR_DESTPDU_BAT_EXV_Cmd_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BAT_EXV_Rsp_LIN1[1] =
{
    PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AC_EXV_Cmd_LIN1[1] =
{
    PDUR_DESTPDU_AC_EXV_Cmd_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AC_EXV_Rsp_LIN1[1] =
{
    PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_MCV_Cmd_LIN1[1] =
{
    PDUR_DESTPDU_MCV_Cmd_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_MCV_Sts_LIN1[1] =
{
    PDUR_DESTPDU_Com_MCV_Sts_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BCV_Cmd_LIN1[1] =
{
    PDUR_DESTPDU_BCV_Cmd_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BCV_Sts_LIN1[1] =
{
    PDUR_DESTPDU_Com_BCV_Sts_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_PMP_Cmd_LIN1[1] =
{
    PDUR_DESTPDU_PMP_Cmd_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_MotPMP_Sts_LIN1[1] =
{
    PDUR_DESTPDU_Com_MotPMP_Sts_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BatPMP_Sts_LIN1[1] =
{
    PDUR_DESTPDU_Com_BatPMP_Sts_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AcPMP_Sts_LIN1[1] =
{
    PDUR_DESTPDU_Com_AcPMP_Sts_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_HP_EXV_Version_LIN1[1] =
{
    PDUR_DESTPDU_Com_HP_EXV_Version_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_Bat_EXV_Version_LIN1[1] =
{
    PDUR_DESTPDU_Com_Bat_EXV_Version_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_MCV_Version_LIN1[1] =
{
    PDUR_DESTPDU_Com_MCV_Version_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BCV_Version_LIN1[1] =
{
    PDUR_DESTPDU_Com_BCV_Version_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AcPMP_Version_LIN1[1] =
{
    PDUR_DESTPDU_Com_AcPMP_Version_LIN1,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AC_EXV_Cmd_LIN2[1] =
{
    PDUR_DESTPDU_AC_EXV_Cmd_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AC_EXV_Rsp_LIN2[1] =
{
    PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AcPMP_Sts_LIN2[1] =
{
    PDUR_DESTPDU_Com_AcPMP_Sts_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_AcPMP_Version_LIN2[1] =
{
    PDUR_DESTPDU_Com_AcPMP_Version_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BAT_EXV_Cmd_LIN2[1] =
{
    PDUR_DESTPDU_BAT_EXV_Cmd_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BAT_EXV_Rsp_LIN2[1] =
{
    PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_BatPMP_Sts_LIN2[1] =
{
    PDUR_DESTPDU_Com_BatPMP_Sts_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_Bat_EXV_Version_LIN2[1] =
{
    PDUR_DESTPDU_Com_Bat_EXV_Version_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_C3WV_Cmd_LIN2[1] =
{
    PDUR_DESTPDU_C3WV_Cmd_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_C3WV_Sts_LIN2[1] =
{
    PDUR_DESTPDU_Com_C3WV_Sts_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_C5WV_Cmd_LIN2[1] =
{
    PDUR_DESTPDU_C5WV_Cmd_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_C5WV_Sts_LIN2[1] =
{
    PDUR_DESTPDU_Com_C5WV_Sts_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_HP_EXV_Cmd_LIN2[1] =
{
    PDUR_DESTPDU_HP_EXV_Cmd_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_HP_EXV_Rsp_LIN2[1] =
{
    PDUR_DESTPDU_Com_HP_EXV_Rsp_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_HP_EXV_Version_LIN2[1] =
{
    PDUR_DESTPDU_Com_HP_EXV_Version_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_MotPMP_Sts_LIN2[1] =
{
    PDUR_DESTPDU_Com_MotPMP_Sts_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_PMP_Cmd_LIN2[1] =
{
    PDUR_DESTPDU_PMP_Cmd_LIN2,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_CCU_FCLCommand_LIN3[1] =
{
    PDUR_DESTPDU_CCU_FCLCommand_LIN3,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_FCLL_Status_LIN3[1] =
{
    PDUR_DESTPDU_Com_FCLL_Status_LIN3,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_FCLR_Status_LIN3[1] =
{
    PDUR_DESTPDU_Com_FCLR_Status_LIN3,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_Frm_InterlockStatus_LIN3[1] =
{
    PDUR_DESTPDU_Com_Frm_InterlockStatus_LIN3,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_Frm_InterlockToVehicle_LIN3[1] =
{
    PDUR_DESTPDU_Com_Frm_InterlockToVehicle_LIN3,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PduRRoutingPath_Frm_VehicleToInterlock_LIN3[1] =
{
    PDUR_DESTPDU_Frm_VehicleToInterlock_LIN3,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Rx_Diag_Phy_BAC[1] =
{
    PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Rx_Diag_Func_BAC[1] =
{
    PDUR_DESTPDU_DCM_RX_Diag_FuncReq_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Tx_Diag_Resp_BAC[1] =
{
    PDUR_DESTPDU_CANTP_TX_Diag_Resp_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_NM_CAN6_CANFD5[1] =
{
    PDUR_DESTPDU_CanNm_CAN6_CANFD5_user,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_Tx_Diag_Resp_OBD_2A[1] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
/* PRQA S 0779,0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */
#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingPathType,PDUR_CONST)
PduR_RoutingPathConfigData0[213] =
{
    {
        PDUR_SRCPDU_COM_INCA_CRO_XCP,
        1u,
        PduR_PDUR_ROUTING_INCA_CRO,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_TMSR_DTO_XCP,
        1u,
        PduR_PDUR_ROUTING_TMSR_DTO,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_CAN5_CANFD3_user,
        1u,
        PduR_PDUR_ROUTING_NM_CAN5_CANFD3,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_CAN2_CANFD6_user,
        1u,
        PduR_PDUR_ROUTING_NM_CAN2_CANFD6,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_CAN1_CANFD8_user,
        1u,
        PduR_PDUR_ROUTING_NM_CAN1_CANFD8,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_10_Torque_CHA,
        1u,
        PduR_PDUR_ROUTING_VCU_10_Torque_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_BCM_4_CruiseSw_PM_CHA,
        1u,
        PduR_PDUR_ROUTING_BCM_4_CruiseSw_PM_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_CHA,
        1u,
        PduR_PDUR_ROUTING_CCU_VehInfo_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_D_Status_CHA,
        1u,
        PduR_PDUR_ROUTING_VCU_D_Status_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_BCM_B_Package_CHA,
        1u,
        PduR_PDUR_ROUTING_BCM_B_Package_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_3_State_CHA,
        1u,
        PduR_PDUR_ROUTING_AC_3_State_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCM_D_CHA,
        2u,
        PduR_PDUR_ROUTING_FCM_D_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCM_B_CHA,
        1u,
        PduR_PDUR_ROUTING_FCM_B_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCM_A_CHA,
        2u,
        PduR_PDUR_ROUTING_FCM_A_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCM_23_Obj0109_CHA,
        2u,
        PduR_PDUR_ROUTING_FCM_23_Obj0109_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCM_24_Obj1018_CHA,
        2u,
        PduR_PDUR_ROUTING_FCM_24_Obj1018_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCM_25_Line123_CHA,
        2u,
        PduR_PDUR_ROUTING_FCM_25_Line123_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCM_ObjTrackID_CHA,
        2u,
        PduR_PDUR_ROUTING_FCM_ObjTrackID_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ESC_WheelPulseTime_CHA,
        1u,
        PduR_PDUR_ROUTING_ESC_WheelPulseTime_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ESC_A_CHA,
        1u,
        PduR_PDUR_ROUTING_ESC_A_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ESC_7_FuncStatus_CHA,
        4u,
        PduR_PDUR_ROUTING_ESC_7_FuncStatus_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_EHB_B_CHA,
        1u,
        PduR_PDUR_ROUTING_EHB_B_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_EHB_A_CHA,
        3u,
        PduR_PDUR_ROUTING_EHB_A_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_SRS_2_YRSOriginalSts_CHA,
        1u,
        PduR_PDUR_ROUTING_SRS_2_YRSOriginalSts_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_SRS_3_YRSActualSts_CHA,
        1u,
        PduR_PDUR_ROUTING_SRS_3_YRSActualSts_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_SRS_1_Status_CHA,
        3u,
        PduR_PDUR_ROUTING_SRS_1_Status_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_EPS_3_LatDrvAndEPSSts_CHA,
        1u,
        PduR_PDUR_ROUTING_EPS_3_LatDrvAndEPSSts_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_EPS_2_StrWhlAng_CHA,
        1u,
        PduR_PDUR_ROUTING_EPS_2_StrWhlAng_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_EPS_1_Status_CHA,
        2u,
        PduR_PDUR_ROUTING_EPS_1_Status_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_PP_InformAndStatus_CHA,
        2u,
        PduR_PDUR_ROUTING_PP_InformAndStatus_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CRRR_A_CHA,
        2u,
        PduR_PDUR_ROUTING_CRRR_A_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CRRR_10_Posn_CHA,
        1u,
        PduR_PDUR_ROUTING_CRRR_10_Posn_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_BOD,
        1u,
        PduR_PDUR_ROUTING_CCU_VehInfo_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_ACStatuts_BOD,
        1u,
        PduR_PDUR_ROUTING_AC_ACStatuts_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_COMP_BOD,
        1u,
        PduR_PDUR_ROUTING_AC_COMP_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_7_DrvRange_BOD,
        1u,
        PduR_PDUR_ROUTING_VCU_7_DrvRange_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_1_Command_BOD,
        1u,
        PduR_PDUR_ROUTING_AC_1_Command_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_HVCH_Command_BOD,
        1u,
        PduR_PDUR_ROUTING_HVCH_Command_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_3_State_BOD,
        1u,
        PduR_PDUR_ROUTING_AC_3_State_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_2_State_BOD,
        1u,
        PduR_PDUR_ROUTING_AC_2_State_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_8_status_BOD,
        1u,
        PduR_PDUR_ROUTING_AC_8_status_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_BCM_ESCLCommand_BOD,
        1u,
        PduR_PDUR_ROUTING_BCM_ESCLCommand_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TMS_LINTestData1_BOD,
        1u,
        PduR_PDUR_ROUTING_TMS_LINTestData1_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TMS_LINTestData2_BOD,
        1u,
        PduR_PDUR_ROUTING_TMS_LINTestData2_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TMS_LINTestData3_BOD,
        1u,
        PduR_PDUR_ROUTING_TMS_LINTestData3_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CCP_PanelStatus_BOD,
        2u,
        PduR_PDUR_ROUTING_CCP_PanelStatus_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_SCS_RiSwitchSts_BOD,
        3u,
        PduR_PDUR_ROUTING_SCS_RiSwitchSts_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_SCS_LeSwitchSts_BOD,
        3u,
        PduR_PDUR_ROUTING_SCS_LeSwitchSts_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_TPMS_Info_BOD,
        3u,
        PduR_PDUR_ROUTING_TPMS_Info_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ESCL_ESCLStatus_BOD,
        1u,
        PduR_PDUR_ROUTING_ESCL_ESCLStatus_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_AVAS_State_BOD,
        2u,
        PduR_PDUR_ROUTING_AVAS_State_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COMP_AC_BOD,
        1u,
        PduR_PDUR_ROUTING_COMP_AC_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ACCM_Version_BOD,
        1u,
        PduR_PDUR_ROUTING_ACCM_Version_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HVCH_Status1_BOD,
        1u,
        PduR_PDUR_ROUTING_HVCH_Status1_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HVCH_Status2_BOD,
        1u,
        PduR_PDUR_ROUTING_HVCH_Status2_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_3_OprtCmd_EPT,
        1u,
        PduR_PDUR_ROUTING_VCU_3_OprtCmd_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_4_ChrgCmd_EPT,
        1u,
        PduR_PDUR_ROUTING_VCU_4_ChrgCmd_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_B_AcclPedal_EPT,
        1u,
        PduR_PDUR_ROUTING_VCU_B_AcclPedal_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_1_InvCmd_EPT,
        1u,
        PduR_PDUR_ROUTING_VCU_1_InvCmd_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_0_Value_EPT,
        1u,
        PduR_PDUR_ROUTING_VCU_0_Value_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_C_OprtCmd_EPT,
        1u,
        PduR_PDUR_ROUTING_VCU_C_OprtCmd_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_EPT,
        1u,
        PduR_PDUR_ROUTING_CCU_VehInfo_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_BCM_IMMOAuthResp1_EPT,
        1u,
        PduR_PDUR_ROUTING_BCM_IMMOAuthResp1_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_1_MainState_EPT,
        2u,
        PduR_PDUR_ROUTING_BMS_1_MainState_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_2_BatState_EPT,
        2u,
        PduR_PDUR_ROUTING_BMS_2_BatState_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_3_DC_ChargeState_EPT,
        1u,
        PduR_PDUR_ROUTING_BMS_3_DC_ChargeState_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_4_AC_ChargeState_EPT,
        1u,
        PduR_PDUR_ROUTING_BMS_4_AC_ChargeState_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_10_DC_ChargeStates_EPT,
        2u,
        PduR_PDUR_ROUTING_BMS_10_DC_ChargeStates_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_5_BatTemp_EPT,
        1u,
        PduR_PDUR_ROUTING_BMS_5_BatTemp_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_6_DischrgRecup_EPT,
        1u,
        PduR_PDUR_ROUTING_BMS_6_DischrgRecup_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_7_CellVolt_EPT,
        1u,
        PduR_PDUR_ROUTING_BMS_7_CellVolt_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_8_TempVoltLimit_EPT,
        1u,
        PduR_PDUR_ROUTING_BMS_8_TempVoltLimit_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_9_BattInfo_EPT,
        1u,
        PduR_PDUR_ROUTING_BMS_9_BattInfo_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_A_GB_EPT,
        2u,
        PduR_PDUR_ROUTING_BMS_A_GB_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_B_GB_EPT,
        2u,
        PduR_PDUR_ROUTING_BMS_B_GB_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_C_GB_EPT,
        2u,
        PduR_PDUR_ROUTING_BMS_C_GB_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BMS_D_GB_EPT,
        2u,
        PduR_PDUR_ROUTING_BMS_D_GB_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPU_OBC_3_CP_CC_EPT,
        1u,
        PduR_PDUR_ROUTING_IPU_OBC_3_CP_CC_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPU_DCC_1_State_EPT,
        1u,
        PduR_PDUR_ROUTING_IPU_DCC_1_State_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPU_OBC_1_State_EPT,
        2u,
        PduR_PDUR_ROUTING_IPU_OBC_1_State_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPU_DCC_2_ChrgInValue_EPT,
        1u,
        PduR_PDUR_ROUTING_IPU_DCC_2_ChrgInValue_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPU_OBC_2_Inlet_EPT,
        1u,
        PduR_PDUR_ROUTING_IPU_OBC_2_Inlet_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_IPU_OBC_4_state_EPT,
        2u,
        PduR_PDUR_ROUTING_IPU_OBC_4_state_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_INV_1_Value_EPT,
        2u,
        PduR_PDUR_ROUTING_INV_1_Value_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_INV_2_Value_EPT,
        1u,
        PduR_PDUR_ROUTING_INV_2_Value_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_INV_3_Value_EPT,
        1u,
        PduR_PDUR_ROUTING_INV_3_Value_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_INV_4_Value_EPT,
        1u,
        PduR_PDUR_ROUTING_INV_4_Value_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_INV_5_Values_EPT,
        1u,
        PduR_PDUR_ROUTING_INV_5_Values_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_INV_IMMO_Req_EPT,
        1u,
        PduR_PDUR_ROUTING_INV_IMMO_Req_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_DispInfo_BAC,
        1u,
        PduR_PDUR_ROUTING_VCU_DispInfo_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_CCU_VehInfo_BAC,
        1u,
        PduR_PDUR_ROUTING_CCU_VehInfo_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_VCU_D_Status_BAC,
        1u,
        PduR_PDUR_ROUTING_VCU_D_Status_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_ACStatuts_BAC,
        1u,
        PduR_PDUR_ROUTING_AC_ACStatuts_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_BCM_B_Package_BAC,
        1u,
        PduR_PDUR_ROUTING_BCM_B_Package_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_AC_3_State_BAC,
        1u,
        PduR_PDUR_ROUTING_AC_3_State_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_BCM_HFSData_BAC,
        1u,
        PduR_PDUR_ROUTING_BCM_HFSData_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ICU_Info_BAC,
        2u,
        PduR_PDUR_ROUTING_ICU_Info_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HU_B_BAC,
        1u,
        PduR_PDUR_ROUTING_HU_B_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HU_A_BAC,
        2u,
        PduR_PDUR_ROUTING_HU_A_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_ICU_2_Odo_BAC,
        4u,
        PduR_PDUR_ROUTING_ICU_2_Odo_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HU_C_BAC,
        2u,
        PduR_PDUR_ROUTING_HU_C_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_TBOX_BJS_Time_BAC,
        4u,
        PduR_PDUR_ROUTING_TBOX_BJS_Time_BAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_CCU_OBD,
        1u,
        PduR_PDUR_ROUTING_Rx_Diag_Phy_OBD,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_OBD,
        1u,
        PduR_PDUR_ROUTING_Rx_Diag_Fun_OBD,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD,
        1u,
        PduR_PDUR_ROUTING_Tx_Diag_Resp_OBD,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_MCU_RX_EPT,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_MCU_EPT_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_BMS_RX_EPT,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_BMS_EPT_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_IPUDCC_EPT_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ESC_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_ESC_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_EHB_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_EHB_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_EPS_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_EPS_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_PP_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_PP_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_FCM_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_FCM_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_FRM_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_FRM_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_CRRL_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_CRRR_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_SRS_RX_CHA,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_SRS_CHA_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_CDCICU_OBD_ToBAC,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD,
        4u,
        PduR_PDUR_ROUTING_Diag_FuncReq_OBD_To_BAC_BOD_CHA_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_PTC_OBD_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_SCS_OBD_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_CCP_OBD_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_AVAS_OBD_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_ESCL_OBD_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_ACCM_OBD_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_TPMS_OBD_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_ESC_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_EHB_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_EPS_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_PP_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_FCM_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_FRM_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_CRRL_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_CRRR_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_SRS_OBD_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_MCU_OBD_To_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_BMS_OBD_To_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_IPUDCC_OBD_To_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_PTC_RX_BOD,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_PTC_BOD_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_SCS_RX_BOD,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_SCS_BOD_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CCP_RX_BOD,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_CCP_BOD_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_AVAS_BOD_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_ESCL_BOD_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_ACCM_BOD_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
        2u,
        PduR_PDUR_ROUTING_Diag_Resp_TPMS_BOD_To_BAC_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_Resp_CDCICU_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_Resp_CDCICU_BAC_To_OBD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_MCU_BAC_To_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_BMS_BAC_To_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_IPUDCC_BAC_To_EPT,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_BAC,
        3u,
        PduR_PDUR_ROUTING_Diag_FuncReq_BAC_To_EPT_CHA_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_ESC_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_EHB_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_EPS_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_PP_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_FCM_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_FRM_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_CRRL_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_CRRR_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_SRS_BAC_To_CHA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_PTC_BAC_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_SCS_BAC_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_CCP_BAC_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_AVAS_BAC_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_ESCL_BAC_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_ACCM_BAC_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC,
        1u,
        PduR_PDUR_ROUTING_Diag_PhyReq_TPMS_BAC_To_BOD,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN1,
        1u,
        PduR_PduRRoutingPath_HP_EXV_Cmd_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HP_EXV__Rsp_LIN1,
        1u,
        PduR_PduRRoutingPath_HP_EXV__Rsp_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN1,
        1u,
        PduR_PduRRoutingPath_BAT_EXV_Cmd_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN1,
        1u,
        PduR_PduRRoutingPath_BAT_EXV_Rsp_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN1,
        1u,
        PduR_PduRRoutingPath_AC_EXV_Cmd_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_AC_EXV_Rsp_LIN1,
        1u,
        PduR_PduRRoutingPath_AC_EXV_Rsp_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_MCV_Cmd_LIN1,
        1u,
        PduR_PduRRoutingPath_MCV_Cmd_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MCV_Sts_LIN1,
        1u,
        PduR_PduRRoutingPath_MCV_Sts_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_BCV_Cmd_LIN1,
        1u,
        PduR_PduRRoutingPath_BCV_Cmd_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BCV_Sts_LIN1,
        1u,
        PduR_PduRRoutingPath_BCV_Sts_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_PMP_Cmd_LIN1,
        1u,
        PduR_PduRRoutingPath_PMP_Cmd_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MotPMP_Sts_LIN1,
        1u,
        PduR_PduRRoutingPath_MotPMP_Sts_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BatPMP_Sts_LIN1,
        1u,
        PduR_PduRRoutingPath_BatPMP_Sts_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_AcPMP_Sts_LIN1,
        1u,
        PduR_PduRRoutingPath_AcPMP_Sts_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HP_EXV_Version_LIN1,
        1u,
        PduR_PduRRoutingPath_HP_EXV_Version_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Bat_EXV_Version_LIN1,
        1u,
        PduR_PduRRoutingPath_Bat_EXV_Version_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MCV_Version_LIN1,
        1u,
        PduR_PduRRoutingPath_MCV_Version_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BCV_Version_LIN1,
        1u,
        PduR_PduRRoutingPath_BCV_Version_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_AcPMP_Version_LIN1,
        1u,
        PduR_PduRRoutingPath_AcPMP_Version_LIN1,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN2,
        1u,
        PduR_PduRRoutingPath_AC_EXV_Cmd_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_AC_EXV_Rsp_LIN2,
        1u,
        PduR_PduRRoutingPath_AC_EXV_Rsp_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_AcPMP_Sts_LIN2,
        1u,
        PduR_PduRRoutingPath_AcPMP_Sts_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_AcPMP_Version_LIN2,
        1u,
        PduR_PduRRoutingPath_AcPMP_Version_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN2,
        1u,
        PduR_PduRRoutingPath_BAT_EXV_Cmd_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BAT_EXV_Rsp_LIN2,
        1u,
        PduR_PduRRoutingPath_BAT_EXV_Rsp_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_BatPMP_Sts_LIN2,
        1u,
        PduR_PduRRoutingPath_BatPMP_Sts_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Bat_EXV_Version_LIN2,
        1u,
        PduR_PduRRoutingPath_Bat_EXV_Version_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_C3WV_Cmd_LIN2,
        1u,
        PduR_PduRRoutingPath_C3WV_Cmd_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_C3WV_Sts_LIN2,
        1u,
        PduR_PduRRoutingPath_C3WV_Sts_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_C5WV_Cmd_LIN2,
        1u,
        PduR_PduRRoutingPath_C5WV_Cmd_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_C5WV_Sts_LIN2,
        1u,
        PduR_PduRRoutingPath_C5WV_Sts_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN2,
        1u,
        PduR_PduRRoutingPath_HP_EXV_Cmd_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HP_EXV_Rsp_LIN2,
        1u,
        PduR_PduRRoutingPath_HP_EXV_Rsp_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_HP_EXV_Version_LIN2,
        1u,
        PduR_PduRRoutingPath_HP_EXV_Version_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MotPMP_Sts_LIN2,
        1u,
        PduR_PduRRoutingPath_MotPMP_Sts_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_PMP_Cmd_LIN2,
        1u,
        PduR_PduRRoutingPath_PMP_Cmd_LIN2,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_CCU_FCLCommand_LIN3,
        1u,
        PduR_PduRRoutingPath_CCU_FCLCommand_LIN3,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCLL_Status_LIN3,
        1u,
        PduR_PduRRoutingPath_FCLL_Status_LIN3,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_FCLR_Status_LIN3,
        1u,
        PduR_PduRRoutingPath_FCLR_Status_LIN3,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Frm_InterlockStatus_LIN3,
        1u,
        PduR_PduRRoutingPath_Frm_InterlockStatus_LIN3,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Frm_InterlockToVehicle_LIN3,
        1u,
        PduR_PduRRoutingPath_Frm_InterlockToVehicle_LIN3,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_Frm_VehicleToInterlock_LIN3,
        1u,
        PduR_PduRRoutingPath_Frm_VehicleToInterlock_LIN3,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_BAC,
        1u,
        PduR_PDUR_ROUTING_Rx_Diag_Phy_BAC,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_BAC,
        1u,
        PduR_PDUR_ROUTING_Rx_Diag_Func_BAC,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_DCM_TX_Diag_Resp_BAC,
        1u,
        PduR_PDUR_ROUTING_Tx_Diag_Resp_BAC,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_Com_CAN6_CANFD5_user,
        1u,
        PduR_PDUR_ROUTING_NM_CAN6_CANFD5,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD_2A,
        1u,
        PduR_PDUR_ROUTING_Tx_Diag_Resp_OBD_2A,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingTableType,PDUR_CONST)
PduR_RoutingTableConfigData[1] =
{
    {
        PduR_RoutingPathConfigData0
    }
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_DestPduPathGroup0[89] =
{
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_OBD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_OBD,
    PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_CCU_OBD,
    PDUR_DESTPDU_DCM_RX_Diag_FuncReq_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_FuncReq_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_BAC,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_OBD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_BAC,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_OBD,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_CDCICU_OBD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_BAC,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1,
    PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_BAC,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_BAC,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_OBD,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT_1,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT,
    PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_OBD,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA_1,
    PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD_1,
    PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1,
    PDUR_DESTPDU_DCM_RX_Diag_FuncReq_BAC,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(uint16,PDUR_CONST)
PduR_DestPduPathGroup1[75] =
{
    PDUR_DESTPDU_COM_FCM_D_CHA,
    PDUR_DESTPDU_FCM_D_CHA_2_BAC,
    PDUR_DESTPDU_FCM_A_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_A_CHA,
    PDUR_DESTPDU_COM_FCM_23_Obj0109_CHA,
    PDUR_DESTPDU_FCM_23_Obj0109_2_BAC,
    PDUR_DESTPDU_COM_FCM_24_Obj1018_CHA,
    PDUR_DESTPDU_FCM_24_Obj1018_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_25_Line123_CHA,
    PDUR_DESTPDU_FCM_25_Line123_CHA_2_BAC,
    PDUR_DESTPDU_COM_FCM_ObjTrackID_CHA,
    PDUR_DESTPDU_FCM_ObjTrackID_CHA_2_BAC,
    PDUR_DESTPDU_COM_ESC_7_FuncStatus_CHA,
    PDUR_DESTPDU_ESC_7_FuncStatus_EPT,
    PDUR_DESTPDU_ESC_7_FuncStatus_BOD,
    PDUR_DESTPDU_ESC_7_FuncStatus_BAC,
    PDUR_DESTPDU_EHB_A_BOD,
    PDUR_DESTPDU_COM_EHB_A_CHA,
    PDUR_DESTPDU_EHB_A_BAC,
    PDUR_DESTPDU_COM_SRS_1_Status_CHA,
    PDUR_DESTPDU_SRS_1_Status_EPT,
    PDUR_DESTPDU_SRS_1_Status_BAC,
    PDUR_DESTPDU_COM_EPS_1_Status_CHA,
    PDUR_DESTPDU_EPS_1_Status_BAC,
    PDUR_DESTPDU_COM_PP_InformAndStatus_CHA,
    PDUR_DESTPDU_PP_InformAndStatus_CHA_2_BAC,
    PDUR_DESTPDU_COM_CRRR_A_CHA,
    PDUR_DESTPDU_CRRR_A_BAC,
    PDUR_DESTPDU_COM_CCP_PanelStatus_BOD,
    PDUR_DESTPDU_CCP_PanelStatus_CHA,
    PDUR_DESTPDU_COM_SCS_RiSwitchSts_BOD,
    PDUR_DESTPDU_SCS_RiSwitchSts_CHA,
    PDUR_DESTPDU_SCS_RiSwitchSts_BAC,
    PDUR_DESTPDU_COM_SCS_LeSwitchSts_BOD,
    PDUR_DESTPDU_SCS_LeSwitchSts_CHA,
    PDUR_DESTPDU_SCS_LeSwitchSts_BAC,
    PDUR_DESTPDU_COM_TPMS_Info_BOD,
    PDUR_DESTPDU_TPMS_Info_CHA,
    PDUR_DESTPDU_TPMS_Info_BAC,
    PDUR_DESTPDU_COM_AVAS_State_BOD,
    PDUR_DESTPDU_AVAS_State_BAC,
    PDUR_DESTPDU_COM_BMS_1_MainState_EPT,
    PDUR_DESTPDU_BMS_1_MainState_BAC,
    PDUR_DESTPDU_COM_BMS_2_BatState_EPT,
    PDUR_DESTPDU_BMS_10_DC_ChargeStates_BAC,
    PDUR_DESTPDU_BMS_2_BatState_BAC,
    PDUR_DESTPDU_COM_BMS_10_DC_ChargeStates_EPT,
    PDUR_DESTPDU_COM_BMS_A_GB_EPT,
    PDUR_DESTPDU_BMS_A_GB_BAC,
    PDUR_DESTPDU_COM_BMS_B_GB_EPT,
    PDUR_DESTPDU_BMS_B_GB_BAC,
    PDUR_DESTPDU_COM_BMS_C_GB_EPT,
    PDUR_DESTPDU_BMS_C_GB_BAC,
    PDUR_DESTPDU_COM_BMS_D_GB_EPT,
    PDUR_DESTPDU_BMS_D_GB_BAC,
    PDUR_DESTPDU_COM_IPU_OBC_1_State_EPT,
    PDUR_DESTPDU_COM_IPU_OBC_4_state_EPT,
    PDUR_DESTPDU_IPU_OBC_4_state_BAC,
    PDUR_DESTPDU_COM_INV_1_Value_EPT,
    PDUR_DESTPDU_IPU_OBC_1_State_BAC,
    PDUR_DESTPDU_INV_1_Value_BAC,
    PDUR_DESTPDU_COM_ICU_Info_BAC,
    PDUR_DESTPDU_ICU_Info_CHA,
    PDUR_DESTPDU_COM_ICU_2_Odo_BAC,
    PDUR_DESTPDU_ICU_2_Odo_EPT,
    PDUR_DESTPDU_TBOX_BJS_Time_BOD,
    PDUR_DESTPDU_COM_TBOX_BJS_Time_BAC,
    PDUR_DESTPDU_HU_A_CHA,
    PDUR_DESTPDU_TBOX_BJS_Time_CHA,
    PDUR_DESTPDU_ICU_2_Odo_CHA,
    PDUR_DESTPDU_ICU_2_Odo_BOD,
    PDUR_DESTPDU_HU_C_BOD,
    PDUR_DESTPDU_COM_HU_A_BAC,
    PDUR_DESTPDU_COM_HU_C_BAC,
    PDUR_DESTPDU_TBOX_BJS_Time_EPT,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingPathGroupType,PDUR_CONST)
PduR_RoutingPathGroupConfigData[PDUR_ROUTING_PATH_GROUP_SUM] =
{
    {
        TRUE,
        PduRRoutingPathGroup_DIAG,
        89u,
        PduR_DestPduPathGroup0
    },
    {
        TRUE,
        PduRRoutingPathGroup_COMRouting,
        75u,
        PduR_DestPduPathGroup1
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(PduR_PBConfigType, PDUR_CONST_PBCFG) PduR_PBConfigData =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    0u,
    2u,
    213u,
    280u,
    PduR_RoutingPathGroupConfigData,
    PduR_RoutingTableConfigData,
    PduR_SrcPduConfigData,
    PduR_DestPduConfigData,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

