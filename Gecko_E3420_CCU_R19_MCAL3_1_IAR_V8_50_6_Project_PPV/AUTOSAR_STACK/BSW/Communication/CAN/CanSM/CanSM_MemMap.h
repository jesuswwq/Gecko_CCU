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
**  FILENAME    : CanSM_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : <Auto generated>                                            **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of CanSM              **
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
    ModeName:CanSM_MemMap<br>
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

/* Total section items: 14 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:1  Section name :CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:2  Section name :CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:3  Section name :CANSM_CONTROLLERBUSOFF_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:4  Section name :CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:5  Section name :CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:6  Section name :CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:7  Section name :CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE*/
#elif defined CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#undef CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANSM_STOP_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#undef CANSM_STOP_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE_NO_MATCH
#undef CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:8  Section name :CODE*/
#elif defined CANSM_START_SEC_CODE
#undef CANSM_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined CANSM_STOP_SEC_CODE
#undef CANSM_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CODE_NO_MATCH
#undef CANSM_START_SEC_CODE_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:9  Section name :CONFIG_DATA_UNSPECIFIED*/
#elif defined CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#undef CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_UNSPECIFIED

/*Index:10  Section name :VAR_CLEARED_BOOLEAN*/
#elif defined CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#undef CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_VAR_CLEARED_BOOLEAN

#elif defined CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#undef CANSM_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_BOOLEAN

/*Index:11  Section name :VAR_CLEARED_UNSPECIFIED*/
#elif defined CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#undef CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_UNSPECIFIED

/*Index:12  Section name :VAR_INIT_8*/
#elif defined CANSM_START_SEC_VAR_INIT_8
#undef CANSM_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_VAR_INIT_8_NO_MATCH
#define START_SEC_VAR_INIT_8

#elif defined CANSM_STOP_SEC_VAR_INIT_8
#undef CANSM_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_VAR_INIT_8_NO_MATCH
#undef CANSM_START_SEC_VAR_INIT_8_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_8

/*Index:13  Section name :VAR_NO_INIT_PTR*/
#elif defined CANSM_START_SEC_VAR_NO_INIT_PTR
#undef CANSM_START_SEC_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanSM_MemMap.h, section is used consecutively many times."
#endif
#define CANSM_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#define START_SEC_VAR_NO_INIT_PTR

#elif defined CANSM_STOP_SEC_VAR_NO_INIT_PTR
#undef CANSM_STOP_SEC_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef CANSM_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#undef CANSM_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#else
#error "CanSM_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_PTR

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "CanSM_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883,0791-- */ /* MISAR Dir-4.10,Rule-5.4 */