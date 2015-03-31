
#ifndef __ARCH_SCHED_H__
#define __ARCH_SCHED_H__

#include <mini-os/machine/limits.h>

static inline struct thread* get_current(void)
{
    struct thread **current;

    current = (void *)((unsigned long)&current & ~(__STACK_SIZE-1));
    return *current;
};

struct thread_md {
    unsigned long thrmd_sp;
    unsigned long thrmd_ip;
    unsigned long thrmd_tp;
    unsigned long thrmd_tl;
};
#define thr_sp md.thrmd_sp
#define thr_ip md.thrmd_ip
#define thr_tp md.thrmd_tp
#define thr_tl md.thrmd_tl

extern void _minios_entry_arch_switch_threads(struct thread_md *prevctx, struct thread_md *nextctx);

#define arch_switch_threads(prev,next) _minios_entry_arch_switch_threads(prev, next)

#endif /* __ARCH_SCHED_H__ */
