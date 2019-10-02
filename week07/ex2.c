#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    printf("Enter the number of integers you want:\n");
    scanf("%d", &N);
    if (N <= 0){
        perror("Nope, entered N was less than 1\n");
        exit(1);
    }
    int* array = malloc(N * sizeof(int));
    if (array == NULL){
        perror("malloc() wasn't successful\n");
        exit(1);
    }
    int* temp = array;
    for (int i = 0; i < N; i++){
        *temp = i;
        temp++;
    }
    temp = array;
    printf("Your array:\n");
    for (int i = 0; i < N; i++){
        printf("%d ", *temp);
        temp++;
    }
    printf("\n");
    free(array);
    return 0;
}