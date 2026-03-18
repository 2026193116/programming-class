#include <stdio.h>

int main(){
    int a = 3;
    printf("a : %d\n", !a);
    int b = 0;
    printf("b : %d\n", !b);

    printf("3 && 0: %d\n", 3&&0);
    printf("3 && 2: %d\n", 3&&2);

    printf("3 || 0: %d\n", 3||0);
    printf("3 || 2: %d\n", 3||2);

    return 0;
}