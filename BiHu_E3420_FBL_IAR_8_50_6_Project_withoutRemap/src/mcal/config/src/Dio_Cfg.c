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
 * @file  Dio_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 * @date 2023-09-22 17:02:49
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dio.h"
/* Version and Check Begin */
/* Version Info Begin */
#define DIO_CFG_C_VENDOR_ID    0x8C
#define DIO_CFG_C_AR_RELEASE_MAJOR_VERSION    4
#define DIO_CFG_C_AR_RELEASE_MINOR_VERSION    3
#define DIO_CFG_C_AR_RELEASE_REVISION_VERSION 1
#define DIO_CFG_C_SW_MAJOR_VERSION    1
#define DIO_CFG_C_SW_MINOR_VERSION    0
#define DIO_CFG_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((DIO_CFG_C_AR_RELEASE_MAJOR_VERSION != DIO_H_AR_RELEASE_MAJOR_VERSION)\
    || (DIO_CFG_C_AR_RELEASE_MINOR_VERSION != DIO_H_AR_RELEASE_MINOR_VERSION)\
    || (DIO_CFG_C_AR_RELEASE_REVISION_VERSION != DIO_H_AR_RELEASE_REVISION_VERSION))
    #error "Opps, Dio_Cfg.c and Dio.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((DIO_CFG_C_SW_MAJOR_VERSION != DIO_H_SW_MAJOR_VERSION)\
    || (DIO_CFG_C_SW_MINOR_VERSION != DIO_H_SW_MINOR_VERSION)\
    || (DIO_CFG_C_SW_PATCH_VERSION != DIO_H_SW_PATCH_VERSION))
    #error "Opps, Dio_Cfg.c and Dio.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define DIO_START_SEC_CONST_UNSPECIFIED
#include "Dio_MemMap.h"


#define DIO_STOP_SEC_CONST_UNSPECIFIED
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

