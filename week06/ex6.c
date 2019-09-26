#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>



int main(){
    int fd[2]; //fd[0] - read end, fd[1] - write end
    char pid_to_send[21];
    char pid_to_read[21];
    for (int i = 0; i < 21; i++){
        pid_to_read[i] = '\0';
    }
    for (int i = 0; i < 21; i++){
        pid_to_send[i] = '\0';
    }
    int status;

    if (pipe(fd) == -1){
        perror("pipe failed");
        return 1; 
    }
    printf("Pipe was created\n");

    __pid_t pid1, pid2;
    if ((pid1 = fork()) < (pid_t) 0){
        perror("fork failed\n");
        kill(pid1, SIGKILL);
        kill(pid2, SIGKILL);
        exit(1);
    }

    if (pid1 > (pid_t) 0){
        printf(">>Parent: First child was created with PID %d:\n", pid1);
        if ((pid2 = fork()) < (pid_t) 0){
            perror("fork failed\n");
            kill(pid1, SIGKILL);
            kill(pid2, SIGKILL);
            exit(1);
        }
        if (pid2 > 0){
            printf(">>Parent: Second child was created with PID: %d\n", pid2);
            sprintf(pid_to_send, "%d", pid2);
            write(fd[1], pid_to_send, strlen(pid_to_send));
            close(fd[1]);
            printf(">>Parent: Process ID of the 2nd child was sent to the 1st child\n");
            printf(">>Parent: I'm gonna waitpid()\n");
            waitpid(pid2, &status, 0);
        }

        else if (pid2 == (pid_t) 0){
            //2nd child
            while(1){
                sleep(1);
                printf(">>Child 2: I'm still alive\n");
            }
        } 
    }
    else if (pid1 == (pid_t) 0){
        //1st child
        sleep(0.5);
        printf(">>Child 1: I'm gonna read from a pipe\n");
        read(fd[0], pid_to_read, 21);
        close(fd[0]);
        int sib_pid = 0;
        sib_pid = atoi(pid_to_read);
        printf(">>Child 1: Just read from the pipe. My sibling's PID is %d\n", sib_pid);
        printf(">>Child 1: I'm going to sleep for 2 seconds\n");
        sleep(2);
        printf(">>Child 1: Ok, I'm awake and I'm gonna send SIGSTOP to my sibling\n");
        kill(sib_pid, SIGSTOP);
        kill(sib_pid, SIGTERM);
    }
}