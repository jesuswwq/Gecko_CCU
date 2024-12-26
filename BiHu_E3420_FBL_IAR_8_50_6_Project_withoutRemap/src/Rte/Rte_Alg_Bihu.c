/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Alg_Bihu.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-11 10:58:37>
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
#define RTE_ALG_BIHU_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Alg_Bihu.h"
#include "DP.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define PUHUA_SEED_LENGTH 4
#define PUHUA_MASK_LENGTH 4
#define PUHUA_KEY_LENGTH 4
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
/*=======[Private functions]==================================================*/
/*@{*/
/*@}*/
SecM_StatusType SecM_ComputeKey_BiHu(const uint8 *seed, uint8 seed_length,
                                const uint8 *security_constant, uint8 security_constant_length,
                                uint8 *key, uint8 key_length)
{
    /* -------------------Init------------------ */
    uint8 uloop;
    SecM_StatusType ret = SECM_OK;
    uint8 Cal[4];
    uint8 tSeed[4];
    uint8 tXor[4];
    uint8 tKey[4];
    /* -------------------Init End------------------ */
    if (seed == NULL_PTR
        || security_constant == NULL_PTR
        || key == NULL_PTR)
    {
        ret = SECM_NOT_OK;
    }

    if (seed_length != PUHUA_SEED_LENGTH
    || security_constant_length != PUHUA_MASK_LENGTH
    || key_length != PUHUA_KEY_LENGTH)
    {
        ret = SECM_NOT_OK;
    }

    if (ret == SECM_OK)
    {
    	DP_Memcpy(tXor,security_constant,security_constant_length);
    	DP_Memcpy(tSeed,seed,seed_length);
        /* -------------------algorithm------------------ */
    	for (uloop = 0u; uloop < 4u; ++uloop)
    	{
    		Cal[uloop] = tSeed[uloop] ^tXor[uloop];
    	}
		tKey[0] = ((Cal[2]&0x0fu)<<4u)|((Cal[1]&0x0fu)    );
		tKey[1] = ((Cal[3]&0x0fu)<<4u)|((Cal[1]&0xf0u)>>4u);
		tKey[2] = ((Cal[0]&0xf0u)    )|((Cal[2]&0x3cu)>>2u);
		tKey[3] = ((Cal[0]&0x0fu)<<4u)|((Cal[3]&0x78u)>>3u);
        /* -------------------algorithm end--------------- */
    	DP_Memcpy(key, tKey,key_length);
    }
    return ret;
}
/*=======[E N D   O F   F I L E]==============================================*/
