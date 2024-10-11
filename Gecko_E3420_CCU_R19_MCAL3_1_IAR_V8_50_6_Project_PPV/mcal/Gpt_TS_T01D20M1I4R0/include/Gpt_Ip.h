/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/

/** *****************************************************************************************************
 *  \file     Gpt_Ip.h                                                                                  *
 *  \brief    This file contains interface header for CAN MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef GPT_IP_H
#define GPT_IP_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Gpt_Cfg.h"
#include "Gpt_Types.h"

/********************************************************************************************************
 *                                    Private Type Declarations                                         *
 *******************************************************************************************************/
/**  configuration of the driver  */
typedef struct
{
    /**  Save external configuration  */
    const Gpt_ConfigType *config;
    /**  driver mode  */
    volatile Gpt_DriverStateType driverMode;
    /**  channel status  */
    Gpt_ChannelInfoType channelInfo[GPT_HW_CHANNEL_NUM];
    /**  channel elapsed time  */
    Gpt_ValueType elapsedTime[GPT_HW_CHANNEL_NUM];
    /**  channel target time  */
    Gpt_ValueType targetTime[GPT_HW_CHANNEL_NUM];
} Gpt_Ip_Handler;

/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
/**  GPT handler */
extern Gpt_Ip_Handler *const Gpt_Handler[5];

/** *****************************************************************************************************
 * Syntax             : void Gpt_GetCoreId(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : get core ID,Used for multi-core support of multi-core GPT.
 *
 * Traceability       : SWSR_GPT_087 SWSR_GPT_020 SWSR_GPT_027
 *******************************************************************************************************/
uint32 Gpt_GetCoreId(void);

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateInitCfg(const Gpt_ConfigType *config)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : config - Incoming configuration information.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check configuration information.
 *
 * Traceability       : SW_SM006 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateInitCfg(const Gpt_ConfigType *config);

/** *****************************************************************************************************
 * Syntax             : void Gpt_CheckStaStartTimer(Gpt_ChannelType channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel Id.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check channel information.
 *
 * Traceability       : SWSR_GPT_054 SWSR_GPT_055 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_CheckStaStartTimer(Gpt_ChannelType channel);

#if (STD_ON == GPT_DEINIT_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_CheckModuleStaDeInit(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check all channel status.
 *
 * Traceability       : SWSR_GPT_031 SWSR_GPT_030
 *******************************************************************************************************/
Std_ReturnType Gpt_CheckModuleStaDeInit(void);
#endif /** #if (STD_ON == GPT_DEINIT_API) */

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateParamStartTimer(Gpt_ChannelType channel,
 *                                                       Gpt_ValueType value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel Id.
 *                      value - counter value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check channel ID and value.
 *
 * Traceability       : SWSR_GPT_052 SWSR_GPT_053 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateParamStartTimer(Gpt_ChannelType channel, Gpt_ValueType value);


#if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateParamGetPredefTime(Gpt_PredefTimerType predefTimer,
 *                                                          const uint32 *timeValuePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefTimer - predeftimer bits
 *                      timeValuePtr - timer value
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check predeftimer bits and time value
 *
 * Traceability       : SWSR_GPT_078 SWSR_GPT_080 SWSR_GPT_081 SWSR_GPT_082 SWSR_GPT_083
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateParamGetPredefTime(Gpt_PredefTimerType predefTimer,
        const uint32 *timeValuePtr);
#endif /** #if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */

#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateNotification(Gpt_ChannelType channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel ID
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check notification pointer.
 *
 * Traceability       : SWSR_GPT_065 SWSR_GPT_069 SWSR_GPT_071 SWSR_GPT_074
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateNotification(Gpt_ChannelType channel);
#endif /** #if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API) */

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateParamCommon(Gpt_ChannelType channel)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel ID
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check driver status and channel ID.
 *
 * Traceability       : SWSR_GPT_037 SWSR_GPT_038 SWSR_GPT_043 SWSR_GPT_045 SWSR_GPT_046
 *                      SWSR_GPT_061 SWSR_GPT_062 SWSR_GPT_065 SWSR_GPT_068 SWSR_GPT_071
 *                      SWSR_GPT_073 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateParamCommon(Gpt_ChannelType channel);

/** *****************************************************************************************************
 * Syntax             : void Gpt_ValidateIrq(Gpt_HwModule hwModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwModule - HW module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - errorId: The ID number where the error occurred
 *
 * Description        : Check if the interrupt is expected.
 *
 * Traceability       : SWSR_GPT_084 SW_SM003 SW_SM004
 *******************************************************************************************************/
Std_ReturnType Gpt_ValidateIrq(Gpt_HwModule hwModule);

#if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_StartPreDefTimer(const Gpt_PredefChannelConfigType *predefCfgPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefCfgPtr - predef timer config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : predef timer start timing.
 *
 * Traceability       : SWSR_GPT_007 SWSR_GPT_008
 *******************************************************************************************************/
void Gpt_Ip_StartPreDefTimer(const Gpt_PredefChannelConfigType *predefCfgPtr);

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_GetPredefTimerValue(const Gpt_PredefChannelConfigType *predefCfgPtr,
 *                                                      Gpt_PredefTimerType predefTimer,
 *                                                      uint32 *timeValuePtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefCfgPtr - predef time config
 *                      predefTimer - predef timer bits
 *
 * Parameters (inout) : uint32 *timeValuePtr - predef time value
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Obtain the value of the timer
 *
 * Traceability       : SWSR_GPT_076 SWSR_GPT_077 SWSR_GPT_078 SWSR_GPT_088 SWSR_GPT_089
 *******************************************************************************************************/
void Gpt_Ip_GetPredefTimerValue(const Gpt_PredefChannelConfigType *predefCfgPtr,
                                Gpt_PredefTimerType predefTimer, uint32 *timeValuePtr);

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_PredefDeInit(const Gpt_PredefChannelConfigType *predefCfgPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : predefCfgPtr - predef time config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : deinit predef timer driver.
 *
 * Traceability       : SWSR_GPT_028
 *******************************************************************************************************/
void Gpt_Ip_PredefDeInit(const Gpt_PredefChannelConfigType *predefCfgPtr);
#endif /** #if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_Init(const Gpt_HwChannelConfigType *hwChannelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    :  hwChannelConfigPtr - configuration structure
 *                        for initializing the module.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initializes the GPT driver.
 *
 * Traceability       : SWSR_GPT_019 SWSR_GPT_018 SWSR_GPT_085 SW_SM005
 *******************************************************************************************************/
void Gpt_Ip_Init(const Gpt_HwChannelConfigType *hwChannelConfigPtr);

#if (STD_ON == GPT_DEINIT_API)
/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_DeInit(const Gpt_HwChannelConfigType *hwChannelConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    : hwChannelConfigPtr - configuration structure
 *                        for deinit the module.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Deinitializes the GPT driver.
 *
 * Traceability       : SWSR_GPT_026
 *******************************************************************************************************/
void Gpt_Ip_DeInit(const Gpt_HwChannelConfigType *hwChannelConfigPtr);
#endif /** #if (STD_ON == GPT_DEINIT_API) */

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_StartTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr,
 *                                              Gpt_ChannelModeType channelMode,
 *                                              Gpt_ValueType value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwChannelConfigPtr - channel config
 *                      channelMode - channel mode
 *                      value - over flow value
 *                      notificationEnabled - Whether to enable the interrupt callback function.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Starts a timer channel.
 *
 * Traceability       : SWSR_GPT_004 SWSR_GPT_005 SWSR_GPT_048 SWSR_GPT_049 SWSR_GPT_050
 *                      SWSR_GPT_085 SW_SM005
 *******************************************************************************************************/
void Gpt_Ip_StartTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr,
                       Gpt_ChannelModeType channelMode, Gpt_ValueType value);

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_StopTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr);
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant (but not for the same timer channel)
 *
 * Parameters (in)    : hwChannelConfigPtr - channel config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Stops a timer channel.
 *
 * Traceability       : SWSR_GPT_056 SWSR_GPT_057 SWSR_GPT_060
 *******************************************************************************************************/
void Gpt_Ip_StopTimer(const Gpt_HwChannelConfigType *hwChannelConfigPtr);

/** *****************************************************************************************************
 * Syntax             : Gpt_ValueType Gpt_Ip_GetTimeElapsed(const Gpt_HwChannelConfigType
 *                                                          *hwChannelConfigPtr,boolean *isExpried)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwChannelConfigPtr - channel config.
 *
 * Parameters (inout) : isExpried - is expried
 *
 * Parameters (out)   : None
 *
 * Return value       : Gpt_ValueType Elapsed timer value (in number of ticks)
 *
 * Description        : Returns the time already elapsed.
 *
 * Traceability       : SWSR_GPT_032 SWSR_GPT_033 SWSR_GPT_035 SWSR_GPT_043
 *******************************************************************************************************/
Gpt_ValueType Gpt_Ip_GetTimeElapsed(const Gpt_HwChannelConfigType *hwChannelConfigPtr,
                                    boolean *isExpried);

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_GetInterrupt(uint8 hwModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwModule - GPT hw module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : get interrupt status.
 *******************************************************************************************************/
uint32 Gpt_Ip_GetInterrupt(uint8 hwModule);

/** *****************************************************************************************************
 * Syntax             : void Gpt_Ip_ClearInterrupt(uint8 hwModule,uint8 position);
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwModule - GPT hw module.
 *                      position - G0 or G1 interrupt status
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : clear interrupt status.
 *******************************************************************************************************/
void Gpt_Ip_ClearInterrupt(uint8 hwModule, uint8 position);

#ifdef __cplusplus
}
#endif

#endif /* GPT_IP_H */

/* End of file */
