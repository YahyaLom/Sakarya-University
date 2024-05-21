/* Same as nsort2, but instead it uses a two-level red-black tree.
   If this is confusing to you, please read the next example in the lecture
   notes, which does a very similar thing. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"

int main()
{
  JRB level_1, level_2;
  JRB bn, bn2;
  IS is;

  is = new_inputstruct(NULL);
  level_1 = make_jrb();

  /* Read each line and look for it in the first level tree. */

  while (get_line(is) >= 0) {
    bn = jrb_find_int(level_1, atoi(is->text1));

    /* If it's not there, insert it with an empty jrb as its val. */

    if (bn == NULL) {
      bn = jrb_insert_int(level_1, atoi(is->text1), new_jval_v((void *)make_jrb()));
    }

    /* Now insert the string into the second level tree. */

    level_2 = (JRB) jval_v(bn->val);
    jrb_insert_str(level_2, strdup(is->text1), new_jval_v(NULL));
  }

  /* To print the tree, you need to do a nested double-traversal. */

  jrb_traverse(bn, level_1) {
    level_2 = (JRB) jval_v(bn->val);
    jrb_traverse(bn2, level_2) {
      printf("%s", bn2->key.s);
    }
  }

  return 0;
}
