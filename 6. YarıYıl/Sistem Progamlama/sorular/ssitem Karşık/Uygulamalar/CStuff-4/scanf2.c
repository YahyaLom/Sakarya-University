/* This program uses scanf and %s to read a string and print out the characters.
   You should *only* use scanf and %s if you are guaranteed that the string you are
   reading will not be bigger than the memory allocated to it.  Otherwise, you expose
   yourself to a buffer overflow attack. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char s[10];
  int i;
  
  if (scanf("%s", s) != 1) exit(0);

  for (i = 0; s[i] != '\0'; i++) {
    printf("Character: %d: %3d %c\n", i, s[i], s[i]);
  }
  exit(0);
}