#if !defined(__THRDKERNEL_H__)
#define  __THRDKERNEL_H__

#include <pthread.h>

extern void* kernel_thrd(void*);
pthread_t kernel_tid;

#endif
