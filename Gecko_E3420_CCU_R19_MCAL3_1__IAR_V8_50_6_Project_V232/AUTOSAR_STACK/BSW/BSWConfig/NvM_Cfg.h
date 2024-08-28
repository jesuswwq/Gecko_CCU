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
**  FILENAME    : NvM_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2024/06/03 14:59:25                                 **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of NvM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef NVM_CFG_H
#define NVM_CFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#define NVM_CFG_SW_MAJOR_VERSION 2U
#define NVM_CFG_SW_MINOR_VERSION 0U
#define NVM_CFG_SW_PATCH_VERSION 0U

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define NVM_API_CONFIG_CLASS                            NVM_API_CONFIG_CLASS_3
#define NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION        STD_ON
#define NVM_BSWM_SINGLEBLOCK_JOBSTATUS_INFORMATION      STD_OFF
#define NVM_COMPILED_CONFIG_ID                          (0x3u)
#define NVM_CRC_NUM_OF_BYTES                              (0xffffu)
#define NVM_DATASET_SELECTION_BITS                      (0x2u)
#define NVM_DEV_ERROR_DETECT                            STD_ON
#define NVM_DRV_MODE_SWITCH                                 STD_OFF
#define NVM_DYNAMIC_CONFIGURATION                         STD_ON
#define NVM_JOB_PRIORITIZATION                            STD_OFF
#define NVM_POLLING_MODE                                STD_OFF
#define NVM_REPEAT_MIRROR_OPERATIONS                      (0x0u)
#define NVM_SET_RAM_BLOCK_STATUS_API                    STD_OFF
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE                    (0x0u)
#define NVM_SIZE_STANDARD_JOB_QUEUE                        (0x64u)
#define NVM_VERSION_INFO_API                            STD_OFF
#define NVM_INCLUDE_CRC                                 STD_ON
#define NVM_CRC_TYPE_8                                  STD_OFF
#define NVM_CRC_TYPE_16                                 STD_ON
#define NVM_CRC_TYPE_32                                 STD_OFF
#define NVM_DEM_PRODUCTION_ERROR_DETECT                    STD_OFF

/*The following definitions used to index NVM block for SW */
#define NvMBlock1_DID_F190               2U
#define NvMBlock2_DID_F101               3U
#define NvMBlock3_DID_F157               4U
#define NvMBlock4_DID_F158               5U
#define NvMBlock5_DID_F086               6U
#define NvMBlock6_DID_F13A               7U
#define NvMBlock7_DID_F13B               8U
#define NvMBlock8_DID_F13C               9U
#define NvMBlock9_DID_F13D               10U
#define NvMBlock10_DID_F13E               11U
#define NvMBlock11_27Counter_Level1               12U
#define NvMBlock12_BL               13U
#define NvMBlock11_27Counter_Level5               14U
#define NvMBlock11_27Counter_Level7               15U
#define NvMBlock_EventEntryPrimary_1               16U
#define NvMBlock_EventEntryPrimary_2               17U
#define NvMBlock_EventEntryPrimary_3               18U
#define NvMBlock_EventEntryPrimary_4               19U
#define NvMBlock_EventEntryPrimary_5               20U
#define NvMBlock_EventEntryPrimary_6               21U
#define NvMBlock_EventEntryPrimary_7               22U
#define NvMBlock_EventEntryPrimary_8               23U
#define NvMBlock_EventEntryPrimary_9               24U
#define NvMBlock_EventEntryPrimary_10               25U
#define NvMBlock_EventEntryPrimary_11               26U
#define NvMBlock_EventEntryPrimary_12               27U
#define NvMBlock_EventEntryPrimary_13               28U
#define NvMBlock_EventEntryPrimary_14               29U
#define NvMBlock_EventEntryPrimary_15               30U
#define NvMBlock_EventEntryPrimary_16               31U
#define NvMBlock_EventEntryPrimary_17               32U
#define NvMBlock_EventEntryPrimary_18               33U
#define NvMBlock_EventEntryPrimary_19               34U
#define NvMBlock_EventEntryPrimary_20               35U
#define NvMBlock_EventEntryPrimary_21               36U
#define NvMBlock_EventEntryPrimary_22               37U
#define NvMBlock_EventEntryPrimary_23               38U
#define NvMBlock_EventEntryPrimary_24               39U
#define NvMBlock_EventEntryPrimary_25               40U
#define NvMBlock_EventEntryPrimary_26               41U
#define NvMBlock_EventEntryPrimary_27               42U
#define NvMBlock_EventEntryPrimary_28               43U
#define NvMBlock_EventEntryPrimary_29               44U
#define NvMBlock_EventEntryPrimary_30               45U
#define NvMBlock_EventEntryPrimary_31               46U
#define NvMBlock_EventEntryPrimary_32               47U
#define NvMBlock_EventEntryPrimary_33               48U
#define NvMBlock_EventEntryPrimary_34               49U
#define NvMBlock_EventEntryPrimary_35               50U
#define NvMBlock_EventEntryPrimary_36               51U
#define NvMBlock_EventEntryPrimary_37               52U
#define NvMBlock_EventEntryPrimary_38               53U
#define NvMBlock_EventEntryPrimary_39               54U
#define NvMBlock_EventEntryPrimary_40               55U
#define NvMBlock_EventEntryPrimary_41               56U
#define NvMBlock_EventEntryPrimary_42               57U
#define NvMBlock_EventEntryPrimary_43               58U
#define NvMBlock_EventEntryPrimary_44               59U
#define NvMBlock_EventEntryPrimary_45               60U
#define NvMBlock_EventEntryPrimary_46               61U
#define NvMBlock_EventEntryPrimary_47               62U
#define NvMBlock_EventEntryPrimary_48               63U
#define NvMBlock_EventEntryPrimary_49               64U
#define NvMBlock_EventEntryPrimary_50               65U
#define NvMBlock_UDS_InternalData               66U
#define NvMBlock_OBD_InternalData               67U
#define NvMBlock_Swc_VCU_01_64               68U
#define NvMBlock_Swc_TMS               69U
#define NvMBlock_Swc_BCM_IMM_20               70U
#define NvMBlock_Swc_BCM_PD_10               71U
#define NvMBlock_Swc_BCM_PEPS_256               72U

/*The total number of user configured*/
#define NVM_BLOCK_NUM_ALL                                 72
#define NVM_REDUNDANT_ALL                                  1

#define NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR                0U

#define NVM_MAX_LENGTH_NV_BLOCK                            588U
#define NVM_MAX_LENGTH_REDUNDANT_BLOCK                    2U

#if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON == NVM_JOB_PRIORITIZATION))
/*The total number of different priority*/
#define NVM_TOTAL_NUM_DIFF_PRI                             NVM_TABLE_SIZE_PRIORITY
#endif

#if (STD_ON==NVM_JOB_PRIORITIZATION)
/* The priority table size*/
#define NVM_TABLE_SIZE_PRIORITY                          2U
#endif

extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[17];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[30];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[16];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[16];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[9];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[16];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[1];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer9[7];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer10[12];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer11[8];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer12[5];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer13[40];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer14[5];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer15[5];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer16[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer17[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer18[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer19[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer20[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer21[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer22[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer23[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer24[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer25[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer26[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer27[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer28[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer29[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer30[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer31[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer32[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer33[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer34[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer35[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer36[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer37[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer38[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer39[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer40[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer41[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer42[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer43[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer44[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer45[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer46[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer47[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer48[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer49[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer50[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer51[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer52[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer53[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer54[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer55[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer56[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer57[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer58[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer59[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer60[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer61[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer62[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer63[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer64[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer65[36];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer66[588];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer67[16];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer68[64];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer69[256];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer70[20];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer71[10];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer72[256];

#endif /* End of NVM_CFG_H*/
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

