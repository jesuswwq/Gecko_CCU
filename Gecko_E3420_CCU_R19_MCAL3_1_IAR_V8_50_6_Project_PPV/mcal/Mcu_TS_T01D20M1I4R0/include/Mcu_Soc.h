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
 *  \file     Mcu_Soc.h                                                                                 *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_SOC_H
#define MCU_SOC_H


#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "Mcu_Modules.h"
#include "Mcu_Cfg.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SOC_H_VENDOR_ID    0x8C
#define MCU_SOC_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SOC_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_SOC_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_SOC_H_SW_MAJOR_VERSION    1
#define MCU_SOC_H_SW_MINOR_VERSION    0
#define MCU_SOC_H_SW_PATCH_VERSION    0
/* Version Info End */

#if defined(CFG_MULTI_CORE_OS)
extern uint32 scr_rbase[];
extern uint32 romc_rbase[];
extern uint32 iram_base[];
extern const uint32 rstgen_rbase[];
extern const uint32 cr5_core_rst_idx[];
extern const uint32 cr5_remap_ar_off_start_bit[];
extern const uint32 cr5_remap_ovrd_en[];
#define IRAM_BASE   iram_base[soc_get_cpu_id()]
#define SCR_RBASE   scr_rbase[soc_get_cpu_id()]
#define ROMC_RBASE  romc_rbase[soc_get_cpu_id()]
#define RSTGEN_RBASE rstgen_rbase[soc_get_cpu_id()]
#define CORE_RESET_B_INDEX  cr5_core_rst_idx[soc_get_cpu_id()]
#define SCR_REMAP_CR5_AR_ADDR_OFF_L32_START_BIT \
            cr5_remap_ar_off_start_bit[soc_get_cpu_id()]
#define SCR_REMAP_CR5_REMAP_OVRD_EN_L31_START_BIT \
            cr5_remap_ovrd_en[soc_get_cpu_id()]
#endif /* defined(CFG_MULTI_CORE_OS) */

#define RG_GPR_TEST_FLAGS           7

#if !defined(SOC_RPC_REG_ADDR_MAP)
#define SOC_RPC_REG_ADDR_MAP(a)     ((uint32)(a))
#define SOC_IOMUX_REG_MAP(a)        SOC_RPC_REG_ADDR_MAP(a)
#define SOC_CKGEN_REG_MAP(a)        SOC_RPC_REG_ADDR_MAP(a)
#define SOC_RSTGEN_REG_MAP(a)       SOC_RPC_REG_ADDR_MAP(a)
#define SOC_SCR_REG_MAP(a)          SOC_RPC_REG_ADDR_MAP(a)
#endif

#define BTM_G0_EN_OFFSET    0x04U
#define BTM_G1_EN_OFFSET    0x24U
#define BTM_INT_STA_OFFSET    0x40U
#define BTM_INT_STA_EN_OFFSET    0x44U
#define BTM_INT_SIG_EN_OFFSET    0x48U

#define ETIMER_DMA_CTRL_OFFSET      0xB8U
#define ETIMER_SW_RST_OFFSET        0xA8U
#define ETIMER_G0_EN_OFFSET         0x10CU
#define ETIMER_G1_EN_OFFSET         0x12CU
#define ETIMER_LCNT_A_EN_OFFSET     0x14CU
#define ETIMER_LCNT_B_EN_OFFSET     0x16CU
#define ETIMER_LCNT_C_EN_OFFSET     0x18CU
#define ETIMER_LCNT_D_EN_OFFSET     0x1ACU
#define ETIMER_CPT_CTRL_OFFSET      0x210U
#define ETIMER_CMP_CTRL_OFFSET      0x2E0U
#define ETIMER_INT_STA_OFFSET       0x0U
#define ETIMER_INT_STA_EN_OFFSET    0x4U
#define ETIMER_INT_SIG_EN_OFFSET    0x8U
#define ETIMER_CMP_A_FAULT_EVENT_CTRL_OFFSET    0x440U
#define ETIMER_CMP_B_FAULT_EVENT_CTRL_OFFSET    0x444U
#define ETIMER_CMP_C_FAULT_EVENT_CTRL_OFFSET    0x448U
#define ETIMER_CMP_D_FAULT_EVENT_CTRL_OFFSET    0x44cU
#define ETIMER_COR_ERR_INT_STA_OFFSET           0xCU
#define ETIMER_COR_ERR_INT_STA_EN_OFFSET        0x10U
#define ETIMER_COR_ERR_INT_SIG_EN_OFFSET        0x14U
#define ETIMER_UNC_ERR_INT_STA_OFFSET           0x18U
#define ETIMER_UNC_ERR_INT_STA_EN_OFFSET        0x1CU
#define ETIMER_UNC_ERR_INT_SIG_EN_OFFSET        0x20U


#define EPWM_DMA_CTRL_OFFSET                      (0xB8U)
#define EPWM_SW_RST_OFFSET                        (0xA8U)
#define EPWM_G0_EN_OFFSET                         (0x10CU)
#define EPWM_G1_EN_OFFSET                         (0x12CU)
#define EPWM_CMP_CTRL_OFFSET                      (0x2E0U)
#define EPWM_INT_STA_OFFSET                       (0x0U)
#define EPWM_INT_STA_EN_OFFSET                    (0x4U)
#define EPWM_INT_SIG_EN_OFFSET                    (0x8U)
#define EPWM_COR_ERR_INT_STA_OFFSET               (0xCU)
#define EPWM_COR_ERR_INT_STA_EN_OFFSET            (0x10U)
#define EPWM_COR_ERR_INT_SIG_EN_OFFSET            (0x14U)
#define EPWM_UNC_ERR_INT_STA_OFFSET               (0x18U)
#define EPWM_UNC_ERR_INT_STA_EN_OFFSET            (0x1CU)
#define EPWM_UNC_ERR_INT_SIG_EN_OFFSET            (0x20U)
#define EPWM_CNT_G0_CFG_OFFSET                    (0x108U)
#define EPWM_CNT_G1_CFG_OFFSET                    (0x128U)
#define EPWM_CMP_A_CONFIG_OFFSET                  (0x220U)
#define EPWM_CMP_A_DITHER_OFFSET                  (0x240U)
#define EPWM_CMP_B_CONFIG_OFFSET                  (0x250U)
#define EPWM_CMP_B_DITHER_OFFSET                  (0x270U)
#define EPWM_CMP_C_CONFIG_OFFSET                  (0x280U)
#define EPWM_CMP_C_DITHER_OFFSET                  (0x2a0U)
#define EPWM_CMP_D_CONFIG_OFFSET                  (0x2b0U)
#define EPWM_CMP_D_DITHER_OFFSET                  (0x2d0U)
#define EPWM_CMP_A_SSE_CTRL_OFFSET                (0x320U)
#define EPWM_CMP_B_SSE_CTRL_OFFSET                (0x328U)
#define EPWM_CMP_C_SSE_CTRL_OFFSET                (0x330U)
#define EPWM_CMP_D_SSE_CTRL_OFFSET                (0x338U)
#define EPWM_FAULT0_FLT_OFFSET                    (0x410U)
#define EPWM_FAULT1_FLT_OFFSET                    (0x414U)
#define EPWM_FAULT2_FLT_OFFSET                    (0x418U)
#define EPWM_FAULT3_FLT_OFFSET                    (0x41cU)
#define EPWM_CMP_A_FAULT_EVENT_CTRL_OFFSET        (0x440U)
#define EPWM_CMP_B_FAULT_EVENT_CTRL_OFFSET        (0x444U)
#define EPWM_CMP_C_FAULT_EVENT_CTRL_OFFSET        (0x448U)
#define EPWM_CMP_D_FAULT_EVENT_CTRL_OFFSET        (0x44cU)
#define EPWM_CMP_A_DTI_CTRL_OFFSET                (0x460U)
#define EPWM_CMP_B_DTI_CTRL_OFFSET                (0x468U)
#define EPWM_CMP_C_DTI_CTRL_OFFSET                (0x470U)
#define EPWM_CMP_D_DTI_CTRL_OFFSET                (0x478U)

#define BM_BISTCTL_OFF                      (0x0034U)
#define BM_BISTDONE_OFF                     (0x0038U)
#define BM_FUSA_INTEN_OFF                   (0x002CU)
#define BM_FUSA_INTCLR_OFF                  (0x0030U)
#define BM_INTEN_BISTDONE               ((uint32)0x01U << 0U)
#define BM_INTEN_MISSIONFAULT           ((uint32)0x01U << 1U)
#define BM_INTCLR_LATENTFAULT           ((uint32)0x01U << 0U)
#define BM_INTCLR_MISSIONFAULT          ((uint32)0x01U << 1U)
#define BM_BISTCTL_BISTDONECLR          ((uint32)0x01U << 1U)
#define BM_BISTCTL_BISTSTART            ((uint32)0x01U << 0U)
#define BM_BISTDONE_BISTDONE            ((uint32)0x01U << 0U)

#define SAF_LP_CTL(dom) (0x1008U + ((uint32)(dom) * 0x8U))
#define SAF_RAM_LP_CTL(ram) (0x1060U + ((uint32)(ram) * 0x4U))

#define PMU_SCRS_BITS_OFFSET 0X70U

#define AP_LP_CTL(dom) (0x1208U + ((uint32)(dom) * 0x8U))
#define AP_RAM_LP_CTL(ram) (0x1260U + ((uint32)(ram) * 0x4U))

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
typedef enum
{
    CPU_ID_SF = 0U,
    CPU_ID_SX0,
    CPU_ID_SX1,
    CPU_ID_SP0,
    CPU_ID_SP1,
    CPU_ID_MAX
/*PRQA S 1535 1*/
} Mcu_CoreType;

typedef enum
{
    CR5_SF_DOM = 0U,
    CR5_SP_DOM,
    CR5_SX_DOM,
    GAMA_DOM,
    SAF_MISC,
    AP_DOM,
    DOM_END,
} Mcu_PowerDomType;

typedef enum
{
    CR5_SF_RAM = 0U,
    CR5_SP_RAM,
    CR5_SX_RAM,
    GAMA_RAM,
    AP_RAM,
} Mcu_PowerRam;

uint32 Mcu_Ip_SocGetCoreFreq(void);

void Mcu_Ip_SocResetLatentIp(Mcu_ModuleType m);
Std_ReturnType Mcu_Ip_SocResetMailbox(void);

void Mcu_Ip_SocPowerGate(Mcu_PowerDomType m);

/**
 * \brief reset all latent module.
 */
void Mcu_Ip_SocResetBtm(void);

/**
 * \brief To get cpu identify index .
*/
uint8  Mcu_GetCoreID(void);


#if (STD_ON == MCU_APDOMAIN_POWERDOWN)
void Mcu_Ip_SocApDomPowerDown(void);
#endif /** #if (STD_ON == MCU_APDOMAIN_POWERDOWN)*/

#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (MCU_RELEASE_DISPLAY_PIN == STD_ON)
/* display mux need clr rterm_en if GPIOLx is not used for display */
void MCU_Ip_SocDispalyPadRelease(void);
#endif /** #if (MCU_RELEASE_DISPLAY_PIN == STD_ON)*/
#endif

uint32 soc_to_dma_address(uint32 cpuAddr);
#ifdef __cplusplus
}
#endif

#endif /* MCU_SOC_H */
