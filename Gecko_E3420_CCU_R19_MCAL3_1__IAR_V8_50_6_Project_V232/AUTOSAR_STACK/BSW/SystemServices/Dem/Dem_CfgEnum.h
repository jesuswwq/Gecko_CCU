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
**  FILENAME    : Dem_CfgEnum.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : CfgEnum definitions of DEM                                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef DEM_CFGENUM_H_
#define DEM_CFGENUM_H_

/*******************************************************************************
**                       Include Section                                      **
*******************************************************************************/

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
#define DEM_BITS_TO_BYTE(x) (((x) + 7u) >> 3u)

/* DemEventMemoryEntryStorageTrigger */
#define DEM_TRIGGER_ON_CONFIRMED     0x00u
#define DEM_TRIGGER_ON_FDC_THRESHOLD 0x01u
#define DEM_TRIGGER_ON_MIRROR        0x02u
#define DEM_TRIGGER_ON_PASSED        0x03u
#define DEM_TRIGGER_ON_PENDING       0x04u
#define DEM_TRIGGER_ON_TEST_FAILED   0x05u

/* DemAvailabilitySupport */
#define DEM_EVENT_AVAILABILITY 1u
#define DEM_NO_AVAILABILITY    2u

/* DemClearDTCBehavior  */
#define DEM_CLRRESP_NONVOLATILE_FINISH  1u
#define DEM_CLRRESP_NONVOLATILE_TRIGGER 2u
#define DEM_CLRRESP_VOLATILE            3u

/* DemClearDTCLimitation */
#define DEM_ALL_SUPPORTED_DTCS  1u
#define DEM_ONLY_CLEAR_ALL_DTCS 2u

/* DemEnvironmentDataCapture */
#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING 1u
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING  2u

/* DemEventCombinationSupport */
#define DEM_EVCOMB_DISABLED    1u
#define DEM_EVCOMB_ONRETRIEVAL 2u
#define DEM_EVCOMB_ONSTORAGE   3u

/* DemEventDisplacementStrategy  */
#define DEM_DISPLACEMENT_FULL     1u
#define DEM_DISPLACEMENT_NONE     2u
#define DEM_DISPLACEMENT_PRIO_OCC 3u

/* DemOBDSupport  */
#define DEM_OBD_DEP_SEC_ECU    1u
#define DEM_OBD_MASTER_ECU     2u
#define DEM_OBD_NO_OBD_SUPPORT 3u
#define DEM_OBD_PRIMARY_ECU    4u

/* DemOccurrenceCounterProcessing  */
#define DEM_PROCESS_OCCCTR_CDTC 1u
#define DEM_PROCESS_OCCCTR_TF   2u

/* DemStatusBitHandlingTestFailedSinceLastClear  */
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT 1u
#define DEM_STATUS_BIT_NORMAL                 2u

/* DemSuppressionSupport  */
#define DEM_DTC_SUPPRESSION 1u
#define DEM_NO_SUPPRESSION  2u

/* DemTypeOfDTCSupported  */
/* DEM_DTC_TRANSLATION_ISO11992_4 1u
 * DEM_DTC_TRANSLATION_ISO14229_1 2u
 * DEM_DTC_TRANSLATION_ISO15031_6 3u
 * DEM_DTC_TRANSLATION_SAEJ1939_73 4u
 */
#define DEM_DTC_TRANSLATION_SAE_J2012_DA_DTCFORMAT_04 5u

/* DemTypeOfFreezeFrameRecordNumeration  */
#define DEM_FF_RECNUM_CALCULATED 1u
#define DEM_FF_RECNUM_CONFIGURED 2u

/* DemDtrUpdateKind */
#define DEM_DTR_UPDATE_ALWAYS 1u
#define DEM_DTR_UPDATE_STEADY 2u

#define DEM_UPDATE_RECORD_NO  0u
#define DEM_UPDATE_RECORD_YES 1u

/* DemOperationCycleType */
#define DEM_OPCYC_IGNITION 0u
#define DEM_OPCYC_OBD_DCY  1u
#define DEM_OPCYC_OTHER    2u
#define DEM_OPCYC_POWER    3u
#define DEM_OPCYC_TIME     4u
#define DEM_OPCYC_WARMUP   5u

/* DemIUMPRDenGroup */
#define DEM_IUMPR_DEN_500MILL   0u
#define DEM_IUMPR_DEN_COLDSTART 1u
#define DEM_IUMPR_DEN_EVAP      2u
#define DEM_IUMPR_DEN_NONE      3u
#define DEM_IUMPR_DEN_PHYS_API  4u

/* DemInternalDataElement  */
#define DEM_AGINGCTR_DOWNCNT             0u
#define DEM_AGINGCTR_UPCNT               1u
#define DEM_CURRENT_FDC                  2u
#define DEM_CYCLES_SINCE_FIRST_FAILED    3u
#define DEM_CYCLES_SINCE_LAST_FAILED     4u
#define DEM_FAILED_CYCLES                5u
#define DEM_MAX_FDC_DURING_CURRENT_CYCLE 6u
#define DEM_MAX_FDC_SINCE_LAST_CLEAR     7u
#define DEM_OCCCTR                       8u
#define DEM_OVFLIND                      9u
#define DEM_SIGNIFICANCE                 10u

/* DemWWHOBDDTCClass */
#define DEM_DTC_WWHOBD_CLASS_NOCLASS 0u
#define DEM_DTC_WWHOBD_CLASS_A       1u
#define DEM_DTC_WWHOBD_CLASS_B1      2u
#define DEM_DTC_WWHOBD_CLASS_B2      3u
#define DEM_DTC_WWHOBD_CLASS_C       4u

/* DemDTCSignificance */
#define DEM_EVENT_SIGNIFICANCE_FAULT      0u
#define DEM_EVENT_SIGNIFICANCE_OCCURRENCE 1u

/* DemDebounceBehavior */
#define DEM_DEBOUNCE_FREEZE               0u
#define DEM_DEBOUNCE_RESET                1u

#define DEM_NO_STATUS_BYTE_CHANGE         0u
#define DEM_ONLY_THIS_CYCLE_AND_READINESS 1u

/* DemEventKind */
#define DEM_EVENT_KIND_BSW 0u
#define DEM_EVENT_KIND_SWC 1u

/* DemReportBehavior */
#define REPORT_AFTER_INIT  0u
#define REPORT_BEFORE_INIT 1u

/* DemDebounceType */
#define DEM_DEBOUNCE_COUNTER_BASED    0u
#define DEM_DEBOUNCE_TIME_BASE        1u
#define DEM_DEBOUNCE_MONITOR_INTERNAL 2u

/* DemEventOBDReadinessGroup */
#define DEM_OBD_RDY_MISF          0u
#define DEM_OBD_RDY_FLSYS         1u
#define DEM_OBD_RDY_CMPRCMPT      2u
#define DEM_OBD_RDY_CAT           4u
#define DEM_OBD_RDY_HTCAT         5u
#define DEM_OBD_RDY_EVAP          6u
#define DEM_OBD_RDY_SECAIR        7u
#define DEM_OBD_RDY_AC            8u
#define DEM_OBD_RDY_O2SENS        9u
#define DEM_OBD_RDY_O2SENSHT      10u
#define DEM_OBD_RDY_ERG           11u
#define DEM_OBD_RDY_BOOSTPR       13u
#define DEM_OBD_RDY_EGSENS        20u
#define DEM_OBD_RDY_FLSYS_NONCONT 21u
#define DEM_OBD_RDY_HCCAT         22u
#define DEM_OBD_RDY_NONE          23u
#define DEM_OBD_RDY_NOXCAT        24u
#define DEM_OBD_RDY_PMFLT         25u

#define DEM_OBD_RDY_INVAILD       0xFFu

/* DemOBDEngineType */
#define DEM_IGNITION_COMPRESSION 0u
#define DEM_IGNITION_SPARK       1u

/*Invalid*/
#define DEM_DATA_ELEMENT_CLASS_NUM_INVALID  0xFFu
#define DEM_ENABLE_CONDITION_GROUP_INVALID  0xFFu
#define DEM_EXTENDED_DATA_RECORD_INVALID    0xFFu
#define DEM_EXTENDED_DATA_INVALID           0xFFFFu
#define DEM_FREEZE_FRAME_INVALID            0xFFFFu
#define DEM_FREEZE_FRAME_RECORD_INVALID     0xFFu
#define DEM_FREEZE_FRAME_REC_NUM_INVALID    0xFFu
#define DemIndicator_INVALID                0xFFu
#define DEM_GROUP_OF_DTC_INVALID            0xFFu
#define DEM_MEM_DEST_INVALID                0xFFu
#define DEM_STORAGE_CONDITION_GROUP_INVALID 0xFFu
#define DEM_EVENT_PARAMETER_INVALID         0xFFFFu
#define DEM_COMPONENT_INVALID               0xFFFFu
#define DEM_DTC_REF_INVALID                 0xFFFFu
#define DEM_OBD_DTC_INVALID                 0xFFFFu
#define DEM_DTC_CFG_INVALID                 0xFFFFFFu
#define DEM_OBD_DTC_CFG_INVALID             0xFFFFu
#define DEM_J1939_DTC_CFG_INVALID           0xFFFFFFu
#define DEM_OPERATION_CYCLE_INVALID         0xFFu
#define DEM_J1939_NODE_INVALID              0xFFu
#define DEM_J1939_FREEZE_FRAME_INVALID      0xFFu
#define DEM_WWHOBD_FREEZE_FRAME_INVALID     0xFFu

/*DEM_BITS_TO_BYTE*/
#define DEM_ENABLE_CONDITION_NUM_BYTE      DEM_BITS_TO_BYTE(DEM_ENABLE_CONDITION_NUM)

#define DEM_EXTENDED_DATA_MAX_REF_NUM_BYTE DEM_BITS_TO_BYTE(DEM_EXTENDED_DATA_MAX_REF_NUM)

#define DEM_GROUP_OF_DTC_NUM_BYTE          DEM_BITS_TO_BYTE(DEM_GROUP_OF_DTC_NUM)

#define DEM_MEM_DEST_MAX_ENTRY_NUM_BYTE    DEM_BITS_TO_BYTE(DEM_MEM_DEST_MAX_ENTRY_NUM)

#define DEM_OPERATION_CYCLE_NUM_BYTE       DEM_BITS_TO_BYTE(DEM_OPERATION_CYCLE_NUM)

#define DEM_STORAGE_CONDITION_NUM_BYTE     DEM_BITS_TO_BYTE(DEM_STORAGE_CONDITION_NUM)

#define DEM_EVENT_PARAMETER_NUM_BYTE       DEM_BITS_TO_BYTE(DEM_EVENT_PARAMETER_NUM)

#define DEM_DTC_NUM_BYTE                   DEM_BITS_TO_BYTE(DEM_DTC_NUM)

#define DEM_OBD_DTC_NUM_BYTE               DEM_BITS_TO_BYTE(DEM_OBD_DTC_NUM)

#endif /* DEM_CFGENUM_H_ */
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
