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
 * \file     Xtrg_PBCfg.c
 * \brief    AUTOSAR 4.3.1 MCAL xtrg generate file
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/09/07     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Xtrg_Types.h"
#include "Xtrg_Cfg.h"
#include "Xtrg_Sig.h"
#include "Compiler.h"

#define XTRG_START_SEC_CONST_UNSPECIFIED
#include "Xtrg_MemMap.h"
const Xtrg_SignalType SmuxConfig_crashsig = {
    .signalInput = IO_I_34,
    .signalOutput = ETIMER2_CPT_B0,
};
const Xtrg_SignalType IOOutConfig_M1 = {
    .signalInput = EPWM2_CMP_A0,
    .signalOutput = IO_O_7,
};
const Xtrg_SignalType IOOutConfig_M0 = {
    .signalInput = EPWM1_CMP_C0,
    .signalOutput = IO_O_6,
};
const Xtrg_SignalType IOOutConfig_M6 = {
    .signalInput = EPWM1_CMP_C1,
    .signalOutput = IO_O_12,
};
const Xtrg_SignalType IOOutConfig_M7 = {
    .signalInput = EPWM1_CMP_D0,
    .signalOutput = IO_O_13,
};
const Xtrg_SignalType IOOutConfig_M8 = {
    .signalInput = EPWM1_CMP_D1,
    .signalOutput = IO_O_14,
};
const Xtrg_SignalType IOOutConfig_C12 = {
    .signalInput = EPWM2_CMP_B0,
    .signalOutput = IO_O_2,
};
const Xtrg_SignalType IOOutConfig_C14 = {
    .signalInput = EPWM2_CMP_B1,
    .signalOutput = IO_O_4,
};
const Xtrg_SignalType IOOutConfig_H1 = {
    .signalInput = EPWM2_CMP_C0,
    .signalOutput = IO_O_33,
};
const Xtrg_SignalType IOOutConfig_A8 = {
    .signalInput = EPWM2_CMP_D0,
    .signalOutput = IO_O_8,
};
const Xtrg_SignalType IOOutConfig_M3 = {
    .signalInput = EPWM3_CMP_B0,
    .signalOutput = IO_O_9,
};
const Xtrg_SignalType IOOutConfig_S2 = {
    .signalInput = EPWM3_CMP_B1,
    .signalOutput = IO_O_20,
};
const Xtrg_SignalType IOOutConfig_H3 = {
    .signalInput = EPWM3_CMP_C0,
    .signalOutput = IO_O_35,
};
const Xtrg_SignalType IOOutConfig_H12 = {
    .signalInput = EPWM3_CMP_C1,
    .signalOutput = IO_O_44,
};
const Xtrg_SignalType IOOutConfig_H4 = {
    .signalInput = EPWM3_CMP_D0,
    .signalOutput = IO_O_36,
};
const Xtrg_SignalType IOOutConfig_H8 = {
    .signalInput = EPWM3_CMP_D1,
    .signalOutput = IO_O_40,
};
const Xtrg_SignalType IOOutConfig_M9 = {
    .signalInput = EPWM4_CMP_B0,
    .signalOutput = IO_O_15,
};
const Xtrg_SignalType IOOutConfig_H6 = {
    .signalInput = EPWM4_CMP_B1,
    .signalOutput = IO_O_38,
};
const Xtrg_SignalType IOOutConfig_H7 = {
    .signalInput = EPWM4_CMP_C0,
    .signalOutput = IO_O_39,
};
const Xtrg_SignalType IOOutConfig_S5 = {
    .signalInput = EPWM4_CMP_C1,
    .signalOutput = IO_O_23,
};
const Xtrg_SignalType IOOutConfig_H9 = {
    .signalInput = EPWM4_CMP_D0,
    .signalOutput = IO_O_41,
};
const Xtrg_SignalType IOOutConfig_H10 = {
    .signalInput = EPWM4_CMP_D1,
    .signalOutput = IO_O_42,
};
const Xtrg_SignalType IOOutConfig_H5 = {
    .signalInput = EPWM1_CMP_B1,
    .signalOutput = IO_O_37,
};

const Xtrg_DeviceType Xtrg_DeviceCfg = {
    .base = XTRG_REG_BASE,
    .cb = NULL_PTR,
    .arg = NULL_PTR,
};
#define XTRG_STOP_SEC_CONST_UNSPECIFIED
#include "Xtrg_MemMap.h"
#ifdef __cplusplus
}
#endif
/* End of file */


