/** **************************************************************************************
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 *  \file     Xtrg_Cfg.h
 *  \brief    This file contains generation file for Xtrg Driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/09/07     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifndef XTRG_CFG_H
#define XTRG_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Xtrg_Types.h"

extern const Xtrg_DeviceType Xtrg_DeviceCfg;

#define XTRG_DEV_ERROR_DETECT                    (STD_OFF)

#define XTRG_SAFETY_ENABLE                    (STD_OFF)

extern const Xtrg_SignalType SmuxConfig_crashsig;






extern const Xtrg_SignalType IOOutConfig_M1;
extern const Xtrg_SignalType IOOutConfig_M0;
extern const Xtrg_SignalType IOOutConfig_M6;
extern const Xtrg_SignalType IOOutConfig_M7;
extern const Xtrg_SignalType IOOutConfig_M8;
extern const Xtrg_SignalType IOOutConfig_C12;
extern const Xtrg_SignalType IOOutConfig_C14;
extern const Xtrg_SignalType IOOutConfig_H1;
extern const Xtrg_SignalType IOOutConfig_A8;
extern const Xtrg_SignalType IOOutConfig_M3;
extern const Xtrg_SignalType IOOutConfig_S2;
extern const Xtrg_SignalType IOOutConfig_H3;
extern const Xtrg_SignalType IOOutConfig_H12;
extern const Xtrg_SignalType IOOutConfig_H4;
extern const Xtrg_SignalType IOOutConfig_H8;
extern const Xtrg_SignalType IOOutConfig_M9;
extern const Xtrg_SignalType IOOutConfig_H6;
extern const Xtrg_SignalType IOOutConfig_H7;
extern const Xtrg_SignalType IOOutConfig_S5;
extern const Xtrg_SignalType IOOutConfig_H9;
extern const Xtrg_SignalType IOOutConfig_H10;
extern const Xtrg_SignalType IOOutConfig_H5;



#ifdef __cplusplus
}
#endif

#endif /* XTRG_CFG_H */
/* End of file */
