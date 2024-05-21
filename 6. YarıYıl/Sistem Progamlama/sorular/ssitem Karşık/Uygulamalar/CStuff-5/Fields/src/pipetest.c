/* pipetest.c counts the number of lines in all the .c files in the  
   src directory.  It does this by using pipe_inputstruct to get
   the standard output of the cat command into an inputstruct */

#include <stdio.h>
#include <stdlib.h>
#include "fields.h"

int main()
{
  IS is;
  int nlines;

  is = pipe_inputstruct("cat src/*.c");
  if (is == NULL) { perror("cat src/*.c"); exit(1); }

  nlines = 0;
  while (get_line(is) >= 0) nlines++;

  printf("# lines in src/*.c: %d\n", nlines);
 
  return 0;
}
