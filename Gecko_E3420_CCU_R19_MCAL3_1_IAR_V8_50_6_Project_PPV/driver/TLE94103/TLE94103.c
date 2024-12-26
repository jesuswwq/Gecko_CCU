
#include "TLE94103.h"
#include "Spi.h"
#include "IoExp_TCA6424A_Api.h"
#include "Mcu_Delay.h"

#define TLE94103_CLEAR_BIT(value,pos) ((value)&=~(1<<(pos)))
#define TLE94103_SET_BIT(value,pos)   ((value)|= (1<<(pos)))

typedef union
{
  struct 
  {
    uint8 reserved       :1;
    uint8 TPW            :1;
    uint8 TSD            :1;
    uint8 NPOR           :1;
    uint8 VS_OV          :1;
    uint8 VS_UV          :1;
    uint8 LE             :1;
    uint8 SPI_ERR        :1;
  }B;    
  uint8 U;
} TLE94103_Spi_SYS_DIAG1_t;

typedef struct
{
   TLE94103_CHIPID_e ChipId;
   Spi_ChannelType SpiCh;
   Spi_SequenceType SpiSeq;
   uint16 EN_Pin;
}TLE75242_CtrlBlock_t_;

static TLE94103_Spi_SYS_DIAG1_t TLE94103_SYS_DIAG1;
static uint16 QSpi_TLE94103_DataRx = 0;
static uint16 QSpi_TLE94103_DataTx = 0;

const TLE75242_CtrlBlock_t_ TLE94103_List[TLE94103_CHIP_NUM] = 
{
	{TLE94103_CHIP_A, SpiConf_SpiChannel_SpiChannel_TLE94103A, SpiConf_SpiSequence_SpiSequence_TLE94103A, IOEXP_TCA6424_P11},
	{TLE94103_CHIP_B, SpiConf_SpiChannel_SpiChannel_TLE94103B, SpiConf_SpiSequence_SpiSequence_TLE94103B, IOEXP_TCA6424_P13 }
};

static Std_ReturnType TLE94103_read_reg(TLE94103_CHIPID_e ChipID ,uint8 reg, uint8* reg_Value)
{
  Std_ReturnType ret = E_OK;
  Spi_ChannelType SpiCh;
  Spi_SequenceType SpiSeq;

  SpiCh = TLE94103_List[ChipID].SpiCh;
  SpiSeq = TLE94103_List[ChipID].SpiSeq;

  QSpi_TLE94103_DataTx =  (TLE94103_OP_READ<<7)| (uint16)(reg<<2) | (NO_DAISY_CHAIN_LABT<<1) | 0x1;
  SuspendAllInterrupts();
  ret = Spi_SetupEB(SpiCh, 
              (uint8*)&QSpi_TLE94103_DataTx, 
              (uint8*)&QSpi_TLE94103_DataRx, 
              (uint16)1);

  if(ret == E_OK)
  {
    ret = Spi_SyncTransmit(SpiSeq);

    if(ret == E_OK)
    {
      *reg_Value = (QSpi_TLE94103_DataRx&0xFF00)>>8;
      TLE94103_SYS_DIAG1.U = (QSpi_TLE94103_DataRx&0x00FF);
    }
  }
  ResumeAllInterrupts();  
  return ret;
}

static Std_ReturnType TLE94103_write_reg(TLE94103_CHIPID_e ChipID, uint8 reg, uint8 reg_Value)
{
  Std_ReturnType ret = E_OK;
  Spi_ChannelType SpiCh;
  Spi_SequenceType SpiSeq;

  SpiCh = TLE94103_List[ChipID].SpiCh;
  SpiSeq = TLE94103_List[ChipID].SpiSeq;

  QSpi_TLE94103_DataTx = ((uint16)reg_Value<<8)|(TLE94103_OP_WRITE<<7)| (uint16)(reg<<2) | (NO_DAISY_CHAIN_LABT<<1) | 0x1;
  SuspendAllInterrupts();
  ret = Spi_SetupEB(SpiCh, 
              (uint8*)&QSpi_TLE94103_DataTx, 
              (uint8*)&QSpi_TLE94103_DataRx, 
              1);

  if(ret == E_OK)
  {
    ret = Spi_SyncTransmit(SpiSeq);
    TLE94103_SYS_DIAG1.U = (QSpi_TLE94103_DataRx&0x00FF);
  }
  ResumeAllInterrupts();  
  return ret;
}

void TLE94103_Init(void)
{
    //release chipB en pin; OUT_EXP_B_P13
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,IOEXP_TCA6424_P13, STD_HIGH);

    //release chipA en pin; OUT_EXP_B_P13
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,IOEXP_TCA6424_P11, STD_HIGH);

    //The output registers must be reset to their default values by programming the Clear mode for all channels once.
    // TLE94103_read_reg(HB_CONFIG_CTRL_REG,&regVal_u16);
    uint8 deviceid;
    deviceid = TLE94103_Get_DeviceID(TLE94103_CHIP_A);
    deviceid = TLE94103_Get_DeviceID(TLE94103_CHIP_B);
}

void TLE94103_SwitchToSleep(TLE94103_CHIPID_e ChipID)
{
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B,TLE94103_List[ChipID].EN_Pin, STD_LOW);
}

Std_ReturnType TLE94103_Set_HSChannelON(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;

  ret = TLE94103_read_reg(ChipID, HB_ACT_1_CTRL_REG,&regVal_u8);
  if(ret == E_OK)
  {
    //clear LS on
    TLE94103_CLEAR_BIT(regVal_u8,(channel*2));
    //open HS on
    TLE94103_SET_BIT(regVal_u8,(channel*2+1));

    ret = TLE94103_write_reg(ChipID, HB_ACT_1_CTRL_REG,regVal_u8);
  }
  
  return ret;
}

Std_ReturnType TLE94103_Set_LSChannelON(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;

  ret = TLE94103_read_reg(ChipID, HB_ACT_1_CTRL_REG,&regVal_u8);
  if(ret == E_OK)
  {
    //clear HS on
    TLE94103_CLEAR_BIT(regVal_u8,(channel*2+1));
    //open LS on
    TLE94103_SET_BIT(regVal_u8,(channel*2));

    ret = TLE94103_write_reg(ChipID, HB_ACT_1_CTRL_REG,regVal_u8);
  }
  
  return ret;
}

Std_ReturnType TLE94103_Set_ChannelOFF(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;

  ret = TLE94103_read_reg(ChipID, HB_ACT_1_CTRL_REG,&regVal_u8);
  if(ret == E_OK)
  {
    //clear HS on
    TLE94103_CLEAR_BIT(regVal_u8,(channel*2+1));
    //clear LS on
    TLE94103_CLEAR_BIT(regVal_u8,(channel*2));

    ret = TLE94103_write_reg(ChipID, HB_ACT_1_CTRL_REG,regVal_u8);
  }
  
  return ret;
}

Std_ReturnType TLE94103_Set_FM_Modulation(TLE94103_CHIPID_e ChipID,TLE94103_FMModulation_e FMMode)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;

  regVal_u8 = FMMode<<6;

  ret = TLE94103_write_reg(ChipID, FM_CLK_CTRL_REG,regVal_u8);
  
  return ret;
}

uint8 TLE94103_Get_DeviceID(TLE94103_CHIPID_e ChipID)
{
  uint8 regVal_u8 = 0;

  TLE94103_read_reg(ChipID, HB_CONFIG_CTRL_REG,&regVal_u8);

  return regVal_u8;
}


Std_ReturnType TLE94103_Clear_ChannelError(TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;

  return ret;
}

TLE94103_CHIP_GlobalDiag_e TLE94103_DiagChip_Status(TLE94103_CHIPID_e ChipID)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;
  TLE94103_CHIP_GlobalDiag_e diagst = TLE94103_NOERR;

  ret = TLE94103_read_reg(ChipID, HB_SYS_DIAG_1_REG,&regVal_u8);
  if(ret == E_OK)
  {
    TLE94103_SYS_DIAG1.U = regVal_u8;
    if(TLE94103_SYS_DIAG1.B.SPI_ERR != 0)
    {
      diagst = TLE94103_COM_SPI_ERR;
    }
    else if(TLE94103_SYS_DIAG1.B.LE != 0)
    {
      diagst = TLE94103_OUT_OPENLOAD_OVERCURRENT;
    }
    else if(TLE94103_SYS_DIAG1.B.VS_UV != 0)
    {
      diagst = TLE94103_VS_UV;
    }
    else if(TLE94103_SYS_DIAG1.B.VS_OV != 0)
    {
      diagst = TLE94103_VS_OV;
    }
    else if(TLE94103_SYS_DIAG1.B.TSD != 0)
    {
      diagst = TLE94103_TEMPERATURE_SHUTDOWN;
    }
    else if(TLE94103_SYS_DIAG1.B.TPW != 0)
    {
      diagst = TLE94103_TEMPERATURE_WARNING;
    }
    else
    {
      diagst = TLE94103_NOERR;
    }
  }

  return diagst;
}

boolean TLE94103_DiagHSCh_OverCurrent(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;
  boolean result = FALSE;

  ret = TLE94103_read_reg(ChipID, HB_SYS_DIAG_2_REG,&regVal_u8);
  if(ret == E_OK)
  {
    if(regVal_u8 &(1<<(channel*2+1)) != 0)
    {
      result = TRUE;
    }
    else
    {
      result = FALSE;
    }
  }

  return result;
}

boolean TLE94103_DiagLSCh_OverCurrent(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;
  boolean result = FALSE;

  ret = TLE94103_read_reg(ChipID, HB_SYS_DIAG_2_REG,&regVal_u8);
  if(ret == E_OK)
  {
    if(regVal_u8 &(1<<(channel*2)) != 0)
    {
      result = TRUE;
    }
    else
    {
      result = FALSE;
    }
  }

  return result;
}

boolean TLE94103_DiagHSCh_Openload(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;
  boolean result= FALSE;

  ret = TLE94103_read_reg(ChipID, HB_SYS_DIAG_3_REG,&regVal_u8);
  if(ret == E_OK)
  {
    if(regVal_u8 &(1<<(channel*2+1)) != 0)
    {
      result = TRUE;
    }
    else
    {
      result = FALSE;
    }
  }

  return result;
}

boolean TLE94103_DiagLSCh_Openload(TLE94103_CHIPID_e ChipID, TLE94103_OUT_Ch_e channel)
{
  Std_ReturnType ret = E_OK;
  uint8 regVal_u8 = 0;
  boolean result= FALSE;

  ret = TLE94103_read_reg(ChipID, HB_SYS_DIAG_3_REG,&regVal_u8);
  if(ret == E_OK)
  {
    if(regVal_u8 &(1<<(channel*2)) != 0)
    {
      result = TRUE;
    }
    else
    {
      result = FALSE;
    }
  }

  return result;
}