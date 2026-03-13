#include <stdio.h>

int main() {
    char b = 'A';
    printf("b %%d : %d\n", b);
    printf("b %%i : %i\n", b);
    printf("b %%c : %c\n", b+32);
    printf("b %%f : %f\n", (float)b);

    return 0; 
}