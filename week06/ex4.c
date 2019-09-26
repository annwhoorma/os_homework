#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig){
    printf("Exiting...\n");
    exit(1);
}

int main(){
    //SIGKILL and SIGSTOP cant be handled manually, according to linux manual page
    signal(SIGKILL, handler);
    signal(SIGUSR1, handler);
    signal(SIGSTOP, handler);
    while(1)
        sleep(1);
    return 0;
}