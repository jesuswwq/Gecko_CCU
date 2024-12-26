
#include "NCK2910_API.h"
#include "Spi.h"
#include "IoExp_TCA6424A_Api.h"
#include "Platform_cfg.h"

#define MSB_FIRST 1u
#define BITS_PER_BYTE 8u
#define MASK_8_BIT 0xFFu
#define CRC_POLYNOMIAL 0x07u

static uint8 QSpi_NCK2910_DataRx[255] ={0} ;
static uint8 QSpi_NCK2910_DataTx[255] = {0};

/* Function to calculate CRC8 out of one byte and a previous CRC8
* (Used in calculateCRC8 function)
*/
uint8 calculateCRC8Byte(uint8 inputByte, uint8 initialCRC, uint8 msbFirst)
{
  /* wCRC is initialized with previous CRC8 */
  uint16 wCRC = initialCRC;
  uint8 i;
  uint8 inputShift;
  /* Calculation is done for every bit of inputByte */
  for (i = 0u; i < BITS_PER_BYTE /*8*/; i++)
  {
    /* Shift wCRC to the left */
    wCRC = wCRC << 1u;
    /* Shifting either MSB or LSB first.
    * Here msbFirst = 1u => MSB first
    */
    inputShift = (msbFirst > 0u) ? (BITS_PER_BYTE - i - 1u) : i;
    /* If wCRC > 0xFF XOR bit (7u-i) = 1. MASK_8_BIT = 0xFF*/
    if ((wCRC > MASK_8_BIT ) ^(((inputByte >> inputShift) & 0x01u) == 1u))
    {
      wCRC = wCRC ^ CRC_POLYNOMIAL;
    }
    /* Mask out last 8 bits of wCRC */
    wCRC = wCRC & MASK_8_BIT /*0xFF*/;
  }
  /* Return wCRC casted to byte (8 first bits are 0 because they were
  * masked out
  */
  return (uint8)wCRC;
}

/* Function to calculate CRC8 of a whole frame */
uint8 calculateCRC8(uint8 const* const frame_pointer, uint8 frame_length)
{
  uint8 currentCRC = 0x00;
  uint8 idx;

  /* Every byte of frame is given to calculateCRC8Byte function
  * and influences the current CRC
  */
  for(idx=0; idx < frame_length; idx++)
  {
    /* Actual byte and CRC are given to the function
    * (MSB_FIRST := 1u)
    */
    currentCRC = calculateCRC8Byte(frame_pointer[idx], currentCRC, MSB_FIRST);
  }
  return currentCRC;
}

/*Byte0  Byte1  Byte2    Byte3          …         ByteLEN
  LEN     CMD  Sub-CMD PayloadByte0  PayloadByte   CRC8*/
Std_ReturnType NCK2910_Frame_Transmit(uint8 cmd, uint8 sub_cmd, uint8* payload_tx, uint8* rxdata, uint8 payload_len)
{
  Std_ReturnType ret = E_OK;
  uint8 data_idx;
  uint16 framelen = 0;

  QSpi_NCK2910_DataTx[0] = payload_len + 3;  //cmd + subcmd + crc
  QSpi_NCK2910_DataTx[1] = cmd;
  QSpi_NCK2910_DataTx[2] = sub_cmd;

  for(data_idx = 0; data_idx < payload_len; data_idx++)
  {
    QSpi_NCK2910_DataTx[(3+data_idx)] = payload_tx[data_idx];
  }

  framelen = (uint16)QSpi_NCK2910_DataTx[0] + 1;

  QSpi_NCK2910_DataTx[payload_len + 3] = calculateCRC8(QSpi_NCK2910_DataTx, framelen);
SuspendAllInterrupts();
  ret = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_NCK2910, 
              (uint8*)&QSpi_NCK2910_DataTx[0], 
              (uint8*)rxdata, 
              (uint16)framelen);

  if(ret == E_OK)
  {
    ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_NCK2910);
  }
  ResumeAllInterrupts();
  return ret;
}

void NCK2910_Init(void)
{
    //release chip reset pin; OUT_EXP_D_P27
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_D,IOEXP_TCA6424_P27, STD_HIGH);
  NCK2910_RSTN_HIGH();
    //test MOSI:0b 71 f6 00 00 25 7e 47 64 d6 00 d8
    //     MISO:08 71 f6 xx xx 00 00 00 xx
    // uint8 payload[8] = {0, 0, 0x25, 0x7e, 0x47, 0x64, 0xd6, 0};
    // uint8 datar[8];
    // NCK2910_Frame_Transmit(0x71, 0xf6,payload,datar,8);
}

boolean Is_NCK2910_RDY_N_Active(void)
{
  Dio_LevelType pinLevel = STD_HIGH;
  boolean ret = FALSE;

  //RKE_RDY_N	OUT_EXP_D_P16
  pinLevel = IoExp_TCA6424_GetChannelInputLevel(TCA6424_CHIP_D,IOEXP_TCA6424_P16);

  if(pinLevel == STD_LOW)
  {
    ret = TRUE;
  }
  else
  {
    ret = FALSE;
  }

  return ret;
}

boolean Is_NCK2910_INT_Active(void)
{
  Dio_LevelType pinLevel = STD_HIGH;
  boolean ret = FALSE;

  //RKE_INT	E3_GPIO_D37
  pinLevel = Dio_ReadChannel(DioConf_DioChannel_RKE_INT_GPIO_D37);

  if(pinLevel == STD_LOW)
  {
    ret = TRUE;
  }
  else
  {
    ret = FALSE;
  }

  return ret;
}
