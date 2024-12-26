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
**  FILENAME    : Dcm_Appl.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  Long.Zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS    **
**                services which used for bootloader project.                 **
**                                                                            **
**  SPECIFICATION(S) : ISO 14229-1-2020 Road vehicles -Unified diagnostic     **
**                     services (UDS) -Part 1 Application layer.pdf           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20200409    Lianren.Wu      Initial version
 *  V1.0.1      20200519    Lianren.Wu      add the judge for eraseAddress
                                            and eraseLength of Dcm_EraseMemory.
 *  V1.0.2      20200519    Lianren.Wu      optimization fuinction - Dcm_EraseMemory.
 *  V1.0.3      20231025    Long.Zhu        1.The 2E write interface logic can be adjusted to return conditional incorrect values.
 *											2.Delete the definitions, functions, and logic of BootSWReferenceNumber
 *                                          , ProgramSuccessCounter, ProgramtCounter, and RepairShopCode
											3.Compatibility check flag processing logic.
											4.31 The erase service processes NRC24 instead of NRC22.
 *  V1.0.4      20231201    Chunjun.hua     optimize DID read procedure
 *  V1.0.9      20231219    yaowei.shen     1.Appl_CheckConsistency add a parameter
 *                                          2.add function Dcm_SwapSwitch,Dcm_SwapRollBack
 *  V1.0.10      20240315    Long.Zhu        Dcm_EraseMemory Functional logic adjustment.
 *  V1.0.11      20240327    yaowei.shen     Dcm_SwapSwitch add Perform compatibility checks , no compatibility check  return NRC22
 *  V1.0.12      20240402    Long.Zhu        Code comment review.
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:FL<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 0306  Rule-11.4 .<br>
    Reason: The integral type expression address

    \li PRQA S 3206 Rule 2.7 .<br>
    Reason:The parameter '%s' is not used in this function.

    \li PRQA S 4604 Rule 21.2.<br>
    Reason:The object/function '%1s' is being declared with the same name as an ordinary identifier defined in '<%2s>'.

    \li PRQA S 3335 Rule 17.3.<br>
    Reason:The exception is use library API.

    \li PRQA S 2991 Rule 14.3 .<br>
    Reason:The exception is the result of this expression needs to be evaluated.

    \li PRQA S 2995 Rule 2.2.<br>
    Reason:The result of this logical operation is always 'true'.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Appl_Dcm.h"
#include "Rte_Inc.h"
#include "SecM_Cfg.h"
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

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
uint32 Dcm_SecMSeedCount;

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*==============================[31 Service]==================================*/
/******************************************************************************/
/**
 * @brief               <handle service 0x31 checksum>
 *
 * <handle service 0x31 checksum> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_CheckMemory(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    (void)txBuff;
    FL_ResultType checksumRet;

#ifdef PROJECT_SPECIAL_BIHU
    if(TRUE == FL_GetFLDownloaded())
    {
        Rte_Step_Set_CheckSUm();
    }
#endif
    /* execute checksum routine */
    checksumRet = FL_CheckSumRoutine(&rxBuff->pduInfo.SduDataPtr[4]);
    /* Check if that routine control of check memory is performed successfully */
    if ((uint8)FL_OK == checksumRet)
    {
        /* send NRC78 */
        Dcm_SendPending();
    }
    /* Check if information such as erasing sequence errors is received */
    else if ((uint8)FL_FAILED == checksumRet)
    {
        /* checksum sequence error, no finger print or download data */
        /* set negative response message */
        /* NRC 24  DCM_E_24_REQUEST_SEQUENCE_ERROR */
        Dcm_SendNrc((uint8)DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
    }
    /* Check if the routine control for checking memory is received does not meet the condition */
    else
    {
        /* set negative response message */
        /* NRC 22  DCM_E_22_CONDITIONS_NOT_CORRECT */
        Dcm_SendNrc((uint8)DCM_E_22_CONDITIONS_NOT_CORRECT);
    }

    return;
}

/******************************************************************************/
/**
 * @brief               <handle service 0x31 erase block>
 *
 * <handle service 0x31 erase block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_EraseMemory(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    (void)txBuff;
    uint8 parameterLen;
    uint32 eraseAddress;
    uint32 eraseLength;
    FL_ResultType eraseRet = (uint8)FL_INVALID_DATA;

    sint8 startIdx;
    sint8 endIdx;

    parameterLen = rxBuff->pduInfo.SduDataPtr[4];
    /* get and convert address format */
    eraseAddress = DP_Get4Byte(&rxBuff->pduInfo.SduDataPtr[5]);
    eraseAddress = Rte_Appl_ConvertAddress(eraseAddress);
    eraseLength = DP_Get4Byte(&rxBuff->pduInfo.SduDataPtr[9]);
    eraseLength = Rte_Appl_ConvertSize(eraseLength);
    /* Check if the address and length are both 4 bytes */
    if ((uint8)0x44u != parameterLen)
    {
    }
#if (FL_FINGER_PRINT_WRITE_ENABLE == STD_ON)    
    else if(FALSE == Dcm_GetFingerPrintWrittenStatus())
    {
        eraseRet = FL_NO_FINGERPRINT;
    }
#endif    
    else
    {
        if (FL_OK == Rte_BlkM_SearchBlock(eraseAddress, eraseLength, &startIdx, &endIdx))
        {
            eraseRet = FL_OK;
            eraseLength = 0;
            eraseAddress =  (Rte_BlkM_GetCfgInfo())[startIdx].address;
            for (; eraseRet == FL_OK && startIdx <= endIdx; startIdx++)
            {
                eraseLength += (Rte_BlkM_GetCfgInfo())[startIdx].length;
                eraseRet = FL_EraseRoutine(startIdx);
            }

        }
    }


    /* Clear the corresponding NvM integrity marker data according to the Block index number */
    if ((uint8)FL_OK == eraseRet)
    {

        /* send NRC78 */
        Dcm_SendPending();
        eraseRet = Rte_BlkM_UpdateNvm();
    }

    if ((uint8)FL_OK == eraseRet)
    {
        eraseRet = Rte_ProgAttemptAdd();
    }

    /* Check if that routine control of erase memory is performed successfully */
    if ((uint8)FL_OK == eraseRet)
    {
#ifdef PROJECT_SPECIAL_BIHU
        Rte_Step_Set_erase();
#endif        
        /* get erase */
        FL_Get_EraseInfo(eraseAddress, eraseLength);
        /* send NRC78 */
//        Dcm_SendPending();
        Dcm_StartP4sTimer_Max((uint32)DCM_P4MAX_TIME_ERASE);
        dcmDspProgram.ErasedLength = eraseLength;
        dcmDspProgram.ErasedAddress = eraseAddress;
#if(BL_BUS_MODE == BL_BUS_MODE_LIN)
        while(Dcm_GetTxStatus() != DCM_BUFF_FREE)
        {
            ;
        }
#endif
    }
    /* Check if information such as erasing sequence errors, no write fingerprint, or download data is received */
    else if (
        ((uint8)FL_NO_FINGERPRINT == eraseRet) || ((uint8)FL_ERR_SEQUENCE == eraseRet)
        || ((uint8)FL_CONDITIONS_NOT_CORRECT == eraseRet)
        || ((uint8)FL_NO_FLASHDRIVER == eraseRet))
    {
        /* erase sequence error, no finger print or download data */
        /* set negative response message */
        /* NRC 24  DCM_E_24_REQUEST_SEQUENCE_ERROR */
        Dcm_SendNrc((uint8)DCM_E_22_CONDITIONS_NOT_CORRECT);
    }
    /* Check if invalid data parameters are received */
    else if ((uint8)FL_INVALID_DATA == eraseRet)
    {
        /* set negative response message */
        /* NRC 31  DCM_E_31_REQUEST_OUT_OF_RANGE */
        Dcm_SendNrc((uint8)DCM_E_31_REQUEST_OUT_OF_RANGE);
    }
    /* Check if the routine control for erasing was received failed */
    else
    {
        /* FL_FAILED == eraseRet */
        /* set negative response message */
        /* NRC 72  DCM_E_72_GENERAL_PROGRAMMING_FAILURE */
        Dcm_SendNrc((uint8)DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
    }
}

/******************************************************************************/
/**
 * @brief               <handle service 0x31 check dependency>
 *
 * <handle service 0x31 check dependency> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_CheckProgDependencies(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    (void)rxBuff;
    FL_ResultType CheckStatus = FL_OK;

#ifdef PROJECT_SPECIAL_BIHU
    if(TRUE == Rte_Step_Check_CheckSum())
    {
        CheckStatus = FL_OK;
    }
    else
    {
        Dcm_PhyAddrSendNrc(FALSE, rxBuff->pduId, DCM_E_22_CONDITIONS_NOT_CORRECT);
        CheckStatus = FL_FAILED;
    }
    Rte_Step_Set_CheckCompabilit();
#endif
    if ((uint8)FL_OK == CheckStatus)
    {
        /* execute routine for check application software dependency */
        /* if needed, please add more check in there*/
        CheckStatus = Rte_BlkM_CheckCompatibility();
    }
    if ((uint8)FL_OK == CheckStatus)
    {
    	CheckStatus = Appl_CheckDependence();
    }

    /* send NRC78 */
    Dcm_SendPending();

    /* Check if all Block integrity valid flags are TRUE */
    if ((uint8)FL_OK == CheckStatus)
    {
        Rte_BlkM_SetIfAppValid();
        if ((FL_OK!= Rte_BlkM_UpdateNvm()) || (FL_OK != Rte_ProgSuccessAdd())
#if (RTE_PARTITION_SWAP_ON == STD_ON)
        || (TRUE == Rte_BlkM_GetIsProgramed() && FALSE == Rte_ABSwap_Switch())
#endif
        )
        {
            Dcm_SendNrc(DCM_E_72_GENERAL_PROGRAMMING_FAILURE);
        }
        else
        {
            /* Program dependency is valid */
            txBuff->pduInfo.SduDataPtr[4] = (uint8)0x00u;
        }
    }
    else
    {
        /* Set the response of the routine control service to fail */
        txBuff->pduInfo.SduDataPtr[4] = (uint8)0x01u;
    }
    
    if ((boolean)FALSE == Dcm_GetComStatus()->respFinished)
    {
        txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
        txBuff->pduInfo.SduDataPtr[1] = rxBuff->pduInfo.SduDataPtr[1];
        txBuff->pduInfo.SduDataPtr[2] = rxBuff->pduInfo.SduDataPtr[2];
        txBuff->pduInfo.SduDataPtr[3] = rxBuff->pduInfo.SduDataPtr[3];
        txBuff->pduInfo.SduLength = (uint8)0x05u;
        Dcm_SendRsp();
    }
}

/******************************************************************************/
/**
 * @brief               <handle service 0x31 check program pre-condition>
 *
 * <handle service 0x31 check program pre-condition> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_CheckProgPreCondition(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    (void)rxBuff;
    uint8 conditionLength;

    if ((uint8)DCM_SESSION_EXTEND != Dcm_GetSessionMode())
    {
        /* set negative response message */
        /* NRC 7F: DCM_E_7F_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION */
        Dcm_SendNrc((uint8)DCM_E_7F_SERVICE_NOT_SUPPORTED_IN_ACTIVE_SESSION);
    }
    else
    {
        /* execute routine for check programming pre-conditions */
        conditionLength = FL_CheckProgPreCondition(&txBuff->pduInfo.SduDataPtr[4]);
        if ((uint8)0x00U == conditionLength)
        {
            /* programming pre-conditions is accepted */
            dcmDspProgram.condition = (boolean)TRUE;
        }
        else
        {
            /* programming pre-conditions is not accepted */
            dcmDspProgram.condition = (boolean)FALSE;
        }
        /* send NRC78 */
        /* if OK, let pending31() response, not here */
        // Dcm_SendPending();
        txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
        txBuff->pduInfo.SduDataPtr[1] = rxBuff->pduInfo.SduDataPtr[1];
        txBuff->pduInfo.SduDataPtr[2] = rxBuff->pduInfo.SduDataPtr[2];
        txBuff->pduInfo.SduDataPtr[3] = rxBuff->pduInfo.SduDataPtr[3];
        txBuff->pduInfo.SduDataPtr[4] = 0u;
        txBuff->pduInfo.SduLength = (uint8)0x05u;
        Dcm_SendRsp();
    }
}


/******************************************************************************/
/**
 * @brief               <Perform partition Switching >
 *
 * <Perform partition Switching > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff>
 * @param[out]          <txBuff>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_SwapSwitch(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
#if(RTE_PARTITION_SWAP_ON == STD_ON)
    static uint8 err = 0u;
    uint8 nrc = 0u;
    switch(rxBuff->pduInfo.SduDataPtr[1])
    {
        case 0x01u:
        err = 0u;
        if(rxBuff->pduInfo.SduDataPtr[4]!=0x01u)
        {
            nrc = DCM_E_31_REQUEST_OUT_OF_RANGE;
        }
        else if (TRUE == Rte_BlkM_GetIsProgramming() && TRUE != Rte_BlkM_GetIsProgramed())
        {
            nrc = DCM_E_22_CONDITIONS_NOT_CORRECT;
        }
        else
        {
            txBuff->pduInfo.SduLength = (uint8)0x04u;
            if (FALSE == Rte_BlkM_GetIntergrity())
            {
                err = 3u;
            }
            else if (FALSE == Rte_BlkM_GetCompatibility())
            {
                err = 4u;
            }
            else if (FALSE == Rte_BlkM_GetAppValid())
            {
                err = 5u;
            }
            else if (TRUE == Rte_ABSwap_Switch())
            {
                err = 1u;
            }
            else
            {
                err = 2;
            }
        }
        break;
        default:
        if(err== 0u)
        {
            nrc = DCM_E_24_REQUEST_SEQUENCE_ERROR;
        }
        else if(err == 1u)
        {
            /*
            Status Byte0:
            0x00 Success
            0x01 Failed
            0x02 Pending
            Process Byte1:
            0x00~0x64 (0%~100%)
            */
            txBuff->pduInfo.SduDataPtr[4] = 0u;
            txBuff->pduInfo.SduDataPtr[5] = 0x64u;
            txBuff->pduInfo.SduLength = (uint8)0x06u;
        }
        else
        {
            txBuff->pduInfo.SduDataPtr[4] = 1u;
            // txBuff->pduInfo.SduDataPtr[5] = err;
            txBuff->pduInfo.SduDataPtr[5] = 0x00;
            txBuff->pduInfo.SduLength = (uint8)0x06u;
        }

        break;
    }

    if(nrc == 0)
    {
        txBuff->pduInfo.SduDataPtr[0] = (uint8)0x71u;
        txBuff->pduInfo.SduDataPtr[1] = rxBuff->pduInfo.SduDataPtr[1];
        txBuff->pduInfo.SduDataPtr[2] = rxBuff->pduInfo.SduDataPtr[2];
        txBuff->pduInfo.SduDataPtr[3] = rxBuff->pduInfo.SduDataPtr[3];
        Dcm_SendRsp();
    }
    else
    {
        Dcm_SendNrc(nrc);
    }
#endif
}

/******************************************************************************/
/**
 * @brief               <Perform partition Rollback >
 *
 * <Perform partition Rollback > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff>
 * @param[out]          <txBuff>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Dcm_SwapRollBack(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
#if(RTE_PARTITION_SWAP_ON == STD_ON)
#endif
}

/*==============================27 Service ===================================*/
/******************************************************************************/
/**
 * @brief               <generate seed for UDS>
 *
 * <Needed by the UDS module,generate seed> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <seed:Seed data pointer.>
 * @param[in/out]       <NONE>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
SecM_StatusType Dcm_SecMGenerateSeed(SecM_SeedType* seed)
{
	Rte_SecM_GenerateSeed((uint8*)seed,DCM_SEED_MAX_LENGTH);

    return (uint8)SECM_OK;
}

/******************************************************************************/
/**
 * @brief               <compare key>
 *
 * <Needed by the UDS module,compare seed> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <KeyLength: Key length.
 * 						 key:Key data pointer.
 * 						 seed:seed data pointer. >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <SECM_OK/SECM_NOT_OK:Compare key success or failure>
 */
/******************************************************************************/
SecM_StatusType Dcm_SecMCompareKey(uint8 KeyLength, const SecM_KeyType* key, const SecM_SeedType* seed)
{
    boolean compare;
    SecM_StatusType retVal;
    SecM_KeyType getkey[DCM_KEY_MAX_LENGTH];

    retVal = Rte_Dcm_SecMComputeKey(seed, (const SecM_WordType)SecM_SecConst, getkey);
    compare = DP_Memcompare(getkey, key, KeyLength);
    if ((boolean)TRUE != compare)
    {
        retVal = (uint8)SECM_NOT_OK;
    }

    return retVal;
}

#if (STD_ON == FL_FINGER_PRINT_WRITE_ENABLE)
static boolean fingerWritten = FALSE;
/******************************************************************************/
/*
 * Brief               <Set finger print written status.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE >
 * Return              <NONE>
 */
/******************************************************************************/
void Dcm_SetFingerPrintWrittenStatus(void)
{
	fingerWritten = TRUE;
}
/******************************************************************************/
/*
 * Brief               <Clear finger print written status.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE >
 * Return              <NONE>
 */
/******************************************************************************/
void Dcm_ClearFingerPrintWrittenStatus(void) 
{
	fingerWritten = FALSE;
}
/******************************************************************************/
/*
 * Brief               <Get finger print written status.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE >
 * Return              <boolean.>
 */
/******************************************************************************/
boolean Dcm_GetFingerPrintWrittenStatus(void)
{
		return fingerWritten;
}
#endif

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


