
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
**  FILENAME    : Det_Cfg.c                                                   **
**                                                                            **
**  Created on  : 2023-08-29 10:41:31                                         **
**  Author      : ShaoHaiBin                                                  **
**  Vendor      : isoft                                                       **
**  DESCRIPTION : Implementation for Det                                      **
**                                                                            **
**  SPECIFICATION(S) :            **                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************    
** Configuration description :    
** All configurations of the DET module are not dependent on tool generation,    
** and all configuration items are fixed    
*******************************************************************************/

/*******************************************************************************
**                       Version  information                                 **
*******************************************************************************/
#define DET_CFG_C_AR_MAJOR_VERSION   4U
#define DET_CFG_C_AR_MINOR_VERSION   5U
#define DET_CFG_C_AR_PATCH_VERSION   0U
#define DET_CFG_C_SW_MAJOR_VERSION   1U
#define DET_CFG_C_SW_MINOR_VERSION   0U
#define DET_CFG_C_SW_PATCH_VERSION   0U

/*==============================================================================    
*                                        INCLUDE FILES    
* 1) system and project includes    
* 2) needed interfaces from external units    
* 3) internal and external interfaces from this unit    
==============================================================================*/
#include "Det_Types.h"
#include "Det_Cfg.h"
#include "Det_Externals.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (DET_CFG_C_AR_MAJOR_VERSION != DET_CFG_H_AR_MAJOR_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif
#if (DET_CFG_C_AR_MINOR_VERSION != DET_CFG_H_AR_MINOR_VERSION)
#error "Det.c : Mismatch in Specification _MINOR Version"
#endif
#if (DET_CFG_C_AR_PATCH_VERSION != DET_CFG_H_AR_PATCH_VERSION)
#error "Det.c : Mismatch in Specification PATCH Version"
#endif
#if (DET_CFG_C_SW_MAJOR_VERSION != DET_CFG_H_SW_MAJOR_VERSION)
#error "Det.c : Mismatch in Software Major Version"
#endif
#if (DET_CFG_C_SW_MINOR_VERSION != DET_CFG_H_SW_MINOR_VERSION)
#error "Det.c : Mismatch in Software MINOR Version"
#endif
#if (DET_CFG_C_SW_PATCH_VERSION != DET_CFG_H_SW_PATCH_VERSION)
#error "Det.c : Mismatch in Software PATCH Version"
#endif

/*******************************************************************************    
**                      Imported Compiler Switch Check                        **    
*******************************************************************************/    

/*******************************************************************************    
**                      Private Macro Definitions                             **    
*******************************************************************************/    

/*******************************************************************************    
**                      Private Type Definitions                              **    
*******************************************************************************/    

/*******************************************************************************    
**                      Private Function Declarations                         **    
*******************************************************************************/    

/*******************************************************************************    
**                      Global Constant Definitions                           **    
*******************************************************************************/    

#define DET_START_SEC_CONST_UNSPECIFIED
#include "Det_MemMap.h"

CONST(Det_ConfigType, DET_CONST) Det_Config =
{
    0u,
    /* This container describes a non BSW module that is using the Det via Service Interface. */
    NULL_PTR
};

#define DET_STOP_SEC_CONST_UNSPECIFIED
#include "Det_MemMap.h"
