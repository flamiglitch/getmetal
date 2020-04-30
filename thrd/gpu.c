#include "gpu.h"
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <string.h>
#include "../types.h"


void* gpu_thrd(void* args)
{

  if (!glfwInit())
  {
    fprintf(stderr, "failed to init glfw\n");
    exit(-1);
  }

  GLFWmonitor* monitor    = glfwGetPrimaryMonitor();
  const GLFWvidmode* mode = glfwGetVideoMode(monitor);

  ((struct gpu_args*)args)->width  = mode->width;
  ((struct gpu_args*)args)->height = mode->height;
  ((struct gpu_args*)args)->hz     = mode->refreshRate;


  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
  GLFWwindow* window = glfwCreateWindow(640, 480, "", NULL, NULL);
  
  if (!window)
  {
    fprintf(stderr, "failed to create renderer context\n");
    exit(-1);
  }

  glfwMakeContextCurrent(window);

  size_t len = strlen(glGetString(GL_RENDERER));
  char* name = (char*) calloc(1, len + 1);
  strcpy(name, glGetString(GL_RENDERER));
  char* end  = strchr(name, '/');

  glfwDestroyWindow(window);
  glfwTerminate();

  if (end != NULL)
  {
    
    ((struct gpu_args*)args)->name = calloc(1, end - name + 1);
    strncpy(((struct gpu_args*)args)->name, name, end - name);
    free(name);

  } else {

    ((struct gpu_args*)args)->name = name;

  }

  return(NULL);

}