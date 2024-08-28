/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    :                                                            **
**                                                                           **
**  Created on  : 2020/5/6 14:29:43                                          **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION :                                                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */
#ifndef DCM_TYPES_H
#define DCM_TYPES_H

#include "Std_Types.h"
#include "ComStack_Types.h"
#include "Dcm_Cfg.h"
#include "DcmDsl_MsgManage.h"
#include "Dem.h"
#include "SchM_Dcm.h"
#include "ComM_Dcm.h"
#include "Det.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
typedef uint8 Dcm_DidSupportedType;
#define DCM_DID_SUPPORTED     ((Dcm_DidSupportedType)0x00)
#define DCM_DID_NOT_SUPPORTED ((Dcm_DidSupportedType)0x01)

typedef uint8 Dcm_CommunicationModeType;
#define DCM_ENABLE_RX_TX_NORM            0x00u
#define DCM_ENABLE_RX_DISABLE_TX_NORM    0x01u
#define DCM_DISABLE_RX_ENABLE_TX_NORM    0x02u
#define DCM_DISABLE_RX_TX_NORMAL         0x03u
#define DCM_ENABLE_RX_TX_NM              0x04u
#define DCM_ENABLE_RX_DISABLE_TX_NM      0x05u
#define DCM_DISABLE_RX_ENABLE_TX_NM      0x06u
#define DCM_DISABLE_RX_TX_NM             0x07u
#define DCM_ENABLE_RX_TX_NORM_NM         0x08u
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM 0x09u
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM 0x0Au
#define DCM_DISABLE_RX_TX_NORM_NM        0x0Bu

typedef uint8 Dcm_EcuStartModeType;
#define DCM_COLD_START ((Dcm_EcuStartModeType)0x00)
#define DCM_WARM_START ((Dcm_EcuStartModeType)0x01)

/**********************************************************************
 *            UDS 0x36 service status define
 **********************************************************************/
#define DCM_UDS0X36_INIT        (0u)
#define DCM_UDS0X36_TO_DOWNLOAD (1u)
#define DCM_UDS0X36_TO_UPLOAD   (2u)
#define DCM_UDS0X38_0x01        (3u)
#define DCM_UDS0X38_0x02        (4u)
#define DCM_UDS0X38_0x03        (5u)
#define DCM_UDS0X38_0x04        (6u)
#define DCM_UDS0X38_0x05        (7u)

/****************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
    DCM_EQUALS = 0,
    DCM_EQUALS_NOT,
    DCM_GREATER_OR_EQUAL,
    DCM_GREATER_THAN,
    DCM_LESS_OR_EQUAL,
    DCM_LESS_THAN
} Dcm_ConditionType;

typedef struct
{
    const Dcm_ConditionType DcmConditionType;
    /*some type referenced from other modules*/
} Dcm_ModeConditionCfgType;

typedef enum
{
    DCM_AND = 0,
    DCM_OR
} Dcm_LogicalOperatorType;

typedef struct
{
    const Dcm_LogicalOperatorType DcmLogicalOperator;
    const uint8 DcmModeRuleNrcValue;
} Dcm_ModeRuleCfgType;

typedef struct
{
    P2CONST(Dcm_ModeConditionCfgType, TYPEDEF, DCM_CONST) DcmModeCondition;
    P2CONST(Dcm_ModeRuleCfgType, TYPEDEF, DCM_CONST) DcmModeRule;
    /*DcmArgumentRef*/
} Dcm_ProcessingConditionsCfgType;

/***************************************************
 ********DcmDsp Container(Multiplicity=1)***********
 ***************************************************/
typedef enum
{
    DCM_BIG_ENDIAN = 0,
    DCM_LITTLE_ENDIAN = 1,
    DCM_OPAQUE = 2
} Dcm_DspEndianType;

/*security access*/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_GetSeedFncType)(
#if (DCM_SECURITY_ADR_MAXSIZE > 0)
    const uint8* SecurityAccessDataRecord,
#endif
    Dcm_OpStatusType OpStatus,
    uint8* Seed,
    Dcm_NegativeResponseCodeType* ErrorCode);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_CompareKeyFncType)(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) key,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_GetSecurityAttemptCounterFncType)(
    Dcm_OpStatusType OpStatus,
    uint8* AttemptCounter);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_SetSecurityAttemptCounterFncType)(
    Dcm_OpStatusType OpStatus,
    uint8 AttemptCounter);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/********************************Clear DTC****************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ClearDTCCheckFncType)(
    uint32 GoDTC,
    Dcm_NegativeResponseCodeType* ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

typedef struct
{
    const Dcm_ClearDTCCheckFncType DcmDsp_ClearDTCCheckFnc;
    //  P2CONST(Dcm_ModeRuleCfgType,TYPEDEF,DCM_CONST) DcmDspClearDTCModeRuleRef;
} Dcm_DspClearDTCType;

/********************************Com Control**************************************/
typedef struct
{
    const boolean DcmDspComControlAllChannelUsed;
    const NetworkHandleType DcmDspComMChannelId;
} Dcm_DspComControlAllChannelType;

typedef struct
{
    uint8 idle; /*Reference to [ DcmModeRule ]*/
} Dcm_DspComControlSettingType;

typedef struct
{
    const boolean DcmDspComControlSpecificChannelUsed;
    const uint8 DcmDspSubnetNumber;
    const NetworkHandleType DcmDspSpecificComMChannelId;
} Dcm_DspComControlSpecificChannelType;

typedef struct
{
    const uint16 DcmDspComControlSubNodeId;
    const boolean DcmDspComControlSubNodeUsed;
    const NetworkHandleType DcmDspComMSubNodeChannelId;
} Dcm_DspComControlSubNodeType;

typedef struct
{
    const uint8 DcmDspComControlAllChannelNum;
    P2CONST(Dcm_DspComControlAllChannelType, TYPEDEF, DCM_CONST) DcmDspComControlAllChannel;
    P2CONST(Dcm_DspComControlSettingType, TYPEDEF, DCM_CONST) DcmDspComControlSetting;
    const uint8 DcmDspComControlSpecificChannelNum;
    /* PRQA S 0779++ */ /* MISRA Rule 5.2 */
    P2CONST(Dcm_DspComControlSpecificChannelType, TYPEDEF, DCM_CONST) DcmDspComControlSpecificChannel;
    /* PRQA S 0779-- */ /* MISRA Rule 5.2 */
    const uint8 DcmDspComControlSubNodeNum;
    P2CONST(Dcm_DspComControlSubNodeType, TYPEDEF, DCM_CONST) DcmDspComControlSubNode;
} Dcm_DspComControlType;

typedef struct
{
    //  P2CONST(Dcm_ModeRuleCfgType,TYPEDEF,DCM_CONST) DcmDspCommonAuthorizationModeRuleRef;
    const uint8 DcmDspCommonAuthorizationSecurityLevelRefNum;
    /* PRQA S 0779++ */ /* MISRA Rule 5.2 */
    P2CONST(uint8, TYPEDEF, DCM_CONST) DcmDspCommonAuthorizationSecurityLevelRef;
    const uint8 DcmDspCommonAuthorizationSessionRefNum;
    P2CONST(uint8, TYPEDEF, DCM_CONST) DcmDspCommonAuthorizationSessionRef;
    /* PRQA S 0779-- */ /* MISRA Rule 5.2 */
    /*Reference to [ DcmDspSessionRow ]*/
} Dcm_DspCommonAuthorizationType;

/*************************Control DTC Setting******************************************/
typedef struct
{
    const boolean DcmSupportDTCSettingControlOptionRecord;
    //  P2CONST(Dcm_ModeRuleCfgType,TYPEDEF,DCM_CONST) DcmDspControlDTCSettingReEnableModeRuleRef;
} Dcm_DspControlDTCSettingType;

typedef struct
{
    const uint16 DcmDspDataScalingInfoSize;
} Dcm_DspDataInfoType;

typedef enum
{
    USE_ASYNCH_CLIENT_SERVER,
    USE_ASYNCH_FNC
} Dcm_DspSecurityUsePortType;

/*Multiplicity=0..31*/
typedef struct
{
    const uint8 DcmDspSecurityLevel;    /*Range:1~63*/
    const uint8 DcmDspSecuritySeedSize; /*size of the security seed (in Bytes),Range:1~255*/
    const uint8 DcmDspSecurityKeySize;  /*size of the security key (in Bytes),Range:1~255*/
    const uint8 DcmDspSecurityADRSize;
    /*Size of the AccessDataRecord used in GetSeed,Range:1~255*/
    const boolean DcmDspSecurityAttemptCounterEnabled;
    const uint8 DcmDspSecurityNumAttDelay;
    /*Number of failed security accesses after which the delay time is activated,Range:1~255*/
    const uint16 DcmDspSecurityDelayTime;
    /*Delay time after failed security access(unit:ms)*/
    const uint16 DcmDspSecurityDelayTimeOnBoot; /*Start delay timer on power on(unit:ms)*/
    const Dcm_GetSeedFncType Dcm_GetSeedFnc;
    const Dcm_CompareKeyFncType Dcm_CompareKeyFnc;
    const Dcm_GetSecurityAttemptCounterFncType Dcm_GetSecurityAttemptCounterFnc;
    const Dcm_SetSecurityAttemptCounterFncType Dcm_SetSecurityAttemptCounterFnc;
    const Dcm_DspSecurityUsePortType DcmDspSecurityUsePort;
} Dcm_DspSecurityRowType;

/*Multiplicity = 1*/
typedef struct
{
    P2CONST(Dcm_DspSecurityRowType, TYPEDEF, DCM_CONST) pDcm_DspSecurityRow;
    /*reference DspSecurityRow container*/
    const uint8 DcmDspSecurityRow_Num; /*Number of DspSecurityRow*/
} Dcm_DspSecurityType;

typedef enum
{
    DCM_NO_BOOT,
    DCM_OEM_BOOT,
    DCM_OEM_BOOT_RESPAPP,
    DCM_SYS_BOOT,
    DCM_SYS_BOOT_RESPAPP
} Dcm_DspSessionForBootType;

/*DcmDspSession */
/*Multiplicity=0..31*/
typedef struct
{
    const Dcm_DspSessionForBootType DcmDspSessionForBoot;
    const uint8 DcmDspSessionLevel; /*hex value of the Session contro;Range:1~126*/
    const uint16 DcmDspSessionP2ServerMax;
    /*This is the session value for P2ServerMax(in ms);Range 0 .. 1*/
    const uint16 DcmDspSessionP2StarServerMax;
    /*This is the session value for P2*ServerMax(in ms);Range 0 .. 100*/
} Dcm_DspSessionRowType;

/*Multiplicity=1*/
typedef struct
{
    P2CONST(Dcm_DspSessionRowType, TYPEDEF, DCM_CONST) pDcmDspSessionRow;
    /*reference DspSessionRow container*/
    const uint8 DcmDspSessionRow_Num; /*Number of DspSessionRow*/
} Dcm_DspSessionType;

/****************************DcmDspData*************************************/

typedef enum
{
    DCM_BOOLEAN = 0,
    DCM_SINT16 = 1,
    DCM_SINT16_N = 2,
    DCM_SINT32 = 3,
    DCM_SINT32_N = 4,
    DCM_SINT8 = 5,
    DCM_SINT8_N = 6,
    DCM_UINT16 = 7,
    DCM_UINT16_N = 8,
    DCM_UINT32 = 9,
    DCM_UINT32_N = 10,
    DCM_UINT8 = 11,
    DCM_UINT8_DYN = 12,
    DCM_UINT8_N = 13,
    DCM_VARIABLE_LENGTH = 14 /*for 31*/
} Dcm_DspDataEnumType;

typedef enum
{
    USE_BLOCK_ID = 0,
    USE_DATA_ASYNCH_CLIENT_SERVER = 1,
    USE_DATA_ASYNCH_CLIENT_SERVER_ERROR = 2,
    USE_DATA_ASYNCH_FNC = 3,
    USE_DATA_ASYNCH_FNC_ERROR = 4,
    USE_DATA_SENDER_RECEIVER = 5,
    USE_DATA_SENDER_RECEIVER_AS_SERVICE = 6,
    USE_DATA_SYNCH_CLIENT_SERVER = 7,
    USE_DATA_SYNCH_FNC = 8,
    USE_ECU_SIGNAL = 9
} Dcm_DspDataUsePortEnumType;

#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
typedef enum
{
    DCM_CONTROLMASK_EXTERNAL = 0,
    DCM_CONTROLMASK_INTERNAL = 1,
    DCM_CONTROLMASK_NO = 2
} Dcm_DspDidControlMaskEnumType;

typedef struct
{
    const uint8 DcmDspDidControlMaskBitPosition;
} Dcm_DspDidControlEnableMaskType;

typedef struct
{
    const Dcm_DspDidControlMaskEnumType DcmDspDidControlMask;
    const uint8 DcmDspDidControlMaskSize;
    const uint8 DcmDspDidControlSecurityLevelRefNum;
    /*Number Of DcmDspSecurityRow Referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspDidControlSecurityLevelRow;
    /*DcmDspSecurityRow Referenced*/
    const uint8 DcmDspDidControlSessionRefNum;
    /*Number Of DcmDspSessionRow Referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspDidControlSessionRow;
    /*DcmDspSessionRow Referenced*/
    const boolean DcmDspDidFreezeCurrentState;
    /*Multiplicity=0..1; This indicates the presence of "FreezeCurrentState" and
     refers to a container defining the sizes of the parameters*/
    const boolean DcmDspDidResetToDefault;
    /*Multiplicity=0..1; This indicates the presence of "ResetToDefault" and
     refers to a container defining the sizes of the parameters*/
    const boolean DcmDspDidShortTermAdjustement;
    /*Multiplicity=0..1;This indicates the presence of "ShortTermAdjustment" and
     * refers to a container defining the sizes of the parameters*/
    /*Reference to [ DcmModeRule ]*/
    P2CONST(Dcm_DspDidControlEnableMaskType, TYPEDEF, DCM_CONST) DcmDspDidControlEnableMask;
    /*Multiplicity=0..1; This indicates the presence of "ReturnControlToEcu" and
     refers to a container defining the sizes of the parameters*/
} Dcm_DspDidControlType;

typedef struct
{
    /*modeRule*/
    const uint8 DcmDspDidReadSecurityLevelRefNum;                      /*Number Of DcmDspSecurityRow Referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspDidReadSecurityLevelRow; /*DcmDspSecurityRow Referenced*/
    const uint8 DcmDspDidReadSessionRefNum;                            /*Number Of DcmDspSessionRow Referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspDidReadSessionRow;       /*DcmDspSessionRow Referenced*/
} Dcm_DspDidReadType;

typedef struct
{
    /*modeRule*/
    const uint8 DcmDspDidWriteSecurityLevelRefNum;                      /*Number Of DcmDspSecurityRow Referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspDidWriteSecurityLevelRow; /*DcmDspSecurityRow Referenced*/
    const uint8 DcmDspDidWriteSessionRefNum;                            /*Number Of DcmDspSessionRow Referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspDidWriteSessionRow;       /*DcmDspSessionRow Referenced*/
} Dcm_DspDidWriteType;

/*DcmDspDidInfo,Multiplicity=0..* */
typedef struct
{
    const uint8 DcmDspDDDIDMaxElements;
    const boolean DcmDspDidDynamicallyDefined;
    /*Multiplicity=1,true = DID can be dynamically
     * defined false = DID can not bedynamically defined */
    // const  boolean  DcmDspDidFixedLength;
    /*Multiplicity=1,true = datalength of the DID is fixed false =
     *  datalength of the DID is variable */
    // const  uint8    DcmDspDidScalingInfoSize;
    /*Multiplicity=0..1,If Scaling information service is available for
     * this DID, it provides the size of the scaling information. */
    P2CONST(Dcm_DspDidControlType, TYPEDEF, DCM_CONST) pDcmDspDidControl;
    /*Multiplicity=0..1, the configuration (parameters)of the DID control*/
    P2CONST(Dcm_DspDidReadType, TYPEDEF, DCM_CONST) pDcmDspDidRead;
    /*Multiplicity=0..1, configuration (parameters)of the DID read*/
    P2CONST(Dcm_DspDidWriteType, TYPEDEF, DCM_CONST) pDcmDspDidWrite;
    /*Multiplicity=0..1, configuration (parameters)of the DID write*/
} Dcm_DspDidInfoType;
#endif

/*DcmDspDid,Multiplicity=0..* */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ConditionCheckReadFncType)(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) Nrc);
/* PRQA S 4604++ */ /* MISRA Rule 21.2 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_EcuSignalFncType)(uint8 action, uint8 signal);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadEcuSignalFncType)(P2VAR(uint8, AUTOMATIC, DCM_VAR) signal);
/* PRQA S 4604-- */ /* MISRA Rule 21.2 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_GetScalingInformationFncType)(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ScalingInfo,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDataFncType)(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    Dcm_NegativeResponseCodeType* ErrorCode);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDataLengthFncType)(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DidLength);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_FreezeCurrentStateFncType)(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ResetToDefaultFncType)(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReturnControlToECUFncType)(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ShortTermAdjustmentFncType)(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) pControlOptionRecord,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_WriteDataFncType)(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) data,
    uint16 dataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/*****************************************DataServices_DIDRange************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDidRangeDataLengthFncType)(
    uint16 DID,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DataLength);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_IsDidAvailableFncType)(
    uint16 DID,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_DidSupportedType, AUTOMATIC, DCM_VAR) supported);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDidDataFncType)(
    uint16 DID,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    Dcm_OpStatusType OpStatus,
    uint16 DataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_WriteDidDataFncType)(
    uint16 DID,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) Data,
    Dcm_OpStatusType OpStatus,
    uint16 DataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

typedef enum
{
    LINEAR = 0,
    SCALE_LINEAR_AND_TEXTTABLE = 1,
    TEXTTABLE = 2
} Dcm_DspDataTypeCategoryType;

typedef struct
{
    /*DcmDataElement;Foreign reference to [ VARIABLE-DATA-PROTOTYPE ]*/
    uint8 idle; /*DcmPortInterfaceMapping;Foreign reference to [ PORT-INTERFACE-MAPPING ]*/
} Dcm_DspAlternativeDataInterfaceType;

typedef struct
{
    const uint32 DcmDspDiagnosisRepresentationDataLowerRange;
    /* PRQA S 0779++ */ /* MISRA Rule 5.2 */
    const uint32 DcmDspDiagnosisRepresentationDataOffset;
    const uint32 DcmDspDiagnosisRepresentationDataResolution;
    const uint32 DcmDspDiagnosisRepresentationDataUpperRange;
    /* PRQA S 0779-- */ /* MISRA Rule 5.2 */
} Dcm_DspLinearScaleType;

typedef struct
{
    const uint32 DcmDspDiagnosisRepresentationDataValue;
    const uint32 DcmDspInternalDataValue;
} Dcm_DspTextTableMappingType;

typedef struct
{
    P2CONST(Dcm_DspDataTypeCategoryType, TYPEDEF, DCM_CONST) DcmDspDataTypeCategory;
    P2CONST(Dcm_DspLinearScaleType, TYPEDEF, DCM_CONST) DcmDspLinearScale;
    P2CONST(Dcm_DspTextTableMappingType, TYPEDEF, DCM_CONST) DcmDspTextTableMapping;
} Dcm_DspAlternativeDataPropsType;

typedef struct
{
    /*DcmApplicationDataType;Foreign reference to [ APPLICATION-PRIMITIVE-DATA-TYPE ]*/
    P2CONST(Dcm_DspTextTableMappingType, TYPEDEF, DCM_CONST) DcmDspTextTableMapping;
} Dcm_DspAlternativeDataTypeType;

typedef struct
{
    P2CONST(Dcm_DspAlternativeDataInterfaceType, TYPEDEF, DCM_CONST) DcmDspAlternativeDataInterface;
    P2CONST(Dcm_DspAlternativeDataPropsType, TYPEDEF, DCM_CONST) DcmDspAlternativeDataProps;
    P2CONST(Dcm_DspAlternativeDataTypeType, TYPEDEF, DCM_CONST) DcmDspAlternativeDataType;
} Dcm_DspDiagnosisScalingType;

typedef struct
{
    uint8 idle;
} Dcm_DspExternalSRDataElementClassType;

typedef struct
{
    const Dcm_ConditionCheckReadFncType DcmDspDataConditionCheckReadFnc;
    /*Function name to demand application if the conditions
     * (e.g. System state) to read the DID are correct.Multiplicity=0..1*/
    const boolean DcmConditionCheckReadFncUsed;
    const Dcm_EcuSignalFncType DcmDspDataEcuSignalFnc;
    const Dcm_ReadEcuSignalFncType DcmDspDataReadEcuSignalFnc;
    const Dcm_DspEndianType DcmDspDataEndianness;
    const Dcm_FreezeCurrentStateFncType DcmDspDataFreezeCurrentStateFnc;
    /*Function name to request to application to freeze the current state of
     *  an IOControl,Multiplicity=0..1*/
    const Dcm_GetScalingInformationFncType DcmDspDataGetScalingInfoFnc;
    /*Function name to request to application the
     * scaling information of the DID,Multiplicity=0..1*/
    const Dcm_ReadDataLengthFncType DcmDspDataReadDataLengthFnc;
    /*Function name to request from application the data length of a DID*/
    const Dcm_ReadDataFncType DcmDspDataReadFnc;
    /*Function name to request from application the data value of a DID*/
    const Dcm_ResetToDefaultFncType DcmDspDataResetToDefaultFnc;
    /*Function name to request to application to reset an IOControl to default value.*/
    const Dcm_ReturnControlToECUFncType DcmDspDataReturnControlToECUFnc;
    /*Function name to request to application to return control to ECU of an IOControl*/
    const Dcm_ShortTermAdjustmentFncType DcmDspDataShortTermAdjustmentFnc;
    /*Function name to request to application to adjuste the IO signal*/
    const Dcm_WriteDataFncType DcmDspDataWriteFnc;
    /*Function name to request application to write the data value of a DID*/
    const uint16 DcmDspDataSize;
    const Dcm_DspDataEnumType DcmDspDataType;
    const Dcm_DspDataUsePortEnumType DcmDspDataUsePort;
    const uint16 DcmDspDataBlockId;
    const uint8 DcmDspDataInfoIndex;
    /*if no DcmDspDataInfo Ref it is 0xFF*/
    /*DcmDspOdxDataDescription*/
    P2CONST(Dcm_DspDiagnosisScalingType, TYPEDEF, DCM_CONST) DcmDspDiagnosisScaling;
    P2CONST(Dcm_DspExternalSRDataElementClassType, TYPEDEF, DCM_CONST)
    DcmDspExternalSRDataElementClass;
} Dcm_DspDataType;

typedef struct
{
    const uint16 DcmDspDidDataPos;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDcmDspDidData;
} Dcm_DspDidSignalType;

typedef struct
{
    const boolean DcmDspDidRangeHasGaps;
    const uint16 DcmDspDidRangeIdentifierLowerLimit;
    const uint16 DcmDspDidRangeIdentifierUpperLimit;
    const Dcm_IsDidAvailableFncType DcmDspDidRangeIsDidAvailableFnc;
    const Dcm_ReadDidRangeDataLengthFncType DcmDspDidRangeReadDataLengthFnc;
    const Dcm_ReadDidDataFncType DcmDspDidRangeReadDidFnc;
    const Dcm_WriteDidDataFncType DcmDspDidRangeWriteDidFnc;
    const uint16 DcmDspDidRangeMaxDataLength;
    const boolean DcmDspDidRangeUsePort;
    const uint8 DcmDspDidRangeInfoIndex;
} Dcm_DspDidRangeType;

typedef struct DcmDspDid
{
    const uint16 DcmDspDidId; /*2 byte Identifier of the DID,Multiplicity=1*/
    const boolean DcmDspDidUsed;
    const uint8 DcmDspDidInfoIndex;
    /*Reference to DcmDspDidInfo containing information on this DID*/
    const uint8 DcmDspRefDidNum;
    /*Number Of Did referenced*/
    P2CONST(uint16, TYPEDEF, DCM_CONST) pDcmDspRefDidIdArray;
    /*Reference to DcmDspDid in case this DID refer to one or serveral other DID's*/
    // const  uint8   DcmDspDidControlRecordSizes;
    /*Number Of DcmDspDidControlRecordSizes Container*/
    // P2CONST(Dcm_DspDidControlRecordSizesType,TYPEDEF,DCM_CONST)pDcmDspDidControlRecordSizes;
    /*This container defines the sizes of the data sent
     * and received with the DID control functions*/
    const uint8 DcmDspDidSignalNum;
    P2CONST(Dcm_DspDidSignalType, TYPEDEF, DCM_CONST) pDcmDspDidSignal;
} Dcm_DspDidType;

/*****************************************************************/
#if (STD_ON == DCM_DSP_PID_FUNC_ENABLED)
typedef enum
{
    DCM_SERVICE_01 = 0,
    DCM_SERVICE_01_02 = 1,
    DCM_SERVICE_02 = 2
} Dcm_DspPidServiceEnumType;

typedef struct
{
    const uint8 DcmDspPidSupportInfoLen;
    const uint8 DcmDspPidSupportInfoPos;
} Dcm_DspPidSupportInfoType;

typedef struct
{
    const Dcm_DspEndianType DcmDspPidDataEndianness;
    const Dcm_ReadDataFncType DcmDspPidDataReadFnc;
    const Dcm_DspDataEnumType DcmDspPidDataType;
    const Dcm_DspDataUsePortEnumType DcmDspPidDataUsePort;
} Dcm_DspPidService01Type;

typedef struct
{
    uint8 idle; /*Reference to [ DemPidDataElement ]*/
} Dcm_DspPidService02Type;

typedef struct
{
    const uint8 DcmDspPidDataSupportInfoBit;
    P2CONST(Dcm_DspPidSupportInfoType, TYPEDEF, DCM_CONST) DcmDspPidDataSupportInfoRef;
} Dcm_DspPidDataSupportInfoType;

typedef struct
{
    const uint16 DcmDspPidDataPos; /*This is the position in bit of the PID structure
 and will not start at position 0 in case a support information
  is available (for packeted PIDs).*/
    const uint16 DcmDspPidDataSize;
    P2CONST(Dcm_DspPidDataSupportInfoType, TYPEDEF, DCM_CONST) pDcmDspPidDataSupportInfo;
    P2CONST(Dcm_DspPidService01Type, TYPEDEF, DCM_CONST) DcmDspPidService01;
    P2CONST(Dcm_DspPidService02Type, TYPEDEF, DCM_CONST) DcmDspPidService02;
} Dcm_DspPidDataType;

/*DcmDspPid container,Multiplicity=0..* */
typedef struct
{
    const uint8 DcmDspPidIdentifier; /*2 bytes Identifier of the PID*/
    const Dcm_DspPidServiceEnumType DcmDspPidService;
    const uint8 DcmDspPidSize;       /*Length of data associated to the PID.*/
    const boolean DcmDspPidUsed;
    const uint8 DcmDspPidSupportInfoNum;
    P2CONST(Dcm_DspPidSupportInfoType, TYPEDEF, DCM_CONST) DcmDspPidSupportInfo;
    const uint8 pDcmDspPidDataNum;
    P2CONST(Dcm_DspPidDataType, TYPEDEF, DCM_CONST) pDcmDspPidData;
} Dcm_DspPidType;
#endif

/*****************************************************************/
typedef struct
{
    const uint8 DcmDspSupportedAddressAndLengthFormatIdentifier;
} Dcm_DspAddressAndLengthFormatIdentifierType;

typedef struct
{
    const uint32 DcmDspReadMemoryRangeHigh;
    const uint32 DcmDspReadMemoryRangeLow;
    /*modeRule*/
    const uint8 DcmDspReadMemoryRangeSessionLevelRefNum; /*Number Of DcmDspSecurityRow referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspReadMemoryRangeSessionLevelRow;
    /*Reference to DcmDspSecurityRow */
    const uint8 DcmDspReadMemorySecurityLevelRefNum; /*Number Of DcmDspSecurityRow referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspReadMemorySecurityLevelRow;
    /*Reference to DcmDspSecurityRow */
} Dcm_DspReadMemoryRangeInfoType;

typedef struct
{
    const uint32 DcmDspWriteMemoryRangeHigh;
    const uint32 DcmDspWriteMemoryRangeLow;
    /*modeRule*/
    const uint8 DcmDspWriteMemoryRangeSessionLevelRefNum; /*Number Of DcmDspSecurityRow referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspWriteMemoryRangeSessionLevelRow;
    /*Reference to DcmDspSecurityRow */
    const uint8 DcmDspWriteMemorySecurityLevelRefNum; /*Number Of DcmDspSecurityRow referenced*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDspWriteMemorySecurityLevelRow;
    /*Reference to DcmDspSecurityRow */
} Dcm_DspWriteMemoryRangeInfoType;

typedef struct
{
    const uint8 DcmDspMemoryIdValue;
    const uint8 DcmDspReadMemoryRangeInfoNum;
    P2CONST(Dcm_DspReadMemoryRangeInfoType, TYPEDEF, DCM_CONST) DcmDspReadMemoryRangeInfo;
    const uint8 DcmDspWriteMemoryRangeInfoNum;
    P2CONST(Dcm_DspWriteMemoryRangeInfoType, TYPEDEF, DCM_CONST) DcmDspWriteMemoryRangeInfo;
} Dcm_DspMemoryIdInfoType;

typedef struct
{
    const uint8 DcmDspAddressAndLengthFormatIdentifierNum;
    /* PRQA S 0779++ */ /* MISRA Rule 5.2 */
    P2CONST(Dcm_DspAddressAndLengthFormatIdentifierType, TYPEDEF, DCM_CONST)
    DcmDspAddressAndLengthFormatIdentifier;
    /* PRQA S 0779++ */ /* MISRA Rule 5.2 */
    const uint8 DcmDspMemoryIdInfoNum;
    P2CONST(Dcm_DspMemoryIdInfoType, TYPEDEF, DCM_CONST) DcmDspMemoryIdInfo;
} Dcm_DspMemoryType;

/*****************************************************************/
#if (STD_ON == DCM_DSP_REQUESTCONTROL_FUNC_ENABLED)
/*DcmDspRequestControl container,Multiplicity=0..* */
typedef struct
{
    const uint8 DcmDspRequestControlInBufferSize;
    const uint8 DcmDspRequestControlOutBufferSize;
    const uint8 DcmDspRequestControlTestId; /*Test Id for OBD Service $08*/
} Dcm_DspRequestControlType;
#endif
typedef struct
{
    const uint8 DcmRequestFileTransferFileSizeParameterLength;
    const uint8 DcmRequestFileTransferLengthFormatIdentifier;
} Dcm_DspRequestFileTransferType;

/*****************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
#if (STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED)
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_StartRoutineFncType)(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_StopRoutineFncType)(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_RequestResultsRoutineFncType)(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
typedef struct
{
    uint8 idle; /*Foreign reference to [ ARGUMENT-DATA-PROTOTYPE ]*/
} Dcm_DspAlternativeArgumentDataType;
typedef struct
{
    P2CONST(Dcm_DspAlternativeArgumentDataType, TYPEDEF, DCM_CONST) DcmDspAlternativeArgumentData;
    P2CONST(Dcm_DspAlternativeDataPropsType, TYPEDEF, DCM_CONST) DcmDspAlternativeDataProps;
    P2CONST(Dcm_DspAlternativeDataTypeType, TYPEDEF, DCM_CONST) DcmDspAlternativeDataType;
} Dcm_DspArgumentScalingType;

typedef struct
{
    const Dcm_DspEndianType DcmDspRoutineSignalEndianness;
    const uint16 DcmDspRoutineSignalLength;
    const uint16 DcmDspRoutineSignalPos;
    const Dcm_DspDataEnumType DcmDspRoutineSignalType;
    P2CONST(Dcm_DspArgumentScalingType, TYPEDEF, DCM_CONST) DcmDspArgumentScaling;
} Dcm_DspRoutineInOutSignalType;
typedef struct
{
    const uint8 RoutineInOutSignalNum;
    P2CONST(Dcm_DspRoutineInOutSignalType, TYPEDEF, DCM_CONST) DcmDspRoutineInOutSignal;
} Dcm_DspRoutineInOutType;
typedef struct
{
    const Dcm_RequestResultsRoutineFncType DcmDspRequestResultsRoutineFnc;
    /*Function name for request to application the results of a routine*/
    P2CONST(Dcm_DspCommonAuthorizationType, TYPEDEF, DCM_CONST)
    DcmDspRequestRoutineResultsCommonAuthorizationRef;
    P2CONST(Dcm_DspRoutineInOutType, TYPEDEF, DCM_CONST) DcmDspRequestRoutineResultsIn;
    P2CONST(Dcm_DspRoutineInOutType, TYPEDEF, DCM_CONST) DcmDspRequestRoutineResultsOut;
} Dcm_DspRequestRoutineResultsType;

/*DcmDspRoutine,Multiplicity=0..* */
typedef struct
{
    const Dcm_StartRoutineFncType DcmDspStartRoutineFnc;
    /*Function name for request to application to start a routine.*/
    P2CONST(Dcm_DspCommonAuthorizationType, TYPEDEF, DCM_CONST)
    DcmDspStartRoutineCommonAuthorizationRef;
    P2CONST(Dcm_DspRoutineInOutType, TYPEDEF, DCM_CONST) DcmDspStartRoutineIn;
    P2CONST(Dcm_DspRoutineInOutType, TYPEDEF, DCM_CONST) DcmDspStartRoutineOut;
} Dcm_DspStartRoutineType;

typedef struct
{
    const Dcm_StopRoutineFncType DcmDspRoutineStopFnc;
    /*Function name for request to application to stop a routine.*/
    P2CONST(Dcm_DspCommonAuthorizationType, TYPEDEF, DCM_CONST)
    DcmDspStopRoutineCommonAuthorizationRef;
    P2CONST(Dcm_DspRoutineInOutType, TYPEDEF, DCM_CONST) DcmDspStopRoutineIn;
    P2CONST(Dcm_DspRoutineInOutType, TYPEDEF, DCM_CONST) DcmDspStopRoutineOut;
} Dcm_DspStopRoutineType;

typedef struct
{
    const uint16 DcmDspRoutineId; /*2 bytes Identifier of the RID*/
    const uint8 DcmDspRoutineInfoByte;
    const boolean DcmDspRoutineUsePort;
    const boolean DcmDspRoutineUsed;
    P2CONST(Dcm_DspCommonAuthorizationType, TYPEDEF, DCM_CONST) DcmDspCommonAuthorizationRef;
    // const  Dcm_DspRequestControlType  DcmDspRoutineTidRef;
    P2CONST(Dcm_DspRequestRoutineResultsType, TYPEDEF, DCM_CONST) DcmDspRequestRoutineResults;
    P2CONST(Dcm_DspStartRoutineType, TYPEDEF, DCM_CONST) DcmDspStartRoutine;
    P2CONST(Dcm_DspStopRoutineType, TYPEDEF, DCM_CONST) DcmDspStopRoutine;
} Dcm_DspRoutineType;
#endif

/*********************************************************************/
#if (STD_ON == DCM_DSP_VEHINFO_FUNC_ENABLED)
/*DcmDspVehInfo Container,Multiplicity=0..* */
typedef Std_ReturnType (*Dcm_GetInfoTypeValueFncType)(uint8* DataValueBuffer);
typedef struct
{
    const uint8 DcmDspVehInfoDataOrder;
    const uint8 DcmDspVehInfoDataSize; /*Length of data of associated INFOTYPE.*/
    const boolean DcmDspVehInfoDataUsePort;
    const Dcm_GetInfoTypeValueFncType DcmGetInfoTypeValueFnc;
    /*Function name for reading the associated INFOTYPE.*/
} Dcm_DspVehInfoDataType;

typedef struct
{
    const uint8 DcmDspVehInfoInfoType; /*INFOTYPE for Service $09 */
    const boolean DcmDspVehInfoNODIProvResp;
    /* In case the responsibility is on provider side
     (DcmDspVehInfoNODIProvResp is set to TRUE), only one DcmDspVehInfoData
     container shall be allowed*/
    /* In case DcmDspVehInfoDataUsePort is set to FALSE and
      DcmDspVehInfoDataReadFnc is set to either Dem_DcmInfoTypeValue08 or
     Dem_DcmInfoTypeValue0B then DcmDspVehInfoNODIProvResp shall be set to
     TRUE.*/
    const uint8 DcmDspVehInfoDataNum;
    P2CONST(Dcm_DspVehInfoDataType, TYPEDEF, DCM_CONST) DcmDspVehInfoData;
} Dcm_DspVehInfoType;
#endif

typedef enum
{
    AFTER_RESET = 0,
    BEFORE_RESET = 1
} Dcm_RespToEcuResetType;

typedef struct
{
    const uint32 DcmDspPeriodicTransmissionFastRate;
    const uint32 DcmDspPeriodicTransmissionMediumRate;
    const uint32 DcmDspPeriodicTransmissionSlowRate;
} Dcm_DspPeriodicTransmissionTypes;

typedef enum
{
    DCM_ROE_CLEARED = 0,
    DCM_ROE_STOPPED = 1,
    DCM_ROE_STARTED = 2
} Dcm_RoeEventStatesTypes;

typedef struct
{
    const uint16 DcmDspRoeDidRef; /*Did value*/
} Dcm_DspRoeOnChangeOfDataIdentifierType;

typedef struct
{
    const uint8 DcmDspRoeDTCStatusMask;
} Dcm_DspRoeOnDTCStatusChangeType;

typedef struct
{
    P2CONST(Dcm_DspRoeOnChangeOfDataIdentifierType, TYPEDEF, DCM_CONST)
    DcmDspRoeOnChangeOfDataIdentifier;
    P2CONST(Dcm_DspRoeOnDTCStatusChangeType, TYPEDEF, DCM_CONST) DcmDspRoeOnDTCStatusChange;
} Dcm_DspRoeEventPropertiesType;

typedef struct
{
    const uint8 DcmDspRoeEventId;
    const Dcm_RoeEventStatesTypes DcmDspRoeInitialEventStatus;
    P2CONST(Dcm_DspRoeEventPropertiesType, TYPEDEF, DCM_CONST) DcmDspRoeEventProperties;
} Dcm_DspRoeEventType;

typedef enum
{
    DCM_ROE_EVENT_WINDOW_INFINITE = 2,
    DCM_ROE_EVENT_WINDOW_CURRENT_CYCLE = 3,
    DCM_ROE_EVENT_WINDOW_CURRENT_AND_FOLLOWING_CYCLE = 4,
} Dcm_DspRoeEventWindowTimeType;

typedef struct
{
    const Dcm_DspRoeEventWindowTimeType DcmDspRoeEventWindowTime;
} Dcm_DspRoeEventWindowTimeTypes;

typedef struct
{
    const uint16 DcmDspRoeInterMessageTime;
    const uint8 DcmDspRoeEventNum;
    P2CONST(Dcm_DspRoeEventType, TYPEDEF, DCM_CONST) DcmDspRoeEvent;
    const uint8 DcmDspRoeEventWindowTimeNum;
    P2CONST(Dcm_DspRoeEventWindowTimeTypes, TYPEDEF, DCM_CONST) DcmDspRoeEventWindowTime;
} Dcm_DspRoeTypes;

typedef struct
{
    P2CONST(boolean, TYPEDEF, DCM_CONST) DcmDspDDDIDcheckPerSourceDID;
    const Dcm_DspEndianType DcmDspDataDefaultEndianness;
    const boolean DcmDspEnableObdMirror;
    const uint16 DcmDspMaxDidToRead;
    /*Indicates the maximum allowed DIDs in a single
     * "ReadDataByIdentifier" request. If set to 0, then no limitation is applied. */
    const uint16 DcmDspMaxPeriodicDidToRead;
    const uint8 DcmDspPowerDownTime;
    const Dcm_RespToEcuResetType DcmResponseToEcuReset;

    P2CONST(Dcm_DspClearDTCType, TYPEDEF, DCM_CONST) pDcmDspClearDTC;
    P2CONST(Dcm_DspComControlType, TYPEDEF, DCM_CONST) pDcmDspComControl;
    P2CONST(Dcm_DspCommonAuthorizationType, TYPEDEF, DCM_CONST) pDcmDspCommonAuthorization;
    P2CONST(Dcm_DspControlDTCSettingType, TYPEDEF, DCM_CONST) pDcmDspControlDTCSetting;

#if (STD_ON == DCM_DSP_DATA_FUNC_ENABLED)
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDcmDspData;
    P2CONST(Dcm_DspDataInfoType, TYPEDEF, DCM_CONST) pDcmDspDataInfo;
#endif

    /*DcmDspDid and DcmDspDidInfo configeration(Multiplicity=0..*)*/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    const uint16 DcmDspDidNum;    /*Number Of Did*/
    P2CONST(Dcm_DspDidType, TYPEDEF, DCM_CONST) pDcmDspDid;
    const uint8 DcmDspDidInfoNum; /*Number Of DidInfo*/
    P2CONST(Dcm_DspDidInfoType, TYPEDEF, DCM_CONST) pDcmDspDidInfo;
    const uint8 DcmDspDidRangeNum;
    P2CONST(Dcm_DspDidRangeType, TYPEDEF, DCM_CONST) pDcmDspDidRange;
#endif

    P2CONST(Dcm_DspMemoryType, TYPEDEF, DCM_CONST) pDcmDspMemory;

    /*DcmDspPid configeration(Multiplicity=0..*)*/
#if (STD_ON == DCM_DSP_PID_FUNC_ENABLED)
    const uint8 DcmDspPidNum;
    P2CONST(Dcm_DspPidType, TYPEDEF, DCM_CONST) pDcmDspPid;
#endif

    /*DcmDspRequestControl configuration(Multiplicity=0..*)*/
#if (STD_ON == DCM_DSP_REQUESTCONTROL_FUNC_ENABLED)
    const uint8 DcmDspRequestControlNum;
    P2CONST(Dcm_DspRequestControlType, TYPEDEF, DCM_CONST) pDcmDspRequestControl;
#endif
    P2CONST(Dcm_DspRequestFileTransferType, TYPEDEF, DCM_CONST) DcmDspRequestFileTransfer;

    /*DcmDspRoutine and DcmDspRoutineInfo configeration(Multiplicity=0..*)*/
#if (STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED)
    const uint8 DcmDspRoutineNum;
    P2CONST(Dcm_DspRoutineType, TYPEDEF, DCM_CONST) pDcmDspRoutine;
#endif
    /*DcmDspSecurity configeration(Multiplicity=1)*/
    P2CONST(Dcm_DspSecurityType, TYPEDEF, DCM_CONST) pDcm_DspSecurity;
    /*DcmDspSession configeration(Multiplicity=1)*/
    P2CONST(Dcm_DspSessionType, TYPEDEF, DCM_CONST) pDcm_DspSession;

    /*DcmDspVehInfo configeration*/
#if (STD_ON == DCM_DSP_VEHINFO_FUNC_ENABLED)
    const uint8 DcmDspVehInfoNum;
    P2CONST(Dcm_DspVehInfoType, TYPEDEF, DCM_CONST) pDcmDspVehInfo;
#endif
    const uint16 DcmDspMaxPeriodicDidScheduler;
    P2CONST(Dcm_DspPeriodicTransmissionTypes, TYPEDEF, DCM_CONST) Dcm_DspPeriodicTransmission;
#if (DCM_DSP_ROE_NUM > 0)
    P2CONST(Dcm_DspRoeTypes, TYPEDEF, DCM_CONST) Dcm_DspRoe;
#endif
} Dcm_DspCfgType;

/**************************************************************************
 ************************DcmDsd container********************
 ************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_DiagnosticService)(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_DiagnosticService_SubService)(
    Dcm_OpStatusType OpStatus,
    P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
typedef struct
{
    P2CONST(Dcm_DiagnosticService_SubService, TYPEDEF, DCM_CONST) DcmDsdSubServiceFnc;
    const uint8 DcmDsdSubServiceId;
    const boolean DcmDsdSubServiceUsed;
    P2CONST(Dcm_ModeRuleCfgType, TYPEDEF, DCM_CONST) DcmDsdSubServiceModeRuleRef;
    P2CONST(uint8, TYPEDEF, DCM_CONST) DcmDsdSubServiceSecurityLevelRef;
    /*Reference to DcmDspSecurityRow*/
    const uint8 DcmDsdSubServiceSecurityLevel_Num; /*Number Of Security Access Levels*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) DcmDsdSubServiceSessionLevelRef;
    const uint8 DcmDsdSubServiceSessionLevel_Num;  /*Number Of  the Session Control*/
} Dcm_DsdSubServiceCfgType;

typedef enum
{
    DCM_PHYSICAL = 0,
    DCM_FUNCTIONAL = 1,
    DCM_PHYANDFUNC = 2
} Dcm_DslProtocolRxAddrType;

/*DcmDsdService container,Multiplicity=1..*,*/
typedef struct
{
    const boolean DcmDsdServiceUsed;
    const Dcm_DiagnosticService DcmDsdSidTabFnc;
    const uint8 DcmDsdServiceId; /*Id of the Service identifier in hex*/
    const boolean DcmDsdSubfuncAvial;
    const boolean DcmDsdSuppressPosRsp;
    /*Information whether the DcmDsdSidTabServiceId includes Subfunctions or not*/
    Dcm_DslProtocolRxAddrType AddressingFormat;
    P2CONST(Dcm_ModeRuleCfgType, TYPEDEF, DCM_CONST) DcmDsdModeRuleRef;
    const uint8 DcmDsdSecurityLevel_Num;                        /*Number Of Security Access Levels*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDsdSecurityLevelRef; /*Reference to DcmDspSecurityRow*/
    const uint8 DcmDsdSessionLevel_Num;                         /*Number Of  the Session Control*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) pDcmDsdSessionLevelRef;
    const uint8 DcmDsdSubService_Num;
    P2CONST(Dcm_DsdSubServiceCfgType, TYPEDEF, DCM_CONST) DcmDsdSubService;
} Dcm_DsdServiceCfgType;

/*DcmDsdServiceTable container,Multiplicity=1..256*/
typedef struct
{
    const uint8 DcmDsdSidTabId;                                        /*service table id*/
    P2CONST(Dcm_DsdServiceCfgType, TYPEDEF, DCM_CONST) pDcmDsdService; /* reference to DcmDsdService*/
    const uint8 DcmDsdSidTab_ServiceNum;                               /*Number of the service*/
} Dcm_DsdServiceTableCfgType;

#if (DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED == STD_ON)
typedef struct
{
    P2FUNC(Std_ReturnType, DCM_APPL_CODE, Indication)
    (uint8 SID,
     P2CONST(uint8, AUTOMATIC, DCM_VAR) RequestData,
     uint16 DataSize,
     uint8 ReqType,
     uint16 SourceAddress,
     P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
    P2FUNC(Std_ReturnType, DCM_APPL_CODE, Confirmation)
    (uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus);
} Dcm_DsdServiceReqSuppNotiType;
#endif

#if (DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED == STD_ON)
typedef struct
{
    P2FUNC(Std_ReturnType, DCM_APPL_CODE, Indication)
    (uint8 SID,
     P2CONST(uint8, AUTOMATIC, DCM_VAR) RequestData,
     uint16 DataSize,
     uint8 ReqType,
     uint16 SourceAddress,
     P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
    P2FUNC(Std_ReturnType, DCM_APPL_CODE, Confirmation)
    (uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus);
} Dcm_DsdServiceReqManuNotiType;
#endif

/*DcmDsd container,Multiplicity=1*/
typedef struct
{
#if (DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED == STD_ON)
    P2CONST(Dcm_DsdServiceReqManuNotiType, TYPEDEF, DCM_CONST) pDcmDsdServiceReqManufacturerNoti;
    const uint16 DcmDsdServiceReqManufacturerNoti_PortNum;
#endif
#if (DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED == STD_ON)
    P2CONST(Dcm_DsdServiceReqSuppNotiType, TYPEDEF, DCM_CONST) pDcmDsdServiceReqSupplierNoti;
    const uint16 DcmDsdServiceReqSupplierNoti_PortNum;
#endif
    P2CONST(Dcm_DsdServiceTableCfgType, TYPEDEF, DCM_CONST) pDcmDsdServiceTable;
    /*pointer to Service table array*/
    const uint16 DcmDsdServiceTable_Num; /*Number of the service table*/
} Dcm_DsdCfgType;

/**************************************************************************
 ************************DcmDsl container********************
 ************************************************************************/
/*DcmDslBuffer container,Multiplicity=1..256*/
typedef struct
{
    const uint8 Dcm_DslBufferId;    /*buffer Id */
    const uint32 Dcm_DslBufferSize; /*length of the buffer,Range=8~4095*/
    const uint32 offset;
} Dcm_DslBufferType;

/*********************************/
/*DslCallbackDCMRequestService container,Multiplicity=1..*,*/
typedef struct
{
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2FUNC(Std_ReturnType, DCM_APPL_CODE, StartProtocol)(Dcm_ProtocolType ProtocolID);
    P2FUNC(Std_ReturnType, DCM_APPL_CODE, StopProtocol)(Dcm_ProtocolType ProtocolID);
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
} Dcm_DslCallbackDCMRequestServiceType;

/*********************************/
/*DcmDslDiagResp container,Multiplicity =1,*/
typedef struct
{
    const boolean DcmDslDiagRespOnSecondDeclinedRequest;
    /*enable (TRUE) or disable (FALSE) the mechanism of directly
     * triggering of ResponsePending by application,Multiplicity=1*/
    const uint8 DcmDslDiagRespMaxNumRespPend; /*Maximum number of negative
responses with response code 0x78 per request,Multiplicity=1*/
    /*DcmDslDiagRespMaxNumRespPend = 0 means 0x78 is no limit*/
} Dcm_DslDiagRespType;

/*********************************/
typedef struct
{
    const PduIdType DcmDslPeriodicTxConfirmationPduId;
    const PduIdType DcmDslTxPduRPduId;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    const uint8 DcmDslMetaDataFlag; /*Reference to a Pdu in EcuC,bit0-3:Metadata
     length,bit4:CANTP_ADDRESS_EXTENSION_8_MASK,bit5:CANTP_SA16_AND_TA16_MASK*/
#endif
} Dcm_DslPeriodicConnectionType;

/*DcmDslPeriodicTransmission container,Multiplicity=0..1*/
typedef struct
{
    P2CONST(Dcm_DslPeriodicConnectionType, TYPEDEF, DCM_CONST) DcmDslPeriodicConnection;
    const uint8 DcmPeriodicTxPduIdNum;
} Dcm_DslPeriodicTransmissionType;

/*DcmDslResponseOnEvent container,Multiplicity=0..1*/
typedef struct
{
    const PduIdType DcmROETxPduId;
    const uint8 DcmROETxPduIdNum;
    /*Reference to a Pdu in EcuC*/
} Dcm_DslResponseOnEventType;

/*Dcm_DslProtocolRx container,Multiplicity=1..*,*/
typedef struct
{
    const uint8 DcmDslParentConnectionCtrlId; /*which connection it belongs*/
    const Dcm_DslProtocolRxAddrType DcmDslProtocolRxAddrType;
    const PduIdType DcmDslProtocolRxPduId;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    const uint8 DcmDslMetaDataFlag; /*Reference to a Pdu in EcuC,bit0-3:Metadata
     length,bit4:CANTP_ADDRESS_EXTENSION_8_MASK,bit5:CANTP_SA16_AND_TA16_MASK*/
#endif
} Dcm_DslProtocolRxType;

typedef struct
{
    const uint8 DcmDslParentConnectionCtrlId; /*which connection it belongs*/
    const PduIdType DcmDslTxConfirmationPduId;
    const PduIdType DcmDslTxPduRPduId;
} Dcm_DslProtocolTxType;

/*DcmDslMainConnection container,Multiplicity=1*/
typedef struct
{
    const uint16 DcmDslProtocolRxTesterSourceAddr;
    P2CONST(Dcm_DslPeriodicTransmissionType, TYPEDEF, DCM_CONST) pDcmDslPeriodicTranmissionConRef;
    const NetworkHandleType DcmDslProtocolComMChannelId; /*Reference to the ComMChannel */
    P2CONST(Dcm_DslProtocolTxType, TYPEDEF, DCM_CONST) pDcmDslROEConnectionRef;
    /*Reference to DcmDslResponseOnEvent,Multiplicity=0..1,*/
    P2CONST(Dcm_DslProtocolRxType, TYPEDEF, DCM_CONST) pDcmDslProtocolRx;
    /*Reference to DcmDslProtocolRx,Multiplicity=1..*,*/
    const uint8 DcmDslProtocolRx_Num;
    /*Number Of DcmDslProtocolRx*/
    P2CONST(Dcm_DslProtocolTxType, TYPEDEF, DCM_CONST) pDcmDslProtocolTx;
    /*Reference to DcmDslProtocolTx,Multiplicity=0..1,*/
    const uint8 DcmDslProtocolTx_Num;
    /*Number Of DcmDslProtocolTx*/
} Dcm_DslMainConnectionType;
/*Dcm_DslConnection,Multiplicity=1..*,*/
typedef struct
{
    const uint8 DcmDslParentProtocolRowCtrlId; /*which protocol it belongs*/
    P2CONST(Dcm_DslMainConnectionType, TYPEDEF, DCM_CONST) pDcmDslMainConnection;
    /*Reference to DcmDslMainConnection,Multiplicity=1,*/
    P2CONST(Dcm_DslPeriodicTransmissionType, TYPEDEF, DCM_CONST) pDcmDslPeriodicTransmission;
    /*Reference to DcmDslPeriodicTransmission,Multiplicity=0..1,*/
    P2CONST(Dcm_DslResponseOnEventType, TYPEDEF, DCM_CONST) pDcmDslResponseOnEvent;
    /*Reference to DcmDslResponseOnEvent,Multiplicity=0..1*/
} Dcm_DslConnectionType;

typedef enum
{
    DCM_PROTOCOL_TRAN_TYPE1 = 0x00,
    /*Messages on the DcmTxPduId already used for normal diagnostic responses*/
    DCM_PROTOCOL_TRAN_TYPE2 = 0x01, /*Messages on a separate DcmTxPduId.*/
    DCM_PROTOCAL_TRAN_NOT_VALID = 0x02
} Dcm_DslProtocolTransType;

/*Dcm_DslProtocolRowCfg container,Multiplicity=1..*,*/
typedef struct
{
    const Dcm_ProtocolType DcmDslProtocolID; /*Protocol Id,Multiplicity=1*/
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    const uint16 DcmDslProtocolMaximumResponseSize;
    /*This parameter is mandatory and defines the maximum length of the response message in case DcmPagedBufferEnabled
     * == TRUE*/
#endif
    const uint32 DcmDslProtocolPreemptTime;
    /*This is the value for the timeout (in ms) of preempting
     *  protocol until protocol needs to be started,Multiplicity=1,*/
    const uint8 DcmDslProtocolPriority;
    /*Protocol Priority,Multiplicity=1*/
    const boolean DcmDslProtocolRowUsed;
    /*Allows to activate or deactivate the usage of a Protocol.
     * This parameter can be used for multi-purpose ECUs*/
    const Dcm_DslProtocolTransType DcmDslProtocolTransType;
    /*the transmission type of ROE or Periodic,Multiplicity=1,*/
    const boolean DcmSendRespPendOnTransToBoot;
    /*Parameter specifying if the ECU should send a NRC 0x78 (response pending)
     *  before transitioning to the bootloader (parameter set to TRUE) or if the
     *   transition shall be initiated without sending NRC 0x78 (parameter set to FALSE).*/
    const uint16 DcmTimStrP2ServerAdjust;
    const uint16 DcmTimStrP2StarServerAdjust;
    P2CONST(Dcm_DslBufferType, TYPEDEF, DCM_CONST) DcmDslProtocolRxBufferRef;
    P2CONST(Dcm_DslBufferType, TYPEDEF, DCM_CONST) DcmDslProtocolTxBufferRef;
    const uint8 DcmDslServiceTableID;
    /*Reference to DcmDsdServiceTable,Multiplicity=1,*/
    P2CONST(Dcm_DslConnectionType, TYPEDEF, DCM_CONST) pDcmDslConnection;
    boolean DcmDslProtocolRequestQueued;
} Dcm_DslProtocolRowType;

/*Dcm_DslProtocol container,Multiplicity=1,*/
typedef struct
{
    P2CONST(Dcm_DslProtocolRowType, TYPEDEF, DCM_CONST) pDcmDslProtocolRow;
    const uint8 DcmDslProtocolRow_Num; /*Number of Protocol*/
} Dcm_DslProtocolType;

/*****************************/
/*DcmDsl container,Multiplicity=1*/
typedef struct
{
    const uint8 DcmChannelCfg_Num;                                 /*Number of DcmDslBuffer configration*/
    P2CONST(Dcm_DslBufferType, TYPEDEF, DCM_CONST) pDcmChannelCfg; /*DcmDslBuffer*/

    const uint8 DCMCallBackDcmRequest_PortNum;                     /*Number of DslCallbackDCMRequestService port*/
    P2CONST(Dcm_DslCallbackDCMRequestServiceType, TYPEDEF, DCM_CONST) pDcmDslCallback_DCMRequestService;

    P2CONST(Dcm_DslDiagRespType, TYPEDEF, DCM_CONST) pDcmDslDiagRespCfg;
    /*reference to DcmDslDiagResp configration*/
    P2CONST(Dcm_DslProtocolType, TYPEDEF, DCM_CONST) pDcmDslProtocol;
    /*reference to DcmDslProtocol configration*/
} Dcm_DslCfgType;

typedef struct
{
    const uint32 DcmPagedBufferTimeout;
    /*the Timeout (in ms) towards the application for filling the next page*/
} Dcm_PageBufferCfgType;

typedef struct
{
    P2CONST(Dcm_DslCfgType, TYPEDEF, DCM_CONST) pDcmDslCfg;
    P2CONST(Dcm_DsdCfgType, TYPEDEF, DCM_CONST) pDcmDsdCfg;
    P2CONST(Dcm_DspCfgType, TYPEDEF, DCM_CONST) pDcmDspCfg;
    P2CONST(Dcm_PageBufferCfgType, TYPEDEF, DCM_CONST) pDcmPageBufferCfg;
    P2CONST(Dcm_ProcessingConditionsCfgType, TYPEDEF, DCM_CONST) pDcmProcessingConditionsCfg;
} Dcm_CfgType;

typedef struct
{
    const boolean DcmDDDIDStorage;
    /*This configuration switch defines, whether DDDID definition is stored non volatile or not.*/
    const boolean DcmDevErrorDetect;
    /*Preprocessor switch to enable or disable the Development Error Detection (DET) mechanism*/
    P2CONST(uint8, TYPEDEF, DCM_CONST) DcmHeaderFileInclusion;
    const boolean DcmRespondAllRequest;
    /*=FALSE:the DCM will not respond to diagnostic request that contains a service ID,
     * which is in the range from 0x40 to 0x7F or in the range from 0xC0 to 0xFF*/
    const boolean DcmVersionInfoApi;
    /*enable or disable the output Version info*/
    const uint32 DcmTaskTime;
    /*the time (in ms)for the periodic cyclic task*/
#if (STD_ON == DCM_DSP_DATA_FUNC_ENABLED)
    P2CONST(Dcm_DspDidType, TYPEDEF, DCM_CONST) DcmVinRef;
    /*Reference to the Did containing the VIN Information.This parameter
     *  is needed for function Dcm_GetVin*/
#endif
} Dcm_GeneralCfgType;

#if (STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED)
typedef enum
{
    DCM_DSP_ROUTINE_INIT = 0,
    DCM_DSP_ROUTINE_ON = 1,
    DCM_DSP_ROUTINE_OFF = 2
} Dcm_RoutineControlStateType;
#endif

typedef enum
{
    DCM_ON = 1,
    DCM_OFF = 0
} Dcm_MkStateType;

typedef struct
{
    Dcm_SesCtrlType Dcm_ActiveSes;       /*DCM Activity session*/
    Dcm_SecLevelType Dcm_ActiveSec;      /*DCM Activity security*/
    Dcm_ProtocolType Dcm_ActiveProtocol; /*DCM Activity Protocol*/
    uint8 Dcm_ActiveProtocolCfgCtrlId;
    Dcm_MkStateType Dcm_MkState;         /*DCM Module status*/
    NetworkHandleType Dcm_ActiveNetwork;
} Dcm_MkCtrlType;

typedef struct
{
    uint16 TesterSourceAddr;     /*Tester source address configured per protocol*/
    uint8 ProtocolId;            /*Id of the protocol on wich the request has been received*/
    uint8 Sid;                   /*Service identifier of the received request*/
    uint8 SubFncId;              /*Identifier of the received subfonction*/
    boolean ReprogramingRequest; /*Set to true in order to request reprogramming of the ECU.*/
    boolean ApplUpdated;         /*Indicate whether the application has been updated or not.*/
    boolean ResponseRequired;
    /*Set to true in case the flashloader or application shall send a response.*/
    boolean BootSuppressPosResponse;
} Dcm_ProgConditionsType;

typedef struct
{
    /* data program start address */
    uint32 address;

    /* data program block Index(compare with parameter transfered by test) */
    uint8 blockId;

    /* status of 0x36 to do */
    uint8 Status;

    /*callout need MemoryIdentifier*/
    uint8 MemoryIdInfoIndex;

    /*one block size*/
    uint32 BlockLength;

    /*total size*/
    uint32 MemorySize;

    boolean FirstFlag;

    uint8 reqBlockId;
} Dcm_DspProgramType;

typedef struct
{
    uint8 Subfunction;
    uint32 Data;
    uint16 Size;
} Dcm_DDDidElementsDataTypes;

#if (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED)
typedef struct
{
    uint16 DDDid;
    uint8 DDDIDNumOfElements;
    Dcm_DDDidElementsDataTypes DcmDspAlternativeArgumentData[DCM_DSP_DDDID_ELEMENTS_MAX];
} Dcm_DDDidTypes;
#endif

typedef struct
{
    uint16 Did;
    uint8 SubFunction;
    uint8 Counter;
    uint16 Length;
    uint8 ProtocolCtrlId;
    boolean DDDid;
    uint8 Data[8];
#if (STD_ON == DCM_GENERIC_CONNECTION)
    uint16 TA;
    uint16 SA;
#endif
} SchedulerQueueTypes;

typedef struct
{
    PduIdType PduId;
    boolean Transmit;
} SchedulerQueueTransmitTypes;

#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
/********************************************
      Page  buffer  Data
 ********************************************/
typedef struct
{
    uint32 TotalSize;
    uint16 IloopOne;
    uint16 TotalDtcCount;
    uint32 ReqOffset;
    uint32 ThisPageSize;
    uint32 ThisPageTxSize;
    uint32 LastFilledSize;
    uint32 AlreadyPageSize;
    boolean Filled;
    boolean PageTxOK;
    uint8 PageIndex;
    boolean LastFilled;
    Dcm_MsgType pResData;
#if (DCM_FD == STD_OFF)
    uint8 LastNotTxData[8];
#else
    uint8 LastNotTxData[64];
#endif
    uint32 LastNotTxDataSize;
    boolean TimerStart;
    boolean TimeOut;
    uint32 CurTimer;
    uint32 ExpiredTimer;
} Dcm_PageBufferDataType;
#endif

#endif /* DCM_TYPES_H */
