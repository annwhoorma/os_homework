#include <stdio.h>
#include <float.h>

int main(){
    int a; 
    float b;
    double c;
    
    a = __INT_MAX__;
    b = __FLT_MAX__;
    c = __DBL_MAX__;

    printf("INT size: %d\t INT value: %d\n", sizeof(a), a);
    printf("FLT size: %d\t FLT value: %f\n", sizeof(b), b);
    printf("DBL size: %d\t DBL value: %lf\n", sizeof(c), c);
}