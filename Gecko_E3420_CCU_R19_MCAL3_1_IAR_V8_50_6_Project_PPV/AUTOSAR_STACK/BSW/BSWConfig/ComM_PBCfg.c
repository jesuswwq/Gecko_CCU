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
 *  @file               : ComM_PBCfg.c
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2024/05/11 13:20:39
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic R19-11
 *
 */

/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"
#include "ComM_PBCfg.h"
#include "CanSM.h"
#include "LinSM.h"
/*==========================================[external function definitions]===========================================*/
BEGIN_C_DECLS
/*=================================================[internal data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserDirectMapChanelTable[9] = {0u,1u,2u,3u,4u,5u,6u,7u,8u};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserMapAllChanelTable[9] = {
    0u,1u,2u,3u,4u,5u,6u,7u,8u
};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserInChanelIdexTable[9] = {0u,0u,0u,0u,0u,0u,0u,0u,0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_UserConfigType, COMM_CONST) ComM_UserCfg[COMM_USER_NUMBER] = {
    /* ComMUser_CANFD3 */
    {
        0u,/*userId*/
        &ComM_UserDirectMapChanelTable[0],/*directChList*/
        1u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[0],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[0],/*userInChIdex*/
    },
    /* ComMUser_CANFD4 */
    {
        1u,/*userId*/
        &ComM_UserDirectMapChanelTable[1],/*directChList*/
        1u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[1],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[1],/*userInChIdex*/
    },
    /* ComMUser_CANFD5 */
    {
        2u,/*userId*/
        &ComM_UserDirectMapChanelTable[2],/*directChList*/
        1u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[2],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[2],/*userInChIdex*/
    },
    /* ComMUser_CANFD6 */
    {
        3u,/*userId*/
        &ComM_UserDirectMapChanelTable[3],/*directChList*/
        1u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[3],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[3],/*userInChIdex*/
    },
    /* ComMUser_CANFD7 */
    {
        4u,/*userId*/
        &ComM_UserDirectMapChanelTable[4],/*directChList*/
        1u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[4],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[4],/*userInChIdex*/
    },
    /* ComMUser_CANFD8 */
    {
        5u,/*userId*/
        &ComM_UserDirectMapChanelTable[5],/*directChList*/
        1u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[5],/*mapAllChList*/
        1u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[5],/*userInChIdex*/
    },
    /* ComMUser_CCU_LIN1 */
    {
        6u,/*userId*/
        &ComM_UserDirectMapChanelTable[6],/*directChList*/
        3u,/*directChListNum*/
        &ComM_UserMapAllChanelTable[6],/*mapAllChList*/
        3u,/*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[6],/*userInChIdex*/
    },
    /* ComMUser_CCU_LIN2 */
    {
        7u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        NULL_PTR,/*mapAllChList*/
        0u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
    },
    /* ComMUser_CCU_LIN3 */
    {
        8u,/*userId*/
        NULL_PTR,/*directChList*/
        0u,/*directChListNum*/
        NULL_PTR,/*mapAllChList*/
        0u,/*mapAllChListNum*/
        NULL_PTR,/*userInChIdex*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_BusSmConfigType, COMM_CONST) ComM_BusSmCfgTable[2] = {
    {
        CanSM_RequestComMode,/*busSm_RequestComMode*/
        CanSM_GetCurrentComMode /*busSm_GetCurrentComMode*/
    },
    {
        LinSM_RequestComMode,/*busSm_RequestComMode*/
        LinSM_GetCurrentComMode /*busSm_GetCurrentComMode*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
#define COMM_START_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CANFD3[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CANFD4[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CANFD5[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CANFD6[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CANFD7[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CANFD8[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_ComMChannel_CCU_LIN1[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_ComMChannel_CCU_LIN2[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_ComMChannel_CCU_LIN3[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_DcmNotifyId[2]={0x4u,0x5u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_ChannelConfigType, COMM_CONST) ComM_ChannelConfig[COMM_CHANNEL_NUMBER] = {
    /* Channel_CANFD3 */
    {
        0u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        0u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_FULL,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        NULL_PTR,/*dcmNotifyIdPtr*/
        0x0u,/*nmLightTimeout*/
        0u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_Channel_CANFD3[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* Channel_CANFD4 */
    {
        1u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        1u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_LIGHT,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        NULL_PTR,/*dcmNotifyIdPtr*/
        0x64u,/*nmLightTimeout*/
        1u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_Channel_CANFD4[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* Channel_CANFD5 */
    {
        2u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        2u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_FULL,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        NULL_PTR,/*dcmNotifyIdPtr*/
        0x0u,/*nmLightTimeout*/
        2u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_Channel_CANFD5[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* Channel_CANFD6 */
    {
        3u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        3u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_FULL,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        NULL_PTR,/*dcmNotifyIdPtr*/
        0x0u,/*nmLightTimeout*/
        3u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_Channel_CANFD6[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* Channel_CANFD7 */
    {
        4u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        4u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_LIGHT,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        &ComM_DcmNotifyId[0],/*dcmNotifyIdPtr*/
        0x64u,/*nmLightTimeout*/
        4u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_Channel_CANFD7[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* Channel_CANFD8 */
    {
        5u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        5u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_FULL,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        &ComM_DcmNotifyId[1],/*dcmNotifyIdPtr*/
        0x0u,/*nmLightTimeout*/
        5u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_Channel_CANFD8[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* ComMChannel_CCU_LIN1 */
    {
        6u,/*inerChIdx*/
        COMM_BUS_TYPE_LIN,/*busType*/
        6u,/*busIndex*/
        &ComM_BusSmCfgTable[1],/*busSmCfgType*/
        COMM_NM_VARIANT_LIGHT,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        NULL_PTR,/*dcmNotifyIdPtr*/
        0xc8u,/*nmLightTimeout*/
        6u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_ComMChannel_CCU_LIN1[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* ComMChannel_CCU_LIN2 */
    {
        7u,/*inerChIdx*/
        COMM_BUS_TYPE_LIN,/*busType*/
        7u,/*busIndex*/
        &ComM_BusSmCfgTable[1],/*busSmCfgType*/
        COMM_NM_VARIANT_LIGHT,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        NULL_PTR,/*dcmNotifyIdPtr*/
        0xc8u,/*nmLightTimeout*/
        7u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_ComMChannel_CCU_LIN2[0],/*requestMask*/
        1u /*requestMaskLen*/
    },
    /* ComMChannel_CCU_LIN3 */
    {
        8u,/*inerChIdx*/
        COMM_BUS_TYPE_LIN,/*busType*/
        8u,/*busIndex*/
        &ComM_BusSmCfgTable[1],/*busSmCfgType*/
        COMM_NM_VARIANT_LIGHT,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        NULL_PTR,/*dcmNotifyIdPtr*/
        0xc8u,/*nmLightTimeout*/
        8u,/*netifId*/
        {0x0},/*cfgMask*/
        500u,/*tMinFullComDuration*/
        &ComM_ReqMaskBuf_ComMChannel_CCU_LIN3[0],/*requestMask*/
        1u /*requestMaskLen*/
    }
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

/*=================================================[external data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
CONST(ComM_ConfigType, COMM_CONST) ComM_Config = {  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
    ComM_ChannelConfig,/*chCfgPtr*/
    COMM_CHANNEL_NUMBER,/*chCfgNum*/
    ComM_UserCfg,/*userCfgPtr*/
    COMM_USER_NUMBER,/*userCfgNum*/
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
END_C_DECLS

