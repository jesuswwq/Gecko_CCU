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
**  FILENAME    : FL.c                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : The Code process checksum,erase and program                 **
**                for bootloader project.                                     **
**                                                                            **
**  SPECIFICATION(S) :  his flashloader specification v1.1.pdf                **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20121227     Gary            Initial version
 *  V1.0.1     20160801     cyWang          update
 *  V1.0.2     20180511     CChen           update
 *  V1.0.3     20200413     Lianren.Wu      optimization
 *  V1.0.4     20200508     Lianren.Wu      modify FL_FlashProgramRegion for 36 service,
 *                                           add FL_FlashDown_TransferStateCheck function for 36 service.
 *  V1.0.5     20200512     Lianren.Wu      Separating the function and errors of FL_DownloadRequestValid.
 *  V1.0.6     20200606     Lianren.Wu      modify FL_mainfunction, if the handle job is
 *                                           check-memory,init the FLstate if the handle ok or not.
 *  V1.0.7     20200705     Lianren.Wu      modify the FL_FlashDown_TransferStateCheck is only check the transferState,
 *                                           add the FL_FlashDown_AddrLenCheck to check the download address and length.
 *  V1.0.8     20200811     Lianren.Wu      optimize the function call of FL_InitState
 *  V1.0.9     20220307     Haibin.shao     Update the logic of multi-block processing mechanism,
 *                                           the data structure of NvM storage and the timing of marker storage,
 *                                           the processing flow of erase logic, and some adjustments of auxiliary
 *  V1.0.10    20221113     Long.Zhu         1、Add the FL ERR MEMORY processing logic.
 *										     2.FL_Init The initial content of the function is adjusted.
 *										     3.Encapsulates flash erase and write functions.
 *										     4.Logical block erase status State machine adjustment.
 *										     5.Compatibility check flag processing logic.
 *										     6.FldownloadStatus.errorCode Error feedback is used up and cleared.
 *										     FL_MainFunction Functional logic adjustment.
 *
 *  V1.0.11    20231218     yaowei.shen     1.modify BLFlash_InfoPtr->BLFlashIf_InfoPtr
 *                                          2.fix CRC caluation logic;
 *                                          3.modify nrOfSegments,calNrOfSegment type uint8->uint32
 *                                          4.Fixed an error with download NRC response not performing erase execution.
 *                                          5.clear FL_RemainDataStruct.remainLength,FL_RemainDataStruct.remainAddr after eraser.
 *  V1.0.12    20240315     Long.Zhu        Add functional FL_CheckAddressRange.
 *  V1.0.13    20240402     yaowei.shen     blkProgSuccessCounter add after compatibility check.
 *  V1.0.14    20240402     Long.Zhu         Code comment review
 *  V1.0.15    20240404     Long.Zhu        Add function FL_ResetAllBlockEraseState()
 *  V1.0.16    20240424     chunjun.hua     QAC fix
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:FL .<br>
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
#include "FL.h"
#include "FL_Type.h"
#include "SecM.h"
#include "Appl.h"
#include "Appl_Dcm.h"
#include "Dcm_Internel.h"

#include "Rte_Inc.h"
#include "FlashIf.h"
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
static FL_ResultType FL_Erasing(void);

static FL_ResultType FL_DownloadRemainData(void);

static FL_ResultType FL_HandleRemainData(void);

static FL_ResultType FL_ProgrammingData(void);

static FL_ResultType FL_Programming(void);

static FL_ResultType FL_CheckSuming(void);

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* save the data which not aligned */
static FL_RemainDataType FL_RemainDataStruct;

/* flashloader status information */
static FL_DownloadStateType FldownloadStatus;

static FL_EraseInfoType Fl_EraseStatus;

/* flashloader program buffer */
static uint8 FL_ProgramData[FL_PROGRAM_SIZE];

/* flashloader program length */
static uint32 FL_ProgramLength;

/* flash driver API input parameter */
static tFlashParam flashParamInfo = {
    (uint8)FLASH_DRIVER_VERSION_PATCH,
    (uint8)FLASH_DRIVER_VERSION_MINOR,
    (uint8)FLASH_DRIVER_VERSION_MAJOR,
    FLASH_UNINIT,
    (uint8)kFlashOk,
    (uint16)0x0000U,
    (uint32)0UL,
    (uint32)0UL,
    NULL_PTR,
    NULL_PTR,
#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
    &Appl_wdTriggerFct
#else
	NULL_PTR
#endif
};
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
void FL_DisableFlsDrv(void);
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
void FL_Init(void) 
{
    /* flash driver is not downloaded */
#ifdef PROJECT_SPECIAL_BIHU
    Rte_Step_Check_Init();
#endif
    FL_DisableFlsDrv();
    FL_InitState();
}

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
void FL_InitState(void)
{
    /* download step is download request 0x34 */
    FL_InitFLDownloadStep();
    /* init nrOfSegments */
    FldownloadStatus.segmentList.nrOfSegments = (uint32)0x00u;
    FldownloadStatus.segmentList.calNrOfSegment = (uint32)0x00u;
    /* current active job is idle */
    FldownloadStatus.activeJob = FL_JOB_IDLE;
    /*init remainLength and remainAddr */
    FL_RemainDataStruct.remainLength = (uint32)0U;
    FL_RemainDataStruct.remainAddr = (uint32)0U;
    FL_ProgramLength = (uint32)0U;


}

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
FL_ResultType FL_CheckSumRoutine(const uint8* checkSum) 
{
    FL_ResultType retVal = (uint8)FL_OK;
    /* record checksum buffer address, this is the CheckSum data send from tester */
    FldownloadStatus.dataBuff = checkSum;
    /* check if download step is checksum step */
    if (FL_CHECKSUM_STEP == FldownloadStatus.downloadStep)
    {
        /* set the download active state to checksum */
        FldownloadStatus.activeJob = FL_JOB_CHECKING;
        FldownloadStatus.errorCode = (uint8)FL_OK;
        if ((boolean)TRUE == FldownloadStatus.flDrvDownloaded)
        {
            retVal = FL_DownloadRemainData();
        }
    }
    else
    {
        /* initialize the flash download state */
        FL_InitState();
        /*"Synchronize with the baseline" retVal = (uint8)FL_CONDITIONS_NOT_CORRECT;*/
        retVal = (uint8)FL_ERR_SEQUENCE;
    }
    return retVal;
}

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
FL_ResultType FL_EraseRoutine(const uint8 blockIndex) 
{
    FL_ResultType retVal = FL_OK;
    /* Check if flash driver has been downloaded */
    if ((boolean)FALSE == FldownloadStatus.flDrvDownloaded)
    {
            retVal = (uint8)FL_NO_FLASHDRIVER;
    }
/* ----------------projectCfg---------------- */
#if 0
    else if ((FL_REQUEST_STEP != FldownloadStatus.downloadStep)
    && (FL_CHECKSUM_STEP != FldownloadStatus.downloadStep))
    {
    	retVal = (uint8)FL_ERR_SEQUENCE;
    }
#endif
/* ----------------projectCfg---------------- */
	else if (blockIndex >= (uint8)FL_NUM_LOGICAL_BLOCKS)
    {
    	retVal = (uint8)FL_INVALID_DATA;
	}
    else
    {
		/* change and initialize status of the programmed block */
        FldownloadStatus.segmentList.nrOfSegments = (uint32)0x00u;
        FldownloadStatus.segmentList.calNrOfSegment = (uint32)0x00u;

        FldownloadStatus.errorCode = (uint8)FL_OK;

        FL_RemainDataStruct.remainLength = (uint32)0U;
        FL_RemainDataStruct.remainAddr = (uint32)0U;
        /* set the download active state to erase */
        FldownloadStatus.activeJob = FL_JOB_ERASING;
        Rte_BlkM_SetBlockInValid(blockIndex);
    }

    if(retVal != FL_OK)
    {
        /* Initialize the flash download state */
        FL_InitState();
    }
    return retVal;
}

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
FL_ResultType FL_DownloadRequest(const uint32 startAdd, const uint32 length) 
{
    FL_ResultType retVal = (uint8)FL_OK;
    FL_SegmentInfoType* curSegment;
    uint32 segmentIndex;

    /* save the parameter used for active job use */
    FldownloadStatus.startAddr = startAdd;
    FldownloadStatus.downLength = length;

    /* get current segment number */
    segmentIndex = FldownloadStatus.segmentList.nrOfSegments;
    /* set the flash download info */
    curSegment = &FldownloadStatus.segmentList.segmentInfo[segmentIndex];
    curSegment->address = FldownloadStatus.startAddr;
    curSegment->length = FldownloadStatus.downLength;
    /* check if flash driver is downloaded */
    if ((boolean)TRUE == FldownloadStatus.flDrvDownloaded)
    {
        retVal = FL_HandleRemainData();
    }

    FldownloadStatus.segmentList.nrOfSegments++;
    FldownloadStatus.downloadStep = FL_TRANSFER_STEP;
    FldownloadStatus.activeJob = FL_JOB_IDLE;
	FldownloadStatus.errorCode = FL_OK;
    return retVal;
}

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
FL_ResultType FL_DownloadRequestValidCheck(const uint32 startAdd, const uint32 length) 
{
    FL_ResultType retVal = (uint8)FL_ERR_ADDR_LENGTH;
    uint32 segmentIndex;
    sint8 blockIndex = 0;
    sint8 blockEndIndex = 0;
    FL_SegmentInfoType* curSegment;

    /* check download step sequence */
    if ((FL_REQUEST_STEP != FldownloadStatus.downloadStep) && (FL_CHECKSUM_STEP != FldownloadStatus.downloadStep))
    {
        /*"Synchronize with the baseline" retVal = FL_CONDITIONS_NOT_CORRECT;*/
        retVal = (uint8)FL_ERR_SEQUENCE;
    }
    /* check the condition for download request */
    else
    {
		if ((boolean)FALSE == FldownloadStatus.flDrvDownloaded)
		{
            if(TRUE == Rte_Appl_CheckAddrAndLen(startAdd,length,FL_FLASH_DRIVER_BASE_ADDRESS,FL_FLASH_DRIVER_SIZE))
            {
                retVal = (uint8)FL_OK;
            }
		}
        else
        {
            if(FL_OK == Rte_BlkM_SearchBlock(startAdd,length,&blockIndex,&blockEndIndex))
            {
                retVal = (uint8)FL_OK;
            }
        }

        if(FL_OK == retVal)
        {
            if(FldownloadStatus.segmentList.nrOfSegments < FL_MAX_SEGMENTS)
            {
	            /* get current segment number */
	            segmentIndex = FldownloadStatus.segmentList.nrOfSegments;
	            /* check if segment address is increase */
				if (segmentIndex > (uint32)0x00u)
	            {
	                curSegment = &FldownloadStatus.segmentList.segmentInfo[segmentIndex - 1u];
	                /* check if download address is in front segment range */
	                if (startAdd < (uint32)(curSegment->address + curSegment->length))
	                {
	                    retVal = (uint8)FL_ADDRESS_OVERLAP_ERR;
                    }
                }
            }
            else
            {
                retVal = (uint8) FL_ERR_ADDR_LENGTH;
            }
        }

        if ((boolean)TRUE == FldownloadStatus.flDrvDownloaded
            &&(uint8)FL_OK == retVal
			)
        {
            for (; blockIndex <= blockEndIndex; blockIndex++)
            {
                if (FALSE == Rte_BlkM_GetBlockEraseStatus(blockIndex))
                {
                    retVal = FL_ERASE_ERR;
                    break;
                }
#ifdef PROJECT_SPECIAL                
                else
                {
                    Rte_BlkM_SetBlockDownloading(startAdd,length);
                }
#endif                
            }
        }
    }

    if (retVal != FL_OK)
    {
        /* initialize the flash download state */
        FL_InitState();
    }

    return retVal;
}

/******************************************************************************/
/**
 * @brief               <0x36 service download data>
 * <download data for current logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <destAddr , * sourceBuff , length >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType FL_FlashProgramRegion(const uint32 destAddr, const uint8* sourceBuff, const uint32 length) 
{
    FL_ResultType retVal = (uint8)FL_OK;
    /* change local address to global address */
    const uint32 globalAddr = destAddr;
    /* check if flash driver is downloaded */
    if ((boolean)FALSE == FldownloadStatus.flDrvDownloaded)
    {
        /* copy the data to the request address */
        DP_Memcpy((uint8*)globalAddr, sourceBuff, length); /*PRQA S 0306*/
#if (RTE_CFG_FL_SEGEMENT_CHECKSUM == STD_ON)
        Rte_FL_Segement_CheckSum_Window(&FldownloadStatus.segmentList, globalAddr,length);
#endif
        /* index start address and length */
        FldownloadStatus.startAddr += length;
        FldownloadStatus.downLength -= length;
        /* check if flash driver download is finished */
        if ((uint32)0U == FldownloadStatus.downLength)
        {
            /* set the download step*/
            FldownloadStatus.downloadStep = FL_EXIT_TRANSFER_STEP;
        }
        FldownloadStatus.activeJob = FL_JOB_IDLE;
        FldownloadStatus.errorCode = (uint8)FL_OK;
    }
    else
    {
        /* save parameter for program active job */
        FldownloadStatus.dataBuff = sourceBuff;
        FL_ProgramLength = length;
        /* set the download active state to program */
        FldownloadStatus.activeJob = FL_JOB_PROGRAMMING;
        FldownloadStatus.errorCode = (uint8)FL_OK;
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <0x36 service download data>
 * <download data for current logical block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <destAddr , length >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType FL_FlashDown_TransferStateCheck(const uint32 destAddr, const uint32 length) 
{
    FL_ResultType retVal = (uint8)FL_OK;
    /* check the conditions of the program */
    if (FL_TRANSFER_STEP != FldownloadStatus.downloadStep)
    {
        retVal = (uint8)FL_ERR_SEQUENCE;
        /* initialize the flash download state */
        FL_InitState();
    }
    else
    {
        if ((FldownloadStatus.startAddr != destAddr) || (FldownloadStatus.downLength < length))
        {
            retVal = (uint8)FL_ERR_ADDR_LENGTH;
        }
    }
    return retVal;
}

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
void FL_ExitTransferData(void) 
{
    FldownloadStatus.downloadStep = FL_CHECKSUM_STEP;
    FldownloadStatus.activeJob = FL_JOB_IDLE;
}

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
boolean FL_ServiceFinished(FL_ResultType* error) 
{
    boolean retVal;
    /* check if service is finished */
    if ((FL_JOB_IDLE == FldownloadStatus.activeJob) && ((uint8)FL_UPDATING_NVM != FldownloadStatus.errorCode))
    {
        *error = FldownloadStatus.errorCode;

        FldownloadStatus.errorCode = (uint8)FL_OK;

        retVal = (boolean)TRUE;
    }
    else
    {
        *error = (uint8)FL_OK;
        retVal = (boolean)FALSE;
    }
    return retVal;
}

#if (STD_ON == FL_SERVICE_0X38_ENABLE)
/******************************************************************************/
/**
 * @brief               <File download.>
 * <File download request add file.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <filePathAndNameLength
 * 					     filePathAndName
 * 					     dataFormatIdentifier
 * 					     fileSizeUncompressed
 * 					     fileSizeCompressed>
 * @param[out]          <ErrorCode >
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType File_ProcessRequestAddFile(
    uint16 filePathAndNameLength,
    uint8* filePathAndName,
    uint8 dataFormatIdentifier,
    uint8* fileSizeUncompressed,
    uint8* fileSizeCompressed,
    uint8* ErrorCode)
{
    FL_ResultType retVal = (uint8)FL_OK;

    return retVal;
}
/******************************************************************************/
/**
 * @brief               <File delete.>
 * <File download request delete file.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <filePathAndNameLength
 * 					     filePathAndName>
 * @param[out]          <ErrorCode >
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType File_ProcessRequestDeleteFile(uint16 filePathAndNameLength, uint8* filePathAndName, uint8* ErrorCode)
{
    FL_ResultType retVal = (uint8)FL_OK;
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <File download.>
 * <File download request replace file.>,
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <filePathAndNameLength
 * 					     filePathAndName
 * 					     dataFormatIdentifier
 * 					     fileSizeUncompressed
 * 					     fileSizeCompressed>
 * @param[out]          <ErrorCode >
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType File_ProcessRequestReplaceFile(
    uint16 filePathAndNameLength,
    uint8* filePathAndName,
    uint8 dataFormatIdentifier,
    uint8* fileSizeUncompressed,
    uint8* fileSizeCompressed,
    uint8* ErrorCode)
{
    FL_ResultType retVal = (uint8)FL_OK;
    return retVal;
}

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
boolean File_ServiceFinished(FL_ResultType* error)
{
    boolean retVal = (boolean)FALSE;
    return retVal;
}

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
FL_DownloadStepType File_GetFLDownloadStep(void)
{
    boolean retVal = FL_REQUEST_STEP;
    return retVal;
}

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
FL_ResultType File_TransferStateCheck(const uint32 length)
{
    FL_ResultType retVal = (uint8)FL_OK;
    return retVal;
}
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
FL_ResultType File_FlashProgramRegion(const uint8* sourceBuff, const uint32 length)
{
    FL_ResultType retVal = (uint8)FL_OK;
    return retVal;
}
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
void File_ExitTransferData(void)
{
    /*nothing*/
}
#endif

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
void FL_MainFunction(void) 
{
    switch (FldownloadStatus.activeJob)
    {
    case FL_JOB_ERASING:
        /* do the flash erase */
        FldownloadStatus.errorCode = FL_Erasing();
        break;
    case FL_JOB_PROGRAMMING:
        /* do the flash program */
        FldownloadStatus.errorCode = FL_Programming();
        break;
    case FL_JOB_CHECKING:
        /* do the flash checksum */
        FldownloadStatus.errorCode = FL_CheckSuming();
        break;
    default:
        /* empty */
        break;
    }
    if ((uint8)FL_HOLD_CUR_JOB != FldownloadStatus.errorCode)
    {
        if ((uint8)FL_OK != FldownloadStatus.errorCode)
        {
        	if(FldownloadStatus.activeJob != FL_JOB_IDLE)
        	{
                /* initialize the flash download state */
                FL_InitState();
        	}
        }
        else
        {
            /* empty */
        }
        /* after handle the fl job, set the job to idle */
        FldownloadStatus.activeJob = FL_JOB_IDLE;
    }
    else
    {
        /* empty */
    }
}

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
void FL_Get_EraseInfo(const uint32 startAdd, const uint32 length) 
{
    /* save the parameter used for erase info use */
    Fl_EraseStatus.startAddr = startAdd;
    Fl_EraseStatus.eraseLength = length;
    Rte_FL_Set_EraseInfo(startAdd,length);
}
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
void FL_InitFLDownloadStep(void) 
{
    /* download step is download request 0x34 */
    FldownloadStatus.downloadStep = FL_REQUEST_STEP;
    Rte_BlkM_SetBlocksDownloadFinish();
}

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
FL_DownloadStepType FL_GetFLDownloadStep(void) 
{
    return FldownloadStatus.downloadStep;
}

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
boolean FL_GetFLDownloaded(void) 
{
    return FldownloadStatus.flDrvDownloaded;
}
/******************************************************************************/
/**
 * @brief               <Check if NRC78 needs to send>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
boolean FL_CheckConditionForPending(void) 
{
    boolean ret;
    if ((FL_JOB_ERASING == FldownloadStatus.activeJob) && (FL_HOLD_CUR_JOB == FldownloadStatus.errorCode))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }
    return ret;
}



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
boolean FL_CheckVehicleSpeedNonZero(void)
{
    return (boolean)TRUE;
}

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
boolean FL_CheckPowerUnderVoltage(void)
{
    return (boolean)TRUE;
}

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
boolean FL_CheckPowerOverVoltage(void)
{
    return (boolean)TRUE;
}

#endif

/******************************************************************************/
/**
 * @brief               < check program pre-condition >
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <NON Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <conditions >
 * @param[in/out]       <NONE>
 * @return              <uint8>
 */
/******************************************************************************/
uint8 FL_CheckProgPreCondition(uint8* conditions) 
{
    uint8* inputConditions = conditions;
    /* defined by user */
    *inputConditions = (uint8)0x00u;
#if (STD_ON == FL_PROG_PRE_CONDITION_USED)
    inputConditions++;
    if ((boolean)TRUE == FL_CheckVehicleSpeedNonZero())
    {
        *inputConditions = (uint8)0x01u;
    }
    else
    {
        *inputConditions = (uint8)0x00u;
    }
    inputConditions++;
    if ((boolean)TRUE == FL_CheckPowerUnderVoltage())
    {
        *inputConditions = (uint8)0x01u;
    }
    else if ((boolean)TRUE == FL_CheckPowerOverVoltage())
    {
        *inputConditions = (uint8)0x02u;
    }
    else
    {
        *inputConditions = (uint8)0x00u;
    }
#endif
    return (uint8)0x00u;
}
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
FL_ResultType FL_GetFldownloadStatusErrorCode(void)
{
    return FldownloadStatus.errorCode ;
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <active job erase>
 * <erase the current logical block witch requested by 0x31 service> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
static FL_ResultType FL_Erasing(void)
{
    FL_ResultType retVal = FL_OK;
#if (STD_ON == FL_SPLIT_SECTORS_ERASE_ENABLED)
    static uint32 FL_Counter = 0u;
    /* set flash driver input parameter */
    /* the start erase address must be the block start address not flashParamInfo.address = Fl_EraseStatus.startAddr */
    /* flashParamInfo.address should be what ? */
    flashParamInfo.address = Fl_EraseStatus.startAddr;

    /* Check if the requested memory size is less than 256K bytes, that is, less than 16 logical sector. */
    if (Fl_EraseStatus.eraseLength < (uint32)FL_MAX_SECTORS_PER_ERASE)
    {
        flashParamInfo.length = Fl_EraseStatus.eraseLength;
    }
    else
    {
        flashParamInfo.length = FL_MAX_SECTORS_PER_ERASE;
    }
    extern void WdgIf_SetTriggerCondition(void);
     WdgIf_SetTriggerCondition();
    /* erase the flash of the requested block. */
    APPL_DISABLE_INTERRUPT();
    BLFlash_InfoPtr->flashEraseFct(&flashParamInfo);
    APPL_ENABLE_INTERRUPT();

    /* check if erase success */
    if ((uint8)kFlashOk == flashParamInfo.errorCode)
    {
        Fl_EraseStatus.eraseLength -= flashParamInfo.length;

        if (Fl_EraseStatus.eraseLength == 0u)
        {
            Rte_BlkM_SetBlockEraseStatus();
        }
        else
        {
            Fl_EraseStatus.startAddr += (uint32)flashParamInfo.length;
            retVal = (uint8)FL_HOLD_CUR_JOB;
#if FL_FLASH_ERASE_PENDING_SEND_PERIOD > 0
            FL_Counter++;
            if (FL_Counter % FL_FLASH_ERASE_PENDING_SEND_PERIOD == 0u)
            {
//                Dcm_SendPending();
            }
#endif
        }
    }
    else
    {
        /* initialize the flash download state */
        FL_InitState();
        retVal = (uint8)FL_FAILED;
    }
#else
    /* set flash driver input parameter */
    /* the start erase address must be the block start address not flashParamInfo.address = Fl_EraseStatus.startAddr */
    /* flashParamInfo.address should be what ? */
    flashParamInfo.address = Fl_EraseStatus.startAddr;
    flashParamInfo.length = Fl_eraseStatus.eraseLength;
    /* erase the flash of the requested block */
    /* Loop until all Flash sector erasing tasks are completed */
    APPL_DISABLE_INTERRUPT();
    BLFlash_InfoPtr->flashEraseFct(&flashParamInfo);
    APPL_ENABLE_INTERRUPT();

    /* check if erase success */
    if ((uint8)kFlashOk == flashParamInfo.errorCode)
    {
        /* set the block erased */
        Rte_BlkM_SetBlockEraseStatus();
        retVal = (uint8)FL_OK;
    }
    else
    {
        /* initialize the flash download state */
        FL_InitState();
        retVal = (uint8)FL_FAILED;
    }
#endif
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <FL_DownloadRemainData>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
static FL_ResultType FL_DownloadRemainData(void)
{
    FL_ResultType retVal = (uint8)FL_OK;

    if ((uint32)0U != FL_RemainDataStruct.remainLength)
    {
        /* two segments are not in one page or checking sum is started, so download the last segment first */
        flashParamInfo.address = FL_RemainDataStruct.remainAddr;
        /* fill pad for the left data */
        DP_Memset(
            (uint8*)(&FL_ProgramData[FL_RemainDataStruct.remainLength]),
            (const uint8)FL_GAP_FILL_VALUE,
            (uint32)((uint32)FL_PROGRAM_SIZE - FL_RemainDataStruct.remainLength));
        /* set the flash download info */
        flashParamInfo.data = (uint8*)(&FL_ProgramData[0]);
        flashParamInfo.length = (uint32)FL_PROGRAM_SIZE;
        FL_RemainDataStruct.remainLength = 0x00U;
        /* write the last 0x36 aligned data */
        /* Loop until all Flash sector programming tasks are completed */
        APPL_DISABLE_INTERRUPT();/*PRQA S 3469*/
        BLFlash_InfoPtr->flashWriteFct(&flashParamInfo);
        APPL_ENABLE_INTERRUPT();/*PRQA S 3469*/
        if ((uint8)kFlashOk != flashParamInfo.errorCode)
        {
            retVal = (uint8)FL_FAILED;
        }
        else
        {
#if (RTE_CFG_FL_SEGEMENT_CHECKSUM == STD_ON)
            Rte_FL_Segement_CheckSum_Window(&FldownloadStatus.segmentList,flashParamInfo.address, flashParamInfo.length);
#endif
        }
    }
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <FL_HandleRemainData>
 * @param[out]          <IN>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
static FL_ResultType FL_HandleRemainData(void)
{
    FL_ResultType retVal = (uint8)FL_OK;

    if ((uint32)0U != FL_RemainDataStruct.remainLength)
    {
        if ((uint32)(FL_RemainDataStruct.remainAddr & ~((uint32)FL_PROGRAM_SIZE - 1U))
            == (uint32)(FldownloadStatus.startAddr & ~((uint32)FL_PROGRAM_SIZE - 1U)))
        {
            /* link the remain data and new segment because one page, and download together via 0x36 */
            DP_Memset(
                (uint8*)(&FL_ProgramData[FL_RemainDataStruct.remainLength]),
                (uint8)FL_GAP_FILL_VALUE,
                (uint32)(FldownloadStatus.startAddr - FL_RemainDataStruct.remainLength - FL_RemainDataStruct.remainAddr));
            FL_RemainDataStruct.remainLength = FldownloadStatus.startAddr - FL_RemainDataStruct.remainAddr;
        }
        else
        {
            retVal = FL_DownloadRemainData();
            FL_RemainDataStruct.remainLength = (uint32)(FldownloadStatus.startAddr & ((uint32)FL_PROGRAM_SIZE - (uint32)1U));
            /* initialize the program buffer */
            DP_Memset((uint8*)(&FL_ProgramData[0]), (uint8)FL_GAP_FILL_VALUE, (uint32)FL_PROGRAM_SIZE);
        }
    }
    else
    {
        FL_RemainDataStruct.remainLength = (uint32)(FldownloadStatus.startAddr & ((uint32)FL_PROGRAM_SIZE - 1U));
        /* initialize the program buffer */
        DP_Memset((uint8*)(&FL_ProgramData[0]), (uint8)FL_GAP_FILL_VALUE, (uint32)FL_PROGRAM_SIZE);
    }

    return retVal;
}

/******************************************************************************/
/**
 * @brief               <program data>
 * <program the aligned data transfered by 0x36 service request > .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
static FL_ResultType FL_ProgrammingData(void)
{
    FL_ResultType retVal = (uint8)FL_OK;

    /* check the program length and program status */
    while ((FL_ProgramLength > (uint32)0UL) && ((uint8)FL_OK == retVal))
    {
        /* check if the program size is more than maximum size of program buffer */
        if ((FL_ProgramLength + FL_RemainDataStruct.remainLength) >= (uint32)FL_PROGRAM_SIZE)
        {
            /* get the download data */
            DP_Memcpy(
                (uint8*)(&FL_ProgramData[FL_RemainDataStruct.remainLength]),
                FldownloadStatus.dataBuff,
                (uint32)((uint32)FL_PROGRAM_SIZE - FL_RemainDataStruct.remainLength));
            /* index the databuff point in transfered buffer */
            FldownloadStatus.dataBuff += ((uint32)FL_PROGRAM_SIZE - FL_RemainDataStruct.remainLength); /*PRQA S 0488*/
            /* index the total program length */
            FL_ProgramLength -= (uint32)((uint32)FL_PROGRAM_SIZE - FL_RemainDataStruct.remainLength);
            /* set the flash driver input parameter */
            flashParamInfo.address = (FldownloadStatus.startAddr - FL_RemainDataStruct.remainLength);
            flashParamInfo.length = (uint32)FL_PROGRAM_SIZE;
            flashParamInfo.data = &FL_ProgramData[0];
            /* program the data */
            /* Loop until all Flash sector programming tasks are completed */
            APPL_DISABLE_INTERRUPT();/*PRQA S 3469*/
            BLFlash_InfoPtr->flashWriteFct(&flashParamInfo);
            APPL_ENABLE_INTERRUPT();/*PRQA S 3469*/
            /* index the start address and length that record in 0x34 service */
            FldownloadStatus.startAddr += ((uint32)FL_PROGRAM_SIZE - FL_RemainDataStruct.remainLength);
            FldownloadStatus.downLength -= ((uint32)FL_PROGRAM_SIZE - FL_RemainDataStruct.remainLength);
            FL_RemainDataStruct.remainAddr = FldownloadStatus.startAddr;
            FL_RemainDataStruct.remainLength = (uint32)0x00U;
            /* check if program success */
            if ((uint8)kFlashOk != flashParamInfo.errorCode)
            {
                retVal = (uint8)FL_FAILED;
            }
            else
            {
#if (RTE_CFG_FL_SEGEMENT_CHECKSUM == STD_ON)
                Rte_FL_Segement_CheckSum_Window(&FldownloadStatus.segmentList,flashParamInfo.address, flashParamInfo.length);
#endif
            }
        }
        else
        {
            /* set the last data for write of current service 0x36 */
            DP_Memcpy(&FL_ProgramData[FL_RemainDataStruct.remainLength], FldownloadStatus.dataBuff, FL_ProgramLength);
            FL_RemainDataStruct.remainAddr = FldownloadStatus.startAddr - FL_RemainDataStruct.remainLength;
            FL_RemainDataStruct.remainLength += FL_ProgramLength;
            /* index the start address and length that record in 0x34 service */
            FldownloadStatus.startAddr += FL_ProgramLength;
            FldownloadStatus.downLength -= FL_ProgramLength;
            /* end of current service 0x36 */
            FL_ProgramLength = (uint32)0U;
        }
    }

    return retVal;
}

/******************************************************************************/
/**
 * @brief               <active job program>
 * <program the data transfered by 0x36 service request > .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
static FL_ResultType FL_Programming(void)
{
    FL_ResultType retVal;

    retVal = Rte_BlkM_SetBlockDownloading(FldownloadStatus.startAddr, FldownloadStatus.downLength);

    if ((FL_ResultType)FL_OK == retVal)
    {
        /* program buffer aligned data */
        retVal = FL_ProgrammingData();
    }
    /* check if the last not aligned data should be programmed */
    if ((FL_ResultType)FL_OK == retVal)
    {
        if ((uint32)0U == FldownloadStatus.downLength)
        {
            FldownloadStatus.downloadStep = FL_EXIT_TRANSFER_STEP;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* initialize the flash download state */
        FL_InitState();
    }

    return retVal;
}

/******************************************************************************/
/**
 * @brief               <active job checksum>
 * <active checksum that request by 0x31 service> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
static FL_ResultType FL_CheckSuming(void)
{
    uint8 i;
    FL_ResultType retVal = FL_OK;
    SecM_StatusType secMStatus = SECM_NOT_OK;/*PRQA S 2981*/
    SecM_VerifyParamType verifyParam;
#if (FL_FLASH_DRIVER_INTEGRITY_VALID_CHECK == STD_ON)
    boolean flashDriverCompare = TRUE;/*PRQA S 2981*/
#endif

    /* set verification API input parameter */
    verifyParam.segmentList = &FldownloadStatus.segmentList;
    verifyParam.verificationData = FldownloadStatus.dataBuff;
    verifyParam.crcTotle = 0u;

    /* CRC compute and verification */
#if (RTE_CFG_FL_SEGEMENT_CHECKSUM == STD_ON)
    secMStatus = Rte_SecM_VerificationCrc(&verifyParam,Rte_FL_Segement_CheckSum_WindowValue(verifyParam.segmentList));
#endif
    /* check if CRC if correct */
    if ((uint8)SECM_OK == secMStatus)
    {
        /* check if flash driver is downloaded */
        if ((boolean)FALSE == FldownloadStatus.flDrvDownloaded)
        {
#if (FL_FLASH_DRIVER_INTEGRITY_VALID_CHECK == STD_ON)
#if (RTE_CFG_FLASHDRIVER_INTEGRITY == STD_ON)
            flashDriverCompare = Rte_SecM_VerifyFlashdriver(&verifyParam);
#else
            flashDriverCompare = DP_Memcompare(FL_flashdriverintegrityvalid, (uint8 *)FL_FLASH_DRIVER_INTEGRITY_VALID_ADDRESS, FL_FLASH_DRIVER_INTEGRITY_VALID_LENGTH); /*PRQA S 0306*/
#endif
            if (flashDriverCompare == TRUE)
            {
                /* flash driver initialize */
                BLFlash_InfoPtr->flashInitFct(&flashParamInfo);
            }
            else
            {
                flashParamInfo.errorCode = kFlashFailed;
            }
#else

            /* flash driver initialize */
            BLFlash_InfoPtr->flashInitFct(&flashParamInfo);
#endif
            /* check if flash driver is initialized success */
            if ((uint8)kFlashOk == flashParamInfo.errorCode)
            {
                FldownloadStatus.flDrvDownloaded = (boolean)TRUE;
            }
            else
            {
                retVal = (uint8)FL_FAILED;
            }
        }
        else
        {
#ifdef PROJECT_SPECIAL_FLS
            FL_DisableFlsDrv();
#endif
            for (i = 0; i < FL_NUM_LOGICAL_BLOCKS; i++)
            {
                if (TRUE == Rte_BlkM_GetBlockIsProgramming(i))
                {
                    if (TRUE)
                    {
                        Rte_BlkM_SetBlockCompatibility(i);
                    }

                    Rte_BlkM_SetBlockIntergrity(i);
                }
            }

            Rte_BlkM_SetBlocksDownloadFinish();


            retVal = Rte_BlkM_UpdateNvm();
        }
    }
    else
    {
#ifdef PROJECT_SPECIAL_FLS
        FL_DisableFlsDrv();
#endif
        retVal = (uint8)FL_FAILED;
    }
/* ----------------projectCfg---------------- */

    /* if routine check memory, it means that the download this block is over */
    FL_InitState();
/* ----------------projectCfg end---------------- */
    return retVal;
}

/******************************************************************************/
/*
 * @brief              [_disableFlsDrv description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void FL_DisableFlsDrv(void)
{
    FldownloadStatus.flDrvDownloaded = FALSE;
    flashParamInfo.flashstatus = FLASH_UNINIT;
}
/******************************************************************************/
/*
 * @brief              [_readFromFlash description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [dat            description]
 *                     [addr           description]
 *                     [len            description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void FL_ReadFromFlash(uint32 dat,uint32 addr ,uint32 len)
{
	/* flash driver API input parameter */
	static tFlashParam flashParamInfoTemp = {
		    (uint8)FLASH_DRIVER_VERSION_PATCH,
		    (uint8)FLASH_DRIVER_VERSION_MINOR,
		    (uint8)FLASH_DRIVER_VERSION_MAJOR,
			FLASH_INIT,
		    (uint8)kFlashOk,
		    (uint16)0x0000U,
		    (uint32)0UL,
		    (uint32)0UL,
		    NULL_PTR,
		    NULL_PTR,
		#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
		    &Appl_wdTriggerFct
		#else
			NULL_PTR
		#endif
		};
    if(TRUE == FL_GetFLDownloaded())
    {
    	flashParamInfoTemp.address =addr;
    	flashParamInfoTemp.length = len;
    	flashParamInfoTemp.readData = (uint8*)dat;
        BLFlash_InfoPtr->flashReadFct(&flashParamInfoTemp);
    }
    else
    {
        DP_Memcpy((uint8*)dat,(uint8*)addr,len);
    }
}
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
uint32 Fl_GetRemainingLen(void)
{
    return FldownloadStatus.downLength;
}
