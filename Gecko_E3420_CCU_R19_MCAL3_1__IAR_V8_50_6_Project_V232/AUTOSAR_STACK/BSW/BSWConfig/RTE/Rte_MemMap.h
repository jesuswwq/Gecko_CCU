/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_MemMap.h>
 *  @brief      <>
 *
 *  
 *  @author     <>
 */
/*============================================================================*/

/* Rte_MemMap.h */

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/

#define MEMMAP_ERROR

/* Total section items: 231 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CODE*/
#elif defined RTE_START_SEC_CODE
#undef RTE_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined RTE_STOP_SEC_CODE
#undef RTE_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CODE_NO_MATCH
#undef RTE_START_SEC_CODE_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:1  Section name :CALLOUT_CODE*/
#elif defined RTE_START_SEC_CALLOUT_CODE
#undef RTE_START_SEC_CALLOUT_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALLOUT_CODE_NO_MATCH
#define START_SEC_CALLOUT_CODE

#elif defined RTE_STOP_SEC_CALLOUT_CODE
#undef RTE_STOP_SEC_CALLOUT_CODE
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALLOUT_CODE_NO_MATCH
#undef RTE_START_SEC_CALLOUT_CODE_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLOUT_CODE

/*Index:2  Section name :CALLBACK_CODE*/
#elif defined RTE_START_SEC_CALLBACK_CODE
#undef RTE_START_SEC_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALLBACK_CODE_NO_MATCH
#define START_SEC_CALLBACK_CODE

#elif defined RTE_STOP_SEC_CALLBACK_CODE
#undef RTE_STOP_SEC_CALLBACK_CODE
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALLBACK_CODE_NO_MATCH
#undef RTE_START_SEC_CALLBACK_CODE_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALLBACK_CODE

/*Index:3  Section name :CODE_FAST*/
#elif defined RTE_START_SEC_CODE_FAST
#undef RTE_START_SEC_CODE_FAST
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CODE_FAST_NO_MATCH
#define START_SEC_CODE_FAST

#elif defined RTE_STOP_SEC_CODE_FAST
#undef RTE_STOP_SEC_CODE_FAST
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CODE_FAST_NO_MATCH
#undef RTE_START_SEC_CODE_FAST_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE_FAST

/*Index:4  Section name :VAR_NO_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_NO_INIT_BOOLEAN
#undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_NO_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_BOOLEAN

/*Index:5  Section name :VAR_NO_INIT_8*/
#elif defined RTE_START_SEC_VAR_NO_INIT_8
#undef RTE_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_NO_INIT_8_NO_MATCH
#define START_SEC_VAR_NO_INIT_8

#elif defined RTE_STOP_SEC_VAR_NO_INIT_8
#undef RTE_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_MATCH
#undef RTE_START_SEC_VAR_NO_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_8

/*Index:6  Section name :VAR_NO_INIT_16*/
#elif defined RTE_START_SEC_VAR_NO_INIT_16
#undef RTE_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_NO_INIT_16_NO_MATCH
#define START_SEC_VAR_NO_INIT_16

#elif defined RTE_STOP_SEC_VAR_NO_INIT_16
#undef RTE_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_MATCH
#undef RTE_START_SEC_VAR_NO_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_16

/*Index:7  Section name :VAR_NO_INIT_32*/
#elif defined RTE_START_SEC_VAR_NO_INIT_32
#undef RTE_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_NO_INIT_32_NO_MATCH
#define START_SEC_VAR_NO_INIT_32

#elif defined RTE_STOP_SEC_VAR_NO_INIT_32
#undef RTE_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_MATCH
#undef RTE_START_SEC_VAR_NO_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_32

/*Index:8  Section name :VAR_NO_INIT_PTR*/
#elif defined RTE_START_SEC_VAR_NO_INIT_PTR
#undef RTE_START_SEC_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#define START_SEC_VAR_NO_INIT_PTR

#elif defined RTE_STOP_SEC_VAR_NO_INIT_PTR
#undef RTE_STOP_SEC_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_NO_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_PTR

/*Index:9  Section name :VAR_NO_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/*Index:10  Section name :VAR_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_CLEARED_BOOLEAN
#undef RTE_START_SEC_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_VAR_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_BOOLEAN

/*Index:11  Section name :VAR_CLEARED_8*/
#elif defined RTE_START_SEC_VAR_CLEARED_8
#undef RTE_START_SEC_VAR_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_CLEARED_8_NO_MATCH
#define START_SEC_VAR_CLEARED_8

#elif defined RTE_STOP_SEC_VAR_CLEARED_8
#undef RTE_STOP_SEC_VAR_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_VAR_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_8

/*Index:12  Section name :VAR_CLEARED_16*/
#elif defined RTE_START_SEC_VAR_CLEARED_16
#undef RTE_START_SEC_VAR_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_CLEARED_16_NO_MATCH
#define START_SEC_VAR_CLEARED_16

#elif defined RTE_STOP_SEC_VAR_CLEARED_16
#undef RTE_STOP_SEC_VAR_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_VAR_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_16

/*Index:13  Section name :VAR_CLEARED_32*/
#elif defined RTE_START_SEC_VAR_CLEARED_32
#undef RTE_START_SEC_VAR_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_CLEARED_32_NO_MATCH
#define START_SEC_VAR_CLEARED_32

#elif defined RTE_STOP_SEC_VAR_CLEARED_32
#undef RTE_STOP_SEC_VAR_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_VAR_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_32

/*Index:14  Section name :VAR_CLEARED_PTR*/
#elif defined RTE_START_SEC_VAR_CLEARED_PTR
#undef RTE_START_SEC_VAR_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_CLEARED_PTR_NO_MATCH
#define START_SEC_VAR_CLEARED_PTR

#elif defined RTE_STOP_SEC_VAR_CLEARED_PTR
#undef RTE_STOP_SEC_VAR_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_PTR

/*Index:15  Section name :VAR_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_UNSPECIFIED

/*Index:16  Section name :VAR_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_VAR_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_VAR_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_CLEAR_BOOLEAN

/*Index:17  Section name :VAR_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_VAR_POWER_ON_CLEAR_8
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_VAR_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_VAR_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_VAR_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_CLEAR_8

/*Index:18  Section name :VAR_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_VAR_POWER_ON_CLEAR_16
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_VAR_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_VAR_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_VAR_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_CLEAR_16

/*Index:19  Section name :VAR_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_VAR_POWER_ON_CLEAR_32
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_VAR_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_VAR_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_VAR_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_CLEAR_32

/*Index:20  Section name :VAR_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_VAR_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_VAR_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_VAR_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_VAR_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_CLEAR_PTR

/*Index:21  Section name :VAR_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_CLEAR_UNSPECIFIED

/*Index:22  Section name :VAR_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_INIT_BOOLEAN
#undef RTE_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_INIT_BOOLEAN
#undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_BOOLEAN

/*Index:23  Section name :VAR_INIT_8*/
#elif defined RTE_START_SEC_VAR_INIT_8
#undef RTE_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_8_NO_MATCH
#define START_SEC_VAR_INIT_8

#elif defined RTE_STOP_SEC_VAR_INIT_8
#undef RTE_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_8_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_8

/*Index:24  Section name :VAR_INIT_16*/
#elif defined RTE_START_SEC_VAR_INIT_16
#undef RTE_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_16_NO_MATCH
#define START_SEC_VAR_INIT_16

#elif defined RTE_STOP_SEC_VAR_INIT_16
#undef RTE_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_16_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_16

/*Index:25  Section name :VAR_INIT_32*/
#elif defined RTE_START_SEC_VAR_INIT_32
#undef RTE_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_32_NO_MATCH
#define START_SEC_VAR_INIT_32

#elif defined RTE_STOP_SEC_VAR_INIT_32
#undef RTE_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_32_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_32

/*Index:26  Section name :VAR_INIT_PTR*/
#elif defined RTE_START_SEC_VAR_INIT_PTR
#undef RTE_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_PTR_NO_MATCH
#define START_SEC_VAR_INIT_PTR

#elif defined RTE_STOP_SEC_VAR_INIT_PTR
#undef RTE_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_PTR

/*Index:27  Section name :VAR_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_INIT_UNSPECIFIED
#undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_UNSPECIFIED

/*Index:28  Section name :VAR_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN

/*Index:29  Section name :VAR_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_VAR_POWER_ON_INIT_8
#undef RTE_START_SEC_VAR_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_VAR_POWER_ON_INIT_8
#undef RTE_STOP_SEC_VAR_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_8

/*Index:30  Section name :VAR_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_VAR_POWER_ON_INIT_16
#undef RTE_START_SEC_VAR_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_VAR_POWER_ON_INIT_16
#undef RTE_STOP_SEC_VAR_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_16

/*Index:31  Section name :VAR_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_VAR_POWER_ON_INIT_32
#undef RTE_START_SEC_VAR_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_VAR_POWER_ON_INIT_32
#undef RTE_STOP_SEC_VAR_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_32

/*Index:32  Section name :VAR_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_VAR_POWER_ON_INIT_PTR
#undef RTE_START_SEC_VAR_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_VAR_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_VAR_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_PTR

/*Index:33  Section name :VAR_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

/*Index:34  Section name :INTERNAL_VAR_NO_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN
#undef RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_NO_INIT_BOOLEAN

/*Index:35  Section name :INTERNAL_VAR_NO_INIT_8*/
#elif defined RTE_START_SEC_INTERNAL_VAR_NO_INIT_8
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_NO_INIT_8_NO_MATCH
#define START_SEC_INTERNAL_VAR_NO_INIT_8

#elif defined RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_8
#undef RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_NO_INIT_8_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_NO_INIT_8

/*Index:36  Section name :INTERNAL_VAR_NO_INIT_16*/
#elif defined RTE_START_SEC_INTERNAL_VAR_NO_INIT_16
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_NO_INIT_16_NO_MATCH
#define START_SEC_INTERNAL_VAR_NO_INIT_16

#elif defined RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_16
#undef RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_NO_INIT_16_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_NO_INIT_16

/*Index:37  Section name :INTERNAL_VAR_NO_INIT_32*/
#elif defined RTE_START_SEC_INTERNAL_VAR_NO_INIT_32
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_NO_INIT_32_NO_MATCH
#define START_SEC_INTERNAL_VAR_NO_INIT_32

#elif defined RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_32
#undef RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_NO_INIT_32_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_NO_INIT_32

/*Index:38  Section name :INTERNAL_VAR_NO_INIT_PTR*/
#elif defined RTE_START_SEC_INTERNAL_VAR_NO_INIT_PTR
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_NO_INIT_PTR_NO_MATCH
#define START_SEC_INTERNAL_VAR_NO_INIT_PTR

#elif defined RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_PTR
#undef RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_NO_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_NO_INIT_PTR

/*Index:39  Section name :INTERNAL_VAR_NO_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_NO_INIT_UNSPECIFIED

/*Index:40  Section name :INTERNAL_VAR_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_INTERNAL_VAR_CLEARED_BOOLEAN
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_INTERNAL_VAR_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_INTERNAL_VAR_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_INTERNAL_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_CLEARED_BOOLEAN

/*Index:41  Section name :INTERNAL_VAR_CLEARED_8*/
#elif defined RTE_START_SEC_INTERNAL_VAR_CLEARED_8
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_CLEARED_8_NO_MATCH
#define START_SEC_INTERNAL_VAR_CLEARED_8

#elif defined RTE_STOP_SEC_INTERNAL_VAR_CLEARED_8
#undef RTE_STOP_SEC_INTERNAL_VAR_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_CLEARED_8

/*Index:42  Section name :INTERNAL_VAR_CLEARED_16*/
#elif defined RTE_START_SEC_INTERNAL_VAR_CLEARED_16
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_CLEARED_16_NO_MATCH
#define START_SEC_INTERNAL_VAR_CLEARED_16

#elif defined RTE_STOP_SEC_INTERNAL_VAR_CLEARED_16
#undef RTE_STOP_SEC_INTERNAL_VAR_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_CLEARED_16

/*Index:43  Section name :INTERNAL_VAR_CLEARED_32*/
#elif defined RTE_START_SEC_INTERNAL_VAR_CLEARED_32
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_CLEARED_32_NO_MATCH
#define START_SEC_INTERNAL_VAR_CLEARED_32

#elif defined RTE_STOP_SEC_INTERNAL_VAR_CLEARED_32
#undef RTE_STOP_SEC_INTERNAL_VAR_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_CLEARED_32

/*Index:44  Section name :INTERNAL_VAR_CLEARED_PTR*/
#elif defined RTE_START_SEC_INTERNAL_VAR_CLEARED_PTR
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_CLEARED_PTR_NO_MATCH
#define START_SEC_INTERNAL_VAR_CLEARED_PTR

#elif defined RTE_STOP_SEC_INTERNAL_VAR_CLEARED_PTR
#undef RTE_STOP_SEC_INTERNAL_VAR_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_CLEARED_PTR

/*Index:45  Section name :INTERNAL_VAR_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_CLEARED_UNSPECIFIED

/*Index:46  Section name :INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_BOOLEAN

/*Index:47  Section name :INTERNAL_VAR_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_8

/*Index:48  Section name :INTERNAL_VAR_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_16

/*Index:49  Section name :INTERNAL_VAR_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_32

/*Index:50  Section name :INTERNAL_VAR_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_PTR

/*Index:51  Section name :INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_CLEAR_UNSPECIFIED

/*Index:52  Section name :INTERNAL_VAR_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_INTERNAL_VAR_INIT_BOOLEAN
#undef RTE_START_SEC_INTERNAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_INIT_BOOLEAN_NO_MATCH
#define START_SEC_INTERNAL_VAR_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_INTERNAL_VAR_INIT_BOOLEAN
#undef RTE_STOP_SEC_INTERNAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_INIT_BOOLEAN

/*Index:53  Section name :INTERNAL_VAR_INIT_8*/
#elif defined RTE_START_SEC_INTERNAL_VAR_INIT_8
#undef RTE_START_SEC_INTERNAL_VAR_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_INIT_8_NO_MATCH
#define START_SEC_INTERNAL_VAR_INIT_8

#elif defined RTE_STOP_SEC_INTERNAL_VAR_INIT_8
#undef RTE_STOP_SEC_INTERNAL_VAR_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_INIT_8_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_INIT_8

/*Index:54  Section name :INTERNAL_VAR_INIT_16*/
#elif defined RTE_START_SEC_INTERNAL_VAR_INIT_16
#undef RTE_START_SEC_INTERNAL_VAR_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_INIT_16_NO_MATCH
#define START_SEC_INTERNAL_VAR_INIT_16

#elif defined RTE_STOP_SEC_INTERNAL_VAR_INIT_16
#undef RTE_STOP_SEC_INTERNAL_VAR_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_INIT_16_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_INIT_16

/*Index:55  Section name :INTERNAL_VAR_INIT_32*/
#elif defined RTE_START_SEC_INTERNAL_VAR_INIT_32
#undef RTE_START_SEC_INTERNAL_VAR_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_INIT_32_NO_MATCH
#define START_SEC_INTERNAL_VAR_INIT_32

#elif defined RTE_STOP_SEC_INTERNAL_VAR_INIT_32
#undef RTE_STOP_SEC_INTERNAL_VAR_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_INIT_32_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_INIT_32

/*Index:56  Section name :INTERNAL_VAR_INIT_PTR*/
#elif defined RTE_START_SEC_INTERNAL_VAR_INIT_PTR
#undef RTE_START_SEC_INTERNAL_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_INIT_PTR_NO_MATCH
#define START_SEC_INTERNAL_VAR_INIT_PTR

#elif defined RTE_STOP_SEC_INTERNAL_VAR_INIT_PTR
#undef RTE_STOP_SEC_INTERNAL_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_INIT_PTR

/*Index:57  Section name :INTERNAL_VAR_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#undef RTE_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_INIT_UNSPECIFIED

/*Index:58  Section name :INTERNAL_VAR_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_BOOLEAN

/*Index:59  Section name :INTERNAL_VAR_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_8
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_8
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_8

/*Index:60  Section name :INTERNAL_VAR_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_16
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_16
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_16

/*Index:61  Section name :INTERNAL_VAR_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_32
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_32
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_32

/*Index:62  Section name :INTERNAL_VAR_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_PTR

/*Index:63  Section name :INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_INTERNAL_VAR_POWER_ON_INIT_UNSPECIFIED

/*Index:64  Section name :VAR_SAVED_ZONE_NO_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_NO_INIT_BOOLEAN

/*Index:65  Section name :VAR_SAVED_ZONE_NO_INIT_8*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_8
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_8_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_NO_INIT_8

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_8
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_8_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_NO_INIT_8

/*Index:66  Section name :VAR_SAVED_ZONE_NO_INIT_16*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_16
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_16_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_NO_INIT_16

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_16
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_16_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_NO_INIT_16

/*Index:67  Section name :VAR_SAVED_ZONE_NO_INIT_32*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_32
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_32_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_NO_INIT_32

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_32
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_32_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_NO_INIT_32

/*Index:68  Section name :VAR_SAVED_ZONE_NO_INIT_PTR*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_PTR
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_PTR_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_NO_INIT_PTR

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_PTR
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_NO_INIT_PTR

/*Index:69  Section name :VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_NO_INIT_UNSPECIFIED

/*Index:70  Section name :VAR_SAVED_ZONE_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_CLEARED_BOOLEAN

/*Index:71  Section name :VAR_SAVED_ZONE_CLEARED_8*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_8
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_8_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_CLEARED_8

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_8
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_CLEARED_8

/*Index:72  Section name :VAR_SAVED_ZONE_CLEARED_16*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_16
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_16_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_CLEARED_16

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_16
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_CLEARED_16

/*Index:73  Section name :VAR_SAVED_ZONE_CLEARED_32*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_32
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_32_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_CLEARED_32

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_32
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_CLEARED_32

/*Index:74  Section name :VAR_SAVED_ZONE_CLEARED_PTR*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_PTR
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_PTR_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_CLEARED_PTR

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_PTR
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_CLEARED_PTR

/*Index:75  Section name :VAR_SAVED_ZONE_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_CLEARED_UNSPECIFIED

/*Index:76  Section name :VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_BOOLEAN

/*Index:77  Section name :VAR_SAVED_ZONE_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_8

/*Index:78  Section name :VAR_SAVED_ZONE_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_16

/*Index:79  Section name :VAR_SAVED_ZONE_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_32

/*Index:80  Section name :VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_PTR

/*Index:81  Section name :VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_CLEAR_UNSPECIFIED

/*Index:82  Section name :VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_BOOLEAN

/*Index:83  Section name :VAR_SAVED_ZONE_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_8

/*Index:84  Section name :VAR_SAVED_ZONE_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_16

/*Index:85  Section name :VAR_SAVED_ZONE_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_32

/*Index:86  Section name :VAR_SAVED_ZONE_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_PTR

/*Index:87  Section name :VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_SAVED_ZONE_POWER_ON_INIT_UNSPECIFIED

/*Index:88  Section name :CONST_NO_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_NO_INIT_BOOLEAN
#undef RTE_START_SEC_CONST_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONST_NO_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_NO_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONST_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_NO_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_NO_INIT_BOOLEAN

/*Index:89  Section name :CONST_NO_INIT_8*/
#elif defined RTE_START_SEC_CONST_NO_INIT_8
#undef RTE_START_SEC_CONST_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_NO_INIT_8_NO_MATCH
#define START_SEC_CONST_NO_INIT_8

#elif defined RTE_STOP_SEC_CONST_NO_INIT_8
#undef RTE_STOP_SEC_CONST_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_NO_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONST_NO_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_NO_INIT_8

/*Index:90  Section name :CONST_NO_INIT_16*/
#elif defined RTE_START_SEC_CONST_NO_INIT_16
#undef RTE_START_SEC_CONST_NO_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_NO_INIT_16_NO_MATCH
#define START_SEC_CONST_NO_INIT_16

#elif defined RTE_STOP_SEC_CONST_NO_INIT_16
#undef RTE_STOP_SEC_CONST_NO_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_NO_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONST_NO_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_NO_INIT_16

/*Index:91  Section name :CONST_NO_INIT_32*/
#elif defined RTE_START_SEC_CONST_NO_INIT_32
#undef RTE_START_SEC_CONST_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_NO_INIT_32_NO_MATCH
#define START_SEC_CONST_NO_INIT_32

#elif defined RTE_STOP_SEC_CONST_NO_INIT_32
#undef RTE_STOP_SEC_CONST_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_NO_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONST_NO_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_NO_INIT_32

/*Index:92  Section name :CONST_NO_INIT_PTR*/
#elif defined RTE_START_SEC_CONST_NO_INIT_PTR
#undef RTE_START_SEC_CONST_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_NO_INIT_PTR_NO_MATCH
#define START_SEC_CONST_NO_INIT_PTR

#elif defined RTE_STOP_SEC_CONST_NO_INIT_PTR
#undef RTE_STOP_SEC_CONST_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_NO_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_NO_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_NO_INIT_PTR

/*Index:93  Section name :CONST_NO_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_NO_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONST_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_NO_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_NO_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_NO_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_NO_INIT_UNSPECIFIED

/*Index:94  Section name :CONST_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_CLEARED_BOOLEAN
#undef RTE_START_SEC_CONST_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_CONST_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_CONST_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_CLEARED_BOOLEAN

/*Index:95  Section name :CONST_CLEARED_8*/
#elif defined RTE_START_SEC_CONST_CLEARED_8
#undef RTE_START_SEC_CONST_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_CLEARED_8_NO_MATCH
#define START_SEC_CONST_CLEARED_8

#elif defined RTE_STOP_SEC_CONST_CLEARED_8
#undef RTE_STOP_SEC_CONST_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_CONST_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_CLEARED_8

/*Index:96  Section name :CONST_CLEARED_16*/
#elif defined RTE_START_SEC_CONST_CLEARED_16
#undef RTE_START_SEC_CONST_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_CLEARED_16_NO_MATCH
#define START_SEC_CONST_CLEARED_16

#elif defined RTE_STOP_SEC_CONST_CLEARED_16
#undef RTE_STOP_SEC_CONST_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_CONST_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_CLEARED_16

/*Index:97  Section name :CONST_CLEARED_32*/
#elif defined RTE_START_SEC_CONST_CLEARED_32
#undef RTE_START_SEC_CONST_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_CLEARED_32_NO_MATCH
#define START_SEC_CONST_CLEARED_32

#elif defined RTE_STOP_SEC_CONST_CLEARED_32
#undef RTE_STOP_SEC_CONST_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_CONST_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_CLEARED_32

/*Index:98  Section name :CONST_CLEARED_PTR*/
#elif defined RTE_START_SEC_CONST_CLEARED_PTR
#undef RTE_START_SEC_CONST_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_CLEARED_PTR_NO_MATCH
#define START_SEC_CONST_CLEARED_PTR

#elif defined RTE_STOP_SEC_CONST_CLEARED_PTR
#undef RTE_STOP_SEC_CONST_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_CLEARED_PTR

/*Index:99  Section name :CONST_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_CONST_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_CLEARED_UNSPECIFIED

/*Index:100  Section name :CONST_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_CONST_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_CONST_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_CLEAR_BOOLEAN

/*Index:101  Section name :CONST_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_CONST_POWER_ON_CLEAR_8
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_CONST_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_CONST_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_CONST_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_CLEAR_8

/*Index:102  Section name :CONST_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_CONST_POWER_ON_CLEAR_16
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_CONST_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_CONST_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_CONST_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_CLEAR_16

/*Index:103  Section name :CONST_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_CONST_POWER_ON_CLEAR_32
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_CONST_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_CONST_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_CONST_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_CLEAR_32

/*Index:104  Section name :CONST_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_CONST_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_CONST_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_CONST_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_CONST_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_CLEAR_PTR

/*Index:105  Section name :CONST_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_CLEAR_UNSPECIFIED

/*Index:106  Section name :CONST_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_INIT_BOOLEAN
#undef RTE_START_SEC_CONST_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONST_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONST_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_INIT_BOOLEAN

/*Index:107  Section name :CONST_INIT_8*/
#elif defined RTE_START_SEC_CONST_INIT_8
#undef RTE_START_SEC_CONST_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_INIT_8_NO_MATCH
#define START_SEC_CONST_INIT_8

#elif defined RTE_STOP_SEC_CONST_INIT_8
#undef RTE_STOP_SEC_CONST_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONST_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_INIT_8

/*Index:108  Section name :CONST_INIT_16*/
#elif defined RTE_START_SEC_CONST_INIT_16
#undef RTE_START_SEC_CONST_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_INIT_16_NO_MATCH
#define START_SEC_CONST_INIT_16

#elif defined RTE_STOP_SEC_CONST_INIT_16
#undef RTE_STOP_SEC_CONST_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONST_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_INIT_16

/*Index:109  Section name :CONST_INIT_32*/
#elif defined RTE_START_SEC_CONST_INIT_32
#undef RTE_START_SEC_CONST_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_INIT_32_NO_MATCH
#define START_SEC_CONST_INIT_32

#elif defined RTE_STOP_SEC_CONST_INIT_32
#undef RTE_STOP_SEC_CONST_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONST_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_INIT_32

/*Index:110  Section name :CONST_INIT_PTR*/
#elif defined RTE_START_SEC_CONST_INIT_PTR
#undef RTE_START_SEC_CONST_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_INIT_PTR_NO_MATCH
#define START_SEC_CONST_INIT_PTR

#elif defined RTE_STOP_SEC_CONST_INIT_PTR
#undef RTE_STOP_SEC_CONST_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_INIT_PTR

/*Index:111  Section name :CONST_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONST_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_INIT_UNSPECIFIED

/*Index:112  Section name :CONST_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_CONST_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONST_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONST_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_INIT_BOOLEAN

/*Index:113  Section name :CONST_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_CONST_POWER_ON_INIT_8
#undef RTE_START_SEC_CONST_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_CONST_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_CONST_POWER_ON_INIT_8
#undef RTE_STOP_SEC_CONST_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_INIT_8

/*Index:114  Section name :CONST_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_CONST_POWER_ON_INIT_16
#undef RTE_START_SEC_CONST_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_CONST_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_CONST_POWER_ON_INIT_16
#undef RTE_STOP_SEC_CONST_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_INIT_16

/*Index:115  Section name :CONST_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_CONST_POWER_ON_INIT_32
#undef RTE_START_SEC_CONST_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_CONST_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_CONST_POWER_ON_INIT_32
#undef RTE_STOP_SEC_CONST_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_INIT_32

/*Index:116  Section name :CONST_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_CONST_POWER_ON_INIT_PTR
#undef RTE_START_SEC_CONST_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_CONST_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_CONST_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_CONST_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_INIT_PTR

/*Index:117  Section name :CONST_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONST_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_POWER_ON_INIT_UNSPECIFIED

/*Index:118  Section name :CALIB_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_CALIB_CLEARED_BOOLEAN
#undef RTE_START_SEC_CALIB_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_CALIB_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_CALIB_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_CALIB_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CALIB_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_CLEARED_BOOLEAN

/*Index:119  Section name :CALIB_CLEARED_8*/
#elif defined RTE_START_SEC_CALIB_CLEARED_8
#undef RTE_START_SEC_CALIB_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_CLEARED_8_NO_MATCH
#define START_SEC_CALIB_CLEARED_8

#elif defined RTE_STOP_SEC_CALIB_CLEARED_8
#undef RTE_STOP_SEC_CALIB_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_CALIB_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_CLEARED_8

/*Index:120  Section name :CALIB_CLEARED_16*/
#elif defined RTE_START_SEC_CALIB_CLEARED_16
#undef RTE_START_SEC_CALIB_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_CLEARED_16_NO_MATCH
#define START_SEC_CALIB_CLEARED_16

#elif defined RTE_STOP_SEC_CALIB_CLEARED_16
#undef RTE_STOP_SEC_CALIB_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_CALIB_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_CLEARED_16

/*Index:121  Section name :CALIB_CLEARED_32*/
#elif defined RTE_START_SEC_CALIB_CLEARED_32
#undef RTE_START_SEC_CALIB_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_CLEARED_32_NO_MATCH
#define START_SEC_CALIB_CLEARED_32

#elif defined RTE_STOP_SEC_CALIB_CLEARED_32
#undef RTE_STOP_SEC_CALIB_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_CALIB_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_CLEARED_32

/*Index:122  Section name :CALIB_CLEARED_PTR*/
#elif defined RTE_START_SEC_CALIB_CLEARED_PTR
#undef RTE_START_SEC_CALIB_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_CLEARED_PTR_NO_MATCH
#define START_SEC_CALIB_CLEARED_PTR

#elif defined RTE_STOP_SEC_CALIB_CLEARED_PTR
#undef RTE_STOP_SEC_CALIB_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_CALIB_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_CLEARED_PTR

/*Index:123  Section name :CALIB_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_CALIB_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_CALIB_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_CALIB_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_CALIB_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_CALIB_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CALIB_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_CLEARED_UNSPECIFIED

/*Index:124  Section name :CALIB_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN

/*Index:125  Section name :CALIB_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_CLEAR_8
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_CALIB_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_CLEAR_8

/*Index:126  Section name :CALIB_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_CLEAR_16
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_CALIB_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_CLEAR_16

/*Index:127  Section name :CALIB_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_CLEAR_32
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_CALIB_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_CLEAR_32

/*Index:128  Section name :CALIB_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_CALIB_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_CLEAR_PTR

/*Index:129  Section name :CALIB_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED

/*Index:130  Section name :CALIB_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CALIB_INIT_BOOLEAN
#undef RTE_START_SEC_CALIB_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CALIB_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CALIB_INIT_BOOLEAN
#undef RTE_STOP_SEC_CALIB_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CALIB_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_INIT_BOOLEAN

/*Index:131  Section name :CALIB_INIT_8*/
#elif defined RTE_START_SEC_CALIB_INIT_8
#undef RTE_START_SEC_CALIB_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_INIT_8_NO_MATCH
#define START_SEC_CALIB_INIT_8

#elif defined RTE_STOP_SEC_CALIB_INIT_8
#undef RTE_STOP_SEC_CALIB_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_INIT_8_NO_MATCH
#undef RTE_START_SEC_CALIB_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_INIT_8

/*Index:132  Section name :CALIB_INIT_16*/
#elif defined RTE_START_SEC_CALIB_INIT_16
#undef RTE_START_SEC_CALIB_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_INIT_16_NO_MATCH
#define START_SEC_CALIB_INIT_16

#elif defined RTE_STOP_SEC_CALIB_INIT_16
#undef RTE_STOP_SEC_CALIB_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_INIT_16_NO_MATCH
#undef RTE_START_SEC_CALIB_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_INIT_16

/*Index:133  Section name :CALIB_INIT_32*/
#elif defined RTE_START_SEC_CALIB_INIT_32
#undef RTE_START_SEC_CALIB_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_INIT_32_NO_MATCH
#define START_SEC_CALIB_INIT_32

#elif defined RTE_STOP_SEC_CALIB_INIT_32
#undef RTE_STOP_SEC_CALIB_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_INIT_32_NO_MATCH
#undef RTE_START_SEC_CALIB_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_INIT_32

/*Index:134  Section name :CALIB_INIT_PTR*/
#elif defined RTE_START_SEC_CALIB_INIT_PTR
#undef RTE_START_SEC_CALIB_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_INIT_PTR_NO_MATCH
#define START_SEC_CALIB_INIT_PTR

#elif defined RTE_STOP_SEC_CALIB_INIT_PTR
#undef RTE_STOP_SEC_CALIB_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CALIB_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_INIT_PTR

/*Index:135  Section name :CALIB_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CALIB_INIT_UNSPECIFIED
#undef RTE_START_SEC_CALIB_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CALIB_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CALIB_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CALIB_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CALIB_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_INIT_UNSPECIFIED

/*Index:136  Section name :CALIB_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CALIB_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_CALIB_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_INIT_BOOLEAN

/*Index:137  Section name :CALIB_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_INIT_8
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_CALIB_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_INIT_8
#undef RTE_STOP_SEC_CALIB_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_INIT_8

/*Index:138  Section name :CALIB_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_INIT_16
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_CALIB_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_INIT_16
#undef RTE_STOP_SEC_CALIB_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_INIT_16

/*Index:139  Section name :CALIB_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_INIT_32
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_CALIB_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_INIT_32
#undef RTE_STOP_SEC_CALIB_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_INIT_32

/*Index:140  Section name :CALIB_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_INIT_PTR
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_CALIB_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_CALIB_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_INIT_PTR

/*Index:141  Section name :CALIB_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED

/*Index:142  Section name :MEA_NO_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_MEA_NO_INIT_BOOLEAN
#undef RTE_START_SEC_MEA_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_MEA_NO_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_MEA_NO_INIT_BOOLEAN
#undef RTE_STOP_SEC_MEA_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_NO_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_MEA_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_NO_INIT_BOOLEAN

/*Index:143  Section name :MEA_NO_INIT_8*/
#elif defined RTE_START_SEC_MEA_NO_INIT_8
#undef RTE_START_SEC_MEA_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_NO_INIT_8_NO_MATCH
#define START_SEC_MEA_NO_INIT_8

#elif defined RTE_STOP_SEC_MEA_NO_INIT_8
#undef RTE_STOP_SEC_MEA_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_NO_INIT_8_NO_MATCH
#undef RTE_START_SEC_MEA_NO_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_NO_INIT_8

/*Index:144  Section name :MEA_NO_INIT_16*/
#elif defined RTE_START_SEC_MEA_NO_INIT_16
#undef RTE_START_SEC_MEA_NO_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_NO_INIT_16_NO_MATCH
#define START_SEC_MEA_NO_INIT_16

#elif defined RTE_STOP_SEC_MEA_NO_INIT_16
#undef RTE_STOP_SEC_MEA_NO_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_NO_INIT_16_NO_MATCH
#undef RTE_START_SEC_MEA_NO_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_NO_INIT_16

/*Index:145  Section name :MEA_NO_INIT_32*/
#elif defined RTE_START_SEC_MEA_NO_INIT_32
#undef RTE_START_SEC_MEA_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_NO_INIT_32_NO_MATCH
#define START_SEC_MEA_NO_INIT_32

#elif defined RTE_STOP_SEC_MEA_NO_INIT_32
#undef RTE_STOP_SEC_MEA_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_NO_INIT_32_NO_MATCH
#undef RTE_START_SEC_MEA_NO_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_NO_INIT_32

/*Index:146  Section name :MEA_NO_INIT_PTR*/
#elif defined RTE_START_SEC_MEA_NO_INIT_PTR
#undef RTE_START_SEC_MEA_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_NO_INIT_PTR_NO_MATCH
#define START_SEC_MEA_NO_INIT_PTR

#elif defined RTE_STOP_SEC_MEA_NO_INIT_PTR
#undef RTE_STOP_SEC_MEA_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_NO_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_MEA_NO_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_NO_INIT_PTR

/*Index:147  Section name :MEA_NO_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_MEA_NO_INIT_UNSPECIFIED
#undef RTE_START_SEC_MEA_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_MEA_NO_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_MEA_NO_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_MEA_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_NO_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_MEA_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_NO_INIT_UNSPECIFIED

/*Index:148  Section name :MEA_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_MEA_CLEARED_BOOLEAN
#undef RTE_START_SEC_MEA_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_MEA_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_MEA_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_MEA_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_MEA_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_CLEARED_BOOLEAN

/*Index:149  Section name :MEA_CLEARED_8*/
#elif defined RTE_START_SEC_MEA_CLEARED_8
#undef RTE_START_SEC_MEA_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_CLEARED_8_NO_MATCH
#define START_SEC_MEA_CLEARED_8

#elif defined RTE_STOP_SEC_MEA_CLEARED_8
#undef RTE_STOP_SEC_MEA_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_MEA_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_CLEARED_8

/*Index:150  Section name :MEA_CLEARED_16*/
#elif defined RTE_START_SEC_MEA_CLEARED_16
#undef RTE_START_SEC_MEA_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_CLEARED_16_NO_MATCH
#define START_SEC_MEA_CLEARED_16

#elif defined RTE_STOP_SEC_MEA_CLEARED_16
#undef RTE_STOP_SEC_MEA_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_MEA_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_CLEARED_16

/*Index:151  Section name :MEA_CLEARED_32*/
#elif defined RTE_START_SEC_MEA_CLEARED_32
#undef RTE_START_SEC_MEA_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_CLEARED_32_NO_MATCH
#define START_SEC_MEA_CLEARED_32

#elif defined RTE_STOP_SEC_MEA_CLEARED_32
#undef RTE_STOP_SEC_MEA_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_MEA_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_CLEARED_32

/*Index:152  Section name :MEA_CLEARED_PTR*/
#elif defined RTE_START_SEC_MEA_CLEARED_PTR
#undef RTE_START_SEC_MEA_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_CLEARED_PTR_NO_MATCH
#define START_SEC_MEA_CLEARED_PTR

#elif defined RTE_STOP_SEC_MEA_CLEARED_PTR
#undef RTE_STOP_SEC_MEA_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_MEA_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_CLEARED_PTR

/*Index:153  Section name :MEA_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_MEA_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_MEA_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_MEA_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_MEA_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_MEA_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_MEA_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_CLEARED_UNSPECIFIED

/*Index:154  Section name :MEA_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_MEA_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_MEA_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_CLEAR_BOOLEAN

/*Index:155  Section name :MEA_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_MEA_POWER_ON_CLEAR_8
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_MEA_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_MEA_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_MEA_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_CLEAR_8

/*Index:156  Section name :MEA_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_MEA_POWER_ON_CLEAR_16
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_MEA_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_MEA_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_MEA_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_CLEAR_16

/*Index:157  Section name :MEA_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_MEA_POWER_ON_CLEAR_32
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_MEA_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_MEA_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_MEA_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_CLEAR_32

/*Index:158  Section name :MEA_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_MEA_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_MEA_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_MEA_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_MEA_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_CLEAR_PTR

/*Index:159  Section name :MEA_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED

/*Index:160  Section name :MEA_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_MEA_INIT_BOOLEAN
#undef RTE_START_SEC_MEA_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_INIT_BOOLEAN_NO_MATCH
#define START_SEC_MEA_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_MEA_INIT_BOOLEAN
#undef RTE_STOP_SEC_MEA_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_MEA_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_INIT_BOOLEAN

/*Index:161  Section name :MEA_INIT_8*/
#elif defined RTE_START_SEC_MEA_INIT_8
#undef RTE_START_SEC_MEA_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_INIT_8_NO_MATCH
#define START_SEC_MEA_INIT_8

#elif defined RTE_STOP_SEC_MEA_INIT_8
#undef RTE_STOP_SEC_MEA_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_INIT_8_NO_MATCH
#undef RTE_START_SEC_MEA_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_INIT_8

/*Index:162  Section name :MEA_INIT_16*/
#elif defined RTE_START_SEC_MEA_INIT_16
#undef RTE_START_SEC_MEA_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_INIT_16_NO_MATCH
#define START_SEC_MEA_INIT_16

#elif defined RTE_STOP_SEC_MEA_INIT_16
#undef RTE_STOP_SEC_MEA_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_INIT_16_NO_MATCH
#undef RTE_START_SEC_MEA_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_INIT_16

/*Index:163  Section name :MEA_INIT_32*/
#elif defined RTE_START_SEC_MEA_INIT_32
#undef RTE_START_SEC_MEA_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_INIT_32_NO_MATCH
#define START_SEC_MEA_INIT_32

#elif defined RTE_STOP_SEC_MEA_INIT_32
#undef RTE_STOP_SEC_MEA_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_INIT_32_NO_MATCH
#undef RTE_START_SEC_MEA_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_INIT_32

/*Index:164  Section name :MEA_INIT_PTR*/
#elif defined RTE_START_SEC_MEA_INIT_PTR
#undef RTE_START_SEC_MEA_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_INIT_PTR_NO_MATCH
#define START_SEC_MEA_INIT_PTR

#elif defined RTE_STOP_SEC_MEA_INIT_PTR
#undef RTE_STOP_SEC_MEA_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_MEA_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_INIT_PTR

/*Index:165  Section name :MEA_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_MEA_INIT_UNSPECIFIED
#undef RTE_START_SEC_MEA_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_MEA_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_MEA_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_MEA_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_MEA_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_INIT_UNSPECIFIED

/*Index:166  Section name :MEA_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_MEA_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_MEA_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_MEA_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_MEA_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_MEA_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_INIT_BOOLEAN

/*Index:167  Section name :MEA_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_MEA_POWER_ON_INIT_8
#undef RTE_START_SEC_MEA_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_MEA_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_MEA_POWER_ON_INIT_8
#undef RTE_STOP_SEC_MEA_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_INIT_8

/*Index:168  Section name :MEA_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_MEA_POWER_ON_INIT_16
#undef RTE_START_SEC_MEA_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_MEA_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_MEA_POWER_ON_INIT_16
#undef RTE_STOP_SEC_MEA_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_INIT_16

/*Index:169  Section name :MEA_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_MEA_POWER_ON_INIT_32
#undef RTE_START_SEC_MEA_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_MEA_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_MEA_POWER_ON_INIT_32
#undef RTE_STOP_SEC_MEA_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_INIT_32

/*Index:170  Section name :MEA_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_MEA_POWER_ON_INIT_PTR
#undef RTE_START_SEC_MEA_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_MEA_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_MEA_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_MEA_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_INIT_PTR

/*Index:171  Section name :MEA_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_MEA_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_MEA_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_MEA_POWER_ON_INIT_UNSPECIFIED

/*Index:172  Section name :CONFIG_DATA_NO_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONFIG_DATA_NO_INIT_BOOLEAN
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONFIG_DATA_NO_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONFIG_DATA_NO_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONFIG_DATA_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_NO_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_NO_INIT_BOOLEAN

/*Index:173  Section name :CONFIG_DATA_NO_INIT_8*/
#elif defined RTE_START_SEC_CONFIG_DATA_NO_INIT_8
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_NO_INIT_8_NO_MATCH
#define START_SEC_CONFIG_DATA_NO_INIT_8

#elif defined RTE_STOP_SEC_CONFIG_DATA_NO_INIT_8
#undef RTE_STOP_SEC_CONFIG_DATA_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_NO_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_NO_INIT_8

/*Index:174  Section name :CONFIG_DATA_NO_INIT_16*/
#elif defined RTE_START_SEC_CONFIG_DATA_NO_INIT_16
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_NO_INIT_16_NO_MATCH
#define START_SEC_CONFIG_DATA_NO_INIT_16

#elif defined RTE_STOP_SEC_CONFIG_DATA_NO_INIT_16
#undef RTE_STOP_SEC_CONFIG_DATA_NO_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_NO_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_NO_INIT_16

/*Index:175  Section name :CONFIG_DATA_NO_INIT_32*/
#elif defined RTE_START_SEC_CONFIG_DATA_NO_INIT_32
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_NO_INIT_32_NO_MATCH
#define START_SEC_CONFIG_DATA_NO_INIT_32

#elif defined RTE_STOP_SEC_CONFIG_DATA_NO_INIT_32
#undef RTE_STOP_SEC_CONFIG_DATA_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_NO_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_NO_INIT_32

/*Index:176  Section name :CONFIG_DATA_NO_INIT_PTR*/
#elif defined RTE_START_SEC_CONFIG_DATA_NO_INIT_PTR
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_NO_INIT_PTR_NO_MATCH
#define START_SEC_CONFIG_DATA_NO_INIT_PTR

#elif defined RTE_STOP_SEC_CONFIG_DATA_NO_INIT_PTR
#undef RTE_STOP_SEC_CONFIG_DATA_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_NO_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_NO_INIT_PTR

/*Index:177  Section name :CONFIG_DATA_NO_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_NO_INIT_UNSPECIFIED

/*Index:178  Section name :CONFIG_DATA_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_CONFIG_DATA_CLEARED_BOOLEAN
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_CONFIG_DATA_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_CONFIG_DATA_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_CONFIG_DATA_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_CLEARED_BOOLEAN

/*Index:179  Section name :CONFIG_DATA_CLEARED_8*/
#elif defined RTE_START_SEC_CONFIG_DATA_CLEARED_8
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_CLEARED_8_NO_MATCH
#define START_SEC_CONFIG_DATA_CLEARED_8

#elif defined RTE_STOP_SEC_CONFIG_DATA_CLEARED_8
#undef RTE_STOP_SEC_CONFIG_DATA_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_CLEARED_8

/*Index:180  Section name :CONFIG_DATA_CLEARED_16*/
#elif defined RTE_START_SEC_CONFIG_DATA_CLEARED_16
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_CLEARED_16_NO_MATCH
#define START_SEC_CONFIG_DATA_CLEARED_16

#elif defined RTE_STOP_SEC_CONFIG_DATA_CLEARED_16
#undef RTE_STOP_SEC_CONFIG_DATA_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_CLEARED_16

/*Index:181  Section name :CONFIG_DATA_CLEARED_32*/
#elif defined RTE_START_SEC_CONFIG_DATA_CLEARED_32
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_CLEARED_32_NO_MATCH
#define START_SEC_CONFIG_DATA_CLEARED_32

#elif defined RTE_STOP_SEC_CONFIG_DATA_CLEARED_32
#undef RTE_STOP_SEC_CONFIG_DATA_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_CLEARED_32

/*Index:182  Section name :CONFIG_DATA_CLEARED_PTR*/
#elif defined RTE_START_SEC_CONFIG_DATA_CLEARED_PTR
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_CLEARED_PTR_NO_MATCH
#define START_SEC_CONFIG_DATA_CLEARED_PTR

#elif defined RTE_STOP_SEC_CONFIG_DATA_CLEARED_PTR
#undef RTE_STOP_SEC_CONFIG_DATA_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_CLEARED_PTR

/*Index:183  Section name :CONFIG_DATA_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_CLEARED_UNSPECIFIED

/*Index:184  Section name :CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_BOOLEAN

/*Index:185  Section name :CONFIG_DATA_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_8
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_8

/*Index:186  Section name :CONFIG_DATA_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_16
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_16

/*Index:187  Section name :CONFIG_DATA_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_32
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_32

/*Index:188  Section name :CONFIG_DATA_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_PTR

/*Index:189  Section name :CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_CLEAR_UNSPECIFIED

/*Index:190  Section name :CONFIG_DATA_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONFIG_DATA_INIT_BOOLEAN
#undef RTE_START_SEC_CONFIG_DATA_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONFIG_DATA_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONFIG_DATA_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONFIG_DATA_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_INIT_BOOLEAN

/*Index:191  Section name :CONFIG_DATA_INIT_8*/
#elif defined RTE_START_SEC_CONFIG_DATA_INIT_8
#undef RTE_START_SEC_CONFIG_DATA_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_INIT_8_NO_MATCH
#define START_SEC_CONFIG_DATA_INIT_8

#elif defined RTE_STOP_SEC_CONFIG_DATA_INIT_8
#undef RTE_STOP_SEC_CONFIG_DATA_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_INIT_8

/*Index:192  Section name :CONFIG_DATA_INIT_16*/
#elif defined RTE_START_SEC_CONFIG_DATA_INIT_16
#undef RTE_START_SEC_CONFIG_DATA_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_INIT_16_NO_MATCH
#define START_SEC_CONFIG_DATA_INIT_16

#elif defined RTE_STOP_SEC_CONFIG_DATA_INIT_16
#undef RTE_STOP_SEC_CONFIG_DATA_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_INIT_16

/*Index:193  Section name :CONFIG_DATA_INIT_32*/
#elif defined RTE_START_SEC_CONFIG_DATA_INIT_32
#undef RTE_START_SEC_CONFIG_DATA_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_INIT_32_NO_MATCH
#define START_SEC_CONFIG_DATA_INIT_32

#elif defined RTE_STOP_SEC_CONFIG_DATA_INIT_32
#undef RTE_STOP_SEC_CONFIG_DATA_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_INIT_32

/*Index:194  Section name :CONFIG_DATA_INIT_PTR*/
#elif defined RTE_START_SEC_CONFIG_DATA_INIT_PTR
#undef RTE_START_SEC_CONFIG_DATA_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_INIT_PTR_NO_MATCH
#define START_SEC_CONFIG_DATA_INIT_PTR

#elif defined RTE_STOP_SEC_CONFIG_DATA_INIT_PTR
#undef RTE_STOP_SEC_CONFIG_DATA_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_INIT_PTR

/*Index:195  Section name :CONFIG_DATA_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONFIG_DATA_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONFIG_DATA_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONFIG_DATA_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONFIG_DATA_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_INIT_UNSPECIFIED

/*Index:196  Section name :CONFIG_DATA_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_INIT_BOOLEAN

/*Index:197  Section name :CONFIG_DATA_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_8
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_8
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_INIT_8

/*Index:198  Section name :CONFIG_DATA_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_16
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_16
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_INIT_16

/*Index:199  Section name :CONFIG_DATA_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_32
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_32
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_INIT_32

/*Index:200  Section name :CONFIG_DATA_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_PTR
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_INIT_PTR

/*Index:201  Section name :CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_POWER_ON_INIT_UNSPECIFIED

/*Index:202  Section name :CONST_PBCFG_NO_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_PBCFG_NO_INIT_BOOLEAN
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_NO_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONST_PBCFG_NO_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_PBCFG_NO_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONST_PBCFG_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_NO_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_NO_INIT_BOOLEAN

/*Index:203  Section name :CONST_PBCFG_NO_INIT_8*/
#elif defined RTE_START_SEC_CONST_PBCFG_NO_INIT_8
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_NO_INIT_8_NO_MATCH
#define START_SEC_CONST_PBCFG_NO_INIT_8

#elif defined RTE_STOP_SEC_CONST_PBCFG_NO_INIT_8
#undef RTE_STOP_SEC_CONST_PBCFG_NO_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_NO_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_NO_INIT_8

/*Index:204  Section name :CONST_PBCFG_NO_INIT_16*/
#elif defined RTE_START_SEC_CONST_PBCFG_NO_INIT_16
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_NO_INIT_16_NO_MATCH
#define START_SEC_CONST_PBCFG_NO_INIT_16

#elif defined RTE_STOP_SEC_CONST_PBCFG_NO_INIT_16
#undef RTE_STOP_SEC_CONST_PBCFG_NO_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_NO_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_NO_INIT_16

/*Index:205  Section name :CONST_PBCFG_NO_INIT_32*/
#elif defined RTE_START_SEC_CONST_PBCFG_NO_INIT_32
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_NO_INIT_32_NO_MATCH
#define START_SEC_CONST_PBCFG_NO_INIT_32

#elif defined RTE_STOP_SEC_CONST_PBCFG_NO_INIT_32
#undef RTE_STOP_SEC_CONST_PBCFG_NO_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_NO_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_NO_INIT_32

/*Index:206  Section name :CONST_PBCFG_NO_INIT_PTR*/
#elif defined RTE_START_SEC_CONST_PBCFG_NO_INIT_PTR
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_NO_INIT_PTR_NO_MATCH
#define START_SEC_CONST_PBCFG_NO_INIT_PTR

#elif defined RTE_STOP_SEC_CONST_PBCFG_NO_INIT_PTR
#undef RTE_STOP_SEC_CONST_PBCFG_NO_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_NO_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_NO_INIT_PTR

/*Index:207  Section name :CONST_PBCFG_NO_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_NO_INIT_UNSPECIFIED

/*Index:208  Section name :CONST_PBCFG_CLEARED_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_PBCFG_CLEARED_BOOLEAN
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_CONST_PBCFG_CLEARED_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_PBCFG_CLEARED_BOOLEAN
#undef RTE_STOP_SEC_CONST_PBCFG_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_CLEARED_BOOLEAN

/*Index:209  Section name :CONST_PBCFG_CLEARED_8*/
#elif defined RTE_START_SEC_CONST_PBCFG_CLEARED_8
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_CLEARED_8_NO_MATCH
#define START_SEC_CONST_PBCFG_CLEARED_8

#elif defined RTE_STOP_SEC_CONST_PBCFG_CLEARED_8
#undef RTE_STOP_SEC_CONST_PBCFG_CLEARED_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_CLEARED_8_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_CLEARED_8

/*Index:210  Section name :CONST_PBCFG_CLEARED_16*/
#elif defined RTE_START_SEC_CONST_PBCFG_CLEARED_16
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_CLEARED_16_NO_MATCH
#define START_SEC_CONST_PBCFG_CLEARED_16

#elif defined RTE_STOP_SEC_CONST_PBCFG_CLEARED_16
#undef RTE_STOP_SEC_CONST_PBCFG_CLEARED_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_CLEARED_16_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_CLEARED_16

/*Index:211  Section name :CONST_PBCFG_CLEARED_32*/
#elif defined RTE_START_SEC_CONST_PBCFG_CLEARED_32
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_CLEARED_32_NO_MATCH
#define START_SEC_CONST_PBCFG_CLEARED_32

#elif defined RTE_STOP_SEC_CONST_PBCFG_CLEARED_32
#undef RTE_STOP_SEC_CONST_PBCFG_CLEARED_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_CLEARED_32_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_CLEARED_32

/*Index:212  Section name :CONST_PBCFG_CLEARED_PTR*/
#elif defined RTE_START_SEC_CONST_PBCFG_CLEARED_PTR
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_CLEARED_PTR_NO_MATCH
#define START_SEC_CONST_PBCFG_CLEARED_PTR

#elif defined RTE_STOP_SEC_CONST_PBCFG_CLEARED_PTR
#undef RTE_STOP_SEC_CONST_PBCFG_CLEARED_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_CLEARED_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_CLEARED_PTR

/*Index:213  Section name :CONST_PBCFG_CLEARED_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_CLEARED_UNSPECIFIED

/*Index:214  Section name :CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_BOOLEAN

/*Index:215  Section name :CONST_PBCFG_POWER_ON_CLEAR_8*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_8
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_8_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_CLEAR_8

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_8
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_8_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_8

/*Index:216  Section name :CONST_PBCFG_POWER_ON_CLEAR_16*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_16
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_16_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_CLEAR_16

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_16
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_16_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_16

/*Index:217  Section name :CONST_PBCFG_POWER_ON_CLEAR_32*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_32
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_32_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_CLEAR_32

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_32
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_32_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_32

/*Index:218  Section name :CONST_PBCFG_POWER_ON_CLEAR_PTR*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_PTR

/*Index:219  Section name :CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_CLEAR_UNSPECIFIED

/*Index:220  Section name :CONST_PBCFG_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_PBCFG_INIT_BOOLEAN
#undef RTE_START_SEC_CONST_PBCFG_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONST_PBCFG_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_PBCFG_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONST_PBCFG_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_INIT_BOOLEAN

/*Index:221  Section name :CONST_PBCFG_INIT_8*/
#elif defined RTE_START_SEC_CONST_PBCFG_INIT_8
#undef RTE_START_SEC_CONST_PBCFG_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_INIT_8_NO_MATCH
#define START_SEC_CONST_PBCFG_INIT_8

#elif defined RTE_STOP_SEC_CONST_PBCFG_INIT_8
#undef RTE_STOP_SEC_CONST_PBCFG_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_INIT_8

/*Index:222  Section name :CONST_PBCFG_INIT_16*/
#elif defined RTE_START_SEC_CONST_PBCFG_INIT_16
#undef RTE_START_SEC_CONST_PBCFG_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_INIT_16_NO_MATCH
#define START_SEC_CONST_PBCFG_INIT_16

#elif defined RTE_STOP_SEC_CONST_PBCFG_INIT_16
#undef RTE_STOP_SEC_CONST_PBCFG_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_INIT_16

/*Index:223  Section name :CONST_PBCFG_INIT_32*/
#elif defined RTE_START_SEC_CONST_PBCFG_INIT_32
#undef RTE_START_SEC_CONST_PBCFG_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_INIT_32_NO_MATCH
#define START_SEC_CONST_PBCFG_INIT_32

#elif defined RTE_STOP_SEC_CONST_PBCFG_INIT_32
#undef RTE_STOP_SEC_CONST_PBCFG_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_INIT_32

/*Index:224  Section name :CONST_PBCFG_INIT_PTR*/
#elif defined RTE_START_SEC_CONST_PBCFG_INIT_PTR
#undef RTE_START_SEC_CONST_PBCFG_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_INIT_PTR_NO_MATCH
#define START_SEC_CONST_PBCFG_INIT_PTR

#elif defined RTE_STOP_SEC_CONST_PBCFG_INIT_PTR
#undef RTE_STOP_SEC_CONST_PBCFG_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_INIT_PTR

/*Index:225  Section name :CONST_PBCFG_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_PBCFG_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONST_PBCFG_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_PBCFG_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_PBCFG_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_PBCFG_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_INIT_UNSPECIFIED

/*Index:226  Section name :CONST_PBCFG_POWER_ON_INIT_BOOLEAN*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_INIT_BOOLEAN

/*Index:227  Section name :CONST_PBCFG_POWER_ON_INIT_8*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_8
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_8_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_INIT_8

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_8
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_8_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_INIT_8

/*Index:228  Section name :CONST_PBCFG_POWER_ON_INIT_16*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_16
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_16_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_INIT_16

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_16
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_16
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_16_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_16_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_INIT_16

/*Index:229  Section name :CONST_PBCFG_POWER_ON_INIT_32*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_32
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_32_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_INIT_32

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_32
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_32
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_32_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_32_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_INIT_32

/*Index:230  Section name :CONST_PBCFG_POWER_ON_INIT_PTR*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_PTR
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_PTR_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_INIT_PTR

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_PTR
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_PTR_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_PTR_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_INIT_PTR

/*Index:231  Section name :CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_PBCFG_POWER_ON_INIT_UNSPECIFIED

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "Rte_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
