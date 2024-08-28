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
**  FILENAME    : PduR_Types.h                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Type definitions of PDUR                                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2 and R19_11            **
**                                                                            **
*******************************************************************************/
#ifndef PDUR_TYPES_H
#define PDUR_TYPES_H
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PDUR_TYPES_H_AR_MAJOR_VERSION 4u
#define PDUR_TYPES_H_AR_MINOR_VERSION 2u
#define PDUR_TYPES_H_AR_PATCH_VERSION 2u
#define PDUR_TYPES_H_SW_MAJOR_VERSION 2u
#define PDUR_TYPES_H_SW_MINOR_VERSION 1u
#define PDUR_TYPES_H_SW_PATCH_VERSION 0u
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR_PBcfg.h"
#include "PduR_Cfg.h"
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
    PDUR_DIRECT = 0u,
    PDUR_TRIGGERTRANSMIT
} PduR_DestPduDataProvisionType;

typedef uint16 PduR_PBConfigIdType;
typedef uint16 PduR_RoutingPathGroupIdType;

typedef enum
{
    PDUR_UNINIT = 0u,
    PDUR_ONLINE
} PduR_StateType;

typedef Std_ReturnType (
    *PduR_LoIfTransmit_FuncPtrType)(PduIdType SoAdSrcPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);

typedef void (*PduR_UpIfTxConfirmation_FuncPtrType)(PduIdType TxPduId);
/*****************************************************************************************************************/
typedef struct
{
    PduLengthType DefaultValueStart;
    PduLengthType DefaultValueLength;
} PduRDefaultValueType;

typedef struct
{
    PduIdType PduRSourcePduHandleId;
    boolean PduRSrcPduUpTxConf;
    PduIdType UpTxconfirmStateIndex;
    PduIdType PduRDestModulePduIndex;
    uint8 BswModuleIndex;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 MetaDataLength;
#endif
} PduRSrcPduType;

typedef struct
{
    PduIdType PduRDestPduHandleId;
    PduR_DestPduDataProvisionType PduRDestPduDataProvision;
    PduIdType PduRGatewayDirectTxStateIndex;
    uint16 PduRTpThreshold;
    PduIdType GateWayTpRunTimeIndex;
    boolean GateWayRoute;
    boolean PduRTransmissionConfirmation;
    PduIdType PduRSrcPduRef;
    PduIdType PduRDestModulePduIndex;
    uint8 BswModuleIndex;
    uint16 PduRDestTxBufferRef;
    P2CONST(PduRDefaultValueType, AUTOMATIC, PDUR_CONST_PBCFG) PduRDefaultValueRef;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 MetaDataLength;
#endif
} PduRDestPduType;

typedef struct
{
    PduIdType PduRSrcPduId;
    uint8 PduDestSum;
    P2CONST(PduIdType, AUTOMATIC, PDUR_CONST_PBCFG) PduRDestPduIdRef;
    boolean TpRoute;
    boolean GatewayOnTheFly;
    uint16 PduRTpMaxThreshold;
} PduRRoutingPathType;

typedef struct
{
    P2CONST(PduRRoutingPathType, AUTOMATIC, PDUR_CONST_PBCFG) PduRRoutingPathRef;
} PduRRoutingTableType;
/*****************************************************************************************************************/
typedef struct
{
    boolean PduRIsEnabledAtInit;
    PduR_RoutingPathGroupIdType PduRRoutingPathGroupId;
    PduIdType PduRDestPduRefNumber;
    P2CONST(PduIdType, AUTOMATIC, PDUR_CONST_PBCFG) PduRDestPduIdRef;
} PduRRoutingPathGroupType;
/*****************************************************************************************************************/
typedef struct
{
    PduR_PBConfigIdType PduRConfigId;
    uint16 PduRRoutingPathGroupNum;
    uint16 PduRRoutingPathNum;
    PduIdType PduRDestPduNum;
    P2CONST(PduRRoutingPathGroupType, AUTOMATIC, PDUR_CONST_PBCFG) PduRRoutingPathGroupRef;
    P2CONST(PduRRoutingTableType, AUTOMATIC, PDUR_CONST_PBCFG) PduRRoutingTableRef;
    P2CONST(PduRSrcPduType, AUTOMATIC, PDUR_CONST_PBCFG) PduRSrcPduRef;
    P2CONST(PduRDestPduType, AUTOMATIC, PDUR_CONST_PBCFG) PduRDestPduRef;
} PduR_PBConfigType;

typedef struct
{
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    uint8 PduRBswModuleRef;
    P2FUNC(Std_ReturnType, PDUR_APPL_CODE, ModuleCancelReceiveApi)(PduIdType RxPduId);
    P2FUNC(Std_ReturnType, PDUR_APPL_CODE, ModuleIfCancelTransmitApi)(PduIdType TxPduId);
    P2FUNC(Std_ReturnType, PDUR_APPL_CODE, ModuleTpCancelTransmitApi)(PduIdType TxPduId);
    P2FUNC(Std_ReturnType, PDUR_APPL_CODE, ModuleChangeParameterApi)
    (PduIdType id, TPParameterType parameter, uint16 value);
    P2FUNC(Std_ReturnType, PDUR_APPL_CODE, ModuleTriggertransmitApi)
    (PduIdType TxPduId, PduInfoType* PduInfoPtr);
    P2FUNC(Std_ReturnType, PDUR_APPL_CODE, ModuleIfTransmitApi)(PduIdType id, const PduInfoType* info);
    P2FUNC(void, PDUR_APPL_CODE, ModuleTxConfirmationApi)(PduIdType TxPduId);
    P2FUNC(void, PDUR_APPL_CODE, ModuleIfRxIndicationApi)(PduIdType RxPduId, const PduInfoType* PduInfoPtr);
    P2FUNC(Std_ReturnType, PDUR_APPL_CODE, ModuleTpTransmitApi)(PduIdType id, const PduInfoType* info);
    P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, ModuleCopyTxDataApi)
    (PduIdType id, const PduInfoType* info, const RetryInfoType* retry, PduLengthType* availableDataPtr);
    P2FUNC(void, PDUR_APPL_CODE, ModuleTpTxConfirmationApi)(PduIdType id, Std_ReturnType result);
    P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, ModuleStartOfReceptionApi)
    (PduIdType id, const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr);
    P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, ModuleCopyRxDataApi)
    (PduIdType id, const PduInfoType* info, PduLengthType* bufferSizePtr);
    P2FUNC(void, PDUR_APPL_CODE, ModuleTpRxIndicationApi)(PduIdType id, Std_ReturnType result);
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
} PduRBswModuleType;

typedef struct
{
    PduLengthType RxBufferOffset;
    PduLengthType TpBufferLength;
    PduLengthType SduLength;
    P2VAR(uint8, AUTOMATIC, PDUR_CONST_PBCFG) TpBufferData; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    PduIdType PduHandleId;
    boolean used;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 MetaData[8u];
#endif
    uint8 NextTpBufferId;
} PduR_TpBufferTableType;

typedef struct
{
    PduLengthType SduLength;
    P2VAR(uint8, AUTOMATIC, PDUR_CONST_PBCFG) TxBufferData; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    boolean used;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 MetaData[8u];
#endif
} PduR_TxBufferType;

typedef struct
{
    PduLengthType PduRPduMaxLength;
    uint8 PduRTxBufferDepth;
    P2VAR(PduR_TxBufferType, AUTOMATIC, PDUR_CONST_PBCFG) PduRTxBufferRef; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
} PduR_TxBufferTableType;
#endif /*STD_OFF == PDUR_ZERO_COST_OPERATION*/

#endif /* end of PDUR_TYPES_H */
