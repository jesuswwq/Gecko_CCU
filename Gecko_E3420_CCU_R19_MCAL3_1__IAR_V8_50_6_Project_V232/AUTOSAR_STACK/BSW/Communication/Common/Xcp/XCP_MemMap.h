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
**  FILENAME    : Xcp_MemMap.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : <Auto generated>                                            **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of Xcp              **
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
#define MEMMAP_ERROR

#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

#elif defined XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef XCP_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#undef XCP_START_SEC_CANIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

#elif defined XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef XCP_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#undef XCP_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

#elif defined XCP_START_SEC_CODE
#undef XCP_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE
#elif defined XCP_STOP_SEC_CODE
#undef XCP_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CODE_NO_MATCH
#undef XCP_START_SEC_CODE_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

#elif defined XCP_START_SEC_CONFIG_DATA_16
#undef XCP_START_SEC_CONFIG_DATA_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CONFIG_DATA_16_NO_MATCH
#define START_SEC_CONFIG_DATA_16
#elif defined XCP_STOP_SEC_CONFIG_DATA_16
#undef XCP_STOP_SEC_CONFIG_DATA_16
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CONFIG_DATA_16_NO_MATCH
#undef XCP_START_SEC_CONFIG_DATA_16_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_16

#elif defined XCP_START_SEC_CONFIG_DATA_32
#undef XCP_START_SEC_CONFIG_DATA_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CONFIG_DATA_32_NO_MATCH
#define START_SEC_CONFIG_DATA_32
#elif defined XCP_STOP_SEC_CONFIG_DATA_32
#undef XCP_STOP_SEC_CONFIG_DATA_32
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CONFIG_DATA_32_NO_MATCH
#undef XCP_START_SEC_CONFIG_DATA_32_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_32

#elif defined XCP_START_SEC_CONFIG_DATA_8
#undef XCP_START_SEC_CONFIG_DATA_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CONFIG_DATA_8_NO_MATCH
#define START_SEC_CONFIG_DATA_8
#elif defined XCP_STOP_SEC_CONFIG_DATA_8
#undef XCP_STOP_SEC_CONFIG_DATA_8
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CONFIG_DATA_8_NO_MATCH
#undef XCP_START_SEC_CONFIG_DATA_8_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_8

#elif defined XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#undef XCP_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined XCP_START_SEC_CONST_PBCFG_16
#undef XCP_START_SEC_CONST_PBCFG_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CONST_PBCFG_16_NO_MATCH
#define START_SEC_CONST_PBCFG_16
#elif defined XCP_STOP_SEC_CONST_PBCFG_16
#undef XCP_STOP_SEC_CONST_PBCFG_16
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CONST_PBCFG_16_NO_MATCH
#undef XCP_START_SEC_CONST_PBCFG_16_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_16

#elif defined XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#undef XCP_START_SEC_CONST_PBCFG_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_CONST_PBCFG_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_PBCFG_UNSPECIFIED
#elif defined XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#undef XCP_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_CONST_PBCFG_UNSPECIFIED_NO_MATCH
#undef XCP_START_SEC_CONST_PBCFG_UNSPECIFIED_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_UNSPECIFIED

#elif defined XCP_START_SEC_INTERNAL_CALVAR_32
#undef XCP_START_SEC_INTERNAL_CALVAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_INTERNAL_CALVAR_32_NO_MATCH
#define START_SEC_INTERNAL_CALVAR_32
#elif defined XCP_STOP_SEC_INTERNAL_CALVAR_32
#undef XCP_STOP_SEC_INTERNAL_CALVAR_32
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_INTERNAL_CALVAR_32_NO_MATCH
#undef XCP_START_SEC_INTERNAL_CALVAR_32_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_CALVAR_32

#elif defined XCP_START_SEC_INTERNAL_CALVAR_8
#undef XCP_START_SEC_INTERNAL_CALVAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_INTERNAL_CALVAR_8_NO_MATCH
#define START_SEC_INTERNAL_CALVAR_8
#elif defined XCP_STOP_SEC_INTERNAL_CALVAR_8
#undef XCP_STOP_SEC_INTERNAL_CALVAR_8
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_INTERNAL_CALVAR_8_NO_MATCH
#undef XCP_START_SEC_INTERNAL_CALVAR_8_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_CALVAR_8

#elif defined XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE
#undef XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_SOADIFRXINDICATION_CALLBACK_CODE
#undef XCP_STOP_SEC_SOADIFRXINDICATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#undef XCP_START_SEC_SOADIFRXINDICATION_CALLBACK_CODE_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

#elif defined XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
#undef XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE
#elif defined XCP_STOP_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
#undef XCP_STOP_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#undef XCP_START_SEC_SOADIFTXCONFIRMATION_CALLBACK_CODE_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

#elif defined XCP_START_SEC_VAR_CLEARED_16
#undef XCP_START_SEC_VAR_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_CLEARED_16_NO_MATCH
#define START_SEC_VAR_CLEARED_16
#elif defined XCP_STOP_SEC_VAR_CLEARED_16
#undef XCP_STOP_SEC_VAR_CLEARED_16
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_CLEARED_16_NO_MATCH
#undef XCP_START_SEC_VAR_CLEARED_16_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_16

#elif defined XCP_START_SEC_VAR_CLEARED_32
#undef XCP_START_SEC_VAR_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_CLEARED_32_NO_MATCH
#define START_SEC_VAR_CLEARED_32
#elif defined XCP_STOP_SEC_VAR_CLEARED_32
#undef XCP_STOP_SEC_VAR_CLEARED_32
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_CLEARED_32_NO_MATCH
#undef XCP_START_SEC_VAR_CLEARED_32_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_32

#elif defined XCP_START_SEC_VAR_CLEARED_8
#undef XCP_START_SEC_VAR_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_CLEARED_8_NO_MATCH
#define START_SEC_VAR_CLEARED_8
#elif defined XCP_STOP_SEC_VAR_CLEARED_8
#undef XCP_STOP_SEC_VAR_CLEARED_8
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_CLEARED_8_NO_MATCH
#undef XCP_START_SEC_VAR_CLEARED_8_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_8

#elif defined XCP_START_SEC_VAR_CLEARED_PTR
#undef XCP_START_SEC_VAR_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_CLEARED_PTR_NO_MATCH
#define START_SEC_VAR_CLEARED_PTR
#elif defined XCP_STOP_SEC_VAR_CLEARED_PTR
#undef XCP_STOP_SEC_VAR_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_CLEARED_PTR_NO_MATCH
#undef XCP_START_SEC_VAR_CLEARED_PTR_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_PTR

#elif defined XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#undef XCP_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined XCP_START_SEC_VAR_INIT_16
#undef XCP_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_INIT_16_NO_MATCH
#define START_SEC_VAR_INIT_16
#elif defined XCP_STOP_SEC_VAR_INIT_16
#undef XCP_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_INIT_16_NO_MATCH
#undef XCP_START_SEC_VAR_INIT_16_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_16

#elif defined XCP_START_SEC_VAR_INIT_8
#undef XCP_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_INIT_8_NO_MATCH
#define START_SEC_VAR_INIT_8
#elif defined XCP_STOP_SEC_VAR_INIT_8
#undef XCP_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_INIT_8_NO_MATCH
#undef XCP_START_SEC_VAR_INIT_8_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_8

#elif defined XCP_START_SEC_VAR_INIT_BOOLEAN
#undef XCP_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_INIT_BOOLEAN
#elif defined XCP_STOP_SEC_VAR_INIT_BOOLEAN
#undef XCP_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_INIT_BOOLEAN_NO_MATCH
#undef XCP_START_SEC_VAR_INIT_BOOLEAN_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_BOOLEAN

#elif defined XCP_START_SEC_VAR_INIT_UNSPECIFIED
#undef XCP_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_INIT_UNSPECIFIED
#elif defined XCP_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#undef XCP_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_UNSPECIFIED

#elif defined XCP_START_SEC_VAR_SAVED_ZONE_16
#undef XCP_START_SEC_VAR_SAVED_ZONE_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Xcp_MemMap.h, section is used consecutively many times."
#endif
#define XCP_START_SEC_VAR_SAVED_ZONE_16_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_16
#elif defined XCP_STOP_SEC_VAR_SAVED_ZONE_16
#undef XCP_STOP_SEC_VAR_SAVED_ZONE_16
#undef MEMMAP_ERROR
#ifdef XCP_START_SEC_VAR_SAVED_ZONE_16_NO_MATCH
#undef XCP_START_SEC_VAR_SAVED_ZONE_16_NO_MATCH
#else
#error "Xcp_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_16

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "Xcp_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
