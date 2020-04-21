#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void* cpu_thrd(void* args)
{

  FILE* cpufile = fopen("/proc/cpuinfo", "r");
  if (cpufile == NULL)
  {
    exit(-1);
  }


  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  char comp[10] = "model name";
  _Bool not_done = true;
  size_t i;

  while ((read = getline(&line, &len, cpufile)) != -1 && not_done)
  {

    const size_t len = strlen(line);


    for (i = 0; i < len; i++)
    {

      if (*(line + i) == comp[i])
      {


        if (i == sizeof(comp) - 1)
        {

          for (; i < len; i++)
          {

            if (*(line + i) == ':')
            {

              if (len > i)
              {
                i++;
              } else
              {
                exit(-1);
              }

              for (; isspace(*(line + i)); i++)
              {

              }

              *((char**)args) = malloc(strlen( (line + i)) + 1);
              strcpy(*((char**)args), (line + i));


            }
          }

          not_done = false;
          break;


        }

      } else
      {
        break;
      }


    }

    free(line);

  }

  free(line);

  fclose(cpufile);
  return(NULL);

}
