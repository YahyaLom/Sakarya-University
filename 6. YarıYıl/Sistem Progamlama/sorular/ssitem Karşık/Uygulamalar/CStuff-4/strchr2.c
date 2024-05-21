/* Instead of printing out the first space, this uses strchr to 
   print the location of all spaces on a line. */

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
      while (ptr != NULL) {
        printf("Space at character %ld\n", ptr-line);
        ptr = strchr(ptr+1, ' ');
      }
    }
  }
  return 0;
}