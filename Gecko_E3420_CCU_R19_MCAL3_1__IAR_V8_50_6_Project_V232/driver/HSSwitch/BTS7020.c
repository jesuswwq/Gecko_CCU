#include "BTS7020.h"
#include "Dio.h"
#ifdef BTS7020_OUTPUT_CTRL_BYPWM
#include "Xtrg_Cfg.h"
#include "Xtrg.h"
#include "Pwm.h"
#endif
#include "IoExp_TCA9539_Api.h"
#include "IoExp_TCA6424A_Api.h"

typedef enum
{
    BTS7020_PIN_DIO,
    BTS7020_PIN_IOEXP,
    BTS7020_PIN_PWM,

    BTS7020_PIN_TYPENUM
}BTS7020_Dio_CtrlPinType_e;

typedef struct 
{
    BTS7020_Dio_CtrlPinType_e PinType;
    uint16                    DioChannel;
    uint8                     ChipId;
}BTS7020_CtrlPin_t;

typedef struct
{
    BTS7020_CtrlPin_t     IN0;                   //control out0 output
    BTS7020_CtrlPin_t     IN1;                   //contrl out1 output
}BTS7020_PinList_t;


BTS7020_CtrlPin_t BTS7020_IN0[BTS7020_CHIP_NUM] = 
{
#ifdef BTS7020_OUTPUT_CTRL_BYPWM
    {BTS7020_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7020_A_IN0, 0xff },
    {BTS7020_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7020_B_IN0, 0xff },
#else
    {BTS7020_PIN_DIO,   DioConf_DioChannel_DioChannel_7020_A_IN0, 0xff },
    {BTS7020_PIN_DIO,   DioConf_DioChannel_DioChannel_7020_B_IN0, 0xff },
#endif
};

BTS7020_CtrlPin_t BTS7020_IN1[BTS7020_CHIP_NUM] = 
{
#ifdef BTS7020_OUTPUT_CTRL_BYPWM
    {BTS7020_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7020_A_IN1, 0xff },
    {BTS7020_PIN_PWM,   PWM_CONFIG_CHANNEL_PwmChannel_7020_B_IN1, 0xff },
#else
    {BTS7020_PIN_DIO,   DioConf_DioChannel_DioChannel_7020_A_IN1, 0xff },
    {BTS7020_PIN_DIO,   DioConf_DioChannel_DioChannel_7020_B_IN1, 0xff },
#endif
};

static void BTS7020_CtrlPin_Status(BTS7020_CtrlPin_t Pin, Dio_LevelType DioSt);



/***************************************User Function******************************************/
void BTS7020_Init(void)
{
    BTS7xxx_EnableAllDiagnostic();
#ifdef BTS7020_OUTPUT_CTRL_BYPWM
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7020_A_IN0);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7020_A_IN1);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7020_B_IN0);
    Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7020_B_IN1);

    //map io to pwm
    // extern xtrg_dev_t xtrg_dev;
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_M0, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_M6, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_M7, true);
	// sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_M8, true);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_M0);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_M6);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_M7);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_M8);
#endif
}

#ifdef BTS7020_OUTPUT_CTRL_BYPWM
void BTS7020_CtrlOutputChannelOnPercent(BTS7020_ChipSelect_e Chip, BTS7020_OutChannel_e OutCh, uint8 dutyPercent)
{
    uint32 duty = 0;

    duty = (uint32)dutyPercent*(0x8000)/100;

    if(OutCh == BTS7020_OUT0)
    {
        //period 10ms, duty: percent
        Pwm_SetPeriodAndDuty(BTS7020_IN0[Chip].DioChannel,10000000,duty);
    }
    else
    {
        //period 10ms, duty: percent
        Pwm_SetPeriodAndDuty(BTS7020_IN1[Chip].DioChannel,10000000,duty);
    }
}
#endif
void BTS7020_CtrlOutputChannelOn(BTS7020_ChipSelect_e Chip, BTS7020_OutChannel_e OutCh)
{
    if(OutCh == BTS7020_OUT0)
    {
        BTS7020_CtrlPin_Status(BTS7020_IN0[Chip], STD_HIGH);
    }
    else
    {
        BTS7020_CtrlPin_Status(BTS7020_IN1[Chip], STD_HIGH);
    }
}


void BTS7020_CtrlOutputChannelOff(BTS7020_ChipSelect_e Chip, BTS7020_OutChannel_e OutCh)
{
#ifdef BTS7020_OUTPUT_CTRL_BYPWM
    if(OutCh == BTS7020_OUT0)
    {
        Pwm_SetOutputToIdle(BTS7020_IN0[Chip].DioChannel);
    }
    else
    {
        Pwm_SetOutputToIdle(BTS7020_IN1[Chip].DioChannel);
    }
#else
    if(OutCh == BTS7020_OUT0)
    {
        BTS7020_CtrlPin_Status(BTS7020_IN0[Chip], STD_LOW);
    }
    else
    {
        BTS7020_CtrlPin_Status(BTS7020_IN1[Chip], STD_LOW);
    }
#endif
}


void BTS7020_SwitchToSleepMode(BTS7020_ChipSelect_e Chip)
{
    //SET DEN_Pin low
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P07, STD_LOW);

    //SET DSEL_Pin low
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_E, IOEXP_TCA6424_P10, STD_LOW);

    //SET IN0/IN1 LOW
    BTS7020_CtrlOutputChannelOff(Chip,BTS7020_OUT0);
    BTS7020_CtrlOutputChannelOff(Chip,BTS7020_OUT1);
}


static void BTS7020_CtrlPin_Status(BTS7020_CtrlPin_t Pin, Dio_LevelType DioSt)
{
    uint32 duty = 0;
    
    if(Pin.PinType == BTS7020_PIN_DIO)
    {
        Dio_WriteChannel(Pin.DioChannel, DioSt);
    }
    else if(Pin.PinType == BTS7020_PIN_IOEXP)
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
        /*Pwm_SetPeriodAndDuty(Pin.DioChannel,10000000,duty);*/
        Pwm_SetDutyCycle(Pin.DioChannel, duty);
    }
}