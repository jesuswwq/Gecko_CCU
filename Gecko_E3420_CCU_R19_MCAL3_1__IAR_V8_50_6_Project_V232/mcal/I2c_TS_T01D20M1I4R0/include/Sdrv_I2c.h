/**
 * @file Sdrv_I2c.h
 * @low level sdrv i2c head file.
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 *
 **/

#ifndef SDRV_I2C_H_
#define SDRV_I2C_H_

/* Doorbell */
#define I2C_MASTER_DOORBELL (0xA53CU)

/* adapter opmode */
#define SDRV_I2C_SLAVE  0x0
#define SDRV_SM_SLAVE   0x1
#define SDRV_PM_SLAVE   0x2
#define SDRV_I2C_MASTER 0x8

/* adapter speedmode */
#define SDRV_I2C_NSPEED 0x0
#define SDRV_I2C_HSPEED 0x3
#define SDRV_I2C_USPEED 0x4

/* fifo watermark level */
#define SDRV_I2C_RX_WML 0x1f
#define SDRV_I2C_TX_WML 0x1f

/* register address */
#define I2C_MCR0    0x00
#define I2C_MCR0_MODEN_BIT      (0U)
#define I2C_MCR0_MODEN_MASK     (0x1U)
#define I2C_MCR0_MODEN_LEN      (1U)
#define I2C_MCR0_MODRST_BIT     (1U)
#define I2C_MCR0_MODRST_MASK    (0x1U)
#define I2C_MCR0_MODRST_LEN     (1U)
#define I2C_MCR0_CGC_BIT        (2U)
#define I2C_MCR0_CGC_MASK       (0x3U)
#define I2C_MCR0_OPMOD_BIT      (4U)
#define I2C_MCR0_OPMOD_MASK     (0xFU)
#define I2C_MCR0_OPMOD_LEN      (4U)
#define I2C_MCR0_QCHCTL_BIT     (8U)
#define I2C_MCR0_QCHCTL_MASK    (0x1U)
#define I2C_MCR0_SELFTESTMODEEN_BIT     (9U)
#define I2C_MCR0_SELFTESTMODEEN_MASK    (0x1U)

#define I2C_MCR1    0x04
#define I2C_MCR2    0x08
#define I2C_MCR3    0x0C
#define I2C_MCR4    0x10

#define I2C_INTR0   0x20
#define I2C_INTR1   0x24
#define I2C_INTR2   0x28
#define I2C_INTR3   0x2C
#define I2C_INTEN0  0x30
#define I2C_INTEN1  0x34
#define I2C_INTEN2  0x38
#define I2C_INTEN3  0x3C

#define I2C_CMDCSR0 0x40
#define I2C_CMDCSR0_DOORBELL_BIT        (0U)
#define I2C_CMDCSR0_DOORBELL_MASK       (0xFFFFU)
#define I2C_CMDCSR0_AUTOSTOP_BIT        (30U)
#define I2C_CMDCSR0_AUTOSTOP_MASK       (0x1U)
#define I2C_CMDCSR0_TRANSNUM_BIT        (31U)
#define I2C_CMDCSR0_TRANSNUM_MASK       (0x1U)

#define I2C_CMDCSR1 0x44
#define I2C_CMDCSR1_CTLBYTE0_BIT        (0U)
#define I2C_CMDCSR1_CTLBYTE0_MASK       (0xFFU)
#define I2C_CMDCSR1_CTLBYTE1_BIT        (8U)
#define I2C_CMDCSR1_CTLBYTE1_MASK       (0xFFU)
#define I2C_CMDCSR1_CTLBYTE2_BIT        (16U)
#define I2C_CMDCSR1_CTLBYTE2_MASK       (0xFFU)
#define I2C_CMDCSR1_CTLBYTE3_BIT        (24U)
#define I2C_CMDCSR1_CTLBYTE3_MASK       (0xFFU)

#define I2C_CMDCSR2 0x48
#define I2C_CMDCSR2_TAR_BIT             (0U)
#define I2C_CMDCSR2_TAR_MASK            (0x3FFU)
#define I2C_CMDCSR2_TARTYP_BIT          (10U)
#define I2C_CMDCSR2_TARTYP_MASK         (0x1U)
#define I2C_CMDCSR2_RWB_BIT             (11U)
#define I2C_CMDCSR2_RWB_MASK            (0x1U)
#define I2C_CMDCSR2_CTLBYTENUM_BIT      (12U)
#define I2C_CMDCSR2_CTLBYTENUM_MASK     (0x3U)
#define I2C_CMDCSR2_BCBEN_BIT           (14U)
#define I2C_CMDCSR2_BCBEN_MASK          (0x1U)
#define I2C_CMDCSR2_PECEN_BIT           (15U)
#define I2C_CMDCSR2_PECEN_MASK          (0x1U)
#define I2C_CMDCSR2_DATBYTENUM_BIT      (16U)
#define I2C_CMDCSR2_DATBYTENUM_MASK     (0xFFFFU)

#define I2C_CMDCSR3 0x4C

#define I2C_FCR     0x50
#define I2C_FCR_TXWMLVL_BIT     (0U)
#define I2C_FCR_TXWMLVL_MASK    (0xFFU)
#define I2C_FCR_TXWMLVL_LEN     (8U)
#define I2C_FCR_RXWMLVL_BIT     (8U)
#define I2C_FCR_RXWMLVL_MASK    (0xFFU)
#define I2C_FCR_RXWMLVL_LEN     (8U)
#define I2C_FCR_CLRF_BIT        (16U)
#define I2C_FCR_CLRF_MASK       (0x1U)
#define I2C_FCR_CLRF_LEN        (1U)

#define I2C_FSR     0x60
#define I2C_FSR_FILLLVL_BIT     (0U)
#define I2C_FSR_FILLLVL_MASK    (0xFFU)
#define I2C_FSR_EMPTYLVL_BIT    (8U)
#define I2C_FSR_EMPTYLVL_MASK   (0xFFU)

#define I2C_DMACR   0x70
#define I2C_DMASR   0x74

#define I2C_PCR0    0x80
#define I2C_PCR0_SPEED_BIT      (0U)
#define I2C_PCR0_SPEED_MASK     (0x7U)
#define I2C_PCR0_SPEED_LEN      (3U)
#define I2C_PCR0_PRESCALE_BIT   (3U)
#define I2C_PCR0_PRESCALE_MASK  (0x1FU)
#define I2C_PCR0_PRESCALE_LEN   (6U)
#define I2C_PCR0_TXNACK_BIT     (8U)
#define I2C_PCR0_TXNACK_MASK    (0x1U)
#define I2C_PCR0_BUSCLR_BIT     (9U)
#define I2C_PCR0_BUSCLR_MASK    (0x1U)
#define I2C_PCR0_STARTBYTEE_BIT (10U)
#define I2C_PCR0_STARTBYTEE_MASK (0x1U)
#define I2C_PCR0_AV_BIT         (11U)
#define I2C_PCR0_AV_MASK        (0x1U)
#define I2C_PCR0_AR_BIT         (12U)
#define I2C_PCR0_AR_MASK        (0x1U)
#define I2C_PCR0_IOCHKCTL_BIT   (13U)
#define I2C_PCR0_IOCHKCTL_MASK  (0x3U)
#define I2C_PCR0_CSRXE_BIT      (15U)
#define I2C_PCR0_CSRXE_MASK     (0x1U)
#define I2C_PCR0_CSTXE_BIT      (16U)
#define I2C_PCR0_CSTXE_MASK     (0x1U)
#define I2C_PCR0_CSRXWFE_BIT    (17U)
#define I2C_PCR0_CSRXWFE_MASK   (0x1U)
#define I2C_PCR0_CHKTATIM_BIT   (18U)
#define I2C_PCR0_CHKTATIM_MASK  (0x1U)

#define I2C_PCR1    0x84
#define I2C_PCR1_DAR_BIT        (0U)
#define I2C_PCR1_DAR_MASK       (0x3FFU)
#define I2C_PCR1_DAR_LEN        (10U)
#define I2C_PCR1_DARMSK_BIT     (10U)
#define I2C_PCR1_DARMSK_MASK    (0x3FFU)
#define I2C_PCR1_DARTYP_BIT     (20U)
#define I2C_PCR1_DARTYP_MASK    (0x1U)

#define I2C_PCR2    0x88
#define I2C_PCR3    0x8C
#define I2C_PCR2_3_TIMSCLL_BIT      (0U)
#define I2C_PCR2_3_TIMSCLL_MASK     (0xFFFU)
#define I2C_PCR2_3_TIMTASCLH_BIT    (12U)
#define I2C_PCR2_3_TIMTASCLH_MASK   (0xFU)
#define I2C_PCR2_3_TIMTASCLL_BIT    (16U)
#define I2C_PCR2_3_TIMTASCLL_MASK   (0xFU)
#define I2C_PCR2_3_TIMTASDAL_BIT    (20U)
#define I2C_PCR2_3_TIMTASDAL_MASK   (0xFU)
#define I2C_PCR2_3_TIMDVDAT_BIT     (24U)
#define I2C_PCR2_3_TIMDVDAT_MASK    (0xFFU)

#define I2C_PCR4    0x90
#define I2C_PCR4_TIMUNIT_BIT        (0U)
#define I2C_PCR4_TIMUNIT_MASK       (0x7U)
#define I2C_PCR4_TIMMEXT_BIT        (3U)
#define I2C_PCR4_TIMMEXT_MASK       (0x3FU)
#define I2C_PCR4_TIMSEXT_BIT        (9U)
#define I2C_PCR4_TIMSEXT_MASK       (0x3FU)
#define I2C_PCR4_TIMSTUCK_BIT       (16U)
#define I2C_PCR4_TIMSTUCK_MASK      (0xFFFFU)

#define I2C_PCR5    0x94
#define I2C_PCR5_TIMSDARXHLD_BIT    (0U)
#define I2C_PCR5_TIMSDARXHLD_MASK   (0x3FU)
#define I2C_PCR5_TIMDATSMPL_BIT     (6U)
#define I2C_PCR5_TIMDATSMPL_MASK    (0x3FU)
#define I2C_PCR5_TIMBUF_BIT         (18U)
#define I2C_PCR5_TIMBUF_MASK        (0x7U)
#define I2C_PCR5_TIMIDLE_BIT        (21U)
#define I2C_PCR5_TIMIDLE_MASK       (0x7U)

#define I2C_PCR6    0x98
#define I2C_PCR7    0x9C
#define I2C_PCR8    0xA0
#define I2C_PCR9    0xA4
#define I2C_PCR10   0xA8
#define I2C_PCR11   0xAC
#define I2C_PCR12   0xB0
#define I2C_PCR13   0xB4
#define I2C_PCR14   0xB8
#define I2C_PCR15   0xBC
#define I2C_PSR0    0x100

#define I2C_TXFIFO  0x200
#define I2C_RXFIFO  0x300

#define I2C_RED_PARITY_ERR_INT_STAT    0xE0
#define I2C_RED_PARITY_ERR_INT_STAT_EN 0xE4
#define I2C_RED_PARITY_ERR_INT_SIG_EN  0xE8

/* int0 bitmask */
#define SDRV_I2C_INT0_TXFWE             (1 << 0)
#define SDRV_I2C_INT0_RXFWF             (1 << 1)
#define SDRV_I2C_INT0_TXFUDF            (1 << 2)
#define SDRV_I2C_INT0_RXFUDF            (1 << 3)
#define SDRV_I2C_INT0_TXFOVF            (1 << 4)
#define SDRV_I2C_INT0_RXFOVF            (1 << 5)
#define SDRV_I2C_INT0_TXFABT            (1 << 6)
#define SDRV_I2C_INT0_RXFABT            (1 << 7)
#define SDRV_I2C_INT0_SCLSTUCKLOW       (1 << 8)
#define SDRV_I2C_INT0_SDASTUCKLOW       (1 << 9)
#define SDRV_I2C_INT0_BUSCLRPASS        (1 << 10)
#define SDRV_I2C_INT0_BUSCLRERR         (1 << 11)
#define SDRV_I2C_INT0_APBCMDDONE        (1 << 12)
#define SDRV_I2C_INT0_APBCMDABORT       (1 << 13)
#define SDRV_I2C_INT0_SLVWRTRANSDONE    (1 << 14)
#define SDRV_I2C_INT0_SLVRDTRANSDONE    (1 << 15)
#define SDRV_I2C_INT0_SLVWRTRANSABORT   (1 << 16)
#define SDRV_I2C_INT0_SLVRDTRANSABORT   (1 << 17)
#define SDRV_I2C_INT0_SCLHLDTX          (1 << 18)
#define SDRV_I2C_INT0_SCLHLDRX          (1 << 19)
#define SDRV_I2C_INT0_BUSCLRDET         (1 << 20)

#define SDRV_I2C_INT0_DEFAULT_MASK \
    (SDRV_I2C_INT0_TXFWE  |\
     SDRV_I2C_INT0_RXFWF  |\
     SDRV_I2C_INT0_TXFUDF |\
     SDRV_I2C_INT0_RXFUDF |\
     SDRV_I2C_INT0_TXFOVF |\
     SDRV_I2C_INT0_RXFOVF |\
     SDRV_I2C_INT0_TXFABT |\
     SDRV_I2C_INT0_RXFABT |\
     SDRV_I2C_INT0_SCLSTUCKLOW |\
     SDRV_I2C_INT0_SDASTUCKLOW |\
     SDRV_I2C_INT0_APBCMDDONE  |\
     SDRV_I2C_INT0_APBCMDABORT)

#define SDRV_I2C_INT0_SLV_DEFAULT_MASK \
    (SDRV_I2C_INT0_TXFUDF |\
     SDRV_I2C_INT0_RXFUDF |\
     SDRV_I2C_INT0_TXFOVF |\
     SDRV_I2C_INT0_RXFOVF |\
     SDRV_I2C_INT0_TXFABT |\
     SDRV_I2C_INT0_RXFABT |\
     SDRV_I2C_INT0_SCLSTUCKLOW |\
     SDRV_I2C_INT0_SDASTUCKLOW |\
     SDRV_I2C_INT0_APBCMDABORT |\
     SDRV_I2C_INT0_SLVWRTRANSDONE |\
     SDRV_I2C_INT0_SLVRDTRANSDONE |\
     SDRV_I2C_INT0_SLVWRTRANSABORT|\
     SDRV_I2C_INT0_SLVRDTRANSABORT)

#define SDRV_I2C_INT0_ERR_STAT \
    (SDRV_I2C_INT0_TXFUDF |\
     SDRV_I2C_INT0_RXFUDF |\
     SDRV_I2C_INT0_TXFOVF |\
     SDRV_I2C_INT0_RXFOVF |\
     SDRV_I2C_INT0_TXFABT |\
     SDRV_I2C_INT0_RXFABT |\
     SDRV_I2C_INT0_SCLSTUCKLOW |\
     SDRV_I2C_INT0_SDASTUCKLOW |\
     SDRV_I2C_INT0_APBCMDABORT |\
     SDRV_I2C_INT0_SLVWRTRANSABORT |\
     SDRV_I2C_INT0_SLVRDTRANSABORT)

/* int2 bitmask */
#define SDRV_I2C_INT2_STARTDET         (1 << 0)
#define SDRV_I2C_INT2_RESTARTDET       (1 << 1)
#define SDRV_I2C_INT2_STOPDET          (1 << 2)
#define SDRV_I2C_INT2_SLVRDREQDET      (1 << 18)
#define SDRV_I2C_INT2_SLVWRREQDET      (1 << 19)
#define SDRV_I2C_INT2_CTLBYTEDET       (1 << 28)

#define SDRV_I2C_INT2_SLV_MASK \
    (SDRV_I2C_INT2_SLVRDREQDET  |\
     SDRV_I2C_INT2_SLVWRREQDET  |\
     SDRV_I2C_INT2_CTLBYTEDET)

#define SDRV_I2C_CMD0_SLV_MASK (0x0)
#define SDRV_I2C_CMD1_SLV_MASK (0x0)
#define SDRV_I2C_CMD2_SLV_MASK (0x1000)
#define SDRV_I2C_CMD3_SLV_MASK (0x0)

uint8 sdrv_i2c_lld_recv_data(uint32 base);
void sdrv_i2c_lld_send_data(uint32 base, uint8 data);
uint32 sdrv_i2c_lld_get_psr0_stat(uint32 base);
uint32 sdrv_i2c_lld_get_wspace(uint32 base);
uint32 sdrv_i2c_lld_get_rspace(uint32 base);
void sdrv_i2c_lld_set_watermark(uint32 base,
                                uint8 tx_lvl, uint8 rx_lvl);
int sdrv_i2c_lld_clear_fifo(uint32 base);
void sdrv_i2c_lld_set_cmdcsr0(uint32 base, uint32 cmdcsr0);
void sdrv_i2c_lld_set_cmdcsr1(uint32 base, uint32 cmdcsr1);
void sdrv_i2c_lld_set_cmdcsr2(uint32 base, uint32 cmdcsr2);
void sdrv_i2c_lld_set_cmdcsr3(uint32 base, uint32 cmdcsr3);
uint32 sdrv_i2c_lld_get_cmdcsr0(uint32 base);
uint32 sdrv_i2c_lld_get_cmdcsr1(uint32 base);
uint32 sdrv_i2c_lld_get_cmdcsr2(uint32 base);
uint32 sdrv_i2c_lld_get_cmdcsr3(uint32 base);
void sdrv_i2c_lld_clear_int(uint32 base);
uint32 sdrv_i2c_lld_get_int0_stat(uint32 base);
uint32 sdrv_i2c_lld_get_int1_stat(uint32 base);
uint32 sdrv_i2c_lld_get_int2_stat(uint32 base);
uint32 sdrv_i2c_lld_get_int3_stat(uint32 base);
void sdrv_i2c_lld_unmask_int0(uint32 base, uint32 int_flag);
void sdrv_i2c_lld_unmask_int1(uint32 base, uint32 int_flag);
void sdrv_i2c_lld_unmask_int2(uint32 base, uint32 int_flag);
void sdrv_i2c_lld_unmask_int3(uint32 base, uint32 int_flag);
void sdrv_i2c_lld_set_speed(uint32 base, uint32 speed_mode);
void sdrv_i2c_lld_set_slvaddr(uint32 base, uint16 addr);
void sdrv_i2c_lld_set_timing(uint32 base,
                             uint32 pcr2, uint32 pcr3, uint32 pcr4, uint32 pcr5);
void sdrv_i2c_lld_set_IO0(uint32 base,  uint32 val);
void sdrv_i2c_lld_set_IO1(uint32 base,  uint32 val);
void sdrv_i2c_lld_set_IO2(uint32 base,  uint32 val);
void sdrv_i2c_lld_set_IO3(uint32 base,  uint32 val);
void sdrv_i2c_lld_set_opmode(uint32 base, uint32 opmode);
void sdrv_i2c_lld_disable(uint32 base);
void sdrv_i2c_lld_enable(uint32 base);
int sdrv_i2c_lld_reset(uint32 base);
void sdrv_i2c_lld_dump_reg(uint32 base, uint32 *reg_val);
void sdrv_i2c_lld_write_reg(uint32 base, uint32 reg, uint32 val);
void sdrv_i2c_lld_read_reg(uint32 base, uint32 reg, uint32 *val);

#endif
