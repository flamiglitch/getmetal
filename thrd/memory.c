#include "memory.h"
#include "../types.h"
#include <string.h>
#include <sys/sysinfo.h>
#include <stdlib.h>

void* mem_thrd(void* args)
{

  struct sysinfo mem_stats;

  if (sysinfo(&mem_stats) != 0)
  {
    exit(-1);
  }

  //GB
  if (mem_stats.totalram > 1000000000L)
  {

    strcpy(((struct mem_args*)args)->units, "GB");
    ((struct mem_args*)args)->num = mem_stats.totalram / 1000000000L;

  }

  //MB
  else if (mem_stats.totalram > 1000000L)
  {

    strcpy(((struct mem_args*)args)->units, "MB");
    ((struct mem_args*)args)->num = mem_stats.totalram / 1000000L;

  }

  //KB
  else if (mem_stats.totalram > 1000L)
  {

    strcpy(((struct mem_args*)args)->units, "KB");
    ((struct mem_args*)args)->num = mem_stats.totalram / 1000L;

  }

  // just in bytes
  else
  {

    strcpy(((struct mem_args*)args)->units, "B");
    ((struct mem_args*)args)->num = mem_stats.totalram;

  }


  return(NULL);

}
