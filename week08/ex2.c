#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define mb 1024*1024

int main(){
    for (int i = 0; i < 10; i++){
        // calloc(10000000, char);
        void* ptr = malloc(10*mb);
        if (ptr == NULL){
            perror("malloc() returned NULL pointer\n");
            exit(1);
        }
        memset(ptr, 0, 10000000);
        sleep(1);
    }
    return 0;
}