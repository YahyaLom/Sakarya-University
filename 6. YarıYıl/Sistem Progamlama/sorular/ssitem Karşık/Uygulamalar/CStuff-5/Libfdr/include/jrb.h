/* Libraries for fields, doubly-linked lists and red-black trees.
   Copyright (C) 2018 James S. Plank */

#ifndef	_JRB_H_
#define	_JRB_H_

#include "jval.h"

/* Main jrb_node.  You only ever use the fields
   flink
   blink
   k.key or k.ikey
   v.val
*/


typedef struct jrb_node {
  unsigned char red;
  unsigned char internal;
  unsigned char left;
  unsigned char roothead;  /* (bit 1 is root, bit 2 is head) */
  struct jrb_node *flink;
  struct jrb_node *blink;
  struct jrb_node *parent;
  Jval key;
  Jval val;
} *JRB;


extern JRB make_jrb();   /* Creates a new rb-tree */


/* Creates a node with key key and val val and inserts it into the tree.
   jrb_insert uses strcmp() as comparison funcion.  jrb_inserti uses <>=,
   jrb_insertg uses func() */

extern JRB jrb_insert_str(JRB tree, char *key, Jval val);
extern JRB jrb_insert_int(JRB tree, int ikey, Jval val);
extern JRB jrb_insert_dbl(JRB tree, double dkey, Jval val);
extern JRB jrb_insert_gen(JRB tree, Jval key, Jval val, int (*func)(Jval,Jval));

/* returns an external node in t whose value is equal k. Returns NULL if
   there is no such node in the tree */

extern JRB jrb_find_str(JRB root, char *key);
extern JRB jrb_find_int(JRB root, int ikey);
extern JRB jrb_find_dbl(JRB root, double dkey);
extern JRB jrb_find_gen(JRB root, Jval, int (*func)(Jval, Jval));


/* returns an external node in t whose value is equal
  k or whose value is the smallest value greater than k. Sets found to
  1 if the key was found, and 0 otherwise.  */

extern JRB jrb_find_gte_str(JRB root, char *key, int *found);
extern JRB jrb_find_gte_int(JRB root, int ikey, int *found);
extern JRB jrb_find_gte_dbl(JRB root, double dkey, int *found);
extern JRB jrb_find_gte_gen(JRB root, Jval key, 
                              int (*func)(Jval, Jval), int *found);


/* Creates a node with key key and val val and inserts it into the 
   tree before/after node nd.  Does not check to ensure that you are 
   keeping the correct order */

extern void jrb_delete_node(JRB node);  /* Deletes and frees a node (but 
                                              not the key or val) */
extern void jrb_free_tree(JRB root);  /* Deletes and frees an entire tree */

extern Jval jrb_val(JRB node);  /* Returns node->v.val -- this is to shut
                                       lint up */

extern int jrb_nblack(JRB n); /* returns # of black nodes in path from
                                    n to the root */
extern int jrb_plength(JRB n);       /* returns the # of nodes in path from
				    n to the root */
 
#define jrb_first(n) (n->flink)
#define jrb_last(n) (n->blink)
#define jrb_next(n) (n->flink)
#define jrb_prev(n) (n->blink)
#define jrb_empty(t) (t->flink == t)
#ifndef jrb_nil
#define jrb_nil(t) (t)
#endif
 
#define jrb_traverse(ptr, lst) \
  for(ptr = jrb_first(lst); ptr != jrb_nil(lst); ptr = jrb_next(ptr))
 
#define jrb_rtraverse(ptr, lst) \
  for(ptr = jrb_last(lst); ptr != jrb_nil(lst); ptr = jrb_prev(ptr))
 
#endif
