#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
  void *mod1 = dlopen("mod1.so", RTLD_NOW);
  void *(*ptr2)(int) = dlsym(mod1, "mod1func");
  ptr2(44);

  return 0;
}
