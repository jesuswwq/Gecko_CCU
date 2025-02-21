
#ifndef __NJJ29C0_CFG_H__
#define __NJJ29C0_CFG_H__

/*********************************************************************************************************
  Includes
*********************************************************************************************************/
#include "platform_cfg.h"

/*********************************************************************************************************
  Constants and macros
*********************************************************************************************************/
/*--------------------------------------------------------------------------------------------------------
	NJJ29C0 SPIï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
 *------------------------------------------------------------------------------------------------------*/
/* General commands */
#define GET_VERSION_CMD 0xF0	 /**< \brief Read device version identifiers */
#define CONFIG_DEVICE_CMD 0x09	 /**< \brief Configure device parameters */
#define CONFIG_ADVANCED_CMD 0xD2 /**< \brief Configure advanced device parameters */

/* Device reset */
#define SET_POR_CMD 0xF4		  /**< \brief Perform a power on reset */
#define GET_POR_STATUS_CMD 0x07	  /**< \brief Read device power on reset status flags */
#define CLEAR_POR_STATUS_CMD 0x08 /**< \brief Clear POR status flag which is set after device reset */

/* Operating states */
#define START_SLEEP_CMD 0x50		/**< \brief Set the device in SLEEP state */
#define START_SLEEP_FORCED_CMD 0x4F /**< \brief Set the device in SLEEP state independent of the device state */

/* Boost convert */
#define CONFIG_BOOST_CMD 0x45 /**< \brief Configure boost converter */

/* LF antenna driver */
#define CONFIG_LF_DRIVER_CMD 0x40 /**< \brief Configure LF driver mode, baudrate, current, dithering, freq. shift */

/* Parallel low current driver */
#define CONFIG_LC_DRIVER_CMD 0x44 /**< \brief Configure low current LF driver */

/* Telegram sequencer */
#define SET_LF_DATA_CMD 0x41			/**< \brief Store data in RAM to be transmitted via the main drivers */
#define SET_LC_DATA_CMD 0x47			/**< \brief Store data in RAM to be transmitted via the low current drivers */
#define START_LF_TRANSMIT_CMD 0x42		/**< \brief Start LF transmission using pre-loaded configuration and data */
#define START_LF_TRANSMIT_DATA_CMD 0x46 /**< \brief Start LF transmission using pre-loaded configuration and attached data */
#define STOP_LF_TRAMSMIT_CMD 0x43		/**< \brief Stop LF transmission */

/* Immobilizer */
#define CONFIG_IMMO_DRIVER_CMD 0x60	   /**< \brief Configure immobilizer antenna driver */
#define CONFIG_IMMO_BPLM_CMD 0x61	   /**< \brief Configure binary pulse length modulator timings */
#define CONFIG_IMMO_RECEIVER_CMD 0x62  /**< \brief Configure immobilizer receiver*/
#define START_IMMO_CMD 0x63			   /**< \brief Start immo driver and transmit constant carrier signal */
#define STOP_IMMO_CMD 0x64			   /**< \brief Stop constant carrier signal transmitted by immo driver */
#define START_IMMO_TRANSCEIVE_CMD 0x65 /**< \brief Write to transponder and read response from transponder */
#define START_IMMO_TRANSMIT_CMD 0x66   /**< \brief Write data to transponder */
#define GET_IMMO_RESPONSE_CMD 0x67	   /**< \brief Read data from receive data buffer */
#define CLEAR_IMMO_STATUS_CMD 0x68	   /**< \brief Clear immobilizer status flags */
#define SET_IMMO_MASK_CMD 0x69		   /**< \brief Mask immobilizer status flags to trigger INT pin */

/* Antenna impedance */
#define MEAS_ANT_IMP_CMD 0x48		   /**< \brief Measure antenna impedance values (variant 1) */
#define MEAS_ANT_IMP_ADVANCED_CMD 0xD5 /**< \brief Measure antenna impedance values (variant 2) */
#define SET_ANT_IMP_CMD 0x49		   /**< \brief Set antenna impedance values */
#define GET_ANT_IMP_CMD 0x4A		   /**< \brief Read antenna impedance values */
#define GET_ANT_IMP_EFFECTIVE_CMD 0xD4 /**< \brief Read the effective antenna impedance values */

/* Device protection */
#define GET_PROT_STATUS_CMD 0x58   /**< \brief Read device protection status flags (malfunctions) */
#define CLEAR_PROT_STATUS_CMD 0x59 /**< \brief Clear device protection status flags */
#define SET_PROT_MASK_CMD 0x5A	   /**< \brief Mask device protection flags to trigger INT pin */

/* Device diagnostics */
#define START_DIAG_CMD 0x4C		   /**< \brief Start diagnostics of boost converter, LF driver & antennas */
#define GET_DIAG_STATUS_CMD 0x4D   /**< \brief Read device diagnostics status flags */
#define CLEAR_DIAG_STATUS_CMD 0x4E /**< \brief Clear device diagnostics status flags */

/* SPI interface */
#define CONFIG_SPI_CMD 0xF1 /**< \brief Configure the SPI interface */
#define ECHO_SPI_CMD 0x01	/**< \brief Check proper physical operation of the SPI link */

/* Wake-up ports */
#define CONFIG_WUP_CMD 0x10		  /**< \brief Configure wake-up ports */
#define GET_WUP_STATUS_CMD 0x13	  /**< \brief Read wake-up status flags */
#define CLEAR_WUP_STATUS_CMD 0x14 /**< \brief Clear wake-up status flags */
#define SET_WUP_MASK_CMD 0x15	  /**< \brief Mask wake-up status flags to trigger INT pin */

/* WUP event triggered polling */
#define CONFIG_WUP_POLLING_CMD 0x51 /**< \brief Configure driver sequence for wake-up via wake-up port */

/* Timer triggered polling */
#define CONFIG_TIMER_POLLING_CMD 0x52 /**< \brief Configure polling timer and polling scheme */
#define START_TIMER_POLLING_CMD 0x53  /**< \brief Sets the device in SLEEP state and starts timer triggered polling */

/* Temperature indication */
#define CONFIG_TEMP_CMD 0x18	   /**< \brief Configure threshold for temperature warning */
#define GET_TEMP_STATUS_CMD 0x19   /**< \brief Read temperature status flag */
#define CLEAR_TEMP_STATUS_CMD 0x1A /**< \brief Clear temperature status flag */
#define SET_TEMP_MASK_CMD 0x1B	   /**< \brief Mask temperature status flag to trigger INT pin */

/* Operation status flags */
#define GET_OP_STATUS_CMD 0x55	 /**< \brief Read operation status flags */
#define CLEAR_OP_STATUS_CMD 0x56 /**< \brief Clear operation status flags */
#define SET_OP_MASK_CMD 0x57	 /**< \brief Mask operation status flags to trigger INT pin */

/* Program download */
#define DOWNLOAD_PROG_CMD 0x30 /**< \brief Stores program in RAM for execution */
#define START_PROG_CMD 0x31	   /**< \brief Executes program downloaded in RAM */
#define GET_PROG_SIG_CMD 0x33  /**< \brief Read program signature */

// HT3_REFRESH?ï¿½ï¿½HT3_SOFT_RST?ï¿½ï¿½ï¿½ï¿½???ï¿½ï¿½?????ï¿½ï¿½DDï¿½ï¿½ï¿???ï¿½ï¿½ï¿½ï¿½?ï¿½ï¿½ï¿½ï¿½?ï¿½ï¿½???5??ï¿½ï¿½DDï¿½ï¿½
// WAIT State
#define HT3_START_AUTH 0xE0
#define HT3_XMA_CFG 0xE8
#define HT3_XMA_WAIT 0x40
#define HT3_USER 0x80
#define HT3_TEST 0xF1
#define HT3_REFRESH 0x00
#define HT3_SOFT_RST 0x80
#define HT3_GET_IDE64 0x30

// AUTHORIZED State
#define HT3_READ_PAGE 0xC0
#define HT3_WRITE_PAGE 0x80
#define HT3_XMA 0x00
#define HT3_SOFT_RST 0x80
#define HT3_REFRESH 0x00

// XMA State
#define HT3_READ_PAGE 0xC0
#define HT3_WRITE_PAGE 0x80
#define HT3_SEL_BLOCK 0x40
#define HT3_XMA 0x00
#define HT3_SOFT_RST 0x80
#define HT3_REFRESH 0x00

// XMA CFG State
#define HT3_READ_CFG 0x40
#define HT3_WRITE_CFG_M 0x80
#define HT3_WRITE_CFG_S 0xC0
#define HT3_SOFT_RST 0x80
#define HT3_REFRESH 0x00

#define AES_GET_IDE64 0x31
#define AES_START_AUTH 0xF0
#define AES_XMA_WAIT 0x40
#define AES_SOFT_RST 0x80
// Data ID
#define DATA_ID_PREMABLE 0x00
#define DATA_ID_CV 0x01

#define DATA_ID_WUP1 0x02
#define DATA_ID_WUP2 0x03

#define DATA_ID_DATA_PE 0x04
#define DATA_ID_DATA_RSSI 0x05
#define DATA_ID_DATA_CB 0x06
#define DATA_ID_DATA_CHECK 0x07

#define DATA_ID_CC_5 0x08
#define DATA_ID_CC_ALL 0x09
#define DATA_ID_CC_30 0x0A
#define HT3_READ_PAGE 0xC0
#define HT3_WRITE_PAGE 0x80

/*--------------------------------------------------------------------------------------------------------
	NJJ29C0 IOï¿½ï¿½Øºê¶¨ï¿½ï¿?
 *------------------------------------------------------------------------------------------------------*/
/* RESET IO */
#define JOKER_RESET_0() NJJ29C0_RSTN_HIGH()
#define JOKER_RESET_1() NJJ29C0_RSTN_LOW()

/* CSN IO */
#define JOKER_CSN_0() NJJ29C0_CSN_LOW()
#define JOKER_CSN_1() NJJ29C0_CSN_HIGH()

/* IRQ IO */
#define JOKER_IRQ() NJJ29C0_INTN_LEVEL

/*********************************************************************************************************
  Local types
*********************************************************************************************************/
/*--------------------------------------------------------------------------------------------------------
	NJJ29C0 SPIï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã¶ï¿½ï¿½
 *------------------------------------------------------------------------------------------------------*/
// Antenna Bit Coding
typedef enum DRPI
{
	DR1P = 0x01,	/**< \brief Select LF driver 1 */
	DR2P = 0x02,	/**< \brief Select LF driver 2 */
	DR3P = 0x04,	/**< \brief Select LF driver 3 */
	DR4P = 0x08,	/**< \brief Select LF driver 4 */
	DR5P = 0x10,	/**< \brief Select LF driver 5 */
	DR6P = 0x20,	/**< \brief Select LF driver 6 */
	DRP_ALL = 0x3f, /**< \brief Select LF driver ALL */
	DRP_NULL = 0x00 /**< \brief Select LF driver NULL */
} drpi_t;

// LF Driver IDs
typedef enum DRIDI
{
	DRID1 = 0x00, /**< \brief Antenna output OUT1 */
	DRID2 = 0x01, /**< \brief Antenna output OUT2 */
	DRID3 = 0x02, /**< \brief Antenna output OUT3 */
	DRID4 = 0x03, /**< \brief Antenna output OUT4 */
	DRID5 = 0x04, /**< \brief Antenna output OUT5 */
	DRID6 = 0x05  /**< \brief Antenna output OUT6 */
} dridi_t;

// PORFC
typedef enum PORFC
{
	SFC_LOWBAT = 0x01, /**< \brief Low supply voltage */
	SFC_RSTEXT = 0x02, /**< \brief External Reset */
	SFC_RSTSW = 0x04,  /**< \brief Software Reset */
	SFC_CLKEXT = 0x08, /**< \brief External Clock Error */
	SFC_WD = 0x10,	   /**< \brief Watchdog Reset */
	SFC_RAMERR = 0x20, /**< \brief RAM parity error */
	SFC_CPUERR = 0x40, /**< \brief CPU Access Error */
	PORFC_ALL = 0x7F
} porfc_t;

// PROTFC
typedef enum PROTFCM
{
	SFCM_BATOV = 0x01,	/**< \brief Battery overvoltage status */
	SFCM_BATUN = 0x02,	/**< \brief Battery undervoltage status */
	SFCM_TEMPOV = 0x04, /**< \brief Over temperature status */
	SFCM_BC = 0x08,		/**< \brief Boost converter status */
	SFCM_DRSUP = 0x10,	/**< \brief Driver supply status */
	PROTFCM_ALL = 0x1F,
	PROTFCM_DIS = 0x00
} protfcm_t;

// DRPFC
typedef enum DRPFCM
{
	SFCM_DR1P = 0x01, /**< \brief LF driver 1 */
	SFCM_DR2P = 0x02, /**< \brief LF driver 2 */
	SFCM_DR3P = 0x04, /**< \brief LF driver 3 */
	SFCM_DR4P = 0x08, /**< \brief LF driver 4 */
	SFCM_DR5P = 0x10, /**< \brief LF driver 5 */
	SFCM_DR6P = 0x20, /**< \brief LF driver 6 */
	DRPFCM_ALL = 0x3F,
	DRPFCM_DIS = 0x00
} drpfcm_t;

// DIAGPAR
typedef enum DIAGPAR
{
	DIAG_SHTBATGND = 0x01, /**< \brief LF driver DC short to VBAT/GND diagnostics */
	DIAG_SHTINTRA = 0x02,  /**< \brief LF driver DC intra antenna short diagnostics */
	DIAG_SHTINTER = 0x04,  /**< \brief LF driver DC inter antenna short diagnostics */
	DIAG_POWER = 0x08,	   /**< \brief Power path diagnostics */
	DIAG_OPN = 0x18		   /**< \brief AC antenna open diagnostics */
} diag_par_t;

// SUPFC
typedef enum SUPFC
{
	SFC_DIAGBC = 0x01,	  /**< \brief Diagnostic result of boost converter */
	SFC_DIAGDRSUP = 0x02, /**< \brief Diagnostic result of device supplies */
	SUPFC_ALL = 0x03
} supfc_t;

// DIAGFC
typedef enum DIAGFC
{
	SFC_SHTGND = 0x01, /**< \brief Tx short to GND */
	SFC_SHTBAT = 0x02, /**< \brief Tx short to battery */
	SFC_OPN = 0x04,	   /**< \brief Tx open antenna connection */
	SFC_SHTANT = 0x08, /**< \brief Tx intra or inter antenna-short */
	DIAGFC_ALL = 0x0F
} diagfc_t;

// WUPFC
typedef enum WUPFCM
{
	SFCM_WUP1 = 0x01, /**< \brief Port 1 wake-up flag/clear/mask */
	SFCM_WUP2 = 0x02, /**< \brief Port 2 wake-up flag/clear/mask */
	SFCM_WUP3 = 0x04, /**< \brief Port 3 wake-up flag/clear/mask */
	SFCM_WUP4 = 0x08, /**< \brief Port 4 wake-up flag/clear/mask */
	SFCM_WUP5 = 0x10, /**< \brief Port 5 wake-up flag/clear/mask */
	SFCM_WUP6 = 0x20, /**< \brief Port 6 wake-up flag/clear/mask */
	WUPFCM_ALL = 0x3F,
	WUPFCM_DIS = 0x00
} wupfcm_t;

// TEMPFCM
typedef enum TEMPFCM
{
	SFCM_TWARN = 0x01,
	TEMPFCM_DIS = 0x00
} tempfcm_t;

// OPFCM
typedef enum OPFCM
{
	OPFCM_DIAG = 0x01,	  /**< \brief Diagnostics ready flag/clear/mask */
	OPFCM_IMPMEAS = 0x02, /**< \brief Impedance measurement ready flag/clear/mask */
	OPFCM_TXREADY = 0x04, /**< \brief LF transmission ready flag/clear/mask */
	OPFCM_RXREADY = 0x08, /**< \brief Immo receiver ready flag/clear/mask */
	OPFCM_ALL = 0x0F,
	OPFCM_DIS = 0x00
} opfcm_t;

// STAT
typedef enum STAT
{
	SF_POR = 0x01,	   /**< \brief Device reset status */
	SF_PROT = 0x02,	   /**< \brief Protection status */
	SF_WUP = 0x04,	   /**< \brief Wake-up status */
	SF_OP = 0x08,	   /**< \brief Operation status */
	SF_PAR = 0x10,	   /**< \brief Parameter interpretation status */
	SF_CRC = 0x20,	   /**< \brief CRC status */
	SF_LAST_OP = 0x40, /**< \brief LF field activation status */
	SF_CMD = 0x80,	   /**< \brief Command code interpretation status */
	SF_SPI = 0xFF	   /**< \brief SPI status */
} stat_t;

// carrier
typedef enum CARRIER
{
	CARRIER_OFF = 0x06,
	CARRIER_CON = 0x07
} carrier_t;

typedef struct njj29c0_version
{
	uint16_t PI;
	uint16_t HW;
	uint16_t RM;
	uint16_t RAM;
} njj29c0_version_t;

/*********************************************************************************************************
  Global functions prototypes
*********************************************************************************************************/
/*--------------------------------------------------------------------------------------------------------
	General Commands
 *------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_GetVersion
** @note	SPI_CMD:GET_VERSION
** @param	psVersion	: Point to the buffer
** @retval	stat_t
*********************************************************************************************************/
stat_t JOKER_GetVersion(njj29c0_version_t *psVersion);

/*********************************************************************************************************
** @brief	JOKER_ConfigDevice
** @note	SPI_CMD:CONFIG_DEVICE
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigDevice(void);

/*********************************************************************************************************
** @brief	JOKER_ConfigAdvanced
** @note	SPI_CMD:CONFIG_DEVICE
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigAdvanced(void);

/*--------------------------------------------------------------------------------------------------------
	Device reset
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_SetPor
** @note	Triggers a power on reset
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetPor(void);

/*********************************************************************************************************
** @brief	JOKER_GetPorStatus
** @note	SPI_CMD:GET_POR_STATUS
** @param	u8PorF: signalizes the cause for the last power on reset event @PORFC
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetPorStatus(uint8_t *u8PorF);

/*********************************************************************************************************
** @brief	JOKER_ClearPorStatus
** @note	SPI_CMD:CLEAR_POR_STATUS
** @param	u8ProC: specifies the device reset status flags to be cleared. @PORFC
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearPorStatus(uint8_t u8ProC);
/*--------------------------------------------------------------------------------------------------------
	Operating States
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_StartSleep
** @note	SPI_CMD:START_SLEEP_CMD
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartSleep(void);

/*********************************************************************************************************
** @brief	JOKER_StartSleepForced
** @note	SPI_CMD:START_SLEEP_FORCED_CMD
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartSleepForced(void);

/*********************************************************************************************************
** @brief	JOKER_WakeUp
** @note
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
void JOKER_WakeUp(void);

/*--------------------------------------------------------------------------------------------------------
	Boost Convert
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigBoost
** @note	SPI_CMD:CONFIG_BOOST
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigBoost(void);

/*--------------------------------------------------------------------------------------------------------
	LF Antenna Driver
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigLfDriver
** @note	SPI_CMD:CONFIG_LF_DRIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
// stat_t JOKER_ConfigLfDriver(void);
stat_t JOKER_ConfigLfDriver(uint8_t ch2_CURSi, uint8_t ch3_CURSi, uint8_t ch4_CURSi);

/*--------------------------------------------------------------------------------------------------------
	Parallel Low Current Driver
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigLcDriver
** @note	SPI_CMD:CONFIG_LC_DRIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigLcDriver(void);

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
stat_t JOKER_SetLfData(uint8_t u8DataIndex, uint8_t u8BytesLen, uint8_t *pu8DataBuff);

stat_t JOKER_SetLfNrz(uint8_t u8DataIndex, uint8_t u8BytesLen, uint8_t *pu8DataBuff);

/*********************************************************************************************************
** @brief	JOKER_SetLfCarrier
** @note	SPI_CMD:SET_LF_DATA
** @param	u8Index  : Data Identifiers [0..59]
** @param	sCarrier :
** @param	u8Time   :
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetLfCarrier(uint8_t u8Index, carrier_t sCarrier, uint8_t u8Time);

/*********************************************************************************************************
** @brief	JOKER_StartLfTransmit
** @note	SPI_CMD:START_LF_TRANSMIT
** @param	sLfDRPi @DRPI
** @param	sLcDRPi @DRPI
** @param	u8BuffLen
** @param	pu8IndexBuff
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartLfTransmit(drpi_t sLfDRPi, drpi_t sLcDRPi, uint8_t u8BuffLen, uint8_t *pu8IndexBuff);

/*********************************************************************************************************
** @brief	JOKER_StopLfTransmit
** @note	SPI_CMD:STOP_LF_TRAMSMIT
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StopLfTransmit(void);

/*--------------------------------------------------------------------------------------------------------
	Immobilizer
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigImmoDriver
** @note	SPI_CMD:CONFIG_IMMO_DRIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigImmoDriver(void);

/*********************************************************************************************************
** @brief	JOKER_ConfigImmoBPLM
** @note	SPI_CMD:CONFIG_IMMO_BPLM
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigImmoBPLM(void);

/*********************************************************************************************************
** @brief	JOKER_ConfigImmoReceiver
** @note	SPI_CMD:CONFIG_IMMO_RECEIVER
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigImmoReceiver(void);

/*********************************************************************************************************
** @brief	JOKER_StartImmo
** @note	SPI_CMD:START_IMMO
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartImmo(void);

/*********************************************************************************************************
** @brief	JOKER_StopImmo
** @note	SPI_CMD:STOP_IMMO
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StopImmo(void);

/*********************************************************************************************************
** @brief	JOKER_StartImmoTransmit
** @note	SPI_CMD:START_IMMO_TRANSMIT_CMD
** @param	pu8TagData
** @param	u8BitsLen
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartImmoTransmit(uint8_t *pu8TagData, uint8_t u8BitsLen);

/*********************************************************************************************************
** @brief	JOKER_StartImmoTransceive
** @note	SPI_CMD:START_IMMO_TRANSCEIVE
** @param	pu8TagData
** @param	u8TagBitsLen
** @param	u8ResBitsLen
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartImmoTransceive(uint8_t *pu8TagData, uint8_t u8TagBitsLen, uint16_t u8ResBitsLen);

/*********************************************************************************************************
** @brief	JOKER_GetImmoResponse
** @note	SPI_CMD:GET_IMMO_RESPONSE
** @param	pu8ResData
** @param	u8ResBitsLen
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetImmoResponse(uint8_t *pu8ResData, uint16_t u8ResBitsLen);

/*********************************************************************************************************
** @brief	JOKER_ClearImmoStatus
** @note	SPI_CMD:CLEAR_IMMO_STATUS
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearImmoStatus(void);

/*********************************************************************************************************
** @brief	JOKER_SetImmoMask
** @note	SPI_CMD:SET_IMMO_MASK
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetImmoMask(void);

/*--------------------------------------------------------------------------------------------------------
	Antenna Parameter
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_MeasAntImp
** @note	SPI_CMD:MEAS_ANT_IMP
** @param	sDRPi ï¿½ï¿½Selects the LF driver for the antenna impedance measurement.
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_MeasAntImp(drpi_t sDRPi);

/*********************************************************************************************************
** @brief	JOKER_MeasAntImpAdvanced
** @note	SPI_CMD:MEAS_ANT_IMP_ADVANCED
** @param	sDRPi ï¿½ï¿½Selects the LF driver for the antenna impedance measurement.
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_MeasAntImpAdvanced(drpi_t sDRPi);

/*********************************************************************************************************
** @brief	JOKER_SetAntImp
** @note	SPI_CMD:SET_ANT_IMP
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetAntImp(void);

/*********************************************************************************************************
** @brief	JOKER_GetAntImp
** @note	SPI_CMD:Get_Ant_Imp
** @param	sDRPi	  : Selects the LF driver. Selecting more than one driver is possible.
** @param	pu8AntImp : The requested actual antenna impedance values
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetAntImp(drpi_t sDRPi, uint8_t *pu8AntImp);

/*********************************************************************************************************
** @brief	JOKER_GetAntImp
** @note	SPI_CMD:GET_ANT_IMP_EFFECTIVE
** @param	sDRPi	  : Selects the LF driver. Selecting more than one driver is possible.
** @param	pu8AntImp : The requested actual antenna impedance values
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetAntImpEff(drpi_t sDRPi, uint8_t *pu8AntImp);

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
stat_t JOKER_GetPortStatus(protfcm_t *psPortF, drpfcm_t *psDrpF);

/*********************************************************************************************************
** @brief	JOKER_ClearProtStatus
** @note	SPI_CMD:GET_PROT_STATUS_CMD
** @param	sProtC : Clears the status flags. @PROTFCM
** @param	sDrpC  : Specifies the drivers which flags to be cleared. @DRPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearProtStatus(protfcm_t sProtC, drpfcm_t sDrpC);

/*********************************************************************************************************
** @brief	JOKER_SetProtMask
** @note	SPI_CMD:SET_PROT_MASK
** @param	sProtM : provides the mask to enable the INT pin if a device protection flag is set. @PROTFCM
** @param	sDrpM  : masks the status flags of the LF drivers. @DRPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetProtMask(protfcm_t sProtM, drpfcm_t sDrpM);

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
stat_t JOKER_StartDiag(drpi_t sDRPi, diag_par_t sDiagPar);

/*********************************************************************************************************
** @brief	JOKER_GetDiagStatus
** @note	SPI_CMD:GET_DIAG_STATUS
** @param	sDRPi : Specify the drivers for diagnostics. @DRPI
** @param	psSupF : Contains the diagnosis results for the boost converter and for the LF driver supply. @SUPFC
** @param	psDiagF : Contain the diagnostic results for the respective LF driver DRIDi @DIAGFC
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetDiagStatus(drpi_t sDRPi, supfc_t *psSupF, uint8_t *psDiagF);

/*********************************************************************************************************
** @brief	JOKER_ClearDiagStatus
** @note	SPI_CMD:CLEAR_DIAG_STATUS
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearDiagStatus(void);

/*--------------------------------------------------------------------------------------------------------
	SPI Interface
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigSpi
** @note	SPI_CMD:CONFIG_SPI
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigSpi(void);

/*--------------------------------------------------------------------------------------------------------
	Wake-up Ports
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigWup
** @note	SPI_CMD:CONFIG_WUP
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigWup(void);

/*********************************************************************************************************
** @brief	JOKER_GetWupStatus
** @note	SPI_CMD:GET_WUP_STATUS
** @param	psWupF:Signalizes wake-up events pending that were generated by the corresponding wake-up inputs. @WUPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetWupStatus(wupfcm_t *psWupF);

/*********************************************************************************************************
** @brief	JOKER_ClearWupStatus
** @note	SPI_CMD:CLEAR_WUP_STATUS
** @param	sWupC:Specifies the wake-up flag to be cleared. @WUPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearWupStatus(wupfcm_t sWupC);

/*********************************************************************************************************
** @brief	JOKER_SetWupMask
** @note	SPI_CMD:SET_WUP_MASK
** @param	sWupM:Provides the mask to enable the INT pin if a wake-up event occurs. @WUPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetWupMask(wupfcm_t sWupM);

/*--------------------------------------------------------------------------------------------------------
	WUP event triggered polling
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigWupPolling
** @note	SPI_CMD:CONFIG_WUP_POLLING
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigWupPolling(void);

/*--------------------------------------------------------------------------------------------------------
	Timer triggered polling
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigTimerPolling
** @note	SPI_CMD:CONFIG_TIMER_POLLING
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigTimerPolling(void);

/*********************************************************************************************************
** @brief	JOKER_StartTimerPolling
** @note	SPI_CMD:START_TIMER_POLLING
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_StartTimerPolling(void);

/*--------------------------------------------------------------------------------------------------------
	Temperature indication
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_ConfigTemp
** @note	SPI_CMD:CONFIG_TEMP
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ConfigTemp(void);

/*********************************************************************************************************
** @brief	JOKER_GetTempStatus
** @note	SPI_CMD:GET_TEMP_STATUS
** @param	psTempF : The temperature warning flag.
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetTempStatus(tempfcm_t *psTempF);

/*********************************************************************************************************
** @brief	JOKER_ClearTempStatus
** @note	SPI_CMD:CLEAR_TEMP_STATUS
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearTempStatus(void);

/*********************************************************************************************************
** @brief	JOKER_SetTempMask
** @note	SPI_CMD:SET_TEMP_MASK
** @param	sTempM : The mask to enable the INT pin if the temperature warning flag is set @TEMPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetTempMask(tempfcm_t sTempM);

/*--------------------------------------------------------------------------------------------------------
	Operation status flags
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_GetOpStatus
** @note	SPI_CMD:GET_OP_STATUS
** @param	psOpF : @OPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_GetOpStatus(opfcm_t *psOpF);

/*********************************************************************************************************
** @brief	JOKER_ClearOpStatus
** @note	SPI_CMD:CLEAR_OP_STATUS
** @param	sOpC : @OPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_ClearOpStatus(opfcm_t sOpC);

/*********************************************************************************************************
** @brief	JOKER_SetOpMask
** @note	SPI_CMD:SET_OP_STATUS
** @param	sOpM : @OPFCM
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetOpMask(opfcm_t sOpM);

/*--------------------------------------------------------------------------------------------------------
	User Preset Lf Data
 *-------------------------------------------------------------------------------------------------------*/
/*********************************************************************************************************
** @brief	JOKER_SetPremable
** @note	SPI_CMD:SET_LF_DATA
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetPremable(void);

/*********************************************************************************************************
** @brief	JOKER_SetCodeViolation
** @note	SPI_CMD:SET_LF_DATA
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
stat_t JOKER_SetCodeViolation(void);

/*********************************************************************************************************
** @brief	JOKER_Init
** @note	Initializes the njj29C0
** @param	none
** @retval	stat_t Status flags
*********************************************************************************************************/
void JOKER_Init(void);
uint8 NJJ29C0_COM_ReadWriteFrame(uint8 *sendFrame, uint8 *recvFrame, uint8 sendFrameSize, uint16 waitdelay);

uint8_t _JOKER_Crc8Algorithm(uint8_t *pu8Data, uint8_t u8BytesLen);

stat_t Peps_Cfg_Joker_Tx_Message(uint8_t Ant1,uint8_t DataId_Len1, uint8_t *Lf_Ant1_DataIdx,
											  uint8_t Ant2,uint8_t DataId_Len2, uint8_t *Lf_Ant2_DataIdx,
											  uint8_t Ant3,uint8_t DataId_Len3, uint8_t *Lf_Ant3_DataIdx);

stat_t NJJ29C0_ConfigTimerPolling(uint8_t drpi, uint16_t ptime, uint8_t len, uint8_t *dataid);

stat_t Peps_Fun_ConfigTimerPolling(uint8_t Cmd, uint8_t Incar_Ant, uint16_t ptime0, uint8_t LfDoor_Ant, uint16_t ptime1, uint8_t RfDoor_Ant, uint16_t ptime2);


stat_t WelcomeGuest_ConfigTimerPollingOne(uint8_t Incar_Ant,uint16_t ptime0, uint8_t LfDoor_Ant,uint16_t ptime1, uint8_t RfDoor_Ant,uint16_t ptime2);

stat_t WelcomeGuest_ConfigTimerPollingTwo(uint8_t wakeid_num, uint8_t drpi0, uint16_t ptime0, uint8_t drpi1, uint16_t ptime1, uint8_t Carrier_OnOff);

stat_t WelcomeGuest_ConfigTimerPollingWakeUp(uint8_t drpi,uint16_t ptime);

void WakeUp_JOKER(void);

stat_t WelcomeGuest_Unlock_PollingWakeUp(uint8_t drpi0,uint8_t drpi1,uint16_t ptime);

void njj29c0_set_datacontent_cb(uint8_t coordinate);
void njj29c0_set_datacontent_check(void);

#endif

/*********************************************************************************************************
  EoF
*********************************************************************************************************/
