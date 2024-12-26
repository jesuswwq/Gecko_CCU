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
**  FILENAME    :  SecM.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION :  seed and key generate for UDS                              **
**                                                                            **
**  SPECIFICATION(S) : NONE                       		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20121109    Gary         Initial version
 *  V1.0.1      20130517    liuyp        modify the generate key algorithm
 *  V1.0.2      20130913    ccl          update
 *  V1.0.3      20180511    CChen        update
 *  V1.0.4      20200426    Lianren.wu   modify function: SecM_ProcessCal
 *  V1.0.5      20240402    Long.Zhu     Code comment review
 *  V1.0.6      20240424    chunjun.hua  QAC fix
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:SecM .<br>
  RuleSorce:puhua-rule2024.rcf 1.0.2

    \li PRQA S 0306 Rule-11.4 .<br>
    Reason: The integral type expression address
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "SecM.h"
#include "Appl.h"

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
#if 0
static SecM_StatusType SecM_ProcessCal(SecM_CRCParamType* crcParam, uint32 Address, uint32 Length);
#endif
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*Transmits data to calculate CRC values in real time. */
static SecM_CRCParamType crcParamCal;

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <compute CRC>
 *
 * <process CRC compute,include init,compute and finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <crcParam >
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
SecM_StatusType SecM_ComputeCRC(SecM_CRCParamType* crcParam)
{
    SecM_StatusType retVal = (uint8)SECM_OK;

    switch (crcParam->crcState)
    {
    case SECM_CRC_INIT:
        /* CRC value initialize */
        Cal_CrcInit(&crcParam->currentCRC);
        break;
    case SECM_CRC_COMPUTE:
        /* CRC value compute */
        Cal_CrcCal(&crcParam->currentCRC, crcParam->crcSourceBuffer, (uint32)crcParam->crcByteCount);
        break;
    case SECM_CRC_FINALIZE:
        /* CRC value finish */
        Cal_CrcFinalize(&crcParam->currentCRC);
        break;
    default:
        retVal = (uint8)SECM_NOT_OK;
        break;
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <Real time compute CRC.>
 *
 * <process CRC compute,include init,compute and finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <crcState
 * 						crcByteCount
 * 						crcSourceBuffer>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void SecM_RealTimeComputeCRC(const uint8* crcSourceBuffer,uint32 crcByteCount,uint8 crcState)
{   
    uint32 ConvertAddress;
    const uint8* ConvertBuffer;
    ConvertAddress = Appl_ConvertLogicAddress((uint32)crcSourceBuffer);/*PRQA S 0306*/
    ConvertBuffer = (uint8*)ConvertAddress;/*PRQA S 0306*/
    switch (crcState)
    {
		case SECM_CRC_INIT:
			/* CRC value initialize */
			crcParamCal.currentCRC = 0;
			Cal_CrcInit(&crcParamCal.currentCRC);
			break;
		case SECM_CRC_COMPUTE:
			/* CRC value compute */
			crcParamCal.crcSourceBuffer = ConvertBuffer;
			crcParamCal.crcByteCount = crcByteCount;
			Cal_CrcCal(&crcParamCal.currentCRC, crcParamCal.crcSourceBuffer, crcParamCal.crcByteCount);
			break;
		case SECM_CRC_FINALIZE:
			/* CRC value finish */
			Cal_CrcFinalize(&crcParamCal.currentCRC);
			break;
		default:
			/*empty*/
			break;
    }
}
/******************************************************************************/
/**
 * @brief               <verificate CRC value>
 * <verificate if transfered CRC is equal to computed CRC> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <verifyParam >
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
SecM_StatusType SecM_Verification(const SecM_VerifyParamType* verifyParam) 
{
    SecM_StatusType retVal = (uint8)SECM_OK;
    SecM_CRCType transferedCrc;

    if (NULL_PTR == verifyParam->segmentList)
    {
        /* if segment list is NULL, verification is failed */
        retVal = (uint8)SECM_NOT_OK;
    }
    else
    {
    	/* finish compute CRC */
        SecM_RealTimeComputeCRC(NULL_PTR,0,SECM_CRC_FINALIZE);
    }

    if ((uint8)SECM_OK == retVal)
    {
        /* get CRC transfered from client */
#if (CAL_CRC32 == CAL_METHOD)
        /* CRC32 */
        transferedCrc = DP_Get4Byte(verifyParam->verificationData);
#elif (CAL_CRC16 == CAL_METHOD)
        /* CRC16 */
        transferedCrc = ((SecM_CRCType)verifyParam->verificationData[0] << 8U);
        transferedCrc += (SecM_CRCType)verifyParam->verificationData[1];
#else
        /* CRC8 */
#endif
        /* compare CRC */
        if (transferedCrc != crcParamCal.currentCRC)
        {
            retVal = (uint8)SECM_NOT_OK;
        }
        else
        {
            /* do nothing */
        }
    }
    return retVal;
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if 0
/******************************************************************************/
/**
 * @brief               <process CRC compute>
 *
 * <CRC compute> .
 * @param[in]           <Address , Length >
 * @param[out]          <NONE>
 * @param[in/out]       <crcParam >
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
static SecM_StatusType SecM_ProcessCal(SecM_CRCParamType* crcParam, uint32 Address, uint32 Length)
{
    SecM_StatusType retVal = (uint8)SECM_OK;
    uint32 readLength;

    /* set CRC compute step */
    crcParam->crcState = (uint8)SECM_CRC_COMPUTE;

    while ((Length > (uint32)0U) && ((uint8)SECM_OK == retVal))
    {
        /* read maximum length is SECM_CAL_BUFFER_LEN */
        if (Length > (uint32)SECM_CAL_BUFFER_LEN)
        {
            readLength = (uint32)SECM_CAL_BUFFER_LEN;
        }
        else
        {
            readLength = Length;
        }
        /* the readLength will be restricted in lien 321- 325 */
        crcParam->crcByteCount = (uint16)readLength;
        crcParam->crcSourceBuffer = (uint8*)Address; /*PRQA S 0306*/
        /* compute CRC */
        retVal = SecM_ComputeCRC(crcParam);

        Length -= readLength;
        Address += readLength;
    }
    return retVal;
}
#endif
