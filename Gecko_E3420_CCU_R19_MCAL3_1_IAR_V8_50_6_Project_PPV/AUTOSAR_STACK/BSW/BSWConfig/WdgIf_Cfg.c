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
**  FILENAME    : WdgIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/01/29 18:01:40                                         **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of WdgIf                 **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGIF_CFG_C_AR_MAJOR_VERSION  3U
#define WDGIF_CFG_C_AR_MINOR_VERSION  0U
#define WDGIF_CFG_C_AR_PATCH_VERSION  3U
#define WDGIF_CFG_C_SW_MAJOR_VERSION  1U
#define WDGIF_CFG_C_SW_MINOR_VERSION  0U
#define WDGIF_CFG_C_SW_PATCH_VERSION  0U

/*===========================[I N C L U D E S]====================================================*/
#include "WdgIf.h"
#include "WdgIf_Cfg.h"

/*===========================[V E R S I O N  C H E C K]===========================================*/
#if (WDGIF_CFG_C_AR_MAJOR_VERSION != WDGIF_CFG_H_AR_MAJOR_VERSION)
    #error "WdgIf_Cfg.c:Mismatch in Specification Major Version"
#endif /* WDGIF_CFG_C_AR_MAJOR_VERSION != WDGIF_CFG_H_AR_MAJOR_VERSION */
#if (WDGIF_CFG_C_AR_MINOR_VERSION != WDGIF_CFG_H_AR_MINOR_VERSION)
    #error "WdgIf_Cfg.c:Mismatch in Specification Minor Version"
#endif /* WDGIF_CFG_C_AR_MINOR_VERSION != WDGIF_H_AR_MINOR_VERSION */
#if (WDGIF_CFG_C_AR_PATCH_VERSION != WDGIF_CFG_H_AR_PATCH_VERSION)
    #error "WdgIf_Cfg.c:Mismatch in Specification Patch Version"
#endif /* WDGIF_CFG_C_AR_PATCH_VERSION != WDGIF_CFG_H_AR_PATCH_VERSION */
#if (WDGIF_CFG_C_SW_MAJOR_VERSION != WDGIF_CFG_H_SW_MAJOR_VERSION)
    #error "WdgIf_Cfg.c:Mismatch in Specification Major Version"
#endif /* WDGIF_CFG_C_SW_MAJOR_VERSION != WDGIF_CFG_H_SW_MAJOR_VERSION */
#if (WDGIF_CFG_C_SW_MINOR_VERSION != WDGIF_CFG_H_SW_MINOR_VERSION)
    #error "WdgIf_Cfg.c:Mismatch in Specification Minor Version"
#endif /* WDGIF_CFG_C_SW_MINOR_VERSION != WDGIF_CFG_H_SW_MINOR_VERSION */

/*===========================[M A C R O S]========================================================*/
/*===========================[T Y P E   D E F I N I T I O N S]====================================*/
/*===========================[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
/*===========================[I N T E R N A L   D A T A]==========================================*/
/*===========================[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
/*===========================[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/

/*===========================[E N D   O F   F I L E]==============================================*/
