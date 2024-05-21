#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void catchSignal(int sigNum){
    printf("Cmd+.\n");
}

int main(){
    //signal(SIGINT, SIG_IGN)
    signal(SIGINT, catchSignal);

    int i;
    for(i=0; i<20; i++){
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}