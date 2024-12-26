
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : FL_Cfg.c                                                    **
**                                                                            **
**  Created on  : 2024/04/11 14:02:49                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Flash Loader Configuration.                                 **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230817    long.zhu          Initial Version
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FL.h"
#include "FL_Type.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#if 0
/* distinction By block ,
 * should make memory layout first, if the 31 erase service
 * request is in the range of block */
const FL_BlockDescriptorType FL_BlkInfo[FL_NUM_LOGICAL_BLOCKS] =
{
    /* start global address, length, integrity info, dependence info,
     * FL download block type, if TRUE, then participate in the verification of Dependencies.*/
    {
        /* The identifier of the block index */
        (uint8)0x0u,
        /* Used to indicate that consistency check is need */
        (boolean)TRUE,
        /* maximum program cycle */
        (uint16)0xffffu,
        /* block start global address */
        (uint32)0x101c0000u,
        /* block memory length */
        (uint32)0x720000u
    },
};
#endif
#if (FL_FLASH_DRIVER_INTEGRITY_VALID_CHECK == STD_ON)
const uint8 FL_flashdriverintegrityvalid[]={0x50,0x17,0x42,0x39};
#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

