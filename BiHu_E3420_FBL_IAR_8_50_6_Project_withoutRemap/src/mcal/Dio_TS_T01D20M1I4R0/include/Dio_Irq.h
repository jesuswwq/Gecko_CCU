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
 * @file  Dio_Irq.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Dio
 */

#ifndef DIO_IRQ_H
#define DIO_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Compiler.h"
#include "Compiler_Cfg.h"

void GPIO_Irq1Handler(void);
void GPIO_Irq2Handler(void);
void GPIO_Irq3Handler(void);
void GPIO_Irq4Handler(void);
void GPIO_Irq5Handler(void);
void GPIO_Irq6Handler(void);
void GPIO_Irq7Handler(void);
void GPIO_Irq8Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* DIO_IRQ_H */
