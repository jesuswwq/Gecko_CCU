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
 * @file  Lin.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin.h"

#if (STD_ON == LIN_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* STD_ON == LIN_DEV_ERROR_DETECT */

#if   ( LIN_CONFIGURATION_VARIANT != LIN_CONFIGURATION_VARIANT_PRECOMPILE ) && \
  ( LIN_CONFIGURATION_VARIANT != LIN_CONFIGURATION_VARIANT_POSTBUILD )
# error "LIN_CONFIGURATION not in valid range, check settings in generation tool"
#endif

#if ( LIN_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
# include "EcuM_Error.h"
#endif

/*****************************/
#define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Lin_MemMap.h"

const Lin_ConfigType *pLin_Config;
static Lin_DrvStatusType Lin_DrvStatus;
uint8 Lin_ChStatus[LIN_NUM_CHANNELS];
Lin_Channel gLin_Channels[LIN_NUM_CHANNELS];
boolean Lin_Wakeup_Flag[LIN_NUM_CHANNELS];
boolean Lin_Wakeup_Self_Flag[LIN_NUM_CHANNELS];
boolean Lin_Sleep_Flag[LIN_NUM_CHANNELS];

#define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"

/* for lin_go_to_sleep : sleep frame */
uint8 SleepFrame[] = {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
Lin_PduType linSleepPduInfo = {
    .Pid = LIN_SLEEP_PID,
    .Cs = LIN_CLASSIC_CS,
    .Drc = LIN_MASTER_RESPONSE,
    .Dl = 8,
    .SduPtr = SleepFrame,
};
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"



/******************************************************************************************************
 * Lin_Init           : LIN driver initialization.
   Return type        : None
   Parameter          : Lin_ConfigType
******************************************************************************************************/
void Lin_Init(const Lin_ConfigType *Config )
{
    uint8 nodeCtr;
    Std_ReturnType retStatus;

    if (Config != NULL_PTR) {
        /* Check Lin driver is not initialized*/
        if (Lin_DrvStatus == LIN_UNINIT) {
            pLin_Config = Config;
            Lin_DrvStatus = LIN_INIT;
            for (nodeCtr = 0; nodeCtr < pLin_Config->numberOfNodes; nodeCtr++) {
                Lin_ChStatus[nodeCtr] = LIN_CH_SLEEP_PENDING;
                gLin_Channels[nodeCtr].ChannelState = LIN_NOT_OK;
                retStatus = Lin_NodeInit(nodeCtr);
                if (E_OK == retStatus) {
                    gLin_Channels[nodeCtr].ChannelState = LIN_CH_SLEEP;
                    Lin_Wakeup_Flag[nodeCtr] = FALSE;
                    Lin_Wakeup_Self_Flag[nodeCtr] = FALSE;
                } else {
                    Lin_DrvStatus = LIN_UNINIT;
                    break;
                }
            }
#if (LIN_ICU_ABR_DETECT == STD_ON)
            /* lin icu abr detect init */
            for (nodeCtr = 0; nodeCtr < pLin_Config->numberOfNodes; nodeCtr++) {
                Lin_NodeIcuAbrInit(nodeCtr);
            }
#endif /* LIN_ICU_ABR_DETECT */
        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_INIT_ID, LIN_E_STATE_TRANSITION);
#endif
        }
    } else {
        /*Not support pre-compiled config*/
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_INIT_ID, LIN_E_INVALID_POINTER);
#endif
    }
}

/******************************************************************************************************
 * Lin_GoToSleep      : LIN function requesting driver to transmit a sleep command on the LIN
                        channel.
   Return type        : Std_ReturnType E_OK when sleep command accepted
                                       E_NOT_OK when sleep command not accepted
   Parameter          : Channel which needs to go sleep
******************************************************************************************************/
Std_ReturnType Lin_GoToSleep( uint8 Channel )
{
    const Lin_Uart *locNodeCfg;
    Lin_Channel *Lin_ChannelPtr;
    Std_ReturnType retVal = E_NOT_OK;
    Lin_ChannelPtr = NULL_PTR;
    /* Check Lin driver initialized*/
    if (Lin_DrvStatus == LIN_INIT) {
        locNodeCfg = &pLin_Config->channels[Channel];
        if (Channel < LIN_NUM_CHANNELS) {
            Lin_ChannelPtr = &gLin_Channels[Channel];
            /* only master mode support goto sleep cmd */
            if (((Lin_ChannelPtr->ChannelState) != LIN_CH_SLEEP) && (locNodeCfg->dataPtr.mode == LIN_UART_MASTER)) {
                Std_ReturnType sleepRet = E_NOT_OK;
                Lin_Sleep_Flag[Channel] = TRUE;
                sleepRet = Lin_SendFrame(Channel, &linSleepPduInfo);
                if (sleepRet == E_OK) {
                    Lin_ChannelPtr->channelInfo.currentState = LIN_WAIT_FOR_WAKEUP;
                    Lin_ChStatus[Channel] = LIN_CH_SLEEP_PENDING;
                    Lin_ChannelPtr->ChannelState = LIN_CH_SLEEP;
                    Lin_Wakeup_Flag[Channel] = FALSE;
                    retVal = E_OK;
                }
            } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
                (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GOTOSLEEP_ID, LIN_E_STATE_TRANSITION);
#endif
            }
        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GOTOSLEEP_ID, LIN_E_INVALID_CHANNEL);
#endif
        }
    } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GOTOSLEEP_ID, LIN_E_UNINT);
#endif
    }

    return retVal;
}

/******************************************************************************************************
 * Lin_GoToSleepInternal      : LIN function sets the channel to LIN_CH_SLEEP, enables wakeup detection.
   Return type                : Std_ReturnType E_OK when sleep command accepted
                                               E_NOT_OK when sleep command not accepted
   Parameter                  : Channel which needs to go sleep
******************************************************************************************************/
Std_ReturnType Lin_GoToSleepInternal(uint8 Channel)
{
    const Lin_Uart *locNodeCfg;
    Lin_Channel *Lin_ChannelPtr;
    Std_ReturnType retVal = E_NOT_OK;
    Lin_ChannelPtr = NULL_PTR;

    /* Check Lin driver initialized*/
    if (Lin_DrvStatus == LIN_INIT) {
        locNodeCfg = &pLin_Config->channels[Channel];
        if (Channel < LIN_NUM_CHANNELS) {
            Lin_ChannelPtr = &gLin_Channels[Channel];
            Lin_ChStatus[Channel] = LIN_CH_SLEEP;
            Lin_ChannelPtr->ChannelState = LIN_CH_SLEEP;
            Lin_ChannelPtr->channelInfo.currentState = LIN_WAIT_FOR_WAKEUP;
            Lin_Wakeup_Flag[Channel] = FALSE;
            if ((locNodeCfg->dataPtr.mode == LIN_UART_MASTER)) {
                /* master mode need a break interrupt to wakeup */
                Lin_UartRxBreakCtrl(locNodeCfg, 11);
                Lin_Sleep_Flag[Channel] = TRUE;
            }
            retVal = E_OK;

        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GOTOSLEEPINTERNAL_ID, LIN_E_INVALID_CHANNEL);
#endif
        }
    } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GOTOSLEEPINTERNAL_ID, LIN_E_UNINT);
#endif
    }

    return retVal;
}

/******************************************************************************************************
 * Lin_WakeUp                 : LIN function generates a wakeup pulse to the LIN channel requested.
   Return type                : Std_ReturnType E_OK when wakeup command is accepted
                                               E_NOT_OK when wakeup command is not accepted or error
   Parameter                  : Channel which needs wakeup
******************************************************************************************************/
Std_ReturnType Lin_Wakeup( uint8 Channel )
{
    Lin_Channel *Lin_ChannelPtr;
    Std_ReturnType retVal = E_NOT_OK;
    Lin_ChannelPtr = NULL_PTR;

    /* Check Lin driver initialized*/
    if (Lin_DrvStatus == LIN_INIT) {
        if (Channel < LIN_NUM_CHANNELS) {
            Lin_ChannelPtr = &gLin_Channels[Channel];

            if (Lin_ChannelPtr->ChannelState == LIN_CH_SLEEP) {
                Lin_Wakeup_Self_Flag[Channel] = TRUE;
                //Lin_ChannelPtr->ChannelState = LIN_OPERATIONAL;
                //Lin_ChStatus[Channel] = LIN_CH_OPERATIONAL;
                retVal = Lin_HwWakeup(Channel);
				if (E_OK == retVal)
                {
                    Lin_ChannelPtr->ChannelState = LIN_OPERATIONAL;
                }
            } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
                (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_WAKEUP_ID, LIN_E_STATE_TRANSITION);
#endif
            }
        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_WAKEUP_ID, LIN_E_INVALID_CHANNEL);
#endif

        }
    } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_WAKEUP_ID, LIN_E_UNINT);
#endif
    }

    return retVal;
}

/******************************************************************************************************
 * Lin_WakeUpInterval         : LIN function does not generate a wakeup pulse to the LIN channel requested.
   Return type                : Std_ReturnType E_OK when wakeup command is accepted
                                               E_NOT_OK when wakeup command is not accepted or error
   Parameter                  : Channel which needs wakeup
******************************************************************************************************/
Std_ReturnType Lin_WakeupInternal( uint8 Channel )
{
    const Lin_Uart *locNodeCfg;
    Lin_Channel *Lin_ChannelPtr;
    Std_ReturnType retVal = E_NOT_OK;

    Lin_ChannelPtr = NULL_PTR;

    /* Check Lin driver initialized*/
    if (Lin_DrvStatus == LIN_INIT) {
        locNodeCfg = &pLin_Config->channels[Channel];
        if (Channel < LIN_NUM_CHANNELS) {
            Lin_ChannelPtr = &gLin_Channels[Channel];

            if (Lin_ChannelPtr->ChannelState == LIN_CH_SLEEP) {
                Lin_ChannelPtr->ChannelState = LIN_OPERATIONAL;
                Lin_ChStatus[Channel] = LIN_CH_OPERATIONAL;
                Lin_ChannelPtr->channelInfo.currentState = LIN_ACTIVE;
                if ((locNodeCfg->dataPtr.mode == LIN_UART_MASTER)) {
                    /* master mode set break to 0 */
                    Lin_UartRxBreakCtrl(locNodeCfg, 0);
                }
                retVal = E_OK;
            } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
                (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_WAKEUPINTERNAL_ID, LIN_E_STATE_TRANSITION);
#endif
            }
        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_WAKEUPINTERNAL_ID, LIN_E_INVALID_CHANNEL);
#endif
        }
    } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_WAKEUPINTERNAL_ID, LIN_E_UNINT);
#endif
    }

    return retVal;
}

/******************************************************************************************************
 * Lin_GetStatus               : LIN function indicates the current transmission, reception or operation
                                status of the LIN driver.
   Return type                 : Lin_StatusType
                                 LIN_NOT_OK            -- DET or DEM error occurred
                                 LIN_TX_OK             -- Transmission successful
                                 LIN_TX_BUSY           -- Transmission ongoing (Header or response)
                                 LIN_TX_HEADER_ERROR   -- Error in transmission of header
                                 LIN_RX_OK             -- Reception successful
                                 LIN_RX_BUSY           -- Reception ongoing
                                 LIN_RX_ERROR          -- Error in reponse. Frame error, Checksum error
                                 LIN_RX_NO_RESPONSE    -- No response byte has been received
                                 LIN_OPERATIONAL       -- Normal operation. Frames are being transmitted normally
                                 LIN_CH_SLEEP          -- Sleep mode operation

   Parameter1                  : Channel ID
   Parameter2                  : Pointer to pointer to shadow buffer or LIN Hardware receive buffer
******************************************************************************************************/
Lin_StatusType Lin_GetStatus( uint8 Channel, uint8 **Lin_SduPtr )
{
    const Lin_Uart *locNodeCfg;
    Lin_Channel *Lin_ChannelPtr;
    Lin_StatusType retVal = LIN_NOT_OK;
    Lin_ChannelPtr = NULL_PTR;

    /* Check Lin driver initialized*/
    if (Lin_DrvStatus == LIN_INIT) {
        if (Channel < LIN_NUM_CHANNELS) {
            Lin_ChannelPtr = &gLin_Channels[Channel];
            locNodeCfg = &pLin_Config->channels[Channel];

            if (Lin_SduPtr != NULL_PTR) {
                if (LIN_CH_OPERATIONAL == Lin_ChStatus[Channel]) {
                    retVal = Lin_ChannelPtr->ChannelState;
                    if (LIN_RX_OK == retVal) {
                        if (LIN_SLAVE_TO_SLAVE == Lin_ChannelPtr->channelInfo.drc) {
                            retVal = LIN_TX_OK;
                            Lin_ChannelPtr->ChannelState = LIN_OPERATIONAL;
                        }
                    }
                    if (locNodeCfg->dataPtr.mode == LIN_UART_MASTER) {
                        if (LIN_SLAVE_RESPONSE == Lin_ChannelPtr->channelInfo.drc) {
                            *Lin_SduPtr = Lin_ChannelPtr->channelInfo.rxframe;
                        } else {
                            *Lin_SduPtr = Lin_ChannelPtr->channelInfo.txframe;
                        }
                    } else {
                        if (LIN_SLAVE_RESPONSE == Lin_ChannelPtr->channelInfo.drc) {
                            *Lin_SduPtr = Lin_ChannelPtr->channelInfo.txframe;
                        } else if (LIN_MASTER_RESPONSE == Lin_ChannelPtr->channelInfo.drc) {
                            *Lin_SduPtr = Lin_ChannelPtr->channelInfo.rxframe;
                        }
                    }
                } else if (LIN_CH_SLEEP_PENDING == Lin_ChStatus[Channel]) {
                    retVal = LIN_CH_SLEEP;
                    Lin_ChStatus[Channel] = LIN_CH_SLEEP;
                } else {
                    retVal = LIN_CH_SLEEP;
                }
            } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
                (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GETSTATUS_ID, LIN_E_PARAM_POINTER);
#endif
            }
        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GETSTATUS_ID, LIN_E_INVALID_CHANNEL);
#endif
        }
    } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_GETSTATUS_ID, LIN_E_UNINT);
#endif
    }

    return retVal;
}

/******************************************************************************************************
 * Lin_CheckWakeup           : LIN function to identify the corresponding LIN channel after Lin wakeup
                                caused by LIN transceiver
   Return type                : Std_ReturnType E_OK
                                               E_NOT_OK
   Parameter                  : ChannelId on which wakeup check should be performed
******************************************************************************************************/
Std_ReturnType  Lin_CheckWakeup (uint8 Channel)
{
    Std_ReturnType retVal = E_NOT_OK;
    /* Check Lin driver initialized*/
    if (Lin_DrvStatus == LIN_INIT) {
        if (Channel < LIN_NUM_CHANNELS) {
                if (Lin_Wakeup_Flag[Channel] == TRUE) {
                    Lin_Wakeup_Flag[Channel] = FALSE;
                    retVal = E_OK;
                }
        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_CHECKWAKEUP_ID, LIN_E_INVALID_CHANNEL);
#endif
        }
    } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_CHECKWAKEUP_ID, LIN_E_UNINT);
#endif
    }

    return retVal;
}

/******************************************************************************************************
 * Lin_SendFrame               : LIN function to transmit header and response of the frame
                                 The function generates the header part (Break field, Sync byte and PID field)
                                 of the LIN frame. Functionality: Sends frame, Receives response, Calculates
                                 checksum and validates checksum of the receive frame
   Return type                 : Std_ReturnType
                                 E_OK                 -- Tranmission successful
                                 E_NOT_OK             -- Transmission not successful

   Parameter1                  : Channel ID
   Parameter2                  : Pointer to PDU containing PID, Checksum model and Response type, Data length
******************************************************************************************************/
Std_ReturnType Lin_SendFrame (uint8 Channel, const Lin_PduType *PduInfoPtr)
{
    Lin_Channel *Lin_ChannelPtr;
    Lin_NodeData *locNodeData;
    Std_ReturnType    retVal = E_NOT_OK;
    Lin_StatusType ChannelState = LIN_NOT_OK;;
    /* Check Lin driver initialized*/
    if (LIN_INIT == Lin_DrvStatus) {
        if (Channel < LIN_NUM_CHANNELS) {
            if (PduInfoPtr != NULL_PTR) {
                Lin_ChannelPtr = &gLin_Channels[Channel];
                Lin_ChannelPtr->pduInfo = PduInfoPtr;

                if (Lin_ChannelPtr->pduInfo->Dl > 8) {
                    return E_NOT_OK;
                }

                locNodeData = &(Lin_ChannelPtr->channelInfo);

                ChannelState = Lin_ChannelPtr->ChannelState;
                /* rst module when last frame not recieve done */
                if ((ChannelState != LIN_NOT_OK) && (ChannelState != LIN_CH_SLEEP)) {
                    if ((ChannelState == LIN_RX_BUSY) || (ChannelState == LIN_TX_BUSY) || (ChannelState == LIN_RX_NO_RESPONSE)) {
                        Lin_HwRstMod(Channel);
                    }

                    for (uint8 i = 0; i < Lin_ChannelPtr->pduInfo->Dl; i++) {
                        locNodeData->txframe[i] = 0;
                    }

                    locNodeData->currentState = LIN_ACTIVE;
                    locNodeData->framestate = LIN_FRAMEIDLE;
                    locNodeData->error = LIN_OK;
                    Lin_ChannelPtr->ChannelState = LIN_OPERATIONAL;
                    Lin_HwSetNodePdu(locNodeData, PduInfoPtr);
                    retVal = Lin_HwSendFrame(Channel);
                } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
                    (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_SENDFRAME_ID, LIN_E_STATE_TRANSITION);
#endif
                }
            } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
                (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_SENDFRAME_ID, LIN_E_PARAM_POINTER);
#endif 
            }
        } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
            (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_SENDFRAME_ID, LIN_E_INVALID_CHANNEL);
#endif
        }
    } else {
#if(STD_ON == LIN_DEV_ERROR_DETECT)
        (void)Det_ReportError(LIN_MODULE_ID, 0, LIN_SENDFRAME_ID, LIN_E_UNINT);
#endif
    }

    return retVal;
}

#if ( LIN_VERSION_INFO_API == STD_ON )
/******************************************************************************************************
 * Lin_GetVersionInfo         : Get driver Version
   Return type                : void
   Parameter                  : Pointer to VersionInfo struct
******************************************************************************************************/
FUNC(void, LIN_CODE) Lin_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LIN_APPL_VAR) VersionInfo
)
{
#if(LIN_DEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC) Lin_ErrId;
    Lin_ErrId = LIN_E_NO_ERROR;
#if ( LIN_DEV_ERROR == STD_ON )

    /* #10 Check validity of parameter versioninfo. Note: no uninit check is performed */
    if ( VersionInfo == (P2VAR(Std_VersionInfoType, AUTOMATIC, LIN_APPL_VAR))NULL_PTR ) {
        Lin_ErrId = LIN_E_PARAM_POINTER;
    } else
#endif
#endif
    {
        VersionInfo->vendorID = LIN_VENDOR_ID;
        VersionInfo->moduleID = LIN_MODULE_ID;
        VersionInfo->sw_major_version = LIN_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = LIN_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = LIN_SW_PATCH_VERSION;
    }

#if ((LIN_DEV_ERROR_REPORT == STD_ON) && (LIN_DEV_ERROR_DETECT == STD_ON))

    if ( Lin_ErrId != LIN_E_NO_ERROR ) {
        (void) Det_ReportError(LIN_MODULE_ID, LIN_DET_ERROR, LIN_GETVERSIONINFO_SERVICE_ID, Lin_ErrId);
    } else {
        /* do nothing */
    }

#endif
}
#endif

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
