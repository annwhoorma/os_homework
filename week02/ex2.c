#include <stdio.h>
#include <string.h>

int main(){
    char string[50];
    char result[50];
    int length;
    printf("Enter string of size < 51: ");
    char c = getchar();
    for (int i = 0; c != '\n'; i++){
        string[i] = c;
        c = getchar();
    }
    length = strlen(string);
    printf("REVERSED STRING: ");
    for (int i = 0; i < length + 1; i++){
        result[i] = string[length - i];
        printf("%c", result[i]);
    }
    printf("\n");
}