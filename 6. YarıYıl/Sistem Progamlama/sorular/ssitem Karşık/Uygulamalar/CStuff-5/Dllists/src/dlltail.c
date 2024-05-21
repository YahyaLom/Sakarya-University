/* This program implements tail using a dllist.  It reads lines onto the dllist until
   it contains the proper number of lines.  Then, each time it reads a line, it appends
   to the dllist and then deletes the first line of the dllist.  At the end, it simply
   prints the dllist. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fields.h"
#include "dllist.h"

int main(int argc, char **argv)
{
  IS is;
  int n;
  Dllist l;
  Dllist tmp;

  /* Error check and read the number of lines to maintain. */

  if (argc != 2) {
    fprintf(stderr, "usage: dlltail n\n");
    exit(1);
  }
  n = atoi(argv[1]);
  if (n < 0) {
    fprintf(stderr, "usage: dlltail n  -- n must be >= 0\n");
    exit(1);
  }

  /* Create the inputstruct and dllist */

  is = new_inputstruct(NULL);
  l = new_dllist();

  /* Read each line and append to the dllist. */

  while (get_line(is) >= 0) {
    dll_append(l, new_jval_s(strdup(is->text1)));

    if (is->line > n) {          /* If the dllist is too big, delete the first line on it. */
      free(l->flink->val.s);     /* You have to free it, becuase you called strdup() to create it. */
      dll_delete_node(l->flink);
    }
  }

  /* At the end, print the dllist -- again note the convenience of dll_traverse. */

  dll_traverse(tmp, l) printf("%s", tmp->val.s);
  return 0;
}
