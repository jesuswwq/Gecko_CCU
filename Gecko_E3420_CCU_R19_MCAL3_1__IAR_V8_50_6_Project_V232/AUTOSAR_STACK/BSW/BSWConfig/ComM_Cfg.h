/**
 *
 * Copyright (C) iSOFT   (2022)
 *
 * All rights reserved.
 *
 * This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and
 * communication of its contents is not permitted without prior written authorization.
 *
 *
 *  @file               : ComM_Cfg.h
 *  @version            : V2.1.1
 *  @author             : darren.zhang
 *  @date               : 2024/01/09 14:45:59
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-11
 */

#ifndef COMM_CFG_H_
#define COMM_CFG_H_

/*------------------------------------------[generate version information]------------------------------------------- */
#if defined(COMM_CFG_MAJOR_VERSION)
#error COMM_CFG_MAJOR_VERSION already defined
#else
/** \brief AUTOSAR comm configuration major version */
#define COMM_CFG_MAJOR_VERSION                  2u
#endif /* defined(COMM_CFG_MAJOR_VERSION) */

#if defined(COMM_CFG_MINOR_VERSION)
#error COMM_CFG_MINOR_VERSION already defined
#else
/** \brief AUTOSAR comm configuration minor version */
#define COMM_CFG_MINOR_VERSION                  1u
#endif /* defined(COMM_SW_MINOR_VERSION) */

#if defined(COMM_CFG_PATCH_VERSION)
#error COMM_CFG_PATCH_VERSION already defined
#else
/** \brief AUTOSAR comm configuration patch version */
#define COMM_CFG_PATCH_VERSION                  7u
#endif /* defined(COMM_CFG_PATCH_VERSION) */

/*--------------------------------------------[normal configure]----------------------------------------------------- */
/** \brief avoids sending of 0-PNC-Vectors */
#define COMM_0PNC_VECTOR_AVOIDANCE              STD_OFF

/** \brief Enable/disable development error detection */
#define COMM_DEV_ERROR_DETECT                   STD_ON

/** \brief automatically user mapping */
#define COMM_DIRECT_USER_MAPPING                STD_OFF

/** \brief partial networking */
#define COMM_PNC_SUPPORT                        STD_OFF

/** \brief mode inhibition affects the ECU or not */
#define COMM_ECU_GROUP_CLASSIFICATION           3u

/** \brief mode limitation functionality */
#define COMM_MODE_LIMITATION_ENABLED            STD_OFF

/** \brief ComM shall perform a reset after entering "No Communication" mode because of an active mode limitation
 *  to "No Communication" mode. */
#define COMM_RESET_AFTER_FORCING_NOCOMM         STD_OFF

/** \brief Wake up of one channel shall lead to a wake up of all channels if true */
#define COMM_SYNC_WAKEUP                        STD_OFF

/** \brief Minimum time duration in seconds, spent in the COMM_FULL_COMMUNICATION sub-state
 * COMM_SPEC_FULL_COM_REQ */
#define COMM_TMIN_FULLCOMMODE_DURATION          50000u

/** \brief Enable/disable the version info API */
#define COMM_VERSION_INFO_API                   STD_ON

/** \brief ComMWakeupInhibitionEnabled */
#define COMM_WAKEUP_INHIBITION_ENABLED          STD_OFF

/** \brief Reference to NVRAM block containing the none volatile data */

/** \brief user mode switch Notification Rte configured */
#define COMM_USER_MODESWITCH_NOTIFY    STD_OFF
/** \brief channel full com request notify */
#define COMM_FULL_COMM_REQUEST_NOTIFY   STD_OFF
/* -------------------------------------associated to generate--------------------------------------------------------*/

/** \brief ComM callback api:ComM_BusSM_ModeIndication input parameter ComMode used tpye is data point */
#define COMM_BUSNM_MODEIND_PARAUSEDPTR           STD_OFF

#define COMM_USED_MODULE_NM                     STD_ON

#define COMM_DCM_INDICATION                     STD_ON

#define COMM_ECUM_ENABLE                       STD_ON

#define COMM_BSWM_ENABLE                       STD_ON

#define COMM_USED_MODULE_BUSSM                  STD_ON

#define COMM_PBCFG_SUPPORT_ENABLED              STD_ON

#if !defined(COMM_INITIALIZATION_AVAILABLE)
#define COMM_INITIALIZATION_AVAILABLE           STD_ON
#endif /* !defined(COMM_INITIALIZATION_AVAILABLE) */

#define COMM_NM_VARIANT_LIGHT_SUPPORT           STD_ON

#define COMM_MANAGED_CHANNEL_SUPPORT            STD_OFF

/* calculate form post build */
#define COMM_CHANNEL_NUMBER                     9u

#define COMM_PNC_NUMBER                         0u

#define COMM_USER_NUMBER                        9u

#define Channel_CANFD3                        0u
#define Channel_CANFD4                        1u
#define Channel_CANFD5                        2u
#define Channel_CANFD6                        3u
#define Channel_CANFD7                        4u
#define Channel_CANFD8                        5u
#define ComMChannel_CCU_LIN1                        6u
#define ComMChannel_CCU_LIN2                        7u
#define ComMChannel_CCU_LIN3                        8u

#define ComMUser_CANFD3                        0u
#define ComMUser_CANFD4                        1u
#define ComMUser_CANFD5                        2u
#define ComMUser_CANFD6                        3u
#define ComMUser_CANFD7                        4u
#define ComMUser_CANFD8                        5u
#define ComMUser_CCU_LIN1                        6u
#define ComMUser_CCU_LIN2                        7u
#define ComMUser_CCU_LIN3                        8u

#endif /* COMM_CFG_H_ */

