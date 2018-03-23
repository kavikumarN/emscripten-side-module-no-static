#include <stdio.h>
#include <math.h>


int mod1func(int x)
{
  const char* msg = "Message";

  // If the above static memory were set, I would expect this to be false
  return (msg[0] == 0);
}
