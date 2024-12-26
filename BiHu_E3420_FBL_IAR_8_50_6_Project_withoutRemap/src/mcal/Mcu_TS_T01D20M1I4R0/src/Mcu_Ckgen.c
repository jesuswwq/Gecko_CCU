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

#ifdef __cplusplus
extern "C" {
#endif

#include "RegHelper.h"
#include "Ckgen_Reg.h"
#include "Mcu_Ckgen.h"
#include "Mcu_Soc.h"
#include "debug.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_CKGEN_C_VENDOR_ID    0x8C
#define MCU_CKGEN_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_CKGEN_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_CKGEN_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_CKGEN_C_SW_MAJOR_VERSION    1
#define MCU_CKGEN_C_SW_MINOR_VERSION    0
#define MCU_CKGEN_C_SW_PATCH_VERSION    0
/* Version Info End */

#define CKGEN_POLLs    10000u

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
#ifdef MCU_CKGEN_RESERVED_FUNCs

/*                             gfree
 * clk_in4   ---> CG(main) -1-> |\
 *                              | |---(pre_div[7:0])--------->clk_out
 * clk_in0 ->|\           -0--> |/
 * clk_in1 ->||           | clk_src_sel[2]
 * clk_in2 ->||-> CG(pre)--
 * clk_in3 ->|/
 *       clk_src_sel[1:0]
 *
 * clk_in0 (usually 24MHz) by default.
 */
void ckgen_ip_slice_cfg(uint32 base, uint32 slice_id,
                        uint32 src_sel, uint32 div)
{
    uint32 ctl_addr = base + IP_SLICE_CTL_OFF(slice_id);
    uint32 ctl = readl(ctl_addr);
    uint32 cur_sel = GFV_IP_SLICE_CTL_CLK_SRC_SEL(ctl);
    uint32 cur_div = GFV_IP_SLICE_CTL_DIV_NUM(ctl);
    uint32 tms = 0;

    /* the default div is '1' and ROM alwasy make it no change or make it bigger
     * We do the div provision before source switch to avoid too high freqency in
     * the middle of the process */
    /* Div_num can be changed on-the-fly */
    if (cur_div != div) {
        ctl &= ~FM_IP_SLICE_CTL_DIV_NUM;
        ctl |= FV_IP_SLICE_CTL_DIV_NUM(div);
        writel(ctl, ctl_addr);

        while ((readl(ctl_addr) & BM_IP_SLICE_CTL_DIV_CHG_BUSY)
               && (tms++ < CKGEN_POLLs));
    }

    if ((cur_sel == src_sel) || (src_sel > 4u) || (src_sel == 4 && cur_sel >= 4)) {
        //  DBG("%s: no need to switch src \n", __FUNCTION__);
        return;
    }

    if ((cur_sel & (0x01u << 2)) && (src_sel < 4)) {    /* from clk_in4 to clk0-3 */
        /* Make sure CG is enabled. */
        ctl |= BM_IP_SLICE_CTL_MAIN_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_IP_SLICE_CTL_MAIN_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        /* Make sure both clk_in0~clk_in3(the used one) and clk_in4 are active. */

        /* set reg_pre_en to 1'b0, wait pre_en_ack to 1'b0.*/
        ctl &= ~BM_IP_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_IP_SLICE_CTL_PRE_EN_STATUS)
               && (tms++ < CKGEN_POLLs));

        /* set clk_src_sel[1:0] to select the clock.*/
        ctl &= ~FV_IP_SLICE_CTL_CLK_SRC_SEL(3);
        ctl |= FV_IP_SLICE_CTL_CLK_SRC_SEL(src_sel & 0x3);
        writel(ctl, ctl_addr);
        /*set reg_pre_en to 1'b1, wait pre_en_ack to 1'b1.*/
        ctl |= BM_IP_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_IP_SLICE_CTL_PRE_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        /* set clk_src_sel[2] to 1'b0. */
        ctl &= ~FV_IP_SLICE_CTL_CLK_SRC_SEL(4);
        writel(ctl, ctl_addr);
        /* until mux D0 active */
        tms = 0;

        while (((readl(ctl_addr) & BM_IP_SLICE_CTL_MUX_D0_ACTIVE) == 0)
               && (tms++ < CKGEN_POLLs));

    } else if ((4u == src_sel) && (cur_sel < 4)) { /* from clk_in0-3 to clk_in4 */
        /* > Make sure CG is enabled. */
        ctl |= BM_IP_SLICE_CTL_MAIN_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_IP_SLICE_CTL_MAIN_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        /* make sure both clk_in0~clk_in3(the used one) and clk_in4 are active. */

        /* set clk_src_sel[2] to 1'b1. */
        /* this mux is glitch-less */
        ctl |= FV_IP_SLICE_CTL_CLK_SRC_SEL(4);
        writel(ctl, ctl_addr);

        /* until mux D0 de-active */
        tms = 0;

        while ((readl(ctl_addr) & BM_IP_SLICE_CTL_MUX_D0_ACTIVE)
               && (tms++ < CKGEN_POLLs));
    } else {    /* between clk_in0-3 */
        ctl &= ~BM_IP_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_IP_SLICE_CTL_PRE_EN_STATUS)
               && (tms++ < CKGEN_POLLs));

        ctl &= ~FM_IP_SLICE_CTL_CLK_SRC_SEL;
        ctl |= FV_IP_SLICE_CTL_CLK_SRC_SEL(src_sel & 0x03u);
        writel(ctl, ctl_addr);
        ctl |= BM_IP_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_IP_SLICE_CTL_PRE_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));
    }
}
#endif
/*
 * Bus clk slice
 *                                                          gfree
 * clk_in4   -----> CG(main) --------------X--------1------> |\
 *                                |                          ||----->clk_out
 *                                |                      -0->|/
 *                                |      gfree  _______  |  clk_src_sel[3]
 *                                ---1---> |\   |     |__|__> m
 *                                         ||-->|Sync |->n
 *                                ---0---> |/   |Div  |->p
 * clk_in0 ->|\                   |  src_sel[2] |_____|->q
 * clk_in1 ->||                   |             (div_mnpq)
 * clk_in2 ->||-> CG-->(div[4:0])-|
 * clk_in3 ->|/  (pre)   (pre)
 *       clk_src_sel[1:0]
 *
 * clk_in0 (usually 24MHz) by default.
 */
void ckgen_bus_slice_cfg(uint32 base, uint32 slice_id,
                         uint32 src_sel, uint32 pre_div, uint32 mnpq)
{
    uint32 ctl_addr = base +  BUS_SLICE_CTL_OFF(slice_id);
    uint32 ctl = readl(ctl_addr);
    uint32 cur_sel = GFV_BUS_SLICE_CTL_CLK_SRC_SEL(ctl);
    uint32 tms = 0;

    if (src_sel > 4) {
        return;
    }

    if (((cur_sel & 0xcu) != 0) && ((cur_sel & 0xcu) != 0x4u)) {
        return;
    }

    if (((cur_sel & (0x01u << 2)) && (src_sel == 4))
        || (((cur_sel & 0xcu) == 0) && (src_sel < 4)
            && (src_sel == (cur_sel & 0x3)))) {
        return;
    }

    /* update divs then change source in case overshot on freq. */
    if (mnpq) {
        uint32 v = readl(base + BUS_SLICE_SYNC_CTL_OFF(slice_id));
        v &= ~(FM_BUS_SLICE_SYNC_CTL_DIV_M_NUM | FM_BUS_SLICE_SYNC_CTL_DIV_N_NUM
               | FM_BUS_SLICE_SYNC_CTL_DIV_P_NUM | FM_BUS_SLICE_SYNC_CTL_DIV_Q_NUM);
        v |= mnpq;
        writel(v, base + BUS_SLICE_SYNC_CTL_OFF(slice_id));
    }

    if (4u == src_sel) {    /* clk_in0-3 -> clk_in4 */
        /* Make sure CG is enabled. */
        ctl |= BM_BUS_SLICE_CTL_MAIN_EN;
        writel(ctl, ctl_addr);

        /* is it ok to do enable-polling with MAIN_EN asserted already per design */
        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_MAIN_EN_STATUS) == 0 &&
               (tms++ < CKGEN_POLLs));

        /* Make sure both clk_in0~clk_in3(the used one) and clk_in4 are active. */

        /* set clk_src_sel[3] to 1'b0, clk_src_sel[2] to 1'b1. */
        ctl |= FV_BUS_SLICE_CTL_CLK_SRC_SEL(0x4U);
        writel(ctl, ctl_addr);

        tms = 0;

        /* until mux d0 de-active */
        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_MUX_D0_ACTIVE) &&
               (tms++ < CKGEN_POLLs));
    } else if (cur_sel & (0x01u << 2)) {    /* clk_in4 -> clk_in0-3 */
        /* Make sure CG is enabled.
           Make sure both clk_in0~clk_in3(the used one) and clk_in4 are active.*/
        ctl |= BM_BUS_SLICE_CTL_MAIN_EN;
        writel(ctl, ctl_addr);

        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_MAIN_EN_STATUS) == 0 &&
               (tms++ < CKGEN_POLLs));

        /* set reg_pre_en to 1'b0, wait pre_en_ack to 1'b0. */
        ctl &= ~BM_BUS_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_EN_STATUS)
               && (tms++ < CKGEN_POLLs));

        ctl &= ~FM_BUS_SLICE_CTL_CLK_SRC_SEL;
        /* set clk_src_sel[1:0] to select the clock.*/
        ctl |= FV_BUS_SLICE_CTL_CLK_SRC_SEL(0x4u | (src_sel & 0x3));
        writel(ctl, ctl_addr);
        /* set reg_pre_en to 1'b1, wait pre_en_ack to 1'b1. */
        ctl |= BM_BUS_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_EN_STATUS) == 0
               && tms++ < CKGEN_POLLs);

        ctl &= ~FM_BUS_SLICE_CTL_DIV_NUM;
        ctl |= FV_BUS_SLICE_CTL_DIV_NUM(pre_div);
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_DIV_CHG_BUSY)
               && (tms++ < CKGEN_POLLs));

        /* set clk_src_sel[3] to 1'b0 and clk_src_sel[2] to 1'b0 */
        ctl &= ~FV_BUS_SLICE_CTL_CLK_SRC_SEL(0xcU);
        writel(ctl, ctl_addr);
        tms = 0;

        /* until mux d0 active */
        while (((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_MUX_D0_ACTIVE) == 0) &&
               (tms++ < CKGEN_POLLs));
    } else {    /* between clk_in0-3 */

        /* Switch to clk_in4 firstly */
        if (!(ctl & BM_BUS_SLICE_CTL_MAIN_EN)) {
            ctl |= BM_BUS_SLICE_CTL_MAIN_EN;
            writel(ctl, ctl_addr);
            tms = 0;

            while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_MAIN_EN_STATUS) == 0 &&
                   (tms++ < CKGEN_POLLs));
        }

        ctl |= FV_BUS_SLICE_CTL_CLK_SRC_SEL(0x4U);
        writel(ctl, ctl_addr);

        tms = 0;

        /* until mux d0 de-active */
        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_MUX_D0_ACTIVE) &&
               (tms++ < CKGEN_POLLs));

        /* select between clk_in0-3 */
        ctl &= ~BM_BUS_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_EN_STATUS)
               && (tms++ < CKGEN_POLLs));

        ctl &= ~FM_BUS_SLICE_CTL_CLK_SRC_SEL;
        ctl |= FV_BUS_SLICE_CTL_CLK_SRC_SEL(0x4u | (src_sel & 0x3));
        writel(ctl, ctl_addr);
        ctl |= BM_BUS_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_EN_STATUS) == 0
               && tms++ < CKGEN_POLLs);

        ctl &= ~FM_BUS_SLICE_CTL_DIV_NUM;
        ctl |= FV_BUS_SLICE_CTL_DIV_NUM(pre_div);
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_BUS_SLICE_CTL_DIV_CHG_BUSY)
               && (tms++ < CKGEN_POLLs));

        /* select clk_in0-3 pach */
        ctl &= ~FV_BUS_SLICE_CTL_CLK_SRC_SEL(0xcU);
        writel(ctl, ctl_addr);
        /* until mux d0 active */
        tms = 0;

        while (((readl(ctl_addr) & BM_BUS_SLICE_CTL_PRE_MUX_D0_ACTIVE) == 0) &&
               (tms++ < CKGEN_POLLs));
    }
}
#ifdef MCU_CKGEN_RESERVED_FUNCs
/*
 * Core clock slice
 *
 * clk_in4   -----> CG(main) -------> |\
 *                                    ||----->clk_out
 *                                 -> |/
 *                                |  clk_src_sel[2]
 * clk_in0 ->|\                   |
 * clk_in1 ->||                   |
 * clk_in2 ->||-> CG-->(div[4:0])-|
 * clk_in3 ->|/  (pre)   (pre)
 *       clk_src_sel[1:0]
 *
 * clk_in0 (usually 24MHz) by default.
 */
void ckgen_core_slice_cfg(uint32 base, uint32 slice_id, uint32 src_sel, uint32 div)
{
    uint32 ctl_addr = base + CORE_SLICE_CTL_OFF(slice_id);
    uint32 ctl = readl(ctl_addr);
    uint32 cur_sel = GFV_CORE_SLICE_CTL_CLK_SRC_SEL(ctl);
    uint32 tms = 0;

    if ((cur_sel == src_sel) || (src_sel > 4u) || (src_sel == 4 && cur_sel >= 4)) {
        return;
    }

    if (cur_sel >= 4) {    /* from clk_in4 to clk0-3 */
        /* Make sure CG is enabled. */
        ctl |= BM_CORE_SLICE_CTL_MAIN_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_CORE_SLICE_CTL_MAIN_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        /* Make sure both clk_in0~clk_in3(the used one) and clk_in4 are active. */

        /* set reg_pre_en to 1'b0, wait pre_en_ack to 1'b0.*/
        ctl &= ~BM_CORE_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);

        tms = 0;

        while ((readl(ctl_addr) & BM_CORE_SLICE_CTL_PRE_EN_STATUS)
               && (tms++ < CKGEN_POLLs));

        /* set clk_src_sel[1:0] to select the clock.*/
        ctl &= ~FV_CORE_SLICE_CTL_CLK_SRC_SEL(3);
        ctl |= FV_CORE_SLICE_CTL_CLK_SRC_SEL(src_sel & 0x3);
        writel(ctl, ctl_addr);
        /*set reg_pre_en to 1'b1, wait pre_en_ack to 1'b1.*/
        ctl |= BM_CORE_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_CORE_SLICE_CTL_PRE_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        /* Div_num can be changed on-the-fly */
        ctl &= ~FM_CORE_SLICE_CTL_DIV_NUM;
        ctl |= FV_CORE_SLICE_CTL_DIV_NUM(div);
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_CORE_SLICE_CTL_DIV_CHG_BUSY)
               && (tms++ < CKGEN_POLLs));

        /* set clk_src_sel[2] to 1'b0. */
        ctl &= ~FV_CORE_SLICE_CTL_CLK_SRC_SEL(4);
        writel(ctl, ctl_addr);
        /* until mux D0 active */
        tms = 0;

        while (((readl(ctl_addr) & BM_CORE_SLICE_CTL_MUX_D0_ACTIVE) == 0)
               && (tms++ < CKGEN_POLLs));
    } else if (4u == src_sel) { /* from clk_in0-3 to clk_in4 */
        /* > Make sure CG is enabled. */
        ctl |= BM_CORE_SLICE_CTL_MAIN_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_CORE_SLICE_CTL_MAIN_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        /* make sure both clk_in0~clk_in3(the used one) and clk_in4 are active. */
        /* set clk_src_sel[2] to 1'b1. */
        /* this mux is glitch-less */
        ctl |= FV_CORE_SLICE_CTL_CLK_SRC_SEL(4);
        writel(ctl, ctl_addr);
        /* until mux D0 de-active */
        tms = 0;

        while ((readl(ctl_addr) & BM_CORE_SLICE_CTL_MUX_D0_ACTIVE)
               && (tms++ < CKGEN_POLLs));
    } else {    /* between clk_in0-3 */
        /* switch to clk_in4 firstly */
        ctl |= BM_CORE_SLICE_CTL_MAIN_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_CORE_SLICE_CTL_MAIN_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        ctl |= FV_CORE_SLICE_CTL_CLK_SRC_SEL(4);
        writel(ctl, ctl_addr);
        /* until mux d0 de-active */
        tms = 0;

        while ((readl(ctl_addr) & BM_CORE_SLICE_CTL_MUX_D0_ACTIVE) &&
               (tms++ < CKGEN_POLLs));

        /* to select between clk_in0-3 */
        ctl &= ~BM_CORE_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);

        tms = 0;

        while ((readl(ctl_addr) & BM_CORE_SLICE_CTL_PRE_EN_STATUS)
               && (tms++ < CKGEN_POLLs));

        ctl &= ~FM_CORE_SLICE_CTL_CLK_SRC_SEL;
        ctl |= FV_CORE_SLICE_CTL_CLK_SRC_SEL(src_sel | 0x4U);
        writel(ctl, ctl_addr);
        ctl |= BM_CORE_SLICE_CTL_PRE_EN;
        writel(ctl, ctl_addr);
        tms = 0;

        while (((readl(ctl_addr) & BM_CORE_SLICE_CTL_PRE_EN_STATUS) == 0)
               && (tms++ < CKGEN_POLLs));

        /* Div_num can be changed on-the-fly */
        ctl &= ~FM_CORE_SLICE_CTL_DIV_NUM;
        ctl |= FV_CORE_SLICE_CTL_DIV_NUM(div);
        writel(ctl, ctl_addr);
        tms = 0;

        while ((readl(ctl_addr) & BM_CORE_SLICE_CTL_DIV_CHG_BUSY)
               && (tms++ < CKGEN_POLLs));

        /* switch to clk_in0-3 path */
        ctl &= ~FV_CORE_SLICE_CTL_CLK_SRC_SEL(4);
        writel(ctl, ctl_addr);
        /* until mux d0 active */
        tms = 0;

        while ((readl(ctl_addr) & BM_CORE_SLICE_CTL_MUX_D0_ACTIVE) == 0 &&
               (tms++ < CKGEN_POLLs));
    }
}

/* ROM code takes care of 'run mode' only */
void ckgen_pcg_clk_on(uint32 base, uint32 id)
{
    uint32 a = base + PCG_CTL_OFF(id);
    uint32 v = readl(a);
    writel(v | BM_PCG_CTL_RUN_MODE, a);
}

void ckgen_pcg_clk_off(uint32 base, uint32 id)
{
    uint32 a = base + PCG_CTL_OFF(id);
    uint32 v = readl(a);
    v &= ~BM_PCG_CTL_RUN_MODE;
    writel(v, a);
}

/*
 * bit0 for sf and bit 1 for sp
 *  0: 4/2/1
 *  1: 2/2/1
 */
void ckgen_clk_ratio_sel(uint32 base, uint32 v)
{
    uint32 a = base + CKGEN_RES_OFF;
    writel (v, a);
}

#endif
static unsigned int mode_cfg(unsigned int mode, unsigned int rdata, int on_off)
{
    unsigned int result;

    if (mode == CKGEN_RUN_MODE) {
        if (on_off == 0) { result = rdata & 0xfffffffe; }
        else          { result = rdata | 0x1;}
    } else if (mode == CKGEN_HIB_MODE) {
        if (on_off == 0) { result = rdata & 0xfffffffd; }
        else          { result = rdata | 0x2;}
    } else {
        if (on_off == 0) { result = rdata & 0xfffffffb; }
        else          { result = rdata | 0x4;}
    }

    return result;

}

void ckgen_pll_dis(unsigned int mode, unsigned int on_off, unsigned int ckgen_sel, int dis_or_pd)
{
    unsigned int addr, rdata, base_addr;

    if (ckgen_sel == 0) {
        base_addr = APB_CKGEN_SF_BASE;
    }

#ifndef SEMIDRIVE_E3_LITE_SERIES
    else  {
        base_addr = APB_CKGEN_AP_BASE;
    }

#endif

    for (unsigned int index = 0; index < 3; index++) {
        addr = base_addr + 0x7004 + index * 12;
        rdata = readl(addr);

        if (dis_or_pd == 0) {
            rdata = mode_cfg(mode, rdata, on_off);
            rdata = rdata & 0xfffffff7;  //set the bit 3 to 0
        } else {
            rdata = mode_cfg(mode, rdata, on_off);
            rdata = rdata & 0xfffffff7;  //set the bit 3 to 0

            if (mode == CKGEN_RUN_MODE) {
                if (on_off)    { rdata = rdata & 0xffffffef; }
                else          { rdata = rdata | 0x10;}
            } else if (mode == CKGEN_HIB_MODE) {
                if (on_off)    { rdata = rdata & 0xffffffdf; }
                else          { rdata = rdata | 0x20;}
            } else {
                if (on_off)    { rdata = rdata & 0xffffffbf; }
                else          { rdata = rdata | 0x40;}
            }

        }

        writel(rdata, addr);
    }
}

void ckgen_xtal_dis(unsigned int mode, unsigned int on_off, unsigned int ckgen_sel)
{
    unsigned int addr, rdata, base_addr;

    if (ckgen_sel == 0) {
        base_addr = APB_CKGEN_SF_BASE;
    }

#ifndef SEMIDRIVE_E3_LITE_SERIES
    else  {
        base_addr = APB_CKGEN_AP_BASE;
    }

#endif

        addr = base_addr + 0x7504;
        rdata = readl(addr);
        rdata = mode_cfg(mode, rdata, on_off);
        rdata = rdata & 0x7;  //set the bit 3 to 0
        writel(rdata, addr);
}

void ckgen_sf_clk_dis(unsigned int mode, unsigned int on_off)
{
    unsigned int addr, rdata, base_addr;
    base_addr = APB_CKGEN_SF_BASE;

    //CCG
    for (unsigned int index = 0; index < 5; index++) {
        addr = base_addr + 0x6004 + index * 8;
        rdata = readl(addr);
        rdata = mode_cfg(mode, rdata, on_off);
        writel(rdata, addr);
    }

    //PCG CTL
    for (unsigned int index = 0; index < 334; index++) {
        addr = base_addr + 0x4004 + index * 8;
        rdata = readl(addr);
        rdata = mode_cfg(mode, rdata, on_off);
        writel(rdata, addr);
    }

    //BCG
    for (unsigned int index = 0; index < 15; index++) {
        addr = base_addr + 0x5004 + index * 8;
        rdata = readl(addr);
        rdata = mode_cfg(mode, rdata, on_off);
        writel(rdata, addr);
    }
}
#ifndef SEMIDRIVE_E3_LITE_SERIES
void ckgen_ap_clk_dis(unsigned int mode, unsigned int on_off)
{
    unsigned int addr, rdata, base_addr;

    base_addr = APB_CKGEN_AP_BASE;

    //PCG CTL
    for (unsigned int index = 0; index < 60; index++) {
        addr = base_addr + 0x4004 + index * 8;
        rdata = readl(addr);
        rdata = mode_cfg(mode, rdata, on_off);
        writel(rdata, addr);
    }

    //BCG
    for (unsigned int index = 0; index < 7; index++) {
        addr = base_addr + 0x5004 + index * 8;
        rdata = readl(addr);
        rdata = mode_cfg(mode, rdata, on_off);
        writel(rdata, addr);
    }
}
#endif
#ifdef MCU_CKGEN_RESERVED_FUNCs
void ckgen_cg_ctl(unsigned int base_addr, int cg_type, int mode, int index, int on_off, int lp_mask)
{
    unsigned int reg_addr, rdata;

    if (cg_type == CKGEN_PCG) {
        reg_addr = base_addr + 0x4004 + index * 8;
    } else if (cg_type == CKGEN_BCG) {
        reg_addr = base_addr + 0x5004 + index * 8;
    } else {
        reg_addr = base_addr + 0x6004  + index * 8;
    }

    rdata = readl(reg_addr);

    if (mode == CKGEN_RUN_MODE) {
        if (on_off == 0) { rdata = rdata & 0xfffffffe; }
        else          { rdata = rdata | 0x1;}
    } else if (mode == CKGEN_HIB_MODE) {
        if (on_off == 0) { rdata = rdata & 0xfffffffd; }
        else          { rdata = rdata | 0x2;}
    } else {
        if (on_off == 0) { rdata = rdata & 0xfffffffb; }
        else          { rdata = rdata | 0x4;}
    }

    if (lp_mask) {
        rdata = rdata | 0x100;
    } else {
        rdata = rdata & 0xfffffeff;
    }

    writel(rdata, reg_addr);
}
#endif
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
