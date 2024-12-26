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
 * \file     Fls_Cfg.c                                                                                 *
 * \brief    AUTOSAR 4.3.1 MCAL fls Driver                                                             *
 *           Fls configuration source file                                                             *
 *                                                                                                     *
 * <table>                                                                                             *
 * <tr><th>Date           <th>Version                                                                  *
 * <tr><td>2024-05-26 15:51:10     <td>1.0.0                                                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif  /* #ifdef __cplusplus */

#include "Fls.h"
/* PRQA S 1533,1552 EOF */


#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static Fls_JobInfoType Fls_PendingJob;

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static Fls_ContextType cor0Context = {
    .index = 0,
    .ops = &Fls_HyperbusOps,
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

static const Fls_SectorConfigType Fls_SectorList[1] =
{
    {
        .numberOfSectors  = 256,
        .pageSize        = 256,
        .sectorSize      = 262144,
        .sectorStartAddr = 0,
        .totalSize       = 67108864,
        .jobNotification = NULL_PTR,
        .jobInfo = &Fls_PendingJob,
        .jobPriority = 0U,
    }
};


static const Fls_ProgramDescriptorType Fls_FlashProgDescriptor = {
    .jobEndNotification = NULL_PTR,
    .jobErrorNotification = NULL_PTR,
    .clkOps = {
        .getClkRate = NULL_PTR,
        .setClkRate = NULL_PTR,
    }

};

const Fls_ConfigType  Fls_ConfigData =
{
    .asyncMode = 0,
    .controllerNumber = 1,
    .controllerTable = {
        {
            .id = FLS_XSPI1_PORTA,
            .busConfig = {
                .id = (uint8)FLS_XSPI1_PORTA,
                .cs = 0,
                .baudrate = 20000000,
                .refClkHz = 200000000,
                .xferMode = FLS_BUS_XFER_POLLING_MODE,
                .devMode = FLS_BUS_DEV_SINGLE_MODE,
                .hyperbusMode = TRUE,
                .rfdEnable = 0,
                .useRomConfig = FALSE,
            },
            .flashSpecialFlag = FLS_SPECIAL_AUTO,
            .pointerContex = &cor0Context,
        }
    /* PRQA S 0686 1 */
    },
    .flashConfig = {
        .callCycle = 10,  /* in us */
        .defaultMode= MEMIF_MODE_SLOW,
        .maxReadFastMode = 256,
        .maxReadNormalMode = 4096,
        .maxWriteFastMode = 256,
        .maxWriteNormalMode = 4096,
        .sectorListSize = 1U,
        .sectorList = Fls_SectorList,
        .progDesc = &Fls_FlashProgDescriptor,
    },
};
#define FLS_STOP_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif  /* #ifdef __cplusplus */

/* End of file */
