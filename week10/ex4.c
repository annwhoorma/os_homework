#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(){
    DIR* dr;
    dr = opendir("temp");
    if (dr == NULL) {
        printf("Error occured\n");
        exit(1); 
    }
    struct dirent* entries[10];
    int k = 0;
    int amounts[10];
    for (int i = 0; i < 10; i++){
        amounts[i] = 0;
    }
    while ((entries[k++] = readdir(dr)) != NULL){}
    for (int i = 0; i < k - 1; i++){
        for (int j = i + 1; j < k; j++){
            if (entries[i]->d_ino == entries[j]->d_ino){
                amounts[i]++;
            }
        }
    }
    for (int i = 0; i < 10; i++){
        if (amounts[i] >= 2){
            printf("%s ", entries[i]->d_name);
        }
    }
    printf("\n");
    return 0;
}