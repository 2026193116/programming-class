#include <stdio.h>
#define N 10

int main() {
    int a[N] = {[0] = 0, [1] = 1, [2] = 2, [3] = 3, [4] = 4, [5] = 5, [6] = 6, [7] = 7, [8] = 8, [9] = 9};
    a[1] = 5;
    for (int i = 0; i < N; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}