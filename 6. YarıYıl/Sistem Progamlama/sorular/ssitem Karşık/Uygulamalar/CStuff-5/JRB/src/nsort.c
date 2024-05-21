/* Uses red-black trees to sort like sort -n -- i.e. it treats each
   line as an integer, and sorts it that way.  If the lines are not
   integers, or there are duplicate lines, anything goes.  */

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

  /* This is the first time that we're using a different key and val.
     The number is the key and the string is the val. */

  while (get_line(is) >= 0) {
    (void) jrb_insert_int(b, atoi(is->text1), new_jval_s(strdup(is->text1)));
  }

  /* Accordingly, we print out the val, and not the key. */

  jrb_traverse(bn, b) {
    printf("%s", bn->val.s);
  }
  return 0;
}
