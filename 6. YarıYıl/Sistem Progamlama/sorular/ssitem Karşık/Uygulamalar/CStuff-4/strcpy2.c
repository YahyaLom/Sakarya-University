/* What happens when you call strcpy and didn't allocate enough memory? */

#include <stdio.h>
#include <string.h>

typedef unsigned long UL;

int main()
{
  char give[5];
  char him[5];
  char six[5];

  /* Print the addresses of the three arrays. */

  printf("give: 0x%lx  him: 0x%lx  six: 0x%lx\n", (UL) give, (UL) him, (UL) six);

  /* This is the same as before -- nice strcpy() statements, and then print. */

  strcpy(give, "Give");
  strcpy(him, "Him");
  strcpy(six, "Six!");
  printf("%s %s %s\n", give, him, six);

  /* Now, this strcpy() is copying a string that is too big. */

  strcpy(him, "T.J. Houshmandzadeh");
  printf("%s %s %s\n", give, him, six);

  return 0;
}