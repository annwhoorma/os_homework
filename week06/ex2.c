#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

#define N 6

int main(void){
    char first_string[N] = "dabin";
    char second_string[N];
    int p[2]; //p[0] - read end, p[1] - write end
    pid_t pidd;

    //we create pipe first so that both child and parent can communicate through it

    if (pipe(p) == -1){
        perror("pipe failed");
        return 1; 
    }
    
    if ((pidd = fork()) < 0){
        perror("fork failed");
        return 1; 
    }

    else if (pidd > (pid_t) 0){
        //parent process
        write(p[1], first_string, N);
        close(p[1]);
    }
    else if (pidd == (pid_t) 0){
        //child process
        printf("String before child process reads: %s\n");
        read(p[0], second_string, N);
        close(p[1]);
        printf("String before child process has read: %s\n", second_string);
    }
    sleep(1);
    return 0;
}