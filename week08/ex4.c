#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
#define mb 1024*1024

int main(){
    struct rusage usage;
    int who = RUSAGE_SELF; 
    /*
    RUSAGE_SELF - return resource usage statistics for the calling process,
    which is the sum of resources used by all threads in the
    process. (c) from man getrusage
    */
    for (int i = 0; i < 10; i++){
        // I think I could use this: calloc(10000000, char);
        void* ptr = malloc(10*mb);
        if (ptr == NULL){
            perror("malloc() returned NULL pointer\n");
            exit(1);
        }
        memset(ptr, 0, 10000000);

        if (getrusage(who, &usage) == -1){
            perror("Problem with getrusage()\n");
            exit(1);
        }
        printf("%d: Memory usage: %ld\n", i, usage.ru_maxrss); // i know that i'd better use another var of usage but this one works here (i checked w top -d <pid>)
        sleep(1);
    }
    return 0;
}