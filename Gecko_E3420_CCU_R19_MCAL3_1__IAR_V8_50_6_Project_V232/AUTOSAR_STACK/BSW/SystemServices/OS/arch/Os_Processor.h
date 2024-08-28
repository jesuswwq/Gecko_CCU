/*============================================================================*/
/*  Copyright (C) 2016, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Processor.h>
 *  @brief      <>
 *  
 * <Compiler: IAR    MCU:CYT2BX>
 *  
 *  @author     <bo.zeng>
 *  @date       <05-12-2014>
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2014-12-05  bo.zeng       Initial version.
 *  V0.2.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li       Functional safety version.
 */
/*============================================================================*/
#ifndef OS_PROCESSOR_H
#define OS_PROCESSOR_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/


/*=======[I N C L U D E S]====================================================*/
#include "Os.h"
#include "Os_SysAsmFun.h"
#include "e3430_vic.h"
#include "irq.h"
#include  "sdrv_btm.h"
#include "__regs_base.h"
#include "Os_Timer.h"
#include "sdrv_vic.h"
#include "reg.h"
#include "Gpt_Ip.h"
#include "Gpt_Register.h"
#include "mbox.h"
#include "Mcu_Extend.h"
   
/*------------------Compiler OS-------------------------*/
#define  ASM                  asm                         /* Embedded assembly. */
#define  OS_REG32(address)    (*(volatile uint32*)(address)) /* DD_1_0325, Define 32-bit register. */
#define  OS_REG16(address)        (*(volatile uint16*)(address))     /* 16-bit register */
#define  OS_REG8(address)         (*(volatile uint8 *)(address))     /*  8-bit register */

/*------------------End Compiler OS-------------------------*/
#define  OS_ARCH_INT_CPU0                        (0UL)
#define  OS_ARCH_INT_CPU1                        (1UL)
#define  OS_ARCH_INT_CPU2                        (2UL)
#define MB_MU_MESSAGE_READY                                 0
#define MB_MU_WAKEUP                                        1
#define MB_SEMAPHORE_LOCK_FAIL                              2
#define MB_SEMAPHORE_LOCK_STATUS_CHANGE                     3
#define GPIO_SF_SYNC_DGPIO                                  4
#define GPIO_SF_ASYNC_DGPIO                                 4
#define GPIO_SF_SYNC_GRP_0                                  5
#define GPIO_SF_ASYNC_GRP_0                                 5
#define GPIO_SF_SYNC_GRP_1                                  6
#define GPIO_SF_ASYNC_GRP_1                                 6
#define GPIO_SF_SYNC_GRP_2                                  7
#define GPIO_SF_ASYNC_GRP_2                                 7
#define GPIO_SF_SYNC_GRP_3                                  8
#define GPIO_SF_ASYNC_GRP_3                                 8
#define GPIO_SF_SYNC_GRP_4                                  9
#define GPIO_SF_ASYNC_GRP_4                                 9
#define CR5_SF_NPMUIRQ0                                     10
#define GPIO_AP_SYNC_DGPIO                                  11
#define GPIO_AP_ASYNC_DGPIO                                 11
#define GPIO_AP_SYNC_GRP_0                                  12
#define GPIO_AP_ASYNC_GRP_0                                 12
#define GPIO_AP_SYNC_GRP_1                                  13
#define GPIO_AP_ASYNC_GRP_1                                 13
#define GPIO_AP_SYNC_GRP_2                                  14
#define GPIO_AP_ASYNC_GRP_2                                 14
#define SMC_SMC_WAKEUP_0                                    15
#define WDT1_WDT                                            16
#define WDT2_WDT                                            17
#define WDT3_WDT                                            18
#define WDT4_WDT                                            19
#define WDT5_WDT                                            20
#define WDT6_WDT                                            21
#define WDT8_WDT                                            22
#define DMA_SF_DMA0_CH_0                                    23
#define DMA_SF_DMA0_CH_1                                    24
#define DMA_SF_DMA0_CH_2                                    25
#define DMA_SF_DMA0_CH_3                                    26
#define DMA_SF_DMA0_CH_4                                    27
#define DMA_SF_DMA0_CH_5                                    28
#define DMA_SF_DMA0_CH_6                                    29
#define DMA_SF_DMA0_CH_7                                    30
#define DMA_SF_DMA0_CH_8                                    31
#define DMA_SF_DMA0_CH_9                                    32
#define DMA_SF_DMA0_CH_10                                   33
#define DMA_SF_DMA0_CH_11                                   34
#define DMA_SF_DMA0_CH_12                                   35
#define DMA_SF_DMA0_CH_13                                   36
#define DMA_SF_DMA0_CH_14                                   37
#define DMA_SF_DMA0_CH_15                                   38
#define DMA_SF_DMA0_CH_16                                   39
#define DMA_SF_DMA0_CH_17                                   40
#define DMA_SF_DMA0_CH_18                                   41
#define DMA_SF_DMA0_CH_19                                   42
#define DMA_SF_DMA0_CH_20                                   43
#define DMA_SF_DMA0_CH_21                                   44
#define DMA_SF_DMA0_CH_22                                   45
#define DMA_SF_DMA0_CH_23                                   46
#define DMA_SF_DMA0                                         47
#define DMA_SF_DMA1_CH_0                                    48
#define DMA_SF_DMA1_CH_1                                    49
#define DMA_SF_DMA1_CH_2                                    50
#define DMA_SF_DMA1_CH_3                                    51
#define DMA_SF_DMA1_CH_4                                    52
#define DMA_SF_DMA1_CH_5                                    53
#define DMA_SF_DMA1_CH_6                                    54
#define DMA_SF_DMA1_CH_7                                    55
#define DMA_SF_DMA1_CH_8                                    56
#define DMA_SF_DMA1_CH_9                                    57
#define DMA_SF_DMA1_CH_10                                   58
#define DMA_SF_DMA1_CH_11                                   59
#define DMA_SF_DMA1_CH_12                                   60
#define DMA_SF_DMA1_CH_13                                   61
#define DMA_SF_DMA1_CH_14                                   62
#define DMA_SF_DMA1_CH_15                                   63
#define DMA_SF_DMA1_CH_16                                   64
#define DMA_SF_DMA1_CH_17                                   65
#define DMA_SF_DMA1_CH_18                                   66
#define DMA_SF_DMA1_CH_19                                   67
#define DMA_SF_DMA1_CH_20                                   68
#define DMA_SF_DMA1_CH_21                                   69
#define DMA_SF_DMA1_CH_22                                   70
#define DMA_SF_DMA1_CH_23                                   71
#define DMA_SF_DMA1                                         72
#define DMA_AP_DMA_CH_0                                     73
#define DMA_AP_DMA_CH_1                                     74
#define DMA_AP_DMA_CH_2                                     75
#define DMA_AP_DMA_CH_3                                     76
#define DMA_AP_DMA_CH_4                                     77
#define DMA_AP_DMA_CH_5                                     78
#define DMA_AP_DMA_CH_6                                     79
#define DMA_AP_DMA_CH_7                                     80
#define DMA_AP_DMA                                          81
#define DMA_AP_DMA_AP_UNCERR                                82
#define SEM1_O_SEM_CPU                                      84
#define SEM2_O_SEM_CPU                                      85
#define UART1                                               86
#define UART2                                               87
#define UART3                                               88
#define UART4                                               89
#define UART5                                               90
#define UART6                                               91
#define UART7                                               92
#define UART8                                               93
#define UART9                                               94
#define UART10                                              95
#define UART11                                              96
#define UART12                                              97
#define UART13                                              98
#define UART14                                              99
#define UART15                                              100
#define UART16                                              101
#define I2C1                                                102
#define I2C2                                                103
#define I2C3                                                104
#define I2C4                                                105
#define I2C5                                                106
#define I2C6                                                107
#define I2C7                                                108
#define I2C8                                                109
#define SPI1_SPI                                            110
#define SPI2_SPI                                            111
#define SPI3_SPI                                            112
#define SPI4_SPI                                            113
#define SPI5_SPI                                            114
#define SPI6_SPI                                            115
#define SPI7_SPI                                            116
#define SPI8_SPI                                            117
#define XSPI1_IRQ0                                          118
#define XSPI1_IRQ1                                          119
#define XSPI2_IRQ0                                          120
#define XSPI2_IRQ1                                          121
#define XSPI_SLV                                            122
#define SACI1_I2S                                           123
#define SACI1_PDM                                           124
#define SACI2_I2S                                           125
#define SACI2_PDM                                           126
#define USB                                                 127
#define ETH1_SBD                                           128
#define ETH1_SBD_PERCH_TX_O0                               129
#define ETH1_SBD_PERCH_TX_O1                               129
#define ETH1_SBD_PERCH_TX_O2                               129
#define ETH1_SBD_PERCH_TX_O3                               129
#define ETH1_SBD_PERCH_TX_O4                               129
#define ETH1_SBD_PERCH_RX_O0                               129
#define ETH1_SBD_PERCH_RX_O1                               129
#define ETH1_SBD_PERCH_RX_O2                               129
#define ETH1_SBD_PERCH_RX_O3                               129
#define ETH1_SBD_PERCH_RX_O4                               129
#define ETH1_LPI                                           130
#define ETH1_PMT                                           130
#define ETH2_SBD                                           131
#define ETH2_SBD_PERCH_TX_O0                               132
#define ETH2_SBD_PERCH_TX_O1                               132
#define ETH2_SBD_PERCH_TX_O2                               132
#define ETH2_SBD_PERCH_TX_O3                               132
#define ETH2_SBD_PERCH_TX_O4                               132
#define ETH2_SBD_PERCH_RX_O0                               132
#define ETH2_SBD_PERCH_RX_O1                               132
#define ETH2_SBD_PERCH_RX_O2                               132
#define ETH2_SBD_PERCH_RX_O3                               132
#define ETH2_SBD_PERCH_RX_O4                               132
#define ETH2_LPI                                           133
#define ETH2_PMT                                           133
#define GAMA1_O_GAMA                                        134
#define SEHC1_SEHC                                          136
#define SEHC1_SEHC_WAKEUP                                   137
#define SEHC2_SEHC                                          138
#define SEHC2_SEHC_WAKEUP                                   139
#define DC_DC_IRQ0                                          140
#define DC_DC_IRQ1                                          141
#define CSI                                                 142
#define G2D_G2D                                             143
#define CANFD1_CANFD                                        144
#define CANFD2_CANFD                                        145
#define CANFD3_CANFD                                        146
#define CANFD4_CANFD                                        147
#define CANFD5_CANFD                                        148
#define CANFD6_CANFD                                        149
#define CANFD7_CANFD                                        150
#define CANFD8_CANFD                                        151
#define CANFD9_CANFD                                        152
#define CANFD10_CANFD                                       153
#define CANFD11_CANFD                                       154
#define CANFD12_CANFD                                       155
#define CANFD13_CANFD                                       156
#define CANFD14_CANFD                                       157
#define CANFD15_CANFD                                       158
#define CANFD16_CANFD                                       159
#define CANFD17_CANFD                                       160
#define CANFD18_CANFD                                       161
#define CANFD19_CANFD                                       162
#define CANFD20_CANFD                                       163
#define CANFD21_CANFD                                       164
#define CANFD22_CANFD                                       165
#define CANFD23_CANFD                                       166
#define CANFD24_CANFD                                       167
#define FLEXRAY1_IPI_GLOB                                   168
#define FLEXRAY1_IPI_RXB                                    169
#define FLEXRAY1_IPI_TXB                                    170
#define FLEXRAY1_IPI_CHI                                    171
#define FLEXRAY1_IPI_PE                                     171
#define FLEXRAY1_IPI_WU                                     172
#define FLEXRAY1_IPI_FIFO_A_NE                              173
#define FLEXRAY1_IPI_FIFO_B_NE                              174
#define FLEXRAY2_IPI_GLOB                                   175
#define FLEXRAY2_IPI_RXB                                    176
#define FLEXRAY2_IPI_TXB                                    177
#define FLEXRAY2_IPI_CHI                                    178
#define FLEXRAY2_IPI_PE                                     178
#define FLEXRAY2_IPI_WU                                     179
#define FLEXRAY2_IPI_FIFO_A_NE                              180
#define FLEXRAY2_IPI_FIFO_B_NE                              181
#define SEIP_PKE                                            182
#define SEIP_SKE                                            183
#define SEIP_HASH                                           184
#define SEIP_TRNG                                           185
#define SEIP_KEY_CHK                                        186
#define SEIP_SOC                                            187
#define SEIP_UART                                           188
#define SEIP_SENSOR                                         189
#define SEIP_O_INTR_SE2SOC_MBOX                             190
#define SEIP_SEIP_ERR                                       191
#define SDRAMC_SDRAMC                                       192
#define BTM1_O_BTM                                          193
#define BTM2_O_BTM                                          194
#define BTM3_O_BTM                                          195
#define BTM4_O_BTM                                          196
#define BTM5_O_BTM                                          197
#define BTM6_O_BTM                                          198
#define ETMR1_CHN_A                                         199
#define ETMR1_CHN_B                                         199
#define ETMR1_CHN_C                                         199
#define ETMR1_CHN_D                                         199
#define ETMR1_CNT_OVF                                       200
#define ETMR2_CHN_A                                         201
#define ETMR2_CHN_B                                         201
#define ETMR2_CHN_C                                         201
#define ETMR2_CHN_D                                         201
#define ETMR2_CNT_OVF                                       202
#define ETMR3_CHN_A                                         203
#define ETMR3_CHN_B                                         203
#define ETMR3_CHN_C                                         203
#define ETMR3_CHN_D                                         203
#define ETMR3_CNT_OVF                                       204
#define ETMR4_CHN_A                                         205
#define ETMR4_CHN_B                                         205
#define ETMR4_CHN_C                                         205
#define ETMR4_CHN_D                                         205
#define ETMR4_CNT_OVF                                       206
#define EPWM1_CHN_A                                         207
#define EPWM1_CHN_B                                         207
#define EPWM1_CHN_C                                         207
#define EPWM1_CHN_D                                         207
#define EPWM1_CNT_OVF                                       208
#define EPWM2_CHN_A                                         209
#define EPWM2_CHN_B                                         209
#define EPWM2_CHN_C                                         209
#define EPWM2_CHN_D                                         209
#define EPWM2_CNT_OVF                                       210
#define EPWM3_CHN_A                                         211
#define EPWM3_CHN_B                                         211
#define EPWM3_CHN_C                                         211
#define EPWM3_CHN_D                                         211
#define EPWM3_CNT_OVF                                       212
#define EPWM4_CHN_A                                         213
#define EPWM4_CHN_B                                         213
#define EPWM4_CHN_C                                         213
#define EPWM4_CHN_D                                         213
#define EPWM4_CNT_OVF                                       214
#define XTRG_FUNC                                           215
#define IOC_GPIO_SYNC                                       216
#define IOC_GPIO_ASYNC                                      216
#define RTC1_RTC_WAKEUP                                     217
#define RTC1_RTC_PERIODICAL                                 218
#define RTC1_VIOLATION                                      219
#define RTC2_RTC_WAKEUP                                     220
#define RTC2_RTC_PERIODICAL                                 221
#define RTC2_VIOLATION                                      222
#define TM_VIOLATION                                        223
#define VD_AP_O_VDC_FUNC                                    224
#define VD_SF_DIG_O_VDC_FUNC                                225
#define PT_SNS_AP_PVT_0                                     226
#define PT_SNS_AP_PVT_1                                     227
#define PT_SNS_SF_DIG_PVT_0                                 228
#define PT_SNS_SF_DIG_PVT_1                                 229
#define SCR_SF_SCR_APB_PSLVERR                              230
#define SCR_AP_SCR                                          231
#define PMU_CORE_PMU                                        232
#define RSTGEN_SF_RSTGEN                                    233
#define U_CKGEN_SF_CKGEN                                    234
#define RSTGEN_AP_RSTGEN                                    235
#define U_CKGEN_AP_CKGEN                                    236
#define SMC_SMC                                             237
#define SADC1_O_SADC                                        238
#define SADC2_O_SADC                                        239
#define SADC3_O_SADC                                        240
#define ACMP1_O_ACMP                                        241
#define ACMP2_O_ACMP                                        242
#define ACMP3_O_ACMP                                        243
#define ACMP4_O_ACMP                                        244
#define DCDC1_O_DCDC_FUNC                                   245
#define LDO_DIG_O_LDO_FUNC                                  246
#define FS_32K_FS_32K                                       247
#define ISTC                                                249
#define MPC_XSPI1A_FUNC                                     250
#define MPC_XSPI1B_FUNC                                     250
#define MPC_XSPI2A_FUNC                                     250
#define MPC_XSPI2B_FUNC                                     250
#define MPC_R5SX_S0_FUNC                                    250
#define MPC_R5SX_S1_FUNC                                    250
#define MPC_VIC3A_FUNC                                      250
#define MPC_VIC3B_FUNC                                      250
#define MPC_R5SF_S_FUNC                                     250
#define MPC_MB_FUNC                                         250
#define MPC_ROMC_FUNC                                       250
#define MPC_IRAMC1_FUNC                                     250
#define MPC_IRAMC2_FUNC                                     250
#define MPC_IRAMC3_FUNC                                     250
#define MPC_IRAMC4_FUNC                                     250
#define MPC_VIC1_FUNC                                       250
#define MAC_FUNC                                            250
#define PPC_APBMUX2_FUNC                                    250
#define PPC_APBMUX3_FUNC                                    250
#define PPC_APBMUX4_FUNC                                    250
#define MPC_CR5_SP0_FUNC                                    250
#define MPC_CR5_SP1_FUNC                                    250
#define MPC_GAMA1_FUNC                                      250
#define MPC_VIC2A_FUNC                                      250
#define MPC_VIC2B_FUNC                                      250
#define PPC_APBMUX5_FUNC                                    250
#define MPC_SDRAMC_FUNC                                     250
#define MPC_SEIP_FUNC                                       250
#define PPC_APBMUX1_FUNC                                    250
#define PPC_APBMUX6_FUNC                                    250
#define PPC_APBMUX7_FUNC                                    250
#define GPIO_SF_SGPIO                                       251
#define IRQ_MAX                                             251 

/* MPU Register. */
/* Indicates the MPU region size. */
#define MPU_SIZE_32B                        ( 0x04UL << 1UL )
#define MPU_SIZE_64B                        ( 0x05UL << 1UL )
#define MPU_SIZE_128B                       ( 0x06UL << 1UL )
#define MPU_SIZE_256B                       ( 0x07UL << 1UL )
#define MPU_SIZE_512B                       ( 0x08UL << 1UL )
#define MPU_SIZE_1KB                        ( 0x09UL << 1UL )
#define MPU_SIZE_2KB                        ( 0x0AUL << 1UL )
#define MPU_SIZE_4KB                        ( 0x0BUL << 1UL )
#define MPU_SIZE_8KB                        ( 0x0CUL << 1UL )
#define MPU_SIZE_16KB                       ( 0x0DUL << 1UL )
#define MPU_SIZE_32KB                       ( 0x0EUL << 1UL )
#define MPU_SIZE_64KB                       ( 0x0FUL << 1UL )
#define MPU_SIZE_128KB                      ( 0x10UL << 1UL )
#define MPU_SIZE_256KB                      ( 0x11UL << 1UL )
#define MPU_SIZE_512KB                      ( 0x12UL << 1UL )
#define MPU_SIZE_1MB                        ( 0x13UL << 1UL )
#define MPU_SIZE_2MB                        ( 0x14UL << 1UL )
#define MPU_SIZE_4MB                        ( 0x15UL << 1UL )
#define MPU_SIZE_8MB                        ( 0x16UL << 1UL )
#define MPU_SIZE_16MB                       ( 0x17UL << 1UL )
#define MPU_SIZE_32MB                       ( 0x18UL << 1UL )
#define MPU_SIZE_64MB                       ( 0x19UL << 1UL )
#define MPU_SIZE_128MB                      ( 0x1AUL << 1UL )
#define MPU_SIZE_256MB                      ( 0x1BUL << 1UL )
#define MPU_SIZE_512MB                      ( 0x1CUL << 1UL )
#define MPU_SIZE_1GB                        ( 0x1DUL << 1UL )
#define MPU_SIZE_2GB                        ( 0x1EUL << 1UL )
#define MPU_SIZE_4GB                        ( 0x1FUL << 1UL )

/* The permission of the region. */
#define MPU_PRIV_NA_USER_NA_EXEC    ( 0x0000UL ) /**< no access in privileged mode, no access in user mode and execute */
#define MPU_PRIV_RW_USER_NA_EXEC    ( 0x0100UL ) /**< read/write in privileged mode, no access in user mode and execute */
#define MPU_PRIV_RW_USER_RO_EXEC    ( 0x0200UL ) /**< read/write in privileged mode, read only in user mode and execute */
#define MPU_PRIV_RW_USER_RW_EXEC    ( 0x0300UL ) /**< read/write in privileged mode, read/write in user mode and execute */
#define MPU_PRIV_RO_USER_NA_EXEC    ( 0x0500UL ) /**< read only in privileged mode, no access in user mode and execute */
#define MPU_PRIV_RO_USER_RO_EXEC    ( 0x0600UL ) /**< read only in privileged mode, read only in user mode and execute */
#define MPU_PRIV_NA_USER_NA_NOEXEC  ( 0x1000UL ) /**< no access in privileged mode, no access in user mode and no execution */
#define MPU_PRIV_RW_USER_NA_NOEXEC  ( 0x1100UL ) /**< read/write in privileged mode, no access in user mode and no execution */
#define MPU_PRIV_RW_USER_RO_NOEXEC  ( 0x1200UL ) /**< read/write in privileged mode, read only in user mode and no execution */
#define MPU_PRIV_RW_USER_RW_NOEXEC  ( 0x1300UL ) /**< read/write in privileged mode, read/write in user mode and no execution */
#define MPU_PRIV_RO_USER_NA_NOEXEC  ( 0x1500UL ) /**< read only in privileged mode, no access in user mode and no execution */
#define MPU_PRIV_RO_USER_RO_NOEXEC  ( 0x1600UL ) /**< read only in privileged mode, read only in user mode and no execution */

#define MPU_REGION_ENABLE           (0x01UL)
#define MPU_REGION_DISABLE          (0x00UL)

#define MPU_STRONGLYORDERED_SHAREABLE  ( 0x0000UL ) /**< Memory type strongly ordered and sharable */
#define MPU_DEVICE_SHAREABLE           ( 0x0001UL ) /**< Memory type device and sharable */
#define MPU_NORMAL_OIWTNOWA_NONSHARED  ( 0x0002UL ) /**< Memory type normal outer and inner write-through, no write allocate and non shared */
#define MPU_NORMAL_OIWBNOWA_NONSHARED  ( 0x0003UL ) /**< Memory type normal outer and inner write-back, no write allocate and non shared */
#define MPU_NORMAL_OIWTNOWA_SHARED     ( 0x0006UL ) /**< Memory type normal outer and inner write-through, no write allocate and shared */
#define MPU_NORMAL_OIWBNOWA_SHARED     ( 0x0007UL ) /**< Memory type normal outer and inner write-back, no write allocate and shared */
#define MPU_NORMAL_OINC_NONSHARED      ( 0x0008UL ) /**< Memory type normal outer and inner non-cachable and non shared */
#define MPU_NORMAL_OIWBWA_NONSHARED    ( 0x000BUL ) /**< Memory type normal outer and inner write-back, write allocate and non shared */
#define MPU_NORMAL_OINC_SHARED         ( 0x000CUL ) /**< Memory type normal outer and inner non-cachable and shared */
#define MPU_NORMAL_OIWBWA_SHARED       ( 0x000FUL ) /**< Memory type normal outer and inner write-back, write allocate and shared */
#define MPU_DEVICE_NONSHAREABLE        ( 0x0010UL ) /**< Memory type device and non sharable */
/* the region of mpu. */
#define MPU_REGION_0                   (0U)
#define MPU_REGION_1                   (1U)
#define MPU_REGION_2                   (2U)
#define MPU_REGION_3                   (3U)
#define MPU_REGION_4                   (4U)
#define MPU_REGION_5                   (5U)
#define MPU_REGION_6                   (6U)
#define MPU_REGION_7                   (7U)
#define MPU_REGION_8                   (8U)
#define MPU_REGION_9                   (9U)
#define MPU_REGION_10                  (10U)
#define MPU_REGION_11                  (11U)
#define MPU_REGION_12                  (12U)
#define MPU_REGION_13                  (13U)
#define MPU_REGION_14                  (14U)
#define MPU_REGION_15                  (15U)

/*Data*/
#define    dsram2_START                           (uint8*)(0x400000)
#define    dsram2_END                             (uint8*)(0x5fffff)
#define    dsram1_START                           (uint8*)(0x400000)
#define    dsram1_END                             (uint8*)(0x5fffff)
#define    dsram0_START                           (uint8*)(0x400000)
#define    dsram0_END                             (uint8*)(0x5fffff)
#define    LMU_SRAM_START                         (uint8*)(0x400000)
#define    LMU_SRAM_END                           (uint8*)(0x5fffff)
#define    DFLASH_START                           (uint8*)(0x10000000)
#define    DFLASH_END                             (uint8*)(0x107fffff)
#define    DMI_DSPR_START                         (uint8*)(0x400000)
#define    DMI_DSPR_END                           (uint8*)(0x5fffff)
#define    PERIPHERAL_START                       (uint8*)(0xF0000000)
#define    PERIPHERAL_END                         (uint8*)(0xFC7FDFFF)
#define    __rodata_start                         (uint8*)CDATA$$Base
#define    __rodata_end                           (uint8*)CDATA$$Limit
/*Code*/
#define    PFLASH_START                           (uint8*)(0x10000000)
#define    PFLASH_END                             (uint8*)(0x107fffff)

/* BTM channel */
#define CHANNEL_CNT_G0                                            0
#define CHANNEL_CNT_G1                                            1

/*-----------------------------os isr src------------------------------------*/

/* Address space of kernel view. */
/*=======[Porting Macro]======================================================*/
#define CHECK_STACK_USAGE             1u
#define OS_ARCH_STACK_ALIGN(addr)   (addr & 0xFFFFFFFFu)//(addr & 0xFFFFFFF8u)
#define Os_ArchDisableInt()         ASM("cpsid I")       /* DD_1_0335, Disables global interrupt. */
#define Os_ArchEnableInt()          ASM("dsb\n cpsie I\n")    /* DD_1_0336, Enables global interrupt. */
#define OS_ARCH_DECLARE_CRITICAL()  Os_ArchMsrType msr      /* DD_1_0338, Declares the variables that hold the interrupt control register. */
#define OS_ARCH_ENTRY_CRITICAL()    Os_ArchSuspendInt(&msr) /* DD_1_0339, Save the variables that hold the interrupt control register. */
#define OS_ARCH_EXIT_CRITICAL()     Os_ArchRestoreInt(msr)  /* DD_1_0340, Resume the variables that hold the interrupt control register. */
#define Os_ArchDisableAllInt()      Os_ArchSuspendInt(&cpsr_isr)
#define Os_ArchEnableAllInt()       Os_ArchRestoreInt(cpsr_isr)

/*-----------------------------Interrupt Macro-------------------------------*/
/* Disable/Enable interrupt X */
#define OS_INTERRUPT_ENABLE(id)     irq_enable(id)
#define OS_INTERRUPT_DISABLE(id)    irq_disable(id)
/* Set/Clear interrupt pending X */
#define OS_INTERRUPT_CLEAR_PENDING(id)
/* Install interrupt */
#define OS_INTERRUPT_INSTALL(id, prio, srcType)
#define OS_INTERRUPT_UNLOAD(id, prio, srcType)
/* Check interrupt enable status */
#define OS_INTERRUPT_CHECK_STATUS(id)
#if (TRUE == CFG_SRV_SHELLOS)
/* Macro definition of CPU mode set,*/
/* Choose user mode for the Tricore platform, User0/1*/
/* Indicates which user mode the CPU uses. */
/* DD_1_0174 */

/*to change to the user or supervisor mode*/
/* DD_1_0348 */
#define OS_CHANGCPUMODE(mode)              \
{                                          \
    CpuInformation = Os_GetCpuMode();      \
    if (OS_CPUMODE_SUPERVISOR == CpuInformation)\
    {                                      \
        if (OS_CPUMODE_USER1 == mode)      \
        {                                  \
            Os_SetCpuMode(OS_CPUMODE_USER1);\
        }                                  \
    }                                      \
    else                                   \
    {                                      \
        if (OS_CPUMODE_SUPERVISOR == mode) \
        {                                  \
            Os_ArchSyscall();              \
        }                                  \
    }                                      \
}

#define OS_RESUMECPUMODE()                   \
{                                            \
    if (OS_CPUMODE_USER1 == CpuInformation)  \
    {                                        \
    	Os_SetCpuMode(OS_CPUMODE_USER1);     \
    }                                        \
    else                                     \
    {                                        \
        /* nothing to do. */                 \
    }                                        \
}
#else /* FALSE == CFG_SRV_SHELLOS */
#define OS_CHANGCPUMODE()
#define OS_RESUMECPUMODE()
#endif /* TRUE == CFG_SRV_SHELLOS */
/**
 * trigger the specific interrupt source by setting the request bit, just for debug.
 * write 1 to the bit26 SETR(set request)
 */
#if (TRUE == CFG_SRV_SHELLOS)
#define OS_INTERRUPT_SETREQ(src)\
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
#else /* #if (FALSE == CFG_SRV_SHELLOS) */
#define OS_INTERRUPT_SETREQ(src)  (*(uint32 volatile *)src)\
    = ((*(uint32 volatile *)src) | 0x04000000u)
#endif /* TRUE == CFG_SRV_SHELLOS */

/* cpu0 = bit0 set to 1, ..., */
/* Request an interrupt service to the specified core. */
/* DD_1_0353 */
#define OS_INTERRUPT_SRB_SETREQ(core)               \
{                                                   \
    if(core == 0)                                   \
    {                                               \
        writel(1U << OS_SHIFT32(MB_SEMAPHORE_LOCK_FAIL), OS_VICSOFTINT0(MB_SEMAPHORE_LOCK_FAIL));  \
    }                                               \
    else if(core == 1)                              \
    {                                               \
        writel(1U << OS_SHIFT32(MB_SEMAPHORE_LOCK_FAIL), OS_VICSOFTINT1(MB_SEMAPHORE_LOCK_FAIL));  \
    }                                               \
    else if(core == 2)                              \
    {                                               \
        writel(1U << OS_SHIFT32(MB_SEMAPHORE_LOCK_FAIL), OS_VICSOFTINT2(MB_SEMAPHORE_LOCK_FAIL));  \
    }                                               \
}
/* Request an interrupt service to the specified core. */
/* DD_1_0354 */
#define Os_ArchRemoteCall(coreId)                   \
{                                                   \
    Os_InterCore[Os_ArchGetCoreID()].remoteCoreRequest[coreId] = TRUE;			\
    OS_INTERRUPT_SRB_SETREQ(coreId);                \
}
/* clear an interrupt service. */
#define Os_ArchRemoteClear()                        \
{                                                   \
    writel(1U << OS_SHIFT32(MB_SEMAPHORE_LOCK_FAIL), OS_VICSOFTINTCLEAR(MB_SEMAPHORE_LOCK_FAIL));  \
}
/* Pre-switch to system stack. */
/* DD_1_0357 */
#define Os_ArchPreSwitch2System()
/* Switch to system stack */
/* DD_1_0358 */
#define Os_ArchSwitch2System()                                        \
{                                                                      \
    Os_ArchSp = OS_ARCH_STACK_ALIGN(((uint32)Os_SystemStack->stackTop) - 20u); \
    asm(" LDR    R0, =Os_ArchSp");\
    asm(" LDR SP,[R0]");\
    asm(" dsb");\
}

/* Switch to ISR2 stack */
/* DD_1_0359 */
#if (CFG_ISR2_MAX > 0U)
#define Os_ArchSwitch2ISR2Stk(isrId)                                       \
{                                                                          \
    Os_ArchSp = OS_ARCH_STACK_ALIGN(((uint32)Os_ISR2Stack[isrId].stackTop)-20u); \
    asm(" LDR    R0, =Os_ArchSp");\
    asm(" LDR SP,[R0]");\
    asm(" dsb");\
}
#else /* #if (CFG_ISR2_MAX == 0U) */
#define Os_ArchSwitch2ISR2Stk(isrId) 
#endif /* CFG_ISR2_MAX > 0U */

#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
/* Some operations that need to be performed when exiting the ISR. */
/* DD_1_0371 */
#define OS_ARCH_ISR2_EPILOGUE()               OS_ARCH_ISR2_EPILOGUE_1()
/* Clear Call Depth Count Enable bit. */
/* DD_1_0372 */
#define Os_CLEAR_CDC_ISR2_EPILOGUE()
/* Update PSW for memory protection and user mode 1 */
#define Os_ISR_UPDATE_PSW()
#else /* #if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC)) */
#if (TRUE == CFG_SRV_SHELLOS)
/* Some operations that need to be performed when exiting the ISR. */
/* DD_1_0371 */
#define OS_ARCH_ISR2_EPILOGUE()        OS_ARCH_ISR2_EPILOGUE_1()
#else /* #if (FALSE == CFG_SRV_SHELLOS) */
/* Some operations that need to be performed when exiting the ISR. */
/* DD_1_0371 */
#define OS_ARCH_ISR2_EPILOGUE()        OS_ARCH_ISR2_EPILOGUE_1()
#endif /* TRUE == CFG_SRV_SHELLOS */
/*update PSW for memory protection and user mode 1*/
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
#define Os_ISR_UPDATE_PSW()                               \
if (Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted != TRUE)  \
{                                                         \
    Os_ArchSetTruReg();                                   \
    asm(" cps #0x10");                                    \
    asm("isb");                                           \
}
#else /* #if (FALSE == CFG_MEMORY_PROTECTION_ENABLE) */
#define Os_ISR_UPDATE_PSW()
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
#endif /* (OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC) */

#if (TRUE == CFG_INT_NEST_ENABLE)
#define OS_IRQ_MODE_CHECK()                                  \
{                                                            \
    if (Os_GetCpuMode() == OS_CPUMODE_USER1)              \
    {                                                        \
        asm("SVC 8");                                        \
    }                                                        \
    else                                                     \
    {                                                        \
        asm("cps #0x12");                                    \
    }                                                        \
}
#else/* #if (FALSE == CFG_INT_NEST_ENABLE) */
#define OS_IRQ_MODE_CHECK()
#endif /*(TRUE == CFG_INT_NEST_ENABLE)*/

/*=======[I N T E R N A L   M A C R O]========================================*/
#if (TRUE == CFG_INT_NEST_ENABLE)
/* Some operations to be performed when ISR1 enters an interrupt. */
#define OS_ARCH_ISR1_PROLOGUE(isrId)                        \
{                                                           \
    if (0u == (Os_IntNestISR1 + Os_IntNestISR2))            \
    {                                                       \
         Os_Switch2System();                                \
    }                                                       \
    else                                                    \
    {                                                       \
        Os_IsrNestPcxStack[(Os_IntNestISR2 + Os_IntNestISR1)] = Os_ArchSp;\
        if ((Os_IntNestISR2 > 0) && (Os_IntNestISR1 == 0))  \
        {                                                   \
            Os_Switch2System();                             \
        }                                                   \
    }                                                       \
    Os_IntCfgIsrId = isrId;                                 \
    if (0U == Os_IntNestISR1)                               \
    {                                                       \
        Os_SaveLevelISR1 = Os_SCB.sysOsLevel;               \
        Os_SCB.sysOsLevel = OS_LEVEL_ISR1;                  \
    }                                                       \
    Os_EnterISR1();                                         \
    Os_IntNestISR1++;                                       \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)   \
    {                                                       \
        Os_ArchEnableInt();                                 \
    }                                                       \
}
/* Some operations to be performed when ISR1 exits an interrupt. */
#define OS_ARCH_ISR1_EPILOGUE()                             \
{                                                           \
    Os_ArchDisableInt();                                    \
    Os_ExitISR1();                                          \
    Os_IntNestISR1--;                                       \
    if(0U == Os_IntNestISR1)                                \
    {                                                       \
        Os_SCB.sysOsLevel = Os_SaveLevelISR1;               \
    }                                                       \
    if ((0U == Os_IntNestISR1) && (0U == Os_IntNestISR2))   \
    {                                                       \
        writel(0Xffff, OS_VICADDRESS);                      \
        asm("cps #0x12");                                   \
        asm("dsb");                                         \
        Os_ArchResumeContext();                             \
    }                                                       \
    else                                                    \
    {                                                       \
        Os_ArchSp = Os_IsrNestPcxStack[(Os_IntNestISR2 + Os_IntNestISR1)];\
        writel(0Xffff, OS_VICADDRESS);                      \
        Os_ISR2ResumeIsrContext();                          \
    }                                                       \
}

#else /* #if (FALSE == CFG_INT_NEST_ENABLE) */
/* Some operations to be performed when ISR1 enters an interrupt. */
#define OS_ARCH_ISR1_PROLOGUE(isrId)                        \
{                                                           \
    Os_IsrNestPcxStack[(Os_IntNestISR2 + Os_IntNestISR1)] = Os_ArchSp;\
    Os_Switch2System();                                     \
    Os_IntCfgIsrId = isrId;                                 \
    Os_SaveLevelISR1 = Os_SCB.sysOsLevel;                   \
    Os_SCB.sysOsLevel = OS_LEVEL_ISR1;                      \
    Os_EnterISR1();                                         \
}
/* Some operations to be performed when ISR1 exits an interrupt. */
#define OS_ARCH_ISR1_EPILOGUE()                             \
{                                                           \
    Os_SCB.sysOsLevel = Os_SaveLevelISR1;                   \
    Os_ExitISR1();                                          \
    Os_ArchSp = Os_IsrNestPcxStack[(Os_IntNestISR2 + Os_IntNestISR1)];\
    writel(0Xffff, OS_VICADDRESS);                          \
    Os_ArchResumeContext();                                 \
}
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
/* Some operations to be performed when ISR2 enters an interrupt. */
/* DD_1_0376 */
#if (OS_SC4 == CFG_SC)
#if (TRUE == CFG_INT_NEST_ENABLE)
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    if (Os_IntNestISR2 >= 1U)                                 \
    {                                                         \
        Os_IsrNestPcxStack[Os_IntNestISR2 - 1u] = Os_ArchSp;  \
    }                                                         \
    if (E_OK != Os_TmProtIsrFrameChk(isrId))                  \
    {                                                         \
        if (0u == Os_IntNestISR2)                             \
        {                                                     \
            Os_IsrNestPcxStack[Os_IntNestISR2] = 0u;          \
            writel(0Xffff, OS_VICADDRESS);                    \
            asm("cps #0x12");                                 \
            asm("dsb");                                       \
            Os_ArchResumeContext();                           \
        }                                                     \
        else                                                  \
        {                                                     \
            Os_ArchSp=Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
            Os_ISR2ResumeIsrContext();                        \
        }                                                     \
    }                                                         \
    Os_IntCfgIsrId = isrId;                                   \
    Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][isrId].hostApp;\
    asm("dsb");                                               \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)     \
    {                                                         \
        Os_ISR_UPDATE_PSW();                                  \
        Os_ArchSwitch2ISR2Stk(isrId);                         \
        Os_EnterISR2();                                       \
        Os_ArchEnableInt();                                   \
    }                                                         \
    else                                                      \
    {                                                         \
        Os_ISR_UPDATE_PSW();                                  \
        Os_ArchSwitch2ISR2Stk(isrId);                         \
        Os_EnterISR2();                                       \
    }                                                         \
}
#else /* FALSE == CFG_INT_NEST_ENABLE */
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    if (Os_IntNestISR2 >= 1U)                                 \
    {                                                         \
        Os_IsrNestPcxStack[Os_IntNestISR2 - 1u] = Os_ArchSp;  \
    }                                                         \
    if (E_OK != Os_TmProtIsrFrameChk(isrId))                  \
    {                                                         \
        if (0u == Os_IntNestISR2)                             \
        {                                                     \
            Os_IsrNestPcxStack[Os_IntNestISR2] = 0u;          \
            writel(0Xffff, OS_VICADDRESS);                    \
            Os_ArchResumeContext();                           \
        }                                                     \
        else                                                  \
        {                                                     \
            Os_ArchSp=Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
            writel(0Xffff, OS_VICADDRESS);                    \
            Os_ISR2ResumeIsrContext();                        \
        }                                                     \
    }                                                         \
    Os_IntCfgIsrId = isrId;                                   \
    Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][isrId].hostApp;\
    asm("dsb");                                               \
    Os_ISR_UPDATE_PSW();                                      \
    Os_ArchSwitch2ISR2Stk(isrId);                             \
    Os_EnterISR2();                                           \
}
#endif /* TRUE == CFG_INT_NEST_ENABLE */

/* Some operations to be performed when ISR2 exits an interrupt. */
/* DD_1_0377 */                                 
#define OS_ARCH_ISR2_EPILOGUE_1()                           \
{                                                           \
    Os_ArchDisableInt();                                    \
    OS_IRQ_MODE_CHECK();                                    \
    OS_ISR2OCCUPYINTRES();                                  \
    Os_ArchMemProtSwithToSystem();                          \
    if (1U == Os_IntNestISR2)                               \
    {                                                       \
        Os_ExitISR2();                                      \
        Os_TprotTerminateIsr = FALSE;                       \
        writel(0Xffff, OS_VICADDRESS);                      \
        Os_ArchResumeContext();                             \
    }                                                       \
    else                                                    \
    {                                                       \
        if (TRUE == Os_TprotTerminateIsr)                   \
        {                                                   \
            Os_IntNestISR2--;                               \
            Os_ExitISR2();                                  \
            Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker -1u; \
            Os_TprotTerminateIsr = FALSE;                   \
            if (0U == Os_IntNestISR2)                       \
            {                                               \
                Os_SCB.sysOsLevel=OS_LEVEL_TASK;            \
                writel(0Xffff, OS_VICADDRESS);              \
                Os_ArchResumeContext();                     \
            }                                               \
            else                                            \
            {                                               \
                Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
                writel(0Xffff, OS_VICADDRESS);              \
                Os_ISR2ResumeIsrContext();                  \
            }                                               \
        }                                                   \
        else                                                \
        {                                                   \
            Os_ExitISR2();                                  \
            Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
            writel(0Xffff, OS_VICADDRESS);                  \
            Os_ISR2ResumeIsrContext();                      \
        }                                                   \
    }                                                       \
}
#else /* OS_SC4 != CFG_SC */
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    if (Os_IntNestISR2 >= 1U)                                 \
    {                                                         \
        Os_IsrNestPcxStack[Os_IntNestISR2 - 1u] = Os_ArchSp;  \
    }                                                         \
    if (E_OK != Os_TmProtIsrFrameChk(isrId))                  \
    {                                                         \
        if (0u == Os_IntNestISR2)                             \
        {                                                     \
            Os_IsrNestPcxStack[Os_IntNestISR2] = 0u;          \
            writel(0Xffff, OS_VICADDRESS);                    \
            asm("cps #0x12");                                 \
            asm("dsb");                                       \
            Os_ArchResumeContext();                           \
        }                                                     \
        else                                                  \
        {                                                     \
            Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
            writel(0Xffff, OS_VICADDRESS);                    \
            Os_ISR2ResumeIsrContext();                        \
        }                                                     \
    }                                                         \
    Os_IntCfgIsrId = isrId;                                   \
    Os_EnterISR2();                                           \
    Os_ArchSwitch2ISR2Stk(isrId)                              \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)     \
    {                                                         \
        Os_ArchEnableInt();                                   \
    }                                                         \
}
/* Some operations to be performed when ISR2 exits an interrupt. */
/* DD_1_0377 */
#define OS_ARCH_ISR2_EPILOGUE_1()                           \
{                                                           \
    Os_ArchDisableInt();                                    \
    OS_IRQ_MODE_CHECK();                                    \
    OS_ISR2OCCUPYINTRES();                                  \
    Os_Switch2System();                                     \
    if (1U == Os_IntNestISR2)                               \
    {                                                       \
        Os_ExitISR2();                                      \
        Os_TprotTerminateIsr = FALSE;                       \
        writel(0xffff, OS_VICADDRESS);                      \
        Os_ArchResumeContext();                             \
    }                                                       \
    else                                                    \
    {                                                       \
        if (TRUE == Os_TprotTerminateIsr)                   \
        {                                                   \
            Os_IntNestISR2--;                               \
            Os_ExitISR2();                                  \
            Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker -1u; \
            Os_TprotTerminateIsr = FALSE;                   \
            if (0U == Os_IntNestISR2)                       \
            {                                               \
                Os_SCB.sysOsLevel=OS_LEVEL_TASK;            \
                writel(0xffff, OS_VICADDRESS);              \
                Os_ArchResumeContext();                     \
            }                                               \
            else                                            \
            {                                               \
                Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
                writel(0Xffff, OS_VICADDRESS);              \
                Os_ISR2ResumeIsrContext();                  \
            }                                               \
        }                                                   \
        else                                                \
        {                                                   \
            Os_ExitISR2();                                  \
            Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
            writel(0Xffff, OS_VICADDRESS);                  \
            Os_ISR2ResumeIsrContext();                      \
        }                                                   \
    }                                                       \
}
#endif /* #if (OS_SC4 == CFG_SC) */
#define OS_ARCH_ISR2_EPILOGUE_ISR2()                        \
{                                                           \
    Os_ArchDisableInt();                                    \
    OS_IRQ_MODE_CHECK();                                    \
    OS_ISR2OCCUPYINTRES();                                  \
    Os_ArchMemProtSwithToSystem();                          \
    if (1U == Os_IntNestISR2)                               \
    {                                                       \
        Os_ExitISR2();                                      \
        Os_TprotTerminateIsr = FALSE;                       \
        Os_ArchResumeContext();                             \
    }                                                       \
    else                                                    \
    {                                                       \
        if (TRUE == Os_TprotTerminateIsr)                   \
        {                                                   \
            Os_IntNestISR2--;                               \
            Os_ExitISR2();                                  \
            Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker -1u; \
            Os_TprotTerminateIsr = FALSE;                   \
            if (0U == Os_IntNestISR2)                       \
            {                                               \
                Os_SCB.sysOsLevel=OS_LEVEL_TASK;            \
                writel(0Xffff, OS_VICADDRESS);              \
                Os_ArchResumeContext();                     \
            }                                               \
            else                                            \
            {                                               \
                Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
                writel(0Xffff, OS_VICADDRESS);              \
                Os_ISR2ResumeIsrContext();                  \
            }                                               \
        }                                                   \
        else                                                \
        {                                                   \
            Os_ExitISR2();                                  \
            Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1U];\
            writel(0Xffff, OS_VICADDRESS);                  \
            Os_ISR2ResumeIsrContext();                      \
        }                                                   \
    }                                                       \
}

#elif (TRUE == CFG_INT_NEST_ENABLE)
/* Some operations to be performed when ISR2 enters an interrupt. */
/* DD_1_0376 */
#if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC))
#define OS_ARCH_ISR2_PROLOGUE(isrId)                             \
{                                                                \
    if (Os_IntNestISR2 >= 1U)                                    \
    {                                                            \
        Os_IsrNestPcxStack[Os_IntNestISR2 - 1u] = Os_ArchSp;     \
    }                                                            \
    Os_IntCfgIsrId = isrId;                                      \
    Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][isrId].hostApp;\
    asm("dsb");                                                  \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)        \
    {                                                            \
        Os_ISR_UPDATE_PSW();                                     \
        Os_ArchSwitch2ISR2Stk(isrId);                            \
        Os_EnterISR2();                                          \
        Os_ArchEnableInt();                                      \
    }                                                            \
    else                                                         \
    {                                                            \
        Os_ISR_UPDATE_PSW();                                     \
        Os_ArchSwitch2ISR2Stk(isrId);                            \
        Os_EnterISR2();                                          \
    }                                                            \
}
#define OS_ARCH_ISR2_EPILOGUE_1()                               \
{                                                               \
    OS_ISR2OCCUPYINTRES();                                      \
    Os_ArchDisableInt();                                        \
    OS_IRQ_MODE_CHECK();                                        \
    Os_Switch2System();                                         \
    Os_ExitISR2();                                              \
    if (0U == Os_IntNestISR2)                                   \
    {                                                           \
        writel(0Xffff, OS_VICADDRESS);                          \
        Os_ArchResumeContext();                                 \
    }                                                           \
    else                                                        \
    {                                                           \
        Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1u];    \
        writel(0Xffff, OS_VICADDRESS);                          \
        Os_ISR2ResumeIsrContext();                              \
    }                                                           \
}
#else /* #if ((OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC)) */
#define OS_ARCH_ISR2_PROLOGUE(isrId)                             \
{                                                                \
    if (Os_IntNestISR2 >= 1U)                                    \
    {                                                            \
        Os_IsrNestPcxStack[Os_IntNestISR2 - 1u] = Os_ArchSp;     \
    }                                                            \
    Os_ArchSwitch2ISR2Stk(isrId);                                \
    Os_IntCfgIsrId = isrId;                                      \
    Os_EnterISR2();                                              \
    if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)        \
    {                                                            \
        Os_ArchEnableInt();                                      \
    }                                                            \
}
#define OS_ARCH_ISR2_EPILOGUE_1()                               \
{                                                               \
    Os_ArchDisableInt();                                        \
    OS_IRQ_MODE_CHECK();                                        \
    OS_ISR2OCCUPYINTRES();                                      \
    Os_Switch2System();                                         \
    Os_ExitISR2();                                              \
    if (0U == Os_IntNestISR2)                                   \
    {                                                           \
        writel(0Xffff, OS_VICADDRESS);                          \
        Os_ArchResumeContext();                                 \
    }                                                           \
    else                                                        \
    {                                                           \
        Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1u];    \
        writel(0Xffff, OS_VICADDRESS);                          \
        Os_ISR2ResumeIsrContext();                              \
    }                                                           \
}
#endif /* #if ((OS_SC4 == CFG_SC) || (OS_SC3 == CFG_SC)) */
/* Some operations to be performed when ISR2 exits an interrupt. */
/* DD_1_0377 */
#define OS_ARCH_ISR2_EPILOGUE_ISR2()                            \
{                                                               \
    Os_ArchDisableInt();                                        \
    OS_IRQ_MODE_CHECK();                                        \
    OS_ISR2OCCUPYINTRES();                                      \
    Os_Switch2System();                                         \
    Os_ExitISR2();                                              \
    if (0U == Os_IntNestISR2)                                   \
    {                                                           \
        writel(0Xffff, OS_VICADDRESS);                          \
        Os_ArchResumeContext();                                 \
    }                                                           \
    else                                                        \
    {                                                           \
        Os_ArchSp = Os_IsrNestPcxStack[Os_IntNestISR2 - 1u];    \
        writel(0Xffff, OS_VICADDRESS);                          \
        Os_ISR2ResumeIsrContext();                              \
    }                                                           \
}
#else /* FALSE == CFG_INT_NEST_ENABLE */
/* Some operations to be performed when ISR2 enters an interrupt. */
/* DD_1_0376 */
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
{                                                             \
    Os_ArchSwitch2ISR2Stk(isrId);                             \
    Os_IntCfgIsrId = isrId;                                   \
    Os_EnterISR2();                                           \
}
/* Some operations to be performed when ISR2 exits an interrupt. */
/* DD_1_0377 */
#define OS_ARCH_ISR2_EPILOGUE_1()                             \
{                                                             \
    Os_Switch2System();                                       \
    OS_ISR2OCCUPYINTRES();                                    \
    Os_ExitISR2();                                            \
    writel(0Xffff, OS_VICADDRESS);                            \
    Os_ArchResumeContext();                                   \
}
#define OS_ARCH_ISR2_EPILOGUE_ISR2()                          \
{                                                             \
    OS_IRQ_MODE_CHECK();                                      \
    Os_Switch2System();                                       \
    OS_ISR2OCCUPYINTRES();                                    \
    Os_ExitISR2();                                            \
    writel(0Xffff, OS_VICADDRESS);                            \
    Os_ArchResumeContext();                                   \
}
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
FUNC(void, OS_CODE)  Os_ArchSetMemProtSet(uint32 MpSetIdx);
FUNC(uint32, OS_CODE) Os_ArchGetMemProtSet(void);
/* Set access rights for memory protection. */
/* DD_1_0378 */

/* Set up areas that can be accessed by a trusted APP. */
/* DD_1_0379 */
#define Os_ArchSetTruReg()                                                      \
{                                                                               \
    Os_MpuDisable();                                                            \
    Os_MpuSetRegion(MPU_REGION_15, ((uint32)PFLASH_START) ,               \
                    Os_CaculateMemSize((uint8*)PFLASH_START, (uint8*)PFLASH_END) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RO_USER_RO_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);  \
    Os_MpuSetRegion(MPU_REGION_14, ((uint32)app_ram_start__) ,               \
                    Os_CaculateMemSize((uint8*)app_ram_start__, (uint8*)app_ram_end__) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);  \
    Os_MpuEnable();                                                             \
}

/* Set memory protection map for isr of non-trusted app */
/* DD_1_0380 */
#define Os_ArchSetNonTruIsrReg(IsrId, HostAppId)                       \
{                                                                              \
    Os_MpuDisable();                                                           \
    Os_MpuSetRegion(MPU_REGION_14, ((uint32)Os_IsrDAddr[IsrId].ISR_ADDR_START) , \
                    Os_CaculateMemSize(Os_IsrDAddr[IsrId].ISR_ADDR_START, Os_IsrDAddr[IsrId].ISR_ADDR_END) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    if (Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) != 0u)\
    {                                                                          \
        Os_MpuSetRegion(MPU_REGION_13, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START,\
                        Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) | MPU_REGION_ENABLE, \
                        MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    }                                                                          \
    Os_MpuSetRegion(MPU_REGION_12, ((uint32)app_ram_start__) , \
                    Os_CaculateMemSize((uint8*)app_ram_start__, (uint8*)app_ram_end__) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RO_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    Os_MpuEnable();                                                            \
}

/* Set memory protection map for isr of trusted app */
/* DD_1_0381 */
#define Os_ArchSetTruIsrProtReg(IsrId, HostAppId)                              \
{                                                                              \
    Os_MpuDisable();                                                           \
    Os_MpuSetRegion(MPU_REGION_14, ((uint32)Os_IsrDAddr[IsrId].ISR_ADDR_START) , \
                    Os_CaculateMemSize(Os_IsrDAddr[IsrId].ISR_ADDR_START, Os_IsrDAddr[IsrId].ISR_ADDR_END) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    if (Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) != 0u)\
    {                                                                          \
        Os_MpuSetRegion(MPU_REGION_13, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START,\
                        Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) | MPU_REGION_ENABLE, \
                        MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    }                                                                          \
    Os_MpuSetRegion(MPU_REGION_12, ((uint32)app_ram_start__) , \
                    Os_CaculateMemSize((uint8*)app_ram_start__, (uint8*)app_ram_end__) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RO_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    Os_MpuEnable();                                                            \
}

/* Set memory protection map for task of non-trusted app. */
/* DD_1_0382 */
#define Os_ArchSetNonTruTskReg(TaskId, HostAppId)                           \
{                                                                                   \
    Os_MpuDisable();                                                                \
    Os_MpuSetRegion(MPU_REGION_14, ((uint32)Os_TaskDAddr[TaskId].Task_ADDR_START) , \
                    Os_CaculateMemSize(Os_TaskDAddr[TaskId].Task_ADDR_START, Os_TaskDAddr[TaskId].Task_ADDR_END) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    if (Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) != 0u)\
    {                                                                          \
        Os_MpuSetRegion(MPU_REGION_13, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START,\
                        Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) | MPU_REGION_ENABLE, \
                        MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    }                                                                          \
    Os_MpuSetRegion(MPU_REGION_12, ((uint32)app_ram_start__) , \
                    Os_CaculateMemSize((uint8*)app_ram_start__, (uint8*)app_ram_end__) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RO_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    Os_MpuEnable();                                                          \
}

/* Set memory protection map for task of trusted app. */
/* DD_1_0383 */
#define Os_ArchSetTruTskProtReg(TaskId,HostAppId)                              \
{                                                                              \
    Os_MpuDisable();                                                           \
    Os_MpuSetRegion(MPU_REGION_14, ((uint32)Os_TaskDAddr[TaskId].Task_ADDR_START) , \
                    Os_CaculateMemSize(Os_TaskDAddr[TaskId].Task_ADDR_START, Os_TaskDAddr[TaskId].Task_ADDR_END) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    if (Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) != 0u)\
    {                                                                          \
        Os_MpuSetRegion(MPU_REGION_13, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START,\
                        Os_CaculateMemSize(Os_AppPriDataAddr[HostAppId].APP_ADDR_START, Os_AppPriDataAddr[HostAppId].APP_ADDR_END) | MPU_REGION_ENABLE, \
                        MPU_PRIV_RW_USER_RW_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    }                                                                          \
    Os_MpuSetRegion(MPU_REGION_12, ((uint32)app_ram_start__) , \
                    Os_CaculateMemSize((uint8*)app_ram_start__, (uint8*)app_ram_end__) | MPU_REGION_ENABLE, \
                    MPU_PRIV_RW_USER_RO_EXEC | MPU_NORMAL_OIWTNOWA_NONSHARED);\
    Os_MpuEnable();                                                            \
}

/* Enable the enable bits for memory protection in PSW and SYSCON. */
/* DD_1_0384 */
#define Os_ArchMemProtEnable()

/* Enable the enable bits for memory protection in PSW. */
/* DD_1_0385 */
#define Os_ArchMemProtSwithToSystem()     \
{                                         \
    Os_ArchSwitch2System();               \
}

#else /* FALSE == CFG_MEMORY_PROTECTION_ENABLE */
/* Enable the enable bits for memory protection in PSW. */
/* DD_1_0385 */
#define Os_ArchMemProtSwithToSystem()
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

/* The interrupt occupies interrupt resources. */
/* DD_1_0387 */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
#define OS_ISR2OCCUPYINTRES() Os_Isr2OccupyIntRes()
#else /* #if (FALSE == CFG_SERVICE_PROTECTION_ENABLE) */
#define OS_ISR2OCCUPYINTRES()
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */

/*============[STACK CHECK]=====================*/
#define IF_STACK_CHECK_ENTER_ISR1_FROM_TASK()                        \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                         \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR1_FROM_ISR2()                        \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                         \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR1_FROM_ISR1()                        \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_EXIT_ISR1()                                   \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                         \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR2_FORM_TASK()                                \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_ENTER_ISR2_FORM_ISR2()                                \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define IF_STACK_CHECK_EXIT_ISR2()                                           \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))        \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))        \
    || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))        \
   )
#define IF_STACK_CHECK_SWITCH_TASK()                                         \
if ((OS_STACK_FILL_PATTERN != (*(StackPtr)))                                 \
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))\
            || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3)))\
   )
#define OS_FILL_SAFET_STACK()                                                \
{                                                                            \
    *ptr = OS_STACK_FILL_PATTERN;                                            \
    *(ptr + (Os_StackDataType)1) = OS_STACK_FILL_PATTERN;                    \
    *(ptr + (Os_StackDataType)2) = OS_STACK_FILL_PATTERN;                    \
    *(ptr + (Os_StackDataType)3) = OS_STACK_FILL_PATTERN;                    \
}
/*=======[T Y P E   D E F I N I T I O N S]====================================*/
/* Type of the variable to save the mcu status registration. */
/* DD_1_0051 */
typedef uint32 Os_ArchMsrType; 
/* Type of the variable to save the task control block extension. */
/* DD_1_0052 */
typedef uint32 Os_TaskCBExtType;
/* Type of the core mode. */
/* DD_1_0056 */
typedef enum
{
    OS_CORE_MODE_HALT       = 0U,
    OS_CORE_MODE_RUN        = 1U,
    OS_CORE_MODE_IDLE       = 2U,
    OS_CORE_MODE_SLEEP      = 3U,
    OS_CORE_MODE_STANDBY    = 4U,
    OS_CORE_MODE_UNKNOWN    = 5U
}Os_CoreModeType;

/*=======[E X T E R N A L   D A T A]==========================================*/
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore0[CFG_TASK_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore1[CFG_TASK_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore2[CFG_TASK_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(volatile uint32, OS_VAR)                 Os_ArchSp;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(volatile uint32, OS_VAR)                 Os_IsrSp;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(volatile uint32, OS_VAR)                   Os_SysSp;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(Os_ArchMsrType, OS_VAR)                   cpsr_isr;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(volatile uint32, OS_VAR)               Os_TpTrusted;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern P2VAR(Os_TaskCBExtType, AUTOMATIC, OS_VAR)   Os_TaskCBExt;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern P2VAR(uint32, AUTOMATIC, OS_VAR)		    Os_IsrNestPcxStack;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern P2CONST(OS_ISR_ADDR, AUTOMATIC, OS_VAR)      Os_IsrDAddr;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern P2CONST(OS_TASK_ADDR, AUTOMATIC, OS_VAR)     Os_TaskDAddr;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(uint32, OS_VAR) Os_PSW_PRS;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"


#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(volatile uint32, OS_VAR) Os_TprotTerminateIsr;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif


#if (CFG_ISR_MAX > 0U)
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore0[CFG_ISR_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore1[CFG_ISR_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
extern VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore2[CFG_ISR_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(Os_CallLevelType, OS_VAR) Os_SaveLevelISR1;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* CFG_ISR_MAX > 0U */

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern P2VAR(volatile Os_TCBType  * volatile , OS_VAR, OS_VAR)       Os_RunningTCB;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
extern FUNC(Os_IPLType, OS_CODE) Os_ArchGetIpl(void);
extern FUNC(void, OS_CODE) Os_ArchSetIpl(Os_IPLType ipl,Os_IsrDescriptionType isrdesc);
extern FUNC(void, OS_CODE) Os_ArchSuspendInt(P2VAR(Os_ArchMsrType, AUTOMATIC, OS_VAR) msr);
extern FUNC(void, OS_CODE) Os_ArchRestoreInt(Os_ArchMsrType msr);
extern FUNC(void, OS_CODE) Os_ArchInitCPU(void);
extern FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void);
extern FUNC(void, OS_CODE) Os_ArchStartScheduler(void);

extern uint32 Os_CmpSwapW(uint32* address, uint32 compareVal, uint32 exchangedVal);

extern FUNC(Os_CoreIdType,OS_CODE)        Os_ArchGetCoreID(void);
extern FUNC(void, OS_CODE)                Os_ArchStartCore(Os_CoreIdType coreId);
extern FUNC(Os_CoreModeType, OS_CODE)     Os_GetCoreMode(Os_CoreIdType core);
extern FUNC(boolean, OS_CODE)             Os_SetCoreMode(Os_CoreIdType core, Os_CoreModeType coreMode);

#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
extern FUNC(void, OS_CODE) Os_ArchInitSystemTimer(void);
extern FUNC(void, OS_CODE) Os_SystickIsrClearFlag(void);
#endif
extern FUNC(void, OS_CODE_FAST) Os_SysTick_Handler0(void);
extern FUNC(void, OS_CODE_FAST) Os_SysTick_Handler1(void);
extern FUNC(void, OS_CODE_FAST) Os_SysTick_Handler2(void);

extern FUNC(void, OS_CODE) Os_SWI_Handler(void);
extern FUNC(void, OS_CODE) Os_IntHandler(void);
extern FUNC(void, OS_CODE) Os_ArchInitIntPrio(void);
extern FUNC(void, OS_CODE) Os_InterruptInit(void);
extern FUNC(void, OS_CODE) Os_InterruptInstall(uint16 irqId, uint8 prio, uint16 srcType, IntFun pFun);

extern void do_dispatch(void);
extern FUNC(void, OS_CODE) Os_ArchDispatch(void);

extern FUNC(void, OS_CODE) Os_ModeSpInit(void);

/* Shell protection */
#if (CFG_SRV_SHELLOS == TRUE)
extern FUNC(void, OS_CODE) Os_ArchSyscall(void);
extern FUNC(void, OS_CODE) Os_SetCpuMode(Os_CPUModeType mode); 
extern FUNC(uint32, OS_CODE) Os_GetCpuMode();
#endif /* CFG_SRV_SHELLOS == TRUE */

/* Timing protection. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
extern FUNC(void, OS_CODE) Os_ArchDisableAllInt_ButTimingProtInt(void);
extern FUNC(void, OS_CODE) Os_ArchEnableAllInt_ButTimingProtInt(void);

extern void Os_TimeProtClearFlag(void);
extern FUNC(void, OS_CODE) Os_ArchInitTimingProtTimer(void);

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0)
extern FUNC(void, OS_CODE_FAST) Os_TimeProtection_Handler0(void);
#endif
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1)
extern FUNC(void, OS_CODE_FAST) Os_TimeProtection_Handler1(void);
#endif
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2)
extern FUNC(void, OS_CODE_FAST) Os_TimeProtection_Handler2(void);
#endif
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

/* Memory protection. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
extern FUNC(void,OS_CODE) Os_ArchInitKnMemMap(void);
extern FUNC(void,OS_CODE) Os_ArchSetTaskMemMap(TaskType TaskId, ApplicationType HostAppId, uint32 isTrusted);
extern FUNC(void, OS_CODE) Os_ArchSetIsrMemMap
(
    ISRType         IsrId, 
    ApplicationType HostAppId, 
    uint32          isTrusted
);

extern FUNC(void, OS_CODE)  Os_MpuEnable(void);
extern FUNC(void, OS_CODE)  Os_MpuDisable(void);
extern FUNC(void, OS_CODE)  Os_MpuSetRegion(uint32 region, uint32 base, uint32 size, uint32 access);
extern FUNC(void, OS_CODE) Os_DisableMpuRegion(uint8 Region);

// extern FUNC(void, OS_CODE) Os_ArchInitSectionAddress(void);
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_ISR_MAX > 0)
extern FUNC(void, OS_CODE) Os_ArchDisableIntInApp
(
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) posCurAppCfg
);
extern FUNC(void, OS_CODE) Os_ArchAppTerminateIsrProc(Os_IsrType OsIsrID);
#endif /* CFG_ISR_MAX > 0 */
extern FUNC(void, OS_CODE) Os_ArchAppTerminateTaskProc(Os_TaskType OsTaskID);
extern FUNC(uint32 , OS_CODE) Os_CaculateMemSize(uint8 startAddr[],uint8 endAddr[]);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif  /* #ifndef OS_PROCESSOR_H */
/*=======[E N D   O F   F I L E]==============================================*/
