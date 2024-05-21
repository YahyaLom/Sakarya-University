/* This program reads words and puts each word onto one of two lists.  If the word is
   a double, it puts it on one list.  If it's not, it puts it on the other list.  It
   then prints the two lists in two columns, formatted.  Please see the lecture notes
   for a precise definition of the format. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "dllist.h"

int main()
{
  Dllist dl, dtmp;  /* The list for doubles */
  Dllist sl, stmp;  /* The list for strings */
  double d;
  int i;
  IS is;

  /* Create the lists and the inputstruct */

  dl = new_dllist();
  sl = new_dllist();
  is = new_inputstruct(NULL);

  /* Append to the two lists, using sscanf to differentiate between numbers and strings. */

  while (get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
      if (sscanf(is->fields[i], "%lf", &d) == 1) {
        dll_append(dl, new_jval_d(d));
      } else {
        dll_append(sl, new_jval_s(strdup(is->fields[i])));
      }
    }
  }

  /* Print the lines that have both doubles and strings.
     You'll note -- I'm using the sentinel to test for the end of each list */

  dtmp = dl->flink;
  stmp = sl->flink;


  while (dtmp != dl && stmp != sl) {
    printf("%-30s %20.4lf\n", stmp->val.s, dtmp->val.d);
    dtmp = dtmp->flink;
    stmp = stmp->flink;
  }

  /* Now print the lines that have strings only: */

  while (stmp != sl) {
    printf("%-30s %20s\n", stmp->val.s, "");
    stmp = stmp->flink;
  }

  /* And print the lines that have doubles only: */

  while (dtmp != dl) {
    printf("%-30s %20.4lf\n", "", dtmp->val.d);
    dtmp = dtmp->flink;
  }

  return 0;
}
