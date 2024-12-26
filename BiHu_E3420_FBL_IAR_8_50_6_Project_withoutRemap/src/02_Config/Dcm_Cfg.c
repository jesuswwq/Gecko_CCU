
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
**  FILENAME    : Dcm_Cfg.c                                                   **
**                                                                            **
**  Created on  : 2023/09/15 16:35:14                                         **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS services
**   which used for bootloader project                                        **
**                                                                            **
**  SPECIFICATION(S) :   UDS Service - ISO14229                               **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230817    long.zhu          Initial Version
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_Dsp.h"
#include "Dcm_Cfg.h"
#include "Appl_Dcm.h"
#include "Rte_Dcm.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


const PduIdGrpType Dcm_PduID_Cfg[DCM_PDU_GRP_NUM] = {
    /* reference to CanTp_TxSdu->txDcmId */
 PDUR_DCM_TX_PDU_ID              ,

/* reference to CanTp_RxSdu->rxDcmId */
 PDUR_DCM_RX_PHY_PDU_ID          ,

/* reference to CanTp_RxSdu->rxDcmId */
 PDUR_DCM_RX_FUNC_PDU_ID         ,

/* reference to CanTp_TxSdu->txDcmId */
 PDUR_DCM_OTA_TX_PDU_ID              ,

/* reference to CanTp_RxSdu->rxDcmId */
 PDUR_DCM_OTA_RX_PHY_PDU_ID          ,

/* reference to CanTp_RxSdu->rxDcmId */
 PDUR_DCM_OTA_RX_FUNC_PDU_ID         ,
};
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
const Dcm_SessionType Dcm_ServiceTable_0x10_Session[3] = {DCM_SESSION_DEFAULT,DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x10_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x11_Session[3] = {DCM_SESSION_DEFAULT,DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x11_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x22_Session[3] = {DCM_SESSION_DEFAULT,DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x22_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x27_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x27_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x28_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x28_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x2e_Session[2] = {DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x2e_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x31_Session[2] = {DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x31_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x34_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x34_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x36_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x36_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x37_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x37_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x3e_Session[3] = {DCM_SESSION_DEFAULT,DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x3e_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x85_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x85_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_ServiceTableType Dcm_ServiceTable[DCM_SERVICE_NUM] =
{
    /* SID, funcAddrSupport,  sessionSupp,      ServiceFct,  pendingFct */
    /* @type:uint8 range:0x00~0xFF note:select unique service Id */
    /* @type:boolean range:TRUE,FALSE note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:API range:NONE note:auto generate */
    /* @type:API range:NONE note:auto generate */
    {
        0x10u,
        DCM_PHY_FUNC_ADDRESSING,
        3u,
        Dcm_ServiceTable_0x10_Session,
        2u,
        Dcm_ServiceTable_0x10_Security,
        &Dcm_RecvMsg10,
        NULL_PTR
    },
    {
        0x11u,
        DCM_PHY_FUNC_ADDRESSING,
        3u,
        Dcm_ServiceTable_0x11_Session,
        2u,
        Dcm_ServiceTable_0x11_Security,
        &Dcm_RecvMsg11,
        NULL_PTR
    },
    {
        0x22u,
        DCM_PHY_FUNC_ADDRESSING,
        3u,
        Dcm_ServiceTable_0x22_Session,
        2u,
        Dcm_ServiceTable_0x22_Security,
        &Dcm_RecvMsg22,
        NULL_PTR
    },
    {
        0x27u,
        DCM_PHYSICAL_ADDRESSING,
        1u,
        Dcm_ServiceTable_0x27_Session,
        2u,
        Dcm_ServiceTable_0x27_Security,
        &Dcm_RecvMsg27,
        NULL_PTR
    },
    {
        0x28u,
        DCM_PHY_FUNC_ADDRESSING,
        1u,
        Dcm_ServiceTable_0x28_Session,
        2u,
        Dcm_ServiceTable_0x28_Security,
        &Dcm_RecvMsg28,
        NULL_PTR
    },
    {
        0x2eu,
        DCM_PHYSICAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x2e_Session,
        2u,
        Dcm_ServiceTable_0x2e_Security,
        &Dcm_RecvMsg2E,
        &Dcm_Pending2E
    },
    {
        0x31u,
        DCM_PHYSICAL_ADDRESSING,
        2u,
        Dcm_ServiceTable_0x31_Session,
        2u,
        Dcm_ServiceTable_0x31_Security,
        &Dcm_RecvMsg31,
        &Dcm_Pending31
    },
    {
        0x34u,
        DCM_PHYSICAL_ADDRESSING,
        1u,
        Dcm_ServiceTable_0x34_Session,
        1u,
        Dcm_ServiceTable_0x34_Security,
        &Dcm_RecvMsg34,
        NULL_PTR
    },
    {
        0x36u,
        DCM_PHYSICAL_ADDRESSING,
        1u,
        Dcm_ServiceTable_0x36_Session,
        1u,
        Dcm_ServiceTable_0x36_Security,
        &Dcm_RecvMsg36,
        &Dcm_Pending36
    },
    {
        0x37u,
        DCM_PHYSICAL_ADDRESSING,
        1u,
        Dcm_ServiceTable_0x37_Session,
        1u,
        Dcm_ServiceTable_0x37_Security,
        &Dcm_RecvMsg37,
        NULL_PTR
    },
    {
        0x3eu,
        DCM_PHY_FUNC_ADDRESSING,
        3u,
        Dcm_ServiceTable_0x3e_Session,
        2u,
        Dcm_ServiceTable_0x3e_Security,
        &Dcm_RecvMsg3E,
        NULL_PTR
    },
    {
        0x85u,
        DCM_PHY_FUNC_ADDRESSING,
        1u,
        Dcm_ServiceTable_0x85_Session,
        2u,
        Dcm_ServiceTable_0x85_Security,
        &Dcm_RecvMsg85,
        NULL_PTR
    },
};

#if (DCM_SESSION_NUM > 0u)

const Dcm_SessionType Dcm_ServiceTable_0x1_Session[3] = {DCM_SESSION_DEFAULT,DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x1_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x2_Session[2] = {DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x2_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ServiceTable_0x3_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ServiceTable_0x3_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionRowType Dcm_SessionRow[DCM_SESSION_NUM] =
{
    /* sessionType, sessionSupp, securitySupp */
    /* @type:uint8 range:0x00~0xFF note:select unique session value */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    {
        DCM_SESSION_DEFAULT,
        3u,
        Dcm_ServiceTable_0x1_Session,
        2u,
        Dcm_ServiceTable_0x1_Security,
    },
    {
        DCM_SESSION_PROGRAMMING,
        2u,
        Dcm_ServiceTable_0x2_Session,
        2u,
        Dcm_ServiceTable_0x2_Security,
    },
    {
        DCM_SESSION_EXTEND,
        2u,
        Dcm_ServiceTable_0x3_Session,
        2u,
        Dcm_ServiceTable_0x3_Security,
    },
};
#endif

const Dcm_SessionType Dcm_ResetRow_Hard_Session[3] = {DCM_SESSION_DEFAULT,DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ResetRow_Hard_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_ResetRowType Dcm_ResetRow[DCM_RESET_NUM] =
{
    /* resetType, sessionSupp, securitySupp */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    {
        DCM_HARD_RESET,
        3u,
        Dcm_ResetRow_Hard_Session,
        2u,
        Dcm_ResetRow_Hard_Security,
    },
    {
        DCM_KEYONOFF_RESET,
        3u,
        Dcm_ResetRow_Hard_Session,
        2u,
        Dcm_ResetRow_Hard_Security,
    },
    {
        DCM_SOFT_RESET ,
        3u,
        Dcm_ResetRow_Hard_Session,
        2u,
        Dcm_ResetRow_Hard_Security,
    },
};

#if ((DCM_READDID_NUM > 0))

const Dcm_SecurityType Dcm_ReadDidRow_0xF084_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ReadDidRow_0xF085_Session[2] = {DCM_SESSION_DEFAULT,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ReadDidRow_0xF15B_Session[3] = {DCM_SESSION_DEFAULT,DCM_SESSION_PROGRAMMING,DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ReadDidRow_0xF084_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ReadDidRow_0xF085_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ReadDidRow_0xF15B_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_ReadDidRowType Dcm_ReadDidRow[DCM_READDID_NUM] =
{
        /* DID, securitySupp,readDataFct */
        /* @type:uint16 range:0x0000~0xFFFF note:NONE */
        /* @type:uint8 range:security value note:select defined security value */
        /* @type:API range:NONE note:input APIname */
#if 0  
    {
        0xF084u,
        2u,
        Dcm_ReadDidRow_0xF084_Security,
        Dcm_ReadDidRow_0xF084_Session,
        2,
        &Rte_Dcm_0xF084_ReadData
    },
    {
        0xF085u,
        2u,
        Dcm_ReadDidRow_0xF085_Security,
        Dcm_ReadDidRow_0xF085_Session,
        2,
        &Rte_Dcm_0xF085_ReadData
    },
#endif    
    {
        0xF15Bu,
        2u,
        Dcm_ReadDidRow_0xF15B_Security,
        Dcm_ReadDidRow_0xF15B_Session,
        3,
        &Rte_Dcm_0xF15B_ReadData
    },
};
#endif

const Dcm_SessionType Dcm_SecurityRow_Level5_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_SecurityRow_Level5_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SecurityRowType Dcm_SecurityRow[DCM_SECURITY_NUM] =
{
    /* seedId,
     * keyId,
     * secAccessLevel,
     * sessionSupp,
     * securitySupp
     * function :generateSeed
     * function :compareKey
     * */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:define range:DCM_SECURITY_LEV1~DCM_SECURITY_LEV2 note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    /* @type:API range:NONE note:input APIname */
    /* @type:API range:NONE note:input APIname */
    {
        0x9u,
        0x4u,
        0xau,
        0x4u,
        DCM_SECURITY_LEV5,
        1u,
        Dcm_SecurityRow_Level5_Session,
        2u,
        Dcm_SecurityRow_Level5_Security,
        &Dcm_SecMGenerateSeed,
        &Dcm_SecMCompareKey
    }
};

#if (DCM_COM_CONTROL_NUM > 0)

const Dcm_SessionType Dcm_ComCtrlRow_Enable_RxTx_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ComCtrlRow_Enable_RxTx_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_ComCtrlRow_Disable_RxTx_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_ComCtrlRow_Disable_RxTx_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_ComControlRowType Dcm_ComControlRow[DCM_COM_CONTROL_NUM] =
{
    /* controlType,
     * communicationType,
     * sessionSupp,
     * securitySupp */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    {
        DCM_ENABLE_RXANDTX,
        DCM_NORMAL_COM_MESSAGES|DCM_NM_COM_MESSAGES|DCM_NMANDNORMAL_COM_MESSAGES,
        1u,
        Dcm_ComCtrlRow_Enable_RxTx_Session,
        2u,
        Dcm_ComCtrlRow_Enable_RxTx_Security
    },
    {
        DCM_ENABLE_RXANDDISTX,
        DCM_NORMAL_COM_MESSAGES|DCM_NM_COM_MESSAGES|DCM_NMANDNORMAL_COM_MESSAGES,
        1u,
        Dcm_ComCtrlRow_Disable_RxTx_Session,
        2u,
        Dcm_ComCtrlRow_Disable_RxTx_Security
    },
    {
        DCM_DISABLE_RXANDENTX,
        DCM_NORMAL_COM_MESSAGES|DCM_NM_COM_MESSAGES|DCM_NMANDNORMAL_COM_MESSAGES,
        1u,
        Dcm_ComCtrlRow_Disable_RxTx_Session,
        2u,
        Dcm_ComCtrlRow_Disable_RxTx_Security
    },
    {
        DCM_DISABLE_RXANDTX,
        DCM_NORMAL_COM_MESSAGES|DCM_NM_COM_MESSAGES|DCM_NMANDNORMAL_COM_MESSAGES,
        1u,
        Dcm_ComCtrlRow_Disable_RxTx_Session,
        2u,
        Dcm_ComCtrlRow_Disable_RxTx_Security
    },
};
#endif

#if (DCM_WRITEDID_NUM > 0u)

const Dcm_SecurityType Dcm_WriteDidRow_0xF15A_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_WriteDidRow_0xF15A_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/

const Dcm_WriteDidRowType Dcm_WriteDidRow[DCM_WRITEDID_NUM] =
{
    /* DID,  dataLength,securitySupp,writeDataFct */
    /* @type:uint16 range:0x0000~0xFFFF note:NONE */
    /* @type:uint16 range:0x0001~0xFFFF note:NONE */
    /* @type:uint8 range:security value note:select defined security value */
    /* @type:API range:NONE note:input APIname */
    {
        (uint16)0xF15Au,
        (uint16)0x9u,
        1u,
        Dcm_WriteDidRow_0xF15A_Security,
        Dcm_WriteDidRow_0xF15A_Session,
        1,
        &Rte_Dcm_FingerPrint_0xF15A_WriteData
    },
};
#endif

#if (DCM_ROUTINE_CONTROL_NUM > 0u)

const Dcm_SessionType Dcm_RoutineCtrlRow_0xFF02_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_RoutineCtrlRow_0xFF02_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_RoutineControlType Dcm_RoutineCtrlRow_0xFF02_RoutineControl[1] = {DCM_START_ROUTINE,0};/*PRQA S 3408*/

const Dcm_SessionType Dcm_RoutineCtrlRow_0xFF00_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_RoutineCtrlRow_0xFF00_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_RoutineControlType Dcm_RoutineCtrlRow_0xFF00_RoutineControl[1] = {DCM_START_ROUTINE,9};/*PRQA S 3408*/

const Dcm_SessionType Dcm_RoutineCtrlRow_0xF001_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_RoutineCtrlRow_0xF001_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_RoutineControlType Dcm_RoutineCtrlRow_0xF001_RoutineControl[1] = {DCM_START_ROUTINE,4};/*PRQA S 3408*/

const Dcm_SessionType Dcm_RoutineCtrlRow_0xFF01_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_RoutineCtrlRow_0xFF01_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_RoutineControlType Dcm_RoutineCtrlRow_0xFF01_RoutineControl[1] = {DCM_START_ROUTINE,0};/*PRQA S 3408*/

const Dcm_SessionType Dcm_RoutineCtrlRow_0xF017_Session[1] = {DCM_SESSION_PROGRAMMING};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_RoutineCtrlRow_0xF017_Security[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/
const Dcm_RoutineControlType Dcm_RoutineCtrlRow_0xF017_RoutineControl[2] = {DCM_START_ROUTINE,1u,DCM_RESULT_ROUTINE,0u};/*PRQA S 3408*/

const Dcm_RoutineControlRowType Dcm_RoutineControlRow[DCM_ROUTINE_CONTROL_NUM] =
{
    /* routineId,optionLength,funcAddrSupp,sessionSupp,    securitySupp,routineControl */
    /* @type:uint16 range:0x0000~0xFFFF note:select unique routine Id */
    /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
    /* @type:boolean range:TRUE,FALSE note:auto generate */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    /* @type:API range:NONE note:auto generate */
    {
        (uint16)0xFF02u,
        (uint16)0x0u,
        1u,
        Dcm_RoutineCtrlRow_0xFF02_Session,
        2u,
        Dcm_RoutineCtrlRow_0xFF02_Security,
        1u,
        Dcm_RoutineCtrlRow_0xFF02_RoutineControl,
        &Rte_Dcm_CheckProgPreCondition_0xFF02,
        NULL_PTR
    },
    {
        (uint16)0xFF00u,
        (uint16)0x9u,
        1u,
        Dcm_RoutineCtrlRow_0xFF00_Session,
        1u,
        Dcm_RoutineCtrlRow_0xFF00_Security,
        1u,
        Dcm_RoutineCtrlRow_0xFF00_RoutineControl,
        &Rte_Dcm_EraseMemory_0xFF00,
        NULL_PTR
    },
    {
        (uint16)0xF001u,
        (uint16)0x4u,
        1u,
        Dcm_RoutineCtrlRow_0xF001_Session,
        1u,
        Dcm_RoutineCtrlRow_0xF001_Security,
        1u,
        Dcm_RoutineCtrlRow_0xF001_RoutineControl,
        &Rte_Dcm_CheckMemory_0xF001,
        NULL_PTR
    },
    {
        (uint16)0xFF01u,
        (uint16)0x0u,
        1u,
        Dcm_RoutineCtrlRow_0xFF01_Session,
        1u,
        Dcm_RoutineCtrlRow_0xFF01_Security,
        1u,
        Dcm_RoutineCtrlRow_0xFF01_RoutineControl,
        &Rte_Dcm_CheckProgDependencies_0xFF01,
        NULL_PTR
    },
    {
        (uint16)0xF017u,
        (uint16)0x0u,
        1u,
        Dcm_RoutineCtrlRow_0xF017_Session,
        1u,
        Dcm_RoutineCtrlRow_0xF017_Security,
        2u,
        Dcm_RoutineCtrlRow_0xF017_RoutineControl,
        &Rte_Dcm_SwapSwitch_0xF017,
        NULL_PTR
    },
};
#endif

const Dcm_SecurityType Dcm_DownloadRow_Security_DcmDownloadRow[1] = {DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_DownloadRowType Dcm_DownloadRow[DCM_DOWNLOADROW_NUM] =
{
    /* dataformatId
     * addrAndLenFormatId
     * securitySupp */
    /* @type:uint8 range:security value note:select defined security value */
    {
    0x0u,
    0x44u,
    1u,
    Dcm_DownloadRow_Security_DcmDownloadRow
    },
};

const Dcm_testPresentRowType Dcm_testPresentRow[DCM_TESTPRESENT_NUM] =
{
    /* testPresentSupp */
    /* @type:uint8 range:zeroSubFunc value note:select defined zeroSubFunc value */
    {
        0u
    }
};

#if (DCM_DTC_SET_NUM > 0)

const Dcm_SessionType Dcm_DTCSettingRow_ON_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_DTCSettingRow_ON_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_SessionType Dcm_DTCSettingRow_OFF_Session[1] = {DCM_SESSION_EXTEND};/*PRQA S 3408*/
const Dcm_SecurityType Dcm_DTCSettingRow_OFF_Security[2] = {DCM_SECURITY_LOCKED,DCM_SECURITY_LEV5};/*PRQA S 3408*/

const Dcm_DTCSettingRowType Dcm_DTCSettingRow[DCM_DTC_SET_NUM] =
{
    /* DTCSet,sessionSupp, securitySupp */
    /* @type:uint8 range:0x00~0xFF note:NONE */
    /* @type:uint8 range:session value note:select defined session value */
    /* @type:uint8 range:security value note:select defined security value */
    {
        DCM_DTC_SETTING_ON,
        1u,
        Dcm_DTCSettingRow_ON_Session,
        2u,
        Dcm_DTCSettingRow_ON_Security
    },
    {
        DCM_DTC_SETTING_OFF,
        1u,
        Dcm_DTCSettingRow_OFF_Session,
        2u,
        Dcm_DTCSettingRow_OFF_Security
    },
};
#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
