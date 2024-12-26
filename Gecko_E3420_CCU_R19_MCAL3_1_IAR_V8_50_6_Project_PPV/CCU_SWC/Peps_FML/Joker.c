/*********************************************************************************************************
  Includes
*********************************************************************************************************/
#include "joker.h"

uint8_t g_peps_ide[4] = {0x2e, 0x3c, 0xbc, 0x2b}; /**< \brief o?ï¿½ï¿½ï¿½ï¿½IDE */

static uint8_t u8CmdBuff[255]; /**< \brief SPIï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?*/
static uint8_t u8ResBuff[255];  /**< \brief SPIï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ */

uint8_t Joker_Init_Status = 0xff;

uint8_t Joker_Init_Fail_Num = 0;

extern uint8 u8JokerInitInCarAntDrvCur;
extern uint8 u8JokerInitLfAntDrvCur;
extern uint8 u8JokerInitRfAntDrvCur;

/*********************************************************************************************************
  Local function prototypes
*********************************************************************************************************/
static void _JOKER_SpiInit(void);
static void _JOKER_GpioInit(void);

uint8_t _JOKER_Crc8Algorithm(uint8_t *pu8Data, uint8_t u8BytesLen);
static void _JOKER_SpiWrite(uint8_t *pu8DataBuff, uint8_t u8BytesLen);
void _JOKER_SpiRead(uint8_t *pu8DataBuff);
static uint8_t _JOKER_CmdTransmit(uint8_t u8CMD, uint8_t *pu8Param, uint8_t *pu8ResBuff, uint8_t u8ParamLen, uint32_t u32DelayUs);

void delay_us(uint32_t u32DelayUs)
{
    Njj29c0_Delay(u32DelayUs);
}

void delay_ms(uint32_t u32DelayMs)
{
    while (u32DelayMs > 0)
    {
        delay_us(1000);
        u32DelayMs--;
    }
}

void NJJ29C0_COM_RequestBus(void)
{
    NJJ29C0_CSN_LOW();
    delay_us(5);
}

void NJJ29C0_COM_ReleaseBus(void)
{
    delay_us(5);
    NJJ29C0_CSN_HIGH();
}

/*********************************************************************************************************
** @brief	_NJJ_SpiInit
** @note	Initializes the SPI peripheral for 29C0
** @param	none
** @retval	none
*********************************************************************************************************/
static void _JOKER_SpiInit(void)
{
}

/*********************************************************************************************************
** @brief	_NJJ_GpioInit
** @note	Initializes the gpio peripheral for 29C0
** @param	none
** @retval	none
*********************************************************************************************************/
static void _JOKER_GpioInit(void)
{
}

/*********************************************************************************************************
** @brief	_NJJ_Crc8Algorithm
** @note	Calculate the CRC8
** @param	pu8Data		: Point to the buffer to calculate
** @param	u8BytesLen	: Length of the buffer
** @retval	uint8_t CRC8
*********************************************************************************************************/
uint8_t _JOKER_Crc8Algorithm(uint8_t *pu8Data, uint8_t u8BytesLen)
{
    uint8_t i, j;

    uint16_t u16CRC = 0;
    uint8_t u8Temp = 0;

    for (i = 0; i < u8BytesLen; i++)
    {
        u8Temp = *pu8Data;
        for (j = 0; j < 8; j++)
        {
            u16CRC = u16CRC * 2;
            if ((u16CRC >= 0x100) ^ (u8Temp & 0x01))
            {
                u16CRC = u16CRC ^ 0x07;
            }
            u16CRC = u16CRC & 0xFF;
            u8Temp >>= 0x01;
        }
        pu8Data++;
    }
    return ((uint8_t)u16CRC);
}

/*********************************************************************************************************
** @brief	_NJJ_SpiWrite
** @note
** @param	pu8DataBuff	: Point to the buffer to send
** @param	u8BytesLen	: Length of the buffer
** @retval	none
*********************************************************************************************************/
static void _JOKER_SpiWrite(uint8_t *pu8DataBuff, uint8_t u8BytesLen)
{
    uint8_t u8rxbuf[255] =
        {
            0};
    (void)NJJ29C0_Spi_ReadWrite(pu8DataBuff, u8rxbuf, u8BytesLen);
}

/*********************************************************************************************************
** @brief	_NJJ_SpiRead
** @note	todo:ï¿½ï¿½ï¿½Õ³ï¿½ï¿½ï¿½ï¿½ï¿½Ð§Öµï¿½Ð¶ï¿½
** @param	pu8DataBuff	: Point to the buffer to Receive
** @retval	none
*********************************************************************************************************/
void _JOKER_SpiRead(uint8_t *pu8DataBuff)
{
    uint8_t u8txbuf[255] =
        {
            0};

    (void)
        NJJ29C0_Spi_ReadWrite(u8txbuf, pu8DataBuff, 1);

    if ((pu8DataBuff[0] < 255) && (pu8DataBuff[0] >= 2))
    {
        NJJ29C0_Spi_ReadWrite(u8txbuf, &pu8DataBuff[1], pu8DataBuff[0]);
    }
}

uint8 Njj29c0_Spi_Transfer(uint8 *sendFrame, uint8 datalen)
{
    uint8 Status;
    uint8 tmpreg[32] =
        {
            0};

    if ((datalen < 32) && (datalen > 0))
    {
        NJJ29C0_COM_RequestBus();
        Status = NJJ29C0_Spi_ReadWrite(sendFrame, tmpreg, datalen);
        NJJ29C0_COM_ReleaseBus();

        if (Status == TRUE)
        {
            return kStatus_Success;
        }
    }

    return kStatus_Fail;
}

uint8 NJJ29C0_COM_ReadWriteFrame(uint8 *sendFrame, uint8 *recvFrame, uint8 sendFrameSize, uint16 waitdelay)
{
    uint8 status = 0;
    uint8 recvLen = 0U; /* Length of the received RCI frame. */
    uint8 tmpreg[16] =
        {
            0};

    NJJ29C0_COM_RequestBus();
    status = NJJ29C0_Spi_ReadWrite(sendFrame, recvFrame, sendFrameSize);
    NJJ29C0_COM_ReleaseBus();

    delay_us(waitdelay);

    NJJ29C0_COM_RequestBus();

    if (1 == status)
    {
        status = NJJ29C0_Spi_ReadWrite(&tmpreg[0], recvFrame, 1);

        if (1 == status)
        { /* Update the SPI data structure to receive the rest of the response frame. */
            recvLen = recvFrame[0];

            if ((0x00U == recvLen) || (recvLen > 16))
            {
                status = 0;
            }
            else
            {
                status = NJJ29C0_Spi_ReadWrite(&tmpreg[0], &recvFrame[1], recvLen);

                if (1 == status)
                {
                    // crc
                    if (_JOKER_Crc8Algorithm(recvFrame, recvLen) == recvFrame[recvLen])
                    {
                        status = 1;
                    }
                    else
                    {
                        status = 0;
                    }
                }
            }
        }

        /* SPI bus must be released even if an error occurred. */
        NJJ29C0_COM_ReleaseBus();
    }

    return status;
}

/*********************************************************************************************************
** @brief	_NJJ_CmdTransmit
** @note	Í¨ï¿½ï¿½SPIï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½NJJ29C0
** @param	u8CMD		: CMD ID
** @param	pu8Param	: CMD param
** @param	pu8ResBuff	: Respond buff
** @param	u8ParamLen	: param bytes len
** @param	u32DelayUs	: Delay between CMD & Respond @spec
** @retval	u8Res    : SPIï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½É¹ï¿½ï¿½ï¿?:ï¿½É¹ï¿½ï¿½ï¿½1:Ê§ï¿½ï¿½
*********************************************************************************************************/
static uint8_t _JOKER_CmdTransmit(uint8_t u8CMD, uint8_t *pu8Param, uint8_t *pu8ResBuff, uint8_t u8ParamLen, uint32_t u32DelayUs)
{
    uint8_t u8CmdBuffer[255];
    uint8_t u8ResBuffer[255];

    uint8_t u8Err = 1;

    uint8_t i = 0x00;

    /* ï¿½ï¿½ä·¢ï¿½Í»ï¿½ï¿½ï¿½ï¿½ï¿?*/
    u8CmdBuffer[0] = u8ParamLen;
    u8CmdBuffer[1] = u8CMD;

    for (i = 0; i < u8ParamLen - 2; i++)
    {
        u8CmdBuffer[2 + i] = pu8Param[i];
    }

    /* ï¿½ï¿½ï¿½ï¿½CRCï¿½Ö½ï¿½ */
    u8CmdBuffer[u8ParamLen] = _JOKER_Crc8Algorithm(u8CmdBuffer, u8ParamLen);

    /* Ê¹ï¿½ï¿½ JOKER */
    JOKER_CSN_0();

    /* Í¨ï¿½ï¿½SPIï¿½ï¿½ï¿½ï¿½JOKERï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ */
    _JOKER_SpiWrite(u8CmdBuffer, u8ParamLen + 1);

    /* ï¿½È´ï¿½ JOKER Ö´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ */
    delay_us(u32DelayUs);

    /* ï¿½È´ï¿½ JOKERï¿½ï¿½ï¿½ï¿½Ö´ï¿½Ðºï¿½ï¿½ï¿½ï¿½ï¿½?*/
    _JOKER_SpiRead(u8ResBuffer);

    /* Ê§ï¿½ï¿½ JOKER */
    JOKER_CSN_1();

    /* ï¿½Ð¶ï¿½ï¿½ï¿½ï¿½ï¿½Ö´ï¿½Ðµï¿½ï¿½ï¿½Ó¦ï¿½Ç·ï¿½ï¿½ï¿½È· */
    //if (u8ResBuffer[0] != 0x00)
	if ((u8ResBuffer[0] > 0) && (u8ResBuffer[0] < 64))
    {
        if (u8ResBuffer[u8ResBuffer[0]] == _JOKER_Crc8Algorithm(u8ResBuffer, u8ResBuffer[0]))
        {
            u8Err = 0;
            for (i = 0; i < u8ResBuffer[0] + 1; i++)
            {
                pu8ResBuff[i] = u8ResBuffer[i];
            }
        }
        else
        {
            u8Err = 1;
        }
    }
    else
    {
        u8Err = 1;
    }
    return u8Err;
}


/*--------------------------------------------------------------------------------------------------------
    General Commands
 *------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_GetVersion
** @note	SPI_CMD:GET_VERSION
** @param	psVersion	: Point to the buffer
** @retval	stat_t
*********************************************************************************************************/
stat_t JOKER_GetVersion(njj29c0_version_t *psVersion)
{
    uint8_t i;

    i = 0;
    while (_JOKER_CmdTransmit(GET_VERSION_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    (*psVersion).PI = (u8ResBuff[4] << 8) | u8ResBuff[3];
    (*psVersion).HW = (u8ResBuff[6] << 8) | u8ResBuff[5];
    (*psVersion).RM = (u8ResBuff[8] << 8) | u8ResBuff[7];
    (*psVersion).RAM = (u8ResBuff[10] << 8) | u8ResBuff[9];

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ConfigDevice
** @note	SPI_CMD:CONFIG_DEVICE
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigDevice(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = 0x00; // DEVPAR
    // [7:2]  | 1      | 0
    // RFU    | PREAMB | VIO
    // 000000 | 1      | 0
    // --> PREAMB = enable, VIO = 3.3V

    while (_JOKER_CmdTransmit(CONFIG_DEVICE_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ConfigAdvanced
** @note	SPI_CMD:CONFIG_DEVICE
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigAdvanced(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = 0x04;
    u8CmdBuff[1] = 0x05; /**< \brief DRVMINTON      : LF driver minimum on-time */
    u8CmdBuff[2] = 0x12;
    u8CmdBuff[3] = 0x02; /**< \brief CHIRPBLANK     : Number of chirp blanking samples */
    u8CmdBuff[4] = 0x02; /**< \brief CHIRPSTEPINC   : Number of frequency step increments */
    u8CmdBuff[5] = 0x01; /**< \brief CHIRPSTEPAFTPK : Number of frequency steps after the peak */
    u8CmdBuff[6] = 0x05; /**< \brief CHIRPSTEPBCK   : Number of frequency steps jumped back */
    u8CmdBuff[7] = 0x08; /**< \brief CHIRPCYCLE     : Number of cycles per frequency */

    while (_JOKER_CmdTransmit(CONFIG_ADVANCED_CMD, &u8CmdBuff[2], u8ResBuff, 0x08, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Device reset
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_SetPor
** @note	Triggers a power on reset
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetPor(void)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(SET_POR_CMD, u8CmdBuff, u8ResBuff, 0x02, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_GetPorStatus
** @note	SPI_CMD:GET_POR_STATUS
** @param	u8PorF: signalizes the cause for the last power on reset event @PORFC
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetPorStatus(uint8_t *u8PorF)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_POR_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    *u8PorF = u8ResBuff[3];

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ClearPorStatus
** @note	SPI_CMD:CLEAR_POR_STATUS
** @param	u8ProC: specifies the device reset status flags to be cleared. @PORFC
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearPorStatus(uint8_t u8ProC)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = u8ProC & 0x7F; /**< \brief ï¿½ï¿½Ö¾Î»È«ï¿½ï¿½ï¿½ï¿½ï¿?*/

    while (_JOKER_CmdTransmit(CLEAR_POR_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Operating States
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_StartSleep
** @note	SPI_CMD:START_SLEEP_CMD
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartSleep(void)
{
    uint8_t i;

    i = 0x00;

    while (_JOKER_CmdTransmit(START_SLEEP_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StartSleepForced
** @note	SPI_CMD:START_SLEEP_FORCED_CMD
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartSleepForced(void)
{
    uint8_t i;

    i = 0x00;

    while (_JOKER_CmdTransmit(START_SLEEP_FORCED_CMD, u8CmdBuff, u8ResBuff, 0x02, 900) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_WakeUp
** @note
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
void JOKER_WakeUp(void)
{
#if 1
    uint8_t u8CmdBuff[1] = {0}; /**< \brief SPIï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?*/
    _JOKER_SpiWrite(u8CmdBuff, 0);
    delay_ms(1);

	JOKER_StartSleepForced();
#else
  JOKER_CSN_0();
  Njj29c0_Delay(200);
  JOKER_CSN_1();
    
  //JOKER_StopLfTransmit();
#endif
}

/*--------------------------------------------------------------------------------------------------------
    Boost Convert
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigBoost
** @note	SPI_CMD:CONFIG_BOOST
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigBoost(void)
{
    uint8_t i;

    // [7:4]    | [3:0]
    // CUR_INIT | CUR_MAX
    // 0000     | 1111
    // --> CUR_INIT = 5A, CUR_MAX = 16A
    u8CmdBuff[0] = 0xff; // 0x0F;		// CURMAX

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_BOOST_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

#if 1
/*--------------------------------------------------------------------------------------------------------
	LF Antenna Driver
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigLfDriver
** @note	SPI_CMD:CONFIG_LF_DRIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
//stat_t JOKER_ConfigLfDriver(void)
stat_t JOKER_ConfigLfDriver(uint8_t ch2_CURSi, uint8_t ch3_CURSi, uint8_t ch4_CURSi)

{
    uint8_t u8CmdBuff[36];	 /**< \brief SPIÃüÁî²ÎÊý»º³åÇø */
    uint8_t u8ResBuff[5];   /**< \brief SPIÏìÓ¦²ÎÊý»º³åÇø */
    uint8_t i;

    i = 0x00;
    // DRPARi
    // [7:6] | 5        | 4       | [3:2]         | 1   | 0
    // RFU   | PHINV    | OPNLOOP | BDRATE        | RFU | MOD
    // 00    | 0 =   0¡ã | 0 = DIS | 00 = 2 kbit/s | 0   | 0 = with mid level
    //       | 1 = 180¡ã | 1 = EN  | 01 = 4 kbit/s |     | 1 = without mid level
    //       |          |         | 10 = 8 kbit/s |     |

    // DITHRi
    // [7:2]  | [1:0]
    // RFU    | DITHR
    // 000000 | 00 = Dithering off
    //        | 01 = Minimum range
    //        | 10 = Medium range
    //        | 10 = Maximum range

    u8CmdBuff[0]  = DRID1;		/**< \brief DRIDi  : LF·¢ÉäÍ¨µÀ1 */
    u8CmdBuff[1]  = 0x04;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[2]  = 0x0f;		/**< \brief CURSi  : µ¥Í¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[3]  = 0x0f;		/**< \brief CURMi  : ¶àÍ¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[4]  = 0x40;		/**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[5]  = 0x00;		/**< \brief DITHRi : ¶¶¶¯·¶Î§ */

    u8CmdBuff[6]  = DRID2;		/**< \brief DRIDi  : LF·¢ÉäÍ¨µÀ2 */
    u8CmdBuff[7]  = 0x04;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[8]  = ch2_CURSi;		/**< \brief CURSi  : µ¥Í¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[9]  = ch2_CURSi;		/**< \brief CURMi  : ¶àÍ¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[10] = 0x40;		/**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[11] = 0x00;		/**< \brief DITHRi : ¶¶¶¯·¶Î§ */

    u8CmdBuff[12] = DRID3;		/**< \brief DRIDi  : LF·¢ÉäÍ¨µÀ3 */
    u8CmdBuff[13] = 0x04;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[14] = ch3_CURSi;		/**< \brief CURSi  : µ¥Í¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[15] = ch3_CURSi;		/**< \brief CURMi  : ¶àÍ¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[16] = 0x40;		/**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[17] = 0x00;		/**< \brief DITHRi : ¶¶¶¯·¶Î§ */

    u8CmdBuff[18] = DRID4;		/**< \brief DRIDi  : LF·¢ÉäÍ¨µÀ4 */
    u8CmdBuff[19] = 0x04;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[20] = ch4_CURSi;		/**< \brief CURSi  : µ¥Í¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[21] = ch4_CURSi;		/**< \brief CURMi  : ¶àÍ¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[22] = 0x40;		/**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[23] = 0x00;		/**< \brief DITHRi : ¶¶¶¯·¶Î§ */

    u8CmdBuff[24] = DRID5;		/**< \brief DRIDi  : LF·¢ÉäÍ¨µÀ5 */
    u8CmdBuff[25] = 0x04;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[26] = 0x0f;		/**< \brief CURSi  : µ¥Í¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[27] = 0x0f;		/**< \brief CURMi  : ¶àÍ¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[28] = 0x40;		/**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[29] = 0x00;		/**< \brief DITHRi : ¶¶¶¯·¶Î§ */

    u8CmdBuff[30] = DRID6;		/**< \brief DRIDi  : LF·¢ÉäÍ¨µÀ6 */
    u8CmdBuff[31] = 0x04;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[32] = 0x0f;		/**< \brief CURSi  : µ¥Í¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[33] = 0x0f;		/**< \brief CURMi  : ¶àÍ¨µÀLFÇý¶¯µçÁ÷Öµ */
    u8CmdBuff[34] = 0x40;		/**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[35] = 0x00;		/**< \brief DITHRi : ¶¶¶¯·¶Î§ */

	while(_JOKER_CmdTransmit(CONFIG_LF_DRIVER_CMD, u8CmdBuff, u8ResBuff, 38, 2000) != 0)
    {
        i++;
        if (i == 3) return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

#else
/*--------------------------------------------------------------------------------------------------------
    LF Antenna Driver
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigLfDriver
** @note	SPI_CMD:CONFIG_LF_DRIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigLfDriver(uint8_t ch2_CURSi, uint8_t ch3_CURSi, uint8_t ch4_CURSi)
{
    uint8_t i = 0;
	
    // DRPARi
    // [7:6] | 5        | 4       | [3:2]         | 1   | 0
    // RFU   | PHINV    | OPNLOOP | BDRATE        | RFU | MOD
    // 00    | 0 =   0ï¿½ï¿½ | 0 = DIS | 00 = 2 kbit/s | 0   | 0 = with mid level
    //       | 1 = 180ï¿½ï¿½ | 1 = EN  | 01 = 4 kbit/s |     | 1 = without mid level
    //       |          |         | 10 = 8 kbit/s |     |

    // DITHRi
    // [7:2]  | [1:0]
    // RFU    | DITHR
    // 000000 | 00 = Dithering off
    //        | 01 = Minimum range
    //        | 10 = Medium range
    //        | 10 = Maximum range

    u8CmdBuff[0] = DRID2;     /**< \brief DRIDi  : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½1 */
    u8CmdBuff[1]  = 0x08;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[2] = ch2_CURSi; /**< \brief CURSi  : ï¿½ï¿½Í¨ï¿½ï¿½LFï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµ */
    u8CmdBuff[3] = ch2_CURSi; /**< \brief CURMi  : ï¿½ï¿½Í¨ï¿½ï¿½LFï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµ */
    u8CmdBuff[4] = 0x40;      /**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[5] = 0x00;      /**< \brief DITHRi : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î§ */

    u8CmdBuff[6] = DRID3;     /**< \brief DRIDi  : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½2 */
    u8CmdBuff[7]  = 0x08;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[8] = ch3_CURSi; /**< \brief CURSi  : ï¿½ï¿½Í¨ï¿½ï¿½LFï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµ */
    u8CmdBuff[9] = ch3_CURSi; /**< \brief CURMi  : ï¿½ï¿½Í¨ï¿½ï¿½LFï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµ */
    u8CmdBuff[10] = 0x40;     /**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[11] = 0x00;     /**< \brief DITHRi : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î§ */

    u8CmdBuff[12] = DRID4;     /**< \brief DRIDi  : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½3 */
    u8CmdBuff[13] = 0x08;		/**< \brief DRPARi : LFÍ¨ÐÅ²¨ÌØÂÊ4kbit/s */
    u8CmdBuff[14] = ch4_CURSi; /**< \brief CURSi  : ï¿½ï¿½Í¨ï¿½ï¿½LFï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµ */
    u8CmdBuff[15] = ch4_CURSi; /**< \brief CURMi  : ï¿½ï¿½Í¨ï¿½ï¿½LFï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµ */
    u8CmdBuff[16] = 0x40;      /**< \brief FREQi  : ÆµÆ« */
    u8CmdBuff[17] = 0x00;      /**< \brief DITHRi : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î§ */

    while (_JOKER_CmdTransmit(CONFIG_LF_DRIVER_CMD, u8CmdBuff, u8ResBuff, 20, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}
#endif



/*--------------------------------------------------------------------------------------------------------
    Parallel Low Current Driver
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigLcDriver
** @note	SPI_CMD:CONFIG_LC_DRIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigLcDriver(void)
{
    uint8_t i;

    i = 0x00;
    // LCCURi
    // [7:5] | [4:0]
    // RFU   | LCDCY
    // 000   | 10 %+ LCDCY * 2.5%

    u8CmdBuff[0] = DRID1; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½1 */
    u8CmdBuff[1] = 0x0F;  /**< \brief LCDCY : Duty Cycle is 47.5% */

    u8CmdBuff[2] = DRID2; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½2 */
    u8CmdBuff[3] = 0x0F;  /**< \brief LCDCY : Duty Cycle is 47.5% */

    u8CmdBuff[4] = DRID3; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½3 */
    u8CmdBuff[5] = 0x0F;  /**< \brief LCDCY : Duty Cycle is 47.5% */

    u8CmdBuff[6] = DRID4; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½4 */
    u8CmdBuff[7] = 0x0F;  /**< \brief LCDCY : Duty Cycle is 47.5% */

    u8CmdBuff[8] = DRID5; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½5 */
    u8CmdBuff[9] = 0x0F;  /**< \brief LCDCY : Duty Cycle is 47.5% */

    u8CmdBuff[10] = DRID6; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½6 */
    u8CmdBuff[11] = 0x0F;  /**< \brief LCDCY : Duty Cycle is 47.5% */

    while (_JOKER_CmdTransmit(CONFIG_LC_DRIVER_CMD, u8CmdBuff, u8ResBuff, 0x0E, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Telegram Sequencer
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_SetLfData
** @note	SPI_CMD:SET_LF_DATA
** @param	u8DataIndex : Data Identifiers [0..59]
** @param	u8BytesLen  : Number of bytes to be sent
** @param	pu8DataBuff : Point to Data Buff
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetLfData(uint8_t u8DataIndex, uint8_t u8BytesLen, uint8_t *pu8DataBuff)
{
    uint8_t i;

    u8BytesLen &= 0x0F;

    u8CmdBuff[0] = u8DataIndex;     /**< \brief DATAID  : ï¿½ï¿½ï¿½Ý¶Î±ï¿½Ê¶ */
    u8CmdBuff[1] = 0x00;            /**< \brief DATACFG : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ï¿½Ã£ï¿½manchester */
    u8CmdBuff[2] = u8BytesLen << 3; /**< \brief DATALEN : ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½ */

    for (i = 0; i < u8BytesLen; i++)
    {
        u8CmdBuff[3 + i] = pu8DataBuff[i]; /**< \brief DATA : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */
    }

    i = 0x00;
    while (_JOKER_CmdTransmit(SET_LF_DATA_CMD, u8CmdBuff, u8ResBuff, 0x05 + u8BytesLen, 100) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

stat_t JOKER_SetLfNrz(uint8_t u8DataIndex, uint8_t u8BytesLen, uint8_t *pu8DataBuff)
{
    uint8_t i;

    u8BytesLen &= 0x0F;

    u8CmdBuff[0] = u8DataIndex; /**< \brief DATAID  : ï¿½ï¿½ï¿½Ý¶Î±ï¿½Ê¶ */
    u8CmdBuff[1] = 0x02;        /**< \brief DATACFG : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ï¿½Ã£ï¿½manchester */
    u8CmdBuff[2] = 18;          /**< \brief DATALEN : ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½ */

    for (i = 0; i < u8BytesLen; i++)
    {
        u8CmdBuff[3 + i] = pu8DataBuff[i]; /**< \brief DATA : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */
    }

    i = 0x00;
    while (_JOKER_CmdTransmit(SET_LF_DATA_CMD, u8CmdBuff, u8ResBuff, 0x05 + u8BytesLen, 100) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetLfCarrier
** @note	SPI_CMD:SET_LF_DATA
** @param	u8Index  : Data Identifiers [0..59]
** @param	sCarrier :
** @param	u8Time   :
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetLfCarrier(uint8_t u8Index, carrier_t sCarrier, uint8_t u8Time)
{
    uint8_t i;

    u8CmdBuff[0] = u8Index;  /**< \brief DATAID  : ï¿½ï¿½ï¿½Ý¶Î±ï¿½Ê¶ */
    u8CmdBuff[1] = sCarrier; /**< \brief DATACFG : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ï¿½ï¿½ */
    u8CmdBuff[2] = u8Time;   /**< \brief DATALEN : ï¿½ï¿½ï¿½Ý³ï¿½ï¿½ï¿½ */

    i = 0x00;
    while (_JOKER_CmdTransmit(SET_LF_DATA_CMD, u8CmdBuff, u8ResBuff, 0x05, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StartLfTransmit
** @note	SPI_CMD:START_LF_TRANSMIT
** @param	sLfDRPi @DRPI
** @param	sLcDRPi @DRPI
** @param	u8BuffLen
** @param	pu8IndexBuff
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartLfTransmit(drpi_t sLfDRPi, drpi_t sLcDRPi, uint8_t u8BuffLen, uint8_t *pu8IndexBuff)
{
    uint8_t i;

    u8CmdBuff[0] = sLfDRPi;   /**< \brief DRPi       : LF Driver */
    u8CmdBuff[1] = 0x00;      /**< \brief RFU        : */
    u8CmdBuff[2] = sLcDRPi;   /**< \brief LCDRPi     : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
    u8CmdBuff[3] = 0x00;      /**< \brief RFU        : */
    u8CmdBuff[4] = u8BuffLen; /**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */

    for (i = 0; i < u8BuffLen; i++)
    {
        u8CmdBuff[5 + i] = pu8IndexBuff[i]; /**< \brief DATAIDik   : */
    }

    i = 0x00;
    while (_JOKER_CmdTransmit(START_LF_TRANSMIT_CMD, u8CmdBuff, u8ResBuff, 0x07 + u8BuffLen, 600) != 0)
    {
        i++;
        if (i == 1)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StopLfTransmit
** @note	SPI_CMD:STOP_LF_TRAMSMIT
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StopLfTransmit(void)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(STOP_LF_TRAMSMIT_CMD, u8CmdBuff, u8ResBuff, 0x02, 900) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Immobilizer
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigImmoDriver
** @note	SPI_CMD:CONFIG_IMMO_DRIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigImmoDriver(void)
{
    uint8_t i;

    // TXPAR
    // 7   | 6       | [5:0]
    // RFU | OPNLOOP | TXCUR
    // 0   | 0 = DIS | (n+1) * 15.625 mA
    //     | 1 = EN  |

    // RXPAR
    // [7:6] | [5:0]
    // RFU   | RXCUR
    // 00    | (n+1) * 15.625 mA

    u8CmdBuff[0] = 0x40 | 0x1f; /**< \brief TXPAR  187ma */
    u8CmdBuff[1] = 0x1f;        /**< \brief RXPAR */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_IMMO_DRIVER_CMD, u8CmdBuff, u8ResBuff, 0x04, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ConfigImmoBPLM
** @note	SPI_CMD:CONFIG_IMMO_BPLM
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigImmoBPLM(void)
{
    uint8_t i;

    // TLOG
    // [7:4]     | [3:0]
    // TLOG_1    | TLOG_0
    // 0000(HT3) | 0001(HT3)

    // MPT
    // [7:4]     | [3:0]
    // TSTOP     | TWRP
    // 0110(HT3) | 0110(HT3)

    u8CmdBuff[0] = (0x00 << 4) | 0x01; /**< \brief TLOG */
    u8CmdBuff[1] = (0x06 << 4) | 0x06; /**< \brief MPT */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_IMMO_BPLM_CMD, u8CmdBuff, u8ResBuff, 0x04, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ConfigImmoReceiver
** @note	SPI_CMD:CONFIG_IMMO_RECEIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigImmoReceiver(void)
{
    uint8_t i;

    // RXCFG
    // 7   | [6:2]                  | 1   | 0
    // RFU | TRWT                   | RFU | EQU
    // 0   | (n+1) * 202 T0 + TSYNC | 0   | 0 = EQ pattern  (5x "1")
    //     |                        |     | 1 = EQM pattern (6x "1" + 1x "0")

    u8CmdBuff[0] = 0x00; /**< \brief RXCFG */
    u8CmdBuff[1] = 0x10; /**< \brief TSYNC */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_IMMO_RECEIVER_CMD, u8CmdBuff, u8ResBuff, 0x04, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StartImmo
** @note	SPI_CMD:START_IMMO
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartImmo(void)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(START_IMMO_CMD, u8CmdBuff, u8ResBuff, 0x02, 3000) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StopImmo
** @note	SPI_CMD:STOP_IMMO
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StopImmo(void)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(STOP_IMMO_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StartImmoTransmit
** @note	SPI_CMD:START_IMMO_TRANSMIT_CMD
** @param	pu8TagData
** @param	u8BitsLen
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartImmoTransmit(uint8_t *pu8TagData, uint8_t u8BitsLen)
{
    uint8_t i;

    u8CmdBuff[0] = u8BitsLen; /**< \brief DATBLEN */

    for (i = 0x00; i < (u8BitsLen + 7) / 8; i++)
    {
        u8CmdBuff[i + 1] = pu8TagData[i]; /**< \brief Send data */
    }

    i = 0x00;
    while (_JOKER_CmdTransmit(START_IMMO_TRANSMIT_CMD, u8CmdBuff, u8ResBuff, ((u8BitsLen + 7) / 8 + 3), 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StartImmoTransceive
** @note	SPI_CMD:START_IMMO_TRANSCEIVE
** @param	pu8TagData
** @param	u8TagBitsLen
** @param	u8ResBitsLen
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartImmoTransceive(uint8_t *pu8TagData, uint8_t u8TagBitsLen, uint16_t u8ResBitsLen)
{
    uint8_t i;

    u8CmdBuff[0] = u8TagBitsLen; /**< \brief DATBLEN */

    for (i = 0; i < (u8TagBitsLen + 7) / 8; i++)
    {
        u8CmdBuff[i + 1] = pu8TagData[i]; /**< \brief Send data */
    }
    u8CmdBuff[i + 1] = (uint8_t)(u8ResBitsLen % 0x100); /**< \brief RX BitLen LOW_BYTE */
    u8CmdBuff[i + 2] = (uint8_t)(u8ResBitsLen / 0x100); /**< \brief RX BitLen HIGH_BYTE */

    i = 0x00;
    while (_JOKER_CmdTransmit(START_IMMO_TRANSCEIVE_CMD, u8CmdBuff, u8ResBuff, ((u8TagBitsLen + 7) / 8 + 5), 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_GetImmoResponse
** @note	SPI_CMD:GET_IMMO_RESPONSE
** @param	pu8ResData
** @param	u8ResBitsLen
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetImmoResponse(uint8_t *pu8ResData, uint16_t u8ResBitsLen)
{
    uint8_t *p_resbuf = 0x00;
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_IMMO_RESPONSE_CMD, u8CmdBuff, u8ResBuff, 0x02, 600) != 0) //((resbitlen + 7) / 8 + 4),
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    p_resbuf = &u8ResBuff[4];
    for (i = 0; i < u8ResBuff[0] - 4; i++)
    {
        *pu8ResData++ = *p_resbuf++;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ClearImmoStatus
** @note	SPI_CMD:CLEAR_IMMO_STATUS
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearImmoStatus(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = 0x01;
    while (_JOKER_CmdTransmit(CLEAR_IMMO_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetImmoMask
** @note	SPI_CMD:SET_IMMO_MASK
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetImmoMask(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = 0x08; // 0x01;
    while (_JOKER_CmdTransmit(SET_OP_MASK_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Antenna Parameter
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_MeasAntImp
** @note	SPI_CMD:MEAS_ANT_IMP
** @param	sDRPi ï¿½ï¿½Selects the LF driver for the antenna impedance measurement.
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_MeasAntImp(drpi_t sDRPi)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = sDRPi; /**< \brief DRiP : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½ */
    u8CmdBuff[1] = 0x00;  /**< \brief RFU */
    while (_JOKER_CmdTransmit(MEAS_ANT_IMP_CMD, u8CmdBuff, u8ResBuff, 0x04, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_MeasAntImpAdvanced
** @note	SPI_CMD:MEAS_ANT_IMP_ADVANCED
** @param	sDRPi ï¿½ï¿½Selects the LF driver for the antenna impedance measurement.
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_MeasAntImpAdvanced(drpi_t sDRPi)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = sDRPi; /**< \brief DRiP : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½ */
    u8CmdBuff[1] = 0x00;  /**< \brief RFU */
    while (_JOKER_CmdTransmit(MEAS_ANT_IMP_ADVANCED_CMD, u8CmdBuff, u8ResBuff, 0x04, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetAntImp
** @note	SPI_CMD:SET_ANT_IMP
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetAntImp(void)
{
    uint8_t i;

    u8CmdBuff[0] = DRID1; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½1 */
    u8CmdBuff[1] = 0x23;  /**< \brief Li    : ï¿½ï¿½ï¿½ßµï¿½ï¿½ï¿½ï¿?*/
    u8CmdBuff[2] = 0x12;  /**< \brief Qi    : ï¿½ï¿½ï¿½ï¿½QÖµ */
    u8CmdBuff[3] = 0x80;  /**< \brief DETi  : ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½Î§ */

    u8CmdBuff[4] = DRID2; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½2 */
    u8CmdBuff[5] = 0x23;  /**< \brief Li    : ï¿½ï¿½ï¿½ßµï¿½ï¿½ï¿½ï¿?*/
    u8CmdBuff[6] = 0x12;  /**< \brief Qi    : ï¿½ï¿½ï¿½ï¿½QÖµ */
    u8CmdBuff[7] = 0x80;  /**< \brief DETi  : ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½Î§ */

    u8CmdBuff[8] = DRID3; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½3 */
    u8CmdBuff[9] = 0x23;  /**< \brief Li    : ï¿½ï¿½ï¿½ßµï¿½ï¿½ï¿½ï¿?*/
    u8CmdBuff[10] = 0x12; /**< \brief Qi    : ï¿½ï¿½ï¿½ï¿½QÖµ */
    u8CmdBuff[11] = 0x80; /**< \brief DETi  : ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½Î§ */

    u8CmdBuff[12] = DRID4; /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½4 */
    u8CmdBuff[13] = 0x23;  /**< \brief Li    : ï¿½ï¿½ï¿½ßµï¿½ï¿½ï¿½ï¿?*/
    u8CmdBuff[14] = 0x12;  /**< \brief Qi    : ï¿½ï¿½ï¿½ï¿½QÖµ */
    u8CmdBuff[15] = 0x80;  /**< \brief DETi  : ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½Î§ */
#if 0	
    u8CmdBuff[16] = DRID5;	  /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½5 */
    u8CmdBuff[17] = 0x23;		/**< \brief Li    : ï¿½ï¿½ï¿½ßµï¿½ï¿½ï¿½ï¿?*/
    u8CmdBuff[18] = 0x12;		/**< \brief Qi    : ï¿½ï¿½ï¿½ï¿½QÖµ */
    u8CmdBuff[19] = 0x80;		/**< \brief DETi  : ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½Î§ */
    u8CmdBuff[20] = DRID6;	  /**< \brief DRIDi : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½6 */
    u8CmdBuff[21] = 0x23;		/**< \brief Li    : ï¿½ï¿½ï¿½ßµï¿½ï¿½ï¿½ï¿?*/
    u8CmdBuff[22] = 0x12;		/**< \brief Qi    : ï¿½ï¿½ï¿½ï¿½QÖµ */
    u8CmdBuff[23] = 0x80;		/**< \brief DETi  : ï¿½ï¿½ï¿½ï¿½Ê§ï¿½ï¿½ï¿½ï¿½Î§ */
#endif
    i = 0x00;
    while (_JOKER_CmdTransmit(SET_ANT_IMP_CMD, u8CmdBuff, u8ResBuff, 0x12, 1500) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_GetAntImp
** @note	SPI_CMD:Get_Ant_Imp
** @param	sDRPi	  : Selects the LF driver. Selecting more than one driver is possible.
** @param	pu8AntImp : The requested actual antenna impedance values
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetAntImp(drpi_t sDRPi, uint8_t *pu8AntImp)
{
    uint8_t i;
    uint8_t count = 0;

    u8CmdBuff[0] = sDRPi; /**< \brief DRiP : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½ */
    u8CmdBuff[1] = 0x00;  /**< \brief RFU */

    for (i = 0; i < 6; i++)
    {
        if (sDRPi & (0x01 << i))
            count++;
    }

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_ANT_IMP_CMD, u8CmdBuff, u8ResBuff, 0x04, 600) != 0) // 3 + count * 3,
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    for (i = 0; i < count; i++)
    {
        pu8AntImp[i * 3 + 0] = u8ResBuff[i * 3 + 3];
        pu8AntImp[i * 3 + 1] = u8ResBuff[i * 3 + 4];
        pu8AntImp[i * 3 + 2] = u8ResBuff[i * 3 + 5];
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_GetAntImp
** @note	SPI_CMD:GET_ANT_IMP_EFFECTIVE
** @param	sDRPi	  : Selects the LF driver. Selecting more than one driver is possible.
** @param	pu8AntImp : The requested actual antenna impedance values
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetAntImpEff(drpi_t sDRPi, uint8_t *pu8AntImp)
{
    uint8_t i;
    uint8_t count = 0;

    u8CmdBuff[0] = sDRPi; /**< \brief DRiP : LFï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½ */
    u8CmdBuff[1] = 0x00;  /**< \brief RFU */

    for (i = 0; i < 6; i++)
    {
        if (sDRPi & (0x01 << i))
            count++;
    }

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_ANT_IMP_EFFECTIVE_CMD, u8CmdBuff, u8ResBuff, 0x04, 600) != 0) // 3 + count * 4,
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    for (i = 0; i < count; i++)
    {
        pu8AntImp[i * 3 + 0] = u8ResBuff[i * 3 + 3];
        pu8AntImp[i * 3 + 1] = u8ResBuff[i * 3 + 4];
        pu8AntImp[i * 3 + 2] = u8ResBuff[i * 3 + 5];
        pu8AntImp[i * 3 + 3] = u8ResBuff[i * 3 + 6];
    }

    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Device Protection
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_GetPortStatus
** @note	SPI_CMD:GET_PROT_STATUS
** @param	pu8PortF : The protection flag register. @PROTFCM
** @param	pu8DrpF  : The LF driver protection status flag register. @DRPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetPortStatus(protfcm_t *psPortF, drpfcm_t *psDrpF)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_PROT_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    *psPortF = (protfcm_t)u8ResBuff[3];
    *psDrpF = (drpfcm_t)u8ResBuff[4];

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ClearProtStatus
** @note	SPI_CMD:GET_PROT_STATUS_CMD
** @param	sProtC : Clears the status flags. @PROTFCM
** @param	sDrpC  : Specifies the drivers which flags to be cleared. @DRPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearProtStatus(protfcm_t sProtC, drpfcm_t sDrpC)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = sProtC; /**< \brief PROTC: */
    u8CmdBuff[1] = sDrpC;  /**< \brief DRPC: */
    u8CmdBuff[2] = 0x00;   /**< \brief RFU */

    while (_JOKER_CmdTransmit(CLEAR_PROT_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x05, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetProtMask
** @note	SPI_CMD:SET_PROT_MASK
** @param	sProtM : provides the mask to enable the INT pin if a device protection flag is set. @PROTFCM
** @param	sDrpM  : masks the status flags of the LF drivers. @DRPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetProtMask(protfcm_t sProtM, drpfcm_t sDrpM)
{
    uint8_t i;

    u8CmdBuff[0] = sProtM; /**< \brief PROTM: */
    u8CmdBuff[1] = sDrpM;  /**< \brief DRPM: */
    u8CmdBuff[2] = 0x00;   /**< \brief RFU */

    i = 0x00;
    while (_JOKER_CmdTransmit(SET_PROT_MASK_CMD, u8CmdBuff, u8ResBuff, 0x05, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Device Diagnostics
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_StartDiag
** @note	SPI_CMD:START_DIAG
** @param	sDRPi    : Specify the drivers for diagnostics. @DRPI
** @param	sDiagPar :  @DIAGPAR
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartDiag(drpi_t sDRPi, diag_par_t sDiagPar)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = sDRPi;    /**< \brief DRP */
    u8CmdBuff[1] = 0x00;     /**< \brief RFU */
    u8CmdBuff[2] = sDiagPar; /**< \brief DIAGPAR : check for inter antenna shorts */

    while (_JOKER_CmdTransmit(START_DIAG_CMD, u8CmdBuff, u8ResBuff, 0x05, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_GetDiagStatus
** @note	SPI_CMD:GET_DIAG_STATUS
** @param	sDRPi : Specify the drivers for diagnostics. @DRPI
** @param	psSupF : Contains the diagnosis results for the boost converter and for the LF driver supply. @SUPFC
** @param	psDiagF : Contain the diagnostic results for the respective LF driver DRIDi @DIAGFC
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetDiagStatus(drpi_t sDRPi, supfc_t *psSupF, uint8_t *psDiagF)
{
    uint8_t i;
    uint8_t count = 0;

    for (i = 0; i < 6; i++)
    {
        if (sDRPi & (0x01 << i))
            count++;
    }

    u8CmdBuff[0] = sDRPi; /**< \brief DRP */
    u8CmdBuff[1] = 0x00;  /**< \brief RFU */

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_DIAG_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x04, 600) != 0) // 4 + count * 2,
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    *psSupF = (supfc_t)u8ResBuff[3];

    for (i = 0; i < count; i++)
    {
        psDiagF[2 * i + 0] = u8ResBuff[2 * i + 4];
        psDiagF[2 * i + 1] = u8ResBuff[2 * i + 5];
    }

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ClearDiagStatus
** @note	SPI_CMD:CLEAR_DIAG_STATUS
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearDiagStatus(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = 0x03;
    u8CmdBuff[1] = DRID1;
    u8CmdBuff[2] = 0x0F;
    u8CmdBuff[3] = DRID2;
    u8CmdBuff[4] = 0x0F;
    u8CmdBuff[5] = DRID3;
    u8CmdBuff[6] = 0x0F;
    u8CmdBuff[7] = DRID4;
    u8CmdBuff[8] = 0x0F;
    u8CmdBuff[9] = DRID5;
    u8CmdBuff[10] = 0x0F;
    u8CmdBuff[11] = DRID6;
    u8CmdBuff[12] = 0x0F;
    while (_JOKER_CmdTransmit(CLEAR_DIAG_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x0F, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    SPI Interface
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigSpi
** @note	SPI_CMD:CONFIG_SPI
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigSpi(void)
{
    uint8_t i;

    u8CmdBuff[0] = 0xFF; /**< \brief SPI_TIMEOUT n ms */
    u8CmdBuff[1] = 0x00; /**< \brief RFU */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_SPI_CMD, u8CmdBuff, u8ResBuff, 0x04, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Wake-up Ports
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigWup
** @note	SPI_CMD:CONFIG_WUP
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigWup(void)
{
    uint8_t i;

    // WUPEN
    // [7:6] | 5       | 4       | 3       | 2       | 1       | 0
    // RFU   | WUP6EN  | WUP5EN  | WUP4EN  | WUP3EN  | WUP2EN  | WUP1EN
    // 00    | 0 = DIS | 0 = DIS | 0 = DIS | 0 = DIS | 0 = DIS | 0 = DIS
    //       | 1 = EN  | 1 = EN  | 1 = EN  | 1 = EN  | 1 = EN  | 1 = EN

    // WUPEDG
    // [7:6] | 5           | 4           | 3           | 2           | 1           | 0
    // RFU   | WUP6EDG     | WUP5EDG     | WUP4EDG     | WUP3EDG     | WUP2EDG     | WUP1EDG
    // 00    | 0 = Falling | 0 = Falling | 0 = Falling | 0 = Falling | 0 = Falling | 0 = Falling
    //       | 1 = Rising  | 1 = Rising  | 1 = Rising  | 1 = Rising  | 1 = Rising  | 1 = Rising

    // WUPDEB
    // [7:6] | [7:0]
    // RFU   | WUPDEB[5:0]
    // 00    | [0x0..0x3f]ms

    // WUPVAL
    // [7:6] | [7:0]
    // RFU   | WUPVAL[5:0]
    // 00    | [0x0..0x3f]ms

    // WUPPRIO1
    // [7:4]         | [3:0]
    // WUP6PRIO[3:0] | WUP5PRIO[3:0]
    // 0000(lowest)..0111(highest)

    // WUPPRIO2
    // [7:4]         | [3:0]
    // WUP4PRIO[3:0] | WUP3PRIO[3:0]
    // 0000(lowest)..0111(highest)

    // WUPPRIO3
    // [7:4]         | [3:0]
    // WUP2PRIO[3:0] | WUP1PRIO[3:0]
    // 0000(lowest)..0111(highest)

    u8CmdBuff[0] = 0x00; /**< \brief WUPEN    : Enables or disables the port pin wake-up function */
    u8CmdBuff[1] = 0x00; /**< \brief WUPEDG   : Specifies the signal edge on which the device wakes up */
    u8CmdBuff[2] = 0x00; /**< \brief WUPDEB   : Time interval for WUP debouncing */
    u8CmdBuff[3] = 0x00; /**< \brief WUPVAL   : Time interval for WUP valid check */
    u8CmdBuff[4] = 0x00; /**< \brief WUPPRIO1 : The priorities for WUP handling */
    u8CmdBuff[5] = 0x00; /**< \brief WUPPRIO2 : The priorities for WUP handling */
    u8CmdBuff[6] = 0x00; /**< \brief WUPPRIO3 : The priorities for WUP handling */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_WUP_CMD, u8CmdBuff, u8ResBuff, 0x09, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_GetWupStatus
** @note	SPI_CMD:GET_WUP_STATUS
** @param	psWupF:Signalizes wake-up events pending that were generated by the corresponding wake-up inputs. @WUPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetWupStatus(wupfcm_t *psWupF)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_WUP_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    *psWupF = (wupfcm_t)u8ResBuff[3];

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ClearWupStatus
** @note	SPI_CMD:CLEAR_WUP_STATUS
** @param	sWupC:Specifies the wake-up flag to be cleared. @WUPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearWupStatus(wupfcm_t sWupC)
{
    uint8_t i;

    u8CmdBuff[0] = sWupC; /**< \brief  */

    i = 0x00;
    while (_JOKER_CmdTransmit(CLEAR_WUP_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetWupMask
** @note	SPI_CMD:SET_WUP_MASK
** @param	sWupM:Provides the mask to enable the INT pin if a wake-up event occurs. @WUPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetWupMask(wupfcm_t sWupM)
{
    uint8_t i;

    u8CmdBuff[0] = sWupM;

    i = 0x00;
    while (_JOKER_CmdTransmit(SET_WUP_MASK_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    WUP event triggered polling
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigWupPolling
** @note	SPI_CMD:CONFIG_WUP_POLLING
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigWupPolling(void)
{
    uint8_t i;

    u8CmdBuff[0] = 0x00;             /**< \brief WUPIO      : The wake-up ports to trigger LF transmission. */
    u8CmdBuff[1] = 0x00;             /**< \brief DRPi       : LF Driver*/
    u8CmdBuff[2] = 0x00;             /**< \brief RFU */
    u8CmdBuff[3] = 0x00;             /**< \brief LCDRPi     : The low current LF drivers to be activated */
    u8CmdBuff[4] = 0x00;             /**< \brief RFU */
    u8CmdBuff[5] = 0xC8;             /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
    u8CmdBuff[6] = 0x01;             /**< \brief PTIME_Hi   : */
    u8CmdBuff[7] = 0x05;             /**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */
    u8CmdBuff[8] = DATA_ID_PREMABLE; /**< \brief DATAIDik   : premable */
    u8CmdBuff[9] = DATA_ID_CV;       /**< \brief DATAIDik   : CVï¿½ï¿½ */
    u8CmdBuff[10] = DATA_ID_WUP1;    /**< \brief DATAIDik   : WUP1 */
    u8CmdBuff[11] = DATA_ID_DATA_PE; /**< \brief DATAIDik   : LF Data */
    u8CmdBuff[12] = DATA_ID_CC_5;    /**< \brief DATAIDik   : 5msï¿½ï¿½ï¿½Ø²ï¿½ */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_WUP_POLLING_CMD, u8CmdBuff, u8ResBuff, 0x0F, 1200) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Timer triggered polling
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigTimerPolling
** @note	SPI_CMD:CONFIG_TIMER_POLLING
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigTimerPolling(void)
{
    uint8_t i;

    u8CmdBuff[0] = DR2P;            /**< \brief DRPi       : LF Driver */
    u8CmdBuff[1] = 0x00;            /**< \brief DRNi       : */
    u8CmdBuff[2] = 0x00;            /**< \brief LCDRPi     : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
    u8CmdBuff[3] = 0x00;            /**< \brief LCDRNi     : */
    u8CmdBuff[4] = 0x64;            /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
    u8CmdBuff[5] = 0x00;            /**< \brief PTIME_Hi   : */
    u8CmdBuff[6] = 0x03;            /**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */
    u8CmdBuff[7] = DATA_ID_WUP1;    /**< \brief DATAIDik   : WUP1 */
    u8CmdBuff[8] = DATA_ID_DATA_PE; /**< \brief DATAIDik : LF Data */
    u8CmdBuff[9] = DATA_ID_CC_5;    /**< \brief DATAIDik   : 5msï¿½ï¿½ï¿½Ø²ï¿½ */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_TIMER_POLLING_CMD, u8CmdBuff, u8ResBuff, 0x0C, 2100) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

stat_t NJJ29C0_ConfigTimerPolling(uint8_t drpi, uint16_t ptime, uint8_t len, uint8_t *dataid)
{
    uint8_t i;

    u8CmdBuff[0] = drpi;                  // DR2P;					/**< \brief DRPi       : LF Driver */
    u8CmdBuff[1] = 0x00;                  /**< \brief DRNi       : */
    u8CmdBuff[2] = 0x00;                  /**< \brief LCDRPi     : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
    u8CmdBuff[3] = 0x00;                  /**< \brief LCDRNi     : */
    u8CmdBuff[4] = (uint8_t)ptime;        // 0x64;					/**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
    u8CmdBuff[5] = (uint8_t)(ptime >> 8); // 0x00;					/**< \brief PTIME_Hi   : */
    u8CmdBuff[6] = len;                   // 0x03;					/**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */

    for (i = 0; i < len; i++)
    {
        u8CmdBuff[7 + i] = dataid[i];
    }
    // u8CmdBuff[7] = DATA_ID_WUP1;			/**< \brief DATAIDik   : WUP1 */
    // u8CmdBuff[8] = DATA_ID_DATA_PE;		/**< \brief DATAIDik : LF Data */
    // u8CmdBuff[9] = DATA_ID_CC_5;			/**< \brief DATAIDik   : 5msï¿½ï¿½ï¿½Ø²ï¿½ */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_TIMER_POLLING_CMD, u8CmdBuff, u8ResBuff, 9 + len, 2100) != 0)
    {
        i++;
        if (i == 3)
        {
            return SF_SPI;
        }
    }
    return (stat_t)u8ResBuff[2];
}

stat_t Peps_Cfg_Joker_Tx_Message(uint8_t Ant1,uint8_t DataId_Len1, uint8_t *Lf_Ant1_DataIdx,
											  uint8_t Ant2,uint8_t DataId_Len2, uint8_t *Lf_Ant2_DataIdx,
											  uint8_t Ant3,uint8_t DataId_Len3, uint8_t *Lf_Ant3_DataIdx)
{
	uint8_t i = 0;
    uint8_t txlen = 0;

	if(Ant1 != DRP_NULL)
	{
		u8CmdBuff[txlen++]  = Ant1;		/**< \brief DRPi       : LF Driver */
	    u8CmdBuff[txlen++]  = 0x00;		/**< \brief RFU        : */
	    u8CmdBuff[txlen++]  = DRP_NULL;	/**< \brief LCDRPi     : µÍ¹¦ºÄLF Driver */
	    u8CmdBuff[txlen++]  = 0x00;		/**< \brief RFU        : */
	    u8CmdBuff[txlen++]  = DataId_Len1;    /**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */

	    for(i = 0; i < DataId_Len1; i++)
	    {
	        u8CmdBuff[txlen++]  = Lf_Ant1_DataIdx[i];	/**< \brief DATAIDik   : */
	    }
	}
	
	if(Ant2 != DRP_NULL)
	{
		u8CmdBuff[txlen++]  = Ant2;		/**< \brief DRPi       : LF Driver */
	    u8CmdBuff[txlen++]  = 0x00;		/**< \brief RFU        : */
	    u8CmdBuff[txlen++]  = DRP_NULL;	/**< \brief LCDRPi     : µÍ¹¦ºÄLF Driver */
	    u8CmdBuff[txlen++]  = 0x00;		/**< \brief RFU        : */
	    u8CmdBuff[txlen++]  = DataId_Len2;    /**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */

	    for(i = 0; i < DataId_Len2; i++)
	    {
	        u8CmdBuff[txlen++]  = Lf_Ant2_DataIdx[i];	/**< \brief DATAIDik   : */
	    }
	}
	
	if(Ant3 != DRP_NULL)
	{
		u8CmdBuff[txlen++]  = Ant3;		/**< \brief DRPi	   : LF Driver */
		u8CmdBuff[txlen++]  = 0x00;		/**< \brief RFU 	   : */
		u8CmdBuff[txlen++]  = DRP_NULL;	/**< \brief LCDRPi	   : µÍ¹¦ºÄLF Driver */
		u8CmdBuff[txlen++]  = 0x00;		/**< \brief RFU 	   : */
		u8CmdBuff[txlen++]  = DataId_Len3;	/**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */

		for(i = 0; i < DataId_Len3; i++)
		{
			u8CmdBuff[txlen++]  = Lf_Ant3_DataIdx[i]; /**< \brief DATAIDik   : */
		}
	}

	_JOKER_CmdTransmit(START_LF_TRANSMIT_CMD, u8CmdBuff, u8ResBuff, txlen + 2, 600);
	
    return (stat_t)u8ResBuff[2];
}

stat_t Peps_Fun_ConfigTimerPolling(uint8_t Cmd, uint8_t Incar_Ant, uint16_t ptime0, uint8_t LfDoor_Ant, uint16_t ptime1, uint8_t RfDoor_Ant, uint16_t ptime2)
{
    uint8_t i;
	uint8_t txlen = 0;

	if((Cmd == 0x10)||(Cmd == 0x00))
	{
		u8CmdBuff[0] = Incar_Ant;					/**< \brief DRPi       : LF Driver */
	    u8CmdBuff[1] = 0x00;					/**< \brief DRNi       : */
	    u8CmdBuff[2] = 0x00;					/**< \brief LCDRPi     : µÍ¹¦ºÄLF Driver */
	    u8CmdBuff[3] = 0x00;					/**< \brief LCDRNi     : */
	    u8CmdBuff[4] = (uint8_t)ptime0;         /**< \brief PTIME_Li   : pollingÊ±¼ä£¬µ¥Î»Îª1ms */
	    u8CmdBuff[5] = (uint8_t)(ptime0>>8);
	    u8CmdBuff[6] = 5;					    /**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */
		u8CmdBuff[7] = DATA_ID_PREMABLE;
		u8CmdBuff[8] = DATA_ID_CV;
		u8CmdBuff[9] = DATA_ID_WUP1;
		u8CmdBuff[10] = DATA_ID_DATA_PE;
		u8CmdBuff[11] = DATA_ID_DATA_RSSI;

		u8CmdBuff[12] = LfDoor_Ant;					/**< \brief DRPi	   : LF Driver */
		u8CmdBuff[13] = 0x00;					/**< \brief DRNi	   : */
		u8CmdBuff[14] = 0x00;					/**< \brief LCDRPi	   : µÍ¹¦ºÄLF Driver */
		u8CmdBuff[15] = 0x00;					/**< \brief LCDRNi	   : */
		u8CmdBuff[16] = (uint8_t)ptime1; 		/**< \brief PTIME_Li   : pollingÊ±¼ä£¬µ¥Î»Îª1ms */
		u8CmdBuff[17] = (uint8_t)(ptime1>>8);
		u8CmdBuff[18] = 1;						/**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */
		u8CmdBuff[19] = DATA_ID_DATA_RSSI;

		u8CmdBuff[20] = RfDoor_Ant;				/**< \brief DRPi	   : LF Driver */
		u8CmdBuff[21] = 0x00;					/**< \brief DRNi	   : */
		u8CmdBuff[22] = 0x00;					/**< \brief LCDRPi	   : µÍ¹¦ºÄLF Driver */
		u8CmdBuff[23] = 0x00;					/**< \brief LCDRNi	   : */
		u8CmdBuff[24] = (uint8_t)ptime2; 		/**< \brief PTIME_Li   : pollingÊ±¼ä£¬µ¥Î»Îª1ms */
		u8CmdBuff[25] = (uint8_t)(ptime2>>8);
		u8CmdBuff[26] = 1;						/**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */
		u8CmdBuff[27] = DATA_ID_DATA_RSSI;

		txlen = 28;
	}
	else if((Cmd == 0x11)||(Cmd == 0x12))
	{
		if(Cmd == 0x11)
		{
			u8CmdBuff[0] = LfDoor_Ant;				/**< \brief DRPi       : LF Driver */
		}
		else
		{
			u8CmdBuff[0] = RfDoor_Ant;				/**< \brief DRPi       : LF Driver */
		}
	    u8CmdBuff[1] = 0x00;					/**< \brief DRNi       : */
	    u8CmdBuff[2] = 0x00;					/**< \brief LCDRPi     : µÍ¹¦ºÄLF Driver */
	    u8CmdBuff[3] = 0x00;					/**< \brief LCDRNi     : */
	    u8CmdBuff[4] = (uint8_t)ptime1;         /**< \brief PTIME_Li   : pollingÊ±¼ä£¬µ¥Î»Îª1ms */
	    u8CmdBuff[5] = (uint8_t)(ptime1>>8);
	    u8CmdBuff[6] = 5;					    /**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */
		u8CmdBuff[7] = DATA_ID_PREMABLE;
		u8CmdBuff[8] = DATA_ID_CV;
		u8CmdBuff[9] = DATA_ID_WUP1;
		u8CmdBuff[10] = DATA_ID_DATA_PE;
		u8CmdBuff[11] = DATA_ID_DATA_RSSI;

		u8CmdBuff[12] = Incar_Ant;				/**< \brief DRPi	   : LF Driver */
		u8CmdBuff[13] = 0x00;					/**< \brief DRNi	   : */
		u8CmdBuff[14] = 0x00;					/**< \brief LCDRPi	   : µÍ¹¦ºÄLF Driver */
		u8CmdBuff[15] = 0x00;					/**< \brief LCDRNi	   : */
		u8CmdBuff[16] = (uint8_t)ptime0; 		/**< \brief PTIME_Li   : pollingÊ±¼ä£¬µ¥Î»Îª1ms */
		u8CmdBuff[17] = (uint8_t)(ptime0>>8);
		u8CmdBuff[18] = 1;						/**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */
		u8CmdBuff[19] = DATA_ID_DATA_RSSI;

		txlen = 20;
	}
	else if(Cmd == 0x13)
	{
		u8CmdBuff[0] = LfDoor_Ant|RfDoor_Ant;	/**< \brief DRPi       : LF Driver */
	    u8CmdBuff[1] = 0x00;					/**< \brief DRNi       : */
	    u8CmdBuff[2] = 0x00;					/**< \brief LCDRPi     : µÍ¹¦ºÄLF Driver */
	    u8CmdBuff[3] = 0x00;					/**< \brief LCDRNi     : */
	    u8CmdBuff[4] = (uint8_t)ptime1;         /**< \brief PTIME_Li   : pollingÊ±¼ä£¬µ¥Î»Îª1ms */
	    u8CmdBuff[5] = (uint8_t)(ptime1>>8);
	    u8CmdBuff[6] = 5;					    /**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */
		u8CmdBuff[7] = DATA_ID_PREMABLE;
		u8CmdBuff[8] = DATA_ID_CV;
		u8CmdBuff[9] = DATA_ID_WUP1;
		u8CmdBuff[10] = DATA_ID_DATA_PE;
		u8CmdBuff[11] = DATA_ID_DATA_RSSI;
		txlen = 12;
	}
	else if(Cmd == 0x14)
	{
		u8CmdBuff[0] = LfDoor_Ant|RfDoor_Ant;	/**< \brief DRPi       : LF Driver */
	    u8CmdBuff[1] = 0x00;					/**< \brief DRNi       : */
	    u8CmdBuff[2] = 0x00;					/**< \brief LCDRPi     : µÍ¹¦ºÄLF Driver */
	    u8CmdBuff[3] = 0x00;					/**< \brief LCDRNi     : */
	    u8CmdBuff[4] = (uint8_t)ptime1;         /**< \brief PTIME_Li   : pollingÊ±¼ä£¬µ¥Î»Îª1ms */
	    u8CmdBuff[5] = (uint8_t)(ptime1>>8);
	    u8CmdBuff[6] = 4;					    /**< \brief LENDATAIDi : Êý¾Ý¶ÎÊý */
		u8CmdBuff[7] = DATA_ID_PREMABLE;
		u8CmdBuff[8] = DATA_ID_CV;
		u8CmdBuff[9] = DATA_ID_WUP1;
		u8CmdBuff[10] = DATA_ID_DATA_PE;

		txlen = 11;
	}
	else
	{
		return SF_LAST_OP;
	}

    i = 0x00;
    while(_JOKER_CmdTransmit(CONFIG_TIMER_POLLING_CMD, u8CmdBuff, u8ResBuff, txlen + 2, 100) != 0)
    {
        i++;
        if (i == 3) 
		{
			return SF_SPI;
        }
    }
    return (stat_t)u8ResBuff[2];
}

stat_t WelcomeGuest_ConfigTimerPollingOne(uint8_t Incar_Ant, uint16_t ptime0, uint8_t LfDoor_Ant, uint16_t ptime1, uint8_t RfDoor_Ant, uint16_t ptime2)
{
    uint8_t i;
    uint8_t txlen = 0;

    u8CmdBuff[0] = Incar_Ant;       /**< \brief DRPi       : LF Driver */
    u8CmdBuff[1] = 0x00;            /**< \brief DRNi       : */
    u8CmdBuff[2] = 0x00;            /**< \brief LCDRPi     : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
    u8CmdBuff[3] = 0x00;            /**< \brief LCDRNi     : */
    u8CmdBuff[4] = (uint8_t)ptime0; /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
    u8CmdBuff[5] = (uint8_t)(ptime0 >> 8);
    u8CmdBuff[6] = 5; /**< \brief LENDATAIDi : æ•°æ®æ®µæ•° */

    u8CmdBuff[7] = DATA_ID_PREMABLE;
    u8CmdBuff[8] = DATA_ID_CV;
    u8CmdBuff[9] = DATA_ID_WUP1;
    u8CmdBuff[10] = DATA_ID_DATA_PE;

    u8CmdBuff[11] = DATA_ID_DATA_RSSI;

    u8CmdBuff[12] = LfDoor_Ant;      /**< \brief DRPi	   : LF Driver */
    u8CmdBuff[13] = 0x00;            /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
    u8CmdBuff[14] = 0x00;            /**< \brief LCDRNi	  : */
    u8CmdBuff[15] = 0x00;            /**< \brief LCDRNi	   : */
    u8CmdBuff[16] = (uint8_t)ptime1; /**< \brief PTIME_Li   : pollingæ—¶é—´ï¼Œå•ä½ä¸º1ms */
    u8CmdBuff[17] = (uint8_t)(ptime1 >> 8);
    u8CmdBuff[18] = 1; /**< \brief LENDATAIDi : æ•°æ®æ®µæ•° */
    u8CmdBuff[19] = DATA_ID_DATA_RSSI;

    u8CmdBuff[20] = RfDoor_Ant;      /**< \brief DRPi	   : LF Driver */
    u8CmdBuff[21] = 0x00;            /**< \brief DRNi	   : */
    u8CmdBuff[22] = 0x00;            /**< \brief LCDRPi	   : ä½ŽåŠŸè€—LF Driver */
    u8CmdBuff[23] = 0x00;            /**< \brief LCDRNi	   : */
    u8CmdBuff[24] = (uint8_t)ptime2; /**< \brief PTIME_Li   : pollingæ—¶é—´ï¼Œå•ä½ä¸º1ms */
    u8CmdBuff[25] = (uint8_t)(ptime2 >> 8);
    u8CmdBuff[26] = 1; /**< \brief LENDATAIDi : æ•°æ®æ®µæ•° */
    u8CmdBuff[27] = DATA_ID_DATA_RSSI;

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_TIMER_POLLING_CMD, u8CmdBuff, u8ResBuff, 30, 100) != 0)
    {
        i++;
        if (i == 3)
        {
            return SF_SPI;
        }
    }
    return (stat_t)u8ResBuff[2];
}

stat_t WelcomeGuest_ConfigTimerPollingTwo(uint8_t wakeid_num, uint8_t drpi0, uint16_t ptime0, uint8_t drpi1, uint16_t ptime1, uint8_t Carrier_OnOff)
{
    uint8_t i;
    uint8_t txlen = 0;

    if (wakeid_num == 1)
    {
        if (Carrier_OnOff > 0)
        {
            u8CmdBuff[0] = drpi0;           /**< \brief DRPi 	  : LF Driver */
            u8CmdBuff[1] = 0x00;            /**< \brief DRNi 	  : */
            u8CmdBuff[2] = 0x00;            /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
            u8CmdBuff[3] = 0x00;            /**< \brief LCDRNi	  : */
            u8CmdBuff[4] = (uint8_t)ptime0; /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
            u8CmdBuff[5] = (uint8_t)(ptime0 >> 8);
            u8CmdBuff[6] = 5; /**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */
            u8CmdBuff[7] = DATA_ID_PREMABLE;
            u8CmdBuff[8] = DATA_ID_CV;
            u8CmdBuff[9] = DATA_ID_WUP1;
            u8CmdBuff[10] = DATA_ID_DATA_PE;
            u8CmdBuff[11] = DATA_ID_DATA_RSSI;
            txlen = 14;
        }
        else
        {
            u8CmdBuff[0] = drpi0;           /**< \brief DRPi 	  : LF Driver */
            u8CmdBuff[1] = 0x00;            /**< \brief DRNi 	  : */
            u8CmdBuff[2] = 0x00;            /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
            u8CmdBuff[3] = 0x00;            /**< \brief LCDRNi	  : */
            u8CmdBuff[4] = (uint8_t)ptime0; /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
            u8CmdBuff[5] = (uint8_t)(ptime0 >> 8);
            u8CmdBuff[6] = 4; /**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */
            u8CmdBuff[7] = DATA_ID_PREMABLE;
            u8CmdBuff[8] = DATA_ID_CV;
            u8CmdBuff[9] = DATA_ID_WUP1;
            u8CmdBuff[10] = DATA_ID_DATA_PE;
            txlen = 13;
        }
    }
    else if (wakeid_num >= 2)
    {
        if (Carrier_OnOff > 0)
        {
            u8CmdBuff[0] = drpi0;           /**< \brief DRPi 	  : LF Driver */
            u8CmdBuff[1] = 0x00;            /**< \brief DRNi 	  : */
            u8CmdBuff[2] = 0x00;            /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
            u8CmdBuff[3] = 0x00;            /**< \brief LCDRNi	  : */
            u8CmdBuff[4] = (uint8_t)ptime0; /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
            u8CmdBuff[5] = (uint8_t)(ptime0 >> 8);
            u8CmdBuff[6] = 5; /**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */
            u8CmdBuff[7] = DATA_ID_PREMABLE;
            u8CmdBuff[8] = DATA_ID_CV;
            u8CmdBuff[9] = DATA_ID_WUP1;
            u8CmdBuff[10] = DATA_ID_DATA_PE;
            u8CmdBuff[11] = DATA_ID_DATA_RSSI;

            u8CmdBuff[12] = drpi1;                  /**< \brief DRPi 	  : LF Driver */
            u8CmdBuff[13] = 0x00;                   /**< \brief DRNi 	  : */
            u8CmdBuff[14] = 0x00;                   /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
            u8CmdBuff[15] = 0x00;                   /**< \brief LCDRNi	  : */
            u8CmdBuff[16] = (uint8_t)ptime1;        /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
            u8CmdBuff[17] = (uint8_t)(ptime1 >> 8); /**< \brief PTIME_Hi   : */
            u8CmdBuff[18] = 5;
            u8CmdBuff[19] = DATA_ID_PREMABLE;
            u8CmdBuff[20] = DATA_ID_CV;
            u8CmdBuff[21] = DATA_ID_WUP2;
            u8CmdBuff[22] = DATA_ID_CC_5;
            u8CmdBuff[23] = DATA_ID_DATA_RSSI;

            txlen = 26;
        }
        else
        {
            u8CmdBuff[0] = drpi0;           /**< \brief DRPi 	  : LF Driver */
            u8CmdBuff[1] = 0x00;            /**< \brief DRNi 	  : */
            u8CmdBuff[2] = 0x00;            /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
            u8CmdBuff[3] = 0x00;            /**< \brief LCDRNi	  : */
            u8CmdBuff[4] = (uint8_t)ptime0; /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
            u8CmdBuff[5] = (uint8_t)(ptime0 >> 8);
            u8CmdBuff[6] = 4; /**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */
            u8CmdBuff[7] = DATA_ID_PREMABLE;
            u8CmdBuff[8] = DATA_ID_CV;
            u8CmdBuff[9] = DATA_ID_WUP1;
            u8CmdBuff[10] = DATA_ID_DATA_PE;

            u8CmdBuff[11] = drpi1;                  /**< \brief DRPi 	  : LF Driver */
            u8CmdBuff[12] = 0x00;                   /**< \brief DRNi 	  : */
            u8CmdBuff[13] = 0x00;                   /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
            u8CmdBuff[14] = 0x00;                   /**< \brief LCDRNi	  : */
            u8CmdBuff[15] = (uint8_t)ptime1;        /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
            u8CmdBuff[16] = (uint8_t)(ptime1 >> 8); /**< \brief PTIME_Hi   : */
            u8CmdBuff[17] = 4;
            u8CmdBuff[18] = DATA_ID_PREMABLE;
            u8CmdBuff[19] = DATA_ID_CV;
            u8CmdBuff[20] = DATA_ID_WUP2;
            u8CmdBuff[21] = DATA_ID_CC_5;
            txlen = 24;
        }
    }

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_TIMER_POLLING_CMD, u8CmdBuff, u8ResBuff, txlen, 100) != 0)
    {
        i++;
        if (i == 3)
        {
            return SF_SPI;
        }
    }
    return (stat_t)u8ResBuff[2];
}

stat_t WelcomeGuest_ConfigTimerPollingWakeUp(uint8_t drpi,uint16_t ptime)
{
    uint8_t i;
	uint8_t txlen = 0;

	u8CmdBuff[0] = drpi;				   /**< \brief DRPi 	  : LF Driver */
	u8CmdBuff[1] = 0x00; 				   /**< \brief DRNi 	  : */
	u8CmdBuff[2] = 0x00; 				   /**< \brief LCDRPi	  : ï¿½Í¹ï¿½ï¿½ï¿½LF Driver */
	u8CmdBuff[3] = 0x00; 				   /**< \brief LCDRNi	  : */
	u8CmdBuff[4] = (uint8_t)ptime;		   /**< \brief PTIME_Li   : pollingÊ±ï¿½ä£¬ï¿½ï¿½Î»Îª1ms */
	u8CmdBuff[5] = (uint8_t)(ptime>>8);
	u8CmdBuff[6] = 4;						/**< \brief LENDATAIDi : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ */
	u8CmdBuff[7] = DATA_ID_PREMABLE;
	u8CmdBuff[8] = DATA_ID_CV;
	u8CmdBuff[9] = DATA_ID_WUP1;
	u8CmdBuff[10] = DATA_ID_DATA_PE;
	txlen = 13;
	
    i = 0x00;
    while(_JOKER_CmdTransmit(CONFIG_TIMER_POLLING_CMD, u8CmdBuff, u8ResBuff, txlen, 100) != 0)
    {
        i++;
        if (i == 3) 
		{
			return SF_SPI;
        }
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_StartTimerPolling
** @note	SPI_CMD:START_TIMER_POLLING
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartTimerPolling(void)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(START_TIMER_POLLING_CMD, u8CmdBuff, u8ResBuff, 0x02, 100) != 0)
    {
        i++;
        if (i == 3)
        {
            return SF_SPI;
        }
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Temperature indication
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigTemp
** @note	SPI_CMD:CONFIG_TEMP
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigTemp(void)
{
    uint8_t i;

    // TPAR
    // [7:5] | 4        | [3:0]
    // RFU   | TWARN_EN | TTHR[3:0]
    // 00    | 0 = DIS  | 0x0  85ï¿½ï¿½C
    //       | 1 = EN   | 0x1  95ï¿½ï¿½C
    //       |          | ...
    //       |          | 0xE 155ï¿½ï¿½C

    u8CmdBuff[0] = 0x00; /**< \brief TPAR: The temperature threshold for temperature indication/warning and enables the function on demand */

    i = 0x00;
    while (_JOKER_CmdTransmit(CONFIG_TEMP_CMD, u8CmdBuff, u8ResBuff, 0x03, 600) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_GetTempStatus
** @note	SPI_CMD:GET_TEMP_STATUS
** @param	psTempF : The temperature warning flag.
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetTempStatus(tempfcm_t *psTempF)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_TEMP_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    *psTempF = (tempfcm_t)u8ResBuff[3];

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ClearTempStatus
** @note	SPI_CMD:CLEAR_TEMP_STATUS
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearTempStatus(void)
{
    uint8_t i;

    u8CmdBuff[0] = 0x01; /**< \brief TEMPC */

    i = 0x00;
    while (_JOKER_CmdTransmit(CLEAR_TEMP_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetTempMask
** @note	SPI_CMD:SET_TEMP_MASK
** @param	sTempM : The mask to enable the INT pin if the temperature warning flag is set @TEMPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetTempMask(tempfcm_t sTempM)
{
    uint8_t i;

    u8CmdBuff[0] = sTempM; /**< \brief TEMPM */

    i = 0x00;
    while (_JOKER_CmdTransmit(SET_TEMP_MASK_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    Operation status flags
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_GetOpStatus
** @note	SPI_CMD:GET_OP_STATUS
** @param	psOpF : @OPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetOpStatus(opfcm_t *psOpF)
{
    uint8_t i;

    i = 0x00;
    while (_JOKER_CmdTransmit(GET_OP_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x02, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }

    *psOpF = (opfcm_t)u8ResBuff[3];

    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_ClearOpStatus
** @note	SPI_CMD:CLEAR_OP_STATUS
** @param	sOpC : @OPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearOpStatus(opfcm_t sOpC)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = sOpC; /**< \brief  */
    while (_JOKER_CmdTransmit(CLEAR_OP_STATUS_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetOpMask
** @note	SPI_CMD:SET_OP_STATUS
** @param	sOpM : @OPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetOpMask(opfcm_t sOpM)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = sOpM;
    while (_JOKER_CmdTransmit(SET_OP_MASK_CMD, u8CmdBuff, u8ResBuff, 0x03, 300) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*--------------------------------------------------------------------------------------------------------
    User Preset Lf Data
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_SetPremable
** @note	SPI_CMD:SET_LF_DATA
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetPremable(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = DATA_ID_PREMABLE; /**< \brief DATAID  : ï¿½ï¿½ï¿½Ý¶Î±ï¿½Ê¶(premable) */
    u8CmdBuff[1] = 0x00;             /**< \brief DATACFG : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ï¿½Ã£ï¿½manchester */
    u8CmdBuff[2] = 0x08;             /**< \brief DATALEN : ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿½7(bit) */
    u8CmdBuff[3] = 0x00;             /**< \brief DATAi   : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½0x00ï¿½ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */

    while (_JOKER_CmdTransmit(SET_LF_DATA_CMD, u8CmdBuff, u8ResBuff, 0x06, 500) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

/*********************************************************************************************************
** @brief	JOKER_SetCodeViolation
** @note	SPI_CMD:SET_LF_DATA
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetCodeViolation(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = DATA_ID_CV; /**< \brief DATAID  : ï¿½ï¿½ï¿½Ý¶Î±ï¿½Ê¶(CV) */
    u8CmdBuff[1] = 0x02;       /**< \brief DATACFG : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ï¿½Ã£ï¿½HBW_NRZ */
    u8CmdBuff[2] = 0x12;       /**< \brief DATALEN : ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿½18(bit) */
    u8CmdBuff[3] = 0xE2;       /**< \brief DATA0   : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */
    u8CmdBuff[4] = 0xCC;       /**< \brief DATA1   : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */
    u8CmdBuff[5] = 0x80;       /**< \brief DATA2   : ï¿½ï¿½Î»ï¿½È·ï¿½ï¿½ï¿½Ê£ï¿½ï¿½Äµï¿½Î»ï¿½ï¿½ï¿½ï¿?*/

    while (_JOKER_CmdTransmit(SET_LF_DATA_CMD, u8CmdBuff, u8ResBuff, 0x08, 500) != 0)
    {
        i++;
        if (i == 3)
            return SF_SPI;
    }
    return (stat_t)u8ResBuff[2];
}

void JOKER_Init(void)
{
    uint8_t status = 0;
    uint8_t _c0_temp[32];
    static uint8_t u8NJJ29c0InitStep = 0;
    static uint8_t u8InitWaitMaxTimeCnt = 0;
    static uint8_t u8InitMaxCnt = 0;

	static uint8_t u8Time10msCnt = 0;

	u8Time10msCnt++;
	if(u8Time10msCnt < 5)
	{
		return;
	}
	
	u8Time10msCnt = 0;
    if (0 == u8NJJ29c0InitStep)
    {
    	Joker_Init_Status = 0xff;
        JOKER_RESET_0(); // ï¿½ï¿½Â·ï¿½ï¿½ï¿½ï¿½Í¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ü¿ï¿½ï¿½ï¿½
        JOKER_CSN_1();
        u8NJJ29c0InitStep++;
    }
    else if (1 == u8NJJ29c0InitStep)
    {
    	JOKER_RESET_1();
		u8NJJ29c0InitStep++;
    }
    else if (2 == u8NJJ29c0InitStep)
    {
        status = JOKER_ClearPorStatus(PORFC_ALL);
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (3 == u8NJJ29c0InitStep)
    {
        status = JOKER_ConfigDevice();
        if (status != 0)
        {
       		Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (4 == u8NJJ29c0InitStep)
    {
        status = JOKER_ClearProtStatus(PROTFCM_ALL, DRPFCM_ALL);
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (5 == u8NJJ29c0InitStep)
    {
        status = JOKER_ClearOpStatus(OPFCM_ALL);
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (6 == u8NJJ29c0InitStep)
    {
        status = JOKER_SetOpMask(OPFCM_ALL);
        if (status != 0)
        {
      		Joker_Init_Fail_Num = u8NJJ29c0InitStep;	
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (7 == u8NJJ29c0InitStep)
    {
        status = JOKER_ConfigBoost();
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (8 == u8NJJ29c0InitStep)
    {
        status = JOKER_ConfigLfDriver(u8JokerInitLfAntDrvCur, u8JokerInitRfAntDrvCur, u8JokerInitInCarAntDrvCur);
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (9 == u8NJJ29c0InitStep)
    {
        status = JOKER_ConfigImmoDriver();
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (10 == u8NJJ29c0InitStep)
    {
        status = JOKER_ConfigImmoBPLM();
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (11 == u8NJJ29c0InitStep)
    {
        status = JOKER_ConfigImmoReceiver();
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }
    else if (12 == u8NJJ29c0InitStep)
    {
        status = JOKER_SetImmoMask();
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
        }
    }

    else if (13 == u8NJJ29c0InitStep)
    {
        status = JOKER_MeasAntImp((drpi_t)(DR2P | DR3P | DR4P)); //(DRP_ALL);
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
            u8NJJ29c0InitStep++;
            u8InitWaitMaxTimeCnt = 7;
        }
    }
    else if (14 == u8NJJ29c0InitStep)
    {
        status = JOKER_GetOpStatus((opfcm_t *)&_c0_temp[0]);

        if (((status & 0x08) == 0x08) && ((_c0_temp[0] & 0x02) == 0x02))
        {
            u8NJJ29c0InitStep++;
        }

        if (u8InitWaitMaxTimeCnt > 0)
        {
            u8InitWaitMaxTimeCnt--;
        }
        else
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
    }
    else if (15 == u8NJJ29c0InitStep)
    {
        (void)JOKER_GetAntImp(DRP_ALL, _c0_temp);
        u8NJJ29c0InitStep++;
    }
    else if (16 == u8NJJ29c0InitStep)
    {
        status = JOKER_ClearOpStatus(OPFCM_ALL);
        if (status != 0)
        {
        	Joker_Init_Fail_Num = u8NJJ29c0InitStep;
            u8NJJ29c0InitStep = 0xff;
        }
        else
        {
             u8NJJ29c0InitStep++;
        }
    }
	else if (17 == u8NJJ29c0InitStep)
    {
        JOKER_StartSleep();
		
		u8InitMaxCnt = 0;
        u8NJJ29c0InitStep = 0;
        Joker_Init_Status = 1;
    }
    else
    {
    	u8NJJ29c0InitStep = 0;
		u8InitMaxCnt++;
        if (u8InitMaxCnt >= 3)
        {
            u8InitMaxCnt = 0;
            Joker_Init_Status = 0;
        }
    }
}

uint8_t cb_crccount(uint8_t *ptr, uint8_t len)
{
    uint8_t i;
    uint8_t crc = 0;
    while (len--)
    {
        crc ^= *ptr++;
        for (i = 0; i > 8; i--)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x31;
            else
                crc = (crc << 1);
        }
    }
    return (crc);
}

/**
 * \brief     Set_DataContent_RSSI
 *
 * \retval    none
 *
 * \note      SPI_CMD:SET_LF_DATA
 */
void njj29c0_set_datacontent_cb(uint8_t coordinate)
{
     uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = DATA_ID_DATA_CB; /**< \brief DATAID  : ï¿½ï¿½ï¿½Ý¶Î±ï¿½Ê¶(LF DATA) */
    u8CmdBuff[1] = 0x00;            /**< \brief DATACFG : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ï¿½Ã£ï¿½manchester */
    u8CmdBuff[2] = 0x18;            /**< \brief DATALEN : ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿½16(bit) */
    u8CmdBuff[3] = 0x03;            /**< \brief FT      : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */
    u8CmdBuff[4] = coordinate;      /**< \brief DATA0   : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */
    u8CmdBuff[5] = cb_crccount(&u8CmdBuff[3], 2);

    while (_JOKER_CmdTransmit(SET_LF_DATA_CMD, u8CmdBuff, u8ResBuff, 0x08, 500) != 0)
    {
        i++;
        if (i == 3)
            return;
    }
}

/**
 * \brief     Set_DataContent_RSSI
 *
 * \retval    none
 *
 * \note      SPI_CMD:SET_LF_DATA
 */
void njj29c0_set_datacontent_check(void)
{
    uint8_t i;

    i = 0x00;
    u8CmdBuff[0] = DATA_ID_DATA_CHECK; /**< \brief DATAID  : ï¿½ï¿½ï¿½Ý¶Î±ï¿½Ê¶(LF DATA) */
    u8CmdBuff[1] = 0x00;               /**< \brief DATACFG : ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ï¿½ï¿½Ã£ï¿½manchester */
    u8CmdBuff[2] = 0x10;               /**< \brief DATALEN : ï¿½ï¿½ï¿½Ý³ï¿½ï¿½È£ï¿½16(bit) */
    u8CmdBuff[3] = 0x05;               /**< \brief FT      : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */
    u8CmdBuff[4] = 0x01;               /**< \brief DATA0   : ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý£ï¿½ï¿½ï¿½Î»ï¿½È·ï¿½ */

    while (_JOKER_CmdTransmit(SET_LF_DATA_CMD, u8CmdBuff, u8ResBuff, 0x07, 500) != 0)
    {
        i++;
        if (i == 3)
            return;
    }
}

/*********************************************************************************************************
  EoF
*********************************************************************************************************/
