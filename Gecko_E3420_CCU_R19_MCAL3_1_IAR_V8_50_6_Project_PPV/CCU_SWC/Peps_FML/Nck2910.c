
#include "nck2910.h"
#include "LoopFifo.h"

/*********************************************************************************************************
  local function
*********************************************************************************************************/
static uint8_t _CalculateCRC8Byte(uint8_t u8InputByte, uint8_t u8InitialCrc);
uint8_t _CalculateCRC8(uint8_t *pu8FrameBuf, uint8_t u8Len);
static uint8_t _NCK2910_RciCmdSend(uint8_t u8Cmd, uint8_t u8SubCmd,
								   uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DC_SET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DC_GET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DC_COPY2RAM(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DC_COPY2NV(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DC_PATCHRAM(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DC_HASH(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DC_GET_STATUS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OS_SET_POLLING(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OS_GET_POLLING(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OS_STORE_POLLING(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OS_SET_MODE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OS_STATUS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_RB_READ_MSG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_RB_READ_BYTES(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_RB_FLUSH_MSG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_RB_STATUS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_PE_VERSIONS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_PE_CAPABILITY(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DD_SET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DD_GET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DD_HASH(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DD_SIG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_DD_TIME(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_WI_CONFIG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_WI_CLEAR(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_WI_STORE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_WI_ECHO(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_WI_ECHO_NXP(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OBM_CONF(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OBM_READ(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OBM_RSSI_OFMU(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OBM_SET_FREQUENCY_OFFSET_OVERRIDE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OBM_GET_FREQUENCY_OFFSET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_OBM_DO_LO_CORRECTION(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_MISC_WAIT_US(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_MISC_PIN_TOGGLE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_EV_TIMER_HEARTBEAT(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_TX_TRIGGER(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_TX_WRITE_PAYLOAD(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);
static uint8_t _RciCmd_TX_READ_PAYLOAD(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen);

// static void _NCK2910_PFlashInit(void);
// static uint8_t _NCK2910_RfParaInit(void);

/*********************************************************************************************************
  local variable
*********************************************************************************************************/
static uint8_t _u8RciCmdDCSendF;	   // Device Configuration�������ͱ��?
static uint8_t _u8RciCmdOSSendF;	   // Operating State�������ͱ��?
static uint8_t _u8RciCmdRBSendF;	   // RX Buffer�������ͱ��?
static uint8_t _u8RciCmdPESendF;	   // Personality�������ͱ��?
static uint8_t _u8RciCmdDDSendF;	   // Debug�������ͱ��?
static uint8_t _u8RciCmdWISendF;	   // Wired Interface�������ͱ��?
static uint8_t _u8RciCmdOBMSendF;	   // On-Board Measurement�������ͱ��?
static uint8_t _u8RciCmdMISCSendF;	   // Miscellaneous�������ͱ��?
static uint8_t _u8RciCmdEV_TIMERSendF; // Event Handling�������ͱ��?
static uint8_t _u8RciCmdTXSendF;	   // Transmitter�������ͱ��?

/*********************************************************************************************************
  global variable
*********************************************************************************************************/
uint8_t Gu8Nck2910RciTxBuf[64]; // NCK2910 RCI���ͻ�����
uint8_t Gu8Nck2910RciRxBuf[64]; // NCK2910 RCI���ջ�����
uint8_t Gu8Nck2910RciRxLen;		// NCK2910 RC1���յ���֡����

uint32 u32UhfRxNum = 0;

extern uint8_t u8Rssi_Can_Tx;
extern uint8_t g_datCan1Tx_0x330[8];

/*********************************************************************************************************
  const variable
*********************************************************************************************************/
// ���µ��������飬Ҫ��RCI��λ�����ɵ�SPI�����¼�У�ȥ��LEN��CMD��SUBCMD��CRC�ֽڣ�Ҳ��ֻ����payload
const uint8_t c_u8LoCfgBuf[RX_CFG_NUM][LO_CFG_BUF_LEN] =
	{
		{0x00, 0x00, 0x90, 0x6e, 0x3d, 0x35, 0x9f, 0x00},
		{0x01, 0x00, 0x5c, 0x24, 0x3b, 0x35, 0x9f, 0x00},
};

const uint8_t c_u8DigFreqBuf[RX_CFG_NUM][DIG_FREQ_BUF_LEN] =
	{
		{0x00, 0x01, 0xae, 0x1d, 0x00},
		{0x01, 0x01, 0xae, 0x1d, 0x00},
};

const uint8_t c_u8FilterBuf[RX_CFG_NUM][FILTER_BUF_LEN] =
	{
		{0x00, 0x02, 0x23, 0xae, 0x1d, 0x09, 0x00, 0x48, 0x42, 0x00,
		 0x00, 0x3f, 0x00, 0x00, 0x00, 0xaf, 0x14, 0x40, 0x15, 0x20,
		 0x01, 0x88, 0x00, 0x00, 0x00, 0x47, 0x08, 0x02, 0x20, 0x36,
		 0x00, 0x0d, 0x40, 0x07, 0x62, 0x00, 0x11, 0xcd, 0x40, 0x80,
		 0x2c, 0xb4, 0x16, 0x20, 0x25, 0x74, 0x00, 0x00},
		{0x01, 0x02, 0x23, 0xae, 0x1d, 0x09, 0x00, 0x48, 0x42, 0x00,
		 0x00, 0x3f, 0x00, 0x00, 0x00, 0xaf, 0x14, 0x40, 0x15, 0x20,
		 0x01, 0x88, 0x00, 0x00, 0x00, 0x47, 0x08, 0x02, 0x20, 0x36,
		 0x00, 0x0d, 0x40, 0x07, 0x62, 0x00, 0x11, 0xcd, 0x40, 0x80,
		 0x2c, 0xb4, 0x16, 0x20, 0x25, 0x74, 0x00, 0x00},
};

const uint8_t c_u8BaseBandBuf[RX_CFG_NUM][BASEBAND_BUF_LEN] =
	{
		{0x00, 0x03, 0xc0, 0x8f, 0x2c, 0xb0, 0x07, 0xa6, 0x1a, 0xa5,
		 0xdf, 0x6c, 0x5c, 0x1d, 0x6b, 0x00, 0xf6, 0x48, 0x5f, 0x31,
		 0x2a, 0x3d, 0x24, 0x00, 0x88, 0x05, 0x28, 0x68, 0x33, 0x40,
		 0x4f, 0x94, 0x61, 0x10, 0x58, 0x06, 0x40, 0x00, 0x4a, 0x04,
		 0x00, 0x00, 0x74, 0x08, 0x00, 0x00, 0x00},
		{0x01, 0x03, 0xc0, 0x8f, 0x2c, 0xb0, 0x07, 0xa6, 0x1a, 0xa5,
		 0xdf, 0x6c, 0x5c, 0x1d, 0x6b, 0x00, 0xf6, 0x48, 0x5f, 0x31,
		 0x2a, 0x3d, 0x24, 0x00, 0x88, 0x05, 0x28, 0x68, 0x33, 0x40,
		 0x4f, 0x94, 0x61, 0x10, 0x58, 0x06, 0x40, 0x00, 0x4a, 0x04,
		 0x00, 0x00, 0x74, 0x08, 0x00, 0x00, 0x00},
};

const uint8_t c_u8FrameWupBuf[RX_CFG_NUM][FRAME_WUP_BUF_LEN] =
	{
		{0x00, 0x04, 0xc0, 0x21, 0x66, 0x03, 0x80, 0x6c, 0xa4, 0xb8,
		 0xa5, 0xb2, 0x20, 0x00, 0x00},
		{0x01, 0x04, 0xc0, 0x21, 0x66, 0x03, 0x80, 0x6c, 0xa4, 0xb8,
		 0xa5, 0xb2, 0x20, 0x00, 0x00},
};

const uint8_t c_u8SwBuf[RX_CFG_NUM][SW_BUF_LEN] =
	{
		{0x00, 0x05, 0x00, 0x00, 0x90, 0xa1, 0x90, 0x60, 0x10, 0x2a,
		 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x01, 0x05, 0x00, 0x00, 0x90, 0xa1, 0x90, 0x60, 0x10, 0x2a,
		 0x00, 0xc0, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00},
};

const uint8_t c_u8MidMapBuf[RX_CFG_NUM][MID_MAP_BUF_LEN] =
	{
		{0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
		 0x00},
		{0x01, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
		 0x00},
};

const uint8_t c_u8MidBuf[RX_CFG_NUM][MID_BUF_LEN] =
	{
		{0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00},
};

const uint8_t c_u8SlotCfgBuf[RX_CFG_NUM][SLOT_CFG_BUF_LEN] =
	{
		{0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x01, 0x08, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00},
};

const uint8_t c_u8ReceptionCfgBuf[RX_CFG_NUM][REC_CFG_BUF_LEN] =
	{
		{0x00, 0x09, 0x00, 0x00, 0x00},
		{0x01, 0x09, 0x01, 0x01, 0x00},
};

const uint8_t c_u8PollingCfgBuf[POLLING_CFG_BUF_LEN] =
	{
		0x00, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x0c, 0x00, 0xff, 0x00, 0xf0, 0x00};

const uint8_t c_u8PflashCfgBuf[PFLASH_CFG_BUF_LEN] =
	{
		0x01, 0xb2, 0x7e, 0x4c};

const uint8_t c_u8PflashCfg_Int_Ignored_Buf[PFLASH_CFG_BUF_LEN] =
	{
		0x01, 0xB3, 0x7E, 0x64};

const uint8_t c_u8PflashCfg_Duraion_Buf[PFLASH_CFG_BUF_LEN + 1] =
	{
		0x02, 0x1e, 0x7a, 0xe0, 0x2e};

const uint8_t c_u8PflashCfgLockBuf[PFLASH_CFG_LOCK_LEN] =
	{
		0x02, 0xbe, 0x7e, 0x70, 0x00};

static boolean bNck2910InterruptFlag = false;

Nck2910_Work_State tnNck2910WorkStatus = NCK2910_INIT;

UHF_MessageTypeDef nck2910recvFrame[5]; // NCK2910 ?????????

static uint8 nck2910ReadyFlag = 0;

LPFifo_TypeDef LPFifo;

uint8 u8Nck2910RciReadWorkMode = 0;

extern void SetEcuPowerOnMode(uint8 para);

extern uint8 GetEcuPowerOnMode(void);

/*******************************************************************************
 * ??????  : GetNck2910InitCompleteStatus
 * ????	 : ???NCK2910??????????
 * ????	 : None
 * ????	 : 0??��???,1?????
 *******************************************************************************/
uint8 GetNck2910InitCompleteStatus(void)
{
	return nck2910ReadyFlag;
}

/*******************************************************************************
 *Name: Nck2910_COM_WaitPinLevel
 *Description: This function waits until a GPIO pin has desired value.
 *Input : None
 *Output: None
 *Return: None
 *******************************************************************************/
boolean Nck2910_COM_WaitPinLevel(uint32_t ChannelId, uint8 pinValExp, uint32_t tmoutUs)
{
	volatile uint8 pinVal; /* Value of a pin. */
	uint32_t tmoutUsTemp = 0U;

	do
	{
		pinVal = Dio_ReadChannel(ChannelId);
		tmoutUsTemp += LZ_COM_TIMEOUT_STEP_US;

		/* WaitUS function ensures the timeout value is not less than a desired
		 * time (tmoutUs). */
		_Nck2910_delay_us(LZ_COM_TIMEOUT_STEP_US);
		tmoutUsTemp += LZ_COM_TIMEOUT_STEP_US;
	} while ((pinVal != pinValExp) && (tmoutUs > tmoutUsTemp));

	return (tmoutUs > tmoutUsTemp) ? TRUE : FALSE;
}

/*********************************************************************************************************
** Function name:		_CalculateCRC8Byte
** Descriptions:		NXP RCI_V1.1 CRC�㷨
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _CalculateCRC8Byte(uint8_t u8InputByte, uint8_t u8InitialCrc)
{
	uint8_t i = 0;
	uint16_t u16Crc = u8InitialCrc;
	uint8_t inputShift = 0;

	for (i = 0; i < 8; i++)
	{
		u16Crc = u16Crc << 1U;
		inputShift = 8 - i - 1;

		if ((u16Crc > 0xFF) ^ (((u8InputByte >> inputShift) & 0x01U) == 1U))
		{
			u16Crc = u16Crc ^ 0x07;
		}

		u16Crc = u16Crc & 0xff;
	}

	return (uint8_t)
		u16Crc;
}

/*********************************************************************************************************
** Function name:		_CalculateCRC8
** Descriptions:		NXP RCI_V1.1 CRC�㷨
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t _CalculateCRC8(uint8_t *pu8FrameBuf, uint8_t u8Len)
{
	uint8_t u8CurrentCRC = 0x00;
	uint8_t idx = 0;

	for (idx = 0; idx < u8Len; idx++)
	{
		u8CurrentCRC = _CalculateCRC8Byte(pu8FrameBuf[idx], u8CurrentCRC);
	}

	return u8CurrentCRC;
}

/*********************************************************************************************************
** Function name:		_NCK2910_RciCmdSend
** Descriptions:		�������2910����ѭNXP RCIЭ��
** input parameters:	u8Cmd : ������
						u8SubCmd : ������
						pu8PayLoadBuf : ���ݻ���ָ��
						u8PayLoadLen : ���ݻ��峤��
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _NCK2910_RciCmdSend(uint8_t u8Cmd, uint8_t u8SubCmd,
								   uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t index = 1; // ��һ���ֽ�Ϊ�����ֽڣ������ʼֵ�?�������ֽ����Ÿ�ֵ
	uint8_t j = 0;
	uint8_t crc8;

	// Step1 : ��������?
	Gu8Nck2910RciTxBuf[index++] = u8Cmd; // Cmd

	// ���ָ�ʽ��ECHO�����û��SubCmd��Ҳ����������û��SubCmd
	if ((WI_ECHO_CMD != u8Cmd) && (WI_ECHO_NXP_CMD != u8Cmd))
	{
		Gu8Nck2910RciTxBuf[index++] = u8SubCmd; // SubCmd(��һ����)
	}

	for (j = 0; j < u8PayLoadLen; j++)
	{
		Gu8Nck2910RciTxBuf[index++] = pu8PayLoadBuf[j]; // PayLoad
	}

	Gu8Nck2910RciTxBuf[0] = index;					  // LEN
	crc8 = _CalculateCRC8(Gu8Nck2910RciTxBuf, index); // CRC
	Gu8Nck2910RciTxBuf[index++] = crc8;

	// Step2 : ��������֡
	// NCK2910_CSN_HIGH();
	// DelayCsT1();									// ��ʱ��Ϊ��ȷ��CS�ɿ���Ч
	NCK2910_CSN_LOW();
	DelayCsT2(); // CsT1 + CsT2Ҫ����Trdy2rcv������RCI V1.1ʱ��淶��Ҳ����ͨ�����RDY_N�ܽŷ�ʽ
	NCK2910_SpiWrite(Gu8Nck2910RciTxBuf, index);
	NCK2910_CSN_HIGH(); // ����SPI���ݺ��������ߣ��������߸��ŵ��²���Ԥ֪�Ķ���

	if (Gu8Nck2910RciTxBuf[2] == DD_SET_SUB_CMD)
	{
		_Nck2910_delay_us(3500);
	}
	else
	{
		_Nck2910_delay_us(200);
	}

	// Step3 : ������Ӧ֡
	// NCK2910_CSN_HIGH();
	// DelayCsT1();									// ��ʱ��Ϊ��ȷ��CS�ɿ���Ч
	NCK2910_CSN_LOW();
	DelayCsT2();						 // CsT1 + CsT2Ҫ����Trdy2rcv������RCI V1.1ʱ��淶��Ҳ����ͨ�����RDY_N�ܽŷ�ʽ
	NCK2910_SpiRead(Gu8Nck2910RciRxBuf); // ʵ�ʶ��ĳ��ȣ��ӵ�һ���ֽ������ж�
	NCK2910_CSN_HIGH();

	// Step4 : ���CRC
	Gu8Nck2910RciRxLen = Gu8Nck2910RciRxBuf[0];

	if (Gu8Nck2910RciRxLen < 2)
	{
		return 0;
	}

	if (_CalculateCRC8(Gu8Nck2910RciRxBuf, Gu8Nck2910RciRxLen) != Gu8Nck2910RciRxBuf[Gu8Nck2910RciRxLen])
	{
		return 0;
	}

	// Step5 : ���communication error & command error
	// Gu8Nck2910RciRxBuf[1]ΪCMD�ֽ�
	// Gu8Nck2910RciRxBuf[5]Ϊstatus�ֽ�
	if (0xFF == Gu8Nck2910RciRxBuf[1])
	{
		return 0;
	}
	else if (Gu8Nck2910RciRxLen > 5)
	{
		if (Gu8Nck2910RciRxBuf[5] > 0)
		{
			return 0;
		}
	}

	return 1;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DC_SET
** Descriptions:		DC_SET����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DC_SET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DC_SET_CMD, DC_SET_SUB_CMD, pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DC_GET
** Descriptions:		DC_GET����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DC_GET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DC_GET_CMD, DC_GET_SUB_CMD, pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DC_COPY2RAM
** Descriptions:		DC_COPY2RAM����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DC_COPY2RAM(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DC_COPY2RAM_CMD, DC_COPY2RAM_SUB_CMD, pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DC_COPY2NV
** Descriptions:		DC_COPY2NV����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DC_COPY2NV(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DC_COPY2NV_CMD, DC_COPY2NV_SUB_CMD, pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DC_PATCHRAM
** Descriptions:		DC_PATCHRAM����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DC_PATCHRAM(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DC_PATCHRAM_CMD, DC_PATCHRAM_SUB_CMD, pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DC_HASH
** Descriptions:		DC_HASH����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DC_HASH(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DC_HASH_CMD, DC_HASH_SUB_CMD, pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DC_GET_STATUS
** Descriptions:		DC_GET_STATUS����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DC_GET_STATUS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DC_GET_STATUS_CMD, DC_GET_STATUS_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OS_SET_POLLING
** Descriptions:		OS_SET_POLLING����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OS_SET_POLLING(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OS_SET_POLLING_CMD, OS_SET_POLLING_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OS_GET_POLLING
** Descriptions:		OS_GET_POLLING����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OS_GET_POLLING(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OS_GET_POLLING_CMD, OS_GET_POLLING_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OS_STORE_POLLING
** Descriptions:		OS_STORE_POLLING����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OS_STORE_POLLING(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OS_STORE_POLLING_CMD, OS_STORE_POLLING_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OS_SET_MODE
** Descriptions:		OS_SET_MODE����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OS_SET_MODE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OS_SET_MODE_CMD, OS_SET_MODE_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OS_STATUS
** Descriptions:		OS_STATUS����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OS_STATUS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OS_STATUS_CMD, OS_STATUS_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_RB_READ_MSG
** Descriptions:		RB_READ_MSG����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_RB_READ_MSG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(RB_READ_MSG_CMD, RB_READ_MSG_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_RB_READ_BYTES
** Descriptions:		RB_READ_BYTES����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_RB_READ_BYTES(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(RB_READ_BYTES_CMD, RB_READ_BYTES_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_RB_FLUSH_MSG
** Descriptions:		RB_FLUSH_MSG����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_RB_FLUSH_MSG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(RB_FLUSH_MSG_CMD, RB_FLUSH_MSG_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_RB_STATUS
** Descriptions:		RB_STATUS����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_RB_STATUS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(RB_STATUS_CMD, RB_STATUS_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_PE_VERSIONS
** Descriptions:		PE_VERSIONS����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_PE_VERSIONS(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(PE_VERSIONS_CMD, PE_VERSIONS_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_PE_CAPABILITY
** Descriptions:		PE_CAPABILITY����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_PE_CAPABILITY(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(PE_CAPABILITY_CMD, PE_CAPABILITY_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DD_SET
** Descriptions:		DD_SET����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DD_SET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DD_SET_CMD, DD_SET_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DD_GET
** Descriptions:		DD_GET����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DD_GET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DD_GET_CMD, DD_GET_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DD_HASH
** Descriptions:		DD_HASH����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DD_HASH(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DD_HASH_CMD, DD_HASH_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DD_SIG
** Descriptions:		DD_SIG����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DD_SIG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DD_SIG_CMD, DD_SIG_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_DD_TIME
** Descriptions:		DD_TIME����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_DD_TIME(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(DD_TIME_CMD, DD_TIME_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_WI_CONFIG
** Descriptions:		WI_CONFIG����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_WI_CONFIG(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(WI_CONFIG_CMD, WI_CONFIG_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_WI_CLEAR
** Descriptions:		WI_CLEAR����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_WI_CLEAR(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(WI_CLEAR_CMD, WI_CLEAR_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_WI_STORE
** Descriptions:		WI_STORE����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_WI_STORE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(WI_STORE_CMD, WI_STORE_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_WI_ECHO
** Descriptions:		WI_ECHO����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_WI_ECHO(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(WI_ECHO_CMD, WI_ECHO_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_WI_ECHO_NXP
** Descriptions:		WI_ECHO_NXP����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_WI_ECHO_NXP(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(WI_ECHO_NXP_CMD, WI_ECHO_NXP_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OBM_CONF
** Descriptions:		OBM_CONF����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OBM_CONF(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OBM_CONF_CMD, OBM_CONF_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OBM_READ
** Descriptions:		OBM_READ����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OBM_READ(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OBM_READ_CMD, OBM_READ_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OBM_RSSI_OFMU
** Descriptions:		OBM_RSSI_OFMU����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OBM_RSSI_OFMU(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OBM_RSSI_OFMU_CMD, OBM_RSSI_OFMU_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OBM_SET_FREQUENCY_OFFSET_OVERRIDE
** Descriptions:		OBM_SET_FREQUENCY_OFFSET_OVERRIDE����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OBM_SET_FREQUENCY_OFFSET_OVERRIDE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OBM_SET_FREQUENCY_OFFSET_OVERRIDE_CMD,
								OBM_SET_FREQUENCY_OFFSET_OVERRIDE_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OBM_GET_FREQUENCY_OFFSET
** Descriptions:		OBM_GET_FREQUENCY_OFFSET����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OBM_GET_FREQUENCY_OFFSET(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OBM_GET_FREQUENCY_OFFSET_CMD, OBM_GET_FREQUENCY_OFFSET_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_OBM_DO_LO_CORRECTION
** Descriptions:		OBM_DO_LO_CORRECTION����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_OBM_DO_LO_CORRECTION(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(OBM_DO_LO_CORRECTION_CMD, OBM_DO_LO_CORRECTION_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_MISC_WAIT_US
** Descriptions:		MISC_WAIT_US����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_MISC_WAIT_US(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(MISC_WAIT_US_CMD, MISC_WAIT_US_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_MISC_PIN_TOGGLE
** Descriptions:		MISC_PIN_TOGGLE����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_MISC_PIN_TOGGLE(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(MISC_PIN_TOGGLE_CMD, MISC_PIN_TOGGLE_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_EV_TIMER_HEARTBEAT
** Descriptions:		EV_TIMER_HEARTBEAT����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_EV_TIMER_HEARTBEAT(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(EV_TIMER_HEARTBEAT_CMD, EV_TIMER_HEARTBEAT_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_TX_TRIGGER
** Descriptions:		TX_TRIGGER����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_TX_TRIGGER(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(TX_TRIGGER_CMD, TX_TRIGGER_SUB_CMD, pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_TX_WRITE_PAYLOAD
** Descriptions:		TX_WRITE_PAYLOAD����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_TX_WRITE_PAYLOAD(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(TX_WRITE_PAYLOAD_CMD, TX_WRITE_PAYLOAD_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		_RciCmd_TX_READ_PAYLOAD
** Descriptions:		TX_READ_PAYLOAD����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _RciCmd_TX_READ_PAYLOAD(uint8_t *pu8PayLoadBuf, uint8_t u8PayLoadLen)
{
	uint8_t i;

	for (i = 0; i < 3; i++)
	{
		if (_NCK2910_RciCmdSend(TX_READ_PAYLOAD_CMD, TX_READ_PAYLOAD_SUB_CMD,
								pu8PayLoadBuf, u8PayLoadLen))
		{
			return 1;
		}
	}

	return 0;
}

static uint8_t _NCK2910_Spi_Check(void)
{
	uint8_t u8TmpBuf[3] =
		{
			0};

	u8TmpBuf[0] = 0x00;

	if (_RciCmd_DD_GET(u8TmpBuf, 1) == 0)
	{
		// ���յ����ݣ�0x07,0x80,0x00,0x00,0x00,0x00,0x00,0xff
		return 0;
	}

	return 1;
}

/*********************************************************************************************************
** Function name:		_NCK2910_PFlashInit
** Descriptions:		��ʼ��NCK2910��PFlash
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
static uint8_t _NCK2910_PFlashInit(void)
{
	uint8_t u8TmpBuf[6] =
		{
			0};

	u8TmpBuf[0] = 0x01;
	u8TmpBuf[1] = 0xB2;
	u8TmpBuf[2] = 0x7E;

	if (_RciCmd_DD_GET(u8TmpBuf, 3))
	{
		if ((Gu8Nck2910RciRxBuf[6] & 0x4C) != 0x4C)
		{
			_Nck2910_delay_us(200);
			if (_RciCmd_DD_SET((uint8_t *)c_u8PflashCfg_Int_Ignored_Buf, PFLASH_CFG_BUF_LEN))
			{
				_Nck2910_delay_us(200);
				if (_RciCmd_DD_SET((uint8_t *)c_u8PflashCfg_Duraion_Buf, PFLASH_CFG_BUF_LEN + 1))
				{
					_Nck2910_delay_us(200);
					if (_RciCmd_DD_SET((uint8_t *)c_u8PflashCfgBuf, PFLASH_CFG_BUF_LEN))
					{
#if 0
                        _Nck2910_delay_us(200);
                        if(_RciCmd_DD_SET((uint8_t *) c_u8PflashCfgLockBuf, PFLASH_CFG_LOCK_LEN))
                        {
                            return 1;
                        }
                        else
                        {
                          return 0;
                        }
#else
						return 1;
#endif
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

/*********************************************************************************************************
** Function name:		NCK2910_Init
** Descriptions:		��ʼ��NCK2910
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
void Nck2910_Init(void)
{
	static uint8_t u8Nck2910InitStep = 0;
	static uint8_t u8Nck2910InitCount = 0;
	UHF_MessageTypeDef uhf_Pdu;

	if (0 == u8Nck2910InitStep)
	{
		NCK2910_RSTN_HIGH();

		NCK2910_RfRcvDataDeal();

		if ((Gu8Nck2910RciRxBuf[0] > 10) && (Gu8Nck2910RciRxBuf[0] <= 28))
		{
			if (_CalculateCRC8(Gu8Nck2910RciRxBuf, Gu8Nck2910RciRxBuf[0]) ==
				Gu8Nck2910RciRxBuf[Gu8Nck2910RciRxBuf[0]])
			{
				uhf_Pdu.m_DataLength = Gu8Nck2910RciRxBuf[0] - 9;
				memcpy(&uhf_Pdu.m_Data[0], &Gu8Nck2910RciRxBuf[9], uhf_Pdu.m_DataLength);

				if (Fifo_IsFull(&LPFifo) != True)
				{
					Fifo_Write(&LPFifo, uhf_Pdu);
					u32UhfRxNum++;
				}

				// zch debug
				/*memset(g_datCan1Tx_0x330,0,8);
				g_datCan1Tx_0x330[0] = 0xA1;
				g_datCan1Tx_0x330[1] = 0x01;
				BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);*/

				u8Nck2910InitStep = 0;
				nck2910ReadyFlag = 1;
				tnNck2910WorkStatus = NCK2910_NORMAL;
			}
		}
		else
		{
			u8Nck2910InitStep++;
		}
	}
	else if (1 == u8Nck2910InitStep) // 夝佝nck2910  ，至�?ms低电平维挝，高电平保�?0ms�?夝佝坯动时间)，开始初始化
	{
		if ((_RciCmd_OS_STATUS(NULL, 0) == 1) && (Gu8Nck2910RciRxBuf[0] == 0x0A))
		{
			if ((Gu8Nck2910RciRxBuf[6] == OM_CON_RCV) || (Gu8Nck2910RciRxBuf[6] == OM_POLLING))
			{
				u8Nck2910InitStep = 0;
				nck2910ReadyFlag = 1;
				tnNck2910WorkStatus = NCK2910_NORMAL;
			}
			else
			{
				u8Nck2910InitStep++;
				NCK2910_RSTN_LOW();
			}
		}
		else
		{
			u8Nck2910InitCount++;
			if (u8Nck2910InitCount >= 5)
			{
				u8Nck2910InitCount = 0;
				u8Nck2910InitStep++;
				NCK2910_RSTN_LOW();
			}
		}
	}
	else if (2 == u8Nck2910InitStep)
	{
		NCK2910_RSTN_HIGH();
		u8Nck2910InitStep++;
	}
	else if (3 == u8Nck2910InitStep)
	{
		_NCK2910_Spi_Check();
		u8Nck2910InitStep++;
	}
	else if (4 == u8Nck2910InitStep)
	{
		if (_NCK2910_PFlashInit() == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 80;
		}
	}
	else if (5 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8LoCfgBuf[0][0], LO_CFG_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 81;
		}
	}
	else if (6 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8LoCfgBuf[1][0], LO_CFG_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 82;
		}
	}
	else if (7 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8DigFreqBuf[0][0], DIG_FREQ_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 83;
		}
	}
	else if (8 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8DigFreqBuf[1][0], DIG_FREQ_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 84;
		}
	}
	else if (9 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8FilterBuf[0][0], FILTER_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 85;
		}
	}
	else if (10 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8FilterBuf[1][0], FILTER_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 86;
		}
	}
	else if (11 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8BaseBandBuf[0][0], BASEBAND_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 87;
		}
	}
	else if (12 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8BaseBandBuf[1][0], BASEBAND_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 88;
		}
	}
	else if (13 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8FrameWupBuf[0][0], FRAME_WUP_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 89;
		}
	}
	else if (14 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8FrameWupBuf[1][0], FRAME_WUP_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 90;
		}
	}
	else if (15 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8SwBuf[0][0], SW_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 91;
		}
	}
	else if (16 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8SwBuf[1][0], SW_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 92;
		}
	}
	else if (17 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8MidMapBuf[0][0], MID_MAP_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 93;
		}
	}
	else if (18 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8MidMapBuf[1][0], MID_MAP_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 94;
		}
	}
	else if (19 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8MidBuf[0][0], MID_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 95;
		}
	}
	else if (20 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8MidBuf[1][0], MID_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 96;
		}
	}
	else if (21 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8SlotCfgBuf[0][0], SLOT_CFG_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 97;
		}
	}
	else if (22 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8SlotCfgBuf[1][0], SLOT_CFG_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 98;
		}
	}
	else if (23 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8ReceptionCfgBuf[0][0], REC_CFG_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 99;
		}
	}
	else if (24 == u8Nck2910InitStep)
	{
		if (_RciCmd_DC_SET((uint8_t *)&c_u8ReceptionCfgBuf[1][0], REC_CFG_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 100;
		}
	}
	else if (25 == u8Nck2910InitStep)
	{
		if (_RciCmd_OS_SET_POLLING((uint8_t *)c_u8PollingCfgBuf, POLLING_CFG_BUF_LEN) == 1)
		{
			u8Nck2910InitStep++;
		}
		else
		{
			u8Nck2910InitStep = 101;
		}
	}
	else if (26 == u8Nck2910InitStep)
	{
		if (NCK2910_Polling() == 1) // OS_SET_MODE����pollingģʽ����ʼpolling
		{
			u8Nck2910InitCount = 0;
			nck2910ReadyFlag = 1;
			tnNck2910WorkStatus = NCK2910_NORMAL;
		}
		else
		{
			u8Nck2910InitStep = 102;
		}
	}
	else
	{
		// zch debug
		/*memset(g_datCan1Tx_0x330,0,8);
		g_datCan1Tx_0x330[0] = 0x80;
		g_datCan1Tx_0x330[1] = 0x00;
		g_datCan1Tx_0x330[2] = 0x03;
		g_datCan1Tx_0x330[3] = u8Nck2910InitStep;

		BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);*/

		u8Nck2910InitCount++;
		if (u8Nck2910InitCount >= 3)
		{
			u8Nck2910InitStep = 0;
			u8Nck2910InitCount = 0;
			tnNck2910WorkStatus = NCK2910_FAIL;
		}
		else
		{
			u8Nck2910InitStep = 1;
		}
	}
}

/*********************************************************************************************************
** Function name:		NCK2910_Reset
** Descriptions:		��λNCK2910
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_Reset(void)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_RESET;
	u8PayloadBuf[1] = 0x00;

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_Standby
** Descriptions:		NCK2910����Standbyģʽ��Standbyģʽ�£�CPU״̬��RAM��?
	??���ݱ��֣�polling timer
	��
**						watchdog��Ч
** input parameters:	u8StandbyTime : ͣ����Standby״̬�µ�ʱ��
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_Standby(uint8_t u8StandbyTime)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_STANDBY;
	u8PayloadBuf[1] = u8StandbyTime;

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_Idle
** Descriptions:		NCK2910����idleģʽ
** input parameters:	idleģʽ�£�RX�������رգ�RCI������?
	??����Ӧ
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_Idle(void)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_IDLE;
	u8PayloadBuf[1] = 0x00;

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_Sleep
** Descriptions:		NCK2910����Sleepģʽ��Sleepģʽ�£�CPU״̬��RAM��?
	?���ݱ��֣�polling timer��
**						watchdog��Ч��֧�ַ�ƵXO Clock���?
** input parameters:	u8SleepTime : ͣ����sleepģʽ�µ�ʱ��
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_Sleep(uint8_t u8SleepTime)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_SLEEP;
	u8PayloadBuf[1] = u8SleepTime;

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_ConRx
** Descriptions:		NCK2910������������ģʽ
** input parameters:	u8RxCfgIndex : �����������ڼ䣬���õ��?
	??���ĸ�RF RX���������գ������õ�?
	?����
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_ConRx(uint8_t u8RxCfgIndex)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_CON_RCV;
	u8PayloadBuf[1] = u8RxCfgIndex;

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_Polling
** Descriptions:		NCK2910����Pollingģʽ
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_Polling(void)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_POLLING;
	u8PayloadBuf[1] = 0x00;

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_PowerOff
** Descriptions:		NCK2910����PowerOffģʽ��PowerOffģʽ�£�polling timer��
	watchdog��Ч
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_PowerOff(void)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_TRANSPORT;
	u8PayloadBuf[1] = 0x01; // �ò���Ϊ1������poweroffģʽ���ò���Ϊ0������transportģʽ

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_Transport
** Descriptions:		NCK2910����Transportģʽ��Transportģʽ�£���ģʽ��
	��͹��ģ���ҪRST_N��?
	??��
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
uint8_t NCK2910_Transport(void)
{
	uint8_t u8PayloadBuf[2];

	u8PayloadBuf[0] = OM_TRANSPORT;
	u8PayloadBuf[1] = 0x00; // �ò���Ϊ1������poweroffģʽ���ò���Ϊ0������transportģʽ

	if (_RciCmd_OS_SET_MODE(u8PayloadBuf, 0x02))
	{
		return 1;
	}

	return 0;
}

/*********************************************************************************************************
** Function name:		NCK2910_ErrorHandle
** Descriptions:		NCK2910���ϴ���
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
void NCK2910_ErrorHandle(void)
{
}

/*********************************************************************************************************
** Function name:		NCK2910_Enter_LowPower
** Descriptions:		NCK2910����polling
**						watchdog��Ч��֧�ַ�ƵXO Clock���?
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
void NCK2910_Enter_LowPower(void)
{
	// step1 : OS_SET_POLLING����polling����
	_RciCmd_OS_SET_POLLING((uint8_t *)c_u8PollingCfgBuf, POLLING_CFG_BUF_LEN);

	// step2 : OS_SET_MODE����pollingģʽ����ʼpolling
	NCK2910_Polling();
}

/*********************************************************************************************************
** Function name:		NCK2910_Enter_Normal
** Descriptions:		NCK2910������������
**						watchdog��Ч��֧�ַ�ƵXO Clock���?
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
void NCK2910_Enter_Normal(void)
{
	NCK2910_ConRx(0);
}

/*********************************************************************************************************
** Function name:		NCK2910_RfRcvDataDeal
** Descriptions:		����NCK2910���յ���RF����
** input parameters:
** output parameters:
** Returned value:
*********************************************************************************************************/
void NCK2910_RfRcvDataDeal(void)
{
	NCK2910_CSN_HIGH();
	DelayCsT1(); // ��ʱ��Ϊ��ȷ��CS�ɿ���Ч
	NCK2910_CSN_LOW();
	DelayCsT2(); // CsT1 + CsT2Ҫ����Trdy2rcv������RCI V1.1ʱ��淶��Ҳ����ͨ�����RDY_N�ܽŷ�ʽ

	NCK2910_SpiRead(Gu8Nck2910RciRxBuf);

	NCK2910_CSN_HIGH();
}

void Nck2910_DataProcess(void)
{
	UHF_MessageTypeDef uhf_Pdu;
	static uint8 u8Wait200mSCycle = 0;
	LONG_UNION Rand_Val;

	if (GetNck2910InitCompleteStatus() == 1)
	{
		if (Is_NCK2910_INT_Active())
		{
			u8Wait200mSCycle++;

			if (u8Wait200mSCycle >= 25)
			{
				u8Wait200mSCycle = 0;
				tnNck2910WorkStatus = NCK2910_INIT;
				nck2910ReadyFlag = 0;
				return;
			}

			NCK2910_RfRcvDataDeal();

			if ((Gu8Nck2910RciRxBuf[0] > 10) && (Gu8Nck2910RciRxBuf[0] <= 28))
			{
				if (_CalculateCRC8(Gu8Nck2910RciRxBuf, Gu8Nck2910RciRxBuf[0]) ==
					Gu8Nck2910RciRxBuf[Gu8Nck2910RciRxBuf[0]])
				{
					uhf_Pdu.m_DataLength = Gu8Nck2910RciRxBuf[0] - 9;
					memcpy(&uhf_Pdu.m_Data[0], &Gu8Nck2910RciRxBuf[9], uhf_Pdu.m_DataLength);

					if (Fifo_IsFull(&LPFifo) != True)
					{
						Fifo_Write(&LPFifo, uhf_Pdu);
						u32UhfRxNum++;
						Rand_Val.Value = u32UhfRxNum;
						// zch debug
						/*memset(g_datCan1Tx_0x330,0,8);
						g_datCan1Tx_0x330[7] = Rand_Val.CHAR_BYTE.Low_byte;
						g_datCan1Tx_0x330[6] = Rand_Val.CHAR_BYTE.Mlow_byte;
						g_datCan1Tx_0x330[5] = Rand_Val.CHAR_BYTE.Mhigh_byte;
						g_datCan1Tx_0x330[4] = Rand_Val.CHAR_BYTE.High_byte;

						BCM_IMMOAuthResp1_EPT_Send_Notication(g_datCan1Tx_0x330);*/
					}
				}
			}
			else
			{
				if ((Gu8Nck2910RciRxBuf[0] == 0x07) && (Gu8Nck2910RciRxBuf[1] == 0x80) && (Gu8Nck2910RciRxBuf[6] > 0))
				{
					tnNck2910WorkStatus = NCK2910_INIT;
				}
			}
		}
		else
		{
			u8Wait200mSCycle = 0;
		}

		bNck2910InterruptFlag = false;
	}
	else
	{
		bNck2910InterruptFlag = false;
		u8Wait200mSCycle = 0;
	}
}

ISR(ISR_GPIO_AP_SYNC_DGPIO)
{
	Dio_Ip_IrqHandler(6);

	if (nck2910ReadyFlag == 1)
	{
		bNck2910InterruptFlag = true;
	}
}

/*********************************************************************************************************
  EoF
*********************************************************************************************************/
