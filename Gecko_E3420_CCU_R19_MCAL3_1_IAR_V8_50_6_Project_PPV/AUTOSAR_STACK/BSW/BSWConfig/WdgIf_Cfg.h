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
**  FILENAME    : WdgIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/01/29 18:01:40                                         **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of WdgM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGIF_CFG_H_AR_MAJOR_VERSION  3U
#define WDGIF_CFG_H_AR_MINOR_VERSION  0U
#define WDGIF_CFG_H_AR_PATCH_VERSION  3U
#define WDGIF_CFG_H_SW_MAJOR_VERSION  1U
#define WDGIF_CFG_H_SW_MINOR_VERSION  0U
#define WDGIF_CFG_H_SW_PATCH_VERSION  0U

/*===========================[I N C L U D E S]====================================================*/
#include "Wdg_140_Instance1_Wdt.h"

/*===========================[M A C R O S]========================================================*/
/*
** Variants Class (PC, PB and LT)
*/
#define WDGIF_VARIANT_PC          VARIANT_PRE_COMPILE
#define WDGIF_VARIANT_PB          VARIANT_POST_BUILD
#define WDGIF_VARIANT_LT          VARIANT_LINK_TIME
#define WDGIF_VARIANT_CFG         WDGIF_VARIANT_PC /* Only (PC)Variant can be used */

/*
** WdgIfGeneral
*/
/* Compile switch to enable or disable development error tracer for this module */
#define WDGIF_DEV_ERROR_DETECT       STD_ON
/* Compile switch to enable or disable the version information API */
#define WDGIF_VERSION_INFO_API        STD_OFF
/* Constant specifying the number of controlled watchdog drivers */
#define WDGIF_NUMBER_OF_DEVICES       (1)

/*
** WdgIfDevice
*/
#define     WdgIfInternalDevice_0            0

#define WdgIf_SetTriggerCondition_Map(timeout)          Wdg_140_Instance1_Wdt_SetTriggerCondition(timeout)
#define WdgIf_SetMode_Map(mode)                         Wdg_140_Instance1_Wdt_SetMode(mode)

/*===========================[T Y P E   D E F I N I T I O N S]====================================*/
/*===========================[C O N F I G  T Y P E   D E F I N I T I O N S]=======================*/
/*===========================[E X T E R N A L   D A T A]==========================================*/
/*===========================[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

#endif /* #ifndef  WDGIF_CFG_H */
/*===========================[E N D   O F   F I L E]==============================================*/
