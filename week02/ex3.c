#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int n;
    sscanf(argv[1], "%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (2*n-1)/2 - i; j++){
            printf(" ");
        }
        for (int j = 0; j < 2*i + 1; j++){
            printf("*");
        }
        for (int j = 0; j < (2*n-1)/2 - i; j++){
            printf(" ");
        }
        printf("\n");
    }
}