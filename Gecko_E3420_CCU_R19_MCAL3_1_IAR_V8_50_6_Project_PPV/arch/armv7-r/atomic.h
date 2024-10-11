/*
 * atomic.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: ARM atomic interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef INCLUDE_ARCH_ATOMIC_H
#define INCLUDE_ARCH_ATOMIC_H

#ifndef ASSEMBLY

#include "__compiler.h"

__BEGIN_CDECLS

/*
 * atomic swap.
 *
 * @ptr     address of data A.
 * @val     value of data B.
 * @return  old value of data A.
 */
int arch_atomic_swap(int *ptr, int val);

/*
 * atomic add.
 *
 * @ptr     address of data A.
 * @val     value of data B.
 * @return  old value of data A.
 */
int arch_atomic_add(int *ptr, int val);

/*
 * atomic and.
 *
 * @ptr     address of data A.
 * @val     value of data B.
 * @return  old value of data A.
 */
int arch_atomic_and(int *ptr, int val);

/*
 * atomic or.
 *
 * @ptr     address of data A.
 * @val     value of data B.
 * @return  old value of data A.
 */
int arch_atomic_or(int *ptr, int val);

/*
 * atomic try_update.
 *
 * @ptr     address of data A.
 * @val     value of data B.
 * @return  0 updated 1 not uptate.
 */
int arch_atomic_try_update(int *ptr, int val);

__END_CDECLS

#endif

#endif
