#ifndef _VNH5200_H_
#define _VNH5200_H_

#include "Platform_Types.h"

typedef enum
{
    VNH5200_DIR_LSON,       //Low side on
    VNH5200_DIR_HSON,       //High side on

    VNH5200_DIRNUM
}VNH5200_HBridgeDir_e;

typedef enum
{
    VNH5200_OUT_A,
    VNH5200_OUT_B,

    VNH5200_OUTCH_NUM
}VNH5200_Channel_e;


extern void VNH5200_Init(void);
extern void VNH5200_HBridge_CtrlOutput(VNH5200_Channel_e channel, VNH5200_HBridgeDir_e OutputDir);
extern void VNH5200_HBridge_ClearChannelErr(VNH5200_Channel_e channel);

#endif