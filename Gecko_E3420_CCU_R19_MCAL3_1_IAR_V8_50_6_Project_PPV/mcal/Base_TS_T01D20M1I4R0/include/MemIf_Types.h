/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     MemIf_Types.h                                                                           *
 *  \brief    This file contains interface header for FLS MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/26     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

typedef enum
{
    //    The underlying abstraction module or device driver has
    //    not been initialized (yet).
    MEMIF_UNINIT,
    // The underlying abstraction module or device driver is
    // currently idle.
    MEMIF_IDLE,

    // The underlying abstraction module or device driver is
    // currently busy.
    MEMIF_BUSY,

    //    The underlying abstraction module is busy with internal
    // management operations. The underlying device driver
    // can be busy or idle.
    MEMIF_BUSY_INTERNAL
} MemIf_StatusType;

typedef enum
{
    //The job has been finished successfully.
    MEMIF_JOB_OK,
    // The job has not been finished successfully.
    MEMIF_JOB_FAILED,
    //    The job has not yet been finished.
    MEMIF_JOB_PENDING,
    //    The job has been canceled.
    MEMIF_JOB_CANCELED,
    //    The requested block is inconsistent, it may contain
    //    corrupted data.
    MEMIF_BLOCK_INCONSISTENT,
    // The requested block has been marked as invalid,
    // the requested operation can not be performed.
    MEMIF_BLOCK_INVALID
} MemIf_JobResultType;


typedef enum
{
    //    The underlying memory abstraction modules and
    //    drivers are working in slow mode.
    MEMIF_MODE_SLOW,
    // The underlying memory abstraction modules and
    // drivers are working in fast mode.
    MEMIF_MODE_FAST
} MemIf_ModeType;

// Definition of broadcast device ID
#define MEMIF_BROADCAST_ID    0xff

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */
#endif /* MEMIF_TYPES_H */

/* End of file */
