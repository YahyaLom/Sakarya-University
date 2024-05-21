#include <stdio.h>
#include <stdlib.h>

int main(){
    int x=100,y=50;
    int *p=&x;
    int *r=&y;
    int *tmp=p;
    p=r;
    r=tmp;
    printf("%d\n",*p);
    printf("%d\n",*r);

    int *ptr=malloc(sizeof(int));
    *ptr=100;
    printf("%d\n",*ptr);
    free(ptr);

    return 0;
}