/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/

/** *****************************************************************************************************
 *  \file     Fls_Ip.h                                                                                 *
 *  \brief    This file contains interface header for FLS MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/26     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FLS_IP_H
#define FLS_IP_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#include <Fls_Bus.h>
#include "Fls_IpDrv.h"
#include "Fls_Cfg.h"
#include "RegHelper.h"
#include "Std_Types.h"
#include "__regs_base.h"

#define INDIRECT_READ_FLAG  (0)
#define INDIRECT_WRITE_FLAG (1)

#define FLS_IP_DLL_USE_OVERRIDE_MODE (1)

#define FLS_IP_NS_2_TICKS(hz, ns) (((hz) / 1000000u * (ns)) / 1000u)
#define FLS_IP_US_2_TICKS(hz, us) (((hz) / 1000u * (us)) / 1000u)
#define FLS_IP_MS_2_TICKS(hz, ms) ((hz) / 1000u * (ms))

#define FLS_IP_DELAY_US(x)                                      \
        {                                                  \
            volatile uint64 count = 20ULL * (uint64)(x); \
            while (count != 0ULL)                          \
                --count;                                   \
        }

typedef enum
{
    FLS_IP_DIRECT_ACCESS_MODE,
    FLS_IP_INDIRECT_ACCESS_MODE
} Fls_IpAccessModeType;

#define FLS_IP_C_LINE(x) ((uint32)(x))
#define FLS_IP_C_RATE(x) ((uint32)(x) << 2)
#define FLS_IP_C_SIZE(x) ((uint32)(x) << 3)
#define FLS_IP_C_EN      ((uint32)1u << 5)

#define FLS_IP_A_LINE(x) ((uint32)(x) << 8)
#define FLS_IP_A_RATE(x) ((uint32)(x) << 10)
#define FLS_IP_A_SIZE(x) ((uint32)(x) << 11)
#define FLS_IP_A_EN      ((uint32)1u << 13)

#define FLS_IP_GET_D_LINE(x) (((uint32)(x) >> 24) & 0x3u)
#define FLS_IP_D_LINE(x) ((uint32)(x) << 24)
#define FLS_IP_D_RATE(x) ((uint32)(x) << 26)
#define FLS_IP_D_EN      ((uint32)1u << 27)


/* Operation timeout value */
#define FLS_IP_IDLE_TIMEOUT_CYCLES (10000u)

#define FLS_IP_MODE_CTRL (0x0u)
#define FLS_IP_MODE_CTRL_SW_RST_LSB (31U)
#define FLS_IP_MODE_CTRL_BYTE_SWAP_LSB (12U)
#define FLS_IP_MODE_CTRL_SW_RST FLS_BIT(31)
#define FLS_IP_MODE_CTRL_IDLE FLS_BIT(30)
#define FLS_IP_MODE_CTRL_XIP FLS_BIT(9)
#define FLS_IP_MODE_CTRL_RX_MODE FLS_BIT(8)

#define FLS_IP_DEV_SIZE (0x4u)
#define FLS_IP_DEV_SIZE_DEV2_HYPER_RAM_EN FLS_BIT(17U)
#define FLS_IP_DEV_SIZE_DEV1_HYPER_RAM_EN FLS_BIT(16U)
#define FLS_IP_DEV_SIZE_DEV1_HYPER_RAM_EN_LSB (16U)
#define FLS_IP_DEV_SIZE_SIZE_LSB (8u)
#define FLS_IP_DEV_SIZE_SIZE_MASK (0x1Fu)

#define FLS_IP_INT_ST_FUC (0x10u)
#define FLS_IP_INT_ST_FUC_INDIRECT_DMA_RD_DONE FLS_BIT(10u)
#define FLS_IP_INT_ST_FUC_TX_FRE_EMPTY FLS_BIT(9u)
#define FLS_IP_INT_ST_FUC_RX_FRE_FULL FLS_BIT(8u)
#define FLS_IP_INT_ST_FUC_FIFO_LEVEL_TRIG (FLS_IP_INT_ST_FUC_RX_FRE_FULL | FLS_IP_INT_ST_FUC_TX_FRE_EMPTY)
#define FLS_IP_INT_ST_FUC_DIRECT_RD_DONE FLS_BIT(3u)
#define FLS_IP_INT_ST_FUC_DIRECT_WR_DONE FLS_BIT(2u)
#define FLS_IP_INT_ST_FUC_INDIRECT_RD_DONE FLS_BIT(1u)
#define FLS_IP_INT_ST_FUC_INDIRECT_WR_DONE FLS_BIT(0u)
#define FLS_IP_INT_ST_FUC_IND_COMP    \
         (FLS_IP_INT_ST_FUC_INDIRECT_DMA_RD_DONE | FLS_IP_INT_ST_FUC_INDIRECT_WR_DONE)


#define FLS_IP_INT_EN_FUC (0x14u)

#define FLS_IP_INT_ST_ERR (0x18u)

#define FLS_IP_INT_EN_ERR (0x1Cu)

#define FLS_IP_INT_EN_ERR_FUC (0x20u)

#define FLS_IP_DATA_INIEGRITY (0x30u)

#define FLS_IP_IO_FMUX1 (0x40u)

#define FLS_IP_IO_FMUX2 (0x44u)

#define FLS_IP_IO1_FMUX1 (0x48u)

#define FLS_IP_IO1_FMUX2 (0x4Cu)

#define FLS_IP_IO_CTRL (0x60u)
#define FLS_IP_IO_CTRL_SW_PAD_RSTN_LSB (1U)
#define FLS_IP_IO_CTRL_SW_PAD_RST_EN_LSB (0U)

#define FLS_IP_ADDR_OFFSET (0x70u)

#define FLS_IP_MISC (0x80u)
#define FLS_IP_MISC_CAPTURE_SEL_LSB (12U)
#define FLS_IP_MISC_INDIRECT_AXI_RD_EN FLS_BIT(11u)
#define FLS_IP_MISC_INDIRECT_AXI_WR_EN FLS_BIT(10u)
#define FLS_IP_MISC_INDIRECT_AXI_WR_EN_LSB (10U)
#define FLS_IP_MISC_RX_ENABLE_MODE_LSB (9U)
#define FLS_IP_MISC_IMMEDIATE_LSB (8U)

#define FLS_IP_AXI_CTRL (0x84u)
#define FLS_IP_TIMEOUT_THRE_LSB (0u)

#define FLS_IP_SCLK_CTRL (0xC0u)
#define FLS_IP_SCLK_CTRL_RX_SEL_MASK (3u)
#define FLS_IP_SCLK_CTRL_RX_SEL_LSB (2u)
#define FLS_IP_SCLK_CTRL_DLL_EN_LSB (1u)

#define FLS_IP_CS_CTRL (0xC4u)
#define FLS_IP_CS_CTRL_SEL_MASK (0xFu)
#define FLS_IP_CS_CTRL_HW_SEL_MASK (0x3u)
#define FLS_IP_CS_CTRL_HW_SEL_DEV1 (0x2u)
#define FLS_IP_CS_CTRL_HW_SEL_DEV2 (0x1u)
#define FLS_IP_CS_CTRL_HW_SEL_AUTO (0x3u)
#define FLS_IP_CS_CTRL_HW_SEL_LSB (27u)
#define FLS_IP_CS_CTRL_SW_SEL_MASK (0x3u)
#define FLS_IP_CS_CTRL_SW_SEL_DEV1 (0x2u)
#define FLS_IP_CS_CTRL_SW_SEL_DEV2 (0x1u)
#define FLS_IP_CS_CTRL_SW_SEL_LSB (25u)
#define FLS_IP_CS_CTRL_SW FLS_BIT(24)
#define FLS_IP_CS_CTRL_TIME_DELAY_MASK ((uint32)0xFu)
#define FLS_IP_CS_CTRL_TIME_SHSL_DELAY_MASK ((uint32)0x1Fu)
#define FLS_IP_CS_CTRL_TSLCH_LSB (16u)
#define FLS_IP_CS_CTRL_TSHSL_LSB (8u)
#define FLS_IP_CS_CTRL_TCHSH_LSB (0u)

#define FLS_IP_HYPERBUS_CTRL (0xD0u)
#define FLS_IP_HYPERBUS_CTRL_PROFILE20_EN_LSB (3U)
#define FLS_IP_HYPERBUS_CTRL_AM_LSB (2U)
#define FLS_IP_HYPERBUS_CTRL_AS_LSB (1U)
#define FLS_IP_HYPERBUS_CTRL_EN_LSB (0U)


#define FLS_IP_DLL_CTRL (0xE0u)
#define FLS_IP_DLL_CTRL_SLV_UPD_GATE_LSB (31U)
#define FLS_IP_DLL_CTRL_OVERRIDE_VAL_LSB (9U)
#define LS_IP_DLL_CTRL_OVERRIDE_ENABLE FLS_BIT(8U)

#define FLS_IP_STATUS (0xE4u)
#define FLS_IP_STATUS_SLV_LOCK FLS_BIT(16U)

#define FLS_IP_DLL1_CTRL (0xE8u)

#define FLS_IP_DLL1_STATUS (0xECu)

#define FLS_IP_DIRECT_RD_PH_CTRL (0x100u)
#define FLS_IP_DIRECT_WR_PH_CTRL (0x104u)
#define FLS_IP_DIRECT_DATA_DDR_RATE FLS_BIT(26)
#define FLS_IP_DIRECT_DATA_LINE_MASK (0x3u)
#define FLS_IP_DIRECT_DATA_LINE_LSB (24u)
#define FLS_IP_DIRECT_MODE_EN FLS_BIT(21)
#define FLS_IP_DIRECT_MODE_SIZE_MASK ((uint32)0x3u)
#define FLS_IP_DIRECT_MODE_SIZE_LSB (19u)
#define FLS_IP_DIRECT_MODE_DDR_RATE FLS_BIT(18)
#define FLS_IP_DIRECT_MODE_LINE_MASK (0x3u)
#define FLS_IP_DIRECT_MODE_LINE_LSB (16u)
#define FLS_IP_DIRECT_ADDR_SIZE_MASK (0x3u)
#define FLS_IP_DIRECT_ADDR_SIZE_LSB (11u)
#define FLS_IP_DIRECT_ADDR_DDR_RATE FLS_BIT(10)
#define FLS_IP_DIRECT_ADDR_LINE_MASK (0x3u)
#define FLS_IP_DIRECT_ADDR_LINE_LSB (8u)
#define FLS_IP_DIRECT_CMD_EN FLS_BIT(5)
#define FLS_IP_DIRECT_CMD_SIZE_MASK (0x3u)
#define FLS_IP_DIRECT_CMD_SIZE_LSB (3u)
#define FLS_IP_DIRECT_CMD_DDR_RATE FLS_BIT(2)
#define FLS_IP_DIRECT_CMD_LINE_MASK (0x3u)
#define FLS_IP_DIRECT_CMD_LINE_LSB (0u)

#define FLS_IP_DIRECT_C_CODE (0x114u)
#define FLS_IP_DIRECT_C_CODE_WCODE_LSB (16U)
#define FLS_IP_DIRECT_C_CODE_RCODE_LSB (0U)
#define FLS_IP_DIRECT_C_CODE_MASK (0xFFu)

#define FLS_IP_DIRECT_WREN (0x118u)
#define FLS_IP_DIRECT_WREN_CODE_LSB (16U)
#define FLS_IP_DIRECT_WREN_CODE (0x06UL)

#define FLS_IP_DIRECT_M_CODE (0x11Cu)

#define FLS_IP_DIRECT_D_CYC (0x120u)
#define FLS_IP_DIRECT_D_CYC_RD_LSB (0u)
#define FLS_IP_DIRECT_D_CYC_RD_MASK (0x1Fu)
#define FLS_IP_DIRECT_D_CYC_WR_LSB (8u)
#define FLS_IP_DIRECT_D_CYC_WR_MASK (0x1Fu)

#define FLS_IP_INDIRECT_WR_CTRL (0x200u)
#define FLS_IP_INDIRECT_WR_CTRL_W_TRIGGER FLS_BIT(0)

#define FLS_IP_INDIRECT_WR_PH_CTRL (0x204u)
#define FLS_IP_INDIRECT_RD_PH_CTRL (0x304u)
#define FLS_IP_INDIRECT_DATA_EN FLS_BIT(27)
#define FLS_IP_INDIRECT_DATA_DDR_RATE FLS_BIT(26)
#define FLS_IP_INDIRECT_DATA_LINE_MASK (0x3u)
#define FLS_IP_INDIRECT_DATA_LINE_LSB (24u)
#define FLS_IP_INDIRECT_ADDR_EN FLS_BIT(13)
#define FLS_IP_INDIRECT_ADDR_SIZE_MASK (0x3u)
#define FLS_IP_INDIRECT_ADDR_SIZE_LSB (11u)
#define FLS_IP_INDIRECT_ADDR_DDR_RATE FLS_BIT(10)
#define FLS_IP_INDIRECT_ADDR_LINE_MASK (0x3u)
#define FLS_IP_INDIRECT_ADDR_LINE_LSB (8u)
#define FLS_IP_INDIRECT_CMD_EN FLS_BIT(5)
#define FLS_IP_INDIRECT_CMD_SIZE_2_BYTES FLS_BIT(3u)
#define FLS_IP_INDIRECT_CMD_DDR_RATE FLS_BIT(2)
#define FLS_IP_INDIRECT_CMD_LINE_MASK (0x3u)
#define FLS_IP_INDIRECT_CMD_LINE_LSB (0u)

#define FLS_IP_INDIRECT_WR_CMD_CODE (0x208u)
#define FLS_IP_INDIRECT_WR_CMD_CODE_MASK (0xFFu)

#define FLS_IP_INDIRECT_WR_ADDR (0x20Cu)

#define FLS_IP_INDIRECT_WR_SIZE (0x210u)

#define FLS_IP_INDIRECT_WR_CYC (0x214u)

#define FLS_IP_INDIRECT_WR_DMA (0x220u)
#define FLS_IP_INDIRECT_RD_DMA (0x320u)
#define FLS_IP_INDIRECT_DMA_TRIG_WML_MASK (0x1Fu)
#define FLS_IP_INDIRECT_DMA_TRIG_WML_LSB (8u)
#define FLS_IP_INDIRECT_DMA_SW_ACK FLS_BIT(2)
#define FLS_IP_INDIRECT_DMA_SINGLE_EN FLS_BIT(1)
#define FLS_IP_INDIRECT_DMA_REQ_EN FLS_BIT(0)

#define FLS_IP_INDIRECT_TX_BUF (0x240u)
#define FLS_IP_INDIRECT_TX_BUF_ENTRY_MASK (0xFFu)
#define FLS_IP_INDIRECT_TX_BUF_ENTRY_LSB (16)
#define FLS_IP_INDIRECT_TX_BUF_LEVEL_MASK (0xFFu)
#define FLS_IP_INDIRECT_TX_BUF_LEVEL_LSB (8)
#define FLS_IP_INDIRECT_TX_BUF_FLUSH_LSB (0)


#define FLS_IP_INDIRECT_WDATA (0x280u)

#define FLS_IP_INDIRECT_RD_CTRL (0x300u)
#define FLS_IP_INDIRECT_RD_CTRL_R_TRIGGER FLS_BIT(0)

#define FLS_IP_INDIRECT_RD_CMD_CODE (0x308u)
#define FLS_IP_INDIRECT_RD_CMD_CODE_MASK (0xFFu)

#define FLS_IP_INDIRECT_RD_ADDR (0x30Cu)

#define FLS_IP_INDIRECT_RD_SIZE (0x310u)

#define FLS_IP_INDIRECT_RD_CYC (0x314u)
#define FLS_IP_INDIRECT_RD_CYC_MASK (0x1Fu)

#define FLS_IP_INDIRECT_RD_M_CODE (0x318u)

#define FLS_IP_INDIRECT_P_VALUE (0x330u)

#define FLS_IP_INDIRECT_P_MASK (0x334u)

#define FLS_IP_INDIRECT_P_TIME (0x338u)

#define FLS_IP_INDIRECT_RX_BUF (0x340u)
#define FLS_IP_INDIRECT_RX_BUF_ENTRY_MASK (0xFFu)
#define FLS_IP_INDIRECT_RX_BUF_ENTRY_LSB (16)
#define FLS_IP_INDIRECT_RX_BUF_LEVEL_MASK (0xFFu)
#define FLS_IP_INDIRECT_RX_BUF_LEVEL_LSB (8)

#define FLS_IP_INDIRECT_RDATA (0x380u)

#define FLS_IP_RBUF_HIT_CNTR (0x390u)

#define FLS_IP_RBUF_MISS_CNTR (0x394u)

#define FLS_IP_GROUP_MERGE (0x3A0u)

#define FLS_IP_RBUF_CTRL (0x400u)
#define FLS_IP_RBUF_CTRL_ENTRY_NUM_LSB (8U)
#define FLS_IP_RBUF_CTRL_PREFETCH_EN_LSB (16U)
#define FLS_IP_RBUF_CTRL_FLUSH_LSB (17U)

#define FLS_IP_GID_MASK (0x404u)

#define FLS_IP_GID_MATCH (0x408u)

#define FLS_IP_IMG_REGION_START (0x500u)

#define FLS_IP_IMG_REGION_END_ADDR (0x504u)

#define FLS_IP_IMG_REGION_CTRL (0x508u)

#define FLS_IP_IMG_REGION_NONCE0 (0x510u)

#define FLS_IP_IMG_REGION_NONCE1 (0x514u)

#define FLS_IP_IMG_REGION_NONCE2 (0x518u)

#define FLS_IP_IMG_REGION_NONCE3 (0x51Cu)

#define FLS_IP_IMG_RFD (0x590u)

#define FLS_IP_MON_OP_TIME (0x600u)

#define FLS_IP_CMD_MON_CTRL (0x610u)

#define FLS_IP_MON_REGION_START_ADDR (0x614u)

#define FLS_IP_MON_REGION_END_ADDR (0x618u)

#define FLS_IP_MON_CMD_VALUE (0x654u)

#define FLS_IP_MS_CTRL (0x800u)

#define FLS_IP_MS_WAIT_TIME (0x810u)

#define FLS_IP_MS_TIMEOUT (0x81Cu)

#define FLS_IP_MS_INT_ST (0x820u)

#define FLS_IP_MS_INT_EN (0x828u)

#define FLS_IP_INDR_WR_PTC (0x900u)

#define FLS_IP_INDR_RD_PTC (0x904u)

#define FLS_IP_DIRECT_WR_PTC (0x908u)

#define FLS_IP_DIRECT_RD_PTC (0x90Cu)

#define FLS_IP_INDR_WR_PTA (0x920u)

#define FLS_IP_INDR_WR_PTD (0x924u)

#define FLS_IP_INDR_RD_PTA (0x928u)

#define FLS_IP_INDR_RD_PTD (0x92Cu)

#define FLS_IP_DIRECT_WR_PTA (0x930u)

#define FLS_IP_DIRECT_WR_PTD (0x934u)

#define FLS_IP_DIRECT_RD_PTA (0x938u)

#define FLS_IP_DIRECT_RD_PTD (0x93Cu)

#define FLS_IP_ERR_INJ_EN (0xC00u)

#define FLS_IP_INJ_DATA (0xC04u)

#define FLS_IP_INJ_CODE (0xC08u)

#define FLS_IP_FATAL_ERR_ST (0xC20u)

#define FLS_IP_FATAL_ERR_EN (0xC28u)

#define FLS_IP_CORE_ERR_ST (0xC30u)

#define FLS_IP_AXI_UNC_ERR_ST (0xC34u)

#define FLS_IP_APB_UNC_ERR_ST (0xC38u)

#define FLS_IP_DMA_ERR_ST (0xC3Cu)

#define FLS_IP_COR_ERR_EN (0xC50u)

#define FLS_IP_AXI_UNC_ERR_EN (0xC54u)

#define FLS_IP_APB_UNC_ERR_EN (0xC58u)

#define FLS_IP_DMA_ERR_EN (0xC5Cu)

#define FLS_IP_CTRL_ERR_ST (0xC60u)

#define FLS_IP_CTRL_ERR_EN (0xC68u)

#define FLS_IP_LSP_ERR_INJ_EN (0x1000u)

#define FLS_IP_LSP_CMP_ERR_INJ (0x1004u)

#define FLS_IP_LSP_ERR_ST (0x1010u)

#define FLS_IP_LSP_ERR_EN (0x1014u)

#ifdef FLS_RFD_ENABLE_CNT
#define FLS_IP_RFD_START_ADDRESS  (0xF0u)
#define FLS_MAX_RFD_REGION     (4u)
#define FLS_IP_RFD_LENGTH         (64u)
typedef struct
{
    uint32 crc[FLS_MAX_RFD_REGION];
    uint8 rfd[FLS_MAX_RFD_REGION][FLS_IP_RFD_LENGTH];
} Fls_IpRfdRegionType;
#endif /* #ifdef FLS_RFD_ENABLE_CNT */

typedef struct
{
    boolean hyperbusMode;
    uint32 phCtrl;
    uint16 cmdCode;
    uint8 dummy;
} Fls_IpProtocolConfigType;

extern volatile int Fls_IpDebug;

void Fls_IpWritel(Fls_IpContextType *ipCtx, uint32 addr, uint32 value);
uint32 Fls_IpReadl(Fls_IpContextType *ipCtx, uint32 addr);
void Fls_IpWriteBits(Fls_IpContextType *ipCtx, uint32 addr,
                     uint8 startBit, uint8 width, uint32 val);
void Fls_IpPretransClean(Fls_BusHandleType *bus);

/** *****************************************************************************************************
 * \brief This function Initialise the IP's context.
 *
 * \verbatim
 * Syntax             : void Fls_IpContextInit(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initialise the IP's context
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void *Fls_IpContextInit(Fls_IpContextType *ipCtx);

/** *****************************************************************************************************
 * \brief This function Relevant register configuration before transfer.
 *
 * \verbatim
 * Syntax             : void Fls_IpBusSetup(
 *                          Fls_BusHandleType *bus, Fls_BusOpsType ops)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *                      ops - The type of operation
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Relevant register configuration before transfer
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpBusSetup(Fls_BusHandleType *bus, Fls_BusOpsType ops);

/** *****************************************************************************************************
 * \brief This function Configuring Transfer mode.
 *
 * \verbatim
 * Syntax             : void Fls_IpProtocolSetup(
 *                          Fls_BusHandleType *bus, Fls_BusCommandType *cmd,
 *                          Fls_IpAccessModeType accessMode, Fls_BusOpsType ops)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *                      cmd - operating command
 *                      accessMode - Is it direct mode
 *                      ops - The type of operation
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configuring Transfer mode Based on the input parameters
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpProtocolSetup(Fls_BusHandleType *bus, Fls_BusCommandType *cmd,
                         Fls_IpAccessModeType accessMode, Fls_BusOpsType ops);

/** *****************************************************************************************************
 * \brief This function Configuring the Interrupt Mask.
 *
 * \verbatim
 * Syntax             : void Fls_IpSetInterruptMask(
 *                          Fls_IpContextType *ipCtx, uint32 addr, uint32 mask)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      addr - Interrupt Register Address
 *                      mask - Interrupt Mask
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configuring the Interrupt Mask
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpSetInterruptMask(Fls_IpContextType *ipCtx, uint32 addr, uint32 mask);

/** *****************************************************************************************************
 * \brief This function Trigger indirect access.
 *
 * \verbatim
 * Syntax             : void Fls_IpIndirectTrigger(
 *                          Fls_IpContextType *ipCtx, uint32 addr
 *                          uint32 size, int flag)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller Context
 *                      addr - Address in flash memory
 *                      size - Buffer size
 *                      flag - Read or Write flag
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Trigger indirect access
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpIndirectTrigger(Fls_IpContextType *ipCtx, uint32 addr,
                           uint32 size, int flag);

/** *****************************************************************************************************
 * \brief This function Initialize the information about this operation.
 *
 * \verbatim
 * Syntax             : int Fls_Init(
 *                          Fls_BusHandleType *bus, Fls_BusOpsType opt,
 *                          Fls_AddressType addr, uint8 *readBuf,
 *                          const uint8 *writeBuf, Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *                      opt - The type of operation
 *                      addr - Address in flash memory
 *                      readBuf - Read buffer, alloc by user
 *                      writeBuf - Write buffer, alloc by user
 *                      size - Buffer size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initialize the information about this operation
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpSetupXfer(Fls_BusHandleType *bus, Fls_BusOpsType opt, Fls_AddressType addr,
                     uint8 *readBuf, const uint8 *writeBuf, Fls_LengthType size);

/** *****************************************************************************************************
 * \brief This function Clear the structure of the operation information.
 *
 * \verbatim
 * Syntax             : void Fls_IpReleaseXfer(
 *                          Fls_BusHandleType *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Clear the structure of the operation information
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpReleaseXfer(Fls_BusHandleType *bus);

/** *****************************************************************************************************
 * \brief This function Reads from the controller's FIFO.
 *
 * \verbatim
 * Syntax             : uint32 Fls_IpReadFifo(
 *                          Fls_IpContextType *ipCtx, uint8 *buf, Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      buf - Read buffer, alloc by user
 *                      size - Buffer size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The number of operation bytes
 *
 * Description        : Reads from the controller's FIFO
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
uint32 Fls_IpReadFifo(Fls_IpContextType *ipCtx, uint8 *buf,
                      Fls_LengthType size);

/** *****************************************************************************************************
 * \brief This function Writes to the controller's FIFO.
 *
 * \verbatim
 * Syntax             : uint32 Fls_IpWriteFifo(
 *                          Fls_IpContextType *ipCtx, uint8 *buf, Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      buf - Read buffer, alloc by user
 *                      size - Buffer size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The number of operation bytes
 *
 * Description        : Writes to the controller's FIFO.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
uint32 Fls_IpWriteFifo(Fls_IpContextType *ipCtx, const uint8 *buf,
                       Fls_LengthType size);

/** *****************************************************************************************************
 * \brief This function Polling receives data.
 *
 * \verbatim
 * Syntax             : int Fls_IpRxPolling(
 *                          Fls_BusHandleType *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Polling receives data until you get an error or finish
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
int Fls_IpRxPolling(Fls_BusHandleType *bus);

/** *****************************************************************************************************
 * \brief This function Polling sends data.
 *
 * \verbatim
 * Syntax             : int Fls_IpTxPolling(
 *                          Fls_BusHandleType *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Polling sends data until you get an error or finish
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
int Fls_IpTxPolling(Fls_BusHandleType *bus);

/** *****************************************************************************************************
 * \brief This function Configure the DMA mode of the controller.
 *
 * \verbatim
 * Syntax             : void Fls_IpDmaEnable(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure the DMA mode of the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpDmaEnable(Fls_IpContextType *ipCtx);

/** *****************************************************************************************************
 * \brief This function Disable DMA mode of the controller.
 *
 * \verbatim
 * Syntax             : void Fls_IpDmaEnable(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Disable DMA mode of the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpDmaDisable(Fls_IpContextType *ipCtx);

/** *****************************************************************************************************
 * \brief This function Configuring the DLL for the receive channel.
 *
 * \verbatim
 * Syntax             : void Fls_IpDllEnable(
 *                          Fls_IpContextType *ipCtx, int dllNum, uint32 value,
 *                          boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      dllNum - Channel number of DLL
 *                      value - The value of delay chain
 *                      enable - Switch of enable DLL
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configuring the DLL for the receive channel.
 *                      In xip mode, this func should to put into iram.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpDllEnable(Fls_IpContextType *ipCtx, int dllNum, uint32 value,
                     boolean enable);

#ifdef FLS_HYPERBUS_FLASH_CNT
/** *****************************************************************************************************
 * \brief This function Enable hyperram mode for the controller.
 *
 * \verbatim
 * Syntax             : void Fls_IpHyperramEnable(
 *                          Fls_BusHandleType *bus, uint8 cs,
 *                          uint8 readDummy, uint8 writeDummy)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *                      cs - Chip select number
 *                      readDummy - Read dummy cycles
 *                      writeDummy - Write dummy cycles
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Enable hyperram mode for the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpHyperramEnable(Fls_BusHandleType *bus, uint8 cs,
                          uint8 readDummy, uint8 writeDummy);
#endif

/** *****************************************************************************************************
 * \brief This function Flush the controller's cache.
 *
 * \verbatim
 * Syntax             : void Fls_IpPrefetchFlush(
 *                          Fls_IpContextType *ipCtx, uint32 channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      channel - The id of cache channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Flush the controller's cache
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpPrefetchFlush(Fls_IpContextType *ipCtx, uint32 channel);

/** *****************************************************************************************************
 * \brief This function Disable caching for all channels.
 *
 * \verbatim
 * Syntax             : void Fls_IpPrefetchDisable(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Disable caching for all channels.
 *                      In xip mode, this func should to put into iram.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpPrefetchDisable(Fls_IpContextType *ipCtx);

/** *****************************************************************************************************
 * \brief This function Open and initialise the cache for all channels.
 *
 * \verbatim
 * Syntax             : void Fls_IpPrefetchEnable(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Open and initialise the cache for all channels.
 *                      In xip mode, this func should to put into iram.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpPrefetchEnable(Fls_IpContextType *ipCtx);

#ifdef FLS_RFD_ENABLE_CNT
/** *****************************************************************************************************
 * \brief This function Enable the RFD area of the controller.
 *
 * \verbatim
 * Syntax             : int Fls_IpRfdEnable(
 *                          Fls_BusHandleType *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Enable the RFD area of the controller witch automatically identify
 *                      based on crc checksums
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
int Fls_IpRfdEnable(Fls_BusHandleType *bus);
#endif /* #ifdef FLS_RFD_ENABLE_CNT */

/** *****************************************************************************************************
 * \brief This function Wait for the status of a bit in the register until timeout.
 *
 * \verbatim
 * Syntax             : int Fls_IpWaitForBitTimes(
 *                          uint32 reg, const uint32 mask, boolean clear,
 *                          uint32 times)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : reg - Register address
 *                      mask - Mask of the wait value
 *                      clear - Inverted or not
 *                      times - Number of timeout cycles
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Timeout
 *
 * Description        : Wait for the status of a bit in the register until timeout
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
int Fls_IpWaitForBitTimes(uint32 reg, const uint32 mask, boolean clear, uint32 times);

/** *****************************************************************************************************
 * \brief This function Enable XIP mode for the controller.
 *
 * \verbatim
 * Syntax             : int Fls_IpXipEnable(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Enable XIP mode for the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpXipEnable(Fls_IpContextType *ipCtx);

/** *****************************************************************************************************
 * \brief This function Configure the controller to enter XIP mode.
 *
 * \verbatim
 * Syntax             : void Fls_IpXipEnter(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure the controller to enter XIP mode
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpXipEnter(Fls_IpContextType *ipCtx);

/** *****************************************************************************************************
 * \brief This function Wait for reception to complete until timeout.
 *
 * \verbatim
 * Syntax             : int Fls_IpRxComplete(
 *                          Fls_IpContextType *ipCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Wait for reception to complete until timeout
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
int Fls_IpTrigerComplete(Fls_IpContextType *ipCtx);

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */
#endif /* #if FLS_IP_H */

/* End of file */
