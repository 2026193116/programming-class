#include <stdio.h>

#define N 10
int main() {
    int a[N];

    a[1] = 5;
    printf("%d\n", a[1]);
    ++a[1];
    printf("%d\n", a[1]);

    for (int i = 0; i < N; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}