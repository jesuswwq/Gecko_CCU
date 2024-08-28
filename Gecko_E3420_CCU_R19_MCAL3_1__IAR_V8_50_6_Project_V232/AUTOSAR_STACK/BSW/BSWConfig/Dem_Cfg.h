/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-06-03 13:54:47>
 */
/*============================================================================*/

#ifndef DEM_CFG_H_
#define DEM_CFG_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_Types.h"
#include "Dem_CfgEnum.h"
#include "Rte_Dem.h"

/*******************************************************************************
*                          General Configuration
*******************************************************************************/
/* DemAvailabilitySupport type: Enum
#define DEM_EVENT_AVAILABILITY 1
#define DEM_NO_AVAILABILITY 2 */
#define DEM_AVAILABILITY_SUPPORT DEM_EVENT_AVAILABILITY

/* DemBswErrorBufferSize Range:0~255 */
#define DEM_BSW_ERROR_BUFFER_SIZE 120u

/* DemClearDTCBehavior type: Enum
#define DEM_CLRRESP_NONVOLATILE_FINISH 1
#define DEM_CLRRESP_NONVOLATILE_TRIGGER 2
#define DEM_CLRRESP_VOLATILE 3 */
#define DEM_CLEAR_DTCBEHAVIOR DEM_CLRRESP_NONVOLATILE_TRIGGER

/* DemClearDTCLimitation type: Enum
#define DEM_ALL_SUPPORTED_DTCS 1
#define DEM_ONLY_CLEAR_ALL_DTCS 2 */
#define DEM_CLEAR_DTCLIMITATION DEM_ALL_SUPPORTED_DTCS

/* DemDebounceCounterBasedSupport Range: true or false */
#define DEM_DEBOUNCE_COUNTER_BASED_SUPPORT STD_ON

/* DemDebounceTimeBasedSupport Range: true or false */
#define DEM_DEBOUNCE_TIME_BASED_SUPPORT STD_ON

/* DemDevErrorDetect Range: true or false */
#define DEM_DEV_ERROR_DETECT STD_OFF

/* DemEnvironmentDataCapture type: Enum
#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING 1
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING 2 */
#define DEM_ENVIRONMENT_DATA_CAPTURE DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING

/* DemEventCombinationSupport type: Enum
#define DEM_EVCOMB_DISABLED 1
#define DEM_EVCOMB_ONRETRIEVAL 2
#define DEM_EVCOMB_ONSTORAGE 3 */
#define DEM_EVENT_COMBINATION_SUPPORT DEM_EVCOMB_ONSTORAGE

/* DemEventDisplacementStrategy type: Enum
#define DEM_DISPLACEMENT_FULL 1
#define DEM_DISPLACEMENT_NONE 2
#define DEM_DISPLACEMENT_PRIO_OCC 3 */
#define DEM_EVENT_DISPLACEMENT_STRATEGY DEM_DISPLACEMENT_FULL

/* DemEventMemoryEntryStorageTrigger type: Enum
#define DEM_TRIGGER_ON_CONFIRMED 1
#define DEM_TRIGGER_ON_FDC_THRESHOLD 2
#define DEM_TRIGGER_ON_PENDING 3
#define DEM_TRIGGER_ON_TEST_FAILED 4 */
#define DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER DEM_TRIGGER_ON_TEST_FAILED

/* DemGeneralInterfaceSupport Range: true or false */
#define DEM_GENERAL_INTERFACE_SUPPORT STD_OFF

/* DemImmediateNvStorageLimit Range:1~255 */
#define DEM_IMMEDIATE_NV_STORAGE_LIMIT 0xffu

/* DemMaxNumberEventEntryEventBuffer Range:1~250 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_EVENT_BUFFER 120u

/* DemMaxNumberPrestoredFF Range:0~255 */
#define DEM_MAX_NUMBER_PRESTORED_FF 0u

/* DemOccurrenceCounterProcessing type: Enum
#define DEM_PROCESS_OCCCTR_CDTC 1
#define DEM_PROCESS_OCCCTR_TF 2 */ /*the occurrence counter is only
triggered by the TestFailed bit (and the fault confirmation is not considered) This parameter is mandatory in case of J1939*/
#define DEM_OCCURRENCE_COUNTER_PROCESSING DEM_PROCESS_OCCCTR_TF

/* DemOperationCycleStatusStorage Range: true or false */
#define DEM_OPERATION_CYCLE_STATUS_STORAGE STD_OFF

/*DemPTOSupport*/
#define DEM_PTO_SUPPORT STD_OFF

/* DemResetConfirmedBitOnOverflow Range: true or false */
#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW STD_OFF

/* DemGeneral/DemStatusBitHandlingTestFailedSinceLastClear
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT 1
#define DEM_STATUS_BIT_NORMAL 2 */
#define DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR DEM_STATUS_BIT_NORMAL

/* DemStatusBitStorageTestFailed Range: true or false */
#define DEM_STATUS_BIT_STORAGE_TEST_FAILED STD_OFF

/* DemSuppressionSupport type: Enum
#define DEM_DTC_SUPPRESSION 1
#define DEM_NO_SUPPRESSION 2 */
#define DEM_SUPPRESSION_SUPPORT DEM_NO_SUPPRESSION

/* DemTaskTime */
#define DEM_TASK_TIME 10u

/* DemTriggerDcmReports Range: true or false */
#define DEM_TRIGGER_DCM_REPORTS STD_OFF

/* DemTriggerDltReports Range: true or false */
#define DEM_TRIGGER_DLT_REPORTS STD_OFF

/* DemTriggerFiMReports Range: true or false */
#define DEM_TRIGGER_FIM_REPORTS STD_OFF

/* DemTriggerMonitorInitBeforeClearOk Range: true or false */
#define DEM_TRIGGER_MONITOR_INIT_BEFORE_CLEAR_OK STD_OFF

/* DemTypeOfDTCSupported type: Enum
#define DEM_DTC_TRANSLATION_ISO11992_4 1
#define DEM_DTC_TRANSLATION_ISO14229_1 2
#define DEM_DTC_TRANSLATION_ISO15031_6 3
#define DEM_DTC_TRANSLATION_SAEJ1939_73 4
#define DEM_DTC_TRANSLATION_SAE_J2012_DA_DTCFORMAT_04 5 */
#define DEM_TYPE_OF_DTCSUPPORTED DEM_DTC_TRANSLATION_ISO15031_6

/* DemTypeOfFreezeFrameRecordNumeration type: Enum
#define DEM_FF_RECNUM_CALCULATED 1
#define DEM_FF_RECNUM_CONFIGURED 2 */
#define DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION DEM_FF_RECNUM_CONFIGURED

/* DemVersionInfoApi Range: true or false */
#define DEM_VERSION_INFO_API STD_OFF

/* COUNT(DemGeneral/DemCallbackDTCStatusChanged) 0-* */
#define DEM_CALLBACK_DTC_STATUS_CHANGED_NUM 0u

/* DemAgingRequieresTestedCycle Range: true or false */
#define DEM_AGING_REQUIERES_TESTED_CYCLE STD_OFF

#define DEM_DEAL_MAINFUNCTION_ENABLE   STD_OFF

#define DEM_ENABLE_SOFT_FILTER_OF_PASS STD_OFF

#define DEM_NVRAM_DIVADED    STD_ON

/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
/*DemDataElementClass*/
#define DEM_DATA_ELEMENT_CLASS_NUM  9

#define DEM_EXTERAL_DATA_ELEMENT_CLASS_NUM  8u

/*******************************************************************************
*                          Condition Configuration
*******************************************************************************/
/* DemOperationCycle 1-256 */
#define DEM_OPERATION_CYCLE_NUM 1u

#define DemOperationCycle_ID 0u

/* DemEnableCondition 0-255 */
#define DEM_ENABLE_CONDITION_NUM 0u

/* DemEnableConditionGroup 0-255 */
#define DEM_ENABLE_CONDITION_GROUP_NUM 0u

/* DemEnableCondition 0-255 */
#define DEM_STORAGE_CONDITION_NUM 0u

/* DemStorageConditionGroup 0-255 */
#define DEM_STORAGE_CONDITION_GROUP_NUM 0u
/*******************************************************************************
*                          FreezeFrame Configuration
*******************************************************************************/
#define DEM_FFPRESTORAGE_SUPPORT   STD_OFF

/* DemSPNClass 0-0xFFFF */
#define DEM_SPN_CLASS_NUM 0u

#define DEM_J1939_FREEZE_FRAME_CLASS_NUM 0u

#define DEM_SPN_CLASS_REF_TOTAL_NUM 0u

/* DemDidClass 0-0xFFFF */
#define DEM_DID_CLASS_NUM 7u

/* DemFreezeFrameClass 0-65535 */
#define DEM_FREEZE_FRAME_CLASS_NUM 1u

/* SUM(COUNT(DemFreezeFrameClass/DemDidClassRef)) */
#define DEM_DID_CLASS_REF_TOTAL_NUM 7u

/* DemFreezeFrameRecordClass 0-255 */
#define DEM_FREEZE_FRAME_RECORD_CLASS_NUM 2u

#define DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)) */
#define DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM 1u

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
/* MAX(COUNT((DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)))  1-254 */
#define DEM_MAX_NUMBER_FF_RECORDS 1u
#endif

/* DemPidClass 0-0xFFFF */
#define DEM_PID_CLASS_NUM 0u
#define DEM_PID_TOTAL_SIZE  0u /*total size of all pid*/

/* max value of PID and all ref freezeframe size) */
#define DEM_FREEZE_FRAME_MAX_LEN 15u
/*******************************************************************************
*                          ExtendedData Configuration
*******************************************************************************/
/* DemExtendedDataRecordClass 0-253 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_NUM 1u

/* DemExtendedDataClass 0-* */
#define DEM_EXTENDED_DATA_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
/* PRQA S 0791++ */ /* MISRA Rule 5.4 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM  1u
/* PRQA S 0791-- */ /* MISRA Rule 5.4 */

/* MAX(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
#define DEM_EXTENDED_DATA_MAX_REF_NUM 1u

/* MAX(SUM(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef/DataSize)) */
#define DEM_EXTENDED_DATA_MAX_LEN 2u
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/
/* DemGroupOfDTC 0-255 */
#define DEM_GROUP_OF_DTC_NUM 4u

#define DEM_DTC_REF_EMISSION_NUM  0u

/* DemDTC 0-65535 */
#define DEM_DTC_NUM 193u

#define DEM_WWWOBD_NUM 0u

/* DemDTCAttributes 0-65535 */
#define DEM_DTC_ATTRIBUTES_NUM 1u

/* DemDtcStatusAvailabilityMask Range:0~255 */
#define DEM_DTC_STATUS_AVAILABILITY_MASK 0x4fu

#define DEM_J1939_NODE_NUM 0u
#define DEM_J1939_NODEID_MAX_NUM  0u

/* DemObdDTC 0-65535 */
#define DEM_OBD_DTC_NUM 0u

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CALCULATED)
/* MAX(DemConfigSet/DemDTCAttributes/DemMaxNumberFreezeFrameRecords) */
#define DEM_MAX_NUMBER_FF_RECORDS 0u
#endif

/*******************************************************************************
*                          Indicator Configuration
*******************************************************************************/
/* DemIndicator 0..255 */
#define DEM_INDICATOR_NUM 0u

/*DemMILIndicatorRef*/
#define DEM_MALFUNCTION_LAMP_INDICATOR DemIndicator_INVALID

/*DemProtectLampIndicatorRef */
#define DEM_PROTECT_LAMP_INDICATOR DemIndicator_INVALID

/*DemRedStopLampIndicatorRef */
#define DEM_RED_STOP_LAMP_INDICATOR DemIndicator_INVALID

/*DemAmberWarningLampIndicatorRef */
#define DEM_AMBER_WARING_LAMP_INDICATOR DemIndicator_INVALID

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemIndicatorAttribute)) */
#define DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM 0u

/*******************************************************************************
*                          Debounce Configuration
*******************************************************************************/
/* DemDebounceCounterBasedClass 0-65535 */
#define DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM 1u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE ((DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased)
 *         && DemDebounceCounterBased/DemDebounceCounterBasedClassRef/DemDebounceCounterStorage == true) */
#define DEM_DEBOUNCE_COUNTER_STORAGE_NUM 0u

/* DemDebounceTimeBaseClass 0-65535 */
#define DEM_DEBOUNCE_TIME_BASE_CLASS_NUM 1u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceTimeBase) */
#define DEM_DEBOUNCE_TIME_BASED_EVENT_NUM 1u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased) */
#define DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM 5u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceMonitorInternal) */
#define DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM 0u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackEventStatusChanged))) */
#define DEM_CALLBACK_EVENT_STATUS_CHANGED_TOTAL_NUM 0u

/*******************************************************************************
*                          Event Configuration
*******************************************************************************/
/*DemComponentClass*/
#define DEM_COMPONENT_NUM 0u

#define DEM_IMMEDITE_CHILD_COMPONENT_MAX_NUM  0u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackClearEventAllowed))) */
#define DEM_CALLBACK_CLEAR_EVENT_ALLOWED_TOTAL_NUM 0u

/* DemEventParameter 1-65535 */
#define DEM_EVENT_PARAMETER_NUM 193u

#define DemEventParameter_0xD11D87  1u
#define DemEventParameter_0x100083  2u
#define DemEventParameter_0x100116  3u
#define DemEventParameter_0x100117  4u
#define DemEventParameter_0x100316  5u
#define DemEventParameter_0x100317  6u
#define DemEventParameter_0x100716  7u
#define DemEventParameter_0x100717  8u
#define DemEventParameter_0x100D16  9u
#define DemEventParameter_0x100D17  10u
#define DemEventParameter_0x101201  11u
#define DemEventParameter_0x101501  12u
#define DemEventParameter_0x101601  13u
#define DemEventParameter_0x101701  14u
#define DemEventParameter_0x101D68  15u
#define DemEventParameter_0x102093  16u
#define DemEventParameter_0x10211A  17u
#define DemEventParameter_0x102496  18u
#define DemEventParameter_0x102596  19u
#define DemEventParameter_0x102696  20u
#define DemEventParameter_0x102796  21u
#define DemEventParameter_0x103093  22u
#define DemEventParameter_0x103196  23u
#define DemEventParameter_0x103296  24u
#define DemEventParameter_0x103396  25u
#define DemEventParameter_0x103496  26u
#define DemEventParameter_0x104093  27u
#define DemEventParameter_0x103996  28u
#define DemEventParameter_0x104196  29u
#define DemEventParameter_0x104296  30u
#define DemEventParameter_0x104396  31u
#define DemEventParameter_0x104496  32u
#define DemEventParameter_0x104696  33u
#define DemEventParameter_0x104796  34u
#define DemEventParameter_0x104896  35u
#define DemEventParameter_0x105093  36u
#define DemEventParameter_0x105196  37u
#define DemEventParameter_0x105496  38u
#define DemEventParameter_0x105596  39u
#define DemEventParameter_0x105693  40u
#define DemEventParameter_0x105796  41u
#define DemEventParameter_0x105896  42u
#define DemEventParameter_0x105996  43u
#define DemEventParameter_0x105B96  44u
#define DemEventParameter_0x105C96  45u
#define DemEventParameter_0x108186  46u
#define DemEventParameter_0x108286  47u
#define DemEventParameter_0x108486  48u
#define DemEventParameter_0x109077  49u
#define DemEventParameter_0x109196  50u
#define DemEventParameter_0x109296  51u
#define DemEventParameter_0x109396  52u
#define DemEventParameter_0x109496  53u
#define DemEventParameter_0x10A182  54u
#define DemEventParameter_0x102A84  55u
#define DemEventParameter_0x100517  56u
#define DemEventParameter_0x100696  57u
#define DemEventParameter_0x101D96  58u
#define DemEventParameter_0x101E96  59u
#define DemEventParameter_0x10221C  60u
#define DemEventParameter_0x10231C  61u
#define DemEventParameter_0x10284B  62u
#define DemEventParameter_0x101F96  63u
#define DemEventParameter_0x105A96  64u
#define DemEventParameter_0x101301  65u
#define DemEventParameter_0x101401  66u
#define DemEventParameter_0x900011  67u
#define DemEventParameter_0x900013  68u
#define DemEventParameter_0x900111  69u
#define DemEventParameter_0x900113  70u
#define DemEventParameter_0x900211  71u
#define DemEventParameter_0x900213  72u
#define DemEventParameter_0x900311  73u
#define DemEventParameter_0x900313  74u
#define DemEventParameter_0x900412  75u
#define DemEventParameter_0x900512  76u
#define DemEventParameter_0x900711  77u
#define DemEventParameter_0x900811  78u
#define DemEventParameter_0x900923  79u
#define DemEventParameter_0x900924  80u
#define DemEventParameter_0x900A23  81u
#define DemEventParameter_0x900A24  82u
#define DemEventParameter_0x900B23  83u
#define DemEventParameter_0x900B24  84u
#define DemEventParameter_0x900C23  85u
#define DemEventParameter_0x900C24  86u
#define DemEventParameter_0x900D23  87u
#define DemEventParameter_0x900D24  88u
#define DemEventParameter_0x900E23  89u
#define DemEventParameter_0x900E24  90u
#define DemEventParameter_0x901016  91u
#define DemEventParameter_0x901116  92u
#define DemEventParameter_0x901216  93u
#define DemEventParameter_0x901316  94u
#define DemEventParameter_0x901031  95u
#define DemEventParameter_0x901131  96u
#define DemEventParameter_0x901231  97u
#define DemEventParameter_0x901331  98u
#define DemEventParameter_0x90141C  99u
#define DemEventParameter_0xF00116  100u
#define DemEventParameter_0xF00117  101u
#define DemEventParameter_0xC04688  102u
#define DemEventParameter_0xC05588  103u
#define DemEventParameter_0xC07388  104u
#define DemEventParameter_0xC06488  105u
#define DemEventParameter_0xC12287  106u
#define DemEventParameter_0xD10287  107u
#define DemEventParameter_0xD11287  108u
#define DemEventParameter_0xD10E87  109u
#define DemEventParameter_0xC13087  110u
#define DemEventParameter_0xC15187  111u
#define DemEventParameter_0xD11687  112u
#define DemEventParameter_0xC19887  113u
#define DemEventParameter_0xC11287  114u
#define DemEventParameter_0xD10887  115u
#define DemEventParameter_0xC10F87  116u
#define DemEventParameter_0xC23087  117u
#define DemEventParameter_0xC14687  118u
#define DemEventParameter_0xE10005  119u
#define DemEventParameter_0xD11F00  120u
#define DemEventParameter_0xD11F87  121u
#define DemEventParameter_0xD12014  122u
#define DemEventParameter_0xD12100  123u
#define DemEventParameter_0xD12241  124u
#define DemEventParameter_0x901416  125u
#define DemEventParameter_0x941211  126u
#define DemEventParameter_0x941215  127u
#define DemEventParameter_0x941311  128u
#define DemEventParameter_0x941315  129u
#define DemEventParameter_0x941411  130u
#define DemEventParameter_0x941515  131u
#define DemEventParameter_0x941A11  132u
#define DemEventParameter_0x941A15  133u
#define DemEventParameter_0x941B11  134u
#define DemEventParameter_0x941B15  135u
#define DemEventParameter_0x941D11  136u
#define DemEventParameter_0x941D15  137u
#define DemEventParameter_0x941E11  138u
#define DemEventParameter_0x941E15  139u
#define DemEventParameter_0x941F11  140u
#define DemEventParameter_0x941F15  141u
#define DemEventParameter_0x942011  142u
#define DemEventParameter_0x942015  143u
#define DemEventParameter_0x942111  144u
#define DemEventParameter_0x942115  145u
#define DemEventParameter_0x942211  146u
#define DemEventParameter_0x942215  147u
#define DemEventParameter_0x942386  148u
#define DemEventParameter_0x942229  149u
#define DemEventParameter_0x942416  150u
#define DemEventParameter_0x942417  151u
#define DemEventParameter_0x942516  152u
#define DemEventParameter_0x942517  153u
#define DemEventParameter_0x942604  154u
#define DemEventParameter_0x942629  155u
#define DemEventParameter_0x942719  156u
#define DemEventParameter_0x942803  157u
#define DemEventParameter_0x942929  158u
#define DemEventParameter_0x942A29  159u
#define DemEventParameter_0x942B29  160u
#define DemEventParameter_0x942C29  161u
#define DemEventParameter_0x942D98  162u
#define DemEventParameter_0x942E98  163u
#define DemEventParameter_0x942B98  164u
#define DemEventParameter_0x942C98  165u
#define DemEventParameter_0x942F1D  166u
#define DemEventParameter_0x942098  167u
#define DemEventParameter_0x943198  168u
#define DemEventParameter_0x943211  169u
#define DemEventParameter_0x943215  170u
#define DemEventParameter_0x943271  171u
#define DemEventParameter_0x943311  172u
#define DemEventParameter_0x943315  173u
#define DemEventParameter_0x943371  174u
#define DemEventParameter_0x943411  175u
#define DemEventParameter_0x943415  176u
#define DemEventParameter_0x943571  177u
#define DemEventParameter_0x943779  178u
#define DemEventParameter_0x943786  179u
#define DemEventParameter_0x943782  180u
#define DemEventParameter_0x943705  181u
#define DemEventParameter_0x943704  182u
#define DemEventParameter_0x943979  183u
#define DemEventParameter_0x94374B  184u
#define DemEventParameter_0x943716  185u
#define DemEventParameter_0x943717  186u
#define DemEventParameter_0x943719  187u
#define DemEventParameter_0x943871  188u
#define DemEventParameter_0x943898  189u
#define DemEventParameter_0x94384B  190u
#define DemEventParameter_0x943821  191u
#define DemEventParameter_0x943817  192u
#define DemEventParameter_0x943816  193u
/*******************************************************************************
*                          Memory Configuration
*******************************************************************************/
/* COUNT(DemGeneral/Dem<xx>Memory) */
#define DEM_MEM_DEST_TOTAL_NUM 1u

/* MAX(DemGeneral/Dem<XX>Memory/DemMaxNumberEventEntry<XX>) */
#define DEM_MEM_DEST_MAX_ENTRY_NUM 50u

/* DemMaxNumberEventEntryPermanent Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT 0u

/* DemPrimaryMemory 1-1 */
/* DemMaxNumberEventEntryPrimary Range:1~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY 50u

/* DemMirrorMemory 0-1 */
/* DemMaxNumberEventEntryMirror Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIRROR  0u

/*DemMaxNumberEventEntryUserDefined*/

/*DemUserDefinedMemoryIdentifier*/

/* COUNT(DemGeneral/DemNvRamBlockId) */
#define DEM_NVRAM_BLOCKID_NUM 52

#define DEM_NVRAM_DIVADED    STD_ON

/* MAX(DemConfigSet/DemDTCAttributes/DemMemoryDestinationRef) 0~2 */
#define DEM_MEM_DEST_MAX_NUM_OF_DTC 1u /* DemMemoryDestinationRef 0-2 */
/*******************************************************************************
*                          OBD Configuration
*******************************************************************************/
/*DemOBDSupport
 * #define DEM_OBD_DEP_SEC_ECU 1
#define DEM_OBD_MASTER_ECU 2
#define DEM_OBD_NO_OBD_SUPPORT 3
#define DEM_OBD_PRIMARY_ECU 4*/
#define DEM_OBD_SUPPORT DEM_OBD_NO_OBD_SUPPORT

#define DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM 0u

#define DEM_SECONDARY_FUNCTIONID_REF_MAX_NUM  2u

#define DEM_RATIO_NUM 0u

#define DEM_DTR_NUM 0u

/*******************************************************************************
*                          J1939 Configuration
*******************************************************************************/
#define DEM_J1939_SUPPORT STD_OFF

#endif /* DEM_CFG_H_ */
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

