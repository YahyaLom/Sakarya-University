/* Use strchr() to determine if each line of standard input has a space. */

#include <stdio.h>
#include <string.h>

int main()
{
  char line[100];
  char *ptr;

  while (fgets(line, 100, stdin) != NULL) {
    ptr = strchr(line, ' ');
    if (ptr == NULL) {
      printf("No spaces\n");
    } else {
      printf("Space at character %ld\n", ptr-line);
    }
  }
  return 0;
}