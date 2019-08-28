#include <stdio.h>

void swap(int* one, int* two){
    int temp = *one;
    *one = *two;
    *two = temp;
}

int main(){
    printf("Enter two numbers: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("You entered: %d %d\n", a, b);
    swap(&a, &b);
    printf("Now they're swapped: %d %d\n", a, b);
}