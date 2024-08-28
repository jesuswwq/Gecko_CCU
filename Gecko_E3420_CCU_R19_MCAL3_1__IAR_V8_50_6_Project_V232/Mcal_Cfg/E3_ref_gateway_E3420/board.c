/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/
#include "Std_Types.h"
#include "Mcu_Mpu.h"
#include "lnk_sym.h"

uint32 board_init(void)
{
    return 0;
}

void mpu_init(void)
{
    int ret = 0;
    uint8 region = 0;

    mpu_enable(FALSE);

    mpu_reset();

    ret = mpu_add_region(region++, 0, 0x100000000, MPU_REGION_DEVICE);
    if (ret != 0) {
        while (1) {}
    }

    /*RAM1/RAM2/IRAM3/IRAM4*/
    ret = mpu_add_region(region++, 0x400000, 0x400000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }

    /*GAMA*/
    ret = mpu_add_region(region++, 0x1000000, 0x400000, MPU_REGION_STRONGORDERED);
    if (ret != 0) {
        while (1) {}
    }

    /*TCM and Cache*/
    ret = mpu_add_region(region++, 0x0, 0x20000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }

    /*override the vector table region for protection */
    ret = mpu_add_region(region++, 0x0, 0x40, MPU_REGION_READONLY);
    if (ret != 0) {
        while (1) {}
    }
#ifndef REMAP_USED  

    /*Flash region 16MB max*/
    ret = mpu_add_region(region++, 0x10000000, 0x1000000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }
#else
    /*Flash region 16MB max*/
    ret = mpu_add_region(region++, 0, 0x400000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }
#endif
    /*Peripheral*/
    ret = mpu_add_region(region++, 0xf0000000,0x10000000, MPU_REGION_DEVICE);
    if (ret != 0) {
        while (1) {}
    }

    /*DMA Buffer*/
    ret = mpu_add_region(region++, (uint32)__dma_buffer_start, (uint32)__dma_buffer_end - (uint32)__dma_buffer_start, MPU_REGION_STRONGORDERED);
    if (ret != 0) {
        while (1) {}
    }

    /*hsm*/
    ret = mpu_add_region(region++, 0x02100000,0x100000, MPU_REGION_DEVICE);
    if (ret != 0) {
        while (1) {}
    }

    mpu_enable(TRUE);
}
