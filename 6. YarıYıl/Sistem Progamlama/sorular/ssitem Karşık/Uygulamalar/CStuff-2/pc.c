/* This program shows how you lose information as you
   convert data from larger types to smaller types. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
  int i;
  int j;

  i = 10000;
  c = i;         /* We are losing information here, because 10000 cannot be stored in a byte. */
  j = c;

  printf("I: %d,   J: %d,       C: %d\n", i, j, c);
  printf("I: 0x%04x,  J: 0x%04x,   C: 0x%04x\n", i, j, c);
  return 0;
}