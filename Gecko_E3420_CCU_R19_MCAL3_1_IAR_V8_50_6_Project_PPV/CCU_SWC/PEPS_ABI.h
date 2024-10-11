#ifndef PEPS_ABI_H
#define PEPS_ABI_H

#include "Platform_Types.h"

// APP输入全局变量
extern uint8 u8PE_Auth_FobStatus;                      // PE����ң��Կ��λ����Ϣ
extern uint8 u8PS_Auth_FobStatus;                      // PS����ң��Կ��λ����Ϣ
extern uint16 u16Leftfront_Door_Ant_Rssi;              // ��ǰ�ŵ�ǰ��Ƶ����ǿ��ֵ(ȫ�ֱ���)
extern uint16 u16Rightfront_Door_Ant_Rssi;             // ��ǰ�ŵ�ǰ��Ƶ����ǿ��ֵ
extern uint16 u16InCar_Door_Ant_Rssi;                  // ���ڵ�ǰ��Ƶ����ǿ��ֵ
extern uint8 u8Lf_Polling_Work_State;                  // Polling����״̬
extern uint8 u8Welcome_Function_Request;               // ӭ�����ܵ�ǰ����ģʽ
extern uint16 u16Left_Door_Ant_DriveCurrent;           // ���PE����������������(ȫ�ֱ���)
extern uint16 u16Right_Door_Ant_DriveCurrent;          // �Ҳ�PE����������������(ȫ�ֱ���)
extern uint16 u16Incar_Ant_DriveCurrent;               // PS����������������(ȫ�ֱ���)
extern uint16 u16Left_Door_Ant_Rssi_Limit;             // ���PE���߳�ǿ��ֵ����(ȫ�ֱ���)
extern uint16 u16Right_Door_Ant_Rssi_Limit;            // �Ҳ�PE���߳�ǿ��ֵ����(ȫ�ֱ���)
extern uint16 u16Incar_Ant_Rssi_Limit;                 // PS���߳�ǿ��ֵ����(ȫ�ֱ���)
extern uint8 u8FobKey_Information_Management_Feedback; // Կ��ѧϰ�Լ�����״̬����(ȫ�ֱ���)
extern uint8 u8FobKey_Disable_Status_Feedback;         // Կ�׽���״̬����(ȫ�ֱ���)
extern uint8 u8SpiCurReadUhfDataBuf[18];               // ��ƵЭ������(ȫ�ֱ���)
extern uint8 u8Fobkey_Cur_RkeCmd;

// APP输入API
extern uint8 GetFobKeyCmdRequest(void);       // ң��Կ������
extern uint8 LoFrqAtnErrWarn(void);           // ��Ƶ���߹��ϱ����ź�
extern uint8 GetTransmitterMaxNumErr(void);   // ң��Կ��ƥ���Ѵ��������
extern uint8 Ecu_Read_LfAnt_DiagStatus(void); // ��Ƶ������Ͻ��
extern uint8 GetSyncCountErr(void);           // ң��Կ��ͬ������ֵ����
extern uint8 ClsDoorKeyNotInCarWarn(void);    // ���Źر�Կ�ײ��ڳ�������

extern uint8 Get_PEAuth_FobStatus(void);
extern uint8 Get_PSAuth_FobStatus(void);
extern uint8 Get_Wlcm_FunStatus(void);
extern uint8 Get_PollingWork_State(void);
extern void PEPS_NVMRead(void);
extern uint8 Get_FobdKeyNum(void);
extern uint8 Get_KeyBat_VolLow(void);
extern uint8 Get_KeyNotInCar_Warn(void);

// APP输出全局变量
extern uint8 u8KeyTempBuffVal[256]; // ��ȡ�ʹ洢������ʱ����
extern uint8 u8PS_Auth_KeyPosReq;   // PS����������֤��λң��Կ��
extern uint8 u8PE_Auth_KeyPosReq;   // PE����������֤��λң��Կ��

extern uint8 u8FobKeyEnterWorkState;

extern uint8 u8PollingFuncRequest; // Polling��������
extern uint8 u8PolingStsReq;       //

extern uint8 u8AntDigRequest;           // �����������
extern uint8 u8LPEDriverCurRead;        // ���PE��������������ȡ
extern uint8 u8RPEDriverCurRead;        // �Ҳ�PE��������������ȡ
extern uint8 u8PSAntDirverCurRead;      // PS��������������ȡ
extern uint16 u16LPEAntDriveCurrentSet; // ���PE����������������
extern uint16 u16RPEAntDriveCurrentSet; // �Ҳ�PE����������������
extern uint16 u16PSAntDriveCurrentSet;  // PS����������������
extern uint16 u16LPEAntRssiLimitRead;   // ���PE���߳�ǿ��ֵ��ȡ
extern uint16 u16RPEAntRssiLimitRead;   // �Ҳ�PE���߳�ǿ��ֵ��ȡ
extern uint16 u16PSAntRssiLimitRead;    // PS���߳�ǿ��ֵ��ȡ
extern uint16 u16LPEAntRssiLimitSet;    // ���PE���߳�ǿ��ֵ����
extern uint16 u16RPEAntRssiLimitSet;    // �Ҳ�PE���߳�ǿ��ֵ����
extern uint16 u16PSAntRssiLimitSet;     // PS���߳�ǿ��ֵ����

extern uint8 status2910;
extern uint8 status29c0;
extern uint8 psreq_count;
extern uint8 psclear_count;
extern uint8 lfworksta;
extern uint16 RxNum2910;
// APP输出API
extern void Set_PEAuth_FobReq(uint8 PEReq_param);
extern void Set_PSAuth_FobReq(uint8 PSReq_param);
extern void Set_Polling_FunReq(uint8 PolReq_param);
extern void Set_AntDig_FunReq(uint8 AntDigReq_param);
extern void Set_LPEDriverCur_Val(uint16 LCur_param);
extern void Set_RPEDriverCur_Val(uint16 RCur_param);
extern void Set_PSAntDirverCur_Val(uint16 PSCur_param);
extern void Set_LPEAntRssiLimit_Val(uint16 LRssi_param);
extern void Set_RPEAntRssiLimit_Val(uint16 RRssi_param);
extern void Set_PSAntRssiLimit_Val(uint16 PSRssi_param);
extern void PEPS_NVMWrite(void);

extern void LUnLock_PEPS_test(void);
extern void Clear_PSStatus(void);
extern void Clear_PEStatus(void);
extern void Clear_RKECommd(void);
extern void PEPS_Interface2CAN(void);
extern void PEPS_KL30_RessetMonit(void);
extern void PEPS_KL30Resset_ParamWrt(void);
#endif