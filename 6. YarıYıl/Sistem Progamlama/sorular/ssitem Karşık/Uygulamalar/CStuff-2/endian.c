/* This code was originally written by Jay Pickens to help CS360 students understand
   type-casting, endian-ness and pointers.  I have since mangled it beyone repair, 
   but I appreciate what he did with it -- James S. Plank */

#include <stdio.h>

typedef unsigned long UL;

int main() 
{
  unsigned int array[4]; /* An array of four integers. */
  unsigned int *ip;      /* An integer pointer that we're going to set to one byte beyond array */
  unsigned char *cp;     /* An unsigned char pointer for exploring the individual bytes in array */
  unsigned short *sp;    /* An unsigned short to show two-byte access. */
  int i;

  /* Set array to equal four integers, which we specify in hexadecimal. */

  array[0] = 0x12345678;
  array[1] = 0x9abcdef0;
  array[2] = 0x13579bdf;
  array[3] = 0x2468ace0;
  
  /* For each value of array, print it out in hexadecimal.  Also print out its location in memory. */

  for (i = 0; i < 4; i++) {
    printf("Array[%d]'s location in memory is 0x%lx.  Its value is 0x%x\n", 
            i, (UL) (array+i), array[i]);
  }

  /* Now, print out the sixteen bytes as bytes, printing each byte's location first. */

  printf("\n");
  printf("Viewing the values of array as bytes:\n");
  printf("\n");

  cp = (unsigned char *) array;

  for (i = 0; i < 16; i++) {
    printf("Byte %2d. Pointer: 0x%lx - Value: 0x%02x\n", i, (UL) (cp+i), cp[i]);
  }

  /* Finally, set the pointer ip to be one byte greater than array,
     and then print out locations and integers. */

  printf("\n");
  printf("Setting the pointer ip to be one byte greater than array:\n");
  printf("\n");

  cp++;
  ip = (unsigned int *) cp;
  for (i = 0; i < 4; i++) {
    printf("(ip+%d) is 0x%lx.  *(ip+%d) is 0x%x\n", i, (UL) (ip+i), i, *(ip+i));
  }

  /* Now, set sp to equal array.  Sp is a pointer to shorts.  We print out sp[0] and sp[0]. */

  printf("\n");
  printf("Finally printing the first four bytes of array as two shorts.\n");
  printf("\n");

  sp = (unsigned short *) array;
  printf("Location: 0x%lx - Value as a short: 0x%04x\n", (UL) sp, sp[0]);
  printf("Location: 0x%lx - Value as a short: 0x%04x\n", (UL) (sp+1), sp[1]);
  printf("\n");

  return 0;
}