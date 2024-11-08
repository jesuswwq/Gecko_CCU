/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-11-06 18:24:50>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef OS_CFG_H
#define OS_CFG_H
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>     <AUTHOR>    <REVISION LOG>
 *  V1.0.0      20141111    bo.zeng     Initial version
 *  V1.1.0      20160418    shi.shu     Add SC34
 *  V2.0.0      20170102    shi.shu     Multicore configuration
 *  V3.0.0      20191121    shun.li     Functional safety version
 *  V3.1.0      20200421    shun.li     Add IOC function
 */

/*=======[I N C L U D E S]====================================================*/
#include "Std_Types.h"

/*=======[F I L E  V E R S I O N   I N F O R M A T I O N]===============================*/
#define     OS_CFG_H_AR_MAJOR_VERSION              4U
#define     OS_CFG_H_AR_MINOR_VERSION              2U
#define     OS_CFG_H_AR_PATCH_VERSION              2U
#define     OS_CFG_H_SW_MAJOR_VERSION              1U
#define     OS_CFG_H_SW_MINOR_VERSION              0U
#define     OS_CFG_H_SW_PATCH_VERSION              0U

/*=======[M A C R O S]========================================================*/

/* --------------------Core-------------------- */
/* Core Definition*/
#define     CFG_CORE_MAX                           3U
#define     OS_CORE_ID_MASTER                      ((Os_CoreIdType)0U)
#define     OS_CORE_ID_0                           ((Os_CoreIdType)0U)
#define     OS_CORE_ID_1                           ((Os_CoreIdType)1U)
#define     OS_CORE_ID_2                           ((Os_CoreIdType)2U)
/* OsNumberOfCores: number of cores that are controlled by the AUTOSAR OS*/
#define     OS_AUTOSAR_CORES                       3U
#define     CFG_CORE0_AUTOSAROS_ENABLE             TRUE
#define     CFG_CORE1_AUTOSAROS_ENABLE             TRUE
#define     CFG_CORE2_AUTOSAROS_ENABLE             TRUE
/* core start address. */
#define     CFG_CORE0_START_ADDRESS                    &_start
#define     CFG_CORE1_START_ADDRESS                    &_start
#define     CFG_CORE2_START_ADDRESS                    &_start
/* --------------------system-------------------- */
/* Scalability Class */
#define     CFG_SC                                  OS_SC1

/* Conformance  Class */
#define     CFG_CC                                  OS_ECC2

/* System Status: stardard, extended */
#define     CFG_STATUS                              OS_STATUS_STANDARD

/* Scheduling policy: full preemptive, no preemptive, mixed preemptive */
#define     CFG_SCHED_POLICY                        OS_PREEMPTIVE_MIXED

/* App Mode Definition */
#define     DONOTCARE                              ((Os_AppModeType)0x0U)
#define     OSDEFAULTAPPMODE                        ((Os_AppModeType)0x1U)

/* Csa Management */
#define     CFG_CSA_MAX_CORE0                       64U
#define     CFG_CSA_MAX_CORE1                       64U
#define     CFG_CSA_MAX_CORE2                       64U

/* system timer */
#define     CFG_SYSTEM_TIMER_ENABLE               TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE0           TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE1           TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE2           TRUE
/* System timer register value define */
#define     CFG_REG_OSTIMER_VALUE_CORE0             100000U
#define     CFG_REG_OSTIMER_VALUE_CORE1             100000U
#define     CFG_REG_OSTIMER_VALUE_CORE2             100000U

/* Timing Protection */
#define     CFG_TIMING_PROTECTION_ENABLE            FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE0     FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE1     FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE2     FALSE

/* timing protection timer register value */
#define     CFG_REG_TP_TIMER_VALUE_CORE0            10000U
#define     CFG_REG_TP_TIMER_VALUE_CORE1            10000U
#define     CFG_REG_TP_TIMER_VALUE_CORE2            10000U

#define     CFG_SYSTEM_STACK_MAX                    1U

/* wether support trace function */
#define     CFG_TRACE_ENABLE                        FALSE

/* wether check stack overflow */
#define     CFG_STACK_CHECK                         TRUE

#define     CFG_CRITICAL_ZONE_MAX                   1U

/* Hooks */
#define     CFG_ERRORHOOK                           TRUE
#define     CFG_PRETASKHOOK                         FALSE
#define     CFG_POSTTASKHOOK                        FALSE
#define     CFG_STARTUPHOOK                         TRUE
#define     CFG_SHUTDOWNHOOK                        TRUE
#define     CFG_USEGETSERVICEID                     FALSE
#define     CFG_USEPARAMETERACCESS                  TRUE
#define     CFG_PROTECTIONHOOK                      FALSE
#define     CFG_READYTASKHOOK                       FALSE

#define     CFG_APPL_STARTUPHOOK                   FALSE
#define     CFG_APPL_ERRORHOOK                     FALSE
#define     CFG_APPL_SHUTDOWNHOOK                  FALSE

/* --------------------Task Definition-------------------- */  
 /* number of task and resource priority in system */
#define     CFG_PRIORITY_MAX_CORE0                  10U
#define     CFG_PRIORITY_MAX_CORE1                  10U
#define     CFG_PRIORITY_MAX_CORE2                  10U
/* group of priority */
#define     CFG_PRIORITY_GROUP_CORE0                1U
#define     CFG_PRIORITY_GROUP_CORE1                1U
#define     CFG_PRIORITY_GROUP_CORE2                1U
/* All of the tasks */
#define     CFG_TASK_MAX                           30U
#define     CFG_EXTENDED_TASK_MAX                  0U
/* Core0 */
#define     CFG_TASK_MAX_CORE0                      10U
#define     CFG_EXTENDED_TASK_MAX_CORE0             0U
#define     OsTask__Core0_100ms                                 ((Os_TaskType)0x0000U)
#define     OsTask__Core0_10ms                                  ((Os_TaskType)0x0001U)
#define     OsTask__Core0_1ms                                   ((Os_TaskType)0x0002U)
#define     OsTask__Core0_1s                                ((Os_TaskType)0x0003U)
#define     OsTask__Core0_20ms                                  ((Os_TaskType)0x0004U)
#define     OsTask__Core0_2ms                                   ((Os_TaskType)0x0005U)
#define     OsTask__Core0_50ms                                  ((Os_TaskType)0x0006U)
#define     OsTask__Core0_5ms                                   ((Os_TaskType)0x0007U)
#define     OsTask_Core0_Init                                   ((Os_TaskType)0x0008U)
#define     OS_TASK_IDLE_CORE0                      ((Os_TaskType)0x0009U)
/* Core1 */
#define     CFG_TASK_MAX_CORE1                      10U
#define     CFG_EXTENDED_TASK_MAX_CORE1             0U
#define     OsTask__Core1_100ms                                 ((Os_TaskType)0x1000U)
#define     OsTask__Core1_10ms                                  ((Os_TaskType)0x1001U)
#define     OsTask__Core1_1ms                                   ((Os_TaskType)0x1002U)
#define     OsTask__Core1_1s                                ((Os_TaskType)0x1003U)
#define     OsTask__Core1_20ms                                  ((Os_TaskType)0x1004U)
#define     OsTask__Core1_2ms                                   ((Os_TaskType)0x1005U)
#define     OsTask__Core1_50ms                                  ((Os_TaskType)0x1006U)
#define     OsTask__Core1_5ms                                   ((Os_TaskType)0x1007U)
#define     OsTask_Core1_Init                                   ((Os_TaskType)0x1008U)
#define     OS_TASK_IDLE_CORE1                      ((Os_TaskType)0x1009U)
/* Core2 */
#define     CFG_TASK_MAX_CORE2                      10U
#define     CFG_EXTENDED_TASK_MAX_CORE2             0U
#define     OsTask__Core2_100ms                                 ((Os_TaskType)0x2000U)
#define     OsTask__Core2_10ms                                  ((Os_TaskType)0x2001U)
#define     OsTask__Core2_1ms                                   ((Os_TaskType)0x2002U)
#define     OsTask__Core2_1s                                ((Os_TaskType)0x2003U)
#define     OsTask__Core2_20ms                                  ((Os_TaskType)0x2004U)
#define     OsTask__Core2_2ms                                   ((Os_TaskType)0x2005U)
#define     OsTask__Core2_50ms                                  ((Os_TaskType)0x2006U)
#define     OsTask__Core2_5ms                                   ((Os_TaskType)0x2007U)
#define     OsTask_Core2_Init                                   ((Os_TaskType)0x2008U)
#define     OS_TASK_IDLE_CORE2                      ((Os_TaskType)0x2009U)
/* --------------------ISR Definition-------------------- */
#define     CFG_ISR_MAX                             21U
#define     CFG_ISR2_MAX                            21U
/* wether support interrupt nest */
#define     CFG_INT_NEST_ENABLE                     FALSE
/* highest ISR2 interrupt priority */   
#define     CFG_ISR2_IPL_MAX_CORE0          10U
#define     CFG_ISR2_IPL_MAX_CORE1          10U
#define     CFG_ISR2_IPL_MAX_CORE2          10U

/* Core0 */
#define     CFG_ISR_MAX_CORE0                       17U
#define     CFG_ISR2_MAX_CORE0                      17U
#define     CFG_SYS_TIMER_CORE0_ID                  0x0000U   /*system timer*/
#define     CFG_REMOTECALL_CORE0_ID                    0x0001U    /*Remote Call Software interrupt*/
#define     CFG_ISR_CANFD3_CANFD_ID                 0x0002U
#define     CFG_ISR_CANFD4_CANFD_ID                 0x0003U
#define     CFG_ISR_CANFD5_CANFD_ID                 0x0004U
#define     CFG_ISR_CANFD6_CANFD_ID                 0x0005U
#define     CFG_ISR_CANFD7_CANFD_ID                 0x0006U
#define     CFG_ISR_CANFD8_CANFD_ID                 0x0007U
#define     CFG_ISR_ETMR2_CHN_B_ID                  0x0008U
#define     CFG_ISR_GPIO_AP_SYNC_DGPIO_ID                   0x0009U
#define     CFG_ISR_SADC1_O_SADC_ID                 0x000aU
#define     CFG_ISR_SADC2_O_SADC_ID                 0x000bU
#define     CFG_ISR_SPI7_SPI_ID                 0x000cU
#define     CFG_ISR_UART3_ID                    0x000dU
#define     CFG_ISR_UART11_ID                   0x000eU
#define     CFG_ISR_UART14_ID                   0x000fU
#define     CFG_ISR_WDT1_WDT_ID                 0x0010U
/* Core1 */
#define     CFG_ISR_MAX_CORE1                       2U
#define     CFG_ISR2_MAX_CORE1                      2U
#define     CFG_SYS_TIMER_CORE1_ID                  0x1000U   /*system timer*/
#define     CFG_REMOTECALL_CORE1_ID                    0x1001U    /*Remote Call Software interrupt*/
/* Core2 */
#define     CFG_ISR_MAX_CORE2                       2U
#define     CFG_ISR2_MAX_CORE2                      2U
#define     CFG_SYS_TIMER_CORE2_ID                  0x2000U   /*system timer*/
#define     CFG_REMOTECALL_CORE2_ID                    0x2001U    /*Remote Call Software interrupt*/
/* --------------------Counter Definition-------------------- */
#define     CFG_COUNTER_MAX                         3U
/* Core0 */
#define     CFG_COUNTER_MAX_CORE0                   1U

#define     SystemTimer_Core0                       ((Os_CounterType)0x0000U)
#define     OS_TICKS2NS_SystemTimer_Core0(ticks)    (ticks*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core0(ticks)    (ticks*1000)
#define     OS_TICKS2MS_SystemTimer_Core0(ticks)    (ticks*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core0(ticks)   (ticks*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core0(ns)       (ns/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core0(us)       (us/1000)
#define     OS_MS2TICKS_SystemTimer_Core0(ms)       (ms*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core0(sec)     (sec*1000000/1000)
/* Core1 */
#define     CFG_COUNTER_MAX_CORE1                   1U

#define     SystemTimer_Core1                       ((Os_CounterType)0x1000U)
#define     OS_TICKS2NS_SystemTimer_Core1(ticks)    (ticks*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core1(ticks)    (ticks*1000)
#define     OS_TICKS2MS_SystemTimer_Core1(ticks)    (ticks*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core1(ticks)   (ticks*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core1(ns)       (ns/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core1(us)       (us/1000)
#define     OS_MS2TICKS_SystemTimer_Core1(ms)       (ms*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core1(sec)     (sec*1000000/1000)
/* Core2 */
#define     CFG_COUNTER_MAX_CORE2                   1U

#define     SystemTimer_Core2                       ((Os_CounterType)0x2000U)
#define     OS_TICKS2NS_SystemTimer_Core2(ticks)    (ticks*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core2(ticks)    (ticks*1000)
#define     OS_TICKS2MS_SystemTimer_Core2(ticks)    (ticks*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core2(ticks)   (ticks*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core2(ns)       (ns/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core2(us)       (us/1000)
#define     OS_MS2TICKS_SystemTimer_Core2(ms)       (ms*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core2(sec)     (sec*1000000/1000)
/* --------------------Alarm Definition-------------------- */
#define     CFG_ALARM_MAX                           24U
#define     CFG_AUTO_ALARM_MAX                      0U
/* Core0 */
#define     CFG_ALARM_MAX_CORE0                     8U
#define     CFG_AUTO_ALARM_MAX_CORE0                0U
#define     OsAlarm_Core0_100ms                                 ((Os_AlarmType)0x0000U)
#define     OsAlarm_Core0_10ms                                  ((Os_AlarmType)0x0001U)
#define     OsAlarm_Core0_1ms                               ((Os_AlarmType)0x0002U)
#define     OsAlarm_Core0_1s                                ((Os_AlarmType)0x0003U)
#define     OsAlarm_Core0_20ms                                  ((Os_AlarmType)0x0004U)
#define     OsAlarm_Core0_2ms                               ((Os_AlarmType)0x0005U)
#define     OsAlarm_Core0_50ms                                  ((Os_AlarmType)0x0006U)
#define     OsAlarm_Core0_5ms                               ((Os_AlarmType)0x0007U)
/* Core1 */
#define     CFG_ALARM_MAX_CORE1                     8U
#define     CFG_AUTO_ALARM_MAX_CORE1                0U
#define     OsAlarm_Core1_100ms                                 ((Os_AlarmType)0x1000U)
#define     OsAlarm_Core1_10ms                                  ((Os_AlarmType)0x1001U)
#define     OsAlarm_Core1_1ms                               ((Os_AlarmType)0x1002U)
#define     OsAlarm_Core1_1s                                ((Os_AlarmType)0x1003U)
#define     OsAlarm_Core1_20ms                                  ((Os_AlarmType)0x1004U)
#define     OsAlarm_Core1_2ms                               ((Os_AlarmType)0x1005U)
#define     OsAlarm_Core1_50ms                                  ((Os_AlarmType)0x1006U)
#define     OsAlarm_Core1_5ms                               ((Os_AlarmType)0x1007U)
/* Core2 */
#define     CFG_ALARM_MAX_CORE2                     8U
#define     CFG_AUTO_ALARM_MAX_CORE2                0U
#define     OsAlarm_Core2_100ms                                 ((Os_AlarmType)0x2000U)
#define     OsAlarm_Core2_10ms                                  ((Os_AlarmType)0x2001U)
#define     OsAlarm_Core2_1ms                               ((Os_AlarmType)0x2002U)
#define     OsAlarm_Core2_1s                                ((Os_AlarmType)0x2003U)
#define     OsAlarm_Core2_20ms                                  ((Os_AlarmType)0x2004U)
#define     OsAlarm_Core2_2ms                               ((Os_AlarmType)0x2005U)
#define     OsAlarm_Core2_50ms                                  ((Os_AlarmType)0x2006U)
#define     OsAlarm_Core2_5ms                               ((Os_AlarmType)0x2007U)
/* --------------------Schedule Table Definition-------------------- */
#define     CFG_SCHEDTBL_MAX                        0U
/* Core0 */
#define     CFG_SCHEDTBL_MAX_CORE0                  0U
/* Core1 */
#define     CFG_SCHEDTBL_MAX_CORE1                  0U
/* Core2 */
#define     CFG_SCHEDTBL_MAX_CORE2                  0U
/* --------------------Event Definition-------------------- */
#define     CFG_EVENT_MAX                           0U
/* -------------------Resource Definition------------------ */
#define     CFG_USERESSCHEDULER                     TRUE
#define     CFG_RESOURCE_MAX                         3U     /* STD + INTERNAL */
#define     CFG_STD_RESOURCE_MAX                    3U
#define     CFG_INTERNAL_RESOURCE_MAX               0U
/* Core0*/
#define     CFG_RESOURCE_MAX_CORE0                  1U
#define     CFG_STD_RESOURCE_MAX_CORE0              1U
#define     CFG_INTERNAL_RESOURCE_MAX_CORE0         0U
#define     RES_SCHEDULER_CORE0                     ((Os_ResourceType)0x0000U)
/* Core1*/
#define     CFG_RESOURCE_MAX_CORE1                  1U
#define     CFG_STD_RESOURCE_MAX_CORE1              1U
#define     CFG_INTERNAL_RESOURCE_MAX_CORE1         0U
#define     RES_SCHEDULER_CORE1                     ((Os_ResourceType)0x1000U)
/* Core2*/
#define     CFG_RESOURCE_MAX_CORE2                  1U
#define     CFG_STD_RESOURCE_MAX_CORE2              1U
#define     CFG_INTERNAL_RESOURCE_MAX_CORE2         0U
#define     RES_SCHEDULER_CORE2                     ((Os_ResourceType)0x2000U)
/* ---------------OsApplication Definition----------------- */
#define     CFG_OSAPPLICATION_MAX                   6U
#define     OsApplication_0                     ((Os_ApplicationType)0U)
#define     OsApplication_1                     ((Os_ApplicationType)1U)
#define     OsApplication_2                     ((Os_ApplicationType)2U)
#define     APP_SYS_CORE0                              ((Os_ApplicationType)3U)
#define     APP_SYS_CORE1                              ((Os_ApplicationType)4U)
#define     APP_SYS_CORE2                              ((Os_ApplicationType)5U)
/* ---------------OsAppEcucPartitionRef-------------------- */
/*Spinlock Definition*/
#define     CFG_SPINLOCK_MAX                       0U

/*  whether shell the os service*/
#define     CFG_SRV_SHELLOS                         FALSE

/* SC34: Memory Protection. */
#define     CFG_MEMORY_PROTECTION_ENABLE            FALSE

/* SC34: Service Protection. */
#define     CFG_SERVICE_PROTECTION_ENABLE           FALSE

/* -------------Trusted Function Definition---------------- */
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX          0U
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0    0U
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1    0U
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2    0U

#define     CFG_CPU_USAGE_ENABLE                   FALSE

#endif /* #define OS_CFG_H */
/*=======[E N D   O F   F I L E]==============================================*/

