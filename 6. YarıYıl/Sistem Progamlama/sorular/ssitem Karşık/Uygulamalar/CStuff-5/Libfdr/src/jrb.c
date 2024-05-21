/* Libraries for fields, doubly-linked lists and red-black trees.
   Copyright (C) 2018 James S. Plank */

/* Revision 1.2.  Jim Plank */

/* Original code by Jim Plank (plank@cs.utk.edu) */
/* modified for THINK C 6.0 for Macintosh by Chris Bartley */
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "jrb.h"
 
typedef unsigned long UL;

static void mk_new_int(JRB l, JRB r, JRB p, int il);
static JRB lprev(JRB n);
static JRB rprev(JRB n);
static void recolor(JRB n);
static void single_rotate(JRB y, int l);
static void jrb_print_tree(JRB t, int level);
static void jrb_iprint_tree(JRB t, int level);
 
#define isred(n) (n->red)
#define isblack(n) (!isred(n))
#define isleft(n) (n->left)
#define isright(n) (!isleft(n))
#define isint(n) (n->internal)
#define isext(n) (!isint(n))
#define ishead(n) (n->roothead & 2)
#define isroot(n) (n->roothead & 1)
#define getlext(n) ((struct jrb_node *)(n->key.v))
#define setlext(node, val) node->key.v = (void *) (val)
#define getrext(n) ((struct jrb_node *)(n->val.v))
#define setrext(node, value) node->val.v = (void *) (value)
#define setred(n) n->red = 1
#define setblack(n) n->red = 0
#define setleft(n) n->left = 1
#define setright(n) n->left = 0
#define sethead(n) (n->roothead |= 2)
#define setroot(n) (n->roothead |= 1)
#define setint(n) n->internal = 1
#define setext(n) n->internal = 0
#define setnormal(n) n->roothead = 0
#define sibling(n) ((isleft(n)) ? n->parent->blink : n->parent->flink)
 
static void insert(JRB item, JRB list)	/* Inserts to the end of a list */
{
  JRB last_node;
 
  last_node = list->blink;
 
  list->blink = item;
  last_node->flink = item;
  item->blink = last_node;
  item->flink = list;
}
 
static void delete_item(JRB item)		/* Deletes an arbitrary iterm */
{
  item->flink->blink = item->blink;
  item->blink->flink = item->flink;
}

#define mk_new_ext(new, kkkey, vvval) {\
  new = (JRB) malloc(sizeof(struct jrb_node));\
  new->val = vvval;\
  new->key = kkkey;\
  setext(new);\
  setblack(new);\
  setnormal(new);\
}
 
static void mk_new_int(JRB l, JRB r, JRB p, int il)
{
  JRB newnode;
 
  newnode = (JRB) malloc(sizeof(struct jrb_node));
  setint(newnode);
  setred(newnode);
  setnormal(newnode);
  newnode->flink = l;
  newnode->blink = r;
  newnode->parent = p;
  setlext(newnode, l);
  setrext(newnode, r);
  l->parent = newnode;
  r->parent = newnode;
  setleft(l);
  setright(r);
  if (ishead(p)) {
    p->parent = newnode;
    setroot(newnode);
  } else if (il) {
    setleft(newnode);
    p->flink = newnode;
  } else {
    setright(newnode);
    p->blink = newnode;
  }
  recolor(newnode);
}  
  
   
JRB lprev(JRB n)
{
  if (ishead(n)) return n;
  while (!isroot(n)) {
    if (isright(n)) return n->parent;
    n = n->parent;
  }
  return n->parent;
}
 
JRB rprev(JRB n)
{
  if (ishead(n)) return n;
  while (!isroot(n)) {
    if (isleft(n)) return n->parent;
    n = n->parent;
  }
  return n->parent;
}
 
JRB make_jrb()
{
  JRB head;
 
  head = (JRB) malloc (sizeof(struct jrb_node));
  head->flink = head;
  head->blink = head;
  head->parent = head;
  head->key.s = "";
  sethead(head);
  return head;
}
 
JRB jrb_find_gte_str(JRB n, char *key, int *fnd)
{
  int cmp;
 
  *fnd = 0;
  if (!ishead(n)) {
    fprintf(stderr, "jrb_find_gte_str called on non-head 0x%lx\n", (UL) n);
    exit(1);
  }
  if (n->parent == n) return n;
  cmp = strcmp(key, n->blink->key.s);
  if (cmp == 0) {
    *fnd = 1;
    return n->blink; 
  }
  if (cmp > 0) return n; 
  else n = n->parent;
  while (1) {
    if (isext(n)) return n;
    cmp = strcmp(key, getlext(n)->key.s);
    if (cmp == 0) {
      *fnd = 1;
      return getlext(n);
    }
    if (cmp < 0) n = n->flink ; else n = n->blink;
  }
}
 
JRB jrb_find_str(JRB n, char *key)
{
  int fnd;
  JRB j;
  j = jrb_find_gte_str(n, key, &fnd);
  if (fnd) return j; else return NULL;
}
 
JRB jrb_find_gte_int(JRB n, int ikey, int *fnd)
{
  *fnd = 0;
  if (!ishead(n)) {
    fprintf(stderr, "jrb_find_gte_int called on non-head 0x%lx\n", (UL) n);
    exit(1);
  }
  if (n->parent == n) return n;
  if (ikey == n->blink->key.i) {
    *fnd = 1;
    return n->blink; 
  }
  if (ikey > n->blink->key.i) return n; 
  else n = n->parent;
  while (1) {
    if (isext(n)) return n;
    if (ikey == getlext(n)->key.i) {
      *fnd = 1;
      return getlext(n);
    }
    n = (ikey < getlext(n)->key.i) ? n->flink : n->blink;
  }
}
 
JRB jrb_find_int(JRB n, int ikey)
{
  int fnd;
  JRB j;

  j = jrb_find_gte_int(n, ikey, &fnd);
  if (fnd) return j; else return NULL;
}
 
JRB jrb_find_gte_dbl(JRB n, double dkey, int *fnd)
{
  *fnd = 0;
  if (!ishead(n)) {
    fprintf(stderr, "jrb_find_gte_dbl called on non-head 0x%lx\n", (UL) n);
    exit(1);
  }
  if (n->parent == n) return n;
  if (dkey == n->blink->key.d) {
    *fnd = 1;
    return n->blink; 
  }
  if (dkey > n->blink->key.d) return n; 
  else n = n->parent;
  while (1) {
    if (isext(n)) return n;
    if (dkey == getlext(n)->key.d) {
      *fnd = 1;
      return getlext(n);
    }
    n = (dkey < getlext(n)->key.d) ? n->flink : n->blink;
  }
}
 
JRB jrb_find_dbl(JRB n, double dkey)
{
  int fnd;
  JRB j;

  j = jrb_find_gte_dbl(n, dkey, &fnd);
  if (fnd) return j; else return NULL;
}
 
JRB jrb_find_gte_gen(JRB n, Jval key,int (*fxn)(Jval, Jval), int *fnd)
{
  int cmp;
 
  *fnd = 0;
  if (!ishead(n)) {
    fprintf(stderr, "jrb_find_gte_str called on non-head 0x%lx\n", (UL) n);
    exit(1);
  }
  if (n->parent == n) return n;
  cmp = (*fxn)(key, n->blink->key);
  if (cmp == 0) {
    *fnd = 1;
    return n->blink; 
  }
  if (cmp > 0) return n; 
  else n = n->parent;
  while (1) {
    if (isext(n)) return n;
    cmp = (*fxn)(key, getlext(n)->key);
    if (cmp == 0) {
      *fnd = 1;
      return getlext(n);
    }
    if (cmp < 0) n = n->flink ; else n = n->blink;
  }
}
 
JRB jrb_find_gen(JRB n, Jval key, int (*fxn)(Jval, Jval))
{
  int fnd;
  JRB j;

  j = jrb_find_gte_gen(n, key, fxn, &fnd);
  if (fnd) return j; else return NULL;
}
 
static JRB jrb_insert_b(JRB n, Jval key, Jval val)
{
  JRB newleft, newright, newnode, list, p;
 
  if (ishead(n)) {
    if (n->parent == n) {         /* Tree is empty */
      mk_new_ext(newnode, key, val);
      insert(newnode, n);
      n->parent = newnode;
      newnode->parent = n;
      setroot(newnode);
      return newnode;
    } else {
      mk_new_ext(newright, key, val);
      insert(newright, n);
      newleft = newright->blink;
      setnormal(newleft);
      mk_new_int(newleft, newright, newleft->parent, isleft(newleft));
      p = rprev(newright);
      if (!ishead(p)) setlext(p, newright);
      return newright;
    }
  } else {
    mk_new_ext(newleft, key, val);
    insert(newleft, n);
    setnormal(n);
    mk_new_int(newleft, n, n->parent, isleft(n));
    p = lprev(newleft);
    if (!ishead(p)) setrext(p, newleft);
    return newleft;    
  }
}
 
static void recolor(JRB n)
{  
  JRB p, gp, s;
  int done = 0;
 
  while(!done) {
    if (isroot(n)) {
      setblack(n);
      return;
    }
 
    p = n->parent;
 
    if (isblack(p)) return;
    
    if (isroot(p)) {
      setblack(p);
      return;
    }
 
    gp = p->parent;
    s = sibling(p);
    if (isred(s)) {
      setblack(p);
      setred(gp);
      setblack(s);
      n = gp;
    } else {
      done = 1;
    }
  }
  /* p's sibling is black, p is red, gp is black */
  
  if ((isleft(n) == 0) == (isleft(p) == 0)) {
    single_rotate(gp, isleft(n));
    setblack(p);
    setred(gp);
  } else {
    single_rotate(p, isleft(n));
    single_rotate(gp, isleft(n));
    setblack(n);
    setred(gp);
  }
}
 
static void single_rotate(JRB y, int l)
{
  int rl, ir;
  JRB x, yp;
  char *tmp;
 
  ir = isroot(y);
  yp = y->parent;
  if (!ir) {
    rl = isleft(y);
  }
  
  if (l) {
    x = y->flink;
    y->flink = x->blink;
    setleft(y->flink);
    y->flink->parent = y;
    x->blink = y;
    setright(y);  
  } else {
    x = y->blink;
    y->blink = x->flink;
    setright(y->blink);
    y->blink->parent = y;
    x->flink = y;
    setleft(y);  
  }
 
  x->parent = yp;
  y->parent = x;
  if (ir) {
    yp->parent = x;
    setnormal(y);
    setroot(x);
  } else {
    if (rl) {
      yp->flink = x;
      setleft(x);
    } else {
      yp->blink = x;
      setright(x);
    }
  }
}
    
void jrb_delete_node(JRB n)
{
  JRB s, p, gp;
  char ir;
 
  if (isint(n)) {
    fprintf(stderr, "Cannot delete an internal node: 0x%lx\n", (UL) n);
    exit(1);
  }
  if (ishead(n)) {
    fprintf(stderr, "Cannot delete the head of an jrb_tree: 0x%lx\n", (UL) n);
    exit(1);
  }
  delete_item(n); /* Delete it from the list */
  p = n->parent;  /* The only node */
  if (isroot(n)) {
    p->parent = p;
    free(n);
    return;
  } 
  s = sibling(n);    /* The only node after deletion */
  if (isroot(p)) {
    s->parent = p->parent;
    s->parent->parent = s;
    setroot(s);
    free(p);
    free(n);
    return;
  }
  gp = p->parent;  /* Set parent to sibling */
  s->parent = gp;
  if (isleft(p)) {
    gp->flink = s;
    setleft(s);
  } else {
    gp->blink = s;
    setright(s);
  }
  ir = isred(p);
  free(p);
  free(n);
  
  if (isext(s)) {      /* Update proper rext and lext values */
    p = lprev(s); 
    if (!ishead(p)) setrext(p, s);
    p = rprev(s);
    if (!ishead(p)) setlext(p, s);
  } else if (isblack(s)) {
    fprintf(stderr, "DELETION PROB -- sib is black, internal\n");
    exit(1);
  } else {
    p = lprev(s);
    if (!ishead(p)) setrext(p, s->flink);
    p = rprev(s);
    if (!ishead(p)) setlext(p, s->blink);
    setblack(s);
    return;
  }
 
  if (ir) return;
 
  /* Recolor */
  
  n = s;
  p = n->parent;
  s = sibling(n);
  while(isblack(p) && isblack(s) && isint(s) && 
        isblack(s->flink) && isblack(s->blink)) {
    setred(s);
    n = p;
    if (isroot(n)) return;
    p = n->parent;
    s = sibling(n);
  }
  
  if (isblack(p) && isred(s)) {  /* Rotation 2.3b */
    single_rotate(p, isright(n));
    setred(p);
    setblack(s);
    s = sibling(n);
  }
    
  { JRB x, z; char il;
    
    if (isext(s)) {
      fprintf(stderr, "DELETION ERROR: sibling not internal\n");
      exit(1);
    }
 
    il = isleft(n);
    x = il ? s->flink : s->blink ;
    z = sibling(x);
 
    if (isred(z)) {  /* Rotation 2.3f */
      single_rotate(p, !il);
      setblack(z);
      if (isred(p)) setred(s); else setblack(s);
      setblack(p);
    } else if (isblack(x)) {   /* Recoloring only (2.3c) */
      if (isred(s) || isblack(p)) {
        fprintf(stderr, "DELETION ERROR: 2.3c not quite right\n");
        exit(1);
      }
      setblack(p);
      setred(s);
      return;
    } else if (isred(p)) { /* 2.3d */
      single_rotate(s, il);
      single_rotate(p, !il);
      setblack(x);
      setred(s);
      return;
    } else {  /* 2.3e */
      single_rotate(s, il);
      single_rotate(p, !il);
      setblack(x);
      return;
    }
  }
}
 
 
void jrb_print_tree(JRB t, int level)
{
  int i;
  if (ishead(t) && t->parent == t) {
    printf("tree 0x%lx is empty\n", (UL) t);
  } else if (ishead(t)) {
    printf("Head: 0x%lx.  Root = 0x%lx\n", (UL) t, (UL) t->parent);
    jrb_print_tree(t->parent, 0);
  } else {
    if (isext(t)) {
      for (i = 0; i < level; i++) putchar(' ');
      printf("Ext node 0x%lx: %c,%c: p=0x%lx, k=%s\n", 
              (UL) t, isred(t)?'R':'B', isleft(t)?'l':'r', (UL) t->parent, t->key.s);
    } else {
      jrb_print_tree(t->flink, level+2);
      jrb_print_tree(t->blink, level+2);
      for (i = 0; i < level; i++) putchar(' ');
      printf("Int node 0x%lx: %c,%c: l=0x%lx, r=0x%lx, p=0x%lx, lr=(%s,%s)\n", 
              (UL) t, isred(t)?'R':'B', isleft(t)?'l':'r', (UL) t->flink, 
              (UL) t->blink, 
              (UL) t->parent, getlext(t)->key.s, getrext(t)->key.s);
    }
  }
}
 
void jrb_iprint_tree(JRB t, int level)
{
  int i;
  if (ishead(t) && t->parent == t) {
    printf("tree 0x%lx is empty\n", (UL) t);
  } else if (ishead(t)) {
    printf("Head: 0x%lx.  Root = 0x%lx, < = 0x%lx, > = 0x%lx\n", 
            (UL) t, (UL) t->parent, (UL) t->blink, (UL) t->flink);
    jrb_iprint_tree(t->parent, 0);
  } else {
    if (isext(t)) {
      for (i = 0; i < level; i++) putchar(' ');
      printf("Ext node 0x%lx: %c,%c: p=0x%lx, <=0x%lx, >=0x%lx k=%d\n", 
              (UL) t, isred(t)?'R':'B', isleft(t)?'l':'r', (UL) t->parent, 
              (UL) t->blink, (UL) t->flink, t->key.i);
    } else {
      jrb_iprint_tree(t->flink, level+2);
      jrb_iprint_tree(t->blink, level+2);
      for (i = 0; i < level; i++) putchar(' ');
      printf("Int node 0x%lx: %c,%c: l=0x%lx, r=0x%lx, p=0x%lx, lr=(%d,%d)\n", 
              (UL) t, isred(t)?'R':'B', isleft(t)?'l':'r', (UL) t->flink, 
              (UL) t->blink, 
              (UL) t->parent, getlext(t)->key.i, getrext(t)->key.i);
    }
  }
}
      
int jrb_nblack(JRB n)
{
  int nb;
  if (ishead(n) || isint(n)) {
    fprintf(stderr, "ERROR: jrb_nblack called on a non-external node 0x%lx\n", (UL) n);
    exit(1);
  }
  nb = 0;
  while(!ishead(n)) {
    if (isblack(n)) nb++;
    n = n->parent;
  }
  return nb;
}
 
int jrb_plength(JRB n)
{
  int pl;
  if (ishead(n) || isint(n)) {
    fprintf(stderr, "ERROR: jrb_plength called on a non-external node 0x%lx\n", (UL) n);
    exit(1);
  }
  pl = 0;
  while(!ishead(n)) {
    pl++;
    n = n->parent;
  }
  return pl;
}
 
void jrb_free_tree(JRB n)
{
  if (!ishead(n)) {
    fprintf(stderr, "ERROR: Rb_free_tree called on a non-head node\n");
    exit(1);
  }
 
  while(jrb_first(n) != jrb_nil(n)) {
    jrb_delete_node(jrb_first(n));
  }
  free(n);
}
 
Jval jrb_val(JRB n)
{
  return n->val;
}
 
static JRB jrb_insert_a(JRB nd, Jval key, Jval val)
{
  return jrb_insert_b(nd->flink, key, val);
}

JRB jrb_insert_str(JRB tree, char *key, Jval val)
{
  Jval k;
  int fnd;

  k.s = key;
  return jrb_insert_b(jrb_find_gte_str(tree, key, &fnd), k, val);
}

JRB jrb_insert_int(JRB tree, int ikey, Jval val)
{
  Jval k;
  int fnd;

  k.i = ikey;
  return jrb_insert_b(jrb_find_gte_int(tree, ikey, &fnd), k, val);
}

JRB jrb_insert_dbl(JRB tree, double dkey, Jval val)
{
  Jval k;
  int fnd;

  k.d = dkey;
  return jrb_insert_b(jrb_find_gte_dbl(tree, dkey, &fnd), k, val);
}

JRB jrb_insert_gen(JRB tree, Jval key, Jval val,
                          int (*func)(Jval, Jval))
{ 
  int fnd;

  return jrb_insert_b(jrb_find_gte_gen(tree, key, func, &fnd), key, val);
}


