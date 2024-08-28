/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Callout.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-11-13 16:08:35>
 */
/*============================================================================*/

#include "Dcm_Internal.h"
#include "UDS.h"
#include "DcmDsl_MsgManage.h"
#include "Dcm_CalloutBoot.h"
#include "FreeRTimer.h"
#if (DCM_TM == STD_ON)
#include "Tm.h"
#endif /* (DCM_TM == STD_ON) */

/* BL_AppFlagType* BL_AppFlag = (BL_AppFlagType*) BL_APP_FLAG_ADDRESS; */

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_SetProgConditions(
Dcm_OpStatusType OpStatus,
Dcm_ProgConditionsType * ProgConditions/* PRQA S 3334 */ /* MISRA Rule 5.3 */
)
{
    if (ProgConditions->ProtocolId == 0)
    {
        uint64 *Boot_Addr;
        Boot_Addr = (uint64 *) 0x10000;
        *Boot_Addr = 0x67616c46676f7250;
    }
    else
    {
        uint8 OtaFlag[8] = {'O','t','a','_','F','l','a','g'};
        uint8 OtaNrspFlag[8] = {'O','t','a','_','N','r','s','p'};
        uint8 *Boot_Addr;
        Boot_Addr = (uint8 *) 0x10000;
        if(ProgConditions->Sid == 0x10 && ProgConditions->BootSuppressPosResponse == 0)
        {
          memcpy(Boot_Addr, OtaFlag, sizeof(OtaFlag));
        }
        else
        {
          memcpy(Boot_Addr, OtaNrspFlag, sizeof(OtaFlag));
        }
    }
    
    /*TODO: Set ReProgramingRequest Flag*/
    /*e.g*/
    /*    BL_AppFlag->FlBootMode = (uint32)FL_EXT_PROG_REQUEST_RECEIVED;
    BL_AppFlag->Busmode = BUS_MODE_ETH;*/
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Dcm_EcuStartModeType Dcm_GetProgConditions(/* PRQA S 3408 */ /* MISRA Rule 8.4 */
Dcm_ProgConditionsType * ProgConditions/* PRQA S 3334 */ /* MISRA Rule 5.3 */
)
{
    DCM_UNUSED(ProgConditions);
    /*TODO: check ApplUpdated*/
    /*e.g*/
    /*    if (BL_AppFlag->FlApplUpdate == (uint32)FL_APPL_UPDATED)
    {
        ProgConditions->ApplUpdated = TRUE;
        BL_AppFlag->FlApplUpdate = (uint32)0;
        return DCM_WARM_START;
    }*/
    return DCM_COLD_START;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*for 0x23 service to read data by memory address*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Dcm_ReturnReadMemoryType Dcm_ReadMemory(Dcm_OpStatusType OpStatus,
        uint8 MemoryIdentifier,
        uint32 MemoryAddress,
        uint32 MemorySize,
        uint8* MemoryData,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(MemoryIdentifier);
    DCM_UNUSED(MemoryAddress);
    DCM_UNUSED(MemorySize);
    DCM_UNUSED(MemoryData);
    DCM_UNUSED(ErrorCode);
    return DCM_READ_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*for 0x3D service to write data by memory address*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Dcm_ReturnWriteMemoryType Dcm_WriteMemory(Dcm_OpStatusType OpStatus,
                                            uint8 MemoryIdentifier,
                                            uint32 MemoryAddress,
                                            uint32 MemorySize,
                                            uint8* MemoryData,
                                            Dcm_NegativeResponseCodeType* ErrorCode)
{
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(MemoryIdentifier);
    DCM_UNUSED(MemoryAddress);
    DCM_UNUSED(MemorySize);
    DCM_UNUSED(MemoryData);
    DCM_UNUSED(ErrorCode);
    return DCM_WRITE_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*for 0x34 service to request download*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_ProcessRequestDownload(Dcm_OpStatusType OpStatus,
                                            uint8 DataFormatIdentifier,
                                            uint32 MemoryAddress,
                                            uint32 MemorySize,
                                            uint32* BlockLength,
                                            Dcm_NegativeResponseCodeType* ErrorCode)
{
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(DataFormatIdentifier);
    DCM_UNUSED(MemoryAddress);
    DCM_UNUSED(MemorySize);
    DCM_UNUSED(BlockLength);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/* service to check DataFormatIdentifier, send NRC31 if return E_NOT_OK*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_DataFormatIdentifierCheck(uint8 DataFormatIdentifier)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Dcm_DataFormatIdentifierCheck>
    */
    /* custom code.... */
    DCM_UNUSED(DataFormatIdentifier);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*for 0x37 service to request transfer exit*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* PRAQ S 0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
Std_ReturnType Dcm_ProcessRequestTransferExit(Dcm_OpStatusType OpStatus,
                                                uint8* transferRequestParameterRecord,
                                                uint32 transferRequestParameterRecordSize,
                                                uint8* transferResponseParameterRecord,
                                                /* PRQA S 0779,0779++ */ /* MISRA Rule 1.3,Rule 5.2 */
                                                uint32* transferResponseParameterRecordSize,
                                                /* PRQA S 0779,0779-- */ /* MISRA Rule 1.3,Rule 5.2 */
                                                Dcm_NegativeResponseCodeType* ErrorCode)
/* PRAQ S 0779-- */ /* MISRA Rule 1.3,Rule 5.2 */
{
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(transferRequestParameterRecord);
    DCM_UNUSED(transferRequestParameterRecordSize);
    DCM_UNUSED(transferResponseParameterRecord);
    DCM_UNUSED(transferResponseParameterRecordSize);
    DCM_UNUSED(ErrorCode);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
void Rte_EnableAllDtcsRecord(void)
{
   /*The update of the DTC status bit information shall continue once a ControlDTCSetting request is performed
     with sub-function set to on or a session layer timeout occurs (server transitions to defaultSession. */
    (void)Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DCM_CODE) Dcm_ResetTime(P2VAR(uint32, AUTOMATIC, DCM_VAR) TimerPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
#if (DCM_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = 0;
    (void)Tm_ResetTimer100us32bit(&Timer);
    *TimerPtr = Timer.ui32RefTime / (uint32)10;
#else /* DCM_TM == STD_ON */
    DCM_UNUSED(TimerPtr);
    *TimerPtr = Frt_ReadOutMS();
#endif /* DCM_TM == STD_ON */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DCM_CODE) Dcm_GetTimeSpan(uint32 TimerPtr,P2VAR(uint32, AUTOMATIC, DCM_VAR) TimeSpanPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
#if (DCM_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;
    *TimeSpanPtr = 0u;

    Timer.ui32RefTime = TimerPtr * (uint32)10;
    (void)Tm_GetTimeSpan100us32bit(&Timer,TimeSpanPtr);
    *TimeSpanPtr = *TimeSpanPtr / (uint32)10;
#else /* DCM_TM == STD_ON */
    DCM_UNUSED(TimerPtr);
    DCM_UNUSED(TimeSpanPtr);
    *TimeSpanPtr = Frt_CalculateElapsedMS(TimerPtr);
#endif /* DCM_TM == STD_ON */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

