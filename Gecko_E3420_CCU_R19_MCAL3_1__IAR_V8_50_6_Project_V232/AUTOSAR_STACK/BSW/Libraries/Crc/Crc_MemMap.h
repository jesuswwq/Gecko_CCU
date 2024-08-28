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
**  FILENAME    : Crc_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : <Auto generated>                                            **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of Crc              **
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
    ModeName:Crc_MemMap<br>
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

/* Total section items: 5 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CODE*/
#elif defined CRC_START_SEC_CODE
#undef CRC_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Crc_MemMap.h, section is used consecutively many times."
#endif
#define CRC_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined CRC_STOP_SEC_CODE
#undef CRC_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef CRC_START_SEC_CODE_NO_MATCH
#undef CRC_START_SEC_CODE_NO_MATCH
#else
#error "Crc_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:1  Section name :CONST_16BIT*/
#elif defined CRC_START_SEC_CONST_16BIT
#undef CRC_START_SEC_CONST_16BIT
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Crc_MemMap.h, section is used consecutively many times."
#endif
#define CRC_START_SEC_CONST_16BIT_NO_MATCH
#define START_SEC_CONST_16BIT

#elif defined CRC_STOP_SEC_CONST_16BIT
#undef CRC_STOP_SEC_CONST_16BIT
#undef MEMMAP_ERROR
#ifdef CRC_START_SEC_CONST_16BIT_NO_MATCH
#undef CRC_START_SEC_CONST_16BIT_NO_MATCH
#else
#error "Crc_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_16BIT

/*Index:2  Section name :CONST_32BIT*/
#elif defined CRC_START_SEC_CONST_32BIT
#undef CRC_START_SEC_CONST_32BIT
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Crc_MemMap.h, section is used consecutively many times."
#endif
#define CRC_START_SEC_CONST_32BIT_NO_MATCH
#define START_SEC_CONST_32BIT

#elif defined CRC_STOP_SEC_CONST_32BIT
#undef CRC_STOP_SEC_CONST_32BIT
#undef MEMMAP_ERROR
#ifdef CRC_START_SEC_CONST_32BIT_NO_MATCH
#undef CRC_START_SEC_CONST_32BIT_NO_MATCH
#else
#error "Crc_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_32BIT

/*Index:3  Section name :CONST_64BIT*/
#elif defined CRC_START_SEC_CONST_64BIT
#undef CRC_START_SEC_CONST_64BIT
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Crc_MemMap.h, section is used consecutively many times."
#endif
#define CRC_START_SEC_CONST_64BIT_NO_MATCH
#define START_SEC_CONST_64BIT

#elif defined CRC_STOP_SEC_CONST_64BIT
#undef CRC_STOP_SEC_CONST_64BIT
#undef MEMMAP_ERROR
#ifdef CRC_START_SEC_CONST_64BIT_NO_MATCH
#undef CRC_START_SEC_CONST_64BIT_NO_MATCH
#else
#error "Crc_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_64BIT

/*Index:4  Section name :CONST_8BIT*/
#elif defined CRC_START_SEC_CONST_8BIT
#undef CRC_START_SEC_CONST_8BIT
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Crc_MemMap.h, section is used consecutively many times."
#endif
#define CRC_START_SEC_CONST_8BIT_NO_MATCH
#define START_SEC_CONST_8BIT

#elif defined CRC_STOP_SEC_CONST_8BIT
#undef CRC_STOP_SEC_CONST_8BIT
#undef MEMMAP_ERROR
#ifdef CRC_START_SEC_CONST_8BIT_NO_MATCH
#undef CRC_START_SEC_CONST_8BIT_NO_MATCH
#else
#error "Crc_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_8BIT

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "Crc_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883,0791-- */ /* MISAR Dir-4.10,Rule-5.4 */
