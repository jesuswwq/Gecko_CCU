/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Did.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-03 18:06:15>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>
 *
 */
/*@{*/
#define RTE_DID_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Inc.h"
/*@}*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "DP.h"
#include "Appl_Callout.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/

/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/

/*@}*/
/*====================[ 22 SERVICE TABLE ]===================================*/

/*@{*/
// const did_Group_Type didF183 = {RTE_DID_STORAGE_IN_RAM, RTE_DATA_FINGER_LEN, 0xF183, (uint32)&BootloaderFingerTemp};
/*@}*/
/*=======[Private functions]==================================================*/
/******************************************************************************/
/*
 * @brief              [Rte_FL_WriteDidGroup description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [did                  description]
 *                     [writeData            description]
 *                     [writeLength          description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_FL_WriteDidGroup(const did_Group_Type *did,const uint8 *writeData, uint16 writeLength)
{
    boolean ret = FALSE;
    uint32 length;
    uint32 dest;
    const uint8* source;

    if ((NULL_PTR == did)
        || (NULL_PTR == writeData)
        || (0U == writeLength)
       )
    {
    }
    else
    {

        do
        {
            if(writeLength < did->len)
            {
                length = writeLength;
            }
            else
            {
                length = did->len;
            }

            dest = did->addr;
            source = writeData;

            switch (did->storageType)
            {
                case RTE_DID_STORAGE_IN_EEP:
                    ret = NvMemWrite((uint32)dest, (const uint8*)source, length);
                    break;

                case RTE_DID_STORAGE_IN_RAM:
                    DP_Memcpy((uint8*)dest, (const uint8*)source, length);
                    ret = TRUE;
                    break;

                default:
                    (void)dest;
                    break;
            }
        }
        while(0);
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_FL_ReadDidGroup description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [did                 description]
 *                     [readData            description]
 *                     [readLength          description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_FL_ReadDidGroup(const did_Group_Type *did, uint8 *readData, uint16 *readLength)
{
    boolean ret = FALSE;
    uint32 length;
    uint8* dest;
    uint32 source;
    uint16 *readlen;

    if ((NULL_PTR == did)
        || (NULL_PTR == readData)
        || (NULL_PTR == readLength)
       )
    {
    }
    else
    {

        do/*PRQA S 0771*/
        {
            readlen = readLength;
            (*readlen) = 0;
            length = did->len;

            if (length == 0U)
            {
                break;
            }

            source = did->addr;

            if(NULL_PTR ==  (uint8*)source)
            {
                break;
            }

            dest = readData;
            (*readlen) = (uint16)length;

            switch (did->storageType)
            {
                case RTE_DID_STORAGE_IN_EEP:
                    if(TRUE == NvMemRead((uint32)source, (uint8*)dest, length))
                    {
                        ret = TRUE;
                    }
                    else
                    {
                        DP_Memset(dest, 0u, length);
                    }

                    break;

                case RTE_DID_STORAGE_IN_RAM   :
                case RTE_DID_STORAGE_IN_FLS   :
                case RTE_DID_STORAGE_IN_CONST :
                    if(did->storageType == RTE_DID_STORAGE_IN_FLS)
                    {
                         Mcu_PflashTrapDisable();
                    }

                    DP_Memcpy((uint8*)dest, (uint8*)source, length);

                    if(did->storageType == RTE_DID_STORAGE_IN_FLS)
                    {
                         Mcu_PflashTrapEnable();
                    }

                    ret = TRUE;
                    break;

                default:
			/*nothing*/
                    break;
            }
        }
        while(0);
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_FL_ReadDidGroupCombination description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [didArr                         description]
 *                     [didNum                         description]
 *                     [readData                       description]
 *                     [readLength                     description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_FL_ReadDidGroupCombination(did_Group_Type **didArr, uint8 didNum, uint8 *readData, uint16 *readLength)
{
    boolean ret;
    uint8 i = 0u;
    uint8 *dest;
    *readLength = 0;

    if ((NULL_PTR == didArr)
        || (0u >= didNum)
        || (NULL_PTR == readData)
        || (NULL_PTR == readLength)
       )
    {
        ret = FALSE;
    }
    else
    {
        dest = readData;

        for(; i < didNum; i++)
        {
            *dest = (uint8)((didArr[i]->did >> 8u) & 0xffu);
            dest++;
            (*readLength)++;
            *dest = (uint8)((didArr[i]->did    ) & 0xffu);
            dest++;
            (*readLength)++;
            ret = Rte_FL_ReadDidGroup(didArr[i], dest, readLength);
            dest += didArr[i]->len;/*PRQA S 0488*/
            if (TRUE != ret)
            {
                break;
            }
        }
    }

    return ret;
}
/* 
 *   FL_ResultType FL_ReadDIDGroupXXXX(uint8* readData,uint16* readLength)
 *   {
 *       FL_ResultType ret;
 *       boolean     processContinue = FALSE;
 *       processContinue = Rte_FL_ReadDidGroup(&didGroupXXXX,readData, readLength);
 *       if(TRUE == processContinue)
 *       {
 *           ret = FL_OK;
 *       }
 *       else
 *       {
 *           ret = FL_FAILED;
 *       }
 *       return (ret);
 *   }
 *   FL_ResultType FL_WriteDIDGroupXXXX(const uint8 *data, const uint16 length)
 *   {
 *       FL_ResultType ret;
 *       boolean     processContinue = FALSE;
 *       processContinue = Rte_FL_WriteDidGroup(&DID_ADDR_XXXX,data, length);
 *       if(TRUE == processContinue)
 *       {
 *           ret = FL_OK;
 *       }
 *       else
 *       {
 *           ret = FL_FAILED;
 *       }
 *       return (ret);
 *   }
*/
/*=======[E N D   O F   F I L E]==============================================*/
