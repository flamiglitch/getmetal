#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* distro_thrd(void* args)
{

  FILE* fp = fopen("/etc/os-release", "r");
  if(fp == NULL) exit(-1);


  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char* str = malloc(fsize + 1);
  if (str == NULL) exit(-1);

  fread(str, 1, fsize, fp);
  fclose(fp);

  char* new_str = strstr(str, "PRETTY_NAME=");
  char* start   = strchr(new_str, '\"') + 1;
  char* end     = strchr(start, '\"');

  *((char**)args) = (char*) calloc(1, end - start + 1);


  strncpy(*((char**)args), start, end - start);
  return(NULL);

}
