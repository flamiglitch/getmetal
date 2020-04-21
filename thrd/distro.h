#if !defined(__DISTRO_H__)
#define __DISTRO_H__

#include <pthread.h>

extern void* distro_thrd(void *);
pthread_t distro_tid;

#endif
