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
 *  @date       <2024-12-17 15:58:42>
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
#define DEM_OPERATION_CYCLE_NUM 2u

#define DemOperationCycle_ID 0u
#define DemOperationCycle_Aging_ID 1u

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
#define DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM 2u

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
/* MAX(COUNT((DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)))  1-254 */
#define DEM_MAX_NUMBER_FF_RECORDS 2u
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
#define DEM_DTC_NUM 280u

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
#define DEM_EVENT_PARAMETER_NUM 280u

#define DemEventParameter_0xD11D87  1u
#define DemEventParameter_0x100083  2u
#define DemEventParameter_0x100116  3u
#define DemEventParameter_0x100117  4u
#define DemEventParameter_0x100316  5u
#define DemEventParameter_0x100317  6u
#define DemEventParameter_0x100716  7u
#define DemEventParameter_0x100717  8u
#define DemEventParameter_0x100D16  9u
#define DemEventParameter_0x100E17  10u
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
#define DemEventParameter_0x901416  120u
#define DemEventParameter_0x941211  121u
#define DemEventParameter_0x941215  122u
#define DemEventParameter_0x941311  123u
#define DemEventParameter_0x941315  124u
#define DemEventParameter_0x941411  125u
#define DemEventParameter_0x941515  126u
#define DemEventParameter_0x941A11  127u
#define DemEventParameter_0x941A15  128u
#define DemEventParameter_0x941B11  129u
#define DemEventParameter_0x941B15  130u
#define DemEventParameter_0x941D11  131u
#define DemEventParameter_0x941D15  132u
#define DemEventParameter_0x941E11  133u
#define DemEventParameter_0x941E15  134u
#define DemEventParameter_0x941F11  135u
#define DemEventParameter_0x941F15  136u
#define DemEventParameter_0x942011  137u
#define DemEventParameter_0x942015  138u
#define DemEventParameter_0x942111  139u
#define DemEventParameter_0x942115  140u
#define DemEventParameter_0x942211  141u
#define DemEventParameter_0x942215  142u
#define DemEventParameter_0x942386  143u
#define DemEventParameter_0x942229  144u
#define DemEventParameter_0x942416  145u
#define DemEventParameter_0x942417  146u
#define DemEventParameter_0x942516  147u
#define DemEventParameter_0x942517  148u
#define DemEventParameter_0x942604  149u
#define DemEventParameter_0x942629  150u
#define DemEventParameter_0x942719  151u
#define DemEventParameter_0x942803  152u
#define DemEventParameter_0x942929  153u
#define DemEventParameter_0x942A29  154u
#define DemEventParameter_0x942B29  155u
#define DemEventParameter_0x942C29  156u
#define DemEventParameter_0x942D98  157u
#define DemEventParameter_0x942E98  158u
#define DemEventParameter_0x942B98  159u
#define DemEventParameter_0x942C98  160u
#define DemEventParameter_0x942F1D  161u
#define DemEventParameter_0x942098  162u
#define DemEventParameter_0x943198  163u
#define DemEventParameter_0x943211  164u
#define DemEventParameter_0x943215  165u
#define DemEventParameter_0x943271  166u
#define DemEventParameter_0x943311  167u
#define DemEventParameter_0x943315  168u
#define DemEventParameter_0x943371  169u
#define DemEventParameter_0x943411  170u
#define DemEventParameter_0x943415  171u
#define DemEventParameter_0x943571  172u
#define DemEventParameter_0x943779  173u
#define DemEventParameter_0x943786  174u
#define DemEventParameter_0x943782  175u
#define DemEventParameter_0x943705  176u
#define DemEventParameter_0x943704  177u
#define DemEventParameter_0x943979  178u
#define DemEventParameter_0x94374B  179u
#define DemEventParameter_0x943716  180u
#define DemEventParameter_0x943717  181u
#define DemEventParameter_0x943719  182u
#define DemEventParameter_0x943871  183u
#define DemEventParameter_0x943817  184u
#define DemEventParameter_0x943816  185u
#define DemEventParameter_0xC24087  186u
#define DemEventParameter_0xC27087  187u
#define DemEventParameter_0xC13187  188u
#define DemEventParameter_0x943A04  189u
#define DemEventParameter_0x943B04  190u
#define DemEventParameter_0x10A296  191u
#define DemEventParameter_0x10A396  192u
#define DemEventParameter_0x10A496  193u
#define DemEventParameter_0x10A596  194u
#define DemEventParameter_0x10A696  195u
#define DemEventParameter_0x10A796  196u
#define DemEventParameter_0x10A896  197u
#define DemEventParameter_0x10A996  198u
#define DemEventParameter_0x10AA96  199u
#define DemEventParameter_0x10AB96  200u
#define DemEventParameter_0x10AC83  201u
#define DemEventParameter_0xC11282  202u
#define DemEventParameter_0xC12282  203u
#define DemEventParameter_0xD10282  204u
#define DemEventParameter_0xD11282  205u
#define DemEventParameter_0xD10E82  206u
#define DemEventParameter_0xC13082  207u
#define DemEventParameter_0xC15182  208u
#define DemEventParameter_0xD11682  209u
#define DemEventParameter_0xC19882  210u
#define DemEventParameter_0xD10882  211u
#define DemEventParameter_0xC10F82  212u
#define DemEventParameter_0xC23082  213u
#define DemEventParameter_0xD11D82  214u
#define DemEventParameter_0xC14682  215u
#define DemEventParameter_0xC13182  216u
#define DemEventParameter_0xC24082  217u
#define DemEventParameter_0xC27082  218u
#define DemEventParameter_0x100496  219u
#define DemEventParameter_0x100F16  220u
#define DemEventParameter_0x100F17  221u
#define DemEventParameter_0x943846  222u
#define DemEventParameter_0x943811  223u
#define DemEventParameter_0x943815  224u
#define DemEventParameter_0x943C71  225u
#define DemEventParameter_0x943C46  226u
#define DemEventParameter_0x943C11  227u
#define DemEventParameter_0x943C15  228u
#define DemEventParameter_0x943C4B  229u
#define DemEventParameter_0x943C17  230u
#define DemEventParameter_0x943C16  231u
#define DemEventParameter_0x943D11  232u
#define DemEventParameter_0x943D15  233u
#define DemEventParameter_0x943E11  234u
#define DemEventParameter_0x943E15  235u
#define DemEventParameter_0x943F11  236u
#define DemEventParameter_0x943F15  237u
#define DemEventParameter_0x944081  238u
#define DemEventParameter_0x944011  239u
#define DemEventParameter_0x944015  240u
#define DemEventParameter_0x944017  241u
#define DemEventParameter_0x944016  242u
#define DemEventParameter_0x944098  243u
#define DemEventParameter_0x94404B  244u
#define DemEventParameter_0x944181  245u
#define DemEventParameter_0x944111  246u
#define DemEventParameter_0x944115  247u
#define DemEventParameter_0x944117  248u
#define DemEventParameter_0x944116  249u
#define DemEventParameter_0x944198  250u
#define DemEventParameter_0x94414B  251u
#define DemEventParameter_0x944281  252u
#define DemEventParameter_0x944211  253u
#define DemEventParameter_0x944215  254u
#define DemEventParameter_0x944217  255u
#define DemEventParameter_0x944216  256u
#define DemEventParameter_0x944398  257u
#define DemEventParameter_0x94434B  258u
#define DemEventParameter_0x901511  259u
#define DemEventParameter_0x901513  260u
#define DemEventParameter_0x901611  261u
#define DemEventParameter_0x901613  262u
#define DemEventParameter_0x901711  263u
#define DemEventParameter_0x901713  264u
#define DemEventParameter_0x901811  265u
#define DemEventParameter_0x901813  266u
#define DemEventParameter_0x901911  267u
#define DemEventParameter_0x901913  268u
#define DemEventParameter_0xD04087  269u
#define DemEventParameter_0xD04187  270u
#define DemEventParameter_0xD04287  271u
#define DemEventParameter_0xD04387  272u
#define DemEventParameter_0xD04487  273u
#define DemEventParameter_0xD04587  274u
#define DemEventParameter_0xD04687  275u
#define DemEventParameter_0xD04787  276u
#define DemEventParameter_0xD04887  277u
#define DemEventParameter_0xD04987  278u
#define DemEventParameter_0xD04A87  279u
#define DemEventParameter_0x94384B  280u
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

