/* Libraries for fields, doubly-linked lists and red-black trees.
   Copyright (C) 2018 James S. Plank */

#ifndef _DLLIST_H_
#define _DLLIST_H_

#include "jval.h"

typedef struct dllist {
  struct dllist *flink;
  struct dllist *blink;
  Jval val;
} *Dllist;

extern Dllist new_dllist();
extern void free_dllist(Dllist);

extern void dll_append(Dllist, Jval);
extern void dll_prepend(Dllist, Jval);
extern void dll_insert_b(Dllist, Jval);
extern void dll_insert_a(Dllist, Jval);

extern void dll_delete_node(Dllist);
extern int dll_empty(Dllist);

extern Jval dll_val(Dllist);

#define dll_first(d) ((d)->flink)
#define dll_next(d) ((d)->flink)
#define dll_last(d) ((d)->blink)
#define dll_prev(d) ((d)->blink)
#define dll_nil(d) (d)

#define dll_traverse(ptr, list) \
  for (ptr = list->flink; ptr != list; ptr = ptr->flink)
#define dll_rtraverse(ptr, list) \
  for (ptr = list->blink; ptr != list; ptr = ptr->blink)

#endif
