/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     Adc_Version.h                                                                             *
 *  \brief    This file contains Adc driver version information                                         *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ADC_VERSION_H
#define ADC_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif
/**
 *  \addtogroup MCAL_ADC_MACRO Adc Macro.
 *
 * This files defines ADC MCAL macros.
 *  \{
 */

/**
 *  \name Adc Driver Module SW Version Info
 *
 *  Defines for ADC Driver version used for compatibility checks
 *  \{
 */

/*****************************************************************************
*                      AUTOSAR VERSION CHECK                                 *
******************************************************************************/
#ifdef ADC_MODULE_ID /* to prevent double declaration */
#  error ADC_MODULE_ID already defined
#else
#  define ADC_MODULE_ID 123U
#endif /* ifdef ADC_MODULE_ID) */


#ifdef ADC_VENDOR_ID /* to prevent double declaration */
#  error ADC_VENDOR_ID is already defined
#else
#  define ADC_VENDOR_ID  (0x8c)
#endif /* ifdef ADC_VENDOR_ID */

#ifdef ADC_INSTANCE_ID /* to prevent double declaration */
#  error ADC_INSTANCE_ID is already defined
#else
#  define ADC_INSTANCE_ID 0U
#endif /* ifdef ADC_VENDOR_ID */
/** \} */
/** \} */
/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef ADC_SW_MAJOR_VERSION
#error "ADC_SW_MAJOR_VERSION is not defined."
#endif

#ifndef ADC_SW_MINOR_VERSION
#error "ADC_SW_MINOR_VERSION is not defined."
#endif

#ifndef ADC_SW_PATCH_VERSION
#error "ADC_SW_PATCH_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef ADC_AR_RELEASE_MAJOR_VERSION
#error "ADC_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef ADC_AR_RELEASE_MINOR_VERSION
#error "ADC_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef ADC_AR_RELEASE_REVISION_VERSION
#error "ADC_AR_RELEASE_REVISION_VERSION is not defined."
#endif

/** \brief  AUTOSAR Major and Minor release version check. */
#if(ADC_AR_RELEASE_MAJOR_VERSION != 4U)
#error "ADC_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(ADC_AR_RELEASE_MINOR_VERSION != 3U)
#error "ADC_AR_RELEASE_MINOR_VERSION does not match."
#endif

#if(ADC_AR_RELEASE_REVISION_VERSION != 1U)
#error "ADC_AR_RELEASE_REVISION_VERSION does not match."
#endif

#ifdef __cplusplus
}
#endif
#endif /* ADC_VERSION_H */
/* End of file */

