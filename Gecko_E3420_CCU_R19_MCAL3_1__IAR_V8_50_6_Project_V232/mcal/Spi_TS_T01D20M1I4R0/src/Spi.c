/** *****************************************************************************************************
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
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \file     Spi.c
 * \brief    AUTOSAR 4.3.1 MCAL can Driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files
 *******************************************************************************************************/
#include "Spi.h"
#include "SchM_Spi.h"
#include "Spi_Driver.h"
/********************************************************************************************************
 *                                 Imported Compiler Switch Checks
 *******************************************************************************************************/
#ifndef SPI_SW_MAJOR_VERSION
#error "SPI_SW_MAJOR_VERSION is not defined."
#endif

#ifndef SPI_SW_MINOR_VERSION
#error "SPI_SW_MINOR_VERSION is not defined."
#endif

#ifndef SPI_SW_PATCH_VERSION
#error "SPI_SW_PATCH_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef SPI_AR_RELEASE_MAJOR_VERSION
#error "SPI_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef SPI_AR_RELEASE_MINOR_VERSION
#error "SPI_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef SPI_AR_RELEASE_REVISION_VERSION
#error "SPI_AR_RELEASE_REVISION_VERSION is not defined."
#endif

/** \brief  AUTOSAR Major and Minor release version check. */
#if(SPI_AR_RELEASE_MAJOR_VERSION != 4U)
#error "SPI_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(SPI_AR_RELEASE_MINOR_VERSION != 3U)
#error "SPI_AR_RELEASE_MINOR_VERSION does not match."
#endif

#if(SPI_AR_RELEASE_REVISION_VERSION != 1U)
#error "SPI_AR_RELEASE_REVISION_VERSION does not match."
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /** #ifdef SPI_DEV_ERROR_DETECT        */
#if (SPI_SAFETY_ENABLE == STD_ON)
#include "FuSaMcalReportError.h"
#endif /** #if (DMA_SAFETY_ENABLE == STD_ON) */
/******************************************************************************************
 *                          Global Function Declarations
 *****************************************************************************************/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
/** **************************************************************************************
 * \brief To perform basic DET checks related to channels.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_ChannelDetCheck(
 *                          const Spi_ChannelType Channel, const uint8 SId,
 *                          const Spi_DataBufferType *TxBuffPtr,
 *                          const Spi_DataBufferType *RxBuffPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel   - Specify Channel ID.
 *                      SId       - Specify Service ID.
 *                      TxBuffPtr - Point to buffer of Tx data.
 *                      RxBuffPtr - Point to buffer of Rx data.
 *                      RxBuffPtr - Point to buffer of Rx data.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: No err related to channels be detected.
 *                      E_NOT_OK: The err related to channels be detected.
 *
 * Description        : Check ReadIB/WriteIB/SetupEB Api input params.
 * \endverbatim
 * Traceability       : SWSR_SPI_066 SWSR_SPI_069 SWSR_SPI_071 SWSR_SPI_081 SWSR_SPI_074
 *****************************************************************************************/
static Std_ReturnType Spi_ChannelDetCheck(
    const Spi_ChannelType Channel, const uint8 SId,
    const Spi_DataBufferType *TxBuffPtr,
    const Spi_DataBufferType *RxBuffPtr)
{
    uint8 errorId = 0;
    uint8 alignSize;
    uint8 coreId = Spi_GetCoreID();
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /*
            #10 Get the Channel configuration structure of the requested channel,
        The Channel may be exceeded the max channel id, but subsequent checks
        prioritize the correctness of the Channel id.
    */
    const Spi_ChannelCfgType *tmpChannelConfig = &Spi_ChannelConfig[Channel];
    Std_ReturnType returnValue = E_OK;

    /* #20 Get the align size from channel data width  */
    if (0x9U > tmpChannelConfig->dataWidth)
    {
        alignSize = 1;
    }
    else if (0x11U > tmpChannelConfig->dataWidth)
    {
        alignSize = 2;
    }
    else
    {
        alignSize = 4;
    }

    /* #30 Check the HandlerStatus is inited?  */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {
        errorId = SPI_E_UNINIT;
        returnValue = E_NOT_OK;
    }
    /* #40 Check the Channel id is in range ?  */
    else if (SPI_MAX_CHANNEL <= (uint16)Channel)
    {
        errorId = SPI_E_PARAM_CHANNEL;
        returnValue = E_NOT_OK;
    }
    /* #50 Check whether the resource access is valid in multicore environment ?  */
    else if (Spi_GetSpiChannelAssignCoreId(Channel) != coreId)
    {
        /* not assign to cur core */
        errorId = SPI_E_ILLEGAL_RES;
        returnValue = E_NOT_OK;
    }
    /*PRQA S 0306,4304  10*/
    /* #60 Check the align size is meeting? */
    else if (FALSE == SPI_IS_ALIGNED(RxBuffPtr, alignSize))
    {
        errorId = SPI_E_CHANNEL_ALIGN;
        returnValue = E_NOT_OK;
    }
    else if (FALSE == SPI_IS_ALIGNED(TxBuffPtr, alignSize))
    {
        errorId = SPI_E_CHANNEL_ALIGN;
        returnValue = E_NOT_OK;
    }

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2)
    /* #70 Check if the channel buffer allowed is IB/EB   */
    else if (((SPI_READIB_SID == SId) || (SPI_WRITEIB_SID == SId)) &&
             (tmpChannelConfig->channelBufferType == EB))
    {
        /* Check if the channel is configured with external buffer IB
        operation is forbidden */
        errorId = SPI_E_CHANNEL_OPS;
        returnValue = E_NOT_OK;
    }
    /* #80 Check if the requested channel is configured for internal buffer but the
    operation is SetupEB  */
    else if ((SPI_SETUPEB_SID == SId) && (tmpChannelConfig->channelBufferType == IB))
    {
        errorId = SPI_E_CHANNEL_OPS;
        returnValue = E_NOT_OK;
    }

#endif/* end of SPI_CHANNEL_BUFFERS_ALLOWED == 0x2 */
    else
    {
        /* No action required */
    }

    /* #90  Report to DET */
#if (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON)

    if (E_NOT_OK == returnValue)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, errorId);
#endif

#if  (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, errorId);
#endif
    }/* else not needed */

#endif

    SPI_DUMMY_STATEMENT(errorId);
    return returnValue;
}
/** **************************************************************************************
 * \brief To perform basic Det Checks for sequence related api request.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_SeqIdDetCheck(
 *                           const Spi_SequenceType Sequence,
 *                           const uint8 SId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Sequence - Specify the sequence ID.
 *                      SId      - Specify the service ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: No err related to Seq be detected.
 *                      E_NOT_OK: The err related to Seq be detected.
 *
 * Description        : Check the input param of SyncTransmit/AsyncTransmit/GetSequenceResult Apis.
 *
 * \endverbatim
 * Traceability       : SWSR_SPI_068 SWSR_SPI_071 SWSR_SPI_081
 *****************************************************************************************/
static Std_ReturnType Spi_SeqIdDetCheck(const Spi_SequenceType Sequence, const uint8 SId)
{
    uint8 errorId = 0;
    uint8 coreId = Spi_GetCoreID();
    Std_ReturnType returnValue = E_OK;
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 Check the HandlerStatus is inited?  */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {

        errorId = SPI_E_UNINIT;
        returnValue = E_NOT_OK;

    }
    /* #20 Check if the sequence ID passed, is valid ?*/
    else if (SPI_MAX_SEQUENCE <= Sequence)
    {
        errorId = SPI_E_PARAM_SEQ;
        returnValue = E_NOT_OK;
    }
    /* #30 Check whether the resource access is valid in a multicore environment ?  */
    else if (Spi_GetSpiSequenceAssignCoreId(Sequence) != coreId)
    {
        errorId = SPI_E_ILLEGAL_RES;
        returnValue = E_NOT_OK;
    }
    else
    {
        /* No action required */
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON)

    /* #40  Report to DET */
    if (E_NOT_OK == returnValue)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, errorId);
#endif
#if  (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, errorId);
#endif
    }/* else not needed */

#endif
    SPI_DUMMY_STATEMENT(errorId);
    return returnValue;
}
/** **************************************************************************************
 * \brief To perform basic Det Checks for Jobs related api request.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Spi_JobIdDetCheck(
 *                          const Spi_JobType JobId,
 *                          const uint8 SId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : JobId - Specify the Job ID.
 *                      SId   - Specify the service ID.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: No err related to Job be detected.
 *                      E_NOT_OK: The err related to Job be detected.
 *
 * Description        : Check the input params of GetJobResult Apis.
 * \endverbatim
 * Traceability       : SWSR_SPI_067 SWSR_SPI_071 SWSR_SPI_075 SWSR_SPI_081
 *****************************************************************************************/
static Std_ReturnType Spi_JobIdDetCheck(const Spi_JobType JobId, const uint8 SId)
{
    uint8 errorId = 0;
    uint8 coreId = Spi_GetCoreID();
    Std_ReturnType returnValue = E_OK;
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 Check if SPI Driver is initialized */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {
        errorId = SPI_E_UNINIT;
        returnValue = E_NOT_OK;
    }
    /* #20 Check if the sequence ID passed, is valid */
    else if (SPI_MAX_JOB <= JobId)
    {
        errorId = SPI_E_PARAM_JOB;
        returnValue = E_NOT_OK;
    }
    /* #30 Check whether the resource access is valid in a multicore environment ?  */
    else if (Spi_GetSpiJobAssignCoreId(JobId) != coreId)
    {
        errorId = SPI_E_ILLEGAL_RES;
        returnValue = E_NOT_OK;
    }
    else
    {
        /* No action required */
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON)

    /* #40  Report to DET */
    if (E_NOT_OK == returnValue)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, errorId);
#endif
#if  (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, errorId);
#endif
    }/* else not needed */

#endif

    SPI_DUMMY_STATEMENT(errorId);


    return returnValue;
}
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
 *                      SWSR_SPI_138 SWSR_SPI_139 SW_SM006
 *****************************************************************************************/
void Spi_Init(const Spi_ConfigType *ConfigPtr)
{
    uint8 errorId = 0;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    Std_ReturnType returnValue = E_OK;

    /* #10 check ConfigPtr == NULL_PTR ?  */
    if (NULL_PTR == ConfigPtr)
    {
        errorId = SPI_E_PARAM_POINTER;
        returnValue = E_NOT_OK;
    }
    /* #20 check the handler already inited ?  */
    else if (SPI_UNINIT != perCoreHandler->handlerStatus)
    {
        errorId = SPI_E_ALREADY_INITIALIZED;
        returnValue = E_NOT_OK;
    }
    else
    {
        /* No Action Required */
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON)

    /* #30  Report to DET */
    if (E_NOT_OK == returnValue)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_INIT_SID, errorId);
#endif
#if (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_INIT_SID, errorId);
#endif
    }/* else not needed */

#endif /** (SPI_DEV_ERROR_DETECT == STD_ON)  || (SPI_SAFETY_ENABLE == STD_ON) */
    SPI_DUMMY_STATEMENT(errorId);

    /* #40 Initialize the module only if Database is present and no DET error */
    if (E_OK == returnValue)
    {
        /* #50 Initialise the global variables */
        Spi_InitData(ConfigPtr);
        /* #60 Initialise the Hardware */
        returnValue = Spi_HWInit(ConfigPtr);

        /* #70 If the Hw Init Pass update the status  */
        if (E_OK == returnValue)
        {
            /* Global Status variable is SPI_IDLE */
            perCoreHandler->handlerStatus = SPI_IDLE;
            perCoreHandler->handlerAsyncStatus = SPI_IDLE;
        }
        else
        {
            /* Update the SPI driver status as uninitialized */
            perCoreHandler->handlerStatus = SPI_UNINIT;
            perCoreHandler->handlerAsyncStatus = SPI_UNINIT;
        }
    }
}
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
 *                      SWSR_SPI_147 SWSR_SPI_148 SWSR_SPI_149 SWSR_SPI_150 SW_SM001
 *****************************************************************************************/
Std_ReturnType Spi_DeInit(void)
{
    uint8 coreId = Spi_GetCoreID();
    Std_ReturnType returnValue = E_NOT_OK;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 Check if SPI Driver is initialized */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /*#20  Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_DEINIT_SID, SPI_E_UNINIT);
#endif
#if (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_DEINIT_SID, SPI_E_UNINIT);
#endif
    }
    else
    {
        /* #30 Enter exclusive area avoid context switch(between the #40 to #50)
        cause abnormal driver behavior */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01();

        /* #40 Check if Global status variable is SPI_BUSY */
        if (SPI_BUSY != Spi_GetStatus())
        {
            /* #50 Deinit the Spi HwUint to POR Status  */
            returnValue = Spi_HWDeInit(coreId);
            /* Update the SPI driver status as uninitialized */
            perCoreHandler->handlerStatus = SPI_UNINIT;
            perCoreHandler->handlerAsyncStatus = SPI_UNINIT;
        }/* else not needed */

        /* #60 Exit exclusive area */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();
    }

    return returnValue;
}
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
 *                      SWSR_SPI_158 SWSR_SPI_159 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr)
{
    uint16 bufferIdx;
    uint8 *tmpBufferIndex;
    Std_ReturnType returnValue;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    const Spi_ChannelCfgType *tmpPtrChannelConfig = &Spi_ChannelConfig[Channel];
    /* #10 Check DET errors of channel */
    returnValue = Spi_ChannelDetCheck(Channel, SPI_WRITEIB_SID, DataBufferPtr, NULL_PTR);
    /*
        #20 Enter exclusive area avoid context switch(between the #3 to #8)
        cause abnormal driver behavior
    */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02();

    /* #30 Check if any DET error has occurred */
    if (E_OK == returnValue)
    {
        /* #40 Check if the channel is locked */
        if (B_LOCKED == perCoreHandler->spiChannelLock[Channel])
        {
            returnValue = E_NOT_OK;
        }/* else not needed */
    }/* else not needed */

    /* #50 Check if any DET error has occurred or IB channel is writting on other context */
    if (E_OK == returnValue)
    {
        /* #60 Get IB Buffer address and lock the channel */
        tmpBufferIndex = tmpPtrChannelConfig->writeBufferIndex;
        perCoreHandler->spiChannelLock[Channel] = B_LOCKED;
        /* #70 Exit exclusive area ,early exit avoids affecting real-time performance */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();

        if (NULL_PTR != DataBufferPtr)
        {
            /* #80 Copy the data to internal buffer,handling of data width by typecast
                as per SWS_Spi_00437 requirement.
            */
            for (bufferIdx = 0; bufferIdx < tmpPtrChannelConfig->bufferSize; bufferIdx++)
            {
                if (0x9U > tmpPtrChannelConfig->dataWidth)
                {
                    /*PRQA S 0488,0306,0310,3305  1*/
                    *((((uint8 *)tmpBufferIndex) + bufferIdx)) = *(((const uint8 *)DataBufferPtr) + bufferIdx);
                }
                else if (0x11U > tmpPtrChannelConfig->dataWidth)
                {
                    /*PRQA S 0488,0306,0310,3305  1*/
                    *((((uint16 *)tmpBufferIndex) + bufferIdx)) = *(((const uint16 *)DataBufferPtr) + bufferIdx);
                }
                else
                {
                    /*PRQA S 0488,0306,0310,3305  1*/
                    *((((uint32 *)tmpBufferIndex) + bufferIdx)) = *(((const uint32 *)DataBufferPtr) + bufferIdx);
                }
            }
        }
        else
        {
            /* #90 If user input buffer is null write the default data to IB . */
            for (bufferIdx = 0; bufferIdx < tmpPtrChannelConfig->bufferSize; bufferIdx++)
            {
                if (0x9U > tmpPtrChannelConfig->dataWidth)
                {
                    /*PRQA S 0488,0306,0310,3305  1*/
                    *((((uint8 *)tmpBufferIndex) + bufferIdx)) = (uint8)(tmpPtrChannelConfig->defaultValue);
                }
                else if (0x11U > tmpPtrChannelConfig->dataWidth)
                {
                    /*PRQA S 0488,0306,0310,3305  1*/
                    *((((uint16 *)tmpBufferIndex) + bufferIdx)) = (uint16)(tmpPtrChannelConfig->defaultValue);
                }
                else
                {
                    /*PRQA S 0488,0306,0310,3305  1*/
                    *((((uint32 *)tmpBufferIndex) + bufferIdx)) = tmpPtrChannelConfig->defaultValue;
                }
            }
        }

        /* #100 Free the Channel */
        perCoreHandler->spiChannelLock[Channel] = B_UNLOCK;
        perCoreHandler->spiChannelState[Channel] = DATA_VALID;
    }
    else
    {
        /* #110 Exit exclusive area */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();
    }

    return returnValue;
}

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
 *                      SWSR_SPI_163 SWSR_SPI_164 SWSR_SPI_176 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
    /* #10 Check DET errors of Sequence */
    Std_ReturnType returnValue = Spi_SeqIdDetCheck(Sequence, SPI_ASYNCTRANSMIT_SID);

    /* #20 If not DET errors call HwAsyncTransmit to trigg once async transmission */
    if (E_OK == returnValue)
    {
        returnValue = Spi_HwAsyncTransmit(Sequence);
    }

    return returnValue;
}

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
 * Traceability       : SWSR_SPI_178 SWSR_SPI_179 SWSR_SPI_180
 *                      SWSR_SPI_181 SWSR_SPI_182 SWSR_SPI_183 SWSR_SPI_184
 *                      SWSR_SPI_185 SWSR_SPI_120 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPointer)
{
    uint16 bufferIdx;
    Std_ReturnType returnValue;
    const Spi_ChannelCfgType *tmpPtrChannelConfig = &Spi_ChannelConfig[Channel];
    /* #10 Check DET errors of channel */
    returnValue = Spi_ChannelDetCheck(Channel, SPI_READIB_SID, NULL_PTR, DataBufferPointer);

    if (NULL_PTR ==  DataBufferPointer)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                              SPI_READIB_SID, SPI_E_PARAM_POINTER);
#endif
#if (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                SPI_READIB_SID, SPI_E_PARAM_POINTER);
#endif
        returnValue = E_NOT_OK;
    }/* else is not needed */

    /* #20 Check if not any DET error has occurred and internal buffer valid */
    if (E_OK == returnValue)
    {
        /* #30 Copy the data from internal buffer to user buffer
            Handling of data width by typecast as per SWS_Spi_00437 requirement */
        for (bufferIdx = 0; bufferIdx < tmpPtrChannelConfig->bufferSize; bufferIdx++)
        {
            if (0x9U > tmpPtrChannelConfig->dataWidth)
            {
                /*PRQA S 0488,0306,0310,3305  2*/
                *(((uint8 *)DataBufferPointer) + bufferIdx) =
                    *(((uint8 *)tmpPtrChannelConfig->readBufferIndex + bufferIdx));
            }
            else if (0x11U > tmpPtrChannelConfig->dataWidth)
            {
                /*PRQA S 0488,0306,0310,3305  2*/
                *(((uint16 *)DataBufferPointer) + bufferIdx) =
                    *(((uint16 *)tmpPtrChannelConfig->readBufferIndex + bufferIdx));
            }
            else
            {
                /*PRQA S 0488,0306,0310,3305  2*/
                *(((uint32 *)DataBufferPointer) + bufferIdx) =
                    *(((uint32 *)tmpPtrChannelConfig->readBufferIndex + bufferIdx));
            }
        }
    } /* End of all operations if there is no DET error */
    else
    {
        /* Do Nothing */
    }

    return returnValue;
}

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
 *                      SWSR_SPI_120 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel,
                           const Spi_DataBufferType *SrcDataBufferPtr,
                           Spi_DataBufferType *DesDataBufferPtr,
                           Spi_NumberOfDataType Length)
{
    uint8 errorId = 0;
    Std_ReturnType returnValue;
    uint8 coreId = Spi_GetCoreID();
    const Spi_ChannelCfgType *tmpPtrChannelConfig;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /*
    #10 Check for DET Errors
    Note:
        For performance, when the data width is greater than 8 and less than 17bits, the external
      memory area is required to be aligned to the double-byte boundary. Similarly, the 17-32bits
      byte needs to be aligned to the 4-byte boundary.
    */
    returnValue = Spi_ChannelDetCheck(Channel, SPI_SETUPEB_SID,
                                      SrcDataBufferPtr, DesDataBufferPtr);
    /* #20 Get the channel config info  */
    tmpPtrChannelConfig = &Spi_ChannelConfig[Channel];

    /*
      #30 Check if the 'length' parameter is greater than configured length and if
     length is equal to zero
    */
    if ((0U == Length) || (Length > (tmpPtrChannelConfig->bufferSize)))
    {
        /* Report to DET */
        errorId = SPI_E_PARAM_LENGTH;
        returnValue = E_NOT_OK;
    }
    /*
      #40 Check if the SrcDataBufferPtr and DesDataBufferPtr both as NULL_PTR this incorrect usage.
    */
    else if ((NULL_PTR == SrcDataBufferPtr) && (NULL_PTR == DesDataBufferPtr))
    {
        errorId = SPI_E_PARAM_POINTER;
        returnValue = E_NOT_OK;
    }
    else
    {
        /* No action required */
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON)

    /* #50 Report to DET  */
    if (E_OK != errorId)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETUPEB_SID, errorId);
#endif
#if  (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETUPEB_SID, errorId);
#endif
    }/* else not needed */

#endif /** End of (SPI_DEV_ERROR_DETECT == STD_ON)  || (SPI_SAFETY_ENABLE == STD_ON) */
    SPI_DUMMY_STATEMENT(errorId);
    /* #60 Enter exclusive area avoid context switch(between the #13 to #18)
        cause abnormal driver behavior */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05();

    /* #70 Check if any DET error has occurred */
    if (E_OK == returnValue)
    {
        /* #14 Check if the channel is locked */
        if (B_LOCKED == perCoreHandler->spiChannelLock[Channel])
        {
            returnValue = E_NOT_OK;
        }/* else not needed */
    }/* else not needed */

    if (E_OK == returnValue)
    {
        perCoreHandler->spiChannelLock[Channel] = B_LOCKED;
        /* #80 Exit exclusive area ,early exit avoids affecting real-time performance */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();

        if (NULL_PTR == SrcDataBufferPtr)
        {
            /* #90 If user do not care about tx so set as default val */
            perCoreHandler->dummyTxBuffer = tmpPtrChannelConfig->defaultValue;
        }/* else not needed */

        /* #100 Copy the source pointer to global variable    */
        perCoreHandler->externalBuffCb[Channel].srcDataBufferPtr = SrcDataBufferPtr;
        /* #110 Copy the destination pointer to global variable */
        perCoreHandler->externalBuffCb[Channel].desDataBufferPtr = DesDataBufferPtr;
        /* #120 Copy length for that channel,SWS_Spi_00037 for each Channel with EB
        declared before call a Transmit method */
        perCoreHandler->externalBuffCb[Channel].length = Length;
        perCoreHandler->spiChannelLock[Channel] = B_UNLOCK;
        perCoreHandler->spiChannelState[Channel] = DATA_VALID;
        SPI_DBG("Ch %d TX Buff valid\n", Channel);
    }
    else
    {
        /* #130 Exit exclusive area */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();
    }

    return returnValue;
}
#endif /** ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2)) */
/*PRQA S 1505 100*/
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
 *                      SWSR_SPI_093 SW_SM006
 *****************************************************************************************/
Spi_StatusType Spi_GetStatus(void)
{
    Spi_StatusType returnValue;
    uint8 coreId = Spi_GetCoreID();
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 Check if SPI Driver is initialized */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {
        returnValue = SPI_UNINIT;
    }
    else if (SPI_BUSY == perCoreHandler->handlerStatus)
    {
        /* #20 If any SyncTransmission is on going return busy immediately */
        returnValue = SPI_BUSY;
    }
    else if (SPI_BUSY == perCoreHandler->handlerAsyncStatus)
    {
        /* #30 If any AsyncTransmission is on going return busy immediately */
        returnValue = SPI_BUSY;
    }
    else
    {
        /* #40 No Sequence is being transmitted return idle immediately */
        returnValue = SPI_IDLE;
    }

    return returnValue;
}
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
 *                      SWSR_SPI_202 SWSR_SPI_203 SWSR_SPI_204 SWSR_SPI_103 SWSR_SPI_123
 *                      SW_SM001 SW_SM006
 *****************************************************************************************/
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)
{
    Std_ReturnType returnValue;
    uint8 coreId = Spi_GetCoreID();
    Spi_JobResultType jobStatus = SPI_JOB_FAILED;
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /* #10 Check DET of Job */
    returnValue = Spi_JobIdDetCheck(Job, SPI_GETJOBRESULT_SID);

    if (E_OK == returnValue)
    {
        /* #20 get Job Result */
        jobStatus = perCoreHandler->jobResultArr[Job];
    }
    else
    {
        /* Default Job Status is SPI_JOB_FAILED */
    }

    return jobStatus;
}

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
 *                      SWSR_SPI_208 SWSR_SPI_106 SWSR_SPI_126 SW_SM001 SW_SM006
 *****************************************************************************************/
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
    Std_ReturnType returnValue;
    uint8 coreId = Spi_GetCoreID();
    Spi_SeqResultType seqStatus = SPI_SEQ_FAILED;
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /* #10 Check DET of Job */
    returnValue = Spi_SeqIdDetCheck(Sequence, SPI_GETSEQUENCERESULT_SID);

    if (E_OK == returnValue)
    {
        /* #20 get Sequence Result */
        seqStatus = perCoreHandler->seqResultArr[Sequence];
    }/* else not needed */

    return seqStatus;
}

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
 * Traceability       : SWSR_SPI_209 SWSR_SPI_210 SW_SM006
 *****************************************************************************************/
void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    /* #10 Check if parameter passed is  Null pointer */
    if (NULL_PTR == versioninfo)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* #20 Report to DET  */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_GETVERSIONINFO_SID, SPI_E_PARAM_POINTER);
#endif /** (SPI_DEV_ERROR_DETECT == STD_ON) */
#if  (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_GETVERSIONINFO_SID, SPI_E_PARAM_POINTER);
#endif
    }
    else
    {
        /*  Copy the vendor Id*/
        versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
        /*  Copy the module Id */
        versioninfo->moduleID = (uint16)SPI_MODULE_ID;
        /*  Copy Software Major Version */
        versioninfo->sw_major_version = SPI_SW_MAJOR_VERSION;
        /*  Copy Software Minor Version */
        versioninfo->sw_minor_version = SPI_SW_MINOR_VERSION;
        /*  Copy Software Patch Version */
        versioninfo->sw_patch_version = SPI_SW_PATCH_VERSION;
    }
}
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
 *                      SWSR_SPI_219 SWSR_SPI_220 SW_SM006 SW_SM007 SW_SM001
 *                      SW_SPI_SM009
 *****************************************************************************************/
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
{
    uint8 needReport = FALSE;
    Std_ReturnType returnValue;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    /* #10 Pointer to get Sequence configuration structure */
    const Spi_SequenceCfgType *tmpPtrSeqConfig = &Spi_SequenceConfig[Sequence];

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
    /* #20 If sync concurrent or deliver level=2 need get scheduler */
    struct Spi_Scheduler *Sche = &perCoreHandler->scheduler;
#endif
    /* #30 Check DET of the Sequence */
    returnValue = Spi_SeqIdDetCheck(Sequence, SPI_SYNCTRANSMIT_SID);

    /* #40 Check if any DET error has occurred */
    if (E_OK == returnValue)
    {
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
        /* #15 Enter exclusive area avoid context switch(between the #20 to #22)
        cause abnormal driver behavior */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();

        /*
            #50 SyncTransmit Service to transmit data on the SPI bus .
            The Spi_SyncTransmit is called while a sequence is on transmission;
            if the sequence is use same bus as new sequence;
            if SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT is disabled
            The SPI Handler/Driver shall not take into account this new transmission request
            and the function shall return the value E_NOT_OK (see [SWS_Spi_00114]).In this case,
            the SPI Handler/Driver shall report the SPI_E_SEQ_IN_PROCESS error according to
            [SWS_BSW_00042] and [SWS_BSW_00045].
        */
        if ((uint8)0 < perCoreHandler->spiSyncSeqActiveCnt)
        {
            /* #60 SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF and sequence being transmitted
                new transmissions are reject and return error. */
            returnValue = E_NOT_OK;
            needReport = TRUE;
        }
        else
        {
            /* #70 SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF and no sequence being transmitted
                new transmissions are accept and record the transmission . */
            perCoreHandler->spiSyncSeqActiveCnt++;
        }

        /* #80 Exit exclusive area */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();

#endif
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))

        /* #90 Check if any DET Error */
        /*PRQA S 2991,2995 2*/
        if (E_OK == returnValue)
        {
            /* #100 Enter exclusive area avoid context switch(between the #30 to #35)
               cause abnormal driver behavior */
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();

            /* #110 Check all need bus is idle ? */
            if ((tmpPtrSeqConfig->seqHwMask & Sche->hwStatusMask)
                    != tmpPtrSeqConfig->seqHwMask)
            {
                returnValue = E_NOT_OK;
                /* because in exclusice area so do not report det error */
                needReport = TRUE;
            }
            else
            {
                /* Lock bus for this Sync Transmit */
                Sche->hwStatusMask &= (uint8)(~tmpPtrSeqConfig->seqHwMask);
            }

            /* #120 Exit exclusive area */
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();
        }/* else not needed */

#endif

        /* Check if any errors nothing to do */
        if (E_OK == returnValue)
        {
            /* #130 Enter exclusive area avoid context switch(between the #43 to #46)
                cause abnormal driver behavior */
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();
            /* #140 Set Driver Status to busy */
            perCoreHandler->handlerStatus = SPI_BUSY;
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
            /* if SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT ON  increased the number of sequence on going */
            perCoreHandler->spiSyncSeqActiveCnt++;
#endif
            /* #150 Exit exclusive area */
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();
            /* #160 Initiate the Sequence Transmission */
            returnValue = Spi_SeqSyncTransmit(Sequence, tmpPtrSeqConfig);
            /* #170 Enter exclusive area avoid context switch(between the #50 to #60)
                cause abnormal driver behavior */
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
            /* #180 Frea the HwUint  */
            Sche->hwStatusMask |= tmpPtrSeqConfig->seqHwMask;
#endif
            /* #190 reduced the number of sequence on going  */
            perCoreHandler->spiSyncSeqActiveCnt--;

            /* if the  the number of sequence on going == 0 means none SyncTransmission  on going  */
            if ((uint8)0 == perCoreHandler->spiSyncSeqActiveCnt)
            {
                perCoreHandler->handlerStatus = SPI_IDLE;
            }

            /* #200 Exit exclusive area */
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)

            /*
                #210 When asynchronous only one Seq initiates a transfer (SeqA -->SPI1),
                synchronous is already in use (SeqB -->SPI1) then;The SeqA transfer is
                delayed until another asynchronous transfer call is made in any context,
                so need trigger schedule once running.
            */
            if ((uint8)0 != Sche->pendingSeqsCnt)
            {
                Spi_TriggerOnceSchedule();
            }/* else not needed */

#endif
        }/* else not needed */
    }/* else not needed */

#if (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON)

    if (TRUE == needReport)
    {
        (void)Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SYNCTRANSMIT_SID,
                                     SPI_E_SEQ_IN_PROCESS);
    }

#endif
    SPI_DUMMY_STATEMENT(needReport);

    return returnValue;
}

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
 *                      SWSR_SPI_224 SWSR_SPI_225 SWSR_SPI_226 SWSR_SPI_094
 *                      SWSR_SPI_129 SW_SM006 SW_SM001
 *****************************************************************************************/
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
    uint8 errorId = E_OK;
    Spi_StatusType hwStatus = SPI_UNINIT;
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[Spi_GetCoreID()];

    /* #10 Check if SPI Driver is initialized */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {
        errorId = SPI_E_UNINIT;
        hwStatus = SPI_UNINIT;
    }/* else not needed */

    /* #20 Check if HWUnit is out of range  */
    if (SPI_TOTAL_HW_COUNT <= HWUnit)
    {
        errorId = SPI_E_PARAM_UNIT;
    }/* else not needed */

#if (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON)

    /* #30 To return DET Error Status */
    if (E_OK != errorId)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_GETHWUNITSTATUS_SID, errorId);
#endif
#if  (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_GETHWUNITSTATUS_SID, errorId);
#endif
    }/* else not needed */

#endif
    SPI_DUMMY_STATEMENT(errorId);

    /* #40 If not any error  */
    if (E_OK == errorId)
    {
        /* #5 Get the  Hardware State */
        hwStatus = Spi_GetHWStatus(HWUnit);
    }/* else not needed */

    return hwStatus;
}
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
 *                      SW_SM006 SW_SM001
 *****************************************************************************************/
void Spi_Cancel(Spi_SequenceType Sequence)
{
    Std_ReturnType returnValue;
    uint8 coreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 To check DET Error Status */
    returnValue = Spi_SeqIdDetCheck(Sequence, SPI_CANCEL_SID);

    if (E_OK == returnValue)
    {
        /* #20 If Sequence is in Pending State there do not need exclusive area,Because when we get to
            #4 Sequence is not pending and when we get to #8 even if we get to pending because the
            context switch is pending it will just exit without a problem; When executing in pending
            state at #4 and executing in pending state at #8 because the context interruption
            changed to not pending the cancel request is still set, this set request will be cleared
            the next time it is initiated asynchronously and the behavior will still be as expected.
        */
        if (SPI_SEQ_PENDING != perCoreHandler->seqResultArr[Sequence])
        {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_CANCEL_SID, SPI_E_CANCEL_ERROR);
#endif
#if  (SPI_SAFETY_ENABLE == STD_ON)
            (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_CANCEL_SID, SPI_E_CANCEL_ERROR);
#endif
            returnValue = E_NOT_OK;
        }/* else not needed */
    }

    /* If the sequence status is ok */
    if (E_OK == returnValue)
    {
        /* #30 Enter exclusive area avoid context switch(between the #9 to #15)
                cause abnormal driver behavior */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_012();
        /* #40 Set the Sequence is canceled */
        perCoreHandler->seqIsCancel[Sequence] = TRUE;
        /* #50 Exit exclusive area */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_012();
    }/* else not needed */
}
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
 *                      SWSR_SPI_240 SWSR_SPI_260 SWSR_SPI_131 SWSR_SPI_132 SWSR_SPI_133
 *                      SW_SM006 SW_SM001
 *****************************************************************************************/
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    uint8 coreId = Spi_GetCoreID();
    Std_ReturnType returnValue = E_OK;
    struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];

    /* #10 Check if SPI Driver is initialized */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETAYNCMODE_SID, SPI_E_UNINIT);
#endif /** End of (SPI_DEV_ERROR_DETECT == STD_ON) */

#if  (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETAYNCMODE_SID, SPI_E_UNINIT);
#endif
        returnValue = E_NOT_OK;
    }
    else
    {
        /* #20 Enter exclusive area avoid context switch(between the #5 to #10)
                cause abnormal driver behavior */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_013();

        /* #30 Check if the Async handler is busy */
        if (SPI_BUSY == perCoreHandler->handlerAsyncStatus)
        {
            returnValue = E_NOT_OK;
        }
        else
        {
            /* #40 async status is not busy switch mode */
            Spi_AsyncModeSet(perCoreHandler, Mode);
        }

        /* #50 Exit exclusive area  */
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_013();
    }

    return returnValue;
}

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
 * Traceability       : SWSR_SPI_071 SWSR_SPI_081 SWSR_SPI_241 SW_SM001
 *****************************************************************************************/
void Spi_MainFunction_Handling(void)
{
    uint8 HwId;
    const uint8 coreId = Spi_GetCoreID();
    const struct Spi_Driver_Handler *perCoreHandler = Spi_Handler[coreId];
    const struct Spi_Scheduler *Sche = &perCoreHandler->scheduler;

    /* #10 Check if SPI Driver is initialized */
    if (SPI_UNINIT == perCoreHandler->handlerStatus)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_MAINFUNCTION_HANDLING_SID, SPI_E_UNINIT);
#endif /** SPI_DEV_ERROR_DETECT == STD_ON */

#if (SPI_SAFETY_ENABLE == STD_ON)
        (void)FuSaMcal_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_MAINFUNCTION_HANDLING_SID, SPI_E_UNINIT);
#endif
    }
    else
    {

        /* #20 Check if function is invoked in Polling mode */
        if (SPI_POLLING_MODE == Sche->schedulerMode)
        {
            for (HwId = 0; HwId < SPI_TOTAL_HW_COUNT; HwId++)
            {
                /* #30 Check if HwUinit is assigning to current core */
                if ((uint8)0 != (Spi_InstanceMask_Config[coreId] & ((uint8)0x01 << HwId)))
                {
                    Spi_HwMainFunctionHandling(HwId);
                }/* else not needed */
            }
        }/*else is not needed */
    }
}
#endif /** (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */

