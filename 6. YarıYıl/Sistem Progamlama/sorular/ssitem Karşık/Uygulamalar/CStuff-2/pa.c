/* Our first intentional segmentation violation.  When we try to
   access the element at address zero, (NULL is zero), the hardware
   tells us that it's illegal by generating a segmentation violation.  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *s;

  s = NULL;

  printf("%d\n", s[0]);   /* Seg fault here */
  return 0;
}