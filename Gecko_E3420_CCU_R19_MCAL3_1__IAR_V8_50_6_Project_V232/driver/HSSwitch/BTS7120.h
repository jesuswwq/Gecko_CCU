#ifndef _BTS7120_H_
#define _BTS7120_H_

#include "Platform_Types.h"

/************Config Item: Define output control by DIO or PWM*************/
#define BTS7120_OUTPUT_CTRL_BYPWM 3

typedef enum
{
    BTS7120_OUT0,
    BTS7120_OUT1,

    BTS7120_OUTCHNUM
}BTS7120_OutChannel_e;

typedef enum
{
    BTS7120_CHST_OFF,
    BTS7120_CHST_ON

}BTS7120_ChannelSt_e;

typedef enum
{
    BTS7120_CHIP_A,
    BTS7120_CHIP_B,
    BTS7120_CHIP_C,
    BTS7120_CHIP_D,

    BTS7120_CHIP_NUM
}BTS7120_ChipSelect_e;


extern void BTS7120_Init(void);
extern void BTS7120_SwitchToSleepMode(BTS7120_ChipSelect_e Chip);
extern void BTS7120_CtrlOutputChannelOff(BTS7120_ChipSelect_e Chip, BTS7120_OutChannel_e OutCh);
extern void BTS7120_CtrlOutputChannelOn(BTS7120_ChipSelect_e Chip, BTS7120_OutChannel_e OutCh);
#ifdef BTS7120_OUTPUT_CTRL_BYPWM
extern void BTS7120_CtrlOutputChannelOnPercent(BTS7120_ChipSelect_e Chip, BTS7120_OutChannel_e OutCh, uint8 dutyPercent);
#endif

//used for all BTS7xxx diagnostic
extern void BTS7xxx_EnableAllDiagnostic(void);
extern void BTS7xxx_ClearAllChipErr(void);
extern void BTS7xxx_DiagSelectOutputChannel(BTS7120_OutChannel_e OutCh);

#endif