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
 * @file  Eth.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Dem.h"
#include "Eth.h"
#include "RegBase.h"
#include "dwmac.h"
#include "EthBuff.h"
#include "EthDesc.h"
#include "Mcu_Soc.h"
#include "RegHelper.h"
#include "irq_num.h"
#include "EthTrcv.h"
#include "EthIf.h"
#include "cdefs.h"
#include "mini_libc.h"
#include "dwmac_common.h"

/* Version and Check Begin */
/* Version Info Begin */
#define ETH_C_VENDOR_ID   0x8C
#define ETH_C_AR_RELEASE_MAJOR_VERSION    4
#define ETH_C_AR_RELEASE_MINOR_VERSION    3
#define ETH_C_AR_RELEASE_REVISION_VERSION 1
#define ETH_C_SW_MAJOR_VERSION    1
#define ETH_C_SW_MINOR_VERSION    0
#define ETH_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((ETH_C_AR_RELEASE_MAJOR_VERSION != ETH_H_AR_RELEASE_MAJOR_VERSION)\
    || (ETH_C_AR_RELEASE_MINOR_VERSION != ETH_H_AR_RELEASE_MINOR_VERSION)\
    || (ETH_C_AR_RELEASE_REVISION_VERSION != ETH_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Eth.c and Eth.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((ETH_C_SW_MAJOR_VERSION != ETH_H_SW_MAJOR_VERSION)\
    || (ETH_C_SW_MINOR_VERSION != ETH_H_SW_MINOR_VERSION)\
    || (ETH_C_SW_PATCH_VERSION != ETH_H_SW_PATCH_VERSION))
#error "Opps, Eth.c and Eth.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */

#define ETH_START_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"


const static Eth_HardWare_Info_t  HW_Info[2] = {
    {
        (uint32)APB_ETH1_BASE,
        ETH1_SBD_INTR_NUM

    },
#ifdef SEMIDRIVE_E3_SERIES
    {
        (uint32)APB_ETH2_BASE,
        ETH2_SBD_INTR_NUM
    }
#endif
};

/* mtl fifo size alloc tbl sum 10kbytes */
#define  FIFO_ALLOC_MUL(p) (((p)*10240U)/100)
/* mtl tx algorithm weights/quantum of DCB wfq mode tbl 0x3fff/16383 0 is 100%*/
#define  DCB_WFQ_WHT(p)    (10-(p))
/* tx queue memery proportion */
const static uint32  tx_queue_mem_tbl[5][5] = {
    {100, 0, 0, 0, 0},
    {40, 60, 0, 0, 0},
    {20, 30, 50, 0, 0},
    {10, 20, 30, 40, 0},
    {10, 10, 20, 30, 30}
};
/* default keep old mechanism */
#ifndef ETH_NOT_RESET_DATABUFF
#define ETH_NOT_RESET_DATABUFF  0
#endif

#define ETH_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

VAR_ALIGN(Eth_Controller_t Eth_gCtrl_Eth0,CACHE_LINE);
#if ETH_MAXCTRLS_SUPPORTED == 2U
VAR_ALIGN(Eth_Controller_t Eth_gCtrl_Eth1,CACHE_LINE);
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */

#if STD_ON == ETH_GET_COUNTVAL_API
VAR_ALIGN(Eth_CounterType Eth_gCounter_Eth0,CACHE_LINE);
#if ETH_MAXCTRLS_SUPPORTED == 2U
VAR_ALIGN(Eth_CounterType Eth_gCounter_Eth1,CACHE_LINE);
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
#endif /* End of ETH_GET_COUNTVAL_API  */

#if STD_ON == ETH_GET_RXSTATS_API
VAR_ALIGN(Eth_RxStatsType Eth_gRxStats_Eth0,CACHE_LINE);
#if ETH_MAXCTRLS_SUPPORTED == 2U
VAR_ALIGN(Eth_RxStatsType Eth_gRxStats_Eth1,CACHE_LINE);
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
#endif /* End of ETH_GET_RXSTATS_API  */

#if STD_ON ==ETH_GET_TXSTATS_API
VAR_ALIGN(Eth_TxStatsType Eth_gTxStats_Eth0,CACHE_LINE);
#if ETH_MAXCTRLS_SUPPORTED == 2U
VAR_ALIGN(Eth_TxStatsType Eth_gTxStats_Eth1,CACHE_LINE);
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
#endif /* End of ETH_GET_TXSTATS_API */

#if STD_ON == ETH_GET_TXERRORCOUNT_API
VAR_ALIGN(Eth_TxErrorCounterValuesType Eth_gTxErrorCounter_Eth0,CACHE_LINE);
#if ETH_MAXCTRLS_SUPPORTED == 2U
VAR_ALIGN(Eth_TxErrorCounterValuesType Eth_gTxErrorCounter_Eth1,CACHE_LINE);
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
#endif /* End of ETH_GET_TXERRORCOUNT_API */

#define TX_TS_EN_BIT        (0x1<<15u)
#define TX_DESC_IDX_MASK    (TX_TS_EN_BIT - 1)
#define TX_DESC_IDX(idx)    (TX_DESC_IDX_MASK & (idx))

#define TX_DESC_CH_MASK     (0xFFFF0000)
#define TX_DESC_CH_GEN(idx) (TX_DESC_CH_MASK & ((idx) << 16U))
#define TX_DESC_CH_GET(idx) ((TX_DESC_CH_MASK & (idx)) >> 16u)

#if (STD_ON == ETH_GET_GLOBALTIME_API || ETH_MAX_DMA_CHANNEL > 1)

VAR_ALIGN(uint32 Eth_gTxTimeStamp0[CTRL0_TX_BUFF_COUNT],CACHE_LINE);
VAR_ALIGN(uint32 Eth_gRxTimeStamp0[CTRL0_RX_BUFF_COUNT],CACHE_LINE);
#if ETH_MAXCTRLS_SUPPORTED == 2U
VAR_ALIGN(uint32 Eth_gTxTimeStamp1[CTRL1_TX_BUFF_COUNT],CACHE_LINE);
VAR_ALIGN(uint32 Eth_gRxTimeStamp1[CTRL1_RX_BUFF_COUNT],CACHE_LINE);
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */

#endif /* End of (STD_ON == ETH_GET_GLOBALTIME_API || ETH_MAX_DMA_CHANNEL > 1) */

#if ETH_MAX_DMA_CHANNEL > 1
VAR_ALIGN(uint8 Eth_gTxPrioty0[CTRL0_TX_BUFF_COUNT],CACHE_LINE);
#if ETH_MAXCTRLS_SUPPORTED == 2U
VAR_ALIGN(uint8 Eth_gTxPrioty1[CTRL1_TX_BUFF_COUNT],CACHE_LINE);
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
#endif /* End of ETH_MAX_DMA_CHANNEL > 1 */

#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

VAR(Eth_Controller_t*, ETH_VAR)   Eth_gCtrl[ETH_MAXCTRLS_SUPPORTED] = {
    &Eth_gCtrl_Eth0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    &Eth_gCtrl_Eth1
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
};

#if STD_ON == ETH_GET_COUNTVAL_API
VAR(Eth_CounterType*, ETH_VAR)   Eth_gCounter[ETH_MAXCTRLS_SUPPORTED]={
    &Eth_gCounter_Eth0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    &Eth_gCounter_Eth1
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
};
#endif /* End of ETH_GET_COUNTVAL_API  */

#if STD_ON == ETH_GET_RXSTATS_API
VAR(Eth_RxStatsType*, ETH_VAR)    Eth_gRxStats[ETH_MAXCTRLS_SUPPORTED] = {
    &Eth_gRxStats_Eth0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    &Eth_gRxStats_Eth1
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
};
#endif /* End of ETH_GET_RXSTATS_API  */

#if STD_ON ==ETH_GET_TXSTATS_API
VAR(Eth_TxStatsType*, ETH_VAR)    Eth_gTxStats[ETH_MAXCTRLS_SUPPORTED] = {
    &Eth_gTxStats_Eth0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    &Eth_gTxStats_Eth1
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
};
#endif /* End of ETH_GET_TXSTATS_API */

#if STD_ON == ETH_GET_TXERRORCOUNT_API
VAR(Eth_TxErrorCounterValuesType*, ETH_VAR)   Eth_gTxErrorCounter[ETH_MAXCTRLS_SUPPORTED]={
    &Eth_gTxErrorCounter_Eth0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    &Eth_gTxErrorCounter_Eth1
#endif /* End of ETH_MAXCTRLS_SUPPORTED ==2 */
};
#endif /* End of ETH_GET_TXERRORCOUNT_API */

#if (STD_ON == ETH_GET_GLOBALTIME_API || ETH_MAX_DMA_CHANNEL > 1)

P2VAR(uint32, AUTOMATIC, ETH_VAR) Eth_gTxTimeStamp[ETH_MAXCTRLS_SUPPORTED] = {
    Eth_gTxTimeStamp0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    Eth_gTxTimeStamp1,
#endif
};

P2VAR(uint32, AUTOMATIC, ETH_VAR) Eth_gRxTimeStamp[ETH_MAXCTRLS_SUPPORTED] = {
    Eth_gRxTimeStamp0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    Eth_gRxTimeStamp1,
#endif
};
#endif

#if ETH_MAX_DMA_CHANNEL > 1

P2VAR(uint8, AUTOMATIC, ETH_VAR) Eth_gTxPriorty[ETH_MAXCTRLS_SUPPORTED] = {
    Eth_gTxPrioty0,
#if ETH_MAXCTRLS_SUPPORTED == 2U
    Eth_gTxPrioty1,
#endif
};

#endif

#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

#if STD_ON == ETH_GET_GLOBALTIME_API
static struct dma_desc *form_bufidx_get_desc(uint8 CtrlIdx, uint16 BufIdx)
{
    return &Eth_Desc_Buf[CtrlIdx][TX_DESC_CH_GET(Eth_gTxTimeStamp[CtrlIdx][BufIdx])][DESC_TX].
           desc[TX_DESC_IDX(Eth_gTxTimeStamp[CtrlIdx][BufIdx])];
}
/* this api for debug & test only */
uint8 form_bufidx_get_desc_chan(uint8 CtrlIdx, uint16 BufIdx)
{
    return TX_DESC_CH_GET(Eth_gTxTimeStamp[CtrlIdx][BufIdx]);
}
#endif

FUNC(void, ETH_CODE)  Eth_update_mmc_status(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#if STD_ON == ETH_GET_RXSTATS_API
    rx_stats_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), Eth_gRxStats[CtrlIdx]);
#else
    rx_stats_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), NULL_PTR);
#endif
#if STD_ON ==ETH_GET_TXSTATS_API
    tx_stats_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), Eth_gTxStats[CtrlIdx]);
#else
    tx_stats_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), NULL_PTR);
#endif
#if STD_ON == ETH_GET_COUNTVAL_API
    controller_counter_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), Eth_gCounter[CtrlIdx]);
#else
    controller_counter_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), NULL_PTR);
#endif
#if STD_ON == ETH_GET_TXERRORCOUNT_API
    tx_error_count_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), Eth_gTxErrorCounter[CtrlIdx]);
#else
    tx_error_count_update(ETH_CFG_CTRL_REG_BASE(CtrlIdx), NULL_PTR);
#endif
}

static void Eth_Init_mmc_status(uint8 CtrlIdx)
{
#if STD_ON == ETH_GET_RXSTATS_API
    memset(Eth_gRxStats[CtrlIdx],0,sizeof(Eth_RxStatsType));
#endif
#if STD_ON ==ETH_GET_TXSTATS_API
    memset(Eth_gTxStats[CtrlIdx],0,sizeof(Eth_TxStatsType));
#endif
#if STD_ON == ETH_GET_COUNTVAL_API
    memset(Eth_gCounter[CtrlIdx],0,sizeof(Eth_CounterType));
#endif
#if STD_ON == ETH_GET_TXERRORCOUNT_API
    memset(Eth_gTxErrorCounter[CtrlIdx],0,sizeof(Eth_TxErrorCounterValuesType));
#endif
}

#if STD_ON == ETH_DEV_ERROR_DETECT
LOCAL_INLINE FUNC(Std_ReturnType, ETH_CODE) Eth_CheckCurCoreCanAccess(uint8 EthCrtlIdx, uint8 Core)
{
    uint8 Ctrl;
    Std_ReturnType RetVal = E_OK;

    if (Eth_Control_Config.EthCoreConfig[Core]) {
        for (Ctrl = 0 ; Ctrl < Eth_Control_Config.EthCoreConfig[Core]->EthMaxControllers; Ctrl++) {
            if (Eth_Control_Config.EthCoreConfig[Core]->EthCntrlConfigPtr[Ctrl].EthCtrlIdx == EthCrtlIdx)
                break;
        }

        if (Eth_Control_Config.EthCoreConfig[Core]->EthMaxControllers <= Ctrl) {
            RetVal = E_NOT_OK;
        }
    } else {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}
#endif
LOCAL_INLINE FUNC(struct dma_desc *, ETH_CODE) Eth_AllocDesc
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) Channel,
    VAR(boolean, AUTOMATIC) dir_rx,
    VAR(uint32, AUTOMATIC) len,
    VAR(uint32, AUTOMATIC) dataptr,
    VAR(uint32, AUTOMATIC) flags
)
{

    P2VAR(struct dma_desc, AUTOMATIC, AUTOMATIC) tdesc;

    if (CtrlIdx >= ETH_MAXCTRLS_SUPPORTED) {
        return NULL_PTR;
    }

    tdesc = alloc_dma_desc(CtrlIdx, Channel, dir_rx);

    if (((uint32)tdesc & 0x1F) || (NULL_PTR == tdesc)) {
        /* Unalign error or alloc fail */
        return NULL_PTR;
    }

    /*swap to dma address */
    dataptr = soc_to_dma_address(dataptr);

    if (dir_rx) {
        dwmac_clear(tdesc);
        dwmac_set_addr(tdesc, (uint32 *)dataptr);
        dwmac_rd_init_rx_desc(tdesc, ETH_CFG_CTRL_RX_INT_MODE(CtrlIdx));
    } else {
        dwmac_rd_init_tx_desc(tdesc);
        dwmac_set_addr(tdesc, (uint32 *)dataptr);
        dwmac_rd_prepare_tx_desc(tdesc, len, len, flags);
    }

    return tdesc;

}

FUNC(void, ETH_CODE) Eth_ReInitRxDesc
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(locked_desc_t, AUTOMATIC, AUTOMATIC) locked_desc
)
{
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) Mem;
    P2VAR(struct dma_desc, AUTOMATIC, AUTOMATIC) tdesc = (struct dma_desc *)locked_desc->desc;

    Mem = (uint8 *)EthBuffAddr(CtrlIdx, locked_desc->buf_idx, TRUE);

    /* The address saved here is the CPU address */
    locked_desc->confirm = LOCKED_DESC_RX_DMA;

    dwmac_clear(tdesc);
    dwmac_set_addr(tdesc, (uint32 *)soc_to_dma_address((uint32)Mem));
    dwmac_rd_init_rx_desc(tdesc, ETH_CFG_CTRL_RX_INT_MODE(CtrlIdx));
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
    flush_dcache_range((uint32)tdesc, ROUNDUP(sizeof(struct dma_desc), CACHE_LINE));
#endif
    if (locked_desc_put(CtrlIdx, MULTI_CH_RX_CH_IDX, locked_desc, TRUE) < 0) {
        /* impossible to run to this position, QAC do this check */
    }

#if STD_ON == ETH_GET_GLOBALTIME_API
    Eth_gRxTimeStamp[CtrlIdx][locked_desc->buf_idx] = GET_RX_DESC_INDEX(CtrlIdx, MULTI_CH_RX_CH_IDX,
            tdesc);
#endif
}


LOCAL_INLINE FUNC(Std_ReturnType, ETH_CODE) Init_Recive_Ring
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) Channel
)
{
    VAR(sint32, AUTOMATIC) ret;
    VAR(uint32, AUTOMATIC) count;
    VAR(locked_desc_t, AUTOMATIC) fream;
    VAR(uint16, AUTOMATIC) len = ETH_CFG_CTRL_MTU(CtrlIdx);
    P2VAR(struct dma_desc, AUTOMATIC, AUTOMATIC) tdesc;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) Mem;
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx;

    for (count = 0; count < MAX_ETH_RING_LENTH; count++) {
        len = ETH_CFG_CTRL_MTU(CtrlIdx);
        ret = EthBuffAlloc(CtrlIdx, &len, &Mem, &BufIdx, TRUE);

        if ((ret < 0) || (Mem == NULL_PTR)) {
            return E_NOT_OK;
        }

        tdesc = Eth_AllocDesc(CtrlIdx, Channel, TRUE, len, (uint32)Mem, 0);

        if (tdesc == NULL_PTR) {
            return E_NOT_OK;
        }

        /* The address saved here is the CPU address */
        fream.desc = (VAR(uint32, AUTOMATIC))tdesc;
        fream.buf_idx = BufIdx;
        fream.confirm = LOCKED_DESC_RX_DMA;
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
        flush_dcache_range((uint32)tdesc, ROUNDUP(sizeof(struct dma_desc), CACHE_LINE));
#endif
        if (locked_desc_put(CtrlIdx, Channel, &fream, TRUE ) < 0) {
            /* Impossible to run to this position, QAC do this check */
        }

#if STD_ON == ETH_GET_GLOBALTIME_API
        Eth_gRxTimeStamp[CtrlIdx][BufIdx] = GET_RX_DESC_INDEX(CtrlIdx, Channel, tdesc);
#endif
    }

    // ring tail ptr
    dwmac_set_rx_tail_ptr(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                          soc_to_dma_address(((uint32)tdesc + sizeof(struct dma_desc))), \
                          Channel);

    return E_OK;
}

/**
* @brief  Init the Controller priv data
*/
LOCAL_INLINE FUNC(uint8, ETH_CODE) Eth_Init_CtrlData
(
    VAR(uint8, AUTOMATIC) Idx,
    P2CONST(Eth_CntrlConfigType, AUTOMATIC, ETH_APPL_CONST) CfgPtr
)
{
    uint8 SocIdx = ((CfgPtr->SocCtrlIdx == (uint32)ETH1) ? 0 : 1);

    uint8 CtrlIdx = CfgPtr->EthCtrlIdx;

    Eth_gCtrl[CtrlIdx]->Init_Param = (Eth_CntrlConfigType *)CfgPtr;
    Eth_gCtrl[CtrlIdx]->Controler_Mode = ETH_MODE_DOWN;
    Eth_gCtrl[CtrlIdx]->Controler_State = ETH_STATE_UNINIT;
    Eth_gCtrl[CtrlIdx]->RegBase = (uint32)(HW_Info[SocIdx].RegBase);
    Eth_gCtrl[CtrlIdx]->CtrlIdx = CtrlIdx;
    Eth_gCtrl[CtrlIdx]->IrqNum = (uint32)(HW_Info[SocIdx].IrqNum);
    Eth_gCtrl[CtrlIdx]->LastCur = 0;
    Eth_gCtrl[CtrlIdx]->RetryCnt = 0;
    Eth_gCtrl[CtrlIdx]->ReinitCnt = 0;

    return CtrlIdx;
}

/**
* @brief  Test Access Controller
*/
static FUNC(boolean, ETH_CODE) Eth_Access_Test
(
    VAR(uint8, AUTOMATIC) CtrlIdx
)
{
    return dwmac_access_test(ETH_CFG_CTRL_REG_BASE(CtrlIdx));
}

/**
* @brief  Init the Controller DMA Block
*/
FUNC(void, ETH_CODE) Eth_Ctrl_Init_DMA
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(boolean, AUTOMATIC) Rx_irq,
    VAR(boolean, AUTOMATIC) Tx_irq
)
{
    VAR(uint8, AUTOMATIC)  u8ChannelCount = 0U;

    dwmac_dma_bus_init(ETH_CFG_CTRL_REG_BASE(CtrlIdx), DEFAULT_DMA_SYS);

    /*PRQA S 2877 2*/
    for (u8ChannelCount = 0; u8ChannelCount < ETH_MAX_DMA_CHANNEL; u8ChannelCount++) {
        /* DMA Control */
        dwmac_dma_init_channel(ETH_CFG_CTRL_REG_BASE(CtrlIdx), 0, u8ChannelCount, DESC_SKIP_SIZE);
        /* ring length */
        dwmac_set_rx_ring_len(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                              MAX_ETH_RING_LENTH - 1, u8ChannelCount);
        /* ring base address */
        dwmac_dma_init_rx_chan(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                               soc_to_dma_address((uint32)Eth_Desc_Buf[CtrlIdx][u8ChannelCount][DESC_RX].desc),
                               u8ChannelCount);
        // rx bufize
        dwmac_set_bfsize(ETH_CFG_CTRL_REG_BASE(CtrlIdx), ETH_CFG_CTRL_MTU(CtrlIdx), MULTI_CH_RX_CH_IDX);
        // ring length
        dwmac_set_tx_ring_len(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                              MAX_ETH_RING_LENTH - 1, u8ChannelCount);
        // ring base address
        dwmac_dma_init_tx_chan(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                               soc_to_dma_address((uint32)Eth_Desc_Buf[CtrlIdx][u8ChannelCount][DESC_TX].desc),
                               u8ChannelCount);
        // ring tail ptr
        dwmac_set_tx_tail_ptr(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                              soc_to_dma_address((uint32)Eth_Desc_Buf[CtrlIdx][u8ChannelCount][DESC_TX].desc), \
                              u8ChannelCount);
        // enable irq
        dwmac_enable_dma_irq(ETH_CFG_CTRL_REG_BASE(CtrlIdx), u8ChannelCount, Rx_irq, Tx_irq);
    }
}
/**
* @brief  Init the Controller DMA Block
*/
LOCAL_INLINE FUNC(void, ETH_CODE) Eth_Set_Ctrl_Mode
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode
)
{
    VAR(uint8, AUTOMATIC)  u8ChannelCount = 0U;

    /*PRQA S 2877 2*/
    for (u8ChannelCount = 0; u8ChannelCount < ETH_MAX_DMA_CHANNEL; u8ChannelCount++) {
        if (CtrlMode == ETH_MODE_ACTIVE) {
            // start rx
            dwmac_dma_start_rx(ETH_CFG_CTRL_REG_BASE(CtrlIdx), MULTI_CH_RX_CH_IDX);
            // start tx
            dwmac_dma_start_tx(ETH_CFG_CTRL_REG_BASE(CtrlIdx), u8ChannelCount);
        } else {
            // stop rx
            dwmac_dma_stop_rx(ETH_CFG_CTRL_REG_BASE(CtrlIdx), MULTI_CH_RX_CH_IDX);
            // stop tx
            dwmac_dma_stop_tx(ETH_CFG_CTRL_REG_BASE(CtrlIdx), u8ChannelCount);
        }
    }
}
/**
* @brief  Init the Controller MTL Block
*/
FUNC(void, ETH_CODE) Eth_Ctrl_Init_MTL
(
    VAR(uint8, AUTOMATIC) CtrlIdx
)
{
    VAR(uint8, AUTOMATIC) u8ChannelCount = 0U;
    VAR(uint32, AUTOMATIC) u32ChannelWeight = 0U;
    Eth_CntrlConfigType *CntrlConfig = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
    const Eth_EgressQueueCBSType *Cbscfg;
    /*
        P1359 num 1 config receive arbitration algorithm  cha 8.8
    */
    dwmac_prog_mtl_rx_algorithms(ETH_CFG_CTRL_REG_BASE(CtrlIdx), MTL_RX_ALGORITHM_SP);
    /*
        P1359 num 1 config Tx scheduling. More inifo at cha 8.10
    */
    dwmac_prog_mtl_tx_algorithms(ETH_CFG_CTRL_REG_BASE(CtrlIdx), CntrlConfig->TxTrafficAlgorithms);

    /*PRQA S 2877 2*/
    for (u8ChannelCount = 0; u8ChannelCount < ETH_MAX_DMA_CHANNEL; u8ChannelCount++) {
        /* per channel config */
        Cbscfg = &CntrlConfig->CbsCfg[u8ChannelCount];

        if (CntrlConfig->MtlQueueMemPolicy != MTL_MEM_POLICY_DEFAULT) {
            u32ChannelWeight = Cbscfg->MemSize;
        } else {
            u32ChannelWeight = FIFO_ALLOC_MUL(tx_queue_mem_tbl[ETH_MAX_DMA_CHANNEL - 1][u8ChannelCount]);
        }

        dwmac_dma_tx_chan_op_mode(ETH_CFG_CTRL_REG_BASE(CtrlIdx), u8ChannelCount, SF_MODE,
                                  u32ChannelWeight, CntrlConfig->TrafficShaper);

        if (CntrlConfig->TxTrafficAlgorithms == MTL_TX_ALGORITHM_SP) {
            dwmac_dma_tx_chan_weight(ETH_CFG_CTRL_REG_BASE(CtrlIdx), u8ChannelCount, u8ChannelCount);
        }

        if (CntrlConfig->TrafficShaper == MTL_QUEUE_MODE_AVB) {
            /*PRQA S 2991,2995 2*/
            if (u8ChannelCount == 0)
                continue;

            if (CntrlConfig->TxTrafficAlgorithms == MTL_TX_ALGORITHM_CC) {
                /* config CBS and ETS not support */
                dwmac_mtl_tx_chan_set_cbs(ETH_CFG_CTRL_REG_BASE(CtrlIdx),
                                          u8ChannelCount, Cbscfg->idleSlopeOrWeight,
                                          Cbscfg->sendSlope, Cbscfg->hiCredit, Cbscfg->loCredit);
            } else if (CntrlConfig->TxTrafficAlgorithms == MTL_TX_ALGORITHM_SP) {
                dwmac_mtl_tx_chan_set_sp_mode(ETH_CFG_CTRL_REG_BASE(CtrlIdx), u8ChannelCount);
            }
        } else {
            /* weight */

            if (CntrlConfig->TxTrafficAlgorithms == MTL_TX_ALGORITHM_WFQ) {
                u32ChannelWeight = DCB_WFQ_WHT(Cbscfg->idleSlopeOrWeight);
            } else {
                u32ChannelWeight = Cbscfg->idleSlopeOrWeight;
            }

            dwmac_mtl_tx_chan_set_weight(ETH_CFG_CTRL_REG_BASE(CtrlIdx), u8ChannelCount, u32ChannelWeight);
        }

    }

    /* rx only enable one queue */
    /* mtl map with dma */
    dwmac_map_mtl_dma(ETH_CFG_CTRL_REG_BASE(CtrlIdx), MULTI_CH_RX_CH_IDX, MULTI_CH_RX_CH_IDX);
    dwmac_rx_queue_enable(ETH_CFG_CTRL_REG_BASE(CtrlIdx), MTL_QUEUE_MODE_DCB, 0);
    dwmac_dma_rx_chan_op_mode(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                              MULTI_CH_RX_CH_IDX, SF_MODE, 10240, MTL_QUEUE_MODE_DCB);

}
/**
* @brief  Init the Controller MAC block
*/
FUNC(void, ETH_CODE) Eth_Ctrl_Init_MAC
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint32, AUTOMATIC) Mtu,
    VAR(uint32, AUTOMATIC) Speed
)
{
    uint32 mac_speed = PHY_SPEED_1000;
#if STD_ON == ETH_GET_GLOBALTIME_API
    Eth_CntrlConfigType *CntrlConfig = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
#endif

    switch (Speed) {
    case ETH_MAC_LAYER_SPEED_10M:
        mac_speed = PHY_SPEED_10;
        break;

    case ETH_MAC_LAYER_SPEED_100M:
        mac_speed = PHY_SPEED_100;
        break;

    case ETH_MAC_LAYER_SPEED_1G:
        mac_speed = PHY_SPEED_1000;
        break;

    default:
        break;
    }

    /* MAC reg */
    dwmac_core_init(ETH_CFG_CTRL_REG_BASE(CtrlIdx), Mtu, \
                    ETH_CFG_CTRL_MAC_ADDR_HIGH(CtrlIdx), \
                    ETH_CFG_CTRL_MAC_ADDR_LOW(CtrlIdx), \
                    mac_speed);
    dwmac_mac_rx_queue_mcbc_routing(ETH_CFG_CTRL_REG_BASE(CtrlIdx), 0);

#if STD_ON == ETH_GET_GLOBALTIME_API
    dwmac_init_systime(ETH_CFG_CTRL_REG_BASE(CtrlIdx), 0, 0);
    config_sub_second_increment(ETH_CFG_CTRL_REG_BASE(CtrlIdx), 250000000U);
    setup_timestamp_filter(ETH_CFG_CTRL_REG_BASE(CtrlIdx),
                           CntrlConfig->ptp_version, CntrlConfig->ptp_mode, CntrlConfig->rxfilter);
#endif

}
/*

*/
LOCAL_INLINE FUNC(sint32, ETH_CODE) Eth_Select_Mii_Type
(
    VAR(uint32, AUTOMATIC) module,
    VAR(uint32, AUTOMATIC) type,
    VAR(uint32, AUTOMATIC) subtype
)
{
    sint32 ret = 0;
    uint32 eth_mii_type = ETH_PHY_INTF_SEL_RGMII;

    if (type == ETH_MAC_LAYER_TYPE_XGMII) {
        if (subtype == REDUCED) {
            eth_mii_type = ETH_PHY_INTF_SEL_RGMII;
        } else {
            ret = -1;
        }
    } else if (type == ETH_MAC_LAYER_TYPE_XMII) {
        if (subtype == SERIAL) {
            /* not support */
            ret = -1;
        } else {
            eth_mii_type = ETH_PHY_INTF_SEL_RMII;
        }
    } else {
        /* not support */
        ret = -1;
    }

    if (ret == 0) {
        /* only support smii and rgmii interface*/
        /*PRQA S 2991,2995 2*/
        if (eth_mii_type == ETH_PHY_INTF_SEL_RGMII ||
            eth_mii_type == ETH_PHY_INTF_SEL_RMII) {
            select_eth_mii_type(ETH_CFG_CTRL_REG_BASE(module), eth_mii_type);
        }
    }

    return ret;
}
static inline Std_ReturnType Eth_Det_Check(uint8 CtrlIdx, uint8 Sid)
{
    Std_ReturnType RetVal = E_OK;
#if STD_ON == ETH_DEV_ERROR_DETECT

    if (Eth_CheckCurCoreCanAccess(CtrlIdx, Mcu_GetCoreID()) != E_OK) {

        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                Sid, ETH_E_ACCESS_RES \
                              );
        RetVal = E_NOT_OK;
    }

#endif /* ETH_DEV_ERROR_DETECT  */

    if (CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED) {
#if STD_ON == ETH_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                Sid, ETH_E_INV_CTRL_IDX \
                              );
#endif /* ETH_DEV_ERROR_DETECT  */
        RetVal = E_NOT_OK;
    } else if (ETH_STATE_INIT != ETH_CTRL_STATE(CtrlIdx)) {
#if STD_ON == ETH_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                Sid, ETH_E_UNINIT \
                              );
#endif /* ETH_DEV_ERROR_DETECT  */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}
static inline Std_ReturnType Eth_Transmit_Det_Check(uint8 CtrlIdx,Eth_BufIdxType BufferIdx,uint8 Sid)
{
    Std_ReturnType RetVal = E_OK;

    if(CtrlIdx == 0 && BufferIdx >= CTRL0_TX_BUFF_COUNT){
        RetVal = E_NOT_OK;
    }
#if ETH_MAXCTRLS_SUPPORTED == 2U
    if(CtrlIdx == 1 && BufferIdx >= CTRL1_TX_BUFF_COUNT){
        RetVal = E_NOT_OK;
    }
#endif

#if STD_ON == ETH_DEV_ERROR_DETECT
    if(RetVal == E_NOT_OK){
        (void)Det_ReportError ((uint8) ETH_MODULE_ID,
                            ETH_DRIVER_INSTANCE,
                            Sid,
                            ETH_E_PARAM_POINTER);
    }
#endif /* ETH_DEV_ERROR_DETECT  */

    return RetVal;
}
/*
    Shall store the config params
*/
FUNC(void, ETH_CODE) Eth_Init
(
    P2CONST(Eth_ConfigType, AUTOMATIC, ETH_APPL_CONST) CfgPtr
)
{

    VAR(uint8, AUTOMATIC)  CtrlIdx = 0U;
    VAR(uint8, AUTOMATIC)  CoreId = 0U;
    VAR(sint32, AUTOMATIC)  reset_ret = 0U;
    VAR(uint8, AUTOMATIC)  CoreCntrlIdx = 0U;
    VAR(Std_ReturnType, AUTOMATIC)  ret = E_OK;
    P2VAR(const Eth_CntrlConfigType, AUTOMATIC, AUTOMATIC) LocalCfgPtr;
    P2VAR(const Eth_CoreConfigType, AUTOMATIC, AUTOMATIC) CoreConfig;

    if (NULL_PTR == CfgPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_INIT, \
                                ETH_E_PARAM_POINTER \
                              );
#endif /* ETH_DEV_ERROR_DETECT  */
    } else {
        CoreId = Mcu_GetCoreID();

        CoreConfig = CfgPtr->EthCoreConfig[CoreId];

        if (NULL_PTR == CoreConfig) {
            ret = E_NOT_OK;
        }

        if (E_OK == ret) {
            /* */
            for (CoreCntrlIdx = 0; CoreCntrlIdx < CoreConfig->EthMaxControllers; CoreCntrlIdx++)
            {
                /* config param */
                LocalCfgPtr = &CoreConfig->EthCntrlConfigPtr[CoreCntrlIdx];
                /* bound init data */
                CtrlIdx = Eth_Init_CtrlData(CoreCntrlIdx, LocalCfgPtr);

                /* hardware special init */
                if (Eth_Select_Mii_Type(CtrlIdx, \
                                        LocalCfgPtr->MacLayerType, \
                                        LocalCfgPtr->MacLayerSubType)) {
#if STD_ON == ETH_DEV_ERROR_DETECT
                    (void)Det_ReportError ( \
                                            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_INIT, \
                                            ETH_E_PARAM_POINTER \
                                          );
#endif  /* ETH_DEM_EVENT_DETECT  */
                    return;
                }

                /* DMA core sw reset */
                reset_ret  = dwmac_dma_reset(ETH_CFG_CTRL_REG_BASE(CtrlIdx));

                if (reset_ret < 0) {
                    Dem_SetEventStatus((Dem_EventIdType)ETH_CFG_DEM_E_ACCESS(CtrlIdx), DEM_EVENT_STATUS_PREFAILED);
                } else {
                    /* DMA Init */
                    Eth_Ctrl_Init_DMA(CtrlIdx, ETH_CFG_CTRL_RX_INT_MODE(CtrlIdx),
                                      ETH_CFG_CTRL_TX_INT_MODE(CtrlIdx));
                    /* MTL Init */
                    Eth_Ctrl_Init_MTL(CtrlIdx);
                    /* MAC Init */
                    Eth_Ctrl_Init_MAC(CtrlIdx, LocalCfgPtr->Mtu, LocalCfgPtr->MacLayerSpeed);
                    /* Init soft Statistic */
                    Eth_Init_mmc_status(CtrlIdx);
                }

                /* Access test*/
                if (reset_ret != 0 || Eth_Access_Test(CtrlIdx) == 0) {
                    Dem_SetEventStatus((Dem_EventIdType)ETH_CFG_DEM_E_ACCESS(CtrlIdx), DEM_EVENT_STATUS_PREFAILED);
                    ETH_CTRL_STATE(CtrlIdx) = ETH_STATE_UNINIT;
                } else {
#if (ETH_NOT_RESET_DATABUFF == 1)
                    /* desc ring init */
                    desc_ring_init(CtrlIdx);
                    /* buffer init*/
                    EthBuffInit(CtrlIdx);
                    /* Init recved desc ring to hw */
                    if(E_OK != Init_Recive_Ring(CtrlIdx, MULTI_CH_RX_CH_IDX))
                    {
                        /* The number of rx descriptors is greater than the number of rx buffers,
                        resulting in failed initialization */
                        ETH_CTRL_STATE(CtrlIdx) = ETH_STATE_UNINIT;
                    }
                    else
                    {
#endif
                        ETH_CTRL_STATE(CtrlIdx) = ETH_STATE_INIT;
#if (ETH_NOT_RESET_DATABUFF == 1)
                    }
#endif
                }
            }
        }
    }
}

/*
*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_SetControllerMode
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode
)
{
    Std_ReturnType RetVal = E_OK;

    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_SETCONTROLLERMODE);

    if (RetVal == E_OK) {
        if (CtrlMode == ETH_MODE_DOWN) {
            /* data buf ring deinit */
#if (ETH_NOT_RESET_DATABUFF == 0)
            EthBuffDeInit(CtrlIdx);
#endif
        } else {
#if (ETH_NOT_RESET_DATABUFF == 0)
            /* desc ring init */
            desc_ring_init(CtrlIdx);
            EthBuffInit(CtrlIdx);
            /* Init recved desc ring to hw */
            if(E_OK != Init_Recive_Ring(CtrlIdx, MULTI_CH_RX_CH_IDX)){
                /* The number of rx descriptors is greater than the number of rx buffers,
                resulting in failed initialization */
                RetVal = E_NOT_OK;
            }
#endif
        }

        if (RetVal == E_NOT_OK || (!Eth_Access_Test(CtrlIdx))) {
            Dem_SetEventStatus((Dem_EventIdType)ETH_CFG_DEM_E_ACCESS(CtrlIdx), DEM_EVENT_STATUS_PREFAILED);
            RetVal = E_NOT_OK;
        }

        if (RetVal == E_OK) {
            ETH_CTRL_MODE(CtrlIdx) = CtrlMode;
            Eth_Set_Ctrl_Mode(CtrlIdx, CtrlMode);
            EthIf_CtrlModeIndication(CtrlIdx, CtrlMode);
        }
    }

    return RetVal;
}
/*
*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetControllerMode
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_CONST) CtrlModePtr
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETCONTROLLERMODE);

    if (RetVal == E_OK) {
        if (NULL_PTR == CtrlModePtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETCONTROLLERMODE, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            *CtrlModePtr = ETH_CTRL_MODE(CtrlIdx);
        }
    }

    return RetVal;
}
/*

*/
FUNC(void, ETH_CODE) Eth_GetPhysAddr
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETH_APPL_CONST) AddrPtr
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETPHYSADDR);

    if (RetVal == E_OK) {
        if (NULL_PTR == AddrPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETPHYSADDR, ETH_E_PARAM_POINTER \
                                  );
#endif
        } else {
            dwmac_get_umac_addr(ETH_CFG_CTRL_REG_BASE(CtrlIdx), AddrPtr, 0);
        }
    }
}

/*

*/
FUNC(void, ETH_CODE) Eth_SetPhysAddr
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) AddrPtr
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_SETPHYSADDR);

    if (RetVal == E_OK) {
        if (NULL_PTR == AddrPtr)  {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_SETPHYSADDR, ETH_E_PARAM_POINTER \
                                  );
#endif
        } else {
            dwmac_set_umac_addr(ETH_CFG_CTRL_REG_BASE(CtrlIdx), AddrPtr, 0);
        }
    }
}

#if STD_ON == ETH_UPDATE_FILTER_API
/*
    PhysAddrPtr is an multicast mac addr
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_UpdatePhysAddrFilter
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr,
    Eth_FilterActionType Action
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_UPDATEADDRFILTER);

    if (RetVal == E_OK) {
        if (NULL_PTR == PhysAddrPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_UPDATEADDRFILTER, ETH_E_PARAM_POINTER \
                                  );
#endif
            RetVal = E_NOT_OK;
        } else {
            if (dwmac_set_filter(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                                 Action, PhysAddrPtr)) {
                RetVal = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#endif

/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_WriteMii(VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(uint8, AUTOMATIC) TrcvIdx, \
        VAR(uint8, AUTOMATIC) RegIdx, \
        VAR(uint16, AUTOMATIC) RegVal)
{
    Std_ReturnType RetVal = E_OK;
#if STD_OFF == MDIO_DET_CHECK_BYPASS
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_WRITEMII);
#endif

    if (RetVal == E_OK) {
        if (mac_mdio_write(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                           TrcvIdx, PHY_CLAUSE_22, RegIdx, RegVal)) {
            RetVal =  E_NOT_OK;
        }else{
            EthTrcv_WriteMiiIndication(CtrlIdx, TrcvIdx, RegIdx);
        }
    }

    return RetVal;
}

/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_ReadMii
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(uint8, AUTOMATIC) RegIdx,
    P2VAR(uint16, AUTOMATIC, ETH_APPL_CONST) RegValPtr
)
{
    Std_ReturnType RetVal = E_OK;
#if STD_OFF == MDIO_DET_CHECK_BYPASS
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_READMII);
#endif

    if (RetVal == E_OK) {
        if (NULL_PTR == RegValPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_READMII, ETH_E_PARAM_POINTER \
                                  );
#endif
            RetVal = E_NOT_OK;
        } else {
            sint32 ret = mac_mdio_read(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                                       TrcvIdx, PHY_CLAUSE_22, RegIdx);

            if (ret == -1) {
                RetVal = E_NOT_OK;
            } else {
                *RegValPtr = (VAR(uint16, AUTOMATIC))(ret & 0xFFFF);
                EthTrcv_ReadMiiIndication(CtrlIdx, TrcvIdx, RegIdx, *RegValPtr);
            }
        }
    }

    return RetVal;
}

#if STD_ON == ETH_GET_COUNTVAL_API
/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetCounterValues
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_CONST) CounterPtr
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETCOUNTERVALUES);

    if (RetVal == E_OK) {
        if (NULL_PTR == CounterPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETCOUNTERVALUES, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            Eth_update_mmc_status(CtrlIdx);
            memcpy(CounterPtr, Eth_gCounter[CtrlIdx], sizeof(Eth_CounterType));
        }
    }

    return RetVal;
}
#endif


#if STD_ON == ETH_GET_RXSTATS_API
/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetRxStats
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_CONST) RxStats
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETRXSTATS);

    if (RetVal == E_OK) {
        if (NULL_PTR == RxStats) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETRXSTATS, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            Eth_update_mmc_status(CtrlIdx);
            memcpy(RxStats, Eth_gRxStats[CtrlIdx], sizeof(Eth_RxStatsType));
        }
    }

    return RetVal;
}
#endif /*ETH_GET_RXSTATS_API*/



#if STD_ON == ETH_GET_TXSTATS_API
/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetTxStats
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_CONST) TxStats
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETTXSTATS);

    if (RetVal == E_OK) {
        if (NULL_PTR == TxStats) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETTXSTATS, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            Eth_update_mmc_status(CtrlIdx);
            memcpy(TxStats, Eth_gTxStats[CtrlIdx], sizeof(Eth_TxStatsType));
        }
    }

    return RetVal;
}
#endif /*ETH_GET_TXSTATS_API*/

#if STD_ON == ETH_GET_TXERRORCOUNT_API
/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetTxErrorCounterValues
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_CONST) TxErrorPtr
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETTXERRORCOUNTERVALUE);

    if (RetVal == E_OK) {
        if (NULL_PTR == TxErrorPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETTXERRORCOUNTERVALUE, ETH_E_PARAM_POINTER \
                                  );
#endif
            RetVal = E_NOT_OK;
        } else {
            Eth_update_mmc_status(CtrlIdx);
            memcpy(TxErrorPtr, Eth_gTxErrorCounter[CtrlIdx], sizeof(Eth_TxErrorCounterValuesType));
        }
    }

    return RetVal;
}
#endif /* ETH_GET_TXERRORCOUNT_API */

#if STD_ON == ETH_GET_GLOBALTIME_API
/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetCurrentTime
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_CONST) timeQualPtr,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) timeStampPtr
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETCURRENTTIME);

    if (RetVal == E_OK) {
        if (NULL_PTR == timeStampPtr || NULL_PTR == timeQualPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETCURRENTTIME, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {

            timeStampPtr->secondsHi = 0;
            dwmac_get_time(ETH_CFG_CTRL_REG_BASE(CtrlIdx),
                           &timeStampPtr->seconds, &timeStampPtr->nanoseconds);
            *timeQualPtr = ETH_VALID;
        }
    }

    return RetVal;
}


/*

*/
FUNC(void, ETH_CODE) Eth_EnableEgressTimeStamp
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_ENABLEEGRESSTIMESTAMP);

    if (RetVal == E_OK) {
        if (cacul_buf_cnt(CtrlIdx, FALSE) >= BufIdx) {
            /* The lower 15bit is used to store desc idx*/
            Eth_gTxTimeStamp[CtrlIdx][BufIdx] |= TX_TS_EN_BIT;
        }
    }
}
/*

*/
FUNC(void, ETH_CODE) Eth_GetEgressTimeStamp
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
    P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_CONST) timeQualPtr,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) timeStampPtr
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETEGRESSTIMESTAMP);

    if (RetVal == E_OK) {
        if ((NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr)) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETEGRESSTIMESTAMP, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
        } else {
            struct dma_desc *desc = form_bufidx_get_desc(CtrlIdx, BufIdx);

            if (dwmac_wrback_get_tx_timestamp_status(desc)) {
                timeStampPtr->nanoseconds = desc->des0;
                timeStampPtr->seconds = desc->des1 ;
                timeStampPtr->secondsHi = 0;
                *timeQualPtr =  ETH_VALID;
            } else {
                *timeQualPtr =  ETH_INVALID;
            }
        }
    }
}

/*

*/
FUNC(void, ETH_CODE) Eth_GetIngressTimeStamp
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2CONST(Eth_DataType, AUTOMATIC, ETH_APPL_CONST) DataPtr, \
    P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_CONST) timeQualPtr,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) timeStampPtr
)
{
    Eth_BufIdxType BufIdx;
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_GETINGRESSTIMESTAMP);

    if (RetVal == E_OK) {
        if ((NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr) || (NULL_PTR == DataPtr)) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_GETINGRESSTIMESTAMP, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
        } else {
            /* Get the idx of buf from it's addr */
            BufIdx = EthBuffIdxFormAddr(CtrlIdx, DataPtr, TRUE);

            if (ILLEGAL_BUFF_IDX != BufIdx ) {
                /* Get Current desc */
                struct dma_desc *cur_desc = get_dma_desc(CtrlIdx, MULTI_CH_RX_CH_IDX,
                                            Eth_gRxTimeStamp[CtrlIdx][BufIdx], TRUE);
                /* Get desc addr from idx of buf */
                struct dma_desc *next_desc = get_dma_desc_next(CtrlIdx, MULTI_CH_RX_CH_IDX,
                                             Eth_gRxTimeStamp[CtrlIdx][BufIdx], TRUE);

                /* This desc is a context desc */
                if (dwmac_wrback_get_rx_timestamp_status(cur_desc, next_desc)) {
                    timeStampPtr->nanoseconds = next_desc->des0;
                    timeStampPtr->seconds = next_desc->des1 ;
                    timeStampPtr->secondsHi  = 0;
                    *timeQualPtr =  ETH_VALID;
                } else {
                    *timeQualPtr =  ETH_INVALID;
                }
            } else {
                *timeQualPtr =  ETH_INVALID;
            }
        }
    }
}
#endif /* ETH_GET_GLOBALTIME_API */
/*

*/
FUNC(BufReq_ReturnType, ETH_CODE) Eth_ProvideTxBuffer
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) Priority,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_CONST) BufIdxPtr,
    P2P2VAR(uint8, AUTOMATIC, ETH_APPL_CONST) BufPtr,
    P2VAR(uint16, AUTOMATIC, ETH_APPL_CONST) LenBytePtr
)
{
    Std_ReturnType ret = E_OK;
    VAR(sint32, AUTOMATIC) result;
    VAR(BufReq_ReturnType, AUTOMATIC) RetVal = BUFREQ_E_NOT_OK;
    /* reserve 14 bytes for ethnet fream header */
    VAR(uint16, AUTOMATIC) LenByte;
#if (ETH_MAX_DMA_CHANNEL > 1U)
    Eth_CntrlConfigType *CntrlConfig = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
#endif
    ret = Eth_Det_Check(CtrlIdx, ETH_SID_PROVIDETXBUFFER);

    if (Priority >= MAX_PRIORITY_LEVEL) {
        ret = E_NOT_OK;
    }

    if (ret == E_OK) {
        if (NULL_PTR == BufIdxPtr || NULL_PTR == LenBytePtr || NULL_PTR == BufPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_PROVIDETXBUFFER, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = BUFREQ_E_NOT_OK;
        } else {
            LenByte = *LenBytePtr + MAC_HEADER_LEN;
            result = EthBuffAlloc(CtrlIdx, &LenByte, BufPtr, BufIdxPtr, FALSE);

            if (-1 == result) {
                RetVal = BUFREQ_E_BUSY;
            } else if (result == -2) {
                *LenBytePtr = LenByte;
                RetVal = BUFREQ_E_OVFL;
            } else {
                *LenBytePtr = LenByte;
                RetVal = BUFREQ_OK;
#if (ETH_MAX_DMA_CHANNEL > 1U)

                if (CntrlConfig->TrafficShaper == MTL_QUEUE_MODE_AVB &&
                    CntrlConfig->TxTrafficAlgorithms == MTL_TX_ALGORITHM_SP) {
                    Eth_gTxPriorty[CtrlIdx][*BufIdxPtr] =
                        (Priority >= ETH_MAX_DMA_CHANNEL) ? ETH_MAX_DMA_CHANNEL - 1 : Priority;
                } else {
                    // default use queue 0 for all pac.
                    Eth_gTxPriorty[CtrlIdx][*BufIdxPtr] = 0;

                    // search config to select queue .
                    for (uint8 u8ChannelCount = 0; u8ChannelCount < ETH_MAX_DMA_CHANNEL; u8ChannelCount++) {
                        if (CntrlConfig->CbsCfg[u8ChannelCount].PriortyMin <= Priority && \
                            Priority <= CntrlConfig->CbsCfg[u8ChannelCount].PriortyMax) {
                            Eth_gTxPriorty[CtrlIdx][*BufIdxPtr] = u8ChannelCount;
                            break;
                        }
                    }
                }

#endif
            }
        }
    }

    return RetVal;
}
/*

*/
FUNC(Std_ReturnType, ETH_CODE) Eth_Transmit(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
    VAR(Eth_FrameType, AUTOMATIC) FrameType,
    VAR(boolean, AUTOMATIC) TxConfirmation,
    VAR(uint16, AUTOMATIC) LenByte,
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr
)
{

    VAR(uint16, AUTOMATIC) len = 0;
    Std_ReturnType RetVal = E_OK;
    VAR(locked_desc_t, AUTOMATIC) fream;
    P2VAR(struct dma_desc, AUTOMATIC, AUTOMATIC) tdesc;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) Mem_BeforData;
    VAR(uint16, AUTOMATIC) flags =   DESC_FLAGS_TX_FIRST | \
                                     DESC_FLAGS_TX_LAST | \
                                     DESC_FLAGS_TX_CPC_CRC_PAD_INSER | \
                                     DESC_FLAGS_TX_SAIC_REPLA | \
                                     DESC_FLAGS_TX_OWN;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_TRANSMIT);

    RetVal |= Eth_Transmit_Det_Check(CtrlIdx,BufIdx,ETH_SID_TRANSMIT);

    if (RetVal == E_OK) {
        if (NULL_PTR == PhysAddrPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (uint8) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (uint8) \
                                    ETH_SID_TRANSMIT, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        }

        if (ETH_MODE_ACTIVE != ETH_CTRL_MODE(CtrlIdx)) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (uint8) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (uint8) \
                                    ETH_SID_TRANSMIT, ETH_E_INV_MODE \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        }
    }

    if (RetVal == E_OK) {
        /* interrupt */
        if (ETH_CFG_CTRL_TX_INT_MODE(CtrlIdx)) {
            flags |= DESC_FLAGS_IC;
        }

#if (ETH_MAX_DMA_CHANNEL > 1U)
        uint8 chan_idx = Eth_gTxPriorty[CtrlIdx][BufIdx];
#else
        uint8 chan_idx = 0;
#endif
        Mem_BeforData = (P2VAR(uint8, AUTOMATIC, AUTOMATIC))\
                        EthBuffAddr(CtrlIdx, BufIdx, FALSE);

        /* full dts mac addr*/
        for (len = 0; len < 6; len++) {
            Mem_BeforData[len] = PhysAddrPtr[len];
        }

        /* fream type */
        Mem_BeforData[12] = ((FrameType >> 8) & 0xFF);
        Mem_BeforData[13] = ((FrameType >> 0) & 0xFF);
        /*
            Critical protection here is to avoid interruption and interruption of the sending process.
        */
        SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_01();
#if STD_ON == ETH_GET_GLOBALTIME_API

        /* timeStamp support for tx */
        if (Eth_gTxTimeStamp[CtrlIdx][BufIdx] & TX_TS_EN_BIT) {
            flags |= DESC_FLAGS_TIMESTAMP;
            Eth_gTxTimeStamp[CtrlIdx][BufIdx] &= (uint32)(~TX_TS_EN_BIT);
        }

#endif
        tdesc = Eth_AllocDesc(CtrlIdx, chan_idx, FALSE, \
                              LenByte + MAC_HEADER_LEN, \
                              (uint32)Mem_BeforData, \
                              flags);

        if ( tdesc == NULL_PTR ) {
            EthBuffFree(CtrlIdx, BufIdx, FALSE);
            RetVal = E_NOT_OK;
        }

        if (RetVal == E_OK) {
            fream.desc = (VAR(uint32, AUTOMATIC))tdesc;
            fream.buf_idx = BufIdx;
            fream.confirm = LOCKED_DESC_TX_DMA;

            if (TxConfirmation) {
                fream.confirm |= LOCKED_DESC_TX_CONFIRM;
            }

            if (locked_desc_put(CtrlIdx, chan_idx, &fream, FALSE)) {
                free_dma_desc(CtrlIdx, chan_idx, FALSE);
                EthBuffFree(CtrlIdx, BufIdx, FALSE);
                RetVal = E_NOT_OK;
            }
        }

#if STD_ON == ETH_GET_GLOBALTIME_API
        Eth_gTxTimeStamp[CtrlIdx][BufIdx] = TX_DESC_IDX(GET_TX_DESC_INDEX(CtrlIdx, chan_idx, tdesc));
#endif
#if (ETH_MAX_DMA_CHANNEL > 1U)
        Eth_gTxTimeStamp[CtrlIdx][BufIdx] &= ~TX_DESC_CH_MASK;
        Eth_gTxTimeStamp[CtrlIdx][BufIdx] |= TX_DESC_CH_GEN(chan_idx);
#endif

        if (RetVal == E_OK) {
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
            flush_dcache_range((uint32)tdesc, ROUNDUP(sizeof(*tdesc), CACHE_LINE));
            flush_dcache_range((uint32)Mem_BeforData, ROUNDUP(LenByte + MAC_HEADER_LEN, CACHE_LINE));
#endif
            dwmac_set_tx_tail_ptr(ETH_CFG_CTRL_REG_BASE(CtrlIdx),
                                  soc_to_dma_address((uint32)&Eth_Desc_Buf[CtrlIdx][chan_idx][DESC_TX].desc[MAX_ETH_RING_LENTH]),
                                  chan_idx);
        }

        SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_01();

    }

    return RetVal;
}
/*

*/
FUNC(void, ETH_CODE) Eth_Receive
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) FifoIdx,
    P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_CONST) RxStatusPtr
)
{
    (void)FifoIdx;
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_RECEIVE);

    if (RetVal == E_OK) {
        if (NULL_PTR == RxStatusPtr) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (uint8) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (uint8) \
                                    ETH_SID_RECEIVE, ETH_E_PARAM_POINTER \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        }

        if (ETH_MODE_ACTIVE != ETH_CTRL_MODE(CtrlIdx)) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (uint8) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (uint8) \
                                    ETH_SID_RECEIVE, ETH_E_INV_MODE \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        }
    }

    if (RetVal == E_OK) {
        if (ETH_CFG_CTRL_RX_INT_MODE(CtrlIdx) == FALSE) {
            *RxStatusPtr = (Eth_RxStatusType)rx_indication(CtrlIdx, 0);
        }
    }
}
/*

*/
FUNC(void, ETH_CODE) Eth_TxConfirmation
(
    VAR(uint8, AUTOMATIC) CtrlIdx
)
{
    Std_ReturnType RetVal = E_OK;
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_TXCONFIRMATION);

    if (RetVal == E_OK) {
        if (ETH_MODE_ACTIVE != ETH_CTRL_MODE(CtrlIdx)) {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (uint8) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (uint8) \
                                    ETH_SID_TXCONFIRMATION, ETH_E_INV_MODE \
                                  );
#endif /* ETH_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        }
    }

    if (RetVal == E_OK) {
        if ((VAR(boolean, AUTOMATIC))FALSE == ETH_CFG_CTRL_TX_INT_MODE(CtrlIdx)) {
            /*PRQA S 2877 2*/
            for (sint8 channel = ETH_MAX_DMA_CHANNEL - 1; channel >= 0; channel--) {
                tx_indication(CtrlIdx, channel, FALSE);
            }
        }/*ETH_CFG_ENABLETXINTERRUPT*/
    }
}

#if STD_ON == ETH_GET_VERSION_INFO_API
/*

*/
FUNC(void, ETH_CODE) Eth_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETH_APPL_CONST) VersionInfoPtr
)
{
#if STD_ON == ETH_DEV_ERROR_DETECT

    if (NULL_PTR == VersionInfoPtr) {
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_GETVERSIONINFO, ETH_E_PARAM_POINTER \
                              );
    } else {
#endif /* ETH_DEV_ERROR_DETECT */
        VersionInfoPtr->moduleID = (VAR(uint16, AUTOMATIC))ETH_MODULE_ID;
        VersionInfoPtr->vendorID = (VAR(uint16, AUTOMATIC))ETH_C_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (VAR(uint8, AUTOMATIC))ETH_C_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (VAR(uint8, AUTOMATIC))ETH_C_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (VAR(uint8, AUTOMATIC))ETH_C_SW_PATCH_VERSION;

#if STD_ON == ETH_DEV_ERROR_DETECT
    }

#endif /* ETH_DEV_ERROR_DETECT */
}
#endif

FUNC(void, ETH_CODE) Eth_MainFunction(VAR(void, AUTOMATIC))
{
    ;
}

/*
    The interface defined by autosar can only describe the phy of Clause22.
    Clause45 phy Write
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_Mdio_Write
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(uint8, AUTOMATIC) Device,
    VAR(uint32, AUTOMATIC) PhyReg,
    VAR(uint16, AUTOMATIC) data
)
{
    Std_ReturnType RetVal = E_OK;
#if STD_OFF == MDIO_DET_CHECK_BYPASS
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_WRITEMII_45);
#endif

    if (RetVal == E_OK) {
        if (mac_mdio_write(ETH_CFG_CTRL_REG_BASE(CtrlIdx), TrcvIdx, Device, PhyReg, data)) {
            RetVal = E_NOT_OK;
        }

    }

    return RetVal;
}
/*
    The interface defined by autosar can only describe the phy of Clause22.
    clause45 phy Read
*/
FUNC(uint16, ETH_CODE) Eth_Mdio_Read
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(uint8, AUTOMATIC) Device,
    VAR(uint32, AUTOMATIC) PhyReg
)
{
    sint32 data = 0;
    uint16 regval = 0;
    Std_ReturnType RetVal = E_OK;
#if STD_OFF == MDIO_DET_CHECK_BYPASS
    RetVal = Eth_Det_Check(CtrlIdx, ETH_SID_READMII_45);
#endif

    if (RetVal == E_OK) {
        data = mac_mdio_read(ETH_CFG_CTRL_REG_BASE(CtrlIdx), TrcvIdx, Device, PhyReg);

        if (data > 0) {
            regval = (uint16) data & 0xFFFF;
        } else {
#if STD_ON == ETH_DEV_ERROR_DETECT
            (void)Det_ReportError ( \
                                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                    ETH_SID_READMII_45, ETH_E_OTHER \
                                  );
#endif
        }
    }

    return regval;
}

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
