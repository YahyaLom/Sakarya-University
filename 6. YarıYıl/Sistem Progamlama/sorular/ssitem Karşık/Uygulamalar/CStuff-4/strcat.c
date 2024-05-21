/* Using strcpy() and strcat() to create the string "Give Him Six!" incrementally. */

#include <stdio.h>
#include <string.h>

int main()
{
  char givehimsix[15];

  strcpy(givehimsix, "Give");
  printf("%s\n", givehimsix);
  strcat(givehimsix, " Him");
  printf("%s\n", givehimsix);
  strcat(givehimsix, " Six!");
  printf("%s\n", givehimsix);
  return 0;
}