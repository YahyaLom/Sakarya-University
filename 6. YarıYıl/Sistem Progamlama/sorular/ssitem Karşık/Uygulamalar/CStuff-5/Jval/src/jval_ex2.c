/* A program that demonstrates the "constructor" functions, and how they help
   when you are using a procedure that takes a jval as a parameter. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "jval.h"

/* Print a jval as an integer, double or string. */

void print_jval(Jval jv, char how)
{
  switch (how) {
    case 'i': printf("%d\n", jv.i); break;
    case 'd': printf("%lg\n", jv.d); break;
    case 's': printf("%s\n", jv.s); break;
    default: fprintf(stderr, "Bad 'how' variable in print_jval: %c\n", how);
             exit(1);
  }
}

/* Call print_jval.  Note that I never have to declare a jval, because I'm using the constructors. */
int main()
{
  print_jval(new_jval_i(10), 'i');
  print_jval(new_jval_d(5.6), 'd');
  print_jval(new_jval_s("Fred"), 's');
  return 0;
}
