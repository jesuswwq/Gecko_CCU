/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     Fls_Asm.h                                                                               *
 *  \brief    Cache opeartions.                                                                         *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/11     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FLS_ASM_H
#define FLS_ASM_H

extern void Fls_WritePmcr(uint32 x);
extern void Fls_WritePmcntenset(uint32 x);
extern uint32 Fls_ReadPmcnten(void);
extern uint32 Fls_ReadPmccntr(void);
extern void *Fls_Memcpy4ByteAligned(void* dst, void* src, uint32 bytes);

#endif /* #ifndef FLS_ASM_H */
/* End of file */
