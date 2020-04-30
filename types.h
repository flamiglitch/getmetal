#if !defined(__TYPES_H__)
#define __TYPES_H__

#include <limits.h>
#include <sys/utsname.h>
#include <pwd.h>

struct name_args
{
    char host[HOST_NAME_MAX];
    struct passwd* pw;
};

struct mem_args
{
  unsigned long num;
  char units[3];
};

struct gpu_args
{
  int width;
  int height;
  int hz;
  char* name;
};

struct name_args host_user;
struct utsname kernel;
struct mem_args memory;
struct gpu_args gpu;
char* cpu_name;
char* board_name;
char* distro_name;

#endif
