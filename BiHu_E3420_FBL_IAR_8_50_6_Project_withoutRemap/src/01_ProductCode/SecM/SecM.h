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
**  FILENAME    : SecM.h                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                             	  	  **
**  Vendor      :                                                             **
**  DESCRIPTION : Macros,Types defines and function declarations for Security **
**                Module.          											  **
**                                                                            **
**  SPECIFICATION(S) :   NONE		                    					  **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20121109    Gary              Initial version
 *  V1.0.1      20130913    ccl               update
 *  V1.0.2      20180511    CChen             update
 *  V1.0.3      20200426    Lianren.wu        label
 *  V1.0.4      20240402    Long.Zhu          Code comment review
 */
#ifndef SECM_H
#define SECM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "SecM_Cfg.h"
#include "FL.h"
#include "Cal.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define SECM_OK     (uint8)0x00U
#define SECM_NOT_OK (uint8)0x01U

/** CRC step */
#define SECM_CRC_INIT     0x00u
#define SECM_CRC_COMPUTE  0x01u
#define SECM_CRC_FINALIZE 0x02u

#if (CAL_CRC32 == CAL_METHOD)
#define SECM_CRC_LENGTH 0x04u
#elif (CAL_CRC16 == CAL_METHOD)
#define SECM_CRC_LENGTH 0x02u
#else
#define SECM_CRC_LENGTH 0x01u
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** return type for SecM module */
typedef uint8 SecM_StatusType;
/** type for Seed */
typedef uint8* SecM_WordType;
/** struct type for Seed */
typedef uint8 SecM_SeedType;
/** type for Key */
typedef uint8 SecM_KeyType;

/** struct type for Crc */
typedef struct
{
    /* current CRC value */
    SecM_CRCType currentCRC;
    /* CRC step */
    uint8 crcState;
    /* CRC buffer point */
    const uint8* crcSourceBuffer;
    /* CRC length */
    uint32 crcByteCount;
} SecM_CRCParamType;

/** struct type for verify parameter list */
typedef struct
{
    /* segment list for block */
    FL_SegmentListType* segmentList;
    /* Crc value transfered by UDS */
    const uint8* verificationData;
    /* Crc value title */
    SecM_CRCType crcTotle;
} SecM_VerifyParamType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
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
extern SecM_StatusType SecM_ComputeCRC(SecM_CRCParamType* crcParam);
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
extern void SecM_RealTimeComputeCRC(const uint8* crcSourceBuffer,uint32 crcByteCount,uint8 crcState);
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
extern SecM_StatusType SecM_Verification(const SecM_VerifyParamType* verifyParam);
#endif/* endif of SECM_H */
