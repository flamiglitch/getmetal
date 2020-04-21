#if !defined(__THRDGPU_H__)
#define  __THRDGPU_H__

#include <pthread.h>

extern void* gpu_thrd(void*);
pthread_t gpu_tid;

#endif
