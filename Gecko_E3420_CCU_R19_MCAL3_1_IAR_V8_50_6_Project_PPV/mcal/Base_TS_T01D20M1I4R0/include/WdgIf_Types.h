
/**
 * @file  WdgIf_Types.h
 * @brief Semidrive E3. AUTOSAR 4.3.1 MCAL Watch Dog Interface.
 */

/********************************************************
*        Copyright(c) 2020    Semidrive                *
*        All rights reserved.                          *
********************************************************/
#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define WDGIF_TYPES_H_VENDOR_ID    0x8C
#define WDGIF_TYPES_H_AR_RELEASE_MAJOR_VERSION    4
#define WDGIF_TYPES_H_AR_RELEASE_MINOR_VERSION    3
#define WDGIF_TYPES_H_AR_RELEASE_REVISION_VERSION 1
#define WDGIF_TYPES_H_SW_MAJOR_VERSION    1
#define WDGIF_TYPES_H_SW_MINOR_VERSION    0
#define WDGIF_TYPES_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDGIF_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDGIF_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (WDGIF_TYPES_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, WdgIf_Types.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDGIF_TYPES_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (WDGIF_TYPES_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (WDGIF_TYPES_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, WdgIf_Types.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

typedef enum {
    WDGIF_OFF_MODE  = 0,
    WDGIF_SLOW_MODE,
    WDGIF_FAST_MODE
} WdgIf_ModeType;

#ifdef __cplusplus
}
#endif

#endif /* WDGIF_TYPES_H */
