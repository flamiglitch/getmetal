#include "gpu.h"
#include <vulkan/vulkan.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void* gpu_thrd(void* args)
{

  VkApplicationInfo applicationInfo;
  VkInstanceCreateInfo instanceInfo;
  VkInstance instance;


  applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  applicationInfo.pNext = NULL;
  applicationInfo.pApplicationName = "\0";
  applicationInfo.pEngineName = NULL;
  applicationInfo.engineVersion = 1;
  applicationInfo.apiVersion = VK_API_VERSION_1_0;
  instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instanceInfo.pNext = NULL;
  instanceInfo.flags = 0;
  instanceInfo.pApplicationInfo = &applicationInfo;
  instanceInfo.enabledLayerCount = 0;
  instanceInfo.ppEnabledLayerNames = NULL;
  instanceInfo.enabledExtensionCount = 0;
  instanceInfo.ppEnabledExtensionNames = NULL;

  if (vkCreateInstance(&instanceInfo, NULL, &instance) != VK_SUCCESS)
  {

    
    fprintf(stderr, "Failed to create instance\n");
    vkDestroyInstance(instance, NULL);
    exit(-1);

  }


  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(instance, &deviceCount, NULL);

  if (deviceCount == 0)
  {
    fprintf(stderr, "failed to find GPUs with Vulkan support!\n");
  }

  VkPhysicalDevice* devices = (VkPhysicalDevice*) malloc(sizeof(VkPhysicalDevice) * deviceCount);

  if (devices == NULL)
  {
    printf("malloc error\n");
  }

  vkEnumeratePhysicalDevices(instance, &deviceCount, devices);
  VkPhysicalDeviceProperties deviceProperties;
  vkGetPhysicalDeviceProperties(devices[0], &deviceProperties);

  free(devices);

  *((char**)args) = (char*) malloc((strlen(deviceProperties.deviceName) + 1) * sizeof(char));
  strcpy(*((char**)args), deviceProperties.deviceName);

  vkDestroyInstance(instance, NULL);

  return(NULL);

}
