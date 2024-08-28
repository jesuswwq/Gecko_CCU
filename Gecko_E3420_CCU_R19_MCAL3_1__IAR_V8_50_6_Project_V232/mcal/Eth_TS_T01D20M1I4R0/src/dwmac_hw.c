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
 * @file  dwmac_hw.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "debug.h"
#include "dwmac.h"
#include "dwmac_common.h"
#include "RegBase.h"
#include "crc32.h"
#include "Mcu_Scr.h"
#include "Mcu_Delay.h"
#include "Mcu_ScrBits.h"
#include "dwc_ether_qos_wrapper_reg.h"


#define     mdelay(x)     Mcu_udelay(1000*(x))

// promiscuous or not
enum filter {
    MAC_FILTER_MODE_PROM_ON = 0,
    MAC_FILTER_MODE_PROM_OFF,
    MAC_FILTER_MODE_PROM_NORMAL,
};

#define ETH_START_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

const scr_signal_t Eth_SignalScr1 = SCR_SF_SCR_ETH1_CLK_RMII_OE;
#ifdef SEMIDRIVE_E3_SERIES
const scr_signal_t Eth_SignalScr2 = SCR_SF_SCR_ETH2_CLK_RMII_OE;
#endif
#define ETH_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/*
    generate mac addr
*/
static void swap_mac_address(uint32 high, uint32 low, uint8 mac[6])
{
    mac[3] = low & 0xff;
    mac[2] = (low >> 8) & 0xff;
    mac[1] = (low >> 16) & 0xff;
    mac[0] = (low >> 24) & 0xff;
    mac[5] = high & 0xff;
    mac[4] = (high >> 8) & 0xff;
}
/**
 * @description:
 * @param {module_e} eth_instance
 * @param {uint32} type
 * @return {*}
 */
void select_eth_mii_type(uint32 RegBase, uint32 type)
{
    if (type == ETH_PHY_INTF_SEL_RMII) {
        if (RegBase == APB_ETH1_BASE) {
            Mcu_ScrSetBit(&Eth_SignalScr1, 1);
        }

#ifdef SEMIDRIVE_E3_SERIES
        else {
            Mcu_ScrSetBit(&Eth_SignalScr2, 1);
        }

#endif
    }

    writel(FV_PHY_INTF_SEL_SEL(type), RegBase + PHY_INTF_SEL_OFF);
}


static void dwmac_set_mac_addr(uint32 RegBase, uint8 Addr[6],
                               uint32 high, uint32 low)
{
    unsigned long data;

    data = (Addr[5] << 8) | Addr[4];
    /* For MAC Addr registers se have to set the Address Enable (AE)
     * bit that has no effect on the High Reg 0 where the bit 31 (MO)
     * is RO.
     */
    data |= (0 << MAC_HI_DCS_SHIFT);
    writel(data | MAC_HI_REG_AE, RegBase + high);
    data = (Addr[3] << 24) | (Addr[2] << 16) | (Addr[1] << 8) | Addr[0];
    writel(data, RegBase + low);
}

static void dwmac_clr_mac_addr(uint32 RegBase, uint32 high, uint32 low)
{
    unsigned long data = 0;
    data &= ~MAC_HI_REG_AE;
    data |= (0 << MAC_HI_DCS_SHIFT);
    writel(data, RegBase + high);
    data = 0;
    writel(data, RegBase + low);
}

static void dwmac_get_mac_addr(uint32 RegBase, uint8 *Addr,
                               uint32 high, uint32 low)
{
    uint32 hi_addr, lo_addr;

    /* Read the MAC address from the hardware */
    hi_addr = readl(RegBase + high);
    lo_addr = readl(RegBase + low);

    /* Extract the MAC address from the high and low words */
    Addr[0] = lo_addr & 0xff;
    Addr[1] = (lo_addr >> 8) & 0xff;
    Addr[2] = (lo_addr >> 16) & 0xff;
    Addr[3] = (lo_addr >> 24) & 0xff;
    Addr[4] = hi_addr & 0xff;
    Addr[5] = (hi_addr >> 8) & 0xff;
}
/* =====================> MAC BLOCK <==================== */
static void  dwmac_mmc_init(uint32 RegBase)
{
    /* 5us */
    uint32 timeout = 50;
    volatile  uint32 value = readl(RegBase + MAC_MMC_CTRL);
    value = MAC_MMC_CTRL_RESET;
    writel(value, RegBase + MAC_MMC_CTRL);

    /* mac will  cleared  reset bit */
    do {
        value = readl(RegBase + MAC_MMC_CTRL);
        timeout--;
    } while ((value & MAC_MMC_CTRL_RESET) && timeout);

    value = MAC_MMC_CTRL_RSTONRD;
    writel(value, RegBase + MAC_MMC_CTRL);
    /* disable all mmc overflow irq */
    writel(0xFFFFFFFF, RegBase + MAC_MMC_RX_INTR_MASK);
    writel(0xFFFFFFFF, RegBase + MAC_MMC_TX_INTR_MASK);
    writel(0xFFFFFFFF, RegBase + MAC_MMC_IPC_INTR_MASK);
}
/**
 * @name:
 * @Desc:
 * @param {void } *RegBase
 * @param {uint32} MTU
 * @param {uint32} Speed
 * @return {*}
 */
void dwmac_core_init(uint32 RegBase, uint32 MTU, uint32 mac_high, uint32 mac_low, uint32 Speed)
{
    uint8 mac[6];
    uint32 value = readl(RegBase + MAC_CONFIG);
    value |= MAC_CORE_INIT;
    value &= ~MAC_CONFIG_TE;
    value &= ~MAC_CONFIG_RE;
#ifdef ENABLE_QOS_LOOPBACK
    value |= MAC_CONFIG_LM;
#endif

    if (MTU > 1500)
        value |= MAC_CONFIG_2K;

    if (MTU > 2000)
        value |= MAC_CONFIG_JE;

    switch (Speed) {
    case PHY_SPEED_1000:
        value &= ~(MAC_CONFIG_FES | MAC_CONFIG_PS);
        break;

    case PHY_SPEED_100:
        value |= MAC_CONFIG_FES | MAC_CONFIG_PS;
        break;

    case PHY_SPEED_10:
        value |= MAC_CONFIG_PS;
        value &= ~MAC_CONFIG_FES;
        break;
    }

    writel(value, RegBase + MAC_CONFIG);
    /* Disable All MAC interrupts */
    value = 0;
    writel(value, RegBase + MAC_INT_EN);
#if defined(MAX_POWER_CASE)
    /* enable correctable error  */
    value = readl(RegBase + MTL_ECC_INT_EN);
    value |= MTL_ECC_COR_ERR_EST | MTL_ECC_COR_ERR_RX | MTL_ECC_COR_ERR_TX;
    writel(value, RegBase + MTL_ECC_INT_EN);
#endif
#if defined(SEMIDRIVE_E3_SERIES) || defined(SEMIDRIVE_E3_LITE_SERIES)
    /* enable ecc */
    value = readl(RegBase + MTL_ECC_CTRL);
    value |= MTL_ECC_DEFAULT_ENABLE;
    writel(value, RegBase + MTL_ECC_CTRL);
    /* enable bus parity */
    value = readl(RegBase + MTL_DPP_CTRL);
    value |= MTL_DPP_CTRL_DATA_PARITY | MTL_DPP_CTRL_SLAVE_PARITY;
    writel(value, RegBase + MTL_DPP_CTRL);
#endif
    /* Init MMC  */
    dwmac_mmc_init(RegBase);
    swap_mac_address(mac_high, mac_low, mac);

    dwmac_set_umac_addr(RegBase, mac, 0);
    value = 0;
    value |= MAC_PACKET_FILTER_PM;
    writel(value, RegBase + MAC_PACKET_FILTER);

    /* Does not receive any multicasts by default */
    writel(0x0, RegBase + MAC_HASH_TAB_0_31);
    writel(0x0, RegBase + MAC_HASH_TAB_32_63);
    writel(0x0, RegBase + MAC_HASH_TAB_64_95);
    writel(0x0, RegBase + MAC_HASH_TAB_96_127);
    value = readl(RegBase + MAC_PACKET_FILTER);
    value &= ~MAC_PACKET_FILTER_PM;
    /*
        The  DAIF bit will applcable unicast and multcast
        so only supports imperfect filtering for multcast.
    */
    value |= MAC_PACKET_FILTER_HMC;
    writel(value, RegBase + MAC_PACKET_FILTER);
    /* Does not receive any multicasts by default end */
    crc32_init();
}
/**
 * @name:
 * @Desc:
 * @param {void} *Addr
 * @param {uint8} Mode
 * @param {uint32} Queue
 * @return {*}
 */
void dwmac_mac_rx_queue_mcbc_routing(uint32  RegBase, uint8 Channel)
{
    uint32 value;
    value = readl(RegBase + MAC_RXQ_CTRL1);
    value |= MAC_RXQCTRL_MCBCQEN;
    value &= ~MAC_RXQCTRL_MCBCQ_MASK;
    value |= (Channel << MAC_RXQCTRL_MCBCQ_SHIFT & \
              MAC_RXQCTRL_MCBCQ_MASK);
    writel(value, RegBase + MAC_RXQ_CTRL1);
}
#if defined(DEBUG_ENABLE)
/**
 * @name:
 * @Desc:
 * @param {void*} Addr
 * @return {*}
 */
void dwmac_dump_mac(uint32  Addr)
{
    uint32 RegBase = Addr;
    int i;

    for (i = 0; i < MAC_REG_NUM; i++)
        DBG("MAC:%p = %p\n", i * 4, readl(RegBase + i * 4));
}
#endif
/**
 * @description:
 * @param {*}
 * @return {*}
 */
void dwmac_clr_umac_addr(uint32 RegBase, uint32 Reg_n)
{
    dwmac_clr_mac_addr(RegBase, MAC_ADDR_HIGH(Reg_n),
                       MAC_ADDR_LOW(Reg_n));
}
/**
 * @name:
 * @Desc:
 * @param {*}
 * @return {*}
 */
void dwmac_set_umac_addr(uint32 RegBase,
                         const uint8 *Addr, uint32 Reg_n)
{
    dwmac_set_mac_addr(RegBase, (uint8 *)Addr, MAC_ADDR_HIGH(Reg_n),
                       MAC_ADDR_LOW(Reg_n));
}
/**
 * @name:
 * @Desc:
 * @param {*}
 * @return {*}
 */
void dwmac_get_umac_addr(uint32 RegBase,
                         unsigned char *Addr, uint32 Reg_n)
{

    dwmac_get_mac_addr(RegBase, Addr, MAC_ADDR_HIGH(Reg_n),
                       MAC_ADDR_LOW(Reg_n));
}
/**
 * @name:
 * @Desc: reverse bit order
 * @param {uint32} param
 * @return {*}
 */
static inline uint32 bitreverseOrder32(uint32 x)
{
    ASM("rbit %0, %1" : "=r" (x) : "r" (x));
    return x;
}

static enum filter is_quirks_mac_addr(const uint8 *Addr)
{
    uint8 i = 0, mode = 0x07;

    for (i = 0; i < 6; i++) {
        if (Addr[i] != 0xFF)
            mode &= 0xFE;

        if (Addr[i] != 0x0)
            mode &= 0xFD;
    }

    if (mode & 0x01)
        return MAC_FILTER_MODE_PROM_ON;
    else if (mode & 0x02) {
        return MAC_FILTER_MODE_PROM_OFF;
    } else {
        return MAC_FILTER_MODE_PROM_NORMAL;
    }
}

sint32 dwmac_set_filter(uint32 RegBase, uint32 Mode, const uint8 *Addr)
{
    sint32 ret = 0;
    enum filter mode = is_quirks_mac_addr(Addr);
    uint32 bit_nr, value = 0, hash_table_width, valid_bits;

    if (MAC_FILTER_MODE_PROM_NORMAL != mode) {
        value = readl(RegBase + MAC_PACKET_FILTER);

        if (MAC_FILTER_MODE_PROM_ON == mode) {
            value |= MAC_PACKET_FILTER_PA | MAC_PACKET_FILTER_PR;

        } else {
            value &= ~(MAC_PACKET_FILTER_PA | MAC_PACKET_FILTER_PR);
        }

        writel(value, RegBase + MAC_PACKET_FILTER);
    } else {
        value = readl(RegBase + MAC_HW_FEATURE1);
        value &= MAC_HASH_TABLE_WIDTH_MASK;
        hash_table_width = value >> MAC_HASH_TABLE_WIDTH_SHIFT;

        if (MAC_HASH_TABLE_WIDTH_64 == hash_table_width) {
            valid_bits = 5;
        } else if (MAC_HASH_TABLE_WIDTH_128 == hash_table_width) {
            valid_bits = 6;
        } else if (MAC_HASH_TABLE_WIDTH_256 == hash_table_width) {
            valid_bits = 7;
        } else {
            valid_bits = 0;
            ret = -1;
        }

        if (ret == 0) {
            bit_nr = bitreverseOrder32(~crc32((uint32)(~0), Addr, valid_bits)) >> (31 - valid_bits);

            if (Mode == ETH_ADD_TO_FILTER) {
                /* add to fillter,not fillter out */
                value = readl(RegBase + MAC_HASH_TAB_0_31 + HASH_TABLE_IDX(bit_nr));
                value |= HASH_REG_MASK(bit_nr  & 0x1f);
            } else {
                value = readl(RegBase + MAC_HASH_TAB_0_31 + HASH_TABLE_IDX(bit_nr));
                value &= ~HASH_REG_MASK(bit_nr  & 0x1f );
            }

            writel(value, RegBase + MAC_HASH_TAB_0_31 + HASH_TABLE_IDX(bit_nr));
        }
    }

    return ret;
}
#if defined(DEBUG_ENABLE)
/**
 * @name:
 * @Desc:
 * @param {void } *RegBase
 * @param {uint32} Queue
 * @return {*}
 */
void dwmac_dump_mtl(uint32 RegBase, uint32 Queue)
{
    uint32 base = 0xc00;

    for (int i = 0; i <= 0x13c; i += 4) {
        DBG("Reg=%p,Val=%p\n", base + i, readl(RegBase + base + i));
    }
}
#endif

static int config_addend(uint32 regbase, uint32 addend)
{
    uint32 value;
    int limit;

    writel(addend, regbase + MAC_PTP_TSAR);
    /* issue command to update the addend value */
    value = readl(regbase + MAC_PTP_CONTRL);
    value |= PTP_CONTRL_TSADDREG;
    writel(value, regbase + MAC_PTP_CONTRL);

    /* wait for present addend update to complete */
    limit = 10;

    while (limit--) {
        if (!(readl(regbase + MAC_PTP_CONTRL) & PTP_CONTRL_TSADDREG))
            break;

        mdelay(10);
    }

    if (limit < 0)
        return -1;

    return 0;
}

void config_sub_second_increment(uint32 regbase, uint32 ptp_clock)
{
    uint32 value = readl(regbase + MAC_PTP_CONTRL);
    unsigned long data;
    uint32 reg_value;

    data = (1000000000ULL / ptp_clock);

    if (value & PTP_CONTRL_TSCFUPDT)
        data *= 2;

    /* 0.465ns accuracy */
    if (!(value & PTP_CONTRL_TSCTRLSSR))
        data = (data * 1000) / 465;

    data &= 0xFF;

    reg_value = data;

    reg_value <<= PTP_SSIR_SSINC_SHIFT;

    writel(reg_value, regbase + MAC_PTP_SSINC);

    uint64 temp = 1000000000ULL / data;

    /* calculate default added value:
     * formula is :
     * addend = (2^32)/freq_div_ratio;
     * where, freq_div_ratio = 1e9ns/sec_inc
     */
    temp = (uint64)(temp << 32);
    temp = temp / ptp_clock;
    config_addend(regbase, (uint32)temp);

}

sint32 dwmac_init_systime(uint32 regbase, uint32 sec, uint32 nsec)
{
    uint32 value, limit;

    value = readl(regbase + MAC_PTP_CONTRL);
    value |= PTP_CONTRL_TSEN | PTP_CONTRL_TSCFUPDT | PTP_CONTRL_TSCTRLSSR;
    writel(value, regbase + MAC_PTP_CONTRL);

    writel(sec, regbase + MAC_PTP_SEC);
    nsec &= PTP_NSEC_MASKE;
    writel(nsec, regbase + MAC_PTP_NSEC);
    /* issue command to initialize the system time value */
    value = readl(regbase + MAC_PTP_CONTRL);
    value |= PTP_CONTRL_INIT;
    writel(value, regbase + MAC_PTP_CONTRL);
    limit = 10;

    /* wait for present system time initialize to complete */
    while (limit--) {
        if (!(readl(regbase + MAC_PTP_CONTRL) & PTP_CONTRL_INIT))
            break;

        mdelay(10);
    }

    if (limit <= 0) {
        return -1;
    }

    return 0;
}

void dwmac_get_time(uint32 regbase, uint32 *sec, uint32 *nsec)
{
    /* twice is enough 100 for margin,is 10us max */
    uint32 timeout = 10;
    uint32 ns, sec0, sec1;

    /* Get the TSS value */
    sec1 = readl(regbase + MAC_PTP_SEC);
    do {
        sec0 = sec1;
        /* Get the TSSS value */
        ns = readl(regbase + MAC_PTP_NSEC);
        /* Get the TSS value */
        sec1 = readl(regbase + MAC_PTP_SEC);
        timeout--;
    } while ((sec0 != sec1) && timeout);

    *sec = sec0;
    *nsec = ns;
}

void setup_timestamp_filter(uint32 regbase, ptp_version_t ptp_v,
                            ptp_mode_t is_ptp_master, ptp_rx_filter_t rxfilter)
{
    /* 802.AS1, any layer */
    uint32 systime_flags = readl(regbase + MAC_PTP_CONTRL);

    if (rxfilter == ALL_RX_PACKET) {
        /* time stamp any incoming packet */
        systime_flags |= PTP_CONTRL_TSENALL;
    } else {
        systime_flags |= PTP_CONTRL_TSIPV4ENA | PTP_CONTRL_TSIPV6ENA | PTP_CONTRL_TSIPENA;

        /* default is PTP v1 */
        if (ptp_v == PTP_V2) {
            /* PTP v2 */
            systime_flags |= PTP_CONTRL_TSVER2ENA;
        }

        /* The snapshot is taken only for the messages that are relevant to the master/slave node.  */
        if (rxfilter != ALL_RX_PTP_PACKET) {
            if (PTP_MASTER == is_ptp_master) {
                /* master role take time stamp for Delay_Req messages only */
                systime_flags |= PTP_CONTRL_TSMSTRENA | PTP_CONTRL_TSEVNTENA;
            } else {
                /* slave role take time stamp for SYNC messages only */
                systime_flags |= PTP_CONTRL_TSEVNTENA;
            }
        } else {
            /* take time stamp for all event messages */
            systime_flags |= PTP_CONTRL_SNAPTYPSEL_1;
        }
    }

    writel(systime_flags, regbase + MAC_PTP_CONTRL);
}
void dwmac_mac_stop_tx(uint32 RegBase)
{
    uint32 value = readl(RegBase + MAC_CONFIG);
    value &= ~MAC_CONFIG_TE;
    writel(value, RegBase + MAC_CONFIG);
}

void dwmac_mac_start_tx(uint32 RegBase)
{
    uint32 value = readl(RegBase + MAC_CONFIG);
    value |= MAC_CONFIG_TE;
    writel(value, RegBase + MAC_CONFIG);
}
/* =====================>MAC BLOCK END<==================== */
/* =====================>  MTL BLOCK  <==================== */
/**
 * @name:
 * @Desc:
 * @param {void} *RegBase
 * @param {uint32} alg
 * @return {*}
 */
void dwmac_prog_mtl_rx_algorithms(uint32  RegBase, uint32 Algorithm)
{

    uint32 value = readl(RegBase + MTL_OPERATION_MODE);

    switch (Algorithm) {
    case MTL_RX_ALGORITHM_SP:
        value &= ~MTL_OPERATION_RAA;
        break;

    case MTL_RX_ALGORITHM_WSP:
        value |= MTL_OPERATION_RAA_WSP;
        break;

    default:
        break;
    }

    writel(value, RegBase + MTL_OPERATION_MODE);
}
/**
 * @name:
 * @Desc:
 * @param {void} *RegBase
 * @param {uint32} alg
 * @return {*}
 */
void dwmac_prog_mtl_tx_algorithms(uint32  RegBase, uint32 Algorithm)
{

    uint32 value = readl(RegBase + MTL_OPERATION_MODE);

    value &= ~MTL_OPERATION_SCHALG_MASK;

    switch (Algorithm) {
    case MTL_TX_ALGORITHM_WRR:
        value |= MTL_OPERATION_SCHALG_WRR;
        break;

    case MTL_TX_ALGORITHM_WFQ:
        value |= MTL_OPERATION_SCHALG_WFQ;
        break;

    case MTL_TX_ALGORITHM_DWRR:
        value |= MTL_OPERATION_SCHALG_DWRR;
        break;

    case MTL_TX_ALGORITHM_SP:
        value |= MTL_OPERATION_SCHALG_SP;
        break;

    default:
        break;
    }

    /* flush MTL  */
    value |= 0x01 << 9;
    writel(value, RegBase + MTL_OPERATION_MODE);
}
/**
 * @name:
 * @Desc:
 * @param {void} *Addr
 * @param {uint32} Queue
 * @param {uint32} Channel
 * @return {*}
 */
void dwmac_map_mtl_dma(uint32  Addr, uint32 Queue, uint32 Channel)
{
    uint32 RegBase = Addr;
    uint32 value;

    if (Queue < 4)
        value = readl(RegBase + MTL_RXQ_DMA_MAP0);
    else
        value = readl(RegBase + MTL_RXQ_DMA_MAP1);

    if (Queue == 0 || Queue == 4) {
        value &= ~MTL_RXQ_DMA_Q04MDMACH_MASK;
        value |= MTL_RXQ_DMA_Q04MDMACH(Channel);
    } else {
        value &= ~MTL_RXQ_DMA_QXMDMACH_MASK(Queue);
        value |= MTL_RXQ_DMA_QXMDMACH(Channel, Queue);
    }

    if (Queue < 4)
        writel(value, RegBase + MTL_RXQ_DMA_MAP0);
    else
        writel(value, RegBase + MTL_RXQ_DMA_MAP1);
}
/**
 * @name:
 * @Desc:
 * @param {void} *Addr
 * @param {uint8} Mode
 * @param {uint32} Queue
 * @return {*}
 */
void dwmac_rx_queue_enable(uint32  Addr, uint8 Mode, uint32 Queue)
{
    uint32  RegBase = Addr;
    uint32 value = readl(RegBase + MAC_RXQ_CTRL0);

    value &= MAC_RX_QUEUE_CLEAR(Queue);

    if (Mode == MTL_QUEUE_MODE_AVB)
        value |= MAC_RX_AV_QUEUE_ENABLE(Queue);
    else if (Mode == MTL_QUEUE_MODE_DCB)
        value |= MAC_RX_DCB_QUEUE_ENABLE(Queue);

    writel(value, RegBase + MAC_RXQ_CTRL0);
}
/**
 * @name:
 * @Desc:
 * @param {*}
 * @return {*}
 */
void dwmac_dma_rx_chan_op_mode(uint32 RegBase, uint32 Channel, int Mode,
                               int FifoSize, uint8 QMode)
{
    unsigned int rqs = FifoSize / 256 - 1;
    uint32 mtl_rx_op, mtl_rx_int;

    mtl_rx_op = readl(RegBase + MTL_CHAN_RX_OP_MODE(Channel));
    /* Forward Undersized Good Packets */
    mtl_rx_op |= MTL_OP_MODE_FUP;

    if (Mode == SF_MODE) {
        mtl_rx_op |= MTL_OP_MODE_RSF;
    } else {
        mtl_rx_op &= ~MTL_OP_MODE_RSF;
        mtl_rx_op &= MTL_OP_MODE_RTC_MASK;

        if (Mode <= 32)
            mtl_rx_op |= MTL_OP_MODE_RTC_32;
        else if (Mode <= 64)
            mtl_rx_op |= MTL_OP_MODE_RTC_64;
        else if (Mode <= 96)
            mtl_rx_op |= MTL_OP_MODE_RTC_96;
        else
            mtl_rx_op |= MTL_OP_MODE_RTC_128;
    }

    mtl_rx_op &= ~MTL_OP_MODE_RQS_MASK;
    mtl_rx_op |= rqs << MTL_OP_MODE_RQS_SHIFT;

    /* Enable flow control only if each Channel gets 4 KiB or more FIFO and
     * only if Channel is not an AVB Channel.
     */
    if ((FifoSize >= 4096) && (QMode != MTL_QUEUE_MODE_AVB)) {
        unsigned int rfd, rfa;

        mtl_rx_op |= MTL_OP_MODE_EHFC;

        /* Set Threshold for Activating Flow Control to min 2 frames,
         * i.e. 1500 * 2 = 3000 bytes.
         *
         * Set Threshold for Deactivating Flow Control to min 1 frame,
         * i.e. 1500 bytes.
         */
        switch (FifoSize) {
        case 4096:
            /* This violates the above formula because of FIFO size
             * limit therefore overflow may occur in spite of this.
             */
            rfd = 0x03; /* Full-2.5K */
            rfa = 0x01; /* Full-1.5K */
            break;

        case 8192:
            rfd = 0x06; /* Full-4K */
            rfa = 0x0a; /* Full-6K */
            break;

        case 16384:
            rfd = 0x06; /* Full-4K */
            rfa = 0x12; /* Full-10K */
            break;

        default:
            rfd = 0x06; /* Full-4K */
            rfa = 0x1e; /* Full-16K */
            break;
        }

        mtl_rx_op &= ~MTL_OP_MODE_RFD_MASK;
        mtl_rx_op |= rfd << MTL_OP_MODE_RFD_SHIFT;

        mtl_rx_op &= ~MTL_OP_MODE_RFA_MASK;
        mtl_rx_op |= rfa << MTL_OP_MODE_RFA_SHIFT;
    }

    writel(mtl_rx_op, RegBase + MTL_CHAN_RX_OP_MODE(Channel));

    /* Enable MTL RX overflow */
    mtl_rx_int = readl(RegBase + MTL_CHAN_INT_CTRL(Channel));
    writel(mtl_rx_int | MTL_RX_OVERFLOW_INT_EN,
           RegBase + MTL_CHAN_INT_CTRL(Channel));
}
/*
    Mode  transmit store and forward enable or not
    QMode transmit Queue enable or not
    fifo  transmit Queue size
*/
void dwmac_dma_tx_chan_op_mode(uint32 RegBase, uint32 Channel, int Mode,
                               uint32 FifoSize, uint8 QMode)
{
    uint32 tqs;
    uint32 mtl_tx_op = readl(RegBase + MTL_CHAN_TX_OP_MODE(Channel));

    if (FifoSize == 0 || FifoSize > MAC_FIFO_SIZE)
        return ;

    tqs = (FifoSize >> 8) - 1;

    if (Mode == SF_MODE) {
        /* Transmit COE type 2 cannot be done in cut-through Mode. */
        mtl_tx_op |= MTL_OP_MODE_TSF;
    } else {
        mtl_tx_op &= ~MTL_OP_MODE_TSF;
        mtl_tx_op &= MTL_OP_MODE_TTC_MASK;

        /* Set the transmit threshold */
        if (Mode <= 32)
            mtl_tx_op |= MTL_OP_MODE_TTC_32;
        else if (Mode <= 64)
            mtl_tx_op |= MTL_OP_MODE_TTC_64;
        else if (Mode <= 96)
            mtl_tx_op |= MTL_OP_MODE_TTC_96;
        else if (Mode <= 128)
            mtl_tx_op |= MTL_OP_MODE_TTC_128;
        else if (Mode <= 192)
            mtl_tx_op |= MTL_OP_MODE_TTC_192;
        else if (Mode <= 256)
            mtl_tx_op |= MTL_OP_MODE_TTC_256;
        else if (Mode <= 384)
            mtl_tx_op |= MTL_OP_MODE_TTC_384;
        else
            mtl_tx_op |= MTL_OP_MODE_TTC_512;
    }

    /* For an IP with DWC_EQOS_NUM_TXQ == 1, the fields TXQEN and TQS are RO
     * with reset values: TXQEN on, TQS == DWC_EQOS_TXFIFO_SIZE.
     * For an IP with DWC_EQOS_NUM_TXQ > 1, the fields TXQEN and TQS are R/W
     * with reset values: TXQEN off, TQS 256 bytes.
     *
     * TXQEN must be written for multi-Channel operation and TQS must
     * reflect the available fifo size per Queue (total fifo size / number
     * of enabled queues).
     */
    mtl_tx_op &= ~MTL_OP_MODE_TXQEN_MASK;

    if (QMode != MTL_QUEUE_MODE_AVB)
        mtl_tx_op |= MTL_OP_MODE_TXQEN;
    else
        mtl_tx_op |= MTL_OP_MODE_TXQEN_AV;

    mtl_tx_op &= ~MTL_OP_MODE_TQS_MASK;
    mtl_tx_op |= tqs << MTL_OP_MODE_TQS_SHIFT;

    writel(mtl_tx_op, RegBase +  MTL_CHAN_TX_OP_MODE(Channel));
}
/*
    set queue weight.
*/
void dwmac_mtl_tx_chan_set_weight(uint32 RegBase, uint32 Channel, uint32 weight)
{
    uint32 value;

    if (Channel != 0) {
        value = readl(RegBase + MTL_CHAN_EST_CTRL(Channel));
        value &= ~(MTL_ETS_CTRL_CC | MTL_ETS_CTRL_AVALG);
        writel(value, RegBase +  MTL_CHAN_EST_CTRL(Channel));
    }

    value = readl(RegBase + MTL_CHAN_TX_WEIGHT(Channel));
    value &= ~MTL_TXQ_WEIGHT_ISCQW_MASK;
    value |= weight & MTL_TXQ_WEIGHT_ISCQW_MASK;
    writel(value, RegBase +  MTL_CHAN_TX_WEIGHT(Channel));

}

/*
    config abv  queue cbs credit.
    isc: idleSlope
    ssc: sendSlope
    hc:  hiCredit
    lc:  loCredit
*/
void dwmac_mtl_tx_chan_set_cbs(uint32 RegBase, uint32 Channel,
                               uint32 isc, uint32 ssc, uint32 hc, uint32 lc)
{
    uint32 value = readl(RegBase + MTL_CHAN_TX_WEIGHT(Channel));
    value &= ~MTL_TXQ_WEIGHT_ISCQW_MASK;
    value |= isc & MTL_TXQ_WEIGHT_ISCQW_MASK;
    writel(value, RegBase +  MTL_CHAN_TX_WEIGHT(Channel));

    value = readl(RegBase + MTL_CHAN_TX_SSC(Channel));
    value &= ~MTL_SEND_SLP_CRED_SSC_MASK;
    value |= ssc & MTL_SEND_SLP_CRED_SSC_MASK;
    writel(value, RegBase +  MTL_CHAN_TX_SSC(Channel));

    value = readl(RegBase + MTL_CHAN_TX_HC(Channel));
    value &= ~MTL_HIGH_CRED_HC_MASK;
    value |= hc & MTL_HIGH_CRED_HC_MASK;
    writel(value, RegBase +  MTL_CHAN_TX_HC(Channel));

    value = readl(RegBase + MTL_CHAN_TX_LC(Channel));
    value &= ~MTL_LOW_CRED_LC_MASK;
    value |= lc & MTL_LOW_CRED_LC_MASK;
    writel(value, RegBase +  MTL_CHAN_TX_LC(Channel));
    /* enable  */
    value = readl(RegBase + MTL_CHAN_EST_CTRL(Channel));
    value |= MTL_ETS_CTRL_CC | MTL_ETS_CTRL_AVALG;
    writel(value, RegBase +  MTL_CHAN_EST_CTRL(Channel));
}

void dwmac_mtl_tx_chan_set_sp_mode(uint32 RegBase, uint32 Channel)
{
    /* config est of this mtl queue  */
    uint32 value = readl(RegBase + MTL_CHAN_EST_CTRL(Channel));
    value &= ~(MTL_ETS_CTRL_CC | MTL_ETS_CTRL_AVALG);
    writel(value, RegBase +  MTL_CHAN_EST_CTRL(Channel));
    /* map priorities */
    writel(0x03020100, RegBase + MAC_TXQ_PRTY_MAP0);
    writel(0x07060504, RegBase + MAC_TXQ_PRTY_MAP1);
}
/* =====================>MTL BLOCK END<==================== */
/* =====================>  DMA BLOCK  <==================== */
/**
 * @name:
 * @Desc:
 * @param {void } *RegBase
 * @return {*}
 */
sint32 dwmac_dma_reset(uint32 RegBase)
{
    sint32 limit;
    uint32 value = readl(RegBase + DMA_BUS_MODE);

    /* DMA SW reset */
    value |= DMA_BUS_MODE_SFT_RESET;
    writel(value, RegBase + DMA_BUS_MODE);
    limit = 100000;

    while (limit--) {
        if (!(readl(RegBase + DMA_BUS_MODE) & DMA_BUS_MODE_SFT_RESET))
            break;

        Mcu_udelay(1);
    }

    if (limit <= 0) {
        return -1;
    }
#ifdef ETH_DISABLE_IRQ_PULSE
    value = readl(RegBase + DMA_BUS_MODE);
    value &= ~DMA_MODE_INTM_MASK;
    value |= DMA_MODE_INTM_LEVEL;
    writel(value, RegBase + DMA_BUS_MODE);
#endif
    return 0;
}



void dwmac_set_rx_tail_ptr(uint32 RegBase, uint32  tail_ptr, uint32 Channel)
{
    writel(tail_ptr, RegBase + DMA_CHAN_RX_END_ADDR(Channel));
}

void dwmac_set_tx_tail_ptr(uint32 RegBase, uint32  tail_ptr, uint32 Channel)
{
    writel(tail_ptr, RegBase + DMA_CHAN_TX_END_ADDR(Channel));
}

void dwmac_rx_trigger(uint32 RegBase, uint32 Channel)
{
    uint32 tail = readl(RegBase + DMA_CHAN_RX_END_ADDR(Channel));
    writel(tail, RegBase + DMA_CHAN_RX_END_ADDR(Channel));
}


void dwmac_dma_start_tx(uint32 RegBase, uint32 Channel)
{
    uint32 value = readl(RegBase + DMA_CHAN_TX_CONTROL(Channel));

    value |= DMA_CONTROL_ST;
    writel(value, RegBase + DMA_CHAN_TX_CONTROL(Channel));

    value = readl(RegBase + MAC_CONFIG);
    value |= MAC_CONFIG_TE;
    writel(value, RegBase + MAC_CONFIG);
}

void dwmac_dma_stop_tx(uint32 RegBase, uint32 Channel)
{
    uint32 value = readl(RegBase + DMA_CHAN_TX_CONTROL(Channel));

    value &= ~DMA_CONTROL_ST;
    writel(value, RegBase + DMA_CHAN_TX_CONTROL(Channel));

    value = readl(RegBase + MAC_CONFIG);
    value &= ~MAC_CONFIG_TE;
    writel(value, RegBase + MAC_CONFIG);
}

void dwmac_dma_start_rx(uint32 RegBase, uint32 Channel)
{
    uint32 value = readl(RegBase + DMA_CHAN_RX_CONTROL(Channel));

    value |= DMA_CONTROL_SR;

    writel(value, RegBase + DMA_CHAN_RX_CONTROL(Channel));

    value = readl(RegBase + MAC_CONFIG);
    value |= MAC_CONFIG_RE;
    writel(value, RegBase + MAC_CONFIG);
}

void dwmac_dma_stop_rx(uint32 RegBase, uint32 Channel)
{
    uint32 value = readl(RegBase + DMA_CHAN_RX_CONTROL(Channel));

    value &= ~DMA_CONTROL_SR;
    writel(value, RegBase + DMA_CHAN_RX_CONTROL(Channel));

    value = readl(RegBase + MAC_CONFIG);
    value &= ~MAC_CONFIG_RE;
    writel(value, RegBase + MAC_CONFIG);
}

void dwmac_set_tx_ring_len(uint32 RegBase, uint32 len, uint32 Channel)
{
    writel(len, RegBase + DMA_CHAN_TX_RING_LEN(Channel));
}

void dwmac_set_rx_ring_len(uint32 RegBase, uint32 len, uint32 Channel)
{
    writel(len, RegBase + DMA_CHAN_RX_RING_LEN(Channel));
}

void dwmac_enable_dma_irq(uint32 RegBase, uint32 Channel, boolean rx, boolean tx)
{
    uint32 irq_enable_mask = DMA_CHAN_INTR_DEFAULT_MASK;
    /* clearn irq */
    writel(0x3fffc7, RegBase + DMA_CHAN_STATUS(Channel));

    /* enable irq */
    if (!rx) {
        irq_enable_mask &= ~DMA_CHAN_INTR_ENA_RIE;
    }

    if (!tx) {
        irq_enable_mask &= ~DMA_CHAN_INTR_ENA_TIE;
    }

    writel(irq_enable_mask, RegBase + DMA_CHAN_INTR_ENA(Channel));
}


void dwmac_disable_dma_irq(uint32 RegBase, uint32 Channel)
{
    writel(0, RegBase + DMA_CHAN_INTR_ENA(Channel));
}

void dwmac_dma_init_rx_chan(uint32 RegBase, uint32  base_ptr, uint32 Channel)
{
    uint32 value = readl(RegBase + DMA_CHAN_RX_CONTROL(Channel));
    value &= ~DMA_BUS_MODE_PBL_MASK;
    value = value | (16 << DMA_BUS_MODE_RPBL_SHIFT);
    writel(value, RegBase + DMA_CHAN_RX_CONTROL(Channel));

    writel(base_ptr, RegBase + DMA_CHAN_RX_BASE_ADDR(Channel));
}

void dwmac_dma_init_tx_chan(uint32 RegBase, uint32  base_ptr, uint32 Channel)
{
    uint32 value;

    value = readl(RegBase + DMA_CHAN_TX_CONTROL(Channel));
    /*
        In e3 chip when data buff place in sdram set max tx burst
        length less than or equal 16，Unlimited if on IRAM.
     */
    value &= ~DMA_BUS_MODE_PBL_MASK;
    value = value | (16 << DMA_BUS_MODE_PBL_SHIFT);

    /* Enable OSP to get best performance */
    value |= DMA_CONTROL_OSP;

    writel(value, RegBase + DMA_CHAN_TX_CONTROL(Channel));
    writel(base_ptr, RegBase + DMA_CHAN_TX_BASE_ADDR(Channel));
}

void dwmac_dma_init_channel(uint32 RegBase, uint32 Flags, \
                            uint32 Channel, uint32 skip)
{
    uint32 value;

    /* common Channel control register config */
    value = readl(RegBase + DMA_CHAN_CONTROL(Channel));

    if (Flags & DMA_BUS_MODE_PBL)
        value = value | DMA_BUS_MODE_PBL;
    else
        value = value & (~DMA_BUS_MODE_PBL);

    value |= ((skip << DMA_CONTROL_DSL_SHIFT) & DMA_CONTROL_DSL_MASK);

    writel(value, RegBase + DMA_CHAN_CONTROL(Channel));

}
/*
    DMA_SYS_BUS_FB
    DMA_SYS_BUS_MB
    DMA_SYS_BUS_AAL
    DMA_SYS_BUS_EAME
    DMS_SysBus_param;
*/
void dwmac_dma_bus_init(uint32 RegBase, uint32 Flags)
{
    uint32 value = readl(RegBase + DMA_SYS_BUS_MODE);

    /* Set the Fixed burst Mode */
    if (Flags & DMA_SYS_BUS_FB)
        value |= DMA_SYS_BUS_FB;

    /* Mixed Burst has no effect when fb is set */
    if (Flags & DMA_SYS_BUS_MB)
        value |= DMA_SYS_BUS_MB;

    if (Flags & DMA_SYS_BUS_AAL)
        value |= DMA_SYS_BUS_AAL;

    if (Flags & DMA_SYS_BUS_EAME)
        value |= DMA_SYS_BUS_EAME;

    if (Flags & DMA_AXI_BLEN256)
        value |= DMA_AXI_BLEN256;
    else if (Flags & DMA_AXI_BLEN128)
        value |= DMA_AXI_BLEN128;
    else if (Flags & DMA_AXI_BLEN64)
        value |= DMA_AXI_BLEN64;
    else if (Flags & DMA_AXI_BLEN32)
        value |= DMA_AXI_BLEN32;
    else if (Flags & DMA_AXI_BLEN16)
        value |= DMA_AXI_BLEN16;
    else if (Flags & DMA_AXI_BLEN8)
        value |= DMA_AXI_BLEN8;
    else if (Flags & DMA_AXI_BLEN4)
        value |= DMA_AXI_BLEN4;

    writel(value, RegBase + DMA_SYS_BUS_MODE);
}
/**
 * @description:
 * @param {uint32} RegBase
 * @param {uint32} Channel
 * @return {*}
 */
uint32 dwmac_dma_rx_state_get(uint32 RegBase, uint32 Channel)
{
    uint32 state = DMX_RX_STOP;

    switch (Channel) {
    case 0:
    case 1:
    case 2:
        state = (readl(RegBase + DMA_DEBUG_STATUS_0) >> (Channel * 8 + 8)) & 0xF;
        break;

    case 3:
    case 4:
    case 5:
        state = (readl(RegBase + DMA_DEBUG_STATUS_2) >> ((Channel - 3) * 8)) & 0xF;
        break;

    case 6:
    case 7:
        state = (readl(RegBase + DMA_DEBUG_STATUS_2) >> ((Channel - 6) * 8)) & 0xF;
        break;

    default:
        break;
    }

    return state;
}

void dwmac_dump_dma_regs(uint32 RegBase, int Channel)
{
    DBG("Reg=%p,Val=%p\n", DMA_STATUS,
        readl(RegBase + DMA_STATUS));
    DBG("Reg=%p,Val=%p\n", DMA_DEBUG_STATUS_0,
        readl(RegBase + DMA_DEBUG_STATUS_0));


    DBG("Reg=%p,Val=%p\n", DMA_CHAN_CONTROL(Channel),
        readl(RegBase + DMA_CHAN_CONTROL(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_TX_CONTROL(Channel),
        readl(RegBase + DMA_CHAN_TX_CONTROL(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_RX_CONTROL(Channel),
        readl(RegBase + DMA_CHAN_RX_CONTROL(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_TX_BASE_ADDR(Channel),
        readl(RegBase + DMA_CHAN_TX_BASE_ADDR(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_RX_BASE_ADDR(Channel),
        readl(RegBase + DMA_CHAN_RX_BASE_ADDR(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_TX_END_ADDR(Channel),
        readl(RegBase + DMA_CHAN_TX_END_ADDR(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_RX_END_ADDR(Channel),
        readl(RegBase + DMA_CHAN_RX_END_ADDR(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_TX_RING_LEN(Channel),
        readl(RegBase + DMA_CHAN_TX_RING_LEN(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_RX_RING_LEN(Channel),
        readl(RegBase + DMA_CHAN_RX_RING_LEN(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_INTR_ENA(Channel),
        readl(RegBase + DMA_CHAN_INTR_ENA(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_RX_WATCHDOG(Channel),
        readl(RegBase + DMA_CHAN_RX_WATCHDOG(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_SLOT_CTRL_STATUS(Channel),
        readl(RegBase + DMA_CHAN_SLOT_CTRL_STATUS(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_CUR_TX_DESC(Channel),
        readl(RegBase + DMA_CHAN_CUR_TX_DESC(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_CUR_RX_DESC(Channel),
        readl(RegBase + DMA_CHAN_CUR_RX_DESC(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_CUR_TX_BUF_ADDR(Channel),
        readl(RegBase + DMA_CHAN_CUR_TX_BUF_ADDR(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_CUR_RX_BUF_ADDR(Channel),
        readl(RegBase + DMA_CHAN_CUR_RX_BUF_ADDR(Channel)));
    DBG("Reg=%p,Val=%p\n", DMA_CHAN_STATUS(Channel),
        readl(RegBase + DMA_CHAN_STATUS(Channel)));;
}

void dwmac_rx_watchdog(uint32 RegBase, uint32 riwt, uint32 Channel)
{
    writel(riwt, RegBase + DMA_CHAN_RX_WATCHDOG(Channel));
}

static uint32 get_bfsize(uint32 mtu)
{
    int ret;

    if (mtu >= BUFF_SIZE_8KB)
        ret = BUFF_SIZE_16KB;
    else if (mtu >= BUFF_SIZE_4KB)
        ret = BUFF_SIZE_8KB;
    else if (mtu >= BUFF_SIZE_2KB)
        ret = BUFF_SIZE_4KB;
    else if (mtu > DEFAULT_BUFSIZE)
        ret = BUFF_SIZE_2KB;
    else
        ret = DEFAULT_BUFSIZE;

    return ret;
}

void dwmac_dma_tx_chan_weight(uint32 RegBase, uint32 Channel, uint32 twc)
{
    uint32 val = readl(RegBase + DMA_CHAN_TX_CONTROL(Channel));
    val &= ~DMA_CONTROL_TCW_MASK;
    val |=  (twc << DMA_CONTROL_TCW_SHIFT) & DMA_CONTROL_TCW_MASK;
    writel(val, RegBase + DMA_CHAN_TX_CONTROL(Channel));

    val = readl(RegBase + DMA_BUS_MODE);
    val &= ~DMA_BUS_TAA_MASK;
    val |=  (1 << DMA_BUS_TAA_SHIFT) & DMA_BUS_TAA_MASK;
    writel(val, RegBase + DMA_BUS_MODE);
}

void dwmac_set_bfsize(uint32 RegBase, uint32 mtu, uint32 Channel)
{
    uint32 value = readl(RegBase + DMA_CHAN_RX_CONTROL(Channel));
    uint32 BuffSize = get_bfsize(mtu);
    value &= ~DMA_RBSZ_MASK;
    value |= (BuffSize << DMA_RBSZ_SHIFT) & DMA_RBSZ_MASK;

    writel(value, RegBase + DMA_CHAN_RX_CONTROL(Channel));
}
/* =====================>DMA BLOCK END<==================== */

#define MII_BUSY 0x00000001
#define MII_WRITE 0x00000002
#define MII_DATA_MASK 0xFFFF

/* GMAC4 defines */
#define MII_MAC_GOC_SHIFT       2
#define MII_MAC_REG_ADDR_SHIFT  16
#define MII_MAC_WRITE           (1 << MII_MAC_GOC_SHIFT)
#define MII_MAC_READ            (3 << MII_MAC_GOC_SHIFT)
#define MII_MAC_C45E            0x02

#define MII_ADDR_OFFSET         21
#define MII_ADDR_MASK           (0x1F<<MII_ADDR_OFFSET)
#define MII_REG_OFFSET          16
#define MII_REG_MASK            (0x1F<<MII_REG_OFFSET)
#define MII_CLK_CSR_OFFSET      8
#define MII_CLK_CSR_MASK        (0xf<<8)

/* Or MII_ADDR_C45 into regnum for read/write on mii_bus to enable the 21 bit
   IEEE 802.3ae clause 45 addressing Mode used by 10GIGE phy chips. */
#define MII_ADDR_C45 (1<<30)
#define MII_DEVADDR_C45_SHIFT   16
#define MII_REGADDR_C45_MASK    0xFFFF
#define CLK_CSR     0x5


static inline sint32 poll_mdio_busy(uint32 RegBase, uint32 Timeout)
{
    // The timeout time is unchanged, and the query frequency is increased
    uint32 limit = Timeout*1000;

    do {
        if (readl(RegBase) & MII_BUSY) {
            Mcu_udelay(1);
        } else {
            return 0;
        }

        limit--;
    } while (limit);

    return -1;
}
/**
 * @description: this function support to Access Clause 45 Phy
 * @param {uint8} PhyAddr
 * @param {uint8} Device
 * @param {uint16} PhyReg
 * @return {*}
 */
sint32 mac_mdio_read(uint32  RegBase, uint8 PhyAddr, uint8 Device, uint16 PhyReg)
{


    uint32 mii_address = (uint32)RegBase + MAC_MDIO_ADDR;
    uint32 mii_data = (uint32)RegBase + MAC_MDIO_DATA;
    uint32 value = MII_BUSY;
    sint32 data = 0;

    value |= (PhyAddr << MII_ADDR_OFFSET) & MII_ADDR_MASK;
    value |= (CLK_CSR << MII_CLK_CSR_OFFSET)& MII_CLK_CSR_MASK;
    value |= MII_MAC_READ;

    if (PHY_CLAUSE_22 == Device) {
        value |= (PhyReg  << MII_REG_OFFSET) & MII_REG_MASK;
    } else {
        value |= MII_MAC_C45E;
        value |= (Device  << MII_REG_OFFSET) & MII_REG_MASK;
        data |= (PhyReg & MII_REGADDR_C45_MASK) << MII_DEVADDR_C45_SHIFT;
    }

    if (poll_mdio_busy(mii_address, 10000)) {
        DBG("PHY awalys busyed.\n");
        return -1;
    }


    writel(data, mii_data);
    writel(value, mii_address);

    if (poll_mdio_busy(mii_address, 10000))
        return -2;

    /* Read the data from the MII data register */
    data = (sint32)(readl(mii_data) & MII_DATA_MASK);

    return data;
}

/**
 * @description:this function support to Access Clause 45 Phy when Device < 32
 * @param {uint8} PhyAddr
 * @param {uint8} phyregspace
 * @param {uint32} PhyReg
 * @param {uint16} PhyData
 * @return {*}
 */
sint32 mac_mdio_write(uint32  RegBase, uint8 PhyAddr, uint8 Device, uint16 PhyReg, uint16 PhyData)
{

    uint32 mii_address = (uint32)RegBase + MAC_MDIO_ADDR;
    uint32 mii_data = (uint32)RegBase + MAC_MDIO_DATA;

    uint32 value = MII_BUSY;
    uint32 data = PhyData & 0xFFFF;

    value |= (PhyAddr << MII_ADDR_OFFSET) & MII_ADDR_MASK;
    value |= (CLK_CSR << MII_CLK_CSR_OFFSET) & MII_CLK_CSR_MASK;
    value |= MII_MAC_WRITE;

    if (PHY_CLAUSE_22 == Device) {
        value |= (PhyReg << MII_REG_OFFSET) & MII_REG_MASK;
    } else {
        value |= MII_MAC_C45E;
        value |= (Device << MII_REG_OFFSET) & MII_REG_MASK;
        data |= (PhyReg & MII_REGADDR_C45_MASK) << MII_DEVADDR_C45_SHIFT;
    }

    /* Wait until any existing MII operation is complete */
    if (poll_mdio_busy(mii_address, 10000)) {
        return -1;
    }

    /* Set the MII address register to write */
    writel(data,  mii_data);
    writel(value, mii_address);

    /* Wait until any existing MII operation is complete */
    return poll_mdio_busy(mii_address, 10000);
}

/**
 * Description:
 * @RegBase: points to the reg Addr
 */
boolean dwmac_access_test(uint32  RegBase)
{
    return (readl(RegBase + MAC_VERSION) & 0xFF) == 0x52;
}
/**
 * @description:
 * @param {Eth_RxStatsType*} Stats
 * @return {*}
 */
void rx_stats_update(uint32  RegBase, Eth_RxStatsType *Stats)
{
    /*
        When the upper layer does not need statistical data packets,
        the hardware still needs to read to avoid MMC overflow interruption;
        therefore, when the upper layer does not need statistical data packets,
        NULL will be passed in here, so a dummy read here has no effect on the result
    */
    if (Stats != NULL_PTR) {
        Stats->RxStatsDropEvents += readl(RegBase + MAC_PACKETS_RX_CONUT_DROP_PKT);
        Stats->RxStatsOctets += readl(RegBase + MAC_PACKETS_RX_CONUT_ALL_BYTES);
        Stats->RxStatsPkts += readl(RegBase + MAC_PACKETS_RX_CONUT_ALL_PKT);
        Stats->RxStatsPkts -= readl(RegBase + MAC_PACKETS_RX_CONUT_BAD_PKT);

        Stats->RxStatsBroadcastPkts += readl(RegBase + MAC_PACKETS_RX_CONUT_BROADCAST);
        Stats->RxStatsMulticastPkts += readl(RegBase + MAC_PACKETS_RX_CONUT_MULTICAST);
        Stats->RxStatsCrcAlignErrors += readl(RegBase + MAC_PACKETS_RX_CONUT_CRC_ERR);
        Stats->RxStatsCrcAlignErrors += readl(RegBase + MAC_PACKETS_RX_CONUT_ALIGN_ERR);
        Stats->RxStatsUndersizePkts += readl(RegBase + MAC_PACKETS_RX_CONUT_UNDER_PKT);
        Stats->RxStatsOversizePkts += readl(RegBase + MAC_PACKETS_RX_CONUT_OVER_PKT);

        Stats->RxStatsFragments += readl(RegBase + MAC_PACKETS_RX_CONUT_FRAG_ERR);
        Stats->RxStatsJabbers += readl(RegBase + MAC_PACKETS_RX_CONUT_JABBER_ERR);
        /* Duplex Mode will not happen */
        Stats->RxStatsCollisions = 0;
        Stats->RxStatsPkts64Octets += readl(RegBase + MAC_PACKETS_RX_CONUT_64);
        Stats->RxStatsPkts65to127Octets += readl(RegBase + MAC_PACKETS_RX_CONUT_65_127);
        Stats->RxStatsPkts128to255Octets += readl(RegBase + MAC_PACKETS_RX_CONUT_128_255);
        Stats->RxStatsPkts256to511Octets += readl(RegBase + MAC_PACKETS_RX_CONUT_256_511);
        Stats->RxStatsPkts512to1023Octets += readl(RegBase + MAC_PACKETS_RX_CONUT_512_1023);
        Stats->RxStatsPkts1024to1518Octets += readl(RegBase + MAC_PACKETS_RX_CONUT_1024_MAX);
        Stats->RxUnicastFrames += readl(RegBase + MAC_PACKETS_RX_CONUT_UNICAST);
    } else {
        readl(RegBase + MAC_PACKETS_RX_CONUT_DROP_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_ALL_BYTES);
        readl(RegBase + MAC_PACKETS_RX_CONUT_ALL_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_BAD_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_BROADCAST);
        readl(RegBase + MAC_PACKETS_RX_CONUT_MULTICAST);
        readl(RegBase + MAC_PACKETS_RX_CONUT_CRC_ERR);
        readl(RegBase + MAC_PACKETS_RX_CONUT_ALIGN_ERR);
        readl(RegBase + MAC_PACKETS_RX_CONUT_UNDER_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_OVER_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_FRAG_ERR);
        readl(RegBase + MAC_PACKETS_RX_CONUT_JABBER_ERR);
        readl(RegBase + MAC_PACKETS_RX_CONUT_64);
        readl(RegBase + MAC_PACKETS_RX_CONUT_65_127);
        readl(RegBase + MAC_PACKETS_RX_CONUT_128_255);
        readl(RegBase + MAC_PACKETS_RX_CONUT_256_511);
        readl(RegBase + MAC_PACKETS_RX_CONUT_512_1023);
        readl(RegBase + MAC_PACKETS_RX_CONUT_1024_MAX);
        readl(RegBase + MAC_PACKETS_RX_CONUT_UNICAST);
    }
}
/**
 * @description:
 * @param {Eth_TxStatsType*} Stats
 * @return {*}
 */
void tx_stats_update(uint32  RegBase, Eth_TxStatsType *Stats)
{
    /*
        When the upper layer does not need statistical data packets,
        the hardware still needs to read to avoid MMC overflow interruption;
        therefore, when the upper layer does not need statistical data packets,
        NULL will be passed in here, so a dummy read here has no effect on the result
    */
    if (Stats != NULL_PTR) {
        Stats->TxNumberOfOctets += readl(RegBase + MAC_PACKETS_TX_CONUT_ALL_BYTES);
        Stats->TxNUcastPkts += readl(RegBase + MAC_PACKETS_TX_CONUT_BROADCAST);
        Stats->TxNUcastPkts += readl(RegBase + MAC_PACKETS_TX_CONUT_MULTICAST);
        Stats->TxUniCastPkts += readl(RegBase + MAC_PACKETS_TX_CONUT_UNICAST);
    } else {
        readl(RegBase + MAC_PACKETS_TX_CONUT_ALL_BYTES);
        readl(RegBase + MAC_PACKETS_TX_CONUT_BROADCAST);
        readl(RegBase + MAC_PACKETS_TX_CONUT_MULTICAST);
        readl(RegBase + MAC_PACKETS_TX_CONUT_UNICAST);
    }
}
/**
 * @description:
 * @param {Eth_CounterType*} Stats
 * @return {*}
 */
void controller_counter_update(uint32  RegBase, Eth_CounterType *Stats)
{
    /*
        When the upper layer does not need statistical data packets,
        the hardware still needs to read to avoid MMC overflow interruption;
        therefore, when the upper layer does not need statistical data packets,
        NULL will be passed in here, so a dummy read here has no effect on the result
    */
    if (Stats != NULL_PTR) {
        Stats->DropPktBufOverrun += readl(RegBase + MAC_PACKETS_RX_CONUT_DROP_PKT);
        Stats->DropPktCrc += readl(RegBase + MAC_PACKETS_RX_CONUT_CRC_ERR);
        Stats->UndersizePkt += readl(RegBase + MAC_PACKETS_RX_CONUT_UNDER_PKT);
        Stats->OversizePkt += readl(RegBase + MAC_PACKETS_TX_CONUT_OVER_PKT);
        Stats->OversizePkt += readl(RegBase + MAC_PACKETS_RX_CONUT_OVER_PKT);
        Stats->AlgnmtErr += readl(RegBase + MAC_PACKETS_RX_CONUT_ALIGN_ERR);
        Stats->SqeTestErr = 0;
        Stats->DiscInbdPkt += readl(RegBase + MAC_PACKETS_RX_CONUT_DROP_PKT);
        Stats->ErrInbdPkt += readl(RegBase + MAC_PACKETS_RX_CONUT_BAD_PKT);
        Stats->DiscOtbdPkt += readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_COLL);
        Stats->DiscOtbdPkt += readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_CARR);
        Stats->ErrOtbdPkt += readl(RegBase + MAC_PACKETS_TX_CONUT_ALL_PKT);
        Stats->ErrOtbdPkt -= readl(RegBase + MAC_PACKETS_TX_CONUT_GOOD_PKT);
        Stats->SnglCollPkt += readl(RegBase + MAC_PACKETS_TX_CONUT_SINGL_COLL);
        Stats->MultCollPkt += readl(RegBase + MAC_PACKETS_TX_CONUT_MULT_COLL);
        Stats->DfrdPkt += readl(RegBase + MAC_PACKETS_TX_CONUT_DFRD_COLL);
        Stats->LatCollPkt += readl(RegBase + MAC_PACKETS_TX_CONUT_LATE_COLL);
        Stats->HwDepCtr0 = 0;
        Stats->HwDepCtr1 = 0;
        Stats->HwDepCtr2 = 0;
        Stats->HwDepCtr3 = 0;
    } else {
        readl(RegBase + MAC_PACKETS_RX_CONUT_DROP_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_CRC_ERR);
        readl(RegBase + MAC_PACKETS_RX_CONUT_UNDER_PKT);
        readl(RegBase + MAC_PACKETS_TX_CONUT_OVER_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_OVER_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_ALIGN_ERR);
        readl(RegBase + MAC_PACKETS_RX_CONUT_DROP_PKT);
        readl(RegBase + MAC_PACKETS_RX_CONUT_BAD_PKT);
        readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_CARR);
        readl(RegBase + MAC_PACKETS_TX_CONUT_ALL_PKT);
        readl(RegBase + MAC_PACKETS_TX_CONUT_GOOD_PKT);
        readl(RegBase + MAC_PACKETS_TX_CONUT_SINGL_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_MULT_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_DFRD_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_LATE_COLL);
    }
}

/**
 * @description:
 * @param {uint32 } RegBase
 * @param {Eth_TxErrorCounterValuesType} *count
 * @return {*}
 */
void tx_error_count_update(uint32  RegBase, Eth_TxErrorCounterValuesType *count)
{
    /*
        When the upper layer does not need statistical data packets,
        the hardware still needs to read to avoid MMC overflow interruption;
        therefore, when the upper layer does not need statistical data packets,
        NULL will be passed in here, so a dummy read here has no effect on the result
    */
    if (count != NULL_PTR) {

        count->TxDroppedNoErrorPkts = 0;
        count->TxDroppedErrorPkts += readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_CARR);
        count->TxDeferredTrans += readl(RegBase + MAC_PACKETS_TX_CONUT_DFRD_COLL);
        count->TxSingleCollision += readl(RegBase + MAC_PACKETS_TX_CONUT_SINGL_COLL);
        count->TxMultipleCollision += readl(RegBase + MAC_PACKETS_TX_CONUT_MULT_COLL);
        count->TxLateCollision += readl(RegBase + MAC_PACKETS_TX_CONUT_LATE_COLL);
        count->TxExcessiveCollison += readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_COLL);
    } else {
        readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_CARR);
        readl(RegBase + MAC_PACKETS_TX_CONUT_DFRD_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_SINGL_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_MULT_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_LATE_COLL);
        readl(RegBase + MAC_PACKETS_TX_CONUT_DROP_PKT_COLL);
    }
}

void mac_irq_handler(uint32  RegBase)
{

    uint32 status = readl(RegBase + MAC_INT_STATUS);
    uint32 enable = readl(RegBase + MAC_INT_EN);
    uint32 mmc_copy = status;
    /* Discard disabled bits */
    status &= enable;

    /* Clear the PMT bits 5 and 6 by reading the PMT status reg */
    if (status & MAC_STATUS_PMT) {
        readl(RegBase + MAC_PMT);
    }

    if (mmc_copy & MAC_STATUS_MMC) {
        /* read to clr */
        if (status & MAC_STATUS_MMC_IPC)
            readl(RegBase + MAC_MMC_IPC_INTR_STA);

        if (status & MAC_STATUS_MMC_TX)
            readl(RegBase + MAC_MMC_TX_INTR_STA);

        if (status & MAC_STATUS_MMC_RX)
            readl(RegBase + MAC_MMC_RX_INTR_STA);
    }

    /* MAC tx/rx EEE LPI entry/exit interrupts */
    if (status & MAC_STATUS_LPI) {
        /* Clear LPI interrupt by reading MAC_LPI_Control_Status */
        readl(RegBase + MAC_LPI_CTRL_STATUS);
    }

    readl(RegBase + MAC_PCS_STATUS);

    if (status & MAC_INT_RGSMIIS)
        readl(RegBase + MAC_PHYIF_CONTROL_STATUS);

}

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
