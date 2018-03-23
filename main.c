#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
  void *mod1 = dlopen("mod1.so", RTLD_NOW);
  int (*ptr2)(int) = dlsym(mod1, "mod1func");
  int x = ptr2(44);

  if (x)
    {
      printf("ERROR! No static string\n");
    } else
    {
      printf("Found static string\n");

    }

  return 0;
}
