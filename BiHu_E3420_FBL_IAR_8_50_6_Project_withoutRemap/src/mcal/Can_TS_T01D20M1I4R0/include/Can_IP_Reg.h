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
 * @file  Can_IP_Reg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */
#ifndef CAN_IP_REG_H_
#define CAN_IP_REG_H_

#ifdef __cplusplus
extern "C" {
#define   I__     volatile             /*!< Defines 'read only' permissions */
#else /* !defined (__cplusplus) */
#define   I__     volatile const       /*!< Defines 'read only' permissions */
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define CAN_IP_REG_H_VENDOR_ID    0x8C
#define CAN_IP_REG_H_AR_RELEASE_MAJOR_VERSION    4
#define CAN_IP_REG_H_AR_RELEASE_MINOR_VERSION    3
#define CAN_IP_REG_H_AR_RELEASE_REVISION_VERSION 1
#define CAN_IP_REG_H_SW_MAJOR_VERSION    1
#define CAN_IP_REG_H_SW_MINOR_VERSION    0
#define CAN_IP_REG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */ /* __cplusplus */
#define     O__     volatile             /*!< Defines 'write only' permissions */
#define     IO__    volatile             /*!< Defines 'read / write' permissions */

/** CAN - Register Layout Typedef */
typedef struct {
    IO__ uint32 MCR;                               /**< Module Configuration Register, offset: 0x0 */
    IO__ uint32 CTRL1;                             /**< Control 1 register, offset: 0x4 */
    IO__ uint32 TIMER;                             /**< Free Running Timer, offset: 0x8 */
    uint8 RESERVED_0[4];
    IO__ uint32
    RXMGMASK;                          /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
    IO__ uint32 RX14MASK;                          /**< Rx 14 Mask register, offset: 0x14 */
    IO__ uint32 RX15MASK;                          /**< Rx 15 Mask register, offset: 0x18 */
    IO__ uint32 ECR;                               /**< Error Counter, offset: 0x1C */
    IO__ uint32 ESR1;                              /**< Error and Status 1 register, offset: 0x20 */
    IO__ uint32 IMASK2;                            /**< Interrupt Masks 2 register, offset: 0x24 */
    IO__ uint32 IMASK1;                            /**< Interrupt Masks 1 register, offset: 0x28 */
    IO__ uint32 IFLAG2;                            /**< Interrupt Flags 2 register, offset: 0x2C */
    IO__ uint32 IFLAG1;                            /**< Interrupt Flags 1 register, offset: 0x30 */
    IO__ uint32 CTRL2;                             /**< Control 2 register, offset: 0x34 */
    I__  uint32 ESR2;                              /**< Error and Status 2 register, offset: 0x38 */
    uint8 RESERVED_1[8];
    I__  uint32 CRCR;                              /**< CRC Register, offset: 0x44 */
    IO__ uint32 RXFGMASK;                          /**< Rx FIFO Global Mask register, offset: 0x48 */
    I__  uint32 RXFIR;                             /**< Rx FIFO Information Register, offset: 0x4C */
    IO__ uint32 CBT;                               /**< CAN Bit Timing Register, offset: 0x50 */
    uint8 RESERVED_2[20];
    IO__ uint32 IMASK4;                            /**< Interrupt Masks 4 register, offset: 0x68 */
    IO__ uint32 IMASK3;                            /**< Interrupt Masks 3 register, offset: 0x6C */
    IO__ uint32 IFLAG4;                            /**< Interrupt Flags 4 register, offset: 0x70 */
    IO__ uint32 IFLAG3;                            /**< Interrupt Flags 3 register, offset: 0x74 */
    uint8 RESERVED_3[8];
    struct {                                       /* offset: 0x80, array step: 0x10 */
        IO__ uint32
        CS;                            /**< Message Buffer 0 CS Register..Message Buffer 127 CS Register, array offset: 0x80, array step: 0x10 */
        IO__ uint32
        ID;                            /**< Message Buffer 0 ID Register..Message Buffer 127 ID Register, array offset: 0x84, array step: 0x10 */
        IO__ uint32
        WORD0;                         /**< Message Buffer 0 WORD0 Register..Message Buffer 127 WORD0 Register, array offset: 0x88, array step: 0x10 */
        IO__ uint32
        WORD1;                         /**< Message Buffer 0 WORD1 Register..Message Buffer 127 WORD1 Register, array offset: 0x8C, array step: 0x10 */
    } MB[128];
    IO__ uint32
    RXIMR[128];                        /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
    uint32 RESERVED_4[24];             /*  96Byte */
    IO__ uint32 MECR;                              /**< Memory Error Control Register, offset: 0xAE0 */
    IO__ uint32
    ERRIAR;                            /**< Error Injection Address Register, offset: 0xAE4 */
    IO__ uint32
    ERRIDPR;                           /**< Error Injection Data Pattern Register, offset: 0xAE8 */
    IO__ uint32
    ERRIPPR;                           /**< Error Injection Parity Pattern Register, offset: 0xAEC */
    I__  uint32 RERRAR;                            /**< Error Report Address Register, offset: 0xAF0 */
    I__  uint32 RERRDR;                            /**< Error Report Data Register, offset: 0xAF4 */
    I__  uint32 RERRSYNR;                          /**< Error Report Syndrome Register, offset: 0xAF8 */
    IO__ uint32 ERRSR;                             /**< Error Status Register, offset: 0xAFC */
    IO__ uint32
    CTRL1_PN;                          /**< Pretended Networking Control 1 Register, offset: 0xB00 */
    IO__ uint32
    CTRL2_PN;                          /**< Pretended Networking Control 2 Register, offset: 0xB04 */
    IO__ uint32
    WU_MTC;                            /**< Pretended Networking Wake Up Match Register, offset: 0xB08 */
    IO__ uint32
    FLT_ID1;                           /**< Pretended Networking ID Filter 1 Register, offset: 0xB0C */
    IO__ uint32
    FLT_DLC;                           /**< Pretended Networking DLC Filter Register, offset: 0xB10 */
    IO__ uint32
    PL1_LO;                            /**< Pretended Networking Payload Low Filter 1 Register, offset: 0xB14 */
    IO__ uint32
    PL1_HI;                            /**< Pretended Networking Payload High Filter 1 Register, offset: 0xB18 */
    IO__ uint32
    FLT_ID2_IDMASK;                    /**< Pretended Networking ID Filter 2 Register/ ID Mask Register, offset: 0xB1C */
    IO__ uint32
    PL2_PLMASK_LO;                     /**< Pretended Networking Payload Low Filter 2 Register/ Payload Low Mask Register, offset: 0xB20 */
    IO__ uint32
    PL2_PLMASK_HI;                     /**< Pretended Networking Payload High Filter 2 High Order Bits/ Payload High Mask Register, offset: 0xB24 */
    uint8 RESERVED_5[24];
    struct {                                       /* offset: 0xB40, array step: 0x10 */
        I__  uint32
        WMB_CS;                        /**< Wake Up Message Buffer Register for C/S, offset: 0xB40, array step: 0x10 */
        I__  uint32
        WMB_ID;                        /**< Wake Up Message Buffer Register for ID, offset: 0xB44, array step: 0x10 */
        I__  uint32
        WMB_D03;                       /**< Wake Up Message Buffer Register for Data 0-3, offset: 0xB48, array step: 0x10 */
        I__  uint32
        WMB_D47;                       /**< Wake Up Message Buffer Register for Data 4-7, offset: 0xB4C, array step: 0x10 */
    } WMB[4];
    uint8 RESERVED_6[128];
    IO__ uint32 FDCTRL;                            /**< CAN FD Control Register, offset: 0xC00 */
    IO__ uint32 FDCBT;                             /**< CAN FD Bit Timing Register, offset: 0xC04 */
    I__  uint32 FDCRC;                             /**< CAN FD CRC Register, offset: 0xC08 */
    /* new for E3 platform, semidriver enhancement */
    uint8 RESERVED_7[9204];
    IO__ uint32 APB_ERR_INJ_EN;  /**< APB Monitor Error Inject Enable Register, offset: 0x3000 */
    IO__ uint32 APB_ERR_INJ_ECC;  /**< APB Monitor Error Inject ECC Register, offset: 0x3004 */
    IO__ uint32 APB_ERR_INJ_WDATA;  /**< APB Monitor error inject for WDATA, offset: 0x3008 */
    IO__ uint32 ERR_IRQ_STATUS;  /**< Function Safety Error Interrupt Status Register, offset: 0x300C */
    IO__ uint32 ERR_IRQ_STATUS_EN;  /**< Safety Error Interrupt Status Enable Register, offset: 0x3010 */
    IO__ uint32 ERR_IRQ_SIG_EN;  /**< Safety Error Interrupt Signal Enable Register, offset: 0x3014 */
    IO__ uint32 IRQ_ERR_INJ;  /**< Interrupt Error Inject Register, offset: offset: 0x3018 */
    uint8 RESERVED_8[8];
    IO__ uint32 IRQ_ERR_INJ_EN;  /**< Interrupt Error Inject Enable Register, offset:0x3024 */
    IO__ uint32 DMA_HDSK_ERR_INJ;  /**< DMA Handshake Interface Error Inject Register, offset:0x3028 */
    IO__ uint32 LOWPOWER_MODE;  /**< LOWPOWER_MODE Register, offset:0x302C */
    IO__ uint32 CANFD_EJ_EN;  /**< CANFD Error Enject Enable Register, offset: 0x3030 */
    IO__ uint32 PARITY_ERR_INT_STAT;  /**< Parity Error interrupt Status Register, offset: 0x3034 */
    IO__ uint32 PARITY_ERR_INT_STAT_EN;  /**< Parity Error interrupt Status Enable Register, offset: 0x3038 */
    IO__ uint32 PARITY_ERR_INT_SIG_EN;  /**< Register Parity Error interrupt Signal Enable Register, offset: 0x303C */
    IO__ uint32 PRDATAINJ;  /**< Prdata Error Injection Register, offset: 0x3040 */
    IO__ uint32 HDSK_CONVERT_ERR_INJ;  /**< Handshake Convert Error Inject Register, offset: 0x3044 */
    IO__ uint32 GLITCH_FILTER_CONFIG;  /**< CANFD glitch filter configuration for stop and doze feature Register, offset: 0x3048 */
    IO__ uint32 SOFT_RESET;  /**< CANFD Soft Reset register, offset: 0x304C */
} Can_RegType;

/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
#define CAN_MCR_MAXMB_MASK                       (0x7FU)
#define CAN_MCR_MAXMB_SHIFT                      (0U)
#define CAN_MCR_MAXMB(x)                         (((uint32)(((uint32)(x)) << CAN_MCR_MAXMB_SHIFT)) & CAN_MCR_MAXMB_MASK)
#define CAN_MCR_IDAM_MASK                        (0x300U)
#define CAN_MCR_IDAM_SHIFT                       (8U)
#define CAN_MCR_IDAM(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_IDAM_SHIFT)) & CAN_MCR_IDAM_MASK)
#define CAN_MCR_FDEN_MASK                        (0x800U)
#define CAN_MCR_FDEN_SHIFT                       (11U)
#define CAN_MCR_FDEN(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_FDEN_SHIFT)) & CAN_MCR_FDEN_MASK)
#define CAN_MCR_AEN_MASK                         (0x1000U)
#define CAN_MCR_AEN_SHIFT                        (12U)
#define CAN_MCR_AEN(x)                           (((uint32)(((uint32)(x)) << CAN_MCR_AEN_SHIFT)) & CAN_MCR_AEN_MASK)
#define CAN_MCR_LPRIOEN_MASK                     (0x2000U)
#define CAN_MCR_LPRIOEN_SHIFT                    (13U)
#define CAN_MCR_LPRIOEN(x)                       (((uint32)(((uint32)(x)) << CAN_MCR_LPRIOEN_SHIFT)) & CAN_MCR_LPRIOEN_MASK)
#define CAN_MCR_DMA_MASK                         (0x8000U)
#define CAN_MCR_DMA_SHIFT                        (15U)
#define CAN_MCR_DMA(x)                           (((uint32)(((uint32)(x)) << CAN_MCR_DMA_SHIFT)) & CAN_MCR_DMA_MASK)
#define CAN_MCR_IRMQ_MASK                        (0x10000U)
#define CAN_MCR_IRMQ_SHIFT                       (16U)
#define CAN_MCR_IRMQ(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_IRMQ_SHIFT)) & CAN_MCR_IRMQ_MASK)
#define CAN_MCR_SRXDIS_MASK                      (0x20000U)
#define CAN_MCR_SRXDIS_SHIFT                     (17U)
#define CAN_MCR_SRXDIS(x)                        (((uint32)(((uint32)(x)) << CAN_MCR_SRXDIS_SHIFT)) & CAN_MCR_SRXDIS_MASK)
#define CAN_MCR_DOZE_MASK                        (0x40000U)
#define CAN_MCR_DOZE_SHIFT                       (18U)
#define CAN_MCR_DOZE(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_DOZE_SHIFT)) & CAN_MCR_DOZE_MASK)
#define CAN_MCR_WAKSRC_MASK                      (0x80000U)
#define CAN_MCR_WAKSRC_SHIFT                     (19U)
#define CAN_MCR_WAKSRC(x)                        (((uint32)(((uint32)(x)) << CAN_MCR_WAKSRC_SHIFT)) & CAN_MCR_WAKSRC_MASK)
#define CAN_MCR_LPMACK_MASK                      (0x100000U)
#define CAN_MCR_LPMACK_SHIFT                     (20U)
#define CAN_MCR_LPMACK(x)                        (((uint32)(((uint32)(x)) << CAN_MCR_LPMACK_SHIFT)) & CAN_MCR_LPMACK_MASK)
#define CAN_MCR_WRNEN_MASK                       (0x200000U)
#define CAN_MCR_WRNEN_SHIFT                      (21U)
#define CAN_MCR_WRNEN(x)                         (((uint32)(((uint32)(x)) << CAN_MCR_WRNEN_SHIFT)) & CAN_MCR_WRNEN_MASK)
#define CAN_MCR_SLFWAK_MASK                      (0x400000U)
#define CAN_MCR_SLFWAK_SHIFT                     (22U)
#define CAN_MCR_SLFWAK(x)                        (((uint32)(((uint32)(x)) << CAN_MCR_SLFWAK_SHIFT)) & CAN_MCR_SLFWAK_MASK)
#define CAN_MCR_SUPV_MASK                        (0x800000U)
#define CAN_MCR_SUPV_SHIFT                       (23U)
#define CAN_MCR_SUPV(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_SUPV_SHIFT)) & CAN_MCR_SUPV_MASK)
#define CAN_MCR_FRZACK_MASK                      (0x1000000U)
#define CAN_MCR_FRZACK_SHIFT                     (24U)
#define CAN_MCR_FRZACK(x)                        (((uint32)(((uint32)(x)) << CAN_MCR_FRZACK_SHIFT)) & CAN_MCR_FRZACK_MASK)
#define CAN_MCR_SOFTRST_MASK                     (0x2000000U)
#define CAN_MCR_SOFTRST_SHIFT                    (25U)
#define CAN_MCR_SOFTRST(x)                       (((uint32)(((uint32)(x)) << CAN_MCR_SOFTRST_SHIFT)) & CAN_MCR_SOFTRST_MASK)
#define CAN_MCR_WAKMSK_MASK                      (0x4000000U)
#define CAN_MCR_WAKMSK_SHIFT                     (26U)
#define CAN_MCR_WAKMSK(x)                        (((uint32)(((uint32)(x)) << CAN_MCR_WAKMSK_SHIFT)) & CAN_MCR_WAKMSK_MASK)
#define CAN_MCR_NOTRDY_MASK                      (0x8000000U)
#define CAN_MCR_NOTRDY_SHIFT                     (27U)
#define CAN_MCR_NOTRDY(x)                        (((uint32)(((uint32)(x)) << CAN_MCR_NOTRDY_SHIFT)) & CAN_MCR_NOTRDY_MASK)
#define CAN_MCR_HALT_MASK                        (0x10000000U)
#define CAN_MCR_HALT_SHIFT                       (28U)
#define CAN_MCR_HALT(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_HALT_SHIFT)) & CAN_MCR_HALT_MASK)
#define CAN_MCR_RFEN_MASK                        (0x20000000U)
#define CAN_MCR_RFEN_SHIFT                       (29U)
#define CAN_MCR_RFEN(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_RFEN_SHIFT)) & CAN_MCR_RFEN_MASK)
#define CAN_MCR_FRZ_MASK                         (0x40000000U)
#define CAN_MCR_FRZ_SHIFT                        (30U)
#define CAN_MCR_FRZ(x)                           (((uint32)(((uint32)(x)) << CAN_MCR_FRZ_SHIFT)) & CAN_MCR_FRZ_MASK)
#define CAN_MCR_MDIS_MASK                        (0x80000000U)
#define CAN_MCR_MDIS_SHIFT                       (31U)
#define CAN_MCR_MDIS(x)                          (((uint32)(((uint32)(x)) << CAN_MCR_MDIS_SHIFT)) & CAN_MCR_MDIS_MASK)

/*! @name CTRL1 - Control 1 register */
#define CAN_CTRL1_PROPSEG_MASK                   (0x7U)
#define CAN_CTRL1_PROPSEG_SHIFT                  (0U)
#define CAN_CTRL1_PROPSEG(x)                     (((uint32)(((uint32)(x)) << CAN_CTRL1_PROPSEG_SHIFT)) & CAN_CTRL1_PROPSEG_MASK)
#define CAN_CTRL1_LOM_MASK                       (0x8U)
#define CAN_CTRL1_LOM_SHIFT                      (3U)
#define CAN_CTRL1_LOM(x)                         (((uint32)(((uint32)(x)) << CAN_CTRL1_LOM_SHIFT)) & CAN_CTRL1_LOM_MASK)
#define CAN_CTRL1_LBUF_MASK                      (0x10U)
#define CAN_CTRL1_LBUF_SHIFT                     (4U)
#define CAN_CTRL1_LBUF(x)                        (((uint32)(((uint32)(x)) << CAN_CTRL1_LBUF_SHIFT)) & CAN_CTRL1_LBUF_MASK)
#define CAN_CTRL1_TSYN_MASK                      (0x20U)
#define CAN_CTRL1_TSYN_SHIFT                     (5U)
#define CAN_CTRL1_TSYN(x)                        (((uint32)(((uint32)(x)) << CAN_CTRL1_TSYN_SHIFT)) & CAN_CTRL1_TSYN_MASK)
#define CAN_CTRL1_BOFFREC_MASK                   (0x40U)
#define CAN_CTRL1_BOFFREC_SHIFT                  (6U)
#define CAN_CTRL1_BOFFREC(x)                     (((uint32)(((uint32)(x)) << CAN_CTRL1_BOFFREC_SHIFT)) & CAN_CTRL1_BOFFREC_MASK)
#define CAN_CTRL1_SMP_MASK                       (0x80U)
#define CAN_CTRL1_SMP_SHIFT                      (7U)
#define CAN_CTRL1_SMP(x)                         (((uint32)(((uint32)(x)) << CAN_CTRL1_SMP_SHIFT)) & CAN_CTRL1_SMP_MASK)
#define CAN_CTRL1_RWRNMSK_MASK                   (0x400U)
#define CAN_CTRL1_RWRNMSK_SHIFT                  (10U)
#define CAN_CTRL1_RWRNMSK(x)                     (((uint32)(((uint32)(x)) << CAN_CTRL1_RWRNMSK_SHIFT)) & CAN_CTRL1_RWRNMSK_MASK)
#define CAN_CTRL1_TWRNMSK_MASK                   (0x800U)
#define CAN_CTRL1_TWRNMSK_SHIFT                  (11U)
#define CAN_CTRL1_TWRNMSK(x)                     (((uint32)(((uint32)(x)) << CAN_CTRL1_TWRNMSK_SHIFT)) & CAN_CTRL1_TWRNMSK_MASK)
#define CAN_CTRL1_LPB_MASK                       (0x1000U)
#define CAN_CTRL1_LPB_SHIFT                      (12U)
#define CAN_CTRL1_LPB(x)                         (((uint32)(((uint32)(x)) << CAN_CTRL1_LPB_SHIFT)) & CAN_CTRL1_LPB_MASK)
#define CAN_CTRL1_CLKSRC_MASK                    (0x2000U)
#define CAN_CTRL1_CLKSRC_SHIFT                   (13U)
#define CAN_CTRL1_CLKSRC(x)                      (((uint32)(((uint32)(x)) << CAN_CTRL1_CLKSRC_SHIFT)) & CAN_CTRL1_CLKSRC_MASK)
#define CAN_CTRL1_ERRMSK_MASK                    (0x4000U)
#define CAN_CTRL1_ERRMSK_SHIFT                   (14U)
#define CAN_CTRL1_ERRMSK(x)                      (((uint32)(((uint32)(x)) << CAN_CTRL1_ERRMSK_SHIFT)) & CAN_CTRL1_ERRMSK_MASK)
#define CAN_CTRL1_BOFFMSK_MASK                   (0x8000U)
#define CAN_CTRL1_BOFFMSK_SHIFT                  (15U)
#define CAN_CTRL1_BOFFMSK(x)                     (((uint32)(((uint32)(x)) << CAN_CTRL1_BOFFMSK_SHIFT)) & CAN_CTRL1_BOFFMSK_MASK)
#define CAN_CTRL1_PSEG2_MASK                     (0x70000U)
#define CAN_CTRL1_PSEG2_SHIFT                    (16U)
#define CAN_CTRL1_PSEG2(x)                       (((uint32)(((uint32)(x)) << CAN_CTRL1_PSEG2_SHIFT)) & CAN_CTRL1_PSEG2_MASK)
#define CAN_CTRL1_PSEG1_MASK                     (0x380000U)
#define CAN_CTRL1_PSEG1_SHIFT                    (19U)
#define CAN_CTRL1_PSEG1(x)                       (((uint32)(((uint32)(x)) << CAN_CTRL1_PSEG1_SHIFT)) & CAN_CTRL1_PSEG1_MASK)
#define CAN_CTRL1_RJW_MASK                       (0xC00000U)
#define CAN_CTRL1_RJW_SHIFT                      (22U)
#define CAN_CTRL1_RJW(x)                         (((uint32)(((uint32)(x)) << CAN_CTRL1_RJW_SHIFT)) & CAN_CTRL1_RJW_MASK)
#define CAN_CTRL1_PRESDIV_MASK                   (0xFF000000U)
#define CAN_CTRL1_PRESDIV_SHIFT                  (24U)
#define CAN_CTRL1_PRESDIV(x)                     (((uint32)(((uint32)(x)) << CAN_CTRL1_PRESDIV_SHIFT)) & CAN_CTRL1_PRESDIV_MASK)

/*! @name TIMER - Free Running Timer */
#define CAN_TIMER_TIMER_MASK                     (0xFFFFU)
#define CAN_TIMER_TIMER_SHIFT                    (0U)
#define CAN_TIMER_TIMER(x)                       (((uint32)(((uint32)(x)) << CAN_TIMER_TIMER_SHIFT)) & CAN_TIMER_TIMER_MASK)

/*! @name RXMGMASK - Rx Mailboxes Global Mask Register */
#define CAN_RXMGMASK_MG_MASK                     (0xFFFFFFFFU)
#define CAN_RXMGMASK_MG_SHIFT                    (0U)
#define CAN_RXMGMASK_MG(x)                       (((uint32)(((uint32)(x)) << CAN_RXMGMASK_MG_SHIFT)) & CAN_RXMGMASK_MG_MASK)

/*! @name RX14MASK - Rx 14 Mask register */
#define CAN_RX14MASK_RX14M_MASK                  (0xFFFFFFFFU)
#define CAN_RX14MASK_RX14M_SHIFT                 (0U)
#define CAN_RX14MASK_RX14M(x)                    (((uint32)(((uint32)(x)) << CAN_RX14MASK_RX14M_SHIFT)) & CAN_RX14MASK_RX14M_MASK)

/*! @name RX15MASK - Rx 15 Mask register */
#define CAN_RX15MASK_RX15M_MASK                  (0xFFFFFFFFU)
#define CAN_RX15MASK_RX15M_SHIFT                 (0U)
#define CAN_RX15MASK_RX15M(x)                    (((uint32)(((uint32)(x)) << CAN_RX15MASK_RX15M_SHIFT)) & CAN_RX15MASK_RX15M_MASK)

/*! @name ECR - Error Counter */
#define CAN_ECR_TXERRCNT_MASK                    (0xFFU)
#define CAN_ECR_TXERRCNT_SHIFT                   (0U)
#define CAN_ECR_TXERRCNT(x)                      (((uint32)(((uint32)(x)) << CAN_ECR_TXERRCNT_SHIFT)) & CAN_ECR_TXERRCNT_MASK)
#define CAN_ECR_RXERRCNT_MASK                    (0xFF00U)
#define CAN_ECR_RXERRCNT_SHIFT                   (8U)
#define CAN_ECR_RXERRCNT(x)                      (((uint32)(((uint32)(x)) << CAN_ECR_RXERRCNT_SHIFT)) & CAN_ECR_RXERRCNT_MASK)

/*! @name ESR1 - Error and Status 1 register */
#define CAN_ESR1_WAKINT_MASK                     (0x1U)
#define CAN_ESR1_WAKINT_SHIFT                    (0U)
#define CAN_ESR1_WAKINT(x)                       (((uint32)(((uint32)(x)) << CAN_ESR1_WAKINT_SHIFT)) & CAN_ESR1_WAKINT_MASK)
#define CAN_ESR1_ERRINT_MASK                     (0x2U)
#define CAN_ESR1_ERRINT_SHIFT                    (1U)
#define CAN_ESR1_ERRINT(x)                       (((uint32)(((uint32)(x)) << CAN_ESR1_ERRINT_SHIFT)) & CAN_ESR1_ERRINT_MASK)
#define CAN_ESR1_BOFFINT_MASK                    (0x4U)
#define CAN_ESR1_BOFFINT_SHIFT                   (2U)
#define CAN_ESR1_BOFFINT(x)                      (((uint32)(((uint32)(x)) << CAN_ESR1_BOFFINT_SHIFT)) & CAN_ESR1_BOFFINT_MASK)
#define CAN_ESR1_RX_MASK                         (0x8U)
#define CAN_ESR1_RX_SHIFT                        (3U)
#define CAN_ESR1_RX(x)                           (((uint32)(((uint32)(x)) << CAN_ESR1_RX_SHIFT)) & CAN_ESR1_RX_MASK)
#define CAN_ESR1_FLTCONF_MASK                    (0x30U)
#define CAN_ESR1_FLTCONF_SHIFT                   (4U)
#define CAN_ESR1_FLTCONF(x)                      (((uint32)(((uint32)(x)) << CAN_ESR1_FLTCONF_SHIFT)) & CAN_ESR1_FLTCONF_MASK)
#define CAN_ESR1_TX_MASK                         (0x40U)
#define CAN_ESR1_TX_SHIFT                        (6U)
#define CAN_ESR1_TX(x)                           (((uint32)(((uint32)(x)) << CAN_ESR1_TX_SHIFT)) & CAN_ESR1_TX_MASK)
#define CAN_ESR1_IDLE_MASK                       (0x80U)
#define CAN_ESR1_IDLE_SHIFT                      (7U)
#define CAN_ESR1_IDLE(x)                         (((uint32)(((uint32)(x)) << CAN_ESR1_IDLE_SHIFT)) & CAN_ESR1_IDLE_MASK)
#define CAN_ESR1_RXWRN_MASK                      (0x100U)
#define CAN_ESR1_RXWRN_SHIFT                     (8U)
#define CAN_ESR1_RXWRN(x)                        (((uint32)(((uint32)(x)) << CAN_ESR1_RXWRN_SHIFT)) & CAN_ESR1_RXWRN_MASK)
#define CAN_ESR1_TXWRN_MASK                      (0x200U)
#define CAN_ESR1_TXWRN_SHIFT                     (9U)
#define CAN_ESR1_TXWRN(x)                        (((uint32)(((uint32)(x)) << CAN_ESR1_TXWRN_SHIFT)) & CAN_ESR1_TXWRN_MASK)
#define CAN_ESR1_STFERR_MASK                     (0x400U)
#define CAN_ESR1_STFERR_SHIFT                    (10U)
#define CAN_ESR1_STFERR(x)                       (((uint32)(((uint32)(x)) << CAN_ESR1_STFERR_SHIFT)) & CAN_ESR1_STFERR_MASK)
#define CAN_ESR1_FRMERR_MASK                     (0x800U)
#define CAN_ESR1_FRMERR_SHIFT                    (11U)
#define CAN_ESR1_FRMERR(x)                       (((uint32)(((uint32)(x)) << CAN_ESR1_FRMERR_SHIFT)) & CAN_ESR1_FRMERR_MASK)
#define CAN_ESR1_CRCERR_MASK                     (0x1000U)
#define CAN_ESR1_CRCERR_SHIFT                    (12U)
#define CAN_ESR1_CRCERR(x)                       (((uint32)(((uint32)(x)) << CAN_ESR1_CRCERR_SHIFT)) & CAN_ESR1_CRCERR_MASK)
#define CAN_ESR1_ACKERR_MASK                     (0x2000U)
#define CAN_ESR1_ACKERR_SHIFT                    (13U)
#define CAN_ESR1_ACKERR(x)                       (((uint32)(((uint32)(x)) << CAN_ESR1_ACKERR_SHIFT)) & CAN_ESR1_ACKERR_MASK)
#define CAN_ESR1_BIT0ERR_MASK                    (0x4000U)
#define CAN_ESR1_BIT0ERR_SHIFT                   (14U)
#define CAN_ESR1_BIT0ERR(x)                      (((uint32)(((uint32)(x)) << CAN_ESR1_BIT0ERR_SHIFT)) & CAN_ESR1_BIT0ERR_MASK)
#define CAN_ESR1_BIT1ERR_MASK                    (0x8000U)
#define CAN_ESR1_BIT1ERR_SHIFT                   (15U)
#define CAN_ESR1_BIT1ERR(x)                      (((uint32)(((uint32)(x)) << CAN_ESR1_BIT1ERR_SHIFT)) & CAN_ESR1_BIT1ERR_MASK)
#define CAN_ESR1_RWRNINT_MASK                    (0x10000U)
#define CAN_ESR1_RWRNINT_SHIFT                   (16U)
#define CAN_ESR1_RWRNINT(x)                      (((uint32)(((uint32)(x)) << CAN_ESR1_RWRNINT_SHIFT)) & CAN_ESR1_RWRNINT_MASK)
#define CAN_ESR1_TWRNINT_MASK                    (0x20000U)
#define CAN_ESR1_TWRNINT_SHIFT                   (17U)
#define CAN_ESR1_TWRNINT(x)                      (((uint32)(((uint32)(x)) << CAN_ESR1_TWRNINT_SHIFT)) & CAN_ESR1_TWRNINT_MASK)
#define CAN_ESR1_SYNCH_MASK                      (0x40000U)
#define CAN_ESR1_SYNCH_SHIFT                     (18U)
#define CAN_ESR1_SYNCH(x)                        (((uint32)(((uint32)(x)) << CAN_ESR1_SYNCH_SHIFT)) & CAN_ESR1_SYNCH_MASK)
#define CAN_ESR1_BOFFDONEINT_MASK                (0x80000U)
#define CAN_ESR1_BOFFDONEINT_SHIFT               (19U)
#define CAN_ESR1_BOFFDONEINT(x)                  (((uint32)(((uint32)(x)) << CAN_ESR1_BOFFDONEINT_SHIFT)) & CAN_ESR1_BOFFDONEINT_MASK)
#define CAN_ESR1_ERRINT_FAST_MASK                (0x100000U)
#define CAN_ESR1_ERRINT_FAST_SHIFT               (20U)
#define CAN_ESR1_ERRINT_FAST(x)                  (((uint32)(((uint32)(x)) << CAN_ESR1_ERRINT_FAST_SHIFT)) & CAN_ESR1_ERRINT_FAST_MASK)
#define CAN_ESR1_ERROVR_MASK                     (0x200000U)
#define CAN_ESR1_ERROVR_SHIFT                    (21U)
#define CAN_ESR1_ERROVR(x)                       (((uint32)(((uint32)(x)) << CAN_ESR1_ERROVR_SHIFT)) & CAN_ESR1_ERROVR_MASK)

/*! @name IMASK1 - Interrupt Masks 1 register */
#define CAN_IMASK1_BUF31TO0M_MASK                (0xFFFFFFFFU)
#define CAN_IMASK1_BUF31TO0M_SHIFT               (0U)
#define CAN_IMASK1_BUF31TO0M(x)                  (((uint32)(((uint32)(x)) << CAN_IMASK1_BUF31TO0M_SHIFT)) & CAN_IMASK1_BUF31TO0M_MASK)

/*! @name IFLAG1 - Interrupt Flags 1 register */
#define CAN_IFLAG1_BUF0I_MASK                    (0x1U)
#define CAN_IFLAG1_BUF0I_SHIFT                   (0U)
#define CAN_IFLAG1_BUF0I(x)                      (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF0I_SHIFT)) & CAN_IFLAG1_BUF0I_MASK)
#define CAN_IFLAG1_BUF4TO1I_MASK                 (0x1EU)
#define CAN_IFLAG1_BUF4TO1I_SHIFT                (1U)
#define CAN_IFLAG1_BUF4TO1I(x)                   (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF4TO1I_SHIFT)) & CAN_IFLAG1_BUF4TO1I_MASK)
#define CAN_IFLAG1_BUF5I_MASK                    (0x20U)
#define CAN_IFLAG1_BUF5I_SHIFT                   (5U)
#define CAN_IFLAG1_BUF5I(x)                      (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF5I_SHIFT)) & CAN_IFLAG1_BUF5I_MASK)
#define CAN_IFLAG1_BUF6I_MASK                    (0x40U)
#define CAN_IFLAG1_BUF6I_SHIFT                   (6U)
#define CAN_IFLAG1_BUF6I(x)                      (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF6I_SHIFT)) & CAN_IFLAG1_BUF6I_MASK)
#define CAN_IFLAG1_BUF7I_MASK                    (0x80U)
#define CAN_IFLAG1_BUF7I_SHIFT                   (7U)
#define CAN_IFLAG1_BUF7I(x)                      (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF7I_SHIFT)) & CAN_IFLAG1_BUF7I_MASK)
#define CAN_IFLAG1_BUF31TO8I_MASK                (0xFFFFFF00U)
#define CAN_IFLAG1_BUF31TO8I_SHIFT               (8U)
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32)(((uint32)(x)) << CAN_IFLAG1_BUF31TO8I_SHIFT)) & CAN_IFLAG1_BUF31TO8I_MASK)

/*! @name CTRL2 - Control 2 register */
#define CAN_CTRL2_EDFLTDIS_MASK                  (0x800U)
#define CAN_CTRL2_EDFLTDIS_SHIFT                 (11U)
#define CAN_CTRL2_EDFLTDIS(x)                    (((uint32)(((uint32)(x)) << CAN_CTRL2_EDFLTDIS_SHIFT)) & CAN_CTRL2_EDFLTDIS_MASK)
#define CAN_CTRL2_ISOCANFDEN_MASK                (0x1000U)
#define CAN_CTRL2_ISOCANFDEN_SHIFT               (12U)
#define CAN_CTRL2_ISOCANFDEN(x)                  (((uint32)(((uint32)(x)) << CAN_CTRL2_ISOCANFDEN_SHIFT)) & CAN_CTRL2_ISOCANFDEN_MASK)
#define CAN_CTRL2_PREXCEN_MASK                   (0x4000U)
#define CAN_CTRL2_PREXCEN_SHIFT                  (14U)
#define CAN_CTRL2_PREXCEN(x)                     (((uint32)(((uint32)(x)) << CAN_CTRL2_PREXCEN_SHIFT)) & CAN_CTRL2_PREXCEN_MASK)
#define CAN_CTRL2_TIMER_SRC_MASK                 (0x8000U)
#define CAN_CTRL2_TIMER_SRC_SHIFT                (15U)
#define CAN_CTRL2_TIMER_SRC(x)                   (((uint32)(((uint32)(x)) << CAN_CTRL2_TIMER_SRC_SHIFT)) & CAN_CTRL2_TIMER_SRC_MASK)
#define CAN_CTRL2_EACEN_MASK                     (0x10000U)
#define CAN_CTRL2_EACEN_SHIFT                    (16U)
#define CAN_CTRL2_EACEN(x)                       (((uint32)(((uint32)(x)) << CAN_CTRL2_EACEN_SHIFT)) & CAN_CTRL2_EACEN_MASK)
#define CAN_CTRL2_RRS_MASK                       (0x20000U)
#define CAN_CTRL2_RRS_SHIFT                      (17U)
#define CAN_CTRL2_RRS(x)                         (((uint32)(((uint32)(x)) << CAN_CTRL2_RRS_SHIFT)) & CAN_CTRL2_RRS_MASK)
#define CAN_CTRL2_MRP_MASK                       (0x40000U)
#define CAN_CTRL2_MRP_SHIFT                      (18U)
#define CAN_CTRL2_MRP(x)                         (((uint32)(((uint32)(x)) << CAN_CTRL2_MRP_SHIFT)) & CAN_CTRL2_MRP_MASK)
#define CAN_CTRL2_TASD_MASK                      (0xF80000U)
#define CAN_CTRL2_TASD_SHIFT                     (19U)
#define CAN_CTRL2_TASD(x)                        (((uint32)(((uint32)(x)) << CAN_CTRL2_TASD_SHIFT)) & CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_RFFN_MASK                      (0xF000000U)
#define CAN_CTRL2_RFFN_SHIFT                     (24U)
#define CAN_CTRL2_RFFN(x)                        (((uint32)(((uint32)(x)) << CAN_CTRL2_RFFN_SHIFT)) & CAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_WRMFRZ_MASK                    (0x10000000U)
#define CAN_CTRL2_WRMFRZ_SHIFT                   (28U)
#define CAN_CTRL2_WRMFRZ(x)                      (((uint32)(((uint32)(x)) << CAN_CTRL2_WRMFRZ_SHIFT)) & CAN_CTRL2_WRMFRZ_MASK)
#define CAN_CTRL2_ECRWRE_MASK                    (0x20000000U)
#define CAN_CTRL2_ECRWRE_SHIFT                   (29U)
#define CAN_CTRL2_ECRWRE(x)                      (((uint32)(((uint32)(x)) << CAN_CTRL2_ECRWRE_SHIFT)) & CAN_CTRL2_ECRWRE_MASK)
#define CAN_CTRL2_BOFFDONEMSK_MASK               (0x40000000U)
#define CAN_CTRL2_BOFFDONEMSK_SHIFT              (30U)
#define CAN_CTRL2_BOFFDONEMSK(x)                 (((uint32)(((uint32)(x)) << CAN_CTRL2_BOFFDONEMSK_SHIFT)) & CAN_CTRL2_BOFFDONEMSK_MASK)
#define CAN_CTRL2_ERRMSK_FAST_MASK               (0x80000000U)
#define CAN_CTRL2_ERRMSK_FAST_SHIFT              (31U)
#define CAN_CTRL2_ERRMSK_FAST(x)                 (((uint32)(((uint32)(x)) << CAN_CTRL2_ERRMSK_FAST_SHIFT)) & CAN_CTRL2_ERRMSK_FAST_MASK)

/*! @name ESR2 - Error and Status 2 register */
#define CAN_ESR2_IMB_MASK                        (0x2000U)
#define CAN_ESR2_IMB_SHIFT                       (13U)
#define CAN_ESR2_IMB(x)                          (((uint32)(((uint32)(x)) << CAN_ESR2_IMB_SHIFT)) & CAN_ESR2_IMB_MASK)
#define CAN_ESR2_VPS_MASK                        (0x4000U)
#define CAN_ESR2_VPS_SHIFT                       (14U)
#define CAN_ESR2_VPS(x)                          (((uint32)(((uint32)(x)) << CAN_ESR2_VPS_SHIFT)) & CAN_ESR2_VPS_MASK)
#define CAN_ESR2_LPTM_MASK                       (0x7F0000U)
#define CAN_ESR2_LPTM_SHIFT                      (16U)
#define CAN_ESR2_LPTM(x)                         (((uint32)(((uint32)(x)) << CAN_ESR2_LPTM_SHIFT)) & CAN_ESR2_LPTM_MASK)

/*! @name CRCR - CRC Register */
#define CAN_CRCR_TXCRC_MASK                      (0x7FFFU)
#define CAN_CRCR_TXCRC_SHIFT                     (0U)
#define CAN_CRCR_TXCRC(x)                        (((uint32)(((uint32)(x)) << CAN_CRCR_TXCRC_SHIFT)) & CAN_CRCR_TXCRC_MASK)
#define CAN_CRCR_MBCRC_MASK                      (0x7F0000U)
#define CAN_CRCR_MBCRC_SHIFT                     (16U)
#define CAN_CRCR_MBCRC(x)                        (((uint32)(((uint32)(x)) << CAN_CRCR_MBCRC_SHIFT)) & CAN_CRCR_MBCRC_MASK)

/*! @name RXFGMASK - Rx FIFO Global Mask register */
#define CAN_RXFGMASK_FGM_MASK                    (0xFFFFFFFFU)
#define CAN_RXFGMASK_FGM_SHIFT                   (0U)
#define CAN_RXFGMASK_FGM(x)                      (((uint32)(((uint32)(x)) << CAN_RXFGMASK_FGM_SHIFT)) & CAN_RXFGMASK_FGM_MASK)

/*! @name RXFIR - Rx FIFO Information Register */
#define CAN_RXFIR_IDHIT_MASK                     (0x1FFU)
#define CAN_RXFIR_IDHIT_SHIFT                    (0U)
#define CAN_RXFIR_IDHIT(x)                       (((uint32)(((uint32)(x)) << CAN_RXFIR_IDHIT_SHIFT)) & CAN_RXFIR_IDHIT_MASK)

/*! @name CBT - CAN Bit Timing Register */
#define CAN_CBT_EPSEG2_MASK                      (0x1FU)
#define CAN_CBT_EPSEG2_SHIFT                     (0U)
#define CAN_CBT_EPSEG2(x)                        (((uint32)(((uint32)(x)) << CAN_CBT_EPSEG2_SHIFT)) & CAN_CBT_EPSEG2_MASK)
#define CAN_CBT_EPSEG1_MASK                      (0x3E0U)
#define CAN_CBT_EPSEG1_SHIFT                     (5U)
#define CAN_CBT_EPSEG1(x)                        (((uint32)(((uint32)(x)) << CAN_CBT_EPSEG1_SHIFT)) & CAN_CBT_EPSEG1_MASK)
#define CAN_CBT_EPROPSEG_MASK                    (0xFC00U)
#define CAN_CBT_EPROPSEG_SHIFT                   (10U)
#define CAN_CBT_EPROPSEG(x)                      (((uint32)(((uint32)(x)) << CAN_CBT_EPROPSEG_SHIFT)) & CAN_CBT_EPROPSEG_MASK)
#define CAN_CBT_ERJW_MASK                        (0xF0000U)
#define CAN_CBT_ERJW_SHIFT                       (16U)
#define CAN_CBT_ERJW(x)                          (((uint32)(((uint32)(x)) << CAN_CBT_ERJW_SHIFT)) & CAN_CBT_ERJW_MASK)
#define CAN_CBT_EPRESDIV_MASK                    (0x7FE00000U)
#define CAN_CBT_EPRESDIV_SHIFT                   (21U)
#define CAN_CBT_EPRESDIV(x)                      (((uint32)(((uint32)(x)) << CAN_CBT_EPRESDIV_SHIFT)) & CAN_CBT_EPRESDIV_MASK)
#define CAN_CBT_BTF_MASK                         (0x80000000U)
#define CAN_CBT_BTF_SHIFT                        (31U)
#define CAN_CBT_BTF(x)                           (((uint32)(((uint32)(x)) << CAN_CBT_BTF_SHIFT)) & CAN_CBT_BTF_MASK)

/*! @name MECR - Memory Error Control Register */
#define CAN_MECR_NCEFAFRZ_MASK                   (0x80U)
#define CAN_MECR_NCEFAFRZ_SHIFT                  (7U)
#define CAN_MECR_NCEFAFRZ(x)                     (((uint32)(((uint32)(x)) << CAN_MECR_NCEFAFRZ_SHIFT)) & CAN_MECR_NCEFAFRZ_MASK)
#define CAN_MECR_ECCDIS_MASK                     (0x100U)
#define CAN_MECR_ECCDIS_SHIFT                    (8U)
#define CAN_MECR_ECCDIS(x)                       (((uint32)(((uint32)(x)) << CAN_MECR_ECCDIS_SHIFT)) & CAN_MECR_ECCDIS_MASK)
#define CAN_MECR_RERRDIS_MASK                    (0x200U)
#define CAN_MECR_RERRDIS_SHIFT                   (9U)
#define CAN_MECR_RERRDIS(x)                      (((uint32)(((uint32)(x)) << CAN_MECR_RERRDIS_SHIFT)) & CAN_MECR_RERRDIS_MASK)
#define CAN_MECR_EXTERRIE_MASK                   (0x2000U)
#define CAN_MECR_EXTERRIE_SHIFT                  (13U)
#define CAN_MECR_EXTERRIE(x)                     (((uint32)(((uint32)(x)) << CAN_MECR_EXTERRIE_SHIFT)) & CAN_MECR_EXTERRIE_MASK)
#define CAN_MECR_FAERRIE_MASK                    (0x4000U)
#define CAN_MECR_FAERRIE_SHIFT                   (14U)
#define CAN_MECR_FAERRIE(x)                      (((uint32)(((uint32)(x)) << CAN_MECR_FAERRIE_SHIFT)) & CAN_MECR_FAERRIE_MASK)
#define CAN_MECR_HAERRIE_MASK                    (0x8000U)
#define CAN_MECR_HAERRIE_SHIFT                   (15U)
#define CAN_MECR_HAERRIE(x)                      (((uint32)(((uint32)(x)) << CAN_MECR_HAERRIE_SHIFT)) & CAN_MECR_HAERRIE_MASK)
#define CAN_MECR_CEI_MSK_MASK                    (0x10000U)
#define CAN_MECR_CEI_MSK_SHIFT                   (16U)
#define CAN_MECR_CEI_MSK(x)                      (((uint32)(((uint32)(x)) << CAN_MECR_CEI_MSK_SHIFT)) & CAN_MECR_CEI_MSK_MASK)
#define CAN_MECR_FANCEI_MSK_MASK                 (0x40000U)
#define CAN_MECR_FANCEI_MSK_SHIFT                (18U)
#define CAN_MECR_FANCEI_MSK(x)                   (((uint32)(((uint32)(x)) << CAN_MECR_FANCEI_MSK_SHIFT)) & CAN_MECR_FANCEI_MSK_MASK)
#define CAN_MECR_HANCEI_MSK_MASK                 (0x80000U)
#define CAN_MECR_HANCEI_MSK_SHIFT                (19U)
#define CAN_MECR_HANCEI_MSK(x)                   (((uint32)(((uint32)(x)) << CAN_MECR_HANCEI_MSK_SHIFT)) & CAN_MECR_HANCEI_MSK_MASK)
#define CAN_MECR_ECRWRDIS_MASK                   (0x80000000U)
#define CAN_MECR_ECRWRDIS_SHIFT                  (31U)
#define CAN_MECR_ECRWRDIS(x)                     (((uint32)(((uint32)(x)) << CAN_MECR_ECRWRDIS_SHIFT)) & CAN_MECR_ECRWRDIS_MASK)

/*! @name CS - Message Buffer CS Register */
#define CAN_CS_TIME_STAMP_MASK                   (0xFFFFU)
#define CAN_CS_TIME_STAMP_SHIFT                  (0U)
#define CAN_CS_TIME_STAMP(x)                     (((uint32)(((uint32)(x)) << CAN_CS_TIME_STAMP_SHIFT)) & CAN_CS_TIME_STAMP_MASK)
#define CAN_CS_DLC_MASK                          (0xF0000U)
#define CAN_CS_DLC_SHIFT                         (16U)
#define CAN_CS_DLC(x)                            (((uint32)(((uint32)(x)) << CAN_CS_DLC_SHIFT)) & CAN_CS_DLC_MASK)
#define CAN_CS_RTR_MASK                          (0x100000U)
#define CAN_CS_RTR_SHIFT                         (20U)
#define CAN_CS_RTR(x)                            (((uint32)(((uint32)(x)) << CAN_CS_RTR_SHIFT)) & CAN_CS_RTR_MASK)
#define CAN_CS_IDE_MASK                          (0x200000U)
#define CAN_CS_IDE_SHIFT                         (21U)
#define CAN_CS_IDE(x)                            (((uint32)(((uint32)(x)) << CAN_CS_IDE_SHIFT)) & CAN_CS_IDE_MASK)
#define CAN_CS_SRR_MASK                          (0x400000U)
#define CAN_CS_SRR_SHIFT                         (22U)
#define CAN_CS_SRR(x)                            (((uint32)(((uint32)(x)) << CAN_CS_SRR_SHIFT)) & CAN_CS_SRR_MASK)
#define CAN_CS_CODE_MASK                         (0xF000000U)
#define CAN_CS_CODE_SHIFT                        (24U)
#define CAN_CS_CODE(x)                           (((uint32)(((uint32)(x)) << CAN_CS_CODE_SHIFT)) & CAN_CS_CODE_MASK)
#define CAN_CS_ESI_MASK                          (0x20000000U)
#define CAN_CS_ESI_SHIFT                         (29U)
#define CAN_CS_ESI(x)                            ((uint32)(((uint32)(x)) << CAN_CS_ESI_SHIFT)) & CAN_CS_ESI_MASK)
#define CAN_CS_BRS_MASK                          (0x40000000U)
#define CAN_CS_BRS_SHIFT                         (30U)
#define CAN_CS_BRS(x)                            ((uint32)(((uint32)(x)) << CAN_CS_BRS_SHIFT)) & CAN_CS_BRS_MASK)
#define CAN_CS_EDL_MASK                          (0x80000000U)
#define CAN_CS_EDL_SHIFT                         (31U)
#define CAN_CS_EDL(x)                            ((uint32)(((uint32)(x)) << CAN_CS_EDL_SHIFT)) & CAN_CS_EDL_MASK)

/* The count of CAN_CS */
#define CAN_CS_COUNT                             (128U)

/*! @name ID - Message Buffer 0 ID Register..Message Buffer 15 ID Register */
#define CAN_ID_EXT_MASK                          (0x3FFFFU)
#define CAN_ID_EXT_SHIFT                         (0U)
#define CAN_ID_EXT(x)                            (((uint32)(((uint32)(x)) << CAN_ID_EXT_SHIFT)) & CAN_ID_EXT_MASK)
#define CAN_ID_STD_MASK                          (0x1FFC0000U)
#define CAN_ID_STD_SHIFT                         (18U)
#define CAN_ID_STD(x)                            (((uint32)(((uint32)(x)) << CAN_ID_STD_SHIFT)) & CAN_ID_STD_MASK)
#define CAN_ID_PRIO_MASK                         (0xE0000000U)
#define CAN_ID_PRIO_SHIFT                        (29U)
#define CAN_ID_PRIO(x)                           (((uint32)(((uint32)(x)) << CAN_ID_PRIO_SHIFT)) & CAN_ID_PRIO_MASK)

/* The count of CAN_ID */
#define CAN_ID_COUNT                             (128U)

/*! @name WORD0 - Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register */
#define CAN_WORD0_DATA_BYTE_3_MASK               (0xFFU)
#define CAN_WORD0_DATA_BYTE_3_SHIFT              (0U)
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32)(((uint32)(x)) << CAN_WORD0_DATA_BYTE_3_SHIFT)) & CAN_WORD0_DATA_BYTE_3_MASK)
#define CAN_WORD0_DATA_BYTE_2_MASK               (0xFF00U)
#define CAN_WORD0_DATA_BYTE_2_SHIFT              (8U)
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32)(((uint32)(x)) << CAN_WORD0_DATA_BYTE_2_SHIFT)) & CAN_WORD0_DATA_BYTE_2_MASK)
#define CAN_WORD0_DATA_BYTE_1_MASK               (0xFF0000U)
#define CAN_WORD0_DATA_BYTE_1_SHIFT              (16U)
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32)(((uint32)(x)) << CAN_WORD0_DATA_BYTE_1_SHIFT)) & CAN_WORD0_DATA_BYTE_1_MASK)
#define CAN_WORD0_DATA_BYTE_0_MASK               (0xFF000000U)
#define CAN_WORD0_DATA_BYTE_0_SHIFT              (24U)
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32)(((uint32)(x)) << CAN_WORD0_DATA_BYTE_0_SHIFT)) & CAN_WORD0_DATA_BYTE_0_MASK)

/* The count of CAN_WORD0 */
#define CAN_WORD0_COUNT                          (128U)

/*! @name WORD1 - Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register */
#define CAN_WORD1_DATA_BYTE_7_MASK               (0xFFU)
#define CAN_WORD1_DATA_BYTE_7_SHIFT              (0U)
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32)(((uint32)(x)) << CAN_WORD1_DATA_BYTE_7_SHIFT)) & CAN_WORD1_DATA_BYTE_7_MASK)
#define CAN_WORD1_DATA_BYTE_6_MASK               (0xFF00U)
#define CAN_WORD1_DATA_BYTE_6_SHIFT              (8U)
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32)(((uint32)(x)) << CAN_WORD1_DATA_BYTE_6_SHIFT)) & CAN_WORD1_DATA_BYTE_6_MASK)
#define CAN_WORD1_DATA_BYTE_5_MASK               (0xFF0000U)
#define CAN_WORD1_DATA_BYTE_5_SHIFT              (16U)
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32)(((uint32)(x)) << CAN_WORD1_DATA_BYTE_5_SHIFT)) & CAN_WORD1_DATA_BYTE_5_MASK)
#define CAN_WORD1_DATA_BYTE_4_MASK               (0xFF000000U)
#define CAN_WORD1_DATA_BYTE_4_SHIFT              (24U)
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32)(((uint32)(x)) << CAN_WORD1_DATA_BYTE_4_SHIFT)) & CAN_WORD1_DATA_BYTE_4_MASK)

/* The count of CAN_WORD1 */
#define CAN_WORD1_COUNT                          (128U)

/*! @name RXIMR - Rx Individual Mask Registers */
#define CAN_RXIMR_MI_MASK                        (0xFFFFFFFFU)
#define CAN_RXIMR_MI_SHIFT                       (0U)
#define CAN_RXIMR_MI(x)                          (((uint32)(((uint32)(x)) << CAN_RXIMR_MI_SHIFT)) & CAN_RXIMR_MI_MASK)

/* The count of CAN_RXIMR */
#define CAN_RXIMR_COUNT                          (128U)

/*! @name FDCTRL - CAN FD Control Register */
#define CAN_FDCTRL_TDCVAL_MASK                   (0x3FU)
#define CAN_FDCTRL_TDCVAL_SHIFT                  (0U)
#define CAN_FDCTRL_TDCOFF_MASK                   (0x1F00U)
#define CAN_FDCTRL_TDCOFF_SHIFT                  (8U)
#define CAN_FDCTRL_TDCOFF(x)                     (((uint32)(((uint32)(x)) << CAN_FDCTRL_TDCOFF_SHIFT)) & CAN_FDCTRL_TDCOFF_MASK)
#define CAN_FDCTRL_TDCFAIL_MASK                  (0x4000U)
#define CAN_FDCTRL_TDCFAIL_SHIFT                 (14U)
#define CAN_FDCTRL_TDCFAIL(x)                    (((uint32)(((uint32)(x)) << CAN_FDCTRL_TDCFAIL_SHIFT)) & CAN_FDCTRL_TDCFAIL_MASK)
#define CAN_FDCTRL_TDCEN_MASK                    (0x8000U)
#define CAN_FDCTRL_TDCEN_SHIFT                   (15U)
#define CAN_FDCTRL_TDCEN(x)                      (((uint32)(((uint32)(x)) << CAN_FDCTRL_TDCEN_SHIFT)) & CAN_FDCTRL_TDCEN_MASK)
#define CAN_FDCTRL_MBDSR0_MASK                   (0x30000U)
#define CAN_FDCTRL_MBDSR0_SHIFT                  (16U)
#define CAN_FDCTRL_MBDSR0(x)                     (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR0_SHIFT)) & CAN_FDCTRL_MBDSR0_MASK)
#define CAN_FDCTRL_MBDSR1_MASK                   (0x180000U)
#define CAN_FDCTRL_MBDSR1_SHIFT                  (19U)
#define CAN_FDCTRL_MBDSR1(x)                     (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR1_SHIFT)) & CAN_FDCTRL_MBDSR1_MASK)
#define CAN_FDCTRL_MBDSR2_MASK                   (0xC00000U)
#define CAN_FDCTRL_MBDSR2_SHIFT                  (22U)
#define CAN_FDCTRL_MBDSR2(x)                     (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR2_SHIFT)) & CAN_FDCTRL_MBDSR2_MASK)
#define CAN_FDCTRL_MBDSR3_MASK                   (0x6000000U)
#define CAN_FDCTRL_MBDSR3_SHIFT                  (25U)
#define CAN_FDCTRL_MBDSR3(x)                     (((uint32)(((uint32)(x)) << CAN_FDCTRL_MBDSR3_SHIFT)) & CAN_FDCTRL_MBDSR3_MASK)
#define CAN_FDCTRL_FDRATE_MASK                   (0x80000000U)
#define CAN_FDCTRL_FDRATE_SHIFT                  (31U)
#define CAN_FDCTRL_FDRATE(x)                     (((uint32)(((uint32)(x)) << CAN_FDCTRL_FDRATE_SHIFT)) & CAN_FDCTRL_FDRATE_MASK)

/*! @name FDCBT - CAN FD Bit Timing Register */
#define CAN_FDCBT_FPSEG2_MASK                    (7U)
#define CAN_FDCBT_FPSEG2_SHIFT                   (0U)
#define CAN_FDCBT_FPSEG2(x)                      (((uint32)(((uint32)(x)) << CAN_FDCBT_FPSEG2_SHIFT)) & CAN_FDCBT_FPSEG2_MASK)
#define CAN_FDCBT_FPSEG1_MASK                    (0xE0U)
#define CAN_FDCBT_FPSEG1_SHIFT                   (5U)
#define CAN_FDCBT_FPSEG1(x)                      (((uint32)(((uint32)(x)) << CAN_FDCBT_FPSEG1_SHIFT)) & CAN_FDCBT_FPSEG1_MASK)
#define CAN_FDCBT_FPROPSEG_MASK                  (0x7C00U)
#define CAN_FDCBT_FPROPSEG_SHIFT                 (10U)
#define CAN_FDCBT_FPROPSEG(x)                    (((uint32)(((uint32)(x)) << CAN_FDCBT_FPROPSEG_SHIFT)) & CAN_FDCBT_FPROPSEG_MASK)
#define CAN_FDCBT_FRJW_MASK                      (0x70000U)
#define CAN_FDCBT_FRJW_SHIFT                     (16U)
#define CAN_FDCBT_FRJW(x)                        (((uint32)(((uint32)(x)) << CAN_FDCBT_FRJW_SHIFT)) & CAN_FDCBT_FRJW_MASK)
#define CAN_FDCBT_FPRESDIV_MASK                  (0x3FF00000U)
#define CAN_FDCBT_FPRESDIV_SHIFT                 (20U)
#define CAN_FDCBT_FPRESDIV(x)                    (((uint32)(((uint32)(x)) << CAN_FDCBT_FPRESDIV_SHIFT)) & CAN_FDCBT_FPRESDIV_MASK)

/*! @name SAFTY_ERR_IRQ_STATUS */
#define APB_PSLVERR_INT_STAT_MASK                (0x200000U)

/*! @name SAFTY_ERR_IRQ_STATUS_EN */
#define APB_PSLVERR_INT_STAT_EN_MASK             (0x200000U)

#ifdef __cplusplus
}
#endif
#endif /* CAN_IP_REG_H_ */
