#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"
#include "dllist.h"

/* We have one of these for every golfer.  Each golfer will end up being on two
   red-black trees.  The first is one keyed on the golfer's name, so that we can
   find the golfer when we read in the score files.  The second is keyed first
   on the golfer's tournaments-played, and then average score. */

typedef struct {
  char *name;
  int ntourn;
  int tscore;
  Dllist scores;
} Golfer;

/* For each golfer, we are going to track his score in each tournament that he
   played in.  This data structure keeps that information. */

typedef struct {
  char *tname;
  int score;
} Score;

/* This is how we compare golfers in the second of the red-black trees described above.
   First we compare their number of tournaments, and then their average score. */

int golfercomp(Jval j1, Jval j2)
{
  Golfer *g1, *g2;

  g1 = (Golfer *) j1.v;
  g2 = (Golfer *) j2.v;

  if (g1->ntourn > g2->ntourn) return 1;
  if (g1->ntourn < g2->ntourn) return -1;
  if (g1->tscore < g2->tscore) return 1;
  if (g1->tscore > g2->tscore) return -1;
  return 0;
}

int main(int argc, char **argv)
{
  JRB golfers;          /* This is the red-black tree sorted by golfer name. */
  JRB sorted_golfers;   /* This is the red-black tree sorted with the above comparison fxn. */

  JRB rnode;            /* These are all temporary variables. */
  Golfer *g;
  Score *s;
  int i, fn;
  int tmp;
  IS is;
  char name[1000];
  Dllist dnode;

  if (argc <= 1) {
    fprintf(stderr, "usage: golf score-files\n");
    exit(1);
  }

  /* In this large block of code, we are reading in all of the golfers from the 
     files, and storing them in the tree (golfers) sorted by name. */

  golfers = make_jrb();

  for (fn = 1; fn < argc; fn++) {
    is = new_inputstruct(argv[fn]);
    if (is == NULL) { perror(argv[fn]); exit(1); }

    /* Error check */

    while(get_line(is) >= 0) {
      if (is->NF < 4 || strcmp(is->fields[is->NF-2], "F") != 0 ||
          sscanf(is->fields[is->NF-1], "%d", &tmp) != 1) {
        fprintf(stderr, "File %s, Line %d: Not the proper format\n",
          is->name, is->line);
        exit(1);
      }
      
      /* Create the golfer's name inefficiently (I'm being lazy and calling strcat) */

      strcpy(name, is->fields[0]);
      for (i = 1; i < is->NF-3; i++) {
        strcat(name, " ");
        strcat(name, is->fields[i]);
      }
      
      /* Find the golfer, and if he's not there, create him */

      rnode = jrb_find_str(golfers, name);
      if (rnode == NULL) {
        g = (Golfer *) malloc(sizeof(Golfer));
        g->name = strdup(name);
        g->ntourn = 0;
        g->tscore = 0;
        g->scores = new_dllist();
        jrb_insert_str(golfers, g->name, new_jval_v(g));
      } else {
        g = (Golfer *) rnode->val.v;
      }

      /* Create the score struct for the golfer/tournament and 
         add it to the golfer's score list. */

      s = (Score *) malloc(sizeof(Score));
      s->tname = argv[fn];
      s->score = atoi(is->fields[is->NF-1]);
      g->ntourn++;
      g->tscore += s->score;
      dll_append(g->scores, new_jval_v(s));
    }
    jettison_inputstruct(is);
  }

  /* Now, build the second tree sorted on number of tournaments and lowest score.
     We'll do this by using a general purpose rb-tree where the comparison
     function compares golfers using number of tournaments and lowest score */

  sorted_golfers = make_jrb();

  jrb_traverse(rnode, golfers) {
    jrb_insert_gen(sorted_golfers, rnode->val, JNULL, golfercomp);
  }

  /* Traverse this new tree and print out each golfer. */

  jrb_rtraverse(rnode, sorted_golfers) {
    g = (Golfer *) rnode->key.v;
    printf("%-40s : %3d tournament%1s : %7.2f\n", g->name, g->ntourn,
           (g->ntourn == 1) ? "" : "s", 
           (float) g->tscore / (float) g->ntourn);
    dll_traverse(dnode, g->scores) {
      s = (Score *) dnode->val.v;
      printf("  %3d : %s\n", s->score, s->tname);
    }
  }
  return 0;
}

