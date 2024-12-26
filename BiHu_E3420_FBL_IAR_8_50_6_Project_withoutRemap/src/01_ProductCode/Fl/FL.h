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
**  FILENAME    : FL.h                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                             	      **
**  Vendor      :                                                             **
**  DESCRIPTION : Macros,Types defines and function declarations for 		  **
**  			Flash Driver Module.           								  **
**                                                                            **
**  SPECIFICATION(S) :    his flashloader specification v1.1.pdf              **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20121227     Gary            Initial version
 *  V1.0.1     20160801     cywang          update
 *  V1.0.2     20180511     CChen           update
 *  V1.0.3     20200413     Lianren.Wu      optimization
 *  V2.0.0     20220307     Haibin.shao     update
 *  V2.0.1     20240402    Long.Zhu          Code comment review
 */
#ifndef FL_H_
#define FL_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FL_Type.h"
#include "FL_Cfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <flashloader module initialize >
 * <initialize download status> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void FL_Init(void);
/******************************************************************************/
/**
 * @brief               <flashloader module initialize state>
 * <initialize download status> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void FL_InitState(void);
/******************************************************************************/
/**
 * @brief               <flash main function for active job>
 * <flash main function for active job,process checksum,erase and program> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void FL_MainFunction(void);
/******************************************************************************/
/**
 * @brief               <0x31 service routine checksum>
 * <checksum routine for flash driver or logical blocks,only for current
 *  download address> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <checkSum >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_CheckSumRoutine(const uint8* checkSum);
/******************************************************************************/
/**
 * @brief               <0x31 service routine erase>
 * <erase routine for  logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <blockIndex  : is the block number>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_EraseRoutine(const uint8 blockIndex);
/******************************************************************************/
/**
 * @brief               <0x34 service download request>
 * <download request for current logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <startAdd , length >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_DownloadRequest(const uint32 startAdd, const uint32 length);
/******************************************************************************/
/**
 * @brief               <0x34 service download request>
 * <download request for current logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <startAdd , length >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_DownloadRequestValidCheck(const uint32 startAdd, const uint32 length);
/******************************************************************************/
/**
 * @brief               <0x36 service download data>
 * <download data for current logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <destAddr , sourceBuff , length >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_FlashProgramRegion(const uint32 destAddr, const uint8* sourceBuff, const uint32 length);
/******************************************************************************/
/**
 * @brief               <0x36 service download data>
 * <download data for current logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <destAddr , sourceBuff , length >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_FlashDown_TransferStateCheck(const uint32 destAddr, const uint32 length);
/******************************************************************************/
/**
 * @brief               <0x37 service download finish>
 * <download finish for current logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void FL_ExitTransferData(void);
/******************************************************************************/
/**
 * @brief               <FL_Get_EraseInfo>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <startAdd , length >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void FL_Get_EraseInfo(const uint32 startAdd, const uint32 length);
/******************************************************************************/
/**
 * @brief               <get service status>
 * <supply active job status for service witch can not response with in 50ms,
 *  and send pending> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <error >
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean FL_ServiceFinished(FL_ResultType* error);
/******************************************************************************/
/**
 * @brief               <Update stored data to non-volatile memory.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_UpdateBlockIntergrityNvm(void);
/******************************************************************************/
/**
 * @brief               <Update stored data to non-volatile memory.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_UpdateBlkProgDependenceNvm(void);
/******************************************************************************/
/**
 * @brief               <Update stored data to non-volatile memory.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_UpdateSecurityAccessNvm(void);
/******************************************************************************/
/**
 * @brief               <Update stored data to non-volatile memory.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_UpdateProgramMarkNvm(void);
/******************************************************************************/
/**
 * @brief               <Init FL download step.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void FL_InitFLDownloadStep(void);
/******************************************************************************/
/**
 * @brief               <Parameter Outgoing FldownloadStatus.downloadStep>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_DownloadStepType>
 */
/******************************************************************************/
extern FL_DownloadStepType FL_GetFLDownloadStep(void);
/******************************************************************************/
/**
 * @brief               <Parameter Outgoing FldownloadStatus.flDrvDownloaded>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean FL_GetFLDownloaded(void);
/******************************************************************************/
/**
 * @brief               <Parameter Outgoing FldownloadStatus.blockIndex.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint8>
 */
/******************************************************************************/
extern uint8 FL_GetDownloadBlcokIndex(void);
/******************************************************************************/
/**
 * @brief               <Parameter Outgoing FL_SecurityAccessNvmInfo.blkSecAcAttemptCounter[secLev].>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <secLev:Security unlocking level.>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
extern uint32 FL_GetSecurityAccessAttemptCounter(uint8 secLev);
/******************************************************************************/
/**
 * @brief               <Parameter Outgoing FL_BlkIntegrityNvmInfo.blkProgSuccessCounter.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
extern uint32 FL_GetProgramSuccessCounter(void);
/******************************************************************************/
/**
 * @brief               <Parameter Outgoing FL_BlkIntegrityNvmInfo.blkProgAttemptCounter.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
extern uint32 FL_GetProgramAttemptCounter(void);
/******************************************************************************/
/**
 * @brief               <Parameter Outgoing FldownloadStatus.activeJob>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean FL_CheckConditionForPending(void);
/******************************************************************************/
/**
 * @brief               < check program pre-condition >
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <* conditions >
 * @param[in/out]       <NONE>
 * @return              <uint8>
 */
/******************************************************************************/
extern uint8 FL_CheckProgPreCondition(uint8* conditions);
/******************************************************************************/
/**
 * @brief               <Get minimum program counter.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
extern uint32 FL_GetMinProgramCounter(void);
/******************************************************************************/
/**
 * @brief               <Get max program counter.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
extern uint32 FL_GetMaxProgramCounter(void);
/******************************************************************************/
/**
 * @brief               <get FldownloadStatus errorCode>
 * <return FldownloadStatus errorCode > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType FL_GetFldownloadStatusErrorCode(void);

#if (STD_ON == FL_PROG_PRE_CONDITION_USED)
/******************************************************************************/
/**
 * @brief               <Check vehicle speed non zero.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean FL_CheckVehicleSpeedNonZero(void);
/******************************************************************************/
/**
 * @brief               <Check power under voltage.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean FL_CheckPowerUnderVoltage(void);
/******************************************************************************/
/**
 * @brief               <Check power over voltage.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean FL_CheckPowerOverVoltage(void);
#endif

#if (STD_ON == FL_SERVICE_0X38_ENABLE)
/******************************************************************************/
/**
 * @brief               <File download.>
 * <File download service finished.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <error >
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean File_ServiceFinished(FL_ResultType* error);
/******************************************************************************/
/**
 * @brief               <File download.>
 * <Get file download step.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_DownloadStepType>
 */
/******************************************************************************/
extern FL_DownloadStepType File_GetFLDownloadStep(void);
/******************************************************************************/
/**
 * @brief               <File download.>
 * <File download transfer state check.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <length>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType File_TransferStateCheck(const uint32 length);
/******************************************************************************/
/**
 * @brief               <File download.>
 * <File download flash program region.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <sourceBuff
 * 						 length>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType File_FlashProgramRegion(const uint8* sourceBuff, const uint32 length);
/******************************************************************************/
/**
 * @brief               <File download.>
 * <File download exit transfer data.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void File_ExitTransferData(void);
#endif
/******************************************************************************/
/*
 * @brief              [Fl_GetRemainingLen description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
extern uint32 Fl_GetRemainingLen(void);
#endif/* endif of FL_H_ */

