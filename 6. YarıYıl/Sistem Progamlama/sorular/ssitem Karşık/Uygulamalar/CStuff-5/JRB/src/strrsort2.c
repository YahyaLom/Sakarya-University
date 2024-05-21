/* Uses red-black trees to sort standard input lexicographically in
   reverse order.  It does this by creating a new comparison function
   revcomp, which simply returns -strcmp().  Now the tree sorts in
   reverse order, so it is traversed in the forward direction. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"

int revcomp(Jval k1, Jval k2)
{
  return -strcmp(k1.s, k2.s);
}

int main()
{
  JRB b;
  JRB bn;
  IS is;

  is = new_inputstruct(NULL);
  b = make_jrb();

  while (get_line(is) >= 0) {
    (void) jrb_insert_gen(b, new_jval_s(strdup(is->text1)), new_jval_v(NULL), revcomp);
  }

  jrb_traverse(bn, b) {
    printf("%s", bn->key.s);
  }
  return 0;
}
