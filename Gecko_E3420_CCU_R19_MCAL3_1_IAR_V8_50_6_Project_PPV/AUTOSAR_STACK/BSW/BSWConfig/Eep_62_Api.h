
/*===========================================================================================================================*/
/*** Copyright (C) 2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *
 *  @file       <Eep_62_Api.h>
 *  @brief
 *
 *  <Compiler:     MCU: >
 *
 *  @author     <Haibin.Shao>
 *  @date       <2023/11/06 15:38:45 >  
 */
/*===========================================================================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]====================================================================*/
/* <VERSION>   <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0     20230306    Haibin.Shao     First Version
 */
/*===========================================================================================================================*/
#ifndef EEP_62_API_H_
#define EEP_62_API_H_

/*=======================[I N C L U D E S]===================================================================================*/
#include "Eep_62.h"

/*===============================================================================
                                       GLOBAL FUNCTIONS
===============================================================================*/

extern FUNC(void, EEP_PUBLIC_CODE) Eep_62_SetMode_0(VAR(MemIf_ModeType, AUTOMATIC) Mode);

extern FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Read_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    P2VAR(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
);

extern FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Write_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_CONST) DataBufferPtr,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
);

extern FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Erase_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
);

extern FUNC(Std_ReturnType, EEP_PUBLIC_CODE) Eep_62_Compare_0
(
    VAR(Eep_62_AddressType, AUTOMATIC) EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_CONST) DataBufferPtr,
    VAR(Eep_62_LengthType, AUTOMATIC) Length
);

extern FUNC(void, EEP_PUBLIC_CODE) Eep_62_Cancel_0(void);

extern FUNC(MemIf_StatusType, EEP_PUBLIC_CODE) Eep_62_GetStatus_0(void);

extern FUNC(MemIf_JobResultType, EEP_PUBLIC_CODE) Eep_62_GetJobResult_0(void);

#endif /* EEP_62_CFG_H_ */

