/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : ComM_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : <Auto generated>                                            **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of ComM              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * Version: V1.0.0
 * Note:    Automatically generated, manual modification is not allowed.
 */
/*============================================================================*/
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:ComM_MemMap<br>
  RuleSorce:puhua-rule.rcf 2.3.1

   \li PRQA S 0883 MISRA Dir 4.10 .<br>
    Reason:<module>_MemMap.h needs to be dynamically referenced multiple times based on pre compiled macros,
            so that duplicate inclusion protection cannot be used.

    \li PRQA S 0791 MISRA Rule 5.4 .<br>
    Reason:According to the segment name definition rules of the autosar specification, segment names may be
            very long and only a few characters may differ between segment names.
 */

/* PRQA S 0883,0791++ */ /* MISAR Dir-4.10,Rule-5.4 */
#define MEMMAP_ERROR

/* Total section items: 8 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CODE*/
#elif defined COMM_START_SEC_CODE
#undef COMM_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined COMM_STOP_SEC_CODE
#undef COMM_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_CODE_NO_MATCH
#undef COMM_START_SEC_CODE_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:1  Section name :CONST_PBCFG_8*/
#elif defined COMM_START_SEC_CONST_PBCFG_8
#undef COMM_START_SEC_CONST_PBCFG_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_CONST_PBCFG_8_NO_MATCH
#define START_SEC_CONST_PBCFG_8

#elif defined COMM_STOP_SEC_CONST_PBCFG_8
#undef COMM_STOP_SEC_CONST_PBCFG_8
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_CONST_PBCFG_8_NO_MATCH
#undef COMM_START_SEC_CONST_PBCFG_8_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_8

/*Index:2  Section name :CONST_PBCFG_PTR*/
#elif defined COMM_START_SEC_CONST_PBCFG_PTR
#undef COMM_START_SEC_CONST_PBCFG_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_CONST_PBCFG_PTR_NO_MATCH
#define START_SEC_CONST_PBCFG_PTR

#elif defined COMM_STOP_SEC_CONST_PBCFG_PTR
#undef COMM_STOP_SEC_CONST_PBCFG_PTR
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_CONST_PBCFG_PTR_NO_MATCH
#undef COMM_START_SEC_CONST_PBCFG_PTR_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_PTR

/*Index:3  Section name :CONST_PBCFG_UNSPECIFIED*/
#elif defined COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#undef COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_PBCFG_UNSPECIFIED

#elif defined COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#undef COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_CONST_PBCFG_UNSPECIFIED_NO_MATCH
#undef COMM_START_SEC_CONST_PBCFG_UNSPECIFIED_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_UNSPECIFIED

/*Index:4  Section name :VAR_INIT_8*/
#elif defined COMM_START_SEC_VAR_INIT_8
#undef COMM_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_VAR_INIT_8_NO_MATCH
#define START_SEC_VAR_INIT_8

#elif defined COMM_STOP_SEC_VAR_INIT_8
#undef COMM_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_VAR_INIT_8_NO_MATCH
#undef COMM_START_SEC_VAR_INIT_8_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_8

/*Index:5  Section name :VAR_NO_INIT_8*/
#elif defined COMM_START_SEC_VAR_NO_INIT_8
#undef COMM_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_VAR_NO_INIT_8_NO_MATCH
#define START_SEC_VAR_NO_INIT_8

#elif defined COMM_STOP_SEC_VAR_NO_INIT_8
#undef COMM_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_VAR_NO_INIT_8_NO_MATCH
#undef COMM_START_SEC_VAR_NO_INIT_8_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_8

/*Index:6  Section name :VAR_NO_INIT_PTR*/
#elif defined COMM_START_SEC_VAR_NO_INIT_PTR
#undef COMM_START_SEC_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#define START_SEC_VAR_NO_INIT_PTR

#elif defined COMM_STOP_SEC_VAR_NO_INIT_PTR
#undef COMM_STOP_SEC_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#undef COMM_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_PTR

/*Index:7  Section name :VAR_NO_INIT_UNSPECIFIED*/
#elif defined COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "ComM_MemMap.h, section is used consecutively many times."
#endif
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#undef COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "ComM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_UNSPECIFIED

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "ComM_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883,0791-- */ /* MISAR Dir-4.10,Rule-5.4 */
