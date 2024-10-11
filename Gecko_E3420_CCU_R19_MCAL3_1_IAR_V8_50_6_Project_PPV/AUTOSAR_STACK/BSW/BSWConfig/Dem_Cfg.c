/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dem_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-07-24 10:01:01>
 */
/*============================================================================*/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Dem_CfgTypes.h"
#include "Dem_Internal.h"
#if (DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM_Cfg.h"
#endif

/*******************************************************************************
*                          General Configuration
*******************************************************************************/

/*******************************************************************************
*                          DemDataElementClass Configuration
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType DemReadOccctr(uint8* Buffer)
{
    *Buffer = DemInternalData.Occctr;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(DemDataElementClassTypes,AUTOMATIC) DemDataElementClass[DEM_DATA_ELEMENT_CLASS_NUM] =
{
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_ReadGear,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_ReadPowerMode,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_ReadPowerVoltage,/*DemDataElementClass*/
    },
    {
        FALSE,
        2u,/*DemDataElementDataSize*/
        Rte_ReadSpeed,/*DemDataElementClass*/
    },
    {
        FALSE,
        6u,/*DemDataElementDataSize*/
        Rte_ReadBjsTime,/*DemDataElementClass*/
    },
    {
        FALSE,
        3u,/*DemDataElementDataSize*/
        Rte_ReadOdometerOfMalfunction,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_ReadOperateMode,/*DemDataElementClass*/
    },
    {
        TRUE,
        1u,/*DemDataElementDataSize*/
        DemReadOccctr,/*DemDataElementClass*/
    },
    {
        FALSE,
        1u,/*DemDataElementDataSize*/
        Rte_AgedCounter,/*DemDataElementClass*/
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          Condition Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemOperationCycle */
CONST(Dem_OperationCycleType,AUTOMATIC) DemOperationCycle[DEM_OPERATION_CYCLE_NUM] =
{
    { /* DemOperationCycle */
        FALSE,
        FALSE,
        DEM_OPCYC_IGNITION
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          FreezeFrame Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDidClass */
CONST(Dem_DidClassType,AUTOMATIC) DemDidClass[DEM_DID_CLASS_NUM] =
{
    { /* DemDidClass_F206 */
        0xf206u,
        0u,
        1u,
        1u,
    },
    { /* DemDidClass_F200 */
        0xf200u,
        1u,
        1u,
        1u,
    },
    { /* DemDidClass_F202 */
        0xf202u,
        2u,
        1u,
        1u,
    },
    { /* DemDidClass_F201 */
        0xf201u,
        3u,
        1u,
        2u,
    },
    { /* DemDidClass_F203 */
        0xf203u,
        4u,
        1u,
        6u,
    },
    { /* DemDidClass_F204 */
        0xf204u,
        5u,
        1u,
        3u,
    },
    { /* DemDidClass_F205 */
        0xf205u,
        6u,
        1u,
        1u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) DemDidClassRef[DEM_DID_CLASS_REF_TOTAL_NUM] =
{
    /* DemFreezeFrameClass_0 */
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x5u,
    0x6u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameClassType,AUTOMATIC) DemFreezeFrameClass[DEM_FREEZE_FRAME_CLASS_NUM] =
{
    { /* DemFreezeFrameClass_0 DID*/
        15u,
        0u,
        7u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemFreezeFrameRecordClass */
CONST(Dem_FreezeFrameRecordClassType,AUTOMATIC) DemFreezeFrameRecordClass[DEM_FREEZE_FRAME_RECORD_CLASS_NUM] =
{
    { /* DemFreezeFrameRecordClass_0 */
        1u,                       /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_TEST_FAILED,   /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_NO       /* DemFreezeFrameRecordUpdate */
    },
    { /* DemFreezeFrameRecordClass_1 */
        2u,                       /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_TEST_FAILED,   /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_YES       /* DemFreezeFrameRecordUpdate */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8,AUTOMATIC) DemFreezeFrameRecordClassRef[DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM] =
{
    /* DemFreezeFrameRecNumClass_0 */
    0x0u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameRecNumClassType,AUTOMATIC) DemFreezeFrameRecNumClass[DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM] =
{
    { /* DemFreezeFrameRecNumClass_0 */
        0u,
        1u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          ExtendedData Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemExtendedDataRecordClass */
CONST(Dem_ExtendedDataRecordClassType,AUTOMATIC) DemExtendedDataRecordClass[DEM_EXTENDED_DATA_RECORD_CLASS_NUM] =
{
    { /* DemExtendedDataRecordClass_0 */
        0x1u,
        DEM_TRIGGER_ON_TEST_FAILED,/*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,/*DemExtendedDataRecordUpdate*/
        7u,/*DemDataElementClassIndex*/
        2u,/*DemDataElementClassNum*/
        2u,
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8,AUTOMATIC) DemExtendedDataRecordClassRef[DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM] =
{
    /* DemExtendedDataClass_0 */
    0x0u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/* DemGeneral/DemExtendedDataClass */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_ExtendedDataClassType,AUTOMATIC) DemExtendedDataClass[DEM_EXTENDED_DATA_CLASS_NUM] =
{
    { /* DemExtendedDataClass_0 */
        0u,
        1u
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          DTC Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGroupOfDTC 0-255 */
CONST(uint32,AUTOMATIC) DemGroupOfDTC[DEM_GROUP_OF_DTC_NUM] =
{
    0x100000u,
    0x400000u,
    0x800000u,
    0xc00000u
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTC 0-65535 */
static CONST(Dem_DTCType,AUTOMATIC) DemDTC[DEM_DTC_NUM] =
{
    { /* DemDTC_0x100083 */
        0x100083u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100116 */
        0x100116u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100117 */
        0x100117u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100316 */
        0x100316u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100317 */
        0x100317u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100716 */
        0x100716u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100717 */
        0x100717u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100D16 */
        0x100d16u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100E17 */
        0x100e17u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101201 */
        0x101201u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101501 */
        0x101501u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101601 */
        0x101601u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101701 */
        0x101701u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101D68 */
        0x101d68u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x102093 */
        0x102093u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10211A */
        0x10211au, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x102496 */
        0x102496u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x102596 */
        0x102596u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x102696 */
        0x102696u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x102796 */
        0x102796u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x103093 */
        0x103093u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x103196 */
        0x103196u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x103296 */
        0x103296u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x103396 */
        0x103396u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x103496 */
        0x103496u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104093 */
        0x104093u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x103996 */
        0x103996u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104196 */
        0x104196u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104296 */
        0x104296u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104396 */
        0x104396u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104496 */
        0x104496u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104696 */
        0x104696u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104796 */
        0x104796u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x104896 */
        0x104896u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105093 */
        0x105093u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105196 */
        0x105196u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105496 */
        0x105496u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105596 */
        0x105596u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105693 */
        0x105693u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105796 */
        0x105796u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105896 */
        0x105896u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105996 */
        0x105996u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105B96 */
        0x105b96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105C96 */
        0x105c96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x108186 */
        0x108186u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x108286 */
        0x108286u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x108486 */
        0x108486u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x109077 */
        0x109077u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x109196 */
        0x109196u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x109296 */
        0x109296u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x109396 */
        0x109396u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x109496 */
        0x109496u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A182 */
        0x10a182u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x102A84 */
        0x102a84u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100517 */
        0x100517u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100696 */
        0x100696u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101D96 */
        0x101d96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101E96 */
        0x101e96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10221C */
        0x10221cu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10231C */
        0x10231cu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10284B */
        0x10284bu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101F96 */
        0x101f96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x105A96 */
        0x105a96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101301 */
        0x101301u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x101401 */
        0x101401u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900011 */
        0x900011u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900013 */
        0x900013u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900111 */
        0x900111u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900113 */
        0x900113u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900211 */
        0x900211u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900213 */
        0x900213u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900311 */
        0x900311u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900313 */
        0x900313u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900412 */
        0x900412u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900512 */
        0x900512u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900711 */
        0x900711u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900811 */
        0x900811u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900923 */
        0x900923u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900924 */
        0x900924u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900A23 */
        0x900a23u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900A24 */
        0x900a24u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900B23 */
        0x900b23u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900B24 */
        0x900b24u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900C23 */
        0x900c23u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900C24 */
        0x900c24u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900D23 */
        0x900d23u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900D24 */
        0x900d24u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900E23 */
        0x900e23u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x900E24 */
        0x900e24u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901016 */
        0x901016u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901116 */
        0x901116u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901216 */
        0x901216u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901316 */
        0x901316u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901031 */
        0x901031u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901131 */
        0x901131u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901231 */
        0x901231u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901331 */
        0x901331u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x90141C */
        0x90141cu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xF00116 */
        0xf00116u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xF00117 */
        0xf00117u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC04688 */
        0xc04688u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC05588 */
        0xc05588u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC07388 */
        0xc07388u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC06488 */
        0xc06488u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC12287 */
        0xc12287u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD10287 */
        0xd10287u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11287 */
        0xd11287u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD10E87 */
        0xd10e87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC13087 */
        0xc13087u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC15187 */
        0xc15187u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11687 */
        0xd11687u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC19887 */
        0xc19887u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC11287 */
        0xc11287u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD10887 */
        0xd10887u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC10F87 */
        0xc10f87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC23087 */
        0xc23087u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11D87 */
        0xd11d87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC14687 */
        0xc14687u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xE10005 */
        0xe10005u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11F00 */
        0xd11f00u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11F87 */
        0xd11f87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD12014 */
        0xd12014u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD12100 */
        0xd12100u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD12241 */
        0xd12241u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x901416 */
        0x901416u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941211 */
        0x941211u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941215 */
        0x941215u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941311 */
        0x941311u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941315 */
        0x941315u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941411 */
        0x941411u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941515 */
        0x941515u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941A11 */
        0x941a11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941A15 */
        0x941a15u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941B11 */
        0x941b11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941B15 */
        0x941b15u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941D11 */
        0x941d11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941D15 */
        0x941d15u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941E11 */
        0x941e11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941E15 */
        0x941e15u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941F11 */
        0x941f11u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x941F15 */
        0x941f15u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942011 */
        0x942011u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942015 */
        0x942015u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942111 */
        0x942111u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942115 */
        0x942115u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942211 */
        0x942211u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942215 */
        0x942215u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942386 */
        0x942386u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942229 */
        0x942229u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942416 */
        0x942416u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942417 */
        0x942417u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942516 */
        0x942516u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942517 */
        0x942517u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942604 */
        0x942604u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942629 */
        0x942629u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942719 */
        0x942719u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942803 */
        0x942803u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942929 */
        0x942929u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942A29 */
        0x942a29u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942B29 */
        0x942b29u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942C29 */
        0x942c29u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942D98 */
        0x942d98u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942E98 */
        0x942e98u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942B98 */
        0x942b98u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942C98 */
        0x942c98u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942F1D */
        0x942f1du, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x942098 */
        0x942098u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943198 */
        0x943198u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943211 */
        0x943211u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943215 */
        0x943215u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943271 */
        0x943271u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943311 */
        0x943311u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943315 */
        0x943315u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943371 */
        0x943371u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943411 */
        0x943411u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943415 */
        0x943415u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943571 */
        0x943571u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943779 */
        0x943779u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943786 */
        0x943786u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943782 */
        0x943782u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943705 */
        0x943705u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943704 */
        0x943704u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943979 */
        0x943979u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x94374B */
        0x94374bu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943716 */
        0x943716u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943717 */
        0x943717u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943719 */
        0x943719u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943871 */
        0x943871u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943898 */
        0x943898u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x94384B */
        0x94384bu, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943821 */
        0x943821u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943817 */
        0x943817u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943816 */
        0x943816u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC24087 */
        0xc24087u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC27087 */
        0xc27087u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC1FF87 */
        0xc1ff87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC1FE87 */
        0xc1fe87u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC13187 */
        0xc13187u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943A04 */
        0x943a04u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x943B04 */
        0x943b04u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        2u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A296 */
        0x10a296u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A396 */
        0x10a396u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A496 */
        0x10a496u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A596 */
        0x10a596u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A696 */
        0x10a696u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A796 */
        0x10a796u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A896 */
        0x10a896u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10A996 */
        0x10a996u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10AA96 */
        0x10aa96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10AB96 */
        0x10ab96u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x10AC83 */
        0x10ac83u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC11282 */
        0xc11282u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC12282 */
        0xc12282u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD10282 */
        0xd10282u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11282 */
        0xd11282u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD10E82 */
        0xd10e82u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC13082 */
        0xc13082u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC15182 */
        0xc15182u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11682 */
        0xd11682u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC19882 */
        0xc19882u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD10882 */
        0xd10882u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC10F82 */
        0xc10f82u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC23082 */
        0xc23082u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xD11D82 */
        0xd11d82u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC14682 */
        0xc14682u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC13182 */
        0xc13182u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC24082 */
        0xc24082u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0xC27082 */
        0xc27082u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100496 */
        0x100496u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100F16 */
        0x100f16u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        0u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    },
    { /* DemDTC_0x100F17 */
        0xc27082u, /* DemDtcValue */
        0u, /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0x0u, /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY, /* DemDTCSeverity */
        3u, /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS,/*DemWWHOBDDTCClass*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTCAttributes */
static CONST(Dem_DTCAttributesType,AUTOMATIC) DemDTCAttributes[DEM_DTC_ATTRIBUTES_NUM] =
{
    { /* ATTR_AgingCnt40 */
        TRUE, /* DemAgingAllowed */
        0u, /* DemAgingCycleRef */
        40u, /* DemAgingCycleCounterThreshold */
        0u, /* DemAgingCycleCounterThresholdForTFSLC */
        0u, /* DemDTCPriority */
        0u, /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u, /* DemFreezeFrameRecNumClassRef */
        TRUE, /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT, /* DemDTCSignificance */
        0u, /* DemExtendedDataClassRef  */
        0u, /* DemFreezeFrameClassRef  */
        {  0}, /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,/*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,/*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID,/*DemWWHOBDFreezeFrameClassRef*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          Indicator Configuration
*******************************************************************************/
/*******************************************************************************
*                          Debounce Configuration
*******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
static CONST(Dem_DebounceCounterBasedClassType,AUTOMATIC) DemDebounceCounterBasedClass[DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM] =
{
    { /* DemDebounceCounterBasedClass_busoff */
        1u, /* DemDebounceCounterDecrementStepSize */
        1u, /* DemDebounceCounterIncrementStepSize  */
        0, /* DemDebounceCounterJumpDownValue  */
        0, /* DemDebounceCounterJumpUpValue */
        8, /* DemDebounceCounterFailedThreshold */
        -1, /* DemDebounceCounterPassedThreshold */
        TRUE, /* DemDebounceCounterJumpDown */
        TRUE, /* DemDebounceCounterJumpUp */
        FALSE, /* DemDebounceCounterStorage */
        DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemConfigSet/DemDebounceTimeBaseClass 0-65535 */
static CONST(Dem_DebounceTimeBaseClassType,AUTOMATIC) DemDebounceTimeBaseClass[DEM_DEBOUNCE_TIME_BASE_CLASS_NUM] =
{
    { /* DemDebounceTimeBaseClass_Busoff */
        850UL, /* DemDebounceTimeFailedThreshold */
        5000UL, /* DemDebounceTimePassedThreshold */
        DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          Event Configuration
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
static CONST(Dem_EventParameterType,AUTOMATIC) DemEventParameter[DEM_EVENT_PARAMETER_NUM] =
{
    {  /* DemEventParameter_0xD11D87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        116u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100083*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        0u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100116*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        1u, /* DemDTCRef */
        1u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100117*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        2u, /* DemDTCRef */
        2u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100316*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        3u, /* DemDTCRef */
        3u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100317*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        4u, /* DemDTCRef */
        4u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100716*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        5u, /* DemDTCRef */
        5u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100717*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        6u, /* DemDTCRef */
        6u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100D16*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        7u, /* DemDTCRef */
        7u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100E17*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        8u, /* DemDTCRef */
        8u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101201*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        9u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101501*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        10u, /* DemDTCRef */
        9u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101601*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        11u, /* DemDTCRef */
        10u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101701*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        12u, /* DemDTCRef */
        11u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101D68*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        13u, /* DemDTCRef */
        12u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x102093*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        14u, /* DemDTCRef */
        13u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10211A*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        15u, /* DemDTCRef */
        14u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x102496*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        16u, /* DemDTCRef */
        15u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x102596*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        17u, /* DemDTCRef */
        16u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x102696*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        18u, /* DemDTCRef */
        17u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x102796*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        19u, /* DemDTCRef */
        18u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x103093*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        20u, /* DemDTCRef */
        19u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x103196*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        21u, /* DemDTCRef */
        20u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x103296*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        22u, /* DemDTCRef */
        21u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x103396*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        23u, /* DemDTCRef */
        22u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x103496*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        24u, /* DemDTCRef */
        23u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104093*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        25u, /* DemDTCRef */
        24u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x103996*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        26u, /* DemDTCRef */
        25u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104196*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        27u, /* DemDTCRef */
        26u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104296*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        28u, /* DemDTCRef */
        27u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104396*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        29u, /* DemDTCRef */
        28u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104496*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        30u, /* DemDTCRef */
        29u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104696*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        31u, /* DemDTCRef */
        30u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104796*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        32u, /* DemDTCRef */
        31u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x104896*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        33u, /* DemDTCRef */
        32u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105093*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        34u, /* DemDTCRef */
        33u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105196*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        35u, /* DemDTCRef */
        34u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105496*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        36u, /* DemDTCRef */
        35u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105596*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        37u, /* DemDTCRef */
        36u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105693*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        38u, /* DemDTCRef */
        37u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105796*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        39u, /* DemDTCRef */
        38u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105896*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        40u, /* DemDTCRef */
        39u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105996*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        41u, /* DemDTCRef */
        40u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105B96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        42u, /* DemDTCRef */
        41u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105C96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        43u, /* DemDTCRef */
        42u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x108186*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        44u, /* DemDTCRef */
        43u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x108286*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        45u, /* DemDTCRef */
        44u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x108486*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        46u, /* DemDTCRef */
        45u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x109077*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        47u, /* DemDTCRef */
        46u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x109196*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        48u, /* DemDTCRef */
        47u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x109296*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        49u, /* DemDTCRef */
        48u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x109396*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        50u, /* DemDTCRef */
        49u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x109496*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        51u, /* DemDTCRef */
        50u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A182*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        52u, /* DemDTCRef */
        51u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x102A84*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        53u, /* DemDTCRef */
        52u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100517*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        54u, /* DemDTCRef */
        53u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100696*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        55u, /* DemDTCRef */
        54u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101D96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        56u, /* DemDTCRef */
        55u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101E96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        57u, /* DemDTCRef */
        56u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10221C*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        58u, /* DemDTCRef */
        57u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10231C*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        59u, /* DemDTCRef */
        58u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10284B*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        60u, /* DemDTCRef */
        59u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101F96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        61u, /* DemDTCRef */
        60u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x105A96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        62u, /* DemDTCRef */
        61u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101301*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        63u, /* DemDTCRef */
        62u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x101401*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        64u, /* DemDTCRef */
        63u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900011*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        65u, /* DemDTCRef */
        64u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900013*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        66u, /* DemDTCRef */
        65u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900111*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        67u, /* DemDTCRef */
        66u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900113*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        68u, /* DemDTCRef */
        67u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900211*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        69u, /* DemDTCRef */
        68u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900213*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        70u, /* DemDTCRef */
        69u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900311*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        71u, /* DemDTCRef */
        70u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900313*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        72u, /* DemDTCRef */
        71u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900412*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        73u, /* DemDTCRef */
        72u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900512*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        74u, /* DemDTCRef */
        73u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900711*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        75u, /* DemDTCRef */
        74u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900811*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        76u, /* DemDTCRef */
        75u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900923*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        77u, /* DemDTCRef */
        76u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900924*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        78u, /* DemDTCRef */
        77u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900A23*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        79u, /* DemDTCRef */
        78u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900A24*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        80u, /* DemDTCRef */
        79u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900B23*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        81u, /* DemDTCRef */
        80u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900B24*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        82u, /* DemDTCRef */
        81u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900C23*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        83u, /* DemDTCRef */
        82u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900C24*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        84u, /* DemDTCRef */
        83u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900D23*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        85u, /* DemDTCRef */
        84u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900D24*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        86u, /* DemDTCRef */
        85u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900E23*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        87u, /* DemDTCRef */
        86u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x900E24*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        88u, /* DemDTCRef */
        87u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901016*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        89u, /* DemDTCRef */
        88u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901116*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        90u, /* DemDTCRef */
        89u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901216*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        91u, /* DemDTCRef */
        90u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901316*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        92u, /* DemDTCRef */
        91u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901031*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        93u, /* DemDTCRef */
        92u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901131*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        94u, /* DemDTCRef */
        93u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901231*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        95u, /* DemDTCRef */
        94u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901331*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        96u, /* DemDTCRef */
        95u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x90141C*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        97u, /* DemDTCRef */
        96u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xF00116*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        98u, /* DemDTCRef */
        97u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xF00117*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        99u, /* DemDTCRef */
        98u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC04688*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        100u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        1u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_BSW, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC05588*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        101u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        2u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_BSW, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC07388*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        102u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        3u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_BSW, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC06488*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        103u, /* DemDTCRef */
        0u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        4u, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_BSW, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC12287*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        104u, /* DemDTCRef */
        99u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD10287*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        105u, /* DemDTCRef */
        100u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD11287*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        106u, /* DemDTCRef */
        101u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD10E87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        107u, /* DemDTCRef */
        102u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC13087*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        108u, /* DemDTCRef */
        103u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC15187*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        109u, /* DemDTCRef */
        104u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD11687*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        110u, /* DemDTCRef */
        105u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC19887*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        111u, /* DemDTCRef */
        106u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC11287*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        112u, /* DemDTCRef */
        107u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD10887*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        113u, /* DemDTCRef */
        108u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC10F87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        114u, /* DemDTCRef */
        109u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC23087*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        115u, /* DemDTCRef */
        110u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC14687*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        117u, /* DemDTCRef */
        111u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xE10005*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        118u, /* DemDTCRef */
        112u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD11F00*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        119u, /* DemDTCRef */
        113u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD11F87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        120u, /* DemDTCRef */
        114u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD12014*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        121u, /* DemDTCRef */
        115u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD12100*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        122u, /* DemDTCRef */
        116u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD12241*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        123u, /* DemDTCRef */
        117u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x901416*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        124u, /* DemDTCRef */
        118u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941211*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        125u, /* DemDTCRef */
        119u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941215*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        126u, /* DemDTCRef */
        120u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941311*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        127u, /* DemDTCRef */
        121u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941315*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        128u, /* DemDTCRef */
        122u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941411*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        129u, /* DemDTCRef */
        123u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941515*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        130u, /* DemDTCRef */
        124u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941A11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        131u, /* DemDTCRef */
        125u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941A15*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        132u, /* DemDTCRef */
        126u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941B11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        133u, /* DemDTCRef */
        127u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941B15*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        134u, /* DemDTCRef */
        128u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941D11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        135u, /* DemDTCRef */
        129u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941D15*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        136u, /* DemDTCRef */
        130u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941E11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        137u, /* DemDTCRef */
        131u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941E15*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        138u, /* DemDTCRef */
        132u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941F11*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        139u, /* DemDTCRef */
        133u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x941F15*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        140u, /* DemDTCRef */
        134u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942011*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        141u, /* DemDTCRef */
        135u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942015*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        142u, /* DemDTCRef */
        136u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942111*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        143u, /* DemDTCRef */
        137u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942115*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        144u, /* DemDTCRef */
        138u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942211*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        145u, /* DemDTCRef */
        139u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942215*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        146u, /* DemDTCRef */
        140u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942386*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        147u, /* DemDTCRef */
        141u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942229*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        148u, /* DemDTCRef */
        142u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942416*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        149u, /* DemDTCRef */
        143u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942417*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        150u, /* DemDTCRef */
        144u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942516*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        151u, /* DemDTCRef */
        145u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942517*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        152u, /* DemDTCRef */
        146u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942604*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        153u, /* DemDTCRef */
        147u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942629*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        154u, /* DemDTCRef */
        148u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942719*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        155u, /* DemDTCRef */
        149u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942803*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        156u, /* DemDTCRef */
        150u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942929*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        157u, /* DemDTCRef */
        151u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942A29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        158u, /* DemDTCRef */
        152u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942B29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        159u, /* DemDTCRef */
        153u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942C29*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        160u, /* DemDTCRef */
        154u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942D98*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        161u, /* DemDTCRef */
        155u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942E98*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        162u, /* DemDTCRef */
        156u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942B98*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        163u, /* DemDTCRef */
        157u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942C98*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        164u, /* DemDTCRef */
        158u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942F1D*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        165u, /* DemDTCRef */
        159u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x942098*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        166u, /* DemDTCRef */
        160u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943198*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        167u, /* DemDTCRef */
        161u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943211*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        168u, /* DemDTCRef */
        162u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943215*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        169u, /* DemDTCRef */
        163u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943271*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        170u, /* DemDTCRef */
        164u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943311*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        171u, /* DemDTCRef */
        165u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943315*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        172u, /* DemDTCRef */
        166u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943371*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        173u, /* DemDTCRef */
        167u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943411*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        174u, /* DemDTCRef */
        168u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943415*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        175u, /* DemDTCRef */
        169u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943571*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        176u, /* DemDTCRef */
        170u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943779*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        177u, /* DemDTCRef */
        171u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943786*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        178u, /* DemDTCRef */
        172u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943782*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        179u, /* DemDTCRef */
        173u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943705*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        180u, /* DemDTCRef */
        174u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943704*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        181u, /* DemDTCRef */
        175u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943979*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        182u, /* DemDTCRef */
        176u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x94374B*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        183u, /* DemDTCRef */
        177u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943716*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        184u, /* DemDTCRef */
        178u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943717*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        185u, /* DemDTCRef */
        179u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943719*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        186u, /* DemDTCRef */
        180u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943871*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        187u, /* DemDTCRef */
        181u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943898*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        188u, /* DemDTCRef */
        182u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x94384B*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        189u, /* DemDTCRef */
        183u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943821*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        190u, /* DemDTCRef */
        184u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943817*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        191u, /* DemDTCRef */
        185u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_AFTER_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943816*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        192u, /* DemDTCRef */
        186u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC24087*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        193u, /* DemDTCRef */
        187u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC27087*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        194u, /* DemDTCRef */
        188u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC1FF87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        195u, /* DemDTCRef */
        189u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC1FE87*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        196u, /* DemDTCRef */
        190u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC13187*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        197u, /* DemDTCRef */
        191u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943A04*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        198u, /* DemDTCRef */
        192u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x943B04*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        199u, /* DemDTCRef */
        193u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A296*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        200u, /* DemDTCRef */
        194u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A396*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        201u, /* DemDTCRef */
        195u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A496*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        202u, /* DemDTCRef */
        196u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A596*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        203u, /* DemDTCRef */
        197u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A696*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        204u, /* DemDTCRef */
        198u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A796*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        205u, /* DemDTCRef */
        199u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A896*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        206u, /* DemDTCRef */
        200u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10A996*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        207u, /* DemDTCRef */
        201u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10AA96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        208u, /* DemDTCRef */
        202u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10AB96*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        209u, /* DemDTCRef */
        203u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x10AC83*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        210u, /* DemDTCRef */
        204u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC11282*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        211u, /* DemDTCRef */
        205u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC12282*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        212u, /* DemDTCRef */
        206u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD10282*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        213u, /* DemDTCRef */
        207u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD11282*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        214u, /* DemDTCRef */
        208u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD10E82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        215u, /* DemDTCRef */
        209u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC13082*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        216u, /* DemDTCRef */
        210u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC15182*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        217u, /* DemDTCRef */
        211u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD11682*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        218u, /* DemDTCRef */
        212u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC19882*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        219u, /* DemDTCRef */
        213u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD10882*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        220u, /* DemDTCRef */
        214u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC10F82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        221u, /* DemDTCRef */
        215u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC23082*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        222u, /* DemDTCRef */
        216u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xD11D82*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        223u, /* DemDTCRef */
        217u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC14682*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        224u, /* DemDTCRef */
        218u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC13182*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        225u, /* DemDTCRef */
        219u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC24082*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        226u, /* DemDTCRef */
        220u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0xC27082*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        227u, /* DemDTCRef */
        221u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100496*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        228u, /* DemDTCRef */
        222u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100F16*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        229u, /* DemDTCRef */
        223u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    },
    {  /* DemEventParameter_0x100F17*/
        NULL_PTR,  /* DemCallbackInitMForE */
        NULL_PTR,  /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u, /* StatusChangedCbkStartIndex*/
        0u, /* StatusChangedCbkNum */
        230u, /* DemDTCRef */
        224u, /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0xFFFF, /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_MONITOR_INTERNAL, /* AlgorithmType */
        0u, /* DemIndicatorAttributeStartIndex */
        0u, /* AttrNum = COUNT(Event/DemIndicatorAttribute) */
        0u,/*DemEventFailureCycleCounterThreshold*/
        TRUE,/*DemEventAvailable*/
        FALSE,  /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC, /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT, /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u, /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        DEM_ENABLE_CONDITION_GROUP_INVALID, /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,/*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,/*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,/*DemOBDGroupingAssociativeEventsRef*/
    }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
*                          Memory Configuration
*******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemPrimaryMemory 1-1 */
static VAR(Dem_EventMemEntryType,AUTOMATIC) DemPrimaryMemory[DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

/* Dem_EventMemEntryType DemUserDefinedMemory<Mem/Name>[Mem/DemMaxNumberEventEntryUserDefined]; */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_MemDestConfigType,AUTOMATIC) DemMemDestCfg[DEM_MEM_DEST_TOTAL_NUM] =
{
    /* DemPrimaryMemory */
    {
        DemPrimaryMemory,
        DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) DemNvRamBlockId[DEM_NVRAM_BLOCKID_NUM] =
{
    NvMBlock_EventEntryPrimary_1, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_2, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_3, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_4, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_5, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_6, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_7, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_8, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_9, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_10, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_11, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_12, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_13, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_14, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_15, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_16, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_17, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_18, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_19, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_20, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_21, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_22, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_23, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_24, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_25, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_26, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_27, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_28, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_29, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_30, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_31, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_32, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_33, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_34, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_35, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_36, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_37, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_38, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_39, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_40, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_41, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_42, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_43, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_44, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_45, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_46, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_47, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_48, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_49, /* DemNvRamBlockIdRef  */
    NvMBlock_EventEntryPrimary_50, /* DemNvRamBlockIdRef  */
    NvMBlock_UDS_InternalData, /* DemNvRamBlockIdRef  */
    NvMBlock_OBD_InternalData, /* DemNvRamBlockIdRef  */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
*                          OBD Configuration
*******************************************************************************/

/*******************************************************************************
*                          J1939 Configuration
*******************************************************************************/
/*******************************************************************************
*                          PB DemConfigSet Configuration
*******************************************************************************/
#define DEM_START_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
CONST(Dem_ConfigType, AUTOMATIC) DemPbCfg =
{
    NULL_PTR,
    DemDTC,
    DemDTCAttributes,
    DemDebounceCounterBasedClass,
    DemDebounceTimeBaseClass,
    NULL_PTR,
    DemEventParameter,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
};
#define DEM_STOP_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

