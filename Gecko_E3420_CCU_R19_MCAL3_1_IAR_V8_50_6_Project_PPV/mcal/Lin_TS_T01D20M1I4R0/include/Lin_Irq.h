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
 * @file  Lin_Ira.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 */

#ifndef LIN_IRQ_H
#define LIN_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"

ISR(Lin_Irq1_Handle);

ISR(Lin_Irq2_Handle);

ISR(Lin_Irq3_Handle);

ISR(Lin_Irq4_Handle);

ISR(Lin_Irq5_Handle);

ISR(Lin_Irq6_Handle);

ISR(Lin_Irq7_Handle);

ISR(Lin_Irq8_Handle);

ISR(Lin_Irq9_Handle);

ISR(Lin_Irq10_Handle);

ISR(Lin_Irq11_Handle);

ISR(Lin_Irq12_Handle);

#ifndef SEMIDRIVE_E3_LITE_SERIES
ISR(Lin_Irq13_Handle);

ISR(Lin_Irq14_Handle);

ISR(Lin_Irq15_Handle);

ISR(Lin_Irq16_Handle);
#endif

#ifdef __cplusplus
}
#endif

#endif /* LIN_IRQ_H */
