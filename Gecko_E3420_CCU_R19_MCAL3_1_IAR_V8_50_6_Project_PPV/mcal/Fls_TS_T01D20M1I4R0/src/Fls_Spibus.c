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
 * \file     Fls_Spibus.c                                                                            *
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

#include "Mcal.h"
#include "Fls.h"
#include "Fls_Cfg.h"

#ifdef FLS_SPIBUS_FLASH_CNT

/* PRQA S 0306,0314,0316,0326,1533,2755,3218,3673 EOF */

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#define PROTO(_opcode, _dq) \
        ((((uint32)(_opcode)) << FLS_BUS_OPCODE_PROTO_LSB) | (_dq))
#define ID_PROTO(dummy, _dq) \
        ((((uint32)(dummy)) << FLS_BUS_READID_DUMMY_LSB) | (_dq))

/* Flash opcodes. */
#define FLS_BUS_OP_WREN (0x06U)       /* Write enable */
#define FLS_BUS_OP_WRDI (0x04U)       /* Write disable */
#define FLS_BUS_OP_RDSR (0x05U)       /* Read status register */
#define FLS_BUS_OP_GIGA_RDSR (0x35U)  /* Read status register for giga */
#define FLS_BUS_OP_GIGA_WRSR (0x31U)  /* Write status register for giga */
#define FLS_BUS_OP_WRSR (0x01U)       /* Write status register 1 byte */
#define FLS_BUS_OP_RDSR2 (0x3fU)      /* Read status register 2 */
#define FLS_BUS_OP_WRSR2 (0x3eU)      /* Write status register 2 */
#define FLS_BUS_OP_WRPR (0xC0U)  /* Write parameters register */
#define FLS_BUS_OP_READ (0x03U)       /* Read data bytes (low frequency) */
#define FLS_BUS_OP_READ_FAST (0x0bU)  /* Read data bytes (high frequency) */
#define FLS_BUS_OP_READ_1_1_2 (0x3bU) /* Read data bytes (Dual Output SPI) */
#define FLS_BUS_OP_READ_1_2_2 (0xbbU) /* Read data bytes (Dual I/O SPI) */
#define FLS_BUS_OP_READ_1_1_4 (0x6bU) /* Read data bytes (Quad Output SPI) */
#define FLS_BUS_OP_READ_1_4_4 (0xebU) /* Read data bytes (Quad I/O SPI) */
#define FLS_BUS_OP_READ_1_1_8 (0x8bU) /* Read data bytes (Octal Output SPI) */
#define FLS_BUS_OP_READ_1_8_8 (0xcbU) /* Read data bytes (Octal I/O SPI) */
#define FLS_BUS_OP_PP (0x02U)         /* Page program (up to 256 bytes) */
#define FLS_BUS_OP_PP_1_1_4 (0x32U)   /* Quad page program */
#define FLS_BUS_OP_PP_1_4_4 (0x38U)   /* Quad page program */
#define FLS_BUS_OP_PP_1_1_8 (0x82U)   /* Octal page program */
#define FLS_BUS_OP_PP_1_8_8 (0xc2U)   /* Octal page program */
#define FLS_BUS_OP_BE_4K (0x20U)      /* Erase 4KiB block */
#define FLS_BUS_OP_BE_4K_PMC (0xd7U)  /* Erase 4KiB block on PMC chips */
#define FLS_BUS_OP_BE_32K (0x52U)     /* Erase 32KiB block */
#define FLS_BUS_OP_CHIP_ERASE (0xc7U) /* Erase whole flash chip */
#define FLS_BUS_OP_SE (0xd8U)         /* Sector erase (usually 64KiB) */
#define FLS_BUS_OP_RDID (0x9fU)       /* Read JEDEC ID */
#define FLS_BUS_OP_RDSFDP (0x5aU)     /* Read SFDP */
#define FLS_BUS_OP_RDCR (0x35U)       /* Read configuration register */
#define FLS_BUS_OP_RDFSR (0x70U)      /* Read flag status register */
#define FLS_BUS_OP_CLFSR (0x50U)      /* Clear flag status register */
#define FLS_BUS_OP_RDEAR (0xc8U)      /* Read Extended Address Register */
#define FLS_BUS_OP_WREAR (0xc5U)      /* Write Extended Address Register */
#define FLS_BUS_OP_RSTEN (0x66U)      /* Reset Enable register */
#define FLS_BUS_OP_RSTMEM (0x99U)     /* Reset Memory */
#define FLS_BUS_OP_EN4B (0xb7U)       /* Enter 4-byte mode */
#define FLS_BUS_OP_EX4B (0xe9U)       /* Exit 4-byte mode */
#define FLS_BUS_OP_RDAR (0x65U)       /* Read Any Register */
#define FLS_BUS_OP_WRAR (0x71U)       /* Write Any Register */
#define FLS_BUS_OP_WRVR (0x81U)       /* Write Volatile Register */
#define FLS_BUS_OP_RDVR (0x85U)       /* Write Volatile Register */
#define FLS_BUS_OP_ISSI_QPI_EN (0x35U) /* Enables the Flash device for QPI mode */
#define FLS_BUS_OP_ISSI_QPI_EX (0xF5U) /* Disable the Flash device from QPI mode */
#define FLS_BUS_OP_GIGA_QPI_EN (0x38U) /* Enables the Flash device for QPI mode */
#define FLS_BUS_OP_GIGA_QPI_EX (0xFFU) /* Disable the Flash device from QPI mode */

/* 4-byte address opcodes - used on Spansion and some Macronix flashes. */
#define FLS_BUS_OP_READ_4B (0x13U)       /* Read data bytes (low frequency) */
#define FLS_BUS_OP_READ_FAST_4B (0x0cU)  /* Read data bytes (high frequency) */
#define FLS_BUS_OP_READ_1_1_2_4B (0x3cU) /* Read data bytes (Dual Output SPI) */
#define FLS_BUS_OP_READ_1_2_2_4B (0xbcU) /* Read data bytes (Dual I/O SPI) */
#define FLS_BUS_OP_READ_1_1_4_4B (0x6cU) /* Read data bytes (Quad Output SPI) */
#define FLS_BUS_OP_READ_1_4_4_4B (0xecU) /* Read data bytes (Quad I/O SPI) */
#define FLS_BUS_OP_READ_1_1_8_4B (0x7cU) /* Read data bytes (Octal Output SPI) */
#define FLS_BUS_OP_READ_1_8_8_4B (0xccU) /* Read data bytes (Octal I/O SPI) */
#define FLS_BUS_OP_PP_4B (0x12U)         /* Page program (up to 256 bytes) */
#define FLS_BUS_OP_PP_1_1_4_4B (0x34U)   /* Quad page program */
#define FLS_BUS_OP_PP_1_4_4_4B (0x3eU)   /* Quad page program */
#define FLS_BUS_OP_PP_1_1_8_4B (0x84U)   /* Octal page program */
#define FLS_BUS_OP_PP_1_8_8_4B (0x8eU)   /* Octal page program */
#define FLS_BUS_OP_BE_4K_4B (0x21U)      /* Erase 4KiB block */
#define FLS_BUS_OP_BE_32K_4B (0x5cU)     /* Erase 32KiB block */
#define FLS_BUS_OP_SE_4B (0xdcU)         /* Sector erase (usually 64KiB) */

/* Miron */
#define FLS_BUS_OCTAL_DQS_MIRION (0xe7U)
#define FLS_BUS_OCTAL_NON_DQS_MIRION (0xc7U)

/* issi giga */
#define FLS_BUS_OP_READ_4S_4D_4D (0xedU)

/* giga */
#define FLS_BUS_OP_PP_1_4_4_GIGA (0xc2U)

/* cycess */
#define FLS_BUS_OP_EX4B_CYCESS (0xB8U)

/* Double Transfer Rate opcodes - defined in JEDEC JESD216B. */
#define FLS_BUS_OP_READ_1_1_1_DTR (0x0dU)
#define FLS_BUS_OP_READ_1_2_2_DTR (0xbdU)
#define FLS_BUS_OP_READ_1_4_4_DTR (0xedU)
#define FLS_BUS_OP_READ_1_1_8_DTR (0x9dU)

#define FLS_BUS_OP_READ_1_1_1_DTR_4B (0x0eU)
#define FLS_BUS_OP_READ_1_2_2_DTR_4B (0xbeU)
#define FLS_BUS_OP_READ_1_4_4_DTR_4B (0xeeU)
#define FLS_BUS_OP_READ_1_8_8_DTR_4B (0xfdU)

#define FLS_BUS_ID_CAPACITY_OFFSET 2

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static int Fls_BusGeneralSetAddressWidth(Fls_BusHandleType *nor,
        boolean enable);
static int Fls_BusMironDefaultInit(Fls_BusHandleType *nor);
static int Fls_BusMironOctalDtrEnable(Fls_BusHandleType *nor, boolean opiEnable, boolean dqsEnable);
static int Fls_BusIssiQuadEnable(Fls_BusHandleType *nor, boolean enable);
static int Fls_BusIssiEnterQuad(Fls_BusHandleType *nor, boolean enable);
static int Fls_BusIssiDefaultInit(Fls_BusHandleType *nor);
static int Fls_BusGigaEnterQuad(Fls_BusHandleType *nor, boolean enable);
static int Fls_BusGigaDefaultInit(Fls_BusHandleType *nor);
static int Fls_BusGiga25qQuadEnable(Fls_BusHandleType *nor, boolean enable);
static int Fls_BusGigaQuadEnable(Fls_BusHandleType *nor, boolean enable);
static int Fls_BusGigaSetProtectArea(Fls_BusHandleType *nor, Fls_AddressType addr,
                                     Fls_LengthType size);
static int Fls_BusCypressDefaultInit(Fls_BusHandleType *nor);
static int Fls_BusCypressSetAddressWidth(Fls_BusHandleType *nor, boolean enable);
static int Fls_BusCypressOctalDtrEnable(Fls_BusHandleType *nor, boolean opiEnable,
                                        boolean dqsEnable);
static int Fls_SpiBusWriteEnableLocked(Fls_BusHandleType *nor, boolean enable);

static int Fls_SpiBusWaitIdle(Fls_BusHandleType *nor);
static int Fls_SpiBusWriteEnable(Fls_BusHandleType *nor, boolean enable);
static int Fls_SpiBusInit(Fls_BusHandleType *nor, Fls_IpHostType *host,
                          const Fls_BusConfigType *config);
static void Fls_SpiBusDeinit(Fls_BusHandleType *nor);
static int Fls_SpiBusRead(Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
                          Fls_LengthType size);
static int Fls_SpiBusWrite(Fls_BusHandleType *nor, Fls_AddressType addr, const uint8 *buf,
                           Fls_LengthType size);
static int Fls_SpiBusErase(Fls_BusHandleType *nor, Fls_AddressType addr, Fls_LengthType size);
static int Fls_SpiBusGetBusyStatus(Fls_BusHandleType *nor);
static int Fls_SpiBusGetProtectStatus(Fls_BusHandleType *nor);
static int Fls_SpiBusCancel(Fls_BusHandleType *nor);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#define FLS_START_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

static VAR_ALIGN(const uint8 Fls_BusTrainingPattern[FLS_BUS_TRAINING_BUF_SIZE],
                 FLS_IP_ARCH_CACHE_LINE) =
{
    0x44, 0x1c, 0x39, 0x05, 0xd3, 0x7a, 0x3c, 0x04,
    0x16, 0x42, 0x0c, 0x8b, 0x7d, 0x12, 0x89, 0xa2,
    0xb8, 0xb1, 0xf7, 0xe8, 0xb7, 0x49, 0xca, 0x1c,
    0xaa, 0x9b, 0xf2, 0x7e, 0x01, 0x97, 0x60, 0x8c
};

static const Fls_BusFlashInfoType Fls_SpiBusIds[] =
{
    /* miron */
    {
        .name = "mt35xu",
        .flashId = {0x2c, 0x5b, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_8_8, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(FLS_BUS_OP_PP_1_8_8, FLS_BUS_PROTO_8_8_8_DTR),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            0,  /* erase 64Kb, do not support this mode */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 128Kb */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 20,
        .statusDummy = 8,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .octalDtrEnable = Fls_BusMironOctalDtrEnable,
        .defaultInit = Fls_BusMironDefaultInit
    },
    /* miron */
    {
        .name = "mt35xl",
        .flashId = {0x2c, 0x5a, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_8_8, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(FLS_BUS_OP_PP_1_8_8, FLS_BUS_PROTO_8_8_8_DTR),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            0,  /* erase 64Kb, do not support this mode */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 128Kb */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 20,
        .statusDummy = 8,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .octalDtrEnable = Fls_BusMironOctalDtrEnable,
        .defaultInit = Fls_BusMironDefaultInit
    },
    /* issi */
    {
        .name = "is25wp",
        .flashId = {0x9d, 0x70, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_4_4, FLS_BUS_PROTO_4_4_4),
        .writeProto = PROTO(FLS_BUS_OP_PP, FLS_BUS_PROTO_4_4_4),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 14,
        .statusDummy = 0,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .quadEnable = Fls_BusIssiQuadEnable,
        .enterQuad = Fls_BusIssiEnterQuad,
        .defaultInit = Fls_BusIssiDefaultInit
    },
    {
        .name = "is25lp",
        .flashId = {0x9d, 0x60, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_4_4, FLS_BUS_PROTO_4_4_4),
        .writeProto = PROTO(FLS_BUS_OP_PP, FLS_BUS_PROTO_4_4_4),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 14,
        .statusDummy = 0,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .quadEnable = Fls_BusIssiQuadEnable,
        .enterQuad = Fls_BusIssiEnterQuad,
        .defaultInit = Fls_BusIssiDefaultInit
    },
    /* giga */
    {
        .name = "gd25lb",
        .flashId = {0xc8, 0x67, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_1_4, FLS_BUS_PROTO_4_4_4),
        .writeProto = PROTO(FLS_BUS_OP_PP_1_4_4_GIGA, FLS_BUS_PROTO_4_4_4),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 10,
        .statusDummy = 0,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .enterQuad = Fls_BusGigaEnterQuad,
        .defaultInit = Fls_BusGigaDefaultInit
    },
    {
        .name = "gd25q",
        .flashId = {0xc8, 0x40, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_1_4, FLS_BUS_PROTO_1_1_4),
        .writeProto = PROTO(FLS_BUS_OP_PP_1_1_4, FLS_BUS_PROTO_1_1_4),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 8,
        .statusDummy = 0,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .quadEnable = Fls_BusGiga25qQuadEnable,
    },
    {
        .name = "gd25f",
        .flashId = {0xc8, 0x43, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_4_4_DTR, FLS_BUS_PROTO_1_4_4_DTR),
        .writeProto = PROTO(FLS_BUS_OP_PP_1_1_4, FLS_BUS_PROTO_1_1_4),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 8,
        .statusDummy = 0,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .quadEnable = Fls_BusGigaQuadEnable,
    },
    {
        .name = "gd25lx",
        .flashId = {0xc8, 0x68, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_8_8, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(FLS_BUS_OP_PP_1_8_8, FLS_BUS_PROTO_8_8_8_DTR),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_8_8_8_DTR),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .readDummy = 14,
        .statusDummy = 8,
        .pageSize = 256,
        .setAddressWidth = Fls_BusGeneralSetAddressWidth,
        .octalDtrEnable = Fls_BusMironOctalDtrEnable,
        .SetProtectArea = Fls_BusGigaSetProtectArea,
        .defaultInit = Fls_BusMironDefaultInit
    },
    {
        .name = "S25fl",
        .flashId = {0x01, 0x60, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_FAST, FLS_BUS_PROTO_1_1_1),
        .writeProto = PROTO(FLS_BUS_OP_PP, FLS_BUS_PROTO_1_1_1),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_1_1_1),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_1_1_1),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_1_1_1),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 8,
        .statusDummy = 0,
        .pageSize = 256,
    },
    {
        .name = "w25q",
        .flashId = {0xef, 0x40, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_1_4, FLS_BUS_PROTO_1_1_4),
        .writeProto = PROTO(FLS_BUS_OP_PP_1_1_4, FLS_BUS_PROTO_1_1_4),
        .eraseProto = {
            PROTO(FLS_BUS_OP_BE_4K, FLS_BUS_PROTO_1_1_4),  /* erase 4Kb */
            PROTO(FLS_BUS_OP_BE_32K, FLS_BUS_PROTO_1_1_4),  /* erase 32Kb */
            PROTO(FLS_BUS_OP_SE, FLS_BUS_PROTO_1_1_4),  /* erase 64Kb */
            0,  /* erase 128Kb, do not support this mode */
            0,  /* erase 256Kb, do not support this mode */
        },
        .sectorSize = FLS_BUS_SECTOR_4K_SIZE,
        .sectorType = FLS_BUS_SECTOR_4KB,
        .readDummy = 8,
        .statusDummy = 0,
        .pageSize = 256,
        .quadEnable = Fls_BusGigaQuadEnable,
    },
    /* cypress */
    {
        .name = "S28hl",
        .flashId = {0x34, 0x5a, 0, 0, 0, 0},
        .readProto = PROTO(FLS_BUS_OP_READ_1_4_4_DTR_4B, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(FLS_BUS_OP_PP_4B, FLS_BUS_PROTO_8_8_8_DTR),
        .eraseProto = {
            0,  /* erase 4Kb , do not support this mode */
            0,  /* erase 32Kb , do not support this mode */
            0,  /* erase 64Kb , do not support this mode */
            0,  /* erase 128Kb, do not support this mode */
            PROTO(FLS_BUS_OP_SE_4B, FLS_BUS_PROTO_8_8_8_DTR), // erase 256Kb
        },
        .sectorSize = FLS_BUS_SECTOR_256K_SIZE,
        .sectorType = FLS_BUS_SECTOR_256KB,
        .readDummy = 23,
        .statusDummy = 8,
        .pageSize = 256,
        .setAddressWidth = Fls_BusCypressSetAddressWidth,
        .defaultInit = Fls_BusCypressDefaultInit,
        .octalDtrEnable = Fls_BusCypressOctalDtrEnable,
    },
};

static uint32 const Fls_SpibusReadIdLansList[] =
{
    ID_PROTO(0U, FLS_BUS_PROTO_1_1_1),
    ID_PROTO(0U, FLS_BUS_PROTO_2_2_2),
    ID_PROTO(0U, FLS_BUS_PROTO_4_4_4),
    ID_PROTO(8U, FLS_BUS_PROTO_8_8_8_DTR),
    ID_PROTO(8U, FLS_BUS_PROTO_8_8_8_DTR) | FLS_BUS_ADDRESS_EN,
};

#define FLS_STOP_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

Fls_BusFlashOpsType Fls_SpibusOps =
{
    .waitIdle = Fls_SpiBusWaitIdle,
    .writeEnable = Fls_SpiBusWriteEnable,
    .init = Fls_SpiBusInit,
    .deinit = Fls_SpiBusDeinit,
    .read = Fls_SpiBusRead,
    .write = Fls_SpiBusWrite,
    .erase = Fls_SpiBusErase,
    .getBusyStatus = Fls_SpiBusGetBusyStatus,
    .getProtectStatus = Fls_SpiBusGetProtectStatus,
    .cancel = Fls_SpiBusCancel,
    .setupNotificationCallback = Fls_BusSetupNotificationCallback,
    .getResult = Fls_BusGetResult,
    .getInfo = Fls_BusGetInfo,
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/** *****************************************************************************************************
 * \brief This function Reading registers from Flash.
 *
 * \verbatim
 * Syntax             : int Fls_Init(
 *                          Fls_BusHandleType *nor,
 *                          Fls_BusCommandType *cmd, Fls_AddressType addr,
 *                          uint8 *buf, Fls_LengthType length)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      cmd - Flash protocol commands
 *                      addr - Register address
 *                      buf - Read buffer, alloc by user
 *                      length - Read size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Reading registers from Flash
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusRegRead(Fls_BusHandleType *nor,
                             Fls_BusCommandType *cmd, Fls_AddressType addr,
                             uint8 *buf, Fls_LengthType length)
{
    int ret;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    ret = nor->host->ops->regRead(nor, cmd, addr, buf, length);
    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Writing registers from Flash.
 *
 * \verbatim
 * Syntax             : int Fls_Init(
 *                          Fls_BusHandleType *nor,
 *                          Fls_BusCommandType *cmd, Fls_AddressType addr,
 *                          uint8 *buf, Fls_LengthType length)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      cmd - Flash protocol commands
 *                      addr - Register address
 *                      buf - Write buffer, alloc by user
 *                      length - Write size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Writing registers from Flash
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusRegWrite(Fls_BusHandleType *nor,
                              Fls_BusCommandType *cmd, Fls_AddressType addr,
                              uint8 *buf, Fls_LengthType length)
{
    int ret;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    ret = nor->host->ops->regWrite(nor, cmd, addr, buf, length);
    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns the status of flash.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusGetStatus(
 *                          Fls_BusHandleType *nor, uint8 *status)
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
 * Parameters (out)   : status - The status of flash
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send commands with the Spibus protocol, and get the state of Flash
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_013
 *******************************************************************************************************/
static int Fls_SpiBusGetStatus(Fls_BusHandleType *nor, uint8 *status)
{
    VAR_ALIGN(uint8 reg[2], 4) = {0};
    int ret;
    Fls_BusCommandType readCmd;

    readCmd.opcode = FLS_BUS_OP_RDSR;
    readCmd.addrBytes = 0;
    readCmd.dummy = nor->info.statusDummy;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);

    ret = Fls_SpiBusRegRead(nor, &readCmd, 0, reg, 2);

    if (FLS_SUCCESS == ret)
    {
        *status = reg[0];
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns the result of whether the status of Flash is busy.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusGetBusyStatus(
 *                           Fls_BusHandleType *nor)
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
 * Return value       : 0 - Flash is idle
 *                     !0 - Flash is busy
 *
 * Description        : Send commands with the Spibus protocol, get the state of
 *                      Flash and determine whether it is idle
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_013
 *******************************************************************************************************/
static int Fls_SpiBusGetBusyStatus(Fls_BusHandleType *nor)
{
    int ret;
    uint8 flashStatus;

    ret = Fls_SpiBusGetStatus(nor, &flashStatus);

    if (0 != ret)
    {
        FLS_DEBUG("spi_nor get flash status failed, ret: %d!\n", ret);
    }
    else if (0U != (flashStatus & FLS_BIT(0)))
    {
        ret = FLS_FLASH_BUSY;
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns the flag status of flash.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusGetFlag(
 *                          Fls_BusHandleType *nor, uint8 *flag)
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
 * Parameters (out)   : flag - The flag status of flash
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send commands with the Spibus protocol, and get the flag status of Flash
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_013
 *******************************************************************************************************/
static int Fls_SpiBusGetFlag(Fls_BusHandleType *nor, uint8 *flag)
{
    VAR_ALIGN(uint8 reg[2], 4) = {0};
    int ret;
    Fls_BusCommandType readCmd;

    readCmd.opcode = FLS_BUS_OP_RDFSR;
    readCmd.addrBytes = 0;
    readCmd.dummy = nor->info.statusDummy;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);

    ret = Fls_SpiBusRegRead(nor, &readCmd, 0, reg, 2);

    if (FLS_SUCCESS == ret)
    {
        *flag = reg[0];
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns the result of whether the status of Flash is protected.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusGetProtectStatus(
 *                           Fls_BusHandleType *nor)
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
 * Return value       : 0 - Non protected error
 *                     !0 - Failed or protected error
 *
 * Description        : Send commands with the Spibus protocol, get the state of
 *                      Flash and determine whether it is idle
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_013
 *******************************************************************************************************/
static int Fls_SpiBusGetProtectStatus(Fls_BusHandleType *nor)
{
    int ret;
    uint8 flag;

    ret = Fls_SpiBusGetFlag(nor, &flag);

    if (0 != ret)
    {
        FLS_DEBUG("spi_nor get flash status failed, ret: %d!\n", ret);
    }
    else if (0U != (flag & FLS_BIT(1)))
    {
        ret = FLS_FLASH_PROTECTED;
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function enable flash writing
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusWriteEnable(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for writable
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send commands with the spibus protocol to write enable
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_033
 *******************************************************************************************************/
static int Fls_SpiBusWriteEnable(Fls_BusHandleType *nor, boolean enable)
{
    int ret;
    Fls_BusCommandType writeEnableCmd;

    writeEnableCmd.opcode = (TRUE == enable) ? FLS_BUS_OP_WREN : FLS_BUS_OP_WRDI;
    writeEnableCmd.addrBytes = 0;
    writeEnableCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeEnableCmd.dummy = 0;

    ret = nor->host->ops->regWrite(nor, &writeEnableCmd, 0, NULL_PTR, 0);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function enable flash writing With the device locked
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusWriteEnableLocked(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for writable
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send commands with the spibus protocol to write enable With the device locked
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_033
 *******************************************************************************************************/
static int Fls_SpiBusWriteEnableLocked(Fls_BusHandleType *nor, boolean enable)
{
    int ret;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    ret = Fls_SpiBusWriteEnable(nor, enable);
    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function wait flash device for idle until timeout.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusWaitIdle(
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
 * Return value       : 0 - Flash has been idle
 *                     !0 - Timeout
 *
 * Description        : Send commands with the Spibus protocol, get the state of flash
 *                      and determine whether it is idle, If busy, wait until timeout
 * \endverbatim
 * Traceability       : SWSR_FLS_166
 *******************************************************************************************************/
static int Fls_SpiBusWaitIdle(Fls_BusHandleType *nor)
{
    int ret;
    uint8 flashStatus = 0;
    uint32 tickCount;
    uint32 parallelCount = 0;

    for (tickCount = 0; tickCount <= FLS_BUS_TIMEOUT_COUNT; tickCount++)
    {
        ret = Fls_SpiBusGetStatus(nor, &flashStatus);

        if (0 != ret)
        {
            if ((FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
                    && (parallelCount < FLS_BUS_TIMEOUT_COUNT))
            {
                parallelCount++;
                Fls_IpDelayUs(1);
                continue;
            }
            else
            {
                FLS_DEBUG("spi_nor get flash status failed, ret: %d!\n", ret);
            }
        }

        if ((0 != ret) || (0U == (flashStatus & FLS_BIT(0))))
        {
            break;
        }

        Fls_IpDelayUs(1);
    }

    if (tickCount > FLS_BUS_TIMEOUT_COUNT)
    {
        ret = FLS_TIMEOUT_ERR;
        FLS_DEBUG("wait flash idle timeout, ret = %d!\n", ret);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Perform software reset flash.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusSoftReset(
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
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send command with the Spibus protocol, execute software reset Flash
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusSoftReset(Fls_BusHandleType *nor)
{
    int ret = FLS_FAILED;
    Fls_BusCommandType resetEnableCmd;
    Fls_BusCommandType resetMemoryCmd;

    resetEnableCmd.opcode = FLS_BUS_OP_RSTEN;
    resetEnableCmd.dummy = 0;
    resetEnableCmd.addrBytes = 0;
    resetEnableCmd.instType = FLS_BUS_INST_LANS(nor->regProto);

    resetMemoryCmd.opcode = FLS_BUS_OP_RSTMEM;
    resetMemoryCmd.dummy = 0;
    resetMemoryCmd.addrBytes = 0;
    resetMemoryCmd.instType = FLS_BUS_INST_LANS(nor->regProto);

    if (0 != Fls_SpiBusRegWrite(nor, &resetEnableCmd, 0, NULL_PTR, 0))
    {
        /* Do nothing */
    }
    else if (0 != Fls_SpiBusRegWrite(nor, &resetMemoryCmd, 0, NULL_PTR, 0))
    {
        /* Do nothing */
    }
    else
    {
        ret = FLS_SUCCESS;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function match Flash based on its ID.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusReadId(
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
 * Return value       : 0 - Flash has been matched
 *                     !0 - No matching Flash
 *
 * Description        : Get flash id with the spibus protocol, And match from the support list
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_021
 *******************************************************************************************************/
static int Fls_SpiBusReadId(Fls_BusHandleType *nor)
{
    int ret;
    VAR_ALIGN(uint8 id[8], 4);
    const Fls_BusFlashInfoType *info;
    uint32 i, j;
    Fls_BusCommandType readCmd;

    readCmd.opcode = FLS_BUS_OP_RDID;
    readCmd.addrBytes = 0;

    for (i = 0; i < ARRAY_SIZE(Fls_SpibusReadIdLansList); i++)
    {
        readCmd.dummy = (uint8)(Fls_SpibusReadIdLansList[i] >> FLS_BUS_READID_DUMMY_LSB);
        readCmd.instType = FLS_BUS_INST_LANS(Fls_SpibusReadIdLansList[i]);
        nor->regProto = Fls_SpibusReadIdLansList[i] & FLS_BUS_PROTO_MASK;

        if (0U != (Fls_SpibusReadIdLansList[i] & FLS_BUS_DTR_PROTO))
        {
            nor->octalDtrEnable = 1;
            nor->dqsEnable = 1;
            nor->addrWidth = 4;
        }

        if (0U != (Fls_SpibusReadIdLansList[i] & FLS_BUS_ADDRESS_EN))
        {
            readCmd.addrBytes = nor->addrWidth;
        }

        FLS_DEBUG("octalDtrEnable: %d, addrBytes = %d, dummy = %d, instType = %d, proto = %x\n",
                  nor->octalDtrEnable, readCmd.addrBytes, readCmd.dummy, readCmd.instType,
                  nor->regProto);

        ret = Fls_SpiBusRegRead(nor, &readCmd, 0, id, 4);

        if (FLS_SUCCESS == ret)
        {
            FLS_DEBUG("norflash id0: %x, id1: %x, id2: %x\n", id[0], id[1], id[2]);

            for (j = 0; j < ARRAY_SIZE(Fls_SpiBusIds); j++)
            {
                info = &Fls_SpiBusIds[j];

                if (0U == Fls_MemCompare((void *)(Fls_PointerType)(info->flashId),
                                         (void *)(Fls_PointerType)(id), 2))
                {
                    (void) Fls_MemCopy((void *)(Fls_PointerType)(&nor->info),
                                       (void *)(Fls_PointerType)info, sizeof(Fls_BusFlashInfoType));
                    nor->info.size = ((uint32)1U) << id[FLS_BUS_ID_CAPACITY_OFFSET];
                    break;
                }
            }

            if (j == ARRAY_SIZE(Fls_SpiBusIds))
            {
                ret = FLS_NO_MATCH_ID;
            }
            else
            {
                break;
            }
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash to enter octal-spi mode.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusOctalDtrEnable(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for octal-spi mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enter octal-spi mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_SpiBusOctalDtrEnable(Fls_BusHandleType *nor, boolean enable)
{
    int ret = FLS_SUCCESS;

    if ((NULL_PTR != nor->info.octalDtrEnable) &&
            (FLS_BUS_PROTO_DTR(nor->info.readProto) == FLS_BUS_PROTO_8_8_8_DTR) &&
            (FLS_BUS_PROTO_DTR(nor->info.writeProto) == FLS_BUS_PROTO_8_8_8_DTR))
    {

        ret = nor->info.octalDtrEnable(nor, enable, enable);

        if (0 != ret)
        {
            /* Do nothing */
        }
        else if (TRUE == enable)
        {
            nor->octalDtrEnable = 1;
            nor->dqsEnable = 1;
            nor->regProto = FLS_BUS_PROTO_8_8_8_DTR;
            nor->addrWidth = 4;
        }
        else
        {
            nor->octalDtrEnable = 0;
            nor->dqsEnable = 0;
            nor->regProto = FLS_BUS_PROTO_1_1_1;
            nor->addrWidth = 3;
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash to enable quad mode.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusQuadEnable(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for quad mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enable quad mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_SpiBusQuadEnable(Fls_BusHandleType *nor, boolean enable)
{
    int ret = FLS_SUCCESS;

    if (NULL_PTR != nor->info.quadEnable)
    {
        if ((FLS_BUS_QUAD_LANS == FLS_BUS_DATA_LANS(nor->info.readProto)) ||
                (FLS_BUS_QUAD_LANS == FLS_BUS_DATA_LANS(nor->info.writeProto)))
        {
            ret = nor->info.quadEnable(nor, enable);
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash to enter quad-spi mode.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusEnterQuad(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for quad-spi mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enter quad-spi mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_SpiBusEnterQuad(Fls_BusHandleType *nor, boolean enable)
{
    int ret = FLS_SUCCESS;

    if (NULL_PTR != nor->info.enterQuad)
    {
        if ((FLS_BUS_PROTO(nor->info.readProto) == FLS_BUS_PROTO_4_4_4) ||
                (FLS_BUS_PROTO(nor->info.writeProto) == FLS_BUS_PROTO_4_4_4))
        {
            ret = nor->info.enterQuad(nor, enable);

            if (FLS_SUCCESS == ret)
            {
                nor->regProto = (TRUE == enable) ? FLS_BUS_PROTO_4_4_4 : FLS_BUS_PROTO_1_1_1;
            }
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash to enter four-byte address mode.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusSetAddressWidth(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for four-address mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enter four-byte address mode
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_SpiBusSetAddressWidth(Fls_BusHandleType *nor, boolean enable)
{
    int ret = FLS_SUCCESS;

    if ((NULL_PTR != nor->info.setAddressWidth) && (nor->info.size > FLS_BUS_SIZE_16M))
    {
        ret = nor->info.setAddressWidth(nor, enable);

        if (FLS_SUCCESS == ret)
        {
            nor->addrWidth = (TRUE == enable) ? 4U : 3U;
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function execute the training process for Flash.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusTraining(
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
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Execute the training process for Flash
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusTraining(Fls_BusHandleType *nor)
{
    int ret = FLS_SUCCESS;
    uint32 trainingLength = FLS_BUS_TRAINING_BUF_SIZE;
    Fls_AddressType trainingAddr;
    VAR_ALIGN(uint8 trainingBuffer[FLS_BUS_TRAINING_BUF_SIZE], 4U) = {0};

    if (NULL_PTR != nor->host->ops->training)
    {
        trainingAddr = nor->info.sectorSize;

        if (0 != Fls_SpiBusRead(nor, trainingAddr,  trainingBuffer, trainingLength))
        {
            ret = FLS_FAILED;
        }
        else if (0u != Fls_MemCompare((const void *)Fls_BusTrainingPattern,
                                      (void *)(Fls_PointerType)trainingBuffer, trainingLength))
        {
            if (FLS_SUCCESS != Fls_SpiBusErase(nor, trainingAddr, nor->info.sectorSize))
            {
                ret = FLS_FAILED;
            }

#ifdef FLS_ASYNC_MODE_EN
            else if (FLS_SUCCESS != Fls_SpiBusWaitIdle(nor))
            {
                ret = FLS_TIMEOUT_ERR;
            }

#endif /* #ifdef FLS_ASYNC_MODE_EN */
            else if (FLS_SUCCESS != Fls_SpiBusWrite(nor, trainingAddr,  Fls_BusTrainingPattern, trainingLength))
            {
                ret = FLS_FAILED;
            }

#ifdef FLS_ASYNC_MODE_EN
            else if (FLS_SUCCESS != Fls_SpiBusWaitIdle(nor))
            {
                ret = FLS_TIMEOUT_ERR;
            }

#endif /* #ifdef FLS_ASYNC_MODE_EN */
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }

        if (FLS_SUCCESS == ret)
        {
            if (NULL_PTR != nor->host->clkOps)
            {
                nor->host->clkOps->setClkRate(nor->host->id, nor->host->refClkHz);
                FLS_DEBUG("spinor host clock rate is %u!\n",
                          nor->host->clkOps->getClkRate(nor->host->id));
            }

            ret = nor->host->ops->training(nor, trainingAddr,  trainingBuffer,
                                           Fls_BusTrainingPattern, trainingLength);
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Initialize Spibus.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusInit(
 *                          Fls_BusHandleType *nor, Fls_IpHostType *host, const Fls_BusConfigType *config)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      host - Pointer to the controller
 *                      config - Pointer to the configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Initialize Spibus based on configuration parameters
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusInit(Fls_BusHandleType *nor, Fls_IpHostType *host,
                          const Fls_BusConfigType *config)
{
    int ret;

    nor->id = config->id;
    nor->baudrate = config->baudrate;
    nor->xferMode = config->xferMode;
    nor->devMode = config->devMode;
    nor->host = host;
    nor->swReset = config->swReset;
    nor->rfdEnable = config->rfdEnable;

    nor->addrWidth = 3;
    nor->octalDtrEnable = 0;
    nor->dqsEnable = 0;

    ret = Fls_SpiBusReadId(nor);

    if (FLS_SUCCESS != ret)
    {
        /* Do nothing */
    }
    else
    {
        if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
        {
            nor->info.sectorSize *= 2u;
            nor->info.size *= 2u;
        }

        FLS_DEBUG("flash size: %llx\n", nor->info.size);

        if (TRUE == nor->swReset)
        {
            (void) Fls_SpiBusSoftReset(nor);
            /* more than 200 ms */
            Fls_IpDelayUs(500);
            nor->octalDtrEnable = 0;
            nor->regProto = FLS_BUS_PROTO_1_1_1;
            nor->addrWidth = 3;
            nor->dqsEnable = 0;
        }

        /* set dummy ... */
        if (NULL_PTR != nor->info.defaultInit)
        {
            (void) nor->info.defaultInit(nor);
        }

        if (0 != Fls_SpiBusSetAddressWidth(nor, TRUE))  /* if more than 16MB, set 4 byte mode */
        {
            ret = FLS_FAILED;
        }
        else if (0 != Fls_SpiBusOctalDtrEnable(nor, TRUE))
        {
            ret = FLS_FAILED;
        }
        else if (0 != Fls_SpiBusQuadEnable(nor, TRUE))
        {
            ret = FLS_FAILED;
        }
        else if (0 != Fls_SpiBusEnterQuad(nor, TRUE))
        {
            ret = FLS_FAILED;
        }
        else if (0 != Fls_SpiBusTraining(nor))
        {
            ret = FLS_FAILED;
        }
        else
        {
            /* Do nothing */
        }

#ifdef FLS_RFD_ENABLE_CNT

        if ((FLS_SUCCESS == ret) && (TRUE == nor->rfdEnable))
        {
            ret = Fls_IpEnableRfd(nor);
        }

#endif /* #ifdef FLS_RFD_ENABLE_CNT */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Read Flash memory data.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusRead(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
 *                          Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      buf - Read buffer, alloc by user
 *                      size - Read size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Read Flash memory data with the Spibus protocol
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusRead(Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
                          Fls_LengthType size)
{
    int ret;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_READ);
    Fls_BusSetupXfer(nor, FLS_BUS_OPS_READ, addr, buf, NULL_PTR, size);
    ret = nor->host->ops->read(nor, addr, buf, size);

    if (0 != ret)
    {
        Fls_BusXferError(nor);
    }
    else
    {
        Fls_BusXferComplete(nor);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Write to flash.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusWrite(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, const uint8 *buf,
 *                          Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      buf - Write buffer, alloc by user
 *                      size - Write size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Write to flash with the Spibus protocol
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusWrite(Fls_BusHandleType *nor, Fls_AddressType addr, const uint8 *buf,
                           Fls_LengthType size)
{
    int ret;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_WRITE);
    Fls_BusSetupXfer(nor, FLS_BUS_OPS_WRITE, addr, NULL_PTR, buf, size);
    ret = nor->host->ops->write(nor, addr, buf, size);

    if (0 != ret)
    {
        Fls_BusXferError(nor);
    }
    else
    {
        Fls_BusXferComplete(nor);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Erase the sector of flash.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusErase(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      size - Erase size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Erase the sector of flash with the Spibus protocol
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusErase(Fls_BusHandleType *nor, Fls_AddressType addr, Fls_LengthType size)
{
    int ret = FLS_SUCCESS;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_ERASE);
    Fls_BusSetupXfer(nor, FLS_BUS_OPS_ERASE, addr, NULL_PTR, NULL_PTR, size);

    while (nor->xferInfo.size > 0U)
    {
        ret = nor->host->ops->erase(nor, nor->xferInfo.addr);

        if (0 != ret)
        {
            break;
        }

#ifndef FLS_ASYNC_MODE_EN
        /* wait for flash idle */
        ret = Fls_SpiBusWaitIdle(nor);

        if (0 != ret)
        {
            break;
        }

#endif /* #ifndef FLS_ASYNC_MODE_EN */

        nor->xferInfo.addr += nor->info.sectorSize;
        nor->xferInfo.size -= nor->info.sectorSize;
    }

    if (0 != ret)
    {
        Fls_BusXferError(nor);
    }
    else
    {
        Fls_BusXferComplete(nor);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Cancel current operation.
 *
 * \verbatim
 * Syntax             : int Fls_SpiBusCancel(
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
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Cancel current operation with the Spibus protocol
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_SpiBusCancel(Fls_BusHandleType *nor)
{
    int ret = FLS_SUCCESS;

    if (NULL_PTR != nor->host->ops->cancel)
    {
        ret = nor->host->ops->cancel(nor);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Reverse initialization of Flash.
 *
 * \verbatim
 * Syntax             : void Fls_SpiBusDeinit(
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
 * Description        : Reverse initialization of Flash
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_SpiBusDeinit(Fls_BusHandleType *nor)
{
    Fls_IpDeinit(nor);
}

/** *****************************************************************************************************
 * \brief This function Configure flash to enter four-byte address mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusGeneralSetAddressWidth(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for four-address mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send command with spubus protocol, And Configure flash to
 *                      enter four-byte address mode
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusGeneralSetAddressWidth(Fls_BusHandleType *nor,
        boolean enable)
{
    int ret;
    Fls_BusCommandType writeCmd;

    writeCmd.opcode = (TRUE == enable) ? FLS_BUS_OP_EN4B : FLS_BUS_OP_EX4B;
    writeCmd.addrBytes = 0;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    ret = Fls_SpiBusRegWrite(nor, &writeCmd, 0, NULL_PTR, 0);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Perform special initialization for flash produced by Miron.
 *
 * \verbatim
 * Syntax             : int Fls_BusMironDefaultInit(
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
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Perform special initialization of Flash model Miron
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusMironDefaultInit(Fls_BusHandleType *nor)
{
    int ret = FLS_SUCCESS;
    uint8 size = (FLS_BUS_INST_LANS(nor->regProto) == FLS_BUS_OCTAL_LANS) ? 2U : 1U;
    VAR_ALIGN(uint8 data[2], 4);
    Fls_BusCommandType writeCmd;
    Fls_BusCommandType readCmd;

    writeCmd.opcode = FLS_BUS_OP_WRVR;
    writeCmd.addrBytes = nor->addrWidth;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;
    readCmd.opcode = FLS_BUS_OP_RDVR;
    readCmd.addrBytes = nor->addrWidth;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    readCmd.dummy = 8;

    (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);

    data[0] = nor->info.readDummy;

    if (FLS_SUCCESS != Fls_SpiBusRegWrite(nor, &writeCmd, 1, data, size))
    {
        ret = FLS_FAILED;
    }
    else if (FLS_SUCCESS != Fls_SpiBusRegRead(nor, &readCmd, 1, data, size))
    {
        ret = FLS_FAILED;
    }
    else if (data[0] != nor->info.readDummy)
    {
        ret = FLS_FAILED;
        FLS_DEBUG("dummy: %d, %d\n", nor->info.readDummy, data[0]);
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Perform special initialization for flash produced by ISSI.
 *
 * \verbatim
 * Syntax             : int Fls_BusIssiDefaultInit(
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
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Perform special initialization of Flash model Issi
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusIssiDefaultInit(Fls_BusHandleType *nor)
{
    int ret;
    const Fls_ContextType *pCtx = ((Fls_ContextType *)nor->parent);
    VAR_ALIGN(uint8 data[2], 4);
    Fls_BusCommandType writeCmd;

    writeCmd.opcode = FLS_BUS_OP_WRPR;
    writeCmd.addrBytes = 0;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);

    if (pCtx->controllerConfig->flashSpecialFlag == FLS_SPECIAL_IS25LP064A)
    {
        /* Fix up for IS25LP064A. Refer to descriptions in part.h */
        nor->info.readDummy = 10;
        data[0] = 0x3U << 3;
    }
    else
    {
        data[0] = nor->info.readDummy << 3;
    }

    ret = Fls_SpiBusRegWrite(nor, &writeCmd, 1, data,
                             (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash produced by Miron to enter octal-spi mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusMironOctalDtrEnable(
 *                          Fls_BusHandleType *nor, boolean opiEnable, boolean dqsEnable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      opiEnable - Switch for octal-spi mode
 *                      dqsEnable - Switch for dqs mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enter octal-spi mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusMironOctalDtrEnable(Fls_BusHandleType *nor, boolean opiEnable, boolean dqsEnable)
{
    int ret;
    VAR_ALIGN(uint8 data[3], 4);
    Fls_BusCommandType writeCmd, readCmd;

    writeCmd.opcode = FLS_BUS_OP_WRVR;
    writeCmd.addrBytes = nor->addrWidth;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;
    readCmd.opcode = FLS_BUS_OP_RDVR;
    readCmd.addrBytes = 4;
    readCmd.instType = 3;
    readCmd.dummy = 8;

    (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);

    data[0] = (TRUE == opiEnable) ?
              ((TRUE == dqsEnable) ? FLS_BUS_OCTAL_DQS_MIRION : FLS_BUS_OCTAL_NON_DQS_MIRION) : 0xffU;
    data[2] = data[0];
    ret = Fls_SpiBusRegWrite(nor, &writeCmd, 0, data,
                             (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U);

    if (FLS_SUCCESS == ret)
    {
        nor->octalDtrEnable = opiEnable;
        nor->dqsEnable = dqsEnable;

        ret = Fls_SpiBusRegRead(nor, &readCmd, 0, data, 2);

        if ((FLS_SUCCESS == ret) && (data[0] != data[2]))
        {
            FLS_DEBUG("I/O mode: %x, %x, ret = %d\n", data[0], data[1], ret);
            ret = FLS_FAILED;
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash produced by ISSI to enable quad mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusIssiQuadEnable(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for quad mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enable quad mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusIssiQuadEnable(Fls_BusHandleType *nor, boolean enable)
{
    int ret;
    VAR_ALIGN(uint8 data[2], 4);
    Fls_BusCommandType readCmd, writeCmd;

    readCmd.opcode = FLS_BUS_OP_RDSR;
    readCmd.addrBytes = 0;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    readCmd.dummy = 0;
    writeCmd.opcode = FLS_BUS_OP_WRSR;
    writeCmd.addrBytes = 0;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    (void) enable;

    ret = Fls_SpiBusRegRead(nor, &readCmd, 0, data,
                            (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U);

    if (FLS_SUCCESS != ret)
    {
        /* The parallel mode register is different and set to the default value */
        if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
        {
            data[0] = 0;
            data[1] = 0;
            ret = FLS_SUCCESS;
        }
    }

    if ((FLS_SUCCESS == ret) && (0U == (data[0] & (1u << 6))))
    {
        (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);

        data[0] |= (1u << 6);
        ret = Fls_SpiBusRegWrite(nor, &writeCmd, 0, data,
                                 (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U);

        if (FLS_SUCCESS == ret)
        {
            ret = Fls_BusWaitIdle(nor);
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash produced by ISSI to enter quad-spi mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusIssiEnterQuad(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for quad-spi mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enter quad-spi mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusIssiEnterQuad(Fls_BusHandleType *nor, boolean enable)
{
    int ret;
    Fls_BusCommandType q_cmd;

    q_cmd.opcode = (TRUE == enable) ? FLS_BUS_OP_ISSI_QPI_EN : FLS_BUS_OP_ISSI_QPI_EX;
    q_cmd.addrBytes = 0;
    q_cmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    q_cmd.dummy = 0;

    ret = Fls_SpiBusRegWrite(nor, &q_cmd, 0, NULL_PTR, 0);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash produced by GIGA to enter quad-spi mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusGigaEnterQuad(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for quad-spi mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enter quad-spi mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusGigaEnterQuad(Fls_BusHandleType *nor, boolean enable)
{
    int ret;
    Fls_BusCommandType cmd;

    cmd.opcode = (TRUE == enable) ? FLS_BUS_OP_GIGA_QPI_EN : FLS_BUS_OP_GIGA_QPI_EX;
    cmd.addrBytes = 0;
    cmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    cmd.dummy = 0;

    ret = Fls_SpiBusRegWrite(nor, &cmd, 0, NULL_PTR, 0);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Perform special initialization for flash produced by GIGA.
 *
 * \verbatim
 * Syntax             : int Fls_BusGigaDefaultInit(
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
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Perform special initialization of Flash model GIGA
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusGigaDefaultInit(Fls_BusHandleType *nor)
{
    int ret = FLS_SUCCESS;
    VAR_ALIGN(uint8 data[2], 4);
    Fls_LengthType size = (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U;

    Fls_BusCommandType writeCmd, readCmd;

    writeCmd.opcode = FLS_BUS_OP_WRVR;
    writeCmd.addrBytes = nor->addrWidth;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;
    readCmd.opcode = FLS_BUS_OP_RDVR;
    readCmd.addrBytes = nor->addrWidth;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    readCmd.dummy = 8;

    (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);
    data[0] = nor->info.readDummy;

    if (FLS_SUCCESS != Fls_SpiBusRegWrite(nor, &writeCmd, 1, data, size))
    {
        ret = FLS_FAILED;
    }
    else if (FLS_SUCCESS != Fls_SpiBusRegRead(nor, &readCmd, 1, data, size))
    {
        ret = FLS_FAILED;
    }
    else if (data[0] != nor->info.readDummy)
    {
        FLS_DEBUG("dummy: %d, %d\n", nor->info.readDummy, data[0]);
        ret = FLS_FAILED;
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash produced by GIGA to enable quad mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusGigaQuadEnable(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for quad-spi mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enable quad mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusGigaQuadEnable(Fls_BusHandleType *nor, boolean enable)
{
    int ret;
    VAR_ALIGN(uint8 data[2], 4);
    VAR_ALIGN(uint8 rdata[2], 4);
    Fls_LengthType size = (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U;
    Fls_BusCommandType readCmd, writeCmd;

    readCmd.opcode = FLS_BUS_OP_GIGA_RDSR;
    readCmd.addrBytes = 0;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    readCmd.dummy = 0;

    writeCmd.opcode = FLS_BUS_OP_GIGA_WRSR;
    writeCmd.addrBytes = 0;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    (void) enable;

    ret = Fls_SpiBusRegRead(nor, &readCmd, 0, data, size);


    if (FLS_SUCCESS != ret)
    {
        // The parallel mode register is different and set to the default value
        if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
        {
            data[0] = 0;
            data[1] = 0;
            ret = FLS_SUCCESS;
        }
    }

    if ((FLS_SUCCESS == ret) && (0U == (data[0] & (1u << 1))))
    {
        (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);
        data[0] |= (1u << 1);

        if (FLS_SUCCESS != Fls_SpiBusRegWrite(nor, &writeCmd, 0, data, size))
        {
            ret = FLS_FAILED;
        }
        else if (FLS_SUCCESS != Fls_SpiBusRegRead(nor, &readCmd, 0, rdata, size))
        {
            ret = FLS_FAILED;
        }
        else if (0U == (rdata[0] & (1u << 1)))
        {
            FLS_DEBUG("I/O mode: %x, %x, ret = %d\n", data[0], data[1], ret);
            ret = FLS_FAILED;
        }
        else
        {
            /* Do nothing */
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure Special flash Models produced by GIGA to enable quad mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusGiga25qQuadEnable(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for enter quad mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enable quad mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusGiga25qQuadEnable(Fls_BusHandleType *nor, boolean enable)
{
    int ret;
    VAR_ALIGN(uint8 data[2], 4);
    VAR_ALIGN(uint8 rdata[2], 4);
    Fls_LengthType size = (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U;
    Fls_LengthType writeSize = size;
    Fls_BusCommandType readCmd, writeCmd;

    readCmd.opcode = FLS_BUS_OP_GIGA_RDSR;
    readCmd.addrBytes = 0;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    readCmd.dummy = 0;

    writeCmd.opcode = FLS_BUS_OP_GIGA_WRSR;
    writeCmd.addrBytes = 0;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    (void)enable;

    ret = Fls_SpiBusRegRead(nor, &readCmd, 0, rdata, size);

    if (FLS_SUCCESS != ret)
    {
        /* The parallel mode register is different and set to the default value */
        if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
        {
            rdata[0] = 0;
            rdata[1] = 0;
            ret = FLS_SUCCESS;
        }
    }

    if ((FLS_SUCCESS == ret) && (0U == (rdata[0] & (1u << 1))))
    {
        if (nor->info.size == 0x80000U)
        {
            writeCmd.opcode = FLS_BUS_OP_WRSR;
            writeSize = 2;
            ret = Fls_SpiBusGetStatus(nor, &data[0]);
            data[1] = rdata[0] | (1u << 1);
        }
        else
        {
            data[0] = rdata[0] | (1u << 1);
        }

        if (FLS_SUCCESS != Fls_SpiBusWriteEnableLocked(nor, TRUE))
        {
            ret = FLS_FAILED;
        }
        else if (FLS_SUCCESS != Fls_SpiBusRegWrite(nor, &writeCmd, 0, data, writeSize))
        {
            ret = FLS_FAILED;
        }
        else if (FLS_SUCCESS != Fls_SpiBusWaitIdle(nor))
        {
            ret = FLS_FAILED;
        }
        else if (FLS_SUCCESS != Fls_SpiBusRegRead(nor, &readCmd, 0, rdata, size))
        {
            ret = FLS_FAILED;
        }
        else if (0U == (rdata[0] & (1u << 1)))
        {
            FLS_DEBUG("I/O mode: %x, %x, ret = %d\n", rdata[0], rdata[1], ret);
            ret = FLS_FAILED;
        }
        else
        {
            /* Do nothing */
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure the protection area for Flash produced by GIGA.
 *
 * \verbatim
 * Syntax             : int Fls_BusGigaSetProtectArea(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Starting physical address for protection
 *                      size - The size of the protected area
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure the protection area for Flash produced by GIGA.
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168 SWSR_FLS_170
 *******************************************************************************************************/
static int Fls_BusGigaSetProtectArea(Fls_BusHandleType *nor, Fls_AddressType addr,
                                     Fls_LengthType size)
{
    int ret = FLS_SUCCESS;
    uint32 blockNum = size / FLS_BUS_SECTOR_64K_SIZE;
    uint8 bpValue = 0;
    uint8 statusMask = 0x3FU << 2;
    VAR_ALIGN(uint8 data[2], 4);
    Fls_LengthType length = (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U;
    Fls_BusCommandType writeCmd;

    writeCmd.opcode = FLS_BUS_OP_WRSR;
    writeCmd.addrBytes = 0;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    if (!FLS_IS_ALIGNED(size, FLS_BUS_SECTOR_64K_SIZE))
    {
        FLS_DEBUG("size is not ALIGNED 64KB\n");
        ret = FLS_FAILED;
    }
    else if (0U != (blockNum & (blockNum - 1U)))
    {
        FLS_DEBUG("blockNum is not 2^n (block size=64KB)\n");
        ret = FLS_FAILED;
    }
    else
    {
        while (blockNum >= 1u)
        {
            blockNum >>= 1u;
            bpValue++;
        }

        if (0U == addr)
        {
            bpValue |= 0x10U;  /* Lower BP4=1 */
        }
        else if ((addr + size) == nor->info.size)
        {
            bpValue &= (~0x10U);  /* Upper BP4=0 */
        }
        else
        {
            FLS_DEBUG("%s do not support this protected area(%x %x)\n",
                      nor->info.name, addr, size);
            ret = FLS_FAILED;
        }

        data[0] = ((bpValue << 2) & statusMask);
    }

    if (FLS_SUCCESS != ret)
    {
        /* Do nothing */
    }
    else if (FLS_SUCCESS != Fls_SpiBusWriteEnableLocked(nor, TRUE))
    {
        ret = FLS_FAILED;
    }
    else if (FLS_SUCCESS != Fls_SpiBusRegWrite(nor, &writeCmd, 0, data, length))
    {
        ret = FLS_FAILED;
    }
    else if (FLS_SUCCESS != Fls_SpiBusGetStatus(nor, &data[1]))
    {
        ret = FLS_FAILED;
    }
    else if ((data[0] & statusMask) != (data[1] & statusMask))
    {
        FLS_DEBUG("Set flash register error(%x %x)\n", data[0], data[1]);
        ret = FLS_FAILED;
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Perform special initialization for flash produced by Cypress.
 *
 * \verbatim
 * Syntax             : int Fls_BusCypressDefaultInit(
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
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Perform special initialization of Flash model Cypress
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusCypressDefaultInit(Fls_BusHandleType *nor)
{
    int ret;
    VAR_ALIGN(uint8 data[2], 4U) = {0};
    Fls_LengthType size = (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U;
    /* set erase 256kb */
    Fls_BusCommandType readCmd, writeCmd;

    readCmd.opcode = FLS_BUS_OP_RDAR;
    readCmd.addrBytes = nor->addrWidth;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    readCmd.dummy = 8;

    writeCmd.opcode = FLS_BUS_OP_WRAR;
    writeCmd.addrBytes = nor->addrWidth;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    ret = Fls_SpiBusRegRead(nor, &readCmd, 0x800004U, data, size);

    if ((FLS_SUCCESS == ret) && (0U == (data[0] & FLS_BIT(3))))
    {
        (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);

        data[0] |= (1U << 3);

        if (FLS_SUCCESS != Fls_SpiBusRegWrite(nor, &writeCmd, 0x04U, data, size))
        {
            ret = FLS_FAILED;
        }
        else if (FLS_SUCCESS != Fls_SpiBusWaitIdle(nor))
        {
            ret = FLS_FAILED;
        }
        else if (FLS_SUCCESS != Fls_SpiBusRegRead(nor, &readCmd, 0x800004U, data, size))
        {
            ret = FLS_FAILED;
        }
        else if (0U == (data[0] & FLS_BIT(3)))
        {
            ret = FLS_FAILED;
            FLS_DEBUG("erase 256kb failed, read data = 0x%x\r\n", data[0]);
        }
        else
        {
            /* Do nothing */
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash produced by Cypress to enter four-byte address mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusCypressSetAddressWidth(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for four-address mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send command with spubus protocol, And Configure flash to
 *                      enter four-byte address mode
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusCypressSetAddressWidth(Fls_BusHandleType *nor, boolean enable)
{
    int ret;
    Fls_BusCommandType writeCmd;

    writeCmd.opcode = (TRUE == enable) ? FLS_BUS_OP_EN4B : FLS_BUS_OP_EX4B_CYCESS;
    writeCmd.addrBytes = 0;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    ret = Fls_SpiBusRegWrite(nor, &writeCmd, 0, NULL_PTR, 0);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure flash produced by Cypress to enter octal-spi mode.
 *
 * \verbatim
 * Syntax             : int Fls_BusCypressOctalDtrEnable(
 *                          Fls_BusHandleType *nor, boolean opiEnable, boolean dqsEnable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      opiEnable - Switch for octal-spi mode
 *                      dqsEnable - Switch for dqs mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure flash to enter octal-spi mode by Calling functions
 *                      registered in the Flash support list
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_BusCypressOctalDtrEnable(Fls_BusHandleType *nor, boolean opiEnable,
                                        boolean dqsEnable)
{
    int ret;
    VAR_ALIGN(uint8 data[3], 4) = {0};
    Fls_LengthType size = (FLS_BUS_OCTAL_LANS == FLS_BUS_INST_LANS(nor->regProto)) ? 2U : 1U;
    Fls_BusCommandType readCmd, writeCmd;

    readCmd.opcode = FLS_BUS_OP_RDAR;
    readCmd.addrBytes = nor->addrWidth;
    readCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    readCmd.dummy = 8;

    writeCmd.opcode = FLS_BUS_OP_WRAR;
    writeCmd.addrBytes = nor->addrWidth;
    writeCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    writeCmd.dummy = 0;

    (void) dqsEnable; /* Do not care about this parameter */

    ret = Fls_SpiBusRegRead(nor, &readCmd, 0x800006U, data, size);

    if (FLS_SUCCESS == ret)
    {
        (void) Fls_SpiBusWriteEnableLocked(nor, TRUE);

        if (TRUE == opiEnable)
        {
            data[0] |= 0x03U;
        }
        else
        {
            data[0] = 0;
        }

        data[2] = data[0];
        ret = Fls_SpiBusRegWrite(nor, &writeCmd, 0x800006U, data, size);

        if ((FLS_SUCCESS == ret) && (TRUE == opiEnable))
        {
            nor->octalDtrEnable = TRUE;
            nor->dqsEnable = TRUE;
            readCmd.addrBytes = 4;
            readCmd.instType = 3;

            if (FLS_SUCCESS != Fls_SpiBusRegRead(nor, &readCmd, 0x800006U, data, 2))
            {
                ret = FLS_FAILED;
            }
            else if ((data[0] & 0x3U) != (data[2] & 0x3U))
            {
                ret = FLS_FAILED;
            }
            else
            {
                FLS_DEBUG("IO mode set sucessful\n");
            }
        }
    }

    return ret;
}


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#endif /* #ifdef FLS_SPIBUS_FLASH_CNT */

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

/* End of file */
