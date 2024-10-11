#include "BTS7012.h"
#include "Dio.h"
#ifdef BTS7012_OUTPUT_CTRL_BYPWM
#include "Xtrg_Cfg.h"
#include "Xtrg.h"
#include "Pwm.h"
#endif
#include "IoExp_TCA9539_Api.h"
#include "IoExp_TCA6424A_Api.h"

typedef enum
{
    BTS7012_PIN_DIO,
    BTS7012_PIN_IOEXP,
    BTS7012_PIN_PWM,

    BTS7012_PIN_TYPENUM
}BTS7012_Dio_CtrlPinType_e;

typedef struct 
{
    BTS7012_Dio_CtrlPinType_e PinType;
    uint16                    DioChannel;
    uint8                     ChipId;
}BTS7012_CtrlPin_t;

typedef struct
{
    BTS7012_CtrlPin_t     IN0;                   //control out0 output
    BTS7012_CtrlPin_t     IN1;                   //contrl out1 output
}BTS7012_PinList_t;


BTS7012_CtrlPin_t BTS7012_IN0[BTS7012_CHIP_NUM] = 
{
#ifdef BTS7012_OUTPUT_CTRL_BYPWM
    {BTS7012_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN0, 0xff },
    {BTS7012_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_B_IN0, 0xff },
    {BTS7012_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_C_IN0, 0xff },
#else
    {BTS7012_PIN_DIO,   DioConf_DioChannel_DioChannel_7012_A_IN0, 0xff },
    {BTS7012_PIN_DIO,   DioConf_DioChannel_DioChannel_7012_B_IN0, 0xff },
    {BTS7012_PIN_DIO,   DioConf_DioChannel_DioChannel_7012_C_IN0, 0xff },
#endif
};

BTS7012_CtrlPin_t BTS7012_IN1[BTS7012_CHIP_NUM] = 
{
#ifdef BTS7012_OUTPUT_CTRL_BYPWM
    {BTS7012_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN1, 0xff },
    {BTS7012_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_B_IN1, 0xff },
    {BTS7012_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_C_IN1, 0xff },
#else
    {BTS7012_PIN_DIO,   DioConf_DioChannel_DioChannel_7012_A_IN1, 0xff },
    {BTS7012_PIN_DIO,   DioConf_DioChannel_DioChannel_7012_B_IN1, 0xff },
    {BTS7012_PIN_DIO,   DioConf_DioChannel_DioChannel_7012_C_IN1, 0xff },
#endif
};

static void BTS7012_CtrlPin_Status(BTS7012_CtrlPin_t Pin, Dio_LevelType DioSt);



/***************************************User Function******************************************/
void BTS7012_Init(void)
{
    BTS7xxx_EnableAllDiagnostic();

    #ifdef BTS7012_OUTPUT_CTRL_BYPWM
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN0);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN1);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_B_IN0);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_B_IN1);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_C_IN0);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_C_IN1);

    //map io to pwm
    // extern xtrg_dev_t xtrg_dev;
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_C12, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_C14, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H1, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_A8, true);
    // sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_M3, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_S2, true);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_C12);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_C14);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H1);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_A8);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_M3);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_S2);
#endif
}
#ifdef BTS7012_OUTPUT_CTRL_BYPWM
void BTS7012_CtrlOutputChannelOnPercent(BTS7012_ChipSelect_e Chip, BTS7012_OutChannel_e OutCh, uint8 dutyPercent)
{
    uint32 duty = 0;

    duty = (uint32)dutyPercent*(0x8000)/100;

    if(OutCh == BTS7012_OUT0)
    {
        //period 10ms, duty: percent
        Pwm_SetPeriodAndDuty(BTS7012_IN0[Chip].DioChannel,10000000,duty);
    }
    else
    {
        //period 10ms, duty: percent
        Pwm_SetPeriodAndDuty(BTS7012_IN1[Chip].DioChannel,10000000,duty);
    }
}
#endif

void BTS7012_CtrlOutputChannelOn(BTS7012_ChipSelect_e Chip, BTS7012_OutChannel_e OutCh)
{
    if(OutCh == BTS7012_OUT0)
    {
        BTS7012_CtrlPin_Status(BTS7012_IN0[Chip], STD_HIGH);
    }
    else
    {
        BTS7012_CtrlPin_Status(BTS7012_IN1[Chip], STD_HIGH);
    }
}

void BTS7012_CtrlOutputChannelOff(BTS7012_ChipSelect_e Chip, BTS7012_OutChannel_e OutCh)
{
#ifdef BTS7012_OUTPUT_CTRL_BYPWM
    if(OutCh == BTS7012_OUT0)
    {
        Pwm_SetOutputToIdle(BTS7012_IN0[Chip].DioChannel);
    }
    else
    {
        Pwm_SetOutputToIdle(BTS7012_IN1[Chip].DioChannel);
    }
#else
    if(OutCh == BTS7012_OUT0)
    {
        BTS7012_CtrlPin_Status(BTS7012_IN0[Chip], STD_LOW);
    }
    else
    {
        BTS7012_CtrlPin_Status(BTS7012_IN1[Chip], STD_LOW);
    }
#endif
}

void BTS7012_SwitchToSleepMode(BTS7012_ChipSelect_e Chip)
{
    //SET DEN_Pin low
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_LOW);

    //SET DSEL_Pin low
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P10, STD_LOW);

    //SET IN0/IN1 LOW
    // BTS7012_CtrlPin_Status(BTS7012_IN0[Chip], STD_LOW);
    // BTS7012_CtrlPin_Status(BTS7012_IN1[Chip], STD_LOW);
    BTS7012_CtrlOutputChannelOff(Chip,BTS7012_OUT0);
    BTS7012_CtrlOutputChannelOff(Chip,BTS7012_OUT1);
}


static void BTS7012_CtrlPin_Status(BTS7012_CtrlPin_t Pin, Dio_LevelType DioSt)
{
    uint32 duty = 0;

    if(Pin.PinType == BTS7012_PIN_DIO)
    {
        Dio_WriteChannel(Pin.DioChannel, DioSt);
    }
    else if(Pin.PinType == BTS7012_PIN_IOEXP)
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