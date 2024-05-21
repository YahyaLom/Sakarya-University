/* ni_sort3.c

   James S. Plank
   CS360 lecture notes on red-black trees.
   January, 2015

   This program works like ni_sort1.c and ni_sort2.c, except now it uses a two-level
   tree.  The top level is keyed on the person's score.  Its val is a second level of
   red-black tree, keyed on the person's name, with the person struct in the val.

   To print this tree, you need to do a nested, two-level traversal.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrb.h"
#include "fields.h"

typedef struct {
  char *name;
  int score;
} Person;

int main()
{
  JRB t, tmp, person_tree, t2;
  IS is;
  Person *p;
  int nsize, i;

  is = new_inputstruct(NULL);
  t = make_jrb();

  while (get_line(is) >= 0) {
    if (is->NF > 1) {

      /* Creating the person is just like ni_sort1.c -- please see the comments
         there for how this is done. */

      p = malloc(sizeof(Person));
      p->score = atoi(is->fields[is->NF-1]);

      nsize = strlen(is->fields[0]);
      for (i = 1; i < is->NF-1; i++) nsize += (strlen(is->fields[i])+1);

      p->name = (char *) malloc(sizeof(char)*(nsize+1));
      strcpy(p->name, is->fields[0]);

      nsize = strlen(is->fields[0]);
      for (i = 1; i < is->NF-1; i++) {
        p->name[nsize] = ' ';
        strcpy(p->name+nsize+1, is->fields[i]);
        nsize += strlen(p->name+nsize);
      }

      /* To insert the person, we first test to see if the score is in the
         tree.  If it is not, we create it with an empty red-black tree as a val. 
         In either case, we insert the name into the second-level tree. */

      tmp = jrb_find_int(t, p->score);
      if (tmp == NULL) {
        person_tree = make_jrb();
        jrb_insert_int(t, p->score, new_jval_v((void *) person_tree));
      } else {
        person_tree = (JRB) tmp->val.v;
      }

      jrb_insert_str(person_tree, p->name, new_jval_v((void *) p));
    }
  }

  /* To print the people, we need to do a nested, two-level recursion */

  jrb_traverse(tmp, t) {
    person_tree = (JRB) tmp->val.v;
    jrb_traverse(t2, person_tree) {
      p = (Person *) t2->val.v;
      printf("%-40s %2d\n", p->name, p->score);
    }
  }
  exit(0);
}
