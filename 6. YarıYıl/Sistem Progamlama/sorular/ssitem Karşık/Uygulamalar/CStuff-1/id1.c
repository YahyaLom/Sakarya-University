/* A very simple program to show a struct 
   that aggregates an integer and a double. */

#include <stdio.h>
#include <stdlib.h>

struct intdouble {
  int i;
  double d;
};

int main()
{
  struct intdouble id1;

  id1.i = 5;
  id1.d = 3.14;

  printf("%d %.2lf\n", id1.i, id1.d);
  printf("%lu\n", sizeof(struct intdouble));
  return 0;
}