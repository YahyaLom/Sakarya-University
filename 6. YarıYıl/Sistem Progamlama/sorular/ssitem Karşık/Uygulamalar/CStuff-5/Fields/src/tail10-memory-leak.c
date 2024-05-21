/* Here we fix the bug of tail10-bad.c by calling strdup().
   It does introduce a memory leak, though. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fields.h"

int main(int argc, char **argv) 
{
  IS is;
  int i, n;
  char *lines[10];
  
  is = new_inputstruct(NULL);
  n = 0;
  while (get_line(is) >= 0) {
    lines[n%10] = strdup(is->text1);       /* This is the only change - we call strdup(). */
    n++;
  }

  i = (n >= 10) ? (n-10) : 0;
  for ( ; i < n; i++) printf("%s", lines[i%10]);

  return 0;
}
