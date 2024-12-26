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
 * \file     Fls_Hyperbus.c                                                                            *
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

#include <Compiler.h>

#include "Fls.h"
#include "Fls_Cfg.h"
#include "Mcal.h"

#ifdef FLS_HYPERBUS_FLASH_CNT

/* PRQA S 0306,0314,0316,0326,2755,3218 EOF */

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  Read JEDEC ID  */
#define FLS_BUS_OP_RDID (0x9FU)
/** \brief  Read any register  */
#define FLS_BUS_OP_RDAR     (0x65U)
/** \brief  Write any register */
#define FLS_BUS_OP_WRAR     (0x71U)
/** \brief  Write enable */
#define FLS_BUS_OP_WREN     (0x06U)
/** \brief  Erase opcode */
#define FLS_BUS_OP_ERASE    (0x30U)
/** \brief  Exit address space overlay mode */
#define FLS_BUS_OP_ASO_EXIT (0xF0U)
/** \brief  SFD register address */
#define FLS_BUS_SFD_ID_0 (0x800U)
#define FLS_BUS_SFD_ID_1 (0x801U)
#define FLS_BUS_SFD_ID_2 (0x802U)
/** \brief  CFI register address */
#define FLS_BUS_CFI_ID_0 (0x00U)
#define FLS_BUS_CFI_ID_1 (0x01U)
#define FLS_BUS_CFI_ID_2 (0x27U)
/** \brief  Hyperram default size in bytes */
#define FLS_BUS_HYPER_RAM_DEFAULT_SIZE (0x8000000U)
/** \brief  Hyperram default dummy cycles */
#define FLS_BUS_HYPER_RAM_DUMMY (5U)

#define PROTO(_opcode, _dq) \
        (((uint32)(_opcode) << FLS_BUS_OPCODE_PROTO_LSB) | (_dq))
#define ID_PROTO(dummy, _dq) \
        (((uint32)(dummy) << FLS_BUS_READID_DUMMY_LSB) | (_dq))

#define FLS_BUS_ID_CAPACITY_OFFSET 4

#define CONFIG_HYPERBUS_INCREMENTAL_PROGRAM_EN


/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static int Fls_HyperBusS26DefaultInit(Fls_BusHandleType *nor);

static int Fls_HyperBusWaitIdle(Fls_BusHandleType *nor);
static int Fls_HyperBusWriteEnable(Fls_BusHandleType *nor, boolean enable);
static int Fls_HyperBusInit(Fls_BusHandleType *nor, Fls_IpHostType *host,
                            const Fls_BusConfigType *config);
static void Fls_HyperBusDeinit(Fls_BusHandleType *nor);
static int Fls_HyperBusRead(Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
                            Fls_LengthType size);
static int Fls_HyperBusWrite(Fls_BusHandleType *nor, Fls_AddressType addr, const uint8 *buf,
                             Fls_LengthType size);
static int Fls_HyperBusErase(Fls_BusHandleType *nor, Fls_AddressType addr, Fls_LengthType size);
static int Fls_HyperBusGetBusyStatus(Fls_BusHandleType *nor);
static int Fls_HyperBusCancel(Fls_BusHandleType *nor);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#define FLS_START_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

static VAR_ALIGN(uint8 const Fls_BusTrainingPattern[FLS_BUS_TRAINING_BUF_SIZE],
                 FLS_IP_ARCH_CACHE_LINE) =
{
    0x44, 0x1c, 0x39, 0x05, 0xd3, 0x7a, 0x3c, 0x04,
    0x16, 0x42, 0x0c, 0x8b, 0x7d, 0x12, 0x89, 0xa2,
    0xb8, 0xb1, 0xf7, 0xe8, 0xb7, 0x49, 0xca, 0x1c,
    0xaa, 0x9b, 0xf2, 0x7e, 0x01, 0x97, 0x60, 0x8c
};

static const Fls_BusFlashInfoType Fls_HyperBusIds[] =
{
    {
        .name = "default",
        /* The 0x00, 0xff, 0x00, 0xff, is a dummy device ID */
        .flashId = {0x00, 0xff, 0x00, 0xff, 0, 0},
        .readProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .readDummy = 16,
        .writeDummy = 0,
        .pageSize = 256,
        .size = 0x200000u,
    },
    {
        .name = "hyperram",
        /* The 0x00, 0xff, 0x00, 0xff, is a dummy device ID */
        .flashId = {0x00, 0xff, 0x00, 0xff, 0, 0},
        .readProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .readDummy = 5,
        .writeDummy = 5,
        .size = FLS_BUS_HYPER_RAM_DEFAULT_SIZE,
    },
    /* cypress */
    {
        .name = "s26hs",
        .flashId = {0x34, 0x00, 0x7B, 0x00, 0, 0},
        .readProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .sectorSize = FLS_BUS_SECTOR_256K_SIZE,
        .sectorType = FLS_BUS_SECTOR_256KB,
        .readDummy = 16,
        .writeDummy = 0,
        .pageSize = 256,
        .defaultInit = Fls_HyperBusS26DefaultInit,
    },
    {
        .name = "s26hl",
        .flashId = {0x34, 0x00, 0x6a, 0x00, 0, 0},
        .readProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .sectorSize = FLS_BUS_SECTOR_256K_SIZE,
        .sectorType = FLS_BUS_SECTOR_256KB,
        .readDummy = 16,
        .writeDummy = 0,
        .pageSize = 256,
        .defaultInit = Fls_HyperBusS26DefaultInit,
    },
    {
        .name = "s26ks",
        .flashId = {0x01, 0x00, 0x7E, 0x00, 0, 0},
        .readProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .writeProto = PROTO(0u, FLS_BUS_PROTO_8_8_8_DTR),
        .sectorSize = FLS_BUS_SECTOR_256K_SIZE,
        .sectorType = FLS_BUS_SECTOR_256KB,
        .readDummy = 16,
        .writeDummy = 0,
        .pageSize = 256,
    },
};

#define FLS_STOP_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static Fls_HyperbusCommandType Fls_HyperBusReadStatus =
{
    .name = "read status",
    .isRead = TRUE,
    .num = 1,
    .ca = {{0x555, 0x70}, {0}, {0}, {0}, {0}, {0}},
};

static Fls_HyperbusCommandType Fls_HyperBusReadVolReg2 =
{
    .name = "read vol reg2",
    .isRead = TRUE,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0xC9}, {0}, {0}, {0}},
};

static Fls_HyperbusCommandType Fls_HyperBusWriteVolReg2 =
{
    .name = "write vol reg2",
    .isRead = FALSE,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x3A}, {0}, {0}, {0}},
};

static Fls_HyperbusCommandType Fls_HyperBusReadDevId =
{
    .name = "read device id",
    .isRead = TRUE,
    .num = 4,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x90}, {0x555, 0x98}, {0}, {0}},
};

static Fls_HyperbusCommandType Fls_HyperBusEraseSector =
{
    .name = "sector_erase",
    .isRead = FALSE,
    .num = 5,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x80}, {0x555, 0xAA}, {0x2AA, 0x55}, {0}},
};

static Fls_HyperbusCommandType Fls_HyperBusProgramWord =
{
    .name = "word_program",
    .isRead = FALSE,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0xA0}, {0}, {0}, {0}},
};

Fls_BusFlashOpsType Fls_HyperbusOps =
{
    .waitIdle = Fls_HyperBusWaitIdle,
    .writeEnable = Fls_HyperBusWriteEnable,
    .init = Fls_HyperBusInit,
    .deinit = Fls_HyperBusDeinit,
    .read = Fls_HyperBusRead,
    .write = Fls_HyperBusWrite,
    .erase = Fls_HyperBusErase,
    .getBusyStatus = Fls_HyperBusGetBusyStatus,
    .cancel = Fls_HyperBusCancel,
    .setupNotificationCallback = Fls_BusSetupNotificationCallback,
    .getResult = Fls_BusGetResult,
    .getInfo = Fls_BusGetInfo,
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/** *****************************************************************************************************
 * \brief This function enable flash writing
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusWriteEnable(
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
 * Description        : Send commands with the Hyperbus protocol to write enable
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_033
 *******************************************************************************************************/
static int Fls_HyperBusWriteEnable(Fls_BusHandleType *nor, boolean enable)
{
    Fls_HyperbusCaType *ca = Fls_HyperBusProgramWord.ca;

    (void) enable;

    nor->host->ops->setPreTransaction(nor, FALSE, FALSE, 3u, &ca);

    return 0;
}

/** *****************************************************************************************************
 * \brief This function returns the status of flash.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusGetStatus(
 *                          Fls_BusHandleType *nor, uint16 *status)
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
 * Description        : Send commands with the Hyperbus protocol, and get the state of Flash
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_013
 *******************************************************************************************************/
static int Fls_HyperBusGetStatus(Fls_BusHandleType *nor, uint16 *status)
{
    int ret;
    VAR_ALIGN(uint16 reg, 4) = 0u;
    Fls_HyperbusCaType *ca = Fls_HyperBusReadStatus.ca;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    nor->host->ops->setPreTransaction(nor, TRUE, FALSE, 1u, &ca);
    ret = nor->host->ops->read16(nor, 0u, &reg);
    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);
    *status = reg;
    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns the result of whether the status of Flash is busy.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusGetBusyStatus(
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
 * Description        : Send commands with the Hyperbus protocol, get the state of
 *                      Flash and determine whether it is idle
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_013
 *******************************************************************************************************/
static int Fls_HyperBusGetBusyStatus(Fls_BusHandleType *nor)
{
    int ret;
    uint16 flashStatus;

    ret = Fls_HyperBusGetStatus(nor, &flashStatus);

    if (FLS_SUCCESS != ret)
    {
        FLS_DEBUG("spi_nor get flash status failed, ret: %d!\n", ret);
    }
    else if (0U == (flashStatus & FLS_BIT(7)))
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
 * \brief This function wait flash device for idle until timeout.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusWaitIdle(
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
 * Description        : Send commands with the Hyperbus protocol, get the state of flash
 *                      and determine whether it is idle, If busy, wait until timeout
 * \endverbatim
 * Traceability       : SWSR_FLS_166
 *******************************************************************************************************/
static int Fls_HyperBusWaitIdle(Fls_BusHandleType *nor)
{
    int ret;
    uint16 flashStatus;
    uint32 tickCount;
    uint32 parallelCount = 0;

    for (tickCount = 0; tickCount <= FLS_BUS_TIMEOUT_COUNT; tickCount++)
    {
        ret = Fls_HyperBusGetStatus(nor, &flashStatus);

        if (FLS_SUCCESS != ret)
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
                FLS_DEBUG("hyperbus get flash status failed, ret: %d!\n", ret);
            }
        }

        if ((FLS_SUCCESS != ret) || (0U != (flashStatus & FLS_BIT(7))))
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
 * \brief This function match Flash based on its ID.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusReadId(
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
 * Description        : Get flash id with the spi protocol, And match from the support list
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_021
 *******************************************************************************************************/
static int Fls_HyperBusReadId(Fls_BusHandleType *nor)
{
    int ret;
    VAR_ALIGN(uint8 id[8], 4);
    const Fls_BusFlashInfoType *info;
    uint32 i;
    Fls_BusCommandType readCmd;
    readCmd.opcode = FLS_BUS_OP_RDID;
    readCmd.dummy = (uint8)(ID_PROTO(0, FLS_BUS_PROTO_1_1_1) >> FLS_BUS_READID_DUMMY_LSB);
    readCmd.instType = FLS_BUS_INST_LANS(ID_PROTO(0, FLS_BUS_PROTO_1_1_1));
    readCmd.addrBytes = 0;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    id[0] = 0;
    id[1] = 0;
    id[2] = 0;
    id[3] = 0;
    id[4] = 0;
    id[5] = 0;
    id[6] = 0;
    id[7] = 0;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    ret = nor->host->ops->regRead(nor, &readCmd, 0, id, 6);
    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    if (FLS_SUCCESS == ret)
    {
        FLS_DEBUG("id0: %x, id1: %x, id2: %x\n", id[0], id[2], id[4]);
        ret = FLS_NO_MATCH_ID;

        for (i = 0; i < ARRAY_SIZE(Fls_HyperBusIds); i++)
        {
            info = &Fls_HyperBusIds[i];

            if (0U == Fls_MemCompare((void *)(Fls_PointerType)info->flashId,
                                     (void *)(Fls_PointerType)id, 4U))
            {
                (void) Fls_MemCopy((void *)(Fls_PointerType)&nor->info,
                                   (void *)(Fls_PointerType)info, sizeof(Fls_BusFlashInfoType));
                nor->info.size = ((uint32)1U) << id[FLS_BUS_ID_CAPACITY_OFFSET];
                ret = FLS_SUCCESS;
                break;
            }
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns match Flash based on its SDF ID.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusReadSfdpId(
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
 * Description        : Get flash id with the hyperbus SFD protocol,
 *                      And match from the support list
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_021
 *******************************************************************************************************/
static int Fls_HyperBusReadSfdpId(Fls_BusHandleType *nor)
{
    int ret = FLS_SUCCESS;
    /* Hyper bus device ID is uint16 */
    VAR_ALIGN(uint16 id0, 4);
    VAR_ALIGN(uint16 id1, 4);
    VAR_ALIGN(uint16 id2, 4);
    const Fls_BusFlashInfoType *info;
    uint32 i;
    VAR_ALIGN(uint16 asoExitData, 4) = FLS_BUS_OP_ASO_EXIT;
    Fls_HyperbusCaType *ca = Fls_HyperBusReadDevId.ca;
    (void) Fls_MemCopy((void *)(Fls_PointerType)&nor->info,
                       (void *)(Fls_PointerType)&Fls_HyperBusIds[0],
                       sizeof(Fls_BusFlashInfoType));

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    nor->host->ops->setPreTransaction(nor, TRUE, FALSE, 3u, &ca);

    if (0 != nor->host->ops->read16(nor, FLS_BUS_SFD_ID_0, &id0))
    {
        ret = FLS_FAILED;
    }

    if (0 != nor->host->ops->read16(nor, FLS_BUS_SFD_ID_1, &id1))
    {
        ret = FLS_FAILED;
    }

    if (0 != nor->host->ops->read16(nor, FLS_BUS_SFD_ID_2, &id2))
    {
        ret = FLS_FAILED;
    }

    nor->host->ops->write16(nor, 0, &asoExitData);

    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    if (FLS_SUCCESS == ret)
    {
        FLS_DEBUG("id0: %x, id1: %x, id2: %x\n", id0, id1, id2);
        ret = FLS_NO_MATCH_ID;

        for (i = 1; i < ARRAY_SIZE(Fls_HyperBusIds); i++)
        {
            info = &Fls_HyperBusIds[i];

            if ((info->flashId[0] == (id0 & 0xffU)) && (info->flashId[2] == (id1 & 0xffU)))
            {
                (void) Fls_MemCopy((void *)(Fls_PointerType)&nor->info,
                                   (void *)(Fls_PointerType)info, sizeof(Fls_BusFlashInfoType));
                nor->info.size = ((uint32)1U) << id2;
                ret = FLS_SUCCESS;
                break;
            }
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns match Flash based on its SDF ID.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusReadCfiId(
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
 * Description        : Get flash id with the hyperbus CFI protocol,
 *                      And match from the support list
 *
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_021
 *******************************************************************************************************/
static int Fls_HyperBusReadCfiId(Fls_BusHandleType *nor)
{
    int ret = FLS_SUCCESS;
    /* Hyper bus device ID is uint16 */
    VAR_ALIGN(uint16 id0, 4);
    VAR_ALIGN(uint16 id1, 4);
    VAR_ALIGN(uint16 id2, 4);
    uint32 i;
    const Fls_BusFlashInfoType *info;
    VAR_ALIGN(uint16 asoExitData, 4) = FLS_BUS_OP_ASO_EXIT;
    Fls_HyperbusCaType *ca = Fls_HyperBusReadDevId.ca;
    (void) Fls_MemCopy((void *)(Fls_PointerType)&nor->info,
                       (void *)(Fls_PointerType)&Fls_HyperBusIds[0],
                       sizeof(Fls_BusFlashInfoType));

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    nor->host->ops->setPreTransaction(nor, TRUE, FALSE, 3u, &ca);

    if (0 != nor->host->ops->read16(nor, FLS_BUS_CFI_ID_0, &id0))
    {
        ret = FLS_FAILED;
    }

    if (0 != nor->host->ops->read16(nor, FLS_BUS_CFI_ID_1, &id1))
    {
        ret = FLS_FAILED;
    }

    if (0 != nor->host->ops->read16(nor, FLS_BUS_CFI_ID_2, &id2))
    {
        ret = FLS_FAILED;
    }

    nor->host->ops->write16(nor, 0, &asoExitData);
    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    if (FLS_SUCCESS == ret)
    {
        FLS_DEBUG("id0: %x, id1: %x, id2: %x\n", id0, id1, id2);
        ret = FLS_NO_MATCH_ID;

        for (i = 1; i < ARRAY_SIZE(Fls_HyperBusIds); i++)
        {
            info = &Fls_HyperBusIds[i];

            if ((info->flashId[0] == (id0 & 0xffU)) && (info->flashId[2] == (id1 & 0xffU)))
            {
                (void) Fls_MemCopy((void *)(Fls_PointerType)&nor->info,
                                   (void *)(Fls_PointerType)info, sizeof(Fls_BusFlashInfoType));
                nor->info.size = ((uint32)1U) << id2;
                ret = FLS_SUCCESS;
                break;
            }
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Enable Hyperbus mode for Flash.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusEnable(
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
 * Description        : Send command to Enable Hyperbus mode for Flash.
 * \endverbatim
 * Traceability       : SWSR SWSR_FLS_033
 *******************************************************************************************************/
static int Fls_HyperBusEnable(Fls_BusHandleType *nor)
{
    int ret;
    VAR_ALIGN(uint8 data[2], 4);
    Fls_BusCommandType readCmd, writeEnableCmd, writeCmd;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    data[0] = 0;
    data[1] = 0;

    readCmd.opcode = FLS_BUS_OP_RDAR;
    readCmd.addrBytes = 3;
    readCmd.instType = 0;
    readCmd.dummy = 8;

    writeEnableCmd.opcode = FLS_BUS_OP_WREN;
    writeEnableCmd.addrBytes = 0;
    writeEnableCmd.instType = 0;
    writeEnableCmd.dummy = 0;

    writeCmd.opcode = FLS_BUS_OP_WRAR;
    writeCmd.addrBytes = 3;
    writeCmd.instType = 0;
    writeCmd.dummy = 0;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    ret = nor->host->ops->regRead(nor, &readCmd, 0x4, data, 1);
    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    if (FLS_SUCCESS == ret)
    {
        FLS_DEBUG("legacy x1 CFR4N register value 0x%x\n", data[0]);
        nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);

        if (0 != nor->host->ops->regWrite(nor, &writeEnableCmd, 0, NULL_PTR, 0))
        {
            ret = FLS_FAILED;
        }

        nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);
        data[0] |= (uint8)FLS_BIT(1);
        FLS_DEBUG("enable hyperbus mode\n");
        nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);

        if (0 != nor->host->ops->regWrite(nor, &writeCmd, 0x4, data, 1))
        {
            ret = FLS_FAILED;
        }

        nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Initialize Hyperflash.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusFlashInit(
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
 * Description        : Initialize Hyperflash
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_HyperBusFlashInit(Fls_BusHandleType *nor)
{
    int ret;

    FLS_DEBUG("hyperbus: try read id by legacy x1 interface\n");

    ret = Fls_HyperBusReadId(nor);

    if (FLS_SUCCESS == ret)
    {
        (void) Fls_HyperBusEnable(nor);
    }

    nor->hyperbusMode = TRUE;
    nor->regProto = FLS_BUS_PROTO_8_8_8_DTR;
    nor->addrWidth = 4u;
    nor->octalDtrEnable = 1u;
    nor->dqsEnable = TRUE;

    FLS_DEBUG("hyperbus: try read id by cfi interface\n");
    ret = Fls_HyperBusReadCfiId(nor);

    if (FLS_SUCCESS != ret)
    {
        FLS_DEBUG("hyperbus: try read id by SFDP interface\n");
        ret = Fls_HyperBusReadSfdpId(nor);
    }

    FLS_DEBUG("flash type is hyperflash\n");
    nor->memType = FLS_BUS_HYPERFLASH;


    return ret;
}

/** *****************************************************************************************************
 * \brief This function Initialize Hyperram.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusRamInit(
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
 * Description        : Initialize Hyperram
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_HyperBusRamInit(Fls_BusHandleType *nor)
{
    nor->hyperbusMode = TRUE;
    nor->regProto = FLS_BUS_PROTO_8_8_8_DTR;
    nor->addrWidth = 4u;
    nor->octalDtrEnable = 1u;
    nor->dqsEnable = TRUE;

    (void) Fls_MemCopy((void *)(Fls_PointerType)&nor->info,
                       (void *)(Fls_PointerType)&Fls_HyperBusIds[1],
                       sizeof(Fls_BusFlashInfoType));
    nor->memType = FLS_BUS_HYPERRAM;
    FLS_DEBUG("flash type is hyperam\n");
    /* For hyperram driver not get size info, set 128M */
    nor->info.size = FLS_BUS_HYPER_RAM_DEFAULT_SIZE;
    nor->host->ops->hyperramEnable(nor, nor->cs, FLS_BUS_HYPER_RAM_DUMMY, FLS_BUS_HYPER_RAM_DUMMY);

    return 0;
}

/** *****************************************************************************************************
 * \brief This function execute the training process for Flash.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusTraining(
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
static int Fls_HyperBusTraining(Fls_BusHandleType *nor)
{
    uint32 trainingLength = FLS_BUS_TRAINING_BUF_SIZE;
    Fls_AddressType trainingAddr;
    int ret = FLS_SUCCESS;
    VAR_ALIGN(uint8 trainingBuffer[FLS_BUS_TRAINING_BUF_SIZE], 4U) = {0};

    if (NULL_PTR != nor->host->ops->training)
    {
        trainingAddr = nor->info.sectorSize;

        if (0 != Fls_HyperBusRead(nor, trainingAddr, trainingBuffer, trainingLength))
        {
            ret = FLS_FAILED;
        }
        else if (0u != Fls_MemCompare((const void *)Fls_BusTrainingPattern,
                                      (void *)(Fls_PointerType)trainingBuffer,
                                      trainingLength))
        {
            if (nor->memType != FLS_BUS_HYPERRAM)
            {
                if (FLS_SUCCESS != Fls_HyperBusErase(nor, trainingAddr, nor->info.sectorSize))
                {
                    ret = FLS_FAILED;
                }

#ifdef FLS_ASYNC_MODE_EN
                else if (FLS_SUCCESS != Fls_HyperBusWaitIdle(nor))
                {
                    ret = FLS_FAILED;
                }
                else
                {
                    /* Do nothing */
                }

#endif /* #ifdef FLS_ASYNC_MODE_EN */
            }

            if (FLS_SUCCESS != Fls_HyperBusWrite(nor, trainingAddr,
                                                 Fls_BusTrainingPattern, trainingLength))
            {
                ret = FLS_FAILED;
            }

#ifdef FLS_ASYNC_MODE_EN
            else if (FLS_SUCCESS != Fls_HyperBusWaitIdle(nor))
            {
                ret = FLS_FAILED;
            }
            else
            {
                /* Do nothing */
            }

#endif /* #ifdef FLS_ASYNC_MODE_EN */
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

            ret = nor->host->ops->training(nor, trainingAddr, trainingBuffer,
                                           Fls_BusTrainingPattern, trainingLength);
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Initialize Hyperbus.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusInit(
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
 * Description        : Initialize Hyperbus based on configuration parameters
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_HyperBusInit(Fls_BusHandleType *nor, Fls_IpHostType *host,
                            const Fls_BusConfigType *config)
{
    int ret;

    const Fls_ContextType *pCtx = ((Fls_ContextType *)nor->parent);

    nor->id = config->id;
    nor->baudrate = config->baudrate;
    nor->xferMode = config->xferMode;
    nor->devMode = config->devMode;

    nor->host = host;
    nor->swReset = config->swReset;
    nor->rfdEnable = config->rfdEnable;


    switch (pCtx->controllerConfig->flashSpecialFlag)
    {
    case FLS_SPECIAL_HYPERRAM:
        ret = Fls_HyperBusRamInit(nor);
        break;

    case FLS_SPECIAL_MCP:
        if (0U == nor->cs)
        {
            ret = Fls_HyperBusFlashInit(nor);
        }
        else
        {
            ret = Fls_HyperBusRamInit(nor);
        }

        break;

    case FLS_SPECIAL_AUTO:
    default:
        ret = Fls_HyperBusFlashInit(nor);

        if (FLS_SUCCESS != ret)
        {
            ret = Fls_HyperBusRamInit(nor);
        }

        break;
    }

    if (FLS_SUCCESS == ret)
    {
        if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
        {
            nor->info.sectorSize *= 2u;

            if (nor->memType != FLS_BUS_HYPERRAM)
            {
                nor->info.size *= 2u;
            }
        }

        FLS_DEBUG("flash size: %llx\n", nor->info.size);

        /* set dummy ... */
        if (NULL_PTR != nor->info.defaultInit)
        {
            nor->info.defaultInit(nor);
        }

        ret = Fls_HyperBusTraining(nor);

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
 * Syntax             : int Fls_HyperBusRead(
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
 * Description        : Read Flash memory data with the Hyperbus protocol
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_HyperBusRead(Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
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
 * Syntax             : int Fls_HyperBusWrite(
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
 * Description        : Write to flash with the Hyperbus protocol
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_HyperBusWrite(Fls_BusHandleType *nor, Fls_AddressType addr, const uint8 *buf,
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
 * Syntax             : int Fls_HyperBusErase(
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
 * Description        : Erase the sector of flash with the Hyperbus protocol
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_HyperBusErase(Fls_BusHandleType *nor, Fls_AddressType addr, Fls_LengthType size)
{
    int ret = FLS_SUCCESS;
    Fls_HyperbusCaType *ca;
    VAR_ALIGN(uint16 eraseCmdData, 4) = FLS_BUS_OP_ERASE;
    const Fls_IpHostOpsType *ops = nor->host->ops;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_ERASE);
    nor->host->ops->cacheFlush(nor, addr, size);
    Fls_BusSetupXfer(nor, FLS_BUS_OPS_ERASE, addr, NULL_PTR, NULL_PTR, size);
    nor->xferInfo.size = size;

    if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
    {
        nor->xferInfo.addr = nor->xferInfo.addr / 2u;
    }

    while (nor->xferInfo.size > 0U)
    {
        ca = Fls_HyperBusEraseSector.ca;

        ops->setPreTransaction(nor, FALSE, FALSE, 5u, &ca);
        /* erase addr need convert to word addr */
        ret = ops->write16(nor, (nor->xferInfo.addr - nor->regOffset) / 2u,
                           &eraseCmdData);

        if (0 != ret)
        {
            break;
        }

#ifndef FLS_ASYNC_MODE_EN
        /* wait for flash idle */
        ret = Fls_HyperBusWaitIdle(nor);

        if (0 != ret)
        {
            break;
        }

#endif /* #ifndef FLS_ASYNC_MODE_EN */

        nor->xferInfo.addr += nor->info.sectorSize;
        nor->xferInfo.size -= nor->info.sectorSize;
    }

    FlsHookError_Fls_HyperBusErase();

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
 * Syntax             : int Fls_HyperBusCancel(
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
 * Description        : Cancel current operation with the Hyperbus protocol
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_HyperBusCancel(Fls_BusHandleType *nor)
{
    int ret = 0;

    if (NULL_PTR != nor->host->ops->cancel)
    {
        ret = nor->host->ops->cancel(nor);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Perform special initialization.
 *
 * \verbatim
 * Syntax             : int Fls_HyperBusS26DefaultInit(
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
 * Description        : Perform special initialization of Flash model S26
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_168
 *******************************************************************************************************/
static int Fls_HyperBusS26DefaultInit(Fls_BusHandleType *nor)
{
    int ret = FLS_SUCCESS;
    VAR_ALIGN(uint16 reg, 4) = 0x0u;

    Fls_HyperbusCaType *ca = Fls_HyperBusReadVolReg2.ca;

    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    nor->host->ops->setPreTransaction(nor, TRUE, FALSE, 3u, &ca);

    if (0 != nor->host->ops->read16(nor, 0u, &reg))
    {
        ret = FLS_FAILED;
    }

    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

#ifdef CONFIG_HYPERBUS_DIFFERENTIAL_CLK_EN
    /* Enable differential clock mode */
    reg &= ~((uint16)FLS_BIT(0));
#endif /* #ifdef CONFIG_HYPERBUS_DIFFERENTIAL_CLK_EN */
#ifdef CONFIG_HYPERBUS_INCREMENTAL_PROGRAM_EN
    /*
     * If 2bit ECC detect enable, program one page two times without erase
     * will result in a program error.
     */
    reg |= (uint16)FLS_BIT(5);
#endif /* #ifdef CONFIG_HYPERBUS_INCREMENTAL_PROGRAM_EN */
    ca = Fls_HyperBusWriteVolReg2.ca;
    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    nor->host->ops->setPreTransaction(nor, FALSE, FALSE, 3u, &ca);

    if (0 != nor->host->ops->write16(nor, 0u, &reg))
    {
        ret = FLS_FAILED;
    }

    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);

    ca = Fls_HyperBusReadVolReg2.ca;
    nor->host->ops->prepare(nor, FLS_BUS_OPS_LOCK);
    nor->host->ops->setPreTransaction(nor, TRUE, FALSE, 3u, &ca);

    if (0 != nor->host->ops->read16(nor, 0u, &reg))
    {
        ret = FLS_FAILED;
    }

    nor->host->ops->unprepare(nor, FLS_BUS_OPS_LOCK);
    FLS_DEBUG("cypress vol regster2 0x%x\n", reg);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Reverse initialization of Flash.
 *
 * \verbatim
 * Syntax             : void Fls_HyperBusDeinit(
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
static void Fls_HyperBusDeinit(Fls_BusHandleType *nor)
{
    Fls_IpDeinit(nor);
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#endif /* #ifdef FLS_HYPERBUS_FLASH_CNT */

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

/* End of file */
