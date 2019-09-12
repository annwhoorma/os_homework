#include <unistd.h>

int main(){
    for (int i = 1; i <= 3; i++){
        fork();
        sleep(5);
    }
    // for (int i = 1; i <=5; i++){
    //     fork();
    //     sleep(5);
    // }
    return 0;
}