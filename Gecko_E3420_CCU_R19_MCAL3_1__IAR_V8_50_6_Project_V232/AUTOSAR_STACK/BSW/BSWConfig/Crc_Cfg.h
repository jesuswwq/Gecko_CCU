
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Crc_Cfg.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : YB                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef CRC_CFG_H_
#define CRC_CFG_H_

#include "Std_Types.h"

/* req<sws_crc_00040></sws_crc_00040> */
/*=======[M A C R O S]========================================================*/

/* calculation method of Crc mode */
#define CRC_HARDWARE  0
#define CRC_RUNTIME   1
#define CRC_TABLE     2

/* CRC8 (SAE J1850) algorithm calculation switch */
#define CRC8_ALGORITHM              STD_ON

/* CRC8 (2Fh polynomial) algorithm calculation switch */
#define CRC8H2F_ALGORITHM           STD_OFF

/* CRC16 (CCITT) algorithm calculation switch */
#define CRC16_ALGORITHM             STD_ON

/* CRC32 (Ethernet) algorithm calculation switch */
#define CRC32_ALGORITHM             STD_OFF

/* CRC32 (0xF4ACFB13 polynomial) algorithm calculation switch */
#define CRC32P4_ALGORITHM            STD_OFF

/* CRC64 algorithm calculation switch */
#define CRC64_ALGORITHM             STD_OFF

/* Switch to select one of the available CRC 8-bit (SAE J1850) calculation methods
 * req<ecuc_crc_00030></ecuc_crc_00030> */     
#define CRC8_MODE CRC_TABLE

/* Switch to select one of the available CRC 8-bit (2Fh polynomial) calculation methods
 * req<ecuc_crc_00031>*/     

/* Switch to select one of the available CRC 16-bit (CCITT) calculation methods
 * req<ecuc_crc_00025>*/  
#define CRC16_MODE   CRC_TABLE

/* Switch to select one of the available CRC 32-bit (IEEE-802.3 CRC32 Ethernet Standard) calculation methods
 * req<ecuc_crc_00026>*/  

/* Switch to select one of the available CRC 32-bit E2E Profile 4 calculation methods
 * req<ecuc_crc_00032>*/   

 /* Switch to select one of the available CRC 64 calculation methods
 * req<ecuc_crc_00034>*/  
#endif

