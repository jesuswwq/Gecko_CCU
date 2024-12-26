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
**  FILENAME    : FL_Type.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : Macros,Types defines and for Flash Driver Module            **
**                                                                            **
**  SPECIFICATION(S) : None                      		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *   V1.0.0     20210817     Haibin.Shao     Initial version
 *   V1.0.0     20231025     Long.Zhu     	 1.Adding macros FL_CONDITIONS_NOT_CORRECT
 											 2.Adjust the struct FL_ProgramMarkNvmInfoType definition.
     V1.0.1     20240228     yaowei.shen     1.modify nrOfSegments,calNrOfSegment type uint8->uint32                                    
 */
#ifndef FL_TYPE_H_
#define FL_TYPE_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "FL_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* FL module execute result */
#define FL_OK              				0x00U
#define FL_FAILED          				0x01U
#define FL_ERR_SEQUENCE    				0x02U
#define FL_NO_FINGERPRINT  				0x03U
#define FL_NO_FLASHDRIVER  				0x04U
#define FL_ERR_ADDR_LENGTH 				0x05U
#define FL_INVALID_DATA    				0x06U
#define FL_UPDATING_NVM    				0x07U
#define FL_ERR_MEMORY      				0x08U
#define FL_ERR_INFRONT     				0x09U
#define FL_HOLD_CUR_JOB    				0x0AU
#define FL_CONDITIONS_NOT_CORRECT    	0x0BU
#define FL_ADDRESS_OVERLAP_ERR			0x0CU
#define FL_ERASE_ERR					0x0DU

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** Standard return type for call back routines. */
typedef uint8 FL_ResultType;

/** Segment list information of the block */
typedef struct
{
    /* Start global address of the segment in flash */
    uint32 address;
    /* Length of the segment */
    uint32 length;

} FL_SegmentInfoType;

/** Needed in interface to the security module. */
typedef struct
{
    /* number of segment. */
	uint32 nrOfSegments;

    /*The number of segments currently calculated. */
    uint32 calNrOfSegment;

    /* segments information. */
    FL_SegmentInfoType segmentInfo[FL_MAX_SEGMENTS];
} FL_SegmentListType;

/** flashloader download step */
typedef enum
{
    FL_REQUEST_STEP = 0U,
    FL_TRANSFER_STEP = 1U,
    FL_EXIT_TRANSFER_STEP = 2U,
    FL_CHECKSUM_STEP = 3U
} FL_DownloadStepType;

/** flashloader job status */
typedef enum
{
    FL_JOB_IDLE = 0U,
    FL_JOB_ERASING = 1U,
    FL_JOB_PROGRAMMING = 2U,
    FL_JOB_CHECKING = 3U
} FL_ActiveJobType;

/* flashloader status information */
typedef struct
{
    /* flag if flash driver has downloaded */
    boolean flDrvDownloaded;
    /* error code for flash active job */
    FL_ResultType errorCode;
    /* flag if current block is erased */
    boolean blockErased[FL_NUM_LOGICAL_BLOCKS];
    /* current process block index */
    uint8 blockIndex;
    /* current process start address */
    uint32 startAddr;
    /* current process length */
    uint32 downLength;
    /* current process buffer point, point to buffer supplied from DCM */
    const uint8* dataBuff;
    /* segment list of current process block */
    FL_SegmentListType segmentList;
    /* flashloader download step */
    FL_DownloadStepType downloadStep;
    /* current job status */
    FL_ActiveJobType activeJob;
    /*Dependency indicates storage state*/
    boolean proDependenciesValidFlagStore;
} FL_DownloadStateType;

/* handle the two segments in one page */
typedef struct
{
    /* current process start address */
    uint32 remainAddr;
    /* current process length */
    uint32 remainLength;
} FL_RemainDataType;

/* flashloader status information */
typedef struct
{
    /* current erase start address */
    uint32 startAddr;
    /* current erase length */
    uint32 eraseLength;
} FL_EraseInfoType;

/*region type*/
typedef uint8  FL_Region_Type;
/*bank type*/
typedef uint8  FL_Bank_Type;
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* endif of FL_TYPE_H_ */
