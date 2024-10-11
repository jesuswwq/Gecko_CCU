/**
 * @file Vic_Irq_Cfg.h
 * @brief Vic_Irq (vector interrupt controller irquest) header file.
 * @details Compatible to "Specification of VicIrqDriver, CP, 4.3.1"
 * @date 2020-10-27 17:54:03
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/
#ifndef VIC_IRQ_CFG_H
#define VIC_IRQ_CFG_H

/*becarefule :can not be used when arutosar os is used*/
// #define CONFIG_VIC_IRQ_INTERRUPT_MODE
// #define CONFIG_VIC_INT_NEST_AUTO_ENABLE
// #define CONFIG_VIC_INT_NEST_MAX_CNT 16

#define CONFIG_VIC_CORE_NUM     3
/*becarefule :can not be used when arutosar os is used*/
// #ifdef CONFIG_VIC_INT_NEST_AUTO_ENABLE
// #define CONFIG_VIC_INT_NEST_ERRATA
// #endif

#endif
