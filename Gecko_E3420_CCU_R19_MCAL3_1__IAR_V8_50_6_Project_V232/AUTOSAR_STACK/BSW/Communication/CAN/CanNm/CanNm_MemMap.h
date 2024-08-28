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
**  FILENAME    : CanNm_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : <Auto generated>                                            **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of CanNm              **
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
    ModeName:CanNm_MemMap<br>
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

/* Total section items: 9 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE*/
#elif defined CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANNM_STOP_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef CANNM_STOP_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#undef CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:1  Section name :CANNM_RXINDICATION_CALLBACK_CODE*/
#elif defined CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE
#undef CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANNM_STOP_SEC_CANNM_RXINDICATION_CALLBACK_CODE
#undef CANNM_STOP_SEC_CANNM_RXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:2  Section name :CANNM_TRIGGERTRANSMIT_CALLBACK_CODE*/
#elif defined CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
#undef CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANNM_STOP_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
#undef CANNM_STOP_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE_NO_MATCH
#undef CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:3  Section name :CANNM_TXCONFIRMATION_CALLBACK_CODE*/
#elif defined CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
#undef CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANNM_STOP_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
#undef CANNM_STOP_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#undef CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:4  Section name :CODE*/
#elif defined CANNM_START_SEC_CODE
#undef CANNM_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined CANNM_STOP_SEC_CODE
#undef CANNM_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_CODE_NO_MATCH
#undef CANNM_START_SEC_CODE_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:5  Section name :CONFIG_DATA_UNSPECIFIED*/
#elif defined CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#undef CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_UNSPECIFIED

/*Index:6  Section name :VAR_CLEARED_UNSPECIFIED*/
#elif defined CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#undef CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_UNSPECIFIED

/*Index:7  Section name :VAR_INIT_PTR*/
#elif defined CANNM_START_SEC_VAR_INIT_PTR
#undef CANNM_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_VAR_INIT_PTR_NO_MATCH
#define START_SEC_VAR_INIT_PTR

#elif defined CANNM_STOP_SEC_VAR_INIT_PTR
#undef CANNM_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_VAR_INIT_PTR_NO_MATCH
#undef CANNM_START_SEC_VAR_INIT_PTR_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_PTR

/*Index:8  Section name :VAR_INIT_UNSPECIFIED*/
#elif defined CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#undef CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanNm_MemMap.h, section is used consecutively many times."
#endif
#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_INIT_UNSPECIFIED

#elif defined CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANNM_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#undef CANNM_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#else
#error "CanNm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_UNSPECIFIED

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "CanNm_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883,0791-- */ /* MISAR Dir-4.10,Rule-5.4 */
