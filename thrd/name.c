#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "../types.h"

void* name_thrd(void* args)
{

  ((struct name_args *)args)->pw = getpwuid(geteuid());

  if (gethostname(((struct name_args *)args)->host, HOST_NAME_MAX) != 0)
  {
    exit(-1);
  }

  return(NULL);

}
