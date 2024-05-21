/* While C doesn't let you copy arrays, it lets you copy a struct that holds
   an array.  I don't think this really makes sense, but there is it.  In this
   code, we copy 4000 bytes in a single statement. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a[1000];
} SID;

int main()
{
  SID s1, s2;
  int i;

  for (i = 0; i < 1000; i++) s1.a[i] = i;       /* Set s1. */

  s2 = s1;       /* This statement copies 4000 bytes. */

  for (i = 0; i < 1000; i++) printf("%4d %4d\n", s1.a[i], s2.a[i]);  /* Print s1 and s2. */
 
  return 0;
}