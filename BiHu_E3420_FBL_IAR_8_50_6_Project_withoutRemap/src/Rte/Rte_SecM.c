/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_SecM.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-03 18:06:32>
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
#define RTE_SECM_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_SecM.h"
#include "Dcm_Cfg.h"
#include "Dcm.h"
#include "Dcm_Dsp.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_SEC_STORAGE RTE_CFG_SEC_STORAGE
#define RTE_SEC_SIZE_TYPE (sizeof(security)/sizeof(security[0]))
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
extern void Dcm_StartSecurityTimer(uint8 attemptId, uint32 timeOut);
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
static struct secAttemptType
{
    uint32 secAttempt;
} security[DCM_SECURITY_NUM];
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
/*@}*/
/*==============================SecurityCounter ===================================*/
/******************************************************************************/
/*
 * @brief              [Rte_SecM_DecreaseSecurityCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [chann                            description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_SecM_DecreaseSecurityCounter(uint8 chann)
{
    if(chann < RTE_SEC_SIZE_TYPE)
    {
        if(security[chann].secAttempt > 0u)
        {
            security[chann].secAttempt--;
        }
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_SecM_IncreaseSecurityCounter_Only description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [chann                      description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_SecM_IncreaseSecurityCounter_Only(uint8 chann)
{
    boolean ret = TRUE;
#if 0    
    uint8 FAA;
    if(chann < RTE_SEC_SIZE_TYPE)
    {
        if(security[chann].secAttempt < DCM_SECURITY_ATTEMPT_NUM)
        {
            security[chann].secAttempt++;
#if (RTE_SEC_STORAGE == STD_ON)
            FAA = security[chann].secAttempt;
            Dcm_SendPending();
            Rte_Data_Write_SecurityAccess(chann,FAA);
#endif
            if(security[chann].secAttempt >= DCM_SECURITY_ATTEMPT_NUM)
            {
                Dcm_StartSecurityTimer(chann, DCM_SECURITY_TIME);
                ret = FALSE;
            }

        }
    }
#endif    
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_SecM_IncreaseSecurityCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [chann                            description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
Dcm_NrcType Rte_SecM_IncreaseSecurityCounter(uint8 chann)
{
    Dcm_NrcType ret = DCM_E_31_REQUEST_OUT_OF_RANGE;
    boolean FAA;

    if(chann < RTE_SEC_SIZE_TYPE)
    {
        if(security[chann].secAttempt < DCM_SECURITY_ATTEMPT_NUM)
        {
            security[chann].secAttempt++;
        }

        if (security[chann].secAttempt <  DCM_SECURITY_ATTEMPT_NUM)
        {
            ret = DCM_E_35_INVALID_KEY;
        }
        else
        {
            ret = DCM_E_36_EXCEED_NUMBER_OF_ATTEMPTS;
            Dcm_StartSecurityTimer(chann, DCM_SECURITY_TIME);
#if (RTE_SEC_STORAGE == STD_ON)
            FAA = TRUE;
            Dcm_SendPending();
            Rte_Data_Write_SecurityAccess(chann, FAA);
#endif
        }
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_SecM_ClearSecurityCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [chann                         description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_SecM_ClearSecurityCounter(uint8 chann)
{
    volatile boolean FAA;

    if(chann < RTE_SEC_SIZE_TYPE)
    {
        if (security[chann].secAttempt > 0u)
        {
            security[chann].secAttempt = 0u;
#if (RTE_SEC_STORAGE == STD_ON)
            FAA = FALSE;
            Dcm_SendPending();
            Rte_Data_Write_SecurityAccess(chann, FAA);
#endif
        }
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_SecM_InitSecurityCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_SecM_InitSecurityCounter(void)
{
    uint8 chann = 0;
    uint8 FAA = 0u;

    for(chann = 0u; chann < DCM_SECURITY_NUM; chann++)
    {
#if (RTE_SEC_STORAGE == STD_ON)

        if(TRUE == Rte_Data_Read_SecurityAccess(chann, (uint8*)&FAA))
        {
            if(FAA == TRUE)
            {
                security[chann].secAttempt = DCM_SECURITY_ATTEMPT_NUM;
                Dcm_StartSecurityTimer(chann, DCM_SECURITY_TIME);
            }
            else
            {
#endif
                security[chann].secAttempt = 0u;
               Dcm_StartSecurityTimer(chann, APPL_START_SECURITY_TIME);
#if (RTE_SEC_STORAGE == STD_ON)
            }
        }
        else
        {
            security[chann].secAttempt = 0u;
            Dcm_StartSecurityTimer(chann, DCM_SECURITY_TIME);
        }

#endif
    }
}
/*=======[E N D   O F   F I L E]==============================================*/
