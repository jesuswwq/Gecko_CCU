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
 * @file  Lin_Ioc_E3.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "RegHelper.h"
#include "Lin_Cfg.h"
#include "ioc_reg_e3.h"
#include "ioc_types_e3.h"
#include "__regs_base.h"
#if (LIN_TX_ERROR_DETECT== STD_ON)
#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"
/* ioc default config */
ioc_cfg ioc_default_cfg = {
    .filter_type_pos = 3,   //default bypass mode
    .filter_type_neg = 3,   //default bypass mode
    .edge_mode = 0,       //default edge
    .det_edge_inc = 0,    //sig det mode pos_edge
    .det_edge_dec = 1,    //sig det mode neg_edge
    .det_edge_default = 3, //default mode pos_neg_edge
    .det_level = 0,       //default high level
    .det_level_low = 1,       //default high level
    .det_pdt = 0,         //default high level
    .diff_cnt = 1,        //difference counter threshold
    .diff_cnt_fusa = 2,
    .sig_det_mode = 1,    //default signal detect mode on
    .pdt_thr = 3,
};
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/**
 * @brief sdrv sem interrupt0~7 enable override.
 *
 * @param[in] base    reg base
 * @param[in] output  sem interrupt output
 * @param[in] en      reg val
 */
static void sdrv_sem_lld_override_en(uint32 base, uint16 output, boolean en)
{
    uint32 val = readl(base + INT_ENABLE_OVRD_OFF);

    val |= FV_INT_ENABLE_OVRD_INT_ENABLE_OVRD_EN(1 << output);
    en ? (val |= FV_INT_ENABLE_OVRD_INT_ENABLE_OVRD_VAL(1 << output))
       : (val &= ~FV_INT_ENABLE_OVRD_INT_ENABLE_OVRD_VAL(1 << output));
    writel(val, base + INT_ENABLE_OVRD_OFF);
}

/**
 * @brief sdrv sem correctable interrupt input enable.
 *
 * @param[in] base    reg base
 * @param[in] output  sem interrupt output
 * @param[in] input   sem cor interrupt input
 * @param[in] en      reg val
 */
static void sdrv_sem_lld_corr_interrupt_en(uint32 base, uint16 output, uint16 input, boolean en)
{
    uint32 val = readl(base + SEM_CORR_INT_ENABLE(output, input));

    en ? (val |= (1 << (input % 32))) : (val &= ~(1 << (input % 32)));
    writel(val, base + (SEM_CORR_INT_ENABLE(output, input)));
}

/**
 * @brief sdrv sem uncorrectable interrupt input enable.
 *
 * @param[in] base    reg base
 * @param[in] output  sem interrupt output
 * @param[in] input   sem uncor interrupt input
 * @param[in] en      reg val
 */
static void sdrv_sem_lld_uncorr_interrupt_en(uint32 base, uint16 output, uint16 input, boolean en)
{
    uint32 val = readl(base + SEM_UNCORR_INT_ENABLE(output, input));

    en ? (val |= (1 << (input % 32))) : (val &= ~(1 << (input % 32)));
    writel(val, base + (SEM_UNCORR_INT_ENABLE(output, input)));
}

/**
 * @brief sdrv sem error injection global enable.
 *
 * @param[in] base reg base
 * @param[in] en   reg val
 */
static void sdrv_sem_lld_error_inj_glb_en(uint32 base, boolean en)
{
    uint32 val = readl(base + SEM_COMMON_SET_OFF);

    en ? (val |= BM_SEM_COMMON_SET_EI_GLOBAL_EN)
       : (val &= ~BM_SEM_COMMON_SET_EI_GLOBAL_EN);
    writel(val, base + SEM_COMMON_SET_OFF);
}

/**
 * @brief sdrv sem correctable interrupt status.
 *
 * @param[in] base   reg base
 * @param[in] input  sem cor interrupt input
 */
static boolean sdrv_sem_lld_corr_int_status(uint32 base, uint16 input)
{
    uint32 val = readl(base + SEM_CORR_INT_STATUS(input));
    val &= (uint32)(1 << (input % 32));
    return (boolean)(val ? 1 : 0);
}

/**
 * @brief sdrv sem uncorrectable interrupt status.
 *
 * @param[in] base   reg base
 * @param[in] input  sem interrupt input
 * @param[in] en     reg val
 */
static boolean sdrv_sem_lld_uncorr_int_status(uint32 base, uint16 input)
{
    uint32 val = readl(base + SEM_UNCORR_INT_STATUS(input));
    val &= (uint32)(1 << (input % 32));
    return (boolean)(val ? 1 : 0);
}

/**
 * @brief sdrv sem cor err init.
 *
 * @param[in] base reg base
 */
static void sem_ioc_init(uint32 base) 
{
    /* enable sem override */
    sdrv_sem_lld_override_en(base, SEM_OUTPUT_CPU, 1);
    /* enable input interrupt */
    sdrv_sem_lld_corr_interrupt_en(base, SEM_OUTPUT_CPU,
                                   SEM_IOC_COR_ERR_INT_NUM, 1);
    /* enable input interrupt */
    sdrv_sem_lld_uncorr_interrupt_en(base, SEM_OUTPUT_CPU,
                                   SEM_IOC_UNC_ERR_INT_NUM, 1);
    sdrv_sem_lld_error_inj_glb_en(base, 1);
}

/**
 * @brief ioc iopm cpmmon cfg init.
 *
 * @param[in] numNodeId ioc channel
 */
static void ioc_iopm_cfg_common(uint8 numNodeId) 
{
    uint32 iopm_cfg_addr = APB_IOC_BASE + IOC_IOPM_CFG_CFG(numNodeId);
    uint32 iopm_cfg = readl(iopm_cfg_addr);
    /* pdt level cfg */
    iopm_cfg &= ~IOPM_CFG_PDT_LEVEL0;
    iopm_cfg &= ~IOPM_CFG_PDT_LEVEL1;
    writel(iopm_cfg, iopm_cfg_addr);
}

/**
 * @brief ioc iopm common int enable.
 *
 * @param[in] numNodeId ioc channel
 */
static void ioc_iopm_int_en(uint8 numNodeId) 
{
    /* cor sta en */
    uint32 cor_sta_en_addr = APB_IOC_BASE + IOC_FUSA_COR_ERR_INT_STA_EN;
    uint32 cor_sta_en = readl(cor_sta_en_addr);
    cor_sta_en |= FUSA_COR_ERR_INT_STA_EN_IOPM_EDT_ERR(numNodeId);
    writel(cor_sta_en, cor_sta_en_addr);
    /* cor sig en */
    uint32 cor_sig_en_addr = APB_IOC_BASE + IOC_FUSA_COR_ERR_INT_SIG_EN;
    uint32 cor_sig_en = readl(cor_sig_en_addr);
    cor_sig_en |= FUSA_COR_ERR_INT_SIG_EN_IOPM_EDT_ERR(numNodeId);
    writel(cor_sig_en, cor_sig_en_addr);
    /* uncor sta en */
    uint32 uncor_sta_en_addr = APB_IOC_BASE + IOC_FUSA_UNC_ERR_INT_STA_EN;
    uint32 uncor_sta_en = readl(uncor_sta_en_addr);
    uncor_sta_en |= FUSA_UNC_ERR_INT_STA_EN_IOPM_EDT_ERR(numNodeId);
    writel(uncor_sta_en, uncor_sta_en_addr);
    /* uncor sig en */
    uint32 uncor_sig_en_addr = APB_IOC_BASE + IOC_FUSA_UNC_ERR_INT_SIG_EN;
    uint32 uncor_sig_en = readl(uncor_sig_en_addr);
    uncor_sig_en |= FUSA_UNC_ERR_INT_SIG_EN_IOPM_EDT_ERR(numNodeId);
    writel(uncor_sig_en, uncor_sig_en_addr);
}

/**
 * @brief ioc iopm gpio mux cfg.
 *
 * @param[in] gpio_in_0 input gpio 0
 * @param[in] gpio_in_1 input gpio 1
 * @param[in] channel chan index
 * @param[in] cfg ioc config
 */
static void ioc_iopm_inout_mux_cfg(uint8 gpio_in_0, uint8 gpio_in_1, uint8 channel, ioc_cfg *cfg) 
{
    /* set iomux select cfg */
    uint32 iopm_mux_addr = APB_IOC_BASE + IOC_IOPM_MUX_SEL_CFG(channel);
    uint32 iopm_mux = 0;
    uint32 iopm_in_0 = IOC_PAD_IN_IOMUX_IN(gpio_in_0);
    uint32 iopm_in_1 = IOC_PAD_OUT_IOMUX_IN(gpio_in_1);
    iopm_mux |= iopm_in_0;
    iopm_mux |= (iopm_in_1 << 16);
    writel(iopm_mux, iopm_mux_addr);

    /* iopm edge mode cfg */
    uint32 iopm_edge_addr = APB_IOC_BASE + IOC_IOPM_EDGE_DET_CFG(channel);
    uint32 iopm_edge_det = readl(iopm_edge_addr);
    /* default edge mode */
    iopm_edge_det |= (cfg->edge_mode << 0);
    iopm_edge_det |= (cfg->edge_mode << 4);
    /* normal mode default edge */
    iopm_edge_det |= (cfg->det_edge_default << 1);
    iopm_edge_det |= (cfg->det_edge_default << 5);
    writel(iopm_edge_det, iopm_edge_addr);

    /* iopm pwd level */
    uint32 iopm_cfg_addr = APB_IOC_BASE + IOC_IOPM_CFG_CFG(channel);
    uint32 iopm_cfg = readl(iopm_cfg_addr);
    iopm_cfg = iopm_cfg & (~0xC00000);
    /* default high level */
    iopm_cfg |= (cfg->det_level << 22);
    /* default low level */
    iopm_cfg |= (cfg->det_level_low << 23);
    /* diff counter thr */
    iopm_cfg |= (cfg->diff_cnt_fusa << 16);
    writel(iopm_cfg, iopm_cfg_addr);

    /* iopm pdt threshold cfg */
    uint32 iopm_pdt_thr_addr = APB_IOC_BASE + IOC_IOPM_PDT_THR_CFG(channel);
    uint32 iopm_pdt_thr = cfg->pdt_thr;
    writel(iopm_pdt_thr, iopm_pdt_thr_addr);

}

/**
 * @brief lin ioc uart correctable interrupt status.
 *
 * @param[in] base   reg base
 * @param[in] input  sem cor interrupt input
 */
static boolean Lin_Ioc_Uart_Cor_Int_Handle(uint32 base, uint8 numNodeId)
{
    boolean ret = FALSE;
    uint32 cor_int = readl(base + IOC_FUSA_COR_ERR_INT_STA);
    /* check ioc uart err */
    if (cor_int & FUSA_COR_ERR_INT_STA_IOPM_EDT_ERR(numNodeId)) {
        ret = TRUE;
    }
    cor_int &= FUSA_COR_ERR_INT_STA_IOPM_EDT_ERR(numNodeId);
    /* clear int status */
    writel(cor_int, base + IOC_FUSA_COR_ERR_INT_STA);
    return ret;
}

/**
 * @brief lin ioc uart uncorrectable interrupt status.
 *
 * @param[in] base   reg base
 * @param[in] input  sem cor interrupt input
 */
static boolean Lin_Ioc_Uart_Unc_Int_Handle(uint32 base, uint8 numNodeId)
{
    boolean ret = FALSE;
    uint32 unc_int = readl(base + IOC_FUSA_UNC_ERR_INT_STA);
    /* check ioc uart err */
    if (unc_int & FUSA_UNC_ERR_INT_STA_IOPM_EDT_ERR(numNodeId)) {
        ret = TRUE;
    }
    unc_int &= FUSA_UNC_ERR_INT_STA_IOPM_EDT_ERR(numNodeId);
    /* clear int status */
    writel(unc_int, base + IOC_FUSA_UNC_ERR_INT_STA);
    return ret;
}

void Lin_IocEnable(uint8 numNodeId, boolean enable)
{
    /* check pointer para */
    uint32 iopm_cfg_addr = APB_IOC_BASE + IOC_IOPM_CFG_CFG(numNodeId);
        /* iopm en */
    uint32 iopm_cfg = readl(iopm_cfg_addr);
    if (enable) {
        iopm_cfg |= 0x1;
    } else {
        iopm_cfg &= ~0x1;
    }
    writel(iopm_cfg, iopm_cfg_addr);
    uint32 cor_int = readl(APB_IOC_BASE + IOC_FUSA_COR_ERR_INT_STA);
    cor_int &= FUSA_COR_ERR_INT_STA_IOPM_EDT_ERR(numNodeId);
    writel(cor_int, APB_IOC_BASE + IOC_FUSA_COR_ERR_INT_STA);
    uint32 unc_int = readl(APB_IOC_BASE + IOC_FUSA_UNC_ERR_INT_STA);
    unc_int &= FUSA_UNC_ERR_INT_STA_IOPM_EDT_ERR(numNodeId);
    writel(unc_int, APB_IOC_BASE + IOC_FUSA_UNC_ERR_INT_STA);
}

/* workaround : Ioc and sem init */
void Lin_IocInit(uint8 numNodeId, const Lin_Uart *Lin_UartCfg)
{
    /* check pointer para */
    if (NULL_PTR == Lin_UartCfg) {
        return;
    }
    const Lin_IocGpioConfig *ioc_gpio = &(Lin_UartCfg->gpio_sel);
    /* sem cfg init */
    sem_ioc_init(APB_SEM1_BASE);
    /* ioc cfg init */
    ioc_iopm_cfg_common(numNodeId);
    /* ioc int enable */
    ioc_iopm_int_en(numNodeId);
    /* ioc module enable */
    ioc_iopm_inout_mux_cfg(ioc_gpio->gpio_rx, ioc_gpio->gpio_tx, numNodeId, &ioc_default_cfg);
}

boolean Lin_IocTxErrCheck(uint8 numNodeId)
{
    boolean errStatus = FALSE;
    /* sem cor err check */
    if (sdrv_sem_lld_corr_int_status(APB_SEM1_BASE, SEM_IOC_COR_ERR_INT_NUM) && 
        sdrv_sem_lld_corr_int_status(APB_SEM2_BASE, SEM_IOC_COR_ERR_INT_NUM)) {
            if (Lin_Ioc_Uart_Cor_Int_Handle(APB_IOC_BASE, numNodeId)) {
                errStatus = TRUE;
            }
    }
    /* sem uncor err check */
    if (sdrv_sem_lld_uncorr_int_status(APB_SEM1_BASE, SEM_IOC_UNC_ERR_INT_NUM) && 
        sdrv_sem_lld_uncorr_int_status(APB_SEM2_BASE, SEM_IOC_UNC_ERR_INT_NUM)) {
            if (Lin_Ioc_Uart_Unc_Int_Handle(APB_IOC_BASE, numNodeId)) {
                errStatus = TRUE;
            }
    }
    return errStatus;
}


#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif /* LIN_TX_ERROR_DETECT */
#ifdef __cplusplus
}
#endif
