
#include "TLE8108EM.h"
#include "Spi.h"
#include "IoExp_TCA6424A_Api.h"
#include "Mcu_Delay.h"
#include "Xtrg_Cfg.h"
#include "Xtrg.h"
#include "Pwm.h"

typedef enum
{
  TLE8108EM_ClearMode = 0,
  InputDirctMode = 1,
  ON_Mode = 2,
  OFF_Mode = 3
}TLE8108EM_ChannelMode_e;


typedef union
{
  struct
  {
    TLE8108EM_ChannelMode_e IN1       :2;
    TLE8108EM_ChannelMode_e IN2       :2;
    TLE8108EM_ChannelMode_e IN3       :2;
    TLE8108EM_ChannelMode_e IN4       :2;
    TLE8108EM_ChannelMode_e IN5       :2;
    TLE8108EM_ChannelMode_e IN6       :2;
    TLE8108EM_ChannelMode_e IN7       :2;
    TLE8108EM_ChannelMode_e IN8       :2;
  } SI;

  uint16 U;
} TLE8108EM_Spi_Data_T;

typedef union
{
  struct 
  {
    TLE8108EM_DiagSt_e DIA1        :2;
    TLE8108EM_DiagSt_e DIA2        :2;
    TLE8108EM_DiagSt_e DIA3        :2;
    TLE8108EM_DiagSt_e DIA4        :2;
    TLE8108EM_DiagSt_e DIA5        :2;
    TLE8108EM_DiagSt_e DIA6        :2;
    TLE8108EM_DiagSt_e DIA7        :2;
    TLE8108EM_DiagSt_e DIA8        :2;
  }SO;    
  uint16 U;
} TLE8108EM_Spi_Data_R;

static TLE8108EM_Spi_Data_T TLE8108EM_TX_Buffer;
static TLE8108EM_Spi_Data_R TLE8108EM_RX_Buffer;

const Pwm_ChannelType TLE8108_INPin_List[DO_OUT_CH_MAX] = 
{
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN1,
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN2,
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN3,
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN4,
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN1,
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN2,
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN3,
  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN4
};

static void TLE8108EM_read_write(uint16 value)
{
  TLE8108EM_TX_Buffer.U = value;

  Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_TLE8108EM, 
              (uint8*)&TLE8108EM_TX_Buffer.U, 
              (uint8*)&TLE8108EM_RX_Buffer.U, 
              1);

  Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_TLE8108EM);

}

void TLE8108EM_Init(void)
{
    uint16 regVal_u16 = 0x0;

    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,IOEXP_TCA6424_P12, STD_LOW);
    //tRST = 50us  min value
    Mcu_udelay(50);
    //release reset pin; OUT_EXP_B_P12
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,IOEXP_TCA6424_P12, STD_HIGH);
    //tWU = 200us  max value
    Mcu_udelay(200);

    //The output registers must be reset to their default values by programming the Clear mode for all channels once.
    TLE8108EM_read_write(regVal_u16);

    //map io to pwm
    // extern xtrg_dev_t xtrg_dev;
    // sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H7, true);
    // sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_S5, true);
    // sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H9, true);
    // sdrv_xtrg_io_out_config(&xtrg_dev, &IOOutConfig_H10, true);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H7);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_S5);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H9);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H10);
}

void TLE8108EM_SwitchToStandby(void)
{
    uint16 regVal_u16 = 0;

    TLE8108EM_read_write(regVal_u16);
}

Std_ReturnType TLE8108EM_Set_ChannelON(DO_OUT_Ch_t channel)
{
  Std_ReturnType ret = E_OK;
  TLE8108EM_Spi_Data_T value;

  value.U = TLE8108EM_TX_Buffer.U;

  switch(channel)
  {
    case DO_OUT_1:
        TLE8108EM_TX_Buffer.SI.IN1 = ON_Mode;
    break;

    case  DO_OUT_2:
        TLE8108EM_TX_Buffer.SI.IN2 = ON_Mode;
    break;

    case DO_OUT_3:
        TLE8108EM_TX_Buffer.SI.IN3 = ON_Mode;
    break;

    case  DO_OUT_4:
        TLE8108EM_TX_Buffer.SI.IN4 = ON_Mode;
    break;

    case  DO_OUT_5:
        TLE8108EM_TX_Buffer.SI.IN5 = ON_Mode;
    break;

    case  DO_OUT_6:
        TLE8108EM_TX_Buffer.SI.IN6 = ON_Mode;
    break;

    case  DO_OUT_7:
        TLE8108EM_TX_Buffer.SI.IN7 = ON_Mode;
    break;

    case  DO_OUT_8:
        TLE8108EM_TX_Buffer.SI.IN8 = ON_Mode;
    break;

    default:
      return E_NOT_OK;
    break;
    
  }

  if(value.U != TLE8108EM_TX_Buffer.U)
  {
    TLE8108EM_read_write(TLE8108EM_TX_Buffer.U);
  }

  return ret;
}

Std_ReturnType TLE8108EM_Set_ChannelOFF(DO_OUT_Ch_t channel)
{
  Std_ReturnType ret = E_OK;
  TLE8108EM_Spi_Data_T value;

  value.U = TLE8108EM_TX_Buffer.U;

  switch(channel)
  {
    case DO_OUT_1:
        TLE8108EM_TX_Buffer.SI.IN1 = OFF_Mode;
    break;

    case  DO_OUT_2:
        TLE8108EM_TX_Buffer.SI.IN2 = OFF_Mode;
    break;

    case DO_OUT_3:
        TLE8108EM_TX_Buffer.SI.IN3 = OFF_Mode;
    break;

    case  DO_OUT_4:
        TLE8108EM_TX_Buffer.SI.IN4 = OFF_Mode;
    break;

    case  DO_OUT_5:
        TLE8108EM_TX_Buffer.SI.IN5 = OFF_Mode;
    break;

    case  DO_OUT_6:
        TLE8108EM_TX_Buffer.SI.IN6 = OFF_Mode;
    break;

    case  DO_OUT_7:
        TLE8108EM_TX_Buffer.SI.IN7 = OFF_Mode;
    break;

    case  DO_OUT_8:
        TLE8108EM_TX_Buffer.SI.IN8 = OFF_Mode;
    break;

    default:
      return E_NOT_OK;
    break;
    
  }

  if(value.U != TLE8108EM_TX_Buffer.U)
  {
    TLE8108EM_read_write(TLE8108EM_TX_Buffer.U);
  }

  return ret;
}

Std_ReturnType TLE8108EM_PwmCtrlChannelOutput(DO_OUT_Ch_t channel, uint8 dutyPercent,uint32 frq)
{
  Std_ReturnType ret = E_OK;
  TLE8108EM_Spi_Data_T value;
  uint32 duty = 0;

  value.U = TLE8108EM_TX_Buffer.U;

  switch(channel)
  {
    case DO_OUT_1:
        TLE8108EM_TX_Buffer.SI.IN1 = InputDirctMode;
    break;

    case  DO_OUT_2:
        TLE8108EM_TX_Buffer.SI.IN2 = InputDirctMode;
    break;

    case DO_OUT_3:
        TLE8108EM_TX_Buffer.SI.IN3 = InputDirctMode;
    break;

    case  DO_OUT_4:
        TLE8108EM_TX_Buffer.SI.IN4 = InputDirctMode;
    break;

    case  DO_OUT_5:
        TLE8108EM_TX_Buffer.SI.IN5 = InputDirctMode;
    break;

    case  DO_OUT_6:
        TLE8108EM_TX_Buffer.SI.IN6 = InputDirctMode;
    break;

    case  DO_OUT_7:
        TLE8108EM_TX_Buffer.SI.IN7 = InputDirctMode;
    break;

    case  DO_OUT_8:
        TLE8108EM_TX_Buffer.SI.IN8 = InputDirctMode;
    break;

    default:
      return E_NOT_OK;
    break;
    
  }

  if(value.U != TLE8108EM_TX_Buffer.U)
  {
    TLE8108EM_read_write(TLE8108EM_TX_Buffer.U);
  }

    duty = (uint32)dutyPercent*(0x8000)/100;

    //period 10ms, duty: percent
    /*Pwm_SetPeriodAndDuty(TLE8108_INPin_List[channel],10000000,duty);*/
  Pwm_SetDutyCycle(TLE8108_INPin_List[channel], duty);

  return ret;
}

Std_ReturnType TLE8108EM_Clear_ChannelError(DO_OUT_Ch_t channel)
{
  Std_ReturnType ret = E_OK;
  TLE8108EM_Spi_Data_T value;

  value.U = TLE8108EM_TX_Buffer.U;

  switch(channel)
  {
    case DO_OUT_1:
        TLE8108EM_TX_Buffer.SI.IN1 = TLE8108EM_ClearMode;
    break;

    case  DO_OUT_2:
        TLE8108EM_TX_Buffer.SI.IN2 = TLE8108EM_ClearMode;
    break;

    case DO_OUT_3:
        TLE8108EM_TX_Buffer.SI.IN3 = TLE8108EM_ClearMode;
    break;

    case  DO_OUT_4:
        TLE8108EM_TX_Buffer.SI.IN4 = TLE8108EM_ClearMode;
    break;

    case  DO_OUT_5:
        TLE8108EM_TX_Buffer.SI.IN5 = TLE8108EM_ClearMode;
    break;

    case  DO_OUT_6:
        TLE8108EM_TX_Buffer.SI.IN6 = TLE8108EM_ClearMode;
    break;

    case  DO_OUT_7:
        TLE8108EM_TX_Buffer.SI.IN7 = TLE8108EM_ClearMode;
    break;

    case  DO_OUT_8:
        TLE8108EM_TX_Buffer.SI.IN8 = TLE8108EM_ClearMode;
    break;

    default:
      return E_NOT_OK;
    break;
    
  }

  if(value.U != TLE8108EM_TX_Buffer.U)
  {
    TLE8108EM_read_write(TLE8108EM_TX_Buffer.U);
  }

  return ret;
}


Std_ReturnType TLE8108EM_Get_DiagStatus(DO_OUT_Ch_t channel, 
                                      TLE8108EM_DiagSt_e *diag_st)
{
  Std_ReturnType op_status = E_OK;
  TLE8108EM_Spi_Data_R value; 
  uint8 result = 0;
  
  TLE8108EM_read_write(TLE8108EM_TX_Buffer.U);
  value.U = TLE8108EM_RX_Buffer.U;
  
  switch(channel)
  {
    case DO_OUT_1:
        result = TLE8108EM_RX_Buffer.SO.DIA1;
    break;

    case DO_OUT_2:
        result = TLE8108EM_RX_Buffer.SO.DIA2;
    break;

    case DO_OUT_3:
        result = TLE8108EM_RX_Buffer.SO.DIA3;
    break;

    case DO_OUT_4:
        result = TLE8108EM_RX_Buffer.SO.DIA4;
    break;

    case DO_OUT_5:
        result = TLE8108EM_RX_Buffer.SO.DIA5;
    break;

    case DO_OUT_6:
        result = TLE8108EM_RX_Buffer.SO.DIA6;
    break;

    case DO_OUT_7:
        result = TLE8108EM_RX_Buffer.SO.DIA7;
    break;

    case DO_OUT_8:
        result = TLE8108EM_RX_Buffer.SO.DIA8;
    break;

    default:
      return E_NOT_OK;
    break;
  }

  *diag_st = (TLE8108EM_DiagSt_e)result;

  return op_status;
}

void TLE8108EM_read_write_Ext(uint16 value)
{
  TLE8108EM_read_write(value);
}