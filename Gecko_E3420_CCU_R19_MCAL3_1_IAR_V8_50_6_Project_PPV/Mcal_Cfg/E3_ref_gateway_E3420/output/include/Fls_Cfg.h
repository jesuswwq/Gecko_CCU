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
 *  \file     Fls_Cfg.h                                                                                 *
 *  \brief    This file contains interface header for FLS MCAL driver,                                  *
 *            details Automatically generated by user settings                                          *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2024-03-08 16:29:00     <td>1.0.0                                                                *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FLS_CFG_H
#define FLS_CFG_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#define FLS_IP_CPU_FREQUENCY_MHZ (600U)

#define CHIP_ID_E3420
#define E3xxx_E3
#define FLS_IP_RESOURE_NUM (2)

#define FLS_MAX_NUMBER_OF_CONTROLLER (FLS_IP_RESOURE_NUM * 2)

#define FLS_DEV_ERROR_DETECT (STD_ON)   /* development error detection */

#define FLS_DEM_ERROR_DETECT (STD_OFF)    /* public error detection */

#define FLS_VERSION_INFO_API    (STD_ON)
#define FLS_CANCEL_API          (STD_OFF)
#define FLS_GET_STATUS_API      (STD_ON)
#define FLS_GET_JOB_RESULT_API  (STD_ON)
#define FLS_COMPARE_API         (STD_ON)
#define FLS_SET_MODE_API        (STD_ON)
#define FLS_BLANK_CHECK_API     (STD_ON)

#define FLS_TIMEOUT_SUPERVISION_ENABLED  (STD_ON)

#define FLS_ERASE_VERIFICATION_ENABLED  (STD_OFF)
#define FLS_WRITE_VERIFICATION_ENABLED  (STD_ON)

#define FLS_ADDRESS_ALIGNED_CHECK_ENABLED  (STD_OFF)

#define FLS_NON_CACHEABLE_EN  (STD_OFF)

#define FLS_INSTANCE  0x0U

#define FLS_BASE_ADDRESS 0U


//FlsPublishedInformation
#define FLS_AC_LOCATION_ERASE 0x0
#define FLS_AC_LOCATION_WRITE 0x0
#define FLS_AC_SIZE_ERASE 0x128U
#define FLS_AC_SIZE_WRITE 0x128U
#define FLS_ERASED_VALUE  0x128U
#define FLS_ERASE_TIME (0U)  /* in us */
#define FLS_EXPECTED_HW_ID 0
#define FLS_SPECIFIED_ERASE_CYCLES 0x10000U
#define FLS_WRITE_TIME (0U)  /* in us */
#define FLS_USE_INTERRUPTS  (STD_OFF)
#define FLS_CALL_CYCLES (100000U)  /* in us */

#define FLS_PROTECTED_AREA_NUM (0u)
#define FLS_HYPERBUS_FLASH_CNT (1U)

#define FLS_MAX_PRIOFITY_NUMBER (1U)


#ifdef __cplusplus
}
#endif  /* #ifdef __cplusplus */
#endif /* #define FLS_CFG_H */

/* End of file */