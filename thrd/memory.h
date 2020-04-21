#if !defined(__THRDMEMORY_H__)
#define  __THRDMEMORY_H__

#include <pthread.h>

extern void* mem_thrd(void*);
pthread_t mem_tid;

#endif
