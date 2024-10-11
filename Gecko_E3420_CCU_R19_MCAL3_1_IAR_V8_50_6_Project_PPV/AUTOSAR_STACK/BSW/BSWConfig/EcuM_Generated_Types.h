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
**  FILENAME    : EcuM_Generated_Types.h                                      **
**                                                                            **
**  Created on  : 2023/09/19 14:21:33                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION :  contains generated type declarations that fulfill the      **
**                 forward declarations in EcuM.h                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define ECUM_WKSOURCE(sourceId) (uint32)((uint32)0x01u << (sourceId))
#define EcuMWakeupSource_EPT     ECUM_WKSOURCE(5)
#define EcuMWakeupSource_CHA     ECUM_WKSOURCE(6)
#define EcuMWakeupSource_BAC     ECUM_WKSOURCE(7)
#define EcuMWakeupSource_BOD     ECUM_WKSOURCE(8)
#define EcuMWakeupSource_LIN     ECUM_WKSOURCE(9)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*********************Generated Configuration Types***************************/
typedef struct
{
    P2CONST(void, TYPEDEF, ECUM_APPL_DATA) bswMPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) portPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) adcPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) linPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canIfPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) linIfPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canSmPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) linSMPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) pduRPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) comPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) comMPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) xcpPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canNmPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) nmPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) eaPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) nvmPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canTpPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) dcmPbCfg;
} EcuM_GenBSWPbCfgType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* ECUM_GENERATED_TYPES_H */
