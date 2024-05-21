/* Copying src/id3.cpp to src/id5.c, and fixing the use of intdouble
   so that it compiles.  It works as in C++, copying the struct, but you
   should be wary of it.  */

#include <stdio.h>
#include <stdlib.h>

struct intdouble {
  int i;
  double d;
};

int main()
{
  struct intdouble id1, id2;

  id1.i = 5;
  id1.d = 3.14;

  id2 = id1;  /* THIS IS THE OFFENDING LINE */
  id2.i += 5;
  id2.d += 5;

  printf("1: %d %.2lf\n", id1.i, id1.d);
  printf("2: %d %.2lf\n", id2.i, id2.d);
  return 0;
}