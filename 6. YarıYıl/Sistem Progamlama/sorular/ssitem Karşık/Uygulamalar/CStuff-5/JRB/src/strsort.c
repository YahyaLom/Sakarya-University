/* Strsort.c - sort lines of input lexicographically using JRB's. */

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

  /* Create the JRB and the inputstruct */

  is = new_inputstruct(NULL);
  b = make_jrb();

  /* Read each line and insert it into the jrb as a key, and with NULL as the val. */

  while (get_line(is) >= 0) {
    (void) jrb_insert_str(b, strdup(is->text1), new_jval_v(NULL));
  }

  /* Traverse the tree and print out the keys. */

  jrb_traverse(bn, b) {
    printf("%s", bn->key.s);
  }
  return 0;
}
