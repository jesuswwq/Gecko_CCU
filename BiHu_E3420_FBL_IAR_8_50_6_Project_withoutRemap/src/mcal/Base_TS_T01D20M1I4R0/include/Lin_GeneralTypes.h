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
 * @file  Lin_GeneralTypes.h
 * @brief Semidrive. AUTOSAR 4.3.1 Lin Stack
 */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined (LIN_GENERALTYPES_H)
#define LIN_GENERALTYPES_H

#include "Std_Types.h"


#define LIN_CH_OPERATIONAL               (0xFeU)
#define LIN_CH_SLEEP_PENDING             (0xFfU)
/*      LIN_CH_SLEEP   (from Lin_StatusType)*/

typedef uint8 Lin_FramePidType;
typedef uint8 Lin_FrameDlType;

typedef enum {
    LIN_ENHANCED_CS = 0U,
    LIN_CLASSIC_CS  = 1U
}Lin_FrameCsModelType;

typedef enum {
    LIN_MASTER_RESPONSE  = 0U,    /*master to slave*/
    LIN_SLAVE_RESPONSE   = 1U,     /*slave to master*/
    LIN_SLAVE_TO_SLAVE   = 2U,     /*slave to slave*/
}Lin_FrameResponseType;

typedef struct {
    uint8                           *SduPtr;  /* Current status of channel*/
    Lin_FrameDlType                 Dl;       /* Length of current frame*/
    Lin_FrameCsModelType            Cs;       /* Checksum Model*/
    Lin_FrameResponseType           Drc;      /* Frame type*/
    Lin_FramePidType                Pid;
}Lin_PduType;

typedef enum {
    /** LIN frame operation return value.
     *  Development or production error occurred */
    LIN_NOT_OK           = 0U,

    /** LIN frame operation return value.
     *  Successful transmission. */
    LIN_TX_OK,

    /** LIN frame operation return value.
     *  Ongoing transmission (Header or Response). */
    LIN_TX_BUSY,

    /** LIN frame operation return value.
     *  Erroneous header transmission such as:
     *  - Mismatch between sent and read back data
     *  - Identifier parity error or
     *  - Physical bus error */
    LIN_TX_HEADER_ERROR,

    /** LIN frame operation return value.
     *  Erroneous response transmission such as:
     *  - Mismatch between sent and read back data
     *  - Physical bus error */
    LIN_TX_ERROR,

    /** LIN frame operation return value.
     *  Reception of correct response. */
    LIN_RX_OK,

    /** LIN frame operation return value. Ongoing reception: at
     *  least one response byte has been received, but the
     *  checksum byte has not been received. */
    LIN_RX_BUSY,

    /** LIN frame operation return value.
     *  Erroneous response reception such as:
     *  - Framing error
     *  - Overrun error
     *  - Checksum error or
     *  - Short response */
    LIN_RX_ERROR,

    /** LIN frame operation return value.
     *  No response byte has been received so far. */
    LIN_RX_NO_RESPONSE,

    /** LIN channel state return value.
     *  Normal operation; the related LIN channel is ready to
     *  transmit next header. No data from previous frame
     *  available (e.g. after initialization) */
    LIN_OPERATIONAL,

    /** LIN channel state return value.
     *  Sleep mode operation; in this mode wake-up detection
     *  from slave nodes is enabled. */
    LIN_CH_SLEEP
} Lin_StatusType;

typedef enum {
    /* Error in header */
    LIN_ERR_HEADER           = 0U,

    /* Framing error in response */
    LIN_ERR_RESP_STOPBIT,

    /* Checksum error */
    LIN_ERR_RESP_CHKSUM,

    /* Monitoring error of transmitted data bit in response */
    LIN_ERR_RESP_DATABIT,

    /* No response */
    LIN_ERR_NO_RESP,

    /* Incomplete response */
    LIN_ERR_INC_RESP,
} Lin_SlaveErrorType;

#endif /* LIN_GENERALTYPES_H */

#ifdef __cplusplus
}
#endif
