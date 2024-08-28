/*
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  Fee_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Flash EEPROM Emulation
 * @date 2024-03-08 16:29:00
 */

#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Fee_Types.h"

/* Fee Error check */
#define FEE_DEV_ERROR_DETECT    (STD_ON)

/* Fee API definition */
#define FEE_VERSION_INFO_API    (STD_ON)

#define FEE_SETMODE_API_SUPPORTED    (STD_ON)

#define FEE_CHECKSUM_SUPPORTED    (STD_OFF)

#define FEE_CANCEL_API    (STD_OFF)

/* Fee Virtual page size */
#define FEE_VIRTUAL_PAGE_SIZE               4U

/* Fee Date cache size */
#define FEE_DATA_CACHE_SIZE               1024U

/* Fee Info cache size */
#define FEE_INFO_CACHE_SIZE               1024U


/* Fee NVM END callback API */
#define FEE_NVM_JOB_END_NOTIFICATION_DECL   
#define FEE_NVM_JOB_END_NOTIFICATION        

/* Fee NVM ERROR callback API */
#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL  
#define FEE_NVM_JOB_ERROR_NOTIFICATION       

/* Fee CFG Number Info */
#define FEE_PAGE_DEV_NUMBER        1U
#define FEE_BLOCKS_CFG_NUMBER            4U

#define FEE_BLOCKS_FULL_SIZE                2048U
#define FEE_BLOCKS_SIZE_MAX                512U

/* Fee CFG Index Info */
#define FeeBlockConfiguration_0     1U
#define FeeBlockConfiguration_1     2U
#define FeeBlockConfiguration_2     3U
#define FeeBlockConfiguration_3     4U

/* Fee CFG structure */
extern const Fee_PageDeviceType Fee_PageDevice[ FEE_PAGE_DEV_NUMBER ];
extern const Fee_BlockConfigType Fee_BlockConfig[ FEE_BLOCKS_CFG_NUMBER ];

#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */
/** @} */
