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
**  FILENAME    : Dcm_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : <Auto generated>                                            **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of Dcm              **
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
    ModeName:Dcm_MemMap<br>
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

/* Total section items: 18 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CODE*/
#elif defined DCM_START_SEC_CODE
#undef DCM_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined DCM_STOP_SEC_CODE
#undef DCM_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_CODE_NO_MATCH
#undef DCM_START_SEC_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:1  Section name :CONST_UNSPECIFIED*/
#elif defined DCM_START_SEC_CONST_UNSPECIFIED
#undef DCM_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_CONST_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_UNSPECIFIED

#elif defined DCM_STOP_SEC_CONST_UNSPECIFIED
#undef DCM_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_CONST_UNSPECIFIED_NO_MATCH
#undef DCM_START_SEC_CONST_UNSPECIFIED_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_UNSPECIFIED

/*Index:2  Section name :DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE
#undef DCM_START_SEC_DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMCOMMFULLCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:3  Section name :DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE
#undef DCM_START_SEC_DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMCOMMNOCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:4  Section name :DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE
#undef DCM_START_SEC_DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMCOMMSILENTCOMMODEENTERED_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:5  Section name :DCMCOPYRXDATA_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMCOPYRXDATA_CALLBACK_CODE
#undef DCM_START_SEC_DCMCOPYRXDATA_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMCOPYRXDATA_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMCOPYRXDATA_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMCOPYRXDATA_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMCOPYRXDATA_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMCOPYRXDATA_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:6  Section name :DCMCOPYTXDATA_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMCOPYTXDATA_CALLBACK_CODE
#undef DCM_START_SEC_DCMCOPYTXDATA_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMCOPYTXDATA_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMCOPYTXDATA_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMCOPYTXDATA_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMCOPYTXDATA_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMCOPYTXDATA_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:7  Section name :DCMSTARTOFRECEPTION_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE
#undef DCM_START_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:8  Section name :DCMTPRXINDICATION_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMTPRXINDICATION_CALLBACK_CODE
#undef DCM_START_SEC_DCMTPRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMTPRXINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMTPRXINDICATION_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMTPRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMTPRXINDICATION_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMTPRXINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:9  Section name :DCMTPTXCONFIRMATION_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE
#undef DCM_START_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:10  Section name :DCMTXCONFIRMATION_CALLBACK_CODE*/
#elif defined DCM_START_SEC_DCMTXCONFIRMATION_CALLBACK_CODE
#undef DCM_START_SEC_DCMTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_DCMTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined DCM_STOP_SEC_DCMTXCONFIRMATION_CALLBACK_CODE
#undef DCM_STOP_SEC_DCMTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_DCMTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#undef DCM_START_SEC_DCMTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:11  Section name :VAR_NO_INIT_32*/
#elif defined DCM_START_SEC_VAR_NO_INIT_32
#undef DCM_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_VAR_NO_INIT_32_NO_MATCH
#define START_SEC_VAR_NO_INIT_32

#elif defined DCM_STOP_SEC_VAR_NO_INIT_32
#undef DCM_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_VAR_NO_INIT_32_NO_MATCH
#undef DCM_START_SEC_VAR_NO_INIT_32_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_32

/*Index:12  Section name :VAR_NO_INIT_8*/
#elif defined DCM_START_SEC_VAR_NO_INIT_8
#undef DCM_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_VAR_NO_INIT_8_NO_MATCH
#define START_SEC_VAR_NO_INIT_8

#elif defined DCM_STOP_SEC_VAR_NO_INIT_8
#undef DCM_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_VAR_NO_INIT_8_NO_MATCH
#undef DCM_START_SEC_VAR_NO_INIT_8_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_8

/*Index:13  Section name :VAR_NO_INIT_UNSPECIFIED*/
#elif defined DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#undef DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/*Index:14  Section name :VAR_POWER_ON_INIT_16*/
#elif defined DCM_START_SEC_VAR_POWER_ON_INIT_16
#undef DCM_START_SEC_VAR_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_VAR_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_16

#elif defined DCM_STOP_SEC_VAR_POWER_ON_INIT_16
#undef DCM_STOP_SEC_VAR_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_VAR_POWER_ON_INIT_16_NO_MATCH
#undef DCM_START_SEC_VAR_POWER_ON_INIT_16_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_16

/*Index:15  Section name :VAR_POWER_ON_INIT_8*/
#elif defined DCM_START_SEC_VAR_POWER_ON_INIT_8
#undef DCM_START_SEC_VAR_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_VAR_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_8

#elif defined DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#undef DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_VAR_POWER_ON_INIT_8_NO_MATCH
#undef DCM_START_SEC_VAR_POWER_ON_INIT_8_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_8

/*Index:16  Section name :VAR_POWER_ON_INIT_BOOLEAN*/
#elif defined DCM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef DCM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_BOOLEAN

#elif defined DCM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef DCM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef DCM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN

/*Index:17  Section name :VAR_POWER_ON_INIT_UNSPECIFIED*/
#elif defined DCM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef DCM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Dcm_MemMap.h, section is used consecutively many times."
#endif
#define DCM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

#elif defined DCM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef DCM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef DCM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef DCM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Dcm_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "Dcm_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883,0791-- */ /* MISAR Dir-4.10,Rule-5.4 */
