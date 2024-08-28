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
**  FILENAME    : CanIf_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : <Auto generated>                                            **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of CanIf              **
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
    ModeName:CanIf_MemMap<br>
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

/* Total section items: 21 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:1  Section name :CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:2  Section name :CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:3  Section name :CANIFCONTROLLERBUSOFF_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:4  Section name :CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:5  Section name :CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:6  Section name :CANIFRXINDICATION_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:7  Section name :CANIFTRCVMODEINDICATION_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:8  Section name :CANIFTRIGGERTRANSMIT_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:9  Section name :CANIFTXCONFIRMATION_CALLBACK_CODE*/
#elif defined CANIF_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef CANIF_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined CANIF_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef CANIF_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#undef CANIF_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:10  Section name :CODE*/
#elif defined CANIF_START_SEC_CODE
#undef CANIF_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined CANIF_STOP_SEC_CODE
#undef CANIF_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CODE_NO_MATCH
#undef CANIF_START_SEC_CODE_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:11  Section name :CONFIG_DATA_8*/
#elif defined CANIF_START_SEC_CONFIG_DATA_8
#undef CANIF_START_SEC_CONFIG_DATA_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CONFIG_DATA_8_NO_MATCH
#define START_SEC_CONFIG_DATA_8

#elif defined CANIF_STOP_SEC_CONFIG_DATA_8
#undef CANIF_STOP_SEC_CONFIG_DATA_8
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CONFIG_DATA_8_NO_MATCH
#undef CANIF_START_SEC_CONFIG_DATA_8_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_8

/*Index:12  Section name :CONFIG_DATA_UNSPECIFIED*/
#elif defined CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#undef CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_UNSPECIFIED

/*Index:13  Section name :PBCONFIG_DATA_16*/
#elif defined CANIF_START_SEC_PBCONFIG_DATA_16
#undef CANIF_START_SEC_PBCONFIG_DATA_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_PBCONFIG_DATA_16_NO_MATCH
#define START_SEC_PBCONFIG_DATA_16

#elif defined CANIF_STOP_SEC_PBCONFIG_DATA_16
#undef CANIF_STOP_SEC_PBCONFIG_DATA_16
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_PBCONFIG_DATA_16_NO_MATCH
#undef CANIF_START_SEC_PBCONFIG_DATA_16_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_PBCONFIG_DATA_16

/*Index:14  Section name :PBCONFIG_DATA_UNSPECIFIED*/
#elif defined CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#undef CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED_NO_MATCH
#define START_SEC_PBCONFIG_DATA_UNSPECIFIED

#elif defined CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#undef CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED_NO_MATCH
#undef CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_PBCONFIG_DATA_UNSPECIFIED

/*Index:15  Section name :VAR_INIT_8*/
#elif defined CANIF_START_SEC_VAR_INIT_8
#undef CANIF_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_VAR_INIT_8_NO_MATCH
#define START_SEC_VAR_INIT_8

#elif defined CANIF_STOP_SEC_VAR_INIT_8
#undef CANIF_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_VAR_INIT_8_NO_MATCH
#undef CANIF_START_SEC_VAR_INIT_8_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_8

/*Index:16  Section name :VAR_INIT_PTR*/
#elif defined CANIF_START_SEC_VAR_INIT_PTR
#undef CANIF_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_VAR_INIT_PTR_NO_MATCH
#define START_SEC_VAR_INIT_PTR

#elif defined CANIF_STOP_SEC_VAR_INIT_PTR
#undef CANIF_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_VAR_INIT_PTR_NO_MATCH
#undef CANIF_START_SEC_VAR_INIT_PTR_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_PTR

/*Index:17  Section name :VAR_INIT_UNSPECIFIED*/
#elif defined CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_INIT_UNSPECIFIED

#elif defined CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_UNSPECIFIED

/*Index:18  Section name :VAR_NO_INIT_32*/
#elif defined CANIF_START_SEC_VAR_NO_INIT_32
#undef CANIF_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_VAR_NO_INIT_32_NO_MATCH
#define START_SEC_VAR_NO_INIT_32

#elif defined CANIF_STOP_SEC_VAR_NO_INIT_32
#undef CANIF_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_VAR_NO_INIT_32_NO_MATCH
#undef CANIF_START_SEC_VAR_NO_INIT_32_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_32

/*Index:19  Section name :VAR_NO_INIT_8*/
#elif defined CANIF_START_SEC_VAR_NO_INIT_8
#undef CANIF_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_VAR_NO_INIT_8_NO_MATCH
#define START_SEC_VAR_NO_INIT_8

#elif defined CANIF_STOP_SEC_VAR_NO_INIT_8
#undef CANIF_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_VAR_NO_INIT_8_NO_MATCH
#undef CANIF_START_SEC_VAR_NO_INIT_8_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_8

/*Index:20  Section name :VAR_NO_INIT_BOOLEAN*/
#elif defined CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
#undef CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "CanIf_MemMap.h, section is used consecutively many times."
#endif
#define CANIF_START_SEC_VAR_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_NO_INIT_BOOLEAN

#elif defined CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef CANIF_START_SEC_VAR_NO_INIT_BOOLEAN_NO_MATCH
#undef CANIF_START_SEC_VAR_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "CanIf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_BOOLEAN

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "CanIf_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883,0791-- */ /* MISAR Dir-4.10,Rule-5.4 */
