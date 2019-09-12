#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_empty(char* str){
    while(*(str++) == ' ') {}
    return (*(--str) == '\0');
}

int main(){
    while(1){
        printf("> ");
        char input[100];
        scanf("%s", input);
        if (is_empty(input) == 1)
            continue;
        if (strcmp(input, "exit") == 0)
            return 0;
        if (system(input) == -1){
            printf("ERROR\n");
            continue;
        }
    }
}