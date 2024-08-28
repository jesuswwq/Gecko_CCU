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
 * @file  Eth.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */

#ifndef ETH_H
#define ETH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "arch.h"
#include "Mcal.h"
#include "descs.h"
#include "ComStack_Types.h"
#include "Eth_PBCfg.h"
#include "Det.h"
#include "SchM_Eth.h"

#define mdelay(x)     Mcu_udelay(1000*(x))
/* Version and Check Begin */
/* Version Info Begin */
#define ETH_H_VENDOR_ID   0x8C
#define ETH_H_AR_RELEASE_MAJOR_VERSION    4
#define ETH_H_AR_RELEASE_MINOR_VERSION    3
#define ETH_H_AR_RELEASE_REVISION_VERSION 1
#define ETH_H_SW_MAJOR_VERSION    1
#define ETH_H_SW_MINOR_VERSION    0
#define ETH_H_SW_PATCH_VERSION    0
/* Version Info End */

#ifndef ETH_CFG_DEM_E_ACCESS_ID_OFFSET
#define ETH_CFG_DEM_E_ACCESS_ID_OFFSET  0
#endif

#define ETH_CFG_DEM_E_ACCESS(idx)  (idx+(ETH_CFG_DEM_E_ACCESS_ID_OFFSET))

#ifndef DEM_EVENT_STATUS_PREFAILED
#define DEM_EVENT_STATUS_PREFAILED (1U)
#endif

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((ETH_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (ETH_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (ETH_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Eth.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((ETH_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (ETH_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (ETH_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Eth.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((ETH_H_AR_RELEASE_MAJOR_VERSION != DET_H_AR_RELEASE_MAJOR_VERSION)\
    || (ETH_H_AR_RELEASE_MINOR_VERSION != DET_H_AR_RELEASE_MINOR_VERSION)\
    || (ETH_H_AR_RELEASE_REVISION_VERSION != DET_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Eth.h and Det.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((ETH_H_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)\
    || (ETH_H_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)\
    || (ETH_H_SW_PATCH_VERSION != DET_H_SW_PATCH_VERSION))
#error "Opps, Eth.h and Det.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/* Service IDs definition */

#define ETH_SID_INIT                    0x01
#define ETH_SID_SETCONTROLLERMODE       0x02
#define ETH_SID_GETCONTROLLERMODE       0x03
#define ETH_SID_GETPHYSADDR             0x08
#define ETH_SID_WRITEMII                0x05
#define ETH_SID_READMII                 0x06
#define ETH_SID_PROVIDETXBUFFER         0x09
#define ETH_SID_TRANSMIT                0x0A
#define ETH_SID_RECEIVE                 0x0B
#define ETH_SID_TXCONFIRMATION          0x0C
#define ETH_SID_GETVERSIONINFO          0x0D
#define ETH_SID_SETPHYSADDR             0x13
#define ETH_SID_UPDATEADDRFILTER        0x12
#define ETH_SID_GETCURRENTTIME          0x16
#define ETH_SID_ENABLEEGRESSTIMESTAMP   0x17
#define ETH_SID_GETEGRESSTIMESTAMP      0x18
#define ETH_SID_GETINGRESSTIMESTAMP     0x19
#define ETH_SID_GETCOUNTERVALUES        0x14
#define ETH_SID_GETRXSTATS              0x15
#define ETH_SID_GETTXSTATS              0x1C
#define ETH_SID_GETTXERRORCOUNTERVALUE  0x1D
#define ETH_SID_WRITEMII_45             0x1E
#define ETH_SID_READMII_45              0x1F

/* DET error codes */
#if STD_ON == ETH_DEV_ERROR_DETECT
/** @implements Eth_DetErrorIds_define */
enum {
    ETH_E_ACCESS = 0x01,
    ETH_E_ALIGNMENT,
    ETH_E_CRC,
    ETH_E_LATECOLLISION,
    ETH_E_MULTIPLECOLLISION,
    ETH_E_OVERSIZEFRAME,
    ETH_E_RX_FRAMES_LOST,
    ETH_E_SINGLECOLLISION,
    ETH_E_UNDERSIZEFRAME,
    ETH_E_INV_CTRL_IDX,
    ETH_E_UNINIT,
    ETH_E_PARAM_POINTER,
    ETH_E_INV_PARAM,
    ETH_E_INV_MODE,
    ETH_E_ACCESS_RES,
    ETH_E_OTHER

};
#endif

#define MAX_ETH_RING_LENTH (0x1 << MAX_RING_SIZE_POWER)

enum {
    DIR_TX = 0,
    DIR_RX,
    DIR_MAX
};
enum {
    MTL_MEM_POLICY_DEFAULT = 0,
    MTL_MEM_POLICY_MANUAL
};

#define  ETH_CFG_CTRL_PARM_PTR(CtrlIdx)    \
    (Eth_gCtrl[CtrlIdx]->Init_Param)

#define  ETH_CFG_CTRL_MTU(CtrlIdx)    \
    (Eth_gCtrl[CtrlIdx]->Init_Param->Mtu)

#define  ETH_CFG_CTRL_REG_BASE(CtrlIdx)    \
    ((uint32)Eth_gCtrl[CtrlIdx]->RegBase)
#define  ETH_CTRL_STATE(CtrlIdx)    \
    (Eth_gCtrl[CtrlIdx]->Controler_State)
#define  ETH_CTRL_MODE(CtrlIdx)    \
    (Eth_gCtrl[CtrlIdx]->Controler_Mode)
#define  ETH_CFG_CTRL_IRQ_NUM(CtrlIdx)    \
    ((uint32)Eth_gCtrl[CtrlIdx]->IrqNum)
#define  ETH_CFG_CTRL_TX_INT_MODE(CtrlIdx)    \
    ((uint32)Eth_gCtrl[CtrlIdx]->Init_Param->EnableTxInterrupt)

#define  ETH_CFG_CTRL_RX_INT_MODE(CtrlIdx)    \
    ((uint32)Eth_gCtrl[CtrlIdx]->Init_Param->EnableRxInterrupt)

#define  ETH_CFG_CTRL_MAC_ADDR_LOW(CtrlIdx)    \
    ((uint32)Eth_gCtrl[CtrlIdx]->Init_Param->MACAddrLow)

#define  ETH_CFG_CTRL_MAC_ADDR_HIGH(CtrlIdx)    \
    ((uint32)Eth_gCtrl[CtrlIdx]->Init_Param->MACAddrHigh)

#define  ETH_CTRL_LAST_CUR_DESC(CtrlIdx)    \
    (Eth_gCtrl[CtrlIdx]->LastCur)

#define  ETH_CTRL_FATAL_RETRY_NUM(CtrlIdx)    \
    (Eth_gCtrl[CtrlIdx]->RetryCnt)

#define  ETH_CTRL_FATAL_REINIT_NUM(CtrlIdx)    \
    (Eth_gCtrl[CtrlIdx]->ReinitCnt)

enum {
    LOCKED_DESC_TX_CONFIRM = 0x01,
    LOCKED_DESC_TX_DMA = 0x02,
    LOCKED_DESC_RX_DMA = 0x04,
    LOCKED_DESC_RX_USBED = 0x08
};

typedef struct {
    Eth_CntrlConfigType *Init_Param;
    Eth_ModeType    Controler_Mode;
    Eth_StateType   Controler_State;
    uint32          CtrlIdx;
    uint32          IrqNum;
    uint32          RegBase;
    uint32          LastCur;
    uint32          RetryCnt;
    uint32          ReinitCnt;
} Eth_Controller_t;

extern VAR(Eth_Controller_t*, ETH_VAR)     Eth_gCtrl[ETH_MAXCTRLS_SUPPORTED];

#define LOCKED_DESC_TX_MASK 0x03
#define LOCKED_DESC_RX_MASK 0x0C

#define  MAC_HEADER_LEN   14
#define  MAX_PRIORITY_LEVEL   (8U)

#define  MULTI_CH_RX_CH_IDX (0U)

typedef struct {
    uint32  desc;
    uint32  buf_idx;
    uint8  confirm;
} locked_desc_t;
//
enum loock_dir {
    LOCK_ALLOC = 0x01,
    LOCK_FREE = 0x02,
};
//
enum op_dir {
    OP_ALLOC = 0,
    OP_FREE = 0x02,
    OP_MAX,
};

typedef struct {

    uint32 front;
    uint32 rear;
    uint32 size;
} ring_t;


typedef struct {
    struct dma_desc  desc[MAX_ETH_RING_LENTH];
    ring_t ringcb;
} __attribute__((aligned(CACHE_LINE))) dma_desc_ring_t ;

typedef struct {
    locked_desc_t array[MAX_ETH_RING_LENTH];
    ring_t ringcb;
} __attribute__((aligned(CACHE_LINE))) locked_desc_ring_t ;

typedef struct {
    /* reg base */
    const uint32 RegBase;
    const uint32 IrqNum;
} Eth_HardWare_Info_t;

/*
*/
FUNC(void, ETH_CODE) Eth_Init
(
    P2CONST(Eth_ConfigType,
            AUTOMATIC, ETH_APPL_CONST) CfgPtr
);
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_SetControllerMode
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode
);
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetControllerMode
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_CONST) CtrlModePtr
);
/*
*/
FUNC(void, ETH_CODE) Eth_GetPhysAddr
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(uint8, AUTOMATIC, ETH_APPL_CONST) AddrPtr
);
/*
*/
FUNC(void, ETH_CODE) Eth_SetPhysAddr
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) AddrPtr
);
#if STD_ON == ETH_UPDATE_FILTER_API
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_UpdatePhysAddrFilter
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr,
    Eth_FilterActionType Action
);
#endif
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_WriteMii
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(uint8, AUTOMATIC) RegIdx,
    VAR(uint16, AUTOMATIC) RegVal
);
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_ReadMii
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(uint8, AUTOMATIC) RegIdx,
    P2VAR(uint16, AUTOMATIC, ETH_APPL_CONST) RegVal
);
#if STD_ON == ETH_GET_COUNTVAL_API
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetCounterValues
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_CONST) CounterPtr
);
#endif

#if STD_ON == ETH_GET_RXSTATS_API
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetRxStats
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_CONST) RxStats
);
#endif

#if STD_ON == ETH_GET_TXSTATS_API
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetTxStats
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_CONST) TxStats
);
#endif

#if STD_ON == ETH_GET_TXERRORCOUNT_API
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetTxErrorCounterValues
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_CONST) TxErrorCounterValues
);
#endif /* ETH_GET_TXERRORCOUNT_API */

#if STD_ON == ETH_GET_GLOBALTIME_API
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_GetCurrentTime
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_CONST) timeQualPtr,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) timeStampPtr
);
/*
*/
FUNC(void, ETH_CODE) Eth_EnableEgressTimeStamp
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_BufIdxType, AUTOMATIC) timeQualPtr
);
/*
*/
FUNC(void, ETH_CODE) Eth_GetEgressTimeStamp
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
    P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_CONST) timeQualPtr,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) timeStampPtr
);
/*
*/
FUNC(void, ETH_CODE) Eth_GetIngressTimeStamp
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2CONST(Eth_DataType, AUTOMATIC, ETH_APPL_CONST) DataPtr, \
    P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_CONST) timeQualPtr,
    P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) timeStampPtr
);
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
);
/*
*/
FUNC(Std_ReturnType, ETH_CODE) Eth_Transmit(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
    VAR(Eth_FrameType, AUTOMATIC) FrameType,
    VAR(boolean, AUTOMATIC) TxConfirmation,
    VAR(uint16, AUTOMATIC) LenByte,
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr
);
/*
*/
FUNC(void, ETH_CODE) Eth_Receive
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) FifoIdx,
    P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_CONST) RxStatusPtr
);
/*
*/
FUNC(void, ETH_CODE) Eth_TxConfirmation
(
    VAR(uint8, AUTOMATIC) CtrlIdx
);
/*
*/
#if STD_ON == ETH_GET_VERSION_INFO_API
FUNC(void, ETH_CODE) Eth_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETH_APPL_CONST) VersionInfoPtr
);
#endif
FUNC(void, ETH_CODE) Eth_MainFunction(VAR(void, AUTOMATIC));
/*

*/
FUNC(void, ETH_CODE) Eth_ReInitRxDesc
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    P2VAR(locked_desc_t, AUTOMATIC, ETH_APPL_CONST) locked_desc
);

FUNC(Std_ReturnType, ETH_CODE) Eth_Mdio_Write
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(uint8, AUTOMATIC) Device,
    VAR(uint32, AUTOMATIC) PhyReg,
    VAR(uint16, AUTOMATIC) data
);

FUNC(uint16, ETH_CODE) Eth_Mdio_Read
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(uint8, AUTOMATIC) Device,
    VAR(uint32, AUTOMATIC) PhyReg
);

FUNC(void, ETH_CODE) Eth_IrqInit
(
    VAR(uint8, AUTOMATIC) CtrlIdx
);

FUNC(void, ETH_CODE)  Eth_update_mmc_status
(
    VAR(uint8, AUTOMATIC) CtrlIdx
);

FUNC(void, ETH_CODE) Eth_Ctrl_Init_DMA
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(boolean, AUTOMATIC) Rx_irq,
    VAR(boolean, AUTOMATIC) Tx_irq
);
FUNC(void, ETH_CODE) Eth_Ctrl_Init_MTL
(
    VAR(uint8, AUTOMATIC) CtrlIdx
);
FUNC(void, ETH_CODE) Eth_Ctrl_Init_MAC
(
    VAR(uint8, AUTOMATIC) CtrlIdx,
    VAR(uint32, AUTOMATIC) Mtu,
    VAR(uint32, AUTOMATIC) Speed
);

#ifdef __cplusplus
}
#endif

#endif
