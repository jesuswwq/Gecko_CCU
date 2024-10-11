/********************************************************************/
/*  Copyright (C) 2009-2011, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  File         interrupt.c
 *  Brief        
 *
 *  Revision History:
 *
 *     V0.1.0  2021-09-26  Initial version.
 */
 /*******************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"
#include "sdrv_btm.h"
#include "__regs_base.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)

const sdrv_btm_hw_cnt_cfg_t   btm1_sys_timer = 
{ 
    1u,
    1u,
    0u,
    SDRV_BTM_DIRECT,
    SDRV_BTM_DIRECT,
    SDRV_BTM_CNT_UP,
    SDRV_BTM_CONTINOUS_MODE
};
const sdrv_btm_hw_cnt_cfg_t   btm2_sys_timer = 
{ 
    1u,
    1u,
    0u,
    SDRV_BTM_DIRECT,
    SDRV_BTM_DIRECT,
    SDRV_BTM_CNT_UP,
    SDRV_BTM_CONTINOUS_MODE
};
const sdrv_btm_hw_cnt_cfg_t   btm3_sys_timer = 
{ 
    1u,
    1u,
    0u,
    SDRV_BTM_DIRECT,
    SDRV_BTM_DIRECT,
    SDRV_BTM_CNT_UP,
    SDRV_BTM_CONTINOUS_MODE
};
const sdrv_btm_hw_cnt_cfg_t   btm4_sys_timer = 
{ 
    1u,
    1u,
    0u,
    SDRV_BTM_DIRECT,
    SDRV_BTM_DIRECT,
    SDRV_BTM_CNT_UP,
    SDRV_BTM_CONTINOUS_MODE
};
const sdrv_btm_hw_cnt_cfg_t   btm5_sys_timer = 
{ 
    1u,
    1u,
    0u,
    SDRV_BTM_DIRECT,
    SDRV_BTM_DIRECT,
    SDRV_BTM_CNT_UP,
    SDRV_BTM_CONTINOUS_MODE
};
const sdrv_btm_hw_cnt_cfg_t   btm6_sys_timer = 
{ 
    1u,
    1u,
    0u,
    SDRV_BTM_DIRECT,
    SDRV_BTM_DIRECT,
    SDRV_BTM_CNT_UP,
    SDRV_BTM_CONTINOUS_MODE
};

/******************************************************************************/
/*
 * Brief                <Os_ArchInitSystemTimer>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 * REQ ID               <DD_1_0898, DD_1_1305>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitSystemTimer(void)
{
    if(Os_SCB.sysCore == 0){
        sdrv_btm_lld_init(APB_BTM1_BASE, SDRV_BTM_G0, &btm1_sys_timer);
        sdrv_btm_lld_set_sta_en(APB_BTM1_BASE, SDRV_BTM_G0);
        sdrv_btm_lld_set_sig_en(APB_BTM1_BASE, SDRV_BTM_G0);
        sdrv_btm_lld_timer_start(APB_BTM1_BASE, SDRV_BTM_G0, 75000);
    }
    else if(Os_SCB.sysCore == 1){
        sdrv_btm_lld_init(APB_BTM2_BASE, SDRV_BTM_G0, &btm2_sys_timer);
        sdrv_btm_lld_set_sta_en(APB_BTM2_BASE, SDRV_BTM_G0);
        sdrv_btm_lld_set_sig_en(APB_BTM2_BASE, SDRV_BTM_G0);
        sdrv_btm_lld_timer_start(APB_BTM2_BASE, SDRV_BTM_G0, 75000);
    }
    else if(Os_SCB.sysCore == 2){
        sdrv_btm_lld_init(APB_BTM3_BASE, SDRV_BTM_G0, &btm3_sys_timer);
        sdrv_btm_lld_set_sta_en(APB_BTM3_BASE, SDRV_BTM_G0);
        sdrv_btm_lld_set_sig_en(APB_BTM3_BASE, SDRV_BTM_G0);
        sdrv_btm_lld_timer_start(APB_BTM3_BASE, SDRV_BTM_G0, 75000);
    }
}
#endif

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
/******************************************************************************/
/*
 * Brief                <Initialize a time-protected clock for each CPU running OS>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchInitCPU>
 * REQ ID               <DD_1_0900, DD_1_1304>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitTimingProtTimer(void)
{
    switch (Os_SCB.sysCore)
    {
        case 0:
            sdrv_btm_lld_init(APB_BTM4_BASE, SDRV_BTM_G0, &btm4_sys_timer);
            sdrv_btm_lld_set_sta_en(APB_BTM4_BASE, SDRV_BTM_G0);
            sdrv_btm_lld_set_sig_en(APB_BTM4_BASE, SDRV_BTM_G0);
            sdrv_btm_lld_timer_start(APB_BTM4_BASE, SDRV_BTM_G0, 7500);
            break;
        case 1:
            sdrv_btm_lld_init(APB_BTM5_BASE, SDRV_BTM_G0, &btm5_sys_timer);
            sdrv_btm_lld_set_sta_en(APB_BTM5_BASE, SDRV_BTM_G0);
            sdrv_btm_lld_set_sig_en(APB_BTM5_BASE, SDRV_BTM_G0);
            sdrv_btm_lld_timer_start(APB_BTM5_BASE, SDRV_BTM_G0, 7500);
            break;
        case 2:
            sdrv_btm_lld_init(APB_BTM6_BASE, SDRV_BTM_G0, &btm6_sys_timer);
            sdrv_btm_lld_set_sta_en(APB_BTM6_BASE, SDRV_BTM_G0);
            sdrv_btm_lld_set_sig_en(APB_BTM6_BASE, SDRV_BTM_G0);
            sdrv_btm_lld_timer_start(APB_BTM6_BASE, SDRV_BTM_G0, 7500);
            break;
        default:
            while(1) { ; }
            break;
    }
}
#endif

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
