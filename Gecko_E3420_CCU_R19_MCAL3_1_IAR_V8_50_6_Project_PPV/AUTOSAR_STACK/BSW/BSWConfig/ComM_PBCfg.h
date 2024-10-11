
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
 *  @file               : ComM_PBCfg.h
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2023/11/22 13:07:41 
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic Platform R19-1
 *
 */

#ifndef COMM_PBCFG_H_
#define COMM_PBCFG_H_

/*=================================================[inclusions]=======================================================*/

#include "ComM_Types.h"
/*====================================================[macros]========================================================*/
BEGIN_C_DECLS
#if !defined(COMM_CONFIG_LOCAL)
#define COMM_CONFIG_LOCAL static
#endif /* !defined(COMM_LOCAL) */

/*=============================================[type definitions]=====================================================*/
/** \brief busSm type */
typedef struct {
    Std_ReturnType (*busSm_RequestComMode)(NetworkHandleType network, ComM_ModeType ComM_Mode);
    Std_ReturnType (*busSm_GetCurrentComMode)(NetworkHandleType network, ComM_ModeType* ComM_Mode);
} ComM_BusSmConfigType;
/** \brief user data type of a channel */
typedef struct {
    uint32 inerChIdx;
#define COMM_BUS_TYPE_CAN      0u
#define COMM_BUS_TYPE_LIN      5u
    uint32 busType;
    NetworkHandleType busIndex;
    const ComM_BusSmConfigType* busSmCfgType;
#define COMM_NM_VARIANT_FULL          0x01u
#define COMM_NM_VARIANT_LIGHT         0x02u
#define COMM_NM_VARIANT_NORMAL        0x3u
    uint8 nmVariant;
    uint8 dcmInReqIdx;
    const uint8* dcmNotifyIdPtr;
    uint32 nmLightTimeout;
    NetworkHandleType netifId;
    uint32 cfgMask[1];
    uint32 tMinFullComDuration;
    /* channel var */
    uint8* requestMask;
    uint8 requestMaskLen;
} ComM_ChannelConfigType;

/** \brief user data type */
typedef struct ComM_UserConfigSTag{
    ComM_UserHandleType userId;
    const uint8* directChList;
    uint32 directChListNum;
    const uint8* mapAllChList;
    uint32 mapAllChListNum;
    const uint8* userInChIdex;
} ComM_UserConfigType;
typedef struct {
    const ComM_ChannelConfigType* chCfgPtr;
    uint32 chCfgNum;
    const ComM_UserConfigType* userCfgPtr;
    uint32 userCfgNum;
}ComM_ConfigType;
/*========================================[external data declarations]============================================*/
extern CONST(ComM_ConfigType, COMM_CONST) ComM_Config;
END_C_DECLS
#endif /* COMM_PBCFG_H_ */

