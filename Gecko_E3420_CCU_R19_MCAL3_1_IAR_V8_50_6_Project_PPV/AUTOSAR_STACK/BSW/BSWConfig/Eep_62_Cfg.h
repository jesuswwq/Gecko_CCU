/*===========================================================================================================================*/
/*** Copyright (C) 2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *
 *  @file       <Eep_62_Cfg.h>
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
#ifndef EEP_62_CFG_H_
#define EEP_62_CFG_H_

/******************************************************************************************************************************
**                      Imported Compiler Switch Check                                                                       **
******************************************************************************************************************************/
#define EEP_62_CFG_H_SW_MAJOR_VERSION (1U)
#define EEP_62_CFG_H_SW_MINOR_VERSION (0U)
#define EEP_62_CFG_H_SW_PATCH_VERSION (0U)

/*=======================[I N C L U D E S]===================================================================================*/
#include "Eep_62_Types.h"

#include "EepCAV24C64.h"

/* Indicates the number of applied EEP modules. */
#define EEP_62_NUMBER_OF_EEP_MODULE            1

/* Switch used to enable or disable API of report development error. */
#define EEP_62_DEV_ERROR_DETECT                       STD_OFF

/* Switch used to enable or disable API of read software version information. */
#define EEP_62_VERSION_INFO_API                       STD_OFF

/* Switches to activate or deactivate interrupt controlled job processing. */
#define EEP_62_USE_INTERRUPTS                         STD_OFF

/* Pre-processor switch to enable / disable the API to use function. */
#define EEP_62_CFG_USE_FCT_API                        STD_OFF

/* Reference to the DemEventParameter which shall be issued when the error "EEPROM compare failed (HW)" has occurred. */
#define EEP_62_DEM_E_COMPARE_FAILED_DETECT      STD_OFF

/* Reference to the DemEventParameter which shall be issued when the error "EEPROM write failed (HW)" has occurred. */
#define EEP_62_DEM_E_WRITE_FAILED_DETECT               STD_OFF

/* Reference to the DemEventParameter which shall be issued when the error "EEPROM read failed (HW)" has occurred. */
#define EEP_62_DEM_E_READ_FAILED_DETECT                STD_OFF

/* Reference to the DemEventParameter which shall be issued when the error "EEPROM erase failed (HW)" has occurred. */
#define EEP_62_DEM_E_ERASE_FAILED_DETECT               STD_OFF

/* Minimum expected size of Eep_AddressType. */
#define EEP_62_MIN_ADDRESS_TYPE                        16u

/* Minimum expected size of Eep_LengthType. */
#define EEP_62_MIN_LENGTH_TYPE                         8u

/* Total size of EEPROM in bytes. */
#define EEP_62_TOTAL_SIZE                              8000u

/* Value of an erased EEPROM cell. */
#define EEP_62_ERASE_VALUE                              32u

/* Maximum time for erasing one EEPROM data unit. */
#define EEP_62_ERASE_TIME                        5u

/* Size of smallest erasable EEPROM data unit in bytes. */
#define EEP_62_READ_UINTSIZE                             1u

/* Size of smallest writeable EEPROM data unit in bytes. */
#define EEP_62_WRITE_UNITSIZE                            1u

/* Size of smallest erasable EEPROM data unit in bytes. */
#define EEP_62_ERASE_UINTSIZE                            1u

/* Number of erase cycles specified for the EEP device (usually given in the device data sheet). */
#define EEP_62_SPECIFIED_ERASE_CYCLES                    1000000u

/* Specified maximum number of write cycles under worst case conditions of specific EEPROM hardware. */
#define EEP_62_ALLOWED_WRITE_CYCLES                      0u

/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
typedef P2FUNC(void, EEP_APPL_CODE, Eep_62_JobNotificationFct)(void);

typedef struct
{
    P2FUNC(void, EA_APPL_CODE, DevInitApi)(void);
    P2FUNC(Std_ReturnType, EA_APPL_CODE, DevReadApi)(Eep_62_AddressType readAddress, uint8 *readBufferPtr, Eep_62_LengthType readLength);
    P2FUNC(Std_ReturnType, EA_APPL_CODE, DevWriteApi)(Eep_62_AddressType writeAddress, const uint8 *writeBufferPtr, Eep_62_LengthType writeLength);
    P2FUNC(Std_ReturnType, EA_APPL_CODE, DevEraseApi)(Eep_62_AddressType eraseAddress, const uint8 ErasedValue, Eep_62_LengthType eraseLength);
}   Eep_62_DevApiType;
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

typedef struct
{
    uint8 DeviceId;
    /* baseAddress */
    Eep_62_AddressType baseAddress;
    /* the used size of EEPROM device */
    Eep_62_LengthType usedSize;
    /* fastReadBlockSize */
    Eep_62_LengthType fastReadBlockSize;
    /* fastWriteBlockSize */
    Eep_62_LengthType fastWriteBlockSize;
    /* normalReadBlockSize */
    Eep_62_LengthType normalReadBlockSize;
    /* normalWriteBlockSize */
    Eep_62_LengthType normalWriteBlockSize;
}   Eep_62_DeviceConfigType;

/* This is the type of the external data structure containing
the initialization data for the EEPROM driver.*/
typedef struct
{
    /* defaultMode */
    MemIf_ModeType defaultMode;
    /* Call cycle time of the EEPROM driver's main function. */
    /* jobCallCycle */
    uint32 jobCallCycle;
    /* jobEndNotification */
    const Eep_62_JobNotificationFct jobEndNotification;
    /* jobErrorNotification */
    const Eep_62_JobNotificationFct jobErrorNotification;
    /* Number of device configuration */
    uint8 DeviceConfigNbr;
    /* Parameter list of device configuration */
    P2CONST(Eep_62_DeviceConfigType, AUTOMATIC, EA_CONST) DeviceConfigPtr;
}   Eep_62_ConfigType;

extern CONST(Eep_62_ConfigType,EEP_CONST) Eep_62_ConfigSet[1];

extern CONST(Eep_62_DevApiType, EEP_CONST) Eep_62_DevHwApis_at[1];

#endif /* EEP_62_CFG_H_ */

