/* The proper version of this program just uses doubles for total and n.  It's not
   like there are ints that can't be stored in a double, and you're using floating
   point division, so you need the doubles. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  double total;
  double n;
  int j;

  n = 0;
  total = 0;
  
  while (scanf("%d", &j) == 1) {
    total += j;
    n++;
  }

  if (n == 0) exit(1);
  printf("Average = %lf\n", total/n);

  return 0;
}

