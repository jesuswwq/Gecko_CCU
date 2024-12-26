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
 * @file  Spi.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "SchM_Spi.h"
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (SPI_E_HARDWARE_ERROR == STD_ON)
#include <Dem.h> /* DEM declarations */
#endif           /* #ifdef SPI_E_HARDWARE_ERROR        */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/** @brief Spi_ChannelDetCheck
 **
 ** To perform basic DET checks related to channels
 **
 ** @param [in] Channel   - Channel ID.
 ** @param [in] SId  - Service ID for Error Reporting
 ** @param [out] None
 ** @return  E_OK: No err related to channels be detected.
 **          E_NOT_OK: The err related to channels be detected.
 */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
FUNC(Std_ReturnType, SPI_CODE)
Spi_ChannelDetCheck(const Spi_ChannelType Channel, const uint8 SId)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2)
    /* Local Pointer for Channel configuration structure */
    P2CONST(Spi_ChannelCfgType, AUTOMATIC, SPI_CONFIG_CONST)
    tmpChannelConfig;
#endif
    Std_ReturnType ReturnValue;
    ReturnValue = E_OK;

    /* Check if SPI Driver is initialized */
    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_UNINIT);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    /* Check if the channel ID passed, is valid */
    if (SPI_MAX_CHANNEL <= (uint16)Channel) {

        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_PARAM_CHANNEL);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    /* Check assign to cur core ?  */
    if (GetSpiChannelAssignCoreId(Channel) != CoreId) {

        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_ILLEGAL_RES);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    /*check if the channel buffer allowed is IB/EB */
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2)

    if (E_OK == ReturnValue) {
        /* Get the Channel configuration structure of the requested channel */
        tmpChannelConfig = &Spi_ChannelConfig[Channel];

        if ((SPI_READIB_SID == SId) || (SPI_WRITEIB_SID == SId)) {
            /* Check if the channel is configured with external buffer */
            if (tmpChannelConfig->ChannelBufferType == EB) {
                /* Report to DET */
                (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_PARAM_CHANNEL);
                ReturnValue = E_NOT_OK;
            } else {
                /* No action required */
            }
        } else {
            /* Check if the requested channel is configured for internal buffer */
            if (tmpChannelConfig->ChannelBufferType == IB) {
                /* Report to DET */
                (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_PARAM_CHANNEL);
                ReturnValue = E_NOT_OK;
            } else {
                /* No action required */
            }
        }
    } else {
        /* Do Nothing */
    }

#endif

    return ReturnValue;
}
#endif

/** @brief Spi_SeqIdDetCheck
 **
 ** To perform basic Det Checks for sequence Transmission request
 **
 ** @param [out] Sequence  - Sequence ID.
 ** @param [in]  SID  - Service ID for Error Reporting
 ** @param [out] None
 ** @return  E_OK: No err related to Seq be detected.
 **          E_NOT_OK: The err related to Seq be detected.
 */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
FUNC(Std_ReturnType, SPI_CODE)
Spi_SeqIdDetCheck(const Spi_SequenceType Sequence, const uint8 SId)
{
    /* To return DET Error Status */
    Std_ReturnType ReturnValue;
    /* Initialise thereturn value with E_OK */
    ReturnValue = E_OK;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];

    /* Check if SPI Driver is initialized */
    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_UNINIT);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    /* Check if the sequence ID passed, is valid */

    if (SPI_MAX_SEQUENCE <= Sequence) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_PARAM_SEQ);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    /* Check if  assign to cur core?  */
    if (GetSpiSequenceAssignCoreId(Sequence) != CoreId) {

        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_ILLEGAL_RES);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    return ReturnValue;
}
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
static FUNC(Std_ReturnType, SPI_CODE)
Spi_ChannelDetBuffCheck(const Spi_ChannelType Channel, const uint8 SId,
                        const Spi_DataBufferType *BuffPtr)
{
    uint8 align_size;
    /* Local Pointer for Channel configuration structure */
    P2CONST(Spi_ChannelCfgType, AUTOMATIC, SPI_CONFIG_CONST)
    tmpChannelConfig;

    Std_ReturnType ReturnValue;
    ReturnValue = E_OK;

    /* Get the Channel configuration structure of the requested channel */
    tmpChannelConfig = &Spi_ChannelConfig[Channel];

    if ((SPI_READIB_SID == SId) || (SPI_WRITEIB_SID == SId)) {
        /* Check if the channel is configured with external buffer */
        if (tmpChannelConfig->DataWidth < 0x9U) {
            align_size = 1;
        } else if (tmpChannelConfig->DataWidth < 0x11U) {
            align_size = 2;
        } else {
            align_size = 4;
        }

        if (IS_ALIGNED(BuffPtr, align_size)) {
            /* Do Nothing */
        } else {
            /* Report to DET */
            (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_PARAM_CHANNEL);
            ReturnValue = E_NOT_OK;
        }
    } else {
        /* Do Nothing */
    }

    return ReturnValue;
}
#endif
#if (SPI_DEV_ERROR_DETECT == STD_ON)
static FUNC(Std_ReturnType, SPI_CODE)
Spi_JobIdDetCheck(const Spi_JobType JobId, const uint8 SId)
{
    /* To return DET Error Status */
    Std_ReturnType ReturnValue;
    /* Initialise thereturn value with E_OK */
    ReturnValue = E_OK;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];

    /* Check if SPI Driver is initialized */
    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_UNINIT);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    /* Check if the sequence ID passed, is valid */

    if (SPI_MAX_JOB <= JobId) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_PARAM_JOB);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    /* Check if  assign to cur core?  */
    if (GetSpiJobAssignCoreId(JobId) != CoreId) {

        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SId, SPI_E_ILLEGAL_RES);
        ReturnValue = E_NOT_OK;
    } else {
        /* No action required */
    }

    return ReturnValue;
}
#endif
/** @brief Spi_Init
**
** Initializes the SPI hardware units and driver.
**
** @param [in] None
** @param [out] None
** @return None
*/

FUNC(void, SPI_CODE)
Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    Std_ReturnType ReturnValue = E_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)

    /* check for DET Errors */
    if (NULL_PTR == ConfigPtr) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_INIT_SID, SPI_E_PARAM_POINTER);
        ReturnValue = E_NOT_OK;
    } else if (SPI_UNINIT != PerCoreHandler->Spi_HandlerStatus) {

        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_INIT_SID, SPI_E_ALREADY_INITIALIZED);
        ReturnValue = E_NOT_OK;
    } else {
        /* Do Nothing */
    }

    /* If no DET errors, continue */
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

    /* Initialize the module only if Database is present or no DET is reported */
    if (E_OK == ReturnValue) {
        /* Initialise the global variables */
        Spi_InitData();
        /* Initialise the Hardware */
        ReturnValue = Spi_HWInit();

        if (ReturnValue == E_OK) {
            /* Global Status variable is SPI_IDLE */
            PerCoreHandler->Spi_HandlerStatus = SPI_IDLE;
            PerCoreHandler->Spi_HandlerAsyncStatus = SPI_IDLE;
        } else {
            /* Update the SPI driver status as uninitialized */
            PerCoreHandler->Spi_HandlerStatus = SPI_UNINIT;
            PerCoreHandler->Spi_HandlerAsyncStatus = SPI_UNINIT;
        }
    }
}

/** @brief Spi_DeInit
**
** Deinitialize the SPI hardware units and driver.
**
** @param [in] None
** @param [out] None
** @return None
*/
FUNC(Std_ReturnType, SPI_CODE)
Spi_DeInit(void)
{
    Std_ReturnType ReturnValue;
    ReturnValue = E_NOT_OK;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
#if (SPI_DEV_ERROR_DETECT == STD_ON)

    /* Check if SPI Driver is initialized */
    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_DEINIT_SID, SPI_E_UNINIT);
    } else
#endif
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01();

        /* Check if Global status variable is SPI_BUSY */
        if (SPI_BUSY != Spi_GetStatus()) {

            ReturnValue = Spi_HWDeInit();
            /* Update the SPI driver status as uninitialized */
            PerCoreHandler->Spi_HandlerStatus = SPI_UNINIT;
            PerCoreHandler->Spi_HandlerAsyncStatus = SPI_UNINIT;
        } else {
            /* No action required */
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();
    }

    return (ReturnValue);
}

/** @brief Spi_WriteIB
**
** Writing one or more data to an IB SPI Handler/Driver channel.
**
** @param [in] Channel  Channel Id.
** @param [in] DataBufferPtr  Buffer to write the data.
** @return E_OK: write command has been accepted.
**         E_NOT_OK: write command has not been accepted.
*/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))

FUNC(Std_ReturnType, SPI_CODE)
Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr)
{

    uint8 CoreId = Spi_GetCoreID();
    Std_ReturnType ReturnValue = E_OK;
    void *tmpBufferIndex;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    P2CONST(Spi_ChannelCfgType, AUTOMATIC,
            SPI_APPL_CONST)
    tmpPtrChannelConfig = &Spi_ChannelConfig[Channel];

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Check for DET Errors */
    ReturnValue = Spi_ChannelDetCheck(Channel, SPI_WRITEIB_SID);
    /* Check aligin  DET Errors */
    ReturnValue |= Spi_ChannelDetBuffCheck(Channel, SPI_WRITEIB_SID,
                                           (const Spi_DataBufferType *)DataBufferPtr);
#endif /* End of (SPI_DEV_ERROR_DETECT == STD_ON) */
    /* Check if any DET error has occurred */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02();

    if (E_OK == ReturnValue) {
        if (PerCoreHandler->Spi_SpiChannelState[Channel].BuffLock == B_LOCKED) {
            ReturnValue = E_NOT_OK;
        }
    }

    if (E_OK == ReturnValue) {
        tmpBufferIndex = (void *)tmpPtrChannelConfig->WriteBufferIndex;
        PerCoreHandler->Spi_SpiChannelState[Channel].BuffLock = B_LOCKED;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();

        if (DataBufferPtr != NULL_PTR) {
            for (uint16 i = 0; i < tmpPtrChannelConfig->BufferSize; i++) {
                /* Copy the data to internal buffer*/
                /* Handling of data width by typecast as per SWS_Spi_00437 requirement*/
                if (tmpPtrChannelConfig->DataWidth < 0x9U) {
                    *(((uint8 *)tmpBufferIndex + i)) = *(((const uint8 *)DataBufferPtr) + i);
                } else if (tmpPtrChannelConfig->DataWidth < 0x11U) {
                    /*PRQA S 3305 4*/
                    *(((uint16 *)tmpBufferIndex + i)) = *(((const uint16 *)DataBufferPtr) + i);
                } else {
                    *(((uint32 *)tmpBufferIndex + i)) = *(((const uint32 *)DataBufferPtr) + i);
                }
            }
        } else {
            /* Write the Default Data */
            for (uint16 i = 0; i < tmpPtrChannelConfig->BufferSize; i++) {
                if (tmpPtrChannelConfig->DataWidth < 0x9U) {
                    *(((uint8 *)tmpBufferIndex + i)) = (uint8)(tmpPtrChannelConfig->DefaultValue);
                } else if (tmpPtrChannelConfig->DataWidth < 0x11U) {
                    *(((uint16 *)tmpBufferIndex + i)) = (uint16)(tmpPtrChannelConfig->DefaultValue);
                } else {
                    *(((uint32 *)tmpBufferIndex + i)) = tmpPtrChannelConfig->DefaultValue;
                }
            }
        }

        PerCoreHandler->Spi_SpiChannelState[Channel].BuffLock = B_UNLOCK;
    } else {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();
    }

    return (ReturnValue);
}

#endif

/** @brief Spi_AsyncTransmit
**
** Transmitting data asynchronously.
**
** @param [in] Sequence  Sequence to be transmitted
** @param [out] None
** @return E_OK: Transmission command has been accepted
**         E_NOT_OK: Transmission command has not been accepted
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

FUNC(Std_ReturnType, SPI_CODE)
Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
    Std_ReturnType ReturnValue = E_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)

    ReturnValue = Spi_SeqIdDetCheck(Sequence, SPI_ASYNCTRANSMIT_SID);

    if (E_OK == ReturnValue)
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    {
        ReturnValue = Spi_HwAsyncTransmit(Sequence);
    }

    return ReturnValue;
}

#endif

/** @brief Spi_ReadIB
**
** reading one or more data from an IB SPI Handler/Driver channel
**
** @param [in] Channel  Channel id
** @param [out] DataBufferPointer  To read the buffer data
** @return E_OK: Read command has been accepted
**         E_NOT_OK: Read command has not been accepted
*/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))

FUNC(Std_ReturnType, SPI_CODE)
Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPointer)
{
    uint8 CoreId = Spi_GetCoreID();
    Std_ReturnType ReturnValue = E_OK;
    P2CONST(Spi_ChannelCfgType, AUTOMATIC, SPI_APPL_CONST)
    tmpPtrChannelConfig = &Spi_ChannelConfig[Channel];
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Check for DET Errors */
    ReturnValue = Spi_ChannelDetCheck(Channel, SPI_WRITEIB_SID);
    /* Check aligin  DET Errors */
    ReturnValue |= Spi_ChannelDetBuffCheck(Channel, SPI_WRITEIB_SID,
                                           (const Spi_DataBufferType *)DataBufferPointer);
#endif /* End of (SPI_DEV_ERROR_DETECT == STD_ON) */

    /* Check if any DET error has occurred */
    if (E_OK == ReturnValue) {
        if (PerCoreHandler->Spi_SpiChannelState[Channel].Rx_Tag == DATA_INVALID)
            ReturnValue = E_NOT_OK;
    }

    if (ReturnValue == E_OK) {
        if (DataBufferPointer != NULL_PTR) {
            for (uint16 i = 0; i < tmpPtrChannelConfig->BufferSize; i++) {
                /* Copy the data to internal buffer*/
                /* Handling of data width by typecast as per SWS_Spi_00437 requirement*/
                if (tmpPtrChannelConfig->DataWidth < 0x9U) {
                    *(((uint8 *)DataBufferPointer) + i) = *(((uint8 *)tmpPtrChannelConfig->ReadBufferIndex + i));
                } else if (tmpPtrChannelConfig->DataWidth < 0x11U) {
                    /*PRQA S 3305 4*/
                    *(((uint16 *)DataBufferPointer) + i) = *(((uint16 *)tmpPtrChannelConfig->ReadBufferIndex + i));
                } else {
                    *(((uint32 *)DataBufferPointer) + i) = *(((uint32 *)tmpPtrChannelConfig->ReadBufferIndex + i));
                }
            }
        } else {
            ReturnValue = E_NOT_OK;
        }
    } /* End of all operations if there is no DET error */

    return (ReturnValue);
}

#endif

/** @brief Spi_SetupEB
**
** setting the buffers and the length of data for the external buffer
**
** @param [in] Channel  Channel id
** @param [in] Length   Data length
** @param [out] SrcDataBufferPtr  To read the buffer data
** @param [out] DesDataBufferPtr  To read the buffer data
** @return E_OK: Setup command has been accepted
**         E_NOT_OK: Setup command has not been accepted
*/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))

FUNC(Std_ReturnType, SPI_CODE)
Spi_SetupEB(Spi_ChannelType Channel,
            const Spi_DataBufferType *SrcDataBufferPtr,
            Spi_DataBufferType *DesDataBufferPtr,
            Spi_NumberOfDataType Length)
{
    void *tmpBufferIndex;
    uint8 CoreId = Spi_GetCoreID();
    Std_ReturnType ReturnValue = E_OK;
    P2CONST(Spi_ChannelCfgType, AUTOMATIC, SPI_APPL_CONST) tmpPtrChannelConfig;
    P2VAR(Spi_EBDataType, AUTOMATIC, SPI_APPL_DATA) tmpPtrEBData;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Check for DET Errors */
    ReturnValue = Spi_ChannelDetCheck(Channel, SPI_SETUPEB_SID);

    /* Check if any DET error has occurred */
    if (E_OK == ReturnValue) {
        tmpPtrChannelConfig = &Spi_ChannelConfig[Channel];

        /*
         * Check if the 'length' parameter is greater than configured length and if
         * length is equal to zero
         */
        if ((Length == 0x0U) || (Length > (tmpPtrChannelConfig->BufferSize))) {
            /* Report to DET */
            (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETUPEB_SID, SPI_E_PARAM_LENGTH);
            ReturnValue = E_NOT_OK;
        } else {
            /* No action required */
        }
    } else {
        /* No action required */
    }

    /*
        Note:
        For performance, when the data width is greater than 8 and less than 17bits, the external
      memory area is required to be aligned to the double-byte boundary. Similarly, the 17-32bits
      byte needs to be aligned to the 4-byte boundary.
    */
    /* Check aligin  DET Errors */
    ReturnValue |= Spi_ChannelDetBuffCheck(Channel, SPI_WRITEIB_SID,
                                           (const Spi_DataBufferType *)SrcDataBufferPtr);
    /* Check aligin  DET Errors */
    ReturnValue |= Spi_ChannelDetBuffCheck(Channel, SPI_WRITEIB_SID,
                                           (const Spi_DataBufferType *)DesDataBufferPtr);

    /* Check aligin  DET Errors */
    if (SrcDataBufferPtr == NULL_PTR && DesDataBufferPtr == NULL_PTR) {
        ReturnValue = E_NOT_OK;
    }

#endif /* End of (SPI_DEV_ERROR_DETECT == STD_ON) */
    /* Check if any DET error has occurred */
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05();

    if (E_OK == ReturnValue) {
        if (PerCoreHandler->Spi_SpiChannelState[Channel].BuffLock == B_LOCKED)
            ReturnValue = E_NOT_OK;
    }

    if (E_OK == ReturnValue) {
        /*
            Put this code in this position, in order to avoid calling SetupEB before initialization,
            which will cause data access exception.
        */
        tmpPtrChannelConfig = &Spi_ChannelConfig[Channel];
        tmpBufferIndex = (void *)tmpPtrChannelConfig->WriteBufferIndex;
        PerCoreHandler->Spi_SpiChannelState[Channel].BuffLock = B_UNLOCK;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();

        if (SrcDataBufferPtr == NULL_PTR) {
            for (uint16 i = 0; i < tmpPtrChannelConfig->BufferSize; i++) {
                if (tmpPtrChannelConfig->DataWidth < 0x9U) {
                    *(((uint8 *)tmpBufferIndex + i)) = (uint8)(tmpPtrChannelConfig->DefaultValue);
                } else if (tmpPtrChannelConfig->DataWidth < 0x11U) {
                    *(((uint16 *)tmpBufferIndex + i)) = (uint16)(tmpPtrChannelConfig->DefaultValue);
                } else {
                    *(((uint32 *)tmpBufferIndex + i)) = tmpPtrChannelConfig->DefaultValue;
                }
            }
        }

        /* Get the EB pointer of the requested channel */
        tmpPtrEBData = &PerCoreHandler->ExtBuff[Channel];
        /*Copy the source pointer to global variable    */
        tmpPtrEBData->SrcDataBufferPtr = (SrcDataBufferPtr == NULL_PTR ?
                                          tmpPtrChannelConfig->WriteBufferIndex : SrcDataBufferPtr);
        /* Copy the destination pointer to global variable */
        tmpPtrEBData->DesDataBufferPtr = DesDataBufferPtr;
        /* Copy length for that channel */
        tmpPtrEBData->Length = Length;
        /* SWS_Spi_00037 for each Channel with EB declared before call a Transmit method */
        PerCoreHandler->Spi_SpiChannelState[Channel].Tx_Tag = BUFF_VALID;
        PerCoreHandler->Spi_SpiChannelState[Channel].BuffLock = B_UNLOCK;
        SPI_DBG("Ch %d TX Buff valid\n", Channel);
    } else {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();
    }

    return (ReturnValue);
}
#endif

/** @brief Spi_GetStatus
**
** getting the status of SPI Driver Component
**
** @param [in] None
** @param [out] None
** @return Spi_HandlerStatus:Spi status type
*/
FUNC(Spi_StatusType, SPI_CODE)
Spi_GetStatus(void)
{
    Spi_StatusType ret = SPI_UNINIT;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
#if (SPI_DEV_ERROR_DETECT == STD_ON)

    /* Check if SPI Driver is initialized */
    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                              SPI_GETSTATUS_SID, SPI_E_UNINIT);
    } else {
        /* No action required */
    }

#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */

    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
        ret = SPI_UNINIT;
    } else if (PerCoreHandler->Spi_HandlerStatus == SPI_BUSY ||
               PerCoreHandler->Spi_HandlerAsyncStatus == SPI_BUSY) {
        ret = SPI_BUSY;
    } else {
        ret = SPI_IDLE;
    }

    return ret;
}

/** @brief Spi_GetJobResult
 **
 ** getting result of the specified job
 **
 ** @param [in] Job     Job id
 ** @param [out] None
 ** @return JobStatus:Spi_JobResultType
 */
FUNC(Spi_JobResultType, SPI_CODE)
Spi_GetJobResult(Spi_JobType Job)
{


    uint8 CoreId = Spi_GetCoreID();
    Spi_JobResultType JobStatus = SPI_JOB_FAILED;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = E_OK;
    ReturnValue = Spi_JobIdDetCheck(Job, SPI_GETJOBRESULT_SID);

    if (E_OK == ReturnValue)
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    {
        /* Return Job Result */
        JobStatus = PerCoreHandler->JobResult[Job];
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    else {
        /* No action required */
    }

#endif
    return (JobStatus);
}

/** @brief Spi_GetSequenceResult
**
** getting result of the specified sequence
**
** @param [in] Sequence     Sequence id
** @param [out] None
** @return SeqStatus:Spi_SeqResultType
*/
FUNC(Spi_SeqResultType, SPI_CODE)
Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
    uint8 CoreId = Spi_GetCoreID();
    Spi_SeqResultType SeqStatus = SPI_SEQ_FAILED;
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = E_OK;
    ReturnValue = Spi_SeqIdDetCheck(Sequence, SPI_GETSEQUENCERESULT_SID);

    if (E_OK == ReturnValue)
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    {
        SeqStatus = PerCoreHandler->SeqResult[Sequence];
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    else {
        /* No action required */
    }

#endif
    return (SeqStatus);
}

/** @brief Spi_GetVersionInfo
**
** getting result of the specified sequence
**
** @param [out] None
** @param [out] versioninfo     Project version information
** @return None
*/
#if (SPI_VERSION_INFO_API == STD_ON)
FUNC(void, SPI_CODE)
Spi_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (SPI_DEV_ERROR_DETECT == STD_ON)

    /* Check if parameter passed is equal to Null pointer */
    if (versioninfo == NULL_PTR) {
        /* Report to DET  */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_GETVERSIONINFO_SID, SPI_E_PARAM_POINTER);
    } else
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)SPI_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = SPI_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = SPI_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = SPI_SW_PATCH_VERSION;
    }
}
#endif

/** @brief Spi_SyncTransmit
**
** Transmitting data synchronously
**
** @param [in] Sequence - Sequence ID
** @param [Out] None
** @return E_OK: Transmission command has been accepted
**         E_NOT_OK: Transmission command has not been accepted
*/
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))

FUNC(Std_ReturnType, SPI_CODE)
Spi_SyncTransmit(Spi_SequenceType Sequence)
{
    uint8 need_report = FALSE;
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    /* Pointer to get Sequence configuration structure */
    P2CONST(Spi_SequenceCfgType, AUTOMATIC, SPI_CONFIG_CONST)
    tmpPtrSeqConfig = &Spi_SequenceConfig[Sequence];
    Std_ReturnType ReturnValue = E_OK;
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;
#endif
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    ReturnValue = Spi_SeqIdDetCheck(Sequence, SPI_SYNCTRANSMIT_SID);
#endif /* End of #if (SPI_DEV_ERROR_DETECT == STD_ON) */

    /* Check if any DET error has occurred */
    if (E_OK == ReturnValue) {
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
        /*
            SyncTransmit Service to transmit data on the SPI bus .
            When the function Spi_SyncTransmit is called while a sequence is on transmission
            and SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT is disabled or another sequence is on
            transmission on same bus, the SPI Handler/Driver shall not take into account this
            new transmission request and the function shall return the value E_NOT_OK (see [SWS_Spi_00114]).
            In this case, the SPI Handler/Driver shall report the SPI_E_SEQ_IN_PROCESS error according to
            [SWS_BSW_00042] and [SWS_BSW_00045].
        */
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();

        if (PerCoreHandler->SpiSyncSeqActiveCnt) {
            ReturnValue = E_NOT_OK;
            need_report = TRUE;
        } else {
            PerCoreHandler->SpiSyncSeqActiveCnt++;
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();

#endif
        /*
            This function only build in LEVEL0/LEVEL2. In the case of LEVEL2 or Enable CONCURRENT of Sync ,
            it is necessary to deal with the competition.
        */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))

        /*PRQA S 2991,2995 2*/
        if (E_OK == ReturnValue) {
            /* Check all Bus is idle ?*/
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();

            if ((tmpPtrSeqConfig->SeqHwMask & Sche->HwStatusMask) != tmpPtrSeqConfig->SeqHwMask) {
                ReturnValue = E_NOT_OK;
                need_report = TRUE;
            } else {
                /* Lock Bus for Sync Transmit */
                Sche->HwStatusMask &= (~tmpPtrSeqConfig->SeqHwMask);
            }

            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();
        }

#endif

        if (E_OK == ReturnValue) {
            /* Make Driver Status to busy */
            PerCoreHandler->Spi_HandlerStatus = SPI_BUSY;
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();
            PerCoreHandler->SpiSyncSeqActiveCnt++;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();
#endif
            /* Initiate the Sequence Transmission */
            ReturnValue = Spi_SeqSyncTransmit(Sequence, tmpPtrSeqConfig);
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_2) || \
     (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON))
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();
            Sche->HwStatusMask |= tmpPtrSeqConfig->SeqHwMask;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();
#endif
            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_010();
            PerCoreHandler->SpiSyncSeqActiveCnt--;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_010();

            if (PerCoreHandler->SpiSyncSeqActiveCnt == 0)
                PerCoreHandler->Spi_HandlerStatus = SPI_IDLE;
        } else {
            /* Do nothing */
        }
    } else {
        /* Do nothing */
    }

    if (need_report)
        Det_ReportRuntimeError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SYNCTRANSMIT_SID,
                               SPI_E_SEQ_IN_PROCESS);

    return (ReturnValue);
}

#endif

/** @brief Spi_GetHWUnitStatus
**
** status of the SPI Hardware micro-controller peripheral
**
** @param [in] HWUnit - ID of SPI HW
** @param [out] None
** @return Spi_StatusType
*/
#if (SPI_HW_STATUS_API == STD_ON)

FUNC(Spi_StatusType, SPI_CODE)
Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
    Spi_StatusType HWStatus;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[Spi_GetCoreID()];

    /* Check if SPI Driver is initialized */
    if (PerCoreHandler->Spi_HandlerStatus == SPI_UNINIT) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_GETHWUNITSTATUS_SID, SPI_E_UNINIT);
        HWStatus = SPI_UNINIT;
    } else {
        HWStatus = SPI_IDLE;
    }

    if (HWUnit >= SPI_TOTAL_HW_COUNT) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_GETHWUNITSTATUS_SID, SPI_E_PARAM_UNIT);

        if (SPI_IDLE == HWStatus) {
            HWStatus = SPI_UNINIT;
        } else {
            /* No Action Required */
        }
    } else {
        /* No Action Required */
    }

    if (SPI_IDLE == HWStatus)
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    {
        /* Check if the Hardware is in Busy State */
        HWStatus = Spi_GetHWStatus(HWUnit);
    }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    else
#endif
    {
        /* No action required */
    }

    return (HWStatus);
}

#endif /* End of (SPI_HW_STATUS_API == STD_ON) */

/** @brief Spi_Cancel
**
** Cancel the transmission of a on-going sequence
**
** @param [in] Sequence - Sequence ID
** @param [out] None
** @return None
*/
#if (SPI_CANCEL_API == STD_ON)

FUNC(void, SPI_CODE)
Spi_Cancel(Spi_SequenceType Sequence)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* To return DET Error Status */
    Std_ReturnType ReturnValue;

    /* Check if Sequence ID is valid */
    ReturnValue = Spi_SeqIdDetCheck(Sequence, SPI_CANCEL_SID);

    if (E_OK == ReturnValue) {
        /* If Sequence is in Pending State */
        if (PerCoreHandler->SeqResult[Sequence] != SPI_SEQ_PENDING) {
            (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_CANCEL_SID, SPI_E_CANCEL_ERROR);
            ReturnValue = E_NOT_OK;
        } else {
            /* No action required */
        }
    }

    if (E_OK == ReturnValue)
#endif
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_012();
        PerCoreHandler->SeqCancel[Sequence] = TRUE;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_012();
    }
}

#endif /* End of (SPI_CANCEL_API == STD_ON) */

/** @brief Spi_SetAsyncMode
**
** setting the asynchronous mode
**
** @param [in] Mode - New Mode Required
** @param [out] None
** @return  E_OK: Setting command has been done
**          E_NOT_OK: setting command has not been accepted
*/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)

FUNC(Std_ReturnType, SPI_CODE)
Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    Std_ReturnType ReturnValue = E_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)

    /* Check if SPI Driver is initialized */
    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETAYNCMODE_SID, SPI_E_UNINIT);
        ReturnValue = E_NOT_OK;
    } else
#endif /* End of (SPI_DEV_ERROR_DETECT == STD_ON) */
    {
        /*Check if the Async handler is busy*/
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_013();

        if (PerCoreHandler->Spi_HandlerAsyncStatus == SPI_BUSY) {
            ReturnValue = E_NOT_OK;
        } else {
            /* No action required */
        }

        if (ReturnValue == E_OK) {
            if (((Mode == SPI_POLLING_MODE) || (Mode == SPI_INTERRUPT_MODE))) {
                /* Update the mode of operation */
                Spi_AsyncModeSet(Mode);
            } else {
                ReturnValue = E_NOT_OK;
            }
        }

        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_013();
    }

    return (ReturnValue);
}

#endif /* End of (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

/** @brief Spi_MainFunction_Handling
**
** asynchronous transmission in polling mode
**
** @param [in] None
** @param [out] None
** @return None
*/
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
FUNC(void, SPI_CODE)
Spi_MainFunction_Handling(void)
{
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_Scheduler *Sche = &PerCoreHandler->Scheduler;

    /* Check if SPI Driver is initialized */
    if (SPI_UNINIT == PerCoreHandler->Spi_HandlerStatus) {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_MAINFUNCTION_HANDLING_SID, SPI_E_UNINIT);
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    }

    /* Check if function is invoked in Polling mode */
    if (Sche->SchedulerMode == SPI_POLLING_MODE) {
        for (uint8 HwId = 0; HwId < SPI_TOTAL_HW_COUNT; HwId++) {
            if (Spi_InstanceMask_Config[CoreId] & (0x01 << HwId)) {
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_015();
                Spi_HwMainFunctionHandling(HwId);
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_015();
            }
        }
    }
}
#endif

/** @brief Spi_Cancel
**
** Cancel the transmission of a on-going sequence
**
** @param [in] Sequence - Sequence ID
** @param [out] None
** @return None
*/
#if (SPI_CANCEL_API == STD_ON && SPI_ENABLE_SLAVE == STD_ON)

FUNC(void, SPI_CODE)
Spi_SlaveCancel(Spi_SequenceType Sequence)
{
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    uint8 CoreId = Spi_GetCoreID();
    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    /* To return DET Error Status */
    Std_ReturnType ReturnValue;
    /* Check if Sequence ID is valid */
    ReturnValue = Spi_SeqIdDetCheck(Sequence, SPI_CANCEL_SID);

    if (E_OK == ReturnValue) {
        /* If Sequence is in Pending State */
        if (PerCoreHandler->SeqResult[Sequence] != SPI_SEQ_PENDING) {
            (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_CANCEL_SID, SPI_E_CANCEL_ERROR);
            ReturnValue = E_NOT_OK;
        } else {
            /* No action required */
        }
    }

    if (E_OK == ReturnValue)
#endif
    {
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_012();
        Spi_SlaveSeqCancel(Sequence);
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_012();
    }
}
#endif /* End of (SPI_CANCEL_API == STD_ON && SPI_ENABLE_SLAVE == STD_ON) */
#if (SPI_ENABLE_SLAVE == STD_ON)
sint32 Spi_GetSlaveTransmittedBytes(Spi_SequenceType SequenceId)
{
    uint32 len;
    uint8 CoreId = Spi_GetCoreID();

    struct Spi_Driver_Handler *PerCoreHandler = &SpiHandler[CoreId];
    struct Spi_SeqNode *SeqNode = PerCoreHandler->SeqNode;

    if (SeqNode[SequenceId].JobQueue.Next) {
        /*PRQA S 2810 2*/
        struct Spi_JobNode *JobItem = GetJobNode(SeqNode[SequenceId].JobQueue.Next);
        struct mld_spi_module *bus = &PerCoreHandler->SpiBus[Spi_JobConfig[JobItem->JobId].HWUnit].Bus;
        enum fifo_width bytes_shift = bus->async.width_type;

        if (bus->async.prxdata.val) {
            len = bus->async.rx_cur;
        } else {
            len = bus->async.tx_cur;
        }

        return (len << bytes_shift);
    } else {
        return -1;
    }
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
