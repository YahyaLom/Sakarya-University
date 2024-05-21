/* This program is more like tail -- it takes the number of lines, n, 
   as a command line argument, and prints the last n lines of standard input. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"

int main(int argc, char **argv)
{
  char **lastn;
  int nlines, i, n;
  IS is;

  /* Error check the command line. */

  if (argc != 2) { fprintf(stderr, "usage: tailany1 n\n"); exit(1); }
  if (sscanf(argv[1], "%d", &n) == 0 || n <= 0) {
    fprintf(stderr, "usage: tailany1 n\n");
    fprintf(stderr, "       bad n: %s\n", argv[1]);
    exit(1);
  }

  /* Allocate the array */

  lastn = (char **) malloc(sizeof(char *)*n);
  if (lastn == NULL) { perror("malloc"); exit(1); }
 
  /* Allocate the IS */

  is = new_inputstruct(NULL);
  if (is == NULL) { perror("stdin"); exit(1); }

  /* Read the input */

  nlines = 0;
  while (get_line(is) >= 0) {
    if (nlines >= n) free(lastn[nlines%n]);     /* Prevent the memory leak. */
    lastn[nlines%n] = strdup(is->text1);
    nlines++;
  }

  /* Print the last n lines */

  i = (nlines < n) ? 0 : nlines-n;
  for ( ; i < nlines; i++) {
    printf("%s", lastn[i%n]);
  }

  /* Don't bother freeing stuff when you're just exiting anyway. */

  return 0;
}

