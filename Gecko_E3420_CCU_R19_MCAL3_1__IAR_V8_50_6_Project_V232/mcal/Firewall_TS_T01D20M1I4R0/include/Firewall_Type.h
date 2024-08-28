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
 *  \file     Firewall_Type.h                                                                           *
 * \brief    This file contains type definition for Firewall MCAL driver.                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_TYPE_H
#define FIREWALL_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Std_Types.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_FIREWALL_MACRO Firewall Macro.
 *
 * This files defines FIREWALL MCAL macros.
 *  \{
 */
/**
 * \name Firewall permission value.
 *
 * Traceability: SWSR_FIREWALL_002
 *  \{
 */
/** \brief Enable read and write permissions. */
#define FIREWALL_PERMISSION_RW          (0x00U)
/** \brief Enable read permission. */
#define FIREWALL_PERMISSION_RO          (0x01U)
/** \brief Enable write permission. */
#define FIREWALL_PERMISSION_WO          (0x02U)
/** \brief No permission. */
#define FIREWALL_PERMISSION_NONE        (0x03U)
/** \} */

/**
 *  \name FIREWALL Error Codes
 *
 *  Error codes returned by FIREWALL functions.
 *  \{
 */
/** \brief  ERROR:Error due to API duplicated invoked FIREWALL_Init(). */
#define FIREWALL_E_INIT                 (0x80U)
/** \brief  ERROR:Error due to API invoked without performing FIREWALL_Init(). */
#define FIREWALL_E_UNINIT               (0x81U)
/** \brief  ERROR:Error due to NULL_PTR passed as parameter. */
#define FIREWALL_E_NULL_POINTER         (0x82U)
/** \brief  ERROR:Error due to invalid master id. */
#define FIREWALL_E_MAC_MASTER_ID        (0x83U)
/** \brief  ERROR:Error due to invalid domain id. */
#define FIREWALL_E_MAC_DOMAIN_ID        (0x84U)
/** \brief  ERROR:Error due to the MAC module has been locked. */
#define FIREWALL_E_MAC_LOCKED           (0x85U)
/** \brief  ERROR:Error due to the unvalid number of memory ports. */
#define FIREWALL_E_MPC_PORT_NUM         (0x86U)
/** \brief  ERROR:Error due to the unvalid number of memory regions. */
#define FIREWALL_E_MPC_REGION_NUM       (0x87U)
/** \brief  ERROR:Error due to the unvalid number of peripherals. */
#define FIREWALL_E_PPC_IP_NUM           (0x88U)
/** \brief  ERROR:Error due to the unvalid number of apb regions. */
#define FIREWALL_E_PPC_REGION_NUM       (0x89U)
/** \brief  ERROR:Error due to invalid core id. */
#define FIREWALL_E_DIO_CORE_ID          (0x8AU)
/** \brief  ERROR:Error due to invalid dio pin channel id. */
#define FIREWALL_E_DIO_CHANNEL_ID       (0x8BU)
/** \brief  ERROR:Error due to invalid number of cores. */
#define FIREWALL_E_DIO_CORE_NUM         (0x8CU)
/** \brief  ERROR:Error due to invalid number of dio pin channels. */
#define FIREWALL_E_DIO_CHANNEL_NUM      (0x8DU)
/** \} */

/** \brief The maximum number of apbmux. */
#define FIREWALL_PPC_APBMUX_MAXNUM      (7U)
/** \brief The maximum number of memory ports. */
#define FIREWALL_MPC_MEMPORT_MAXNUM     (23U)
/** \brief The id of the MPC reserved port. */
#define FIREWALL_MPC_RESERVED_PORTID    (16U)

/** \brief The minimum value of register. */
#define FIREWALL_REG_VALUE_MIN          (0x00U)
/** \brief The maximum value of register. */
#define FIREWALL_REG_VALUE_MAX          (0xFFFFFFFFU)

/** \brief  Dummy process. */
#define FIREWALL_DUMMY_STATEMENT(state) ((state) = (state))

/** \} */

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_FIREWALL_STRUCT Firewall Configuration.
 *
 * This files defines FIREWALL MCAL structures
 *  \{
 */
/** \brief The type of configuarion for the MAC module */
typedef const uint8 *Firewall_MacConfigType;

/** \brief The type of configuarion for the MPC region */
typedef struct
{
    uint32 mpcStartAddr;                  /**< The start address of the region */
    uint32 mpcEndAddr;                    /**< The end address of the region */
    unsigned int mpcUnlockPermission : 4; /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
    unsigned int mpcLockPermission : 4;   /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
    unsigned int mpcSp0Permission : 4;    /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
    unsigned int mpcSp1Permission : 4;    /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
    unsigned int mpcSx0Permission : 4;    /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
    unsigned int mpcSx1Permission : 4;    /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
    unsigned int mpcDmaPermission : 4;    /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
    unsigned int mpcSfPermission : 4;     /**< 2 bit user permission, 2 bit privilege, first bit as
                                          read,second as write */
} Firewall_MpcRegionConfigType;

/** \brief The type of configuarion for the MPC port */
typedef struct
{
    uint8 mpcRegionNum;   /**< The number of regions in the specified memory port */
    uint16 mpcBaseOffset; /**< The base offset of the memory port */
    const Firewall_MpcRegionConfigType
        *mpcRegionCfgPtr; /**< The pointer to the configuration of regions in the specified memory port */
} Firewall_MpcMemPortConfigType;

/** \brief The type of configuarion for the PPC address regions */
typedef struct
{
    unsigned int ppcSfUserPermission : 2;        /**< SF User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSfPrivilegedPermission : 2;  /**< SF Privileged Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSp0UserPermission : 2;       /**< SP0 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSp0PrivilegedPermission : 2; /**< SP0 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcSp1UserPermission : 2;       /**< SP1 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSp1PrivilegedPermission : 2; /**< SP1 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcSx0UserPermission : 2;       /**< SX0 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSx0PrivilegedPermission : 2; /**< SX0 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcSx1UserPermission : 2;       /**< SX1 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSx1PrivilegedPermission : 2; /**< SX1 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcDmaPermission : 2;           /**< Dma Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcApbmuxId : 4;                /**< PPC protected APBMUX num */
    uint8 ppcRegionN;                            /**< PPC protected Region N */
    uint32 ppcStartAddr;                         /**< start addr */
    uint32 ppcEndAddr;                           /**< end addr */
} Firewall_PpcAddrConfigType;

/** \brief The type of configuarion for the PPC peripherals */
typedef struct
{
    unsigned int ppcSfUserPermission : 2;        /**< SF User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSfPrivilegedPermission : 2;  /**< SF Privileged Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSp0UserPermission : 2;       /**< SP0 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSp0PrivilegedPermission : 2; /**< SP0 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcSp1UserPermission : 2;       /**< SP1 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSp1PrivilegedPermission : 2; /**< SP1 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcSx0UserPermission : 2;       /**< SX0 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSx0PrivilegedPermission : 2; /**< SX0 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcSx1UserPermission : 2;       /**< SX1 User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcSx1PrivilegedPermission : 2; /**< SX1 Privileged Permission 0:RW 1:RO 2:WO 3:NONE
                                                  */
    unsigned int ppcDmaPermission : 2;           /**< Dma Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int ppcApbmuxId : 4;                /**< PPC protected APBMUX num */
    uint8 ppcApbmuxIpId;                         /**< ID number of IP */
} Firewall_PpcIpConfigType;

/** \brief The type of configuarion for the DIO pin channel */
typedef struct
{
    const uint16 *dioChannelID; /**< dio channel id */
    uint16 dioChannelNum;       /**< dio channel number */
} Firewall_DioChannelCfgType;

/** \brief The type of dio configuarions for the core */
typedef struct
{
    unsigned int dioUserPermission : 2;             /**< SF User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int dioPrivilegedPermission : 2;       /**< SF User Permission 0:RW 1:RO 2:WO 3:NONE */
    unsigned int dioCoreId : 4;                     /**< DIO core ID 0:sf 1:sx0 2:sx1 3:sp0 4:sp1  */
    const Firewall_DioChannelCfgType dioChannelCfg; /**< dio channel id */
} Firewall_DioCoreCfgType;

/** \brief The type of the configuarion for the firewall
 *
 * Traceability: SWSR_FIREWALL_028
 */
typedef struct
{
    uint32 macBaseAddr;                              /**< The base address of the firewall module. */
    const Firewall_MacConfigType *macCfgPtr;         /**< The pointer to the configurations of the MAC module. */
    const Firewall_MpcMemPortConfigType *mpcCfgPtr;  /**< The pointer to the configurations of the MPC module. */
    uint8 mpcMemPortCfgNum;                          /**< The number of the memory ports. */
    const Firewall_PpcIpConfigType *ppcBaseIpCfgPtr; /**< The pointer to the basic configurations of the PPC module. */
    uint16 ppcBaseIpCfgNum;                          /**< The number of peripherals which will be configured. */
    const Firewall_PpcIpConfigType *ppcIpCfgPtr;     /**< The pointer to the ip configurations of the PPC module. */
    uint16 ppcIpCfgNum;                              /**< The number of peripherals which will be configured. */
    const Firewall_PpcAddrConfigType *ppcAddrCfgPtr; /**< The pointer to the region configurations of the PPC module. */
    uint16 ppcAddrCfgNum;                            /**< The number of apb regions which will be configured. */
    const Firewall_DioCoreCfgType
        *dioRuleSpaceCfgPtr; /**< The pointer to the region configurations of the Firewall DIO module. */
    uint8 dioCoreCfgNum;     /**< The number of cores which will be configured. */
} Firewall_ConfigType;

/** \brief The type of the illegal access information for the PPC module */
typedef struct
{
    unsigned int ppcApbmuxIpId : 16; /**< APBMUX ID:0~6 */
    unsigned int ppcErrSta : 16;     /**< int status 1:peripheral access error
                                                     2:register access error */
} Firewall_PpcIrqStaType;

/** \brief The type of the illegal access information for the MPC module */
typedef struct
{
    unsigned int mpcMemPortId : 16; /**< memport id:0~22 */
    unsigned int mpcErrSta : 16;    /**< int status 1:peripheral access error 2:register access error */
} Firewall_MpcIrqStaType;

/** \brief The type of the illegal access information for the firewall
 *
 * Traceability: SWSR_FIREWALL_027
 */
typedef struct
{
    Firewall_PpcIrqStaType
        ppcErrInfo[FIREWALL_PPC_APBMUX_MAXNUM]; /**< The illegal access information of the PPC module. */
    Firewall_MpcIrqStaType
        mpcErrInfo[FIREWALL_MPC_MEMPORT_MAXNUM]; /**< The illegal access information of the MPC module. */
} Firewall_ErrInfoType;

/** \} */

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_TYPE_H */
/* End of file */
