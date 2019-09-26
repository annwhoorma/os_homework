#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int received){
    signal(received, SIG_IGN);
    printf("\n>Do you want to quit? [y/n]\n");
    char c = getchar();
    if (c == 'y' || c == 'Y')
        exit(0);
    else
        signal(SIGINT, handler);
    getchar(); // to get '\n' 
}

int main(){
    signal(SIGINT, handler);
    while (1){};
    return 0;
}