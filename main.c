#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "config.h"
#include "types.h"
#include "thrd/gpu.h"
#include "thrd/cpu.h"
#include "thrd/board.h"
#include "thrd/kernel.h"
#include "thrd/memory.h"
#include "thrd/name.h"
#include "thrd/distro.h"


int main(int argc, const char** argv)
{

  pthread_create(&name_tid,   NULL, name_thrd,   (void *)&host_user);
  pthread_create(&kernel_tid, NULL, kernel_thrd, (void *)&kernel);
  pthread_create(&mem_tid,    NULL, mem_thrd,    (void *)&memory);
  pthread_create(&gpu_tid,    NULL, gpu_thrd,    (void *)&gpu_name);
  pthread_create(&board_tid,  NULL, board_thrd,  (void *)&board_name);
  pthread_create(&distro_tid, NULL, distro_thrd, (void *)&distro_name);
  cpu_thrd(&cpu_name);

  pthread_join(name_tid,   NULL);
  pthread_join(kernel_tid, NULL);
  pthread_join(mem_tid,    NULL);
  pthread_join(gpu_tid,    NULL);
  pthread_join(board_tid,  NULL);


  printf("\n");
  printf("%s%s%s@%s%s\n", PRIMARY, host_user.pw->pw_name, SECONDARY, PRIMARY, host_user.host);

  #if defined(DISTRO)
    printf("%sDISTRO:   %s\n", DISTRO, distro_name);
  #else
    printf("%sDISTRO:%s   %s\n", PRIMARY, SECONDARY, distro_name);
  #endif

  #if defined(KERNEL)
    printf("%sKERNEL:   %s %s %s\n", KERNEL, kernel.sysname, kernel.release, kernel.machine);
  #else
    printf("%sKERNEL:%s   %s %s %s\n", PRIMARY, SECONDARY, kernel.sysname, kernel.release, kernel.machine);
  #endif


  #if defined(SHELL)
    printf("%sSHELL:    %s\n", SHELL, host_user.pw->pw_shell);
  #else
    printf("%sSHELL:    %s%s\n", PRIMARY, SECONDARY, host_user.pw->pw_shell);
  #endif

  #if defined(RAM)
    printf("%sRAM:      %lu%s\n", RAM, memory.num, memory.units);
  #else
    printf("%sRAM:      %s%lu%s\n", PRIMARY, SECONDARY, memory.num, memory.units);
  #endif

  #if defined(GPU)
    printf("%sGRAPHICS: %s\n", GPU, gpu_name);
  #else
    printf("%sGRAPHICS: %s%s\n", PRIMARY, SECONDARY, gpu_name);
  #endif

  #if defined(CPU)
    printf("%sCPU:      %s", CPU, cpu_name);
  #else
    printf("%sCPU:      %s%s", PRIMARY, SECONDARY, cpu_name);
  #endif

  #if defined(BOARD)
    printf("%sBOARD:    %s\n", BOARD, board_name);
  #else
    printf("%sBOARD:    %s%s\n", PRIMARY, SECONDARY, board_name);
  #endif


  printf("\033[0m");
  free(cpu_name);
  free(gpu_name);
  free(board_name);
  free(distro_name);

  return 0;

}
