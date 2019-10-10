#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b){
    return a < b ? a : b;
}

void* my_realloc(void* ptr, int old_size, int new_size){
    if (new_size < 0){
        perror("Attempt to reallocate with negative size\n");
        exit(1);
    }

    if (new_size == old_size){
        return ptr;
    }

    if (ptr != NULL){
        // must be returned by malloc(), calloc() or realloc()
        if (new_size == 0){
            free (ptr);
            return NULL;
        }
        else{
            void* new_ptr = malloc(new_size);
            memcpy(ptr, new_ptr, min(new_size, old_size));
        }
    }
    else {
        // call is equivalent to malloc(size)
        if (new_size == 0){
            return NULL;
        }
        else if (new_size > 0){
            return malloc(new_size);
        }
    }
}

int main(){

}


