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
 * @file  CryIf.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "CryIf_Cbk.h"
#include "debug.h"
#include "Crypto_Hsm.h"
#include "soc_seip_reg.h"
#include "mini_libc.h"

#define mini_printf(...)

#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static Crypto_JobType last_job;

#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

static CryIf_HsmResponseType cryif_response = CRYIF_RESPONSE_INIT;

#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

void CryIf_Response_Init(void)
{
    cryif_response = CRYIF_RESPONSE_INIT;
}

CryIf_HsmResponseType CryIf_Get_Response(void)
{
    return cryif_response;
}

void CryIf_CallbackNotification (Crypto_JobType* job, Std_ReturnType result )
{
    if (E_OK != result || NULL == job) {
        mini_printf("process err\n");
        return;
    }

    /*** get async result ***/
    if (NULL == job->jobPrimitiveInfo) {
        /* check response */
        if (SEIP_SUCCESS == rSOCMBOX_RSP_D0) {
            /* return E_OK;*/
            cryif_response = CRYIF_RESPONSE_OK;
        } else {
            /* return E_NOT_OK; */
            cryif_response = CRYIF_RESPONSE_NOT_OK;
        }
    } else {
        switch (job->jobPrimitiveInputOutput.mode) {
        case CRYPTO_OPERATIONMODE_START:
            mini_printf("start\n");
            break;
        case CRYPTO_OPERATIONMODE_UPDATE:
            mini_printf("update\n");
            break;
        case CRYPTO_OPERATIONMODE_STREAMSTART:
            mini_printf("stream start\n");
            break;
        case CRYPTO_OPERATIONMODE_FINISH:
            /* record the current job */
            mini_memcpy_s(&last_job, job, sizeof(Crypto_JobType));
            mini_printf("finish\n");
            break;
        case CRYPTO_OPERATIONMODE_SINGLECALL:
            mini_printf("singlecall\n");
            break;
        default:
            mini_printf("mode err\n");
            break;
        }
        /* Processing sync algo. */
        if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_SYNC) {
            /* check response */
            if (SEIP_SUCCESS == rSOCMBOX_RSP_D0) {
                /* return E_OK;*/
                cryif_response = CRYIF_RESPONSE_OK;
            } else {
                /* return E_NOT_OK; */
                cryif_response = CRYIF_RESPONSE_NOT_OK;
            }
        }
    }
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
