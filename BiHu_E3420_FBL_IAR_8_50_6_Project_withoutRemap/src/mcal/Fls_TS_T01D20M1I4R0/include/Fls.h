/*
* SEMIDRIVE Copyright Statement
* Copyright (c) SEMIDRIVE. All rights reserved
*
* This software and all rights therein are owned by SEMIDRIVE, and are
* protected by copyright law and other relevant laws, regulations and
* protection. Without SEMIDRIVE's prior written consent and/or related rights,
* please do not use this software or any potion thereof in any form or by any
* means. You may not reproduce, modify or distribute this software except in
* compliance with the License. Unless required by applicable law or agreed to
* in writing, software distributed under the License is distributed on
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/

/*
* @file  Fls.h
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifndef  FLS_H
#define  FLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "Std_Types.h"
#include "spi_nor.h"
#include "MemIf_Types.h"
#include "Fls_Cfg.h"
#include "taishan_xspi_drv.h"

/*****************Version Information************/
#define FLS_AR_MAJOR_VERSION  4U
#define FLS_AR_MINOR_VERSION  3U
#define FLS_AR_PATCH_VERSION  1U

#define FLS_SW_MAJOR_VERSION  1U
#define FLS_SW_MINOR_VERSION  0U
#define FLS_SW_PATCH_VERSION  0U

/*Service ID for DET reporting */
#define FLS_E_PARAM_CONFIG                 0x01U
#define FLS_E_PARAM_ADDRESS                0x02U
#define FLS_E_PARAM_LENGTH                 0x03U
#define FLS_E_PARAM_DATA                   0x04U
#define FLS_E_UNINIT                       0x05U
#define FLS_E_BUSY                         0x06U
#define FLS_E_VERIFY_ERASE_FAILED          0x07U
#define FLS_E_VERIFY_WRITE_FAILED          0x08U
#define FLS_E_TIMEOUT                      0x09U
#define FLS_E_PARAM_POINTER                0x0AU

/* Transient Faults ID*/
#define FLS_E_ERASE_FAILED                 0x01U
#define FLS_E_WRITE_FAILED                 0x02U
#define FLS_E_READ_FAILED                  0x03U
#define FLS_E_COMPARE_FAILED               0x04U
#define FLS_E_UNEXPECTED_FLASH_ID          0x05U
#define FLS_E_BLANK_CHECK_FAILED_ID        0x06U    /* The error code is not defined in specification*/

#define FLS_MODULE_ID         (0x5CU)

/* Service id's for fls functions */
#define FLS_INIT_ID                    0x00U
#define FLS_ERASE_ID                   0x01U
#define FLS_WRITE_ID                   0x02U
#define FLS_CANCEL_ID                  0x03U
#define FLS_GET_STATUS_ID              0x04U
#define FLS_GET_JOB_RESULT_ID          0x05U
#define FLS_MAIN_FUNCTION_ID           0x06U
#define FLS_READ_ID                    0x07U
#define FLS_COMPARE_ID                 0x08U
#define FLS_SET_MODE_ID                0x09U
#define FLS_GET_VERSION_INFO_ID        0x10U
#define FLS_TIMEOUT_ID                 0x0AU
#define FLS_BLANKCHECK_ID              0x0BU
#define FLS_GET_CAPACITY_ID            0x0CU

/* Number of flash devices */
#define NUM_FLASH_DEVICES 1U
#define FLS_CANCEL_INDEX 1U
#define FLS_REQUESTED_CANCEL 0U
#define FLS_NOT_REQUESTED_CANCEL 1U

typedef enum {
    FLS_OK_E               = 0x00,
    FLS_ERROR_E            = 0x01,
    FLS_ERASE_E            = 0x02,
    FLS_WRITE_E            = 0x03,
    FLS_READ_E             = 0x04,
    FLS_COMPARE_E          = 0x05,
    FLS_BUSY_E             = 0x06,
    FLS_BLANKCHECK_E       = 0x07,
    FLS_IDLE_E             = 0x08,
    FLS_CMD_SEND_E         = 0x09,
    FLS_WRITE_DONE_E       = 0x0A,
    /* Erros Info*/
    FLS_ADDR_ERR_E         = 0xFE,
    FLS_LENTGH_ERR_E       = 0xFF
} Fls_stReturnInfo;

/* Type Definitions */
typedef uint32 Fls_AddressType;
typedef uint32 Fls_LengthType;

typedef struct {
    Fls_AddressType      FlsSectorStartAddr;
    Fls_LengthType       FlsSectorSize;
    Fls_LengthType       FlsPageSize;
    Fls_LengthType       FlsNumberOfSectors;
    Fls_LengthType       FlsTotalSize;
    int                  ControllerIndex;
} Fls_SectorConfigType;

typedef struct {
    Fls_stReturnInfo stReturn;
    Fls_LengthType  BytesCompleted;
} Fls_stDriverRet;

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
typedef struct Fls_StateType {
    /* Erase and Write Timeout Cycle Count */
    uint32 FlsEraseTimeoutCycleCount;
    uint32 FlsWriteTimeoutCycleCount;

    /* Timeout handling status */
    uint8 FlsTimeoutControl;
} Fls_StateType;
#endif

enum spi_nor_special_type {
    FLS_SPECIAL_AUTO = 0,
    FLS_SPECIAL_IS25LP064A,
    FLS_SPECIAL_HYPERRAM,
    FLS_SPECIAL_MCP,            /* device mode = SPI_NOR_DEV_SWITCH_MODE */
};

enum Fls_interface_type {
    FLS_INTERFACE_SPI_NOR,
    FLS_INTERFACE_HYPERBUS
};

typedef struct {
    uint32   FlsCallCycle;
    /* Modes */
    MemIf_ModeType FlsDefaultMode;
    uint32    FlsMaxReadFastMode;
    uint32    FlsMaxReadNormalMode;
    uint32    FlsMaxWriteFastMode;
    uint32    FlsMaxWriteNormalMode;
    uint32   FlsProtection;
    uint8   FlsSectorListSize;
    uint32   FlsTotalSize;
    Fls_SectorConfigType *FlsSectorList;
    Fls_ProgramDescriptorType *FlsProgDesc;
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    Fls_StateType   *FlsStateVarPtr;
#endif  /*FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON*/
} Fls_Flash_ConfigType;  /* EB FlsConfigSet */

typedef struct {
    Fls_Controller_ID_t ID;
    struct spi_nor_config HostConfig;
    enum spi_nor_special_type   FlsSpecialFlag;
    void    *FlsPrivateData;  // Fls_ContextType*
} Fls_OSPIController_ConfigType; /* EB FlsController */

typedef struct {
    uint8 async_mode;
    Fls_Flash_ConfigType Flash;
    Fls_OSPIController_ConfigType OSPIController[MAX_NUMBER_OF_CONTROLLER];
    uint8 NumberOfController;
} Fls_ConfigType;

#define PORT_MAX_FLASH_NUM (2u)
typedef struct fls_context {
    uint8 index;
    struct spi_nor nor[PORT_MAX_FLASH_NUM];
    uint8 FlashNum;
    struct spi_nor_host host;
    Fls_OpsType *ops;
    const Fls_OSPIController_ConfigType *ControllerConfig;
    const Fls_Flash_ConfigType *FlashConfig;
    Fls_SectorConfigType *CurrentSector;
    Fls_AddressType      FlsBaseAddr;
    uint64               TotalSize;
    uint8 MemIfMode;
    uint32 MaxNumBytesRead;
    uint32 MaxNumBytesWrite;
} Fls_ContextType;

extern const Fls_ConfigType *Fls_ConfigPtr;
extern const Fls_ConfigType Fls_ConfigData;

extern Std_ReturnType Fls_WriteVerification(Fls_AddressType TargetAddress,
        const uint8 *SourceAddressPtr, Fls_LengthType Length );
extern Std_ReturnType Fls_EraseVerification(Fls_AddressType TargetAddress, Fls_LengthType Length );
extern uint8 Fls_TimeOut(const uint8 ServiceID);

/******************************************************************************
** Service name        : Fls_Init                                               **
** Parameters (in)     : ConfigPtr  Pointer to flash driver configuration set   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Initializes the Flash Driver                            **
******************************************************************************/
extern void Fls_Init(const Fls_ConfigType *ConfigPtr );

/******************************************************************************
** Service name        : Fls_Erase                                              **
** Parameters (in)     : Fls_AddressType TargetAddress: Target address in flash **
**                                                   memory                     **
**                      Fls_LengthType Length: Number of bytes to erase         **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType E_OK: erase command has been accepted   **
**                                   E_NOT_OK: erase command has not been       **
**                                               accepted                       **
** Description        : Erases flash sector(s)                                  **
******************************************************************************/
extern Std_ReturnType Fls_Erase(  Fls_AddressType TargetAddress,
                                  Fls_LengthType Length);

/******************************************************************************
** Service name        : Fls_Write                                              **
** Parameters (in)     : Fls_AddressType TargetAddress: Target address in flash **
**                                                   memory                     **
**                      uint8* SourceAddressPtr: Pointer to source data buffer  **
**                      Fls_LengthType Length: Number of bytes to write         **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType E_OK: write command has been accepted   **
**                                   E_NOT_OK: write command has not been       **
**                                               accepted                       **
** Description        : Writes one or more complete flash page                  **
******************************************************************************/
extern Std_ReturnType Fls_Write( Fls_AddressType TargetAddress,
                                 const uint8 *SourceAddressPtr,
                                 Fls_LengthType Length );

/******************************************************************************
** Service name        : Fls_Cancel                                             **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Cancels an ongoing job                                  **
******************************************************************************/
#if (FLS_CANCEL_API == STD_ON)
extern void Fls_Cancel( void );
#endif

/******************************************************************************
** Service name        : Fls_GetStatus                                          **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_StatusType                                       **
** Description        : Returns the driver state                                **
******************************************************************************/
#if (FLS_GET_STATUS_API == STD_ON)
extern MemIf_StatusType Fls_GetStatus( void );
#endif

/******************************************************************************
** Service name        : Fls_GetJobResult                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_JobResultType                                    **
** Description        : Returns the result of the last job                      **
******************************************************************************/
#if (FLS_GET_JOB_RESULT_API == STD_ON)
extern MemIf_JobResultType Fls_GetJobResult( void );
#endif

/******************************************************************************
** Service name        : Fls_MainFunction                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Performs the processing of jobs                         **
******************************************************************************/
extern void Fls_MainFunction( void );

/******************************************************************************
** Service name        : Fls_Read                                               **
** Parameters (in)     : Fls_AddressType SourceAddress :Source address in flash **
**                                                      memory                  **
**                      uint8* TargetAddressPtr :Pointer to target data buffer  **
**                    Fls_LengthType Length : Number of bytes to read           **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description        : Reads from flash memory                                 **
******************************************************************************/
extern Std_ReturnType Fls_Read( Fls_AddressType SourceAddress,
                                uint8 *TargetAddressPtr,
                                Fls_LengthType Length );

/******************************************************************************
** Service name        : Fls_Compare                                            **
** Parameters (in)     : Fls_AddressType SourceAddress                          **
**                      const uint8* TargetAddressPtr                           **
**                    Fls_LengthType Length    : Number of bytes to compare     **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description        : Compares the contents of an area of flash memory with   **
**                    that of an application data buffer                        **
******************************************************************************/
#if (FLS_COMPARE_API == STD_ON)
extern Std_ReturnType Fls_Compare( Fls_AddressType SourceAddress,
                                   const uint8 *TargetAddressPtr,
                                   Fls_LengthType Length );
#endif

/******************************************************************************
** Service name        : Fls_SetMode                                            **
** Parameters (in)     : MemIf_ModeType Mode (Mode MEMIF_MODE_SLOW /            **
**                                         MEMIF_MODE_FAST)                     **
** Parameters (out)    : None                                                   **
** Return value        : void                                                   **
** Description        : Sets the flash driver's operation mode                  **
******************************************************************************/
#if (FLS_SET_MODE_API == STD_ON)
extern void Fls_SetMode( MemIf_ModeType Mode );
#endif

/******************************************************************************
** Service name        : Fls_BlankCheck                                         **
** Parameters (in)     : Fls_AddressType TargetAddress                          **
**                    Fls_LengthType Length    : Number of bytes to compare     **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description        : The function Fls_BlankCheck shall verify, whether a     **
                      given memory area has been erased but not (yet)           **
                      programmed.                                               **
******************************************************************************/
#if (FLS_COMPARE_API == STD_ON)
Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length);
#endif

#if (FLS_VERSION_INFO_API == STD_ON)
void Fls_GetVersionInfo( Std_VersionInfoType *VersioninfoPtr );
#endif

/******************************************************************************
** Service name        : Fls_GetSector                                      **
** Parameters (in)     : Fls_AddressType                                    **
** Parameters (out)    : Fls_SectorConfigType                               **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                 **
** Description        : Obtain the sector config for TargetAddress          **
******************************************************************************/
Std_ReturnType Fls_GetSector( Fls_AddressType TargetAddress, const Fls_SectorConfigType** SectorConfig );

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef FLS_H */
