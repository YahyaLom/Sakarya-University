/* Read a single integer from standard input using scanf. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  
  if (scanf("%d", &i) == 1) {
    printf("Just read i: %d (0x%x)\n", i, i);
  } else {
    printf("Scanf() failed for some reason.\n");
  }
  exit(0);
}