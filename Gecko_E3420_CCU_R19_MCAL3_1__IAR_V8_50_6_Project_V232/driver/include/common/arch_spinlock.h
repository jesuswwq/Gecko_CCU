/*
 * spinlock.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: ARM spinlock interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef INCLUDE_ARM_SPINLOCK_H
#define INCLUDE_ARM_SPINLOCK_H

#include "arch.h"
#include "Mcal.h"
#include <atomic.h>
#include "Mcu_Mpu.h"

#ifndef ASSEMBLY

__BEGIN_CDECLS
/* spin lock type */
#ifndef EN_UNIFIED_IMAGE
typedef unsigned long spin_lock_t;
#else
typedef union
{
    volatile uint32 rlock;
    volatile struct tickets {
        volatile uint16 owner;
        volatile uint16 next;
    } tickets;
}spin_lock_t;
#endif

#define MAILBOX_SUPPORT_MAX  (31U)

/*
 * arch spinlock init.
 *
 * @spinlock    spinlock address.
 */
#ifdef CONFIG_ARCH_WITH_SMP
void arch_spin_lock_init(spin_lock_t *spinlock);
#else
static inline void arch_spin_lock_init(spin_lock_t *spinlock)
{
#ifndef EN_UNIFIED_IMAGE
    *spinlock = 0;
#else
    spinlock->rlock = 0;
    DMB;
#endif
}
#endif

/*
 * arch spin lock.
 *
 * @spinlock    spinlock address.
 */
#ifdef CONFIG_ARCH_WITH_SMP
void arch_spin_lock(spin_lock_t *spinlock);
#else
static inline void arch_spin_lock(spin_lock_t *spinlock)
{
#ifndef EN_UNIFIED_IMAGE
    *spinlock = 1;
#else
    spin_lock_t temp;
    /* atomic operation start */
    temp.rlock = arch_atomic_add((int*)&spinlock->rlock,0x1 << TICKET_SHIFT);
    DMB;
    /* atomic operation end */
#if defined(_IAR_C_)
    #pragma diag_suppress=Pa082
#endif
    while(temp.tickets.next != spinlock->tickets.owner);
#if defined(_IAR_C_)
    #pragma diag_warning=Pa082
#endif
#endif
}
#endif

/*
 * arch spin trylock.
 *
 * @spinlock    spinlock address.
 */
#ifdef CONFIG_ARCH_WITH_SMP
int arch_spin_trylock(spin_lock_t *spinlock);
#else
static inline int arch_spin_trylock(spin_lock_t *spinlock)
{
#ifndef EN_UNIFIED_IMAGE
    *spinlock = 1;
    return 0;
#else
    int ret = 0;
    /* atomic operation start */
    ret = arch_atomic_try_update((int*)&spinlock->rlock,0x1 << TICKET_SHIFT);
    DMB;
    /* atomic operation end */
    return ret;
#endif
}
#endif

/*
 * arch spin unlock.
 *
 * @spinlock    spinlock address.
 */
#ifdef CONFIG_ARCH_WITH_SMP
void arch_spin_unlock(spin_lock_t *spinlock);
#else
static inline void arch_spin_unlock(spin_lock_t *spinlock)
{
#ifndef EN_UNIFIED_IMAGE
    *spinlock = 0;
#else
    /* atomic operation start */
    spinlock->tickets.owner++;
    DMB;
    /* atomic operation end */
#endif
}
#endif

__END_CDECLS

#endif

#endif