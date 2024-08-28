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
**  FILENAME    : Xcp_Interface.h                                             **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : API declaration and type definitions of interface functions **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*=======[I N C L U D E S]====================================================*/
#ifndef XCP_INTERFACE_H_
#define XCP_INTERFACE_H_

/*=======[I N C L U D E S]====================================================*/
#include "Xcp_Cfg.h"
/*=======[M A C R O S]========================================================*/
typedef struct
{
    uint8* seed;
    uint8 lengthS;
} Xcp_SeedVerifyType;

typedef struct
{
    uint8* key;
    uint8 lengthK;
} Xcp_KeyVerifyType;
/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#if (STD_ON == XCP_SEED_AND_UNLOCK)
extern FUNC(Std_ReturnType, XCP_CODE) Xcp_CreateSeed(uint8* length, uint8* seed, const uint8 resource);
extern boolean Xcp_IsKeyRight(
    const Xcp_SeedVerifyType seedVerify,
    const Xcp_KeyVerifyType keyVerify,
    const uint8 resource);
#endif /* (STD_ON == XCP_SEED_AND_UNLOCK) */

#if (STD_ON == XCP_BUILD_CHECKSUM)
extern void Xcp_InitCrc16CcittTable(void);
extern FUNC(void, XCP_CODE)
    Xcp_ChecksumCompute(const uint32 checksumStartAddress, const uint32 blockSize, uint32* crcResult);
#endif /* (STD_ON == XCP_BUILD_CHECKSUM) */

#if (STD_ON == XCP_PAG_SUPPORT)
extern void Xcp_InitCalMem(void);
#endif /*(STD_ON == XCP_PAG_SUPPORT)*/

#endif /* XCP_INTERFACE_H_ */
