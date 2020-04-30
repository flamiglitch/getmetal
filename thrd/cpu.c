#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void* cpu_thrd(void* args)
{

  FILE* cpufile = fopen("/proc/cpuinfo", "r");
  if (cpufile == NULL)
  {
    fprintf(stderr, "no /proc/cpuinfo file is readable");
    exit(-1);
  }

  size_t len = 0;
  char* line = NULL;

  while (getline(&line, &len, cpufile) != -1)
  {

    if (strstr(line, "model name") != NULL)
    {

      *((char**)args)  = line + 13;
      fclose(cpufile);
      return(NULL);

    }

    free(line);
    line = NULL;

  }

  *((char**)args) = (char*) calloc(1, 1);
  fprintf(stderr, "couldn\'t read from /proc/cpuinfo");
  fclose(cpufile);
  return(NULL);

}
