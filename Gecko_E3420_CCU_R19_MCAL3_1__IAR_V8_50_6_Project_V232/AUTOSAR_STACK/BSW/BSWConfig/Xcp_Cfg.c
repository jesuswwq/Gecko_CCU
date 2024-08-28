/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Xcp_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-10-18 15:44:16>
 */
/*============================================================================*/

#include "Xcp.h"
/*
 *  GetId CMD Config
 */
#define XCP_START_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"
static CONST(uint8, XCP_CONST_PBCFG) IdInfo1[5] = {"test"};
#define XCP_STOP_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_IdInfoType, XCP_CONST_PBCFG) Xcp_IdInfo[XCP_NUM_OF_ID] =
{
    {
        1, 0, sizeof(IdInfo1), &IdInfo1[0]
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(XcpDtoType, XCP_CONST_PBCFG) Xcp_Dto[4] =
{
    {
        0,/*XcpFirstPid*/
        &Xcp_Daq_Pdu[0] /*XcpDto2PduMapping*/
    },
    {
        0,/*XcpFirstPid*/
        &Xcp_Daq_Pdu[1] /*XcpDto2PduMapping*/
    },
    {
        0,/*XcpFirstPid*/
        &Xcp_Daq_Pdu[2] /*XcpDto2PduMapping*/
    },
    {
        0,/*XcpFirstPid*/
        &Xcp_Daq_Pdu[3] /*XcpDto2PduMapping*/
    },
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_DaqListConfigType, XCP_CONST_PBCFG) Xcp_DaqConfig[XCP_MAX_DAQ] =
{
    {
        0,/*XcpDaqListNumber*/
        DAQ, /* XcpDaqListtype */
        0,  /* XcpDaqSize */
        &Xcp_Dto[0],  /* XcpDto */
        NULL_PTR   /* XcpOdt */
    },
    {
        1,/*XcpDaqListNumber*/
        DAQ, /* XcpDaqListtype */
        0,  /* XcpDaqSize */
        &Xcp_Dto[1],  /* XcpDto */
        NULL_PTR   /* XcpOdt */
    },
    {
        2,/*XcpDaqListNumber*/
        DAQ, /* XcpDaqListtype */
        0,  /* XcpDaqSize */
        &Xcp_Dto[2],  /* XcpDto */
        NULL_PTR   /* XcpOdt */
    },
    {
        3,/*XcpDaqListNumber*/
        DAQ, /* XcpDaqListtype */
        0,  /* XcpDaqSize */
        &Xcp_Dto[3],  /* XcpDto */
        NULL_PTR   /* XcpOdt */
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
static VAR(Xcp_AGType, XCP_VAR) Xcp_EvCh0Buffer[XCP_EVCHBUFFER_0_DEPTH];
static VAR(Xcp_AGType, XCP_VAR) Xcp_EvCh1Buffer[XCP_EVCHBUFFER_1_DEPTH];
static VAR(Xcp_AGType, XCP_VAR) Xcp_EvCh2Buffer[XCP_EVCHBUFFER_2_DEPTH];
static VAR(Xcp_AGType, XCP_VAR) Xcp_EvCh3Buffer[XCP_EVCHBUFFER_3_DEPTH];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"
static CONST(uint8, XCP_CONST_PBCFG) Xcp_Evch_0[MAX_EVCH_NAME_LENGTH] = { "EventChannel_0" };
static CONST(uint8, XCP_CONST_PBCFG) Xcp_Evch_1[MAX_EVCH_NAME_LENGTH] = { "EventChannel_1" };
static CONST(uint8, XCP_CONST_PBCFG) Xcp_Evch_2[MAX_EVCH_NAME_LENGTH] = { "EventChannel_2" };
static CONST(uint8, XCP_CONST_PBCFG) Xcp_Evch_3[MAX_EVCH_NAME_LENGTH] = { "EventChannel_3" };
#define XCP_STOP_SEC_CONFIG_DATA_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_16
#include "Xcp_MemMap.h"
static CONST(Xcp_DaqNumType, XCP_CONST_PBCFG) Xcp_EvCh0DaqList[4] = {0, 1, 2, 3 };
static CONST(Xcp_DaqNumType, XCP_CONST_PBCFG) Xcp_EvCh1DaqList[4] = {0, 1, 2, 3 };
static CONST(Xcp_DaqNumType, XCP_CONST_PBCFG) Xcp_EvCh2DaqList[4] = {0, 1, 2, 3 };
static CONST(Xcp_DaqNumType, XCP_CONST_PBCFG) Xcp_EvCh3DaqList[4] = {0, 1, 2, 3 };
#define XCP_STOP_SEC_CONFIG_DATA_16
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_EvChConfigType, XCP_CONST_PBCFG) Xcp_EvChConfig[XCP_MAX_EVENT_CHANNEL] =
{
    {
        Xcp_Evch_0,
        sizeof(Xcp_Evch_0),
        XCP_EVENT_CONSIST_ODT,
        4, /*XcpEvChMaxDaqList*/
        0,/*XcpEvChNumber*/
        0,/*XcpEvChPriority*/
        1,/*XcpEvChTimeCycle*/
        TIMESTAMP_UNIT_10MS,/*XcpEvChTimeUnit*/
        DAQ,/*XcpEvChType*/
        XCP_EVCHBUFFER_0_DEPTH,
        &Xcp_EvCh0Buffer[0],
        &Xcp_EvCh0DaqList[0]
    },
    {
        Xcp_Evch_1,
        sizeof(Xcp_Evch_1),
        XCP_EVENT_CONSIST_ODT,
        4, /*XcpEvChMaxDaqList*/
        1,/*XcpEvChNumber*/
        0,/*XcpEvChPriority*/
        2,/*XcpEvChTimeCycle*/
        TIMESTAMP_UNIT_10MS,/*XcpEvChTimeUnit*/
        DAQ,/*XcpEvChType*/
        XCP_EVCHBUFFER_1_DEPTH,
        &Xcp_EvCh1Buffer[0],
        &Xcp_EvCh1DaqList[0]
    },
    {
        Xcp_Evch_2,
        sizeof(Xcp_Evch_2),
        XCP_EVENT_CONSIST_ODT,
        4, /*XcpEvChMaxDaqList*/
        2,/*XcpEvChNumber*/
        0,/*XcpEvChPriority*/
        5,/*XcpEvChTimeCycle*/
        TIMESTAMP_UNIT_10MS,/*XcpEvChTimeUnit*/
        DAQ,/*XcpEvChType*/
        XCP_EVCHBUFFER_2_DEPTH,
        &Xcp_EvCh2Buffer[0],
        &Xcp_EvCh2DaqList[0]
    },
    {
        Xcp_Evch_3,
        sizeof(Xcp_Evch_3),
        XCP_EVENT_CONSIST_ODT,
        4, /*XcpEvChMaxDaqList*/
        3,/*XcpEvChNumber*/
        0,/*XcpEvChPriority*/
        1,/*XcpEvChTimeCycle*/
        TIMESTAMP_UNIT_100MS,/*XcpEvChTimeUnit*/
        DAQ,/*XcpEvChType*/
        XCP_EVCHBUFFER_3_DEPTH,
        &Xcp_EvCh3Buffer[0],
        &Xcp_EvCh3DaqList[0]
    }
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
static VAR(uint8, XCP_VAR) Xcp_PageBuffer0[XCP_PAGE_BUF0_SIZE];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_32
#include "Xcp_MemMap.h"
CONST(uint32, XCP_CONST) Xcp_MeaStartAddr = 0x5C0000; /* PRQA S 1533 */ /* MISRA Rule 8.9 */
CONST(uint32, XCP_CONST) Xcp_MeaLen = 0x10000; /* PRQA S 1533 */ /* MISRA Rule 8.9 */
#define XCP_STOP_SEC_CONFIG_DATA_32
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
static CONST(Xcp_PageInfoType, XCP_CONST_PBCFG) Xcp_PageInfo[XCP_MAX_SEGMENT] =
{
    {
        0x30000,
        0x5d0000,
        0x5fffff,
#ifdef REMAP_USED 
        0x3d0000,
        0x3fffff,
#else
        0x10510000u,
        0x1053ffffu,
#endif
        (uint32)Xcp_PageBuffer0, /* PRQA S 0306 */ /* MISRA Rule 11.4 */
    }
};

CONST(Xcp_SegmentInfoType,XCP_CONST_PBCFG) Xcp_SegmentInfo =
{
    XCP_MAX_SEGMENT,
    Xcp_PageInfo,
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
CONST(Xcp_PCConfigType, XCP_CONST_PBCFG) Xcp_PConfig = /* PRQA S 1533 */ /* MISRA Rule 8.9 */
{
    &Xcp_DaqConfig[0],
    &Xcp_EvChConfig[0],
    XCP_NUM_OF_ID,
    &Xcp_IdInfo[0]
};
#define XCP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Xcp_MemMap.h"
