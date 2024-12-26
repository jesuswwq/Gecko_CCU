
#include "platform_cfg.h"
#include "ioexp_tca6424a_api.h"
#include "Os_Processor.h"

extern void nck2910_interrupt_handler(uint32_t irq, uint32_t pin, void *arg);
extern void njj29c0_interrupt_handler(uint32_t irq, uint32_t pin, void *arg);

int Spi2Transmit(uint8_t ic,uint8_t * txbuf,uint8_t *rxbuf,uint32_t len)
{
  Std_ReturnType ret = E_OK;

  if(ic == 0)
  {
	  ret = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_NCK2910, 
              (uint8*)txbuf, 
              (uint8*)rxbuf, 
              len);

	  if(ret == E_OK)
	  {
	    ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_NCK2910);
	  }
  }
  else if(ic == 1)
  {
	 ret = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_NJJ29C0B, 
              (uint8*)txbuf, 
              (uint8*)rxbuf, 
              len);

	  if(ret == E_OK)
	  {
	    ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_NJJ29C0B);
	  }
  }
  else
  {
	ret = E_NOT_OK;
  }

  if(ret > 0)
  {
	ret  = 0;
  }
  else
  {
	ret  = 1;	
  }
  
  return ret;
}

void _NCK2910_Hal_Init(void)
{
                                                                        NCK2910_CSN_HIGH();
    OS_INTERRUPT_DISABLE(GPIO_AP_SYNC_DGPIO);
}

/*********************************************************************************************************
** Function name:		NCK2910_SpiWrite
** Descriptions:		ͨ��SPI��������
** input parameters:	pu8WrBuf : SPIд����ָ��
**						WrBufLen : SPIд���峤�ȣ�unit(Byte)
** output parameters:	
** Returned value:		
*********************************************************************************************************/
void NCK2910_SpiWrite(uint8_t * pu8WrBuf, uint8_t WrBufLen)
{
	uint8_t 		u8rxbuf[MAX_BUFFER_LENGTH] =
	{
		0
	};

	(void)Spi2Transmit(0,pu8WrBuf, u8rxbuf, WrBufLen);
}


/*********************************************************************************************************
** Function name:		NCK2910_SpiRead
** Descriptions:		ͨ��SPI������
** input parameters:	pu8RdBuf : SPI������ָ��
** output parameters:	
** Returned value:		
*********************************************************************************************************/
void NCK2910_SpiRead(uint8_t * pu8RdBuf)
{
	uint8_t 		u8txbuf[MAX_BUFFER_LENGTH] =
	{
		0
	};

	(void)Spi2Transmit(0,u8txbuf, pu8RdBuf, 1);

	if ((pu8RdBuf[0] <= MAX_BUFFER_LENGTH) && (pu8RdBuf[0] >= 2))
	{
		Spi2Transmit(0,u8txbuf, &pu8RdBuf[1], pu8RdBuf[0]);
	}
}

int NJJ29C0_Spi_ReadWrite(uint8_t * txbuf,uint8_t *rxbuf,uint32_t len)
{
	return Spi2Transmit(1,txbuf,rxbuf,len);
}

/*******************************************************************************
*Name: Nck2910_delay(char *Functionname, uint8* TxBuff, uint16 Txlen)
*Description: ��ʱ������count=1000��Ҳ����1Ms
*Input : Functionname	- 函数�?
		 TxBuff 		- �?要打印的数组
		 Txlen			- �?要打印的长度
*Output: None
*Return: None
*******************************************************************************/
void _Nck2910_delay_us(uint32_t nus)
{
	Mcu_udelay(nus);
}

void Njj29c0_Delay(uint32_t count)
{
	Mcu_udelay(count);
}

/*--------EOF--------*/
