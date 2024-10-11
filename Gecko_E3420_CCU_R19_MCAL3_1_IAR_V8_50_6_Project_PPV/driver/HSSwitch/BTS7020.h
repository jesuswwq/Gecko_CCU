#ifndef _BTS7020_H_
#define _BTS7020_H_

#include "Platform_Types.h"

/************Config Item: Define output control by DIO or PWM*************/
#define BTS7020_OUTPUT_CTRL_BYPWM 1

typedef enum
{
    BTS7020_OUT0,
    BTS7020_OUT1,

    BTS7020_OUTCHNUM
}BTS7020_OutChannel_e;

typedef enum
{
    BTS7020_CHST_OFF,
    BTS7020_CHST_ON

}BTS7020_ChannelSt_e;

typedef enum
{
    BTS7020_CHIP_A,
    BTS7020_CHIP_B,

    BTS7020_CHIP_NUM
}BTS7020_ChipSelect_e;


extern void BTS7020_Init(void);
extern void BTS7020_SwitchToSleepMode(BTS7020_ChipSelect_e Chip);
extern void BTS7020_CtrlOutputChannelOff(BTS7020_ChipSelect_e Chip, BTS7020_OutChannel_e OutCh);
extern void BTS7020_CtrlOutputChannelOn(BTS7020_ChipSelect_e Chip, BTS7020_OutChannel_e OutCh);
#ifdef BTS7020_OUTPUT_CTRL_BYPWM
extern void BTS7020_CtrlOutputChannelOnPercent(BTS7020_ChipSelect_e Chip, BTS7020_OutChannel_e OutCh, uint8 dutyPercent);
#endif

#endif
