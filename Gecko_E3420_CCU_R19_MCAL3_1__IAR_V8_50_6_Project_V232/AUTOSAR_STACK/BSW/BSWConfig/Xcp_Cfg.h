/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Xcp_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-01-11 13:18:39>
 */
/*============================================================================*/

#ifndef  XCP_CFG_H
#define  XCP_CFG_H
/*Bus Interface Select*/
#define XCP_ON_CCD_ENABLE           STD_OFF
#define XCP_ON_ETHERNET_ENABLE      STD_OFF
#define XCP_ON_FLEXRAY_ENABLE       STD_OFF
#define XCP_ON_CAN_ENABLE           STD_ON
#include "Xcp_GenericTypes.h"

/*Available resource & protection.*/
#define XCP_RESOURCE                (0u|XCP_PL_DAQ|XCP_PL_CAL)
#define XCP_PROTECTION              (0u|XCP_PL_DAQ|XCP_PL_CAL)

#define XCP_BUS_TX_POLLING_MODE     STD_OFF
#define XCP_TANSFER_TIME_OUT        3u

/*SET_REQUEST related.*/
#define XCP_CAL_STORE_SUPPORT       STD_OFF
#define XCP_DAQ_STORE_SUPPORT       STD_OFF
#define XCP_RESUME_SUPPORT          STD_OFF
#define XCP_BIT_STIM_SUPPORT        STD_OFF

#define XCP_MAX_CTO                    64u
#define XCP_MAX_DTO                 64u
#define XCP_CTO_BUFFER_SIZE         64u
#define XCP_DTO_BUFFER_SIZE         XCP_MAX_DTO

/*General configuration.*/
#define XCP_MAIN_FUNCTION_PERIOD    10u
#define XCP_DEV_ERROR_DETECT        STD_ON
#define XCP_VERSION_INFO_API        STD_OFF
#define XCP_SUPPRESS_TX_SUPPORTED   STD_OFF

/*CAL & PAG characteristic.*/
#define XCP_MAX_SEGMENT             1u
#define XCP_PAG_SUPPORT             STD_ON
#define XCP_SWITCH_PAG_SUPPORT      STD_ON
    #define XCP_RAM_PAGE_NUM            0u
    #define XCP_FLASH_PAGE_NUM          1u
#define XCP_PAGE_BUF0_SIZE 0x30000u

/*DAQ characteristic.*/
#define XCP_DAQ_CONFIG_TYPE             XCP_DAQ_DYNAMIC
#define XCP_IDENTIFICATION_FIELD_TYPE   XCP_PID_ABSOLUTE
#define XCP_PID_OFF_SUPPORT             STD_OFF
#define XCP_PRESCALER_SUPPORTED            STD_OFF
#define XCP_DAQ_PRIORITY_SUPPORT        STD_OFF
#define XCP_DAQ_OVL_INDICATION            XCP_DAQ_OVL_NO_INDIC
#define XCP_PID_OVFLOW                     0x80u
#define XCP_MAX_WRITEDAQ_SIZE        63u

/*Dynamic daq configuration.*/
#define XCP_DAQ_COUNT               4u
#define XCP_ODT_COUNT               64u
#define XCP_ODTENTRY_COUNT          XCP_MAX_WRITEDAQ_SIZE
#define XCP_DYNAMIC_DAQ_BUFFER_SIZE    4096u
#define XCP_MIN_DAQ                    0u
#define XCP_MAX_DAQ                 4u
#define XCP_ODT_ENTRY_SIZE_STIM     0u
#define XCP_ODT_ENTRY_SIZE_DAQ      63u

/*Event configuration.*/
#define EventChannel_0              0u
#define EventChannel_1              1u
#define EventChannel_2              2u
#define EventChannel_3              3u
#define MAX_EVCH_NAME_LENGTH        32u
#define XCP_MAX_EVENT_CHANNEL       4u
#define XCP_EVCHBUFFER_0_DEPTH      1u
#define XCP_EVCHBUFFER_1_DEPTH      1u
#define XCP_EVCHBUFFER_2_DEPTH      1u
#define XCP_EVCHBUFFER_3_DEPTH      1u
/*TimeStamp configuration.*/
#define XCP_TIMESTAMP_TYPE          XCP_TS_NO_TS
#define XCP_INTERLEAVED_MODE        STD_OFF
/*Blcok Mode.*/
#define XCP_SLAVE_BLOCK_MODE        STD_OFF
#define XCP_MASTER_BLOCK_MODE       STD_OFF
//#define XCP_MAX_BS                  8u
//#define XCP_MIN_ST                  100u
//#define XCP_BLOCK_BUFFER_SIZE       48u
//#define XCP_INCREASED_CAN_ID        STD_OFF
#define XCP_CAN_MAX_DLC_REQUIRED    STD_ON
#define XCP_CAN_MAX_DLC              64u
/*Optional command.*/
#define XCP_GET_COMM_MODE_INFO              STD_ON
#define XCP_GET_ID                          STD_ON
#define XCP_NUM_OF_ID                       0x1u
/*STD*/
#define XCP_SET_REQUEST                        STD_OFF
#define XCP_SEED_AND_UNLOCK                 STD_ON
#define XCP_SET_MTA                            STD_ON
#define XCP_UPLOAD                          STD_ON
#define XCP_SHORT_UPLOAD                    STD_ON
#define XCP_BUILD_CHECKSUM                  STD_ON
#define XCP_MAX_CHECKSUM_SIZE               0x100u
#define XCP_TRANSPORT_LAYER_CMD             STD_OFF
#define    XCP_GET_SLAVE_ID                    STD_OFF
#define    XCP_GET_DAQ_ID                      STD_OFF
#define    XCP_SET_DAQ_ID                      STD_OFF
#define XCP_USER_CMD                        STD_OFF
/*CAL*/
#define XCP_DOWNLOAD_NEXT                    STD_OFF
#define XCP_DOWNLOAD_MAX                    STD_ON
#define XCP_SHORT_DOWNLOAD                    STD_ON
#define XCP_MODIFY_BITS                     STD_OFF
#define XCP_SET_CAL_PAGE                    XCP_PAG_SUPPORT
#define XCP_GET_CAL_PAGE                    XCP_PAG_SUPPORT
#define XCP_GET_PAG_PROCESSOR_INFO          STD_OFF
#define XCP_GET_SEGMENT_INFO                STD_OFF
#define XCP_GET_PAGE_INFO                   STD_OFF
#define XCP_SET_SEGMENT_MODE                STD_OFF
#define XCP_GET_SEGMENT_MODE                STD_OFF
#define XCP_COPY_CAL_PAGE                   STD_OFF
/*DAQ*/
#define XCP_WRITE_DAQ_MULTIPLE              STD_OFF
#define XCP_READ_DAQ                        STD_ON
#define XCP_GET_DAQ_CLOCK                   STD_OFF
#define XCP_GET_DAQ_PROCESSOR_INFO          STD_ON
#define XCP_GET_DAQ_RESOLUTION_INFO         STD_ON
#define XCP_GET_DAQ_LIST_MODE               STD_ON
#define XCP_GET_DAQ_EVENT_INFO              STD_ON

#define XCP_CHECK_MEA_ADDR                  STD_ON

typedef VAR(uint8,TYPEDEF)           Xcp_DaqNumType;
#define XCP_ADDR_GRANULARITY         XCP_AG_BYTE

#define XCP_AG                       (0x01u)

typedef VAR(uint8,TYPEDEF)           Xcp_AGType;

#define XCP_RX_PDU_NUMBER_MAX        1u
#define XCP_TMSR_DTO_XCP                                                  0u

#define XCP_TX_PDU_NUMBER_MAX        1u
#define XCP_INCA_CRO_XCP                                                  0u

#endif  /* endof XCP_CFG_H */

/*=======[E N D   O F   F I L E]==============================================*/

