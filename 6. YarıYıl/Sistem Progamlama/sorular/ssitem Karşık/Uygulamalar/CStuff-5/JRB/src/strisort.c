/* Uses red-black trees to sort standard input lexicographically,
   ignoring upper and lower case.  It does this by creating a separate key,
   which is the string in upper case.  It sorts with that string, and stores
   the original string in the val. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jrb.h"
#include "fields.h"

int main()
{
  JRB b;
  JRB bn;
  IS is;
  int i;
  char *upper_case;

  is = new_inputstruct(NULL);
  b = make_jrb();

  while (get_line(is) >= 0) {
    upper_case = strdup(is->text1);
    for (i = 0; upper_case[i] != '\0'; i++) {
      if (upper_case[i] >= 'a' && upper_case[i] <= 'z') upper_case[i] += ('A'-'a');
    }
    (void) jrb_insert_str(b, upper_case, new_jval_s(strdup(is->text1)));
  }

  jrb_traverse(bn, b) {
    printf("%s", bn->val.s);
  }
  return 0;
}
