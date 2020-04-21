#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void* board_thrd(void* args)
{

  FILE* mbfile = fopen("/sys/devices/virtual/dmi/id/board_name", "r");
  if (mbfile == NULL)
  {
    exit(-1);
  }

  char* str = NULL;
  size_t n = 0;

  getline(&str, &n, mbfile);
  *((char**)args) = str;

  fclose(mbfile);

  return(NULL);

}
