#include "kernel.h"
#include <sys/utsname.h>
#include <stdlib.h>

void* kernel_thrd(void* args)
{

  if (uname((struct utsname *)args) != 0)
  {
    exit(-1);
  }

  return(NULL);

}
