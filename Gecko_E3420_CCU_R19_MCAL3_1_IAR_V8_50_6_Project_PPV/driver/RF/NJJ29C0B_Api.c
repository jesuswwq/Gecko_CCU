
#include "NJJ29C0B_API.h"
#include "Spi.h"
#include "IoExp_TCA6424A_Api.h"

static uint8 QSpi_NJJ29C0B_DataRx[255] ={0} ;
static uint8 QSpi_NJJ29C0B_DataTx[255] = {0};


Std_ReturnType NJJ29C0B_Frame_Transmit(uint8* payload_tx, uint8* rxdata, uint16 payload_len)
{
  Std_ReturnType ret = E_OK;
  uint8 data_idx;
SuspendAllInterrupts();
  ret = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_NJJ29C0B, 
              (uint8*)payload_tx, 
              (uint8*)rxdata, 
              (uint16)payload_len);

  if(ret == E_OK)
  {
    ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_NJJ29C0B);
  }
ResumeAllInterrupts();  
  return ret;
}

void NJJ29C0B_Init(void)
{
    //release chip reset pin;LF_RESET_EN	OUT_EXP_C_P00
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_C,IOEXP_TCA6424_P00, STD_HIGH);

    //test 
    // uint8 tx[2] = {0x1,0x2};
    // uint8 rx[2];
    // NJJ29C0B_Frame_Transmit(tx,rx,2);
}

Dio_LevelType Get_NJJ29C0B_INT_PinLevel(void)
{
  Dio_LevelType pinLevel = STD_HIGH;

  //LF_INT	E3_GPIO_D28
  pinLevel = Dio_ReadChannel(DioConf_DioChannel_LF_INT_GPIO_D28);

  return pinLevel;
}
