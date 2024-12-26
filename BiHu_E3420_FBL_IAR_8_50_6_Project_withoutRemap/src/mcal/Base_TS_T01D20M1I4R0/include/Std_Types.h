/**
 *   @file    Std_Types.h
 *
 *   @brief   Implementation of AutoSAR Specification of Standard Types, CP, 4.3.1
 *   @details
 *       AUTOSAR standard types header file. To provide compilor/platform independancy to BSW.
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_Types.h"

#include "Compiler.h"
/* Version and Check Begin */
/* Version Info Begin */
#define STD_TYPES_H_VENDOR_ID    0x8C
#define STD_TYPES_H_AR_RELEASE_MAJOR_VERSION    4
#define STD_TYPES_H_AR_RELEASE_MINOR_VERSION    3
#define STD_TYPES_H_AR_RELEASE_REVISION_VERSION 1
#define STD_TYPES_H_SW_MAJOR_VERSION    1
#define STD_TYPES_H_SW_MINOR_VERSION    0
#define STD_TYPES_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((STD_TYPES_H_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (STD_TYPES_H_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (STD_TYPES_H_AR_RELEASE_REVISION_VERSION != PLATFORM_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Std_Types.h and Platform_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((STD_TYPES_H_SW_MAJOR_VERSION != PLATFORM_TYPES_H_SW_MAJOR_VERSION)\
    || (STD_TYPES_H_SW_MINOR_VERSION != PLATFORM_TYPES_H_SW_MINOR_VERSION)\
    || (STD_TYPES_H_SW_PATCH_VERSION != PLATFORM_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Std_Types.h and Platform_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((STD_TYPES_H_AR_RELEASE_MAJOR_VERSION != COMPILER_H_AR_RELEASE_MAJOR_VERSION)\
    || (STD_TYPES_H_AR_RELEASE_MINOR_VERSION != COMPILER_H_AR_RELEASE_MINOR_VERSION)\
    || (STD_TYPES_H_AR_RELEASE_REVISION_VERSION != COMPILER_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Std_Types.h and Compiler.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((STD_TYPES_H_SW_MAJOR_VERSION != COMPILER_H_SW_MAJOR_VERSION)\
    || (STD_TYPES_H_SW_MINOR_VERSION != COMPILER_H_SW_MINOR_VERSION)\
    || (STD_TYPES_H_SW_PATCH_VERSION != COMPILER_H_SW_PATCH_VERSION))
#error "Opps, Std_Types.h and Compiler.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */


/**
 * SRS_BSW_00004
 *      All Basic SW Modules shall perform a pre-processor
 *      check of the versions of all imported include files
 */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((STD_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
    (STD_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Std_Types.h and Platform_Types.h dismatch"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */

#if  !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((STD_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
    (STD_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Std_Types.h and Compiler.h dismatch"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */

/**
 * @brief Physical state 5V or 3.3V or 1.8v
 */
#define STD_HIGH    0x01u

/**
 * @brief Physical state 0V.
 */
#define STD_LOW     0x00u

/**
 * @brief Logical state active.
 */
#define STD_ACTIVE  0x01u

/**
 * @brief Logical state idle.
 */
#define STD_IDLE    0x00u

/**
 * @brief ON State.
 */
#define STD_ON      0x01u

/**
 * @brief OFF state.
 */
#define STD_OFF     0x00u

/**
 * @brief Return code for failure/error.
 */
#define E_NOT_OK 0x01u

/**
 * Because E_OK is already defined within OSEK, the symbol E_OK has to be
 * shared. To avoid name clashes and redefinition problems, the symbols have to be
 * defined in the following way (approved within implementation):
 */
#if (!defined(STATUSTYPEDEFINED))
#define STATUSTYPEDEFINED
/**
 * @brief Success return code
 */
#define E_OK 0x00u
/**
 * @brief To compatile to OSEK definition.
 */
typedef unsigned char StatusType;
#endif  /* !STATUSTYPEDEFINED */

typedef uint8 Std_ReturnType;

/**
 * @brief This type shall be used to request the version of a BSW module using the <Module
 *         name>_GetVersionInfo() function.
 */
typedef struct {
    uint16  vendorID;               /**< @brief vendor ID */
    uint16  moduleID;               /**< @brief module ID */
    uint8   sw_major_version;       /**< @brief software major version */
    uint8   sw_minor_version;       /**< @brief software minor version */
    uint8   sw_patch_version;       /**< @brief software patch version */
} Std_VersionInfoType;

#define ARRAY_SZ(x) (sizeof(x)/sizeof(x[0]))
#ifdef __cplusplus
}
#endif

#endif /* #ifndef STD_TYPES_H */
