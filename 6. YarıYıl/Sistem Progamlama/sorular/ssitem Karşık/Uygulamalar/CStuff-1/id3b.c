#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a[1000];
} SID;

void a(SID s)    /* Although this procedure changes element 999 of s, */
{                /* s is a copy of the calling parameter, so it is    */
  s.a[999] = -1; /* deleted at the end of the procedure.              */
}                /* In other words, the procedure does nothing.       */


int main()
{
  SID s1;
  int i;

  for (i = 0; i < 1000; i++) s1.a[i] = i;    /* Set the elements of s1. */

  a(s1);                /* This does nothing, because it modifies a copy of s1 */

  printf("Element 999: %d\n", s1.a[999]);
 
  return 0;
}