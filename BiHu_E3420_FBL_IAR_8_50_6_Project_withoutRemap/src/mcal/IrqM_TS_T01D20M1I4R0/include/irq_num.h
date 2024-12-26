
//*****************************************************************************
//
// WARNING: Automatically generated file, don't modify anymore!!!
//
// Copyright (c) 2021-2029 Semidrive Incorporated.  All rights reserved.
// Software License Agreement
//
//*****************************************************************************

#ifndef IRQ_NUM_H
#define IRQ_NUM_H

#ifndef SEMIDRIVE_E3_LITE_SERIES
#ifdef CONFIG_CR5_SF
#include "irq_num_sf.h"
#elif defined CONFIG_CR5_SP
#include "irq_num_sp0.h"
#elif defined CONFIG_CR5_SP0
#include "irq_num_sp0.h"
#elif defined CONFIG_CR5_SP1
#include "irq_num_sp1.h"
#elif defined CONFIG_CR5_SX
#include "irq_num_sx0.h"
#elif defined CONFIG_CR5_SX0
#include "irq_num_sx0.h"
#elif defined CONFIG_CR5_SX1
#include "irq_num_sx1.h"
#endif
#else
#include "irq_num_taishan_l.h"
#endif
#endif /* IRQ_NUM_H */
