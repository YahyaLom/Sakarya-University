/* A buggy program to print the last 10 lines of standard input. */

#include <stdio.h>
#include <stdlib.h>
#include "fields.h"

int main(int argc, char **argv) 
{
  IS is;
  int i, n;
  char *lines[10];    /* This array will hold the last 10 lines of standard input. */
  
  /* Read the lines of standard input, and only keep the last ten. */

  is = new_inputstruct(NULL);
  n = 0;
  while (get_line(is) >= 0) {
    lines[n%10] = is->text1;        /* This is the bad line -- it doesn't copy the string. */
    n++;
  }

  /* Print the last 10 lines, or fewer if there are fewer lines. 
     Remember that is->text1 has a newline at the end. */

  i = (n >= 10) ? (n-10) : 0;                      /* This is the line number of the 10th line from the end. */
  for ( ; i < n; i++) printf("%s", lines[i%10]);   /* Print this line to the last line. */

  return 0;
}
