/**
 * @file SchM_Dma.h
 * @brief Dma critical areas management function declarations.
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef SCHM_DMA_H
#define SCHM_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SchM_Base.h"

/* Version and Check Begin */
/* Version Info Begin */
#define SCHM_DMA_H_VENDOR_ID    140u
#define SCHM_DMA_H_AR_RELEASE_MAJOR_VERSION    4u
#define SCHM_DMA_H_AR_RELEASE_MINOR_VERSION    3u
#define SCHM_DMA_H_AR_RELEASE_REVISION_VERSION 1u
#define SCHM_DMA_H_SW_MAJOR_VERSION    1u
#define SCHM_DMA_H_SW_MINOR_VERSION    0u
#define SCHM_DMA_H_SW_PATCH_VERSION    0u

#if defined(AUTOSAR_OS_NOT_USED)

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_01() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_01() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_02() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_02() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_03() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_03() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_04() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_04() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_05() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_05() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_06() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_06() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_07() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_07() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_08() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_08() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_09() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_09() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_010() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_010() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_011() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_011() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_012() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_012() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_013() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_013() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_014() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_014() SchM_Exit_EXCLUSIVE_AREA();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_015() SchM_Enter_EXCLUSIVE_AREA();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_015() SchM_Exit_EXCLUSIVE_AREA();

#else

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_01() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_01() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_02() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_02() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_03() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_03() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_04() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_04() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_05() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_05() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_06() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_06() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_07() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_07() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_08() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_08() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_09() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_09() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_010() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_010() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_011() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_011() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_012() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_012() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_013() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_013() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_014() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_014() ResumeAllInterrupts();

#define SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_015() SuspendAllInterrupts();
#define SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_015() ResumeAllInterrupts();

#endif

#ifdef __cplusplus
}
#endif

#endif  /* SCHM_DMA_H */
