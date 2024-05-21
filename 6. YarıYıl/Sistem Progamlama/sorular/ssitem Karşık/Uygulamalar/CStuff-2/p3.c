/* Print out pointers of local variables */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  char j[14];
  j[0]=1;
  int *ip;
  char *jp;

  ip = &i;
  jp = j; //diziler pointer oldugu ve ilk elemanını işaret ettiği için & yok

  printf("ip = 0x%lx.  jp = 0x%lx\n", ip, jp);
  /* for not getting warning, casting 
  printf("ip = 0x%lx.  jp = 0x%lx\n", 
         (long unsigned int) ip,   
         (long unsigned int) jp); */

  printf("jp's first element: %d\n", *jp);
  return 0;
}