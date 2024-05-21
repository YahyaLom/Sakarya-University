#include <stdio.h>

int main()
{
  char buf[1000];
  int i, h;
  double d;

  while (fgets(buf, 1000, stdin) != NULL) {
    if (sscanf(buf, "%d", &i) == 1) {
      printf("When treated as an integer, the value is %d\n", i);
    } 
    if (sscanf(buf, "%x", &h) == 1) {
      printf("When treated as hex, the value is 0x%x (%d)\n", h, h);
    } 
    if (sscanf(buf, "%lf", &d) == 1) {
      printf("When treated as a double, the value is %lf\n", d);
    }
    if (sscanf(buf, "0x%x", &h) == 1) {
      printf("When treated as a hex with 0x%%x formatting, the value is 0x%x (%d)\n", h, h);
    }
    printf("\n");
  }
}