#include <stdio.h>

int main() {
    int d = 128;
    printf("d %%d : %d\n", d);
    printf("d %%i : %i\n", d);
    printf("d %%c : %c\n", d);
    printf("d %%f : %f\n", (float)d);
    printf("d %%e : %e\n", d);
    return 0; 
}