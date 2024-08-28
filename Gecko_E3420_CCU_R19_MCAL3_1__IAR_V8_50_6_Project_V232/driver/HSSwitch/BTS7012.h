#ifndef _BTS7012_H_
#define _BTS7012_H_

#include "Platform_Types.h"

/************Config Item: Define output control by DIO or PWM*************/
#define BTS7012_OUTPUT_CTRL_BYPWM 2

typedef enum
{
    BTS7012_OUT0,
    BTS7012_OUT1,

    BTS7012_OUTCHNUM
}BTS7012_OutChannel_e;

typedef enum
{
    BTS7012_CHST_OFF,
    BTS7012_CHST_ON

}BTS7012_ChannelSt_e;

typedef enum
{
    BTS7012_CHIP_A,
    BTS7012_CHIP_B,
    BTS7012_CHIP_C,

    BTS7012_CHIP_NUM
}BTS7012_ChipSelect_e;


extern void BTS7012_Init(void);
extern void BTS7012_SwitchToSleepMode(BTS7012_ChipSelect_e Chip);
extern void BTS7012_CtrlOutputChannelOff(BTS7012_ChipSelect_e Chip, BTS7012_OutChannel_e OutCh);
extern void BTS7012_CtrlOutputChannelOn(BTS7012_ChipSelect_e Chip, BTS7012_OutChannel_e OutCh);
#ifdef BTS7012_OUTPUT_CTRL_BYPWM
extern void BTS7012_CtrlOutputChannelOnPercent(BTS7012_ChipSelect_e Chip, BTS7012_OutChannel_e OutCh, uint8 dutyPercent);
#endif

#endif
