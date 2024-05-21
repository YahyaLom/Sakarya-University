/* Uses red-black trees to sort standard input lexicographically in reverse order.  
   It does this by traversing the tree in reverse order using jrb_rtraverse.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"

int main()
{
  JRB b;
  JRB bn;
  IS is;

  is = new_inputstruct(NULL);
  b = make_jrb();

  while (get_line(is) >= 0) {
    (void) jrb_insert_str(b, strdup(is->text1), new_jval_v(NULL));
  }

  /* Everything is the same as src/strsort.c except this rtraverse line. */

  jrb_rtraverse(bn, b) {
    printf("%s", bn->key.s);
  }
  return 0;
}
