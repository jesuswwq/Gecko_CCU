/** **************************************************************************************
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 * \file     Spi_PbCfg.c
 * \brief    AUTOSAR 4.3.1 MCAL can Driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2024-03-08 16:29:00     <td>1.0.0 R
 * </table>
 *****************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "cdefs.h"
#include "Compiler.h"
#include "Spi_PbCfg.h"
#include "Spi_Pin.h"
#include "Mcal.h"
/*****************************************************************************************
 *                   Global Macro definition
 *****************************************************************************************/
/** \brief  Spi UserCallback HeaderFile include */

#if (SPI_NO_CACHEABLE_NEEDED == STD_ON)
#define SPI_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

/* Channels params check */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                                                                                    
/* Global array for internal write buffers */
static VAR_ALIGN(uint8 Spi_IBWriteBuffer_SpiChannel_0[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_0,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint8 Spi_IBWriteBuffer_SpiChannel_1[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_1,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint8 Spi_IBWriteBuffer_SpiChannel_2[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_2,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint8 Spi_IBWriteBuffer_SpiChannel_3[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_3,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBWriteBuffer_SpiChannel_4[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_4,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBWriteBuffer_SpiChannel_5[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_5,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBWriteBuffer_SpiChannel_6[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_6,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBWriteBuffer_SpiChannel_7[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_7,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBWriteBuffer_SpiChannel_8[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_8,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBWriteBuffer_SpiChannel_9[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_9,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBWriteBuffer_SpiChannel_10[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_10,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBWriteBuffer_SpiChannel_11[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_11,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBWriteBuffer_SpiChannel_12[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_12,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBWriteBuffer_SpiChannel_13[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_13,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBWriteBuffer_SpiChannel_14[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_14,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
/* Global array for internal read buffers */
static VAR_ALIGN(uint8  Spi_IBReadBuffer_SpiChannel_0[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_0,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint8  Spi_IBReadBuffer_SpiChannel_1[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_1,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint8  Spi_IBReadBuffer_SpiChannel_2[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_2,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint8  Spi_IBReadBuffer_SpiChannel_3[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_3,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBReadBuffer_SpiChannel_4[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_4,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBReadBuffer_SpiChannel_5[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_5,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBReadBuffer_SpiChannel_6[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_6,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBReadBuffer_SpiChannel_7[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_7,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBReadBuffer_SpiChannel_8[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_8,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBReadBuffer_SpiChannel_9[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_9,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBReadBuffer_SpiChannel_10[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_10,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBReadBuffer_SpiChannel_11[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_11,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBReadBuffer_SpiChannel_12[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_12,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint16 Spi_IBReadBuffer_SpiChannel_13[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_13,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);
static VAR_ALIGN(uint32 Spi_IBReadBuffer_SpiChannel_14[SPI_ROUNDUP(SPI_BUFFER_SIZE_CHANNEL_14,BUFF_SIZE_ROUNDUP_LEN)],SPI_BUFF_ALIGN_LEN);


#if (SPI_NO_CACHEABLE_NEEDED == STD_ON)
#define SPI_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#include "Spi_MemMap.h"

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

/** \brief  This array contains configuration details for Channels */
CONST(Spi_ChannelCfgType, SPI_CONST) Spi_ChannelConfig[SPI_TOTAL_CH_COUNT] =
{
  /* Index: 0 - SpiChannel_0 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_0,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_0,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_0,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0x0,
  }  ,
    /* Index: 1 - SpiChannel_1 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_1,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_1,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_1,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 2 - SpiChannel_2 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_2,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_2,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_2,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 3 - SpiChannel_3 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_3,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_3,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_3,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 4 - SpiChannel_4 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_4,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_4,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_4,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 5 - SpiChannel_5 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_5,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_5,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_5,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 6 - SpiChannel_6 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_6,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_6,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_6,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 7 - SpiChannel_7 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_7,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_7,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_7,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 8 - SpiChannel_8 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_8,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_8,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_8,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 9 - SpiChannel_9 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_9,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_9,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_9,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 10 - SpiChannel_10 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_10,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_10,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_10,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 11 - SpiChannel_11 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_11,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_11,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_11,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 12 - SpiChannel_12 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_12,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_12,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_12,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 13 - SpiChannel_13 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_13,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_13,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_13,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 14 - SpiChannel_14 */
  {
    /* channelBufferType */
    IB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_14,
    /* writeBufferIndex */
    (Spi_DataBufferType*)Spi_IBWriteBuffer_SpiChannel_14,
    /* readBufferIndex */
    (Spi_DataBufferType*)Spi_IBReadBuffer_SpiChannel_14,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 15 - SpiChannel_15 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_15,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 16 - SpiChannel_16 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_16,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 17 - SpiChannel_17 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_17,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 18 - SpiChannel_18 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_18,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 19 - SpiChannel_19 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_19,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 20 - SpiChannel_20 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    32U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_20,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFFFFFU,
  }  ,
    /* Index: 21 - SpiChannel_21 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_21,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 22 - SpiChannel_22 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_22,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 23 - SpiChannel_23 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_23,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 24 - SpiChannel_24 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_24,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 25 - SpiChannel_25 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_25,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 26 - SpiChannel_26 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_26,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 27 - SpiChannel_27 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_27,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 28 - SpiChannel_28 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_28,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 29 - SpiChannel_29 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_29,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 30 - SpiChannel_30 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_30,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 31 - SpiChannel_31 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_31,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 32 - SpiChannel_32 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_32,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    LSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 33 - SpiChannel_TLE75242A */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_33,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 34 - SpiChannel_TLE75242B */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_34,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 35 - SpiChannel_TLE75004 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_35,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 36 - SpiChannel_TLE8108EM */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_36,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 37 - SpiChannel_NCK2910 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_37,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 38 - SpiChannel_NJJ29C0B */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_38,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }  ,
    /* Index: 39 - SpiChannel_TLE94103B */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_39,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    LSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 40 - SpiChannel_TLE94103A */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    16U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_40,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    LSB,
    /* defaultValue */
    0xFFFFU,
  }  ,
    /* Index: 41 - SpiChannel_ADAU1462 */
  {
    /* channelBufferType */
    EB,
    /* dataWidth */
    8U,
    /* bufferSize */
    SPI_BUFFER_SIZE_CHANNEL_41,
    /* writeBufferIndex */
    NULL_PTR,
    /* readBufferIndex */
    NULL_PTR,
    /* bitOrder */
    MSB,
    /* defaultValue */
    0xFFU,
  }    
};

/* Channel list */
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_0_ChannelList [4]=
{
    /* Linked channels for job: 0  */
    0U,    1U,    2U,    3U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_1_ChannelList [4]=
{
    /* Linked channels for job: 1  */
    25U,    26U,    27U,    24U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_2_ChannelList [3]=
{
    /* Linked channels for job: 2  */
    8U,    9U,    13U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_3_ChannelList [3]=
{
    /* Linked channels for job: 3  */
    21U,    22U,    23U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_4_ChannelList [2]=
{
    /* Linked channels for job: 4  */
    4U,    5U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_5_ChannelList [2]=
{
    /* Linked channels for job: 5  */
    6U,    7U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_6_ChannelList [3]=
{
    /* Linked channels for job: 6  */
    15U,    16U,    17U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_7_ChannelList [3]=
{
    /* Linked channels for job: 7  */
    18U,    19U,    20U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_8_ChannelList [4]=
{
    /* Linked channels for job: 8  */
    10U,    12U,    11U,    14U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_9_ChannelList [3]=
{
    /* Linked channels for job: 9  */
    28U,    29U,    30U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_slave_ChannelList [1]=
{
    /* Linked channels for job: 10  */
    31U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_sbc_ChannelList [1]=
{
    /* Linked channels for job: 11  */
    32U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_TLE75242A_ChannelList [1]=
{
    /* Linked channels for job: 12  */
    33U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_TLE75242B_ChannelList [1]=
{
    /* Linked channels for job: 13  */
    34U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_TLE75004_ChannelList [1]=
{
    /* Linked channels for job: 14  */
    35U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_TLE8108EM_ChannelList [1]=
{
    /* Linked channels for job: 15  */
    36U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_NCK2910_ChannelList [1]=
{
    /* Linked channels for job: 16  */
    37U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_NJJ29C0B_ChannelList [1]=
{
    /* Linked channels for job: 17  */
    38U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_TLE94103B_ChannelList [1]=
{
    /* Linked channels for job: 18  */
    39U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_TLE94103A_ChannelList [1]=
{
    /* Linked channels for job: 19  */
    40U,
};
static  CONST(Spi_ChannelType, SPI_CONST) SpiJob_ADAU1462_ChannelList [1]=
{
    /* Linked channels for job: 20  */
    41U,
};
/*
  Why don't we use a loop statement here, because I can't figure out the German thinking circuit
*/
                                                                                                                                                                                                                                


/*
  This array contains configuration details for Jobs.
  And sorted by Job priority
*/

                                                                                    
                                                                                                                              




CONST(Spi_JobCfgType, SPI_CONST) Spi_JobConfig[SPI_TOTAL_JOB_COUNT] =
{
    /* Index: 0 - SpiJob_0 */
  {
    /* DataWith */
    8,
    /* bitOrder */
    MSB,
    /* device Idx */
    0,
    /*hwIdxOfHwUnitCfgs*/
    3U,
    /* hwUnitId */
    CSIB4,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    4U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    4U,
    /* ChannelList */
    SpiJob_0_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 1 - SpiJob_1 */
  {
    /* DataWith */
    8,
    /* bitOrder */
    MSB,
    /* device Idx */
    1,
    /*hwIdxOfHwUnitCfgs*/
    3U,
    /* hwUnitId */
    CSIB4,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    4U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    4U,
    /* ChannelList */
    SpiJob_1_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 2 - SpiJob_2 */
  {
    /* DataWith */
    16,
    /* bitOrder */
    MSB,
    /* device Idx */
    2,
    /*hwIdxOfHwUnitCfgs*/
    0U,
    /* hwUnitId */
    CSIB1,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    0U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    3U,
    /* ChannelList */
    SpiJob_2_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 3 - SpiJob_3 */
  {
    /* DataWith */
    16,
    /* bitOrder */
    MSB,
    /* device Idx */
    3,
    /*hwIdxOfHwUnitCfgs*/
    0U,
    /* hwUnitId */
    CSIB1,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    0U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    3U,
    /* ChannelList */
    SpiJob_3_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 4 - SpiJob_4 */
  {
    /* DataWith */
    16,
    /* bitOrder */
    MSB,
    /* device Idx */
    4,
    /*hwIdxOfHwUnitCfgs*/
    0U,
    /* hwUnitId */
    CSIB1,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    0U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    2U,
    /* ChannelList */
    SpiJob_4_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 5 - SpiJob_5 */
  {
    /* DataWith */
    32,
    /* bitOrder */
    MSB,
    /* device Idx */
    5,
    /*hwIdxOfHwUnitCfgs*/
    1U,
    /* hwUnitId */
    CSIB2,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    0U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    2U,
    /* ChannelList */
    SpiJob_5_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 6 - SpiJob_6 */
  {
    /* DataWith */
    32,
    /* bitOrder */
    MSB,
    /* device Idx */
    6,
    /*hwIdxOfHwUnitCfgs*/
    1U,
    /* hwUnitId */
    CSIB2,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    0U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    3U,
    /* ChannelList */
    SpiJob_6_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 7 - SpiJob_7 */
  {
    /* DataWith */
    32,
    /* bitOrder */
    MSB,
    /* device Idx */
    7,
    /*hwIdxOfHwUnitCfgs*/
    2U,
    /* hwUnitId */
    CSIB3,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    0U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    3U,
    /* ChannelList */
    SpiJob_7_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 8 - SpiJob_8 */
  {
    /* DataWith */
    32,
    /* bitOrder */
    MSB,
    /* device Idx */
    8,
    /*hwIdxOfHwUnitCfgs*/
    2U,
    /* hwUnitId */
    CSIB3,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    0U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    4U,
    /* ChannelList */
    SpiJob_8_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 9 - SpiJob_9 */
  {
    /* DataWith */
    8,
    /* bitOrder */
    MSB,
    /* device Idx */
    9,
    /*hwIdxOfHwUnitCfgs*/
    6U,
    /* hwUnitId */
    CSIB7,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    3U,
    /* ChannelList */
    SpiJob_9_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 10 - SpiJob_slave */
  {
    /* DataWith */
    8,
    /* bitOrder */
    MSB,
    /* device Idx */
    10,
    /*hwIdxOfHwUnitCfgs*/
    4U,
    /* hwUnitId */
    CSIB5,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_slave_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 11 - SpiJob_sbc */
  {
    /* DataWith */
    8,
    /* bitOrder */
    LSB,
    /* device Idx */
    11,
    /*hwIdxOfHwUnitCfgs*/
    6U,
    /* hwUnitId */
    CSIB7,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    49U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_sbc_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 12 - SpiJob_TLE75242A */
  {
    /* DataWith */
    16,
    /* bitOrder */
    MSB,
    /* device Idx */
    12,
    /*hwIdxOfHwUnitCfgs*/
    6U,
    /* hwUnitId */
    CSIB7,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_2,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_TLE75242A_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 13 - SpiJob_TLE75242B */
  {
    /* DataWith */
    16,
    /* bitOrder */
    MSB,
    /* device Idx */
    13,
    /*hwIdxOfHwUnitCfgs*/
    6U,
    /* hwUnitId */
    CSIB7,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_TLE75242B_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 14 - SpiJob_TLE75004 */
  {
    /* DataWith */
    16,
    /* bitOrder */
    MSB,
    /* device Idx */
    14,
    /*hwIdxOfHwUnitCfgs*/
    6U,
    /* hwUnitId */
    CSIB7,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_1,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_TLE75004_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 15 - SpiJob_TLE8108EM */
  {
    /* DataWith */
    16,
    /* bitOrder */
    MSB,
    /* device Idx */
    15,
    /*hwIdxOfHwUnitCfgs*/
    4U,
    /* hwUnitId */
    CSIB5,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_2,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    49U,    
    /* EndDelay */
    49U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_TLE8108EM_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 16 - SpiJob_NCK2910 */
  {
    /* DataWith */
    8,
    /* bitOrder */
    MSB,
    /* device Idx */
    16,
    /*hwIdxOfHwUnitCfgs*/
    1U,
    /* hwUnitId */
    CSIB2,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,//39,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_GPIO,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    49U,
    /* timeClk2Cs StartDelay */
    0,//99U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    HIGH,
    /* shiftEdge */
    TRAILING,//LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_NCK2910_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 17 - SpiJob_NJJ29C0B */
  {
    /* DataWith */
    8,
    /* bitOrder */
    LSB,
    /* device Idx */
    17,
    /*hwIdxOfHwUnitCfgs*/
    1U,
    /* hwUnitId */
    CSIB2,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_1,//SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,//38,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_GPIO,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    49,//24U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_NJJ29C0B_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 18 - SpiJob_TLE94103B */
  {
    /* DataWith */
    16,
    /* bitOrder */
    LSB,
    /* device Idx */
    18,
    /*hwIdxOfHwUnitCfgs*/
    6U,
    /* hwUnitId */
    CSIB7,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_3,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_TLE94103B_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 19 - SpiJob_TLE94103A */
  {
    /* DataWith */
    16,
    /* bitOrder */
    LSB,
    /* device Idx */
    19,
    /*hwIdxOfHwUnitCfgs*/
    4U,
    /* hwUnitId */
    CSIB5,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_3,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    9U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    LEADING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_TLE94103A_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
    /* Index: 20 - SpiJob_ADAU1462 */
  {
    /* DataWith */
    8,
    /* bitOrder */
    MSB,
    /* device Idx */
    20,
    /*hwIdxOfHwUnitCfgs*/
    4U,
    /* hwUnitId */
    CSIB5,
    /* CSIdx */
    /** Traceability       : SWSR_SPI_010 */
    SPI_CS_0,
    /* hwCS0Enable */
    FALSE,
    /* hwCs0PinId */
    0xFF,
    /* GPIOCsPinID*/
    0xFF,
    /* IsEnableRx */
    TRUE,
    /* CSHandling */
    CS_VIA_PERIPHERAL_ENGINE,
    /* CSPolarity */
    (uint8)LOW,
    /* HwCSPolarity idle */
    (uint8)STD_HIGH,
    /** Traceability       : SWSR_SPI_003 */
    /* baudRateDiv Div */
    24U,
    /* timeClk2Cs StartDelay */
    0U,    
    /* EndDelay */
    0U,    
    /* Frame delay */
    0U,    
    /* idleLevel */
    LOW,
    /* shiftEdge */
    TRAILING,
    /* Priority */
    0U,
    /* jobEndNotification */
    NULL_PTR,
    /* numOfChannels */
    1U,
    /* ChannelList */
    SpiJob_ADAU1462_ChannelList,
    /* In master mode, delay half sclk to sample miso */
    FALSE,

  },
};

/* Job list */

static CONST(Spi_JobType, SPI_CONST) SpiSequence_0_JobList [2]=
{
    /*
      Linked Job for Sequence: 0
      and sorted by Job priority.
    */
    0U ,    1U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_1_JobList [3]=
{
    /*
      Linked Job for Sequence: 1
      and sorted by Job priority.
    */
    3U ,    4U ,    2U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_2_JobList [4]=
{
    /*
      Linked Job for Sequence: 2
      and sorted by Job priority.
    */
    5U ,    6U ,    7U ,    8U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_3_JobList [1]=
{
    /*
      Linked Job for Sequence: 3
      and sorted by Job priority.
    */
    9U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_4_JobList [1]=
{
    /*
      Linked Job for Sequence: 4
      and sorted by Job priority.
    */
    10U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_5_JobList [1]=
{
    /*
      Linked Job for Sequence: 5
      and sorted by Job priority.
    */
    11U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_TLE75242A_JobList [1]=
{
    /*
      Linked Job for Sequence: 6
      and sorted by Job priority.
    */
    12U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_TLE75242B_JobList [1]=
{
    /*
      Linked Job for Sequence: 7
      and sorted by Job priority.
    */
    13U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_TLE75004_JobList [1]=
{
    /*
      Linked Job for Sequence: 8
      and sorted by Job priority.
    */
    14U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_TLE8108EM_JobList [1]=
{
    /*
      Linked Job for Sequence: 9
      and sorted by Job priority.
    */
    15U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_NCK2910_JobList [1]=
{
    /*
      Linked Job for Sequence: 10
      and sorted by Job priority.
    */
    16U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_NJJ29C0B_JobList [1]=
{
    /*
      Linked Job for Sequence: 11
      and sorted by Job priority.
    */
    17U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_TLE94103B_JobList [1]=
{
    /*
      Linked Job for Sequence: 12
      and sorted by Job priority.
    */
    18U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_TLE94103A_JobList [1]=
{
    /*
      Linked Job for Sequence: 13
      and sorted by Job priority.
    */
    19U ,  
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_ADAU1462_JobList [1]=
{
    /*
      Linked Job for Sequence: 14
      and sorted by Job priority.
    */
    20U ,  
};






/* This array contains configuration details for Sequences */
CONST(Spi_SequenceCfgType, SPI_CONST) Spi_SequenceConfig[SPI_TOTAL_SEQ_COUNT] =
{
  /* Index: 0 - SpiSequence_0 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    2U,
    /* JobList */
    SpiSequence_0_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB4)|(0x1U << CSIB4)
  },
  /* Index: 1 - SpiSequence_1 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    3U,
    /* JobList */
    SpiSequence_1_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB1)|(0x1U << CSIB1)|(0x1U << CSIB1)
  },
  /* Index: 2 - SpiSequence_2 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    4U,
    /* JobList */
    SpiSequence_2_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB2)|(0x1U << CSIB2)|(0x1U << CSIB3)|(0x1U << CSIB3)
  },
  /* Index: 3 - SpiSequence_3 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_3_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB7)
  },
  /* Index: 4 - SpiSequence_4 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_4_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB5)
  },
  /* Index: 5 - SpiSequence_5 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_5_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB7)
  },
  /* Index: 6 - SpiSequence_TLE75242A */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_TLE75242A_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB7)
  },
  /* Index: 7 - SpiSequence_TLE75242B */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_TLE75242B_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB7)
  },
  /* Index: 8 - SpiSequence_TLE75004 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_TLE75004_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB7)
  },
  /* Index: 9 - SpiSequence_TLE8108EM */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_TLE8108EM_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB5)
  },
  /* Index: 10 - SpiSequence_NCK2910 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_NCK2910_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB2)
  },
  /* Index: 11 - SpiSequence_NJJ29C0B */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_NJJ29C0B_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB2)
  },
  /* Index: 12 - SpiSequence_TLE94103B */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_TLE94103B_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB7)
  },
  /* Index: 13 - SpiSequence_TLE94103A */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_TLE94103A_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB5)
  },
  /* Index: 14 - SpiSequence_ADAU1462 */
  {
    /* interruptableSequence */
    FALSE,
    /* sequenceEndNotification */
    NULL_PTR,
    /* numOfJobs */
    1U,
    /* JobList */
    SpiSequence_ADAU1462_JobList,
    /* Jobs HwMask */
    (0x1U << CSIB5)
  },

};

/*PRQA S 0686,1533 110*/
/* Hw list */
/* This array contains HwUnit property */
CONST(Spi_HwUnitConfigType, SPI_CONST) Spi_HwUnitConfig[SPI_TOTAL_HW_COUNT] =
{
  
  /* SpiHwUnit_SPI1 */
  {
    .hwUnitId = CSIB1,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
,

  /* SpiHwUnit_SPI2 */
  {
    .hwUnitId = CSIB2,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
,

  /* SpiHwUnit_SPI3 */
  {
    .hwUnitId = CSIB3,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
,

  /* SpiHwUnit_SPI4 */
  {
    .hwUnitId = CSIB4,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
,

  /* SpiHwUnit_SPI5 */
  {
    .hwUnitId = CSIB5,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
,

  /* SpiHwUnit_SPI6 */
  {
    .hwUnitId = CSIB6,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
,

  /* SpiHwUnit_SPI7 */
  {
    .hwUnitId = CSIB7,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
,

  /* SpiHwUnit_SPI8 */
  {
    .hwUnitId = CSIB8,
    /* DMA mode Enable */
    .isEnableDMA = (boolean)FALSE,
    /* hwMode: spi master or slave */
    .hwMode = SPI_MASTER,
    /* Ti mode Enable */
    .isEnableTiMod = (boolean)FALSE,
    /* In E3 this params no use */
    .transferMode = SPI_ASYNC_MODE,
  }
};


CONST(uint8, SPI_CONST) Spi_InstanceMask_Config[5] =
{
      (0x01U <<CSIB5) | (0x01U <<CSIB7) | (0x01U <<CSIB2) | (0x01U <<CSIB3) | 0U ,    
      (0x01U <<CSIB4) | (0x01U <<CSIB1) | 0U ,    
      0U,  
      0U,  
      0U,  

};
/** \brief  Structure for SPI Init configuration */
/** Traceability       : SWSR_SPI_007 SWSR_SPI_086 */
CONST(Spi_ConfigType, SPI_CONST) Spi_Config[SPI_TOTAL_DRIVERS] =
{
  /* Index: 0 - SpiDriver */
  {
    /* ChannelType */
    Spi_ChannelConfig,
    /* JobType */
    Spi_JobConfig,
    /* SequenceType */
    Spi_SequenceConfig
  }
};

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */


