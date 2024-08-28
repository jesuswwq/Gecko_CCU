/*
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
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  Lin_Icu_Abr_E3.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin.h"
#include "SchM_Lin.h"
#if (LIN_ICU_ABR_DETECT== STD_ON)

#define LIN_ICU_CPT_TIMES 12
extern const Lin_ConfigType *pLin_Config;
/* last time saved baud rate */
uint32 Lin_Pre_Baud[LIN_NUM_CHANNELS];
/* 2 : use sync phase to prase baudrate */
/* break :2 */
uint32 Lin_Icu_Timestamp_Buffer[LIN_NUM_CHANNELS][LIN_ICU_CPT_TIMES];
/* spend time (us) */
uint32 Lin_Icu_Timespend_Buffer[LIN_NUM_CHANNELS][LIN_ICU_CPT_TIMES - 1];
uint32 Lin_Sync_Single_Bit_Time[LIN_NUM_CHANNELS];
boolean Lin_Icu_Sync_Success[LIN_NUM_CHANNELS];

static void Lin_IcuAbrDataHandle(uint8 numNodeId)
{
    /* init handle data */
    Lin_Sync_Single_Bit_Time[numNodeId] = 0;
    Lin_Icu_Sync_Success[numNodeId] = FALSE;
    uint32 syncBitFlag[LIN_ICU_CPT_TIMES - 1] = {0};
    /* equal allow tolerance (+- 5000ns) */
    uint32 minBitTolerance = Lin_Icu_Timespend_Buffer[numNodeId][2] - 5000;
    uint32 maxBitTolerance = Lin_Icu_Timespend_Buffer[numNodeId][2] + 5000;

    for(uint32 n = 0; n < (LIN_ICU_CPT_TIMES - 1); n++) {
        if(Lin_Icu_Timespend_Buffer[numNodeId][n] >= minBitTolerance && Lin_Icu_Timespend_Buffer[numNodeId][n] <= maxBitTolerance) {
            syncBitFlag[n] = 1;
        }
    }
    uint32 syncByteFlag = syncBitFlag[2] & syncBitFlag[3] & syncBitFlag[4] & syncBitFlag[5] &
                            syncBitFlag[6] & syncBitFlag[7] & syncBitFlag[8] & syncBitFlag[9];
    if (syncByteFlag == 1) {
        Lin_Icu_Sync_Success[numNodeId] = TRUE;
        Lin_Sync_Single_Bit_Time[numNodeId] = ((Lin_Icu_Timespend_Buffer[numNodeId][2] + Lin_Icu_Timespend_Buffer[numNodeId][3] + 
                                                Lin_Icu_Timespend_Buffer[numNodeId][4] + Lin_Icu_Timespend_Buffer[numNodeId][5] + 
                                                Lin_Icu_Timespend_Buffer[numNodeId][6] + Lin_Icu_Timespend_Buffer[numNodeId][7] + 
                                                Lin_Icu_Timespend_Buffer[numNodeId][8] + Lin_Icu_Timespend_Buffer[numNodeId][9]) / 8);
    }
}

static void Lin_IcuAbrHandle(uint8 numNodeId)
{
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_00();
    for(uint32 i = 0; i < (LIN_ICU_CPT_TIMES - 1); i++) {
        /* update new sync filed buffer info */
        uint32 icuSpendTick = 0;
        if (Lin_Icu_Timespend_Buffer[numNodeId][i + 1] >= Lin_Icu_Timespend_Buffer[numNodeId][i]) {
            icuSpendTick = Lin_Icu_Timestamp_Buffer[numNodeId][i + 1] - Lin_Icu_Timestamp_Buffer[numNodeId][i];
        } else {
            icuSpendTick = (0xFFFFFFFF - Lin_Icu_Timestamp_Buffer[numNodeId][i]) + Lin_Icu_Timestamp_Buffer[numNodeId][i + 1];
        }
        Lin_Icu_Timespend_Buffer[numNodeId][i] = (icuSpendTick * ((1000 * 1000000)/ LIN_ICU_ABR_FREQ));
    }
    Lin_IcuAbrDataHandle(numNodeId);
    /* check data validity */
    if ((Lin_Icu_Sync_Success[numNodeId] != TRUE) || (Lin_Sync_Single_Bit_Time[numNodeId] == 0)) {
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00();
        return;
    }
    const Lin_Uart      *locNodeCfg;
    /* Initialize local variables*/
    locNodeCfg  = &(pLin_Config->channels[numNodeId]);
    /* calculate the single bit time (ns) */
    uint32 singleBitTime = Lin_Sync_Single_Bit_Time[numNodeId];
    /* calculate baudrate */
    uint32 autoBaud = (1000 * 1000000) / singleBitTime;
    /* check auto baudrate validity */
    uint32 errTolerance = (autoBaud * 10) / Lin_Pre_Baud[numNodeId];
    /* baud rate tolerance scope : 80% - 120% */
    if ((errTolerance >= 8) && (errTolerance <= 12)) {
        /* update new baudrate */
        Lin_Pre_Baud[numNodeId] = autoBaud;
        /*set buadrate to uart register */
        Lin_Uart_Set_Baudrate(locNodeCfg, autoBaud);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00();
}

#define ABR(AbrHandle) void AbrHandle(void)
#define LIN_ICU_ABR(chan) \
ABR(Lin_Icu_Abr_Handle_Uart##chan)\
{\
    uint32 numNodeID = Lin_HwGetNode((Mcu_ModuleType)UART##chan);\
    if (numNodeID < LIN_NUM_CHANNELS) {\
        Lin_IcuAbrHandle(numNodeID);\
    }\
}

LIN_ICU_ABR(1)
LIN_ICU_ABR(2)
LIN_ICU_ABR(3)
LIN_ICU_ABR(4)
LIN_ICU_ABR(5)
LIN_ICU_ABR(6)
LIN_ICU_ABR(7)
LIN_ICU_ABR(8)
LIN_ICU_ABR(9)
LIN_ICU_ABR(10)
LIN_ICU_ABR(11)
LIN_ICU_ABR(12)
#ifndef SEMIDRIVE_E3_LITE_SERIES
LIN_ICU_ABR(13)
LIN_ICU_ABR(14)
LIN_ICU_ABR(15)
LIN_ICU_ABR(16)
#endif
#endif /* LIN_ICU_ABR_DETECT */
#ifdef __cplusplus
}
#endif
