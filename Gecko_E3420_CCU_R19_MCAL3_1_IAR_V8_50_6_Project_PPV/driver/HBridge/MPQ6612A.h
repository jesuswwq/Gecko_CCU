#ifndef _MPQ6612A_H_
#define _MPQ6612A_H_

#include "Platform_Types.h"

typedef enum
{
    MPQ6612A_CHIP_A,
    MPQ6612A_CHIP_B,
    MPQ6612A_CHIP_C,

    MPQ6612A_CHIP_NUM
}MPQ6612A_ChipSelect_e;

typedef enum
{
    MPQ6612A_OUTDIR_FORWARD, 
    MPQ6612A_OUTDIR_REVERSE,
    MPQ6612A_OUTDIR_BRAKE,

    MPQ6612A_OUTDIR_NUM
}MPQ6612A_OutPutDirection_e;

extern void MPQ6612A_Init(void);
extern void MPQ6612A_SwitchToSleepMode(MPQ6612A_ChipSelect_e Chip);
extern void MPQ6612A_Hbridge_CtrlOutDir(MPQ6612A_ChipSelect_e Chip, MPQ6612A_OutPutDirection_e OutDir);

extern void HBridge_MPQ6612A(MPQ6612A_ChipSelect_e Chip,uint8 Pin1,uint8 Pin2);
#endif