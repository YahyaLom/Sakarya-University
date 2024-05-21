/* Use the fields library to print each word on standard input, labeled with its line number. */

#include <stdio.h>
#include <stdlib.h>
#include "fields.h"

int main(int argc, char **argv)
{
  IS is;
  int i;

  if (argc != 2) { fprintf(stderr, "usage: printwords filename\n"); exit(1); }
 
  /* Open the file as an inputstruct.  Error check. */

  is = new_inputstruct(argv[1]);
  if (is == NULL) {
    perror(argv[1]);
    exit(1);
  }

  /* Read each line with get_line().  Print out each word. */

  while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
      printf("%d: %s\n", is->line, is->fields[i]);
    }
  }

  /* Free up the memory allocated with new_inputstruct, and
     close the open file.  This is not necessary in this program, 
     since we are exiting anyway, but I just want to show how you free it up. */

  jettison_inputstruct(is);
  return 0;
}
