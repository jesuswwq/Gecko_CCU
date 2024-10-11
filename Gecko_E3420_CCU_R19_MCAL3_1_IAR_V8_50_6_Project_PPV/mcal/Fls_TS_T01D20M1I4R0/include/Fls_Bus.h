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
 * \file     Fls_Bus.h                                                                                  *
 * \brief    This file contains interface header for FLS MCAL driver                                    *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/26     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FLS_BUS_H
#define FLS_BUS_H

#ifdef __cplusplus
extern "C" {
#endif  /* #ifdef __cplusplus */

#include <RegHelper.h>
#include "Std_Types.h"

#define FLS_BIT(nr) (((uint32)1u) << (nr))

#define FLS_BUS_TIMEOUT_COUNT   (1000000U)

#define FLS_BUS_READID_DUMMY_LSB (24u)
#define FLS_BUS_OPCODE_PROTO_LSB (24u)
#define FLS_BUS_DTR_PROTO       FLS_BIT(16)
#define FLS_BUS_ADDRESS_EN      FLS_BIT(17)

#define FLS_BUS_SINGLE_LAN      ((uint8)0U)
#define FLS_BUS_DUAL_LANS      ((uint8)1U)
#define FLS_BUS_QUAD_LANS      ((uint8)2U)
#define FLS_BUS_OCTAL_LANS      ((uint8)3U)

#define FLS_BUS_INST_LANS_PROTO_LSB  (8u)
#define FLS_BUS_INST_LANS_PROTO_MASK (0xFu)
#define FLS_BUS_INST_SINGLE_LANS     ((uint32)0u << FLS_BUS_INST_LANS_PROTO_LSB)
#define FLS_BUS_INST_DUAL_LANS       ((uint32)1u << FLS_BUS_INST_LANS_PROTO_LSB)
#define FLS_BUS_INST_QUAD_LANS       ((uint32)2u << FLS_BUS_INST_LANS_PROTO_LSB)
#define FLS_BUS_INST_OCTAL_LANS      ((uint32)3u << FLS_BUS_INST_LANS_PROTO_LSB)
#define FLS_BUS_INST_LANS(x)         ((uint8)(((uint32)(x) >> FLS_BUS_INST_LANS_PROTO_LSB) & \
                                                    FLS_BUS_INST_LANS_PROTO_MASK))

#define FLS_BUS_ADDR_LANS_PROTO_LSB  (4u)
#define FLS_BUS_ADDR_LANS_PROTO_MASK (0xFu)
#define FLS_BUS_ADDR_SINGLE_LANS     ((uint32)0u << FLS_BUS_ADDR_LANS_PROTO_LSB)
#define FLS_BUS_ADDR_DUAL_LANS       ((uint32)1u << FLS_BUS_ADDR_LANS_PROTO_LSB)
#define FLS_BUS_ADDR_QUAD_LANS       ((uint32)2u << FLS_BUS_ADDR_LANS_PROTO_LSB)
#define FLS_BUS_ADDR_OCTAL_LANS      ((uint32)3u << FLS_BUS_ADDR_LANS_PROTO_LSB)
#define FLS_BUS_ADDR_LANS(x)         ((uint8)(((uint32)(x) >> FLS_BUS_ADDR_LANS_PROTO_LSB) & \
                                                 FLS_BUS_ADDR_LANS_PROTO_MASK))


#define FLS_BUS_DATA_LANS_PROTO_LSB  (0u)
#define FLS_BUS_DATA_LANS_PROTO_MASK (0xFu)
#if (FLS_BUS_DATA_LANS_PROTO_LSB > 0U)
#define FLS_BUS_DATA_SINGLE_LANS     ((uint32)0u << FLS_BUS_DATA_LANS_PROTO_LSB)
#define FLS_BUS_DATA_DUAL_LANS       ((uint32)1u << FLS_BUS_DATA_LANS_PROTO_LSB)
#define FLS_BUS_DATA_QUAD_LANS       ((uint32)2u << FLS_BUS_DATA_LANS_PROTO_LSB)
#define FLS_BUS_DATA_OCTAL_LANS      ((uint32)3u << FLS_BUS_DATA_LANS_PROTO_LSB)
#define FLS_BUS_DATA_LANS(x)         ((uint8)(((uint32)(x) >> FLS_BUS_DATA_LANS_PROTO_LSB) & \
                                                    FLS_BUS_DATA_LANS_PROTO_MASK))
#else
#define FLS_BUS_DATA_SINGLE_LANS     (0u)
#define FLS_BUS_DATA_DUAL_LANS       (1u)
#define FLS_BUS_DATA_QUAD_LANS       (2u)
#define FLS_BUS_DATA_OCTAL_LANS      (3u)
#define FLS_BUS_DATA_LANS(x)         ((uint8)((uint32)(x) & FLS_BUS_DATA_LANS_PROTO_MASK))
#endif /* #if (FLS_BUS_DATA_LANS_PROTO_LSB > 0U) */

#define FLS_BUS_PROTO_1_1_1                                                       \
    (FLS_BUS_INST_SINGLE_LANS | FLS_BUS_ADDR_SINGLE_LANS | FLS_BUS_DATA_SINGLE_LANS)
#define FLS_BUS_PROTO_1_1_2                                                       \
    (FLS_BUS_INST_SINGLE_LANS | FLS_BUS_ADDR_SINGLE_LANS | FLS_BUS_DATA_DUAL_LANS)
#define FLS_BUS_PROTO_1_1_4                                                       \
    (FLS_BUS_INST_SINGLE_LANS | FLS_BUS_ADDR_SINGLE_LANS | FLS_BUS_DATA_QUAD_LANS)
#define FLS_BUS_PROTO_1_1_8                                                       \
    (FLS_BUS_INST_SINGLE_LANS | FLS_BUS_ADDR_SINGLE_LANS | FLS_BUS_DATA_OCTAL_LANS)
#define FLS_BUS_PROTO_1_2_2                                                       \
    (FLS_BUS_INST_SINGLE_LANS | FLS_BUS_ADDR_DUAL_LANS | FLS_BUS_DATA_DUAL_LANS)
#define FLS_BUS_PROTO_1_4_4                                                       \
    (FLS_BUS_INST_SINGLE_LANS | FLS_BUS_ADDR_QUAD_LANS | FLS_BUS_DATA_QUAD_LANS)
#define FLS_BUS_PROTO_1_8_8                                                       \
    (FLS_BUS_INST_SINGLE_LANS | FLS_BUS_ADDR_OCTAL_LANS | FLS_BUS_DATA_OCTAL_LANS)
#define FLS_BUS_PROTO_2_2_2                                                       \
    (FLS_BUS_INST_DUAL_LANS | FLS_BUS_ADDR_DUAL_LANS | FLS_BUS_DATA_DUAL_LANS)
#define FLS_BUS_PROTO_4_4_4                                                       \
    (FLS_BUS_INST_QUAD_LANS | FLS_BUS_ADDR_QUAD_LANS | FLS_BUS_DATA_QUAD_LANS)
#define FLS_BUS_PROTO_8_8_8                                                       \
    (FLS_BUS_INST_OCTAL_LANS | FLS_BUS_ADDR_OCTAL_LANS | FLS_BUS_DATA_OCTAL_LANS)
#define FLS_BUS_PROTO_1_1_1_DTR (FLS_BUS_PROTO_1_1_1 | FLS_BUS_DTR_PROTO)
#define FLS_BUS_PROTO_1_2_2_DTR (FLS_BUS_PROTO_1_2_2 | FLS_BUS_DTR_PROTO)
#define FLS_BUS_PROTO_1_4_4_DTR (FLS_BUS_PROTO_1_4_4 | FLS_BUS_DTR_PROTO)
#define FLS_BUS_PROTO_4_4_4_DTR (FLS_BUS_PROTO_4_4_4 | FLS_BUS_DTR_PROTO)
#define FLS_BUS_PROTO_1_1_8_DTR (FLS_BUS_PROTO_1_1_8 | FLS_BUS_DTR_PROTO)
#define FLS_BUS_PROTO_1_8_8_DTR (FLS_BUS_PROTO_1_8_8 | FLS_BUS_DTR_PROTO)
#define FLS_BUS_PROTO_8_8_8_DTR (FLS_BUS_PROTO_8_8_8 | FLS_BUS_DTR_PROTO)

#define FLS_BUS_PROTO_DTR_MASK (0x1ffffu)
#define FLS_BUS_PROTO_MASK     (0xffffu)
#define FLS_BUS_PROTO_DTR(x) ((x) & FLS_BUS_PROTO_DTR_MASK)
#define FLS_BUS_PROTO(x) ((x) & FLS_BUS_PROTO_MASK)

#define FLS_BUS_SECTOR_4K_SIZE (0x1000U)
#define FLS_BUS_SECTOR_32K_SIZE (0x8000U)
#define FLS_BUS_SECTOR_64K_SIZE (0x10000U)
#define FLS_BUS_SECTOR_128K_SIZE (0x20000U)
#define FLS_BUS_SECTOR_256K_SIZE (0x40000U)

#define FLS_BUS_SIZE_16M (0x1000000U)

#define FLS_BUS_TRAINING_BUF_SIZE (32)

#define FLS_BUS_NAME_BUF_SIZE (32)

#define FLS_BUS_INIT_CLOCK_RATE (20000000)

struct Fls_BusHandle;
typedef struct Fls_BusHandle Fls_BusHandleType;


#define FLS_SUCCESS             (0)
#define FLS_FLASH_BUSY          (1)
#define FLS_FLASH_PROTECTED     (2)
/* Error code */
#define FLS_FAILED              (-1)
#define FLS_TIMEOUT_ERR         (-2)
#define FLS_NO_MATCH_ID         (-3)

typedef enum
{
    FLS_BUS_SECTOR_4KB = 0,
    FLS_BUS_SECTOR_32KB,
    FLS_BUS_SECTOR_64KB,
    FLS_BUS_SECTOR_128KB,
    FLS_BUS_SECTOR_256KB,
    FLS_BUS_SECTOR_TYPE_MAX,
} Fls_BusSectorType;
#define SECTOR_POST_TO_SIZE(n) (((uint32)1U) << (uint8)(n))
#define SECTOR_TYPE_TO_POST(type) (12U + (2U * ((0U == (uint8)(type)) ? 0U : 1U)) + (uint8)(type))
#define SECTOR_TYPE_TO_SIZE(type) SECTOR_POST_TO_SIZE(SECTOR_TYPE_TO_POST((uint8)(type)))

typedef enum
{
    FLS_BUS_XFER_POLLING_MODE = 0,
    FLS_BUS_XFER_INTERRUPT_MODE,
    FLS_BUS_XFER_DMA_MODE,
} Fls_BusXferModeType;

typedef enum
{
    FLS_BUS_DEV_SINGLE_MODE = 0,
    FLS_BUS_DEV_LOCKSTEP_MODE,
    FLS_BUS_DEV_PARALLEL_MODE,
    FLS_BUS_DEV_SWITCH_MODE,
} Fls_BusDeviceModeType;

#define FLS_BUS_MAX_ID_LEN 6

typedef enum
{
    FLS_BUS_NORFLASH = 0,
    FLS_BUS_NANDFLASH,
    FLS_BUS_HYPERFLASH,
    FLS_BUS_HYPERRAM,
    FLS_BUS_HYPERBUS_MCP,
} Fls_BusMemoryType;

/* Type Definitions */
typedef uint32 Fls_AddressType;
typedef uint32 Fls_LengthType;

typedef struct
{
    uint8 opcode;
    uint8 instType;
    uint8 dummy;
    uint8 addrBytes; /* 0 bytes(no need addr) 3 bytes or 4 bytes */
} Fls_BusCommandType;

typedef struct
{
    uint16 addr;
    uint16 data;
} Fls_HyperbusCaType;

#define FLS_HYPERFLSAH_CMD_MAX_NUM (6U)
typedef struct
{
    const char name[FLS_BUS_NAME_BUF_SIZE];
    boolean isRead;
    uint32 num;
    Fls_HyperbusCaType ca[FLS_HYPERFLSAH_CMD_MAX_NUM];
} Fls_HyperbusCommandType;

typedef enum
{
    FLS_BUS_OPS_UNKNOW = 0,
    FLS_BUS_OPS_READ = 1,
    FLS_BUS_OPS_WRITE,
    FLS_BUS_OPS_ERASE,
    FLS_BUS_OPS_LOCK,
    FLS_BUS_OPS_UNLOCK,
} Fls_BusOpsType;

typedef enum
{
    FLS_BUS_OPS_COMPLETE = 0,
    FLS_BUS_OPS_FAILED,
    FLS_BUS_OPS_PENDING,
    FLS_BUS_OPS_INCONSISTENT,
    FLS_BUS_OPS_INVALID,
    FLS_BUS_OPS_RESULET_MAX,
} Fls_BusOpsResultType;

typedef struct
{
    uint8 id;
    uint8 cs;
    uint32 baudrate;
    unsigned long refClkHz;
    Fls_BusXferModeType xferMode;
    Fls_BusDeviceModeType devMode;
    boolean hyperbusMode;
    boolean swReset;
    boolean rfdEnable;
} Fls_BusConfigType;

typedef struct
{
    Fls_BusOpsType opsType;
    Fls_BusOpsResultType opsResult;
    Fls_AddressType addr;
    uint8 *readBuf;
    const uint8 *writeBuf;
    Fls_LengthType size;
} Fls_BusXferInfoType;

typedef void (*Fls_BusNotificationType)(Fls_BusOpsType type, Fls_BusOpsResultType result);

typedef struct
{
    int (*prepare)(Fls_BusHandleType *handle, Fls_BusOpsType ops);
    void (*unprepare)(Fls_BusHandleType *handle, Fls_BusOpsType ops);
    int (*regRead)(Fls_BusHandleType *handle, Fls_BusCommandType *cmd,
                   Fls_AddressType addr, uint8 *buf, Fls_LengthType length);
    int (*regWrite)(Fls_BusHandleType *handle, Fls_BusCommandType *cmd,
                    Fls_AddressType addr, const uint8 *buf,
                    Fls_LengthType length);
    int (*read)(Fls_BusHandleType *handle, Fls_AddressType addr, uint8 *buf,
                Fls_LengthType length);
    int (*write)(Fls_BusHandleType *handle, Fls_AddressType addr,
                 const uint8 *buf, Fls_LengthType length);
    int (*erase)(Fls_BusHandleType *handle, Fls_AddressType offset);
    int (*training)(Fls_BusHandleType *handle, Fls_AddressType addr,
                    uint8 *buf, const uint8 *pattern, Fls_LengthType length);
    int (*cancel)(Fls_BusHandleType *handle);
    void (*cacheFlush)(Fls_BusHandleType *handle, Fls_AddressType addr,
                       Fls_LengthType length);
    int (*enableRfd)(Fls_BusHandleType *handle);
    int (*read16)(Fls_BusHandleType *handle, Fls_AddressType addr, uint16 *buf);
    int (*write16)(Fls_BusHandleType *handle, Fls_AddressType addr, uint16 *buf);
    void (*setPreTransaction)(Fls_BusHandleType *handle, boolean isRead,
                              boolean isDirect, uint32 num, Fls_HyperbusCaType **caArray);
    void (*hyperramEnable)(Fls_BusHandleType *handle, uint8 cs,
                           uint8 readDummy, uint8 writeDummy);
    int (*enterXipMode)(Fls_BusHandleType *handle, boolean enable);
} Fls_IpHostOpsType;

typedef struct
{
    int (*setClkRate)(uint8 id, unsigned long rate);
    unsigned long (*getClkRate)(uint8 id);
} Fls_IpClockOpsType;

typedef struct
{
    uint8 id;
    uint32 base;
    unsigned int irq;
    unsigned long refClkHz;
    Fls_IpClockOpsType *clkOps;
    Fls_IpHostOpsType *ops;
    Fls_BusHandleType *dev;
    void *privData;
} Fls_IpHostType;

typedef struct Fls_BusFlashInfo
{
    const char name[FLS_BUS_NAME_BUF_SIZE];
    uint8 flashId[FLS_BUS_MAX_ID_LEN];
    uint32 readProto;
    uint32 writeProto;
    uint32 eraseProto[FLS_BUS_SECTOR_TYPE_MAX];
    uint8 readDummy;
    uint8 writeDummy;
    uint8 statusDummy;
    uint32 sectorSize;
    uint16 pageSize;
    Fls_BusSectorType sectorType;
    Fls_LengthType size;
    Fls_AddressType regOffset;
    int (*defaultInit)(Fls_BusHandleType *bus);
    int (*octalDtrEnable)(Fls_BusHandleType *bus, boolean opiEnable, boolean dqsEnable);
    int (*quadEnable)(Fls_BusHandleType *bus, boolean enable);
    int (*enterQuad)(Fls_BusHandleType *bus, boolean enable);
    int (*setAddressWidth)(Fls_BusHandleType *bus, boolean enable);
    int (*SetProtectArea)(Fls_BusHandleType *bus, Fls_AddressType addr,
                          Fls_LengthType length);
    int (*enterXipMode)(Fls_BusHandleType *handle, boolean enable);
} Fls_BusFlashInfoType;

typedef struct Fls_BusFlashOps
{
    int (*waitIdle)(Fls_BusHandleType *bus);
    int (*writeEnable)(Fls_BusHandleType *bus, boolean enable);
    int (*init)(Fls_BusHandleType *bus, Fls_IpHostType *host,
                const Fls_BusConfigType *busConfig);
    void (*deinit)(Fls_BusHandleType *bus);
    int (*read)(Fls_BusHandleType *bus, Fls_AddressType addr, uint8 *buf,
                Fls_LengthType size);
    int (*write)(Fls_BusHandleType *bus, Fls_AddressType addr,
                 const uint8 *buf, Fls_LengthType size);
    int (*erase)(Fls_BusHandleType *bus, Fls_AddressType addr,
                 Fls_LengthType size);
    int (*getBusyStatus)(Fls_BusHandleType *bus);
    int (*getProtectStatus)(Fls_BusHandleType *bus);
    int (*cancel)(Fls_BusHandleType *bus);
    void (*setupNotificationCallback)(Fls_BusHandleType *bus, Fls_BusNotificationType callback);
    Fls_BusOpsResultType (*getResult)(Fls_BusHandleType *bus);
    Fls_BusFlashInfoType *(*getInfo)(Fls_BusHandleType *bus);
} Fls_BusFlashOpsType;

struct Fls_BusHandle
{
    uint8 id;
    uint8 cs;
    uint32 baudrate;

    Fls_BusMemoryType memType;
    Fls_BusDeviceModeType devMode;
    Fls_BusFlashInfoType info;

    boolean phyEnable;
    boolean dqsEnable;
    boolean octalDtrEnable;
    boolean hyperbusMode;
    boolean swReset;
    boolean rfdEnable;

    uint32 regProto;

    uint8 addrWidth;

    Fls_BusXferModeType xferMode;
    Fls_BusXferInfoType xferInfo;
    Fls_BusXferInfoType xferInfoBottom;
    Fls_BusNotificationType eventHandler;

    Fls_IpHostType *host;
    Fls_BusFlashOpsType *ops;
    void *parent;
};

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */
#endif /* #ifndef FLS_BUS_H */

/* End of file */
