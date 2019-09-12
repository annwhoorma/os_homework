#include <stdio.h>
#include <unistd.h>

int main(){
    //i didn't use any n to output PID
    pid_t pid;
    pid = fork();
    if (pid == 0)
        printf("Hello from child [PID - %d]\n", getpid());
    else if (pid > 0)
        printf("Hello from parent [PID - %d]\n", getpid());
    else //pid < 0 => fork() was unsuccessful
        printf("Creation of a new process was unsuccessful\n");
    printf("----------------------------\n");
    return 0;
}
