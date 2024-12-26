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
 * @file  SchM_Base.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Rte Emulation
 */
#ifndef RTE_BASE_H
#define RTE_BASE_H

#include <Mcal.h>

FUNC(void, RTE_CODE) SchM_EXCLUSIVE_AREA_INIT(void);
FUNC(void, RTE_CODE) SchM_Enter_EXCLUSIVE_AREA(void);
FUNC(void, RTE_CODE) SchM_Exit_EXCLUSIVE_AREA(void);

#endif

