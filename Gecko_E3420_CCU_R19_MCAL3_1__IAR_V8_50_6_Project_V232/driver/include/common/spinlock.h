/*
 * spinlock.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: spinlock interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef _INCLUDE_SPINLOCK_H_
#define _INCLUDE_SPINLOCK_H_

#ifndef ASSEMBLY

#include <arch_spinlock.h>
#include <arch_irq.h>

#define define_spinlock(lockname)     \
        spin_lock_t  lockname _SECTION(.dma_buffer)

__BEGIN_CDECLS

/*
 * spinlock init.
 *
 * @spinlock    spinlock address.
 */
static inline void spin_lock_init(spin_lock_t *spinlock)
{
    arch_spin_lock_init(spinlock);
}

/*
 * spin lock.
 *
 * @spinlock    spinlock address.
 */
static inline void spin_lock(spin_lock_t *spinlock)
{
    arch_spin_lock(spinlock);
}

/*
 * spin trylock.
 *
 * @spinlock    spinlock address.
 * @return      try lock result.
 */
static inline int spin_trylock(spin_lock_t *spinlock)
{
    return arch_spin_trylock(spinlock);
}

/*
 * spin unlock.
 *
 * @spinlock    spinlock address.
 */
static inline void spin_unlock(spin_lock_t *spinlock)
{
    arch_spin_unlock(spinlock);
}

/*
 * spin lock with irq save
 *
 * @spinlock    spinlock address.
 * @return      old irq state.
 */
static inline irq_state_t spin_lock_irqsave(spin_lock_t *spinlock)
{
    irq_state_t state = arch_irq_save();
    spin_lock(spinlock);
    return state;
}

/*
 * spin unlock with irq restore
 *
 * @spinlock    spinlock address.
 * @state       old irq state.
 */
static inline void spin_unlock_irqrestore(spin_lock_t *spinlock, irq_state_t state)
{
    spin_unlock(spinlock);
    arch_irq_restore(state);
}
__END_CDECLS

#endif

#endif
