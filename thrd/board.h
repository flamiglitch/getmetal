#if !defined(__THRDBOARD_H__)
#define  __THRDBOARD_H__

#include <pthread.h>

extern void* board_thrd(void*);
pthread_t board_tid; 

#endif
