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
**  FILENAME    : EcuM_PbCfg.c                                                **
**                                                                            **
**  Created on  : 2023/11/27 10:51:30                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :  Configuration constant variables for pre-compile           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "Dem.h"
#include "Port.h"
#include "Adc.h"
#include "Can.h"
#include "Lin.h"
#include "CanIf.h"
#include "LinIf.h"
#include "CanSM.h"
#include "LinSM.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "Xcp.h"
#include "CanNm.h"
#include "Nm.h"
#include "Ea.h"
#include "NvM.h"
#include "CanTp.h"
#include "Dcm.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"
static CONST(EcuM_GenBSWPbCfgType, ECUM_VAR_NO_INIT) EcuM_GenMcalConfig =
{
    NULL_PTR, /*bswmPbCfg*/
    (const void *)&Port_Cfg,
    (const void *)&Adc_Config,
    (const void *)&Can_Config,
    (const void *)&LinGlobalConfig,
    (const void *)&CanIf_InitCfgSet,
    (const void *)&LinIf_PCConfig,
    (const void *)&CanSM_Config,
    (const void *)&LinSM_PCConfig,
    (const void *)&PduR_PBConfigData,
    (const void *)&Com_PBConfigData,
    (const void *)&ComM_Config,
    (const void *)&Xcp_PBConfig,
    (const void *)&CanNm_Config,
    (const void *)&Nm_Config,
    (const void *)&Ea_Config,
    NULL_PTR,
    (const void *)&CanTp_Config,
    (const void *)&Dcm_Cfg,
};
CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config =
{
    255,    /*EcuMConfigConsistencyHash*/
    OSDEFAULTAPPMODE,    /*EcuMDefaultAppMode*/
    ECUM_SHUTDOWN_TARGET_OFF,
    0,
    &EcuM_GenMcalConfig
};
#define ECUM_STOP_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

