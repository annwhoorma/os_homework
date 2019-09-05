#include <stdio.h>

void bubble_sort(int*, int);

int main(){
    return 0;
}

//args: array to sort and its size
void bubble_sort(int a[], int size){
    int t = 0;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}