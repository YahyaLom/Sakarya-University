/* A program that abuses jvals.  It averages integers on standard input. */

#include <stdio.h>
#include <stdlib.h>
#include "jval.h"

int main()
{
  Jval total;      /* You'll note, no types other than Jvals. */
  Jval j;
  Jval n;

  n.i = 0;         /* n and j are always treated as ints.  They should be ints. */
  total.i = 0;     /* Total starts as an int */
  
  while (scanf("%d", &(j.i)) == 1) {
    total.i += j.i;
    n.i++;
  }

  /* And then total is used as a double.  You should simply use a double.... */

  total.d = ((double) total.i) / ((double) n.i);
  printf("Average = %lf\n", total.d);
  return 0;
}

