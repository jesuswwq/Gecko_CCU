/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-06-12 13:49:49>
 */
/*============================================================================*/

/******************************* references ************************************/
#include "Dcm_Types.h"
#include "Rte_Dcm.h"
#include "Dcm_Cfg.h"
#if (STD_ON == DCM_UDS_FUNC_ENABLED)
#include "UDS.h"
#endif
#if (STD_ON == DCM_OBD_FUNC_ENABLED)
#include "OBD.h"
#endif

/*******************Control DTC Setting********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspControlDTCSettingType, DCM_CONST) Dcm_DspControlDTCSettingCfg =
{
    FALSE, /*DcmSupportDTCSettingControlOptionRecord*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Com Control********************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannelCfg[6] =
{
    {
        TRUE, /*DcmDspComControlAllChannelUsed*/
        4u, /*DcmDspComMChannelId*/
    },
    {
        TRUE, /*DcmDspComControlAllChannelUsed*/
        0u, /*DcmDspComMChannelId*/
    },
    {
        TRUE, /*DcmDspComControlAllChannelUsed*/
        1u, /*DcmDspComMChannelId*/
    },
    {
        TRUE, /*DcmDspComControlAllChannelUsed*/
        2u, /*DcmDspComMChannelId*/
    },
    {
        TRUE, /*DcmDspComControlAllChannelUsed*/
        3u, /*DcmDspComMChannelId*/
    },
    {
        TRUE, /*DcmDspComControlAllChannelUsed*/
        5u, /*DcmDspComMChannelId*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControlCfg =
{
    6u, /*DcmDspComControlAllChannelNum*/
    &Dcm_DspComControlAllChannelCfg[0], /*DcmDspComControlAllChannel*/
    NULL_PTR, /*DcmDspComControlSetting*/
    0u, /*DcmDspComControlSpecificChannelNum*/
    NULL_PTR, /*DcmDspComControlSpecificChannel*/
    0u, /*DcmDspComControlSubNodeNum*/
    NULL_PTR /*DcmDspComControlSubNode*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Common Authorization********************/
/* PRQA S 0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_Ses3_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_Ses3_Sec5_SecRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_Ses3_Sec5_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_Ses3_Sec1_SecRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)DcmDspCommonAuthorization_Ses3_Sec1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3,Rule 5.2 */

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspCommonAuthorizationType, DCM_CONST) Dcm_DspCommonAuthorizationCfg[3] =
{
    {
        0u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR, /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_Ses3_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        1u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        &DcmDspCommonAuthorization_Ses3_Sec5_SecRef[0], /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_Ses3_Sec5_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        1u,     /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        &DcmDspCommonAuthorization_Ses3_Sec1_SecRef[0], /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u, /*DcmDspCommonAuthorizationSessionRefNum*/
        &DcmDspCommonAuthorization_Ses3_Sec1_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/* PRQA S 0674++ */ /* MISRA Rule 1.1 */
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspDataCfg[144] =
{
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F197_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F197_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F18A_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F18A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F191_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F191_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        168u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F187_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F187_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F188_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F188_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F180_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F180_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F18B_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F18B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F18C_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F18C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        120u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F190_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F190_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F190_WriteData, /*DcmDspDataWriteFnc*/
        136u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F15B_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F15B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F192_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F192_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F194_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F194_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F101_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F101_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F101_WriteData, /*DcmDspDataWriteFnc*/
        240u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F157_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F157_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F157_WriteData, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F158_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F158_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F158_WriteData, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F080_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F080_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F081_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F081_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        88u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F084_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F084_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F085_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F085_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3231_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_1_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3233_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3233_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3233_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_2_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3234_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3234_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3234_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_3_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3235_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3235_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3235_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_4_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3236_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3236_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3236_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F163_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F163_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AA_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AA_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AB_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AB_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AC_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AC_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AD_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AD_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AE_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AE_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AF_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F1AF_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        152u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13A_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13A_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13A_WriteData, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13B_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13B_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13B_WriteData, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13C_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13C_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13C_WriteData, /*DcmDspDataWriteFnc*/
        56u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13D_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13D_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13D_WriteData, /*DcmDspDataWriteFnc*/
        96u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13E_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13E_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F13E_WriteData, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF200H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF200H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF201H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF201H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF202H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF202H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF203H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF203H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        48u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF204H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF204H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        24u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF205H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF205H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF206H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF206H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF251H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF251H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF252H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF252H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF253H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF253H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF254H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF254H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF255H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF255H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF256H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF256H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF257H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF257H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF258H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF258H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF259H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF259H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF25AH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF25AH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF25BH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF25BH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF25CH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF25CH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF25DH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF25DH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF25EH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF25EH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF25FH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF25FH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF210H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF210H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF211H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF211H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF212H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF212H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF213H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF213H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF214H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF214H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF215H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF215H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF216H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF216H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF217H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF217H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF218H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF218H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF219H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF219H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF21AH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF21AH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF21BH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF21BH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF21CH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF21CH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF21DH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF21DH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF21EH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF21EH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF21FH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF21FH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF220H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF220H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF221H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF221H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF222H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF222H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF223H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF223H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF224H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF224H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF225H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF225H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF226H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF226H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF227H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF227H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF228H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF228H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF229H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF229H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF22AH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF22AH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        32u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF22BH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF22BH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        128u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF22CH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF22CH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF230H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF230H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF231H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF231H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF232H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF232H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF233H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF233H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF234H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF234H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        184u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF235H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF235H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        40u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF236H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF236H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        40u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF237H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF237H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF238H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF238H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF239H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF239H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF23AH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF23AH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF23BH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF23BH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF23CH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF23CH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF23DH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF23DH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF23EH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF23EH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF23FH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF23FH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        48u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF240H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF240H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        160u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_0xF241H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_0xF241H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        64u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3237_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_3232_4_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3238_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3238_ReturnControlToECU, /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_3238_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        40u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F260H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F260H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F261H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F261H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F262H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F262H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F263H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F263H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F264H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F264H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F265H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F265H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F266H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F266H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F267H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F267H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F268H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F268H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F269H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F269H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F26AH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F26AH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F26BH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F26BH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F26CH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F26CH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F26DH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F26DH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F26EH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F26EH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F26FH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F26FH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F270H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F270H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F271H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F271H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F272H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F272H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F273H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F273H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F274H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F274H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F275H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F275H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F276H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F276H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F277H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F277H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F278H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F278H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F279H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F279H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F27AH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F27AH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F27BH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F27BH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F27CH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F27CH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F27DH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F27DH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F27EH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F27EH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        16u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F27FH,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F27FH, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F280H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F280H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F281H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F281H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_DataConditionCheck_F282H,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_BIG_ENDIAN, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_DataRead_F282H, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        8u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_Dcm_CSDataServices_DcmDspData_F15E_ConditionCheckRead,     /*DcmDspDataConditionCheckReadFnc*/
        TRUE, /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,     /*DcmDspDataEcuSignalFnc*/
        NULL_PTR, /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE, /*DcmDspDataEndianness*/
        NULL_PTR,     /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,     /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,  /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_Dcm_CSDataServices_DcmDspData_F15E_ReadData, /*DcmDspDataReadFnc*/
        NULL_PTR, /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR, /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR, /*DcmDspDataWriteFnc*/
        80u, /*DcmDspDataSize*/
        DCM_UINT8, /*DcmDspDataType*/
        USE_DATA_SYNCH_FNC, /*DcmDspDataUsePort*/
        0u, /*DcmDspDataBlockId*/
        0xffu, /*DcmDspDataInfoIndex*/
        NULL_PTR, /*DcmDspDiagnosisScaling*/
        NULL_PTR /*DcmDspExternalSRDataElementClass*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0674-- */ /* MISRA Rule 1.1 */

/********************Dsp Did******************************/
/******************************************
 *DcmDspDidRead container configration
 *****************************************/                                                                        
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_0_Read_SesRefCfg[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_0_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    2u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_0_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Read_SesRefCfg[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_1_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    2u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_1_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Read_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Read_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_2_ReadCfg =
{
    1u, /*DcmDspDidReadSecurityLevelRefNum*/
    &Dcm_DidInfo_2_Read_SecRefCfg[0], /*pDcmDspDidReadSecurityLevelRow*/
    1u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_2_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_3_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u, /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Read_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Read_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_4_ReadCfg =
{
    1u, /*DcmDspDidReadSecurityLevelRefNum*/
    &Dcm_DidInfo_4_Read_SecRefCfg[0], /*pDcmDspDidReadSecurityLevelRow*/
    1u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_4_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_5_Read_SesRefCfg[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_5_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    2u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_5_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_6_Read_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_6_Read_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_6_ReadCfg =
{
    1u, /*DcmDspDidReadSecurityLevelRefNum*/
    &Dcm_DidInfo_6_Read_SecRefCfg[0], /*pDcmDspDidReadSecurityLevelRow*/
    1u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_6_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_7_ReadCfg =
{
    0u, /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u, /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_8_Read_SecRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_8_Read_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidReadType,DCM_CONST)Dcm_DidInfo_8_ReadCfg =
{
    1u, /*DcmDspDidReadSecurityLevelRefNum*/
    &Dcm_DidInfo_8_Read_SecRefCfg[0], /*pDcmDspDidReadSecurityLevelRow*/
    1u, /*DcmDspDidReadSessionRefNum*/
    &Dcm_DidInfo_8_Read_SesRefCfg[0], /*pDcmDspDidReadSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidWrite container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Write_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_1_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_1_WriteCfg=
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_1_Write_SecRefCfg[0],    /*pDcmDspDidWriteSecurityLevelRow*/
    1u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_1_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Write_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_2_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_2_WriteCfg=
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_2_Write_SecRefCfg[0],    /*pDcmDspDidWriteSecurityLevelRow*/
    1u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_2_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Write_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_4_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_4_WriteCfg=
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_4_Write_SecRefCfg[0],    /*pDcmDspDidWriteSecurityLevelRow*/
    1u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_4_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_6_Write_SecRefCfg[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_6_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_6_WriteCfg=
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_6_Write_SecRefCfg[0],    /*pDcmDspDidWriteSecurityLevelRow*/
    1u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_6_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_8_Write_SecRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DidInfo_8_Write_SesRefCfg[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DspDidWriteType,DCM_CONST)Dcm_DidInfo_8_WriteCfg=
{
    1u,/*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_8_Write_SecRefCfg[0],    /*pDcmDspDidWriteSecurityLevelRow*/
    1u,    /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_8_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidControl container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidControlType,DCM_CONST) Dcm_DidInfo_3_ControlCfg =
{
    DCM_CONTROLMASK_EXTERNAL, /*DcmDspDidControlMask*/
    1u, /*DcmDspDidControlMaskSize*/
    0u, /*DcmDspDidControlSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidControlSecurityLevelRow*/
    0u, /*DcmDspDidControlSessionRefNum*/
    NULL_PTR, /*pDcmDspDidControlSessionRow*/
    FALSE, /*DcmDspDidFreezeCurrentState*/
    FALSE, /*DcmDspDidResetToDefault*/
    TRUE, /*DcmDspDidShortTermAdjustement*/
    NULL_PTR, /*DcmDspDidControlEnableMask*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidControlType,DCM_CONST) Dcm_DidInfo_7_ControlCfg =
{
    DCM_CONTROLMASK_EXTERNAL, /*DcmDspDidControlMask*/
    2u, /*DcmDspDidControlMaskSize*/
    0u, /*DcmDspDidControlSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidControlSecurityLevelRow*/
    0u, /*DcmDspDidControlSessionRefNum*/
    NULL_PTR, /*pDcmDspDidControlSessionRow*/
    FALSE, /*DcmDspDidFreezeCurrentState*/
    FALSE, /*DcmDspDidResetToDefault*/
    TRUE, /*DcmDspDidShortTermAdjustement*/
    NULL_PTR, /*DcmDspDidControlEnableMask*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/******************************************
 *DcmDspDidInfo container Configuration ***
 ******************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidInfoType,DCM_CONST)Dcm_DspDidInfoCfg[9] =
{
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_0_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_1_ReadCfg, /*pDcmDspDidRead*/
        &Dcm_DidInfo_1_WriteCfg, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_2_ReadCfg, /*pDcmDspDidRead*/
        &Dcm_DidInfo_2_WriteCfg, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        &Dcm_DidInfo_3_ControlCfg, /*pDcmDspDidControl*/
        &Dcm_DidInfo_3_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_4_ReadCfg, /*pDcmDspDidRead*/
        &Dcm_DidInfo_4_WriteCfg, /*pDcmDspDidWrite*/
    },
    {
        5u, /*DcmDspDDDIDMaxElements*/
        TRUE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_5_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_6_ReadCfg, /*pDcmDspDidRead*/
        &Dcm_DidInfo_6_WriteCfg, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        &Dcm_DidInfo_7_ControlCfg, /*pDcmDspDidControl*/
        &Dcm_DidInfo_7_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR, /*pDcmDspDidWrite*/
    },
    {
        0u, /*DcmDspDDDIDMaxElements*/
        FALSE, /*DcmDspDidDynamicallyDefined*/
        NULL_PTR, /*pDcmDspDidControl*/
        &Dcm_DidInfo_8_ReadCfg, /*pDcmDspDidRead*/
        &Dcm_DidInfo_8_WriteCfg, /*pDcmDspDidWrite*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F197_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[0],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[1],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F191_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[2],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F187_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[3],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F188_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[4],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F180_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[5],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[6],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F18C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[7],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F190_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[8],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F15B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[9],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F192_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[10],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F194_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[11],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F101_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[12],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F157_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[13],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F158_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[14],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F080_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[15],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F081_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[16],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F084_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[17],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F085_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[18],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3231_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[19],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3232_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[20],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3233_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[21],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3234_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[22],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3235_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[23],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3236_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[24],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F163_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[25],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AA_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[26],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AB_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[27],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AC_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[28],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AD_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[29],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AE_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[30],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F1AF_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[31],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F13A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[32],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F13B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[33],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F13C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[34],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F13D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[35],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F13E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[36],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F200_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[37],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F201_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[38],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F202_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[39],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F203_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[40],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F204_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[41],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F205_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[42],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F206_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[43],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F251_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[44],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F252_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[45],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F253_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[46],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F254_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[47],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F255_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[48],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F256_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[49],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F257_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[50],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F258_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[51],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F259_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[52],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F25A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[53],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F25B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[54],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F25C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[55],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F25D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[56],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F25E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[57],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F25F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[58],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F210_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[59],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F211_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[60],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F212_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[61],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F213_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[62],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F214_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[63],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F215_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[64],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F216_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[65],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F217_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[66],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F218_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[67],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F219_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[68],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F21A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[69],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F21B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[70],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F21C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[71],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F21D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[72],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F21E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[73],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F21F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[74],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F220_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[75],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F221_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[76],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F222_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[77],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F223_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[78],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F224_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[79],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F225_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[80],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F226_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[81],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F227_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[82],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F228_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[83],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F229_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[84],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F22A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[85],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F22B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[86],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F22C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[87],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F230_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[88],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F231_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[89],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F232_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[90],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F233_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[91],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F234_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[92],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F235_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[93],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F236_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[94],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F237_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[95],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F238_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[96],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F239_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[97],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F23A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[98],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F23B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[99],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F23C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[100],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F23D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[101],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F23E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[102],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F23F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[103],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F240_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[104],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F241_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[105],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3237_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[106],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_3238_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[107],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F260_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[108],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F261_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[109],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F262_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[110],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F263_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[111],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F264_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[112],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F265_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[113],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F266_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[114],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F267_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[115],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F268_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[116],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F269_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[117],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F26A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[118],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F26B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[119],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F26C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[120],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F26D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[121],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F26E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[122],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F26F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[123],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F270_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[124],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F271_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[125],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F272_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[126],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F273_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[127],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F274_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[128],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F275_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[129],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F276_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[130],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F277_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[131],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F278_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[132],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F279_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[133],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F27A_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[134],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F27B_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[135],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F27C_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[136],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F27D_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[137],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F27E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[138],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F27F_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[139],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F280_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[140],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F281_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[141],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F282_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[142],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType,DCM_CONST)Dcm_Did_F15E_SignalCfg[1] =
{
    {
        0u,                   /*DcmDspDidDataPos*/
        &Dcm_DspDataCfg[143],     /*pDcmDspDidData*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************
 *DcmDspDid container configration*************
 **********************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspDidType,DCM_CONST)Dcm_DspDidCfg[144] =
{
    { /* Did_0xF197 */
        0xF197u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F197_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF18A */
        0xF18Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F18A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF191 */
        0xF191u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F191_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF187 */
        0xF187u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F187_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF188 */
        0xF188u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F188_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF180 */
        0xF180u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F180_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF18B */
        0xF18Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F18B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF18C */
        0xF18Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F18C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF190 */
        0xF190u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F190_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF15B */
        0xF15Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F15B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF192 */
        0xF192u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F192_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF194 */
        0xF194u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F194_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF101 */
        0xF101u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F101_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF157 */
        0xF157u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F157_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF158 */
        0xF158u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        8u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F158_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF080 */
        0xF080u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F080_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF081 */
        0xF081u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F081_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF084 */
        0xF084u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F084_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF085 */
        0xF085u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F085_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3231 */
        0x3231u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        7u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3231_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3232 */
        0x3232u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3232_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3233 */
        0x3233u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3233_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3234 */
        0x3234u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3234_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3235 */
        0x3235u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3235_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3236 */
        0x3236u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3236_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF163 */
        0xF163u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F163_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AA */
        0xF1AAu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AA_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AB */
        0xF1ABu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AB_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AC */
        0xF1ACu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AC_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AD */
        0xF1ADu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AD_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AE */
        0xF1AEu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AE_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF1AF */
        0xF1AFu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F1AF_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF13A */
        0xF13Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        4u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F13A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF13B */
        0xF13Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F13B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF13C */
        0xF13Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F13C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF13D */
        0xF13Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        2u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F13D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF13E */
        0xF13Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        1u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F13E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF200 */
        0xF200u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F200_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF201 */
        0xF201u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F201_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF202 */
        0xF202u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F202_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF203 */
        0xF203u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F203_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF204 */
        0xF204u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F204_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF205 */
        0xF205u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F205_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF206 */
        0xF206u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F206_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF251 */
        0xF251u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F251_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF252 */
        0xF252u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F252_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF253 */
        0xF253u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F253_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF254 */
        0xF254u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F254_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF255 */
        0xF255u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F255_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF256 */
        0xF256u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F256_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF257 */
        0xF257u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F257_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF258 */
        0xF258u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F258_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF259 */
        0xF259u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F259_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF25A */
        0xF25Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F25A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF25B */
        0xF25Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F25B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF25C */
        0xF25Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F25C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF25D */
        0xF25Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F25D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF25E */
        0xF25Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F25E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF25F */
        0xF25Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F25F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF210 */
        0xF210u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F210_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF211 */
        0xF211u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F211_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF212 */
        0xF212u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F212_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF213 */
        0xF213u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F213_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF214 */
        0xF214u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F214_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF215 */
        0xF215u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F215_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF216 */
        0xF216u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F216_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF217 */
        0xF217u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F217_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF218 */
        0xF218u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F218_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF219 */
        0xF219u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F219_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF21A */
        0xF21Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F21A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF21B */
        0xF21Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F21B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF21C */
        0xF21Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F21C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF21D */
        0xF21Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F21D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF21E */
        0xF21Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F21E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF21F */
        0xF21Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F21F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF220 */
        0xF220u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F220_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF221 */
        0xF221u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F221_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF222 */
        0xF222u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F222_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF223 */
        0xF223u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F223_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF224 */
        0xF224u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F224_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF225 */
        0xF225u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F225_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF226 */
        0xF226u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F226_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF227 */
        0xF227u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F227_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF228 */
        0xF228u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F228_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF229 */
        0xF229u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F229_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF22A */
        0xF22Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F22A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF22B */
        0xF22Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F22B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF22C */
        0xF22Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F22C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF230 */
        0xF230u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F230_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF231 */
        0xF231u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F231_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF232 */
        0xF232u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F232_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF233 */
        0xF233u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F233_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF234 */
        0xF234u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F234_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF235 */
        0xF235u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F235_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF236 */
        0xF236u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F236_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF237 */
        0xF237u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F237_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF238 */
        0xF238u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F238_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF239 */
        0xF239u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F239_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF23A */
        0xF23Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F23A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF23B */
        0xF23Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F23B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF23C */
        0xF23Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F23C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF23D */
        0xF23Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F23D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF23E */
        0xF23Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F23E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF23F */
        0xF23Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F23F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF240 */
        0xF240u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F240_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF241 */
        0xF241u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F241_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3237 */
        0x3237u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3237_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0x3238 */
        0x3238u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        3u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_3238_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF260 */
        0xF260u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F260_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF261 */
        0xF261u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F261_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF262 */
        0xF262u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F262_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF263 */
        0xF263u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F263_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF264 */
        0xF264u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F264_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF265 */
        0xF265u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F265_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF266 */
        0xF266u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F266_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF267 */
        0xF267u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F267_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF268 */
        0xF268u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F268_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF269 */
        0xF269u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F269_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF26A */
        0xF26Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F26A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF26B */
        0xF26Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F26B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF26C */
        0xF26Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F26C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF26D */
        0xF26Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F26D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF26E */
        0xF26Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F26E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF26F */
        0xF26Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F26F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF270 */
        0xF270u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F270_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF271 */
        0xF271u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F271_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF272 */
        0xF272u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F272_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF273 */
        0xF273u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F273_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF274 */
        0xF274u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F274_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF275 */
        0xF275u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F275_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF276 */
        0xF276u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F276_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF277 */
        0xF277u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F277_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF278 */
        0xF278u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F278_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF279 */
        0xF279u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F279_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF27A */
        0xF27Au,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F27A_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF27B */
        0xF27Bu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F27B_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF27C */
        0xF27Cu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F27C_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF27D */
        0xF27Du,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F27D_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF27E */
        0xF27Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F27E_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF27F */
        0xF27Fu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F27F_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF280 */
        0xF280u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F280_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF281 */
        0xF281u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F281_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF282 */
        0xF282u,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        5u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F282_SignalCfg[0],     /*pDcmDspDidSignal*/
    },
    { /* Did_0xF15E */
        0xF15Eu,     /*DcmDspDidId*/
        TRUE,     /*DcmDspDidUsed*/
        0u,     /*DcmDspDidInfoIndex*/
        0u,     /*DcmDspRefDidNum*/
        NULL_PTR,     /*pDcmDspRefDidIdArray*/
        1u, /*DcmDspDidSignalNum*/
        &Dcm_Did_F15E_SignalCfg[0],     /*pDcmDspDidSignal*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Routine**************/
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xFF02_SignalCfg[2] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        0u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF159_SignalCfg[3] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        128u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_UINT8, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x5231_SignalCfg[1] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x5234_SignalCfg[1] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x5232_SignalCfg[1] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0x5235_SignalCfg[1] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF015_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF0AD_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        16u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF0AE_SignalCfg[2] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF0AF_SignalCfg[1] =
{
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType,DCM_CONST)Dcm_Routine_0xF1B0_SignalCfg[2] =
{
    {
        DCM_OPAQUE,     /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        8u, /*DcmDspRoutineSignalLength*/
        0u, /*DcmDspRoutineSignalPos*/
        DCM_BOOLEAN, /*DcmDspRoutineSignalType*/
        NULL_PTR, /*DcmDspArgumentScaling*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF159_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF159_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF159_ResultsCfg =
{
    Rte_DcmDspRequestRoutineResultsFnc_0xF159, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF159_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x5231_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x5231_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x5231_ResultsCfg =
{
    Rte_DcmDspRequestRoutineResultsFnc_5231, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x5231_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x5234_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x5234_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x5234_ResultsCfg =
{
    Rte_DcmDspRequestRoutineResultsFnc_5234, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x5234_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x5232_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x5232_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x5232_ResultsCfg =
{
    Rte_DcmDspRequestRoutineResultsFnc_5232, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x5232_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0x5235_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0x5235_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0x5235_ResultsCfg =
{
    Rte_DcmDspRequestRoutineResultsFnc_5235, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0x5235_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF1B0_RequestRoutineResultsOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineOutSignalNum*/
    &Dcm_Routine_0xF1B0_SignalCfg[0],    /*DcmDspRoutineOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRequestRoutineResultsType,DCM_CONST)Dcm_RoutineInfo_0xF1B0_ResultsCfg =
{
    Rte_DcmDspRequestRoutineResultsFnc_0xF1B0, /*DcmDspRequestResultsRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
    NULL_PTR, /*DcmDspRequestRoutineResultsCommonAuthorizationRef*/
    NULL_PTR, /*DcmDspRequestRoutineResultsIn*/
    &Dcm_Routine_0xF1B0_RequestRoutineResultsOutCfg, /*DcmDspRequestRoutineResultsOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRoutineStart container
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xFF02_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xFF02_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xFF02_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xFF02_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xFF02_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xFF02_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xFF02_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xFF02_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF159_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF159_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF159_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF159_SignalCfg[2],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF159_StartCfg =
{

     Rte_Call_Dcm_RoutineServices_DcmDspRoutine_0xF159_Start, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xF159_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF159_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x5231_StartCfg =
{

     Rte_DcmRoutineStart_0x5231, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     NULL_PTR, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x5234_StartCfg =
{

     Rte_DcmRoutineStart_0x5234, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     NULL_PTR, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x5232_StartCfg =
{

     Rte_DcmRoutineStart_0x5232, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     NULL_PTR, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0x5235_StartCfg =
{

     Rte_DcmRoutineStart_0x5235, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     NULL_PTR, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF015_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF015_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF015_StartCfg =
{

     Rte_DcmRoutineStart_0xF015, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF015_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF0AD_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF0AD_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF0AD_StartCfg =
{

     Rte_DcmRoutineStart_F1AD, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xF0AD_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     NULL_PTR, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF0AE_StartRoutineInCfg =
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF0AE_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF0AE_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF0AE_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF0AE_StartCfg =
{

     Rte_DcmRoutineStart_F1AE, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     &Dcm_Routine_0xF0AE_StartRoutineInCfg, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF0AE_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF0AF_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF0AF_SignalCfg[0],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF0AF_StartCfg =
{

     Rte_DcmRoutineStart_F1AF, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF0AF_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType,DCM_CONST)Dcm_Routine_0xF1B0_StartRoutineOutCfg =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    1u,                                  /*RoutineInOutSignalNum*/
    &Dcm_Routine_0xF1B0_SignalCfg[1],    /*DcmDspRoutineInOutSignal*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType,DCM_CONST)Dcm_RoutineInfo_0xF1B0_StartCfg =
{

     Rte_DcmRoutineStart_F1B0, /*DcmDspStartRoutineFnc*//* PRQA S 0674 */ /* MISRA Rule 1.1 */
     NULL_PTR, /*DcmDspStartRoutineCommonAuthorizationRef*/
     NULL_PTR, /*DcmDspStartRoutineIn*/
     &Dcm_Routine_0xF1B0_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************
 *DcmDspRoutineStop container
 **********************************/
/***********************************
 *DcmDspRoutine container configration
 **********************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineType,DCM_CONST)Dcm_DspRoutineCfg[11] =
{
    { /* DcmDspRoutine_0xFF02 */
        0xFF02u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xFF02_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF159 */
        0xF159u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[1],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF159_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xF159_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x5231 */
        0x5231u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x5231_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x5231_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x5234 */
        0x5234u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x5234_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x5234_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x5232 */
        0x5232u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x5232_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x5232_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0x5235 */
        0x5235u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0x5235_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x5235_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF015 */
        0xF015u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xF015_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF0AD */
        0xF0ADu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xF0AD_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF0AE */
        0xF0AEu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xF0AE_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF0AF */
        0xF0AFu, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[0],     /*DcmDspCommonAuthorizationRef*/
        NULL_PTR, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xF0AF_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    },
    { /* DcmDspRoutine_0xF1B0 */
        0xF1B0u, /*DcmDspRoutineId*/
        0u, /*DcmDspRoutineInfoByte*/
        FALSE, /*DcmDspRoutineUsePort*/
        TRUE,     /*DcmDspRoutineUsed*/
        &Dcm_DspCommonAuthorizationCfg[2],     /*DcmDspCommonAuthorizationRef*/
        &Dcm_RoutineInfo_0xF1B0_ResultsCfg, /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0xF1B0_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR, /*DcmDspStopRoutine*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/******************Dsp Security Row**************/
/************************************************
 ****DcmDspSecurityRow container(Multiplicity=0..31)****
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSecurityRowType,DCM_CONST)Dcm_DspSecurityRow[3] =
{
    { /* DcmDspSecurityRow_level_1 */
        1u,          /*DcmDspSecurityLevel*/
        4u,          /*DcmDspSecuritySeedSize*/
        4u,          /*DcmDspSecurityKeySize*/
        0u,          /*DcmDspSecurityADRSize*/
        TRUE,        /*DcmDspSecurityAttemptCounterEnabled*/
        3u,    /*DcmDspSecurityNumAttDelay*/
        10000u,  /*DcmDspSecurityDelayTime,10s */
        10000u,/*DcmDspSecurityDelayTimeOnBoot*/
        /* PRQA S 0674++ */ /* MISRA Rule 1.1 */                
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level1_GetSeed,    /*Dcm_GetSeedFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level1_CompareKey,    /*Dcm_CompareKeyFnc*/
        Rte_GetSecurityAttemptCounter_Level1,    /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_SetSecurityAttemptCounter_Level1,    /*DcmDspSecurityUsePort*/
        /* PRQA S 0674-- */ /* MISRA Rule 1.1 */
        USE_ASYNCH_FNC,    /*DcmDspSecurityUsePort*/
    },
    { /* DcmDspSecurityRow_level_5 */
        3u,          /*DcmDspSecurityLevel*/
        4u,          /*DcmDspSecuritySeedSize*/
        4u,          /*DcmDspSecurityKeySize*/
        0u,          /*DcmDspSecurityADRSize*/
        TRUE,        /*DcmDspSecurityAttemptCounterEnabled*/
        3u,    /*DcmDspSecurityNumAttDelay*/
        10000u,  /*DcmDspSecurityDelayTime,10s */
        10000u,/*DcmDspSecurityDelayTimeOnBoot*/
        /* PRQA S 0674++ */ /* MISRA Rule 1.1 */                
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level5_GetSeed,    /*Dcm_GetSeedFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Level5_CompareKey,    /*Dcm_CompareKeyFnc*/
        Rte_GetSecurityAttemptCounter_Level5,    /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_SetSecurityAttemptCounter_Level5,    /*DcmDspSecurityUsePort*/
        /* PRQA S 0674-- */ /* MISRA Rule 1.1 */
        USE_ASYNCH_FNC,    /*DcmDspSecurityUsePort*/
    },
    { /* DcmDspSecurityRow_level_FBL */
        5u,          /*DcmDspSecurityLevel*/
        4u,          /*DcmDspSecuritySeedSize*/
        4u,          /*DcmDspSecurityKeySize*/
        0u,          /*DcmDspSecurityADRSize*/
        TRUE,        /*DcmDspSecurityAttemptCounterEnabled*/
        3u,    /*DcmDspSecurityNumAttDelay*/
        10000u,  /*DcmDspSecurityDelayTime,10s */
        10000u,/*DcmDspSecurityDelayTimeOnBoot*/
        /* PRQA S 0674++ */ /* MISRA Rule 1.1 */                
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_LevelFBL_GetSeed,    /*Dcm_GetSeedFnc*/
        Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_LevelFBL_CompareKey,    /*Dcm_CompareKeyFnc*/
        Rte_GetSecurityAttemptCounter_LevelFBL,    /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_SetSecurityAttemptCounter_LevelFBL,    /*DcmDspSecurityUsePort*/
        /* PRQA S 0674-- */ /* MISRA Rule 1.1 */
        USE_ASYNCH_FNC,    /*DcmDspSecurityUsePort*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/************************************************
 ****DcmDspSecurity container(Multiplicity=1)****
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSecurityType,DCM_CONST)Dcm_DspSecurity =
{
    &Dcm_DspSecurityRow[0],    /*pDcm_DspSecurityRow*/
    3u,    /*DcmDspSecurityRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Session Row**************/
/************************************************
 ****DcmDspSessionRow container(Multiplicity=0..31)
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSessionRowType,DCM_CONST)Dcm_DspSessionRow[3] =
{
    { /* DcmDspSessionRow_default */
        DCM_NO_BOOT,    /*DcmDspSessionForBoot*/
        1u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    },
    { /* DcmDspSessionRow_program */
        DCM_SYS_BOOT,    /*DcmDspSessionForBoot*/
        2u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    },
    { /* DcmDspSessionRow_extended */
        DCM_NO_BOOT,    /*DcmDspSessionForBoot*/
        3u,    /*DcmDspSessionLevel*/
        50u,    /*DcmDspSessionP2ServerMax*/
        5000u,    /*DcmDspSessionP2StarServerMax*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/************************************************
 *******Dcm_DspSession container(Multiplicity=1)*
 ************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspSessionType,DCM_CONST)Dcm_DspSession =
{
    &Dcm_DspSessionRow[0],    /*pDcmDspSessionRow*/
    3u,        /*DcmDspSessionRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DspPeriodicTransmissionTypes,DCM_CONST)Dcm_DspPeriodicTransmission =
{
    10UL,/*DcmDspPeriodicTransmissionFastRate*/
    20UL,/*DcmDspPeriodicTransmissionMediumRate*/
    30UL,/*DcmDspPeriodicTransmissionSlowRate*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****************DcmDsp container configration********
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DspCfgType,DCM_CONST) Dcm_DspCfg =
{
    NULL_PTR,    /*DcmDspDDDIDcheckPerSourceDID*/
    DCM_BIG_ENDIAN,    /*DcmDspDataDefaultEndianness*/
    FALSE,/*DcmDspEnableObdMirror*/
    5,/*DcmDspMaxDidToRead*/
    DCM_DSP_MAX_PERIODIC_DID_TO_READ,/*DcmDspMaxPeriodicDidToRead*/
    0u,/*DcmDspPowerDownTime*/
    BEFORE_RESET,    /*DcmResponseToEcuReset*/
    NULL_PTR,        /*pDcmDspClearDTC*/
    &Dcm_DspComControlCfg,        /*pDcmDspComControl*/
    &Dcm_DspCommonAuthorizationCfg[0],        /*pDcmDspCommonAuthorization*/
    &Dcm_DspControlDTCSettingCfg,    /*pDcmDspControlDTCSetting*/
    &Dcm_DspDataCfg[0],    /*pDcmDspData*/    NULL_PTR,    /*pDcmDspDataInfo*/
    144u,    /*DcmDspDidNum*/
    &Dcm_DspDidCfg[0],        /*pDcmDspDid*/
    9u,    /*DcmDspDidInfoNum*/
    &Dcm_DspDidInfoCfg[0],        /*pDcmDspDidInfo*/
    0u,    /*DcmDspDidRangeNum*/
    NULL_PTR,        /*pDcmDspDidRange*/
    NULL_PTR, /*pDcmDspMemory*/

    NULL_PTR,    /*DcmDspRequestFileTransfer*/

    11u,        /*DcmDspRoutineNum*/
    &Dcm_DspRoutineCfg[0],    /*pDcmDspRoutine*/

    &Dcm_DspSecurity,  /* pDcm_DspSecurity */
    &Dcm_DspSession,  /* pDcm_DspSession */

    DCM_DSP_MAX_PERIODIC_DID_SCHEDULER,
    &Dcm_DspPeriodicTransmission,

};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSD container configration*****************************
 *****************************************************************************************/

/*DcmDsdService_10 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x10_2_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x10_3_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x10[3] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x10_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x10_3_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_11 SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x11[3] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_19 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x19_1_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x19_2_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x19_4_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x19_6_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x19_A_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x19[5] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x19_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x19_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x4u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x19_4_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x6u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x19_6_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0xAu,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x19_A_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        2u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_27 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x27_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x27_2_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x27_5_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x27_6_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x27_9_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x27_A_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x27[6] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x27_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x27_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x5u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x27_5_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x6u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x27_6_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x9u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x27_9_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0xAu,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x27_A_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_28 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x28_0_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x28_3_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x28_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x28_2_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x28[4] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x0u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x28_0_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x28_3_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x28_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x28_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_31 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x31_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x31_2_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x31_3_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x31[3] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x31_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x31_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x31_3_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_3E SubService*/

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x3E[1] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x0u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR,    /*DcmDsdSubServiceSessionLevelRef*/
        0u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_85 SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x85_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x85_2_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x85[2] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x85_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x2u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,    /*DcmDsdSubServiceSecurityLevelRef*/
        0u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x85_2_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*DcmDsdService_2C SubService*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2C_1_SecRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2C_1_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2C_3_SecRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2C_3_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdSubServiceCfgType,DCM_CONST)Dcm_DcmDsdServiceTable_DsdSubService_UDS0x2C[2] =
{
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x1u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        &Dcm_DcmDsdServiceTable_UDS0x2C_1_SecRef[0],    /*DcmDsdSubServiceSecurityLevelRef*/
        1u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2C_1_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    },
    {
        NULL_PTR,    /*DcmDsdSubServiceFnc*/
        0x3u,    /*DcmDsdSubServiceId*/
        TRUE,    /*DcmDsdSubServiceUsed*/
        NULL_PTR,    /*DcmDsdSubServiceModeRuleRef*/
        &Dcm_DcmDsdServiceTable_UDS0x2C_3_SecRef[0],    /*DcmDsdSubServiceSecurityLevelRef*/
        1u,    /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2C_3_SesRef[0],    /*DcmDsdSubServiceSessionLevelRef*/
        1u    /*DcmDsdSubServiceSessionLevel_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*UDS Service session and security configuration*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x14_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x19_SesRef[2] = {1u, 3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2E_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x27_SesRef[2] = {3u, 2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x28_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x31_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x85_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2F_SecRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2F_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x34_SecRef[1] = {5u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x34_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x36_SecRef[1] = {5u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x36_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x37_SecRef[1] = {5u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x37_SesRef[1] = {2u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2A_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2C_SecRef[1] = {1u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(uint8,DCM_CONST)Dcm_DcmDsdServiceTable_UDS0x2C_SesRef[1] = {3u};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/*DcmDsdService DcmDsdServiceTable*/    
static  CONST(Dcm_DsdServiceCfgType,DCM_CONST)DcmDsdServiceTable_Service[17] =
{
    { /*DiagnosticSessionControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x10,    /*DcmDsdSidTabFnc*/
        0x10u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        3u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x10[0],    /*DcmDsdSubService*/
    },
    { /*ECUReset*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x11,    /*DcmDsdSidTabFnc*/
        0x11u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        3u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x11[0],    /*DcmDsdSubService*/
    },
    { /*ClearDiagnosticInformation*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x14,    /*DcmDsdSidTabFnc*/
        0x14u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x14_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*ReadDTCInformation*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x19,    /*DcmDsdSidTabFnc*/
        0x19u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x19_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        5u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x19[0],    /*DcmDsdSubService*/
    },
    { /*ReadDataByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x22,    /*DcmDsdSidTabFnc*/
        0x22u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*WriteDataByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2E,    /*DcmDsdSidTabFnc*/
        0x2Eu,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2E_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*SecurityAccess*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x27,    /*DcmDsdSidTabFnc*/
        0x27u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        2u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x27_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        6u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x27[0],    /*DcmDsdSubService*/
    },
    { /*CommunicationControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x28,    /*DcmDsdSidTabFnc*/
        0x28u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x28_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        4u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x28[0],    /*DcmDsdSubService*/
    },
    { /*RoutineControl*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x31,    /*DcmDsdSidTabFnc*/
        0x31u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x31_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        3u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x31[0],    /*DcmDsdSubService*/
    },
    { /*TesterPresent*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x3E,    /*DcmDsdSidTabFnc*/
        0x3Eu,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        0u,    /*DcmDsdSessionLevel_Num*/
        NULL_PTR,    /*pDcmDsdSessionLevelRef*/
        1u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x3E[0],    /*DcmDsdSubService*/
    },
    { /*ControlDTCSetting*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x85,    /*DcmDsdSidTabFnc*/
        0x85u,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        TRUE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x85_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        2u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x85[0],    /*DcmDsdSubService*/
    },
    { /*InputOutputControlByIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2F,    /*DcmDsdSidTabFnc*/
        0x2Fu,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2F_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2F_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*RequestDownload*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x34,    /*DcmDsdSidTabFnc*/
        0x34u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x34_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x34_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*TransferData*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x36,    /*DcmDsdSidTabFnc*/
        0x36u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x36_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x36_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*RequestTransferExit*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x37,    /*DcmDsdSidTabFnc*/
        0x37u,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x37_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x37_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*ReadDataByPeriodicIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2A,    /*DcmDsdSidTabFnc*/
        0x2Au,    /*DcmDsdServiceId*/
        FALSE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        0u, /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2A_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        0u,    /*DcmDsdSubService_Num*/
        NULL_PTR,    /*DcmDsdSubService*/
    },
    { /*DynamicallyDefineDataIdentifier*/
        TRUE,    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2C,    /*DcmDsdSidTabFnc*/
        0x2Cu,    /*DcmDsdServiceId*/
        TRUE,    /*DcmDsdSubfuncAvial*/
        FALSE,  /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,    /*DcmDsdModeRuleRef*/
        1u, /*DcmDsdSecurityLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2C_SecRef[0],    /*pDcmDsdSecurityLevelRef*/
        1u,    /*DcmDsdSessionLevel_Num*/
        &Dcm_DcmDsdServiceTable_UDS0x2C_SesRef[0],    /*pDcmDsdSessionLevelRef*/
        2u,    /*DcmDsdSubService_Num*/
        &Dcm_DcmDsdServiceTable_DsdSubService_UDS0x2C[0],    /*DcmDsdSubService*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/
/*DCM Support Service Table(Multiplicity=1..256)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DsdServiceTableCfgType,DCM_CONST)Dcm_DsdServiceTable[DCM_SERVICE_TAB_NUM]=
{
    {
        0x0u,    /*DcmDsdSidTabId*/
        &DcmDsdServiceTable_Service[0],    /*pDcmDsdService*/
        17u    /*DcmDsdSidTab_ServiceNum*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/

/**********************************************************************/
/*Dsd container(Multiplicity=1)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DsdCfgType,DCM_CONST)Dcm_DsdCfg =
{
        /*DcmDsdServiceReqManufacturerNoti_PortNum*/
        /*DcmDsdServiceReqSupplierNoti_PortNum*/
    &Dcm_DsdServiceTable[0],    /*pDcmDsdServiceTable*/
    DCM_SERVICE_TAB_NUM        /*DcmDsdServiceTable_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSL container configration*****************************
 *****************************************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/*DcmDslBuffer container(Multiplicity=1..256)*/
static  CONST(Dcm_DslBufferType,DCM_CONST)Dcm_DslBufferCfg[DCM_CHANNEL_NUM] =
{
    {/* DcmDslBuffer_Rx*/
        0x0u,    /*Dcm_DslBufferId*/
        2048u,    /*Dcm_DslBufferSize*/
        0u    /*offset*/
    },
    {/* DcmDslBuffer_Tx*/
        0x1u,    /*Dcm_DslBufferId*/
        2048u,    /*Dcm_DslBufferSize*/
        2048u    /*offset*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************/
/*DcmDslDiagResp container(Multiplicity=1)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DslDiagRespType,DCM_CONST)Dcm_DslDiagRespCfg =
{
    TRUE,        /*DcmDslDiagRespOnSecondDeclinedRequest*/
    10u        /*DcmDslDiagRespMaxNumRespPend*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslCallbackDCMRequestService port configuration(Multiplicity=1..*)
 *****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static  CONST(Dcm_DslCallbackDCMRequestServiceType,DCM_CONST)Dcm_DslCallbackDCMRequestServiceCfg[1] =
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */
{
    {
        DcmDslCallbackDCMRequestService_0_StartProtocol,    /*StartProtocol*/
        DcmDslCallbackDCMRequestService_0_StopProtocol,    /*StopProtocol*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/********************UDS protocol Connection configuration*******************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolRxType,DCM_CONST)Dsl_Protocol_Connection_RxCfg[DCM_DSL_RX_ID_NUM]=
{
    {
        0x0u,              /*DcmDslParentConnectionCtrlId*/
        DCM_FUNCTIONAL,    /*DcmDslProtocolRxAddrType*/
        DCM_DCM_RX_Diag_FuncReq_OBD,       /*DcmDslProtocolRxPduId*/

    },
    {
        0x0u,              /*DcmDslParentConnectionCtrlId*/
        DCM_PHYSICAL,    /*DcmDslProtocolRxAddrType*/
        DCM_DCM_RX_Phy_Diag_PhyReq_CCU_OBD,       /*DcmDslProtocolRxPduId*/

    },
    {
        0x1u,              /*DcmDslParentConnectionCtrlId*/
        DCM_FUNCTIONAL,    /*DcmDslProtocolRxAddrType*/
        DCM_DCM_RX_Diag_FuncReq_BAC,       /*DcmDslProtocolRxPduId*/

    },
    {
        0x1u,              /*DcmDslParentConnectionCtrlId*/
        DCM_PHYSICAL,    /*DcmDslProtocolRxAddrType*/
        DCM_DCM_RX_Phy_Diag_PhyReq_BAC,       /*DcmDslProtocolRxPduId*/

    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolTxType,DCM_CONST)Dsl_Protocol_Connection_TxCfg[DCM_DSL_TX_ID_NUM]=
{
    {
        0x0u,            /*parent connection id*/
        DCM_DCM_TX_Diag_Resp_CCU_OBD,       /*DcmDslProtocolTxPduId*/
        DCM_PDUR_DCM_TX_Diag_Resp_CCU_OBD,  /*DcmDslProtocolTx Pdu Id of PduR*/
    },
    {
        0x0u,            /*parent connection id*/
        DCM_DCM_TX_Diag_Resp_CCU_OBD_2A,       /*DcmDslProtocolTxPduId*/
        DCM_PDUR_DCM_TX_Diag_Resp_CCU_OBD_2A,   /*DcmDslProtocolTx Pdu Id of PduR*/
    },
    {
        0x1u,            /*parent connection id*/
        DCM_DCM_TX_Diag_Resp_BAC,       /*DcmDslProtocolTxPduId*/
        DCM_PDUR_DCM_TX_Diag_Resp_BAC,  /*DcmDslProtocolTx Pdu Id of PduR*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static  CONST(Dcm_DslPeriodicConnectionType,DCM_CONST)Dcm_DslPeriodicConnection0[1] =
{
    {
        DCM_DCM_TX_Diag_Resp_CCU_OBD_2A,
        PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD_2A,

    },
};
static  CONST(Dcm_DslPeriodicTransmissionType,DCM_CONST)Dcm_DslPeriodicTransmission[DCM_PERIODICCONNECTION_NUM] =
{
    {
        Dcm_DslPeriodicConnection0,/*DcmDslPeriodicTxConfirmationPduId*/
        1u,/*DcmPeriodicTxPduIdNum*/
    },
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Connection1,Mainconnection,ProtocolTx configration(Multiplicity=1..*)*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslMainConnectionType,DCM_CONST) Dsl_Protocol_MainConnectionCfg[DCM_MAINCONNECTION_NUM] =
{
    {
        0x00000000u,                            /*DcmDslProtocolRxTesterSourceAddr*/
        &Dcm_DslPeriodicTransmission[0],  /*pDcmDslPeriodicTranmissionConRef*/
        4u,                                     /*DcmDslProtocolComMChannelId*/
        NULL_PTR,  /*pDcmDslROEConnectionRef*/
        &Dsl_Protocol_Connection_RxCfg[0],    /*pDcmDslProtocolRx*/
        2u,                                   /*DcmDslProtocolRx_Num*/
        &Dsl_Protocol_Connection_TxCfg[0],  /*pDcmDslProtocolTx*/
        1u                                    /*DcmDslProtocolTx_Num*/
    },
    {
        0x00000000u,                            /*DcmDslProtocolRxTesterSourceAddr*/
        NULL_PTR,  /*pDcmDslPeriodicTranmissionConRef*/
        5u,                                     /*DcmDslProtocolComMChannelId*/
        NULL_PTR,  /*pDcmDslROEConnectionRef*/
        &Dsl_Protocol_Connection_RxCfg[2],    /*pDcmDslProtocolRx*/
        2u,                                   /*DcmDslProtocolRx_Num*/
        &Dsl_Protocol_Connection_TxCfg[2],  /*pDcmDslProtocolTx*/
        1u                                    /*DcmDslProtocolTx_Num*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Connection1 configration*/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslConnectionType,DCM_CONST)Dsl_Protocol_ConnectionCfg[DCM_CONNECTION_NUM]=
{
    {
        0x0u,                                /*parent protocolRow id*/
        &Dsl_Protocol_MainConnectionCfg[0],    /*pDcmDslMainConnection*/
        NULL_PTR,                             /*pDcmDslPeriodicTransmission*/
        NULL_PTR                              /*pDcmDslResponseOnEvent*/
    },
    {
        0x1u,                                /*parent protocolRow id*/
        &Dsl_Protocol_MainConnectionCfg[1],    /*pDcmDslMainConnection*/
        NULL_PTR,                             /*pDcmDslPeriodicTransmission*/
        NULL_PTR                              /*pDcmDslResponseOnEvent*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*****************************************************
 ****Dcm_DslProtocolRow container configration(Multiplicity=1..*)*******
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslProtocolRowType,DCM_CONST)Dsl_ProtocolRowCfg[DCM_DSLPROTOCOLROW_NUM_MAX] =
{
    {
        DCM_UDS_ON_CAN,        /*DcmDslProtocolID*/
        0u,                    /*DcmDslProtocolPreemptTimes*/
        0u,                    /*DcmDslProtocolPriority*/
        TRUE,                /*true-protocol is available*/
        DCM_PROTOCAL_TRAN_NOT_VALID,
        TRUE,                /*True-send 0x78 before transitioning to the bootloader */
        15u,                     /*DcmTimStrP2ServerAdjust*/
        0u,                /*DcmTimStrP2StarServerAdjust*/
        &Dcm_DslBufferCfg[0],/*DcmDslProtocolRxBuffer*/
        &Dcm_DslBufferCfg[1],/*DcmDslProtocolTxBuffer*/
        0u,                 /*DcmDslServiceTableId*/
        &Dsl_Protocol_ConnectionCfg[0], /*DcmDslConnection*/
        FALSE,              /*DcmDslProtocolRequestQueued*/
    },
    {
        DCM_UDS_ON_CAN,        /*DcmDslProtocolID*/
        0u,                    /*DcmDslProtocolPreemptTimes*/
        1u,                    /*DcmDslProtocolPriority*/
        TRUE,                /*true-protocol is available*/
        DCM_PROTOCAL_TRAN_NOT_VALID,
        TRUE,                /*True-send 0x78 before transitioning to the bootloader */
        0u,                     /*DcmTimStrP2ServerAdjust*/
        0u,                /*DcmTimStrP2StarServerAdjust*/
        &Dcm_DslBufferCfg[0],/*DcmDslProtocolRxBuffer*/
        &Dcm_DslBufferCfg[1],/*DcmDslProtocolTxBuffer*/
        0u,                 /*DcmDslServiceTableId*/
        &Dsl_Protocol_ConnectionCfg[1], /*DcmDslConnection*/
        FALSE,              /*DcmDslProtocolRequestQueued*/
    }
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslProtocol container configration(Multiplicity=1)
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
static CONST(Dcm_DslProtocolType,DCM_CONST)Dcm_DslProtocol =
{
    &Dsl_ProtocolRowCfg[0],    /*pDcmDslProtocolRow*/
    DCM_DSLPROTOCOLROW_NUM_MAX,    /*DcmDslProtocolRow_Num*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****************DcmDsl container configration*****
 ****************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_DslCfgType,DCM_CONST)Dcm_DslCfg =
{
    DCM_CHANNEL_NUM,        /*Number of Channel configration*/
    &Dcm_DslBufferCfg[0],    /*DcmDslBuffer*/
    1u,                        /*Number of DslCallbackDCMRequestService port*/
    &Dcm_DslCallbackDCMRequestServiceCfg[0],    /*pDcmDslCallback_DCMRequestService*/
    &Dcm_DslDiagRespCfg,       /*reference to DcmDslDiagResp configration*/
    &Dcm_DslProtocol,        /*reference to DcmDslProtocol configration*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_CfgType,DCM_CONST)Dcm_Cfg =
{
    &Dcm_DslCfg,    /*pDcmDslCfg*/
    &Dcm_DsdCfg,    /*pDcmDsdCfg*/
    &Dcm_DspCfg,    /*pDcmDspCfg*/
    NULL_PTR,        /*pDcmPageBufferCfg*/
    NULL_PTR,        /*pDcmProcessingConditionsCfg*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************
 ***********************DcmGeneral Container***************************
 **********************************************************************/
#define   DCM_START_SEC_CONST_UNSPECIFIED
#include  "Dcm_MemMap.h"
CONST(Dcm_GeneralCfgType,DCM_CONST)Dcm_GeneralCfg =
{
    FALSE, /*DcmDDDIDStorage*/
    DCM_DEV_ERROR_DETECT, /*DcmDevErrorDetect*//* PRQA S 1295 */ /* MISRA Rule 10.3 */
    NULL_PTR, /*DcmHeaderFileInclusion*/
    DCM_RESPOND_ALL_REQUEST, /*DcmRespondAllRequest*//* PRQA S 1295 */ /* MISRA Rule 10.3 */
    DCM_VERSION_INFO_API, /*DcmVersionInfoApi*//* PRQA S 1295 */ /* MISRA Rule 10.3 */
    10, /*DcmTaskTime*/
    NULL_PTR, /*DcmVinRef*/
};
#define  DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

