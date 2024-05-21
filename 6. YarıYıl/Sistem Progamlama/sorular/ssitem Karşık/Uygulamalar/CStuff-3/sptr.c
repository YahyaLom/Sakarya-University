/* This is the same as src/iptr.c, except iarray is an array of "Two" structs instead
   of ints.  The "Two" struct is simply a struct of two doubles. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double d1;
  double d2;
} Two;

typedef unsigned long (UL);

int main()
{
  Two iarray[10];
  Two *ip;
  int i;

  for (i = 0; i < 10; i++) iarray[i].d1 = 100+i;   /* Set the d1 field to be 100 + i */
  for (i = 0; i < 10; i++) iarray[i].d2 = 200+i;   /* Set the d2 field to be 200 + i */

  printf("iarray = 0x%lx\n", (UL) iarray);

  ip = iarray;

  for (i = 0; i < 10; i++) {
    printf("i=%d.  ",                    i                              );
    printf("iarray[i]={%.2lf,%.2lf}.  ", iarray[i].d1, iarray[i].d2     );
    printf("ip = 0x%lx.  ",              (UL) ip                        );
    printf("*ip={%.2lf,%.2lf}.  ",       ip->d1, ip->d2                 );
    printf("(ip-iarray)=%ld.\n",         (UL) (ip-iarray)               );
    ip++;
  }

  return 0;
}