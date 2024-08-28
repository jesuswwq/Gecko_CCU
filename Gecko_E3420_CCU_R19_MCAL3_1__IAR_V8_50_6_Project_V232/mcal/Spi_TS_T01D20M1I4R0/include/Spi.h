/** **************************************************************************************
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
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 *  \file     Spi.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifndef SPI_H
#define SPI_H
/**
 *  \defgroup MCAL_SPI SPI Driver
 *
 *  The SPI Handler/Driver provides services for reading from and writing to devices
 *  connected via SPI busses.
 *
 *  This spi driver provide only master mode transmission via chip spi controllers
 *  depend on user configurations <br>
 *  This module relevanto to dam module in dma mode, too short transmission dma mode
 *  is not recommended.<br>
 *  \sa MCAL_SPI_CFG
 *  \sa MCAL_SPI_API
 *  \sa MCAL_SPI_MACRO
 */

/** \{ */

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"
#include "Spi_Cfg.h"
#include "Spi_PbCfg.h"
/** Traceability       : SWSR_SPI_085 */
#include "Spi_Types.h"
/**
 *  \defgroup MCAL_SPI_CFG SPI Configuration.
 *
 * This files defines SPI MCAL configuration structures
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_SPI_API SPI Api.
 *
 * This files defines SPI MCAL api
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_SPI_MACRO SPI macro.
 *
 * This files defines SPI MCAL macro
 *  \{
 */

/** \} */

/**
 *  \addtogroup MCAL_SPI_MACRO SPI macro.
 *  \{
 */
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  Service ID for Spi_Init() */
#define SPI_INIT_SID (uint8)0x00
/** \brief  Service ID for Spi_DeInit() */
#define SPI_DEINIT_SID (uint8)0x01
/** \brief  Service ID for Spi_WriteIB() */
#define SPI_WRITEIB_SID (uint8)0x02
/** \brief  Service ID for Spi_AsyncTransmit() */
#define SPI_ASYNCTRANSMIT_SID (uint8)0x03
/** \brief  Service ID for Spi_ReadIB() */
#define SPI_READIB_SID (uint8)0x04
/** \brief  Service ID for Spi_SetupEB() */
#define SPI_SETUPEB_SID (uint8)0x05
/** \brief  Service ID for Spi_GetStatus() */
#define SPI_GETSTATUS_SID (uint8)0x06
/** \brief  Service ID for Spi_GetJobResult() */
#define SPI_GETJOBRESULT_SID (uint8)0x07
/** \brief  Service ID for Spi_GetSequenceResult() */
#define SPI_GETSEQUENCERESULT_SID (uint8)0x08
/** \brief  Service ID for Spi_GetVersionInfo() */
#define SPI_GETVERSIONINFO_SID (uint8)0x09
/** \brief  Service ID for Spi_SyncTransmit() */
#define SPI_SYNCTRANSMIT_SID (uint8)0x0A
/** \brief  Service ID for Spi_GetHWUnitStatus() */
#define SPI_GETHWUNITSTATUS_SID (uint8)0x0B
/** \brief  Service ID for Spi_Cancel() */
#define SPI_CANCEL_SID (uint8)0x0C
/** \brief  Service ID for Spi_SetAyncMode() */
#define SPI_SETAYNCMODE_SID (uint8)0x0D
/** \brief  Service ID for Spi_MainFunction_Driving() */
#define SPI_MAINFUNCTION_HANDLING_SID (uint8)0x10

/******************************************************************************************
**                      DET Error Codes
******************************************************************************************/
/** \brief  API services invoked with invalid channel ID */
#define SPI_E_PARAM_CHANNEL (uint8)0x0A

/** \brief  API services invoked with invalid job ID */
#define SPI_E_PARAM_JOB (uint8)0x0B

/** \brief  API services invoked with invalid sequence ID */
#define SPI_E_PARAM_SEQ (uint8)0x0C

/** \brief  Spi_SetupEB API invoked with length greater than configured length */
#define SPI_E_PARAM_LENGTH (uint8)0x0D

/** \brief  Spi_GetHWUnitStatus API invoked with invalid hardware unit ID */
#define SPI_E_PARAM_UNIT (uint8)0x0E

/** \brief  Spi_GetVersionInfo API invoked with invalid pointer */
#define SPI_E_PARAM_POINTER (uint8)0x10

/** \brief  API services invoked before the initialization of SPI Driver */
#define SPI_E_UNINIT (uint8)0x1A

/** \brief  Spi_init API service called while the Spi driver has already been initialized */
#define SPI_E_ALREADY_INITIALIZED (uint8)0x4A

/** \brief  API services invoked in a wrong sequence */
#define SPI_E_SEQ_PENDING (uint8)0x2A

/** \brief  Spi_SyncTransmit API invoked at wrong time */
#define SPI_E_SEQ_IN_PROCESS (uint8)0x3A

/** \brief  Spi ASyncTransmit error eg:fifo udr/ovr or dma err, */
#define SPI_E_ASYNC_ERROR (uint8)0x3B

/** \brief  Spi cancel error eg:seq not in queue  */
#define SPI_E_CANCEL_ERROR (uint8)0x3C

/** \brief  multi core illegal access */
#define SPI_E_ILLEGAL_RES (uint8)0x3D
/** \brief  channel operation  not match */
#define SPI_E_CHANNEL_OPS (uint8)0x3E
/** \brief  channel operation  not align  */
#define SPI_E_CHANNEL_ALIGN (uint8)0x3F

/** \} */

/**
 *  \addtogroup MCAL_SPI_API SPI Api.
 *  \{
 */
/******************************************************************************************
 *                          Global Function Declarations
 *****************************************************************************************/
/** **************************************************************************************
 * \brief Initializes the SPI hardware units and driver.
 *
 * \verbatim
 * Syntax             : void Spi_Init(const Spi_ConfigType * ConfigPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initializes the SPI hardware units and driver
 *                      by the parameter configPtr.
 * \endverbatim
 * Traceability       : SWSR_SPI_073 SWSR_SPI_082 SWSR_SPI_083 SWSR_SPI_136 SWSR_SPI_137
 *                      SWSR_SPI_138 SWSR_SPI_139
 *****************************************************************************************/
void Spi_Init(const Spi_ConfigType *ConfigPtr);
/** **************************************************************************************
 * \brief Deinitialize the SPI hardware units and driver.
 *
 * \verbatim
 *
 * Syntax             : Std_ReturnType Spi_DeInit(void)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Deinitialize the SPI hardware units and driver.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_142 SWSR_SPI_143 SWSR_SPI_144 SWSR_SPI_145 SWSR_SPI_146
 *                      SWSR_SPI_147 SWSR_SPI_148 SWSR_SPI_149 SWSR_SPI_150
 *****************************************************************************************/
Std_ReturnType Spi_DeInit(void);
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
/** **************************************************************************************
 * \brief Writing one or more data to an IB SPI Handler/Driver channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_WriteIB(
 *                          Spi_ChannelType Channel
 *                          const Spi_DataBufferType *DataBufferPtr
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel       - Specify the channel ID.
 *                      DataBufferPtr - Pointer to user buffer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: write command has been accepted.
 *                      E_NOT_OK: write command has not been accepted.
 *
 * Description        : Writing one or more data to an IB SPI Handler/Driver channel.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_025 SWSR_SPI_151 SWSR_SPI_152 SWSR_SPI_153
 *                      SWSR_SPI_154 SWSR_SPI_155 SWSR_SPI_156 SWSR_SPI_157
 *                      SWSR_SPI_158 SWSR_SPI_159
 *****************************************************************************************/
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr);
#endif/*((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/** **************************************************************************************
 * \brief Issue once transmission asynchronously.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Sequence - Specify the Sequence ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Transmission command has been accepted
 *                      E_NOT_OK: Transmission command has not been accepted
 *
 * Description        : Issue once transmission asynchronously.
 * \endverbatim
 * Traceability       : SWSR_SPI_072 SWSR_SPI_160 SWSR_SPI_161 SWSR_SPI_162
 *                      SWSR_SPI_163 SWSR_SPI_164 SWSR_SPI_176
 *****************************************************************************************/
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence);

#endif/*((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))*/

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
/** **************************************************************************************
 * \brief reading one or more data from an IB SPI Handler/Driver channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_ReadIB(
 *                               Spi_ChannelType Channel,
 *                               Spi_DataBufferType *DataBufferPointer)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - Pointer to configuration set
 *                      DataBufferPointer - Point to user data buffer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : reading one or more data from an IB SPI Handler/Driver channel.
 * \endverbatim
 * Traceability       : SWSR_SPI_177 SWSR_SPI_178 SWSR_SPI_179 SWSR_SPI_180
 *                      SWSR_SPI_181 SWSR_SPI_182 SWSR_SPI_183 SWSR_SPI_184
 *                      SWSR_SPI_185
 *****************************************************************************************/
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPointer);
#endif/* ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))*/

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
/** **************************************************************************************
 * \brief setting the buffers and the length of data for the external buffer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel,
 *                           const Spi_DataBufferType *SrcDataBufferPtr,
 *                           Spi_DataBufferType *DesDataBufferPtr,
 *                           Spi_NumberOfDataType Length)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - Specify the External type channel ID.
 *                      SrcDataBufferPtr - Pointer to Txdata buffer.
 *                      DesDataBufferPtr - Pointer to RxData Buffer.
 *                      Length - Specify the buffer lenth.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Setup command has been accepted
 *                      E_NOT_OK: Setup command has not been accepted
 *
 * Description        : setting the buffers and the length of data for the external buffer.
 * \endverbatim
 * Traceability       : SWSR_SPI_028 SWSR_SPI_029 SWSR_SPI_030 SWSR_SPI_077
 *                      SWSR_SPI_078 SWSR_SPI_172 SWSR_SPI_186 SWSR_SPI_187
 *                      SWSR_SPI_188 SWSR_SPI_189 SWSR_SPI_190 SWSR_SPI_191
 *                      SWSR_SPI_194 SWSR_SPI_195 SWSR_SPI_254 SWSR_SPI_117
 *****************************************************************************************/
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel,
                           const Spi_DataBufferType *SrcDataBufferPtr,
                           Spi_DataBufferType *DesDataBufferPtr,
                           Spi_NumberOfDataType Length);
#endif /** ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2)) */

/** **************************************************************************************
 * \brief getting the status of SPI Driver Component.
 *
 * \verbatim
 * Syntax             : Spi_StatusType Spi_GetStatus(void)
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : SPI_UNINIT: Driver is uninitialized.
 *                      SPI_BUSY: Driver is busy.
 *                      SPI_IDLE: Driver is idle.
 *
 * Description        : getting the status of SPI Driver Component.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_032 SWSR_SPI_096 SWSR_SPI_097 SWSR_SPI_098
 *                      SWSR_SPI_196 SWSR_SPI_197 SWSR_SPI_198 SWSR_SPI_199
 *****************************************************************************************/
Spi_StatusType Spi_GetStatus(void);
/** **************************************************************************************
 * \brief getting result of the specified job.
 *
 * \verbatim
 * Syntax             : Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Job - Specify the job ID
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The last transmission result of the specified Job.
 *
 * Description        : getting result of the specified job.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_071 SWSR_SPI_081 SWSR_SPI_105 SWSR_SPI_200 SWSR_SPI_201
 *                      SWSR_SPI_202 SWSR_SPI_203 SWSR_SPI_204
 *****************************************************************************************/
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job);

/** **************************************************************************************
 * \brief getting result of the specified sequence.
 *
 * \verbatim
 * Syntax             : Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Sequence - Specify the Sequence ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The last transmission result of the specified Sequence.
 *
 * Description        : getting result of the specified sequence.
 * \endverbatim
 * Traceability       : SWSR_SPI_071 SWSR_SPI_081 SWSR_SPI_111 SWSR_SPI_112
 *                      SWSR_SPI_113 SWSR_SPI_205 SWSR_SPI_206 SWSR_SPI_207
 *                      SWSR_SPI_208
 *****************************************************************************************/
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence);

#if (SPI_VERSION_INFO_API == STD_ON)
/** **************************************************************************************
 * \brief Spi_GetVersionInfo.
 *
 * \verbatim
 * Syntax             : void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo)
 *
 * Service ID[hex]    : 0x09
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : versioninfo - Pointer to versioninfo varaable.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Get the driver version infomations.
 * \endverbatim
 * Traceability       : SWSR_SPI_209 SWSR_SPI_210
 *****************************************************************************************/
void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif/*(SPI_VERSION_INFO_API == STD_ON)*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/** **************************************************************************************
 * \brief This function issue an transmitting data synchronously.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
 *
 * Service ID[hex]    : 0x0A
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Sequence - Specify the Sequence ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Transmission command has been accepted
 *                      E_NOT_OK: Transmission command has not been accepted
 *
 * Description        : This function issue an transmitting data synchronously.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_031 SWSR_SPI_034 SWSR_SPI_035 SWSR_SPI_060
 *                      SWSR_SPI_061 SWSR_SPI_065 SWSR_SPI_072 SWSR_SPI_076
 *                      SWSR_SPI_211 SWSR_SPI_212 SWSR_SPI_213 SWSR_SPI_214
 *                      SWSR_SPI_215 SWSR_SPI_216 SWSR_SPI_217 SWSR_SPI_218
 *                      SWSR_SPI_219 SWSR_SPI_220
 *****************************************************************************************/
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence);
#endif/* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#if (SPI_HW_STATUS_API == STD_ON)
/** **************************************************************************************
 * \brief This function returns Specify HwUint Status.
 *
 * \verbatim
 * Syntax             : Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
 *
 * Service ID[hex]    : 0x0B
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : HWUnit - Specify the HwUint ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : SPI_UNINIT: The HwUint is uninitialized.
 *                      SPI_BUSY: The HwUint is busy.
 *                      SPI_IDLE: The HwUint is idle.
 *
 * Description        : Get the status of the SPI Hardware micro-controller peripheral
 * \endverbatim
 * Traceability       : SWSR_SPI_070 SWSR_SPI_079 SWSR_SPI_080 SWSR_SPI_099
 *                      SWSR_SPI_100 SWSR_SPI_221 SWSR_SPI_222 SWSR_SPI_223
 *                      SWSR_SPI_224 SWSR_SPI_225 SWSR_SPI_226
 *****************************************************************************************/
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
#endif /** End of (SPI_HW_STATUS_API == STD_ON) */

#if (SPI_CANCEL_API == STD_ON)
/** **************************************************************************************
 * \brief Cancel the transmission of a on-going sequence.
 *
 * \verbatim
 * Syntax             : void Spi_Cancel(Spi_SequenceType Sequence)
 *
 * Service ID[hex]    : 0x0C
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Sequence - Specify the sequence ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Cancel the transmission of a on-going sequence.
 * \endverbatim
 * Traceability       : SWSR_SPI_227 SWSR_SPI_228 SWSR_SPI_229 SWSR_SPI_230 SWSR_SPI_231
 *****************************************************************************************/
void Spi_Cancel(Spi_SequenceType Sequence);
#endif /** End of (SPI_CANCEL_API == STD_ON) */

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/** **************************************************************************************
 * \brief This function setting the asynchronous mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
 *
 * Service ID[hex]    : 0x0D
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Mode - Specify the mode of asynchronous.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Transmission command has been accepted
 *                      E_NOT_OK: Transmission command has not been accepted
 *
 * Description        : Setting the asynchronous mode as Poling or Interrupt.
 * \endverbatim
 * Traceability       : SWSR_SPI_071 SWSR_SPI_081 SWSR_SPI_232 SWSR_SPI_233 SWSR_SPI_234
 *                      SWSR_SPI_235 SWSR_SPI_236 SWSR_SPI_237 SWSR_SPI_238 SWSR_SPI_239
 *                      SWSR_SPI_240
 *****************************************************************************************/
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode);

#endif /** End of (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/** **************************************************************************************
 * \brief This function asynchronous transmission in polling mode main function.
 *
 * \verbatim
 * Syntax             : void Spi_MainFunction_Handling(void)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Asynchronous transmission in polling mode handler.
 * \endverbatim
 * Traceability       : SWSR_SPI_071 SWSR_SPI_081 SWSR_SPI_241
 *****************************************************************************************/
void Spi_MainFunction_Handling(void);
#endif /** (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

#ifdef __cplusplus
}
#endif

/** \} */

/** \} */

#endif /** SPI_H */
/** End of file */

