/* This program sets a pointer to an array, and then dereferences each of the
   elements of the array using the pointer and pointer arithmetic.  It prints
   the pointers in hexadecimal while it does so. */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long (UL);

int main()
{
  int iarray[10];
  int *ip;
  int i;

  /* Set the 10 elements of iarray to be 100 to 109, and print the array's address. */

  for (i = 0; i < 10; i++) iarray[i] = 100+i;
  printf("iarray = 0x%lx\n", (UL) iarray);

  /* Set ip equal to array, and then print the 10 elements using both iarray and ip.
     The following quantities will be printed for each element:

      - The index i (goes from 0 to 9)
      - The value of iarray[i] (goes from 100 to 109)
      - The pointer ip (will start at iarray and increment by four each time).
      - What *ip points to (this will be 100 to 109 again)
      - Pointer arithmetic: (ip-array) -- this will be the value of i.
   */

  ip = iarray;

  for (i = 0; i < 10; i++) {
    printf("i=%d.  ",            i              );
    printf("iarray[i]=%d.  ",    iarray[i]      );
    printf("ip = 0x%lx.  ",      (UL) ip        );
    printf("*ip=%d.  ",          *ip            );
    printf("(ip-iarray)=%ld.\n", (UL) (ip-iarray)); //i=1 için ip adresi sonu f4, iarray f0. f4-f0=4 çıkıyor. Bunu da int 4 byte, /4 yapınca 1 çıkıyor.
    ip++;
  }

  return 0;
}