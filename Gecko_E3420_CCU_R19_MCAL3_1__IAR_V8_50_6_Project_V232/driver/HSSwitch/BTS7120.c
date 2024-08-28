#include "BTS7120.h"
#include "Dio.h"
#ifdef BTS7120_OUTPUT_CTRL_BYPWM
#include "Xtrg_Cfg.h"
#include "Xtrg.h"
#include "Pwm.h"
#endif
#include "IoExp_TCA6424A_Api.h"

typedef enum
{
    BTS7120_PIN_DIO,
    BTS7120_PIN_IOEXP,
    BTS7120_PIN_PWM,

    BTS7120_PIN_TYPENUM
}BTS7120_Dio_CtrlPinType_e;

typedef struct 
{
    BTS7120_Dio_CtrlPinType_e PinType;
    uint16                    DioChannel;
    uint8                     ChipId;
}BTS7120_CtrlPin_t;

typedef struct
{
    BTS7120_CtrlPin_t     IN0;                   //control out0 output
    BTS7120_CtrlPin_t     IN1;                   //contrl out1 output
}BTS7120_PinList_t;

BTS7120_CtrlPin_t DEN_Pin = 
{
    BTS7120_PIN_IOEXP, IOEXP_TCA6424_P07, TCA6424_CHIP_E 
};

BTS7120_CtrlPin_t DSEL_Pin = 
{
    BTS7120_PIN_IOEXP, IOEXP_TCA6424_P10, TCA6424_CHIP_E 
};	

BTS7120_CtrlPin_t BTS7120_IN0[BTS7120_CHIP_NUM] = 
{
    {BTS7120_PIN_IOEXP, IOEXP_TCA6424_P06, TCA6424_CHIP_B },
#ifdef BTS7120_OUTPUT_CTRL_BYPWM
    {BTS7120_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN0, TCA6424_CHIP_B},
#else
    {BTS7120_PIN_DIO,   DioConf_DioChannel_DioChannel_7120_B_IN0, 0xff },
#endif
    {BTS7120_PIN_IOEXP, IOEXP_TCA6424_P05, TCA6424_CHIP_B },
#ifdef BTS7120_OUTPUT_CTRL_BYPWM
    {BTS7120_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7120_D_IN0, 0xff },
#else
    {BTS7120_PIN_DIO,   DioConf_DioChannel_DioChannel_7120_D_IN0, 0xff },
#endif
};

BTS7120_CtrlPin_t BTS7120_IN1[BTS7120_CHIP_NUM] = 
{
    {BTS7120_PIN_IOEXP, IOEXP_TCA6424_P10, TCA6424_CHIP_B },
#ifdef BTS7120_OUTPUT_CTRL_BYPWM
    {BTS7120_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN1, 0xff },
#else
    {BTS7120_PIN_DIO,   DioConf_DioChannel_DioChannel_7120_B_IN1, 0xff },
#endif
    {BTS7120_PIN_IOEXP, IOEXP_TCA6424_P04, TCA6424_CHIP_B },
#ifdef BTS7120_OUTPUT_CTRL_BYPWM
    {BTS7120_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7120_D_IN1, 0xff },
#else
    {BTS7120_PIN_DIO,   DioConf_DioChannel_DioChannel_7120_D_IN1, 0xff },
#endif
};

static void BTS7120_CtrlPin_Status(BTS7120_CtrlPin_t Pin, Dio_LevelType DioSt);



/***************************************User Function******************************************/
void BTS7120_Init(void)
{
    BTS7xxx_EnableAllDiagnostic();

    #ifdef BTS7120_OUTPUT_CTRL_BYPWM
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN0);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7120_D_IN0);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN1);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7120_D_IN1);

    //map io to pwm
    // extern xtrg_dev_t xtrg_dev;
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H12, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H3, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H8, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H4, true);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H12);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H3);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H8);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H4);
#endif
}

#ifdef BTS7120_OUTPUT_CTRL_BYPWM
void BTS7120_CtrlOutputChannelOnPercent(BTS7120_ChipSelect_e Chip, BTS7120_OutChannel_e OutCh, uint8 dutyPercent)
{
    uint32 duty = 0;

    duty = (uint32)dutyPercent*(0x8000)/100;

    if((Chip == BTS7120_CHIP_B) || Chip == (BTS7120_CHIP_D))
    {
        if(OutCh == BTS7120_OUT0)
        {
            //period 10ms, duty: percent
            Pwm_SetPeriodAndDuty(BTS7120_IN0[Chip].DioChannel,10000000,duty);
        }
        else
        {
            //period 10ms, duty: percent
            Pwm_SetPeriodAndDuty(BTS7120_IN1[Chip].DioChannel,10000000,duty);
        }
    }
    
}
#endif

void BTS7120_CtrlOutputChannelOn(BTS7120_ChipSelect_e Chip, BTS7120_OutChannel_e OutCh)
{
    if(OutCh == BTS7120_OUT0)
    {
        BTS7120_CtrlPin_Status(BTS7120_IN0[Chip], STD_HIGH);
    }
    else
    {
        BTS7120_CtrlPin_Status(BTS7120_IN1[Chip], STD_HIGH);
    }
}

void BTS7120_CtrlOutputChannelOff(BTS7120_ChipSelect_e Chip, BTS7120_OutChannel_e OutCh)
{
    if(OutCh == BTS7120_OUT0)
    {
        BTS7120_CtrlPin_Status(BTS7120_IN0[Chip], STD_LOW);
    }
    else
    {
        BTS7120_CtrlPin_Status(BTS7120_IN1[Chip], STD_LOW);
    }
}

void BTS7120_SwitchToSleepMode(BTS7120_ChipSelect_e Chip)
{
    //SET DEN_Pin low
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_LOW);

    //SET DSEL_Pin low
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P10, STD_LOW);

    //SET IN0/IN1 LOW
    BTS7120_CtrlPin_Status(BTS7120_IN0[Chip], STD_LOW);
    BTS7120_CtrlPin_Status(BTS7120_IN1[Chip], STD_LOW);
}

void BTS7xxx_EnableAllDiagnostic(void)
{
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_HIGH);
}

void BTS7xxx_ClearAllChipErr(void)
{
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_HIGH);
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_LOW);
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_HIGH);
}

void BTS7xxx_DiagSelectOutputChannel(BTS7120_OutChannel_e OutCh)
{
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_HIGH);

    if(OutCh == BTS7120_OUT0)
    {
        IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P10, STD_LOW);
    }
    else
    {
        IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P10, STD_HIGH);
    }
}


static void BTS7120_CtrlPin_Status(BTS7120_CtrlPin_t Pin, Dio_LevelType DioSt)
{
    uint32 duty = 0;

    if(Pin.PinType == BTS7120_PIN_DIO)
    {
        Dio_WriteChannel(Pin.DioChannel, DioSt);
    }
    else if(Pin.PinType == BTS7120_PIN_IOEXP)
    {
        IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B, Pin.DioChannel, DioSt);
    }
    else
    {
        if(DioSt == STD_HIGH)
        {
            duty = 0x8000;
        }
        else
        {
            duty = 0;
        }
        Pwm_SetPeriodAndDuty(Pin.DioChannel,10000000,duty);
    }
}