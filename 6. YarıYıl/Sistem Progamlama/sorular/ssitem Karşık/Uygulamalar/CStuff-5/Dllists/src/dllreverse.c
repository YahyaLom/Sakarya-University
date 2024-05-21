/* Printing the lines of standard input in reverse order, by appending
   to a dllist, and then printing the dllist backward. */

#include <stdio.h>
#include <string.h>
#include "fields.h"
#include "dllist.h"

int main()
{
  IS is;
  Dllist l;
  Dllist tmp;

  is = new_inputstruct(NULL);
  l = new_dllist();

  while (get_line(is) >= 0) {
    dll_append(l, new_jval_s(strdup(is->text1)));
  }

  /* Notice how convenient this macro is! */

  dll_rtraverse(tmp, l) printf("%s", tmp->val.s);
  return 0;
}
