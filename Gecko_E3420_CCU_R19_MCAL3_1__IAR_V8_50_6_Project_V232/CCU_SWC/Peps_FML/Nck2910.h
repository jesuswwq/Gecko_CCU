// Modification History
// created by ZhenJinHong, 2017/06/28 ,GuangZhou, base on RCI V1.1


#ifndef __NCK2910_H
#define __NCK2910_H

#include <stdint.h>
#include "platform_cfg.h"

#define LZ_COM_TIMEOUT_STEP_US         	20U

#define NCK2910_WORK_MODE				1U		//0->ConRx  1->POLLING  2->POLLING_ConRx(���Ѻ������������ģʽ)

/*********************************************************************************************************
  NCK2910 Event��غ궨��
*********************************************************************************************************/
/* Reboot Event */
#define	REBOOT_EVT_CMD								0x80
#define	REBOOT_REASON_POWER_ON_RST					0x00
#define REBOOT_REASON_WATCHDOG_OVERFLOW				0x01
#define REBOOT_REASON_BROWN_RESET					0x02
#define REBOOT_REASON_SOFTWARE_RESET				0x03
#define REBOOT_REASON_TX_BUFFER_FULL				0x05
#define REBOOT_REASON_IGNORED_INT_LINE				0x06
#define	REBOOT_REASON_INCOMPLETE_TRANSFER_RESET		0xF7
#define REBOOT_REASON_CRC_ERROR_RESET				0xF8
#define REBOOT_REASON_UNKNOWN_COMMAND_ERROR			0xF9
#define REBOOT_REASON_COMMAND_LENGTH_ERROR			0xFA
/* HeartBeat Event */
#define	HEART_BEAT_EVT_CMD							0x81
/* RF Event */
#define	RF_EVT_CMD									0x84
#define RF_EVT_TYPE_WUP_FOUND						0x00
#define RF_EVT_TYPE_FSYNC_FOUND						0x01
#define RF_EVT_TYPE_EOM								0x02
#define RF_EVT_TYPE_FSYNC_DURING_DATA				0x03
#define RF_EVT_TYPE_WUP_DURING_FSYNC				0x04
#define RF_EVT_TYPE_WUP_DURING_DATA					0x05
#define RF_EVT_TYPE_EOT								0x06
#define RF_EVT_TYPE_WUP_FAILED						0x81
#define RF_EVT_TYPE_FSYNC_FAILED					0x82
#define RF_EVT_TYPE_RF_STARTUP_FAILED				0xF1
#define RF_EVT_TYPE_RF_STARTUP_SUCCESS				0xF2
#define RF_EVT_TYPE_RF_RECEPTION_BUF_FULL			0xF3
#define RF_EVT_TYPE_PLL_UNLOCK_DETECTEDd			0xF4
#define RF_EVT_TYPE_TX_STARTUP_FAILED				0xF5
#define RF_EVT_TYPE_TX_STARTUP_SUCCESS				0xF6
#define RF_EVT_TYPE_RX_RESYNC						0xF7
/* RSSI Event */
#define	RSSI_EVT_CMD								0x85
/* Received Frame Event */
#define	RCV_FRAME_EVT_CMD							0x82


/*********************************************************************************************************
  NCK2910 Error Conditions��غ궨��
*********************************************************************************************************/
/* Communication Error */
#define EVT_INCOMPLETE_TRANSFER			0xF7
#define EVT_CRC_ERROR					0xF8
#define EVT_UNKNOWN_COMMAND				0xF9
#define EVT_LEN_ERROR					0xFA
/* Command Error */
#define STATUS_CMD_LENGTH_ERROR			0xD8
#define STATUS_CMD_PARAMETER_ERROR		0xD9
#define STATUS_CMD_HIGH_VOLTAGE_ERROR	0xDA
#define STATUS_CMD_EMPTY_BUFFER			0xDB
#define STATUS_CMD_ACCESS_DENIED		0xDC
#define STATUS_CMD_NOT_AVAILABLE		0xDD


/*********************************************************************************************************
  NCK2910 Device Configuration��غ궨��
*********************************************************************************************************/
#define DC_GET_STATUS_CMD				0x71
#define DC_GET_STATUS_SUB_CMD			0x03
#define DC_HASH_CMD						0x71
#define DC_HASH_SUB_CMD					0x0F
#define DC_COPY2NV_CMD					0x71
#define DC_COPY2NV_SUB_CMD				0x10
#define DC_COPY2RAM_CMD					0x71
#define DC_COPY2RAM_SUB_CMD				0x11
#define DC_PATCHRAM_CMD					0x71
#define DC_PATCHRAM_SUB_CMD				0xD0
#define DC_GET_CMD						0x71
#define DC_GET_SUB_CMD					0xF0
#define DC_SET_CMD						0x71
#define DC_SET_SUB_CMD					0xF6


/*********************************************************************************************************
  NCK2910 Operating State��غ궨��
*********************************************************************************************************/
/* OS������� */
#define OS_STATUS_CMD					0x06
#define OS_STATUS_SUB_CMD				0x00
#define OS_SET_MODE_CMD					0x06
#define OS_SET_MODE_SUB_CMD				0x01
#define OS_SET_POLLING_CMD				0x06
#define OS_SET_POLLING_SUB_CMD			0x02
#define OS_GET_POLLING_CMD				0x06
#define OS_GET_POLLING_SUB_CMD			0x03
#define OS_STORE_POLLING_CMD			0x06
#define OS_STORE_POLLING_SUB_CMD		0x04
/* OM����ģʽ���״̬ ��OS_SET_MODE�������õ�*/
#define OM_STANDBY						0x00		// STANDBY
#define OM_IDLE							0x01		// IDLE
#define OM_SLEEP						0x02		// SLEEP
#define OM_CON_RCV						0x03		// ��������
#define OM_POLLING						0x04		// POLLING
#define OM_TRANSPORT					0x05		// TRANSPORT
#define OM_RESET						0x06		// RESET
#define OM_TX_PRE 						0x07		// RF����׼�����������з��书�ܵ�����


/*********************************************************************************************************
  NCK2910 RX Buffer��غ궨��
*********************************************************************************************************/
#define RB_READ_BYTES_CMD				0x0F
#define RB_READ_BYTES_SUB_CMD			0x10
#define RB_READ_MSG_CMD					0x0F
#define RB_READ_MSG_SUB_CMD				0x80
#define RB_STATUS_CMD					0x0F
#define RB_STATUS_SUB_CMD				0x81
#define RB_FLUSH_MSG_CMD				0x0F
#define RB_FLUSH_MSG_SUB_CMD			0x88


/*********************************************************************************************************
  NCK2910 Personality��غ궨��
*********************************************************************************************************/
#define PE_CAPABILITY_CMD				0x03
#define PE_CAPABILITY_SUB_CMD			0x0F
#define PE_VERSIONS_CMD					0x03
#define PE_VERSIONS_SUB_CMD				0xF0


/*********************************************************************************************************
  NCK2910 Debug��غ궨��
*********************************************************************************************************/
#define DD_HASH_CMD						0x60
#define DD_HASH_SUB_CMD					0x5A
#define DD_SIG_CMD						0x60
#define DD_SIG_SUB_CMD					0x5B
#define DD_SET_CMD						0x60
#define DD_SET_SUB_CMD					0x65
#define DD_GET_CMD						0x60
#define DD_GET_SUB_CMD					0x6A
#define DD_TIME_CMD						0x60
#define DD_TIME_SUB_CMD					0x90


/*********************************************************************************************************
  NCK2910 Wired Interface��غ궨��
*********************************************************************************************************/
#define WI_ECHO_CMD						0x01
#define WI_ECHO_SUB_CMD					0		// no sub cmd
#define WI_ECHO_NXP_CMD					0x02
#define WI_ECHO_NXP_SUB_CMD				0		// no sub cmd
#define WI_CONFIG_CMD					0x05
#define WI_CONFIG_SUB_CMD				0x01	
#define WI_CLEAR_CMD					0x05
#define WI_CLEAR_SUB_CMD				0xFE
#define WI_STORE_CMD					0x10
#define WI_STORE_SUB_CMD				0x01


/*********************************************************************************************************
  NCK2910 On-Board Measurement��غ궨��
*********************************************************************************************************/
#define OBM_CONF_CMD									0x08
#define OBM_CONF_SUB_CMD								0x01
#define OBM_READ_CMD									0x08
#define OBM_READ_SUB_CMD								0x02
#define OBM_RSSI_OFMU_CMD								0x08
#define OBM_RSSI_OFMU_SUB_CMD							0x03
#define OBM_SET_FREQUENCY_OFFSET_OVERRIDE_CMD			0x08
#define OBM_SET_FREQUENCY_OFFSET_OVERRIDE_SUB_CMD		0x04
#define OBM_GET_FREQUENCY_OFFSET_CMD					0x08
#define OBM_GET_FREQUENCY_OFFSET_SUB_CMD				0x05
#define OBM_DO_LO_CORRECTION_CMD						0x08
#define OBM_DO_LO_CORRECTION_SUB_CMD					0x06


/*********************************************************************************************************
  NCK2910 Miscellaneous Commands��غ궨��
*********************************************************************************************************/
#define MISC_WAIT_US_CMD				0x09
#define MISC_WAIT_US_SUB_CMD			0x01
#define MISC_PIN_TOGGLE_CMD				0x09
#define MISC_PIN_TOGGLE_SUB_CMD			0x02


/*********************************************************************************************************
  NCK2910 Event Handling��غ궨��
*********************************************************************************************************/
#define EV_TIMER_HEARTBEAT_CMD			0x07
#define EV_TIMER_HEARTBEAT_SUB_CMD		0x00


/*********************************************************************************************************
  NCK2910 Transmitter Configuration and Control��غ궨��
*********************************************************************************************************/
#define TX_TRIGGER_CMD					0x04
#define TX_TRIGGER_SUB_CMD				0x00
#define TX_WRITE_PAYLOAD_CMD			0x04
#define TX_WRITE_PAYLOAD_SUB_CMD		0x01
#define TX_READ_PAYLOAD_CMD				0x04
#define TX_READ_PAYLOAD_SUB_CMD			0x02


/*********************************************************************************************************
  NCK2910 RF���û����С��غ궨��
*********************************************************************************************************/
#define	RX_CFG_NUM			2u			// RF RX����������
#define LO_CFG_BUF_LEN		8u			// length of Local oscillator
#define DIG_FREQ_BUF_LEN	5u			// length of Digital frequency configuration 
#define FILTER_BUF_LEN		48u			// length of Channel filter configuration
#define BASEBAND_BUF_LEN	47u			// length of Baseband configuration
#define FRAME_WUP_BUF_LEN	15u			// length of Frame/WUP configuration
#define SW_BUF_LEN			20u			// length of SW configuration
#define MID_MAP_BUF_LEN		11u			// length of MIDMAP
#define MID_BUF_LEN			7u			// length of MID
#define	SLOT_CFG_BUF_LEN	9u			// length of Slot configuration 
#define	REC_CFG_BUF_LEN		5u			// length of Reception configuration
#define POLLING_CFG_BUF_LEN	12u			// OS_SET_POLLING��payload���ȣ�����RCI��λ�����޸�
#define PFLASH_CFG_BUF_LEN	4u			// ��Ҫ���õ�PFLASH���ݴ�С
#define PFLASH_CFG_LOCK_LEN	5u	

/*********************************************************************************************************
  NCK2910���ʱ������궨��
*********************************************************************************************************/
#define Tspi_wake_from_standby
#define Trst_hld
#define Trdy2rcv


/*********************************************************************************************************
  NCK2910�����궨��
*********************************************************************************************************/
#define HW_RST		0x00			// �����Ƿ����Ӳ����λ��0x01Ϊ����Ӳ����λ������ֵΪ���������λ

#define DelayCsT1()			_Nck2910_delay_us(100)
#define DelayCsT2()			_Nck2910_delay_us(100)
#define DelayRstHoldTime()	        _Nck2910_delay_us(6000)

#define POLLING_STATUS_CHECK_MAXTIME  (uint16)(3000/10)

typedef struct
{
    uint8_t m_DataLength;          /* ???????*/
    uint8_t m_Data[20];             /* ????????    ???16???????? */
}UHF_MessageTypeDef;

typedef enum 
{
	NCK2910_INIT,											//NCK2910��ʼ��RAM
	NCK2910_NORMAL, 										//NCK2910��������״̬
	NCK2910_FAIL,											//NCK2910��ʼ��ʧ��
} Nck2910_Work_State;


extern Nck2910_Work_State	tnNck2910WorkStatus;
extern uint8 u8Nck2910RciReadWorkMode;
extern uint32 u32UhfRxNum;

/*********************************************************************************************************
** Function name:       NCK2910_SpiWrite
** Descriptions:        ͨ��SPI��������
** input parameters:    pu8WrBuf : SPIд����ָ��
**						WrBufLen : SPIд���峤�ȣ�unit(Byte)
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern void NCK2910_SpiWrite(uint8_t *pu8WrBuf, uint8_t WrBufLen);

/*********************************************************************************************************
** Function name:       NCK2910_SpiRead
** Descriptions:        ͨ��SPI������
** input parameters:    pu8RdBuf : SPI������ָ��
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern void NCK2910_SpiRead(uint8_t *pu8RdBuf);

/*********************************************************************************************************
** Function name:       NCK2910_Init
** Descriptions:        ��ʼ��NCK2910
** input parameters:    
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern void Nck2910_Init(void);

/*********************************************************************************************************
** Function name:       NCK2910_Reset
** Descriptions:        ��λNCK2910
** input parameters:    
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_Reset(void);

/*********************************************************************************************************
** Function name:       NCK2910_Standby
** Descriptions:        NCK2910����Standbyģʽ��Standbyģʽ�£�CPU״̬��RAM�����ݱ��֣�polling timer��
**						watchdog��Ч
** input parameters:    u8StandbyTime : ͣ����Standby״̬�µ�ʱ��
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_Standby(uint8_t u8StandbyTime);

/*********************************************************************************************************
** Function name:       NCK2910_Idle
** Descriptions:        NCK2910����idleģʽ
** input parameters:    idleģʽ�£�RX�������رգ�RCI����������Ӧ
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_Idle(void);

/*********************************************************************************************************
** Function name:       NCK2910_Sleep
** Descriptions:        NCK2910����Sleepģʽ��Sleepģʽ�£�CPU״̬��RAM�����ݱ��֣�polling timer��
**						watchdog��Ч��֧�ַ�ƵXO Clock���
** input parameters:    u8SleepTime : ͣ����sleepģʽ�µ�ʱ��
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_Sleep(uint8_t u8SleepTime);

/*********************************************************************************************************
** Function name:       NCK2910_ConRx
** Descriptions:        NCK2910������������ģʽ
** input parameters:    u8RxCfgIndex : �����������ڼ䣬���õ����ĸ�RF RX���������գ������õ�������
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_ConRx(uint8_t u8RxCfgIndex);

/*********************************************************************************************************
** Function name:       NCK2910_Polling
** Descriptions:        NCK2910����Pollingģʽ
** input parameters:    
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_Polling(void);

/*********************************************************************************************************
** Function name:       NCK2910_PowerOff
** Descriptions:        NCK2910����PowerOffģʽ��PowerOffģʽ�£�polling timer��watchdog��Ч
** input parameters:    
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_PowerOff(void);

/*********************************************************************************************************
** Function name:       NCK2910_Transport
** Descriptions:        NCK2910����Transportģʽ��Transportģʽ�£���ģʽ����͹��ģ���ҪRST_N������
** input parameters:    
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern boolean NCK2910_Transport(void);

/*********************************************************************************************************
** Function name:       NCK2910_RfRcvDataDeal
** Descriptions:        ����NCK2910���յ���RF����
** input parameters:    
** output parameters:   
** Returned value:      
*********************************************************************************************************/
extern void NCK2910_RfRcvDataDeal(void);


extern uint8 GetNck2910InitCompleteStatus(void);
extern void Nck2910_DataProcess(void);
extern void NCK2910_Enter_LowPower(void);
extern void NCK2910_Enter_Normal(void);

#endif

/*********************************************************************************************************
  EoF
*********************************************************************************************************/


