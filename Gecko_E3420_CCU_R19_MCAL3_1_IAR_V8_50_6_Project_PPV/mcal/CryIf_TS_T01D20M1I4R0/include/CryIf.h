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
 * @file  CryIf.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRY_IF_H
#define CRY_IF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Csm_Types.h"

/* Enumeration of the async response */
typedef enum {
    CRYIF_RESPONSE_INIT = 0xFF,
    /** hsm init success*/
    CRYIF_RESPONSE_OK = 0x00,
    CRYIF_RESPONSE_NOT_OK = 0x01,
} CryIf_HsmResponseType;

void CryIf_CallbackNotification (Crypto_JobType* job, Std_ReturnType result );
void CryIf_Response_Init(void);
CryIf_HsmResponseType CryIf_Get_Response(void);

#ifdef __cplusplus
}
#endif

#endif /* CRY_IF_H */
