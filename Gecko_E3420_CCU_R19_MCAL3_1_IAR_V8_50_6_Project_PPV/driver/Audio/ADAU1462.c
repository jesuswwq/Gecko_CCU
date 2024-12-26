#include "ADAU1462_Cfg.h"
#include "ADAU1462_API.h"
#include "Spi.h"
#include "IoExp_TCA6424A_Api.h"


static uint8 QSpi_ADAU1462_DataRx[255] ={0} ;
static uint8 QSpi_ADAU1462_DataTx[255] = {0};

//Byte0                  Byte1                Byte2        Byte3    Byte4 and Subsequent Bytes 
//Chip Address[6:0], R/W Subaddress[15:8] Subaddress[7:0]  Data         Data
Std_ReturnType ADAU1462_Frame_Transmit(uint8 rwcmd,uint8 SubaddressHi, uint8 SubaddressLow, 
                                        uint8* payload_tx, uint8* rxdata, uint16 payload_len)
{
  Std_ReturnType ret = E_OK;
  uint8 data_idx;
  uint16 framelen = 0;

  QSpi_ADAU1462_DataTx[0] = ADAU_DEVICEID<<1 | rwcmd;
  QSpi_ADAU1462_DataTx[1] = SubaddressHi;
  QSpi_ADAU1462_DataTx[2] = SubaddressLow;

  for(data_idx = 0; data_idx < payload_len; data_idx++)
  {
    QSpi_ADAU1462_DataTx[(3+data_idx)] = payload_tx[data_idx];
  }

  framelen = payload_len + 3;
	SuspendAllInterrupts();
  ret = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_ADAU1462, 
                    &QSpi_ADAU1462_DataTx[0], 
                    rxdata, 
                    framelen);

  if(ret == E_OK)
  {
    ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_ADAU1462);
  }
   ResumeAllInterrupts();
  return ret;
}

Std_ReturnType ADAU1462_ReadReg(uint16 regaddr, uint16* RegVal)
{
  Std_ReturnType ret = E_OK;
  uint8 data_dummy[2] = {0};
  uint8 dataRx[5] = {0};
  uint8 addrHi_u8 = 0;
  uint8 addrLow_u8 = 0;

  addrHi_u8 = (regaddr&0xff00)>>8;
  addrLow_u8 = (regaddr&0x00ff);

  ret = ADAU1462_Frame_Transmit(ADAU1462_READ, addrHi_u8, addrLow_u8,data_dummy,dataRx,(uint16)2);
  if(ret == E_OK)
  {
    *RegVal = (uint16)dataRx[3]<<8;
    *RegVal |= dataRx[4];
  }

  return ret;
}

Std_ReturnType ADAU1462_WriteReg(uint16 regaddr, uint16 RegVal)
{
  Std_ReturnType ret = E_OK;
  uint8 dataTx[2] = {0};
  uint8 dataRx[5] = {0};
  uint8 addrHi_u8 = 0;
  uint8 addrLow_u8 = 0;

  addrHi_u8 = (regaddr&0xff00)>>8;
  addrLow_u8 = (regaddr&0x00ff);

  dataTx[0] = (RegVal&0xff00)>>8;
  dataTx[1] = RegVal&0x00ff;

  ret = ADAU1462_Frame_Transmit(ADAU1462_WRITE, addrHi_u8, addrLow_u8,dataTx,dataRx,(uint16)2);
  
  return ret;
}

static void ADAU1462_ActiveSlaveSPI(void)
{
  //toggle cs 3 times to active spi slave mode
  ADAU1462_WriteReg(0,0);
  ADAU1462_WriteReg(0,0);
  ADAU1462_WriteReg(0,0);
}

static void ADAU1462_Config_PLL(void)
{
  /*0xF000 0x00, 0x60 PLL_CTRL0 Set feedback divider to 96 (this is the default power-on setting). 
    0xF001 0x00, 0x02 PLL_CTRL1 Set PLL input clock divider to 4.
    0xF002 0x00, 0x01 PLL_CLK_SRC Set clock source to PLL clock.
    0xF003 0x00, 0x01 PLL_ENABLE Enable PLL.
 */
  ADAU1462_WriteReg(PLL_CTRL0,0x0060);
  // /*00 Divide by 1 
  //   01 Divide by 2 
  //   10 Divide by 4 
  //   11 Divide by 8*/
  ADAU1462_WriteReg(PLL_CTRL1,0x0002);
  ADAU1462_WriteReg(PLL_CLK_SRC,0x0001);
  ADAU1462_WriteReg(PLL_ENABLE,0x0001);
}

void ADAU1462_EnablePowerDomain(void)
{
  //enable all power domain
  ADAU1462_WriteReg(POWER_ENABLE0,0x1FFF);
  //enable PDM power
  ADAU1462_WriteReg(POWER_ENABLE1,0x0018);
}

void ADAU1462_Init(void)
{
    uint16 clocklock = 0;
    /*First step*/
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A,IOEXP_TCA6424_P27, STD_LOW);

    ADAU1462_Select_SelfBootMode(ADAU1462_BOOTFROM_SPI);
    //release chip reset pin; OUT_EXP_A_P27
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A,IOEXP_TCA6424_P27, STD_HIGH);

    ADAU1462_ActiveSlaveSPI();

    /*second step*/
    ADAU1462_Config_PLL();

    /*Third step: wait clock lock*/
    while((clocklock&0x1) != 1)
    {
      ADAU1462_ReadReg(PLL_LOCK,&clocklock);
    }
    /*Five step*/
    ADAU1462_EnablePowerDomain();

    /*six step*/
    /*0xF404 0x00, 0x00 START_ADDRESS Set program start address as defined by the SigmaStudio compiler. 
    0xF401 0x00, 0x02 START_PULSE Set DSP core start pulse to internally generated pulse. 
    N/A N/A N/A Configure any other registers that require nondefault values. 
    0xF402 0x00, 0x00 START_CORE Stop the core. 
    0xF402 0x00, 0x01 START_CORE Start the core.*/
    ADAU1462_WriteReg(START_ADDRESS,0x0000);
    ADAU1462_WriteReg(START_PULSE,0x0002);
    ADAU1462_WriteReg(START_CORE,0x0000);
    ADAU1462_WriteReg(START_CORE,0x0001);
}

void ADAU1462_Select_SelfBootMode(ADAU1462_BootMode_e BootMode)
{
    if(BootMode == ADAU1462_BOOTFROM_EEPROM)
    {
      IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A,IOEXP_TCA6424_P26, STD_HIGH);
    }
    else
    {
      IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A,IOEXP_TCA6424_P26, STD_LOW);
    }
}

void ADAU1462_Ctrl_CLKOUT(ADAU1462_CLKOUT_Frequency_e Frequency,boolean enableOut)
{
  uint16 regVal_u16 = 0;

  if((Frequency < ADAU1462_CLKOUT_SELNUM)
    &&(enableOut <= 1))
  {
    regVal_u16 |= enableOut;
    regVal_u16 |= 1<<Frequency;

    ADAU1462_WriteReg(MCLK_OUT,regVal_u16);
  }

}

void ADAU1462_InitMP6ToOutPin(void)
{
  uint16 regVal_u16 = 0;

  //General-purpose output without pull-up
  regVal_u16 = (3<<1) | 1;
  ADAU1462_WriteReg(MP6_MODE,regVal_u16);
}

void ADAU1462_InitMP7ToOutPin(void)
{
  uint16 regVal_u16 = 0;

  //General-purpose output without pull-up
  regVal_u16 = (3<<1) | 1;
  ADAU1462_WriteReg(MP7_MODE,regVal_u16);
}

void ADAU1462_CtrlMP6OutLevel(Dio_LevelType PinLevel)
{
  uint16 regVal_u16 = 0;

  regVal_u16 = PinLevel;
  ADAU1462_WriteReg(MP6_WRITE,regVal_u16);
}

void ADAU1462_CtrlMP7OutLevel(Dio_LevelType PinLevel)
{
  uint16 regVal_u16 = 0;

  regVal_u16 = PinLevel;
  ADAU1462_WriteReg(MP7_WRITE,regVal_u16);
}

void ADAU1462_SetMic1Clock(void)
{
  uint16 regVal_u16 = 0;

  //59.9HZ | LRCLK_IN0/MP10 | BCLK_IN0
  regVal_u16 = (0xa<<8)|(0<<4);
  ADAU1462_WriteReg(DMIC_CTRL0,regVal_u16);
}

void ADAU1462_SetSDATA_IN0(void)
{
  uint16 regVal_u16 = 0;

  //Slave from LRCLK_IN0 or LRCLK_OUT0 | Slave from BCLK_IN0 or BCLK_OUT0
  regVal_u16 = (0<<13)|(0<<10);
  ADAU1462_WriteReg(SERIAL_BYTE_0_0,regVal_u16);
}

void ADAU1462_SetSDATA_IN2(void)
{
  uint16 regVal_u16 = 0;

  //Slave from LRCLK_IN2 or LRCLK_OUT2 | Slave from BCLK_IN2 or BCLK_OUT2
  regVal_u16 = (2<<13)|(2<<10);
  ADAU1462_WriteReg(SERIAL_BYTE_0_0,regVal_u16);
}

