#ifndef _DR702_H_
#define _DR702_H_

#include "Platform_Types.h"
typedef enum
{
    DR702_CHIP_C,
    DR702_CHIP_D,

    DR702_CHIP_NUM
}DR702_ChipSelect_e;

typedef enum
{
    DR702_DIR_SH2TOSH1,
    DR702_DIR_SH1TOSH2,
    DR702_DIR_BRAKE,

    DR702_DIRNUM
}DR702_HBridgeDir_e;

typedef enum
{
    DR702_HalfBridgeCh_HS1,
    DR702_HalfBridgeCh_LS1,
    DR702_HalfBridgeCh_HS2,
    DR702_HalfBridgeCh_LS2,

    HalfBridge_CH_NUM
}DR702_HalfBridgeCh_e;

typedef enum
{
    DR702_MODE_H_BRIDGE,
    DR702_MODE_HALF_BRIDGE
}DR702_Mode_e;

extern void DR702_Init(void);
extern void DR702_SwitchToSleepMode(DR702_ChipSelect_e Chip);
extern void DR702_SetChipMode(DR702_ChipSelect_e Chip, DR702_Mode_e ChipMode);
extern boolean DR702_DiagChipAtFault(DR702_ChipSelect_e Chip);

//H-Bridge driver
extern void DR702_HBridge_CtrlOutputOff(DR702_ChipSelect_e Chip);
extern void DR702_HBridge_CtrlOutputOn(DR702_ChipSelect_e Chip, DR702_HBridgeDir_e OutputDir);

//half-bridge deriver
extern void DR702_HalfBridge_CtrlOutputChOn(DR702_ChipSelect_e Chip, DR702_HalfBridgeCh_e OutCh);

#endif