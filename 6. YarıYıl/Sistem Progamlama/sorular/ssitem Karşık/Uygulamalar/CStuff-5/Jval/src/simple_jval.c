/* This program shows the very simple use of a jval. */

#include <stdio.h>
#include <stdlib.h>
#include "jval.h"

int main()
{
  Jval jv;

  /* Set and use as an integer. */

  jv.i = 10;
  printf("Using the jval as an integer: %d\n", jv.i);

  /* Set and use as a double. */

  jv.d = 5.6;
  printf("Using the jval as a double: %.2lf\n", jv.d);

  /* Set and use as a char *. */

  jv.s = "Fred";
  printf("Using the jval as a char *: %s\n", jv.s);

  /* Since I've set it as a (char *), I shouldn't use it as a double. */

  printf("If I now print the jval as a double, I get garbage: %lg\n", jv.d);
  return 0;
}
