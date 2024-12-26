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
 * @file  CanIf_Types.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Canif Driver.
 */
#ifndef CANIF_TYPES_H_
#define CANIF_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
/* Version and Check Begin */
/* Version Info Begin */
#define CANIF_TYPES_H_VENDOR_ID    0x8C
#define CANIF_TYPES_H_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_TYPES_H_AR_RELEASE_MINOR_VERSION    3
#define CANIF_TYPES_H_AR_RELEASE_REVISION_VERSION 1
#define CANIF_TYPES_H_SW_MAJOR_VERSION    1
#define CANIF_TYPES_H_SW_MINOR_VERSION    0
#define CANIF_TYPES_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CANIF_TYPES_H_AR_RELEASE_MAJOR_VERSION != COMSTACK_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (CANIF_TYPES_H_AR_RELEASE_MINOR_VERSION != COMSTACK_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (CANIF_TYPES_H_AR_RELEASE_REVISION_VERSION != COMSTACK_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, CanIf_Types.h and ComStack_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CANIF_TYPES_H_SW_MAJOR_VERSION != COMSTACK_TYPES_H_SW_MAJOR_VERSION)\
    || (CANIF_TYPES_H_SW_MINOR_VERSION != COMSTACK_TYPES_H_SW_MINOR_VERSION)\
    || (CANIF_TYPES_H_SW_PATCH_VERSION != COMSTACK_TYPES_H_SW_PATCH_VERSION))
#error "Opps, CanIf_Types.h and ComStack_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CANIF_TYPES_H_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (CANIF_TYPES_H_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (CANIF_TYPES_H_AR_RELEASE_REVISION_VERSION != CAN_GENERALTYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, CanIf_Types.h and Can_GeneralTypes.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CANIF_TYPES_H_SW_MAJOR_VERSION != CAN_GENERALTYPES_H_SW_MAJOR_VERSION)\
    || (CANIF_TYPES_H_SW_MINOR_VERSION != CAN_GENERALTYPES_H_SW_MINOR_VERSION)\
    || (CANIF_TYPES_H_SW_PATCH_VERSION != CAN_GENERALTYPES_H_SW_PATCH_VERSION))
#error "Opps, CanIf_Types.h and Can_GeneralTypes.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/**
 * @brief CanIf controller mode type.
 */
typedef enum {
    CANIF_CS_UNINIT = 0U,    /**< @brief UNINIT mode */
    CANIF_CS_SLEEP,         /**< @brief SLEEP mode */
    CANIF_CS_STARTED,        /**< @brief STARTED mode */
    CANIF_CS_STOPPED        /**< @brief STOPPED mode */
} CanIf_ControllerModeType;

#ifdef __cplusplus
}
#endif

#endif
