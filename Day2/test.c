#include <stdio.h>

void* num(void* a){
    return a;
}

int main(void){
    int a = 2;
    float b = 3.14;

    printf("%d\n", *(int*)num((&a)));
    printf("%f", *(float*)num((&b)));

    return 0;
}