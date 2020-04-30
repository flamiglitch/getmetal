#if !defined(__THRDCPU_H__)
#define  __THRDCPU_H__

#include <pthread.h>

extern void* cpu_thrd(void*);
pthread_t cpu_tid;

#endif
