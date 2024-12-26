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

/**
 * @file  Spi.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifndef SPI_H
#define SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi_Driver.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define SPI_INSTANCE_ID SPI_INSTANCE_ID_VALUE

/* Version identification */
#define SPI_VENDOR_ID SPI_VENDOR_ID_VALUE
#define SPI_MODULE_ID SPI_MODULE_ID_VALUE

/* AUTOSAR specification version information */
#define SPI_AR_RELEASE_MAJOR_VERSION 4U
#define SPI_AR_RELEASE_MINOR_VERSION 3U
#define SPI_AR_RELEASE_REVISION_VERSION 1U

/* File version information */
#define SPI_SW_MAJOR_VERSION SPI_SW_MAJOR_VERSION_VALUE
#define SPI_SW_MINOR_VERSION SPI_SW_MINOR_VERSION_VALUE
#define SPI_SW_PATCH_VERSION SPI_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*Spi module levels */
#define SPI_LEVEL_0 0u
#define SPI_LEVEL_1 1u
#define SPI_LEVEL_2 2u

/*******************************************************************************
**                     Service IDs                                            **
*******************************************************************************/

/* Service ID for Spi_Init() */
#define SPI_INIT_SID (uint8)0x00
/* Service ID for Spi_DeInit() */
#define SPI_DEINIT_SID (uint8)0x01
/* Service ID for Spi_WriteIB() */
#define SPI_WRITEIB_SID (uint8)0x02
/* Service ID for Spi_AsyncTransmit() */
#define SPI_ASYNCTRANSMIT_SID (uint8)0x03
/* Service ID for Spi_ReadIB() */
#define SPI_READIB_SID (uint8)0x04
/* Service ID for Spi_SetupEB() */
#define SPI_SETUPEB_SID (uint8)0x05
/* Service ID for Spi_GetStatus() */
#define SPI_GETSTATUS_SID (uint8)0x06
/* Service ID for Spi_GetJobResult() */
#define SPI_GETJOBRESULT_SID (uint8)0x07
/* Service ID for Spi_GetSequenceResult() */
#define SPI_GETSEQUENCERESULT_SID (uint8)0x08
/* Service ID for Spi_GetVersionInfo() */
#define SPI_GETVERSIONINFO_SID (uint8)0x09
/* Service ID for Spi_SyncTransmit() */
#define SPI_SYNCTRANSMIT_SID (uint8)0x0A
/* Service ID for Spi_GetHWUnitStatus() */
#define SPI_GETHWUNITSTATUS_SID (uint8)0x0B
/* Service ID for Spi_Cancel() */
#define SPI_CANCEL_SID (uint8)0x0C
/* Service ID for Spi_SetAyncMode() */
#define SPI_SETAYNCMODE_SID (uint8)0x0D
/* Service ID for Spi_MainFunction_Driving() */
#define SPI_MAINFUNCTION_HANDLING_SID (uint8)0x10

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* API services invoked with invalid channel ID */
#define SPI_E_PARAM_CHANNEL (uint8)0x0A

/* API services invoked with invalid job ID */
#define SPI_E_PARAM_JOB (uint8)0x0B

/* API services invoked with invalid sequence ID */
#define SPI_E_PARAM_SEQ (uint8)0x0C

/* Spi_SetupEB API invoked with length greater than configured length */
#define SPI_E_PARAM_LENGTH (uint8)0x0D

/* Spi_GetHWUnitStatus API invoked with invalid hardware unit ID */
#define SPI_E_PARAM_UNIT (uint8)0x0E

/* Spi_GetVersionInfo API invoked with invalid pointer */
#define SPI_E_PARAM_POINTER (uint8)0x10

/* API services invoked before the initialization of SPI Driver */
#define SPI_E_UNINIT (uint8)0x1A

/* Spi_init API service called while the Spi driver has already been initialized */
#define SPI_E_ALREADY_INITIALIZED (uint8)0x4A

/* API services invoked in a wrong sequence */
#define SPI_E_SEQ_PENDING (uint8)0x2A

/* Spi_SyncTransmit API invoked at wrong time */
#define SPI_E_SEQ_IN_PROCESS (uint8)0x3A

/* Spi ASyncTransmit error eg:fifo udr/ovr or dma err, */
#define SPI_E_ASYNC_ERROR (uint8)0x3B

/* Spi cancel error eg:seq not in queue  */
#define SPI_E_CANCEL_ERROR (uint8)0x3C

/* multi core illegal access */
#define SPI_E_ILLEGAL_RES (uint8)0x3D
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/**
 * @brief   Function init spi driver.
 *
 * @details Init spi controller base pre config types.
 *
 * @param   ConfigPtr spi config pointe.
 *
 * @return  NONE
 */
extern FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr);

/**
 * @brief   Deinit spi driver.
 *
 * @details Deinit spi driver when driver in idle status.
 *
 * @param   ConfigPtr spi config pointe.
 *
 * @return  Std_ReturnType E_OK/E_NOT_OK
 */
extern FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void);

/**
 * @brief   Write prepare transmit data to internal buffer.
 *
 * @details Application data will be copy to spi interrnal buffer.
 *
 * @param   Channel spi channel index.
 *          DataBufferPtr pointe to application buffer.
 *
 * @return  Std_ReturnType E_OK/E_NOT_OK
 */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
extern FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB(Spi_ChannelType Channel,
        const Spi_DataBufferType *DataBufferPtr);
#endif

/**
 * @brief   spi async transmit.
 *
 * @details transmit data use interrupt mode.
 *
 * @param   Sequence include jobs and channels.
 *
 * @return  Std_ReturnType E_OK/E_NOT_OK
 */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
extern FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(Spi_SequenceType Sequence);
#endif

/**
 * @brief   read data from spi internal buffer to application.
 *
 * @details read data from spi driver internal buffer to application buffer.
 *
 * @param   Channel spi channel index.
 *          DataBufferPointer pointe to application buffer.
 *
 * @return  Std_ReturnType E_OK/E_NOT_OK
 */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
extern FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB(Spi_ChannelType Channel,
        Spi_DataBufferType *DataBufferPointer);
#endif

/**
 * @brief   transmit/receive data use application buffer without copy.
 *
 * @details the data will be write to ro read from fifo directly.
 *
 * @param   Channel spi channel index.
 *          SrcDataBufferPtr pointe to buffer need be transmit.
 *          DesDataBufferPtr pointe to buffer need be receive.
 *          Length transmit data length.
 *
 * @return  Std_ReturnType E_OK/E_NOT_OK
 */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
extern FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB(Spi_ChannelType Channel,
        const Spi_DataBufferType *SrcDataBufferPtr,
        Spi_DataBufferType *DesDataBufferPtr,
        Spi_NumberOfDataType Length);
#endif

/**
 * @brief   return spi driver status.
 *
 * @details return spi driver status.
 *
 * @param   NONE.
 *
 * @return  Spi_StatusType.
 */
extern FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void);

/**
 * @brief   return current spi job status.
 *
 * @details return current spi job status.
 *
 * @param   Job index.
 *
 * @return  Spi_JobType.
 */
extern FUNC(Spi_JobResultType, SPI_CODE)
Spi_GetJobResult(Spi_JobType Job);

/**
 * @brief   return current spi sequence status.
 *
 * @details return current spi sequence status.
 *
 * @param   Sequence index.
 *
 * @return  Spi_SequenceType.
 */
extern FUNC(Spi_SeqResultType, SPI_CODE)
Spi_GetSequenceResult(Spi_SequenceType Sequence);

/**
 * @brief   return spi driver verison.
 *
 * @details return spi driver verison.
 *
 * @param   versioninfo type.
 *
 * @return  NONE.
 */
#if (SPI_VERSION_INFO_API == STD_ON)
extern FUNC(void, SPI_CODE) Spi_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/**
 * @brief   spi sync transmit.
 *
 * @details transmit data in polling mode, wait until data transmit finshed.
 *
 * @param   Sequence index.
 *
 * @return  Std_ReturnType E_OK/E_NOT_OK
 */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
extern FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(Spi_SequenceType Sequence);
#endif

/**
 * @brief   return spi hardware unit status.
 *
 * @details return spi hardware unit status.
 *
 * @param   HWUnit index.
 *
 * @return  Spi_StatusType.
 */
#if (SPI_HW_STATUS_API == STD_ON)

extern FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
#endif

/**
 * @brief   cancel spi transmit.
 *
 * @details cancel spi transmit when sequence transmit finshed.
 *
 * @param   Sequence index.
 *
 * @return  NONE.
 */
#if (SPI_CANCEL_API == STD_ON)
extern FUNC(void, SPI_CODE) Spi_Cancel(Spi_SequenceType Sequence);
#endif

/**
 * @brief   set async transmit mode.
 *
 * @details async mode: polling mode or interrupt mode.
 *
 * @param   Mode polling or interrupt.
 *
 * @return  Std_ReturnType E_OK/E_NOT_OK.
 */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
extern FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(Spi_AsyncModeType Mode);
#endif

/**
 * @brief   set async transmit mode.
 *
 * @details async mode: polling mode.
 *
 * @param   NONE.
 *
 * @return  NONE.
 */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
extern FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void);
#endif

#if (SPI_CANCEL_API == STD_ON && SPI_ENABLE_SLAVE == STD_ON)
FUNC(void, SPI_CODE) Spi_SlaveCancel(Spi_SequenceType Sequence);
#endif
#if (SPI_ENABLE_SLAVE == STD_ON)
sint32 Spi_GetSlaveTransmittedBytes(Spi_SequenceType SequenceId);
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* SPI_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
