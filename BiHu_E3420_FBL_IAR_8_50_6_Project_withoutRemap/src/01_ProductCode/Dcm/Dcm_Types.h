/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Dcm_Types.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS    **
**               services which used for bootloader project.                  **
**                                                                            **
**  SPECIFICATION(S) :  UDS Service - ISO14229.      	                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20121109    Gary            Initial version
 *  V1.0.1      20160801    cywang          update
 *  V1.0.2      20200413    Lianren.Wu      optimization
 *  V1.0.3      20200506    Lianren.Wu      optimization Dcm_SecurityRowType
                                            Dcm_ComControlRowType Dcm_DownloadRowType.
 *  V1.0.4      20210326    Lianren.Wu      add the member: securitySupportMask in
 *                                          Dcm_ServiceTableType.
 *  V1.0.5      20231218    Chunjun.Hua     add error code to Dcm_RoutineControlCalloutFct
 */
#ifndef DCM_TYPES_H
#define DCM_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
#include "SecM.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** Dcm Buffer status */
typedef enum
{
    DCM_BUFF_FREE,
    DCM_BUFF_FOR_TP,
    DCM_BUFF_FOR_SERVICE
} Dcm_BuffStatusType;

/** struct of DCM Buffer type */
typedef struct
{
    /* status of this buffer */
    Dcm_BuffStatusType buffStatus;
    /* PduId of this buffer */
    PduIdType pduId;
    /* Pdu Data of this buffer */
    PduInfoType pduInfo;
} Dcm_BuffType;

typedef struct 
{
    PduIdType txId;
    PduIdType phyId;
    PduIdType funId;
}PduIdGrpType;

/** service function type */
typedef void (*Dcm_ServiceFct)(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
/** service pending function type */
typedef void (*Dcm_PendingFct)(const FL_ResultType errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

typedef uint8 Dcm_AddressModeType;
typedef uint8 Dcm_SessionType;
typedef uint8 Dcm_ResetType;
typedef struct {uint8 id;uint16 len;}Dcm_RoutineControlType;
typedef uint8 Dcm_ComControlType;
typedef uint8 Dcm_CommunicationType;
typedef uint8 Dcm_zeroSubFuncType;
typedef uint8 Dcm_DTCSettingType;
typedef uint8 Dcm_SecurityType;

/** service table parameter configuration */
typedef struct
{
    /* service Id */
    const uint8 SID;
    /* if function address is supported */
    const Dcm_AddressModeType addressSupportMask;
    /* supported session mode number */
    const uint8 sessionSupportNbr;
    /* supported session mode */
    const Dcm_SessionType* sessionSupportPtr;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
    /* service function */
    const Dcm_ServiceFct serviceFct;
    /* service pending function */
    const Dcm_PendingFct pendingFct;
} Dcm_ServiceTableType;

/** 0x10 service parameter configuration */
typedef struct
{
    /* session mode type */
    const Dcm_SessionType sessionType;
    /* supported session mode number */
    const uint8 sessionSupportNbr;
    /* supported session mode */
    const Dcm_SessionType* sessionSupportPtr;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
} Dcm_SessionRowType;

/** 0x11 service parameter configuration */
typedef struct
{
    /* reset mode type */
    const Dcm_ResetType resetType;
    /* supported session mode number */
    const uint8 sessionSupportNbr;
    /* supported session mode */
    const Dcm_SessionType* sessionSupportPtr;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
} Dcm_ResetRowType;

/** 0x22 service parameter configuration */
/** read data function type */
typedef FL_ResultType (*Dcm_ReadDataFct)(uint8* readData, uint16* readLength);

/** 0x22 service parameter configuration */
typedef struct
{
    /* read data Id */
    const uint16 DID;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
    const Dcm_SessionType* sessionSupportPtr;
    const uint8 sessionSupportNbr;
    /* read data function */
    const Dcm_ReadDataFct readDataFct;
} Dcm_ReadDidRowType;

/** 0x27 service parameter configuration */

/** generate seed function type */
typedef SecM_StatusType (*Dcm_GenerateSeedFct)(SecM_SeedType* seed);

/** compare key function type */
typedef SecM_StatusType (*Dcm_CompareKeyFct)(uint8 KeyLength, const SecM_KeyType* key, const SecM_SeedType* seed);

/** 0x27 service parameter configuration */
typedef struct
{
    /* request seed sub function Id */
    const uint8 reqSeedId;
    /* request seed sub function Id */
    const uint8 SeedLength;
    /* send key sub function Id */
    const uint8 sendKeyId;
    /* request seed sub function Id */
    const uint8 KeyLength;
    /* security access level */
    const Dcm_SecurityType secAccessLevel;
    /* supported session mode */
    /* supported session mode number */
    const uint8 sessionSupportNbr;
    const Dcm_SessionType* sessionSupportPtr;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
    /* generate seed function */
    const Dcm_GenerateSeedFct generateSeed;
    /* compare key function */
    const Dcm_CompareKeyFct compareKey;
} Dcm_SecurityRowType;

/** 0x28 service parameter configuration */
typedef struct
{
    /* communication control type */
    const Dcm_ComControlType controlType;
    /* communication control type */
    const Dcm_CommunicationType communicationType;
    /* supported session mode number */
    const uint8 sessionSupportNbr;
    /* supported session mode */
    const Dcm_SessionType* sessionSupportPtr;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
} Dcm_ComControlRowType;

/** 0x2E service parameter configuration */
/** write data function type */
typedef FL_ResultType (*Dcm_WriteDataFct)(const uint8* data, const uint16 length);

/* 0x2E service parameter configuration */
typedef struct
{
    /* write data Id */
    const uint16 DID;
    /* write length */
    const uint16 dataLength;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
    const Dcm_SessionType* sessionSupportPtr;
    const uint8 sessionSupportNbr;
    /* write data function */
    const Dcm_WriteDataFct writeDataFct;
} Dcm_WriteDidRowType;

/** 0x31 service parameter configuration */

/** routine control function type */
typedef void (*Dcm_RoutineControlFct)(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
typedef void (*Dcm_RoutineControlCalloutFct)(const FL_ResultType errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

typedef struct
{
    /* routine Id */
    const uint16 routineId;
    /* routine option length */
    const uint16 optionLength;
    /* supported session mode number */
    const uint8 sessionSupportNbr;
    /* supported session mode */
    const Dcm_SessionType* sessionSupportPtr;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
    /*supported routine control number */
    const uint8 routineControlSupportNbr;
    /* supported routine control */
    const Dcm_RoutineControlType* routineControlSupportPtr;
    /* routine control function */
    const Dcm_RoutineControlFct routineControl;
    /* routine control Callout function */
    Dcm_RoutineControlCalloutFct routineControlCallout;
} Dcm_RoutineControlRowType;

/** 0x34 0x36 0x37 service parameter configuration */
typedef struct
{
    const uint8 dataformatId;
    const uint8 addrAndLenFormatId;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
} Dcm_DownloadRowType;

/** 0x38 service parameter configuration */
typedef struct
{
    /*request file transfer mode num*/
    const uint8 modeOfOperationNum;
    const uint8* modeOfOperation;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
} Dcm_RequestFileTransferType;

/** 0x3E service parameter configuration */
typedef struct
{
    /* supported zeroSubFunc */
    const Dcm_zeroSubFuncType zeroSubFunc;
} Dcm_testPresentRowType;

/** 0x85 service parameter configuration */
typedef struct
{
    /* DTC setting type */
    const Dcm_DTCSettingType DTCSet;
    /* supported session mode number */
    const uint8 sessionSupportNbr;
    /* supported session mode */
    const Dcm_SessionType* sessionSupportPtr;
    /* supported security level number */
    const uint8 securitySupportNbr;
    /* supported security level */
    const Dcm_SecurityType* securitySupportPtr;
} Dcm_DTCSettingRowType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* endof DCM_TYPES_H */
