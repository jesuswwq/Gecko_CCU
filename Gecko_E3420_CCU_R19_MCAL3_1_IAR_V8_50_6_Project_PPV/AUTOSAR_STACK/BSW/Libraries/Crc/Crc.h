/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Crc.h                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : ShenXu,Yb                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef CRC_H_
#define CRC_H_
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*@ req<SWS_Crc_00048> */
#define CRC_VENDOR_ID                   (62u)
#define CRC_MODULE_ID                   (201u)
#define CRC_AR_RELEASE_MAJOR_VERSION    (4u)
#define CRC_AR_RELEASE_MINOR_VERSION    (5u)
#define CRC_AR_RELEASE_REVISION_VERSION (0u)
#define CRC_SW_MAJOR_VERSION            (2u)
#define CRC_SW_MINOR_VERSION            (1u)
#define CRC_SW_PATCH_VERSION            (0u)

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Crc_Cfg.h"

/*@ req<SWS_Crc_00017>,<SWS_Crc_00021>,<SWS_Crc_00011> */
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*
 * Brief               This service returns the version information of
 *                     this module
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Versioninfo: Pointer to where to store the version
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
#define Crc_GetVersionInfo(VersionInfo)                         \
    do                                                          \
    {                                                           \
        (VersionInfo)->vendorID = CRC_VENDOR_ID;                \
        (VersionInfo)->moduleID = CRC_MODULE_ID;                \
        (VersionInfo)->instanceID = 0u;                         \
        (VersionInfo)->sw_major_version = CRC_SW_MAJOR_VERSION; \
        (VersionInfo)->sw_minor_version = CRC_SW_MINOR_VERSION; \
        (VersionInfo)->sw_patch_version = CRC_SW_PATCH_VERSION; \
        (VersionInfo)->sw_major_version = CRC_SW_MAJOR_VERSION; \
        (VersionInfo)->sw_minor_version = CRC_SW_MINOR_VERSION; \
        (VersionInfo)->sw_patch_version = CRC_SW_PATCH_VERSION; \
    } while (0)

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
#if (STD_ON == CRC8_ALGORITHM)
/*************************************************************************/
/*
 * Brief               This service makes a CRC8 calculation on Crc_Length
 *                     data bytes, with SAE J1850 parameters
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Crc_DataPtr:Pointer to start address of data block
 *                     to be calculated.
 *                     Crc_Length:Length of data block to be calculated in bytes.
 *                     Crc_StartValue8:Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     TRUE: First call in a sequence or individual CRC calculation;
 *                     start from initial value, ignore Crc_StartValue8.
 *                     FALSE:Subsequent call in a call sequence; Crc_StartValue8 is
 *                     interpreted to be the return value of the previous function call.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
/* req<SWS_Crc_00031>*/

extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    VAR(uint32, AUTOMATIC) Crc_Length,
    VAR(uint8, AUTOMATIC) Crc_StartValue8,
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);

#endif /* STD_ON == CRC8_ALGORITHM */

#if (STD_ON == CRC8H2F_ALGORITHM)
/*************************************************************************/
/*
 * Brief               This service makes a CRC8 calculation with the
 *                     Polynomial 0x2F on Crc_Length
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Crc_DataPtr:Pointer to start address of data block
 *                     to be calculated.
 *                     Crc_Length:Length of data block to be calculated in bytes.
 *                     Crc_StartValue8H2F:Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     TRUE: First call in a sequence or individual CRC calculation;
 *                     start from initial value, ignore Crc_StartValue8.
 *                     FALSE:Subsequent call in a call sequence; Crc_StartValue8 is
 *                     interpreted to be the return value of the previous function call.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
/* req<SWS_Crc_00043>*/

extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    VAR(uint32, AUTOMATIC) Crc_Length,
    VAR(uint8, AUTOMATIC) Crc_StartValue8H2F,
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);

#endif /* STD_ON == CRC8H2F_ALGORITHM */

#if (STD_ON == CRC16_ALGORITHM)
/*************************************************************************/
/*
 * Brief               This service makes a CRC16 calculation on Crc_Length
 *                     data bytes.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Crc_DataPtr:Pointer to start address of data block
 *                     to be calculated.
 *                     Crc_Length:Length of data block to be calculated in bytes.
 *                     Crc_StartValue16:Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     TRUE: First call in a sequence or individual CRC calculation;
 *                     start from initial value, ignore Crc_StartValue16.
 *                     FALSE:Subsequent call in a call sequence; Crc_StartValue16 is
 *                     interpreted to be the return value of the previous function call.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint16
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
/* req<SWS_Crc_00019>*/

extern FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    VAR(uint32, AUTOMATIC) Crc_Length,
    VAR(uint16, AUTOMATIC) Crc_StartValue16,
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);

#endif /* STD_ON == CRC16_ALGORITHM */

#if (STD_ON == CRC32_ALGORITHM)
/*************************************************************************/
/*
 * Brief               This service makes a CRC32 calculation on Crc_Length
 *                     data bytes.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Crc_DataPtr: Pointer to start address of data block
 *                     to be calculated.
 *                     Crc_Length: Length of data block to be calculated in bytes.
 *                     Crc_StartValue32: Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     TRUE: First call in a sequence or individual CRC calculation;
 *                     start from initial value, ignore Crc_StartValue32.
 *                     FALSE: Subsequent call in a call sequence; Crc_StartValue32 is
 *                     interpreted to be the return value of the previous function call.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint16
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
/* req<SWS_Crc_00020>*/

extern FUNC(uint32, CRC_CODE) Crc_CalculateCRC32(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    VAR(uint32, AUTOMATIC) Crc_Length,
    VAR(uint32, AUTOMATIC) Crc_StartValue32,
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);

#endif /* STD_ON == CRC32_ALGORITHM */

#if (STD_ON == CRC32P4_ALGORITHM)
/*************************************************************************/
/*
 * Brief               This service makes a CRC32 calculation on Crc_Length
 *                     data bytes.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Crc_DataPtr: Pointer to start address of data block
 *                     to be calculated.
 *                     Crc_Length: Length of data block to be calculated in bytes.
 *                     Crc_StartValue32: Start value when the algorithm starts.
 *                     Crc_IsFirstCall:
 *                     TRUE: First call in a sequence or individual CRC calculation;
 *                     start from initial value, ignore Crc_StartValue32.
 *                     FALSE: Subsequent call in a call sequence; Crc_StartValue32 is
 *                     interpreted to be the return value of the previous function call.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint16
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
/* req<SWS_Crc_00058>*/

extern FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    VAR(uint32, AUTOMATIC) Crc_Length,
    VAR(uint32, AUTOMATIC) Crc_StartValue32,
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);

#endif /* STD_ON == CRC32P4_ALGORITHM */

#if (STD_ON == CRC64_ALGORITHM)

extern FUNC(uint64, CRC_CODE) Crc_CalculateCRC64(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    VAR(uint64, AUTOMATIC) Crc_Length,
    VAR(uint64, AUTOMATIC) Crc_StartValue64,
    VAR(boolean, AUTOMATIC) Crc_IsFirstCall);

#endif /* STD_ON == CRC64_ALGORITHM */

#endif /* CRC_H_ */
