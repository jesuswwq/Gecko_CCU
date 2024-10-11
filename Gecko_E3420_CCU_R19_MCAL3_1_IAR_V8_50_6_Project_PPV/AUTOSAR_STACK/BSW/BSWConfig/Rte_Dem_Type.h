/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem_Type.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-10-23 13:54:36>
 */
/*============================================================================*/

/* Rte_Dem_Type.h */

#ifndef RTE_DEM_TYPE_H
#define RTE_DEM_TYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/
typedef uint16 Dem_EventIdType;

typedef uint8 Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED                      0x00u
#define DEM_EVENT_STATUS_FAILED                      0x01u
#define DEM_EVENT_STATUS_PREPASSED                   0x02u
#define DEM_EVENT_STATUS_PREFAILED                   0x03u
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED       0x04u

typedef uint8 Dem_DebouncingStateType;
#define DEM_TEMPORARILY_DEFECTIVE                    0x01u  /*Bit 0: Temporarily Defective (corresponds to 0 <FDC < 127)*/
#define DEM_FINALLY_DEFECTIVE                        0x02u  /*Bit 1: finally Defective (corresponds to FDC = 127)*/
#define DEM_TEMPORARILY_HEALED                       0x04u  /*Bit 2: temporarily healed (corresponds to -128 < FDC < 0)*/
#define DEM_TEST_COMPLETE                            0x08u  /*Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127)*/
#define DEM_DTR_UPDATE                               0x10u  /*Bit 4: DTR Update (= Test complete && Debouncing complete && enable conditions / storage conditions fulfilled)*/

typedef uint8 Dem_DebounceResetStatusType;
#define DEM_DEBOUNCE_STATUS_FREEZE                   0x00u
#define DEM_DEBOUNCE_STATUS_RESET                    0x01u

typedef uint8 Dem_UdsStatusByteType;
#define DEM_UDS_STATUS_TF                            0x01u /*bit 0: TestFailed*/
#define DEM_UDS_STATUS_TFTOC                         0x02u /*bit 1: TestFailedThisOperationCycle*/
#define DEM_UDS_STATUS_PDTC                          0x04u /*bit 2: PendingDTC*/
#define DEM_UDS_STATUS_CDTC                          0x08u /*bit 3: ConfirmedDTC*/
#define DEM_UDS_STATUS_TNCSLC                        0x10u /*bit 4: TestNotCompletedSinceLastClear*/
#define DEM_UDS_STATUS_TFSLC                         0x20u /*bit 5: TestFailedSinceLastClear*/
#define DEM_UDS_STATUS_TNCTOC                        0x40u /*bit 6: TestNotCompletedThisOperationCycle*/
#define DEM_UDS_STATUS_WIR                           0x80u /*bit 7: WarningIndicatorRequested*/

typedef uint8 Dem_OperationCycleStateType;
#define DEM_CYCLE_STATE_START                        0x00u
#define DEM_CYCLE_STATE_END                          0x01u

typedef uint8 Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                        0x01u
#define DEM_DTC_KIND_EMISSION_REL_DTCS               0x02u /*Select OBD-relevant DTCs*/

typedef uint8 Dem_DTCFormatType;
#define DEM_DTC_FORMAT_OBD                           0x00u /*selects the 2-byte OBD DTC format (refer to configuration parameter DemObdDTC)*/
#define DEM_DTC_FORMAT_UDS                           0x01u /*selects the 3-byte UDS DTC format (refer to configuration parameter DemUdsDTC)*/
#define DEM_DTC_FORMAT_J1939                         0x02u /*selects the merged SPN + FMI to 3-byte J1939 DTC format (refer to DemJ1939DTC)*/

typedef uint8 Dem_DTCOriginType;
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY                0x01u
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                 0x02u
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY              0x03u

typedef uint8 Dem_DTRControlType;
#define DEM_DTR_CTL_NORMAL                           0x00u
#define DEM_DTR_CTL_NO_MAX                           0x01u
#define DEM_DTR_CTL_NO_MIN                           0x02u
#define DEM_DTR_CTL_RESET                            0x03u
#define DEM_DTR_CTL_INVISIBLE                        0x04u

typedef uint8 Dem_IumprDenomCondIdType;
#define DEM_IUMPR_GENERAL_DENOMINATOR                0x01u
#define DEM_IUMPR_DEN_COND_COLDSTART                 0x02u
#define DEM_IUMPR_DEN_COND_EVAP                      0x03u
#define DEM_IUMPR_DEN_COND_500MI                     0x04u

typedef uint8 Dem_IumprDenomCondStatusType;
#define DEM_IUMPR_DEN_STATUS_NOT_REACHED             0x00u
#define DEM_IUMPR_DEN_STATUS_REACHED                 0x01u
#define DEM_IUMPR_DEN_STATUS_INHIBITED               0x02u

#endif /* RTE_DEM_TYPE_H */

