#include <stdio.h>

int main(){
    int digits = 0;
    int n;

    printf("positive integer : ");
    scanf("%d", &n);

    do {
        n /= 10;
        ++digits;
    } while (n > 0);
    printf("digits is : %d\n", digits);
    return 0;
}