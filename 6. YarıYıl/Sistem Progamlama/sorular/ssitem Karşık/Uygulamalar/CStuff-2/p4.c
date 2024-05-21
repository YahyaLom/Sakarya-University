/* This program assigns a char to an int, and the int to a float.
   Although it looks benign, there are some things going on 
   beneath the hood (changing number formats). */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
  int i;
  float f;

  c = 'a';
  i = c;
  f = i;

  printf("c = %d (%c).   i = %d (%c).  f = %f\n", c, c, i, i, f);
  return 0;
}