/* A program where we inadvisedly typecast a pointer to an int and back again.
   On machines with 8-byte pointers, this is a buggy activity, because you lose
   data when you typecast from an integer to a pointer. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long unsigned int LUI;

int main()
{
  char s[4];
  int i; //long olursa 8 byte tutabilir
  char *s2;

  /* Copy the string "Jim" to s, then turn the pointer into an integer i.
     Print out the pointer's value, and i's value. */

  strcpy(s, "Jim");
  i = (int) s; //(long) olursa 8 bayt tutacagından adres kaybı yaşamayız
  printf("Before incrementing i.\n");
  printf("i = %d (0x%x)\n", i, i);
  printf("s = %ld (0x%lx)\n", (LUI) s, (LUI) s);

  /* Now increment i, and turn it back into a pointer.  
     Print out the pointers, and then attempt to print out what they point to. */

  i++;
  s2 = (char *) i;
  printf("\n");
  printf("After incrementing i.\n");
  printf("s = 0x%lx.  s2 = 0x%lx, i = 0x%x\n", (LUI) s, (LUI) s2, i);
  printf("s[0] = %c, s[1] = %c, *s2 = %c\n", s[0], s[1], *s2);
  return 0;
}