#include "MPQ6612A.h"
#include "Dio.h"
#include "IoExp_TCA9539_Api.h"
#include "IoExp_TCA6424A_Api.h"

typedef enum
{
    MPQ6612A_PIN_DIO,
    MPQ6612A_PIN_IOEXP,

    MPQ6612A_PIN_TYPENUM
}MPQ6612A_Dio_CtrlPinType_e;

typedef struct 
{
    MPQ6612A_Dio_CtrlPinType_e   PinType;
    uint16                    DioChannel;
    TCA6424_ChipID_e_         ChipId;
}MPQ6612A_CtrlPin_t;

const MPQ6612A_CtrlPin_t MPQ6612A_nSLEEP_Pin[MPQ6612A_CHIP_NUM] = 
{
    { MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P24, TCA6424_CHIP_B },
    { MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P25, TCA6424_CHIP_B },
    { MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P23, TCA6424_CHIP_B },
};

const MPQ6612A_CtrlPin_t MPQ6612A_IN1_Pin[MPQ6612A_CHIP_NUM] = 
{
    {MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P20, TCA6424_CHIP_B },
    {MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P22, TCA6424_CHIP_B },
    {MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P16, TCA6424_CHIP_B }
};

const MPQ6612A_CtrlPin_t MPQ6612A_IN2_Pin[MPQ6612A_CHIP_NUM] = 
{
    {MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P17, TCA6424_CHIP_B },
    {MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P21, TCA6424_CHIP_B },
    {MPQ6612A_PIN_IOEXP, IOEXP_TCA6424_P15, TCA6424_CHIP_B },
};

static void MPQ6612A_CtrlPin_Status(MPQ6612A_CtrlPin_t Pin, Dio_LevelType DioSt);


/***************************************User Function******************************************/
void MPQ6612A_Init(void)
{
    MPQ6612A_ChipSelect_e chipid = MPQ6612A_CHIP_A;

    for(chipid = MPQ6612A_CHIP_A; chipid < MPQ6612A_CHIP_NUM; chipid++)
    {
        //set MPQ6612A to normal operate
        MPQ6612A_CtrlPin_Status(MPQ6612A_nSLEEP_Pin[chipid], STD_HIGH);
    }
}

void MPQ6612A_SwitchToSleepMode(MPQ6612A_ChipSelect_e Chip)
{
    //SET MPQ6612A_nSLEEP_Pin low
    MPQ6612A_CtrlPin_Status(MPQ6612A_nSLEEP_Pin[Chip], STD_LOW);
}

void MPQ6612A_Hbridge_CtrlOutDir(MPQ6612A_ChipSelect_e Chip, MPQ6612A_OutPutDirection_e OutDir)
{
    Dio_LevelType IN1Pin = STD_LOW;
    Dio_LevelType IN2Pin = STD_LOW;

    switch(OutDir)
    {
        case MPQ6612A_OUTDIR_FORWARD:
            IN1Pin = STD_HIGH;
            IN2Pin = STD_LOW;
            break;

        case MPQ6612A_OUTDIR_REVERSE:
            IN1Pin = STD_LOW;
            IN2Pin = STD_HIGH;
            break;
        
        case MPQ6612A_OUTDIR_BRAKE:
        default:
            IN1Pin = STD_LOW;
            IN2Pin = STD_LOW;
            break;
    }

    MPQ6612A_CtrlPin_Status(MPQ6612A_IN1_Pin[Chip], IN1Pin);
    MPQ6612A_CtrlPin_Status(MPQ6612A_IN2_Pin[Chip], IN2Pin);
}

static void MPQ6612A_CtrlPin_Status(MPQ6612A_CtrlPin_t Pin, Dio_LevelType DioSt)
{
    IoExp_TCA6424_SetChannelOutLevel(Pin.ChipId, Pin.DioChannel, DioSt);
}
void HBridge_MPQ6612A(MPQ6612A_ChipSelect_e Chip,uint8 Pin1,uint8 Pin2)
{
    IoExp_TCA6424_SetChannelOutLevel(MPQ6612A_IN1_Pin[Chip].ChipId,MPQ6612A_IN1_Pin[Chip].DioChannel,Pin1);
    IoExp_TCA6424_SetChannelOutLevel(MPQ6612A_IN2_Pin[Chip].ChipId,MPQ6612A_IN2_Pin[Chip].DioChannel,Pin2);
}