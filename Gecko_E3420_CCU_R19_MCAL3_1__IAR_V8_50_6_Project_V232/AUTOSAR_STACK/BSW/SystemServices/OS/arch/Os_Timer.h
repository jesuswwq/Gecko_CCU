/*============================================================================*/
/*  Copyright (C) 2009-2011, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Timer.h>
 *  @brief      <>
 *  
 * <Compiler:  IAR    MCU:E3110>
 *  
 *  @author     <>
 *  @date       <07-12-2022>
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2022-07-12  shun.li       Initial version.
 */
/*============================================================================*/
#ifndef OS_TIMER_H
#define OS_TIMER_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Types.h"
#include "Os_Internal.h"
/*=======[M A C R O S]========================================================*/
#define TMR1_ADDR                          (0XF0180000)
#define TMR2_ADDR                          (0XF0190000)

#define APB_TIMER1_BASE (0xf0180000u)
#define APB_TIMER8_BASE (0xf0900000u)
#define APB_TIMER7_BASE (0xf08f0000u)
#define APB_TIMER6_BASE (0xf08e0000u)
#define APB_TIMER5_BASE (0xf08d0000u)
#define APB_TIMER4_BASE (0xf08c0000u)
#define APB_TIMER3_BASE (0xf08b0000u)
/* timer register. */
typedef struct {
    volatile uint32 int_sta;  /* offset: 0x0 */
    volatile uint32 int_sta_en;  /* offset: 0x4 */
    volatile uint32 int_sig_en;  /* offset: 0x8 */
    uint8 rsvd0[4];
    volatile uint32 dma_ctrl;  /* offset: 0x10 */
    volatile uint32 dma_sig_mask;  /* offset: 0x14 */
    volatile uint32 sw_rst;  /* offset: 0x18 */
    volatile uint32 fifo_sta;  /* offset: 0x1c */
    volatile uint32 tim_clk_config;  /* offset: 0x20 */
    volatile uint32 cnt_config;  /* offset: 0x24 */
    volatile uint32 cnt_g0_ovf;  /* offset: 0x28 */
    volatile uint32 cnt_g1_ovf;  /* offset: 0x2c */
    volatile uint32 cnt_local_a_ovf;  /* offset: 0x30 */
    volatile uint32 cnt_local_b_ovf;  /* offset: 0x34 */
    volatile uint32 cnt_local_c_ovf;  /* offset: 0x38 */
    volatile uint32 cnt_local_d_ovf;  /* offset: 0x3c */
    volatile uint32 cnt_g0;  /* offset: 0x40 */
    volatile uint32 cnt_g1;  /* offset: 0x44 */
    volatile uint32 cnt_local_a;  /* offset: 0x48 */
    volatile uint32 cnt_local_b;  /* offset: 0x4c */
    volatile uint32 cnt_local_c;  /* offset: 0x50 */
    volatile uint32 cnt_local_d;  /* offset: 0x54 */
    uint8 rsvd1[8];
    volatile uint32 cmp_a_val_upt;  /* offset: 0x60 */
    volatile uint32 cmp0_a_val;  /* offset: 0x64 */
    volatile uint32 cmp1_a_val;  /* offset: 0x68 */
    uint8 rsvd2[4];
    volatile uint32 cmp_b_val_upt;  /* offset: 0x70 */
    volatile uint32 cmp0_b_val;  /* offset: 0x74 */
    volatile uint32 cmp1_b_val;  /* offset: 0x78 */
    uint8 rsvd3[4];
    volatile uint32 cmp_c_val_upt;  /* offset: 0x80 */
    volatile uint32 cmp0_c_val;  /* offset: 0x84 */
    volatile uint32 cmp1_c_val;  /* offset: 0x88 */
    uint8 rsvd4[4];
    volatile uint32 cmp_d_val_upt;  /* offset: 0x90 */
    volatile uint32 cmp0_d_val;  /* offset: 0x94 */
    volatile uint32 cmp1_d_val;  /* offset: 0x98 */
    uint8 rsvd5[4];
    volatile uint32 fifo_a;  /* offset: 0xa0 */
    volatile uint32 fifo_b;  /* offset: 0xa4 */
    volatile uint32 fifo_c;  /* offset: 0xa8 */
    volatile uint32 fifo_d;  /* offset: 0xac */
    volatile uint32 cnt_g0_init;  /* offset: 0xb0 */
    volatile uint32 cnt_g1_init;  /* offset: 0xb4 */
    volatile uint32 cnt_local_a_init;  /* offset: 0xb8 */
    volatile uint32 cnt_local_b_init;  /* offset: 0xbc */
    volatile uint32 cnt_local_c_init;  /* offset: 0xc0 */
    volatile uint32 cnt_local_d_init;  /* offset: 0xc4 */
    volatile uint32 cpt_flt;  /* offset: 0xc8 */
    volatile uint32 sse_ctrl;  /* offset: 0xcc */
    volatile uint32 sse_cpt_a;  /* offset: 0xd0 */
    volatile uint32 sse_cpt_b;  /* offset: 0xd4 */
    volatile uint32 sse_cpt_c;  /* offset: 0xd8 */
    volatile uint32 sse_cpt_d;  /* offset: 0xdc */
    volatile uint32 sse_cmp_a;  /* offset: 0xe0 */
    volatile uint32 sse_cmp_b;  /* offset: 0xe4 */
    volatile uint32 sse_cmp_c;  /* offset: 0xe8 */
    volatile uint32 sse_cmp_d;  /* offset: 0xec */
    uint8 rsvd6[16];
    volatile uint32 cpt_a_config;  /* offset: 0x100 */
    volatile uint32 cpt_b_config;  /* offset: 0x104 */
    volatile uint32 cpt_c_config;  /* offset: 0x108 */
    volatile uint32 cpt_d_config;  /* offset: 0x10c */
    volatile uint32 cmp_a_config;  /* offset: 0x110 */
    volatile uint32 cmp_b_config;  /* offset: 0x114 */
    volatile uint32 cmp_c_config;  /* offset: 0x118 */
    volatile uint32 cmp_d_config;  /* offset: 0x11c */
}timer;

#define TIMER1_BASE (0xf0180000u)

#define FM_TIM_CLK_CONFIG_SRC_CLK_SEL   (0x3U << 16U)
#define FV_TIM_CLK_CONFIG_SRC_CLK_SEL(v) \
    (((v) << 16U) & FM_TIM_CLK_CONFIG_SRC_CLK_SEL)
#define GFV_TIM_CLK_CONFIG_SRC_CLK_SEL(v) \
    (((v) & FM_TIM_CLK_CONFIG_SRC_CLK_SEL) >> 16U)

#define FM_TIM_CLK_CONFIG_DIV_NUM   (0xffffU << 0U)
#define FV_TIM_CLK_CONFIG_DIV_NUM(v) \
    (((v) << 0U) & FM_TIM_CLK_CONFIG_DIV_NUM)
#define GFV_TIM_CLK_CONFIG_DIV_NUM(v) \
    (((v) & FM_TIM_CLK_CONFIG_DIV_NUM) >> 0U)
/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"



#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #ifndef OS_EXTEND_H */
/*=======[E N D   O F   F I L E]==============================================*/
