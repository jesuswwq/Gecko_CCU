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
 * @file  Lin_Hw.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "ComM.h"
#include "BswM_Check_Action.h"
#include "Lin_Hw.h"
#if (LIN_SLAVE_MODE_USED == STD_ON)
#include "LinIf.h"
#endif /* LIN_SLAVE_MODE_USED */
#include "mini_libc.h"
#include "SchM_Lin.h"
#include "LinIf_Master.h"
#include "CanIf.h"
#if defined(SEMIDRIVE_E3_LITE_SERIES)
#include "Mcu.h"
#endif
#if (LIN_ICU_ABR_DETECT == STD_ON)
#include "Icu.h"
uint32 Lin_Icu_Abr_Chan[LIN_NUM_CHANNELS];
extern uint32 Lin_Pre_Baud[LIN_NUM_CHANNELS];
extern uint32 Lin_Icu_Timestamp_Buffer[LIN_NUM_CHANNELS][12];
#endif /* LIN_ICU_ABR_DETECT */
extern const Lin_ConfigType *pLin_Config;
extern Lin_Channel gLin_Channels[LIN_NUM_CHANNELS];
extern uint8 Lin_ChStatus[LIN_NUM_CHANNELS];
extern boolean Lin_Wakeup_Flag[LIN_NUM_CHANNELS];
extern boolean Lin_Wakeup_Self_Flag[LIN_NUM_CHANNELS];
extern boolean Lin_Sleep_Flag[LIN_NUM_CHANNELS];

/* lin err interrupt */
#define LIN_ERR_INT_STA     (LIN_INTR0_TXFUDF | LIN_INTR0_RXFUDF | \
                            LIN_INTR0_TXFOVF | LIN_INTR0_RXFOVF | \
                            LIN_INTR0_PARITYERR | LIN_INTR0_FRAMEERR | \
                            LIN_INTEN0_STARTERRE | LIN_INTR0_NOISEERR)
/* lin frame err interrupt */
#define LIN_FRAME_ERR_INT_STA     (LIN_INTR0_PARITYERR | LIN_INTR0_FRAMEERR | \
                                  LIN_INTEN0_STARTERRE | LIN_INTR0_NOISEERR)
/* lin fifo err interrupt */
#define LIN_TX_FIFO_ERR_INT_STA     (LIN_INTR0_TXFUDF | LIN_INTR0_TXFOVF)
#define LIN_RX_FIFO_ERR_INT_STA     (LIN_INTR0_RXFUDF | LIN_INTR0_RXFOVF)

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

static uint32 Lin_GetErrSta(void)
{
    uint32 errSta = 0;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    /* e3 lite 1.1 chip ignore baudrate err */
    if (Mcu_GetChipVersion() == 0x0U) {
#endif
        errSta = LIN_ERR_INT_STA | LIN_INTR0_BAUDRATEERRE;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    } else {
        errSta = LIN_ERR_INT_STA;
    }
#endif
    return errSta;
}

static uint32 Lin_GetFrameErrSta(void)
{
    uint32 frameErrSta = 0;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    /* e3 lite 1.1 chip ignore baudrate err */
    if (Mcu_GetChipVersion() == 0x0U) {
#endif
        frameErrSta = LIN_FRAME_ERR_INT_STA | LIN_INTR0_BAUDRATEERRE;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
    } else {
        frameErrSta = LIN_FRAME_ERR_INT_STA;
    }
#endif
    return frameErrSta;
}

void Lin_HwSetNodePdu(Lin_NodeData *locNodePdu, const Lin_PduType *locPdu)
{
    locNodePdu->pid = locPdu->Pid | LIN_CALCPARITY1 (locPdu->Pid) | LIN_CALCPARITY2(locPdu->Pid);

    if (locPdu->Cs == LIN_ENHANCED_CS) {
        locNodePdu->cs = 1;
    } else {
        locNodePdu->cs = 0;
    }

    locNodePdu->drc = locPdu->Drc;
    locNodePdu->dl = locPdu->Dl;

    /* lin frame data length : 0 - 8 */
    if (locPdu->Dl > 0 && locPdu->SduPtr != NULL_PTR && locPdu->Dl <= 8) {
        mini_memcpy_s(locNodePdu->txframe, locPdu->SduPtr, locPdu->Dl);
        mini_memset_s(locNodePdu->rxframe, 0, locPdu->Dl);
    }
}

void Lin_HwRstMod(uint8 ChannelID)
{
    const Lin_Uart *locNodeCfg = &(pLin_Config->channels[ChannelID]);
    Lin_UartRstMod(locNodeCfg);
}


/* Send 'break field' and filled data frame. */
uint8 Lin_HwSendFrame(uint8 ChannelID)
{
    Std_ReturnType Ret = E_NOT_OK;
    Lin_NodeData *locNodeData = &(gLin_Channels[ChannelID].channelInfo);
    const Lin_Uart *locNodeCfg = &(pLin_Config->channels[ChannelID]);

    /* Process the frame for tramssion if ready*/
    if ((locNodeData->currentState == LIN_ACTIVE) && (locNodeData->framestate == LIN_FRAMEIDLE)) {
        if (locNodeCfg->dataPtr.mode == LIN_UART_MASTER) {
            locNodeData->framestate = LIN_FRAMETRANSMIT;
            Lin_UartPidSet(locNodeCfg, locNodeData->pid);

            if (LIN_MASTER_RESPONSE == locNodeData->drc) {
#if (LIN_TX_ERROR_DETECT == STD_ON)
                Lin_IocEnable(ChannelID, TRUE);
#endif /* LIN_TX_ERROR_DETECT */
                gLin_Channels[ChannelID].ChannelState = LIN_TX_BUSY;
                Lin_UartTransmit(locNodeCfg, locNodeData->cs, locNodeData->txframe, locNodeData->dl);
            } else if (LIN_SLAVE_RESPONSE == locNodeData->drc) {
                locNodeData->framestate = LIN_FRAMERECEIVE;
                gLin_Channels[ChannelID].ChannelState = LIN_RX_NO_RESPONSE;
                Lin_UartReceive(locNodeCfg, locNodeData->cs, locNodeData->dl);
            }
        }

        Ret = E_OK;
    }

    return Ret;
}

/******************************************************************************************************
 * Lin_NodeInit       : initializes the node mentioned by the parameter.
   Return type        : Std_ReturnType E_OK or E_NOT_OK
   Parameter          : nodeID which needs to be initialized
******************************************************************************************************/
Std_ReturnType Lin_NodeInit(uint8 numNodeId)
{
    const Lin_Uart *locNodeCfg;
    Lin_Channel *locNodeData;

    locNodeCfg = &pLin_Config->channels[numNodeId];
    locNodeData = &gLin_Channels[numNodeId];

    if (locNodeCfg->dataPtr.mode == LIN_UART_MASTER) {
        locNodeData->channelInfo.framestate = LIN_FRAMEIDLE;
    } else {
        locNodeData->channelInfo.framestate = LIN_FRAMEPENDING;
    }

    locNodeData->channelInfo.currentState = LIN_WAIT_FOR_WAKEUP;
    locNodeData->channelInfo.error = LIN_OK;
    Lin_UartInit(locNodeCfg);
#if (LIN_TX_ERROR_DETECT == STD_ON)
    /* IOC init : for lin tx err detect */
    Lin_IocInit(numNodeId, locNodeCfg);
#endif /* LIN_TX_ERROR_DETECT */
    return E_OK;
}

#if (LIN_ICU_ABR_DETECT == STD_ON)
/******************************************************************************************************
 * Lin_NodeIcuAbrInit : when use icu for abr , this function is used to init abr config.
   Return type        : void
   Parameter          : nodeID which needs to be initialized
******************************************************************************************************/
void Lin_NodeIcuAbrInit(uint8 numNodeID)
{
    const Lin_Uart *locNodeCfg;
    locNodeCfg = &pLin_Config->channels[numNodeID];
    /* only slave mode can use lin icu abr function */
    if ((locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) && (locNodeCfg->dataPtr.icu_abr == TRUE)) {
        /* get initial baud rate */
        Lin_Pre_Baud[numNodeID] = locNodeCfg->dataPtr.baud_rate;
        /* get icu abr chan */
        Lin_Icu_Abr_Chan[numNodeID] = locNodeCfg->dataPtr.icu_abr_chn;
    }
}
#endif /* LIN_ICU_ABR_DETECT */

/******************************************************************************************************
 * Lin_TransmitCallBk : Tramission callback function of Uart. Once Uart tramission of 1 or more bytes
                        is successful this function gets called.
   Return type        : void
   Parameter          : node which generates the callback
******************************************************************************************************/
void Lin_TransmitCallBk(uint8 numNodeID)
{
    const Lin_Uart      *locNodeCfg;
    Lin_NodeData        *locNodeData;

    /* Initialize local variables*/
    locNodeCfg  = &(pLin_Config->channels[numNodeID]);
    locNodeData = &(gLin_Channels[numNodeID].channelInfo);

    uint32 int_sta = Lin_UartGetInt(locNodeCfg);
    Lin_UartClearInt(locNodeCfg, int_sta);
    /* check err interrupt first */
    if (locNodeData->currentState != LIN_WAIT_FOR_WAKEUP) {
        if (int_sta & Lin_GetErrSta()) {
            /* frame err : reset module */
            if (int_sta & Lin_GetFrameErrSta()) {
                Lin_HwRstMod(numNodeID);
            }
            /* tx fifo err : reset tx fifo */
            if (int_sta & LIN_TX_FIFO_ERR_INT_STA) {
                Lin_UartClrTxFifo(locNodeCfg);
            }
            /* rx fifo err : reset rx fifo */
            if (int_sta & LIN_RX_FIFO_ERR_INT_STA) {
                Lin_UartClrRxFifo(locNodeCfg);
            }

            /* switch lin status */
            switch (locNodeData->framestate) {
            case LIN_FRAMERECEIVE:
                Lin_UartClrRxFifo(locNodeCfg);
                locNodeData->error   = LIN_FRAMIN_ERROR;
                gLin_Channels[numNodeID].ChannelState = LIN_RX_ERROR;

                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
    #if (LIN_SLAVE_MODE_USED == STD_ON)
                    LinIf_LinErrorIndication(numNodeID, LIN_ERR_INC_RESP);
    #endif /* LIN_SLAVE_MODE_USED */
                } else {
                    locNodeData->framestate   = LIN_FRAMERECEIVEERR;
                }
                break;
            case LIN_FRAMETRANSMIT:
                Lin_UartClrTxFifo(locNodeCfg);
                gLin_Channels[numNodeID].ChannelState = LIN_TX_ERROR;
                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                    LinIf_LinErrorIndication(numNodeID, LIN_ERR_RESP_DATABIT);
#endif /* LIN_SLAVE_MODE_USED */
                } else {
                    locNodeData->framestate   = LIN_FRAMETRANSMITERR;
                }
#if (LIN_TX_ERROR_DETECT == STD_ON)
                Lin_IocEnable(numNodeID, FALSE);
#endif /* LIN_TX_ERROR_DETECT */
                break;
            case LIN_FRAMEPENDING:
#if (LIN_SLAVE_MODE_USED == STD_ON)
                if (int_sta & LIN_INTR0_RXPIDERR || int_sta & LIN_INTR0_RXPIDPASS) {
                    LinIf_LinErrorIndication(numNodeID, LIN_ERR_HEADER);
                }
#endif /* LIN_SLAVE_MODE_USED */
                break;
            default:
                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
                } else {
                    locNodeData->framestate   = LIN_FRAMEIDLE;
                }
                break;
            }
            return;
        }
    }

    switch (locNodeData->currentState) {
    case LIN_WAIT_FOR_WAKEUP:
        /* slave mode: rxbreak int is wakeup signal
            master mode: frameerr is wakeup signal */
        if (int_sta & LIN_INTR0_RXBREAK || int_sta & LIN_INTR0_FRAMEERR) {
            /* Get ready for sync break transmission */
            if (Lin_Wakeup_Self_Flag[numNodeID] == TRUE) {
                locNodeData->currentState = LIN_ACTIVE;
                Lin_Wakeup_Self_Flag[numNodeID] = FALSE;
                LinIf_MasterWakeupConfirmation(0);
            }
            if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                locNodeData->framestate   = LIN_FRAMEPENDING;

            } else {
                /* master mode recieve wakeup break */
                Lin_UartRxBreakCtrl(locNodeCfg, 0);
                Lin_Sleep_Flag[numNodeID] = FALSE;
                locNodeData->framestate   = LIN_FRAMEIDLE;
            }
            Lin_ChStatus[numNodeID] = LIN_CH_OPERATIONAL;
            Lin_Wakeup_Flag[numNodeID] = TRUE;
            Lin_UartRstMod(locNodeCfg);
            /**************Add by Jxy*****************/
            if(((0xFF == CCUWakeupReturnValue)||(0x22 == CCUWakeupReturnValue)||(0x31 == CCUWakeupReturnValue))&&(0x55 != App_ComMReqFlag)&&(100 > FirstWakeUpSource500ms ))
            {
               CCUWakeupReturnValue = 0x13;
               HW_Trigger_Timer = (2000/10);
            }
            else if((0 == HW_Active_ComReq)&&(100 <= FirstWakeUpSource500ms)&&(0 == CanIf_FirstCallRxInd[0])
            &&(0 == CanIf_FirstCallRxInd[1])&&(0 == CanIf_FirstCallRxInd[3])&&(0 == CanIf_FirstCallRxInd[5]))
            {
                HW_Trigger_Timer = (2000/10);
            }
        }
        /* master mode need set break bit when goto sleep frame over */
        if ((int_sta & LIN_INTR0_APBCMDDONE) && (Lin_Sleep_Flag[numNodeID] == TRUE)) {
            Lin_UartRxBreakCtrl(locNodeCfg, 11);
        }
        break;
    case LIN_ACTIVE:
        switch (locNodeData->framestate) {
        case LIN_FRAMERECEIVE:
            if (int_sta & LIN_INTR0_RXCHKSUMPASS) {
                Lin_UartGetChar(locNodeCfg, locNodeData->rxframe, locNodeData->dl);
                gLin_Channels[numNodeID].ChannelState = LIN_RX_OK;

                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                    LinIf_RxIndication(numNodeID, (locNodeData->rxframe));
#endif /* LIN_SLAVE_MODE_USED */
                } else {
                    locNodeData->framestate   = LIN_FRAMEIDLE;
                }
            } else if (int_sta & LIN_INTR0_RXCHKSUMERR) {
                Lin_UartGetChar(locNodeCfg, locNodeData->rxframe, locNodeData->dl);
                locNodeData->error   = LIN_CHKSUM_ERROR;
                gLin_Channels[numNodeID].ChannelState = LIN_RX_ERROR;

                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                    LinIf_LinErrorIndication(numNodeID, LIN_ERR_RESP_CHKSUM);
#endif /* LIN_SLAVE_MODE_USED */
                } else {
                    locNodeData->framestate   = LIN_FRAMECHECKSUMERR;
                }
            } else if (int_sta & LIN_INTR0_APBCMDABORT) {
                Lin_UartClrRxFifo(locNodeCfg);
                locNodeData->error   = LIN_FRAMIN_ERROR;
                gLin_Channels[numNodeID].ChannelState = LIN_RX_ERROR;

                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                    LinIf_LinErrorIndication(numNodeID, LIN_ERR_INC_RESP);
#endif /* LIN_SLAVE_MODE_USED */
                } else {
                    Lin_UartRstMod(locNodeCfg);
                    locNodeData->framestate   = LIN_FRAMERECEIVEERR;

                }
            }
            break;
        case LIN_FRAMETRANSMIT:
            if (int_sta & LIN_INTR0_APBCMDDONE) {
#if (LIN_TX_ERROR_DETECT== STD_ON)
                if (Lin_IocTxErrCheck(numNodeID)) {
                    gLin_Channels[numNodeID].ChannelState = LIN_TX_ERROR;
                    if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                        locNodeData->framestate   = LIN_FRAMEPENDING;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                        LinIf_LinErrorIndication(numNodeID, LIN_ERR_RESP_DATABIT);
#endif /* LIN_SLAVE_MODE_USED */
                    } else {
                        locNodeData->framestate   = LIN_FRAMEIDLE;
                    }
                } else {
#endif /* LIN_TX_ERROR_DETECT */
                    gLin_Channels[numNodeID].ChannelState = LIN_TX_OK;
                    if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                        locNodeData->framestate   = LIN_FRAMEPENDING;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                        LinIf_TxConfirmation(numNodeID);
#endif /* LIN_SLAVE_MODE_USED */
                    } else {
                        locNodeData->framestate   = LIN_FRAMEIDLE;
                    }
#if (LIN_TX_ERROR_DETECT== STD_ON)
                }
#endif /* LIN_TX_ERROR_DETECT */

            } else if (int_sta & LIN_INTR0_APBCMDABORT) {
                gLin_Channels[numNodeID].ChannelState = LIN_TX_ERROR;

                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                        LinIf_LinErrorIndication(numNodeID, LIN_ERR_RESP_DATABIT);
#endif /* LIN_SLAVE_MODE_USED */
                } else {
                    locNodeData->framestate   = LIN_FRAMETRANSMITERR;
                }
            }
#if (LIN_TX_ERROR_DETECT == STD_ON)
            Lin_IocEnable(numNodeID, FALSE);
#endif /* LIN_TX_ERROR_DETECT */
            break;
        /* LIN_FRAMEPENDING : slave mode only */
        case LIN_FRAMEPENDING:
            if ((int_sta & LIN_INTR0_ABRPASSE)) {
#if defined(SEMIDRIVE_E3_LITE_SERIES)
                /* e3 lite 1.1 chip noneed dis able abr anymore */
                if (Mcu_GetChipVersion() == 0x0U) {
#endif
                    Lin_UartClrRxFifo(locNodeCfg);
                    Lin_UartSetAbr(locNodeCfg);
                    Lin_UartRstMod(locNodeCfg);
                    Lin_UartSetAbrEn(locNodeCfg, FALSE);
#if defined(SEMIDRIVE_E3_LITE_SERIES)
                } else{
                    Lin_UartSetAbr(locNodeCfg);
                }
#endif
                break;
            }

            if ((int_sta & LIN_INTR0_ABRFAILE)) {
                Lin_UartClrRxFifo(locNodeCfg);
                gLin_Channels[numNodeID].ChannelState = LIN_RX_ERROR;
#if defined(SEMIDRIVE_E3_LITE_SERIES)
                if (Mcu_GetChipVersion() == 0x0U) {
#endif
                    Lin_UartRstMod(locNodeCfg);
                    Lin_UartSetAbrEn(locNodeCfg, TRUE);
#if defined(SEMIDRIVE_E3_LITE_SERIES)
                }
#endif
                break;
            }

            if ((int_sta & LIN_INTR0_RXPIDERR)) {
#if (LIN_SLAVE_MODE_USED == STD_ON)
                LinIf_LinErrorIndication(numNodeID, LIN_ERR_HEADER);
#endif /* LIN_SLAVE_MODE_USED */
                break;
            }

            if ((int_sta & LIN_INTR0_RXPIDPASS)) {
                Lin_PduType slvPduInfo;
                slvPduInfo.Pid = Lin_UartPidGet(locNodeCfg);
                slvPduInfo.SduPtr = locNodeData->txframe;
#if (LIN_SLAVE_MODE_USED == STD_ON)
                Std_ReturnType Ret = E_NOT_OK;
                Ret = LinIf_HeaderIndication(numNodeID, &slvPduInfo);
                if (Ret != E_OK || slvPduInfo.Drc == LIN_SLAVE_TO_SLAVE) {
                    break;
                }
#endif /* LIN_SLAVE_MODE_USED */
                Lin_HwSetNodePdu(locNodeData, &slvPduInfo);

                if (slvPduInfo.Drc == LIN_MASTER_RESPONSE) {
                    Lin_UartReceive(locNodeCfg, locNodeData->cs, locNodeData->dl);
                    locNodeData->framestate = LIN_FRAMERECEIVE;
                    gLin_Channels[numNodeID].ChannelState = LIN_RX_NO_RESPONSE;
                } else if (slvPduInfo.Drc == LIN_SLAVE_RESPONSE) {
#if (LIN_TX_ERROR_DETECT == STD_ON)
                    Lin_IocEnable(numNodeID, TRUE);
#endif /* LIN_TX_ERROR_DETECT */
                    Lin_UartTransmit(locNodeCfg, locNodeData->cs, locNodeData->txframe, locNodeData->dl);
                    locNodeData->framestate   = LIN_FRAMETRANSMIT;
                    gLin_Channels[numNodeID].ChannelState = LIN_TX_BUSY;
                }
            }
            break;

        case LIN_FRAMEABORT:
            if (int_sta & LIN_INTR0_APBCMDABORT) {
                if (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE) {
                    locNodeData->framestate   = LIN_FRAMEPENDING;
                } else {
                    locNodeData->framestate = LIN_FRAMEIDLE;
                }
                gLin_Channels[numNodeID].ChannelState = LIN_OPERATIONAL;
            }

            break;

        default:
            break;

        }

    default:
        break;
    }
#if (LIN_ICU_ABR_DETECT == STD_ON)
    if ((int_sta & LIN_INTR0_RXBREAK) && (locNodeCfg->dataPtr.icu_abr == TRUE) && (locNodeCfg->dataPtr.mode == LIN_UART_SLAVE)) {
        Icu_StartTimestamp(Lin_Icu_Abr_Chan[numNodeID], Lin_Icu_Timestamp_Buffer[numNodeID], 12, 12);
    }
#endif /* LIN_ICU_ABR_DETECT */
}

Std_ReturnType Lin_HwWakeup(uint8 numNodeId)
{
    const Lin_Uart     *locNodeCfg;
    Lin_NodeData       *locNodeData;
    uint8               Ret = E_OK;
    locNodeCfg = &pLin_Config->channels[numNodeId];
    locNodeData = &(gLin_Channels[numNodeId].channelInfo);

    if (locNodeData->currentState == LIN_WAIT_FOR_WAKEUP) {
        Lin_Uart_Set_Break(locNodeCfg);
    } else {
        Ret = E_NOT_OK;
    }

    return Ret;
}

uint32 Lin_HwGetNode(Mcu_ModuleType UartId)
{
    const Lin_Uart     *locNodeCfg;
    uint32 NodeId;

    for (NodeId = 0; NodeId <= LIN_NUM_CHANNELS; NodeId++) {
        locNodeCfg = &pLin_Config->channels[NodeId];

        if (locNodeCfg->UartModule == UartId) {
            break;
        }
    }

    return NodeId;
}

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
