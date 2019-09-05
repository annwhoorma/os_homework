#include <stdio.h>
void quick_sort(int array[], int first, int last);

int main(){
    return 0;
}

void quick_sort(int array[], int first, int last){
    if (first < last){
        int pivot = first;
        int temp;
        int a = first;
        int b = last;
        while (a < b){
            while (array[a] <= array[pivot] && a < last){
                a++;
            }
            while (array[b] > array[pivot]){
                b--;
            }
            if (a < b){
                temp = array[a];
                array[a] = array[b];
                array[b] = temp;
            }
        }
        temp = array[pivot];
        array[pivot] = array[b];
        array[b] = temp;
        quick_sort(array, first, b-1);
        quick_sort(array, b+1, last);
    }
}
