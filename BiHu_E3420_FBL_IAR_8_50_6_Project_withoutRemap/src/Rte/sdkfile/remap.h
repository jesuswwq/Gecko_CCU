/**
 * @file remap.h
 * @brief remap common api
 *
 * @copyright Copyright (c) 2022  Semidrive Semiconductor.
 *            All rights reserved.
 */

#ifndef SDRV_REMAP_H_
#define SDRV_REMAP_H_

#include "Std_Types.h"

enum sdrv_remap_status {
    SDRV_REMAP_FAIL = 0,
    SDRV_REMAP_OK = 1,
};

typedef enum sdrv_remap_core {
    SDRV_REMAP_SF,
    SDRV_REMAP_SP0,
    SDRV_REMAP_SP1,
    SDRV_REMAP_SX0,
    SDRV_REMAP_SX1,
} sdrv_remap_core_e;

/**
 * @brief Remap specific memory to exception table.
 *
 * This function remap memory to exception vector, after call this
 * function, core will be reset.
 *
 * @param [in] core core to be remap
 * @param [in] mem_base memory base
 * @return SDRV_REMAP_OK: reset core success, SDRV_REMAP_FAIL: reset core fail
 */
enum sdrv_remap_status sdrv_core_remap(sdrv_remap_core_e core,
                                       uint32 mem_base);

/**
 * @brief Force remap specific memory to exception table.
 *
 * This function remap memory to exception vector, after call this
 * function, core will be reset. This function will force remap
 * and reset.
 *
 * @param [in] core core to be remap
 * @param [in] mem_base memory base
 * @return SDRV_REMAP_OK: reset core success, SDRV_REMAP_FAIL: reset core fail
 */
enum sdrv_remap_status sdrv_core_force_remap(sdrv_remap_core_e core,
                                             uint32 mem_base);

#endif /* SDRV_REMAP_H_ */
