/*===========================================================================================================================*/
/*** Copyright (C) 2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *
 *  @file       <Eep_62_Api.c>
 *  @brief
 *
 *  <Compiler:    MCU: >
 *
 *  @author     <Haibin.Shao>
 *  @date       <2023/11/06 15:38:45 > 
 */
/*===========================================================================================================================*/

/*=====================[R E V I S I O N   H I S T O R Y]=====================================================================*/
/* <VERSION>   <DATE>      <AUTHOR>       <REVISION LOG>
 *  V1.0.0     20190709    Haibin.Shao    First Version
 */
/*===========================================================================================================================*/

/******************************************************************************************************************************
**                      Include Section                                                                                      **
******************************************************************************************************************************/
#include "Eep_62_Api.h"

/******************************************************************************************************************************
**                      GLOBAL FUNCTIONS                                                                                     **
******************************************************************************************************************************/

#define EEP_62_START_SEC_CODE
#include "Eep_62_MemMap.h"

FUNC(void, EEP_PUBLIC_CODE) Eep_62_SetMode_0(VAR(MemIf_ModeType, AUTOMATIC) Mode)
{
    Eep_62_SetMode(0, Mode);
}

/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Read_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    P2VAR(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType retVal;
    retVal = Eep_62_Read(0, EepromAddress, DataBufferPtr, Length);
    return retVal;
}

FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Write_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_CONST) DataBufferPtr,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
)
{
    Std_ReturnType retVal;
    retVal = Eep_62_Write(0, EepromAddress, DataBufferPtr, Length);
    return retVal;
}

FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Erase_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
)
{
    Std_ReturnType retVal;
    retVal = Eep_62_Erase(0, EepromAddress, Length);
    return retVal;
}

FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Compare_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_CONST) DataBufferPtr,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
)
{
    Std_ReturnType retVal;
    retVal = Eep_62_Compare(0, EepromAddress, DataBufferPtr, Length);
    return retVal;
}

FUNC(void, EEP_PUBLIC_CODE) Eep_62_Cancel_0(void)
{
    Eep_62_Cancel(0);
}

FUNC(MemIf_StatusType, EEP_PUBLIC_CODE) Eep_62_GetStatus_0(void)
{
    MemIf_StatusType retVal;
    retVal = Eep_62_GetStatus(0);
    return retVal;
}

FUNC(MemIf_JobResultType, EEP_PUBLIC_CODE) Eep_62_GetJobResult_0(void)
{
    MemIf_JobResultType retVal;
    retVal = Eep_62_GetJobResult(0);
    return retVal;
}

#define EEP_62_STOP_SEC_CODE
#include "Eep_62_MemMap.h"

