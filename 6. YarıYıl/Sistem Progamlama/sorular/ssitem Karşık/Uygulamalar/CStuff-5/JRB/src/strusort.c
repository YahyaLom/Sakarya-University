/* Uses red-black trees to sort standard input lexicographically, and
   it removes duplicate lines.  It does this by checking for a line
   before inserting it into the tree. */

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
    if (jrb_find_str(b, is->text1) == NULL) {                           /* Only insert if you don't find the line there. */
      (void) jrb_insert_str(b, strdup(is->text1), new_jval_v(NULL));
    }
  }

  jrb_traverse(bn, b) {
    printf("%s", bn->key.s);
  }
  return 0;
}
