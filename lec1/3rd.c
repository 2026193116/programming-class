#include <stdio.h>

int main() {
    int c = -3;
    printf("c %%d : %d\n", c);
    printf("c %%i : %i\n", c);
    printf("c %%c : %c\n", c);
    printf("c %%f : %f\n", (float)c);
    printf("c %%u : %u\n", c);
    return 0; 
}