/**
 *   @file    EcuM.h
 *
 *   @brief
 *   @details
 *
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef ECUM_H
#define ECUM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32 EcuM_WakeupSourceType;
#define ECUM_WKSOURCE_POWER             (EcuM_WakeupSourceType)0x00000001
#define ECUM_WKSOURCE_RESET             (EcuM_WakeupSourceType)0x00000002
#define ECUM_WKSOURCE_INTERNAL_RESET    (EcuM_WakeupSourceType)0x00000004
#define ECUM_WKSOURCE_INTERNAL_WDG      (EcuM_WakeupSourceType)0x00000008
#define ECUM_WKSOURCE_EXTERNAL_WDG      (EcuM_WakeupSourceType)0x00000010

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MCAL_H_ */
