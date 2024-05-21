#include <stdio.h>
#include <stdlib.h>

/* This sets all lower-case letters in a to upper case. */

void change_case(char a[20])
{
  int i;

  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] >= 'a' && a[i] <= 'z') a[i] += ('A' - 'a');
  }
}

/* This initializes a 19-character string of lower-case letters, and then calls change_case(). */

int main()
{
  int i;
  char s[20];
  
  /* Set s to "abcdefghijklmnopqrs". */

  for (i = 0; i < 19; i++) s[i] = 'a' + i;
  s[19] = '\0';

  /* Print, call change_case() and print again. */

  printf("First, S is %s.\n", s);
  change_case(s);
  printf("Now, S is   %s.\n", s);

  return 0;
}