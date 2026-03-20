#include <stdio.h>

int main(){
    int sum = 0;

    for(int i  = 1; i < 21; i++){
        printf("%d\n", i);
        sum += i;
        if (i>4) {
            break;
        }
    }

    printf("sum = %d\n", sum);
    return 0;
}