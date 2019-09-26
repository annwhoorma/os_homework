#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int p[2]; //p[0] - read end, p[1] - write end
    pid_t pidd;

    pidd = fork();
    if (pidd < 0){
        perror("fork failed");
        return 1; 
    }
     else if (pidd > (pid_t) 0){
        //parent process
        int time = 0;
        while(time != 11){
            sleep(1);
            time++;
        }
        kill(pidd, SIGKILL);
    }
    else if (pidd == (pid_t) 0){
        //child process
        while (1){
            sleep(1);
            printf("From a child: I'm alive\n");
        };
    }
    return 0;
}