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

#ifndef UDS_H
#define UDS_H

/****************************** references *********************************/
#include "Dcm_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "Dcm_Internal.h"
#include "Dem_Dcm.h"
#include "Com.h"
#if ((STD_ON == DCM_OBD_FUNC_ENABLED) || (DEM_OBD_NO_OBD_SUPPORT != DEM_OBD_SUPPORT))
#include "Dcm_OBDInternal.h"
#endif /* (STD_ON == DCM_OBD_FUNC_ENABLED) || (DEM_OBD_NO_OBD_SUPPORT != DEM_OBD_SUPPORT) */

/**************************************************************************
 **********************Service request packet length defined***************
 **************************************************************************/
/* have subservice Service request packet length defined*/
#define DCM_UDS_REQ_DATA_MINLENGTH  (2U)

#define DCM_UDS0X10_REQ_DATA_LENGTH (2U)
/*0x10 Service request packet length defined*/
#define DCM_UDS0X11_REQ_DATA_LENGTH (2U)
/*0x11 Service request packet length defined*/
#define DCM_UDS0X14_REQ_DATA_LENGTH (4U)
/*0x14 Service request packet length defined*/
#define DCM_UDS0X19_REQ_DATA_MINLENGTH (2U)
/*0x19 Service request packet length defined*/
#define DCM_UDS0X19_SUBFUNC0X01_REQ_DATA_LENGTH (3U)
/*sub-function 0x01 request message length*/
#define DCM_UDS0X19_SUBFUNC0X02_REQ_DATA_LENGTH (3U)
/*sub-function 0x02 request message length*/
#define DCM_UDS0X19_SUBFUNC0X03_REQ_DATA_LENGTH (2U)
/*sub-function 0x03 request message length*/
#define DCM_UDS0X19_SUBFUNC0X04_REQ_DATA_LENGTH (6U)
/*sub-function 0x04 request message length*/
#define DCM_UDS0X19_SUBFUNC0X06_REQ_DATA_LENGTH (6U)
/*sub-function 0x06 request message length*/
#define DCM_UDS0X19_SUBFUNC0X0A_REQ_DATA_LENGTH (2U)
/*sub-function 0x0A request message length*/
#define DCM_UDS0X19_SUBFUNC0X0E_REQ_DATA_LENGTH (2U)
/*sub-function 0x0A request message length*/
#define DCM_UDS0X22_REQ_DATA_MINLENGTH (3U)
/*0x22 Service request packet length defined*/
#define DCM_UDS0X23_REQ_DATA_MINLENGTH (4u)
/*0x23 Service request packet length defined*/
#define DCM_UDS0X24_REQ_DATA_LENGTH (3u)
/*0x24 Service request packet length defined*/
#define DCM_UDS0X27_REQ_DATA_MINLENGTH (2U)
/*0x27 Service request packet length defined*/
#define DCM_UDS0X28_REQ_DATA_MINLENGTH (3U)
/*0x28 request message length*/
#define DCM_UDS0X28_REQ_DATA_MAXLENGTH (5U)
/*0x28 request message length*/
#define DCM_UDS0X2A_SUBFUNC0X04_REQ_DATA_MINLENGTH (2U)
/*0x2A 04 Service request packet length defined*/
#define DCM_UDS0X2A_REQ_DATA_MINLENGTH (3U)
/*0x2A other Service request packet length defined*/
#define DCM_UDS0X2C_REQ_DATA_MINLENGTH (2U)
/*0x2C Service request packet length defined*/
#define DCM_UDS0X2C_SUBFUNC0X01_REQ_DATA_MINLENGTH (8U)
/*0x2C Service request packet length defined*/
#define DCM_UDS0X2C_SUBFUNC0X02_REQ_DATA_MINLENGTH (7U)
/*0x2C Service request packet length defined*/
#define DCM_UDS0X2C_SUBFUNC0X03_REQ_DATA_MINLENGTH (4U)
/*0x2C Service request packet length defined*/
#define DCM_UDS0X2E_REQ_DATA_MINLENGTH (4U)
/*0x2E Service request packet length defined*/
#define DCM_UDS0X2F_REQ_DATA_MINLENGTH (4U)
/*0x2F Service request packet length defined*/
#define DCM_UDS0X31_REQ_DATA_MINLENGTH (4U)
/*0x31 Service request packet length defined*/
#define DCM_UDS0X34_REQ_DATA_MINLENGTH (5u)
/*0x34 Service request packet length defined*/
#define DCM_UDS0X35_REQ_DATA_MINLENGTH (5u)
/*0x35 Service request packet length defined*/
#define DCM_UDS0X36_REQ_DATA_UPLOAD_MINLENGTH (2u)
/*0x36 Service request upload packet length defined*/
#define DCM_UDS0X36_REQ_DATA_DOWNLOAD_MINLENGTH (3u)
/*0x36 Service request download packet length defined*/
#define DCM_UDS0X38_REQ_DATA_MINLENGTH (5u)
/*0x38 Service request packet length defined*/
#define DCM_UDS0X3D_REQ_DATA_MINLENGTH (5u)
/*0x3D Service request packet length defined*/
#define DCM_UDS0X3E_REQ_DATA_LENGTH (2U)
/*0x3E Service request packet length defined*/
#define DCM_UDS0X85_REQ_DATA_MINLENGTH (2U)
/*0x85 request message minimum length*/
#define DCM_UDS0X85_REQ_DATA_DTC_MINLENGTH (5U)
/*0x85 request message minimum length with DTC*/
#define DCM_UDS0X86_REQ_DATA_MINLENGTH (3U)
/*0x86 request message minimum length*/
/**********************************************************************
 *             UDS 0x19 service sub-function
 **********************************************************************/
/*UDS 0x19 service,sub-function defined*/
#define DCM_REPORTNUMBEROFDTCBYSTATUSMASK (0x01u)
/*reportNumberOfDTCByStatusMask */
#define DCM_REPORTDTCBYSTATUSMASK (0x02u)
/*reportDTCByStatusMask*/
#define DCM_REPORTREPORTDTCSNAPSHOTIDENTIFICATION (0x03u)
/*reportDTCSnapshotIdentification*/
#define DCM_REPORTDTCSNAPSHOTRECORDBYDTCNUMBER (0x04u)
/*reportDTCSnapshotRecordByDTCNumber*/
#define DCM_REPORTDTCEXTENDEDDATARECORDBYDTCNUMBER (0x06u)
/*reportDTCExtendedDataRecordByDTCNumber */
#define DCM_REPORTSUPPORTEDDTC (0x0Au)
/*reportSupportedDTC*/
#define DCM_REPORTMOSTRECENTCONFIRMEDDTC (0x0Eu)
/*reportMostRecentConfirmedDTC*/
/***********************************************************************
              UDS 0x2F service InputOutputControlParameter define
 ***********************************************************************/
#define DCM_UDS0X2F_RETURNCONTROLTOECU  (0u) /*ReturnControlToEcu*/
#define DCM_UDS0X2F_RESETTODEFAULT      (1u) /*ResetToDefault*/
#define DCM_UDS0X2F_FREEZECURRENTSTATE  (2u) /*FreezeCurrentState*/
#define DCM_UDS0X2F_SHORTTERMADJUSTMENT (3u) /*ShortTermAdjustment*/

/**********************************************************************
 *            UDS 0x2C service sub-function define
 **********************************************************************/
#define DCM_UDS0X2C_01_DDBYDID    (1u) /*defineByIdentifier*/
#define DCM_UDS0X2C_02_DDBYMEMORY (2u) /*defineByMemoryAddress*/
#define DCM_UDS0X2C_03_CLEARDDDID (3u)
/*clearDynamicallyDefinedDataIdentifier*/

/**********************************************************************
 *            UDS 0x2A service sub-function define
 **********************************************************************/
#define DCM_UDS0X2A_01_SLOW   (1u) /*sendAtSlowRate*/
#define DCM_UDS0X2A_02_MEDIUM (2u) /*sendAtMediumRate*/
#define DCM_UDS0X2A_03_FAST   (3u) /*sendAtFastRate*/
#define DCM_UDS0X2A_04_STOP   (4u) /*stopSending*/

/**********************************************************************
 *            UDS 0x31 service sub-function define
 **********************************************************************/
#define DCM_UDS0X31_STARTROUTINE          (1u) /*startRoutine*/
#define DCM_UDS0X31_STOPROUTINE           (2u) /*stopRoutine*/
#define DCM_UDS0X31_REQUESTROUTINERESULTS (3u) /*RequestRoutineResult*/

/**********************************************************************
 *            UDS 0x3E service sub-function define
 **********************************************************************/
#define DCM_UDS0X3E_ZERO_SUBFUNCTION (0u) /*zero sub-function*/

/**********************************************************************
 *            UDS 0x85 service sub-function define
 **********************************************************************/
#define DCM_UDS0X85_ON  (1u) /*turn on the setting of DTC*/
#define DCM_UDS0X85_OFF (2u) /*turn off the setting of DTC*/

/**********************************************************************
 *            UDS 0x86 service sub-function define
 **********************************************************************/
#define DCM_UDS0X86_STOP_RESPONSE_ON_EVENT       (0u) /*stopResponseOnEvent*/
#define DCM_UDS0X86_ON_DTC_STATUS_CHANGE         (1u) /*onDTCStatusChange*/
#define DCM_UDS0X86_ON_CHANGE_OF_DATA_IDENTIFIER (3u) /*onChangeOfDataIdentifier*/
#define DCM_UDS0X86_REPORT_ACTIVATED_EVENTS      (4u) /*reportActivatedEvents*/
#define DCM_UDS0X86_START_RESPONSE_ON_EVENT      (5u) /*startResponseOnEvent*/
#define DCM_UDS0X86_CLEAR_RESPONSE_ON_EVENT      (6u) /*clearResponseOnEvent*/

/**********************************************************************
 *            UDS 0x28 service sub-function define
 **********************************************************************/
#define COMTYPE_NORM        (1u) /*normal communication message*/
#define COMTYPE_NORM_AND_NM (3u) /*NORM and NM communication message*/
/******************************END of dependence****************************************/
#if (STD_ON == DCM_UDS_SERVICE0X87_ENABLED)
/*definition of processing status of link control*/

typedef enum Dcm_LinkControlStatus_t
{
    LINK_CONTROL_IDLE = 0,
    LINK_CONTROL_FBR_VERIFICATION = 1,
    LINK_CONTROL_FBR_TRANSITION = 2,
    LINK_CONTROL_SBR_VERIFICATION = 3,
    LINK_CONTROL_SBR_TRANSITION = 4
} Dcm_LinkControlStatusType;

/*definition of 'link control' control block*/
typedef struct Dcm_LinkControlCtrlType_t
{
    VAR(Dcm_LinkControlStatusType, TYPEDEF) linkCtrlStatus;
    VAR(uint8, TYPEDEF) fixedBaudrate;
    VAR(uint32, TYPEDEF) specialBaudrate;
} Dcm_LinkControlCtrlType;
#endif

#if (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED)

extern VAR(Dcm_DDDidTypes, DCM_VAR_NOINIT) Dcm_DDDid[DCM_DSP_DDDID_MAX_NUMBER];

#endif

/*SID Table*/
#define SID_DIAGNOSTIC_SESSION_CONTROL         0x10u
#define SID_ECU_RESET                          0x11u
#define SID_CLEAR_DIAGNOSTIC_INFORMATION       0x14u
#define SID_READ_DTC_INFORMATION               0x19u
#define SID_READ_DATA_BY_IDENTIFIER            0x22u
#define SID_READ_DATA_BY_MEMORYADDRESS         0x23u
#define SID_READ_SCALING_DATA_BY_IDENTIFIER    0x24u
#define SID_SECURITY_ACCESS                    0x27u
#define SID_COMMUNICATION_CONTROL              0x28u
#define SID_READ_DATA_BY_PERIODIC_IDENTIFER    0x2Au
#define SID_DYNAMICALLY_DEFINE_DATA_IDENTIFER  0x2Cu
#define SID_WRITE_DATA_BY_IDENTIFIER           0x2Eu
#define SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER 0x2Fu
#define SID_ROUTINE_CONTROL                    0x31u
#define SID_REQUEST_DOWNLOAD                   0x34u
#define SID_REQUEST_UPLOAD                     0x35u
#define SID_TRANSFER_DATA                      0x36u
#define SID_REQUEST_TRANSFER_EXIT              0x37u
#define SID_REQUEST_FILE_TRANSFER              0x38u
#define SID_WIRTE_DATA_BY_MEMORYADDRESS        0x3Du
#define SID_TESTER_PRESENT                     0x3Eu
#define SID_CONTROL_DTC_SETTING                0x85u
#define SID_RESPONSE_ON_EVENT                  0x86u

/*END OF SID Table*/

extern VAR(Dcm_DspProgramType, DCM_VAR_NOINIT) Dcm_DspProgram;

#if (STD_ON == DCM_UDS_FUNC_ENABLED)
/****************************** declarations *********************************/
#if (STD_ON == DCM_UDS_SERVICE0X10_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x10(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X11_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x11(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X27_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x27(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X28_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x28(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

extern FUNC(void, DCM_CODE) DspInternalUDS0x28_CheckNewSes(Dcm_SesCtrlType NewSes);

#endif

#if (STD_ON == DCM_UDS_SERVICE0X3E_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x3E(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X85_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x85(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X86_ENABLED)

extern FUNC(void, DCM_CODE) Dcm_UDS0x86_DTCStatusChange(uint8 DTCStatusOld, uint8 DTCStatusNew);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x86_ChangeOfDataIdentifier(uint8 RoeEventId);

extern FUNC(void, DCM_CODE) Dcm_UDS0x86_CheckTimer(void);

extern FUNC(void, DCM_CODE) Dcm_UDS0x86_SesTranslation(Dcm_SesCtrlType NewSes);

extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_UDS0x86_CheckProcessRoe(uint8 ProtocolCtrlId);

extern FUNC(boolean, DCM_CODE) Dcm_UDS0x86_GetTxPduId(PduIdType* pduTxId);

extern FUNC(boolean, DCM_CODE) Dcm_UDS0x86_TxConfirmation(uint8 ProtocolCtrlId);

FUNC(void, DCM_CODE) Dcm_UDS0x86_Init(void);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x86(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X87_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x87(uint8 ProtocolCtrlId);

#endif

#if (STD_ON == DCM_UDS_SERVICE0X14_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x14(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X19_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x19(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X22_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x22(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X23_ENABLED)

FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x23(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X24_ENABLED)

FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x24(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X2A_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2A(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

extern FUNC(void, DCM_CODE) Dcm_MainFunction_Scheduler_0x2A(uint8 ProtocolCtrlId);

extern FUNC(void, DCM_CODE) Dcm_Scheduler_0x2A_Init(void);

extern FUNC(void, DCM_CODE) Dcm_UDS0x2ACheckNewSession(Dcm_SesCtrlType NewSes);

extern FUNC(void, DCM_CODE) Dcm_UDS0x2ACheckNewSecurity(void);

#endif

#if (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2C(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#if (DCM_DDDID_STORAGE == STD_ON)

extern FUNC(void, DCM_CODE) Dcm_UDS0x2C_Init(void);

#endif
#endif

#if (STD_ON == DCM_UDS_SERVICE0X2E_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2E(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X2F_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2F(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#if (DCM_DSP_DID_FOR_2F_NUM > 0)

extern FUNC(void, DCM_CODE) Dcm_UDS0x2FCheckNewSession(Dcm_SesCtrlType NewSes);

#if (DCM_DSP_DID_FOR_2F_NUM > 0)

extern FUNC(void, DCM_CODE) Dcm_UDS0x2FCheckNewSecurity(Dcm_SecLevelType NewSec);

#endif
#endif

#endif

#if (STD_ON == DCM_UDS_SERVICE0X31_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x31(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X34_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x34(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X35_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x35(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X36_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x36(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X37_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x37(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X38_ENABLED)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x38(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#if (STD_ON == DCM_UDS_SERVICE0X3D_ENABLED)

FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x3D(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#endif

#endif /*end of 'STD_ON == DCM_UDS_FUNC_ENABLED'*/

#if ((STD_ON == DCM_UDS_SERVICE0X23_ENABLED) || (STD_ON == DCM_UDS_SERVICE0X36_ENABLED))

extern Dcm_ReturnReadMemoryType Dcm_ReadMemory(
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode);

#endif

#if ((STD_ON == DCM_UDS_SERVICE0X3D_ENABLED) || (STD_ON == DCM_UDS_SERVICE0X36_ENABLED))

extern Dcm_ReturnWriteMemoryType Dcm_WriteMemory(
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode);

#endif

#if (DCM_UDS_SERVICE0X34_ENABLED == STD_ON)
/*for 0x34 service to request download*/

extern Std_ReturnType Dcm_ProcessRequestDownload(
    Dcm_OpStatusType OpStatus,
    uint8 DataFormatIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint32* BlockLength,
    Dcm_NegativeResponseCodeType* ErrorCode);

#endif

#if (DCM_UDS_SERVICE0X35_ENABLED == STD_ON)
/*for 0x35 service to request upload*/

extern Std_ReturnType Dcm_ProcessRequestUpload(
    Dcm_OpStatusType OpStatus,
    uint8 DataFormatIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint32* BlockLength,
    Dcm_NegativeResponseCodeType* ErrorCode);

#endif

#if ((DCM_UDS_SERVICE0X35_ENABLED == STD_ON) || (DCM_UDS_SERVICE0X34_ENABLED == STD_ON))
/* service to check DataFormatIdentifier, send NRC31 if return E_NOT_OK*/
extern Std_ReturnType Dcm_DataFormatIdentifierCheck(uint8 DataFormatIdentifier);
#endif

#if (DCM_UDS_SERVICE0X37_ENABLED == STD_ON)
/*for 0x37 service to request transfer exit*/

extern Std_ReturnType Dcm_ProcessRequestTransferExit(
    Dcm_OpStatusType OpStatus,
    uint8* transferRequestParameterRecord,
    uint32 transferRequestParameterRecordSize,
    uint8* transferResponseParameterRecord,
    uint32* transferResponseParameterRecordSize,
    Dcm_NegativeResponseCodeType* ErrorCode);

#endif

#if (DCM_UDS_SERVICE0X38_ENABLED == STD_ON)
/*for 0x38 service to request file transfer*/

extern Std_ReturnType Dcm_ProcessRequestFileTransfer(
    Dcm_OpStatusType OpStatus,
    uint8 modeofOperation,
    uint16 fileSizeParameterLength,
    uint8* filePathAndName,
    uint8 dataFormatIdentifier,
    uint8* fileSizeUncompressedOrDirInfoLength,
    uint8* fileSizeCompressed,
    uint32* BlockLength,
    Dcm_NegativeResponseCodeType* ErrorCode);

#endif

#if (DCM_BSWM_ENABLE != STD_ON)

extern void Rte_DcmControlCommunicationMode(
    NetworkHandleType DcmDspComMChannelId,
    Dcm_CommunicationModeType RequestedMode);

#endif

#if ((STD_ON == DCM_UDS_FUNC_ENABLED) && (STD_ON == DCM_UDS_SERVICE0X85_ENABLED))

/*The update of the DTC status will be re-enabled*/
extern void Rte_EnableAllDtcsRecord(void);

#endif
#define DCM_MINIMUMLENGTH_CHECK_ENABLED STD_ON
/****************************** definitions *********************************/

#endif /* UDS_H_ */
