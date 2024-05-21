/* This fixes the memory leak in tail10-memory-leak.c */

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
    if (n >= 10) free(lines[n%10]);         /* This line prevents the memory leak. */
    lines[n%10] = strdup(is->text1);
    n++;
  }

  i = (n >= 10) ? (n-10) : 0;
  for ( ; i < n; i++) printf("%s", lines[i%10]);

  return 0;
}
