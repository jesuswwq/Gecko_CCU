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
 *  \file     Mcu_Rstgen.h                                                                              *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_RSTGEN_H
#define MCU_RSTGEN_H

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/* This section defines the register offsets of rstgen component */
#define DOM_PER0_OFF(n)          (0x0U + (12U*(n)))
#define DOM_PER0_DOM3_USE_PER    (30U)
#define DOM_PER0_DOM3_PRI_PER    (28U)
#define DOM_PER0_DOM3_NSE_PER    (26U)
#define DOM_PER0_DOM3_SEC_PER    (24U)
#define DOM_PER0_DOM2_USE_PER    (22U)
#define DOM_PER0_DOM2_PRI_PER    (20U)
#define DOM_PER0_DOM2_NSE_PER    (18U)
#define DOM_PER0_DOM2_SEC_PER    (16U)
#define DOM_PER0_DOM1_USE_PER    (14U)
#define DOM_PER0_DOM1_PRI_PER    (12U)
#define DOM_PER0_DOM1_NSE_PER    (10U)
#define DOM_PER0_DOM1_SEC_PER    (8U)
#define DOM_PER0_DOM0_USE_PER    (6U)
#define DOM_PER0_DOM0_PRI_PER    (4U)
#define DOM_PER0_DOM0_NSE_PER    (2U)
#define DOM_PER0_DOM0_SEC_PER    (0U)

#define DOM_PER1_OFF(n)          (0x4U + (12U*(n)))
#define DOM_PER1_DOM7_USE_PER    (30U)
#define DOM_PER1_DOM7_PRI_PER    (28U)
#define DOM_PER1_DOM7_NSE_PER    (26U)
#define DOM_PER1_DOM7_SEC_PER    (24U)
#define DOM_PER1_DOM6_USE_PER    (22U)
#define DOM_PER1_DOM6_PRI_PER    (20U)
#define DOM_PER1_DOM6_NSE_PER    (18U)
#define DOM_PER1_DOM6_SEC_PER    (16U)
#define DOM_PER1_DOM5_USE_PER    (14U)
#define DOM_PER1_DOM5_PRI_PER    (12U)
#define DOM_PER1_DOM5_NSE_PER    (10U)
#define DOM_PER1_DOM5_SEC_PER    (8U)
#define DOM_PER1_DOM4_USE_PER    (6U)
#define DOM_PER1_DOM4_PRI_PER    (4U)
#define DOM_PER1_DOM4_NSE_PER    (2U)
#define DOM_PER1_DOM4_SEC_PER    (0U)

#define DOM_PER_LOCK_OFF(n)      (0x8U + (12U*(n)))
#define DOM_PER_LOCK_DOM7_LOCK   (7U)
#define DOM_PER_LOCK_DOM6_LOCK   (6U)
#define DOM_PER_LOCK_DOM5_LOCK   (5U)
#define DOM_PER_LOCK_DOM4_LOCK   (4U)
#define DOM_PER_LOCK_DOM3_LOCK   (3U)
#define DOM_PER_LOCK_DOM2_LOCK   (2U)
#define DOM_PER_LOCK_DOM1_LOCK   (1U)
#define DOM_PER_LOCK_DOM0_LOCK   (0U)

/* Global reset */
#define GLOBAL_RESET_RS_OFF      (0x200U)
#define GLOBAL_RESET_RS_LOCK     (31U)

#define GLOBAL_RESET_RS_EN       (0U)

#define GLOBAL_RESET_CONTROL_OFF             (0x204U)
#define GLOBAL_RESET_CONTROL_SS_RDY          (31U)
#define GLOBAL_RESET_CONTROL_TEST_IST_EN     (29U)
#define GLOBAL_RESET_CONTROL_SW_GLB_RST      (28U)
#define GLOBAL_RESET_CONTROL_SW_GLB_RST_EN   (27U)
#define GLOBAL_RESET_CONTROL_RST_REQ_EN      (19U)
#define GLOBAL_RESET_CONTROL_WDT2_EN         (11U)
#define GLOBAL_RESET_CONTROL_WDT1_EN         (3U)
#define GLOBAL_RESET_CONTROL_SEC_VIO_EN      (2U)
#define GLOBAL_RESET_CONTROL_SEM_EN          (1U)
#define GLOBAL_RESET_CONTROL_SYS_PANIC_EN    (0U)

#define GLOBAL_RESET_STA_OFF                 (0x208U)
#define GLOBAL_RESET_STA_GLB_STA_LAST        (0U)

#define GLOBAL_RESET_STA_ALL_OFF             (0x20CU)
#define GLOBAL_RESET_STA_ALL_GLB_STA_ALL     (0U)

#define GLOBAL_ERR_STA_ALL_OFF               (0x210U)
#define GLOBAL_ERR_STA_ALL_ERR_STA_ALL       (0U)

/* IST reset */
#define IST_RESET_RS_OFF                     (0x1000U)
#define IST_RESET_RS_LOCK                    (31U)

#define IST_RESET_RS_EN                      (0U)

#define IST_RESET_CONTROL_OFF                (0x1004U)
#define IST_RESET_CONTROL_RMON_O             (31U)
#define IST_RESET_CONTROL_RMON_I             (30U)
#define IST_RESET_CONTROL_RSTA               (29U)
#define IST_RESET_CONTROL_AUTO_CLR_RST_B     (6U)
#define IST_RESET_CONTROL_SLP_MODE           (2U)
#define IST_RESET_CONTROL_HIB_MODE           (1U)
#define IST_RESET_CONTROL_RUN_MODE           (0U)

/* Mission reset */
#define MISSION_RESET_RS_OFF(n)              (0x1100U + (8U*(n)))
#define MISSION_RESET_RS_LOCK                (31U)

#define MISSION_RESET_RS_EN                  (0U)

#define MISSION_RESET_CONTROL_OFF(n)         (0x1104U + (8U*(n)))
#define MISSION_RESET_CONTROL_RMON_O         (31U)
#define MISSION_RESET_CONTROL_RMON_I         (30U)
#define MISSION_RESET_CONTROL_RSTA           (29U)
#define MISSION_RESET_CONTROL_AUTO_CLR_RST_B (6U)
#define MISSION_RESET_CONTROL_SLP_MODE       (2U)
#define MISSION_RESET_CONTROL_HIB_MODE       (1U)
#define MISSION_RESET_CONTROL_RUN_MODE       (0U)

/* Latent reset */
#define LATENT_RESET_RS_OFF(n)               (0x1200U + (8U*(n)))
#define LATENT_RESET_RS_LOCK                 (31U)
#define LATENT_RESET_RS_RS                   (1U)
#define LATENT_RESET_RS_EN                   (0U)

#define LATENT_RESET_CONTROL_OFF(n)          (0x1204U + (8U*(n)))
#define LATENT_RESET_CONTROL_RMON_O          (31U)
#define LATENT_RESET_CONTROL_RMON_I          (30U)
#define LATENT_RESET_CONTROL_RSTA            (29U)
#define LATENT_RESET_CONTROL_AUTO_CLR_RST_B  (6U)
#define LATENT_RESET_CONTROL_SLP_MODE        (2U)
#define LATENT_RESET_CONTROL_HIB_MODE        (1U)
#define LATENT_RESET_CONTROL_RUN_MODE        (0U)

/* Module reset */
#define MODULE_RESET_RS_OFF(n)               (0x1300U + (8U*(n)))
#define MODULE_RESET_RS_LOCK                 (31U)

#define MODULE_RESET_RS_EN                   (0U)

#define MODULE_RESET_CONTROL_OFF(n)          (0x1304U + (8U*(n)))
#define MODULE_RESET_CONTROL_RMON_O          (31U)
#define MODULE_RESET_CONTROL_RMON_I          (30U)
#define MODULE_RESET_CONTROL_RSTA            (29U)
#define MODULE_RESET_CONTROL_BTI_TOUT_VAL    (8U)
#define MODULE_RESET_CONTROL_AUTO_CLR_RST_B  (6U)
#define MODULE_RESET_CONTROL_SLP_MODE        (2U)
#define MODULE_RESET_CONTROL_HIB_MODE        (1U)
#define MODULE_RESET_CONTROL_RUN_MODE        (0U)

/* Core reset */
#define CORE_RESET_RS_OFF(n)                 (0x1a00U + (8U*(n)))
#define CORE_RESET_RS_LOCK                   (31U)

#define CORE_RESET_RS_EN                     (0U)

#define CORE_RESET_CONTROL_OFF(n)            (0x1a04U + (8U*(n)))
#define CORE_RESET_CONTROL_RMON_O            (31U)
#define CORE_RESET_CONTROL_RMON_I            (30U)
#define CORE_RESET_CONTROL_RSTA              (29U)
#define CORE_RESET_CONTROL_BTI_TOUT_VAL      (8U)
#define CORE_RESET_CONTROL_AUTO_CLR_RST_B    (6U)
#define CORE_RESET_CONTROL_RST_REQ_EN        (5U)
#define CORE_RESET_CONTROL_WDT2_RST_EN       (4U)
#define CORE_RESET_CONTROL_WDT1_RST_EN       (3U)
#define CORE_RESET_CONTROL_SLP_MODE          (2U)
#define CORE_RESET_CONTROL_HIB_MODE          (1U)
#define CORE_RESET_CONTROL_RUN_MODE          (0U)

/* DBG reset */
#define DBG_RESET_RS_OFF                     (0x1b00U)
#define DBG_RESET_RS_LOCK                    (31U)
#define DBG_RESET_RS_RS                      (1U)
#define DBG_RESET_RS_EN                      (0U)

#define DBG_RESET_CONTROL_OFF                (0x1b04U)
#define DBG_RESET_CONTROL_RMON_O             (31U)
#define DBG_RESET_CONTROL_RMON_I             (30U)
#define DBG_RESET_CONTROL_RSTA               (29U)
#define DBG_RESET_CONTROL_DBG_REQ_EN         (8U)
#define DBG_RESET_CONTROL_AUTO_CLR_RST_B     (6U)
#define DBG_RESET_CONTROL_SLP_MODE           (2U)
#define DBG_RESET_CONTROL_HIB_MODE           (1U)
#define DBG_RESET_CONTROL_RUN_MODE           (0U)

/* SW reset */
#define SW_RESET_PASSWORD_CONTROL_OFF        (0x1c00U)
#define SW_RESET_PASSWORD_CONTROL_LOCK       (31U)
#define SW_RESET_PASSWORD_CONTROL_EN         (0U)

#define SW_RESET_PASSWORD_OFF                (0x1c04U)
#define SW_RESET_PASSWORD_PW                 (0U)

#define GENERAL_REG_RS_OFF(n)                (0x2000U + (8U*(n)))
#define GENERAL_REG_RS_LOCK                  (31U)

#define GENERAL_REG_RS_EN                    (0U)

#define GENERAL_REG_OFF(n)                   (0x2004U + (8U*(n)))
#define GENERAL_REG_GENERAL                  (0U)

#define BOOT_MODE_RS_OFF                     (0x3000U)
#define BOOT_MODE_RS_LOCK                    (31U)

#define BOOT_MODE_RS_EN                      (0U)

#define BOOT_MODE_OFF                        (0x3004U)

#define RESET_FLOW_TIME_RS_OFF               (0x3100U)
#define RESET_FLOW_TIME_RS_LOCK              (31U)
#define RESET_FLOW_TIME_RS_RS                (1U)
#define RESET_FLOW_TIME_RS_EN                (0U)

#define RESET_FLOW_TIME_CONTROL_OFF          (0x3104U)
#define RESET_FLOW_TIME_CONTROL_T4           (20U)
#define RESET_FLOW_TIME_CONTROL_T3           (16U)
#define RESET_FLOW_TIME_CONTROL_T2           (8U)
#define RESET_FLOW_TIME_CONTROL_T1           (4U)
#define RESET_FLOW_TIME_CONTROL_T0           (0U)

#define RSTGEN_RES_RS_OFF                    (0x3200U)
#define RSTGEN_RES_RS_LOCK                   (31U)
#define RSTGEN_RES_RS_RS                     (1U)
#define RSTGEN_RES_RS_EN                     (0U)

#define RSTGEN_RES_OFF                       (0x3204U)

#define RSTGEN_MISC_RS_OFF                   (0x3300U)
#define RSTGEN_MISC_RS_LOCK                  (31U)
#define RSTGEN_MISC_RS_RS                    (1U)
#define RSTGEN_MISC_RS_EN                    (0U)

#define RSTGEN_MISC_OFF                      (0x3304U)

#define RSTGEN_SUP_DOM_OFF                   (0x3400U)
#define RSTGEN_SUP_DOM_LOCK                  (31U)
#define RSTGEN_SUP_DOM_PPROT                 (5U)

#define RSTGEN_SUP_DOM_SEC_EN                (4U)
#define RSTGEN_SUP_DOM_DID                   (0U)

#define RSTGEN_TOUT_RS_OFF                   (0x3500U)
#define RSTGEN_TOUT_RS_LOCK                  (31U)
#define RSTGEN_TOUT_RS_RS                    (1U)
#define RSTGEN_TOUT_RS_EN                    (0U)

#define RSTGEN_IST_TOUT_OFF                  (0x3504U)
#define RSTGEN_IST_TOUT_TOUT_VAL             (0U)


#define RSTGEN_BTI_TOUT_OFF                  (0x3508U)
#define RSTGEN_BTI_TOUT_TOUT_VAL             (0U)

#define RSTGEN_FUSA_RS_OFF                   (0x4000U)
#define RSTGEN_FUSA_RS_LOCK                  (31U)
#define RSTGEN_FUSA_RS_RS                    (1U)
#define RSTGEN_FUSA_RS_EN                    (0U)


#define APB_ERR_INT_PADDR_INT_CLR            (23U)
#define APB_ERR_INT_PUSER_INT_CLR            (22U)
#define APB_ERR_INT_PCTRL1_INT_CLR           (21U)
#define APB_ERR_INT_PCTRL0_INT_CLR           (20U)
#define APB_ERR_INT_PWDAT_C_INT_CLR          (19U)
#define APB_ERR_INT_PWDAT_U_INT_CLR          (18U)
#define APB_ERR_INT_PWDAT_F_INT_CLR          (17U)
#define APB_ERR_INT_PADDR_INT_STA            (15U)
#define APB_ERR_INT_PUSER_INT_STA            (14U)
#define APB_ERR_INT_PCTRL1_INT_STA           (13U)
#define APB_ERR_INT_PCTRL0_INT_STA           (12U)
#define APB_ERR_INT_PWDAT_C_INT_STA          (11U)
#define APB_ERR_INT_PWDAT_U_INT_STA          (10U)
#define APB_ERR_INT_PWDAT_F_INT_STA          (9U)
#define APB_ERR_INT_PADDR_INT_EN             (7U)
#define APB_ERR_INT_PUSER_INT_EN             (6U)
#define APB_ERR_INT_PCTRL1_INT_EN            (5U)
#define APB_ERR_INT_PCTRL0_INT_EN            (4U)
#define APB_ERR_INT_PWDAT_C_INT_EN           (3U)
#define APB_ERR_INT_PWDAT_U_INT_EN           (2U)
#define APB_ERR_INT_PWDAT_F_INT_EN           (1U)


#define APB_LKSTEP_INT_SYNC_ERR_INT_CLR      (19U)
#define APB_LKSTEP_INT_RESP_ERR_INT_CLR      (18U)
#define APB_LKSTEP_INT_REQ_ERR_INT_CLR       (17U)
#define APB_LKSTEP_INT_CMP_ERR_INT_CLR       (16U)
#define APB_LKSTEP_INT_SYNC_ERR_INT_STA      (11U)
#define APB_LKSTEP_INT_RESP_ERR_INT_STA      (10U)
#define APB_LKSTEP_INT_REQ_ERR_INT_STA       (9U)
#define APB_LKSTEP_INT_CMP_ERR_INT_STA       (8U)
#define APB_LKSTEP_INT_SYNC_ERR_INT_EN       (3U)
#define APB_LKSTEP_INT_RESP_ERR_INT_EN       (2U)
#define APB_LKSTEP_INT_REQ_ERR_INT_EN        (1U)
#define APB_LKSTEP_INT_CMP_ERR_INT_EN        (0U)

#define RSTGEN_FUSA_INT_OFF                    (0x400cU)
#define RSTGEN_FUSA_INT_BTI_TOUT_ERR_CLR       (21U)
#define RSTGEN_FUSA_INT_LKSTEP_CMP_ERR_CLR     (20U)
#define RSTGEN_FUSA_INT_SYNC_ERR_CLR           (19U)
#define RSTGEN_FUSA_INT_BOOT_MODE_CHK_ERR_CLR  (18U)
#define RSTGEN_FUSA_INT_SWM_TRANS_ERR_CLR      (17U)
#define RSTGEN_FUSA_INT_SWM_CHK_ERR_CLR        (16U)
#define RSTGEN_FUSA_INT_BTI_TOUT_ERR_STA       (13U)
#define RSTGEN_FUSA_INT_LKSTEP_CMP_ERR_STA     (12U)
#define RSTGEN_FUSA_INT_SYNC_ERR_STA           (11U)
#define RSTGEN_FUSA_INT_BOOT_MODE_CHK_ERR_STA  (10U)
#define RSTGEN_FUSA_INT_SWM_TRANS_ERR_STA      (9U)
#define RSTGEN_FUSA_INT_SWM_CHK_ERR_STA        (8U)
#define RSTGEN_FUSA_INT_BTI_TOUT_ERR_EN        (5U)
#define RSTGEN_FUSA_INT_LKSTEP_CMP_ERR_EN      (4U)
#define RSTGEN_FUSA_INT_SYNC_ERR_EN            (3U)
#define RSTGEN_FUSA_INT_BOOT_MODE_CHK_ERR_EN   (2U)
#define RSTGEN_FUSA_INT_SWM_TRANS_ERR_EN       (1U)
#define RSTGEN_FUSA_INT_SWM_CHK_ERR_EN         (0U)


#define WDT_LKSTEP_INT_IST_TOUT_ERR_INT_CLR    (18U)
#define WDT_LKSTEP_INT_SYNC_ERR_INT_CLR        (17U)
#define WDT_LKSTEP_INT_CMP_ERR_INT_CLR         (16U)
#define WDT_LKSTEP_INT_IST_TOUT_ERR_INT_STA    (10U)
#define WDT_LKSTEP_INT_SYNC_ERR_INT_STA        (9U)
#define WDT_LKSTEP_INT_CMP_ERR_INT_STA         (8U)
#define WDT_LKSTEP_INT_IST_TOUT_ERR_INT_EN     (2U)
#define WDT_LKSTEP_INT_SYNC_ERR_INT_EN         (1U)
#define WDT_LKSTEP_INT_CMP_ERR_INT_EN          (0U)

#define RSTGEN_INJ_EN_OFF                    (0x4100U)
#define RSTGEN_INJ_EN_INJ_EN                 (0U)

#define RSTGEN_INJ_BIT_OFF                   (0x4104U)
#define RSTGEN_INJ_BIT_IRQ_INJ               (29U)
#define RSTGEN_INJ_BIT_ERR_INJ_BIT           (0U)

#define RSTGEN_INJ_BIT_1_OFF                 (0x4108U)
#define RSTGEN_INJ_BIT_1_ERR_INJ_BIT         (0U)

#define RSTGEN_INJ_BIT_2_OFF                 (0x410cU)
#define RSTGEN_INJ_BIT_2_ERR_INJ_BIT         (0U)

#define RSTGEN_FUNC_INT_RS_OFF               (0x4200U)
#define RSTGEN_FUNC_INT_RS_LOCK              (31U)
#define RSTGEN_FUNC_INT_RS_RS                (1U)
#define RSTGEN_FUNC_INT_RS_EN                (0U)

#define RSTGEN_FUNC_INT_OFF                  (0x4204U)
#define RSTGEN_FUNC_INT_ACCESS_PER_ERR_CLR   (16U)
#define RSTGEN_FUNC_INT_ACCESS_PER_ERR_STA   (8U)
#define RSTGEN_FUNC_INT_ACCESS_PER_ERR_EN    (0U)

/*define module reset*/
#ifdef SEMIDRIVE_E3_LITE_SERIES
#define RSTGEN_MODULE_CAND16_INDEX           (0U)
#define RSTGEN_MODULE_CAND21_INDEX           (1U)
#define RSTGEN_MODULE_CAND3_INDEX            (2U)
#define RSTGEN_MODULE_CAND4_INDEX            (3U)
#define RSTGEN_MODULE_CAND5_INDEX            (4U)
#define RSTGEN_MODULE_CAND6_INDEX            (5U)
#define RSTGEN_MODULE_CAND7_INDEX            (6U)
#define RSTGEN_MODULE_CAND23_INDEX           (7U)

#define RSTGEN_MODULE_XSPI1A_INDEX           (8U)
#define RSTGEN_MODULE_XSPI1B_INDEX           (9U)

#define RSTGEN_MODULE_DMA_RST0_INDEX         (10U)
#define RSTGEN_MODULE_DMA_RST1_INDEX         (11U)

#define RSTGEN_MODULE_ENET1_INDEX            (12U)
#define RSTGEN_MODULE_VIC1_INDEX             (13U)
#define RSTGEN_MODULE_XSPI_SLV_INDEX         (14U)
#define RSTGEN_MODULE_XTRG_INDEX             (15U)
#define RSTGEN_MODULE_SACI2_INDEX            (16U)
#define RSTGEN_MODULE_SEHC1_INDEX            (17U)
#define RSTGEN_MODULE_USB_INDEX              (18U)
#define RSTGEN_MODULE_SEIP_INDEX             (19U)
#endif  /* SEMIDRIVE_E3_LITE_SERIES */

#define RSTGEN_POLLs    (0x10000U)
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/**
 * \brief e3 rstgen core control
 * Reset core processor.
 *
 * \param[in] base e3 rstgen address
 * \param[in] core_idx core index
 * \param[in] run_mode run mode bit
 */
Std_ReturnType Mcu_Ip_RstgenLldCoreControl(uint32 base, uint32 coreIdx, boolean en);

/**
 * \brief e3 rstgen core reset
 * Reset core processor.
 *
 * \param[in] base e3 rstgen address
 * \param[in] core_idx core index
 */
Std_ReturnType Mcu_Ip_RstgenLldCoreReset(uint32 base, uint32 coreIdx);

/**
 * \brief e3 rstgen module control
 * Reset IP module.
 *
 * \param[in] base e3 rstgen address
 * \param[in] module_idx module index
 * \param[in] run_mode 0:module off, 1:module on
 */
Std_ReturnType Mcu_Ip_RstgenLldModuleControl(uint32 base, uint32 moduleIdx, boolean en);

/**
 * \brief e3 rstgen mission control
 *
 * \param[in] base e3 rstgen address
 * \param[in] mission_idx mission index
 * \param[in] run_mode 0:misson off, 1:misson on
 */
Std_ReturnType Mcu_Ip_RstgenLldMissionControl(uint32 base, uint32 missionIdx, boolean en);

/**
 * \brief
 *
 * \param[in] sf_base e3 rstgen sf domain address
 * \param[in] ap_base e3 rstgen ap domain address
 */
void Mcu_Ip_RstgenLldGlobalReset(uint32 sfBase);

/**
 * \brief e3 rstgen get core reset status
 *
 * \param[in] base e3 rstgen address
 * \param[in] core_idx core index
 * \return 1, the core reset has be released.
 *         0, the core reset hasn't be released.
 */
boolean Mcu_Ip_RstgenLldGetCoreResetStatus(uint32 base, uint32 coreIdx);

/**
 * \brief e3 rstgen get module reset status
 *
 * \param[in] base e3 rstgen address
 * \param[in] module_idx module index
 * \return 1, the module reset has be released.
 *         0, the module reset hasn't be released.
 */
boolean Mcu_Ip_RstgenLldGetModuleResetStatus(uint32 base, uint32 moduleIdx);

/**
 * \brief e3 rstgen get mission reset status
 *
 * \param[in] base e3 rstgen address
 * \param[in] mission_idx mission index
 * \return 1, the mission reset has be released.
 *         0, the mission reset hasn't be released.
 */
boolean Mcu_Ip_RstgenLldGetMissionResetStatus(uint32 base, uint32 missionIdx);

/**
 * \brief  rstgen get general reg value
 *
 * \param[in] base e3 rstgen address
 * \param[in] reg_idx reg index
 * \return reg value
 */
uint32 Mcu_Ip_RstgenLldReadGeneralReg(uint32 base, uint32 regIdx);

/**
 * \brief e3 rstgen set general reg value
 *
 * \param[in] base e3 rstgen address
 * \param[in] reg_idx reg index
 * \param[in] val write value
 * \return void
 */
void Mcu_Ip_RstgenLldWriteGeneralReg(uint32 base, uint32 regIdx, uint32 val);


void Mcu_Ip_RstgenRgGlbResetEn(uint32 base, uint32 msk);

Mcu_RawResetType Mcu_Ip_GetResetRawValue(uint32 base);

Mcu_ResetType Mcu_Ip_GetResetReason(uint32 base);

/*------------------------------------------add bihu  change code------------*/
uint8 Mcu_Ip_GetResetRawValue_bihuchange(uint32 base);
uint8 Mcu_Ip_GetResetReason_bihuchange(uint32 base);
/*  ----------add bihu  change code------------                             */
#endif /* MCU_RSTGEN_H */
/* End of file */
