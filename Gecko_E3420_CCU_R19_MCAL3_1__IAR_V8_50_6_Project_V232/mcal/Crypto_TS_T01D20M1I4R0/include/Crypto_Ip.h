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
 * @file  Crypto_Ip.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_IP_H
#define CRYPTO_IP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Csm_Types.h"
#include "Std_Types.h"

#define CRYPTO_KEY_ELEMENT_ENC_KEY_ID 4
/*Std_ReturnType is uint8, 1byte*/
#define CRYPTO_E_SDRV_DEF_CRYPTOID_OVERFLOW    (0x8Du)

typedef enum {
    CRYPTO_IP_AJOB_STATE_NORMAL = 0x0u,
    CRYPTO_IP_AJOB_STATE_CANCEL = 0x1u,
} Crypto_CryptoaJobStateType;

/*doubly linked lists*/
typedef struct Crypto_QueueNode{
    VAR(Crypto_JobType, CRYPTO_VAR) aJob;
    struct Crypto_QueueNode * pJobQueueNodePre;
    struct Crypto_QueueNode * pJobQueueNodeNext;
} Crypto_QueueNodeType;

typedef struct {
    VAR(uint32, CRYPTO_VAR) u32JobQueueUsedSize;
    P2VAR(Crypto_QueueNodeType, AUTOMATIC, CRYPTO_APPL_DATA) pHeadEmptyJobQueue;
    P2VAR(Crypto_QueueNodeType, AUTOMATIC, CRYPTO_APPL_DATA) pHeadUsedJobQueue;
} Crypto_JobQueueInfo;

typedef struct {
    VAR(Crypto_JobType, CRYPTO_VAR) aJob;
    VAR(uint32, CRYPTO_VAR) nextOpMode;
    VAR(Crypto_CryptoaJobStateType, CRYPTO_VAR) CurrentaJobState;
} Crypto_CurrentJobInfo;

typedef struct {
    uint32 JobId;
    uint8 CryptoDriverObjState;/*0,idle 1,busy*/
    Crypto_AlgorithmFamilyType Alogrithm;   /* Just hold the first alogrithm */
    uint8 IsStreamMode;
    Crypto_CurrentJobInfo aJobInfo;
    VAR(Crypto_JobQueueInfo, CRYPTO_VAR) aJobsQueueInfo;
    Crypto_QueueNodeType aDriverObj_JobQueue[CRYPTO_DRIVEROBJ_QUEUE_SIZE];
    uint32 *pIpContext;                 /* aes rsa ... */
} Crypto_ContextType;

typedef enum {
    CRYPTO_IP_CRYPTODRIVEROBJ_STATE_IDLE                = 0x0u,
    CRYPTO_IP_CRYPTODRIVEROBJ_STATE_BUSY             = 0x1u,
} Crypto_CryptoDriverObjStateType;


FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_Init
(
    void
);

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_InitDriverObjContext
(
    VAR(uint32, AUTOMATIC) objectId
);

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_GetCryptoDriverObj
(
    uint32 objectId,
    P2VAR(Crypto_ObjectType, AUTOMATIC, CRYPTO_APPL_DATA) *objPtr,
    P2VAR(Crypto_ContextType, AUTOMATIC, CRYPTO_APPL_DATA) *contextPtr
);

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_JobPushQueue
(
    VAR(uint32, AUTOMATIC) objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
);

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_JobPopQueue
(
    VAR(uint32, AUTOMATIC) objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
);

FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Ip_ProcessJob
(
    uint32 objectId,
    Crypto_JobType *job,
    Crypto_ContextType *current_context
);

#if (CRYPTO_HSM_STATE_API == STD_ON)
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_Get_Status
(
    uint32 *device_status
);
#endif /* CRYPTO_HSM_STATE_API == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_IP_H */

