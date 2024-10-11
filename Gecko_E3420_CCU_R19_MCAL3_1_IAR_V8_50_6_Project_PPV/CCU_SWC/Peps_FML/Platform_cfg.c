
#include "platform_cfg.h"
#include "ioexp_tca6424a_api.h"
#include "Os_Processor.h"

extern void nck2910_interrupt_handler(uint32_t irq, uint32_t pin, void *arg);
extern void njj29c0_interrupt_handler(uint32_t irq, uint32_t pin, void *arg);

#ifdef demoboard

static struct sdrv_spi g_spi2_master;

static struct spi_device_config spi_nck2910_cfg = {
    .sclk_freq = 2000000,
    .cpol = SCK_IDLE_HIGH,
    .cpha = DATA_CPT_ON_FIRST_SCK_EDGE,
    .cs_pol = CS_ACTIVE_LOW,
    .cs_sel = CS_SEL_SS0,
    .width = SPI_DATA_WIDTH_BYTE,
    .fream_delay = 0,
    .clk2cs_delay = 0,
    .clk2cs_end_delay = 0,
    .is_lsb_mode = false,
};

static struct spi_device_config spi_njj29c0_cfg = {
    .sclk_freq = 1000000,
    .cpol = SCK_IDLE_LOW,
    .cpha = DATA_CPT_ON_SECOND_SCK_EDGE,
    .cs_pol = CS_ACTIVE_LOW,
    .cs_sel = CS_SEL_SS0,
    .width = SPI_DATA_WIDTH_BYTE,
    .fream_delay = 0,
    .clk2cs_delay = 0,
    .clk2cs_end_delay = 0,
    .is_lsb_mode = true,
};


static struct spi_common_config spi2_master = {
    .is_spi_mode = true,
    .is_half_mode = false,
    .is_master = true,
    .base = APB_SPI2_BASE,
    .irq = SPI2_SPI_INTR_NUM,
#if CONFIG_E3
    .clk = &g_ckgen_ip_spi_sf_1_to_4,
#else
    .clk = &g_ckgen_ip_spi_sf_1_to_3,
#endif
};


/*****************************************************************************
**                             Global Functions                            **
*****************************************************************************/
void Spi2_Init(void)
{	
    /* Init Spi Instance  */
    sdrv_spi_init(&g_spi2_master, &spi2_master);

	/* select external spi slave device  */
    sdrv_spi_config_device(&g_spi2_master, &spi_nck2910_cfg);
}


/*****************************************************************************
 *  @brief     : nck2910 Initialize the spi2 module
 *  @param in  : SPIx_SFR
 *  @param out : None
 *  @retval    : None
 ****************************************************************************/
void Nck2910_Spi2_Init(void)
{
	(void) sdrv_spi_deinit(&g_spi2_master);
	
    /* Init Spi Instance  */
    sdrv_spi_init(&g_spi2_master, &spi2_master);

	/* select external spi slave device  */
    sdrv_spi_config_device(&g_spi2_master, &spi_nck2910_cfg);
}

/*****************************************************************************
 *  @brief     : njj29c0 Initialize the spi2 module
 *  @param in  : SPIx_SFR
 *  @param out : None
 *  @retval    : None
 ****************************************************************************/
void Njj29c0_Spi2_Init(void)
{
	(void) sdrv_spi_deinit(&g_spi2_master);
	
    /* Init Spi Instance  */
    sdrv_spi_init(&g_spi2_master, &spi2_master);

	/* select external spi slave device  */
    sdrv_spi_config_device(&g_spi2_master, &spi_njj29c0_cfg);
}


uint8_t Spi2Transmit(uint8_t * txbuf,uint8_t *rxbuf,uint32_t len)
{
	if (sdrv_spi_sync_transmit(&g_spi2_master, txbuf, rxbuf, len, 100) != 0)
	{
		return 0;
	}

	while (sdrv_spi_get_status(&g_spi2_master) == SPI_BUSY) 
	{
		sdrv_spi_polling(&g_spi2_master);
	}

	return 1;
}


void Nck2910_Interrupt_En(void)
{
	Dio_Ip_IrqStatusClear(NCK2910_INTN_PIN);
	sdrv_gpio_pin_interrupt_disable(NCK2910_INTN_PIN);
	sdrv_gpio_set_pin_interrupt(NCK2910_INTN_PIN, GPIO_INTR_FALLING_EDGE);
	sdrv_gpio_register_interrupt_handler(NCK2910_INTN_PIN, nck2910_interrupt_handler, NULL);
	sdrv_gpio_pin_interrupt_enable(NCK2910_INTN_PIN);
}

void NJJ29C0_Interrupt_En(void)
{
	Dio_Ip_IrqStatusClear(NJJ29C0_INTERRUPT_PIN);
	sdrv_gpio_pin_interrupt_disable(NJJ29C0_INTERRUPT_PIN);
	sdrv_gpio_set_pin_interrupt(NJJ29C0_INTERRUPT_PIN, GPIO_INTR_RISING_EDGE);
	sdrv_gpio_register_interrupt_handler(NJJ29C0_INTERRUPT_PIN, njj29c0_interrupt_handler, NULL);
	sdrv_gpio_pin_interrupt_enable(NJJ29C0_INTERRUPT_PIN);
}

/*********************************************************************************************************
** Function name:		_NCK2910_IoInit
** Descriptions:		��ʼ��NCK2910���IO��
**						NCK2910_RDYN	: 
						NCK2910_RSTN	: 
						NCK2910_INTN	: 
						NCK2910_CSN		: 
** input parameters:	
** output parameters:	
** Returned value:		
*********************************************************************************************************/
void _NCK2910_Hal_Init(void)
{
	Spi2_Init();
	
	NCK2910_CSN_HIGH();

	//NJJ29C0_Interrupt_En();
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
	Nck2910_Spi2_Init();
	(void)Spi2Transmit(pu8WrBuf, u8rxbuf, WrBufLen);
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
		
	Nck2910_Spi2_Init();
	(void)Spi2Transmit(u8txbuf, pu8RdBuf, 1);

	if ((pu8RdBuf[0] <= MAX_BUFFER_LENGTH) && (pu8RdBuf[0] >= 2))
	{
		Spi2Transmit(u8txbuf, &pu8RdBuf[1], pu8RdBuf[0]);
	}
}

int NJJ29C0_Spi_ReadWrite(uint8_t * txbuf,uint8_t *rxbuf,uint32_t len)
{
	Njj29c0_Spi2_Init();
	return Spi2Transmit(txbuf,rxbuf,len);
}


#else

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

#endif

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
#ifdef demoboard
	uint32_t		i, j;

	for (i = 0; i < nus; i++)
	{
		for (j = 0; j < 150; j++)
		{
			;
		}
	}
#else
	Mcu_udelay(nus);
#endif
}

void Njj29c0_Delay(uint32_t count)
{
#ifdef demoboard
	uint32_t		i, j;

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < 150; j++)
		{
			;
		}
	}
#else
	Mcu_udelay(count);
#endif
}

/*--------EOF--------*/
