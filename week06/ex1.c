#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

#define N 6

int main(void){
    char first_string[N] = "dabin";
    char second_string[N];
    int fd[2]; //fd[0] - read end, fd[1] - write end

    if (pipe(fd) == -1){
        perror("pipe failed");
        return 1; 
    }
    write(fd[1], first_string, N);
    
    read(fd[0], second_string, N);
    printf("first (was like this) : \t%s\nsecond (copied from first) : \t%s\n", first_string, second_string);
    close(fd[0]);
    close(fd[1]);
    return 0;
}