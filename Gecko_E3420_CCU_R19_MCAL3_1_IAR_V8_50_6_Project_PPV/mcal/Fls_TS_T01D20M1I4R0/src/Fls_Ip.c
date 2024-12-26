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
 * \file     Fls_Ip.c                                                                            *
 * \brief    AUTOSAR 4.3.1 MCAL fls Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/26     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#include "Fls_Ip.h"

/* PRQA S 0306,0310,0314,0316,0326,0488,1505,3305,3673,3678 EOF */

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#define FLS_IP_POLLING_INTERVAL_FACTOR 80
#define FLS_BUS_XFER_COMPLETE (0x1u)

#define FLS_IP_DLL_ENABLE_TIMEOUT_CYCLES (100000u)
#define FLS_IP_READ_DONE_TIMEOUT_CYCLES (10000u)
#define FLS_IP_WRITE_DONE_TIMEOUT_CYCLES (100u)
#define FLS_IP_KEY_READY_TIMEOUT_CYCLES (10000u)
#define FLS_IP_WAIT_TRIGGER_COMPLETE_TIMEOUT (100u)

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

volatile int Fls_IpDebug = 1;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

#ifdef FLS_RFD_ENABLE_CNT
/** CRC table for the CRC-32. The poly isPoly : 0x04C11DB7 */
static const unsigned int Fls_Crc32Table[256] =
{
    0x00000000U, 0x04C11DB7U, 0x09823B6EU, 0x0D4326D9U, 0x130476DCU, 0x17C56B6BU,
    0x1A864DB2U, 0x1E475005U, 0x2608EDB8U, 0x22C9F00FU, 0x2F8AD6D6U, 0x2B4BCB61U,
    0x350C9B64U, 0x31CD86D3U, 0x3C8EA00AU, 0x384FBDBDU, 0x4C11DB70U, 0x48D0C6C7U,
    0x4593E01EU, 0x4152FDA9U, 0x5F15ADACU, 0x5BD4B01BU, 0x569796C2U, 0x52568B75U,
    0x6A1936C8U, 0x6ED82B7FU, 0x639B0DA6U, 0x675A1011U, 0x791D4014U, 0x7DDC5DA3U,
    0x709F7B7AU, 0x745E66CDU, 0x9823B6E0U, 0x9CE2AB57U, 0x91A18D8EU, 0x95609039U,
    0x8B27C03CU, 0x8FE6DD8BU, 0x82A5FB52U, 0x8664E6E5U, 0xBE2B5B58U, 0xBAEA46EFU,
    0xB7A96036U, 0xB3687D81U, 0xAD2F2D84U, 0xA9EE3033U, 0xA4AD16EAU, 0xA06C0B5DU,
    0xD4326D90U, 0xD0F37027U, 0xDDB056FEU, 0xD9714B49U, 0xC7361B4CU, 0xC3F706FBU,
    0xCEB42022U, 0xCA753D95U, 0xF23A8028U, 0xF6FB9D9FU, 0xFBB8BB46U, 0xFF79A6F1U,
    0xE13EF6F4U, 0xE5FFEB43U, 0xE8BCCD9AU, 0xEC7DD02DU, 0x34867077U, 0x30476DC0U,
    0x3D044B19U, 0x39C556AEU, 0x278206ABU, 0x23431B1CU, 0x2E003DC5U, 0x2AC12072U,
    0x128E9DCFU, 0x164F8078U, 0x1B0CA6A1U, 0x1FCDBB16U, 0x018AEB13U, 0x054BF6A4U,
    0x0808D07DU, 0x0CC9CDCAU, 0x7897AB07U, 0x7C56B6B0U, 0x71159069U, 0x75D48DDEU,
    0x6B93DDDBU, 0x6F52C06CU, 0x6211E6B5U, 0x66D0FB02U, 0x5E9F46BFU, 0x5A5E5B08U,
    0x571D7DD1U, 0x53DC6066U, 0x4D9B3063U, 0x495A2DD4U, 0x44190B0DU, 0x40D816BAU,
    0xACA5C697U, 0xA864DB20U, 0xA527FDF9U, 0xA1E6E04EU, 0xBFA1B04BU, 0xBB60ADFCU,
    0xB6238B25U, 0xB2E29692U, 0x8AAD2B2FU, 0x8E6C3698U, 0x832F1041U, 0x87EE0DF6U,
    0x99A95DF3U, 0x9D684044U, 0x902B669DU, 0x94EA7B2AU, 0xE0B41DE7U, 0xE4750050U,
    0xE9362689U, 0xEDF73B3EU, 0xF3B06B3BU, 0xF771768CU, 0xFA325055U, 0xFEF34DE2U,
    0xC6BCF05FU, 0xC27DEDE8U, 0xCF3ECB31U, 0xCBFFD686U, 0xD5B88683U, 0xD1799B34U,
    0xDC3ABDEDU, 0xD8FBA05AU, 0x690CE0EEU, 0x6DCDFD59U, 0x608EDB80U, 0x644FC637U,
    0x7A089632U, 0x7EC98B85U, 0x738AAD5CU, 0x774BB0EBU, 0x4F040D56U, 0x4BC510E1U,
    0x46863638U, 0x42472B8FU, 0x5C007B8AU, 0x58C1663DU, 0x558240E4U, 0x51435D53U,
    0x251D3B9EU, 0x21DC2629U, 0x2C9F00F0U, 0x285E1D47U, 0x36194D42U, 0x32D850F5U,
    0x3F9B762CU, 0x3B5A6B9BU, 0x0315D626U, 0x07D4CB91U, 0x0A97ED48U, 0x0E56F0FFU,
    0x1011A0FAU, 0x14D0BD4DU, 0x19939B94U, 0x1D528623U, 0xF12F560EU, 0xF5EE4BB9U,
    0xF8AD6D60U, 0xFC6C70D7U, 0xE22B20D2U, 0xE6EA3D65U, 0xEBA91BBCU, 0xEF68060BU,
    0xD727BBB6U, 0xD3E6A601U, 0xDEA580D8U, 0xDA649D6FU, 0xC423CD6AU, 0xC0E2D0DDU,
    0xCDA1F604U, 0xC960EBB3U, 0xBD3E8D7EU, 0xB9FF90C9U, 0xB4BCB610U, 0xB07DABA7U,
    0xAE3AFBA2U, 0xAAFBE615U, 0xA7B8C0CCU, 0xA379DD7BU, 0x9B3660C6U, 0x9FF77D71U,
    0x92B45BA8U, 0x9675461FU, 0x8832161AU, 0x8CF30BADU, 0x81B02D74U, 0x857130C3U,
    0x5D8A9099U, 0x594B8D2EU, 0x5408ABF7U, 0x50C9B640U, 0x4E8EE645U, 0x4A4FFBF2U,
    0x470CDD2BU, 0x43CDC09CU, 0x7B827D21U, 0x7F436096U, 0x7200464FU, 0x76C15BF8U,
    0x68860BFDU, 0x6C47164AU, 0x61043093U, 0x65C52D24U, 0x119B4BE9U, 0x155A565EU,
    0x18197087U, 0x1CD86D30U, 0x029F3D35U, 0x065E2082U, 0x0B1D065BU, 0x0FDC1BECU,
    0x3793A651U, 0x3352BBE6U, 0x3E119D3FU, 0x3AD08088U, 0x2497D08DU, 0x2056CD3AU,
    0x2D15EBE3U, 0x29D4F654U, 0xC5A92679U, 0xC1683BCEU, 0xCC2B1D17U, 0xC8EA00A0U,
    0xD6AD50A5U, 0xD26C4D12U, 0xDF2F6BCBU, 0xDBEE767CU, 0xE3A1CBC1U, 0xE760D676U,
    0xEA23F0AFU, 0xEEE2ED18U, 0xF0A5BD1DU, 0xF464A0AAU, 0xF9278673U, 0xFDE69BC4U,
    0x89B8FD09U, 0x8D79E0BEU, 0x803AC667U, 0x84FBDBD0U, 0x9ABC8BD5U, 0x9E7D9662U,
    0x933EB0BBU, 0x97FFAD0CU, 0xAFB010B1U, 0xAB710D06U, 0xA6322BDFU, 0xA2F33668U,
    0xBCB4666DU, 0xB8757BDAU, 0xB5365D03U, 0xB1F740B4U
};
#endif /* #ifdef FLS_RFD_ENABLE_CNT */

#define FLS_STOP_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/** *****************************************************************************************************
 * \brief This function returns the log2 of the input value.
 *
 * \verbatim
 * Syntax             : uint8 Fls_IpLog2Uint(
 *                          uint64 val)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : val - Value to be calculated
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Calculation results of log2
 *
 * Description        : Returns the calculation result of log2 based on the input value
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static uint8 Fls_IpLog2Uint(uint64 val)
{
    uint8 ret = 0;
    uint64 valTemp = val;

    if (0u != (valTemp & (valTemp - 1U)))
    {
        FLS_DEBUG("val is not 2^n\n");
    }

    while (valTemp > 1ULL)
    {
        valTemp >>= 1ULL;
        ret++;
    }

    return ret;
}

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
int Fls_IpWaitForBitTimes(uint32 reg, const uint32 mask, boolean clear,
                          uint32 times)
{
    uint32 val;
    uint32 count = 0;
    int ret = -1;

    while (count < times)
    {
        val = readl(reg);

        if (TRUE == clear)
        {
            val = ~val;
        }

        val &= mask;

        if (val == mask)
        {
            ret = 0;
            break;
        }

        count++;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Get the amount of data received in the Buffer in the controller.
 *
 * \verbatim
 * Syntax             : uint32 Fls_IpGetReceiveBufLevel(
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
 * Return value       : The amount of data received
 *
 * Description        : Get the amount of data received in the Buffer in the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static uint32 Fls_IpGetReceiveBufLevel(Fls_IpContextType *ipCtx)
{
    uint32 reg = Fls_IpReadl(ipCtx, FLS_IP_INDIRECT_RX_BUF);
    reg >>= FLS_IP_INDIRECT_RX_BUF_ENTRY_LSB;
    return reg & FLS_IP_INDIRECT_RX_BUF_ENTRY_MASK;
}

/** *****************************************************************************************************
 * \brief This function Get the amount of data sent to the Buffer in the controller.
 *
 * \verbatim
 * Syntax             : uint32 Fls_IpGetWriteBufLevel(
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
 * Return value       : The amount of data received
 *
 * Description        : Get the amount of data sent to the Buffer in the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static uint32 Fls_IpGetWriteBufLevel(Fls_IpContextType *ipCtx)
{
    uint32 reg = Fls_IpReadl(ipCtx, FLS_IP_INDIRECT_TX_BUF);
    reg >>= FLS_IP_INDIRECT_TX_BUF_ENTRY_LSB;
    return reg & FLS_IP_INDIRECT_TX_BUF_ENTRY_MASK;
}

/** *****************************************************************************************************
 * \brief This function Reset Flash.
 *
 * \verbatim
 * Syntax             : void Fls_IpResetFlash(
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
 * Description        : Reset Flash using controller-controlled hardware IOs
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpResetFlash(Fls_IpContextType *ipCtx)
{
    /* rst enable */
    Fls_IpWriteBits(ipCtx, FLS_IP_IO_CTRL, FLS_IP_IO_CTRL_SW_PAD_RST_EN_LSB, 1u, 1U);

    /* rst start */
    Fls_IpWriteBits(ipCtx, FLS_IP_IO_CTRL, FLS_IP_IO_CTRL_SW_PAD_RSTN_LSB, 1u, 0U);
    Fls_IpDelayUs(1000u);

    /* rst end */
    Fls_IpWriteBits(ipCtx, FLS_IP_IO_CTRL, FLS_IP_IO_CTRL_SW_PAD_RSTN_LSB, 1u, 1U);
    Fls_IpDelayUs(1000u);

    /* rst disable */
    Fls_IpWriteBits(ipCtx, FLS_IP_IO_CTRL, FLS_IP_IO_CTRL_SW_PAD_RST_EN_LSB, 1u, 0U);
}

/** *****************************************************************************************************
 * \brief This function Configure the controller delay.
 *
 * \verbatim
 * Syntax             : void Fls_IpSetDelay(
 *                          Fls_BusHandleType *nor)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure the controller delay such as cs setup and hold times etc.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpSetDelay(Fls_BusHandleType *nor)
{
    uint32 reg, tslch, tshsl, tchsh;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;

    tslch = FLS_IP_NS_2_TICKS(ipCtx->refClkHz, 10U);
    tshsl = FLS_IP_NS_2_TICKS(ipCtx->refClkHz, 30U);
    tchsh = FLS_IP_NS_2_TICKS(ipCtx->refClkHz, 10U);
    tchsh = (tchsh >= 3U) ? tchsh : 3U;

    reg = Fls_IpReadl(ipCtx, FLS_IP_CS_CTRL);
    reg &= ~(FLS_IP_CS_CTRL_TIME_DELAY_MASK << FLS_IP_CS_CTRL_TSLCH_LSB);
    reg |= (uint32)(tslch & FLS_IP_CS_CTRL_TIME_DELAY_MASK) << FLS_IP_CS_CTRL_TSLCH_LSB;

    reg &= ~(FLS_IP_CS_CTRL_TIME_SHSL_DELAY_MASK << FLS_IP_CS_CTRL_TSHSL_LSB);
    reg |= (uint32)(tshsl & FLS_IP_CS_CTRL_TIME_SHSL_DELAY_MASK) << FLS_IP_CS_CTRL_TSHSL_LSB;

#if (FLS_IP_CS_CTRL_TCHSH_LSB > 0U)
    reg &= ~(FLS_IP_CS_CTRL_TIME_DELAY_MASK << FLS_IP_CS_CTRL_TCHSH_LSB);
    reg |= (uint32)(tchsh & FLS_IP_CS_CTRL_TIME_DELAY_MASK) << FLS_IP_CS_CTRL_TCHSH_LSB;
#else
    reg &= ~(FLS_IP_CS_CTRL_TIME_DELAY_MASK);
    reg |= (tchsh & FLS_IP_CS_CTRL_TIME_DELAY_MASK);
#endif /* #if (FLS_IP_CS_CTRL_TCHSH_LSB > 0U) */
    Fls_IpWritel(ipCtx, FLS_IP_CS_CTRL, reg);
}

/** *****************************************************************************************************
 * \brief This function Wait for control to become idle until timeout.
 *
 * \verbatim
 * Syntax             : int Fls_IpWaitIdle(
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
 * Return value       : 0 - Controlle has been idle
 *                     !0 - Timeout
 *
 * Description        : Wait for control to become idle until timeout.In xip mode,
 *                      this func should to put into iram.
 * \endverbatim
 * Traceability       : SWSR_FLS_166
 *******************************************************************************************************/
static int Fls_IpWaitIdle(Fls_IpContextType *ipCtx)
{
    uint32 idle_latency_cycles = 4;
    uint32 idle_count = 0;
    uint32 polling_cycles;
    int ret = -1;
    uint32 reg;

    for (polling_cycles = 0; polling_cycles <= FLS_IP_IDLE_TIMEOUT_CYCLES; polling_cycles++)
    {
        reg = Fls_IpReadl(ipCtx, FLS_IP_MODE_CTRL);

        if (0U != (reg & FLS_IP_MODE_CTRL_IDLE))
        {
            idle_count++;
        }
        else
        {
            idle_count = 0;
        }

        /* When IDLE bit asserted, need wait 4 cycyles of refClkHz. */
        if (idle_count >= idle_latency_cycles)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

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
void Fls_IpXipEnable(Fls_IpContextType *ipCtx)
{
    uint32 reg;
    uint32 readDummy;

    /* Enable xip mode */
    reg = Fls_IpReadl(ipCtx, FLS_IP_MODE_CTRL);
    reg |= FLS_IP_MODE_CTRL_XIP;
    Fls_IpWritel(ipCtx, FLS_IP_MODE_CTRL, reg);

    Fls_IpWritel(ipCtx, FLS_IP_DIRECT_M_CODE, 0U);

    reg = Fls_IpReadl(ipCtx, FLS_IP_DIRECT_RD_PH_CTRL);
    /* Set read mode phase 1 byte */
    reg &= ~(FLS_IP_DIRECT_MODE_SIZE_MASK << FLS_IP_DIRECT_MODE_SIZE_LSB);
    /* Xip mode bit sent by 8 lines */
    reg |= ((uint32)0x3u) << FLS_IP_DIRECT_MODE_LINE_LSB;
    /* Enable read mode phase */
    reg |= FLS_IP_DIRECT_MODE_EN;
    Fls_IpWritel(ipCtx, FLS_IP_DIRECT_RD_PH_CTRL, reg);

    /* Read dummy cycle - 1 */
    reg = Fls_IpReadl(ipCtx, FLS_IP_DIRECT_D_CYC);
    readDummy = reg & FLS_IP_DIRECT_D_CYC_RD_MASK;
    reg &= ~(FLS_IP_DIRECT_D_CYC_RD_MASK);
    reg |= readDummy - 1U;
    Fls_IpWritel(ipCtx, FLS_IP_DIRECT_D_CYC, reg);
}

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
void Fls_IpXipEnter(Fls_IpContextType *ipCtx)
{
    uint32 reg;

    /* Disable direct read cmd phase */
    reg = Fls_IpReadl(ipCtx, FLS_IP_DIRECT_RD_PH_CTRL);
    reg &= ~FLS_IP_DIRECT_CMD_EN;
    Fls_IpWritel(ipCtx, FLS_IP_DIRECT_RD_PH_CTRL, reg);
}

#if FLS_IP_USE_DMA
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
void Fls_IpDmaEnable(Fls_IpContextType *ipCtx)
{
    uint32 reg;

    reg = Fls_IpReadl(ipCtx, FLS_IP_INDIRECT_WR_DMA);
    reg |= FLS_IP_INDIRECT_DMA_SINGLE_EN | FLS_IP_INDIRECT_DMA_REQ_EN;
    Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_DMA, reg);

    reg = Fls_IpReadl(ipCtx, FLS_IP_INDIRECT_RD_DMA);
    reg |= FLS_IP_INDIRECT_DMA_SINGLE_EN | FLS_IP_INDIRECT_DMA_REQ_EN;
    Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_DMA, reg);
}

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
void Fls_IpDmaDisable(Fls_IpContextType *ipCtx)
{
    Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_DMA, 0U);
    Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_DMA, 0U);
}
#endif /* #if FLS_IP_USE_DMA */

/** *****************************************************************************************************
 * \brief This function Configure the RX mode of the controller.
 *
 * \verbatim
 * Syntax             : void Fls_IpRxModeConfig(
 *                          Fls_IpContextType *ipCtx, uint32 mode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      mode - RX mode
 *                              0x0: internal sclk
 *                              0x1: sclk loopback
 *                              0x2: DQS
 *                              0x3: IO loopback dummy DQS
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure the RX mode of the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpRxModeConfig(Fls_IpContextType *ipCtx, uint32 mode)
{
    uint32 reg;

    reg = Fls_IpReadl(ipCtx, FLS_IP_SCLK_CTRL);
    reg &= ~(FLS_IP_SCLK_CTRL_RX_SEL_MASK << FLS_IP_SCLK_CTRL_RX_SEL_LSB);
    reg |= mode << FLS_IP_SCLK_CTRL_RX_SEL_LSB;
    Fls_IpWritel(ipCtx, FLS_IP_SCLK_CTRL, reg);
}

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
                     boolean enable)
{
    uint32 reg;
    uint32 addr;

    addr = (1 == dllNum) ? FLS_IP_DLL1_CTRL : FLS_IP_DLL_CTRL;

    if (TRUE == enable)
    {
        Fls_IpWritel(ipCtx, addr, 0u);
#ifdef FLS_IP_DLL_USE_OVERRIDE_MODE
        reg = value << FLS_IP_DLL_CTRL_OVERRIDE_VAL_LSB;
        Fls_IpWritel(ipCtx, addr, reg);
        reg |= LS_IP_DLL_CTRL_OVERRIDE_ENABLE;
        Fls_IpWritel(ipCtx, addr, reg);
#else
        reg = value << 1;
        Fls_IpWritel(ipCtx, addr, reg);
        reg |= FLS_BIT(0);
        Fls_IpWritel(ipCtx, addr, reg);

        ret = Fls_IpWaitForBitTimes(ipCtx->apbBase + addr + 4U, FLS_IP_STATUS_SLV_LOCK, FALSE,
                                    FLS_IP_DLL_ENABLE_TIMEOUT_CYCLES);

        if (ret)
        {
            FLS_DEBUG("dll enable err\r\n");
        }

#ifdef SEMIDRIVE_E3_SERIES
        /* workround: XSPI DLL slave chain update should be gated during flash read operation.
            otherwise, there will be DQS (read strobe) glitch and read data will be wrong. */
        Fls_IpWriteBits(ipCtx, addr, FLS_IP_DLL_CTRL_SLV_UPD_GATE_LSB, 1U, 1U);
#endif /* #ifdef SEMIDRIVE_E3_SERIES */
#endif /* #ifdef FLS_IP_DLL_USE_OVERRIDE_MODE */
    }

    Fls_IpWriteBits(ipCtx, FLS_IP_MODE_CTRL, FLS_IP_MODE_CTRL_SW_RST_LSB, 1u, 1U);
    Fls_IpDelayUs(1);
    Fls_IpWriteBits(ipCtx, FLS_IP_MODE_CTRL, FLS_IP_MODE_CTRL_SW_RST_LSB, 1u, 0U);
    (void) Fls_IpWaitIdle(ipCtx);

    /* set dll_en */
    Fls_IpWriteBits(ipCtx, FLS_IP_SCLK_CTRL, FLS_IP_SCLK_CTRL_DLL_EN_LSB, 1u,
                    (TRUE == enable) ? 1U : 0U);
}

/** *****************************************************************************************************
 * \brief This function Configuring the Controller's Cache.
 *
 * \verbatim
 * Syntax             : void Fls_IpPrefetchConfig(
 *                          Fls_IpContextType *ipCtx, uint32 channel,
 *                          uint16 gidMask, uint16 gidMatch,
 *                          uint8 blockNum, uint16 groupNum)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      channel - The id of cache channel
 *                      gidMask - The group id mask
 *                      gidMatch - The match value of group id
 *                      blockNum - Block size(Multiply by 64B) for each enters
 *                      groupNum - Enter number
 *
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configuring the Controller's Cache
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpPrefetchConfig(Fls_IpContextType *ipCtx, uint32 channel,
                                 uint16 gidMask, uint16 gidMatch,
                                 uint8 blockNum, uint16 groupNum)
{
    uint32 reg;

    /* Entry size is 8 blocks */
    reg = blockNum;
    reg |= (uint32)groupNum << FLS_IP_RBUF_CTRL_ENTRY_NUM_LSB;
    reg |= 1UL << FLS_IP_RBUF_CTRL_PREFETCH_EN_LSB;
    Fls_IpWritel(ipCtx, FLS_IP_RBUF_CTRL + (0x10U * channel), reg);
    Fls_IpWritel(ipCtx, FLS_IP_GID_MASK + (0x10U * channel), gidMask);
    Fls_IpWritel(ipCtx, FLS_IP_GID_MATCH + (0x10U * channel), gidMatch);
}

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
void Fls_IpPrefetchFlush(Fls_IpContextType *ipCtx, uint32 channel)
{

    Fls_IpWriteBits(ipCtx, FLS_IP_RBUF_CTRL + (0x10U * channel), FLS_IP_RBUF_CTRL_FLUSH_LSB, 1U, 1U);
    Fls_IpWriteBits(ipCtx, FLS_IP_RBUF_CTRL + (0x10U * channel), FLS_IP_RBUF_CTRL_FLUSH_LSB, 1U, 0U);
}

/** *****************************************************************************************************
 * \brief This function Clears the cache configuration for the specified channel.
 *
 * \verbatim
 * Syntax             : void Fls_IpPrefetchClear(
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
 * Description        : Clears the cache configuration for the specified channel
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpPrefetchClear(Fls_IpContextType *ipCtx, uint32 channel)
{
    Fls_IpWritel(ipCtx, FLS_IP_RBUF_CTRL + (0x10U * channel), 0u);
    Fls_IpWritel(ipCtx, FLS_IP_GID_MASK + (0x10U * channel), 0u);
    Fls_IpWritel(ipCtx, FLS_IP_GID_MATCH + (0x10U * channel), 0u);
}

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
void Fls_IpPrefetchDisable(Fls_IpContextType *ipCtx)
{
    Fls_IpPrefetchClear(ipCtx, 0u);
    Fls_IpPrefetchClear(ipCtx, 1u);
    Fls_IpPrefetchClear(ipCtx, 2u);
    Fls_IpPrefetchClear(ipCtx, 3u);
    Fls_IpPrefetchClear(ipCtx, 4u);
    Fls_IpPrefetchClear(ipCtx, 5u);
    Fls_IpPrefetchClear(ipCtx, 6u);
    Fls_IpPrefetchClear(ipCtx, 7u);
    Fls_IpWritel(ipCtx, FLS_IP_GROUP_MERGE, 0U);
}

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
void Fls_IpPrefetchEnable(Fls_IpContextType *ipCtx)
{
    Fls_IpWritel(ipCtx, FLS_IP_AXI_CTRL, FLS_BIT(25));

#ifndef FLS_IP_PERFORMANCE_FIRST

    Fls_IpPrefetchConfig(ipCtx, 0u, 0x0000u, 0x000u, 2u, 4u);
    Fls_IpPrefetchConfig(ipCtx, 1u, 0xff00u, 0x000u, 2u, 4u);
    Fls_IpPrefetchConfig(ipCtx, 2u, 0xff00u, 0x100u, 2u, 4u);
    Fls_IpPrefetchConfig(ipCtx, 3u, 0xff00u, 0x200u, 2u, 4u);
    Fls_IpPrefetchConfig(ipCtx, 4u, 0xff00u, 0x300u, 2u, 4u);
    Fls_IpPrefetchConfig(ipCtx, 5u, 0xff00u, 0x400u, 2u, 4u);
    Fls_IpPrefetchConfig(ipCtx, 6u, 0xff00u, 0x500u, 8u, 1u);
    Fls_IpPrefetchConfig(ipCtx, 7u, 0xff00u, 0x800u, 8u, 1u);
#else
    Fls_IpPrefetchConfig(ipCtx, 0u, 0x0000u, 0x000u, 8u, 4u); /* others */
    Fls_IpPrefetchConfig(ipCtx, 1u, 0xff00u, 0x000u, 8u, 4u); /* sf core */

#endif /* #ifndef FLS_IP_PERFORMANCE_FIRST */
    /* merge group 0-1 */
    Fls_IpWritel(ipCtx, FLS_IP_GROUP_MERGE, 1u);
}

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
void *Fls_IpContextInit(Fls_IpContextType *ipCtx)
{
    Fls_IpContextType *ptrCtx = NULL_PTR;
    /* initialize the current cs for no one */
    ipCtx->currentCs = 0xff;

#ifdef SEMIDRIVE_E3_LITE_SERIES
    ipCtx->fifoDepth = 48;
#else
    ipCtx->fifoDepth = 16;
#endif /* #ifdef SEMIDRIVE_E3_LITE_SERIES */
    ipCtx->fifoWidth = 4u;
    ipCtx->fifoSize = ipCtx->fifoDepth * ipCtx->fifoWidth;

    if (TRUE == ipCtx->useRomConfig)
    {
        ptrCtx = ipCtx;
    }
    else if (0 != Fls_IpWaitIdle(ipCtx))
    {
        FLS_DEBUG("%s: wait idle err.", __FUNCTION__);
    }
    else
    {
        /* Use rx mode by pop data by deafult */
        Fls_IpWritel(ipCtx, FLS_IP_MODE_CTRL, FLS_IP_MODE_CTRL_RX_MODE);

        if (TRUE == ipCtx->prefetchEnable)
        {
            Fls_IpPrefetchEnable(ipCtx);
        }
        else
        {
            Fls_IpPrefetchDisable(ipCtx);
        }

        /* Set AXI access timeout threshold */
        Fls_IpWriteBits(ipCtx, FLS_IP_AXI_CTRL, FLS_IP_TIMEOUT_THRE_LSB, 24U,
                        FLS_IP_MS_2_TICKS(ipCtx->refClkHz, 5U));

#ifdef FLS_IP_INDIRECT_AXI_EN
        /* indirect wr/rd enable */
        Fls_IpWriteBits(ipCtx, FLS_IP_MISC, FLS_IP_MISC_INDIRECT_AXI_WR_EN_LSB, 2U, 0x3U);
        Fls_IpReadl(ipCtx, FLS_IP_MISC);
#endif /* #ifdef FLS_IP_INDIRECT_AXI_EN */

        /* Set capture enable select to 7 clk period */
        Fls_IpWriteBits(ipCtx, FLS_IP_MISC, FLS_IP_MISC_CAPTURE_SEL_LSB, 3U, 0x5U);

        /* Set immediate=0, Turnaround when half of dummy */
        Fls_IpWriteBits(ipCtx, FLS_IP_MISC, FLS_IP_MISC_IMMEDIATE_LSB, 1U, 0u);

        Fls_IpResetFlash(ipCtx);

        /* rx_mode use internal sclk by default */
        Fls_IpRxModeConfig(ipCtx, 0x0);

        Fls_IpDllEnable(ipCtx, 0, 7u, TRUE);
        Fls_IpDllEnable(ipCtx, 1, 4u, TRUE);
        ptrCtx = ipCtx;
    }

    return (void *)ptrCtx;
}

/** *****************************************************************************************************
 * \brief This function Copy data from memort to flash  by one byte.
 *
 * \verbatim
 * Syntax             : void Fls_IpReadsb(
 *                          uint8 *addr, uint8 *data, uint32 len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : addr - Source address
 *                      data - Target address
 *                      len - Data length in bytes
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Copy data from memory to memory  by byte
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpReadsb(uint8 *addr, uint8 *data, uint32 len)
{
    uint32 lenTemp = len;
    uint8 *ptrAddr = addr;
    uint8 *ptrData = data;

    while (lenTemp != 0u)
    {
        *ptrData = readb(ptrAddr);
        lenTemp--;
        ptrAddr++;
        ptrData++;
    }
}

/** *****************************************************************************************************
 * \brief This function Copy data from memort to flash by four byte.
 *
 * \verbatim
 * Syntax             : void Fls_IpReadsl(
 *                          uint32 *addr, uint32 *data, uint32 len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : addr - Source address
 *                      data - Target address
 *                      len - Data length in bytes
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Copy data from memort to flash  by four bytes
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpReadsl(uint32 *addr, uint32 *data, uint32 len)
{
    uint32 lenTemp = len;
    uint32 *ptrData = data;

    while (lenTemp != 0u)
    {
        *ptrData = readl(addr);
        lenTemp--;
        ptrData++;
    }
}

/** *****************************************************************************************************
 * \brief This function write data to memory by four byte.
 *
 * \verbatim
 * Syntax             : void Fls_IpWritesl(
 *                          uint32 *addr, uint32 *data, uint32 len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : addr - Source address
 *                      data - Target address
 *                      len - Data length in bytes
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Write data to memory by four bytes
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpWritesl(uint32 *addr, uint32 const *data, uint32 len)
{
    uint32 lenTemp = len;
    uint32 const *ptrData = data;

    while (lenTemp != 0u)
    {
        writel(*ptrData, (uint32)addr);
        ptrData++;
        lenTemp--;
    }
}

/** *****************************************************************************************************
 * \brief This function Configuring Flash size in the controller.
 *
 * \verbatim
 * Syntax             : void Fls_IpSetSize(
 *                          Fls_BusHandleType *nor)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configuring Flash size in the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpSetSize(Fls_BusHandleType *nor)
{
    uint8 size;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    uint32 reg = Fls_IpReadl(ipCtx, FLS_IP_DEV_SIZE) >> (nor->cs * FLS_IP_DEV_SIZE_SIZE_LSB);

    size = Fls_IpLog2Uint(nor->info.size) & FLS_IP_DEV_SIZE_SIZE_MASK;

    if ((0U != size) && (size != (reg & FLS_IP_DEV_SIZE_SIZE_MASK)))
    {
        Fls_IpWriteBits(ipCtx, FLS_IP_DEV_SIZE, nor->cs * FLS_IP_DEV_SIZE_SIZE_LSB, 5U, size);
        FLS_DEBUG("xspi dev size reg = 0x%x\n", Fls_IpReadl(ipCtx, FLS_IP_DEV_SIZE));
    }
}

/** *****************************************************************************************************
 * \brief This function Configuring Transfer mode dependent register.
 *
 * \verbatim
 * Syntax             : void Fls_IpProtocolConfig(
 *                          Fls_IpContextType *ipCtx, Fls_IpAccessModeType accessMode,
 *                          Fls_BusOpsType ops, Fls_IpProtocolConfigType *config)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      accessMode - Is it direct mode
 *                      ops - The type of operation
 *                      config - Pointer of register configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configuring Transfer mode dependent register, such as opcode, dummy etc.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpProtocolConfig(Fls_IpContextType *ipCtx, Fls_IpAccessModeType accessMode,
                                 Fls_BusOpsType ops, Fls_IpProtocolConfigType *config)
{
    /* Turnaround when dummy phase complete */
    if ((FLS_BUS_OPS_READ == ops) && (0u == config->dummy) && (0u != FLS_IP_GET_D_LINE(config->phCtrl)))
    {
        FLS_DEBUG("%s(%d, %d, 0x%x): dummy==0 err.\r\n", __FUNCTION__, accessMode, ops, config->phCtrl);
    }

    if (FLS_IP_DIRECT_ACCESS_MODE == accessMode)
    {
        if (FLS_BUS_OPS_WRITE == ops)
        {
            Fls_IpWritel(ipCtx, FLS_IP_DIRECT_WR_PH_CTRL, config->phCtrl);
            Fls_IpWriteBits(ipCtx, FLS_IP_DIRECT_C_CODE, FLS_IP_DIRECT_C_CODE_WCODE_LSB,
                            16U, config->cmdCode);
            Fls_IpWriteBits(ipCtx, FLS_IP_DIRECT_D_CYC, FLS_IP_DIRECT_D_CYC_WR_LSB,
                            5U, config->dummy);

            /* Hyperbus mode not need write enable */
            if (FALSE == config->hyperbusMode)
            {
                Fls_IpWritel(ipCtx, FLS_IP_DIRECT_WREN,
                             (FLS_IP_DIRECT_WREN_CODE << FLS_IP_DIRECT_WREN_CODE_LSB) | (uint32)1U);
            }
        }
        else if (FLS_BUS_OPS_READ == ops)
        {
            Fls_IpWritel(ipCtx, FLS_IP_DIRECT_RD_PH_CTRL, config->phCtrl);
            Fls_IpWriteBits(ipCtx, FLS_IP_DIRECT_C_CODE, FLS_IP_DIRECT_C_CODE_RCODE_LSB,
                            16U, config->cmdCode);
            Fls_IpWriteBits(ipCtx, FLS_IP_DIRECT_D_CYC, FLS_IP_DIRECT_D_CYC_RD_LSB,
                            5U, config->dummy);
        }
        else
        {
            FLS_DEBUG("%s: set direct mode err. %d\n", __FUNCTION__,
                      ops);
        }
    }
    else
    {
        if (FLS_BUS_OPS_WRITE == ops)
        {
            Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_PH_CTRL, config->phCtrl);
            Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_CMD_CODE, config->cmdCode);
            Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_CYC, config->dummy);
        }
        else if (FLS_BUS_OPS_READ == ops)
        {
            Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_PH_CTRL, config->phCtrl);
            Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_CMD_CODE, config->cmdCode);
            Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_CYC, config->dummy);
        }
        else
        {
            FLS_DEBUG("%s: set indirect mode err. %d\n",
                      __FUNCTION__, ops);
        }
    }
}

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
                         Fls_IpAccessModeType accessMode,
                         Fls_BusOpsType ops)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)bus->host->privData;
    Fls_IpProtocolConfigType config =
    {
        .hyperbusMode = bus->hyperbusMode,
        .phCtrl = 0,
        .cmdCode = 0,
        .dummy = 0,
    };

    if (FALSE == bus->hyperbusMode)
    {
        config.phCtrl |= FLS_IP_C_EN | FLS_IP_C_SIZE(0u);
    }

    if ((TRUE == bus->octalDtrEnable) || (TRUE == bus->hyperbusMode))
    {
        config.phCtrl |= FLS_IP_C_RATE(1u) | FLS_IP_A_RATE(1u) | FLS_IP_D_RATE(1u) |
                         FLS_IP_C_SIZE(1u) | FLS_IP_A_SIZE(3u);
    }

    if (bus->xferInfoBottom.size > 0U)
    {
        config.phCtrl |= FLS_IP_D_EN;
    }

    if (NULL_PTR != cmd)
    {
        config.dummy = cmd->dummy;
        config.phCtrl |= FLS_IP_C_LINE(cmd->instType) | FLS_IP_A_LINE(cmd->instType) |
                         FLS_IP_D_LINE(cmd->instType);
        config.cmdCode = cmd->opcode;

        if (0U != cmd->addrBytes)
        {
            config.phCtrl |= FLS_IP_A_EN | FLS_IP_A_SIZE((uint32)cmd->addrBytes - 1UL);
        }
    }
    else
    {
        if (0U != bus->addrWidth)
        {
            config.phCtrl |= FLS_IP_A_SIZE((uint32)bus->addrWidth - 1UL);

            if (FLS_IP_INDIRECT_ACCESS_MODE == accessMode)
            {
                config.phCtrl |= FLS_IP_A_EN;
            }
        }

        if (FLS_BUS_OPS_WRITE == ops)
        {
            config.dummy = (FLS_BUS_HYPERRAM == bus->memType) ? bus->info.writeDummy : 0U;
            config.phCtrl |= FLS_IP_C_LINE(FLS_BUS_INST_LANS(bus->info.writeProto)) |
                             FLS_IP_A_LINE(FLS_BUS_ADDR_LANS(bus->info.writeProto)) |
                             FLS_IP_D_LINE(FLS_BUS_DATA_LANS(bus->info.writeProto));
            config.cmdCode = (uint16)(bus->info.writeProto >> FLS_BUS_OPCODE_PROTO_LSB);

            /* Add for 1s-Xd-Xd, X=2,4,8 */
            if ((FALSE == bus->octalDtrEnable) &&
                    (0U != (bus->info.writeProto & FLS_BUS_DTR_PROTO)))
            {
                config.phCtrl |= FLS_IP_A_RATE(1u) | FLS_IP_D_RATE(1u);
            }
        }
        else if (FLS_BUS_OPS_READ == ops)
        {
            config.dummy = bus->info.readDummy;
            config.phCtrl |= FLS_IP_C_LINE(FLS_BUS_INST_LANS(bus->info.readProto)) |
                             FLS_IP_A_LINE(FLS_BUS_ADDR_LANS(bus->info.readProto)) |
                             FLS_IP_D_LINE(FLS_BUS_DATA_LANS(bus->info.readProto));
            config.cmdCode = (uint16)(bus->info.readProto >> FLS_BUS_OPCODE_PROTO_LSB);

            /* Add for 1s-Xd-Xd, X=2,4,8 */
            if ((FALSE == bus->octalDtrEnable) &&
                    (0U != (bus->info.readProto & FLS_BUS_DTR_PROTO)))
            {
                config.phCtrl |= FLS_IP_A_RATE(1u) | FLS_IP_D_RATE(1u);
            }
        }
        else
        {
            /* Do nothing */
        }
    }

    if (FLS_BUS_HYPERRAM == bus->memType)
    {
        /* For hyperram, e3 xspi's dummy is device spec's dummy + 1 */
        config.dummy = config.dummy + 1u;
    }
    else if ((TRUE == bus->hyperbusMode) && (config.dummy > 0u))
    {
        /* For hyperflash, e3 xspi's dummy is device spec's dummy - 1 */
        config.dummy = config.dummy - 1u;
    }
    else
    {
        /* Do nothing */
    }

    if ((TRUE == bus->octalDtrEnable) || (TRUE == bus->hyperbusMode))
    {
        config.cmdCode |= config.cmdCode << 8u;
    }

    Fls_IpProtocolConfig(ipCtx, accessMode, ops, &config);
}

/*
static void xspi_lld_cs_set(Fls_BusHandleType *nor)
{
    uint32 reg;
    uint8 cs;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;

    if (nor->cs == 0u) {
        cs = FLS_IP_CS_CTRL_HW_SEL_DEV1;
    } else {
        cs = FLS_IP_CS_CTRL_HW_SEL_DEV2;
    }

    reg = Fls_IpReadl(ipCtx, FLS_IP_CS_CTRL);
    reg &= ~(FLS_IP_CS_CTRL_HW_SEL_MASK << FLS_IP_CS_CTRL_HW_SEL_LSB);

    reg |= cs << FLS_IP_CS_CTRL_HW_SEL_LSB;

    Fls_IpWritel(ipCtx, FLS_IP_CS_CTRL, reg);
}
*/

/** *****************************************************************************************************
 * \brief This function Configure the controller's register to set the auto polling.
 *
 * \verbatim
 * Syntax             : void Fls_IpAutoPollingSetup(
 *                          Fls_BusHandleType *nor)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure the controller's register to set the auto polling
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpAutoPollingSetup(Fls_BusHandleType *nor)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    uint32 refCycle = (uint32)ipCtx->refClkHz / 80U;

    Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_P_VALUE, 1u);
    Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_P_MASK, 0xfffffffeu);
    Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_P_TIME, FLS_IP_US_2_TICKS(refCycle, 2U));
}

/** *****************************************************************************************************
 * \brief This function Configure the controller's register to enable DQS.
 *
 * \verbatim
 * Syntax             : void Fls_IpDqsEnable(
 *                          Fls_IpContextType *ipCtx, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ipCtx - Pointer to controller context
 *                      enable - Switch of enable DQS
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure the controller's register to enable DQS
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpDqsEnable(Fls_IpContextType *ipCtx, boolean enable)
{
    uint32 reg;

    /* For aviod dqs bug */
    Fls_IpWriteBits(ipCtx, FLS_IP_MISC, FLS_IP_MISC_RX_ENABLE_MODE_LSB, 1U, 1U);

    reg = Fls_IpReadl(ipCtx, FLS_IP_SCLK_CTRL);
    reg &= ~(FLS_IP_SCLK_CTRL_RX_SEL_MASK << FLS_IP_SCLK_CTRL_RX_SEL_LSB);

    if (TRUE == enable)
    {
        /* dqs mode */
        reg |= 2u << FLS_IP_SCLK_CTRL_RX_SEL_LSB;
    }

    Fls_IpWritel(ipCtx, FLS_IP_SCLK_CTRL, reg);
}

/** *****************************************************************************************************
 * \brief This function Configure the controller's register to support hyperflash.
 *
 * \verbatim
 * Syntax             : void Fls_IpHyperbusEnable(
 *                          Fls_BusHandleType *nor)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure the controller's register to support hyperflash
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpHyperbusEnable(Fls_BusHandleType *nor)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;

    uint32 reg;
    reg = Fls_IpReadl(ipCtx, 0x60);
    reg |= FLS_BIT(4);
    Fls_IpWritel(ipCtx, 0x60, reg);

    /* Set rx enable mode to half-dummy or rdata phase 0 */
    Fls_IpWriteBits(ipCtx, FLS_IP_MISC, FLS_IP_MISC_RX_ENABLE_MODE_LSB, 1U, 1U);

    /* Set bytes swap */
    Fls_IpWriteBits(ipCtx, FLS_IP_MODE_CTRL, FLS_IP_MODE_CTRL_BYTE_SWAP_LSB, 1U, 1U);

    /* Set profile2.0 enable */
    Fls_IpWriteBits(ipCtx, FLS_IP_HYPERBUS_CTRL, FLS_IP_HYPERBUS_CTRL_PROFILE20_EN_LSB, 1U, 1U);

    /* Set address type divided to 2 */
    Fls_IpWriteBits(ipCtx, FLS_IP_HYPERBUS_CTRL, FLS_IP_HYPERBUS_CTRL_AM_LSB, 1U, 0U);

    /*Set address space type memory */
    Fls_IpWriteBits(ipCtx, FLS_IP_HYPERBUS_CTRL, FLS_IP_HYPERBUS_CTRL_AS_LSB, 1U, 0U);

    Fls_IpWriteBits(ipCtx, FLS_IP_HYPERBUS_CTRL, FLS_IP_HYPERBUS_CTRL_EN_LSB, 1U, nor->hyperbusMode);
}

/** *****************************************************************************************************
 * \brief This function Wait for the send to complete until it times out.
 *
 * \verbatim
 * Syntax             : int Fls_IpTxComplete(
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
 * Description        : Wait for the send to complete until it times out
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpTxComplete(Fls_IpContextType *ipCtx)
{
    int ret;
    uint32 reg;

    ret = Fls_IpWaitForBitTimes(ipCtx->apbBase + FLS_IP_INT_ST_FUC,
                                FLS_IP_INT_ST_FUC_INDIRECT_WR_DONE,
                                FALSE, FLS_IP_WRITE_DONE_TIMEOUT_CYCLES);

    if (ret != 0)
    {
        FLS_DEBUG("Indirect write not complete, ret %d.\n", ret);
    }
    else
    {
        reg = Fls_IpReadl(ipCtx, FLS_IP_INT_ST_FUC);
        Fls_IpWritel(ipCtx, FLS_IP_INT_ST_FUC, reg);
    }

    return ret;
}

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
static int Fls_IpRxComplete(Fls_IpContextType *ipCtx)
{
    int ret;
    uint32 reg;

    ret = Fls_IpWaitForBitTimes(ipCtx->apbBase + FLS_IP_INT_ST_FUC,
                                FLS_IP_INT_ST_FUC_INDIRECT_RD_DONE,
                                FALSE, FLS_IP_READ_DONE_TIMEOUT_CYCLES);

    if (ret != 0)
    {
        FLS_DEBUG("Indirect read not complete, ret %d.\n", ret);
    }
    else
    {
        reg = Fls_IpReadl(ipCtx, FLS_IP_INT_ST_FUC);
        Fls_IpWritel(ipCtx, FLS_IP_INT_ST_FUC, reg);
    }

    return ret;
}

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
int Fls_IpTrigerComplete(Fls_IpContextType *ipCtx)
{
    int ret = -1;

    if (0 != Fls_IpWaitForBitTimes(ipCtx->apbBase + FLS_IP_INDIRECT_WR_CTRL,
                                FLS_IP_INDIRECT_WR_CTRL_W_TRIGGER,
                                TRUE, FLS_IP_WAIT_TRIGGER_COMPLETE_TIMEOUT))
    {
        FLS_DEBUG("Wait Indirect write complete timeout.\n");
    }
    else if (0 != Fls_IpWaitForBitTimes(ipCtx->apbBase + FLS_IP_INDIRECT_RD_CTRL,
                                FLS_IP_INDIRECT_RD_CTRL_R_TRIGGER,
                                TRUE, FLS_IP_WAIT_TRIGGER_COMPLETE_TIMEOUT))
    {
        FLS_DEBUG("Wait Indirect read complete timeout.\n");
    }
    else
    {
        ret = 0;
    }

    return ret;
}

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
                          uint8 readDummy, uint8 writeDummy)
{
    uint32 dummy;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)bus->host->privData;

    Fls_IpWriteBits(ipCtx, FLS_IP_DEV_SIZE, FLS_IP_DEV_SIZE_DEV1_HYPER_RAM_EN_LSB + cs, 1u, 0x1u);

    /* Config direct read pre-transaction to 0 */
    Fls_IpWritel(ipCtx, FLS_IP_DIRECT_RD_PTC, 0u);

    /* Config direct write pre-transaction to 0 */
    Fls_IpWritel(ipCtx, FLS_IP_DIRECT_WR_PTC, 0U);

    dummy = (((uint32)readDummy + 1UL) & FLS_IP_DIRECT_D_CYC_RD_MASK);
    dummy |= (((uint32)writeDummy + 1UL) & FLS_IP_DIRECT_D_CYC_WR_MASK) << FLS_IP_DIRECT_D_CYC_WR_LSB;
    Fls_IpWritel(ipCtx, FLS_IP_DIRECT_D_CYC, dummy);

    Fls_IpPrefetchDisable(ipCtx);
}
#endif /* #ifdef FLS_HYPERBUS_FLASH_CNT */

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
void Fls_IpBusSetup(Fls_BusHandleType *bus, Fls_BusOpsType ops)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)bus->host->privData;

    (void) ops;

    if (0 != Fls_IpWaitIdle(ipCtx))
    {
        FLS_DEBUG("%s: wait idle err.", __FUNCTION__);
    }
    else
    {
        if ((bus->cs != ipCtx->currentCs) && (0u != bus->info.size)
            && (FALSE == ipCtx->useRomConfig))
        {
            /* cs select by hardware, based on access address */
            /* xspi_lld_cs_set(bus); */
            Fls_IpSetDelay(bus);

            if (TRUE == bus->hyperbusMode)
            {
                Fls_IpHyperbusEnable(bus);
                Fls_IpPretransClean(bus);
                Fls_IpProtocolSetup(bus, NULL_PTR, FLS_IP_INDIRECT_ACCESS_MODE, FLS_BUS_OPS_READ);
                Fls_IpProtocolSetup(bus, NULL_PTR, FLS_IP_INDIRECT_ACCESS_MODE, FLS_BUS_OPS_WRITE);
                Fls_IpProtocolSetup(bus, NULL_PTR, FLS_IP_DIRECT_ACCESS_MODE, FLS_BUS_OPS_READ);
                Fls_IpProtocolSetup(bus, NULL_PTR, FLS_IP_DIRECT_ACCESS_MODE, FLS_BUS_OPS_WRITE);
            }
            else
            {
                Fls_IpAutoPollingSetup(bus);
            }

            ipCtx->currentCs = bus->cs;
        }

        if (0u != bus->info.size)
        {
            Fls_IpSetSize(bus);
        }

        if (bus->dqsEnable != ipCtx->dqsEnable)
        {
            Fls_IpDllEnable(ipCtx, 0, 7u, bus->dqsEnable);
            Fls_IpDllEnable(ipCtx, 1, 7u, bus->dqsEnable);
            Fls_IpDqsEnable(ipCtx, bus->dqsEnable);
            ipCtx->dqsEnable = bus->dqsEnable;
        }

        if (FALSE == bus->hyperbusMode)
        {
            Fls_IpProtocolSetup(bus, NULL_PTR, FLS_IP_DIRECT_ACCESS_MODE, FLS_BUS_OPS_READ);
        }
    }

    return;
}

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
void Fls_IpSetupXfer(Fls_BusHandleType *bus, Fls_BusOpsType opt,
                     Fls_AddressType addr, uint8 *readBuf,
                     const uint8 *writeBuf, Fls_LengthType size)

{
    bus->xferInfoBottom.opsType = opt;
    bus->xferInfoBottom.addr = addr;
    bus->xferInfoBottom.readBuf = readBuf;
    bus->xferInfoBottom.writeBuf = writeBuf;
    bus->xferInfoBottom.opsResult = FLS_BUS_OPS_PENDING;
    bus->xferInfoBottom.size = size;
}

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
void Fls_IpReleaseXfer(Fls_BusHandleType *bus)
{
    bus->xferInfoBottom.writeBuf = NULL_PTR;
    bus->xferInfoBottom.readBuf = NULL_PTR;
    bus->xferInfoBottom.size = 0;
}

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
                      Fls_LengthType size)
{
    uint32 lastWord;
    uint32 alignedSize;
    uint32 bytesNeedRead = 0;

#ifdef FLS_IP_INDIRECT_AXI_EN
    uint32 addr = Fls_IpReadl(ipCtx, FLS_IP_INDIRECT_RD_ADDR);
    uint32 fifoAddress = ipCtx->directBase + FLS_ROUNDUP(addr, 4u);
#else
    uint32 fifoAddress = ipCtx->apbBase + FLS_IP_INDIRECT_RDATA;
#endif /* #ifdef FLS_IP_INDIRECT_AXI_EN */

    if (FLS_IS_ALIGNED(buf, 4U))
    {
        bytesNeedRead =
            Fls_IpGetReceiveBufLevel(ipCtx) * (uint32)ipCtx->fifoWidth;

        bytesNeedRead = FLS_MIN(bytesNeedRead, size);

        if (0U != bytesNeedRead)
        {
            alignedSize = bytesNeedRead / 4u * 4u;

            Fls_IpReadsl((uint32 *)fifoAddress, (uint32 *)buf, alignedSize / 4u);

            if (0U != (bytesNeedRead % 4U))
            {
                lastWord = readl(fifoAddress);
                Fls_IpReadsb((uint8 *) &lastWord, buf + alignedSize, bytesNeedRead % 4U);
            }
        }
    }

    return bytesNeedRead;
}

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
                       Fls_LengthType size)
{
    uint32 sramLevel;
    uint32 writeBytes = 0;
    uint32 sramSize = (uint32)ipCtx->fifoDepth * ipCtx->fifoWidth;
#ifdef FLS_IP_INDIRECT_AXI_EN
    uint32 addr = Fls_IpReadl(ipCtx, FLS_IP_INDIRECT_WR_ADDR);
    uint32 fifoAddress = ipCtx->directBase + FLS_ROUNDUP(addr, 4u);
#else
    uint32 fifoAddress = ipCtx->apbBase + FLS_IP_INDIRECT_WDATA;
#endif /* #ifdef FLS_IP_INDIRECT_AXI_EN */

    if (FLS_IS_ALIGNED(buf, 4U))
    {
        sramLevel = Fls_IpGetWriteBufLevel(ipCtx);

        if (0u == sramLevel)
        {
            writeBytes = FLS_MIN(size, sramSize);
            Fls_IpWritesl((uint32 *)fifoAddress, (const uint32 *)buf,
                          FLS_DIV_ROUND_UP(writeBytes, 4u));
        }
    }

    return writeBytes;
}

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
                           uint32 size, int flag)
{
    if (flag == INDIRECT_READ_FLAG)
    {
        /* Set indirect read start address */
        Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_ADDR, addr);
        /* Set indirect read bytes number */
        Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_SIZE, size);
        /* Start the indirect read */
        Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_RD_CTRL, 1u);
    }
    else
    {
        /* Set indirect write start address */
        Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_ADDR, addr);
        /* Set indirect write bytes number */
        Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_SIZE, size);
        /* Start the indirect write */
        Fls_IpWritel(ipCtx, FLS_IP_INDIRECT_WR_CTRL, 1u);
    }
}

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
int Fls_IpRxPolling(Fls_BusHandleType *bus)
{
    int ret = 0;
    uint32 rx_size;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)bus->host->privData;

    if ((bus->xferInfoBottom.readBuf != NULL_PTR) &&
            (bus->xferInfoBottom.size > 0u))
    {
        rx_size = Fls_IpReadFifo(ipCtx, bus->xferInfoBottom.readBuf,
                                 bus->xferInfoBottom.size);
        bus->xferInfoBottom.readBuf += rx_size;
        bus->xferInfoBottom.size -= rx_size;

        if (bus->xferMode == FLS_BUS_XFER_POLLING_MODE)
        {
            if (bus->xferInfoBottom.size == 0u)
            {
                ret = Fls_IpRxComplete(ipCtx);
            }
        }
    }
    else
    {
        ret = Fls_IpRxComplete(ipCtx);
    }

    return ret;
}

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
int Fls_IpTxPolling(Fls_BusHandleType *bus)
{
    int ret = 0;
    uint32 tx_size;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)bus->host->privData;

    if ((bus->xferInfoBottom.writeBuf != NULL_PTR) &&
            (bus->xferInfoBottom.size > 0u))
    {
        tx_size = Fls_IpWriteFifo(ipCtx, bus->xferInfoBottom.writeBuf,
                                  bus->xferInfoBottom.size);
        bus->xferInfoBottom.writeBuf += tx_size;
        bus->xferInfoBottom.size -= tx_size;

        if (bus->xferMode == FLS_BUS_XFER_POLLING_MODE)
        {
            if (bus->xferInfoBottom.size == 0u)
            {
                ret = Fls_IpTxComplete(ipCtx);
            }
        }
    }
    else
    {
        ret = Fls_IpTxComplete(ipCtx);
    }

    return ret;
}

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
void Fls_IpSetInterruptMask(Fls_IpContextType *ipCtx, uint32 addr, uint32 mask)
{
    uint32 reg;
    reg = Fls_IpReadl(ipCtx, addr);
    reg |= mask;
    Fls_IpWritel(ipCtx, addr, reg);
}

#ifdef FLS_RFD_ENABLE_CNT
/** *****************************************************************************************************
 * \brief This function returns the crc checksum of this Specify buffer.
 *
 * \verbatim
 * Syntax             : uint32 Fls_IpCrc32(
 *                          uint32 crc, uint8 const *buffer, uint32 len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The value of crc checksum
 *
 * Description        : Calculate the crc checksum
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static uint32 Fls_IpCrc32(uint32 crc, uint8 const *buffer, uint32 len)
{
    crc ^= 0xFFFFFFFFUL;

    while (0U != len--)
    {
        crc = (crc << 8) ^ Fls_Crc32Table[(crc >> 24) ^ (*buffer++)];
    }

    return crc ^ 0xFFFFFFFFUL;
}

/** *****************************************************************************************************
 * \brief This function Checking crc checksum in RFD area.
 *
 * \verbatim
 * Syntax             : uint8 Fls_IpRfdCheck(
 *                          Fls_BusHandleType *nor)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The mask of the region
 *
 * Description        : Checking crc checksum in RFD area and returns the mask of the region
 *                      where the checksum was successful.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static uint8 Fls_IpRfdCheck(Fls_BusHandleType *nor)
{
    int ret;
    uint8 enableMask = 0U;
    uint8 i;
    Fls_IpRfdRegionType rfdBuffer;

    ret = Fls_BusRead(nor, FLS_IP_RFD_START_ADDRESS, (uint8 *)&rfdBuffer, sizeof(Fls_IpRfdRegionType));

    if (0 == ret)
    {
        for (i = 0; i < FLS_MAX_RFD_REGION; i++)
        {
            if (rfdBuffer.crc[i] ==
                    Fls_IpCrc32(0, rfdBuffer.rfd[i], FLS_IP_RFD_LENGTH))
            {
                enableMask |= (1U << i);
            }
        }
    }

    return enableMask;
}

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
int Fls_IpRfdEnable(Fls_BusHandleType *bus)
{
    uint32 reg;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)bus->host->privData;
    uint8 regionMask;
    int ret = 0;
    uint32 tmt;
    uint8 i;
    uint8 channel;

    regionMask = Fls_IpRfdCheck(bus);

    if (0U == regionMask)
    {
        FLS_DEBUG("RFD CRC check failed. Can't enable");
        ret = -1;
    }
    else
    {
        bus->xferInfoBottom.size = 4U;
        Fls_IpProtocolSetup(bus, NULL_PTR, FLS_IP_INDIRECT_ACCESS_MODE,
                            FLS_BUS_OPS_READ);

        for (i = 0; i < FLS_MAX_RFD_REGION; i++)
        {
            if (0U != (regionMask & (1u << i)))
            {
                /* Key derivation trigger */
                reg = Fls_IpReadl(ipCtx, FLS_IP_IMG_RFD);
                reg |= FLS_BIT(8U + i);
                Fls_IpWritel(ipCtx, FLS_IP_IMG_RFD, reg);

                /* Polling key ready */
                tmt = FLS_IP_KEY_READY_TIMEOUT_CYCLES;

                while (0U == (Fls_IpReadl(ipCtx, FLS_IP_IMG_RFD) & FLS_BIT(16U + i)))
                {
                    if (0U == tmt--)
                    {
                        break;
                    }

                    Fls_IpDelayUs(1);
                }
            }
        }

        /* Enable decryption */
        reg = Fls_IpReadl(ipCtx, FLS_IP_IMG_RFD);
        reg |= ((uint32)regionMask << 28);
        Fls_IpWritel(ipCtx, FLS_IP_IMG_RFD, reg);
        bus->xferInfoBottom.size = 0;

        /* Flush prefetch */
        if (0U != Fls_IpReadl(ipCtx, FLS_IP_GROUP_MERGE))
        {
            for (channel = 0; channel < 8U; channel++)
            {
                Fls_IpPrefetchFlush(ipCtx, channel);
            }
        }
    }

    return ret;
}
#endif /* #ifdef FLS_RFD_ENABLE_CNT */

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

/* End of file */
